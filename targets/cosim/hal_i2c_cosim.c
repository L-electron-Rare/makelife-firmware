/* hal_i2c_cosim.c — I2C HAL backed by POSIX shared memory transaction protocol.
 *
 * Shared memory I2C buffer (offset 256):
 *   [0]   bus_id
 *   [1]   direction  (0=write, 1=read)
 *   [2]   address    (7-bit)
 *   [3]   reg_addr
 *   [4]   length
 *   [5]   status     (0=idle, 1=pending, 2=complete)
 *   [6-7] reserved
 *   [8..255] data payload
 *
 * Protocol:
 *   1. Fill fields [0..4], set status=pending.
 *   2. Spin-wait until status==complete (set by Python orchestrator).
 *   3. For reads: copy data from [8..8+len].
 *   4. Set status=idle.
 */
#include "hal/i2c.h"

#include <fcntl.h>
#include <stdint.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>

#define SHM_NAME          "/spice_life_bridge"
#define SHM_SIZE          4096

#define OFF_I2C           256

#define I2C_STATUS_IDLE     0
#define I2C_STATUS_PENDING  1
#define I2C_STATUS_COMPLETE 2

#define I2C_DIR_WRITE 0
#define I2C_DIR_READ  1

/* Shared pointer — same mmap as GPIO cosim if linked together.
 * In a single-binary build, only one mmap is needed; we re-open for safety. */
static volatile uint8_t *shm_base = NULL;

static void _shm_init(void) {
    if (shm_base != NULL) {
        return;
    }
    int fd = open("/dev/shm/spice_life_bridge", O_RDWR);
    if (fd < 0) {
        fd = shm_open(SHM_NAME, O_RDWR, 0666);
    }
    if (fd < 0) {
        return;
    }
    shm_base = (volatile uint8_t *)mmap(
        NULL, SHM_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    close(fd);
    if (shm_base == MAP_FAILED) {
        shm_base = NULL;
    }
}

static inline volatile uint8_t *_i2c_buf(void) {
    return shm_base + OFF_I2C;
}

int hal_i2c_read(uint8_t bus, uint8_t addr, uint8_t reg, uint8_t *data, uint8_t len) {
    _shm_init();
    if (!shm_base) {
        return -1;
    }
    volatile uint8_t *i2c = _i2c_buf();

    /* Wait until bus is idle before submitting */
    while (i2c[5] != I2C_STATUS_IDLE) { /* spin */ }

    i2c[0] = bus;
    i2c[1] = I2C_DIR_READ;
    i2c[2] = addr;
    i2c[3] = reg;
    i2c[4] = len;
    i2c[5] = I2C_STATUS_PENDING;

    /* Wait for orchestrator to fill response */
    while (i2c[5] != I2C_STATUS_COMPLETE) { /* spin */ }

    memcpy(data, (const void *)(i2c + 8), len);
    i2c[5] = I2C_STATUS_IDLE;
    return 0;
}

int hal_i2c_write(uint8_t bus, uint8_t addr, uint8_t reg, const uint8_t *data, uint8_t len) {
    _shm_init();
    if (!shm_base) {
        return -1;
    }
    volatile uint8_t *i2c = _i2c_buf();

    while (i2c[5] != I2C_STATUS_IDLE) { /* spin */ }

    i2c[0] = bus;
    i2c[1] = I2C_DIR_WRITE;
    i2c[2] = addr;
    i2c[3] = reg;
    i2c[4] = len;
    memcpy((void *)(i2c + 8), data, len);
    i2c[5] = I2C_STATUS_PENDING;

    while (i2c[5] != I2C_STATUS_COMPLETE) { /* spin */ }

    i2c[5] = I2C_STATUS_IDLE;
    return 0;
}
