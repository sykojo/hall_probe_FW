#ifndef SENSORS
#define SENSORS

#include "stdio.h"
#include "stdint.h"
#include "string.h"
#include "stdlib.h"
#include "main.h"

#define RANGE 75

#define TEST_REG_EXPECTED_VAL 0x54
#define DEVICE_CONFIG_EXPECTED_VAL 0x5020
#define SENSOR_CONFIG_EXPECTED_VAL 0x01D5
#define SYSTEM_CONFIG_EXPECTED_VAL 0x00


typedef enum
    {
		//Test config
		CRC_DIS=2,
		//Device config
		CONV_AVG=12,
		MAG_TEMPCO=8,
		OPERATING_MODE=4,
		T_CH_EN=3,
		T_RATE=2,
		T_HLT_EN=1,
		//Sensor config
		ANGLE_EN=14,
		SLEEPTIME=10,
		MAG_CH_EN=6,
		Z_RANGE=4,
		Y_RANGE=2,
		X_RANGE=0,
		//System config
		DIAG_SEL=12,
		TRIGGER_MODE=9,
		DATA_TYPE=6,
		DIAG_EN=5,
		Z_HLT_EN=2,
		Y_HLT_EN=1,
		X_HLT_EN=0,
		//Conv_status register
		RDY=13,
		A=12,
		T=11,
		Z=10,
		Y=9,
		X=8,
		SET_COUNT=4,
		ALRT_STATUS=0,
		//X_CH_RESULT
		/*
		X_CH_RESULT=0,
		//Y_CH_RESULT
		Y_CH_RESULT=0,
		//Z_CH_RESULT
		Z_CH_RESULT=0,
		// Temperature result
		TEMP_RESULT_SH=15
		*/


    }REGISTER_FEATURE;

    typedef enum
    {
        DEVICE_CONFIG=0x00,
        SENSOR_CONFIG=0x01,
		SYSTEM_CONFIG=0x02,
		ALERT_CONFIG=0x03,
		X_THRX_CONFIG=0x04,
		Y_THRX_CONFIG=0x05,
		Z_THRX_CONFIG=0x06,
		T_THRX_CONFIG=0x07,
		CONV_STATUS=0x08,
		X_CH_RESULT=0x09,
		Y_CH_RESULT=0x0A,
		Z_CH_RESULT=0x0B,
		TEMP_RESULT=0x0C,
		AFE_STATUS=0x0D,
		SYS_STATUS=0x0E,
		TEST_CONFIG=0x0F,
		OSC_MONITOR=0x10,
		MAG_GAIN_CONFIG=0x11,
		MAG_OFFSET_CONFIG=0x12,
		ANGLE_RESULT=0x13,
		MAGNITUDE_RESULT=0x14
    }REGISTER_ADR;

typedef struct
{
    REGISTER_ADR adr;
    uint16_t data;
}Register;

typedef struct
{
	int32_t x_B;
	//uint32_t separator_x;
	int32_t y_B;
	//uint32_t separator_y;
	int32_t z_B;
	//uint32_t separator_z;
}MeasuredData;

typedef struct
{
	//uint8_t start_char;
	MeasuredData data[8];
	//uint8_t stop_char;
}Message;

typedef struct
{
    uint8_t adr;
    uint8_t ok;
    uint8_t num_of_axis;
    MeasuredData measured_data;

    Register DEVICE_CONFIG;
    Register SENSOR_CONFIG;
    Register SYSTEM_CONFIG;
    Register ALERT_CONFIG;
    Register X_THRX_CONFIG;
    Register Y_THRX_CONFIG;
    Register Z_THRX_CONFIG;
    Register T_THRX_CONFIG;
    Register CONV_STATUS;
    Register X_CH_RESULT;
    Register Y_CH_RESULT;
    Register Z_CH_RESULT;
    Register TEMP_RESULT;
    Register AFE_STATUS;
    Register SYS_STATUS;
    Register TEST_CONFIG;
	Register OSC_MONITOR;
	Register MAG_GAIN_CONFIG;
	Register MAG_OFFSET_CONFIG;
	Register ANGLE_RESULT;
	Register MAGNITUDE_RESULT;

}Sensor;



void writeToRegister(uint16_t* pRegData,REGISTER_FEATURE pos,uint16_t value);
Sensor sensor_init(uint8_t adr);
void sensor_power_on();
void sensor_power_off();
void deactivateSCLR();
uint8_t calc_crc(REGISTER_ADR adr,uint16_t* data);
uint16_t read_register(Sensor* sen,REGISTER_ADR reg);
uint32_t registersAreSet(uint16_t* testReg);
void read_test_reg(Sensor* sen);
void device_config(Sensor* sen);
void sensor_config(Sensor* sen);
void system_config(Sensor* sen);
void select_sensor(uint8_t adr);
void deselect_sensor();
void clear_sh_reg();
void set_sh_reg_OE(uint32_t value);
void measuringLED();
void errorLED();
void statusLED();
void read_sensor_data(Sensor *sen);


#endif


