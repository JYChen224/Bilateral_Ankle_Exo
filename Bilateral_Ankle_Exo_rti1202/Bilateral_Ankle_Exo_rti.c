/*********************** dSPACE target specific file *************************

   Include file Bilateral_Ankle_Exo_rti.c:

   Definition of functions and variables for the system I/O and for
   the hardware and software interrupts used.

   RTI1202 7.9 (02-Nov-2017)
   Thu Jun 18 18:06:16 2020

   Copyright 2020, dSPACE GmbH. All rights reserved.

 *****************************************************************************/

#if !(defined(__RTI_SIMENGINE__) || defined(RTIMP_FRAME))
# error This file may be included only by the RTI(-MP) simulation engine.
#endif

/* Include the model header file. */
#include "Bilateral_Ankle_Exo.h"
#include "Bilateral_Ankle_Exo_private.h"

/* Defines for block output and parameter structure existence */
#define RTI_rtB_STRUCTURE_EXISTS       1
#define RTI_rtP_STRUCTURE_EXISTS       1
#define RTB_STRUCTURE_NAME             Bilateral_Ankle_Exo_B
#define RTP_STRUCTURE_NAME             Bilateral_Ankle_Exo_P

/* dSPACE generated includes for header files */
#include <brtenv.h>
#include <rtkernel.h>
#include <rti_assert.h>
#include <rtidefineddatatypes.h>
#include <rtican_ds1202.h>
#ifndef dsRtmGetNumSampleTimes
# define dsRtmGetNumSampleTimes(rtm)   4
#endif

#ifndef dsRtmGetTPtr
# define dsRtmGetTPtr(rtm)             ((rtm)->Timing.t)
#endif

#ifndef dsRtmSetTaskTime
# define dsRtmSetTaskTime(rtm, sti, val) (dsRtmGetTPtr((rtm))[sti] = (val))
#endif

/****** Definitions: task functions for timer tasks *********************/

/* Timer Task 1. (Base rate). */
static void rti_TIMERA(rtk_p_task_control_block task)
{
  /* Task entry code BEGIN */
  /* -- None. -- */
  /* Task entry code END */

  /* Task code. */
  baseRateService(task);

  /* Task exit code BEGIN */
  /* -- None. -- */
  /* Task exit code END */
}

/****** Definitions: task functions for timer interrupts ****************/

/* Timer Interrupt: <Root>/Timer Interrupt */
static void rti_TIMERB(rtk_p_task_control_block task)
{
  /* Task entry code BEGIN */
  /* -- None. -- */
  /* Task entry code END */

  /* Task code. */
  {
    int32_T i;

    /* RateTransition: '<Root>/RT4' */
    switch (Bilateral_Ankle_Exo_DW.RT4_write_buf) {
     case 0:
      Bilateral_Ankle_Exo_DW.RT4_read_buf = 1;
      break;

     case 1:
      Bilateral_Ankle_Exo_DW.RT4_read_buf = 0;
      break;

     default:
      Bilateral_Ankle_Exo_DW.RT4_read_buf =
        Bilateral_Ankle_Exo_DW.RT4_last_buf_wr;
      break;
    }

    if (Bilateral_Ankle_Exo_DW.RT4_read_buf != 0) {
      Bilateral_Ankle_Exo_B.RT4[0] = Bilateral_Ankle_Exo_DW.RT4_Buffer1[0];
      Bilateral_Ankle_Exo_B.RT4[1] = Bilateral_Ankle_Exo_DW.RT4_Buffer1[1];
    } else {
      Bilateral_Ankle_Exo_B.RT4[0] = Bilateral_Ankle_Exo_DW.RT4_Buffer0[0];
      Bilateral_Ankle_Exo_B.RT4[1] = Bilateral_Ankle_Exo_DW.RT4_Buffer0[1];
    }

    Bilateral_Ankle_Exo_DW.RT4_read_buf = -1;

    /* End of RateTransition: '<Root>/RT4' */

    /* RateTransition: '<Root>/RT5' */
    switch (Bilateral_Ankle_Exo_DW.RT5_write_buf) {
     case 0:
      Bilateral_Ankle_Exo_DW.RT5_read_buf = 1;
      break;

     case 1:
      Bilateral_Ankle_Exo_DW.RT5_read_buf = 0;
      break;

     default:
      Bilateral_Ankle_Exo_DW.RT5_read_buf =
        Bilateral_Ankle_Exo_DW.RT5_last_buf_wr;
      break;
    }

    if (Bilateral_Ankle_Exo_DW.RT5_read_buf != 0) {
      Bilateral_Ankle_Exo_B.RT5[0] = Bilateral_Ankle_Exo_DW.RT5_Buffer1[0];
      Bilateral_Ankle_Exo_B.RT5[1] = Bilateral_Ankle_Exo_DW.RT5_Buffer1[1];
    } else {
      Bilateral_Ankle_Exo_B.RT5[0] = Bilateral_Ankle_Exo_DW.RT5_Buffer0[0];
      Bilateral_Ankle_Exo_B.RT5[1] = Bilateral_Ankle_Exo_DW.RT5_Buffer0[1];
    }

    Bilateral_Ankle_Exo_DW.RT5_read_buf = -1;

    /* End of RateTransition: '<Root>/RT5' */

    /* RateTransition: '<Root>/RT6' */
    switch (Bilateral_Ankle_Exo_DW.RT6_write_buf) {
     case 0:
      Bilateral_Ankle_Exo_DW.RT6_read_buf = 1;
      break;

     case 1:
      Bilateral_Ankle_Exo_DW.RT6_read_buf = 0;
      break;

     default:
      Bilateral_Ankle_Exo_DW.RT6_read_buf =
        Bilateral_Ankle_Exo_DW.RT6_last_buf_wr;
      break;
    }

    if (Bilateral_Ankle_Exo_DW.RT6_read_buf != 0) {
      Bilateral_Ankle_Exo_B.RT6[0] = Bilateral_Ankle_Exo_DW.RT6_Buffer1[0];
      Bilateral_Ankle_Exo_B.RT6[1] = Bilateral_Ankle_Exo_DW.RT6_Buffer1[1];
      Bilateral_Ankle_Exo_B.RT6[2] = Bilateral_Ankle_Exo_DW.RT6_Buffer1[2];
    } else {
      Bilateral_Ankle_Exo_B.RT6[0] = Bilateral_Ankle_Exo_DW.RT6_Buffer0[0];
      Bilateral_Ankle_Exo_B.RT6[1] = Bilateral_Ankle_Exo_DW.RT6_Buffer0[1];
      Bilateral_Ankle_Exo_B.RT6[2] = Bilateral_Ankle_Exo_DW.RT6_Buffer0[2];
    }

    Bilateral_Ankle_Exo_DW.RT6_read_buf = -1;

    /* End of RateTransition: '<Root>/RT6' */

    /* RateTransition: '<Root>/RT1' */
    switch (Bilateral_Ankle_Exo_DW.RT1_write_buf) {
     case 0:
      Bilateral_Ankle_Exo_DW.RT1_read_buf = 1;
      break;

     case 1:
      Bilateral_Ankle_Exo_DW.RT1_read_buf = 0;
      break;

     default:
      Bilateral_Ankle_Exo_DW.RT1_read_buf =
        Bilateral_Ankle_Exo_DW.RT1_last_buf_wr;
      break;
    }

    if (Bilateral_Ankle_Exo_DW.RT1_read_buf != 0) {
      Bilateral_Ankle_Exo_B.RT1[0] = Bilateral_Ankle_Exo_DW.RT1_Buffer1[0];
      Bilateral_Ankle_Exo_B.RT1[1] = Bilateral_Ankle_Exo_DW.RT1_Buffer1[1];
      Bilateral_Ankle_Exo_B.RT1[2] = Bilateral_Ankle_Exo_DW.RT1_Buffer1[2];
      Bilateral_Ankle_Exo_B.RT1[3] = Bilateral_Ankle_Exo_DW.RT1_Buffer1[3];
    } else {
      Bilateral_Ankle_Exo_B.RT1[0] = Bilateral_Ankle_Exo_DW.RT1_Buffer0[0];
      Bilateral_Ankle_Exo_B.RT1[1] = Bilateral_Ankle_Exo_DW.RT1_Buffer0[1];
      Bilateral_Ankle_Exo_B.RT1[2] = Bilateral_Ankle_Exo_DW.RT1_Buffer0[2];
      Bilateral_Ankle_Exo_B.RT1[3] = Bilateral_Ankle_Exo_DW.RT1_Buffer0[3];
    }

    Bilateral_Ankle_Exo_DW.RT1_read_buf = -1;

    /* End of RateTransition: '<Root>/RT1' */

    /* RateTransition: '<Root>/RT2' */
    switch (Bilateral_Ankle_Exo_DW.RT2_write_buf) {
     case 0:
      Bilateral_Ankle_Exo_DW.RT2_read_buf = 1;
      break;

     case 1:
      Bilateral_Ankle_Exo_DW.RT2_read_buf = 0;
      break;

     default:
      Bilateral_Ankle_Exo_DW.RT2_read_buf =
        Bilateral_Ankle_Exo_DW.RT2_last_buf_wr;
      break;
    }

    for (i = 0; i < 6; i++) {
      if (Bilateral_Ankle_Exo_DW.RT2_read_buf != 0) {
        Bilateral_Ankle_Exo_B.RT2[i] = Bilateral_Ankle_Exo_DW.RT2_Buffer1[i];
      } else {
        Bilateral_Ankle_Exo_B.RT2[i] = Bilateral_Ankle_Exo_DW.RT2_Buffer0[i];
      }
    }

    Bilateral_Ankle_Exo_DW.RT2_read_buf = -1;

    /* End of RateTransition: '<Root>/RT2' */

    /* RateTransition: '<Root>/RT3' */
    switch (Bilateral_Ankle_Exo_DW.RT3_write_buf) {
     case 0:
      Bilateral_Ankle_Exo_DW.RT3_read_buf = 1;
      break;

     case 1:
      Bilateral_Ankle_Exo_DW.RT3_read_buf = 0;
      break;

     default:
      Bilateral_Ankle_Exo_DW.RT3_read_buf =
        Bilateral_Ankle_Exo_DW.RT3_last_buf_wr;
      break;
    }

    for (i = 0; i < 9; i++) {
      if (Bilateral_Ankle_Exo_DW.RT3_read_buf != 0) {
        Bilateral_Ankle_Exo_B.RT3[i] = Bilateral_Ankle_Exo_DW.RT3_Buffer1[i];
      } else {
        Bilateral_Ankle_Exo_B.RT3[i] = Bilateral_Ankle_Exo_DW.RT3_Buffer0[i];
      }
    }

    Bilateral_Ankle_Exo_DW.RT3_read_buf = -1;

    /* End of RateTransition: '<Root>/RT3' */

    /* RateTransition: '<Root>/RT7' */
    switch (Bilateral_Ankle_Exo_DW.RT7_write_buf) {
     case 0:
      Bilateral_Ankle_Exo_DW.RT7_read_buf = 1;
      break;

     case 1:
      Bilateral_Ankle_Exo_DW.RT7_read_buf = 0;
      break;

     default:
      Bilateral_Ankle_Exo_DW.RT7_read_buf =
        Bilateral_Ankle_Exo_DW.RT7_last_buf_wr;
      break;
    }

    if (Bilateral_Ankle_Exo_DW.RT7_read_buf != 0) {
      Bilateral_Ankle_Exo_B.RT7[0] = Bilateral_Ankle_Exo_DW.RT7_Buffer1[0];
      Bilateral_Ankle_Exo_B.RT7[1] = Bilateral_Ankle_Exo_DW.RT7_Buffer1[1];
      Bilateral_Ankle_Exo_B.RT7[2] = Bilateral_Ankle_Exo_DW.RT7_Buffer1[2];
      Bilateral_Ankle_Exo_B.RT7[3] = Bilateral_Ankle_Exo_DW.RT7_Buffer1[3];
    } else {
      Bilateral_Ankle_Exo_B.RT7[0] = Bilateral_Ankle_Exo_DW.RT7_Buffer0[0];
      Bilateral_Ankle_Exo_B.RT7[1] = Bilateral_Ankle_Exo_DW.RT7_Buffer0[1];
      Bilateral_Ankle_Exo_B.RT7[2] = Bilateral_Ankle_Exo_DW.RT7_Buffer0[2];
      Bilateral_Ankle_Exo_B.RT7[3] = Bilateral_Ankle_Exo_DW.RT7_Buffer0[3];
    }

    Bilateral_Ankle_Exo_DW.RT7_read_buf = -1;

    /* End of RateTransition: '<Root>/RT7' */

    /* RateTransition: '<Root>/RT8' */
    switch (Bilateral_Ankle_Exo_DW.RT8_write_buf) {
     case 0:
      Bilateral_Ankle_Exo_DW.RT8_read_buf = 1;
      break;

     case 1:
      Bilateral_Ankle_Exo_DW.RT8_read_buf = 0;
      break;

     default:
      Bilateral_Ankle_Exo_DW.RT8_read_buf =
        Bilateral_Ankle_Exo_DW.RT8_last_buf_wr;
      break;
    }

    if (Bilateral_Ankle_Exo_DW.RT8_read_buf != 0) {
      Bilateral_Ankle_Exo_B.RT8[0] = Bilateral_Ankle_Exo_DW.RT8_Buffer1[0];
      Bilateral_Ankle_Exo_B.RT8[1] = Bilateral_Ankle_Exo_DW.RT8_Buffer1[1];
    } else {
      Bilateral_Ankle_Exo_B.RT8[0] = Bilateral_Ankle_Exo_DW.RT8_Buffer0[0];
      Bilateral_Ankle_Exo_B.RT8[1] = Bilateral_Ankle_Exo_DW.RT8_Buffer0[1];
    }

    Bilateral_Ankle_Exo_DW.RT8_read_buf = -1;

    /* End of RateTransition: '<Root>/RT8' */

    /* RateTransition: '<Root>/RT9' */
    switch (Bilateral_Ankle_Exo_DW.RT9_write_buf) {
     case 0:
      Bilateral_Ankle_Exo_DW.RT9_read_buf = 1;
      break;

     case 1:
      Bilateral_Ankle_Exo_DW.RT9_read_buf = 0;
      break;

     default:
      Bilateral_Ankle_Exo_DW.RT9_read_buf =
        Bilateral_Ankle_Exo_DW.RT9_last_buf_wr;
      break;
    }

    if (Bilateral_Ankle_Exo_DW.RT9_read_buf != 0) {
      Bilateral_Ankle_Exo_B.RT9[0] = Bilateral_Ankle_Exo_DW.RT9_Buffer1[0];
      Bilateral_Ankle_Exo_B.RT9[1] = Bilateral_Ankle_Exo_DW.RT9_Buffer1[1];
    } else {
      Bilateral_Ankle_Exo_B.RT9[0] = Bilateral_Ankle_Exo_DW.RT9_Buffer0[0];
      Bilateral_Ankle_Exo_B.RT9[1] = Bilateral_Ankle_Exo_DW.RT9_Buffer0[1];
    }

    Bilateral_Ankle_Exo_DW.RT9_read_buf = -1;

    /* End of RateTransition: '<Root>/RT9' */

    /* RateTransition: '<Root>/RT10' */
    switch (Bilateral_Ankle_Exo_DW.RT10_write_buf) {
     case 0:
      Bilateral_Ankle_Exo_DW.RT10_read_buf = 1;
      break;

     case 1:
      Bilateral_Ankle_Exo_DW.RT10_read_buf = 0;
      break;

     default:
      Bilateral_Ankle_Exo_DW.RT10_read_buf =
        Bilateral_Ankle_Exo_DW.RT10_last_buf_wr;
      break;
    }

    if (Bilateral_Ankle_Exo_DW.RT10_read_buf != 0) {
      Bilateral_Ankle_Exo_B.RT10[0] = Bilateral_Ankle_Exo_DW.RT10_Buffer1[0];
      Bilateral_Ankle_Exo_B.RT10[1] = Bilateral_Ankle_Exo_DW.RT10_Buffer1[1];
      Bilateral_Ankle_Exo_B.RT10[2] = Bilateral_Ankle_Exo_DW.RT10_Buffer1[2];
    } else {
      Bilateral_Ankle_Exo_B.RT10[0] = Bilateral_Ankle_Exo_DW.RT10_Buffer0[0];
      Bilateral_Ankle_Exo_B.RT10[1] = Bilateral_Ankle_Exo_DW.RT10_Buffer0[1];
      Bilateral_Ankle_Exo_B.RT10[2] = Bilateral_Ankle_Exo_DW.RT10_Buffer0[2];
    }

    Bilateral_Ankle_Exo_DW.RT10_read_buf = -1;

    /* End of RateTransition: '<Root>/RT10' */

    /* S-Function (rti_commonblock): '<S9>/S-Function1' */
    Bilateral_Ankle_E_ControlModule();

    /* End of Outputs for S-Function (rti_commonblock): '<S9>/S-Function1' */
  }

  /* Task exit code BEGIN */
  /* -- None. -- */
  /* Task exit code END */
}

