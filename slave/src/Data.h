/*
 * Data.h
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

#ifndef __DATA_H_INCLUDED__		//If this library is not defined..
#define __DATA_H_INCLUDED__		//Define this variable and read the code


class Data { 

	public:
		Data();				//Constructor

		union{				//union to allow the data array to be accessed as a char
			int dataArray[10];
			unsigned char packet;
		} dataUnion;

		unsigned long int timeSince();	//returns time since last collect

		unsigned char * returnData(int* dataArray);	//returns a pointer to an array of
		void returnData(int * dataArray, int index);	//newest or specified index

		void saveData();				//writes to the SD card
		void readSensorData();			//reads from the sensors


		void setAltiPin(int pin);		//Public methods to set 
		void setHumiPin(int pin);		//private variables
		void setPresPin(int pin);		//They only accept valid pins 0-64
		void setTempPin(int pin);
		void setCO2Pin(int pin);
		void setN2OPin(int pin);
		void setCOPin(int pin);
		void setIRPin(int pin);
		void setUVPin(int pin);
		void setO3Pin(int pin);
		
		void initPins();				//sets pinMode to input for pins

	private:

		union{
			unsigned long int timeCollect;	//milliseconds
			int timeArray[2];				//to make concatenation easy
		};

		int temp, pres, alti, humi;		//Private variables to hold sensor
		int CO2, CO, N2O, UV, O3, IR;		//values for different measurements

		int sensorPin[30];				//Array to hold the sensor pins
									//Shrink once # of pins is certain
		union {
			unsigned long int index;		//Holds current collection index
			int indexArray[2];		//<----So we can throw it around easily
		};

		void readTemp();			//these functions should be private
		void readAlti();			//and called by readSensorData()
		void readHumi();			//Each group should customize that
		void readPres();			//function to only call the needed
		void readCO2();			//read****() for their project
		void readN2O();
		void readCO();
		void readIR();
		void readO3();
		void readUV();

		void reset();					//resets all readings to null
};

#endif
