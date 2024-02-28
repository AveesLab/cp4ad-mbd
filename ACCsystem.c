/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ACCsystem.c
 *
 * Code generated for Simulink model 'ACCsystem'.
 *
 * Model version                  : 10.4
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Wed Feb 28 12:25:09 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64) 
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ACCsystem.h"
#include "ACCsystem_CTGACC.h"
#include <math.h>
#include "rtwtypes.h"

/* Block signals (default storage) */
B_ACCsystem_T ACCsystem_B;

/* Block states (default storage) */
DW_ACCsystem_T ACCsystem_DW;

/* Real-time model */
static RT_MODEL_ACCsystem_T ACCsystem_M_;
RT_MODEL_ACCsystem_T *const ACCsystem_M = &ACCsystem_M_;
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
  (ACCsystem_M->Timing.TaskCounters.TID[1])++;
  if ((ACCsystem_M->Timing.TaskCounters.TID[1]) > 1) {/* Sample time: [0.2s, 0.0s] */
    ACCsystem_M->Timing.TaskCounters.TID[1] = 0;
  }

  (ACCsystem_M->Timing.TaskCounters.TID[2])++;
  if ((ACCsystem_M->Timing.TaskCounters.TID[2]) > 2) {/* Sample time: [0.3s, 0.0s] */
    ACCsystem_M->Timing.TaskCounters.TID[2] = 0;
  }
}

/* Model step function */
void ACCsystem_step(void)
{
  real_T rtb_DiscreteTimeIntegrator;
  if (ACCsystem_M->Timing.TaskCounters.TID[1] == 0) {
    /* Outputs for Atomic SubSystem: '<Root>/Ego Car' */
    /* DiscreteIntegrator: '<S2>/Discrete-Time Integrator' */
    ACCsystem_B.DiscreteTimeIntegrator =
      ACCsystem_DW.DiscreteTimeIntegrator_DSTATE_b;

    /* DiscreteIntegrator: '<S2>/Discrete-Time Integrator1' */
    ACCsystem_B.DiscreteTimeIntegrator1 =
      ACCsystem_DW.DiscreteTimeIntegrator1_DSTATE;

    /* End of Outputs for SubSystem: '<Root>/Ego Car' */
  }

  /* Outputs for Atomic SubSystem: '<Root>/Target Car' */
  /* DiscreteIntegrator: '<S3>/Discrete-Time Integrator' */
  rtb_DiscreteTimeIntegrator = ACCsystem_DW.DiscreteTimeIntegrator_DSTATE;

  /* End of Outputs for SubSystem: '<Root>/Target Car' */
  if (ACCsystem_M->Timing.TaskCounters.TID[2] == 0) {
    /* Outputs for Atomic SubSystem: '<Root>/CTG ACC' */
    /* Outputs for Atomic SubSystem: '<Root>/Target Car' */
    /* Sum: '<Root>/Sum' incorporates:
     *  DiscreteIntegrator: '<S3>/Discrete-Time Integrator'
     *  DiscreteIntegrator: '<S3>/Discrete-Time Integrator2'
     *  Sum: '<Root>/Sum1'
     */
    ACCsystem_CTGACC(ACCsystem_B.DiscreteTimeIntegrator,
                     ACCsystem_DW.DiscreteTimeIntegrator2_DSTATE -
                     ACCsystem_B.DiscreteTimeIntegrator1,
                     ACCsystem_DW.DiscreteTimeIntegrator_DSTATE -
                     ACCsystem_B.DiscreteTimeIntegrator, &ACCsystem_B.Min,
                     &ACCsystem_B.CTGACC);

    /* End of Outputs for SubSystem: '<Root>/Target Car' */
    /* End of Outputs for SubSystem: '<Root>/CTG ACC' */
  }

  /* Sin: '<Root>/Sine Wave' */
  if (ACCsystem_DW.systemEnable != 0) {
    real_T lastSin_tmp;
    lastSin_tmp = 0.2 * ((ACCsystem_M->Timing.clockTick0) * 0.1);
    ACCsystem_DW.lastSin = sin(lastSin_tmp);
    ACCsystem_DW.lastCos = cos(lastSin_tmp);
    ACCsystem_DW.systemEnable = 0;
  }

  if (ACCsystem_M->Timing.TaskCounters.TID[1] == 0) {
    /* Update for Atomic SubSystem: '<Root>/Ego Car' */
    /* Update for DiscreteIntegrator: '<S2>/Discrete-Time Integrator' */
    ACCsystem_DW.DiscreteTimeIntegrator_DSTATE_b += 0.2 * ACCsystem_B.Min;

    /* Update for DiscreteIntegrator: '<S2>/Discrete-Time Integrator1' */
    ACCsystem_DW.DiscreteTimeIntegrator1_DSTATE += 0.2 *
      ACCsystem_B.DiscreteTimeIntegrator;

    /* End of Update for SubSystem: '<Root>/Ego Car' */
  }

  /* Update for Atomic SubSystem: '<Root>/Target Car' */
  /* Update for DiscreteIntegrator: '<S3>/Discrete-Time Integrator' incorporates:
   *  Sin: '<Root>/Sine Wave'
   */
  ACCsystem_DW.DiscreteTimeIntegrator_DSTATE += ((ACCsystem_DW.lastSin *
    0.99980000666657776 + ACCsystem_DW.lastCos * -0.019998666693333084) *
    0.99980000666657776 + (ACCsystem_DW.lastCos * 0.99980000666657776 -
    ACCsystem_DW.lastSin * -0.019998666693333084) * 0.019998666693333084) * 0.6 *
    0.1;

  /* Update for DiscreteIntegrator: '<S3>/Discrete-Time Integrator2' */
  ACCsystem_DW.DiscreteTimeIntegrator2_DSTATE += 0.1 *
    rtb_DiscreteTimeIntegrator;

  /* End of Update for SubSystem: '<Root>/Target Car' */

  /* Update for Sin: '<Root>/Sine Wave' */
  rtb_DiscreteTimeIntegrator = ACCsystem_DW.lastSin;
  ACCsystem_DW.lastSin = ACCsystem_DW.lastSin * 0.99980000666657776 +
    ACCsystem_DW.lastCos * 0.019998666693333084;
  ACCsystem_DW.lastCos = ACCsystem_DW.lastCos * 0.99980000666657776 -
    rtb_DiscreteTimeIntegrator * 0.019998666693333084;

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.1, which is the step size
   * of the task. Size of "clockTick0" ensures timer will not overflow during the
   * application lifespan selected.
   */
  ACCsystem_M->Timing.clockTick0++;
  rate_scheduler();
}

