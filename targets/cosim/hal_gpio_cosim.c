/* hal_gpio_cosim.c — GPIO HAL backed by POSIX shared memory.
 *
 * Shared memory layout (matches Python ShmBridge):
 *   offset 0  : gpio_out[32]  uint8  — this side writes here
 *   offset 160: gpio_in[32]   uint8  — this side reads here
 */
#include "hal/gpio.h"

#include <fcntl.h>
#include <stdint.h>
#include <sys/mman.h>
#include <unistd.h>

#define SHM_NAME      "/spice_life_bridge"
#define SHM_SIZE      4096

#define OFF_GPIO_OUT  0
#define OFF_GPIO_IN   160

static volatile uint8_t *shm_base = NULL;

static void _shm_init(void) {
    if (shm_base != NULL) {
        return;
    }
    /* Try /dev/shm path first (Linux), fallback to shm_open */
    int fd = open("/dev/shm/spice_life_bridge", O_RDWR);
    if (fd < 0) {
        fd = shm_open(SHM_NAME, O_RDWR, 0666);
    }
    if (fd < 0) {
        /* No shared memory available — silently use NULL (reads return 0) */
        return;
    }
    shm_base = (volatile uint8_t *)mmap(
        NULL, SHM_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    close(fd);
    if (shm_base == MAP_FAILED) {
        shm_base = NULL;
    }
}

void hal_gpio_init(uint8_t pin, hal_gpio_mode_t mode) {
    (void)mode;
    _shm_init();
}

void hal_gpio_write(uint8_t pin, hal_gpio_level_t level) {
    if (!shm_base || pin >= 32) {
        return;
    }
    shm_base[OFF_GPIO_OUT + pin] = (uint8_t)(level & 0x01);
}

hal_gpio_level_t hal_gpio_read(uint8_t pin) {
    if (!shm_base || pin >= 32) {
        return HAL_GPIO_LOW;
    }
    return (hal_gpio_level_t)(shm_base[OFF_GPIO_IN + pin] & 0x01);
}

void hal_gpio_toggle(uint8_t pin) {
    if (!shm_base || pin >= 32) {
        return;
    }
    shm_base[OFF_GPIO_OUT + pin] ^= 0x01;
}
