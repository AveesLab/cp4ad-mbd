/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Lead.h
 *
 * Code generated for Simulink model 'Lead'.
 *
 * Model version                  : 10.3
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Fri Mar  8 11:08:18 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Lead_h_
#define RTW_HEADER_Lead_h_
#ifndef Lead_COMMON_INCLUDES_
#define Lead_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* Lead_COMMON_INCLUDES_ */

#include "Lead_types.h"

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
  real_T lastSin;                      /* '<S1>/Sine Wave' */
  real_T lastCos;                      /* '<S1>/Sine Wave' */
  int32_T systemEnable;                /* '<S1>/Sine Wave' */
} DW_Lead_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T s_lead;                       /* '<Root>/s_lead' */
  real_T v_lead;                       /* '<Root>/v_lead' */
} ExtY_Lead_T;

/* Real-time Model Data Structure */
struct tag_RTM_Lead_T {
  const char_T * volatile errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
  } Timing;
};

/* Block states (default storage) */
extern DW_Lead_T Lead_DW;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_Lead_T Lead_Y;

/* Model entry point functions */
extern void Lead_initialize(void);
extern void Lead_step(void);
extern void Lead_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Lead_T *const Lead_M;

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
 * hilite_system('ACCsystem/Lead')    - opens subsystem ACCsystem/Lead
 * hilite_system('ACCsystem/Lead/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'ACCsystem'
 * '<S1>'   : 'ACCsystem/Lead'
 * '<S2>'   : 'ACCsystem/Lead/Lead Car'
 */
#endif                                 /* RTW_HEADER_Lead_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
