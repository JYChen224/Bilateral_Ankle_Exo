/*
 * Bilateral_Ankle_Exo.h
 *
 * Code generation for model "Bilateral_Ankle_Exo".
 *
 * Model version              : 1.1398
 * Simulink Coder version : 8.13 (R2017b) 24-Jul-2017
 * C source code generated on : Thu Jun 18 11:37:25 2020
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

/* Block signals for system '<S28>/Mux' */
typedef struct {
  real_T x[2];                         /* '<S28>/Mux' */
} B_Mux_Bilateral_Ankle_Exo_T;

/* Block signals for system '<S30>/Filter_L' */
typedef struct {
  real_T state;                        /* '<S30>/Filter_L' */
} B_Filter_L_Bilateral_Ankle_Ex_T;

/* Block states (auto storage) for system '<S30>/Filter_L' */
typedef struct {
  real_T foot_state;                   /* '<S30>/Filter_L' */
  real_T filter_time;                  /* '<S30>/Filter_L' */
} DW_Filter_L_Bilateral_Ankle_E_T;

/* Block signals for system '<S32>/Mux1' */
typedef struct {
  real_T x[3];                         /* '<S32>/Mux1' */
} B_Mux1_Bilateral_Ankle_Exo_T;

/* Block signals for system '<S6>/Mux1' */
typedef struct {
  real_T x[4];                         /* '<S6>/Mux1' */
} B_Mux1_Bilateral_Ankle_Exo_c_T;