/* ===== Declarations of RTI blocks ======================================== */
DacCl1AnalogOutSDrvObject *pRTIDacC1AnalogOut_Ch_16;
DacCl1AnalogOutSDrvObject *pRTIDacC1AnalogOut_Ch_15;
AdcCl1AnalogInSDrvObject *pRTIAdcC1AnalogIn_Ch_6;
DioCl2EncoderInSDrvObject *pRTIEmcEncoder_Unit_5_DioCl_2_Port_1_Ch10;
DioCl2EncoderInSDrvObject *pRTIEmcEncoder_Unit_2_DioCl_2_Port_1_Ch3;
DioCl1DigInSDrvObject *pRTIDioC1DigIn_Port_1_Ch_2;
DioCl1DigInSDrvObject *pRTIDioC1DigIn_Port_1_Ch_4;
AdcCl1AnalogInSDrvObject *pRTIAdcC1AnalogIn_Ch_7;
DioCl2EncoderInSDrvObject *pRTIEmcEncoder_Unit_4_DioCl_2_Port_1_Ch7;
DioCl2EncoderInSDrvObject *pRTIEmcEncoder_Unit_3_DioCl_2_Port_1_Ch5;
SensorSupplySDrvObject *pRTI_Sensor_Supply;
DioCl1DigOutSDrvObject *pRTIDioC1DigOut_Port_3_Ch_15;
DioCl1DigOutSDrvObject *pRTIDioC1DigOut_Port_3_Ch_16;
DioCl1DigOutSDrvObject *pRTIDioC1DigOut_Port_3_Ch_12;
DioCl1DigOutSDrvObject *pRTIDioC1DigOut_Port_3_Ch_13;
DioCl1DigOutSDrvObject *pRTIDioC1DigOut_Port_1_Ch_1;
DioCl1DigOutSDrvObject *pRTIDioC1DigOut_Port_1_Ch_3;
AdcCl1AnalogInSDrvObject *pRTIAdcC1AnalogIn_Ch_1;
AdcCl1AnalogInSDrvObject *pRTIAdcC1AnalogIn_Ch_10;
AdcCl1AnalogInSDrvObject *pRTIAdcC1AnalogIn_Ch_11;
AdcCl1AnalogInSDrvObject *pRTIAdcC1AnalogIn_Ch_12;
AdcCl1AnalogInSDrvObject *pRTIAdcC1AnalogIn_Ch_2;
AdcCl1AnalogInSDrvObject *pRTIAdcC1AnalogIn_Ch_3;
AdcCl1AnalogInSDrvObject *pRTIAdcC1AnalogIn_Ch_4;
AdcCl1AnalogInSDrvObject *pRTIAdcC1AnalogIn_Ch_9;

/* dSPACE I/O Board DS1_RTICAN #1 */

/* ...  definition of channel struct */
can_tp1_canChannel* can_type1_channel_M1_C1;

/* ...  definition of channel struct */
can_tp1_canChannel* can_type1_channel_M1_C2;

/* declare pointers to CAN message structures for support of TX-Custom code */
can_tp1_canMsg* CANTP1_TX_SPMSG_M1_C1_STD;
can_tp1_canMsg* CANTP1_TX_SPMSG_M1_C1_XTD;

/* declare pointer to CAN message object for STD-Msg */
can_tp1_canMsg* CANTP1_RX_SPMSG_M1_C1_STD;

/* declare needed identifiers for mcr-queue */
can_tp1_canMsg* CANTP1_RX_M1_C1_MCRCLT_STD;

/* declare pointers to CAN message structures for support of TX-Custom code */
can_tp1_canMsg* CANTP1_TX_SPMSG_M1_C2_STD;
can_tp1_canMsg* CANTP1_TX_SPMSG_M1_C2_XTD;

/* declare pointer to CAN message object for STD-Msg */
can_tp1_canMsg* CANTP1_RX_SPMSG_M1_C2_STD;

/* declare needed identifiers for mcr-queue */
can_tp1_canMsg* CANTP1_RX_M1_C2_MCRCLT_STD;

/* ... definition of message variable for the RTICAN blocks */
can_tp1_canMsg* can_type1_msg_M1[CANTP1_M1_NUMMSG];

/* dSPACE I/O Board RTICAN_GLOBAL #0 */

/* ===== Definition of interface functions for simulation engine =========== */
#if GRTINTERFACE == 1
#ifdef MULTITASKING
# define dsIsSampleHit(RTM,sti)        rtmGetSampleHitPtr(RTM)[sti]
#else
# define dsIsSampleHit(RTM,sti)        rtmIsSampleHit(RTM,sti,0)
#endif

#else
#ifndef rtmStepTask
# define rtmStepTask(rtm, idx)         ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

# define dsIsSampleHit(RTM,sti)        rtmStepTask(RTM, sti)
#endif

#undef __INLINE
#if defined(_INLINE)
# define __INLINE                      static inline
#else
# define __INLINE                      static
#endif

/*Define additional variables*/
static time_T dsTFinal = -1.0;

#define dsGetTFinal(rtm)               (dsTFinal)

static time_T dsStepSize = 0.0002;

# define dsGetStepSize(rtm)            (dsStepSize)

static void rti_mdl_initialize_host_services(void)
{
  DsDaq_Init(0, 32, 1);
}

