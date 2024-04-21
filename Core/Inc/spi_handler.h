#ifndef SPI_HANDLER
#define SPI_HANDLER
#include "spi_handler.h"
#include "spi.h"
#include "stdio.h"
#include "sensors.h"
#include "main.h"

uint16_t spi_read_reg(uint8_t regAdr, uint16_t *stat);
void spi_write_reg(uint8_t regAdr,uint16_t* pRegData);
void displayTempData(uint16_t data);


#endif