/* Block signals for system '<S13>/MATLAB Function' */
typedef struct {
  real_T vel;                          /* '<S13>/MATLAB Function' */
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
  real_T SFunction1;                   /* '<S89>/S-Function1' */
  real_T Gain;                         /* '<S33>/Gain' */
  real_T u4low2;                       /* '<S33>/0.4low2' */
  real_T x2k1;                         /* '<S86>/Unit Delay1' */
  real_T x1k1;                         /* '<S86>/Unit Delay' */
  real_T Gain1;                        /* '<S86>/Gain1' */
  real_T Gain2;                        /* '<S86>/Gain2' */
  real_T UnitDelay2;                   /* '<S86>/Unit Delay2' */
  real_T Gain4;                        /* '<S86>/Gain4' */
  real_T Add2;                         /* '<S86>/Add2' */
  real_T Gain3;                        /* '<S86>/Gain3' */
  real_T x2k;                          /* '<S86>/Add1' */
  real_T RT4[2];                       /* '<Root>/RT4' */
  real_T SFunction1_o1;                /* '<S36>/S-Function1' */
  real_T SFunction1_o2;                /* '<S36>/S-Function1' */
  real_T Gain_g;                       /* '<S28>/Gain' */
  real_T Gain1_o;                      /* '<S28>/Gain1' */
  real_T RT5[2];                       /* '<Root>/RT5' */
  real_T SFunction1_o1_j;              /* '<S80>/S-Function1' */
  real_T SFunction1_o2_h;              /* '<S80>/S-Function1' */
  real_T Gain1_k;                      /* '<S32>/Gain1' */
  real_T Gain4_m;                      /* '<S32>/Gain4' */
  real_T x2k1_h;                       /* '<S77>/Unit Delay1' */
  real_T x1k1_g;                       /* '<S77>/Unit Delay' */
  real_T Gain1_m;                      /* '<S77>/Gain1' */
  real_T Gain2_h;                      /* '<S77>/Gain2' */
  real_T UnitDelay2_e;                 /* '<S77>/Unit Delay2' */
  real_T Gain4_p;                      /* '<S77>/Gain4' */
  real_T Add2_f;                       /* '<S77>/Add2' */
  real_T Gain3_i;                      /* '<S77>/Gain3' */
  real_T x2k_k;                        /* '<S77>/Add1' */
  real_T RT6[3];                       /* '<Root>/RT6' */
  real_T RT1[4];                       /* '<Root>/RT1' */
  real_T RT2[6];                       /* '<Root>/RT2' */
  real_T RT3[4];                       /* '<Root>/RT3' */
  real_T RT7[4];                       /* '<Root>/RT7' */
  real_T SFunction1_o;                 /* '<S88>/S-Function1' */
  real_T Gain1_l;                      /* '<S33>/Gain1' */
  real_T u4low1;                       /* '<S33>/0.4low1' */
  real_T x2k1_m;                       /* '<S87>/Unit Delay1' */
  real_T x1k1_f;                       /* '<S87>/Unit Delay' */
  real_T Gain1_a;                      /* '<S87>/Gain1' */
  real_T Gain2_j;                      /* '<S87>/Gain2' */
  real_T UnitDelay2_b;                 /* '<S87>/Unit Delay2' */
  real_T Gain4_g;                      /* '<S87>/Gain4' */
  real_T Add2_c;                       /* '<S87>/Add2' */
  real_T Gain3_f;                      /* '<S87>/Gain3' */
  real_T x2k_l;                        /* '<S87>/Add1' */
  real_T RT8[2];                       /* '<Root>/RT8' */
  real_T SFunction1_o1_jc;             /* '<S37>/S-Function1' */
  real_T SFunction1_o2_o;              /* '<S37>/S-Function1' */
  real_T Gain2_n;                      /* '<S28>/Gain2' */
  real_T Gain3_o;                      /* '<S28>/Gain3' */
  real_T RT9[2];                       /* '<Root>/RT9' */
  real_T SFunction1_o1_jr;             /* '<S81>/S-Function1' */
  real_T SFunction1_o2_j;              /* '<S81>/S-Function1' */
  real_T Gain2_c;                      /* '<S32>/Gain2' */
  real_T Gain3_h;                      /* '<S32>/Gain3' */
  real_T x2k1_d;                       /* '<S76>/Unit Delay1' */
  real_T x1k1_e;                       /* '<S76>/Unit Delay' */
  real_T Gain1_p;                      /* '<S76>/Gain1' */
  real_T Gain2_na;                     /* '<S76>/Gain2' */
  real_T UnitDelay2_i;                 /* '<S76>/Unit Delay2' */
  real_T Gain4_o;                      /* '<S76>/Gain4' */
  real_T Add2_fk;                      /* '<S76>/Add2' */
  real_T Gain3_hf;                     /* '<S76>/Gain3' */
  real_T x2k_a;                        /* '<S76>/Add1' */
  real_T RT10[3];                      /* '<Root>/RT10' */
  real_T Gain_h;                       /* '<S86>/Gain' */
  real_T x1k;                          /* '<S86>/Add' */
  real_T Gain_n;                       /* '<S87>/Gain' */
  real_T x1k_o;                        /* '<S87>/Add' */
  real_T Gain_hf;                      /* '<S77>/Gain' */
  real_T x1k_i;                        /* '<S77>/Add' */
  real_T Gain_o;                       /* '<S76>/Gain' */
  real_T x1k_k;                        /* '<S76>/Add' */
  real_T SFunction1_g;                 /* '<S42>/S-Function1' */
  real_T SFunction1_i;                 /* '<S43>/S-Function1' */
  real_T SFunction1_m;                 /* '<S44>/S-Function1' */
  real_T SFunction1_j;                 /* '<S45>/S-Function1' */
  real_T SFunction1_l;                 /* '<S46>/S-Function1' */
  real_T SFunction1_k;                 /* '<S47>/S-Function1' */
  real_T Gain_m;                       /* '<S29>/Gain' */
  real_T Gain1_aa;                     /* '<S29>/Gain1' */
  real_T Gain2_p;                      /* '<S29>/Gain2' */
  real_T Gain3_n;                      /* '<S29>/Gain3' */
  real_T Gain4_mo;                     /* '<S29>/Gain4' */
  real_T Gain5;                        /* '<S29>/Gain5' */
  real_T low_pass;                     /* '<S49>/low_pass' */
  real_T low_pass_e;                   /* '<S50>/low_pass' */
  real_T low_pass_m;                   /* '<S51>/low_pass' */
  real_T low_pass_d;                   /* '<S52>/low_pass' */
  real_T low_pass_p;                   /* '<S54>/low_pass' */
  real_T low_pass_i;                   /* '<S53>/low_pass' */
  real_T high_pass;                    /* '<S49>/high_pass' */
  real_T Abs;                          /* '<S49>/Abs' */
  real_T high_pass_h;                  /* '<S50>/high_pass' */
  real_T Abs_i;                        /* '<S50>/Abs' */
  real_T high_pass_hy;                 /* '<S51>/high_pass' */
  real_T Abs_l;                        /* '<S51>/Abs' */
  real_T high_pass_j;                  /* '<S52>/high_pass' */
  real_T Abs_b;                        /* '<S52>/Abs' */
  real_T high_pass_e;                  /* '<S53>/high_pass' */
  real_T Abs_lh;                       /* '<S53>/Abs' */
  real_T high_pass_b;                  /* '<S54>/high_pass' */
  real_T Abs_p;                        /* '<S54>/Abs' */
  real_T Constant;                     /* '<S5>/Constant' */
  real_T Constant1;                    /* '<S5>/Constant1' */
  real_T SFunction1_o1_c;              /* '<S72>/S-Function1' */
  real_T SFunction1_o2_l;              /* '<S72>/S-Function1' */
  real_T SFunction1_o3;                /* '<S72>/S-Function1' */
  real_T SFunction1_o4;                /* '<S72>/S-Function1' */
  real_T SFunction1_o5;                /* '<S72>/S-Function1' */
  real_T DataTypeConversion;           /* '<S73>/Data Type Conversion' */
  real_T Gain_gd;                      /* '<S73>/Gain' */
  real_T DataTypeConversion_j;         /* '<S74>/Data Type Conversion' */
  real_T Gain_b;                       /* '<S74>/Gain' */
  real_T DataTypeConversion_m;         /* '<S75>/Data Type Conversion' */
  real_T Gain_n4;                      /* '<S75>/Gain' */
  real_T SFunction1_o1_h;              /* '<S70>/S-Function1' */
  real_T SFunction1_o2_f;              /* '<S70>/S-Function1' */
  real_T SFunction1_o3_g;              /* '<S70>/S-Function1' */
  real_T SineWave;                     /* '<S68>/Sine Wave' */
  real_T SFunction1_o1_l;              /* '<S71>/S-Function1' */
  real_T SFunction1_o2_jb;             /* '<S71>/S-Function1' */
  real_T SFunction1_o3_p;              /* '<S71>/S-Function1' */
  real_T SFunction1_o4_k;              /* '<S71>/S-Function1' */
  real_T Gain2_ch;                     /* '<S13>/Gain2' */
  real_T Gain1_la;                     /* '<S13>/Gain1' */
  real_T Gain2_o;                      /* '<S14>/Gain2' */
  real_T Gain1_h;                      /* '<S14>/Gain1' */
  real_T torque_des_r;                 /* '<S1>/Torque Track R' */
  real_T torque_delta_des_r;           /* '<S1>/Torque Track R' */
  real_T torque_trace_r[1500];         /* '<S1>/Torque Track R' */
  real_T torque_delta_trace_r[1500];   /* '<S1>/Torque Track R' */
  real_T torque_error_r[2];            /* '<S1>/Torque Track R' */
  real_T torque_des_l;                 /* '<S1>/Torque Track L' */
  real_T torque_delta_des_l;           /* '<S1>/Torque Track L' */
  real_T torque_trace_l[1500];         /* '<S1>/Torque Track L' */
  real_T torque_delta_trace_l[1500];   /* '<S1>/Torque Track L' */
  real_T torque_error_l[2];            /* '<S1>/Torque Track L' */
  real_T lrn_cmd_r;                    /* '<S1>/LRN_R' */
  real_T lrn_mem_r[750];               /* '<S1>/LRN_R' */
  real_T lrn_cmd_l;                    /* '<S1>/LRN_L' */
  real_T lrn_mem_l[750];               /* '<S1>/LRN_L' */
  real_T motor_vel_cmd_r;              /* '<S1>/Controller_R' */
  real_T motor_vel_cmd_l;              /* '<S1>/Controller_L' */
  real_T mode_r;                       /* '<S7>/State Machine' */
  real_T state_r;                      /* '<S7>/State Machine' */
  real_T stride_time_r;                /* '<S7>/State Machine' */
  real_T stride_timer_r;               /* '<S7>/State Machine' */
  real_T mode_l;                       /* '<S6>/State Machine' */
  real_T state_l;                      /* '<S6>/State Machine' */
  real_T stride_time_l;                /* '<S6>/State Machine' */
  real_T stride_timer_l;               /* '<S6>/State Machine' */
  real_T torque_dot;                   /* '<S33>/MATLAB Function' */
  real_T torque;                       /* '<S33>/Calibration_R' */
  real_T torque_k;                     /* '<S33>/Calibration_L' */
  real_T angle;                        /* '<S32>/Calibration_R' */
  real_T angle_a;                      /* '<S32>/Calibration_L' */
  real_T y;                            /* '<S54>/MVC' */
  real_T y_e;                          /* '<S52>/MVC' */
  real_T y_j;                          /* '<S51>/MVC' */
  real_T y_g;                          /* '<S50>/MVC' */
  real_T y_b;                          /* '<S49>/MVC' */
  real_T x[6];                         /* '<S29>/Mux1' */
  real_T angle_k;                      /* '<S28>/Calibration_R' */
  real_T angle_b;                      /* '<S28>/Calibration_L' */
  real_T x_k[4];                       /* '<S22>/Mux1' */
  real_T x_h[6];                       /* '<S21>/Mux1' */
  boolean_T SFunction1_o3_b;           /* '<S36>/S-Function1' */
  boolean_T SFunction1_it;             /* '<S60>/S-Function1' */
  boolean_T SFunction1_jo;             /* '<S61>/S-Function1' */
  boolean_T SFunction1_o3_h;           /* '<S37>/S-Function1' */
  B_MATLABFunction_Bilateral_An_T sf_MATLABFunction_b;/* '<S14>/MATLAB Function' */
  B_MATLABFunction_Bilateral_An_T sf_MATLABFunction_h;/* '<S13>/MATLAB Function' */
  B_Mux1_Bilateral_Ankle_Exo_c_T sf_Mux1;/* '<S7>/Mux1' */
  B_Mux1_Bilateral_Ankle_Exo_c_T sf_Mux1_p;/* '<S6>/Mux1' */
  B_Mux_Bilateral_Ankle_Exo_T sf_Mux_R;/* '<S33>/Mux_R' */
  B_Mux_Bilateral_Ankle_Exo_T sf_Mux_L;/* '<S33>/Mux_L' */
  B_Mux1_Bilateral_Ankle_Exo_T sf_Mux3;/* '<S32>/Mux3' */
  B_Mux1_Bilateral_Ankle_Exo_T sf_Mux1_o;/* '<S32>/Mux1' */
  B_Filter_L_Bilateral_Ankle_Ex_T sf_Filter_R;/* '<S30>/Filter_R' */
  B_Filter_L_Bilateral_Ankle_Ex_T sf_Filter_L;/* '<S30>/Filter_L' */
  B_Mux_Bilateral_Ankle_Exo_T sf_Mux1_b;/* '<S28>/Mux1' */
  B_Mux_Bilateral_Ankle_Exo_T sf_Mux;  /* '<S28>/Mux' */
} B_Bilateral_Ankle_Exo_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T u4low2_states[3];             /* '<S33>/0.4low2' */
  real_T UnitDelay1_DSTATE;            /* '<S86>/Unit Delay1' */
  real_T UnitDelay_DSTATE;             /* '<S86>/Unit Delay' */
  real_T UnitDelay2_DSTATE;            /* '<S86>/Unit Delay2' */
  real_T UnitDelay1_DSTATE_n;          /* '<S77>/Unit Delay1' */
  real_T UnitDelay_DSTATE_o;           /* '<S77>/Unit Delay' */
  real_T UnitDelay2_DSTATE_i;          /* '<S77>/Unit Delay2' */
  real_T u4low1_states[3];             /* '<S33>/0.4low1' */
  real_T UnitDelay1_DSTATE_m;          /* '<S87>/Unit Delay1' */
  real_T UnitDelay_DSTATE_n;           /* '<S87>/Unit Delay' */
  real_T UnitDelay2_DSTATE_l;          /* '<S87>/Unit Delay2' */
  real_T UnitDelay1_DSTATE_f;          /* '<S76>/Unit Delay1' */
  real_T UnitDelay_DSTATE_a;           /* '<S76>/Unit Delay' */
  real_T UnitDelay2_DSTATE_e;          /* '<S76>/Unit Delay2' */
  real_T u4low2_tmp;                   /* '<S33>/0.4low2' */
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
  volatile real_T RT3_Buffer0[4];      /* '<Root>/RT3' */
  volatile real_T RT3_Buffer1[4];      /* '<Root>/RT3' */
  volatile real_T RT7_Buffer0[4];      /* '<Root>/RT7' */
  volatile real_T RT7_Buffer1[4];      /* '<Root>/RT7' */
  real_T u4low1_tmp;                   /* '<S33>/0.4low1' */
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
  real_T last_footstate;               /* '<S1>/Torque Track R' */
  real_T last_footstate_h;             /* '<S1>/Torque Track L' */
  real_T last_footstate_a;             /* '<S1>/LRN_R' */
  real_T torque_error_memory[1000];    /* '<S1>/LRN_R' */
  real_T lrn_cmd_memory[1000];         /* '<S1>/LRN_R' */
  real_T last_torque_parm[2];          /* '<S1>/LRN_R' */
  real_T last_footstate_g;             /* '<S1>/LRN_L' */
  real_T torque_error_memory_h[1000];  /* '<S1>/LRN_L' */
  real_T lrn_cmd_memory_n[1000];       /* '<S1>/LRN_L' */
  real_T last_torque_parm_m[2];        /* '<S1>/LRN_L' */
  real_T calib_state;                  /* '<S1>/Controller_R' */
  real_T smooth_filter;                /* '<S1>/Controller_R' */
  real_T calib_state_p;                /* '<S1>/Controller_L' */
  real_T smooth_filter_b;              /* '<S1>/Controller_L' */
  real_T reg_stride_time;              /* '<S7>/State Machine' */
  real_T reg_stride_time_count;        /* '<S7>/State Machine' */
  real_T reg_mode;                     /* '<S7>/State Machine' */
  real_T reg_state;                    /* '<S7>/State Machine' */
  real_T bt_run;                       /* '<S7>/State Machine' */
  real_T reg_last_switch;              /* '<S7>/State Machine' */
  real_T reg_stride_time_e;            /* '<S6>/State Machine' */
  real_T reg_stride_time_count_a;      /* '<S6>/State Machine' */
  real_T reg_mode_d;                   /* '<S6>/State Machine' */
  real_T reg_state_p;                  /* '<S6>/State Machine' */
  real_T bt_run_c;                     /* '<S6>/State Machine' */
  real_T reg_last_switch_p;            /* '<S6>/State Machine' */
  real_T data[15];                     /* '<S33>/MATLAB Function' */
  int_T SFunction1_IWORK[2];           /* '<S66>/S-Function1' */
  int_T SFunction1_IWORK_c[2];         /* '<S67>/S-Function1' */
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
  boolean_T last_footstate_not_empty;  /* '<S1>/LRN_R' */
  boolean_T last_footstate_not_empty_o;/* '<S1>/LRN_L' */
  DW_Filter_L_Bilateral_Ankle_E_T sf_Filter_R;/* '<S30>/Filter_R' */
  DW_Filter_L_Bilateral_Ankle_E_T sf_Filter_L;/* '<S30>/Filter_L' */
} DW_Bilateral_Ankle_Exo_T;

