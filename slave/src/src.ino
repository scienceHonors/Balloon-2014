/*
 * slave.cc
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

#define BAUD 9600


#include "../lib/MD5.h"
#include "../lib/MD5.cpp"
#include "../lib/Borp.h"
#include "../lib/Borp.cc"
#include "../lib/Data.h"
#include "../lib/Data.cc"

void setup(){
	Serial.begin(BAUD);
	point.setTempPin(14);
}

void loop(){
	//while (time<alloted){
	//	check for connection request
	//	}
	//send feedback to master
	//collect data
	//write data
	//if (connection == 1){
	//	check for data request
	//	prepare data
	//	send data
	//	}
//	point.readSensorData(); //Fill in collected data baszed on group.
//	Borp radio(1,9600);	//Baud rate and pin should be hardcoded by each group.
//	radio.phoneHome(point.returnData());

	//This is to test the functions of the data library

	point.readSensorData();
	int array[50] = {0};
	point.returnData(array);
	for(int i = 0; i < 25; i++){
//		Serial.print(array[i]);
	}
	Serial.println(point.timeCollect);


//Below is a load of code designed to test the ability to copy between pointers
	int shorta[4] = {0};
	long int cool = 23758239475;
	memcpy(&shorta, &cool, 4);
	Serial.println(shorta[0]);
	Serial.println(shorta[1]);
	Serial.println(shorta[2]);
	Serial.println(shorta[3]);

//This just waits until the time to the last collect is equal to PERIOD
	while((millis() - point.timeCollect)<PERIOD){}
}






