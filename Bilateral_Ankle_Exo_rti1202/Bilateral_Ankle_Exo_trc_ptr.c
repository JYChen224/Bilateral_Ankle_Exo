/***************************************************************************

   Source file Bilateral_Ankle_Exo_trc_ptr.c:

   Definition of function that initializes the global TRC pointers

   RTI1202 7.9 (02-Nov-2017)
   Mon Jun 15 21:41:53 2020

   Copyright 2020, dSPACE GmbH. All rights reserved.

 *****************************************************************************/

/* Include header file. */
#include "Bilateral_Ankle_Exo_trc_ptr.h"
#include "Bilateral_Ankle_Exo.h"
#include "Bilateral_Ankle_Exo_private.h"

/* Compiler options to turn off optimization. */
#if !defined(DS_OPTIMIZE_INIT_TRC_POINTERS)
#ifdef _MCCPPC

#pragma options -nOt -nOr -nOi -nOx

#endif

#ifdef __GNUC__

#pragma GCC optimize ("O0")

#endif

#ifdef _MSC_VER

#pragma optimize ("", off)

#endif
#endif

/* Definition of Global pointers to data type transitions (for TRC-file access) */
volatile real_T *p_0_Bilateral_Ankle_Exo_real_T_0 = NULL;
volatile boolean_T *p_0_Bilateral_Ankle_Exo_boolean_T_1 = NULL;
volatile real_T *p_0_Bilateral_Ankle_Exo_real_T_2 = NULL;
volatile real_T *p_0_Bilateral_Ankle_Exo_real_T_3 = NULL;
volatile real_T *p_0_Bilateral_Ankle_Exo_real_T_4 = NULL;
volatile real_T *p_0_Bilateral_Ankle_Exo_real_T_5 = NULL;
volatile real_T *p_0_Bilateral_Ankle_Exo_real_T_6 = NULL;
volatile real_T *p_0_Bilateral_Ankle_Exo_real_T_7 = NULL;
volatile real_T *p_0_Bilateral_Ankle_Exo_real_T_8 = NULL;
volatile real_T *p_0_Bilateral_Ankle_Exo_real_T_9 = NULL;
volatile real_T *p_0_Bilateral_Ankle_Exo_real_T_10 = NULL;
volatile real_T *p_0_Bilateral_Ankle_Exo_real_T_11 = NULL;
volatile real_T *p_0_Bilateral_Ankle_Exo_real_T_12 = NULL;
volatile real_T *p_0_Bilateral_Ankle_Exo_real_T_13 = NULL;
volatile real_T *p_1_Bilateral_Ankle_Exo_real_T_0 = NULL;
volatile int32_T *p_1_Bilateral_Ankle_Exo_int32_T_1 = NULL;
volatile int8_T *p_1_Bilateral_Ankle_Exo_int8_T_2 = NULL;
volatile boolean_T *p_1_Bilateral_Ankle_Exo_boolean_T_3 = NULL;
volatile real_T *p_1_Bilateral_Ankle_Exo_real_T_4 = NULL;
volatile boolean_T *p_1_Bilateral_Ankle_Exo_boolean_T_5 = NULL;
volatile real_T *p_2_Bilateral_Ankle_Exo_real_T_0 = NULL;
volatile int_T *p_2_Bilateral_Ankle_Exo_int_T_1 = NULL;
volatile int8_T *p_2_Bilateral_Ankle_Exo_int8_T_2 = NULL;
volatile boolean_T *p_2_Bilateral_Ankle_Exo_boolean_T_3 = NULL;
volatile real_T *p_2_Bilateral_Ankle_Exo_real_T_4 = NULL;
volatile real_T *p_2_Bilateral_Ankle_Exo_real_T_5 = NULL;
volatile real_T *p_3_Bilateral_Ankle_Exo_real_T_0 = NULL;

/*
 *  Declare the functions, that initially assign TRC pointers
 */
static void rti_init_trc_pointers_0(void);

