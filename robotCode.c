#pragma config(Sensor, in1,    lightboi,              sensorReflection)
#pragma config(Motor,  port2,           leftMotor1,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           leftMotor2,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           rightMotor1,   tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           rightMotor2,   tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           flipper,       tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           spinnythingy,  tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,          flipperShaft,  tmotorVex393_HBridge, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*        Description: Competition template for VEX EDR                      */
/*                                                                           */
/*---------------------------------------------------------------------------*/

// This code is for the VEX cortex platform
#pragma platform(VEX2)

// Select Download method as "competition"
#pragma competitionControl(Competition)

//Main competition background code...do not modify!
#include "Vex_Competition_Includes.c"

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the cortex has been powered on and    */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

const short leftButton = 1;
const short centerButton = 2;
const short rightButton = 4;
const int threshold = 16;
int count = 0;


void waitForPress() {
	while(nLCDButtons == 0){}
	wait1Msec(5);
}

void waitForRelease() {
	while(nLCDButtons != 0){}
	wait1Msec(5);
}
void setMotors(float speedLeft, float speedRight) {
	motor[rightMotor1] = speedRight;
	motor[rightMotor2] = speedRight;
	motor[leftMotor1] = speedLeft;
	motor[leftMotor2] = speedLeft;
}

void pre_auton() {
	//------------- Beginning of User Interface Code ---------------
	//Clear LCD
	clearLCDLine(0);
	clearLCDLine(1);
	//Loop while center button is not pressed
	while(nLCDButtons != centerButton) {
		//Switch case that allows the user to choose from 4 different options
		switch(count) {
		case 0:
			//Display first choice
			displayLCDCenteredString(0, "No Movements");
			displayLCDCenteredString(1, "<     Enter    >");
			waitForPress();
			//Increment or decrement "count" based on button press
			if(nLCDButtons == leftButton) {
				waitForRelease();
				count = 4;
			}
			else if(nLCDButtons == rightButton) {
				waitForRelease();
				count++;
			}
			break;
		case 1:
			//Display second choice
			displayLCDCenteredString(0, "Cap Diagonal- Fwd");
			displayLCDCenteredString(1, "<     Enter    >");
			waitForPress();
			//Increment or decrement "count" based on button press
			if(nLCDButtons == leftButton) {
				waitForRelease();
				count--;
			}
			else if(nLCDButtons == rightButton) {
				waitForRelease();
				count++;
			}
			break;
		case 2:
			//Display third choice
			displayLCDCenteredString(0, "Flag- Bkwd");
			displayLCDCenteredString(1, "<     Enter    >");
			waitForPress();
			//Increment or decrement "count" based on button press
			if(nLCDButtons == leftButton) {
				waitForRelease();
				count--;
			}
			else if(nLCDButtons == rightButton) {
				waitForRelease();
				count++;
			}
			break;
		case 3:
			//Display fourth choice
			displayLCDCenteredString(0, "Cap Fwd- Bkwd");
			displayLCDCenteredString(1, "<     Enter    >");
			waitForPress();
			//Increment or decrement "count" based on button press
			if(nLCDButtons == leftButton) {
				waitForRelease();
				count--;
			}
			else if(nLCDButtons == rightButton) {
				waitForRelease();
				count++;
			}
			break;
		case 4:
			//Display fourth choice
			displayLCDCenteredString(0, "Skills");
			displayLCDCenteredString(1, "<     Enter    >");
			waitForPress();
			//Increment or decrement "count" based on button press
			if(nLCDButtons == leftButton) {
				waitForRelease();
				count--;
			}
			else if(nLCDButtons == rightButton) {
				waitForRelease();
				count = 0;
			}
			break;
		}
	}
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

task autonomous() {
	clearLCDLine(0);
	clearLCDLine(1);
	switch(count) {
	case 1: //Cap Diagnal (Forwards)
		setMotors(-128,-128);
		motor[spinnythingy] = 128;
		while(SensorValue(lightboi) > 490) 
			wait1Msec(10);
		setMotors(128,128);
		wait1Msec(500);
		setMotors(0,0);
		break;
	case 2: // Right Side Flag (Backwards
		motor[flipper] = -128;
		wait1Msec(1500);
		motor[flipper] = 0;
		setMotors(128,128);
		wait1Msec(5000);
		setMotors(-128,-128);
		wait1Msec(1000);
		setMotors(0,0);
		break;

	case 3: //Forwards Cap
		setMotors(-128,-128);
		wait1Msec(1000);
		setMotors(0,0);
		wait1Msec(250);
		motor[flipperShaft] = 128;
		wait1Msec(1000);
		motor[flipperShaft] = 0;
		motor[flipper] = -72;
		wait1Msec(250);
		motor[flipper] = 0;
		break;
	case 4:
		setMotors(-128,-128);
		motor[spinnythingy] = 128;
		wait1Msec(5000);
		setMotors(128, -128);
		wait1Msec(500);
		setMotors(-128,-128);
		wait1Msec(1000);
		setMotors(128,128);
		break;
	}
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                       46	q                    */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/
task showBattery() {
	string mainBattery;
	while (true) {
		displayLCDString(0, 0, "Primary: ");
		sprintf(mainBattery, "%1.2f%c", nImmediateBatteryLevel/1000.0,'V'); //Build the value to be displayed
		displayNextLCDString(mainBattery);
		wait1Msec(100);
	}
}

task usercontrol() {
	int finalA = 128;
	startTask(showBattery);
	while (true) {
		if(vexRT[Btn8U] == 0) {
			if(abs(vexRT[Ch3]) >= threshold) {
				motor[leftMotor1] = -vexRT[Ch3];// (vexRT[Btn8U] * finalA);// + vexRT[Ch4];
				motor[leftMotor2] = -vexRT[Ch3];// (vexRT[Btn8U] * finalA);// + vexRT[Ch4];
			} else {
				motor[leftMotor1] = 0;
				motor[leftMotor2] = 0;
			}
			if(abs(vexRT[Ch2]) >= threshold) {
				motor[rightMotor1] = -vexRT[Ch2]; //(vexRT[Btn8U] * finalA);// - vexRT[C h4];
				motor[rightMotor2] = -vexRT[Ch2];// (vexRT[Btn8U] * finalA);// - vexRT[Ch4]; //for tank controls
			} else {
				motor[rightMotor1] = 0;
				motor[rightMotor2] = 0;
			}
		} else {
			setMotors(-finalA,-finalA);
		}
		motor[flipperShaft] = (vexRT[Btn6U] - vexRT[Btn6D])*128;
		motor[flipper] = (vexRT[Btn5U] - vexRT[Btn5D])*128*2/3;
		motor[spinnythingy] = (vexRT[Btn8U] + vexRT[Btn8D] - vexRT[Btn7D])*128;
		//if(SensorValue(lightboi) < 490) {
		//	setMotors(128,128);
		//	wait1Msec(500);
		//	setMotors(0,0);
		//	wait1Msec(10000);
		//}
		//motor[rotX] = (vexRT[Btn7R]*64)-(vexRT[Btn7L]*128);
		//motor[rotY1] = (vexRT[Btn7U]*40)-(vexRT[Btn7D]*40);
		//motor[rotY2] = (vexRT[Btn7U]*40)-(vexRT[Btn7D]*40);
		//motor[flipper] = vexRT[Ch2]/3;
	}
}