/* Continuous states (auto storage) */
typedef struct {
  real_T low_pass_CSTATE[2];           /* '<S49>/low_pass' */
  real_T low_pass_CSTATE_b[2];         /* '<S50>/low_pass' */
  real_T low_pass_CSTATE_m[2];         /* '<S51>/low_pass' */
  real_T low_pass_CSTATE_d[2];         /* '<S52>/low_pass' */
  real_T low_pass_CSTATE_j[2];         /* '<S54>/low_pass' */
  real_T low_pass_CSTATE_a[2];         /* '<S53>/low_pass' */
  real_T high_pass_CSTATE[2];          /* '<S49>/high_pass' */
  real_T high_pass_CSTATE_p[2];        /* '<S50>/high_pass' */
  real_T high_pass_CSTATE_f[2];        /* '<S51>/high_pass' */
  real_T high_pass_CSTATE_a[2];        /* '<S52>/high_pass' */
  real_T high_pass_CSTATE_o[2];        /* '<S53>/high_pass' */
  real_T high_pass_CSTATE_ff[2];       /* '<S54>/high_pass' */
} X_Bilateral_Ankle_Exo_T;

/* State derivatives (auto storage) */
typedef struct {
  real_T low_pass_CSTATE[2];           /* '<S49>/low_pass' */
  real_T low_pass_CSTATE_b[2];         /* '<S50>/low_pass' */
  real_T low_pass_CSTATE_m[2];         /* '<S51>/low_pass' */
  real_T low_pass_CSTATE_d[2];         /* '<S52>/low_pass' */
  real_T low_pass_CSTATE_j[2];         /* '<S54>/low_pass' */
  real_T low_pass_CSTATE_a[2];         /* '<S53>/low_pass' */
  real_T high_pass_CSTATE[2];          /* '<S49>/high_pass' */
  real_T high_pass_CSTATE_p[2];        /* '<S50>/high_pass' */
  real_T high_pass_CSTATE_f[2];        /* '<S51>/high_pass' */
  real_T high_pass_CSTATE_a[2];        /* '<S52>/high_pass' */
  real_T high_pass_CSTATE_o[2];        /* '<S53>/high_pass' */
  real_T high_pass_CSTATE_ff[2];       /* '<S54>/high_pass' */
} XDot_Bilateral_Ankle_Exo_T;

