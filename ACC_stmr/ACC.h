/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ACC.h
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

#ifndef RTW_HEADER_ACC_h_
#define RTW_HEADER_ACC_h_
#ifndef ACC_COMMON_INCLUDES_
#define ACC_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* ACC_COMMON_INCLUDES_ */

#include "ACC_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
typedef struct {
  real_T driver_set_velocity;          /* '<S2>/Set velocity' */
} B_ACC_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T s_lead;                       /* '<Root>/In1' */
  real_T In2;                          /* '<Root>/In2' */
  real_T v_lead;                       /* '<Root>/In3' */
  real_T v_ego;                        /* '<Root>/v_ego' */
} ExtU_ACC_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T accel;                        /* '<Root>/accel' */
} ExtY_ACC_T;

/* Real-time Model Data Structure */
struct tag_RTM_ACC_T {
  const char_T * volatile errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint8_T TID[3];
    } TaskCounters;
  } Timing;
};

/* Block signals (default storage) */
extern B_ACC_T ACC_B;

/* External inputs (root inport signals with default storage) */
extern ExtU_ACC_T ACC_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_ACC_T ACC_Y;

/* Model entry point functions */
extern void ACC_initialize(void);
extern void ACC_step(void);
extern void ACC_terminate(void);

/* Real-time Model object */
extern RT_MODEL_ACC_T *const ACC_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Note that this particular code originates from a subsystem build,
 * and has its own system numbers different from the parent model.
 * Refer to the system hierarchy for this subsystem below, and use the
 * MATLAB hilite_system command to trace the generated code back
 * to the parent model.  For example,
 *
 * hilite_system('ACCsystem/ACC')    - opens subsystem ACCsystem/ACC
 * hilite_system('ACCsystem/ACC/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'ACCsystem'
 * '<S1>'   : 'ACCsystem/ACC'
 * '<S2>'   : 'ACCsystem/ACC/CTG ACC'
 */
#endif                                 /* RTW_HEADER_ACC_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
