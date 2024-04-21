#include "spi_handler.h"
#include "spi.h"
#include "stdio.h"
#include "sensors.h"
#include "main.h"

#define SPI_MESSAGE_LENGTH 4

uint16_t spi_read_reg(uint8_t regAdr, uint16_t *stat)
{
	uint8_t txData[4]={0x00};
	uint8_t rxData[4]={0x00};
	uint16_t msg;
	regAdr |= 0x80; //MSB 1 for reading
	txData[0] = regAdr;
	HAL_SPI_TransmitReceive(&hspi1,txData,rxData,4,10);
	*stat = (rxData[0]<<8) + rxData[3];
	msg = ((rxData[1]<<8) + rxData[2]);
	return msg;
}

void spi_write_reg(REGISTER_ADR regAdr,uint16_t* pRegData)
{
	uint8_t message[4];
	regAdr |= 0x00;              //First MSB bitm must be
	message[0] = regAdr;         //Write an address with first bit set to 0
	message[1] = *pRegData>>8;    //Write data to register 8MSB bits
	message[2] = *pRegData;       //Write data to register 8LSB bits
	message[3] = calc_crc(regAdr, pRegData); //TODO: CRC!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!        //Write cmd to start conversion on next CS going high
	HAL_SPI_Transmit(&hspi1, message, SPI_MESSAGE_LENGTH, HAL_MAX_DELAY);
}

void displayTempData(uint16_t data)
{
	printf("%d",data);
}
/*
SensorMeasuredData spi_read_measured_data(Sensor* sen)
{
	uint8_t txData[4]={0};
	uint8_t rxData[4]={0};
	uint16_t msg=0;
	SensorMeasuredData data;


	regAdr |= 0x80;
	txData[0] = regAdr;
	HAL_SPI_TransmitReceive(&hspi1, txData, rxData, 4, 10);


}
*/