/* Model initialize function */
void ACCsystem_initialize(void)
{
  /* SystemInitialize for Atomic SubSystem: '<Root>/Ego Car' */
  /* InitializeConditions for DiscreteIntegrator: '<S2>/Discrete-Time Integrator' */
  ACCsystem_DW.DiscreteTimeIntegrator_DSTATE_b = 25.0;

  /* InitializeConditions for DiscreteIntegrator: '<S2>/Discrete-Time Integrator1' */
  ACCsystem_DW.DiscreteTimeIntegrator1_DSTATE = -120.0;

  /* End of SystemInitialize for SubSystem: '<Root>/Ego Car' */

  /* SystemInitialize for Atomic SubSystem: '<Root>/Target Car' */
  /* InitializeConditions for DiscreteIntegrator: '<S3>/Discrete-Time Integrator' */
  ACCsystem_DW.DiscreteTimeIntegrator_DSTATE = 25.0;

  /* InitializeConditions for DiscreteIntegrator: '<S3>/Discrete-Time Integrator2' */
  ACCsystem_DW.DiscreteTimeIntegrator2_DSTATE = -80.0;

  /* End of SystemInitialize for SubSystem: '<Root>/Target Car' */

  /* Enable for Sin: '<Root>/Sine Wave' */
  ACCsystem_DW.systemEnable = 1;
}

/* Model terminate function */
void ACCsystem_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
