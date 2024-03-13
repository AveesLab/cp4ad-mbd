/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Ego.c
 *
 * Code generated for Simulink model 'Ego'.
 *
 * Model version                  : 10.5
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Tue Mar 12 18:14:49 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Ego.h"

/* Block states (default storage) */
DW_Ego_T Ego_DW;

/* External inputs (root inport signals with default storage) */
ExtU_Ego_T Ego_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_Ego_T Ego_Y;

/* Real-time model */
static RT_MODEL_Ego_T Ego_M_;
RT_MODEL_Ego_T *const Ego_M = &Ego_M_;

/* Model step function */
void Ego_step(void)
{
  /* Outputs for Atomic SubSystem: '<Root>/Ego' */
  /* DiscreteIntegrator: '<S2>/Discrete-Time Integrator' */
  Ego_Y.v_ego = Ego_DW.DiscreteTimeIntegrator_DSTATE;

  /* Outport: '<Root>/s_ego' incorporates:
   *  DiscreteIntegrator: '<S2>/Discrete-Time Integrator1'
   */
  Ego_Y.s_ego = Ego_DW.DiscreteTimeIntegrator1_DSTATE;

  /* Update for DiscreteIntegrator: '<S2>/Discrete-Time Integrator' incorporates:
   *  Inport: '<Root>/a_ego'
   */
  Ego_DW.DiscreteTimeIntegrator_DSTATE += 0.2 * Ego_U.a_ego;

  /* Update for DiscreteIntegrator: '<S2>/Discrete-Time Integrator1' */
  Ego_DW.DiscreteTimeIntegrator1_DSTATE += 0.2 * Ego_Y.v_ego;

  /* End of Outputs for SubSystem: '<Root>/Ego' */
}

/* Model initialize function */
void Ego_initialize(void)
{
  /* SystemInitialize for Atomic SubSystem: '<Root>/Ego' */
  /* InitializeConditions for DiscreteIntegrator: '<S2>/Discrete-Time Integrator' */
  Ego_DW.DiscreteTimeIntegrator_DSTATE = 25.0;

  /* InitializeConditions for DiscreteIntegrator: '<S2>/Discrete-Time Integrator1' */
  Ego_DW.DiscreteTimeIntegrator1_DSTATE = -120.0;

  /* End of SystemInitialize for SubSystem: '<Root>/Ego' */
}

/* Model terminate function */
void Ego_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