/* Global pointers to data type transitions are separated in different functions to avoid overloading */
static void rti_init_trc_pointers_0(void)
{
  p_0_Bilateral_Ankle_Exo_real_T_0 = &Bilateral_Ankle_Exo_B.SFunction1;
  p_0_Bilateral_Ankle_Exo_boolean_T_1 = &Bilateral_Ankle_Exo_B.SFunction1_o3_b;
  p_0_Bilateral_Ankle_Exo_real_T_2 =
    &Bilateral_Ankle_Exo_B.sf_MATLABFunction_b.vel;
  p_0_Bilateral_Ankle_Exo_real_T_3 =
    &Bilateral_Ankle_Exo_B.sf_MATLABFunction_h.vel;
  p_0_Bilateral_Ankle_Exo_real_T_4 = &Bilateral_Ankle_Exo_B.sf_Mux1.x[0];
  p_0_Bilateral_Ankle_Exo_real_T_5 = &Bilateral_Ankle_Exo_B.sf_Mux1_p.x[0];
  p_0_Bilateral_Ankle_Exo_real_T_6 = &Bilateral_Ankle_Exo_B.sf_Mux_R.x[0];
  p_0_Bilateral_Ankle_Exo_real_T_7 = &Bilateral_Ankle_Exo_B.sf_Mux_L.x[0];
  p_0_Bilateral_Ankle_Exo_real_T_8 = &Bilateral_Ankle_Exo_B.sf_Mux3.x[0];
  p_0_Bilateral_Ankle_Exo_real_T_9 = &Bilateral_Ankle_Exo_B.sf_Mux1_o.x[0];
  p_0_Bilateral_Ankle_Exo_real_T_10 = &Bilateral_Ankle_Exo_B.sf_Filter_R.state;
  p_0_Bilateral_Ankle_Exo_real_T_11 = &Bilateral_Ankle_Exo_B.sf_Filter_L.state;
  p_0_Bilateral_Ankle_Exo_real_T_12 = &Bilateral_Ankle_Exo_B.sf_Mux1_b.x[0];
  p_0_Bilateral_Ankle_Exo_real_T_13 = &Bilateral_Ankle_Exo_B.sf_Mux.x[0];
  p_1_Bilateral_Ankle_Exo_real_T_0 =
    &Bilateral_Ankle_Exo_P.Controller_L_FOLLOW_SLACK_ANGLE;
  p_1_Bilateral_Ankle_Exo_int32_T_1 = &Bilateral_Ankle_Exo_P.LRN_L_time_delay_l;
  p_1_Bilateral_Ankle_Exo_int8_T_2 = &Bilateral_Ankle_Exo_P.Controller_L_MODE_L;
  p_1_Bilateral_Ankle_Exo_boolean_T_3 =
    &Bilateral_Ankle_Exo_P.StateMachine_BT_CALIB_L;
  p_1_Bilateral_Ankle_Exo_real_T_4 = &Bilateral_Ankle_Exo_P.torque_offset_Value;
  p_1_Bilateral_Ankle_Exo_boolean_T_5 = &Bilateral_Ankle_Exo_P.VCC1_Value;
  p_2_Bilateral_Ankle_Exo_real_T_0 = &Bilateral_Ankle_Exo_DW.u4low2_states[0];
  p_2_Bilateral_Ankle_Exo_int_T_1 = &Bilateral_Ankle_Exo_DW.SFunction1_IWORK[0];
  p_2_Bilateral_Ankle_Exo_int8_T_2 = &Bilateral_Ankle_Exo_DW.RT4_write_buf;
  p_2_Bilateral_Ankle_Exo_boolean_T_3 =
    &Bilateral_Ankle_Exo_DW.last_footstate_not_empty;
  p_2_Bilateral_Ankle_Exo_real_T_4 =
    &Bilateral_Ankle_Exo_DW.sf_Filter_R.foot_state;
  p_2_Bilateral_Ankle_Exo_real_T_5 =
    &Bilateral_Ankle_Exo_DW.sf_Filter_L.foot_state;
  p_3_Bilateral_Ankle_Exo_real_T_0 = &Bilateral_Ankle_Exo_X.low_pass_CSTATE[0];
}

void Bilateral_Ankle_Exo_rti_init_trc_pointers(void)
{
  rti_init_trc_pointers_0();
}
