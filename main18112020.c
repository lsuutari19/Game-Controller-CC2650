/*
 * Lauri Suutari and Mikael Pennanen
 * Course: Johdatus Tietokonejärjestelmiin harjoitustyö 2020
 *
 * Most of the basics of TI CC2650 obtained from:
 * -Johdatus Tietokonejärjestelmiin course
 * -TI Resources
 *
 * Music notes obtained from https://github.com/xitangg/-Pirates-of-the-Caribbean-Theme-Song/
 blob/master/Pirates_of_the_Caribbean_-_Theme_Song.ino
 *
 */

//REMEMBER TO DELETE TEST SYSTEMPRINTS
// tee musiikki alkamaan F statesta että se lähtee käyntiin vain jos state muutetaan T:ksi

#include <stdio.h>
#include <string.h>

/* XDCtools Header files */
#include <xdc/std.h>
#include <xdc/runtime/System.h>
#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Clock.h>
#include <ti/sysbios/knl/Task.h>
#include <ti/drivers/I2C.h>
#include <ti/drivers/i2c/I2CCC26XX.h>
#include <ti/drivers/PIN.h>
#include <ti/drivers/pin/PINCC26XX.h>
#include <ti/mw/display/Display.h>
#include <ti/drivers/Power.h>
#include <ti/drivers/power/PowerCC26XX.h>
#include <ti/drivers/pin/PINCC26XX.h>
#include <driverlib/timer.h>
#include <buzzer.h>
#include "wireless/CWC_CC2650_154Drv.h"
#include "wireless/address.h"
#include <picture.h>

/* Board Header files */
#include "Board.h"
#include "sensors/mpu9250.h"
#include "wireless/comm_lib.h"
#include <ti/mw/display/DisplayExt.h>

#define _BUZZER_H_
#define BUZZER_FREQ_MIN            3
#define BUZZER_FREQ_MAX            8000

//Defining note frequency
#define C4  262
#define D4  294
#define E4  330
#define F4  349
#define G4  392
#define A4  440
#define B4  494
#define C5  523
#define D5  587
#define E5  659
#define F5  698
#define G5  784
#define A5  880
#define B5  988

#define STACKSIZE 2048
#define small_STACKSIZE 1024
Char taskStack[STACKSIZE];
Char musicStack[small_STACKSIZE];
Char commStack[small_STACKSIZE];
Char displayStack[STACKSIZE];


// MPU GLOBAL VARIABLES

static PIN_Handle hMpuPin;
static PIN_State MpuPinState;
static PIN_Config MpuPinConfig[] = {
    Board_MPU_POWER  | PIN_GPIO_OUTPUT_EN | PIN_GPIO_HIGH | PIN_PUSHPULL | PIN_DRVSTR_MAX,
    PIN_TERMINATE
};


//BUTTON

static PIN_Handle buttonHandle;
static PIN_State buttonState;
PIN_Config buttonConfig[] = {
   Board_BUTTON0  | PIN_INPUT_EN | PIN_PULLUP | PIN_IRQ_NEGEDGE,
   PIN_TERMINATE
};

static PIN_Handle button1Handle;
static PIN_State button1State;
PIN_Config button1Config[] = {
   Board_BUTTON1  | PIN_INPUT_EN | PIN_PULLUP | PIN_IRQ_NEGEDGE,
   PIN_TERMINATE
};


// display handle setup
Display_Handle displayHandle;


// MPU USES ITS OWN I2C INTERFACE

static const I2CCC26XX_I2CPinCfg i2cMPUCfg = {
    .pinSDA = Board_I2C0_SDA1,
    .pinSCL = Board_I2C0_SCL1
};

// BUZZER
static PIN_Handle hBuzzer;
static PIN_State sBuzzer;
PIN_Config cBuzzer[] = {
  Board_BUZZER | PIN_GPIO_OUTPUT_EN,
  PIN_TERMINATE
};



// States
enum state { WAIT=1, DOWN, UP, LEFT, RIGHT, PLAY, MUSIC, MUTE, WINGAME, LOSE};
enum state myState = PLAY;

enum boolean { F=1, T };
enum boolean updateScreen = F;
enum boolean musicState = T;


//commTask sends output of the code to a receiving machine
Void commTask(UArg arg0, UArg arg1) {
   char message[16];
   uint16_t senderAddr;


   int32_t result = StartReceive6LoWPAN();
   if(result != true) {
      System_abort("Wireless receive start failed");
   }

   while (true) {
        if (GetRXFlag()) {  //tässä pitäisi olla GetRXFlag()
           memset(message,0,16);
           Receive6LoWPAN(&senderAddr, message, 16);

			   if(message == "70,LOST GAME"){

				   myState = LOSE;

			   } else if (message == "70,WIN"){

				   myState = WINGAME;

			   }
           System_printf(message);
           System_flush();
        }
    }
}


