/*
 * Bilateral_Ankle_Exo.h
 *
 * Code generation for model "Bilateral_Ankle_Exo".
 *
 * Model version              : 1.1618
 * Simulink Coder version : 8.13 (R2017b) 24-Jul-2017
 * C source code generated on : Thu Jun 18 18:06:16 2020
 *
 * Target selection: rti1202.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Custom Processor->Custom
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Bilateral_Ankle_Exo_h_
#define RTW_HEADER_Bilateral_Ankle_Exo_h_
#include <math.h>
#include <string.h>
#ifndef Bilateral_Ankle_Exo_COMMON_INCLUDES_
# define Bilateral_Ankle_Exo_COMMON_INCLUDES_
#include <brtenv.h>
#include <rtkernel.h>
#include <rti_assert.h>
#include <rtidefineddatatypes.h>
#include <rtican_ds1202.h>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* Bilateral_Ankle_Exo_COMMON_INCLUDES_ */

#include "Bilateral_Ankle_Exo_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetContStateDisabled
# define rtmGetContStateDisabled(rtm)  ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
# define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
# define rtmGetContStates(rtm)         ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
# define rtmSetContStates(rtm, val)    ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
# define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
# define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
# define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
# define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetIntgData
# define rtmGetIntgData(rtm)           ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
# define rtmSetIntgData(rtm, val)      ((rtm)->intgData = (val))
#endif

#ifndef rtmGetOdeF
# define rtmGetOdeF(rtm)               ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
# define rtmSetOdeF(rtm, val)          ((rtm)->odeF = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
# define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
# define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
# define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
# define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
# define rtmGetZCCacheNeedsReset(rtm)  ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
# define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
# define rtmGetdX(rtm)                 ((rtm)->derivs)
#endif

#ifndef rtmSetdX
# define rtmSetdX(rtm, val)            ((rtm)->derivs = (val))
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

/* Block signals for system '<S29>/Mux' */
typedef struct {
  real_T x[2];                         /* '<S29>/Mux' */
} B_Mux_Bilateral_Ankle_Exo_T;

/* Block signals for system '<S30>/EMG3' */
typedef struct {
  real_T EMG_L_O3;                     /* '<S30>/EMG3' */
} B_EMG3_Bilateral_Ankle_Exo_T;

/* Block signals for system '<S30>/EMG4' */
typedef struct {
  real_T EMG_L_O4;                     /* '<S30>/EMG4' */
} B_EMG4_Bilateral_Ankle_Exo_T;

/* Block signals for system '<S30>/EMG_o1' */
typedef struct {
  real_T EMG_L_O1;                     /* '<S30>/EMG_o1' */
} B_EMG_o1_Bilateral_Ankle_Exo_T;

/* Block signals for system '<S30>/EMG_o2' */
typedef struct {
  real_T EMG_L_O2;                     /* '<S30>/EMG_o2' */
} B_EMG_o2_Bilateral_Ankle_Exo_T;

/* Block signals for system '<S30>/EMG_o5' */
typedef struct {
  real_T EMG_R_O1;                     /* '<S30>/EMG_o5' */
} B_EMG_o5_Bilateral_Ankle_Exo_T;

/* Block signals for system '<S30>/EMG_o6' */
typedef struct {
  real_T EMG_R_O2;                     /* '<S30>/EMG_o6' */
} B_EMG_o6_Bilateral_Ankle_Exo_T;

/* Block signals for system '<S30>/EMG_o7' */
typedef struct {
  real_T EMG_R_O3;                     /* '<S30>/EMG_o7' */
} B_EMG_o7_Bilateral_Ankle_Exo_T;

/* Block signals for system '<S30>/EMG_o8' */
typedef struct {
  real_T EMG_R_O4;                     /* '<S30>/EMG_o8' */
} B_EMG_o8_Bilateral_Ankle_Exo_T;

/* Block signals for system '<S68>/MVC' */
typedef struct {
  real_T y;                            /* '<S68>/MVC' */
} B_MVC_Bilateral_Ankle_Exo_T;

/* Block signals for system '<S31>/Filter_L' */
typedef struct {
  real_T state;                        /* '<S31>/Filter_L' */
} B_Filter_L_Bilateral_Ankle_Ex_T;

/* Block states (auto storage) for system '<S31>/Filter_L' */
typedef struct {
  real_T foot_state;                   /* '<S31>/Filter_L' */
  real_T filter_time;                  /* '<S31>/Filter_L' */
} DW_Filter_L_Bilateral_Ankle_E_T;

/* Block signals for system '<S33>/Mux1' */
typedef struct {
  real_T x[3];                         /* '<S33>/Mux1' */
} B_Mux1_Bilateral_Ankle_Exo_T;

/* Block signals for system '<S7>/Mux1' */
typedef struct {
  real_T x[4];                         /* '<S7>/Mux1' */
} B_Mux1_Bilateral_Ankle_Exo_c_T;

/* Block signals for system '<S14>/MATLAB Function' */
typedef struct {
  real_T vel;                          /* '<S14>/MATLAB Function' */
} B_MATLABFunction_Bilateral_An_T;

