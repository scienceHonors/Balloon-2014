/*
 * Data.cc
 * This file is part of Borp
 *
 * Copyright (C) 2014 - Houghton College Science Honors
 *
 * Borp is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * Borp is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Borp. If not, see <http://www.gnu.org/licenses/>.
 */

#define DATACOUNT 9					//number of sensors being read

#include "Data.h"
#include "Arduino.h"

////////////////////////////////////////////////////////////////////////////////
//Constructor to initialize and rest function

Data::Data(){
	//constructor to initialize to -1
	reset();
}

void Data::reset(){
	//Set the readings to sentinal value
	temp = -1;
	alti = -1;
	pres = -1;
	humi = -1;
	CO2 = -1;
	CO = -1;
	N2O = -1;
	UV = -1;
	O3 = -1;

	index++;						//increment the index by 1 on
}

//End initialize/reset
//****************************************************************************//



////////////////////////////////////////////////////////////////////////////////
//Functions to return data (to pass to borp, etc.)

void Data::returnData(int * dataArray){

	//Makes an int array with the size representing the number of readings

	dataArray[0] = indexArray[0];
	dataArray[1] = indexArray[1];
	dataArray[2] = timeArray[0];
	dataArray[3] = timeArray[1];
	dataArray[4] = temp;
	dataArray[5] = alti;
	dataArray[6] = pres;
	dataArray[7] = humi;
	dataArray[8] = CO2;
	dataArray[9] = CO;
	dataArray[10] = N2O;
	dataArray[11] = UV;
	dataArray[12] = O3;
	return;

}

void Data::returnData(int * dataArray, int index){
		returnData(dataArray);				//return newest reading
		//retrieves data point with a certain index
		//it probably is on the SD card, could be on the EEPROM
}

//End return data functions
//****************************************************************************//


////////////////////////////////////////////////////////////////////////////////
//Functions for reading the data

void Data::readSensorData(){
	timeCollect = millis();
	readTemp();
}

void Data::readTemp(){
	temp = analogRead(sensorPin[0]);
}

void Data::readAlti(){
	//read from the sensor and write to **** variable
}

void Data::readHumi(){
	//read from the sensor and write to **** variable
}

void Data::readPres(){
	//read from the sensor and write to **** variable
}

void Data::readCO2(){
	//read from the sensor and write to **** variable
}

void Data::readN2O(){
	//read from the sensor and write to **** variable
}

void Data::readCO(){
	//read from the sensor and write to **** variable
}

void Data::readIR(){
	//read from the sensor and write to **** variable
}

void Data::readO3(){
	//read from the sensor and write to **** variable
}

//End read functions
//****************************************************************************//



////////////////////////////////////////////////////////////////////////////////
//Below is a ridiculous number of functions. They are set functions for each of 
//the possible variables, continue at your own risk.

void Data::setTempPin(int pin){
	if((pin <= 65) && (pin >= 0 )){
		sensorPin[0] = pin;
	}else {
		Serial.print("Error: pin invalid, dummy:  ");
		Serial.println(pin);
	}
}

void Data::setAltiPin(int pin){
	if((pin <= 65) && (pin >= 0 )){
		sensorPin[1] = pin;
	}else {
		Serial.print("Error: pin invalid, dummy: ");
		Serial.println(pin);
	}
}

void Data::setPresPin(int pin){
	if((pin <= 65) && (pin >= 0 )){
		sensorPin[2] = pin;
	}else {
		Serial.print("Error: pin invalid, dummy: ");
		Serial.println(pin);
	}
}

void Data::setCO2Pin(int pin){
	if((pin <= 65) && (pin >= 0 )){
		sensorPin[3] = pin;
	}else {
		Serial.print("Error: pin invalid, dummy: ");
		Serial.println(pin);
	}
}

void Data::setCOPin(int pin){
	if((pin <= 65) && (pin >= 0 )){
		sensorPin[4] = pin;
	}else {
		Serial.print("Error: pin invalid, dummy: ");
		Serial.println(pin);
	}
}

void Data::setN2OPin(int pin){
	if((pin <= 65) && (pin >= 0 )){
		sensorPin[5] = pin;
	}else {
		Serial.print("Error: pin invalid, dummy: ");
		Serial.println(pin);
	}
}

void Data::setIRPin(int pin){
	if((pin <= 65) && (pin >= 0 )){
		sensorPin[6] = pin;
	}else {
		Serial.print("Error: pin invalid, dummy: ");
		Serial.println(pin);
	}
}

void Data::setHumiPin(int pin){
	if((pin <= 65) && (pin >= 0 )){
		sensorPin[7] = pin;
	}else {
		Serial.print("Error: pin invalid, dummy: ");
		Serial.println(pin);
	}
}

void Data::setUVPin(int pin){
	if((pin <= 65) && (pin >= 0 )){
		sensorPin[8] = pin;
	}else {
		Serial.print("Error: pin invalid, dummy: ");
		Serial.println(pin);
	}
}

//End set functions
//****************************************************************************//

