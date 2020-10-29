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

/*music play*/
#define _BUZZER_H_
#define BUZZER_FREQ_MIN            3
#define BUZZER_FREQ_MAX            8000


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

// Tilaesittelyt
enum state { WAIT=1, READ_SENSOR, UPDATE, NEW_MSG, TAAKSE, ETEEN, VASEN, OIKEA};
enum state myState = WAIT;

Void clkFxn(UArg arg0) {

    // Muutetaan tilaa halutuksi
    // Hox! If-lauseella tarkistetaan, että tilasiirto on mahdollinen!!
    // Nyt sallitaan vain tilasiirtymä IDLE -> READ_SENSOR
    if (myState == WAIT) {

        // Tilasiirtymä IDLE -> READ_SENSOR
        myState = READ_SENSOR;
    }
}

Void sensorTask(UArg arg0, UArg arg1) {

    while (1) {
        if (myState == READ_SENSOR) {
            // Tilan toiminnallisuus
            read_sensor_values();          // <---- 
            // Tilasiirtymä READ_SENSOR -> UPDATE
            myState = UPDATE;
        }
        Task_sleep(1000000 / Clock_tickPeriod);
    }
}

// Anturien käsittely
Void displayTask(UArg arg0, UArg arg1) {

    while (1) {
        if (myState == UPDATE) {
            // Tilan toiminnallisuus
            update_screen();                   // <--- koitin aluksi tehdä displayprintillä
            // Tilasiirtymä UPDATE -> IDLE
            myState = WAIT;
        }
        Task_sleep(1000000 / Clock_tickPeriod);
    }
}



// SENSOR TASK
Void sensorFxn(UArg arg0, UArg arg1) {

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
	    // *******************************
	    //
	    // MPU CLOSE I2C
	    //
	    // *******************************

		if(gx < -75)
		{
			myState = TAAKSE;
			Display_print0(displayHandle, 5, 5, "TAAKSE");
			System_printf("taakse \n");
			System_flush();
			Task_sleep(1000000 / Clock_tickPeriod);
			Display_clear(displayHandle);
		} else if (gx > 75)
		{
			myState = ETEEN;
			Display_print0(displayHandle, 5, 5, "ETEEN");
			System_printf("eteen \n");
			System_flush();
			Task_sleep(1000000 / Clock_tickPeriod);
			Display_clear(displayHandle);
		} else if (gy < -75)
		{
			myState = VASEN;
			Display_print0(displayHandle, 5, 5, "VASEN");
			System_printf("vasen \n");
			System_flush();
			Task_sleep(1000000 / Clock_tickPeriod);
			Display_clear(displayHandle);
		} else if (gy > 75)
		{
			myState = OIKEA;
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