/* Block signals (auto storage) */
typedef struct {
  real_T result_data[3000];
  real_T tmp_data[3000];
  real_T b_result_data[2250];
  real_T tmp_data_m[2250];
  real_T torque_track[750];
  real_T torque_delta_track[750];
  real_T tmp_data_c[750];
  real_T tmp_data_k[750];
  real_T tmp_data_cx[750];
  real_T z1_data[750];
  real_T z1_data_b[750];
  real_T z1_data_p[750];
  real_T z1_data_c[750];
  real_T SFunction1;                   /* '<S113>/S-Function1' */
  real_T Gain;                         /* '<S34>/Gain' */
  real_T u4low2;                       /* '<S34>/0.4low2' */
  real_T x2k1;                         /* '<S110>/Unit Delay1' */
  real_T x1k1;                         /* '<S110>/Unit Delay' */
  real_T Gain1;                        /* '<S110>/Gain1' */
  real_T Gain2;                        /* '<S110>/Gain2' */
  real_T UnitDelay2;                   /* '<S110>/Unit Delay2' */
  real_T Gain4;                        /* '<S110>/Gain4' */
  real_T Add2;                         /* '<S110>/Add2' */
  real_T Gain3;                        /* '<S110>/Gain3' */
  real_T x2k;                          /* '<S110>/Add1' */
  real_T RT4[2];                       /* '<Root>/RT4' */
  real_T SFunction1_o1;                /* '<S37>/S-Function1' */
  real_T SFunction1_o2;                /* '<S37>/S-Function1' */
  real_T Gain_g;                       /* '<S29>/Gain' */
  real_T Gain1_o;                      /* '<S29>/Gain1' */
  real_T RT5[2];                       /* '<Root>/RT5' */
  real_T SFunction1_o1_j;              /* '<S104>/S-Function1' */
  real_T SFunction1_o2_h;              /* '<S104>/S-Function1' */
  real_T Gain1_k;                      /* '<S33>/Gain1' */
  real_T Gain4_m;                      /* '<S33>/Gain4' */
  real_T x2k1_h;                       /* '<S101>/Unit Delay1' */
  real_T x1k1_g;                       /* '<S101>/Unit Delay' */
  real_T Gain1_m;                      /* '<S101>/Gain1' */
  real_T Gain2_h;                      /* '<S101>/Gain2' */
  real_T UnitDelay2_e;                 /* '<S101>/Unit Delay2' */
  real_T Gain4_p;                      /* '<S101>/Gain4' */
  real_T Add2_f;                       /* '<S101>/Add2' */
  real_T Gain3_i;                      /* '<S101>/Gain3' */
  real_T x2k_k;                        /* '<S101>/Add1' */
  real_T RT6[3];                       /* '<Root>/RT6' */
  real_T RT1[4];                       /* '<Root>/RT1' */
  real_T RT2[6];                       /* '<Root>/RT2' */
  real_T RT3[9];                       /* '<Root>/RT3' */
  real_T RT7[4];                       /* '<Root>/RT7' */
  real_T SFunction1_o;                 /* '<S112>/S-Function1' */
  real_T Gain1_l;                      /* '<S34>/Gain1' */
  real_T u4low1;                       /* '<S34>/0.4low1' */
  real_T x2k1_m;                       /* '<S111>/Unit Delay1' */
  real_T x1k1_f;                       /* '<S111>/Unit Delay' */
  real_T Gain1_a;                      /* '<S111>/Gain1' */
  real_T Gain2_j;                      /* '<S111>/Gain2' */
  real_T UnitDelay2_b;                 /* '<S111>/Unit Delay2' */
  real_T Gain4_g;                      /* '<S111>/Gain4' */
  real_T Add2_c;                       /* '<S111>/Add2' */
  real_T Gain3_f;                      /* '<S111>/Gain3' */
  real_T x2k_l;                        /* '<S111>/Add1' */
  real_T RT8[2];                       /* '<Root>/RT8' */
  real_T SFunction1_o1_jc;             /* '<S38>/S-Function1' */
  real_T SFunction1_o2_o;              /* '<S38>/S-Function1' */
  real_T Gain2_n;                      /* '<S29>/Gain2' */
  real_T Gain3_o;                      /* '<S29>/Gain3' */
  real_T RT9[2];                       /* '<Root>/RT9' */
  real_T SFunction1_o1_jr;             /* '<S105>/S-Function1' */
  real_T SFunction1_o2_j;              /* '<S105>/S-Function1' */
  real_T Gain2_c;                      /* '<S33>/Gain2' */
  real_T Gain3_h;                      /* '<S33>/Gain3' */
  real_T x2k1_d;                       /* '<S100>/Unit Delay1' */
  real_T x1k1_e;                       /* '<S100>/Unit Delay' */
  real_T Gain1_p;                      /* '<S100>/Gain1' */
  real_T Gain2_na;                     /* '<S100>/Gain2' */
  real_T UnitDelay2_i;                 /* '<S100>/Unit Delay2' */
  real_T Gain4_o;                      /* '<S100>/Gain4' */
  real_T Add2_fk;                      /* '<S100>/Add2' */
  real_T Gain3_hf;                     /* '<S100>/Gain3' */
  real_T x2k_a;                        /* '<S100>/Add1' */
  real_T RT10[3];                      /* '<Root>/RT10' */
  real_T Gain_h;                       /* '<S110>/Gain' */
  real_T x1k;                          /* '<S110>/Add' */
  real_T Gain_n;                       /* '<S111>/Gain' */
  real_T x1k_o;                        /* '<S111>/Add' */
  real_T Gain_hf;                      /* '<S101>/Gain' */
  real_T x1k_i;                        /* '<S101>/Add' */
  real_T Gain_o;                       /* '<S100>/Gain' */
  real_T x1k_k;                        /* '<S100>/Add' */
  real_T SFunction1_l;                 /* '<S43>/S-Function1' */
  real_T SFunction1_i;                 /* '<S44>/S-Function1' */
  real_T SFunction1_m;                 /* '<S45>/S-Function1' */
  real_T SFunction1_j;                 /* '<S46>/S-Function1' */
  real_T SFunction1_k;                 /* '<S47>/S-Function1' */
  real_T SFunction1_g;                 /* '<S48>/S-Function1' */
  real_T SFunction1_a;                 /* '<S49>/S-Function1' */
  real_T SFunction1_gi;                /* '<S50>/S-Function1' */
  real_T Gain6;                        /* '<S30>/Gain6' */
  real_T Gain7;                        /* '<S30>/Gain7' */
  real_T Gain4_mo;                     /* '<S30>/Gain4' */
  real_T Gain5;                        /* '<S30>/Gain5' */
  real_T Gain_m;                       /* '<S30>/Gain' */
  real_T Gain1_aa;                     /* '<S30>/Gain1' */
  real_T Gain2_p;                      /* '<S30>/Gain2' */
  real_T Gain3_n;                      /* '<S30>/Gain3' */
  real_T low_pass;                     /* '<S68>/low_pass' */
  real_T low_pass_l;                   /* '<S69>/low_pass' */
  real_T low_pass_k;                   /* '<S70>/low_pass' */
  real_T low_pass_o;                   /* '<S71>/low_pass' */
  real_T low_pass_d;                   /* '<S72>/low_pass' */
  real_T low_pass_p;                   /* '<S73>/low_pass' */
  real_T low_pass_l2;                  /* '<S74>/low_pass' */
  real_T low_pass_kv;                  /* '<S75>/low_pass' */
  real_T high_pass;                    /* '<S68>/high_pass' */
  real_T Abs;                          /* '<S68>/Abs' */
  real_T high_pass_h;                  /* '<S69>/high_pass' */
  real_T Abs_p;                        /* '<S69>/Abs' */
  real_T high_pass_d;                  /* '<S70>/high_pass' */
  real_T Abs_e;                        /* '<S70>/Abs' */
  real_T high_pass_c;                  /* '<S71>/high_pass' */
  real_T Abs_o;                        /* '<S71>/Abs' */
  real_T high_pass_hg;                 /* '<S72>/high_pass' */
  real_T Abs_h;                        /* '<S72>/Abs' */
  real_T high_pass_ci;                 /* '<S73>/high_pass' */
  real_T Abs_i;                        /* '<S73>/Abs' */
  real_T high_pass_i;                  /* '<S74>/high_pass' */
  real_T Abs_id;                       /* '<S74>/Abs' */
  real_T high_pass_p;                  /* '<S75>/high_pass' */
  real_T Abs_m;                        /* '<S75>/Abs' */
  real_T Constant;                     /* '<S6>/Constant' */
  real_T Constant1;                    /* '<S6>/Constant1' */
  real_T SFunction1_o1_c;              /* '<S96>/S-Function1' */
  real_T SFunction1_o2_l;              /* '<S96>/S-Function1' */
  real_T SFunction1_o3;                /* '<S96>/S-Function1' */
  real_T SFunction1_o4;                /* '<S96>/S-Function1' */
  real_T SFunction1_o5;                /* '<S96>/S-Function1' */
  real_T DataTypeConversion;           /* '<S97>/Data Type Conversion' */
  real_T Gain_gd;                      /* '<S97>/Gain' */
  real_T DataTypeConversion_j;         /* '<S98>/Data Type Conversion' */
  real_T Gain_b;                       /* '<S98>/Gain' */
  real_T DataTypeConversion_m;         /* '<S99>/Data Type Conversion' */
  real_T Gain_n4;                      /* '<S99>/Gain' */
  real_T SFunction1_o1_h;              /* '<S94>/S-Function1' */
  real_T SFunction1_o2_f;              /* '<S94>/S-Function1' */
  real_T SFunction1_o3_g;              /* '<S94>/S-Function1' */
  real_T SineWave;                     /* '<S92>/Sine Wave' */
  real_T SFunction1_o1_l;              /* '<S95>/S-Function1' */
  real_T SFunction1_o2_jb;             /* '<S95>/S-Function1' */
  real_T SFunction1_o3_p;              /* '<S95>/S-Function1' */
  real_T SFunction1_o4_k;              /* '<S95>/S-Function1' */
  real_T Gain2_ch;                     /* '<S14>/Gain2' */
  real_T Gain1_la;                     /* '<S14>/Gain1' */
  real_T Gain2_o;                      /* '<S15>/Gain2' */
  real_T Gain1_h;                      /* '<S15>/Gain1' */
  real_T torque_des_r;                 /* '<S2>/Torque Track R' */
  real_T torque_delta_des_r;           /* '<S2>/Torque Track R' */
  real_T torque_trace_r[1500];         /* '<S2>/Torque Track R' */
  real_T torque_delta_trace_r[1500];   /* '<S2>/Torque Track R' */
  real_T torque_error_r[2];            /* '<S2>/Torque Track R' */
  real_T torque_des_l;                 /* '<S2>/Torque Track L' */
  real_T torque_delta_des_l;           /* '<S2>/Torque Track L' */
  real_T torque_trace_l[1500];         /* '<S2>/Torque Track L' */
  real_T torque_delta_trace_l[1500];   /* '<S2>/Torque Track L' */
  real_T torque_error_l[2];            /* '<S2>/Torque Track L' */
  real_T lrn_cmd_r;                    /* '<S2>/LRN_R' */
  real_T lrn_mem_r[750];               /* '<S2>/LRN_R' */
  real_T lrn_cmd_l;                    /* '<S2>/LRN_L' */
  real_T lrn_mem_l[750];               /* '<S2>/LRN_L' */
  real_T motor_vel_cmd_r;              /* '<S2>/Controller_R' */
  real_T motor_vel_cmd_l;              /* '<S2>/Controller_L' */
  real_T mode_r;                       /* '<S8>/State Machine' */
  real_T state_r;                      /* '<S8>/State Machine' */
  real_T stride_time_r;                /* '<S8>/State Machine' */
  real_T stride_timer_r;               /* '<S8>/State Machine' */
  real_T mode_l;                       /* '<S7>/State Machine' */
  real_T state_l;                      /* '<S7>/State Machine' */
  real_T stride_time_l;                /* '<S7>/State Machine' */
  real_T stride_timer_l;               /* '<S7>/State Machine' */
  real_T torque_dot;                   /* '<S34>/MATLAB Function' */
  real_T torque;                       /* '<S34>/Calibration_R' */
  real_T torque_k;                     /* '<S34>/Calibration_L' */
  real_T angle;                        /* '<S33>/Calibration_R' */
  real_T angle_a;                      /* '<S33>/Calibration_L' */
  real_T x[8];                         /* '<S30>/Mux1' */
  real_T angle_k;                      /* '<S29>/Calibration_R' */
  real_T angle_b;                      /* '<S29>/Calibration_L' */
  real_T x_k[9];                       /* '<S23>/Mux1' */
  real_T x_h[6];                       /* '<S22>/Mux1' */
  real_T parm_out[9];                  /* '<Root>/AutoTunning' */
  real_T scan_state;                   /* '<Root>/AutoTunning' */
  real_T scan_step;                    /* '<Root>/AutoTunning' */
  boolean_T SFunction1_o3_b;           /* '<S37>/S-Function1' */
  boolean_T SFunction1_it;             /* '<S84>/S-Function1' */
  boolean_T SFunction1_jo;             /* '<S85>/S-Function1' */
  boolean_T SFunction1_o3_h;           /* '<S38>/S-Function1' */
  B_MATLABFunction_Bilateral_An_T sf_MATLABFunction_b;/* '<S15>/MATLAB Function' */
  B_MATLABFunction_Bilateral_An_T sf_MATLABFunction_h;/* '<S14>/MATLAB Function' */
  B_Mux1_Bilateral_Ankle_Exo_c_T sf_Mux1;/* '<S8>/Mux1' */
  B_Mux1_Bilateral_Ankle_Exo_c_T sf_Mux1_p;/* '<S7>/Mux1' */
  B_Mux_Bilateral_Ankle_Exo_T sf_Mux_R;/* '<S34>/Mux_R' */
  B_Mux_Bilateral_Ankle_Exo_T sf_Mux_L;/* '<S34>/Mux_L' */
  B_Mux1_Bilateral_Ankle_Exo_T sf_Mux3;/* '<S33>/Mux3' */
  B_Mux1_Bilateral_Ankle_Exo_T sf_Mux1_o;/* '<S33>/Mux1' */
  B_Filter_L_Bilateral_Ankle_Ex_T sf_Filter_R;/* '<S31>/Filter_R' */
  B_Filter_L_Bilateral_Ankle_Ex_T sf_Filter_L;/* '<S31>/Filter_L' */
  B_MVC_Bilateral_Ankle_Exo_T sf_MVC_f;/* '<S75>/MVC' */
  B_MVC_Bilateral_Ankle_Exo_T sf_MVC_d;/* '<S74>/MVC' */
  B_MVC_Bilateral_Ankle_Exo_T sf_MVC_md;/* '<S73>/MVC' */
  B_MVC_Bilateral_Ankle_Exo_T sf_MVC_m;/* '<S72>/MVC' */
  B_MVC_Bilateral_Ankle_Exo_T sf_MVC_j;/* '<S71>/MVC' */
  B_MVC_Bilateral_Ankle_Exo_T sf_MVC_e;/* '<S70>/MVC' */
  B_MVC_Bilateral_Ankle_Exo_T sf_MVC_o;/* '<S69>/MVC' */
  B_MVC_Bilateral_Ankle_Exo_T sf_MVC;  /* '<S68>/MVC' */
  B_EMG_o8_Bilateral_Ankle_Exo_T sf_EMG_p8;/* '<S30>/EMG_p8' */
  B_EMG_o7_Bilateral_Ankle_Exo_T sf_EMG_p7;/* '<S30>/EMG_p7' */
  B_EMG_o6_Bilateral_Ankle_Exo_T sf_EMG_p6;/* '<S30>/EMG_p6' */
  B_EMG_o5_Bilateral_Ankle_Exo_T sf_EMG_p5;/* '<S30>/EMG_p5' */
  B_EMG4_Bilateral_Ankle_Exo_T sf_EMG_p4;/* '<S30>/EMG_p4' */
  B_EMG3_Bilateral_Ankle_Exo_T sf_EMG_p3;/* '<S30>/EMG_p3' */
  B_EMG_o2_Bilateral_Ankle_Exo_T sf_EMG_p2;/* '<S30>/EMG_p2' */
  B_EMG_o1_Bilateral_Ankle_Exo_T sf_EMG_p1;/* '<S30>/EMG_p1' */
  B_EMG_o8_Bilateral_Ankle_Exo_T sf_EMG_o8;/* '<S30>/EMG_o8' */
  B_EMG_o7_Bilateral_Ankle_Exo_T sf_EMG_o7;/* '<S30>/EMG_o7' */
  B_EMG_o6_Bilateral_Ankle_Exo_T sf_EMG_o6;/* '<S30>/EMG_o6' */
  B_EMG_o5_Bilateral_Ankle_Exo_T sf_EMG_o5;/* '<S30>/EMG_o5' */
  B_EMG_o2_Bilateral_Ankle_Exo_T sf_EMG_o2;/* '<S30>/EMG_o2' */
  B_EMG_o1_Bilateral_Ankle_Exo_T sf_EMG_o1;/* '<S30>/EMG_o1' */
  B_EMG4_Bilateral_Ankle_Exo_T sf_EMG4;/* '<S30>/EMG4' */
  B_EMG3_Bilateral_Ankle_Exo_T sf_EMG3;/* '<S30>/EMG3' */
  B_Mux_Bilateral_Ankle_Exo_T sf_Mux1_b;/* '<S29>/Mux1' */
  B_Mux_Bilateral_Ankle_Exo_T sf_Mux;  /* '<S29>/Mux' */
} B_Bilateral_Ankle_Exo_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T u4low2_states[3];             /* '<S34>/0.4low2' */
  real_T UnitDelay1_DSTATE;            /* '<S110>/Unit Delay1' */
  real_T UnitDelay_DSTATE;             /* '<S110>/Unit Delay' */
  real_T UnitDelay2_DSTATE;            /* '<S110>/Unit Delay2' */
  real_T UnitDelay1_DSTATE_n;          /* '<S101>/Unit Delay1' */
  real_T UnitDelay_DSTATE_o;           /* '<S101>/Unit Delay' */
  real_T UnitDelay2_DSTATE_i;          /* '<S101>/Unit Delay2' */
  real_T u4low1_states[3];             /* '<S34>/0.4low1' */
  real_T UnitDelay1_DSTATE_m;          /* '<S111>/Unit Delay1' */
  real_T UnitDelay_DSTATE_n;           /* '<S111>/Unit Delay' */
  real_T UnitDelay2_DSTATE_l;          /* '<S111>/Unit Delay2' */
  real_T UnitDelay1_DSTATE_f;          /* '<S100>/Unit Delay1' */
  real_T UnitDelay_DSTATE_a;           /* '<S100>/Unit Delay' */
  real_T UnitDelay2_DSTATE_e;          /* '<S100>/Unit Delay2' */
  real_T u4low2_tmp;                   /* '<S34>/0.4low2' */
  volatile real_T RT4_Buffer0[2];      /* '<Root>/RT4' */
  volatile real_T RT4_Buffer1[2];      /* '<Root>/RT4' */
  volatile real_T RT5_Buffer0[2];      /* '<Root>/RT5' */
  volatile real_T RT5_Buffer1[2];      /* '<Root>/RT5' */
  volatile real_T RT6_Buffer0[3];      /* '<Root>/RT6' */
  volatile real_T RT6_Buffer1[3];      /* '<Root>/RT6' */
  volatile real_T RT1_Buffer0[4];      /* '<Root>/RT1' */
  volatile real_T RT1_Buffer1[4];      /* '<Root>/RT1' */
  volatile real_T RT2_Buffer0[6];      /* '<Root>/RT2' */
  volatile real_T RT2_Buffer1[6];      /* '<Root>/RT2' */
  volatile real_T RT3_Buffer0[9];      /* '<Root>/RT3' */
  volatile real_T RT3_Buffer1[9];      /* '<Root>/RT3' */
  volatile real_T RT7_Buffer0[4];      /* '<Root>/RT7' */
  volatile real_T RT7_Buffer1[4];      /* '<Root>/RT7' */
  real_T u4low1_tmp;                   /* '<S34>/0.4low1' */
  volatile real_T RT8_Buffer0[2];      /* '<Root>/RT8' */
  volatile real_T RT8_Buffer1[2];      /* '<Root>/RT8' */
  volatile real_T RT9_Buffer0[2];      /* '<Root>/RT9' */
  volatile real_T RT9_Buffer1[2];      /* '<Root>/RT9' */
  volatile real_T RT10_Buffer0[3];     /* '<Root>/RT10' */
  volatile real_T RT10_Buffer1[3];     /* '<Root>/RT10' */
  real_T TorqueMem_R[4400];            /* '<Root>/Data Store Memory' */
  real_T ParmReg_R[10];                /* '<Root>/Data Store Memory1' */
  real_T ParmReg_L[10];                /* '<Root>/Data Store Memory2' */
  real_T TorqueMem_L[4400];            /* '<Root>/Data Store Memory3' */
  real_T last_footstate;               /* '<S2>/Torque Track R' */
  real_T last_footstate_h;             /* '<S2>/Torque Track L' */
  real_T last_footstate_a;             /* '<S2>/LRN_R' */
  real_T torque_error_memory[1000];    /* '<S2>/LRN_R' */
  real_T lrn_cmd_memory[1000];         /* '<S2>/LRN_R' */
  real_T last_torque_parm[2];          /* '<S2>/LRN_R' */
  real_T last_footstate_g;             /* '<S2>/LRN_L' */
  real_T torque_error_memory_h[1000];  /* '<S2>/LRN_L' */
  real_T lrn_cmd_memory_n[1000];       /* '<S2>/LRN_L' */
  real_T last_torque_parm_m[2];        /* '<S2>/LRN_L' */
  real_T calib_state;                  /* '<S2>/Controller_R' */
  real_T smooth_filter;                /* '<S2>/Controller_R' */
  real_T calib_state_p;                /* '<S2>/Controller_L' */
  real_T smooth_filter_b;              /* '<S2>/Controller_L' */
  real_T reg_stride_time;              /* '<S8>/State Machine' */
  real_T reg_stride_time_count;        /* '<S8>/State Machine' */
  real_T reg_mode;                     /* '<S8>/State Machine' */
  real_T reg_state;                    /* '<S8>/State Machine' */
  real_T bt_run;                       /* '<S8>/State Machine' */
  real_T reg_last_switch;              /* '<S8>/State Machine' */
  real_T reg_stride_time_e;            /* '<S7>/State Machine' */
  real_T reg_stride_time_count_a;      /* '<S7>/State Machine' */
  real_T reg_mode_d;                   /* '<S7>/State Machine' */
  real_T reg_state_p;                  /* '<S7>/State Machine' */
  real_T bt_run_c;                     /* '<S7>/State Machine' */
  real_T reg_last_switch_p;            /* '<S7>/State Machine' */
  real_T data[15];                     /* '<S34>/MATLAB Function' */
  real_T last_state;                   /* '<Root>/AutoTunning' */
  real_T Scan_state;                   /* '<Root>/AutoTunning' */
  real_T Scan_step;                    /* '<Root>/AutoTunning' */
  real_T Scan_dir;                     /* '<Root>/AutoTunning' */
  real_T step_count;                   /* '<Root>/AutoTunning' */
  real_T parm_delta;                   /* '<Root>/AutoTunning' */
  int_T SFunction1_IWORK[2];           /* '<S90>/S-Function1' */
  int_T SFunction1_IWORK_c[2];         /* '<S91>/S-Function1' */
  volatile int8_T RT4_write_buf;       /* '<Root>/RT4' */
  volatile int8_T RT4_read_buf;        /* '<Root>/RT4' */
  volatile int8_T RT4_last_buf_wr;     /* '<Root>/RT4' */
  volatile int8_T RT5_write_buf;       /* '<Root>/RT5' */
  volatile int8_T RT5_read_buf;        /* '<Root>/RT5' */
  volatile int8_T RT5_last_buf_wr;     /* '<Root>/RT5' */
  volatile int8_T RT6_write_buf;       /* '<Root>/RT6' */
  volatile int8_T RT6_read_buf;        /* '<Root>/RT6' */
  volatile int8_T RT6_last_buf_wr;     /* '<Root>/RT6' */
  volatile int8_T RT1_write_buf;       /* '<Root>/RT1' */
  volatile int8_T RT1_read_buf;        /* '<Root>/RT1' */
  volatile int8_T RT1_last_buf_wr;     /* '<Root>/RT1' */
  volatile int8_T RT2_write_buf;       /* '<Root>/RT2' */
  volatile int8_T RT2_read_buf;        /* '<Root>/RT2' */
  volatile int8_T RT2_last_buf_wr;     /* '<Root>/RT2' */
  volatile int8_T RT3_write_buf;       /* '<Root>/RT3' */
  volatile int8_T RT3_read_buf;        /* '<Root>/RT3' */
  volatile int8_T RT3_last_buf_wr;     /* '<Root>/RT3' */
  volatile int8_T RT7_write_buf;       /* '<Root>/RT7' */
  volatile int8_T RT7_read_buf;        /* '<Root>/RT7' */
  volatile int8_T RT7_last_buf_wr;     /* '<Root>/RT7' */
  volatile int8_T RT8_write_buf;       /* '<Root>/RT8' */
  volatile int8_T RT8_read_buf;        /* '<Root>/RT8' */
  volatile int8_T RT8_last_buf_wr;     /* '<Root>/RT8' */
  volatile int8_T RT9_write_buf;       /* '<Root>/RT9' */
  volatile int8_T RT9_read_buf;        /* '<Root>/RT9' */
  volatile int8_T RT9_last_buf_wr;     /* '<Root>/RT9' */
  volatile int8_T RT10_write_buf;      /* '<Root>/RT10' */
  volatile int8_T RT10_read_buf;       /* '<Root>/RT10' */
  volatile int8_T RT10_last_buf_wr;    /* '<Root>/RT10' */
  boolean_T last_footstate_not_empty;  /* '<S2>/LRN_R' */
  boolean_T last_footstate_not_empty_o;/* '<S2>/LRN_L' */
  DW_Filter_L_Bilateral_Ankle_E_T sf_Filter_R;/* '<S31>/Filter_R' */
  DW_Filter_L_Bilateral_Ankle_E_T sf_Filter_L;/* '<S31>/Filter_L' */
} DW_Bilateral_Ankle_Exo_T;