static void rti_mdl_initialize_io_boards(void)
{
  /* Registering of RTI products and modules at VCM */
  {
    vcm_module_register(VCM_MID_RTI1202, (void *) 0,
                        VCM_TXT_RTI1202, 7, 9, 0,
                        VCM_VERSION_RELEASE, 0, 0, 0, VCM_CTRL_NO_ST);

    {
      vcm_module_descriptor_type* msg_mod_ptr;
      msg_mod_ptr = vcm_module_register(VCM_MID_MATLAB, (void *) 0,
        VCM_TXT_MATLAB, 9, 3, 0,
        VCM_VERSION_RELEASE, 0, 0, 0, VCM_CTRL_NO_ST);
      vcm_module_register(VCM_MID_SIMULINK, msg_mod_ptr,
                          VCM_TXT_SIMULINK, 9, 0, 0,
                          VCM_VERSION_RELEASE, 0, 0, 0, VCM_CTRL_NO_ST);
      vcm_module_register(VCM_MID_RTW, msg_mod_ptr,
                          VCM_TXT_RTW, 8, 13, 0,
                          VCM_VERSION_RELEASE, 0, 0, 0, VCM_CTRL_NO_ST);
      vcm_module_register(VCM_MID_STATEFLOW, msg_mod_ptr,
                          VCM_TXT_STATEFLOW, 9, 0, 0,
                          VCM_VERSION_RELEASE, 0, 0, 0, VCM_CTRL_NO_ST);
      vcm_module_register(VCM_MID_STATEFLOW_CODER, msg_mod_ptr,
                          VCM_TXT_STATEFLOW_CODER, 8, 13, 0,
                          VCM_VERSION_RELEASE, 0, 0, 0, VCM_CTRL_NO_ST);
    }

    vcm_module_register(VCM_MID_RTICAN, (void *) 0,
                        VCM_TXT_RTICAN, 3, 4, 5,
                        VCM_VERSION_RELEASE, 0, 0, 0, VCM_CTRL_NO_ST);
  }

  /* --- Bilateral_Ankle_Exo/Control Module/Motor_L/DAC_CLASS1_BL1 --- */
  /* --- [RTI120X, DAC C1] - Channel: 16 --- */
  {
    /* define a variable for IO error handling */
    UInt32 ioErrorCode = IOLIB_NO_ERROR;

    /* Init DAC CL1 AnalogOut driver object pRTIDacC1AnalogOut_Ch_16 */
    ioErrorCode = DacCl1AnalogOut_create(&pRTIDacC1AnalogOut_Ch_16,
      DAC_CLASS1_MASK_CH_16);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    /* Apply all parameter settings. Finalize the construction of the AnalogOut driver object */
    ioErrorCode = DacCl1AnalogOut_apply(pRTIDacC1AnalogOut_Ch_16);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }
  }

  /* --- Bilateral_Ankle_Exo/Control Module/Motor_R/DAC_CLASS1_BL1 --- */
  /* --- [RTI120X, DAC C1] - Channel: 15 --- */
  {
    /* define a variable for IO error handling */
    UInt32 ioErrorCode = IOLIB_NO_ERROR;

    /* Init DAC CL1 AnalogOut driver object pRTIDacC1AnalogOut_Ch_15 */
    ioErrorCode = DacCl1AnalogOut_create(&pRTIDacC1AnalogOut_Ch_15,
      DAC_CLASS1_MASK_CH_15);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    /* Apply all parameter settings. Finalize the construction of the AnalogOut driver object */
    ioErrorCode = DacCl1AnalogOut_apply(pRTIDacC1AnalogOut_Ch_15);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }
  }

  /* --- Bilateral_Ankle_Exo/Sensor Data/Ankle Encoder/EMC_ENCODER_BL1 --- */
  /* --- [RTIEMC, Encoder] - DIO class: 2 - Unit: 5 - Port: 1 - Channel: 10 --- */
  {
    /* define a variable for IO error handling */
    UInt32 ioErrorRetValue = IOLIB_NO_ERROR;

    /* Create EMC Encoder driver object pRTIEmcEncoder_Unit_5_DioCl_2_Port_1_Ch10 */
    ioErrorRetValue = DioCl2EncoderIn_create
      (&pRTIEmcEncoder_Unit_5_DioCl_2_Port_1_Ch10, DIO_CLASS2_CHANNEL_10,
       DIO_ENC_INSTANCE_5,DIO_ENC_IUSAGE_ENABLED);
    if (ioErrorRetValue > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    /* -- Position measurement enabled -- */

    /* Sets number of encoder lines for the selected incremental Encoder */
    ioErrorRetValue = DioCl2EncoderIn_setEncoderLines
      (pRTIEmcEncoder_Unit_5_DioCl_2_Port_1_Ch10, (UInt32) 250000.0);
    if (ioErrorRetValue > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    /* Sets minimum position for the selected incremental Encoder (in lines) */
    ioErrorRetValue = DioCl2EncoderIn_setMinPosition
      (pRTIEmcEncoder_Unit_5_DioCl_2_Port_1_Ch10, (Float64) -125000);
    if (ioErrorRetValue > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    /* Sets maximum position for the selected incremental Encoder (in lines) */
    ioErrorRetValue = DioCl2EncoderIn_setMaxPosition
      (pRTIEmcEncoder_Unit_5_DioCl_2_Port_1_Ch10, (Float64) 125000);
    if (ioErrorRetValue > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    /* Sets index signal usage mode for the selected incremental Encoder */
    ioErrorRetValue = DioCl2EncoderIn_setIndexMode
      (pRTIEmcEncoder_Unit_5_DioCl_2_Port_1_Ch10, (Float64)
       DIO_ENC_IMODE_EVERY_INDEX);
    if (ioErrorRetValue > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    /* Sets index position for the selected incremental Encoder on index signal detection (in lines) */
    ioErrorRetValue = DioCl2EncoderIn_setIndexPosition
      (pRTIEmcEncoder_Unit_5_DioCl_2_Port_1_Ch10, (Float64) 0);
    if (ioErrorRetValue > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    /* specify the minimum encoder velocity (in lines per second) */
    ioErrorRetValue = DioCl2EncoderIn_setMinEncVelocity
      (pRTIEmcEncoder_Unit_5_DioCl_2_Port_1_Ch10, (Float64) 1);
    if (ioErrorRetValue > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    /* Sets gated mode for the selected incremental Encoder */
    ioErrorRetValue = DioCl2EncoderIn_setGatedMode
      (pRTIEmcEncoder_Unit_5_DioCl_2_Port_1_Ch10, DIO_ENC_IUSAGE_ENABLED);
    if (ioErrorRetValue > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorRetValue = DioCl2EncoderIn_setMeasurementInterval
      (pRTIEmcEncoder_Unit_5_DioCl_2_Port_1_Ch10, 1);
    if (ioErrorRetValue > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    /* Apply all parameter settings. Finalize the construction of the Encoder Obj driver object */
    ioErrorRetValue = DioCl2EncoderIn_apply
      (pRTIEmcEncoder_Unit_5_DioCl_2_Port_1_Ch10);
    if (ioErrorRetValue > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }
  }

  /* --- Bilateral_Ankle_Exo/Sensor Data/Motor Encoder/EMC_ENCODER_BL2 --- */
  /* --- [RTIEMC, Encoder] - DIO class: 2 - Unit: 2 - Port: 1 - Channel: 3 --- */
  {
    /* define a variable for IO error handling */
    UInt32 ioErrorRetValue = IOLIB_NO_ERROR;

    /* Create EMC Encoder driver object pRTIEmcEncoder_Unit_2_DioCl_2_Port_1_Ch3 */
    ioErrorRetValue = DioCl2EncoderIn_create
      (&pRTIEmcEncoder_Unit_2_DioCl_2_Port_1_Ch3, DIO_CLASS2_CHANNEL_3,
       DIO_ENC_INSTANCE_2,DIO_ENC_IUSAGE_DISABLED);
    if (ioErrorRetValue > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    /* -- Position measurement enabled -- */

    /* Sets number of encoder lines for the selected incremental Encoder */
    ioErrorRetValue = DioCl2EncoderIn_setEncoderLines
      (pRTIEmcEncoder_Unit_2_DioCl_2_Port_1_Ch3, (UInt32) 250000.0);
    if (ioErrorRetValue > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    /* Sets minimum position for the selected incremental Encoder (in lines) */
    ioErrorRetValue = DioCl2EncoderIn_setMinPosition
      (pRTIEmcEncoder_Unit_2_DioCl_2_Port_1_Ch3, (Float64) -125000);
    if (ioErrorRetValue > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    /* Sets maximum position for the selected incremental Encoder (in lines) */
    ioErrorRetValue = DioCl2EncoderIn_setMaxPosition
      (pRTIEmcEncoder_Unit_2_DioCl_2_Port_1_Ch3, (Float64) 125000);
    if (ioErrorRetValue > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    /* Sets index signal usage mode for the selected incremental Encoder */
    ioErrorRetValue = DioCl2EncoderIn_setIndexMode
      (pRTIEmcEncoder_Unit_2_DioCl_2_Port_1_Ch3, (Float64)
       DIO_ENC_IMODE_DISABLED);
    if (ioErrorRetValue > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    /* specify the minimum encoder velocity (in lines per second) */
    ioErrorRetValue = DioCl2EncoderIn_setMinEncVelocity
      (pRTIEmcEncoder_Unit_2_DioCl_2_Port_1_Ch3, (Float64) 1);
    if (ioErrorRetValue > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    /* Sets gated mode for the selected incremental Encoder */
    ioErrorRetValue = DioCl2EncoderIn_setGatedMode
      (pRTIEmcEncoder_Unit_2_DioCl_2_Port_1_Ch3, DIO_ENC_IUSAGE_ENABLED);
    if (ioErrorRetValue > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorRetValue = DioCl2EncoderIn_setMeasurementInterval
      (pRTIEmcEncoder_Unit_2_DioCl_2_Port_1_Ch3, 1);
    if (ioErrorRetValue > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    /* Apply all parameter settings. Finalize the construction of the Encoder Obj driver object */
    ioErrorRetValue = DioCl2EncoderIn_apply
      (pRTIEmcEncoder_Unit_2_DioCl_2_Port_1_Ch3);
    if (ioErrorRetValue > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }
  }

  /* --- Bilateral_Ankle_Exo/Sensor Data/FootSwitch module/DIO_CLASS1_BIT_IN_BL1 --- */
  /* --- [RTI120X, BITIN] - Port: 1 - Channel: 2 --- */
  {
    /* define a variable for IO error handling */
    UInt32 ioErrorCode = IOLIB_NO_ERROR;

    /* Init DIO CL1 DigIn driver object pRTIDioC1DigIn_Port_1_Ch_2 */
    ioErrorCode = DioCl1DigIn_create(&pRTIDioC1DigIn_Port_1_Ch_2,
      DIO_CLASS1_PORT_1, DIO_CLASS1_MASK_CH_2);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = DioCl1DigIn_setInputFilter(pRTIDioC1DigIn_Port_1_Ch_2, 0);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = DioCl1DigIn_apply(pRTIDioC1DigIn_Port_1_Ch_2);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = DioCl1DigIn_start(pRTIDioC1DigIn_Port_1_Ch_2);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }
  }

  /* --- Bilateral_Ankle_Exo/Sensor Data/FootSwitch module/DIO_CLASS1_BIT_IN_BL2 --- */
  /* --- [RTI120X, BITIN] - Port: 1 - Channel: 4 --- */
  {
    /* define a variable for IO error handling */
    UInt32 ioErrorCode = IOLIB_NO_ERROR;

    /* Init DIO CL1 DigIn driver object pRTIDioC1DigIn_Port_1_Ch_4 */
    ioErrorCode = DioCl1DigIn_create(&pRTIDioC1DigIn_Port_1_Ch_4,
      DIO_CLASS1_PORT_1, DIO_CLASS1_MASK_CH_4);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = DioCl1DigIn_setInputFilter(pRTIDioC1DigIn_Port_1_Ch_4, 0);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = DioCl1DigIn_apply(pRTIDioC1DigIn_Port_1_Ch_4);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = DioCl1DigIn_start(pRTIDioC1DigIn_Port_1_Ch_4);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }
  }

  /* --- Bilateral_Ankle_Exo/Sensor Data/Ankle Encoder/EMC_ENCODER_BL2 --- */
  /* --- [RTIEMC, Encoder] - DIO class: 2 - Unit: 4 - Port: 1 - Channel: 7 --- */
  {
    /* define a variable for IO error handling */
    UInt32 ioErrorRetValue = IOLIB_NO_ERROR;

    /* Create EMC Encoder driver object pRTIEmcEncoder_Unit_4_DioCl_2_Port_1_Ch7 */
    ioErrorRetValue = DioCl2EncoderIn_create
      (&pRTIEmcEncoder_Unit_4_DioCl_2_Port_1_Ch7, DIO_CLASS2_CHANNEL_7,
       DIO_ENC_INSTANCE_4,DIO_ENC_IUSAGE_ENABLED);
    if (ioErrorRetValue > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    /* -- Position measurement enabled -- */

    /* Sets number of encoder lines for the selected incremental Encoder */
    ioErrorRetValue = DioCl2EncoderIn_setEncoderLines
      (pRTIEmcEncoder_Unit_4_DioCl_2_Port_1_Ch7, (UInt32) 250000.0);
    if (ioErrorRetValue > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    /* Sets minimum position for the selected incremental Encoder (in lines) */
    ioErrorRetValue = DioCl2EncoderIn_setMinPosition
      (pRTIEmcEncoder_Unit_4_DioCl_2_Port_1_Ch7, (Float64) -125000);
    if (ioErrorRetValue > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    /* Sets maximum position for the selected incremental Encoder (in lines) */
    ioErrorRetValue = DioCl2EncoderIn_setMaxPosition
      (pRTIEmcEncoder_Unit_4_DioCl_2_Port_1_Ch7, (Float64) 125000);
    if (ioErrorRetValue > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    /* Sets index signal usage mode for the selected incremental Encoder */
    ioErrorRetValue = DioCl2EncoderIn_setIndexMode
      (pRTIEmcEncoder_Unit_4_DioCl_2_Port_1_Ch7, (Float64)
       DIO_ENC_IMODE_EVERY_INDEX);
    if (ioErrorRetValue > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    /* Sets index position for the selected incremental Encoder on index signal detection (in lines) */
    ioErrorRetValue = DioCl2EncoderIn_setIndexPosition
      (pRTIEmcEncoder_Unit_4_DioCl_2_Port_1_Ch7, (Float64) 0);
    if (ioErrorRetValue > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    /* specify the minimum encoder velocity (in lines per second) */
    ioErrorRetValue = DioCl2EncoderIn_setMinEncVelocity
      (pRTIEmcEncoder_Unit_4_DioCl_2_Port_1_Ch7, (Float64) 1);
    if (ioErrorRetValue > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    /* Sets gated mode for the selected incremental Encoder */
    ioErrorRetValue = DioCl2EncoderIn_setGatedMode
      (pRTIEmcEncoder_Unit_4_DioCl_2_Port_1_Ch7, DIO_ENC_IUSAGE_ENABLED);
    if (ioErrorRetValue > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorRetValue = DioCl2EncoderIn_setMeasurementInterval
      (pRTIEmcEncoder_Unit_4_DioCl_2_Port_1_Ch7, 1);
    if (ioErrorRetValue > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    /* Apply all parameter settings. Finalize the construction of the Encoder Obj driver object */
    ioErrorRetValue = DioCl2EncoderIn_apply
      (pRTIEmcEncoder_Unit_4_DioCl_2_Port_1_Ch7);
    if (ioErrorRetValue > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }
  }

  /* --- Bilateral_Ankle_Exo/Sensor Data/Motor Encoder/EMC_ENCODER_BL3 --- */
  /* --- [RTIEMC, Encoder] - DIO class: 2 - Unit: 3 - Port: 1 - Channel: 5 --- */
  {
    /* define a variable for IO error handling */
    UInt32 ioErrorRetValue = IOLIB_NO_ERROR;

    /* Create EMC Encoder driver object pRTIEmcEncoder_Unit_3_DioCl_2_Port_1_Ch5 */
    ioErrorRetValue = DioCl2EncoderIn_create
      (&pRTIEmcEncoder_Unit_3_DioCl_2_Port_1_Ch5, DIO_CLASS2_CHANNEL_5,
       DIO_ENC_INSTANCE_3,DIO_ENC_IUSAGE_DISABLED);
    if (ioErrorRetValue > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    /* -- Position measurement enabled -- */

    /* Sets number of encoder lines for the selected incremental Encoder */
    ioErrorRetValue = DioCl2EncoderIn_setEncoderLines
      (pRTIEmcEncoder_Unit_3_DioCl_2_Port_1_Ch5, (UInt32) 250000.0);
    if (ioErrorRetValue > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    /* Sets minimum position for the selected incremental Encoder (in lines) */
    ioErrorRetValue = DioCl2EncoderIn_setMinPosition
      (pRTIEmcEncoder_Unit_3_DioCl_2_Port_1_Ch5, (Float64) -125000);
    if (ioErrorRetValue > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    /* Sets maximum position for the selected incremental Encoder (in lines) */
    ioErrorRetValue = DioCl2EncoderIn_setMaxPosition
      (pRTIEmcEncoder_Unit_3_DioCl_2_Port_1_Ch5, (Float64) 125000);
    if (ioErrorRetValue > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    /* Sets index signal usage mode for the selected incremental Encoder */
    ioErrorRetValue = DioCl2EncoderIn_setIndexMode
      (pRTIEmcEncoder_Unit_3_DioCl_2_Port_1_Ch5, (Float64)
       DIO_ENC_IMODE_DISABLED);
    if (ioErrorRetValue > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    /* specify the minimum encoder velocity (in lines per second) */
    ioErrorRetValue = DioCl2EncoderIn_setMinEncVelocity
      (pRTIEmcEncoder_Unit_3_DioCl_2_Port_1_Ch5, (Float64) 1);
    if (ioErrorRetValue > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    /* Sets gated mode for the selected incremental Encoder */
    ioErrorRetValue = DioCl2EncoderIn_setGatedMode
      (pRTIEmcEncoder_Unit_3_DioCl_2_Port_1_Ch5, DIO_ENC_IUSAGE_ENABLED);
    if (ioErrorRetValue > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorRetValue = DioCl2EncoderIn_setMeasurementInterval
      (pRTIEmcEncoder_Unit_3_DioCl_2_Port_1_Ch5, 1);
    if (ioErrorRetValue > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    /* Apply all parameter settings. Finalize the construction of the Encoder Obj driver object */
    ioErrorRetValue = DioCl2EncoderIn_apply
      (pRTIEmcEncoder_Unit_3_DioCl_2_Port_1_Ch5);
    if (ioErrorRetValue > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }
  }

  /* --- Bilateral_Ankle_Exo/Sensor Data/Torque module/DS1202_SENSOR_SUPPLY --- */
  /* --- [RTI120X, Sensor Supply] --- */
  {
    /* define a variable for IO error handling */
    UInt32 ioErrorCode = IOLIB_NO_ERROR;

    /* Init Sensor Supply driver object pRTI_Sensor_Supply */
    ioErrorCode = SensorSupply_create(&pRTI_Sensor_Supply, SENSOR_SUPPLY_NO_2);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = SensorSupply_setVoltage(pRTI_Sensor_Supply, 20);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = SensorSupply_setSensorState(pRTI_Sensor_Supply,
      SENSOR_STATE_ENABLE);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = SensorSupply_apply(pRTI_Sensor_Supply);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = SensorSupply_start(pRTI_Sensor_Supply);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }
  }

  /* --- Bilateral_Ankle_Exo/Sensor Data/Ankle Encoder/Encoder Power Setup1 --- */
  /* --- [RTI120X, BITOUT] - Port: 3 - Channel: 15 --- */
  {
    /* define a variable for IO error handling */
    UInt32 ioErrorCode = IOLIB_NO_ERROR;

    /* define variables required for BitOut initial functions */
    UInt32 outputDataInit = 0;

    /* Init DIO CL1 DigOut driver object pRTIDioC1DigOut_Port_3_Ch_15 */
    ioErrorCode = DioCl1DigOut_create(&pRTIDioC1DigOut_Port_3_Ch_15,
      DIO_CLASS1_PORT_3, DIO_CLASS1_MASK_CH_15);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = DioCl1DigOut_setSignalVoltage(pRTIDioC1DigOut_Port_3_Ch_15,
      DIO_CLASS1_SIGNAL_5_0_V);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    outputDataInit = ( ( ( (UInt32)0) << (15 - 1)) | outputDataInit);

    /* write initialization value to digital output channel 15-15 on port 3 */
    ioErrorCode = DioCl1DigOut_setChMaskOutData(pRTIDioC1DigOut_Port_3_Ch_15,
      outputDataInit);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = DioCl1DigOut_apply(pRTIDioC1DigOut_Port_3_Ch_15);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = DioCl1DigOut_start(pRTIDioC1DigOut_Port_3_Ch_15);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }
  }

  /* --- Bilateral_Ankle_Exo/Sensor Data/Ankle Encoder/Encoder Power Setup2 --- */
  /* --- [RTI120X, BITOUT] - Port: 3 - Channel: 16 --- */
  {
    /* define a variable for IO error handling */
    UInt32 ioErrorCode = IOLIB_NO_ERROR;

    /* define variables required for BitOut initial functions */
    UInt32 outputDataInit = 0;

    /* Init DIO CL1 DigOut driver object pRTIDioC1DigOut_Port_3_Ch_16 */
    ioErrorCode = DioCl1DigOut_create(&pRTIDioC1DigOut_Port_3_Ch_16,
      DIO_CLASS1_PORT_3, DIO_CLASS1_MASK_CH_16);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = DioCl1DigOut_setSignalVoltage(pRTIDioC1DigOut_Port_3_Ch_16,
      DIO_CLASS1_SIGNAL_5_0_V);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    outputDataInit = ( ( ( (UInt32)0) << (16 - 1)) | outputDataInit);

    /* write initialization value to digital output channel 16-16 on port 3 */
    ioErrorCode = DioCl1DigOut_setChMaskOutData(pRTIDioC1DigOut_Port_3_Ch_16,
      outputDataInit);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = DioCl1DigOut_apply(pRTIDioC1DigOut_Port_3_Ch_16);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = DioCl1DigOut_start(pRTIDioC1DigOut_Port_3_Ch_16);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }
  }

  /* --- Bilateral_Ankle_Exo/Sensor Data/Motor Encoder/Encoder Power Setup2 --- */
  /* --- [RTI120X, BITOUT] - Port: 3 - Channel: 12 --- */
  {
    /* define a variable for IO error handling */
    UInt32 ioErrorCode = IOLIB_NO_ERROR;

    /* define variables required for BitOut initial functions */
    UInt32 outputDataInit = 0;

    /* Init DIO CL1 DigOut driver object pRTIDioC1DigOut_Port_3_Ch_12 */
    ioErrorCode = DioCl1DigOut_create(&pRTIDioC1DigOut_Port_3_Ch_12,
      DIO_CLASS1_PORT_3, DIO_CLASS1_MASK_CH_12);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = DioCl1DigOut_setSignalVoltage(pRTIDioC1DigOut_Port_3_Ch_12,
      DIO_CLASS1_SIGNAL_5_0_V);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    outputDataInit = ( ( ( (UInt32)0) << (12 - 1)) | outputDataInit);

    /* write initialization value to digital output channel 12-12 on port 3 */
    ioErrorCode = DioCl1DigOut_setChMaskOutData(pRTIDioC1DigOut_Port_3_Ch_12,
      outputDataInit);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = DioCl1DigOut_apply(pRTIDioC1DigOut_Port_3_Ch_12);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = DioCl1DigOut_start(pRTIDioC1DigOut_Port_3_Ch_12);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }
  }

  /* --- Bilateral_Ankle_Exo/Sensor Data/Motor Encoder/Encoder Power Setup3 --- */
  /* --- [RTI120X, BITOUT] - Port: 3 - Channel: 13 --- */
  {
    /* define a variable for IO error handling */
    UInt32 ioErrorCode = IOLIB_NO_ERROR;

    /* define variables required for BitOut initial functions */
    UInt32 outputDataInit = 0;

    /* Init DIO CL1 DigOut driver object pRTIDioC1DigOut_Port_3_Ch_13 */
    ioErrorCode = DioCl1DigOut_create(&pRTIDioC1DigOut_Port_3_Ch_13,
      DIO_CLASS1_PORT_3, DIO_CLASS1_MASK_CH_13);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = DioCl1DigOut_setSignalVoltage(pRTIDioC1DigOut_Port_3_Ch_13,
      DIO_CLASS1_SIGNAL_5_0_V);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    outputDataInit = ( ( ( (UInt32)0) << (13 - 1)) | outputDataInit);

    /* write initialization value to digital output channel 13-13 on port 3 */
    ioErrorCode = DioCl1DigOut_setChMaskOutData(pRTIDioC1DigOut_Port_3_Ch_13,
      outputDataInit);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = DioCl1DigOut_apply(pRTIDioC1DigOut_Port_3_Ch_13);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = DioCl1DigOut_start(pRTIDioC1DigOut_Port_3_Ch_13);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }
  }

  /* --- Bilateral_Ankle_Exo/Sensor Data/FootSwitch module/DIO_CLASS1_BIT_OUT_BL1 --- */
  /* --- [RTI120X, BITOUT] - Port: 1 - Channel: 1 --- */
  {
    /* define a variable for IO error handling */
    UInt32 ioErrorCode = IOLIB_NO_ERROR;

    /* define variables required for BitOut initial functions */
    UInt32 outputDataInit = 0;

    /* Init DIO CL1 DigOut driver object pRTIDioC1DigOut_Port_1_Ch_1 */
    ioErrorCode = DioCl1DigOut_create(&pRTIDioC1DigOut_Port_1_Ch_1,
      DIO_CLASS1_PORT_1, DIO_CLASS1_MASK_CH_1);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = DioCl1DigOut_setSignalVoltage(pRTIDioC1DigOut_Port_1_Ch_1,
      DIO_CLASS1_SIGNAL_5_0_V);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    outputDataInit = ( ( ( (UInt32)0) << (1 - 1)) | outputDataInit);

    /* write initialization value to digital output channel 1-1 on port 1 */
    ioErrorCode = DioCl1DigOut_setChMaskOutData(pRTIDioC1DigOut_Port_1_Ch_1,
      outputDataInit);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = DioCl1DigOut_apply(pRTIDioC1DigOut_Port_1_Ch_1);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = DioCl1DigOut_start(pRTIDioC1DigOut_Port_1_Ch_1);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }
  }

  /* --- Bilateral_Ankle_Exo/Sensor Data/FootSwitch module/DIO_CLASS1_BIT_OUT_BL2 --- */
  /* --- [RTI120X, BITOUT] - Port: 1 - Channel: 3 --- */
  {
    /* define a variable for IO error handling */
    UInt32 ioErrorCode = IOLIB_NO_ERROR;

    /* define variables required for BitOut initial functions */
    UInt32 outputDataInit = 0;

    /* Init DIO CL1 DigOut driver object pRTIDioC1DigOut_Port_1_Ch_3 */
    ioErrorCode = DioCl1DigOut_create(&pRTIDioC1DigOut_Port_1_Ch_3,
      DIO_CLASS1_PORT_1, DIO_CLASS1_MASK_CH_3);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = DioCl1DigOut_setSignalVoltage(pRTIDioC1DigOut_Port_1_Ch_3,
      DIO_CLASS1_SIGNAL_5_0_V);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    outputDataInit = ( ( ( (UInt32)0) << (3 - 1)) | outputDataInit);

    /* write initialization value to digital output channel 3-3 on port 1 */
    ioErrorCode = DioCl1DigOut_setChMaskOutData(pRTIDioC1DigOut_Port_1_Ch_3,
      outputDataInit);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = DioCl1DigOut_apply(pRTIDioC1DigOut_Port_1_Ch_3);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = DioCl1DigOut_start(pRTIDioC1DigOut_Port_1_Ch_3);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }
  }

  /* dSPACE I/O Board DS120XSTDADCC1 #0 */
  /* --- Bilateral_Ankle_Exo/Sensor Data/Torque module/ADC_CLASS1_BL6 --- */
  /* --- [RTI120X, ADC C1] - Channel: 6 --- */
  {
    /* define a variable for IO error handling */
    UInt32 ioErrorCode = IOLIB_NO_ERROR;

    /* Init ADC CL1 AnalogIn driver object pRTIAdcC1AnalogIn_Ch_6 */
    ioErrorCode = AdcCl1AnalogIn_create(&pRTIAdcC1AnalogIn_Ch_6,
      ADC_CLASS1_CHANNEL_6);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    /* Set parameters for ADC CL1 AnalogIn driver object pRTIAdcC1AnalogIn_Ch_6 */
    ioErrorCode = AdcCl1AnalogIn_setConversionMode(pRTIAdcC1AnalogIn_Ch_6,
      ADC_CLASS1_SINGLE_CONV_MODE);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = AdcCl1AnalogIn_setConversTrigger(pRTIAdcC1AnalogIn_Ch_6,
      ADC_CLASS1_TRIGGER_SW);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }
  }

  /* --- Bilateral_Ankle_Exo/Sensor Data/Torque module/ADC_CLASS1_BL1 --- */
  /* --- [RTI120X, ADC C1] - Channel: 7 --- */
  {
    /* define a variable for IO error handling */
    UInt32 ioErrorCode = IOLIB_NO_ERROR;

    /* Init ADC CL1 AnalogIn driver object pRTIAdcC1AnalogIn_Ch_7 */
    ioErrorCode = AdcCl1AnalogIn_create(&pRTIAdcC1AnalogIn_Ch_7,
      ADC_CLASS1_CHANNEL_7);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    /* Set parameters for ADC CL1 AnalogIn driver object pRTIAdcC1AnalogIn_Ch_7 */
    ioErrorCode = AdcCl1AnalogIn_setConversionMode(pRTIAdcC1AnalogIn_Ch_7,
      ADC_CLASS1_SINGLE_CONV_MODE);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = AdcCl1AnalogIn_setConversTrigger(pRTIAdcC1AnalogIn_Ch_7,
      ADC_CLASS1_TRIGGER_SW);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }
  }

  /* --- Bilateral_Ankle_Exo/Sensor Data/EMG module/ADC_CLASS1_BL1 --- */
  /* --- [RTI120X, ADC C1] - Channel: 1 --- */
  {
    /* define a variable for IO error handling */
    UInt32 ioErrorCode = IOLIB_NO_ERROR;

    /* Init ADC CL1 AnalogIn driver object pRTIAdcC1AnalogIn_Ch_1 */
    ioErrorCode = AdcCl1AnalogIn_create(&pRTIAdcC1AnalogIn_Ch_1,
      ADC_CLASS1_CHANNEL_1);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    /* Set parameters for ADC CL1 AnalogIn driver object pRTIAdcC1AnalogIn_Ch_1 */
    ioErrorCode = AdcCl1AnalogIn_setConversionMode(pRTIAdcC1AnalogIn_Ch_1,
      ADC_CLASS1_SINGLE_CONV_MODE);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = AdcCl1AnalogIn_setConversTrigger(pRTIAdcC1AnalogIn_Ch_1,
      ADC_CLASS1_TRIGGER_SW);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }
  }

  /* --- Bilateral_Ankle_Exo/Sensor Data/EMG module/ADC_CLASS1_BL10 --- */
  /* --- [RTI120X, ADC C1] - Channel: 10 --- */
  {
    /* define a variable for IO error handling */
    UInt32 ioErrorCode = IOLIB_NO_ERROR;

    /* Init ADC CL1 AnalogIn driver object pRTIAdcC1AnalogIn_Ch_10 */
    ioErrorCode = AdcCl1AnalogIn_create(&pRTIAdcC1AnalogIn_Ch_10,
      ADC_CLASS1_CHANNEL_10);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    /* Set parameters for ADC CL1 AnalogIn driver object pRTIAdcC1AnalogIn_Ch_10 */
    ioErrorCode = AdcCl1AnalogIn_setConversionMode(pRTIAdcC1AnalogIn_Ch_10,
      ADC_CLASS1_SINGLE_CONV_MODE);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = AdcCl1AnalogIn_setConversTrigger(pRTIAdcC1AnalogIn_Ch_10,
      ADC_CLASS1_TRIGGER_SW);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }
  }

  /* --- Bilateral_Ankle_Exo/Sensor Data/EMG module/ADC_CLASS1_BL11 --- */
  /* --- [RTI120X, ADC C1] - Channel: 11 --- */
  {
    /* define a variable for IO error handling */
    UInt32 ioErrorCode = IOLIB_NO_ERROR;

    /* Init ADC CL1 AnalogIn driver object pRTIAdcC1AnalogIn_Ch_11 */
    ioErrorCode = AdcCl1AnalogIn_create(&pRTIAdcC1AnalogIn_Ch_11,
      ADC_CLASS1_CHANNEL_11);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    /* Set parameters for ADC CL1 AnalogIn driver object pRTIAdcC1AnalogIn_Ch_11 */
    ioErrorCode = AdcCl1AnalogIn_setConversionMode(pRTIAdcC1AnalogIn_Ch_11,
      ADC_CLASS1_SINGLE_CONV_MODE);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = AdcCl1AnalogIn_setConversTrigger(pRTIAdcC1AnalogIn_Ch_11,
      ADC_CLASS1_TRIGGER_SW);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }
  }

  /* --- Bilateral_Ankle_Exo/Sensor Data/EMG module/ADC_CLASS1_BL12 --- */
  /* --- [RTI120X, ADC C1] - Channel: 12 --- */
  {
    /* define a variable for IO error handling */
    UInt32 ioErrorCode = IOLIB_NO_ERROR;

    /* Init ADC CL1 AnalogIn driver object pRTIAdcC1AnalogIn_Ch_12 */
    ioErrorCode = AdcCl1AnalogIn_create(&pRTIAdcC1AnalogIn_Ch_12,
      ADC_CLASS1_CHANNEL_12);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    /* Set parameters for ADC CL1 AnalogIn driver object pRTIAdcC1AnalogIn_Ch_12 */
    ioErrorCode = AdcCl1AnalogIn_setConversionMode(pRTIAdcC1AnalogIn_Ch_12,
      ADC_CLASS1_SINGLE_CONV_MODE);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = AdcCl1AnalogIn_setConversTrigger(pRTIAdcC1AnalogIn_Ch_12,
      ADC_CLASS1_TRIGGER_SW);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }
  }

  /* --- Bilateral_Ankle_Exo/Sensor Data/EMG module/ADC_CLASS1_BL2 --- */
  /* --- [RTI120X, ADC C1] - Channel: 2 --- */
  {
    /* define a variable for IO error handling */
    UInt32 ioErrorCode = IOLIB_NO_ERROR;

    /* Init ADC CL1 AnalogIn driver object pRTIAdcC1AnalogIn_Ch_2 */
    ioErrorCode = AdcCl1AnalogIn_create(&pRTIAdcC1AnalogIn_Ch_2,
      ADC_CLASS1_CHANNEL_2);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    /* Set parameters for ADC CL1 AnalogIn driver object pRTIAdcC1AnalogIn_Ch_2 */
    ioErrorCode = AdcCl1AnalogIn_setConversionMode(pRTIAdcC1AnalogIn_Ch_2,
      ADC_CLASS1_SINGLE_CONV_MODE);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = AdcCl1AnalogIn_setConversTrigger(pRTIAdcC1AnalogIn_Ch_2,
      ADC_CLASS1_TRIGGER_SW);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }
  }

  /* --- Bilateral_Ankle_Exo/Sensor Data/EMG module/ADC_CLASS1_BL3 --- */
  /* --- [RTI120X, ADC C1] - Channel: 3 --- */
  {
    /* define a variable for IO error handling */
    UInt32 ioErrorCode = IOLIB_NO_ERROR;

    /* Init ADC CL1 AnalogIn driver object pRTIAdcC1AnalogIn_Ch_3 */
    ioErrorCode = AdcCl1AnalogIn_create(&pRTIAdcC1AnalogIn_Ch_3,
      ADC_CLASS1_CHANNEL_3);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    /* Set parameters for ADC CL1 AnalogIn driver object pRTIAdcC1AnalogIn_Ch_3 */
    ioErrorCode = AdcCl1AnalogIn_setConversionMode(pRTIAdcC1AnalogIn_Ch_3,
      ADC_CLASS1_SINGLE_CONV_MODE);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = AdcCl1AnalogIn_setConversTrigger(pRTIAdcC1AnalogIn_Ch_3,
      ADC_CLASS1_TRIGGER_SW);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }
  }

  /* --- Bilateral_Ankle_Exo/Sensor Data/EMG module/ADC_CLASS1_BL4 --- */
  /* --- [RTI120X, ADC C1] - Channel: 4 --- */
  {
    /* define a variable for IO error handling */
    UInt32 ioErrorCode = IOLIB_NO_ERROR;

    /* Init ADC CL1 AnalogIn driver object pRTIAdcC1AnalogIn_Ch_4 */
    ioErrorCode = AdcCl1AnalogIn_create(&pRTIAdcC1AnalogIn_Ch_4,
      ADC_CLASS1_CHANNEL_4);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    /* Set parameters for ADC CL1 AnalogIn driver object pRTIAdcC1AnalogIn_Ch_4 */
    ioErrorCode = AdcCl1AnalogIn_setConversionMode(pRTIAdcC1AnalogIn_Ch_4,
      ADC_CLASS1_SINGLE_CONV_MODE);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = AdcCl1AnalogIn_setConversTrigger(pRTIAdcC1AnalogIn_Ch_4,
      ADC_CLASS1_TRIGGER_SW);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }
  }

  /* --- Bilateral_Ankle_Exo/Sensor Data/EMG module/ADC_CLASS1_BL9 --- */
  /* --- [RTI120X, ADC C1] - Channel: 9 --- */
  {
    /* define a variable for IO error handling */
    UInt32 ioErrorCode = IOLIB_NO_ERROR;

    /* Init ADC CL1 AnalogIn driver object pRTIAdcC1AnalogIn_Ch_9 */
    ioErrorCode = AdcCl1AnalogIn_create(&pRTIAdcC1AnalogIn_Ch_9,
      ADC_CLASS1_CHANNEL_9);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    /* Set parameters for ADC CL1 AnalogIn driver object pRTIAdcC1AnalogIn_Ch_9 */
    ioErrorCode = AdcCl1AnalogIn_setConversionMode(pRTIAdcC1AnalogIn_Ch_9,
      ADC_CLASS1_SINGLE_CONV_MODE);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = AdcCl1AnalogIn_setConversTrigger(pRTIAdcC1AnalogIn_Ch_9,
      ADC_CLASS1_TRIGGER_SW);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }
  }

  /* dSPACE I/O Board DS120XSTDADCC1 #0 Unit:ADCC1 */

  /* dSPACE I/O Board DS120XSTDADCC1 #0 Unit:ADCC1 Group:ADC */
  /* --- Bilateral_Ankle_Exo/Sensor Data/Torque module/ADC_CLASS1_BL6 --- */
  /* --- [RTI120X, ADC C1] - Channel: 6 --- */
  {
    /* define a variable for IO error handling */
    UInt32 ioErrorCode = IOLIB_NO_ERROR;

    /* Apply- and Start-Fcn for pRTIAdcC1AnalogIn_Ch_6 */
    ioErrorCode = AdcCl1AnalogIn_apply(pRTIAdcC1AnalogIn_Ch_6);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = AdcCl1AnalogIn_start(pRTIAdcC1AnalogIn_Ch_6);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }
  }

  /* --- Bilateral_Ankle_Exo/Sensor Data/Torque module/ADC_CLASS1_BL1 --- */
  /* --- [RTI120X, ADC C1] - Channel: 7 --- */
  {
    /* define a variable for IO error handling */
    UInt32 ioErrorCode = IOLIB_NO_ERROR;

    /* Apply- and Start-Fcn for pRTIAdcC1AnalogIn_Ch_7 */
    ioErrorCode = AdcCl1AnalogIn_apply(pRTIAdcC1AnalogIn_Ch_7);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = AdcCl1AnalogIn_start(pRTIAdcC1AnalogIn_Ch_7);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }
  }

  /* --- Bilateral_Ankle_Exo/Sensor Data/EMG module/ADC_CLASS1_BL1 --- */
  /* --- [RTI120X, ADC C1] - Channel: 1 --- */
  {
    /* define a variable for IO error handling */
    UInt32 ioErrorCode = IOLIB_NO_ERROR;

    /* Apply- and Start-Fcn for pRTIAdcC1AnalogIn_Ch_1 */
    ioErrorCode = AdcCl1AnalogIn_apply(pRTIAdcC1AnalogIn_Ch_1);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = AdcCl1AnalogIn_start(pRTIAdcC1AnalogIn_Ch_1);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }
  }

  /* --- Bilateral_Ankle_Exo/Sensor Data/EMG module/ADC_CLASS1_BL10 --- */
  /* --- [RTI120X, ADC C1] - Channel: 10 --- */
  {
    /* define a variable for IO error handling */
    UInt32 ioErrorCode = IOLIB_NO_ERROR;

    /* Apply- and Start-Fcn for pRTIAdcC1AnalogIn_Ch_10 */
    ioErrorCode = AdcCl1AnalogIn_apply(pRTIAdcC1AnalogIn_Ch_10);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = AdcCl1AnalogIn_start(pRTIAdcC1AnalogIn_Ch_10);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }
  }

  /* --- Bilateral_Ankle_Exo/Sensor Data/EMG module/ADC_CLASS1_BL11 --- */
  /* --- [RTI120X, ADC C1] - Channel: 11 --- */
  {
    /* define a variable for IO error handling */
    UInt32 ioErrorCode = IOLIB_NO_ERROR;

    /* Apply- and Start-Fcn for pRTIAdcC1AnalogIn_Ch_11 */
    ioErrorCode = AdcCl1AnalogIn_apply(pRTIAdcC1AnalogIn_Ch_11);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = AdcCl1AnalogIn_start(pRTIAdcC1AnalogIn_Ch_11);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }
  }

  /* --- Bilateral_Ankle_Exo/Sensor Data/EMG module/ADC_CLASS1_BL12 --- */
  /* --- [RTI120X, ADC C1] - Channel: 12 --- */
  {
    /* define a variable for IO error handling */
    UInt32 ioErrorCode = IOLIB_NO_ERROR;

    /* Apply- and Start-Fcn for pRTIAdcC1AnalogIn_Ch_12 */
    ioErrorCode = AdcCl1AnalogIn_apply(pRTIAdcC1AnalogIn_Ch_12);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = AdcCl1AnalogIn_start(pRTIAdcC1AnalogIn_Ch_12);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }
  }

  /* --- Bilateral_Ankle_Exo/Sensor Data/EMG module/ADC_CLASS1_BL2 --- */
  /* --- [RTI120X, ADC C1] - Channel: 2 --- */
  {
    /* define a variable for IO error handling */
    UInt32 ioErrorCode = IOLIB_NO_ERROR;

    /* Apply- and Start-Fcn for pRTIAdcC1AnalogIn_Ch_2 */
    ioErrorCode = AdcCl1AnalogIn_apply(pRTIAdcC1AnalogIn_Ch_2);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = AdcCl1AnalogIn_start(pRTIAdcC1AnalogIn_Ch_2);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }
  }

  /* --- Bilateral_Ankle_Exo/Sensor Data/EMG module/ADC_CLASS1_BL3 --- */
  /* --- [RTI120X, ADC C1] - Channel: 3 --- */
  {
    /* define a variable for IO error handling */
    UInt32 ioErrorCode = IOLIB_NO_ERROR;

    /* Apply- and Start-Fcn for pRTIAdcC1AnalogIn_Ch_3 */
    ioErrorCode = AdcCl1AnalogIn_apply(pRTIAdcC1AnalogIn_Ch_3);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = AdcCl1AnalogIn_start(pRTIAdcC1AnalogIn_Ch_3);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }
  }

  /* --- Bilateral_Ankle_Exo/Sensor Data/EMG module/ADC_CLASS1_BL4 --- */
  /* --- [RTI120X, ADC C1] - Channel: 4 --- */
  {
    /* define a variable for IO error handling */
    UInt32 ioErrorCode = IOLIB_NO_ERROR;

    /* Apply- and Start-Fcn for pRTIAdcC1AnalogIn_Ch_4 */
    ioErrorCode = AdcCl1AnalogIn_apply(pRTIAdcC1AnalogIn_Ch_4);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = AdcCl1AnalogIn_start(pRTIAdcC1AnalogIn_Ch_4);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }
  }

  /* --- Bilateral_Ankle_Exo/Sensor Data/EMG module/ADC_CLASS1_BL9 --- */
  /* --- [RTI120X, ADC C1] - Channel: 9 --- */
  {
    /* define a variable for IO error handling */
    UInt32 ioErrorCode = IOLIB_NO_ERROR;

    /* Apply- and Start-Fcn for pRTIAdcC1AnalogIn_Ch_9 */
    ioErrorCode = AdcCl1AnalogIn_apply(pRTIAdcC1AnalogIn_Ch_9);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = AdcCl1AnalogIn_start(pRTIAdcC1AnalogIn_Ch_9);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }
  }

  /* dSPACE I/O Board DS1_RTICAN #1 */
  /* Initialization of DS1501 board */
  can_tp1_communication_init(can_tp1_address_table[0].module_addr,
    CAN_TP1_INT_ENABLE);

  /* dSPACE RTICAN MASTER SETUP Block */
  /* ... Initialize the CAN communication: 500 kbit/s */
  can_type1_channel_M1_C1 = can_tp1_channel_init(can_tp1_address_table[0].
    module_addr, 0, (500 * 1000), CAN_TP1_STD, CAN_TP1_NO_SUBINT);
  can_tp1_channel_termination_set(can_type1_channel_M1_C1,
    CAN_TP1_TERMINATION_ON);

  /* ... Initialize TX message structs for custom code  */
  CANTP1_TX_SPMSG_M1_C1_STD = can_tp1_msg_tx_register(can_type1_channel_M1_C1, 3,
    1050, CAN_TP1_STD, CAN_TP1_TIMECOUNT_INFO | CAN_TP1_DELAYCOUNT_INFO |
    CAN_TP1_MSG_INFO, CAN_TP1_NO_SUBINT, 0, CAN_TP1_TRIGGER_MSG,
    CAN_TP1_TIMEOUT_NORMAL);
  CANTP1_TX_SPMSG_M1_C1_XTD = can_tp1_msg_tx_register(can_type1_channel_M1_C1, 3,
    1100, CAN_TP1_EXT, CAN_TP1_TIMECOUNT_INFO | CAN_TP1_DELAYCOUNT_INFO |
    CAN_TP1_MSG_INFO, CAN_TP1_NO_SUBINT, 0, CAN_TP1_TRIGGER_MSG,
    CAN_TP1_TIMEOUT_NORMAL);

  /* ... Initialize STD RX message for RX Service support */
  {
    UInt32 mask = 0;
    UInt32 queueSize = 64;
    UInt32 msgId = 1;
    CANTP1_RX_SPMSG_M1_C1_STD = can_tp1_msg_rx_register(can_type1_channel_M1_C1,
      0, 1, CAN_TP1_STD, CAN_TP1_TIMECOUNT_INFO | CAN_TP1_DATA_INFO |
      CAN_TP1_MSG_INFO, CAN_TP1_NO_SUBINT);

    /* set the queue depth */
    can_tp1_msg_set(CANTP1_RX_SPMSG_M1_C1_STD,CAN_TP1_MSG_DSMCR_BUFFER,
                    &queueSize);

    /* set the mask to select which messages are received by service mode */
    can_tp1_msg_set(CANTP1_RX_SPMSG_M1_C1_STD,CAN_TP1_MSG_MASK, &mask);

    /* create the r-buffer */
    can_tp1_dsmcr_client_create(CANTP1_RX_SPMSG_M1_C1_STD,
      CAN_TP1_DSMCR_OVERRUN_OVERWRITE, NULL, &CANTP1_RX_M1_C1_MCRCLT_STD );
  }

  /* dSPACE RTICAN MASTER SETUP Block */
  /* ... Initialize the Partial Networking Settings */

  /* dSPACE RTICAN RX Message Block: "RX Message" Id:3 */
  /* ... Register message */
  can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X3] = can_tp1_msg_rx_register
    (can_type1_channel_M1_C1, 0, 3, CAN_TP1_STD, (CAN_TP1_DATA_INFO|
      CAN_TP1_DATA_INFO|CAN_TP1_TIMECOUNT_INFO), CAN_TP1_NO_SUBINT);

  /* dSPACE RTICAN RX Message Block: "RX Message" Id:100 */
  /* ... Register message */
  can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X64] = can_tp1_msg_rx_register
    (can_type1_channel_M1_C1, 1, 100, CAN_TP1_STD, (CAN_TP1_DATA_INFO|
      CAN_TP1_DATA_INFO|CAN_TP1_TIMECOUNT_INFO), CAN_TP1_NO_SUBINT);

  /* dSPACE RTICAN MASTER SETUP Block */
  /* ... Initialize the CAN communication: 500 kbit/s */
  can_type1_channel_M1_C2 = can_tp1_channel_init(can_tp1_address_table[0].
    module_addr, 1, (500 * 1000), CAN_TP1_STD, CAN_TP1_NO_SUBINT);
  can_tp1_channel_termination_set(can_type1_channel_M1_C2,
    CAN_TP1_TERMINATION_ON);

  /* ... Initialize TX message structs for custom code  */
  CANTP1_TX_SPMSG_M1_C2_STD = can_tp1_msg_tx_register(can_type1_channel_M1_C2, 3,
    1050, CAN_TP1_STD, CAN_TP1_TIMECOUNT_INFO | CAN_TP1_DELAYCOUNT_INFO |
    CAN_TP1_MSG_INFO, CAN_TP1_NO_SUBINT, 0, CAN_TP1_TRIGGER_MSG,
    CAN_TP1_TIMEOUT_NORMAL);
  CANTP1_TX_SPMSG_M1_C2_XTD = can_tp1_msg_tx_register(can_type1_channel_M1_C2, 3,
    1100, CAN_TP1_EXT, CAN_TP1_TIMECOUNT_INFO | CAN_TP1_DELAYCOUNT_INFO |
    CAN_TP1_MSG_INFO, CAN_TP1_NO_SUBINT, 0, CAN_TP1_TRIGGER_MSG,
    CAN_TP1_TIMEOUT_NORMAL);

  /* ... Initialize STD RX message for RX Service support */
  {
    UInt32 mask = 0;
    UInt32 queueSize = 64;
    UInt32 msgId = 1;
    CANTP1_RX_SPMSG_M1_C2_STD = can_tp1_msg_rx_register(can_type1_channel_M1_C2,
      0, 1, CAN_TP1_STD, CAN_TP1_TIMECOUNT_INFO | CAN_TP1_DATA_INFO |
      CAN_TP1_MSG_INFO, CAN_TP1_NO_SUBINT);

    /* set the queue depth */
    can_tp1_msg_set(CANTP1_RX_SPMSG_M1_C2_STD,CAN_TP1_MSG_DSMCR_BUFFER,
                    &queueSize);

    /* set the mask to select which messages are received by service mode */
    can_tp1_msg_set(CANTP1_RX_SPMSG_M1_C2_STD,CAN_TP1_MSG_MASK, &mask);

    /* create the r-buffer */
    can_tp1_dsmcr_client_create(CANTP1_RX_SPMSG_M1_C2_STD,
      CAN_TP1_DSMCR_OVERRUN_OVERWRITE, NULL, &CANTP1_RX_M1_C2_MCRCLT_STD );
  }

  /* dSPACE RTICAN MASTER SETUP Block */
  /* ... Initialize the Partial Networking Settings */

  /* dSPACE RTICAN TX Message Block: "TX Message" Id:100 */
  /* ... Register message */
  can_type1_msg_M1[CANTP1_M1_C2_TX_STD_0X64] = can_tp1_msg_tx_register
    (can_type1_channel_M1_C2, 1, 100, CAN_TP1_STD, (CAN_TP1_TIMECOUNT_INFO|
      CAN_TP1_TIMECOUNT_INFO|CAN_TP1_TIMECOUNT_INFO|CAN_TP1_DELAYCOUNT_INFO),
     CAN_TP1_NO_SUBINT, 0, CAN_TP1_TRIGGER_MSG, CAN_TP1_TIMEOUT_NORMAL);

  /* dSPACE RTICAN RX Message Block: "RX Message" Id:3 */
  Bilateral_Ankle_Exo_B.SFunction1_o4 = 0;/* processed - flag */
  Bilateral_Ankle_Exo_B.SFunction1_o5 = 0;/* timestamp */

  /* dSPACE RTICAN RX Message Block: "RX Message" Id:100 */
  Bilateral_Ankle_Exo_B.SFunction1_o2_f = 0;/* processed - flag */
  Bilateral_Ankle_Exo_B.SFunction1_o3_g = 0;/* timestamp */

  /* dSPACE RTICAN TX Message Block: "TX Message" Id:100 */
  /* Messages with timestamp zero have been received in pause/stop state
     and must not be handled.
   */
  if (can_type1_msg_M1[CANTP1_M1_C2_TX_STD_0X64]->timestamp > 0.0) {
    Bilateral_Ankle_Exo_B.SFunction1_o1_l = 0;/* processed - flag */
    Bilateral_Ankle_Exo_B.SFunction1_o2_jb = 0;/* timestamp */
    Bilateral_Ankle_Exo_B.SFunction1_o3_p = 0;/* deltatime */
    Bilateral_Ankle_Exo_B.SFunction1_o4_k = 0;/* delaytime */
  }

  /* dSPACE I/O Board RTICAN_GLOBAL #0 */
}

/* Function rti_mdl_slave_load() is empty */
#define rti_mdl_slave_load()

/* Function rti_mdl_rtk_initialize() is empty */
#define rti_mdl_rtk_initialize()

static void rti_mdl_initialize_io_units(void)
{
  /* --- Bilateral_Ankle_Exo/Control Module/Motor_L/DAC_CLASS1_BL1 --- */
  /* --- [RTI120X, DAC C1] - Channel: 16 --- */
  {
    /* define a variable for IO error handling */
    UInt32 ioErrorCode = IOLIB_NO_ERROR;

    /* All channel outputs are released from high impedance state */
    DacCl1AnalogOut_setOutputHighZ(pRTIDacC1AnalogOut_Ch_16,
      DAC_CLASS1_HIGH_Z_OFF);

    /* write initial value of CL1 DAC for output channel 16 */
    ioErrorCode = DacCl1AnalogOut_setOutputValue(pRTIDacC1AnalogOut_Ch_16,
      DAC_CLASS1_CHANNEL_16, (Float64) 0.0);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    /* Activates AnalogOut functionality */
    ioErrorCode = DacCl1AnalogOut_start(pRTIDacC1AnalogOut_Ch_16);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }
  }

  /* --- Bilateral_Ankle_Exo/Control Module/Motor_R/DAC_CLASS1_BL1 --- */
  /* --- [RTI120X, DAC C1] - Channel: 15 --- */
  {
    /* define a variable for IO error handling */
    UInt32 ioErrorCode = IOLIB_NO_ERROR;

    /* All channel outputs are released from high impedance state */
    DacCl1AnalogOut_setOutputHighZ(pRTIDacC1AnalogOut_Ch_15,
      DAC_CLASS1_HIGH_Z_OFF);

    /* write initial value of CL1 DAC for output channel 15 */
    ioErrorCode = DacCl1AnalogOut_setOutputValue(pRTIDacC1AnalogOut_Ch_15,
      DAC_CLASS1_CHANNEL_15, (Float64) 0.0);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    /* Activates AnalogOut functionality */
    ioErrorCode = DacCl1AnalogOut_start(pRTIDacC1AnalogOut_Ch_15);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }
  }

  /* --- Bilateral_Ankle_Exo/Sensor Data/Ankle Encoder/EMC_ENCODER_BL1 --- */
  /* --- [RTIEMC, Encoder] - DIO class: 2 - Unit: 5 - Port: 1 - Channel: 10 --- */
  {
    /* define a variable for IO error handling */
    UInt32 ioErrorRetValue = IOLIB_NO_ERROR;

    /* Resets start (initial) position for the selected incremental Encoder (in lines) */
    ioErrorRetValue = DioCl2EncoderIn_setEncPosition
      (pRTIEmcEncoder_Unit_5_DioCl_2_Port_1_Ch10, (Float64) 0);
    if (ioErrorRetValue > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    /* Activate Encoder signals read */
    ioErrorRetValue = DioCl2EncoderIn_start
      (pRTIEmcEncoder_Unit_5_DioCl_2_Port_1_Ch10);
    if (ioErrorRetValue > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }
  }

  /* --- Bilateral_Ankle_Exo/Sensor Data/Motor Encoder/EMC_ENCODER_BL2 --- */
  /* --- [RTIEMC, Encoder] - DIO class: 2 - Unit: 2 - Port: 1 - Channel: 3 --- */
  {
    /* define a variable for IO error handling */
    UInt32 ioErrorRetValue = IOLIB_NO_ERROR;

    /* Resets start (initial) position for the selected incremental Encoder (in lines) */
    ioErrorRetValue = DioCl2EncoderIn_setEncPosition
      (pRTIEmcEncoder_Unit_2_DioCl_2_Port_1_Ch3, (Float64) 0);
    if (ioErrorRetValue > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    /* Activate Encoder signals read */
    ioErrorRetValue = DioCl2EncoderIn_start
      (pRTIEmcEncoder_Unit_2_DioCl_2_Port_1_Ch3);
    if (ioErrorRetValue > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }
  }

  /* --- Bilateral_Ankle_Exo/Sensor Data/Ankle Encoder/EMC_ENCODER_BL2 --- */
  /* --- [RTIEMC, Encoder] - DIO class: 2 - Unit: 4 - Port: 1 - Channel: 7 --- */
  {
    /* define a variable for IO error handling */
    UInt32 ioErrorRetValue = IOLIB_NO_ERROR;

    /* Resets start (initial) position for the selected incremental Encoder (in lines) */
    ioErrorRetValue = DioCl2EncoderIn_setEncPosition
      (pRTIEmcEncoder_Unit_4_DioCl_2_Port_1_Ch7, (Float64) 0);
    if (ioErrorRetValue > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    /* Activate Encoder signals read */
    ioErrorRetValue = DioCl2EncoderIn_start
      (pRTIEmcEncoder_Unit_4_DioCl_2_Port_1_Ch7);
    if (ioErrorRetValue > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }
  }

  /* --- Bilateral_Ankle_Exo/Sensor Data/Motor Encoder/EMC_ENCODER_BL3 --- */
  /* --- [RTIEMC, Encoder] - DIO class: 2 - Unit: 3 - Port: 1 - Channel: 5 --- */
  {
    /* define a variable for IO error handling */
    UInt32 ioErrorRetValue = IOLIB_NO_ERROR;

    /* Resets start (initial) position for the selected incremental Encoder (in lines) */
    ioErrorRetValue = DioCl2EncoderIn_setEncPosition
      (pRTIEmcEncoder_Unit_3_DioCl_2_Port_1_Ch5, (Float64) 0);
    if (ioErrorRetValue > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    /* Activate Encoder signals read */
    ioErrorRetValue = DioCl2EncoderIn_start
      (pRTIEmcEncoder_Unit_3_DioCl_2_Port_1_Ch5);
    if (ioErrorRetValue > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }
  }

  /* --- Bilateral_Ankle_Exo/Sensor Data/Ankle Encoder/Encoder Power Setup1 --- */
  /* --- [RTI120X, BITOUT] - Port: 3 - Channel: 15 --- */
  {
    /* define a variable for IO error handling */
    UInt32 ioErrorCode = IOLIB_NO_ERROR;

    /* define variables required for BitOut initial functions */
    UInt32 outputDataInit = 0;
    ioErrorCode = DioCl1DigOut_setChMaskOutHighZ(pRTIDioC1DigOut_Port_3_Ch_15,
      DIO_CLASS1_HIGH_Z_OFF);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    outputDataInit = ( ( ( (UInt32)0) << (15 - 1)) | outputDataInit);

    /* write initialization value to digital output channel 15-15 on port 3 */
    ioErrorCode = DioCl1DigOut_setChMaskOutData(pRTIDioC1DigOut_Port_3_Ch_15,
      outputDataInit);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = DioCl1DigOut_write(pRTIDioC1DigOut_Port_3_Ch_15);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }
  }

  /* --- Bilateral_Ankle_Exo/Sensor Data/Ankle Encoder/Encoder Power Setup2 --- */
  /* --- [RTI120X, BITOUT] - Port: 3 - Channel: 16 --- */
  {
    /* define a variable for IO error handling */
    UInt32 ioErrorCode = IOLIB_NO_ERROR;

    /* define variables required for BitOut initial functions */
    UInt32 outputDataInit = 0;
    ioErrorCode = DioCl1DigOut_setChMaskOutHighZ(pRTIDioC1DigOut_Port_3_Ch_16,
      DIO_CLASS1_HIGH_Z_OFF);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    outputDataInit = ( ( ( (UInt32)0) << (16 - 1)) | outputDataInit);

    /* write initialization value to digital output channel 16-16 on port 3 */
    ioErrorCode = DioCl1DigOut_setChMaskOutData(pRTIDioC1DigOut_Port_3_Ch_16,
      outputDataInit);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = DioCl1DigOut_write(pRTIDioC1DigOut_Port_3_Ch_16);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }
  }

  /* --- Bilateral_Ankle_Exo/Sensor Data/Motor Encoder/Encoder Power Setup2 --- */
  /* --- [RTI120X, BITOUT] - Port: 3 - Channel: 12 --- */
  {
    /* define a variable for IO error handling */
    UInt32 ioErrorCode = IOLIB_NO_ERROR;

    /* define variables required for BitOut initial functions */
    UInt32 outputDataInit = 0;
    ioErrorCode = DioCl1DigOut_setChMaskOutHighZ(pRTIDioC1DigOut_Port_3_Ch_12,
      DIO_CLASS1_HIGH_Z_OFF);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    outputDataInit = ( ( ( (UInt32)0) << (12 - 1)) | outputDataInit);

    /* write initialization value to digital output channel 12-12 on port 3 */
    ioErrorCode = DioCl1DigOut_setChMaskOutData(pRTIDioC1DigOut_Port_3_Ch_12,
      outputDataInit);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = DioCl1DigOut_write(pRTIDioC1DigOut_Port_3_Ch_12);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }
  }

  /* --- Bilateral_Ankle_Exo/Sensor Data/Motor Encoder/Encoder Power Setup3 --- */
  /* --- [RTI120X, BITOUT] - Port: 3 - Channel: 13 --- */
  {
    /* define a variable for IO error handling */
    UInt32 ioErrorCode = IOLIB_NO_ERROR;

    /* define variables required for BitOut initial functions */
    UInt32 outputDataInit = 0;
    ioErrorCode = DioCl1DigOut_setChMaskOutHighZ(pRTIDioC1DigOut_Port_3_Ch_13,
      DIO_CLASS1_HIGH_Z_OFF);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    outputDataInit = ( ( ( (UInt32)0) << (13 - 1)) | outputDataInit);

    /* write initialization value to digital output channel 13-13 on port 3 */
    ioErrorCode = DioCl1DigOut_setChMaskOutData(pRTIDioC1DigOut_Port_3_Ch_13,
      outputDataInit);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = DioCl1DigOut_write(pRTIDioC1DigOut_Port_3_Ch_13);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }
  }

  /* --- Bilateral_Ankle_Exo/Sensor Data/FootSwitch module/DIO_CLASS1_BIT_OUT_BL1 --- */
  /* --- [RTI120X, BITOUT] - Port: 1 - Channel: 1 --- */
  {
    /* define a variable for IO error handling */
    UInt32 ioErrorCode = IOLIB_NO_ERROR;

    /* define variables required for BitOut initial functions */
    UInt32 outputDataInit = 0;
    ioErrorCode = DioCl1DigOut_setChMaskOutHighZ(pRTIDioC1DigOut_Port_1_Ch_1,
      DIO_CLASS1_HIGH_Z_OFF);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    outputDataInit = ( ( ( (UInt32)0) << (1 - 1)) | outputDataInit);

    /* write initialization value to digital output channel 1-1 on port 1 */
    ioErrorCode = DioCl1DigOut_setChMaskOutData(pRTIDioC1DigOut_Port_1_Ch_1,
      outputDataInit);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = DioCl1DigOut_write(pRTIDioC1DigOut_Port_1_Ch_1);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }
  }

  /* --- Bilateral_Ankle_Exo/Sensor Data/FootSwitch module/DIO_CLASS1_BIT_OUT_BL2 --- */
  /* --- [RTI120X, BITOUT] - Port: 1 - Channel: 3 --- */
  {
    /* define a variable for IO error handling */
    UInt32 ioErrorCode = IOLIB_NO_ERROR;

    /* define variables required for BitOut initial functions */
    UInt32 outputDataInit = 0;
    ioErrorCode = DioCl1DigOut_setChMaskOutHighZ(pRTIDioC1DigOut_Port_1_Ch_3,
      DIO_CLASS1_HIGH_Z_OFF);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    outputDataInit = ( ( ( (UInt32)0) << (3 - 1)) | outputDataInit);

    /* write initialization value to digital output channel 3-3 on port 1 */
    ioErrorCode = DioCl1DigOut_setChMaskOutData(pRTIDioC1DigOut_Port_1_Ch_3,
      outputDataInit);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = DioCl1DigOut_write(pRTIDioC1DigOut_Port_1_Ch_3);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }
  }

  /* dSPACE I/O Board DS1_RTICAN #1 */
  /* Start CAN controller */
  can_tp1_channel_start(can_type1_channel_M1_C1, CAN_TP1_INT_DISABLE);

  /* Start CAN controller */
  can_tp1_channel_start(can_type1_channel_M1_C2, CAN_TP1_INT_DISABLE);

  /* Set the type1CAN error level */
  rtican_type1_error_level = 0;

  /* ... Reset all taskqueue-specific error variables */
  rtican_type1_tq_err_all_reset(0);

  /* ... Clear all message data buffers */
  can_tp1_all_data_clear(can_tp1_address_table[0].module_addr);

  /* dSPACE RTICAN STD Srvc-Message Block */
  {
    static int numInit = 0;
    if (numInit != 0) {
      /* ... Wake message up */
      while ((rtican_type1_tq_error[0][0] = can_tp1_msg_wakeup
              (CANTP1_RX_SPMSG_M1_C1_STD))== DSMCOM_BUFFER_OVERFLOW) ;
    }

    ++numInit;
  }

  {
    static UInt32 numInit = 0;
    if (numInit != 0) {
      /* ... Wake message up */
      while ((rtican_type1_tq_error[0][0] = can_tp1_msg_wakeup
              (can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X3])) ==
             DSMCOM_BUFFER_OVERFLOW) ;
    }

    ++numInit;
  }

  {
    static UInt32 numInit = 0;
    if (numInit != 0) {
      /* ... Wake message up */
      while ((rtican_type1_tq_error[0][1] = can_tp1_msg_wakeup
              (can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X64])) ==
             DSMCOM_BUFFER_OVERFLOW) ;
    }

    ++numInit;
  }

  /* dSPACE RTICAN STD Srvc-Message Block */
  {
    static int numInit = 0;
    if (numInit != 0) {
      /* ... Wake message up */
      while ((rtican_type1_tq_error[0][0] = can_tp1_msg_wakeup
              (CANTP1_RX_SPMSG_M1_C2_STD))== DSMCOM_BUFFER_OVERFLOW) ;
    }

    ++numInit;
  }

  {
    static UInt32 numInit = 0;
    if (numInit != 0) {
      /* ... Wake message up */
      while ((rtican_type1_tq_error[0][1] = can_tp1_msg_wakeup
              (can_type1_msg_M1[CANTP1_M1_C2_TX_STD_0X64])) ==
             DSMCOM_BUFFER_OVERFLOW) ;
    }

    ++numInit;
  }
}

