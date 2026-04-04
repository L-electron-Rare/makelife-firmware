#pragma once
#include <stdint.h>

/**
 * hal_i2c_read — read `len` bytes from I2C device at `addr`, register `reg`.
 * Returns 0 on success, -1 on error.
 */
int hal_i2c_read(uint8_t bus, uint8_t addr, uint8_t reg, uint8_t *data, uint8_t len);

/**
 * hal_i2c_write — write `len` bytes to I2C device at `addr`, register `reg`.
 * Returns 0 on success, -1 on error.
 */
int hal_i2c_write(uint8_t bus, uint8_t addr, uint8_t reg, const uint8_t *data, uint8_t len);