/* Continuous states (auto storage) */
typedef struct {
  real_T low_pass_CSTATE[2];           /* '<S68>/low_pass' */
  real_T low_pass_CSTATE_n[2];         /* '<S69>/low_pass' */
  real_T low_pass_CSTATE_b[2];         /* '<S70>/low_pass' */
  real_T low_pass_CSTATE_a[2];         /* '<S71>/low_pass' */
  real_T low_pass_CSTATE_d[2];         /* '<S72>/low_pass' */
  real_T low_pass_CSTATE_de[2];        /* '<S73>/low_pass' */
  real_T low_pass_CSTATE_h[2];         /* '<S74>/low_pass' */
  real_T low_pass_CSTATE_l[2];         /* '<S75>/low_pass' */
  real_T high_pass_CSTATE[2];          /* '<S68>/high_pass' */
  real_T high_pass_CSTATE_p[2];        /* '<S69>/high_pass' */
  real_T high_pass_CSTATE_h[2];        /* '<S70>/high_pass' */
  real_T high_pass_CSTATE_f[2];        /* '<S71>/high_pass' */
  real_T high_pass_CSTATE_i[2];        /* '<S72>/high_pass' */
  real_T high_pass_CSTATE_o[2];        /* '<S73>/high_pass' */
  real_T high_pass_CSTATE_m[2];        /* '<S74>/high_pass' */
  real_T high_pass_CSTATE_f3[2];       /* '<S75>/high_pass' */
} X_Bilateral_Ankle_Exo_T;

