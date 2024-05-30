/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ACC.c
 *
 * Code generated for Simulink model 'ACC'.
 *
 * Model version                  : 10.3
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Fri Mar  8 11:17:45 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ACC.h"
#include <math.h>

/* Block signals (default storage) */
B_ACC_T ACC_B;

/* External inputs (root inport signals with default storage) */
ExtU_ACC_T ACC_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_ACC_T ACC_Y;

/* Real-time model */
static RT_MODEL_ACC_T ACC_M_;
RT_MODEL_ACC_T *const ACC_M = &ACC_M_;
static void rate_scheduler(void);

/*
 *         This function updates active task flag for each subrate.
 *         The function is called at model base rate, hence the
 *         generated code self-manages all its subrates.
 */
static void rate_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (ACC_M->Timing.TaskCounters.TID[1])++;
  if ((ACC_M->Timing.TaskCounters.TID[1]) > 1) {/* Sample time: [0.2s, 0.0s] */
    ACC_M->Timing.TaskCounters.TID[1] = 0;
  }

  (ACC_M->Timing.TaskCounters.TID[2])++;
  if ((ACC_M->Timing.TaskCounters.TID[2]) > 3) {/* Sample time: [0.4s, 0.0s] */
    ACC_M->Timing.TaskCounters.TID[2] = 0;
  }
}

/* Model step function */
void ACC_step(void)
{
  if (ACC_M->Timing.TaskCounters.TID[2] == 0) {
    /* Outputs for Atomic SubSystem: '<Root>/ACC' */
    /* Constant: '<S2>/Set velocity' */
    ACC_B.driver_set_velocity = 30.0;

    /* Outport: '<Root>/accel' incorporates:
     *  Constant: '<S2>/Default Spacing'
     *  Constant: '<S2>/Time Gap'
     *  Gain: '<S2>/Gain1'
     *  Gain: '<S2>/Kd'
     *  Gain: '<S2>/Kp'
     *  Inport: '<Root>/In1'
     *  Inport: '<Root>/In2'
     *  Inport: '<Root>/In3'
     *  Inport: '<Root>/v_ego'
     *  MinMax: '<S2>/Min'
     *  Product: '<S2>/Product'
     *  Sum: '<S1>/Sum'
     *  Sum: '<S1>/Sum1'
     *  Sum: '<S2>/Sum1'
     *  Sum: '<S2>/Sum2'
     *  Sum: '<S2>/Sum3'
     *  Sum: '<S2>/Sum4'
     */
    ACC_Y.accel = fmin((30.0 - ACC_U.v_ego) * 5.0, (ACC_U.v_lead - ACC_U.v_ego) *
                       2.0 - ((1.4 * ACC_U.v_ego + 10.0) - (ACC_U.s_lead -
      ACC_U.In2)) * 0.1);

    /* End of Outputs for SubSystem: '<Root>/ACC' */
  }

  rate_scheduler();
}

/* Model initialize function */
void ACC_initialize(void)
{

}

/* Model terminate function */
void ACC_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