/* State disabled  */
typedef struct {
  boolean_T low_pass_CSTATE[2];        /* '<S49>/low_pass' */
  boolean_T low_pass_CSTATE_b[2];      /* '<S50>/low_pass' */
  boolean_T low_pass_CSTATE_m[2];      /* '<S51>/low_pass' */
  boolean_T low_pass_CSTATE_d[2];      /* '<S52>/low_pass' */
  boolean_T low_pass_CSTATE_j[2];      /* '<S54>/low_pass' */
  boolean_T low_pass_CSTATE_a[2];      /* '<S53>/low_pass' */
  boolean_T high_pass_CSTATE[2];       /* '<S49>/high_pass' */
  boolean_T high_pass_CSTATE_p[2];     /* '<S50>/high_pass' */
  boolean_T high_pass_CSTATE_f[2];     /* '<S51>/high_pass' */
  boolean_T high_pass_CSTATE_a[2];     /* '<S52>/high_pass' */
  boolean_T high_pass_CSTATE_o[2];     /* '<S53>/high_pass' */
  boolean_T high_pass_CSTATE_ff[2];    /* '<S54>/high_pass' */
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
  real_T Controller_L_FOLLOW_SLACK_ANGLE;/* Mask Parameter: Controller_L_FOLLOW_SLACK_ANGLE
                                          * Referenced by: '<S1>/Controller_L'
                                          */
  real_T Controller_R_FOLLOW_SLACK_ANGLE;/* Mask Parameter: Controller_R_FOLLOW_SLACK_ANGLE
                                          * Referenced by: '<S1>/Controller_R'
                                          */
  real_T EMGmodule_Kemg;               /* Mask Parameter: EMGmodule_Kemg
                                        * Referenced by:
                                        *   '<S29>/Gain'
                                        *   '<S29>/Gain1'
                                        *   '<S29>/Gain2'
                                        *   '<S29>/Gain3'
                                        *   '<S29>/Gain4'
                                        *   '<S29>/Gain5'
                                        */
  real_T MATLABFunction_MAX_MOTOR_ANGLE;/* Mask Parameter: MATLABFunction_MAX_MOTOR_ANGLE
                                         * Referenced by: '<S13>/MATLAB Function'
                                         */
  real_T MATLABFunction_MAX_MOTOR_ANGL_a;/* Mask Parameter: MATLABFunction_MAX_MOTOR_ANGL_a
                                          * Referenced by: '<S14>/MATLAB Function'
                                          */
  real_T MATLABFunction_MAX_SPEED;     /* Mask Parameter: MATLABFunction_MAX_SPEED
                                        * Referenced by: '<S13>/MATLAB Function'
                                        */
  real_T MATLABFunction_MAX_SPEED_a;   /* Mask Parameter: MATLABFunction_MAX_SPEED_a
                                        * Referenced by: '<S14>/MATLAB Function'
                                        */
  real_T MATLABFunction_MAX_TORQUE;    /* Mask Parameter: MATLABFunction_MAX_TORQUE
                                        * Referenced by: '<S13>/MATLAB Function'
                                        */
  real_T MATLABFunction_MAX_TORQUE_p;  /* Mask Parameter: MATLABFunction_MAX_TORQUE_p
                                        * Referenced by: '<S14>/MATLAB Function'
                                        */
  real_T MATLABFunction_MIN_MOTOR_ANGLE;/* Mask Parameter: MATLABFunction_MIN_MOTOR_ANGLE
                                         * Referenced by: '<S13>/MATLAB Function'
                                         */
  real_T MATLABFunction_MIN_MOTOR_ANGL_g;/* Mask Parameter: MATLABFunction_MIN_MOTOR_ANGL_g
                                          * Referenced by: '<S14>/MATLAB Function'
                                          */
  real_T Controller_L_SWING_MAX_ANGLE_L;/* Mask Parameter: Controller_L_SWING_MAX_ANGLE_L
                                         * Referenced by: '<S1>/Controller_L'
                                         */
  real_T Controller_R_SWING_MAX_ANGLE_R;/* Mask Parameter: Controller_R_SWING_MAX_ANGLE_R
                                         * Referenced by: '<S1>/Controller_R'
                                         */
  real_T uOrderTD_T1;                  /* Mask Parameter: uOrderTD_T1
                                        * Referenced by:
                                        *   '<S86>/Gain1'
                                        *   '<S86>/Gain2'
                                        *   '<S86>/Gain4'
                                        */
  real_T uOrderTD1_T1;                 /* Mask Parameter: uOrderTD1_T1
                                        * Referenced by:
                                        *   '<S77>/Gain1'
                                        *   '<S77>/Gain2'
                                        *   '<S77>/Gain4'
                                        */
  real_T uOrderTD1_T1_a;               /* Mask Parameter: uOrderTD1_T1_a
                                        * Referenced by:
                                        *   '<S87>/Gain1'
                                        *   '<S87>/Gain2'
                                        *   '<S87>/Gain4'
                                        */
  real_T uOrderTD_T1_p;                /* Mask Parameter: uOrderTD_T1_p
                                        * Referenced by:
                                        *   '<S76>/Gain1'
                                        *   '<S76>/Gain2'
                                        *   '<S76>/Gain4'
                                        */
  real_T uOrderTD_T2;                  /* Mask Parameter: uOrderTD_T2
                                        * Referenced by:
                                        *   '<S86>/Gain1'
                                        *   '<S86>/Gain2'
                                        *   '<S86>/Gain4'
                                        */
  real_T uOrderTD1_T2;                 /* Mask Parameter: uOrderTD1_T2
                                        * Referenced by:
                                        *   '<S77>/Gain1'
                                        *   '<S77>/Gain2'
                                        *   '<S77>/Gain4'
                                        */
  real_T uOrderTD1_T2_f;               /* Mask Parameter: uOrderTD1_T2_f
                                        * Referenced by:
                                        *   '<S87>/Gain1'
                                        *   '<S87>/Gain2'
                                        *   '<S87>/Gain4'
                                        */
  real_T uOrderTD_T2_k;                /* Mask Parameter: uOrderTD_T2_k
                                        * Referenced by:
                                        *   '<S76>/Gain1'
                                        *   '<S76>/Gain2'
                                        *   '<S76>/Gain4'
                                        */
  real_T uOrderTD_Ts;                  /* Mask Parameter: uOrderTD_Ts
                                        * Referenced by:
                                        *   '<S86>/Gain'
                                        *   '<S86>/Gain3'
                                        */
  real_T uOrderTD1_Ts;                 /* Mask Parameter: uOrderTD1_Ts
                                        * Referenced by:
                                        *   '<S77>/Gain'
                                        *   '<S77>/Gain3'
                                        */
  real_T uOrderTD1_Ts_a;               /* Mask Parameter: uOrderTD1_Ts_a
                                        * Referenced by:
                                        *   '<S87>/Gain'
                                        *   '<S87>/Gain3'
                                        */
  real_T uOrderTD_Ts_n;                /* Mask Parameter: uOrderTD_Ts_n
                                        * Referenced by:
                                        *   '<S76>/Gain'
                                        *   '<S76>/Gain3'
                                        */
  real_T LRN_L_error_filter_k_l;       /* Mask Parameter: LRN_L_error_filter_k_l
                                        * Referenced by: '<S1>/LRN_L'
                                        */
  real_T LRN_R_error_filter_k_r;       /* Mask Parameter: LRN_R_error_filter_k_r
                                        * Referenced by: '<S1>/LRN_R'
                                        */
  real_T MVC_l_L_GAS_MAX;              /* Mask Parameter: MVC_l_L_GAS_MAX
                                        * Referenced by: '<S54>/MVC'
                                        */
  real_T MVC_l_L_GAS_MIN;              /* Mask Parameter: MVC_l_L_GAS_MIN
                                        * Referenced by: '<S54>/MVC'
                                        */
  real_T MVC_l_M_GAS_MAX;              /* Mask Parameter: MVC_l_M_GAS_MAX
                                        * Referenced by: '<S52>/MVC'
                                        */
  real_T MVC_l_M_GAS_MIN;              /* Mask Parameter: MVC_l_M_GAS_MIN
                                        * Referenced by: '<S52>/MVC'
                                        */
  real_T Calibration_L_load_vol_gain;  /* Mask Parameter: Calibration_L_load_vol_gain
                                        * Referenced by: '<S33>/Calibration_L'
                                        */
  real_T Calibration_R_load_vol_gain;  /* Mask Parameter: Calibration_R_load_vol_gain
                                        * Referenced by: '<S33>/Calibration_R'
                                        */
  real_T Calibration_L_load_vol_offset;/* Mask Parameter: Calibration_L_load_vol_offset
                                        * Referenced by: '<S33>/Calibration_L'
                                        */
  real_T Calibration_R_load_vol_offset;/* Mask Parameter: Calibration_R_load_vol_offset
                                        * Referenced by: '<S33>/Calibration_R'
                                        */
  real_T LRN_L_lrn_shrink_l;           /* Mask Parameter: LRN_L_lrn_shrink_l
                                        * Referenced by: '<S1>/LRN_L'
                                        */
  real_T LRN_R_lrn_shrink_r;           /* Mask Parameter: LRN_R_lrn_shrink_r
                                        * Referenced by: '<S1>/LRN_R'
                                        */
  real_T MVC_r_L_GAS_MAX;              /* Mask Parameter: MVC_r_L_GAS_MAX
                                        * Referenced by: '<S51>/MVC'
                                        */
  real_T MVC_r_L_GAS_MIN;              /* Mask Parameter: MVC_r_L_GAS_MIN
                                        * Referenced by: '<S51>/MVC'
                                        */
  real_T MVC_r_M_GAS_MAX;              /* Mask Parameter: MVC_r_M_GAS_MAX
                                        * Referenced by: '<S50>/MVC'
                                        */
  real_T MVC_r_M_GAS_MIN;              /* Mask Parameter: MVC_r_M_GAS_MIN
                                        * Referenced by: '<S50>/MVC'
                                        */
  real_T MVC_r_SOL_MAX;                /* Mask Parameter: MVC_r_SOL_MAX
                                        * Referenced by: '<S49>/MVC'
                                        */
  real_T MVC_r_SOL_MIN;                /* Mask Parameter: MVC_r_SOL_MIN
                                        * Referenced by: '<S49>/MVC'
                                        */
  int32_T LRN_L_time_delay_l;          /* Mask Parameter: LRN_L_time_delay_l
                                        * Referenced by: '<S1>/LRN_L'
                                        */
  int32_T LRN_R_time_delay_r;          /* Mask Parameter: LRN_R_time_delay_r
                                        * Referenced by: '<S1>/LRN_R'
                                        */
  int8_T Controller_L_MODE_L;          /* Mask Parameter: Controller_L_MODE_L
                                        * Referenced by: '<S1>/Controller_L'
                                        */
  int8_T Controller_R_MODE_R;          /* Mask Parameter: Controller_R_MODE_R
                                        * Referenced by: '<S1>/Controller_R'
                                        */
  boolean_T StateMachine_BT_CALIB_L;   /* Mask Parameter: StateMachine_BT_CALIB_L
                                        * Referenced by: '<S6>/State Machine'
                                        */
  boolean_T StateMachine_BT_CALIB_R;   /* Mask Parameter: StateMachine_BT_CALIB_R
                                        * Referenced by: '<S7>/State Machine'
                                        */
  boolean_T StateMachine_BT_ERROR_L;   /* Mask Parameter: StateMachine_BT_ERROR_L
                                        * Referenced by: '<S6>/State Machine'
                                        */
  boolean_T StateMachine_BT_ERROR_R;   /* Mask Parameter: StateMachine_BT_ERROR_R
                                        * Referenced by: '<S7>/State Machine'
                                        */
  boolean_T StateMachine_BT_IDLE_L;    /* Mask Parameter: StateMachine_BT_IDLE_L
                                        * Referenced by: '<S6>/State Machine'
                                        */
  boolean_T StateMachine_BT_IDLE_R;    /* Mask Parameter: StateMachine_BT_IDLE_R
                                        * Referenced by: '<S7>/State Machine'
                                        */
  boolean_T LRN_L_BT_LRN_CLEAR_L;      /* Mask Parameter: LRN_L_BT_LRN_CLEAR_L
                                        * Referenced by: '<S1>/LRN_L'
                                        */
  boolean_T LRN_R_BT_LRN_CLEAR_R;      /* Mask Parameter: LRN_R_BT_LRN_CLEAR_R
                                        * Referenced by: '<S1>/LRN_R'
                                        */
  boolean_T LRN_L_BT_LRN_ON_L;         /* Mask Parameter: LRN_L_BT_LRN_ON_L
                                        * Referenced by: '<S1>/LRN_L'
                                        */
  boolean_T LRN_R_BT_LRN_ON_R;         /* Mask Parameter: LRN_R_BT_LRN_ON_R
                                        * Referenced by: '<S1>/LRN_R'
                                        */
  boolean_T Calibration_L_BT_RESET_ANKLE_L;/* Mask Parameter: Calibration_L_BT_RESET_ANKLE_L
                                            * Referenced by: '<S28>/Calibration_L'
                                            */
  boolean_T Calibration_R_BT_RESET_ANKLE_R;/* Mask Parameter: Calibration_R_BT_RESET_ANKLE_R
                                            * Referenced by: '<S28>/Calibration_R'
                                            */
  boolean_T Calibration_L_BT_RESET_MOTOR_L;/* Mask Parameter: Calibration_L_BT_RESET_MOTOR_L
                                            * Referenced by: '<S32>/Calibration_L'
                                            */
  boolean_T Calibration_R_BT_RESET_MOTOR_R;/* Mask Parameter: Calibration_R_BT_RESET_MOTOR_R
                                            * Referenced by: '<S32>/Calibration_R'
                                            */
  boolean_T Calibration_L_BT_RESET_TORQUE_L;/* Mask Parameter: Calibration_L_BT_RESET_TORQUE_L
                                             * Referenced by: '<S33>/Calibration_L'
                                             */
  boolean_T Calibration_R_BT_RESET_TORQUE_R;/* Mask Parameter: Calibration_R_BT_RESET_TORQUE_R
                                             * Referenced by: '<S33>/Calibration_R'
                                             */
  boolean_T StateMachine_BT_RUN_L;     /* Mask Parameter: StateMachine_BT_RUN_L
                                        * Referenced by: '<S6>/State Machine'
                                        */
  boolean_T StateMachine_BT_RUN_R;     /* Mask Parameter: StateMachine_BT_RUN_R
                                        * Referenced by: '<S7>/State Machine'
                                        */
  boolean_T StateMachine_BT_SLACK_L;   /* Mask Parameter: StateMachine_BT_SLACK_L
                                        * Referenced by: '<S6>/State Machine'
                                        */
  boolean_T StateMachine_BT_SLACK_R;   /* Mask Parameter: StateMachine_BT_SLACK_R
                                        * Referenced by: '<S7>/State Machine'
                                        */
  real_T torque_offset_Value;          /* Expression: 2
                                        * Referenced by: '<S1>/torque_offset'
                                        */
  real_T Gain2_Gain;                   /* Expression: 1/360
                                        * Referenced by: '<S13>/Gain2'
                                        */
  real_T Gain1_Gain;                   /* Expression: 1/100
                                        * Referenced by: '<S13>/Gain1'
                                        */
  real_T Gain2_Gain_g;                 /* Expression: 1/360
                                        * Referenced by: '<S14>/Gain2'
                                        */
  real_T Gain1_Gain_c;                 /* Expression: -1/100
                                        * Referenced by: '<S14>/Gain1'
                                        */
  real_T Gain_Gain;                    /* Expression: 10
                                        * Referenced by: '<S33>/Gain'
                                        */
  real_T u4low2_NumCoef[4];            /* Expression: [0.219606211225382   0.658818633676145   0.658818633676145   0.219606211225382]*1e-3
                                        * Referenced by: '<S33>/0.4low2'
                                        */
  real_T u4low2_DenCoef[4];            /* Expression: [1.000000000000000  -2.748835809214676   2.528231219142559  -0.777638560238080]
                                        * Referenced by: '<S33>/0.4low2'
                                        */
  real_T u4low2_InitialStates;         /* Expression: 0
                                        * Referenced by: '<S33>/0.4low2'
                                        */
  real_T UnitDelay1_InitialCondition;  /* Expression: 0
                                        * Referenced by: '<S86>/Unit Delay1'
                                        */
  real_T UnitDelay_InitialCondition;   /* Expression: 0
                                        * Referenced by: '<S86>/Unit Delay'
                                        */
  real_T UnitDelay2_InitialCondition;  /* Expression: 0
                                        * Referenced by: '<S86>/Unit Delay2'
                                        */
  real_T RT4_InitialCondition;         /* Expression: 0
                                        * Referenced by: '<Root>/RT4'
                                        */
  real_T Gain_Gain_o;                  /* Expression: -360/2000
                                        * Referenced by: '<S28>/Gain'
                                        */
  real_T Gain1_Gain_m;                 /* Expression: -360/2000
                                        * Referenced by: '<S28>/Gain1'
                                        */
  real_T RT5_InitialCondition;         /* Expression: 0
                                        * Referenced by: '<Root>/RT5'
                                        */
  real_T Gain1_Gain_cu;                /* Expression: 360.0/1250.0
                                        * Referenced by: '<S32>/Gain1'
                                        */
  real_T Gain4_Gain;                   /* Expression: 360.0/1250.0
                                        * Referenced by: '<S32>/Gain4'
                                        */
  real_T UnitDelay1_InitialCondition_e;/* Expression: 0
                                        * Referenced by: '<S77>/Unit Delay1'
                                        */
  real_T UnitDelay_InitialCondition_b; /* Expression: 0
                                        * Referenced by: '<S77>/Unit Delay'
                                        */
  real_T UnitDelay2_InitialCondition_m;/* Expression: 0
                                        * Referenced by: '<S77>/Unit Delay2'
                                        */
  real_T RT6_InitialCondition;         /* Expression: 0
                                        * Referenced by: '<Root>/RT6'
                                        */
  real_T RT1_InitialCondition;         /* Expression: 0
                                        * Referenced by: '<Root>/RT1'
                                        */
  real_T Kp_Value;                     /* Expression: 8
                                        * Referenced by: '<S21>/Kp'
                                        */
  real_T Kd_Value;                     /* Expression: 0
                                        * Referenced by: '<S21>/Kd'
                                        */
  real_T Kl_Value;                     /* Expression: 0.05
                                        * Referenced by: '<S21>/Kl'
                                        */
  real_T Ksp_Value;                    /* Expression: 3
                                        * Referenced by: '<S21>/Ksp'
                                        */
  real_T Ksd_Value;                    /* Expression: 0.2
                                        * Referenced by: '<S21>/Ksd'
                                        */
  real_T Ko_Value;                     /* Expression: 0
                                        * Referenced by: '<S21>/Ko'
                                        */
  real_T controlreset_Value;           /* Expression: 0
                                        * Referenced by: '<S21>/control reset'
                                        */
  real_T RT2_InitialCondition;         /* Expression: 0
                                        * Referenced by: '<Root>/RT2'
                                        */
  real_T peak_torque_Value;            /* Expression: 0
                                        * Referenced by: '<S22>/peak_torque'
                                        */
  real_T rise_time_Value;              /* Expression: 22.8
                                        * Referenced by: '<S22>/rise_time'
                                        */
  real_T peak_time_Value;              /* Expression: 48
                                        * Referenced by: '<S22>/peak_time'
                                        */
  real_T fall_time_Value;              /* Expression: 11.7
                                        * Referenced by: '<S22>/fall_time'
                                        */
  real_T RT3_InitialCondition;         /* Expression: 0
                                        * Referenced by: '<Root>/RT3'
                                        */
  real_T RT7_InitialCondition;         /* Expression: 0
                                        * Referenced by: '<Root>/RT7'
                                        */
  real_T Gain1_Gain_e;                 /* Expression: 10
                                        * Referenced by: '<S33>/Gain1'
                                        */
  real_T u4low1_NumCoef[4];            /* Expression: [0.219606211225382   0.658818633676145   0.658818633676145   0.219606211225382]*1e-3
                                        * Referenced by: '<S33>/0.4low1'
                                        */
  real_T u4low1_DenCoef[4];            /* Expression: [1.000000000000000  -2.748835809214676   2.528231219142559  -0.777638560238080]
                                        * Referenced by: '<S33>/0.4low1'
                                        */
  real_T u4low1_InitialStates;         /* Expression: 0
                                        * Referenced by: '<S33>/0.4low1'
                                        */
  real_T UnitDelay1_InitialCondition_i;/* Expression: 0
                                        * Referenced by: '<S87>/Unit Delay1'
                                        */
  real_T UnitDelay_InitialCondition_a; /* Expression: 0
                                        * Referenced by: '<S87>/Unit Delay'
                                        */
  real_T UnitDelay2_InitialCondition_e;/* Expression: 0
                                        * Referenced by: '<S87>/Unit Delay2'
                                        */
  real_T RT8_InitialCondition;         /* Expression: 0
                                        * Referenced by: '<Root>/RT8'
                                        */
  real_T Gain2_Gain_l;                 /* Expression: 360/2000
                                        * Referenced by: '<S28>/Gain2'
                                        */
  real_T Gain3_Gain;                   /* Expression: 360/2000
                                        * Referenced by: '<S28>/Gain3'
                                        */
  real_T RT9_InitialCondition;         /* Expression: 0
                                        * Referenced by: '<Root>/RT9'
                                        */
  real_T Gain2_Gain_h;                 /* Expression: -360.0/1250.0
                                        * Referenced by: '<S32>/Gain2'
                                        */
  real_T Gain3_Gain_e;                 /* Expression: -360.0/1250.0
                                        * Referenced by: '<S32>/Gain3'
                                        */
  real_T UnitDelay1_InitialCondition_b;/* Expression: 0
                                        * Referenced by: '<S76>/Unit Delay1'
                                        */
  real_T UnitDelay_InitialCondition_c; /* Expression: 0
                                        * Referenced by: '<S76>/Unit Delay'
                                        */
  real_T UnitDelay2_InitialCondition_c;/* Expression: 0
                                        * Referenced by: '<S76>/Unit Delay2'
                                        */
  real_T RT10_InitialCondition;        /* Expression: 0
                                        * Referenced by: '<Root>/RT10'
                                        */
  real_T low_pass_A[3];                /* Computed Parameter: low_pass_A
                                        * Referenced by: '<S49>/low_pass'
                                        */
  real_T low_pass_B;                   /* Computed Parameter: low_pass_B
                                        * Referenced by: '<S49>/low_pass'
                                        */
  real_T low_pass_C;                   /* Computed Parameter: low_pass_C
                                        * Referenced by: '<S49>/low_pass'
                                        */
  real_T low_pass_InitialCondition;    /* Expression: 0
                                        * Referenced by: '<S49>/low_pass'
                                        */
  real_T low_pass_A_k[3];              /* Computed Parameter: low_pass_A_k
                                        * Referenced by: '<S50>/low_pass'
                                        */
  real_T low_pass_B_j;                 /* Computed Parameter: low_pass_B_j
                                        * Referenced by: '<S50>/low_pass'
                                        */
  real_T low_pass_C_a;                 /* Computed Parameter: low_pass_C_a
                                        * Referenced by: '<S50>/low_pass'
                                        */
  real_T low_pass_InitialCondition_i;  /* Expression: 0
                                        * Referenced by: '<S50>/low_pass'
                                        */
  real_T low_pass_A_e[3];              /* Computed Parameter: low_pass_A_e
                                        * Referenced by: '<S51>/low_pass'
                                        */
  real_T low_pass_B_f;                 /* Computed Parameter: low_pass_B_f
                                        * Referenced by: '<S51>/low_pass'
                                        */
  real_T low_pass_C_g;                 /* Computed Parameter: low_pass_C_g
                                        * Referenced by: '<S51>/low_pass'
                                        */
  real_T low_pass_InitialCondition_n;  /* Expression: 0
                                        * Referenced by: '<S51>/low_pass'
                                        */
  real_T low_pass_A_l[3];              /* Computed Parameter: low_pass_A_l
                                        * Referenced by: '<S52>/low_pass'
                                        */
  real_T low_pass_B_n;                 /* Computed Parameter: low_pass_B_n
                                        * Referenced by: '<S52>/low_pass'
                                        */
  real_T low_pass_C_e;                 /* Computed Parameter: low_pass_C_e
                                        * Referenced by: '<S52>/low_pass'
                                        */
  real_T low_pass_InitialCondition_o;  /* Expression: 0
                                        * Referenced by: '<S52>/low_pass'
                                        */
  real_T low_pass_A_c[3];              /* Computed Parameter: low_pass_A_c
                                        * Referenced by: '<S54>/low_pass'
                                        */
  real_T low_pass_B_m;                 /* Computed Parameter: low_pass_B_m
                                        * Referenced by: '<S54>/low_pass'
                                        */
  real_T low_pass_C_o;                 /* Computed Parameter: low_pass_C_o
                                        * Referenced by: '<S54>/low_pass'
                                        */
  real_T low_pass_InitialCondition_ir; /* Expression: 0
                                        * Referenced by: '<S54>/low_pass'
                                        */
  real_T low_pass_A_ec[3];             /* Computed Parameter: low_pass_A_ec
                                        * Referenced by: '<S53>/low_pass'
                                        */
  real_T low_pass_B_h;                 /* Computed Parameter: low_pass_B_h
                                        * Referenced by: '<S53>/low_pass'
                                        */
  real_T low_pass_C_p;                 /* Computed Parameter: low_pass_C_p
                                        * Referenced by: '<S53>/low_pass'
                                        */
  real_T low_pass_InitialCondition_h;  /* Expression: 0
                                        * Referenced by: '<S53>/low_pass'
                                        */
  real_T high_pass_A[3];               /* Computed Parameter: high_pass_A
                                        * Referenced by: '<S49>/high_pass'
                                        */
  real_T high_pass_B;                  /* Computed Parameter: high_pass_B
                                        * Referenced by: '<S49>/high_pass'
                                        */
  real_T high_pass_C[2];               /* Computed Parameter: high_pass_C
                                        * Referenced by: '<S49>/high_pass'
                                        */
  real_T high_pass_D;                  /* Computed Parameter: high_pass_D
                                        * Referenced by: '<S49>/high_pass'
                                        */
  real_T high_pass_InitialCondition;   /* Expression: 0
                                        * Referenced by: '<S49>/high_pass'
                                        */
  real_T high_pass_A_g[3];             /* Computed Parameter: high_pass_A_g
                                        * Referenced by: '<S50>/high_pass'
                                        */
  real_T high_pass_B_i;                /* Computed Parameter: high_pass_B_i
                                        * Referenced by: '<S50>/high_pass'
                                        */
  real_T high_pass_C_b[2];             /* Computed Parameter: high_pass_C_b
                                        * Referenced by: '<S50>/high_pass'
                                        */
  real_T high_pass_D_d;                /* Computed Parameter: high_pass_D_d
                                        * Referenced by: '<S50>/high_pass'
                                        */
  real_T high_pass_InitialCondition_a; /* Expression: 0
                                        * Referenced by: '<S50>/high_pass'
                                        */
  real_T high_pass_A_p[3];             /* Computed Parameter: high_pass_A_p
                                        * Referenced by: '<S51>/high_pass'
                                        */
  real_T high_pass_B_h;                /* Computed Parameter: high_pass_B_h
                                        * Referenced by: '<S51>/high_pass'
                                        */
  real_T high_pass_C_by[2];            /* Computed Parameter: high_pass_C_by
                                        * Referenced by: '<S51>/high_pass'
                                        */
  real_T high_pass_D_o;                /* Computed Parameter: high_pass_D_o
                                        * Referenced by: '<S51>/high_pass'
                                        */
  real_T high_pass_InitialCondition_d; /* Expression: 0
                                        * Referenced by: '<S51>/high_pass'
                                        */
  real_T high_pass_A_a[3];             /* Computed Parameter: high_pass_A_a
                                        * Referenced by: '<S52>/high_pass'
                                        */
  real_T high_pass_B_n;                /* Computed Parameter: high_pass_B_n
                                        * Referenced by: '<S52>/high_pass'
                                        */
  real_T high_pass_C_p[2];             /* Computed Parameter: high_pass_C_p
                                        * Referenced by: '<S52>/high_pass'
                                        */
  real_T high_pass_D_n;                /* Computed Parameter: high_pass_D_n
                                        * Referenced by: '<S52>/high_pass'
                                        */
  real_T high_pass_InitialCondition_m; /* Expression: 0
                                        * Referenced by: '<S52>/high_pass'
                                        */
  real_T high_pass_A_a0[3];            /* Computed Parameter: high_pass_A_a0
                                        * Referenced by: '<S53>/high_pass'
                                        */
  real_T high_pass_B_n3;               /* Computed Parameter: high_pass_B_n3
                                        * Referenced by: '<S53>/high_pass'
                                        */
  real_T high_pass_C_e[2];             /* Computed Parameter: high_pass_C_e
                                        * Referenced by: '<S53>/high_pass'
                                        */
  real_T high_pass_D_l;                /* Computed Parameter: high_pass_D_l
                                        * Referenced by: '<S53>/high_pass'
                                        */
  real_T high_pass_InitialCondition_h; /* Expression: 0
                                        * Referenced by: '<S53>/high_pass'
                                        */
  real_T high_pass_A_f[3];             /* Computed Parameter: high_pass_A_f
                                        * Referenced by: '<S54>/high_pass'
                                        */
  real_T high_pass_B_g;                /* Computed Parameter: high_pass_B_g
                                        * Referenced by: '<S54>/high_pass'
                                        */
  real_T high_pass_C_h[2];             /* Computed Parameter: high_pass_C_h
                                        * Referenced by: '<S54>/high_pass'
                                        */
  real_T high_pass_D_e;                /* Computed Parameter: high_pass_D_e
                                        * Referenced by: '<S54>/high_pass'
                                        */
  real_T high_pass_InitialCondition_e; /* Expression: 0
                                        * Referenced by: '<S54>/high_pass'
                                        */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S5>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 1
                                        * Referenced by: '<S5>/Constant1'
                                        */
  real_T Gain_Gain_a;                  /* Expression: 4/32767
                                        * Referenced by: '<S73>/Gain'
                                        */
  real_T Gain_Gain_h;                  /* Expression: 4/32767
                                        * Referenced by: '<S74>/Gain'
                                        */
  real_T Gain_Gain_j;                  /* Expression: 4/32767
                                        * Referenced by: '<S75>/Gain'
                                        */
  real_T SineWave_Amp;                 /* Expression: 100
                                        * Referenced by: '<S68>/Sine Wave'
                                        */
  real_T SineWave_Bias;                /* Expression: 0
                                        * Referenced by: '<S68>/Sine Wave'
                                        */
  real_T SineWave_Freq;                /* Expression: 1
                                        * Referenced by: '<S68>/Sine Wave'
                                        */
  real_T SineWave_Phase;               /* Expression: 0
                                        * Referenced by: '<S68>/Sine Wave'
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
                                        * Referenced by: '<S28>/VCC1'
                                        */
  boolean_T VCC2_Value;                /* Computed Parameter: VCC2_Value
                                        * Referenced by: '<S28>/VCC2'
                                        */
  boolean_T VCC2_Value_c;              /* Computed Parameter: VCC2_Value_c
                                        * Referenced by: '<S32>/VCC2'
                                        */
  boolean_T VCC3_Value;                /* Computed Parameter: VCC3_Value
                                        * Referenced by: '<S32>/VCC3'
                                        */
  boolean_T Constant_Value_e;          /* Computed Parameter: Constant_Value_e
                                        * Referenced by: '<S30>/Constant'
                                        */
  boolean_T Constant1_Value_k;         /* Computed Parameter: Constant1_Value_k
                                        * Referenced by: '<S30>/Constant1'
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
  real_T odeF[1][24];
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
 * '<S1>'   : 'Bilateral_Ankle_Exo/Control Module'
 * '<S2>'   : 'Bilateral_Ankle_Exo/Data Capture1'
 * '<S3>'   : 'Bilateral_Ankle_Exo/Parameter Module'
 * '<S4>'   : 'Bilateral_Ankle_Exo/RTI Data'
 * '<S5>'   : 'Bilateral_Ankle_Exo/Sensor Data'
 * '<S6>'   : 'Bilateral_Ankle_Exo/State_Module_l'
 * '<S7>'   : 'Bilateral_Ankle_Exo/State_Module_r'
 * '<S8>'   : 'Bilateral_Ankle_Exo/Timer Interrupt'
 * '<S9>'   : 'Bilateral_Ankle_Exo/Control Module/Controller_L'
 * '<S10>'  : 'Bilateral_Ankle_Exo/Control Module/Controller_R'
 * '<S11>'  : 'Bilateral_Ankle_Exo/Control Module/LRN_L'
 * '<S12>'  : 'Bilateral_Ankle_Exo/Control Module/LRN_R'
 * '<S13>'  : 'Bilateral_Ankle_Exo/Control Module/Motor_L'
 * '<S14>'  : 'Bilateral_Ankle_Exo/Control Module/Motor_R'
 * '<S15>'  : 'Bilateral_Ankle_Exo/Control Module/Torque Track L'
 * '<S16>'  : 'Bilateral_Ankle_Exo/Control Module/Torque Track R'
 * '<S17>'  : 'Bilateral_Ankle_Exo/Control Module/Motor_L/DAC_CLASS1_BL1'
 * '<S18>'  : 'Bilateral_Ankle_Exo/Control Module/Motor_L/MATLAB Function'
 * '<S19>'  : 'Bilateral_Ankle_Exo/Control Module/Motor_R/DAC_CLASS1_BL1'
 * '<S20>'  : 'Bilateral_Ankle_Exo/Control Module/Motor_R/MATLAB Function'
 * '<S21>'  : 'Bilateral_Ankle_Exo/Parameter Module/Control Parameter'
 * '<S22>'  : 'Bilateral_Ankle_Exo/Parameter Module/Torque Parameter'
 * '<S23>'  : 'Bilateral_Ankle_Exo/Parameter Module/Control Parameter/Mux1'
 * '<S24>'  : 'Bilateral_Ankle_Exo/Parameter Module/Torque Parameter/Mux1'
 * '<S25>'  : 'Bilateral_Ankle_Exo/RTI Data/RTI Data Store'
 * '<S26>'  : 'Bilateral_Ankle_Exo/RTI Data/RTI Data Store/RTI Data Store'
 * '<S27>'  : 'Bilateral_Ankle_Exo/RTI Data/RTI Data Store/RTI Data Store/RTI Data Store'
 * '<S28>'  : 'Bilateral_Ankle_Exo/Sensor Data/Ankle Encoder'
 * '<S29>'  : 'Bilateral_Ankle_Exo/Sensor Data/EMG module'
 * '<S30>'  : 'Bilateral_Ankle_Exo/Sensor Data/FootSwitch module'
 * '<S31>'  : 'Bilateral_Ankle_Exo/Sensor Data/IMU module'
 * '<S32>'  : 'Bilateral_Ankle_Exo/Sensor Data/Motor Encoder'
 * '<S33>'  : 'Bilateral_Ankle_Exo/Sensor Data/Torque module'
 * '<S34>'  : 'Bilateral_Ankle_Exo/Sensor Data/Ankle Encoder/Calibration_L'
 * '<S35>'  : 'Bilateral_Ankle_Exo/Sensor Data/Ankle Encoder/Calibration_R'
 * '<S36>'  : 'Bilateral_Ankle_Exo/Sensor Data/Ankle Encoder/EMC_ENCODER_BL1'
 * '<S37>'  : 'Bilateral_Ankle_Exo/Sensor Data/Ankle Encoder/EMC_ENCODER_BL2'
 * '<S38>'  : 'Bilateral_Ankle_Exo/Sensor Data/Ankle Encoder/Encoder Power Setup1'
 * '<S39>'  : 'Bilateral_Ankle_Exo/Sensor Data/Ankle Encoder/Encoder Power Setup2'
 * '<S40>'  : 'Bilateral_Ankle_Exo/Sensor Data/Ankle Encoder/Mux'
 * '<S41>'  : 'Bilateral_Ankle_Exo/Sensor Data/Ankle Encoder/Mux1'
 * '<S42>'  : 'Bilateral_Ankle_Exo/Sensor Data/EMG module/ADC_CLASS1_BL1'
 * '<S43>'  : 'Bilateral_Ankle_Exo/Sensor Data/EMG module/ADC_CLASS1_BL2'
 * '<S44>'  : 'Bilateral_Ankle_Exo/Sensor Data/EMG module/ADC_CLASS1_BL3'
 * '<S45>'  : 'Bilateral_Ankle_Exo/Sensor Data/EMG module/ADC_CLASS1_BL4'
 * '<S46>'  : 'Bilateral_Ankle_Exo/Sensor Data/EMG module/ADC_CLASS1_BL5'
 * '<S47>'  : 'Bilateral_Ankle_Exo/Sensor Data/EMG module/ADC_CLASS1_BL6'
 * '<S48>'  : 'Bilateral_Ankle_Exo/Sensor Data/EMG module/Mux1'
 * '<S49>'  : 'Bilateral_Ankle_Exo/Sensor Data/EMG module/Preprocessing'
 * '<S50>'  : 'Bilateral_Ankle_Exo/Sensor Data/EMG module/Preprocessing1'
 * '<S51>'  : 'Bilateral_Ankle_Exo/Sensor Data/EMG module/Preprocessing2'
 * '<S52>'  : 'Bilateral_Ankle_Exo/Sensor Data/EMG module/Preprocessing3'
 * '<S53>'  : 'Bilateral_Ankle_Exo/Sensor Data/EMG module/Preprocessing8'
 * '<S54>'  : 'Bilateral_Ankle_Exo/Sensor Data/EMG module/Preprocessing9'
 * '<S55>'  : 'Bilateral_Ankle_Exo/Sensor Data/EMG module/Preprocessing/MVC'
 * '<S56>'  : 'Bilateral_Ankle_Exo/Sensor Data/EMG module/Preprocessing1/MVC'
 * '<S57>'  : 'Bilateral_Ankle_Exo/Sensor Data/EMG module/Preprocessing2/MVC'
 * '<S58>'  : 'Bilateral_Ankle_Exo/Sensor Data/EMG module/Preprocessing3/MVC'
 * '<S59>'  : 'Bilateral_Ankle_Exo/Sensor Data/EMG module/Preprocessing9/MVC'
 * '<S60>'  : 'Bilateral_Ankle_Exo/Sensor Data/FootSwitch module/DIO_CLASS1_BIT_IN_BL1'
 * '<S61>'  : 'Bilateral_Ankle_Exo/Sensor Data/FootSwitch module/DIO_CLASS1_BIT_IN_BL2'
 * '<S62>'  : 'Bilateral_Ankle_Exo/Sensor Data/FootSwitch module/DIO_CLASS1_BIT_OUT_BL1'
 * '<S63>'  : 'Bilateral_Ankle_Exo/Sensor Data/FootSwitch module/DIO_CLASS1_BIT_OUT_BL2'
 * '<S64>'  : 'Bilateral_Ankle_Exo/Sensor Data/FootSwitch module/Filter_L'
 * '<S65>'  : 'Bilateral_Ankle_Exo/Sensor Data/FootSwitch module/Filter_R'
 * '<S66>'  : 'Bilateral_Ankle_Exo/Sensor Data/IMU module/CAN_TYPE1_SETUP_M1_C1'
 * '<S67>'  : 'Bilateral_Ankle_Exo/Sensor Data/IMU module/CAN_TYPE1_SETUP_M1_C2'
 * '<S68>'  : 'Bilateral_Ankle_Exo/Sensor Data/IMU module/CAN_Test'
 * '<S69>'  : 'Bilateral_Ankle_Exo/Sensor Data/IMU module/IMU'
 * '<S70>'  : 'Bilateral_Ankle_Exo/Sensor Data/IMU module/CAN_Test/CAN_TYPE1_RX_M1_C1'
 * '<S71>'  : 'Bilateral_Ankle_Exo/Sensor Data/IMU module/CAN_Test/CAN_TYPE1_TX_M1_C2'
 * '<S72>'  : 'Bilateral_Ankle_Exo/Sensor Data/IMU module/IMU/CAN_RX_Accel'
 * '<S73>'  : 'Bilateral_Ankle_Exo/Sensor Data/IMU module/IMU/Subsystem6'
 * '<S74>'  : 'Bilateral_Ankle_Exo/Sensor Data/IMU module/IMU/Subsystem7'
 * '<S75>'  : 'Bilateral_Ankle_Exo/Sensor Data/IMU module/IMU/Subsystem8'
 * '<S76>'  : 'Bilateral_Ankle_Exo/Sensor Data/Motor Encoder/2-Order TD'
 * '<S77>'  : 'Bilateral_Ankle_Exo/Sensor Data/Motor Encoder/2-Order TD1'
 * '<S78>'  : 'Bilateral_Ankle_Exo/Sensor Data/Motor Encoder/Calibration_L'
 * '<S79>'  : 'Bilateral_Ankle_Exo/Sensor Data/Motor Encoder/Calibration_R'
 * '<S80>'  : 'Bilateral_Ankle_Exo/Sensor Data/Motor Encoder/EMC_ENCODER_BL2'
 * '<S81>'  : 'Bilateral_Ankle_Exo/Sensor Data/Motor Encoder/EMC_ENCODER_BL3'
 * '<S82>'  : 'Bilateral_Ankle_Exo/Sensor Data/Motor Encoder/Encoder Power Setup2'
 * '<S83>'  : 'Bilateral_Ankle_Exo/Sensor Data/Motor Encoder/Encoder Power Setup3'
 * '<S84>'  : 'Bilateral_Ankle_Exo/Sensor Data/Motor Encoder/Mux1'
 * '<S85>'  : 'Bilateral_Ankle_Exo/Sensor Data/Motor Encoder/Mux3'
 * '<S86>'  : 'Bilateral_Ankle_Exo/Sensor Data/Torque module/2-Order TD'
 * '<S87>'  : 'Bilateral_Ankle_Exo/Sensor Data/Torque module/2-Order TD1'
 * '<S88>'  : 'Bilateral_Ankle_Exo/Sensor Data/Torque module/ADC_CLASS1_BL1'
 * '<S89>'  : 'Bilateral_Ankle_Exo/Sensor Data/Torque module/ADC_CLASS1_BL6'
 * '<S90>'  : 'Bilateral_Ankle_Exo/Sensor Data/Torque module/Calibration_L'
 * '<S91>'  : 'Bilateral_Ankle_Exo/Sensor Data/Torque module/Calibration_R'
 * '<S92>'  : 'Bilateral_Ankle_Exo/Sensor Data/Torque module/DS1202_SENSOR_SUPPLY'
 * '<S93>'  : 'Bilateral_Ankle_Exo/Sensor Data/Torque module/MATLAB Function'
 * '<S94>'  : 'Bilateral_Ankle_Exo/Sensor Data/Torque module/Mux_L'
 * '<S95>'  : 'Bilateral_Ankle_Exo/Sensor Data/Torque module/Mux_R'
 * '<S96>'  : 'Bilateral_Ankle_Exo/State_Module_l/Mux1'
 * '<S97>'  : 'Bilateral_Ankle_Exo/State_Module_l/State Machine'
 * '<S98>'  : 'Bilateral_Ankle_Exo/State_Module_r/Mux1'
 * '<S99>'  : 'Bilateral_Ankle_Exo/State_Module_r/State Machine'
 */
#endif                                 /* RTW_HEADER_Bilateral_Ankle_Exo_h_ */