/* State derivatives (auto storage) */
typedef struct {
  real_T low_pass_CSTATE[2];           /* '<S68>/low_pass' */
  real_T low_pass_CSTATE_n[2];         /* '<S69>/low_pass' */
  real_T low_pass_CSTATE_b[2];         /* '<S70>/low_pass' */
  real_T low_pass_CSTATE_a[2];         /* '<S71>/low_pass' */
  real_T low_pass_CSTATE_d[2];         /* '<S72>/low_pass' */
  real_T low_pass_CSTATE_de[2];        /* '<S73>/low_pass' */
  real_T low_pass_CSTATE_h[2];         /* '<S74>/low_pass' */
  real_T low_pass_CSTATE_l[2];         /* '<S75>/low_pass' */
  real_T high_pass_CSTATE[2];          /* '<S68>/high_pass' */
  real_T high_pass_CSTATE_p[2];        /* '<S69>/high_pass' */
  real_T high_pass_CSTATE_h[2];        /* '<S70>/high_pass' */
  real_T high_pass_CSTATE_f[2];        /* '<S71>/high_pass' */
  real_T high_pass_CSTATE_i[2];        /* '<S72>/high_pass' */
  real_T high_pass_CSTATE_o[2];        /* '<S73>/high_pass' */
  real_T high_pass_CSTATE_m[2];        /* '<S74>/high_pass' */
  real_T high_pass_CSTATE_f3[2];       /* '<S75>/high_pass' */
} XDot_Bilateral_Ankle_Exo_T;

/* State disabled  */
typedef struct {
  boolean_T low_pass_CSTATE[2];        /* '<S68>/low_pass' */
  boolean_T low_pass_CSTATE_n[2];      /* '<S69>/low_pass' */
  boolean_T low_pass_CSTATE_b[2];      /* '<S70>/low_pass' */
  boolean_T low_pass_CSTATE_a[2];      /* '<S71>/low_pass' */
  boolean_T low_pass_CSTATE_d[2];      /* '<S72>/low_pass' */
  boolean_T low_pass_CSTATE_de[2];     /* '<S73>/low_pass' */
  boolean_T low_pass_CSTATE_h[2];      /* '<S74>/low_pass' */
  boolean_T low_pass_CSTATE_l[2];      /* '<S75>/low_pass' */
  boolean_T high_pass_CSTATE[2];       /* '<S68>/high_pass' */
  boolean_T high_pass_CSTATE_p[2];     /* '<S69>/high_pass' */
  boolean_T high_pass_CSTATE_h[2];     /* '<S70>/high_pass' */
  boolean_T high_pass_CSTATE_f[2];     /* '<S71>/high_pass' */
  boolean_T high_pass_CSTATE_i[2];     /* '<S72>/high_pass' */
  boolean_T high_pass_CSTATE_o[2];     /* '<S73>/high_pass' */
  boolean_T high_pass_CSTATE_m[2];     /* '<S74>/high_pass' */
  boolean_T high_pass_CSTATE_f3[2];    /* '<S75>/high_pass' */
} XDis_Bilateral_Ankle_Exo_T;

#ifndef ODE1_INTG
#define ODE1_INTG

/* ODE1 Integration Data */
typedef struct {
  real_T *f[1];                        /* derivatives */
} ODE1_IntgData;

#endif