// This task compares the values from sensorTask and prints to screen accordingly
Void displayTask(UArg arg0, UArg arg1) {

    	Display_Params displayParams;
    	Display_Params_init(&displayParams);
    	displayParams.lineClearMode = DISPLAY_CLEAR_BOTH;
    	displayHandle = Display_open(Display_Type_LCD, &displayParams);
		tContext *pContext = DisplayExt_getGrlibContext(displayHandle);
		Display_clear(displayHandle);
		GrClearDisplay(pContext);
		StartReceive6LoWPAN();
		while(1) {
			if(myState != WAIT){
				if(updateScreen == T)
				{
					Display_clear(displayHandle);
					if(myState == PLAY)
					{
						Display_print0(displayHandle, 5, 5, "->PLAY");
						Display_print0(displayHandle, 6, 5, "MUSIC");
						System_flush();
					}
					else if(myState == MUSIC)
					{
						Display_print0(displayHandle, 5, 5, "PLAY");
						Display_print0(displayHandle, 6, 5, "->MUSIC");
						System_flush();
					}
				updateScreen = F;
				}
			}

			if (myState == DOWN) {
				GrImageDraw(pContext, &down, 0, 0);
				char message[16] = "event:DOWN";
	//			Send6LoWPAN(IEEE80154_SERVER_ADDR, message, strlen(message));
				System_printf("DOWN \n");
				GrFlush(pContext);
				System_flush();
				myState = WAIT;
				Task_sleep(1000000 / Clock_tickPeriod);
	//			StartReceive6LoWPAN();
				GrClearDisplay(pContext);


			} else if (myState == UP) {
				GrImageDraw(pContext, &up, 0, 0);
				char message[16] = "event:UP";
				System_printf("UP \n");
				GrFlush(pContext);
				System_flush();
		//		Send6LoWPAN(IEEE80154_SERVER_ADDR, message, strlen(message));
				myState = WAIT;
				Task_sleep(1000000 / Clock_tickPeriod);
				GrClearDisplay(pContext);
		//		StartReceive6LoWPAN();


			} else if (myState == RIGHT) {
				GrImageDraw(pContext, &right, 0, 0);
				char message[16] = "event:RIGHT";
				System_printf("RIGHT \n");
				GrFlush(pContext);
				System_flush();
		//		Send6LoWPAN(IEEE80154_SERVER_ADDR, message, strlen(message));
				myState = WAIT;
				Task_sleep(1000000 / Clock_tickPeriod);
				GrClearDisplay(pContext);
		//		StartReceive6LoWPAN();
			} else if (myState == LEFT) {
				GrImageDraw(pContext, &left, 0, 0);
				char message[16] = "event:LEFT";
				System_printf("LEFT \n");
				GrFlush(pContext);
				System_flush();
		//		Send6LoWPAN(IEEE80154_SERVER_ADDR, message, strlen(message));
				myState = WAIT;
				Task_sleep(1000000 / Clock_tickPeriod);
				GrClearDisplay(pContext);
		//		StartReceive6LoWPAN();


			} else if(myState == LOSE){
				GrImageDraw(pContext, &lose, 0, 0);
				GrFlush(pContext);
				Task_sleep(10000000 / Clock_tickPeriod);
				myState = PLAY;
				StartReceive6LoWPAN();

			} else if(myState == WINGAME) {
				GrImageDraw(pContext, &win, 0, 0);
				GrFlush(pContext);
				Task_sleep(10000000 / Clock_tickPeriod);
				myState = PLAY;
				StartReceive6LoWPAN();
			} else if (myState != PLAY && myState != MUSIC) {
				Display_print0(displayHandle, 0, 2, "waiting...");
				System_flush();
			}
	}
}