/* Function rti_mdl_acknowledge_interrupts() is empty */
#define rti_mdl_acknowledge_interrupts()

/* Function rti_mdl_timetables_register() is empty */
#define rti_mdl_timetables_register()

/* Function rti_mdl_timesync_simstate() is empty */
#define rti_mdl_timesync_simstate()

/* Function rti_mdl_timesync_baserate() is empty */
#define rti_mdl_timesync_baserate()

static void rti_mdl_background(void)
{
  /* DsDaq background call */
  DsDaq_Background(0);

  /* dSPACE I/O Board DS1_RTICAN #1 */
  {
    real_T bg_code_exec_time;
    static real_T bg_code_last_exec_time = 0.0;
    bg_code_exec_time = RTLIB_TIC_READ();
    if ((bg_code_exec_time - bg_code_last_exec_time) > 0.25 ||
        (bg_code_exec_time - bg_code_last_exec_time) < 0) {
      /* ... Check taskqueue-specific error variables */
      rtican_type1_tq_err_all_chk(can_tp1_address_table[0].module_addr, 0);
      bg_code_last_exec_time = bg_code_exec_time;
    }
  }

  /* copy DPMEM - buffers in background */
  {
    /* call update function for CAN Tp1 CAN interface (module number: 1) */
    can_tp1_msg_copy_all_to_mem(can_tp1_address_table[0].module_addr);
  }
}

