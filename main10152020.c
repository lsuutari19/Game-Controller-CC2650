
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

/* Board Header files */
#include "Board.h"
#include "sensors/mpu9250.h"

#define STACKSIZE 2048
Char taskStack[STACKSIZE];

// *******************************
//
// MPU GLOBAL VARIABLES
//
// *******************************
static PIN_Handle hMpuPin;
static PIN_State MpuPinState;
static PIN_Config MpuPinConfig[] = {
    Board_MPU_POWER  | PIN_GPIO_OUTPUT_EN | PIN_GPIO_HIGH | PIN_PUSHPULL | PIN_DRVSTR_MAX,
    PIN_TERMINATE
};

// ******************************
//
// MPU USES ITS OWN I2C INTERFACE
//
// ******************************
static const I2CCC26XX_I2CPinCfg i2cMPUCfg = {
    .pinSDA = Board_I2C0_SDA1,
    .pinSCL = Board_I2C0_SCL1
};

// SENSOR TASK
Void sensorFxn(UArg arg0, UArg arg1) {

    // *******************************
    //
    // IDEA IS TO USE THE TWO DIFFERENT
    // I2C INTERFACES IN ALTERNATING TURNS:
    // ...
    // 1. OPEN 1ST
    // 2. SETUP 1ST SENSOR
    // 3. CLOSE 1ST
    // 4. OPEN 2ND
    // 5. SETUP 2ND SENSOR
    // 6. CLOSE 2ND
    // ...
    // 7. OPEN 1ST
    // 8. READ 1ST SENSOR DATA
    // 9. CLOSE 1ST
    // 10. OPEN 2ND
    // 11. READ 2ND SENSOR DATA
    // 12. CLOSE 2ND
    // ...
    //
    // *******************************
	float ax, ay, az, gx, gy, gz;



	I2C_Handle i2cMPU; // INTERFACE FOR MPU9250 SENSOR
	I2C_Params i2cMPUParams;
    I2C_Params_init(&i2cMPUParams);
    i2cMPUParams.bitRate = I2C_400kHz;
    i2cMPUParams.custom = (uintptr_t)&i2cMPUCfg;

    Display_Params params; //näytön parametrit alustetaan näyttö
    Display_Params_init(&params);
    params.lineClearMode = DISPLAY_CLEAR_BOTH;

    Display_Handle displayHandle = Display_open(Display_Type_LCD, &params);

    // *******************************
    //
    // MPU OPEN I2C
    //
    // *******************************
    i2cMPU = I2C_open(Board_I2C, &i2cMPUParams);
    if (i2cMPU == NULL) {
        System_abort("Error Initializing I2CMPU\n");
    }

    // *******************************
    //
    // MPU POWER ON
    //
    // *******************************
    PIN_setOutputValue(hMpuPin,Board_MPU_POWER, Board_MPU_POWER_ON);

    // WAIT 100MS FOR THE SENSOR TO POWER UP
	Task_sleep(100000 / Clock_tickPeriod);
    System_printf("MPU9250: Power ON\n");
    System_flush();

    // *******************************
    //
    // MPU9250 SETUP
    //
    // *******************************
	System_printf("MPU9250: Setup and calibration...\n");
	System_flush();

	mpu9250_setup(&i2cMPU);

	System_printf("MPU9250: Setup and calibration OK\n");
	System_flush();

    // *******************************
    //
    // MPU CLOSE I2C
    //
    // *******************************
    I2C_close(i2cMPU);


	while (1) {


	    // *******************************
	    //
	    // MPU OPEN I2C
	    //
	    // *******************************
	    i2cMPU = I2C_open(Board_I2C, &i2cMPUParams);
	    if (i2cMPU == NULL) {
	        System_abort("Error Initializing I2CMPU\n");
	    }

	    // *******************************
	    //
	    // MPU ASK DATA
		//
	    // *******************************

		mpu9250_get_data(&i2cMPU, &ax, &ay, &az, &gx, &gy, &gz);
	/*	if(gx > 100 || gx < -100 || gy > 100 || gy < -100 || gz > 100 || gz < -100 ) {
			sprintf(mpureceived,"%f " "%f " "%f \n", gx, gy, gz);
			System_printf("gx gy gz  ");
			System_printf(mpureceived);
			System_flush();

		} */
	    // *******************************
	    //
	    // MPU CLOSE I2C
	    //
	    // *******************************

		if(gx < -75)
		{
			Display_print0(displayHandle, 5, 3, "TAAKSE");
			System_printf("taakse \n");
			System_flush();
			Task_sleep(1000000 / Clock_tickPeriod);
			Display_clear(displayHandle);
		} else if (gx > 75)
		{
			Display_print0(displayHandle, 5, 5, "ETEEN");
			System_printf("eteen \n");
			System_flush();
			Task_sleep(1000000 / Clock_tickPeriod);
			Display_clear(displayHandle);
		} else if (gy < -75)
		{
			Display_print0(displayHandle, 5, 5, "VASEN");
			System_printf("vasen \n");
			System_flush();
			Task_sleep(1000000 / Clock_tickPeriod);
			Display_clear(displayHandle);
		} else if (gy > 75)
		{
			Display_print0(displayHandle, 5, 5, "OIKEA");
			System_printf("oikea \n");
			System_flush();
			Task_sleep(1000000 / Clock_tickPeriod);
			Display_clear(displayHandle);
		}





		I2C_close(i2cMPU);
	    // WAIT 1s
    	Task_sleep(100000 / Clock_tickPeriod);

	}

	// MPU9250 POWER OFF
	// Because of loop forever, code never goes here
 //   PIN_setOutputValue(hMpuPin,Board_MPU_POWER, Board_MPU_POWER_OFF);
}

int main(void) {

	Task_Handle task;
	Task_Params taskParams;

    Board_initGeneral();
    Board_initI2C();

    // *******************************
    //
    // OPEN MPU POWER PIN
    //
    // *******************************
    hMpuPin = PIN_open(&MpuPinState, MpuPinConfig);
    if (hMpuPin == NULL) {
    	System_abort("Pin open failed!");
    }

    Task_Params_init(&taskParams);
    taskParams.stackSize = STACKSIZE;
    taskParams.stack = &taskStack;
    task = Task_create((Task_FuncPtr)sensorFxn, &taskParams, NULL);
    if (task == NULL) {
    	System_abort("Task create failed!");
    }

    /* Start BIOS */
    BIOS_start();

    return (0);
}
