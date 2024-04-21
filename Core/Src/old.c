
	//int16_t x_ch_result=0;
	//int32_t x_B=0;
	//uint16_t conv_status=0;
	//uint8_t rdy=0;
	//uint8_t xIsCurrent=0;
	//uint8_t message[2] = {0};
	//int i =0;

//Sensor sen1 = sensor_init(8);
	// if(sen1.ok){
//	  while(1)
//	  {
//		  HAL_UART_Receive(&huart4, &flag, 1, HAL_MAX_DELAY);
//
//		  while(1)
//		  {
//			  conv_status = read_register(&sen1, CONV_STATUS);
//			  rdy = (conv_status&(1<<13)) ? 1:0;
//			  xIsCurrent = (conv_status&(1<<8)) ? 1:0;
//			  if(rdy&&xIsCurrent)
//			  {
//				  break;
//			  }
//		  }
//
//		  if(rdy&&xIsCurrent)
//		  {
//			  measuringLED();
//			  x_ch_result = read_register(&sen1, X_CH_RESULT);
//			  x_B = ((int32_t)x_ch_result)*lsb;
//
//			  message[0] = (x_B >> 24) & 0xFF;
//			  message[1] = (x_B >> 16) & 0xFF;
//			  message[2] = (x_B >> 8) & 0xFF;
//			  message[3] = x_B & 0xFF;
//
//			  HAL_UART_Transmit(&huart4, message, 4, 10);
//			  //HAL_Delay(10);
//			  i++;
//		  }
//
//	  }
	/* -------------Funk�?ní verze-------------------
	uint16_t conv_status = 0;
	uint8_t rdy = 0;
	uint8_t dataAreCurrent = 0;
	uint8_t num_of_sensors = 8;
	Sensor* sensors = (Sensor*) malloc(sizeof(Sensor) * num_of_sensors);

	sensor_power_on();
	HAL_Delay(250);

	deactivateSCLR();
	HAL_Delay(250);

	for (int i = 0; i < (num_of_sensors); i++) {
		if (i == 3)
			continue;

		sensors[i] = sensor_init(i + 1);
		if (!(sensors[i].ok)) {
			while (1) {
				errorLED();
				HAL_Delay(200);
			}
		}
	}

	while (1) {
		uint8_t flag = 0;

		for (int sen = 0; sen < (num_of_sensors); sen++) {
			statusLED();
			HAL_UART_Receive(&huart4, &flag, 1, HAL_MAX_DELAY);
			statusLED();
			if (sen == 3)
				continue;
			if (sensors[sen].ok) {
				do {
					conv_status = read_register(&sensors[sen], CONV_STATUS);
					rdy = conv_status & (1 << 13) ? 1 : 0;
					dataAreCurrent = conv_status & (0x07 << 8) ? 1 : 0;
				} while (!(dataAreCurrent && rdy));

				int32_t lsb = (2 * RANGE * 1000000) / (1 << 16); //LSB in nT
				measuringLED();

				int16_t x_result = read_register(&sensors[sen], X_CH_RESULT);
				int16_t y_result = read_register(&sensors[sen], Y_CH_RESULT);
				int16_t z_result = read_register(&sensors[sen], Z_CH_RESULT);

				sensors[sen].measured_data.x_B = ((int32_t) x_result) * lsb;
				sensors[sen].measured_data.y_B = ((int32_t) y_result) * lsb;
				sensors[sen].measured_data.z_B = ((int32_t) z_result) * lsb;

//				  sensors[sen].measured_data.x_B = (int32_t)(51);
//				  sensors[sen].measured_data.y_B = (int32_t)(52);
//				  sensors[sen].measured_data.z_B = (int32_t)(53);

				uint8_t* message = (uint8_t*) malloc(sizeof(MeasuredData));
				if (message == NULL)
					errorLED();
				uint8_t meas_rdy = 35;
				memcpy(message, &(sensors[sen].measured_data),
						sizeof(MeasuredData));
				HAL_UART_Transmit(&huart4, &meas_rdy, sizeof(uint8_t),
						HAL_MAX_DELAY);
				HAL_UART_Transmit(&huart4, message, sizeof(MeasuredData),
						HAL_MAX_DELAY);
				free(message);
			} else {
				while (1) {
					errorLED();
				}
			}
		}
	}
	free(sensors);
------------------------------------------------------------------*/

// -----Konzultace s Lufinkou----------------
	/*----------Select Sensor-------------*/
	/*
	 sensor_power_on();
	 set_sh_reg_OE(1);
	 sen1.adr = 1;
	 select_sensor(sen1.adr);
	 HAL_Delay(1);
	 set_sh_reg_OE(0);
	 */
	//sen1 = sensor_init(0x02);
	//HAL_SPI_Transmit(&hspi1, crc_disable, 4, 50);
	//crc_disable[0] = 0x8F;
	//uint8_t crc = calc_crc(0x0F, 0);
	//uint8_t adress[4] = {0x8F,0,0,crc};
	/*-----Disable CRC ----------------------------
	 uint8_t crc_disable[4] = {0x0F,0x00,0x04,0x07};
	 HAL_SPI_TransmitReceive(&hspi1, crc_disable, reg_data, 4, 50);
	 HAL_Delay(1);
	 ----------------------------------------------------------*/

	/*---------Select another sensor--------------
	 clear_sh_reg();
	 set_sh_reg_OE(1);
	 sen1.adr = 0;
	 select_sensor(sen1.adr);
	 HAL_Delay(1);
	 set_sh_reg_OE(0);

	 clear_sh_reg();
	 set_sh_reg_OE(1);
	 sen1.adr = 8;
	 select_sensor(sen1.adr);
	 HAL_Delay(1);
	 set_sh_reg_OE(0);

	 ----------------------------------------------*/

	/*----------------Read Sensor----------------
	 crc_disable[0] = 0x8F;
	 crc_disable[1] = 0;
	 crc_disable[2] = 0;
	 crc_disable[3] = 0;
	 HAL_SPI_TransmitReceive(&hspi1,crc_disable ,reg_data , 4, 50);
	 HAL_Delay(1);


	 clear_sh_reg();
	 set_sh_reg_OE(1);
	 sen1.adr = 0;
	 select_sensor(sen1.adr);
	 HAL_Delay(1);
	 set_sh_reg_OE(0);
	 ---------------------------------------------------*/

	//uint16_t result = reg_data[1] + reg_data[2];
	//adress[0] = 0x0F;
	//crc_disable[3] = calc_crc(adress[0], &crc_disable[2]);
//  HAL_SPI_Transmit(&hspi1,crc_disable, 4, 50);
//  adress[0] = 0x8F;
//  HAL_SPI_TransmitReceive(&hspi1, adress, reg_data, 4, 50);
//  result = reg_data[1] + reg_data[2];
	//reg_data = spi_read_reg(sen1.DEVICE_CONFIG.adr, &stat);
	//displayTempData(reg_data);