// SENSOR TASK
Void sensorTask(UArg arg0, UArg arg1) {

	float ax, ay, az, gx, gy, gz;


	I2C_Handle i2cMPU; // INTERFACE FOR MPU9250 SENSOR
	I2C_Params i2cMPUParams;
    I2C_Params_init(&i2cMPUParams);
    i2cMPUParams.bitRate = I2C_400kHz;
    i2cMPUParams.custom = (uintptr_t)&i2cMPUCfg;


    // MPU OPEN I2C
    i2cMPU = I2C_open(Board_I2C, &i2cMPUParams);
    if (i2cMPU == NULL) {
        System_abort("Error Initializing I2CMPU\n");
    }

    // MPU POWER ON
    PIN_setOutputValue(hMpuPin,Board_MPU_POWER, Board_MPU_POWER_ON);

    // WAIT 100MS FOR THE SENSOR TO POWER UP
	Task_sleep(100000 / Clock_tickPeriod);
    System_printf("MPU9250: Power ON\n");
    System_flush();

    // MPU9250 SETUP
	System_printf("MPU9250: Setup and calibration...\n");
	System_flush();

	mpu9250_setup(&i2cMPU);

	System_printf("MPU9250: Setup and calibration OK\n");
	System_flush();


	while (1) {
		if(myState == WAIT) {
			StartReceive6LoWPAN();
			mpu9250_get_data(&i2cMPU, &ax, &ay, &az, &gx, &gy, &gz);

			if(gx < -85)
			{
				myState = DOWN;
				char message[16] = "event:DOWN";
				Send6LoWPAN(IEEE80154_SERVER_ADDR, message, strlen(message));
				StartReceive6LoWPAN();
				Task_sleep(1000000 / Clock_tickPeriod);
			} else if (gx > 85)
			{
				myState = UP;
				char message[16] = "event:UP";
				Send6LoWPAN(IEEE80154_SERVER_ADDR, message, strlen(message));
				StartReceive6LoWPAN();
				Task_sleep(1000000 / Clock_tickPeriod);
			} else if (gy < -85)
			{
				myState = LEFT;
				char message[16] = "event:LEFT";
				Send6LoWPAN(IEEE80154_SERVER_ADDR, message, strlen(message));
				StartReceive6LoWPAN();
				Task_sleep(1000000 / Clock_tickPeriod);
			} else if (gy > 85)
			{
				myState = RIGHT;
				char message[16] = "event:RIGHT";
				Send6LoWPAN(IEEE80154_SERVER_ADDR, message, strlen(message));
				StartReceive6LoWPAN();
				Task_sleep(1000000 / Clock_tickPeriod);
			}
		}
	Task_sleep(100000 / Clock_tickPeriod);
    }
}


void buttonFxn(PIN_Handle handle, PIN_Id pinId) { 	//Button0

	if(myState == PLAY)
	{
	    myState = WAIT;
		System_printf("buttonFxn PLAY -> WAIT \n");
		System_flush();

    } else if(myState == MUSIC)
    {
    	if (musicState == F){
    		System_printf("musicState F -> T \n");
    		System_flush();
    		musicState = T;

    	} else if (musicState == T)
    	{
    		System_printf("musicState T -> F \n");
    		System_flush();
    		musicState = F;

    	}
    	myState = PLAY;
		System_printf("buttonFxn MUSIC -> PLAY \n");
		System_flush();

    }  else if(myState == WAIT)
    {
    	myState = PLAY;
    	updateScreen = T;
    	System_printf("back to menu");
    	System_flush();
    }
}


void menuFxn(PIN_Handle handle, PIN_Id pinId) { 	//Button1

	if(myState == PLAY)
	{
		myState = MUSIC;
		updateScreen = T;
		System_printf("menuFxn PLAY -> MUSIC \n");
		System_flush();
	}
	else if(myState == MUSIC)
	{
		myState = PLAY;
		updateScreen = T;
		System_printf("menuFxn MUSIC -> PLAY \n");
		System_flush();
	}
}


int main(void) {

	Task_Handle task;
	Task_Params taskParams;
	Task_Handle mtask;
	Task_Params musicParams;
	Task_Handle displaytask;
	Task_Params displayParams;
    Task_Handle comtask;
	Task_Params commParams;
    Board_initGeneral();
    Board_initI2C();

    //setup buzzer
    hBuzzer = PIN_open(&sBuzzer, cBuzzer);
    if (hBuzzer == NULL) {
    	System_abort("Pin open failed!");
    }

    //Board_BUTTON:s opened
    buttonHandle = PIN_open(&buttonState, buttonConfig);
    if (PIN_registerIntCb(buttonHandle, &buttonFxn) != 0) {
       System_abort("Error registering button callback function");
    }

    button1Handle = PIN_open(&button1State, button1Config);
    if (PIN_registerIntCb(button1Handle, &menuFxn) != 0) {
       System_abort("Error registering button callback function");
    }

    // Open MPU_pin
    hMpuPin = PIN_open(&MpuPinState, MpuPinConfig);
    if (hMpuPin == NULL) {
    	System_abort("Pin open failed!");
    }

    Init6LoWPAN();

    //setup wireless communications
    Task_Params_init(&commParams);
    commParams.stackSize = STACKSIZE;
    commParams.stack = &commStack;
    commParams.priority = 1;
    comtask = Task_create(commTask, &commParams, NULL);
    if (comtask == NULL) {
    	System_abort("Music task create failed!");
    }


    //setup sensorTask
    Task_Params_init(&taskParams);
    taskParams.stackSize = STACKSIZE;
    taskParams.stack = &taskStack;
    taskParams.priority = 3;
    task = Task_create((Task_FuncPtr)sensorTask, &taskParams, NULL);
    if (task == NULL) {
    	System_abort("Task create failed!");
    }

    Task_Params_init(&displayParams);
    displayParams.stackSize = STACKSIZE;
    displayParams.stack = &displayStack;
    displayParams.priority = 2;
    displaytask = Task_create(displayTask, &displayParams, NULL);
    if (displaytask == NULL) {
    	System_abort("Display task create failed!");
    }


    /* Start BIOS */
    BIOS_start();

    return (0);
}



