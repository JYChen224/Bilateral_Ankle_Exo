/*
 * Bilateral_Ankle_Exo_private.h
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

#ifndef RTW_HEADER_Bilateral_Ankle_Exo_private_h_
#define RTW_HEADER_Bilateral_Ankle_Exo_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "Bilateral_Ankle_Exo.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmIsMajorTimeStep
# define rtmIsMajorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
# define rtmIsMinorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

#ifndef rtmSetTPtr
# define rtmSetTPtr(rtm, val)          ((rtm)->Timing.t = (val))
#endif

/* ...  variable for information on a CAN channel */
extern can_tp1_canChannel* can_type1_channel_M1_C1;

/* ...  variable for information on a CAN channel */
extern can_tp1_canChannel* can_type1_channel_M1_C2;

/* ... definition of message variable for the RTICAN blocks */
#define CANTP1_M1_NUMMSG               3

extern can_tp1_canMsg* can_type1_msg_M1[CANTP1_M1_NUMMSG];

/* ... variable for taskqueue error checking                  */
extern Int32 rtican_type1_tq_error[CAN_TYPE1_NUM_MODULES]
  [CAN_TYPE1_NUM_TASKQUEUES];

/* Declaration of user indices (CAN_Type1_M1) */
#define CANTP1_M1_C1_RX_STD_0X3        0
#define RX_C1_STD_0X3                  0
#undef RX_C1_STD_0X3
#define CANTP1_M1_C1_RX_STD_0X64       1
#define RX_C1_STD_0X64                 1
#undef RX_C1_STD_0X64
#define CANTP1_M1_C2_TX_STD_0X64       2
#define TX_C2_STD_0X64                 2
#undef TX_C2_STD_0X64

/* predefine needed TX-definition code to support TX-Custom code */
extern can_tp1_canMsg* CANTP1_TX_SPMSG_M1_C1_STD;
extern can_tp1_canMsg* CANTP1_TX_SPMSG_M1_C1_XTD;

/* predefine pointer to CAN message object for STD-Msg */
extern can_tp1_canMsg* CANTP1_RX_SPMSG_M1_C1_STD;

/* predefine needed identifiers for mcr-queue */
extern can_tp1_canMsg* CANTP1_RX_M1_C1_MCRCLT_STD;

/* predefine needed TX-definition code to support TX-Custom code */
extern can_tp1_canMsg* CANTP1_TX_SPMSG_M1_C2_STD;
extern can_tp1_canMsg* CANTP1_TX_SPMSG_M1_C2_XTD;

/* predefine pointer to CAN message object for STD-Msg */
extern can_tp1_canMsg* CANTP1_RX_SPMSG_M1_C2_STD;

/* predefine needed identifiers for mcr-queue */
extern can_tp1_canMsg* CANTP1_RX_M1_C2_MCRCLT_STD;
extern DacCl1AnalogOutSDrvObject *pRTIDacC1AnalogOut_Ch_16;
extern DacCl1AnalogOutSDrvObject *pRTIDacC1AnalogOut_Ch_15;
extern AdcCl1AnalogInSDrvObject *pRTIAdcC1AnalogIn_Ch_6;
extern DioCl2EncoderInSDrvObject *pRTIEmcEncoder_Unit_5_DioCl_2_Port_1_Ch10;
extern DioCl2EncoderInSDrvObject *pRTIEmcEncoder_Unit_2_DioCl_2_Port_1_Ch3;
extern DioCl1DigInSDrvObject *pRTIDioC1DigIn_Port_1_Ch_2;
extern DioCl1DigInSDrvObject *pRTIDioC1DigIn_Port_1_Ch_4;
extern AdcCl1AnalogInSDrvObject *pRTIAdcC1AnalogIn_Ch_7;
extern DioCl2EncoderInSDrvObject *pRTIEmcEncoder_Unit_4_DioCl_2_Port_1_Ch7;
extern DioCl2EncoderInSDrvObject *pRTIEmcEncoder_Unit_3_DioCl_2_Port_1_Ch5;
extern SensorSupplySDrvObject *pRTI_Sensor_Supply;
extern DioCl1DigOutSDrvObject *pRTIDioC1DigOut_Port_3_Ch_15;
extern DioCl1DigOutSDrvObject *pRTIDioC1DigOut_Port_3_Ch_16;
extern DioCl1DigOutSDrvObject *pRTIDioC1DigOut_Port_3_Ch_12;
extern DioCl1DigOutSDrvObject *pRTIDioC1DigOut_Port_3_Ch_13;
extern DioCl1DigOutSDrvObject *pRTIDioC1DigOut_Port_1_Ch_1;
extern DioCl1DigOutSDrvObject *pRTIDioC1DigOut_Port_1_Ch_3;
extern AdcCl1AnalogInSDrvObject *pRTIAdcC1AnalogIn_Ch_1;
extern AdcCl1AnalogInSDrvObject *pRTIAdcC1AnalogIn_Ch_2;
extern AdcCl1AnalogInSDrvObject *pRTIAdcC1AnalogIn_Ch_3;
extern AdcCl1AnalogInSDrvObject *pRTIAdcC1AnalogIn_Ch_4;
extern AdcCl1AnalogInSDrvObject *pRTIAdcC1AnalogIn_Ch_9;
extern AdcCl1AnalogInSDrvObject *pRTIAdcC1AnalogIn_Ch_10;
extern real_T rt_roundd_snf(real_T u);
extern real_T rt_powd_snf(real_T u0, real_T u1);
extern real_T rt_hypotd_snf(real_T u0, real_T u1);
extern void Bilateral_Ankle_Exo_Mux(real_T rtu_x1, real_T rtu_x2,
  B_Mux_Bilateral_Ankle_Exo_T *localB);
extern void Bilateral_Ankle_E_Filter_L_Init(DW_Filter_L_Bilateral_Ankle_E_T
  *localDW);
extern void Bilateral_Ankle_Exo_Filter_L(boolean_T rtu_signal,
  B_Filter_L_Bilateral_Ankle_Ex_T *localB, DW_Filter_L_Bilateral_Ankle_E_T
  *localDW);
extern void Bilateral_Ankle_Exo_Mux1(real_T rtu_x1, real_T rtu_x2, real_T rtu_x3,
  B_Mux1_Bilateral_Ankle_Exo_T *localB);
extern void Bilateral_Ankle_Exo_Mux1_p(real_T rtu_x1, real_T rtu_x2, real_T
  rtu_x3, real_T rtu_x4, B_Mux1_Bilateral_Ankle_Exo_c_T *localB);
extern void Bilateral_Ankle__MATLABFunction(const real_T rtu_torque[2], const
  real_T rtu_motor[3], real_T rtu_motor_vel_cmd, B_MATLABFunction_Bilateral_An_T
  *localB, real_T rtp_MAX_MOTOR_ANGLE, real_T rtp_MAX_SPEED, real_T
  rtp_MAX_TORQUE, real_T rtp_MIN_MOTOR_ANGLE);
extern void Bilateral_An_ControlModule_Init(void);
extern void Bilateral_A_ControlModule_Reset(void);
extern void Bilateral_Ankle_E_ControlModule(void);
extern void Bilateral_An_ControlModule_Term(void);

/* private model entry point functions */
extern void Bilateral_Ankle_Exo_derivatives(void);

#endif                                 /* RTW_HEADER_Bilateral_Ankle_Exo_private_h_ */
