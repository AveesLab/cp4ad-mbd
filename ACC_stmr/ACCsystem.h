/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ACCsystem.h
 *
 * Code generated for Simulink model 'ACCsystem'.
 *
 * Model version                  : 10.5
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Wed Feb 28 18:33:38 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_ACCsystem_h_
#define RTW_HEADER_ACCsystem_h_
#ifndef ACCsystem_COMMON_INCLUDES_
#define ACCsystem_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* ACCsystem_COMMON_INCLUDES_ */

#include "ACCsystem_types.h"
#include "ACCsystem_CTGACC.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
typedef struct {
  real_T RateTransition1;              /* '<Root>/Rate Transition1' */
  real_T DiscreteTimeIntegrator;       /* '<S2>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator1;      /* '<S2>/Discrete-Time Integrator1' */
  B_CTGACC_ACCsystem_T CTGACC;         /* '<Root>/CTG ACC' */
} B_ACCsystem_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S3>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator1_DSTATE;/* '<S3>/Discrete-Time Integrator1' */
  real_T DiscreteTimeIntegrator_DSTATE_b;/* '<S2>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator1_DSTAT_a;/* '<S2>/Discrete-Time Integrator1' */
  real_T RateTransition2_Buffer;       /* '<Root>/Rate Transition2' */
  real_T lastSin;                      /* '<Root>/Sine Wave' */
  real_T lastCos;                      /* '<Root>/Sine Wave' */
  real_T RateTransition1_Buffer0;      /* '<Root>/Rate Transition1' */
  int32_T systemEnable;                /* '<Root>/Sine Wave' */
} DW_ACCsystem_T;

/* Real-time Model Data Structure */
struct tag_RTM_ACCsystem_T {
  const char_T * volatile errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    struct {
      uint8_T TID[3];
    } TaskCounters;
  } Timing;
};

/* Block signals (default storage) */
extern B_ACCsystem_T ACCsystem_B;

/* Block states (default storage) */
extern DW_ACCsystem_T ACCsystem_DW;

/* Model entry point functions */
extern void ACCsystem_initialize(void);
extern void ACCsystem_step(void);
extern void ACCsystem_terminate(void);

/* Real-time Model object */
extern RT_MODEL_ACCsystem_T *const ACCsystem_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'ACCsystem'
 * '<S1>'   : 'ACCsystem/CTG ACC'
 * '<S2>'   : 'ACCsystem/Ego Car'
 * '<S3>'   : 'ACCsystem/Target Car'
 */
#endif                                 /* RTW_HEADER_ACCsystem_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
