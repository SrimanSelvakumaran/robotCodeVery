#pragma config(Motor,  port2,           leftMotor1,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           leftMotor2,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           rightMotor1,   tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           rightMotor2,   tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           flipper,       tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           belt,          tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,          flipperMover,  tmotorVex393_HBridge, openLoop, reversed)
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

void pre_auton()
{
	// Set bStopTasksBetweenModes to false if you want to keep user created tasks
	// running between Autonomous and Driver controlled modes. You will need to
	// manage all user created tasks if set to false.
	bStopTasksBetweenModes = true;

	// Set bDisplayCompetitionStatusOnLcd to false if you don't want the LCD
	// used by the competition include file, for example, you might want
	// to display your team name on the LCD in this function.
	// bDisplayCompetitionStatusOnLcd = false;

	// All activities that occur before the competition starts
	// Example: clearing encoders, setting servo positions, ...

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

task autonomous()
{
	// ..........................................................................
	// Insert user code here.
	// ..........................................................................

	// Remove this function call once you have "real" code.
	AutonomousCodePlaceholderForTesting();
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

task usercontrol()
{
	while (true) {
		motor[leftMotor1] = vexRT[Ch2];// + vexRT[Ch4];
		motor[leftMotor2] = vexRT[Ch2];// + vexRT[Ch4];
		motor[leftMotorU1] = vexRT[Ch2];

		motor[rightMotor1] = vexRT[Ch3];// - vexRT[Ch4];
		motor[rightMotor2] = vexRT[Ch3];// - vexRT[Ch4];

		//motor[belt] = vexRT[AccelY];
		//sriman have big gay
		motor[flipperMover] = (vexRT[Btn6U]*128)-(vexRT[Btn6D]*128);
		motor[flipper] = (vexRT[Btn5U]*70)-(vexRT[Btn5D]*40);
		//motor[flipper] = vexRT[Ch2]/3;
	}

	/*	if (vexRT[Btn8U] == 1) {
	motor[flipper] = 128;
	}
	else {
	motor[flipper] = 0;
	}*/
}

void srimansWorseCode()
{
	int left;
	int right;
	int invert = 1;
	displayLCDCenteredString(0, "In Normal Mode");
	while (true)
	{
		//left = invert * (vexRT[Ch3]^3)/127^2;
		//right = invert * (vexRT[Ch2]^3)/127^2;
		right = vexRT[Ch2];
		left = vexRT[Ch3];
		motor[leftMotor1]  = left;
		motor[leftMotor2]  = left;
		motor[rightMotor1] = right;
		motor[rightMotor2] = right;

		if (vexRT[Btn5U] && vexRT[Btn6U] && invert == 1) {
			invert = -1;
			wait1Msec(100);
			displayLCDCenteredString(0, "In Reverse Mode");
		}
		else if (vexRT[Btn5U] && vexRT[Btn6U] && invert == -1) {
			invert = 1;
			wait1Msec(100);
			displayLCDCenteredString(0, "In Normal Mode");
		}
	}
}

void srimansEvenWorseCode() {
	bool tank = true;
	while (true) {
		motor[flipperMover] = (vexRT[Btn6U]*128)-(vexRT[Btn6D]*128);
		motor[flipper] = (vexRT[Btn5U]*70)-(vexRT[Btn5D]*40);
		switch (tank) {
		case true:
			motor[leftMotor1] = vexRT[Ch2];// + vexRT[Ch4];
			motor[leftMotor2] = vexRT[Ch2];// + vexRT[Ch4];
			motor[rightMotor1] = vexRT[Ch3];// - vexRT[Ch4];
			motor[rightMotor2] = vexRT[Ch3];// - vexRT[Ch4];
			break;
		default:
			motor[leftMotor1] = vexRT[Ch3] + vexRT[Ch4];
			motor[leftMotor2] = vexRT[Ch3] + vexRT[Ch4];
			motor[rightMotor1] = vexRT[Ch3] - vexRT[Ch4];
			motor[rightMotor2] = vexRT[Ch3] - vexRT[Ch4];
			break;
		}
	}
}
