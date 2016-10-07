/*
 * main.cpp
 *
 *  Created on: Sep 8, 2016
 *      Author: mono
 */

#include <iostream>
#include <unistd.h>
#include "uart.h"
#include <string.h> // memcpy
#include <stdlib.h> //realloc

using namespace std;

int main(void) {
	CompCom rp6;
	time_t startTime = time(0);
	double byte;
	while(true){
	rp6.SendMotionCommand(20,'F');
	while(rp6.isMove){rp6.SendPoseRequest(); byte=byte+12;};
	rp6.SendMotionCommand(45,'L');
	while(rp6.isMove){rp6.SendPoseRequest();byte=byte+12;};
	rp6.SendMotionCommand(45,'R');
	while(rp6.isMove){rp6.SendPoseRequest();byte=byte+12;};
	cout<<byte/difftime( time(0), startTime)<<endl;
	}
}


