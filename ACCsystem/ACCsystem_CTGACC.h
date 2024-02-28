/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ACCsystem_CTGACC.h
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

#ifndef RTW_HEADER_ACCsystem_CTGACC_h_
#define RTW_HEADER_ACCsystem_CTGACC_h_
#ifndef ACCsystem_COMMON_INCLUDES_
#define ACCsystem_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* ACCsystem_COMMON_INCLUDES_ */

/* Block signals for system '<Root>/CTG ACC' */
typedef struct {
  real_T driver_set_velocity;          /* '<S1>/Set velocity' */
} B_CTGACC_ACCsystem_T;

extern void ACCsystem_CTGACC(real_T rtu_LongitudinalVelocity, real_T
  rtu_RelativeDistance, real_T rtu_RelativeVelocity, real_T *rty_Acceleration,
  B_CTGACC_ACCsystem_T *localB);

#endif                                 /* RTW_HEADER_ACCsystem_CTGACC_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
