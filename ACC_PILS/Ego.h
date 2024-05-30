/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Ego.h
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

#ifndef RTW_HEADER_Ego_h_
#define RTW_HEADER_Ego_h_
#ifndef Ego_COMMON_INCLUDES_
#define Ego_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* Ego_COMMON_INCLUDES_ */

#include "Ego_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S2>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator1_DSTATE;/* '<S2>/Discrete-Time Integrator1' */
} DW_Ego_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T a_ego;                        /* '<Root>/a_ego' */
} ExtU_Ego_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T s_ego;                        /* '<Root>/s_ego' */
  real_T v_ego;                        /* '<Root>/v_ego' */
} ExtY_Ego_T;

/* Real-time Model Data Structure */
struct tag_RTM_Ego_T {
  const char_T * volatile errorStatus;
};

/* Block states (default storage) */
extern DW_Ego_T Ego_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_Ego_T Ego_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_Ego_T Ego_Y;

/* Model entry point functions */
extern void Ego_initialize(void);
extern void Ego_step(void);
extern void Ego_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Ego_T *const Ego_M;

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
 * hilite_system('ACCsystem/Ego')    - opens subsystem ACCsystem/Ego
 * hilite_system('ACCsystem/Ego/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'ACCsystem'
 * '<S1>'   : 'ACCsystem/Ego'
 * '<S2>'   : 'ACCsystem/Ego/Ego Car'
 */
#endif                                 /* RTW_HEADER_Ego_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
