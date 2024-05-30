/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Lead.c
 *
 * Code generated for Simulink model 'Lead'.
 *
 * Model version                  : 10.5
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Tue Mar 12 18:10:44 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Lead.h"
#include <math.h>
#include "rtwtypes.h"

/* Block states (default storage) */
DW_Lead_T Lead_DW;

/* External outputs (root outports fed by signals with default storage) */
ExtY_Lead_T Lead_Y;

/* Real-time model */
static RT_MODEL_Lead_T Lead_M_;
RT_MODEL_Lead_T *const Lead_M = &Lead_M_;

/* Model step function */
void Lead_step(void)
{
  real_T lastSin_tmp;

  /* Outputs for Atomic SubSystem: '<Root>/Lead' */
  /* DiscreteIntegrator: '<S2>/Discrete-Time Integrator' */
  Lead_Y.v_lead = Lead_DW.DiscreteTimeIntegrator_DSTATE;

  /* Outport: '<Root>/s_lead' incorporates:
   *  DiscreteIntegrator: '<S2>/Discrete-Time Integrator1'
   */
  Lead_Y.s_lead = Lead_DW.DiscreteTimeIntegrator1_DSTATE;

  /* Sin: '<S1>/Sine Wave' */
  if (Lead_DW.systemEnable != 0) {
    lastSin_tmp = 0.2 * ((Lead_M->Timing.clockTick0) * 0.1);
    Lead_DW.lastSin = sin(lastSin_tmp);
    Lead_DW.lastCos = cos(lastSin_tmp);
    Lead_DW.systemEnable = 0;
  }

  /* Update for DiscreteIntegrator: '<S2>/Discrete-Time Integrator' incorporates:
   *  Sin: '<S1>/Sine Wave'
   */
  Lead_DW.DiscreteTimeIntegrator_DSTATE += ((Lead_DW.lastSin *
    0.99980000666657776 + Lead_DW.lastCos * -0.019998666693333084) *
    0.99980000666657776 + (Lead_DW.lastCos * 0.99980000666657776 -
    Lead_DW.lastSin * -0.019998666693333084) * 0.019998666693333084) * 0.6 * 0.1;

  /* Update for DiscreteIntegrator: '<S2>/Discrete-Time Integrator1' */
  Lead_DW.DiscreteTimeIntegrator1_DSTATE += 0.1 * Lead_Y.v_lead;

  /* Update for Sin: '<S1>/Sine Wave' */
  lastSin_tmp = Lead_DW.lastSin;
  Lead_DW.lastSin = Lead_DW.lastSin * 0.99980000666657776 + Lead_DW.lastCos *
    0.019998666693333084;
  Lead_DW.lastCos = Lead_DW.lastCos * 0.99980000666657776 - lastSin_tmp *
    0.019998666693333084;

  /* End of Outputs for SubSystem: '<Root>/Lead' */

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.1, which is the step size
   * of the task. Size of "clockTick0" ensures timer will not overflow during the
   * application lifespan selected.
   */
  Lead_M->Timing.clockTick0++;
}

/* Model initialize function */
void Lead_initialize(void)
{
  /* SystemInitialize for Atomic SubSystem: '<Root>/Lead' */
  /* InitializeConditions for DiscreteIntegrator: '<S2>/Discrete-Time Integrator' */
  Lead_DW.DiscreteTimeIntegrator_DSTATE = 25.0;

  /* InitializeConditions for DiscreteIntegrator: '<S2>/Discrete-Time Integrator1' */
  Lead_DW.DiscreteTimeIntegrator1_DSTATE = -80.0;

  /* End of SystemInitialize for SubSystem: '<Root>/Lead' */

  /* Enable for Atomic SubSystem: '<Root>/Lead' */
  /* Enable for Sin: '<S1>/Sine Wave' */
  Lead_DW.systemEnable = 1;

  /* End of Enable for SubSystem: '<Root>/Lead' */
}

/* Model terminate function */
void Lead_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
