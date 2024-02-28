/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ACCsystem_CTGACC.c
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

#include "rtwtypes.h"
#include "ACCsystem_CTGACC.h"
#include <math.h>

/* Output and update for atomic system: '<Root>/CTG ACC' */
void ACCsystem_CTGACC(real_T rtu_LongitudinalVelocity, real_T
                      rtu_RelativeDistance, real_T rtu_RelativeVelocity, real_T *
                      rty_Acceleration, B_CTGACC_ACCsystem_T *localB)
{
  /* Constant: '<S1>/Set velocity' */
  localB->driver_set_velocity = 30.0;

  /* MinMax: '<S1>/Min' incorporates:
   *  Constant: '<S1>/Default Spacing'
   *  Constant: '<S1>/Time Gap'
   *  Gain: '<S1>/Gain1'
   *  Gain: '<S1>/Kd'
   *  Gain: '<S1>/Kp'
   *  Product: '<S1>/Product'
   *  Sum: '<S1>/Sum1'
   *  Sum: '<S1>/Sum2'
   *  Sum: '<S1>/Sum3'
   *  Sum: '<S1>/Sum4'
   */
  *rty_Acceleration = fmin((30.0 - rtu_LongitudinalVelocity) * 5.0, 2.0 *
    rtu_RelativeVelocity - ((1.4 * rtu_LongitudinalVelocity + 10.0) -
    rtu_RelativeDistance) * 0.1);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
