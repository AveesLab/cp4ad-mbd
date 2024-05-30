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
    printfSerial(" %f", Lead_Y.s_lead);
    ACC_U.v_lead=Lead_Y.v_lead;
    ACC_U.In1=Lead_Y.s_lead;
	TerminateTask();
};

TASK(TaskM) {
    Ego_step();
    printfSerial("        %f", Ego_Y.s_ego);
    ACC_U.v_ego=Ego_Y.v_ego;
    ACC_U.In2=Ego_Y.s_ego;
	TerminateTask();
};

TASK(TaskL) {
    ACC_step();
    printfSerial("               %f", ACC_Y.accel);
    Ego_U.a_ego=ACC_Y.accel;
	TerminateTask();
};
