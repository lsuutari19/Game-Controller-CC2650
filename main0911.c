/*
MENU toimii pl. QUIT ei vielä tee mitään
TO-DO:
-lisää musa takaisin(ehkä eri filuun)
-implementoi QUIT
-siisti koodia
*/

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



/* Board Header files */
#include "Board.h"
#include "sensors/mpu9250.h"


#define STACKSIZE 2048
Char taskStack[STACKSIZE];


// MPU GLOBAL VARIABLES

static PIN_Handle hMpuPin;
static PIN_State MpuPinState;
static PIN_Config MpuPinConfig[] = {
    Board_MPU_POWER  | PIN_GPIO_OUTPUT_EN | PIN_GPIO_HIGH | PIN_PUSHPULL | PIN_DRVSTR_MAX,
    PIN_TERMINATE
};


//napeille vaadittavat alustukset

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


// Tilaesittelyt
enum state { WAIT=1, DOWN, UP, LEFT, RIGHT, PLAY, QUIT};
enum state myState = PLAY;

enum boolean { F=1, T };
enum boolean updateScreen = F;

// Anturien käsittely
Void displayTask(UArg arg0, UArg arg1) {

//	if(myState == WAIT) {
		Display_clear(displayHandle);
		if (myState == DOWN) {
			Display_print0(displayHandle, 5, 5, "DOWN");
			System_printf("DOWN \n");
			System_flush();
			myState = WAIT;
		} else if (myState == UP) {

			Display_print0(displayHandle, 5, 5, "UP");
			System_printf("UP \n");
			System_flush();
			myState = WAIT;

		} else if (myState == RIGHT) {

			Display_print0(displayHandle, 5, 5, "RIGHT");
			System_printf("RIGHT \n");
			System_flush();
			myState = WAIT;

		} else if (myState == LEFT) {

			Display_print0(displayHandle, 5, 5, "LEFT");
			System_printf("LEFT \n");
			System_flush();
			myState = WAIT;
		}
 //   }
	Task_sleep(1000000 / Clock_tickPeriod);
    Display_clear(displayHandle);
}

// SENSOR TASK
Void sensorTask(UArg arg0, UArg arg1) {

	float ax, ay, az, gx, gy, gz;
	Display_Params params; //näytön parametrit alustetaan näyttö
	Display_Params_init(&params);
	params.lineClearMode = DISPLAY_CLEAR_BOTH;

	displayHandle = Display_open(Display_Type_LCD, &params);
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

    // MPU CLOSE I2C

    I2C_close(i2cMPU);

    Display_clear(displayHandle);
	while (1) {
		if(myState == WAIT) {
			i2cMPU = I2C_open(Board_I2C, &i2cMPUParams);
			if (i2cMPU == NULL) {
				System_abort("Error Initializing I2CMPU\n");
			}

			mpu9250_get_data(&i2cMPU, &ax, &ay, &az, &gx, &gy, &gz);
			if(gx < -75)
			{
				System_flush();
				myState = DOWN;
				displayTask(arg0, arg1);
			} else if (gx > 75)
			{
				myState = UP;
				displayTask(arg0, arg1);
			} else if (gy < -75)
			{
				myState = LEFT;
				displayTask(arg0, arg1);
			} else if (gy > 75)
			{
				myState = RIGHT;
				displayTask(arg0, arg1);
			}
			I2C_close(i2cMPU);
		}
//		Task_sleep(100000 / Clock_tickPeriod);
		if(myState != WAIT){
			if(updateScreen == T)
			{
				if(myState == PLAY)
				{
					Display_print0(displayHandle, 5, 5, "->PLAY");
					Display_print0(displayHandle, 6, 5, "QUIT");
					System_flush();
				}
				else if(myState == QUIT)
				{
					Display_print0(displayHandle, 5, 5, "PLAY");
					Display_print0(displayHandle, 6, 5, "->QUIT");
					System_flush();
				}
			}
		}
    }
//    PIN_setOutputValue(hMpuPin,Board_MPU_POWER, Board_MPU_POWER_OFF);
}




void buttonFxn(PIN_Handle handle, PIN_Id pinId) { 	//Button0

	if(myState == PLAY)
	{
	    myState = WAIT;
		System_printf("buttonFxn PLAY -> WAIT \n");
		System_flush();
    } else if(myState == QUIT)
    {
    	myState = PLAY;
		System_printf("buttonFxn QUIT -> PLAY \n");
		System_flush();
    }
}


void menuFxn(PIN_Handle handle, PIN_Id pinId) { 	//Button1

	if(myState == PLAY)
	{
		myState = QUIT;
		updateScreen = T;
		System_printf("menuFxn PLAY -> QUIT \n");
		System_flush();
	}
	else if(myState == QUIT)
	{
		myState = PLAY;
		updateScreen = T;
		System_printf("menuFxn QUIT -> PLAY \n");
		System_flush();
	}
}


int main(void) {

	Task_Handle task;
	Task_Params taskParams;
    Board_initGeneral();
    Board_initI2C();

    //Board_BUTTON:ien pinnien avaus käyttöön
    buttonHandle = PIN_open(&buttonState, buttonConfig);
    if (PIN_registerIntCb(buttonHandle, &buttonFxn) != 0) {
       System_abort("Error registering button callback function");
    }
    button1Handle = PIN_open(&button1State, button1Config);
    if (PIN_registerIntCb(button1Handle, &menuFxn) != 0) {
       System_abort("Error registering button callback function");
    }
    // Avataan MPU pin
    hMpuPin = PIN_open(&MpuPinState, MpuPinConfig);
    if (hMpuPin == NULL) {
    	System_abort("Pin open failed!");
    }

    //alustetaan sensorTask
    Task_Params_init(&taskParams);
    taskParams.stackSize = STACKSIZE;
    taskParams.stack = &taskStack;
    task = Task_create((Task_FuncPtr)sensorTask, &taskParams, NULL);
    if (task == NULL) {
    	System_abort("Task create failed!");
    }

    /* Start BIOS */
    BIOS_start();

    return (0);
}