__INLINE void rti_mdl_sample_input(void)
{
  /* Calls for base sample time: [0.0002, 0] */
  /* dSPACE I/O Board DS120XSTDADCC1 #0 Unit:ADCC1 */

  /* dSPACE I/O Board DS120XSTDADCC1 #0 Unit:ADCC1 Group:ADC */
  /* fire burst- or conversion trigger for analog input channel. Called by ADC C1 block pRTIAdcC1AnalogIn_Ch_6 */
  AdcCl1AnalogIn_setConversSwTrigger(pRTIAdcC1AnalogIn_Ch_6);
  AdcCl1AnalogIn_write(pRTIAdcC1AnalogIn_Ch_6);

  /* fire burst- or conversion trigger for analog input channel. Called by ADC C1 block pRTIAdcC1AnalogIn_Ch_7 */
  AdcCl1AnalogIn_setConversSwTrigger(pRTIAdcC1AnalogIn_Ch_7);
  AdcCl1AnalogIn_write(pRTIAdcC1AnalogIn_Ch_7);

  /* fire burst- or conversion trigger for analog input channel. Called by ADC C1 block pRTIAdcC1AnalogIn_Ch_1 */
  AdcCl1AnalogIn_setConversSwTrigger(pRTIAdcC1AnalogIn_Ch_1);
  AdcCl1AnalogIn_write(pRTIAdcC1AnalogIn_Ch_1);

  /* fire burst- or conversion trigger for analog input channel. Called by ADC C1 block pRTIAdcC1AnalogIn_Ch_10 */
  AdcCl1AnalogIn_setConversSwTrigger(pRTIAdcC1AnalogIn_Ch_10);
  AdcCl1AnalogIn_write(pRTIAdcC1AnalogIn_Ch_10);

  /* fire burst- or conversion trigger for analog input channel. Called by ADC C1 block pRTIAdcC1AnalogIn_Ch_11 */
  AdcCl1AnalogIn_setConversSwTrigger(pRTIAdcC1AnalogIn_Ch_11);
  AdcCl1AnalogIn_write(pRTIAdcC1AnalogIn_Ch_11);

  /* fire burst- or conversion trigger for analog input channel. Called by ADC C1 block pRTIAdcC1AnalogIn_Ch_12 */
  AdcCl1AnalogIn_setConversSwTrigger(pRTIAdcC1AnalogIn_Ch_12);
  AdcCl1AnalogIn_write(pRTIAdcC1AnalogIn_Ch_12);

  /* fire burst- or conversion trigger for analog input channel. Called by ADC C1 block pRTIAdcC1AnalogIn_Ch_2 */
  AdcCl1AnalogIn_setConversSwTrigger(pRTIAdcC1AnalogIn_Ch_2);
  AdcCl1AnalogIn_write(pRTIAdcC1AnalogIn_Ch_2);

  /* fire burst- or conversion trigger for analog input channel. Called by ADC C1 block pRTIAdcC1AnalogIn_Ch_3 */
  AdcCl1AnalogIn_setConversSwTrigger(pRTIAdcC1AnalogIn_Ch_3);
  AdcCl1AnalogIn_write(pRTIAdcC1AnalogIn_Ch_3);

  /* fire burst- or conversion trigger for analog input channel. Called by ADC C1 block pRTIAdcC1AnalogIn_Ch_4 */
  AdcCl1AnalogIn_setConversSwTrigger(pRTIAdcC1AnalogIn_Ch_4);
  AdcCl1AnalogIn_write(pRTIAdcC1AnalogIn_Ch_4);

  /* fire burst- or conversion trigger for analog input channel. Called by ADC C1 block pRTIAdcC1AnalogIn_Ch_9 */
  AdcCl1AnalogIn_setConversSwTrigger(pRTIAdcC1AnalogIn_Ch_9);
  AdcCl1AnalogIn_write(pRTIAdcC1AnalogIn_Ch_9);

  /* --- Bilateral_Ankle_Exo/Sensor Data/Ankle Encoder/EMC_ENCODER_BL1 --- */
  /* --- [RTIEMC, Encoder] - DIO class: 2 - Unit: 5 - Port: 1 - Channel: 10 --- */
  {
    /* define variables required for encoder sensor realtime functions */
    Float64 positionOrAngle= 0.0, speedOrAngVelocity= 0.0;
    UInt32 isIndexRaised= 0;

    /* Reads complete input data from selected encoder input channels (update data from hardware) */
    DioCl2EncoderIn_read(pRTIEmcEncoder_Unit_5_DioCl_2_Port_1_Ch10);

    /* Gets encoder position (line) */
    DioCl2EncoderIn_getEncPosition(pRTIEmcEncoder_Unit_5_DioCl_2_Port_1_Ch10,
      &positionOrAngle);

    /* Gets encoder speed (lines/second) */
    DioCl2EncoderIn_getEncVelocity(pRTIEmcEncoder_Unit_5_DioCl_2_Port_1_Ch10,
      &speedOrAngVelocity);
    Bilateral_Ankle_Exo_B.SFunction1_o1 = (real_T) positionOrAngle;
    Bilateral_Ankle_Exo_B.SFunction1_o2 = (real_T) speedOrAngVelocity;

    /* Once the index signal is detected, this outport is raised high.   *
     * This value is retained until the end of the real-time application */
    DioCl2EncoderIn_getIsIndexRaised (pRTIEmcEncoder_Unit_5_DioCl_2_Port_1_Ch10,
      &isIndexRaised);
    Bilateral_Ankle_Exo_B.SFunction1_o3_b = (boolean_T) isIndexRaised ;
  }

  /* --- Bilateral_Ankle_Exo/Sensor Data/Motor Encoder/EMC_ENCODER_BL2 --- */
  /* --- [RTIEMC, Encoder] - DIO class: 2 - Unit: 2 - Port: 1 - Channel: 3 --- */
  {
    /* define variables required for encoder sensor realtime functions */
    Float64 positionOrAngle= 0.0, speedOrAngVelocity= 0.0;
    UInt32 isIndexRaised= 0;

    /* Reads complete input data from selected encoder input channels (update data from hardware) */
    DioCl2EncoderIn_read(pRTIEmcEncoder_Unit_2_DioCl_2_Port_1_Ch3);

    /* Gets encoder position (line) */
    DioCl2EncoderIn_getEncPosition(pRTIEmcEncoder_Unit_2_DioCl_2_Port_1_Ch3,
      &positionOrAngle);

    /* Gets encoder speed (lines/second) */
    DioCl2EncoderIn_getEncVelocity(pRTIEmcEncoder_Unit_2_DioCl_2_Port_1_Ch3,
      &speedOrAngVelocity);
    Bilateral_Ankle_Exo_B.SFunction1_o1_j = (real_T) positionOrAngle;
    Bilateral_Ankle_Exo_B.SFunction1_o2_h = (real_T) speedOrAngVelocity;
  }

  /* --- Bilateral_Ankle_Exo/Sensor Data/FootSwitch module/DIO_CLASS1_BIT_IN_BL1 --- */
  /* --- [RTI120X, BITIN] - Port: 1 - Channel: 2 --- */
  {
    UInt32 inputDataUInt32;

    /* get digital signal state on channel 2-2 on port 1 */
    DioCl1DigIn_read(pRTIDioC1DigIn_Port_1_Ch_2);
    DioCl1DigIn_getChMaskInData(pRTIDioC1DigIn_Port_1_Ch_2, &inputDataUInt32);
    Bilateral_Ankle_Exo_B.SFunction1_it = (boolean_T)((inputDataUInt32 &
      DIO_CLASS1_MASK_CH_2) >> 1);
  }

  /* --- Bilateral_Ankle_Exo/Sensor Data/FootSwitch module/DIO_CLASS1_BIT_IN_BL2 --- */
  /* --- [RTI120X, BITIN] - Port: 1 - Channel: 4 --- */
  {
    UInt32 inputDataUInt32;

    /* get digital signal state on channel 4-4 on port 1 */
    DioCl1DigIn_read(pRTIDioC1DigIn_Port_1_Ch_4);
    DioCl1DigIn_getChMaskInData(pRTIDioC1DigIn_Port_1_Ch_4, &inputDataUInt32);
    Bilateral_Ankle_Exo_B.SFunction1_jo = (boolean_T)((inputDataUInt32 &
      DIO_CLASS1_MASK_CH_4) >> 3);
  }

  /* --- Bilateral_Ankle_Exo/Sensor Data/Ankle Encoder/EMC_ENCODER_BL2 --- */
  /* --- [RTIEMC, Encoder] - DIO class: 2 - Unit: 4 - Port: 1 - Channel: 7 --- */
  {
    /* define variables required for encoder sensor realtime functions */
    Float64 positionOrAngle= 0.0, speedOrAngVelocity= 0.0;
    UInt32 isIndexRaised= 0;

    /* Reads complete input data from selected encoder input channels (update data from hardware) */
    DioCl2EncoderIn_read(pRTIEmcEncoder_Unit_4_DioCl_2_Port_1_Ch7);

    /* Gets encoder position (line) */
    DioCl2EncoderIn_getEncPosition(pRTIEmcEncoder_Unit_4_DioCl_2_Port_1_Ch7,
      &positionOrAngle);

    /* Gets encoder speed (lines/second) */
    DioCl2EncoderIn_getEncVelocity(pRTIEmcEncoder_Unit_4_DioCl_2_Port_1_Ch7,
      &speedOrAngVelocity);
    Bilateral_Ankle_Exo_B.SFunction1_o1_jc = (real_T) positionOrAngle;
    Bilateral_Ankle_Exo_B.SFunction1_o2_o = (real_T) speedOrAngVelocity;

    /* Once the index signal is detected, this outport is raised high.   *
     * This value is retained until the end of the real-time application */
    DioCl2EncoderIn_getIsIndexRaised (pRTIEmcEncoder_Unit_4_DioCl_2_Port_1_Ch7,
      &isIndexRaised);
    Bilateral_Ankle_Exo_B.SFunction1_o3_h = (boolean_T) isIndexRaised ;
  }

  /* --- Bilateral_Ankle_Exo/Sensor Data/Motor Encoder/EMC_ENCODER_BL3 --- */
  /* --- [RTIEMC, Encoder] - DIO class: 2 - Unit: 3 - Port: 1 - Channel: 5 --- */
  {
    /* define variables required for encoder sensor realtime functions */
    Float64 positionOrAngle= 0.0, speedOrAngVelocity= 0.0;
    UInt32 isIndexRaised= 0;

    /* Reads complete input data from selected encoder input channels (update data from hardware) */
    DioCl2EncoderIn_read(pRTIEmcEncoder_Unit_3_DioCl_2_Port_1_Ch5);

    /* Gets encoder position (line) */
    DioCl2EncoderIn_getEncPosition(pRTIEmcEncoder_Unit_3_DioCl_2_Port_1_Ch5,
      &positionOrAngle);

    /* Gets encoder speed (lines/second) */
    DioCl2EncoderIn_getEncVelocity(pRTIEmcEncoder_Unit_3_DioCl_2_Port_1_Ch5,
      &speedOrAngVelocity);
    Bilateral_Ankle_Exo_B.SFunction1_o1_jr = (real_T) positionOrAngle;
    Bilateral_Ankle_Exo_B.SFunction1_o2_j = (real_T) speedOrAngVelocity;
  }

  /* dSPACE I/O Board DS1_RTICAN #1 Unit:DEFAULT */
  /* call update function for CAN Tp1 CAN interface (module number: 1) */
  can_tp1_msg_copy_all_to_mem(can_tp1_address_table[0].module_addr);
}

/* Function rti_mdl_daq_service() is empty */
#define rti_mdl_daq_service()
#undef __INLINE

/****** [EOF] ****************************************************************/