/* Parameters (auto storage) */
struct P_Bilateral_Ankle_Exo_T_ {
  real_T AutoTunning_BT_SCAN;          /* Mask Parameter: AutoTunning_BT_SCAN
                                        * Referenced by: '<Root>/AutoTunning'
                                        */
  real_T Controller_L_FOLLOW_SLACK_ANGLE;/* Mask Parameter: Controller_L_FOLLOW_SLACK_ANGLE
                                          * Referenced by: '<S2>/Controller_L'
                                          */
  real_T Controller_R_FOLLOW_SLACK_ANGLE;/* Mask Parameter: Controller_R_FOLLOW_SLACK_ANGLE
                                          * Referenced by: '<S2>/Controller_R'
                                          */
  real_T EMGmodule_Kemg;               /* Mask Parameter: EMGmodule_Kemg
                                        * Referenced by:
                                        *   '<S30>/Gain'
                                        *   '<S30>/Gain1'
                                        *   '<S30>/Gain2'
                                        *   '<S30>/Gain3'
                                        *   '<S30>/Gain4'
                                        *   '<S30>/Gain5'
                                        *   '<S30>/Gain6'
                                        *   '<S30>/Gain7'
                                        */
  real_T MATLABFunction_MAX_MOTOR_ANGLE;/* Mask Parameter: MATLABFunction_MAX_MOTOR_ANGLE
                                         * Referenced by: '<S14>/MATLAB Function'
                                         */
  real_T MATLABFunction_MAX_MOTOR_ANGL_a;/* Mask Parameter: MATLABFunction_MAX_MOTOR_ANGL_a
                                          * Referenced by: '<S15>/MATLAB Function'
                                          */
  real_T MATLABFunction_MAX_SPEED;     /* Mask Parameter: MATLABFunction_MAX_SPEED
                                        * Referenced by: '<S14>/MATLAB Function'
                                        */
  real_T MATLABFunction_MAX_SPEED_a;   /* Mask Parameter: MATLABFunction_MAX_SPEED_a
                                        * Referenced by: '<S15>/MATLAB Function'
                                        */
  real_T MATLABFunction_MAX_TORQUE;    /* Mask Parameter: MATLABFunction_MAX_TORQUE
                                        * Referenced by: '<S14>/MATLAB Function'
                                        */
  real_T MATLABFunction_MAX_TORQUE_p;  /* Mask Parameter: MATLABFunction_MAX_TORQUE_p
                                        * Referenced by: '<S15>/MATLAB Function'
                                        */
  real_T MATLABFunction_MIN_MOTOR_ANGLE;/* Mask Parameter: MATLABFunction_MIN_MOTOR_ANGLE
                                         * Referenced by: '<S14>/MATLAB Function'
                                         */
  real_T MATLABFunction_MIN_MOTOR_ANGL_g;/* Mask Parameter: MATLABFunction_MIN_MOTOR_ANGL_g
                                          * Referenced by: '<S15>/MATLAB Function'
                                          */
  real_T AutoTunning_Parm_index;       /* Mask Parameter: AutoTunning_Parm_index
                                        * Referenced by: '<Root>/AutoTunning'
                                        */
  real_T Controller_L_SWING_MAX_ANGLE_L;/* Mask Parameter: Controller_L_SWING_MAX_ANGLE_L
                                         * Referenced by: '<S2>/Controller_L'
                                         */
  real_T Controller_R_SWING_MAX_ANGLE_R;/* Mask Parameter: Controller_R_SWING_MAX_ANGLE_R
                                         * Referenced by: '<S2>/Controller_R'
                                         */
  real_T AutoTunning_Scan_Interval;    /* Mask Parameter: AutoTunning_Scan_Interval
                                        * Referenced by: '<Root>/AutoTunning'
                                        */
  real_T AutoTunning_Scan_Max;         /* Mask Parameter: AutoTunning_Scan_Max
                                        * Referenced by: '<Root>/AutoTunning'
                                        */
  real_T AutoTunning_Scan_Min;         /* Mask Parameter: AutoTunning_Scan_Min
                                        * Referenced by: '<Root>/AutoTunning'
                                        */
  real_T uOrderTD_T1;                  /* Mask Parameter: uOrderTD_T1
                                        * Referenced by:
                                        *   '<S110>/Gain1'
                                        *   '<S110>/Gain2'
                                        *   '<S110>/Gain4'
                                        */
  real_T uOrderTD1_T1;                 /* Mask Parameter: uOrderTD1_T1
                                        * Referenced by:
                                        *   '<S101>/Gain1'
                                        *   '<S101>/Gain2'
                                        *   '<S101>/Gain4'
                                        */
  real_T uOrderTD1_T1_a;               /* Mask Parameter: uOrderTD1_T1_a
                                        * Referenced by:
                                        *   '<S111>/Gain1'
                                        *   '<S111>/Gain2'
                                        *   '<S111>/Gain4'
                                        */
  real_T uOrderTD_T1_p;                /* Mask Parameter: uOrderTD_T1_p
                                        * Referenced by:
                                        *   '<S100>/Gain1'
                                        *   '<S100>/Gain2'
                                        *   '<S100>/Gain4'
                                        */
  real_T uOrderTD_T2;                  /* Mask Parameter: uOrderTD_T2
                                        * Referenced by:
                                        *   '<S110>/Gain1'
                                        *   '<S110>/Gain2'
                                        *   '<S110>/Gain4'
                                        */
  real_T uOrderTD1_T2;                 /* Mask Parameter: uOrderTD1_T2
                                        * Referenced by:
                                        *   '<S101>/Gain1'
                                        *   '<S101>/Gain2'
                                        *   '<S101>/Gain4'
                                        */
  real_T uOrderTD1_T2_f;               /* Mask Parameter: uOrderTD1_T2_f
                                        * Referenced by:
                                        *   '<S111>/Gain1'
                                        *   '<S111>/Gain2'
                                        *   '<S111>/Gain4'
                                        */
  real_T uOrderTD_T2_k;                /* Mask Parameter: uOrderTD_T2_k
                                        * Referenced by:
                                        *   '<S100>/Gain1'
                                        *   '<S100>/Gain2'
                                        *   '<S100>/Gain4'
                                        */
  real_T uOrderTD_Ts;                  /* Mask Parameter: uOrderTD_Ts
                                        * Referenced by:
                                        *   '<S110>/Gain'
                                        *   '<S110>/Gain3'
                                        */
  real_T uOrderTD1_Ts;                 /* Mask Parameter: uOrderTD1_Ts
                                        * Referenced by:
                                        *   '<S101>/Gain'
                                        *   '<S101>/Gain3'
                                        */
  real_T uOrderTD1_Ts_a;               /* Mask Parameter: uOrderTD1_Ts_a
                                        * Referenced by:
                                        *   '<S111>/Gain'
                                        *   '<S111>/Gain3'
                                        */
  real_T uOrderTD_Ts_n;                /* Mask Parameter: uOrderTD_Ts_n
                                        * Referenced by:
                                        *   '<S100>/Gain'
                                        *   '<S100>/Gain3'
                                        */
  real_T LRN_L_error_filter_k_l;       /* Mask Parameter: LRN_L_error_filter_k_l
                                        * Referenced by: '<S2>/LRN_L'
                                        */
  real_T LRN_R_error_filter_k_r;       /* Mask Parameter: LRN_R_error_filter_k_r
                                        * Referenced by: '<S2>/LRN_R'
                                        */
  real_T Calibration_L_load_vol_gain;  /* Mask Parameter: Calibration_L_load_vol_gain
                                        * Referenced by: '<S34>/Calibration_L'
                                        */
  real_T Calibration_R_load_vol_gain;  /* Mask Parameter: Calibration_R_load_vol_gain
                                        * Referenced by: '<S34>/Calibration_R'
                                        */
  real_T Calibration_L_load_vol_offset;/* Mask Parameter: Calibration_L_load_vol_offset
                                        * Referenced by: '<S34>/Calibration_L'
                                        */
  real_T Calibration_R_load_vol_offset;/* Mask Parameter: Calibration_R_load_vol_offset
                                        * Referenced by: '<S34>/Calibration_R'
                                        */
  real_T LRN_L_lrn_shrink_l;           /* Mask Parameter: LRN_L_lrn_shrink_l
                                        * Referenced by: '<S2>/LRN_L'
                                        */
  real_T LRN_R_lrn_shrink_r;           /* Mask Parameter: LRN_R_lrn_shrink_r
                                        * Referenced by: '<S2>/LRN_R'
                                        */
  real_T Preprocessing1_r_SOL_MAX;     /* Mask Parameter: Preprocessing1_r_SOL_MAX
                                        * Referenced by: '<S68>/MVC'
                                        */
  real_T Preprocessing2_r_SOL_MAX;     /* Mask Parameter: Preprocessing2_r_SOL_MAX
                                        * Referenced by: '<S69>/MVC'
                                        */
  real_T Preprocessing3_r_SOL_MAX;     /* Mask Parameter: Preprocessing3_r_SOL_MAX
                                        * Referenced by: '<S70>/MVC'
                                        */
  real_T Preprocessing4_r_SOL_MAX;     /* Mask Parameter: Preprocessing4_r_SOL_MAX
                                        * Referenced by: '<S71>/MVC'
                                        */
  real_T Preprocessing5_r_SOL_MAX;     /* Mask Parameter: Preprocessing5_r_SOL_MAX
                                        * Referenced by: '<S72>/MVC'
                                        */
  real_T Preprocessing6_r_SOL_MAX;     /* Mask Parameter: Preprocessing6_r_SOL_MAX
                                        * Referenced by: '<S73>/MVC'
                                        */
  real_T Preprocessing7_r_SOL_MAX;     /* Mask Parameter: Preprocessing7_r_SOL_MAX
                                        * Referenced by: '<S74>/MVC'
                                        */
  real_T Preprocessing8_r_SOL_MAX;     /* Mask Parameter: Preprocessing8_r_SOL_MAX
                                        * Referenced by: '<S75>/MVC'
                                        */
  real_T Preprocessing1_r_SOL_MIN;     /* Mask Parameter: Preprocessing1_r_SOL_MIN
                                        * Referenced by: '<S68>/MVC'
                                        */
  real_T Preprocessing2_r_SOL_MIN;     /* Mask Parameter: Preprocessing2_r_SOL_MIN
                                        * Referenced by: '<S69>/MVC'
                                        */
  real_T Preprocessing3_r_SOL_MIN;     /* Mask Parameter: Preprocessing3_r_SOL_MIN
                                        * Referenced by: '<S70>/MVC'
                                        */
  real_T Preprocessing4_r_SOL_MIN;     /* Mask Parameter: Preprocessing4_r_SOL_MIN
                                        * Referenced by: '<S71>/MVC'
                                        */
  real_T Preprocessing5_r_SOL_MIN;     /* Mask Parameter: Preprocessing5_r_SOL_MIN
                                        * Referenced by: '<S72>/MVC'
                                        */
  real_T Preprocessing6_r_SOL_MIN;     /* Mask Parameter: Preprocessing6_r_SOL_MIN
                                        * Referenced by: '<S73>/MVC'
                                        */
  real_T Preprocessing7_r_SOL_MIN;     /* Mask Parameter: Preprocessing7_r_SOL_MIN
                                        * Referenced by: '<S74>/MVC'
                                        */
  real_T Preprocessing8_r_SOL_MIN;     /* Mask Parameter: Preprocessing8_r_SOL_MIN
                                        * Referenced by: '<S75>/MVC'
                                        */
  int32_T LRN_L_time_delay_l;          /* Mask Parameter: LRN_L_time_delay_l
                                        * Referenced by: '<S2>/LRN_L'
                                        */
  int32_T LRN_R_time_delay_r;          /* Mask Parameter: LRN_R_time_delay_r
                                        * Referenced by: '<S2>/LRN_R'
                                        */
  int8_T Controller_L_MODE_L;          /* Mask Parameter: Controller_L_MODE_L
                                        * Referenced by: '<S2>/Controller_L'
                                        */
  int8_T Controller_R_MODE_R;          /* Mask Parameter: Controller_R_MODE_R
                                        * Referenced by: '<S2>/Controller_R'
                                        */
  boolean_T StateMachine_BT_CALIB_L;   /* Mask Parameter: StateMachine_BT_CALIB_L
                                        * Referenced by: '<S7>/State Machine'
                                        */
  boolean_T StateMachine_BT_CALIB_R;   /* Mask Parameter: StateMachine_BT_CALIB_R
                                        * Referenced by: '<S8>/State Machine'
                                        */
  boolean_T StateMachine_BT_ERROR_L;   /* Mask Parameter: StateMachine_BT_ERROR_L
                                        * Referenced by: '<S7>/State Machine'
                                        */
  boolean_T StateMachine_BT_ERROR_R;   /* Mask Parameter: StateMachine_BT_ERROR_R
                                        * Referenced by: '<S8>/State Machine'
                                        */
  boolean_T StateMachine_BT_IDLE_L;    /* Mask Parameter: StateMachine_BT_IDLE_L
                                        * Referenced by: '<S7>/State Machine'
                                        */
  boolean_T StateMachine_BT_IDLE_R;    /* Mask Parameter: StateMachine_BT_IDLE_R
                                        * Referenced by: '<S8>/State Machine'
                                        */
  boolean_T LRN_L_BT_LRN_CLEAR_L;      /* Mask Parameter: LRN_L_BT_LRN_CLEAR_L
                                        * Referenced by: '<S2>/LRN_L'
                                        */
  boolean_T LRN_R_BT_LRN_CLEAR_R;      /* Mask Parameter: LRN_R_BT_LRN_CLEAR_R
                                        * Referenced by: '<S2>/LRN_R'
                                        */
  boolean_T LRN_L_BT_LRN_ON_L;         /* Mask Parameter: LRN_L_BT_LRN_ON_L
                                        * Referenced by: '<S2>/LRN_L'
                                        */
  boolean_T LRN_R_BT_LRN_ON_R;         /* Mask Parameter: LRN_R_BT_LRN_ON_R
                                        * Referenced by: '<S2>/LRN_R'
                                        */
  boolean_T Calibration_L_BT_RESET_ANKLE_L;/* Mask Parameter: Calibration_L_BT_RESET_ANKLE_L
                                            * Referenced by: '<S29>/Calibration_L'
                                            */
  boolean_T Calibration_R_BT_RESET_ANKLE_R;/* Mask Parameter: Calibration_R_BT_RESET_ANKLE_R
                                            * Referenced by: '<S29>/Calibration_R'
                                            */
  boolean_T Calibration_L_BT_RESET_MOTOR_L;/* Mask Parameter: Calibration_L_BT_RESET_MOTOR_L
                                            * Referenced by: '<S33>/Calibration_L'
                                            */
  boolean_T Calibration_R_BT_RESET_MOTOR_R;/* Mask Parameter: Calibration_R_BT_RESET_MOTOR_R
                                            * Referenced by: '<S33>/Calibration_R'
                                            */
  boolean_T Calibration_L_BT_RESET_TORQUE_L;/* Mask Parameter: Calibration_L_BT_RESET_TORQUE_L
                                             * Referenced by: '<S34>/Calibration_L'
                                             */
  boolean_T Calibration_R_BT_RESET_TORQUE_R;/* Mask Parameter: Calibration_R_BT_RESET_TORQUE_R
                                             * Referenced by: '<S34>/Calibration_R'
                                             */
  boolean_T StateMachine_BT_RUN_L;     /* Mask Parameter: StateMachine_BT_RUN_L
                                        * Referenced by: '<S7>/State Machine'
                                        */
  boolean_T StateMachine_BT_RUN_R;     /* Mask Parameter: StateMachine_BT_RUN_R
                                        * Referenced by: '<S8>/State Machine'
                                        */
  boolean_T StateMachine_BT_SLACK_L;   /* Mask Parameter: StateMachine_BT_SLACK_L
                                        * Referenced by: '<S7>/State Machine'
                                        */
  boolean_T StateMachine_BT_SLACK_R;   /* Mask Parameter: StateMachine_BT_SLACK_R
                                        * Referenced by: '<S8>/State Machine'
                                        */
  real_T torque_offset_Value;          /* Expression: 2
                                        * Referenced by: '<S2>/torque_offset'
                                        */
  real_T Gain2_Gain;                   /* Expression: 1/360
                                        * Referenced by: '<S14>/Gain2'
                                        */
  real_T Gain1_Gain;                   /* Expression: 1/100
                                        * Referenced by: '<S14>/Gain1'
                                        */
  real_T Gain2_Gain_g;                 /* Expression: 1/360
                                        * Referenced by: '<S15>/Gain2'
                                        */
  real_T Gain1_Gain_c;                 /* Expression: -1/100
                                        * Referenced by: '<S15>/Gain1'
                                        */
  real_T Gain_Gain;                    /* Expression: 10
                                        * Referenced by: '<S34>/Gain'
                                        */
  real_T u4low2_NumCoef[4];            /* Expression: [0.219606211225382   0.658818633676145   0.658818633676145   0.219606211225382]*1e-3
                                        * Referenced by: '<S34>/0.4low2'
                                        */
  real_T u4low2_DenCoef[4];            /* Expression: [1.000000000000000  -2.748835809214676   2.528231219142559  -0.777638560238080]
                                        * Referenced by: '<S34>/0.4low2'
                                        */
  real_T u4low2_InitialStates;         /* Expression: 0
                                        * Referenced by: '<S34>/0.4low2'
                                        */
  real_T UnitDelay1_InitialCondition;  /* Expression: 0
                                        * Referenced by: '<S110>/Unit Delay1'
                                        */
  real_T UnitDelay_InitialCondition;   /* Expression: 0
                                        * Referenced by: '<S110>/Unit Delay'
                                        */
  real_T UnitDelay2_InitialCondition;  /* Expression: 0
                                        * Referenced by: '<S110>/Unit Delay2'
                                        */
  real_T RT4_InitialCondition;         /* Expression: 0
                                        * Referenced by: '<Root>/RT4'
                                        */
  real_T Gain_Gain_o;                  /* Expression: -360/2000
                                        * Referenced by: '<S29>/Gain'
                                        */
  real_T Gain1_Gain_m;                 /* Expression: -360/2000
                                        * Referenced by: '<S29>/Gain1'
                                        */
  real_T RT5_InitialCondition;         /* Expression: 0
                                        * Referenced by: '<Root>/RT5'
                                        */
  real_T Gain1_Gain_cu;                /* Expression: 360.0/1250.0
                                        * Referenced by: '<S33>/Gain1'
                                        */
  real_T Gain4_Gain;                   /* Expression: 360.0/1250.0
                                        * Referenced by: '<S33>/Gain4'
                                        */
  real_T UnitDelay1_InitialCondition_e;/* Expression: 0
                                        * Referenced by: '<S101>/Unit Delay1'
                                        */
  real_T UnitDelay_InitialCondition_b; /* Expression: 0
                                        * Referenced by: '<S101>/Unit Delay'
                                        */
  real_T UnitDelay2_InitialCondition_m;/* Expression: 0
                                        * Referenced by: '<S101>/Unit Delay2'
                                        */
  real_T RT6_InitialCondition;         /* Expression: 0
                                        * Referenced by: '<Root>/RT6'
                                        */
  real_T RT1_InitialCondition;         /* Expression: 0
                                        * Referenced by: '<Root>/RT1'
                                        */
  real_T Kp_Value;                     /* Expression: 8
                                        * Referenced by: '<S22>/Kp'
                                        */
  real_T Kd_Value;                     /* Expression: 0
                                        * Referenced by: '<S22>/Kd'
                                        */
  real_T Kl_Value;                     /* Expression: 0.05
                                        * Referenced by: '<S22>/Kl'
                                        */
  real_T Ksp_Value;                    /* Expression: 3
                                        * Referenced by: '<S22>/Ksp'
                                        */
  real_T Ksd_Value;                    /* Expression: 0.2
                                        * Referenced by: '<S22>/Ksd'
                                        */
  real_T Ko_Value;                     /* Expression: 0
                                        * Referenced by: '<S22>/Ko'
                                        */
  real_T controlreset_Value;           /* Expression: 0
                                        * Referenced by: '<S22>/control reset'
                                        */
  real_T RT2_InitialCondition;         /* Expression: 0
                                        * Referenced by: '<Root>/RT2'
                                        */
  real_T peak_torque_Value;            /* Expression: 0
                                        * Referenced by: '<S23>/peak_torque'
                                        */
  real_T rise_time_Value;              /* Expression: 20
                                        * Referenced by: '<S23>/rise_time'
                                        */
  real_T peak_time_Value;              /* Expression: 48
                                        * Referenced by: '<S23>/peak_time'
                                        */
  real_T fall_time_Value;              /* Expression: 10
                                        * Referenced by: '<S23>/fall_time'
                                        */
  real_T transit_time_Value;           /* Expression: 30
                                        * Referenced by: '<S23>/transit_time'
                                        */
  real_T maintain_time_Value;          /* Expression: 10
                                        * Referenced by: '<S23>/maintain_time'
                                        */
  real_T transit_torque_Value;         /* Expression: 30
                                        * Referenced by: '<S23>/transit_torque'
                                        */
  real_T maintain_torque_Value;        /* Expression: 30
                                        * Referenced by: '<S23>/maintain_torque'
                                        */
  real_T Torque_Mode_Value;            /* Expression: 1
                                        * Referenced by: '<S23>/Torque_Mode'
                                        */
  real_T RT3_InitialCondition;         /* Expression: 0
                                        * Referenced by: '<Root>/RT3'
                                        */
  real_T RT7_InitialCondition;         /* Expression: 0
                                        * Referenced by: '<Root>/RT7'
                                        */
  real_T Gain1_Gain_e;                 /* Expression: 10
                                        * Referenced by: '<S34>/Gain1'
                                        */
  real_T u4low1_NumCoef[4];            /* Expression: [0.219606211225382   0.658818633676145   0.658818633676145   0.219606211225382]*1e-3
                                        * Referenced by: '<S34>/0.4low1'
                                        */
  real_T u4low1_DenCoef[4];            /* Expression: [1.000000000000000  -2.748835809214676   2.528231219142559  -0.777638560238080]
                                        * Referenced by: '<S34>/0.4low1'
                                        */
  real_T u4low1_InitialStates;         /* Expression: 0
                                        * Referenced by: '<S34>/0.4low1'
                                        */
  real_T UnitDelay1_InitialCondition_i;/* Expression: 0
                                        * Referenced by: '<S111>/Unit Delay1'
                                        */
  real_T UnitDelay_InitialCondition_a; /* Expression: 0
                                        * Referenced by: '<S111>/Unit Delay'
                                        */
  real_T UnitDelay2_InitialCondition_e;/* Expression: 0
                                        * Referenced by: '<S111>/Unit Delay2'
                                        */
  real_T RT8_InitialCondition;         /* Expression: 0
                                        * Referenced by: '<Root>/RT8'
                                        */
  real_T Gain2_Gain_l;                 /* Expression: 360/2000
                                        * Referenced by: '<S29>/Gain2'
                                        */
  real_T Gain3_Gain;                   /* Expression: 360/2000
                                        * Referenced by: '<S29>/Gain3'
                                        */
  real_T RT9_InitialCondition;         /* Expression: 0
                                        * Referenced by: '<Root>/RT9'
                                        */
  real_T Gain2_Gain_h;                 /* Expression: -360.0/1250.0
                                        * Referenced by: '<S33>/Gain2'
                                        */
  real_T Gain3_Gain_e;                 /* Expression: -360.0/1250.0
                                        * Referenced by: '<S33>/Gain3'
                                        */
  real_T UnitDelay1_InitialCondition_b;/* Expression: 0
                                        * Referenced by: '<S100>/Unit Delay1'
                                        */
  real_T UnitDelay_InitialCondition_c; /* Expression: 0
                                        * Referenced by: '<S100>/Unit Delay'
                                        */
  real_T UnitDelay2_InitialCondition_c;/* Expression: 0
                                        * Referenced by: '<S100>/Unit Delay2'
                                        */
  real_T RT10_InitialCondition;        /* Expression: 0
                                        * Referenced by: '<Root>/RT10'
                                        */
  real_T low_pass_A[3];                /* Computed Parameter: low_pass_A
                                        * Referenced by: '<S68>/low_pass'
                                        */
  real_T low_pass_B;                   /* Computed Parameter: low_pass_B
                                        * Referenced by: '<S68>/low_pass'
                                        */
  real_T low_pass_C;                   /* Computed Parameter: low_pass_C
                                        * Referenced by: '<S68>/low_pass'
                                        */
  real_T low_pass_InitialCondition;    /* Expression: 0
                                        * Referenced by: '<S68>/low_pass'
                                        */
  real_T low_pass_A_k[3];              /* Computed Parameter: low_pass_A_k
                                        * Referenced by: '<S69>/low_pass'
                                        */
  real_T low_pass_B_f;                 /* Computed Parameter: low_pass_B_f
                                        * Referenced by: '<S69>/low_pass'
                                        */
  real_T low_pass_C_p;                 /* Computed Parameter: low_pass_C_p
                                        * Referenced by: '<S69>/low_pass'
                                        */
  real_T low_pass_InitialCondition_f;  /* Expression: 0
                                        * Referenced by: '<S69>/low_pass'
                                        */
  real_T low_pass_A_h[3];              /* Computed Parameter: low_pass_A_h
                                        * Referenced by: '<S70>/low_pass'
                                        */
  real_T low_pass_B_fe;                /* Computed Parameter: low_pass_B_fe
                                        * Referenced by: '<S70>/low_pass'
                                        */
  real_T low_pass_C_e;                 /* Computed Parameter: low_pass_C_e
                                        * Referenced by: '<S70>/low_pass'
                                        */
  real_T low_pass_InitialCondition_b;  /* Expression: 0
                                        * Referenced by: '<S70>/low_pass'
                                        */
  real_T low_pass_A_j[3];              /* Computed Parameter: low_pass_A_j
                                        * Referenced by: '<S71>/low_pass'
                                        */
  real_T low_pass_B_m;                 /* Computed Parameter: low_pass_B_m
                                        * Referenced by: '<S71>/low_pass'
                                        */
  real_T low_pass_C_f;                 /* Computed Parameter: low_pass_C_f
                                        * Referenced by: '<S71>/low_pass'
                                        */
  real_T low_pass_InitialCondition_bx; /* Expression: 0
                                        * Referenced by: '<S71>/low_pass'
                                        */
  real_T low_pass_A_e[3];              /* Computed Parameter: low_pass_A_e
                                        * Referenced by: '<S72>/low_pass'
                                        */
  real_T low_pass_B_d;                 /* Computed Parameter: low_pass_B_d
                                        * Referenced by: '<S72>/low_pass'
                                        */
  real_T low_pass_C_j;                 /* Computed Parameter: low_pass_C_j
                                        * Referenced by: '<S72>/low_pass'
                                        */
  real_T low_pass_InitialCondition_d;  /* Expression: 0
                                        * Referenced by: '<S72>/low_pass'
                                        */
  real_T low_pass_A_d[3];              /* Computed Parameter: low_pass_A_d
                                        * Referenced by: '<S73>/low_pass'
                                        */
  real_T low_pass_B_o;                 /* Computed Parameter: low_pass_B_o
                                        * Referenced by: '<S73>/low_pass'
                                        */
  real_T low_pass_C_eg;                /* Computed Parameter: low_pass_C_eg
                                        * Referenced by: '<S73>/low_pass'
                                        */
  real_T low_pass_InitialCondition_l;  /* Expression: 0
                                        * Referenced by: '<S73>/low_pass'
                                        */
  real_T low_pass_A_m[3];              /* Computed Parameter: low_pass_A_m
                                        * Referenced by: '<S74>/low_pass'
                                        */
  real_T low_pass_B_a;                 /* Computed Parameter: low_pass_B_a
                                        * Referenced by: '<S74>/low_pass'
                                        */
  real_T low_pass_C_h;                 /* Computed Parameter: low_pass_C_h
                                        * Referenced by: '<S74>/low_pass'
                                        */
  real_T low_pass_InitialCondition_lj; /* Expression: 0
                                        * Referenced by: '<S74>/low_pass'
                                        */
  real_T low_pass_A_n[3];              /* Computed Parameter: low_pass_A_n
                                        * Referenced by: '<S75>/low_pass'
                                        */
  real_T low_pass_B_e;                 /* Computed Parameter: low_pass_B_e
                                        * Referenced by: '<S75>/low_pass'
                                        */
  real_T low_pass_C_a;                 /* Computed Parameter: low_pass_C_a
                                        * Referenced by: '<S75>/low_pass'
                                        */
  real_T low_pass_InitialCondition_h;  /* Expression: 0
                                        * Referenced by: '<S75>/low_pass'
                                        */
  real_T high_pass_A[3];               /* Computed Parameter: high_pass_A
                                        * Referenced by: '<S68>/high_pass'
                                        */
  real_T high_pass_B;                  /* Computed Parameter: high_pass_B
                                        * Referenced by: '<S68>/high_pass'
                                        */
  real_T high_pass_C[2];               /* Computed Parameter: high_pass_C
                                        * Referenced by: '<S68>/high_pass'
                                        */
  real_T high_pass_D;                  /* Computed Parameter: high_pass_D
                                        * Referenced by: '<S68>/high_pass'
                                        */
  real_T high_pass_InitialCondition;   /* Expression: 0
                                        * Referenced by: '<S68>/high_pass'
                                        */
  real_T high_pass_A_d[3];             /* Computed Parameter: high_pass_A_d
                                        * Referenced by: '<S69>/high_pass'
                                        */
  real_T high_pass_B_p;                /* Computed Parameter: high_pass_B_p
                                        * Referenced by: '<S69>/high_pass'
                                        */
  real_T high_pass_C_l[2];             /* Computed Parameter: high_pass_C_l
                                        * Referenced by: '<S69>/high_pass'
                                        */
  real_T high_pass_D_p;                /* Computed Parameter: high_pass_D_p
                                        * Referenced by: '<S69>/high_pass'
                                        */
  real_T high_pass_InitialCondition_f; /* Expression: 0
                                        * Referenced by: '<S69>/high_pass'
                                        */
  real_T high_pass_A_c[3];             /* Computed Parameter: high_pass_A_c
                                        * Referenced by: '<S70>/high_pass'
                                        */
  real_T high_pass_B_e;                /* Computed Parameter: high_pass_B_e
                                        * Referenced by: '<S70>/high_pass'
                                        */
  real_T high_pass_C_o[2];             /* Computed Parameter: high_pass_C_o
                                        * Referenced by: '<S70>/high_pass'
                                        */
  real_T high_pass_D_c;                /* Computed Parameter: high_pass_D_c
                                        * Referenced by: '<S70>/high_pass'
                                        */
  real_T high_pass_InitialCondition_i; /* Expression: 0
                                        * Referenced by: '<S70>/high_pass'
                                        */
  real_T high_pass_A_h[3];             /* Computed Parameter: high_pass_A_h
                                        * Referenced by: '<S71>/high_pass'
                                        */
  real_T high_pass_B_l;                /* Computed Parameter: high_pass_B_l
                                        * Referenced by: '<S71>/high_pass'
                                        */
  real_T high_pass_C_g[2];             /* Computed Parameter: high_pass_C_g
                                        * Referenced by: '<S71>/high_pass'
                                        */
  real_T high_pass_D_j;                /* Computed Parameter: high_pass_D_j
                                        * Referenced by: '<S71>/high_pass'
                                        */
  real_T high_pass_InitialCondition_f3;/* Expression: 0
                                        * Referenced by: '<S71>/high_pass'
                                        */
  real_T high_pass_A_p[3];             /* Computed Parameter: high_pass_A_p
                                        * Referenced by: '<S72>/high_pass'
                                        */
  real_T high_pass_B_h;                /* Computed Parameter: high_pass_B_h
                                        * Referenced by: '<S72>/high_pass'
                                        */
  real_T high_pass_C_f[2];             /* Computed Parameter: high_pass_C_f
                                        * Referenced by: '<S72>/high_pass'
                                        */
  real_T high_pass_D_a;                /* Computed Parameter: high_pass_D_a
                                        * Referenced by: '<S72>/high_pass'
                                        */
  real_T high_pass_InitialCondition_b; /* Expression: 0
                                        * Referenced by: '<S72>/high_pass'
                                        */
  real_T high_pass_A_m[3];             /* Computed Parameter: high_pass_A_m
                                        * Referenced by: '<S73>/high_pass'
                                        */
  real_T high_pass_B_k;                /* Computed Parameter: high_pass_B_k
                                        * Referenced by: '<S73>/high_pass'
                                        */
  real_T high_pass_C_o5[2];            /* Computed Parameter: high_pass_C_o5
                                        * Referenced by: '<S73>/high_pass'
                                        */
  real_T high_pass_D_l;                /* Computed Parameter: high_pass_D_l
                                        * Referenced by: '<S73>/high_pass'
                                        */
  real_T high_pass_InitialCondition_if;/* Expression: 0
                                        * Referenced by: '<S73>/high_pass'
                                        */
  real_T high_pass_A_a[3];             /* Computed Parameter: high_pass_A_a
                                        * Referenced by: '<S74>/high_pass'
                                        */
  real_T high_pass_B_la;               /* Computed Parameter: high_pass_B_la
                                        * Referenced by: '<S74>/high_pass'
                                        */
  real_T high_pass_C_o3[2];            /* Computed Parameter: high_pass_C_o3
                                        * Referenced by: '<S74>/high_pass'
                                        */
  real_T high_pass_D_b;                /* Computed Parameter: high_pass_D_b
                                        * Referenced by: '<S74>/high_pass'
                                        */
  real_T high_pass_InitialCondition_o; /* Expression: 0
                                        * Referenced by: '<S74>/high_pass'
                                        */
  real_T high_pass_A_g[3];             /* Computed Parameter: high_pass_A_g
                                        * Referenced by: '<S75>/high_pass'
                                        */
  real_T high_pass_B_b;                /* Computed Parameter: high_pass_B_b
                                        * Referenced by: '<S75>/high_pass'
                                        */
  real_T high_pass_C_gb[2];            /* Computed Parameter: high_pass_C_gb
                                        * Referenced by: '<S75>/high_pass'
                                        */
  real_T high_pass_D_e;                /* Computed Parameter: high_pass_D_e
                                        * Referenced by: '<S75>/high_pass'
                                        */
  real_T high_pass_InitialCondition_m; /* Expression: 0
                                        * Referenced by: '<S75>/high_pass'
                                        */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S6>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 1
                                        * Referenced by: '<S6>/Constant1'
                                        */
  real_T Gain_Gain_a;                  /* Expression: 4/32767
                                        * Referenced by: '<S97>/Gain'
                                        */
  real_T Gain_Gain_h;                  /* Expression: 4/32767
                                        * Referenced by: '<S98>/Gain'
                                        */
  real_T Gain_Gain_j;                  /* Expression: 4/32767
                                        * Referenced by: '<S99>/Gain'
                                        */
  real_T SineWave_Amp;                 /* Expression: 100
                                        * Referenced by: '<S92>/Sine Wave'
                                        */
  real_T SineWave_Bias;                /* Expression: 0
                                        * Referenced by: '<S92>/Sine Wave'
                                        */
  real_T SineWave_Freq;                /* Expression: 1
                                        * Referenced by: '<S92>/Sine Wave'
                                        */
  real_T SineWave_Phase;               /* Expression: 0
                                        * Referenced by: '<S92>/Sine Wave'
                                        */
  real_T DataStoreMemory_InitialValue[4400];/* Expression: zeros(4,1100)
                                             * Referenced by: '<Root>/Data Store Memory'
                                             */
  real_T DataStoreMemory1_InitialValue[10];/* Expression: zeros(1,10)
                                            * Referenced by: '<Root>/Data Store Memory1'
                                            */
  real_T DataStoreMemory2_InitialValue[10];/* Expression: zeros(1,10)
                                            * Referenced by: '<Root>/Data Store Memory2'
                                            */
  real_T DataStoreMemory3_InitialValue[4400];/* Expression: zeros(4,1100)
                                              * Referenced by: '<Root>/Data Store Memory3'
                                              */
  boolean_T VCC1_Value;                /* Computed Parameter: VCC1_Value
                                        * Referenced by: '<S29>/VCC1'
                                        */
  boolean_T VCC2_Value;                /* Computed Parameter: VCC2_Value
                                        * Referenced by: '<S29>/VCC2'
                                        */
  boolean_T VCC2_Value_c;              /* Computed Parameter: VCC2_Value_c
                                        * Referenced by: '<S33>/VCC2'
                                        */
  boolean_T VCC3_Value;                /* Computed Parameter: VCC3_Value
                                        * Referenced by: '<S33>/VCC3'
                                        */
  boolean_T Constant_Value_e;          /* Computed Parameter: Constant_Value_e
                                        * Referenced by: '<S31>/Constant'
                                        */
  boolean_T Constant1_Value_k;         /* Computed Parameter: Constant1_Value_k
                                        * Referenced by: '<S31>/Constant1'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Bilateral_Ankle_Exo_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;
  X_Bilateral_Ankle_Exo_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeF[1][32];
  ODE1_IntgData intgData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    struct {
      uint8_T TID[3];
    } TaskCounters;

    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[4];
  } Timing;
};

/* Block parameters (auto storage) */
extern P_Bilateral_Ankle_Exo_T Bilateral_Ankle_Exo_P;

/* Block signals (auto storage) */
extern B_Bilateral_Ankle_Exo_T Bilateral_Ankle_Exo_B;

/* Continuous states (auto storage) */
extern X_Bilateral_Ankle_Exo_T Bilateral_Ankle_Exo_X;

/* Block states (auto storage) */
extern DW_Bilateral_Ankle_Exo_T Bilateral_Ankle_Exo_DW;

/* Model entry point functions */
extern void Bilateral_Ankle_Exo_initialize(void);
extern void Bilateral_Ankle_Exo_output(void);
extern void Bilateral_Ankle_Exo_update(void);
extern void Bilateral_Ankle_Exo_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Bilateral_Ankle_Exo_T *const Bilateral_Ankle_Exo_M;

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
 * '<Root>' : 'Bilateral_Ankle_Exo'
 * '<S1>'   : 'Bilateral_Ankle_Exo/AutoTunning'
 * '<S2>'   : 'Bilateral_Ankle_Exo/Control Module'
 * '<S3>'   : 'Bilateral_Ankle_Exo/Data Capture1'
 * '<S4>'   : 'Bilateral_Ankle_Exo/Parameter Module'
 * '<S5>'   : 'Bilateral_Ankle_Exo/RTI Data'
 * '<S6>'   : 'Bilateral_Ankle_Exo/Sensor Data'
 * '<S7>'   : 'Bilateral_Ankle_Exo/State_Module_l'
 * '<S8>'   : 'Bilateral_Ankle_Exo/State_Module_r'
 * '<S9>'   : 'Bilateral_Ankle_Exo/Timer Interrupt'
 * '<S10>'  : 'Bilateral_Ankle_Exo/Control Module/Controller_L'
 * '<S11>'  : 'Bilateral_Ankle_Exo/Control Module/Controller_R'
 * '<S12>'  : 'Bilateral_Ankle_Exo/Control Module/LRN_L'
 * '<S13>'  : 'Bilateral_Ankle_Exo/Control Module/LRN_R'
 * '<S14>'  : 'Bilateral_Ankle_Exo/Control Module/Motor_L'
 * '<S15>'  : 'Bilateral_Ankle_Exo/Control Module/Motor_R'
 * '<S16>'  : 'Bilateral_Ankle_Exo/Control Module/Torque Track L'
 * '<S17>'  : 'Bilateral_Ankle_Exo/Control Module/Torque Track R'
 * '<S18>'  : 'Bilateral_Ankle_Exo/Control Module/Motor_L/DAC_CLASS1_BL1'
 * '<S19>'  : 'Bilateral_Ankle_Exo/Control Module/Motor_L/MATLAB Function'
 * '<S20>'  : 'Bilateral_Ankle_Exo/Control Module/Motor_R/DAC_CLASS1_BL1'
 * '<S21>'  : 'Bilateral_Ankle_Exo/Control Module/Motor_R/MATLAB Function'
 * '<S22>'  : 'Bilateral_Ankle_Exo/Parameter Module/Control Parameter'
 * '<S23>'  : 'Bilateral_Ankle_Exo/Parameter Module/Torque Parameter'
 * '<S24>'  : 'Bilateral_Ankle_Exo/Parameter Module/Control Parameter/Mux1'
 * '<S25>'  : 'Bilateral_Ankle_Exo/Parameter Module/Torque Parameter/Mux1'
 * '<S26>'  : 'Bilateral_Ankle_Exo/RTI Data/RTI Data Store'
 * '<S27>'  : 'Bilateral_Ankle_Exo/RTI Data/RTI Data Store/RTI Data Store'
 * '<S28>'  : 'Bilateral_Ankle_Exo/RTI Data/RTI Data Store/RTI Data Store/RTI Data Store'
 * '<S29>'  : 'Bilateral_Ankle_Exo/Sensor Data/Ankle Encoder'
 * '<S30>'  : 'Bilateral_Ankle_Exo/Sensor Data/EMG module'
 * '<S31>'  : 'Bilateral_Ankle_Exo/Sensor Data/FootSwitch module'
 * '<S32>'  : 'Bilateral_Ankle_Exo/Sensor Data/IMU module'
 * '<S33>'  : 'Bilateral_Ankle_Exo/Sensor Data/Motor Encoder'
 * '<S34>'  : 'Bilateral_Ankle_Exo/Sensor Data/Torque module'
 * '<S35>'  : 'Bilateral_Ankle_Exo/Sensor Data/Ankle Encoder/Calibration_L'
 * '<S36>'  : 'Bilateral_Ankle_Exo/Sensor Data/Ankle Encoder/Calibration_R'
 * '<S37>'  : 'Bilateral_Ankle_Exo/Sensor Data/Ankle Encoder/EMC_ENCODER_BL1'
 * '<S38>'  : 'Bilateral_Ankle_Exo/Sensor Data/Ankle Encoder/EMC_ENCODER_BL2'
 * '<S39>'  : 'Bilateral_Ankle_Exo/Sensor Data/Ankle Encoder/Encoder Power Setup1'
 * '<S40>'  : 'Bilateral_Ankle_Exo/Sensor Data/Ankle Encoder/Encoder Power Setup2'
 * '<S41>'  : 'Bilateral_Ankle_Exo/Sensor Data/Ankle Encoder/Mux'
 * '<S42>'  : 'Bilateral_Ankle_Exo/Sensor Data/Ankle Encoder/Mux1'
 * '<S43>'  : 'Bilateral_Ankle_Exo/Sensor Data/EMG module/ADC_CLASS1_BL1'
 * '<S44>'  : 'Bilateral_Ankle_Exo/Sensor Data/EMG module/ADC_CLASS1_BL10'
 * '<S45>'  : 'Bilateral_Ankle_Exo/Sensor Data/EMG module/ADC_CLASS1_BL11'
 * '<S46>'  : 'Bilateral_Ankle_Exo/Sensor Data/EMG module/ADC_CLASS1_BL12'
 * '<S47>'  : 'Bilateral_Ankle_Exo/Sensor Data/EMG module/ADC_CLASS1_BL2'
 * '<S48>'  : 'Bilateral_Ankle_Exo/Sensor Data/EMG module/ADC_CLASS1_BL3'
 * '<S49>'  : 'Bilateral_Ankle_Exo/Sensor Data/EMG module/ADC_CLASS1_BL4'
 * '<S50>'  : 'Bilateral_Ankle_Exo/Sensor Data/EMG module/ADC_CLASS1_BL9'
 * '<S51>'  : 'Bilateral_Ankle_Exo/Sensor Data/EMG module/EMG3'
 * '<S52>'  : 'Bilateral_Ankle_Exo/Sensor Data/EMG module/EMG4'
 * '<S53>'  : 'Bilateral_Ankle_Exo/Sensor Data/EMG module/EMG_o1'
 * '<S54>'  : 'Bilateral_Ankle_Exo/Sensor Data/EMG module/EMG_o2'
 * '<S55>'  : 'Bilateral_Ankle_Exo/Sensor Data/EMG module/EMG_o5'
 * '<S56>'  : 'Bilateral_Ankle_Exo/Sensor Data/EMG module/EMG_o6'
 * '<S57>'  : 'Bilateral_Ankle_Exo/Sensor Data/EMG module/EMG_o7'
 * '<S58>'  : 'Bilateral_Ankle_Exo/Sensor Data/EMG module/EMG_o8'
 * '<S59>'  : 'Bilateral_Ankle_Exo/Sensor Data/EMG module/EMG_p1'
 * '<S60>'  : 'Bilateral_Ankle_Exo/Sensor Data/EMG module/EMG_p2'
 * '<S61>'  : 'Bilateral_Ankle_Exo/Sensor Data/EMG module/EMG_p3'
 * '<S62>'  : 'Bilateral_Ankle_Exo/Sensor Data/EMG module/EMG_p4'
 * '<S63>'  : 'Bilateral_Ankle_Exo/Sensor Data/EMG module/EMG_p5'
 * '<S64>'  : 'Bilateral_Ankle_Exo/Sensor Data/EMG module/EMG_p6'
 * '<S65>'  : 'Bilateral_Ankle_Exo/Sensor Data/EMG module/EMG_p7'
 * '<S66>'  : 'Bilateral_Ankle_Exo/Sensor Data/EMG module/EMG_p8'
 * '<S67>'  : 'Bilateral_Ankle_Exo/Sensor Data/EMG module/Mux1'
 * '<S68>'  : 'Bilateral_Ankle_Exo/Sensor Data/EMG module/Preprocessing1'
 * '<S69>'  : 'Bilateral_Ankle_Exo/Sensor Data/EMG module/Preprocessing2'
 * '<S70>'  : 'Bilateral_Ankle_Exo/Sensor Data/EMG module/Preprocessing3'
 * '<S71>'  : 'Bilateral_Ankle_Exo/Sensor Data/EMG module/Preprocessing4'
 * '<S72>'  : 'Bilateral_Ankle_Exo/Sensor Data/EMG module/Preprocessing5'
 * '<S73>'  : 'Bilateral_Ankle_Exo/Sensor Data/EMG module/Preprocessing6'
 * '<S74>'  : 'Bilateral_Ankle_Exo/Sensor Data/EMG module/Preprocessing7'
 * '<S75>'  : 'Bilateral_Ankle_Exo/Sensor Data/EMG module/Preprocessing8'
 * '<S76>'  : 'Bilateral_Ankle_Exo/Sensor Data/EMG module/Preprocessing1/MVC'
 * '<S77>'  : 'Bilateral_Ankle_Exo/Sensor Data/EMG module/Preprocessing2/MVC'
 * '<S78>'  : 'Bilateral_Ankle_Exo/Sensor Data/EMG module/Preprocessing3/MVC'
 * '<S79>'  : 'Bilateral_Ankle_Exo/Sensor Data/EMG module/Preprocessing4/MVC'
 * '<S80>'  : 'Bilateral_Ankle_Exo/Sensor Data/EMG module/Preprocessing5/MVC'
 * '<S81>'  : 'Bilateral_Ankle_Exo/Sensor Data/EMG module/Preprocessing6/MVC'
 * '<S82>'  : 'Bilateral_Ankle_Exo/Sensor Data/EMG module/Preprocessing7/MVC'
 * '<S83>'  : 'Bilateral_Ankle_Exo/Sensor Data/EMG module/Preprocessing8/MVC'
 * '<S84>'  : 'Bilateral_Ankle_Exo/Sensor Data/FootSwitch module/DIO_CLASS1_BIT_IN_BL1'
 * '<S85>'  : 'Bilateral_Ankle_Exo/Sensor Data/FootSwitch module/DIO_CLASS1_BIT_IN_BL2'
 * '<S86>'  : 'Bilateral_Ankle_Exo/Sensor Data/FootSwitch module/DIO_CLASS1_BIT_OUT_BL1'
 * '<S87>'  : 'Bilateral_Ankle_Exo/Sensor Data/FootSwitch module/DIO_CLASS1_BIT_OUT_BL2'
 * '<S88>'  : 'Bilateral_Ankle_Exo/Sensor Data/FootSwitch module/Filter_L'
 * '<S89>'  : 'Bilateral_Ankle_Exo/Sensor Data/FootSwitch module/Filter_R'
 * '<S90>'  : 'Bilateral_Ankle_Exo/Sensor Data/IMU module/CAN_TYPE1_SETUP_M1_C1'
 * '<S91>'  : 'Bilateral_Ankle_Exo/Sensor Data/IMU module/CAN_TYPE1_SETUP_M1_C2'
 * '<S92>'  : 'Bilateral_Ankle_Exo/Sensor Data/IMU module/CAN_Test'
 * '<S93>'  : 'Bilateral_Ankle_Exo/Sensor Data/IMU module/IMU'
 * '<S94>'  : 'Bilateral_Ankle_Exo/Sensor Data/IMU module/CAN_Test/CAN_TYPE1_RX_M1_C1'
 * '<S95>'  : 'Bilateral_Ankle_Exo/Sensor Data/IMU module/CAN_Test/CAN_TYPE1_TX_M1_C2'
 * '<S96>'  : 'Bilateral_Ankle_Exo/Sensor Data/IMU module/IMU/CAN_RX_Accel'
 * '<S97>'  : 'Bilateral_Ankle_Exo/Sensor Data/IMU module/IMU/Subsystem6'
 * '<S98>'  : 'Bilateral_Ankle_Exo/Sensor Data/IMU module/IMU/Subsystem7'
 * '<S99>'  : 'Bilateral_Ankle_Exo/Sensor Data/IMU module/IMU/Subsystem8'
 * '<S100>' : 'Bilateral_Ankle_Exo/Sensor Data/Motor Encoder/2-Order TD'
 * '<S101>' : 'Bilateral_Ankle_Exo/Sensor Data/Motor Encoder/2-Order TD1'
 * '<S102>' : 'Bilateral_Ankle_Exo/Sensor Data/Motor Encoder/Calibration_L'
 * '<S103>' : 'Bilateral_Ankle_Exo/Sensor Data/Motor Encoder/Calibration_R'
 * '<S104>' : 'Bilateral_Ankle_Exo/Sensor Data/Motor Encoder/EMC_ENCODER_BL2'
 * '<S105>' : 'Bilateral_Ankle_Exo/Sensor Data/Motor Encoder/EMC_ENCODER_BL3'
 * '<S106>' : 'Bilateral_Ankle_Exo/Sensor Data/Motor Encoder/Encoder Power Setup2'
 * '<S107>' : 'Bilateral_Ankle_Exo/Sensor Data/Motor Encoder/Encoder Power Setup3'
 * '<S108>' : 'Bilateral_Ankle_Exo/Sensor Data/Motor Encoder/Mux1'
 * '<S109>' : 'Bilateral_Ankle_Exo/Sensor Data/Motor Encoder/Mux3'
 * '<S110>' : 'Bilateral_Ankle_Exo/Sensor Data/Torque module/2-Order TD'
 * '<S111>' : 'Bilateral_Ankle_Exo/Sensor Data/Torque module/2-Order TD1'
 * '<S112>' : 'Bilateral_Ankle_Exo/Sensor Data/Torque module/ADC_CLASS1_BL1'
 * '<S113>' : 'Bilateral_Ankle_Exo/Sensor Data/Torque module/ADC_CLASS1_BL6'
 * '<S114>' : 'Bilateral_Ankle_Exo/Sensor Data/Torque module/Calibration_L'
 * '<S115>' : 'Bilateral_Ankle_Exo/Sensor Data/Torque module/Calibration_R'
 * '<S116>' : 'Bilateral_Ankle_Exo/Sensor Data/Torque module/DS1202_SENSOR_SUPPLY'
 * '<S117>' : 'Bilateral_Ankle_Exo/Sensor Data/Torque module/MATLAB Function'
 * '<S118>' : 'Bilateral_Ankle_Exo/Sensor Data/Torque module/Mux_L'
 * '<S119>' : 'Bilateral_Ankle_Exo/Sensor Data/Torque module/Mux_R'
 * '<S120>' : 'Bilateral_Ankle_Exo/State_Module_l/Mux1'
 * '<S121>' : 'Bilateral_Ankle_Exo/State_Module_l/State Machine'
 * '<S122>' : 'Bilateral_Ankle_Exo/State_Module_r/Mux1'
 * '<S123>' : 'Bilateral_Ankle_Exo/State_Module_r/State Machine'
 */
#endif                                 /* RTW_HEADER_Bilateral_Ankle_Exo_h_ */
