/*********************** dSPACE target specific file *************************

   Header file Bilateral_Ankle_Exo_trc_ptr.h:

   Declaration of function that initializes the global TRC pointers

   RTI1202 7.9 (02-Nov-2017)
   Mon Jun 15 21:41:53 2020

   Copyright 2020, dSPACE GmbH. All rights reserved.

 *****************************************************************************/
#ifndef RTI_HEADER_Bilateral_Ankle_Exo_trc_ptr_h_
#define RTI_HEADER_Bilateral_Ankle_Exo_trc_ptr_h_

/* Include the model header file. */
#include "Bilateral_Ankle_Exo.h"
#include "Bilateral_Ankle_Exo_private.h"
#ifdef EXTERN_C
#undef EXTERN_C
#endif

#ifdef __cplusplus
#define EXTERN_C                       extern "C"
#else
#define EXTERN_C                       extern
#endif

/*
 *  Declare the global TRC pointers
 */
EXTERN_C volatile real_T *p_0_Bilateral_Ankle_Exo_real_T_0;
EXTERN_C volatile boolean_T *p_0_Bilateral_Ankle_Exo_boolean_T_1;
EXTERN_C volatile real_T *p_0_Bilateral_Ankle_Exo_real_T_2;
EXTERN_C volatile real_T *p_0_Bilateral_Ankle_Exo_real_T_3;
EXTERN_C volatile real_T *p_0_Bilateral_Ankle_Exo_real_T_4;
EXTERN_C volatile real_T *p_0_Bilateral_Ankle_Exo_real_T_5;
EXTERN_C volatile real_T *p_0_Bilateral_Ankle_Exo_real_T_6;
EXTERN_C volatile real_T *p_0_Bilateral_Ankle_Exo_real_T_7;
EXTERN_C volatile real_T *p_0_Bilateral_Ankle_Exo_real_T_8;
EXTERN_C volatile real_T *p_0_Bilateral_Ankle_Exo_real_T_9;
EXTERN_C volatile real_T *p_0_Bilateral_Ankle_Exo_real_T_10;
EXTERN_C volatile real_T *p_0_Bilateral_Ankle_Exo_real_T_11;
EXTERN_C volatile real_T *p_0_Bilateral_Ankle_Exo_real_T_12;
EXTERN_C volatile real_T *p_0_Bilateral_Ankle_Exo_real_T_13;
EXTERN_C volatile real_T *p_1_Bilateral_Ankle_Exo_real_T_0;
EXTERN_C volatile int32_T *p_1_Bilateral_Ankle_Exo_int32_T_1;
EXTERN_C volatile int8_T *p_1_Bilateral_Ankle_Exo_int8_T_2;
EXTERN_C volatile boolean_T *p_1_Bilateral_Ankle_Exo_boolean_T_3;
EXTERN_C volatile real_T *p_1_Bilateral_Ankle_Exo_real_T_4;
EXTERN_C volatile boolean_T *p_1_Bilateral_Ankle_Exo_boolean_T_5;
EXTERN_C volatile real_T *p_2_Bilateral_Ankle_Exo_real_T_0;
EXTERN_C volatile int_T *p_2_Bilateral_Ankle_Exo_int_T_1;
EXTERN_C volatile int8_T *p_2_Bilateral_Ankle_Exo_int8_T_2;
EXTERN_C volatile boolean_T *p_2_Bilateral_Ankle_Exo_boolean_T_3;
EXTERN_C volatile real_T *p_2_Bilateral_Ankle_Exo_real_T_4;
EXTERN_C volatile real_T *p_2_Bilateral_Ankle_Exo_real_T_5;
EXTERN_C volatile real_T *p_3_Bilateral_Ankle_Exo_real_T_0;

/*
 *  Declare the general function for TRC pointer initialization
 */
EXTERN_C void Bilateral_Ankle_Exo_rti_init_trc_pointers(void);

#endif                                 /* RTI_HEADER_Bilateral_Ankle_Exo_trc_ptr_h_ */
