#include "ee.h"
#include "Arduino.h"
#include "serial.h"
#include "Ego.h"
#include "Lead.h"
#include "ACC.h"

void mdelay(unsigned long delay_ms);

void StartupHook(void)
{
    Ego_initialize();
    Lead_initialize();
    ACC_initialize();
    printfSerial("\nOS Begins... ", 0ul);
}

/* Timer1 ISR2 */
ISR2(TimerISR)
{
    static long c = -5;
    IncrementCounter(counter1);
    printfSerial("\n%4ld: ", ++c);
}

TASK(TaskH) {
    Lead_step();
    /*        write below your code        */




    /***************************************/
	TerminateTask();
};

TASK(TaskM) {
    Ego_step();
    /*        write below your code        */




    /***************************************/
	TerminateTask();
};

TASK(TaskL) {
    ACC_step();
    /*        write below your code        */




    /***************************************/
	TerminateTask();
};
