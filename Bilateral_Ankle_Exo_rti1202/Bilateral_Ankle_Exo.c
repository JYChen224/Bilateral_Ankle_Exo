/*
 * Bilateral_Ankle_Exo.c
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

#include "Bilateral_Ankle_Exo_trc_ptr.h"
#include "Bilateral_Ankle_Exo.h"
#include "Bilateral_Ankle_Exo_private.h"

/* Block signals (auto storage) */
B_Bilateral_Ankle_Exo_T Bilateral_Ankle_Exo_B;

/* Continuous states */
X_Bilateral_Ankle_Exo_T Bilateral_Ankle_Exo_X;

/* Block states (auto storage) */
DW_Bilateral_Ankle_Exo_T Bilateral_Ankle_Exo_DW;

/* Real-time model */
RT_MODEL_Bilateral_Ankle_Exo_T Bilateral_Ankle_Exo_M_;
RT_MODEL_Bilateral_Ankle_Exo_T *const Bilateral_Ankle_Exo_M =
  &Bilateral_Ankle_Exo_M_;

/* Forward declaration for local functions */
static void Bilateral_Ankle_Exo_mldivide(const real_T A[16], real_T B[4]);
static void Bilateral_Ankle_Exo_power(const real_T a_data[], const int32_T
  a_size[2], real_T y_data[], int32_T y_size[2]);
static void Bilateral_Ankle_Exo_power_e(const real_T a_data[], const int32_T
  a_size[2], real_T y_data[], int32_T y_size[2]);
static void Bilateral_Ankle_Exo_mldivide_l(const real_T A[16], real_T B[4]);
static void Bilateral_Ankle_Exo_power_j(const real_T a_data[], const int32_T
  a_size[2], real_T y_data[], int32_T y_size[2]);
static void Bilateral_Ankle_Exo_power_ju(const real_T a_data[], const int32_T
  a_size[2], real_T y_data[], int32_T y_size[2]);

/* Forward declaration for local functions */
static real_T Bilateral_Ankle_Exo_xnrm2(const real_T x[30], int32_T ix0);
static real_T Bilateral_Ankle_Exo_xnrm2_o(int32_T n, const real_T x[30], int32_T
  ix0);
static void Bilateral_Ankle_Exo_xgeqp3(real_T A[30], real_T tau[2], int32_T
  jpvt[2]);
static void rate_scheduler(void);

/*
 *   This function updates active task flag for each subrate.
 * The function is called at model base rate, hence the
 * generated code self-manages all its subrates.
 */
static void rate_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (Bilateral_Ankle_Exo_M->Timing.TaskCounters.TID[2])++;
  if ((Bilateral_Ankle_Exo_M->Timing.TaskCounters.TID[2]) > 9) {/* Sample time: [0.002s, 0.0s] */
    Bilateral_Ankle_Exo_M->Timing.TaskCounters.TID[2] = 0;
  }
}

/*
 * This function updates continuous states using the ODE1 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE1_IntgData *id = (ODE1_IntgData *)rtsiGetSolverData(si);
  real_T *f0 = id->f[0];
  int_T i;
  int_T nXc = 24;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  Bilateral_Ankle_Exo_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; ++i) {
    x[i] += h * f0[i];
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/*
 * Output and update for atomic system:
 *    '<S28>/Mux'
 *    '<S28>/Mux1'
 *    '<S33>/Mux_L'
 *    '<S33>/Mux_R'
 */
void Bilateral_Ankle_Exo_Mux(real_T rtu_x1, real_T rtu_x2,
  B_Mux_Bilateral_Ankle_Exo_T *localB)
{
  /* MATLAB Function 'Sensor Data/Ankle Encoder/Mux': '<S40>:1' */
  /* '<S40>:1:3' */
  localB->x[0] = rtu_x1;
  localB->x[1] = rtu_x2;
}

/*
 * System initialize for atomic system:
 *    '<S30>/Filter_L'
 *    '<S30>/Filter_R'
 */
void Bilateral_Ankle_E_Filter_L_Init(DW_Filter_L_Bilateral_Ankle_E_T *localDW)
{
  localDW->foot_state = 0.0;
  localDW->filter_time = 0.0;
}

/*
 * Output and update for atomic system:
 *    '<S30>/Filter_L'
 *    '<S30>/Filter_R'
 */
void Bilateral_Ankle_Exo_Filter_L(boolean_T rtu_signal,
  B_Filter_L_Bilateral_Ankle_Ex_T *localB, DW_Filter_L_Bilateral_Ankle_E_T
  *localDW)
{
  /* MATLAB Function 'Sensor Data/FootSwitch module/Filter_L': '<S64>:1' */
  /* '<S64>:1:6' */
  if (localDW->foot_state == 0.0) {
    /* '<S64>:1:15' */
    if (rtu_signal) {
      /* '<S64>:1:16' */
      /* '<S64>:1:17' */
      localDW->foot_state = 1.0;
    } else {
      /* '<S64>:1:19' */
      localDW->foot_state = 0.0;
    }
  } else if (rtu_signal) {
    /* '<S64>:1:22' */
    /* '<S64>:1:23' */
    localDW->foot_state = 1.0;
  } else {
    /* '<S64>:1:25' */
    localDW->filter_time += 0.0002;
    if (localDW->filter_time > 0.1) {
      /* '<S64>:1:26' */
      /* '<S64>:1:27' */
      localDW->filter_time = 0.0;

      /* '<S64>:1:28' */
      localDW->foot_state = 0.0;
    }
  }

  /* '<S64>:1:33' */
  localB->state = localDW->foot_state;
}

/*
 * Output and update for atomic system:
 *    '<S32>/Mux1'
 *    '<S32>/Mux3'
 */
void Bilateral_Ankle_Exo_Mux1(real_T rtu_x1, real_T rtu_x2, real_T rtu_x3,
  B_Mux1_Bilateral_Ankle_Exo_T *localB)
{
  /* MATLAB Function 'Sensor Data/Motor Encoder/Mux1': '<S84>:1' */
  /* '<S84>:1:3' */
  localB->x[0] = rtu_x1;
  localB->x[1] = rtu_x2;
  localB->x[2] = rtu_x3;
}

/*
 * Output and update for atomic system:
 *    '<S6>/Mux1'
 *    '<S7>/Mux1'
 */
void Bilateral_Ankle_Exo_Mux1_p(real_T rtu_x1, real_T rtu_x2, real_T rtu_x3,
  real_T rtu_x4, B_Mux1_Bilateral_Ankle_Exo_c_T *localB)
{
  /* MATLAB Function 'State_Module_l/Mux1': '<S96>:1' */
  /* '<S96>:1:3' */
  localB->x[0] = rtu_x1;
  localB->x[1] = rtu_x2;
  localB->x[2] = rtu_x3;
  localB->x[3] = rtu_x4;
}

/*
 * Output and update for atomic system:
 *    '<S13>/MATLAB Function'
 *    '<S14>/MATLAB Function'
 */
void Bilateral_Ankle__MATLABFunction(const real_T rtu_torque[2], const real_T
  rtu_motor[3], real_T rtu_motor_vel_cmd, B_MATLABFunction_Bilateral_An_T
  *localB, real_T rtp_MAX_MOTOR_ANGLE, real_T rtp_MAX_SPEED, real_T
  rtp_MAX_TORQUE, real_T rtp_MIN_MOTOR_ANGLE)
{
  /* MATLAB Function 'Control Module/Motor_L/MATLAB Function': '<S18>:1' */
  /* '<S18>:1:3' */
  /* '<S18>:1:4' */
  if (rtu_torque[0] > rtp_MAX_TORQUE) {
    /* '<S18>:1:6' */
    /* '<S18>:1:7' */
    localB->vel = 0.0;
  } else if (rtu_motor[0] > rtp_MAX_MOTOR_ANGLE) {
    /* '<S18>:1:8' */
    /* '<S18>:1:9' */
    localB->vel = 0.0;
  } else if (rtu_motor[0] < rtp_MIN_MOTOR_ANGLE) {
    /* '<S18>:1:10' */
    /* '<S18>:1:11' */
    localB->vel = 0.0;
  } else if (rtu_motor_vel_cmd > rtp_MAX_SPEED) {
    /* '<S18>:1:12' */
    /* '<S18>:1:13' */
    localB->vel = rtp_MAX_SPEED;
  } else if (rtu_motor_vel_cmd < -rtp_MAX_SPEED) {
    /* '<S18>:1:14' */
    /* '<S18>:1:15' */
    localB->vel = -rtp_MAX_SPEED;
  } else {
    /* '<S18>:1:17' */
    localB->vel = rtu_motor_vel_cmd;
  }
}

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

real_T rt_powd_snf(real_T u0, real_T u1)
{
  real_T y;
  real_T tmp;
  real_T tmp_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else {
    tmp = fabs(u0);
    tmp_0 = fabs(u1);
    if (rtIsInf(u1)) {
      if (tmp == 1.0) {
        y = 1.0;
      } else if (tmp > 1.0) {
        if (u1 > 0.0) {
          y = (rtInf);
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = (rtInf);
      }
    } else if (tmp_0 == 0.0) {
      y = 1.0;
    } else if (tmp_0 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > floor(u1))) {
      y = (rtNaN);
    } else {
      y = pow(u0, u1);
    }
  }

  return y;
}

/* Function for MATLAB Function: '<S1>/Torque Track L' */
static void Bilateral_Ankle_Exo_mldivide(const real_T A[16], real_T B[4])
{
  real_T b_A[16];
  int8_T ipiv[4];
  int32_T j;
  int32_T ix;
  real_T smax;
  real_T s;
  int32_T k;
  int32_T iy;
  int32_T c_ix;
  int32_T d;
  int32_T ijA;
  int32_T kAcol;
  memcpy(&b_A[0], &A[0], sizeof(real_T) << 4U);
  ipiv[0] = 1;
  ipiv[1] = 2;
  ipiv[2] = 3;
  for (j = 0; j < 3; j++) {
    kAcol = j * 5;
    iy = 0;
    ix = kAcol;
    smax = fabs(b_A[kAcol]);
    for (k = 2; k <= 4 - j; k++) {
      ix++;
      s = fabs(b_A[ix]);
      if (s > smax) {
        iy = k - 1;
        smax = s;
      }
    }

    if (b_A[kAcol + iy] != 0.0) {
      if (iy != 0) {
        ipiv[j] = (int8_T)((j + iy) + 1);
        ix = j;
        iy += j;
        smax = b_A[ix];
        b_A[ix] = b_A[iy];
        b_A[iy] = smax;
        ix += 4;
        iy += 4;
        smax = b_A[ix];
        b_A[ix] = b_A[iy];
        b_A[iy] = smax;
        ix += 4;
        iy += 4;
        smax = b_A[ix];
        b_A[ix] = b_A[iy];
        b_A[iy] = smax;
        ix += 4;
        iy += 4;
        smax = b_A[ix];
        b_A[ix] = b_A[iy];
        b_A[iy] = smax;
      }

      iy = (kAcol - j) + 4;
      for (ix = kAcol + 1; ix + 1 <= iy; ix++) {
        b_A[ix] /= b_A[kAcol];
      }
    }

    iy = kAcol;
    ix = kAcol + 4;
    for (k = 1; k <= 3 - j; k++) {
      smax = b_A[ix];
      if (b_A[ix] != 0.0) {
        c_ix = kAcol + 1;
        d = (iy - j) + 8;
        for (ijA = 5 + iy; ijA + 1 <= d; ijA++) {
          b_A[ijA] += b_A[c_ix] * -smax;
          c_ix++;
        }
      }

      ix += 4;
      iy += 4;
    }
  }

  if (ipiv[0] != 1) {
    smax = B[0];
    B[0] = B[ipiv[0] - 1];
    B[ipiv[0] - 1] = smax;
  }

  if (ipiv[1] != 2) {
    smax = B[1];
    B[1] = B[ipiv[1] - 1];
    B[ipiv[1] - 1] = smax;
  }

  if (ipiv[2] != 3) {
    smax = B[2];
    B[2] = B[ipiv[2] - 1];
    B[ipiv[2] - 1] = smax;
  }

  if (B[0] != 0.0) {
    for (iy = 1; iy + 1 < 5; iy++) {
      B[iy] -= B[0] * b_A[iy];
    }
  }

  if (B[1] != 0.0) {
    for (iy = 2; iy + 1 < 5; iy++) {
      B[iy] -= b_A[iy + 4] * B[1];
    }
  }

  if (B[2] != 0.0) {
    for (iy = 3; iy + 1 < 5; iy++) {
      B[iy] -= b_A[iy + 8] * B[2];
    }
  }

  if (B[3] != 0.0) {
    B[3] /= b_A[15];
    for (iy = 0; iy + 1 < 4; iy++) {
      B[iy] -= b_A[iy + 12] * B[3];
    }
  }

  if (B[2] != 0.0) {
    B[2] /= b_A[10];
    for (iy = 0; iy + 1 < 3; iy++) {
      B[iy] -= b_A[iy + 8] * B[2];
    }
  }

  if (B[1] != 0.0) {
    B[1] /= b_A[5];
    for (iy = 0; iy + 1 < 2; iy++) {
      B[iy] -= b_A[iy + 4] * B[1];
    }
  }

  if (B[0] != 0.0) {
    B[0] /= b_A[0];
  }
}

/* Function for MATLAB Function: '<S1>/Torque Track L' */
static void Bilateral_Ankle_Exo_power(const real_T a_data[], const int32_T
  a_size[2], real_T y_data[], int32_T y_size[2])
{
  int32_T loop_ub;
  int32_T z1_size_idx_1;
  y_size[1] = (int16_T)a_size[1];
  z1_size_idx_1 = y_size[1];
  loop_ub = y_size[1];
  if (0 <= loop_ub - 1) {
    memcpy(&Bilateral_Ankle_Exo_B.z1_data[0], &y_data[0], loop_ub * sizeof
           (real_T));
  }

  for (loop_ub = 0; loop_ub + 1 <= y_size[1]; loop_ub++) {
    Bilateral_Ankle_Exo_B.z1_data[loop_ub] = a_data[loop_ub] * a_data[loop_ub];
  }

  y_size[0] = 1;
  y_size[1] = z1_size_idx_1;
  if (0 <= z1_size_idx_1 - 1) {
    memcpy(&y_data[0], &Bilateral_Ankle_Exo_B.z1_data[0], z1_size_idx_1 * sizeof
           (real_T));
  }
}

/* Function for MATLAB Function: '<S1>/Torque Track L' */
static void Bilateral_Ankle_Exo_power_e(const real_T a_data[], const int32_T
  a_size[2], real_T y_data[], int32_T y_size[2])
{
  int32_T loop_ub;
  int32_T z1_size_idx_1;
  y_size[1] = (int16_T)a_size[1];
  z1_size_idx_1 = y_size[1];
  loop_ub = y_size[1];
  if (0 <= loop_ub - 1) {
    memcpy(&Bilateral_Ankle_Exo_B.z1_data_b[0], &y_data[0], loop_ub * sizeof
           (real_T));
  }

  for (loop_ub = 0; loop_ub + 1 <= y_size[1]; loop_ub++) {
    Bilateral_Ankle_Exo_B.z1_data_b[loop_ub] = rt_powd_snf(a_data[loop_ub], 3.0);
  }

  y_size[0] = 1;
  y_size[1] = z1_size_idx_1;
  if (0 <= z1_size_idx_1 - 1) {
    memcpy(&y_data[0], &Bilateral_Ankle_Exo_B.z1_data_b[0], z1_size_idx_1 *
           sizeof(real_T));
  }
}

/* Function for MATLAB Function: '<S1>/Torque Track R' */
static void Bilateral_Ankle_Exo_mldivide_l(const real_T A[16], real_T B[4])
{
  real_T b_A[16];
  int8_T ipiv[4];
  int32_T j;
  int32_T ix;
  real_T smax;
  real_T s;
  int32_T k;
  int32_T iy;
  int32_T c_ix;
  int32_T d;
  int32_T ijA;
  int32_T kAcol;
  memcpy(&b_A[0], &A[0], sizeof(real_T) << 4U);
  ipiv[0] = 1;
  ipiv[1] = 2;
  ipiv[2] = 3;
  for (j = 0; j < 3; j++) {
    kAcol = j * 5;
    iy = 0;
    ix = kAcol;
    smax = fabs(b_A[kAcol]);
    for (k = 2; k <= 4 - j; k++) {
      ix++;
      s = fabs(b_A[ix]);
      if (s > smax) {
        iy = k - 1;
        smax = s;
      }
    }

    if (b_A[kAcol + iy] != 0.0) {
      if (iy != 0) {
        ipiv[j] = (int8_T)((j + iy) + 1);
        ix = j;
        iy += j;
        smax = b_A[ix];
        b_A[ix] = b_A[iy];
        b_A[iy] = smax;
        ix += 4;
        iy += 4;
        smax = b_A[ix];
        b_A[ix] = b_A[iy];
        b_A[iy] = smax;
        ix += 4;
        iy += 4;
        smax = b_A[ix];
        b_A[ix] = b_A[iy];
        b_A[iy] = smax;
        ix += 4;
        iy += 4;
        smax = b_A[ix];
        b_A[ix] = b_A[iy];
        b_A[iy] = smax;
      }

      iy = (kAcol - j) + 4;
      for (ix = kAcol + 1; ix + 1 <= iy; ix++) {
        b_A[ix] /= b_A[kAcol];
      }
    }

    iy = kAcol;
    ix = kAcol + 4;
    for (k = 1; k <= 3 - j; k++) {
      smax = b_A[ix];
      if (b_A[ix] != 0.0) {
        c_ix = kAcol + 1;
        d = (iy - j) + 8;
        for (ijA = 5 + iy; ijA + 1 <= d; ijA++) {
          b_A[ijA] += b_A[c_ix] * -smax;
          c_ix++;
        }
      }

      ix += 4;
      iy += 4;
    }
  }

  if (ipiv[0] != 1) {
    smax = B[0];
    B[0] = B[ipiv[0] - 1];
    B[ipiv[0] - 1] = smax;
  }

  if (ipiv[1] != 2) {
    smax = B[1];
    B[1] = B[ipiv[1] - 1];
    B[ipiv[1] - 1] = smax;
  }

  if (ipiv[2] != 3) {
    smax = B[2];
    B[2] = B[ipiv[2] - 1];
    B[ipiv[2] - 1] = smax;
  }

  if (B[0] != 0.0) {
    for (iy = 1; iy + 1 < 5; iy++) {
      B[iy] -= B[0] * b_A[iy];
    }
  }

  if (B[1] != 0.0) {
    for (iy = 2; iy + 1 < 5; iy++) {
      B[iy] -= b_A[iy + 4] * B[1];
    }
  }

  if (B[2] != 0.0) {
    for (iy = 3; iy + 1 < 5; iy++) {
      B[iy] -= b_A[iy + 8] * B[2];
    }
  }

  if (B[3] != 0.0) {
    B[3] /= b_A[15];
    for (iy = 0; iy + 1 < 4; iy++) {
      B[iy] -= b_A[iy + 12] * B[3];
    }
  }

  if (B[2] != 0.0) {
    B[2] /= b_A[10];
    for (iy = 0; iy + 1 < 3; iy++) {
      B[iy] -= b_A[iy + 8] * B[2];
    }
  }

  if (B[1] != 0.0) {
    B[1] /= b_A[5];
    for (iy = 0; iy + 1 < 2; iy++) {
      B[iy] -= b_A[iy + 4] * B[1];
    }
  }

  if (B[0] != 0.0) {
    B[0] /= b_A[0];
  }
}

/* Function for MATLAB Function: '<S1>/Torque Track R' */
static void Bilateral_Ankle_Exo_power_j(const real_T a_data[], const int32_T
  a_size[2], real_T y_data[], int32_T y_size[2])
{
  int32_T loop_ub;
  int32_T z1_size_idx_1;
  y_size[1] = (int16_T)a_size[1];
  z1_size_idx_1 = y_size[1];
  loop_ub = y_size[1];
  if (0 <= loop_ub - 1) {
    memcpy(&Bilateral_Ankle_Exo_B.z1_data_p[0], &y_data[0], loop_ub * sizeof
           (real_T));
  }

  for (loop_ub = 0; loop_ub + 1 <= y_size[1]; loop_ub++) {
    Bilateral_Ankle_Exo_B.z1_data_p[loop_ub] = a_data[loop_ub] * a_data[loop_ub];
  }

  y_size[0] = 1;
  y_size[1] = z1_size_idx_1;
  if (0 <= z1_size_idx_1 - 1) {
    memcpy(&y_data[0], &Bilateral_Ankle_Exo_B.z1_data_p[0], z1_size_idx_1 *
           sizeof(real_T));
  }
}

/* Function for MATLAB Function: '<S1>/Torque Track R' */
static void Bilateral_Ankle_Exo_power_ju(const real_T a_data[], const int32_T
  a_size[2], real_T y_data[], int32_T y_size[2])
{
  int32_T loop_ub;
  int32_T z1_size_idx_1;
  y_size[1] = (int16_T)a_size[1];
  z1_size_idx_1 = y_size[1];
  loop_ub = y_size[1];
  if (0 <= loop_ub - 1) {
    memcpy(&Bilateral_Ankle_Exo_B.z1_data_c[0], &y_data[0], loop_ub * sizeof
           (real_T));
  }

  for (loop_ub = 0; loop_ub + 1 <= y_size[1]; loop_ub++) {
    Bilateral_Ankle_Exo_B.z1_data_c[loop_ub] = rt_powd_snf(a_data[loop_ub], 3.0);
  }

  y_size[0] = 1;
  y_size[1] = z1_size_idx_1;
  if (0 <= z1_size_idx_1 - 1) {
    memcpy(&y_data[0], &Bilateral_Ankle_Exo_B.z1_data_c[0], z1_size_idx_1 *
           sizeof(real_T));
  }
}

/* System initialize for function-call system: '<Root>/Control Module' */
void Bilateral_An_ControlModule_Init(void)
{
  /* SystemInitialize for MATLAB Function: '<S1>/LRN_L' */
  Bilateral_Ankle_Exo_DW.last_footstate_not_empty_o = false;
  Bilateral_Ankle_Exo_DW.last_footstate_g = 0.0;

  /* SystemInitialize for MATLAB Function: '<S1>/Torque Track L' */
  Bilateral_Ankle_Exo_DW.last_footstate_h = 0.0;

  /* SystemInitialize for MATLAB Function: '<S1>/Controller_L' */
  Bilateral_Ankle_Exo_DW.calib_state_p = 0.0;
  Bilateral_Ankle_Exo_DW.smooth_filter_b = 0.0;

  /* SystemInitialize for MATLAB Function: '<S1>/Torque Track R' */
  Bilateral_Ankle_Exo_DW.last_footstate = 0.0;

  /* SystemInitialize for MATLAB Function: '<S1>/LRN_R' */
  Bilateral_Ankle_Exo_DW.last_footstate_not_empty = false;
  Bilateral_Ankle_Exo_DW.last_footstate_a = 0.0;

  /* SystemInitialize for MATLAB Function: '<S1>/LRN_L' */
  memset(&Bilateral_Ankle_Exo_DW.torque_error_memory_h[0], 0, 1000U * sizeof
         (real_T));
  memset(&Bilateral_Ankle_Exo_DW.lrn_cmd_memory_n[0], 0, 1000U * sizeof(real_T));

  /* SystemInitialize for MATLAB Function: '<S1>/LRN_R' */
  memset(&Bilateral_Ankle_Exo_DW.torque_error_memory[0], 0, 1000U * sizeof
         (real_T));
  memset(&Bilateral_Ankle_Exo_DW.lrn_cmd_memory[0], 0, 1000U * sizeof(real_T));

  /* SystemInitialize for MATLAB Function: '<S1>/Controller_R' */
  Bilateral_Ankle_Exo_DW.calib_state = 0.0;
  Bilateral_Ankle_Exo_DW.smooth_filter = 0.0;
}

/* System reset for function-call system: '<Root>/Control Module' */
void Bilateral_A_ControlModule_Reset(void)
{
  /* SystemReset for MATLAB Function: '<S1>/LRN_L' */
  Bilateral_Ankle_Exo_DW.last_footstate_not_empty_o = false;
  Bilateral_Ankle_Exo_DW.last_footstate_g = 0.0;

  /* SystemReset for MATLAB Function: '<S1>/Torque Track L' */
  Bilateral_Ankle_Exo_DW.last_footstate_h = 0.0;

  /* SystemReset for MATLAB Function: '<S1>/Controller_L' */
  Bilateral_Ankle_Exo_DW.calib_state_p = 0.0;
  Bilateral_Ankle_Exo_DW.smooth_filter_b = 0.0;

  /* SystemReset for MATLAB Function: '<S1>/Torque Track R' */
  Bilateral_Ankle_Exo_DW.last_footstate = 0.0;

  /* SystemReset for MATLAB Function: '<S1>/LRN_R' */
  Bilateral_Ankle_Exo_DW.last_footstate_not_empty = false;
  Bilateral_Ankle_Exo_DW.last_footstate_a = 0.0;

  /* SystemReset for MATLAB Function: '<S1>/LRN_L' */
  memset(&Bilateral_Ankle_Exo_DW.torque_error_memory_h[0], 0, 1000U * sizeof
         (real_T));
  memset(&Bilateral_Ankle_Exo_DW.lrn_cmd_memory_n[0], 0, 1000U * sizeof(real_T));

  /* SystemReset for MATLAB Function: '<S1>/LRN_R' */
  memset(&Bilateral_Ankle_Exo_DW.torque_error_memory[0], 0, 1000U * sizeof
         (real_T));
  memset(&Bilateral_Ankle_Exo_DW.lrn_cmd_memory[0], 0, 1000U * sizeof(real_T));

  /* SystemReset for MATLAB Function: '<S1>/Controller_R' */
  Bilateral_Ankle_Exo_DW.calib_state = 0.0;
  Bilateral_Ankle_Exo_DW.smooth_filter = 0.0;
}

/* Output and update for function-call system: '<Root>/Control Module' */
void Bilateral_Ankle_E_ControlModule(void)
{
  real_T stride_index;
  real_T mode;
  real_T footstate;
  real_T peak_torque;
  real_T torque_measure;
  real_T troque_delta;
  real_T index_peak;
  real_T index_rise;
  real_T index_fall;
  real_T parm1[4];
  real_T c;
  int32_T e;
  int32_T g;
  int32_T i;
  int32_T b_n;
  int32_T br;
  int32_T ar;
  int32_T ia;
  real_T tmp[16];
  int16_T tmp_data[750];
  int32_T loop_ub;
  int32_T tmp_size[2];
  int32_T tmp_size_0[2];
  int32_T tmp_size_1[2];
  int32_T tmp_size_2[2];
  int32_T tmp_size_3[2];
  int32_T tmp_size_4[2];
  int32_T tmp_size_5[2];
  int32_T tmp_size_6[2];
  int32_T tmp_size_7[2];
  int32_T tmp_size_8[2];
  int32_T tmp_size_9[2];
  int32_T tmp_size_idx_1;
  int16_T tmp_0;
  int32_T q1;

  /* MATLAB Function: '<S1>/LRN_L' */
  /* MATLAB Function 'Control Module/LRN_L': '<S11>:1' */
  if (!Bilateral_Ankle_Exo_DW.last_footstate_not_empty_o) {
    /* '<S11>:1:10' */
    Bilateral_Ankle_Exo_DW.last_footstate_not_empty_o = true;

    /* '<S11>:1:14' */
    Bilateral_Ankle_Exo_DW.last_torque_parm_m[0] = Bilateral_Ankle_Exo_B.RT3[0];
    Bilateral_Ankle_Exo_DW.last_torque_parm_m[1] = Bilateral_Ankle_Exo_B.RT3[2];
  }

  /* '<S11>:1:18' */
  /* '<S11>:1:22' */
  /* '<S11>:1:25' */
  /* '<S11>:1:26' */
  /* '<S11>:1:28' */
  /* '<S11>:1:30' */
  /* '<S11>:1:32' */
  stride_index = Bilateral_Ankle_Exo_B.RT7[3] * 500.0 + 1.0;
  if (stride_index > 750.0) {
    /* '<S11>:1:33' */
    /* '<S11>:1:34' */
    stride_index = 750.0;
  }

  if ((Bilateral_Ankle_Exo_DW.last_footstate_g == 0.0) &&
      (Bilateral_Ankle_Exo_B.RT7[1] == 1.0) && (Bilateral_Ankle_Exo_B.RT7[0] ==
       2.0) && Bilateral_Ankle_Exo_P.LRN_L_BT_LRN_ON_L) {
    /* '<S11>:1:37' */
    /* '<S11>:1:38' */
    /* '<S11>:1:39' */
    mode = 1.0 - Bilateral_Ankle_Exo_P.LRN_L_error_filter_k_l;

    /* '<S11>:1:40' */
    footstate = Bilateral_Ankle_Exo_B.RT2[2];
    for (g = 0; g < 750; g++) {
      peak_torque = (Bilateral_Ankle_Exo_DW.TorqueMem_L[g << 2] -
                     Bilateral_Ankle_Exo_DW.TorqueMem_L[(g << 2) + 1]) *
        Bilateral_Ankle_Exo_P.LRN_L_error_filter_k_l + mode *
        Bilateral_Ankle_Exo_DW.torque_error_memory_h[g];
      Bilateral_Ankle_Exo_DW.torque_error_memory_h[g] = peak_torque;
      Bilateral_Ankle_Exo_DW.lrn_cmd_memory_n[g] =
        Bilateral_Ankle_Exo_P.LRN_L_lrn_shrink_l *
        Bilateral_Ankle_Exo_DW.lrn_cmd_memory_n[g] + footstate *
        Bilateral_Ankle_Exo_DW.torque_error_memory_h[g];
    }
  }

  if (Bilateral_Ankle_Exo_P.LRN_L_BT_LRN_CLEAR_L ||
      (Bilateral_Ankle_Exo_DW.last_torque_parm_m[0] !=
       Bilateral_Ankle_Exo_B.RT3[0]) ||
      (Bilateral_Ankle_Exo_DW.last_torque_parm_m[1] !=
       Bilateral_Ankle_Exo_B.RT3[2])) {
    /* '<S11>:1:43' */
    /* '<S11>:1:44' */
    /* '<S11>:1:45' */
    memset(&Bilateral_Ankle_Exo_DW.torque_error_memory_h[0], 0, 1000U * sizeof
           (real_T));
    memset(&Bilateral_Ankle_Exo_DW.lrn_cmd_memory_n[0], 0, 1000U * sizeof(real_T));
  }

  if (Bilateral_Ankle_Exo_B.RT7[0] == 2.0) {
    /* '<S11>:1:48' */
    q1 = Bilateral_Ankle_Exo_P.LRN_L_time_delay_l;
    if (q1 < -2147482897) {
      q1 = MAX_int32_T;
    } else {
      q1 = 750 - q1;
    }

    if (stride_index >= q1) {
      /* '<S11>:1:49' */
      /* '<S11>:1:50' */
      Bilateral_Ankle_Exo_B.lrn_cmd_l = 0.0;
    } else {
      /* '<S11>:1:52' */
      mode = rt_roundd_snf(stride_index + (real_T)
                           Bilateral_Ankle_Exo_P.LRN_L_time_delay_l);
      if (mode < 2.147483648E+9) {
        if (mode >= -2.147483648E+9) {
          g = (int32_T)mode;
        } else {
          g = MIN_int32_T;
        }
      } else {
        g = MAX_int32_T;
      }

      Bilateral_Ankle_Exo_B.lrn_cmd_l =
        Bilateral_Ankle_Exo_DW.lrn_cmd_memory_n[g - 1];
    }
  } else {
    /* '<S11>:1:55' */
    Bilateral_Ankle_Exo_B.lrn_cmd_l = 0.0;
  }

  /* '<S11>:1:58' */
  Bilateral_Ankle_Exo_DW.last_footstate_g = Bilateral_Ankle_Exo_B.RT7[1];

  /* '<S11>:1:59' */
  Bilateral_Ankle_Exo_DW.last_torque_parm_m[0] = Bilateral_Ankle_Exo_B.RT3[0];
  Bilateral_Ankle_Exo_DW.last_torque_parm_m[1] = Bilateral_Ankle_Exo_B.RT3[2];

  /* '<S11>:1:60' */
  memcpy(&Bilateral_Ankle_Exo_B.lrn_mem_l[0],
         &Bilateral_Ankle_Exo_DW.lrn_cmd_memory_n[0], 750U * sizeof(real_T));

  /* End of MATLAB Function: '<S1>/LRN_L' */

  /* MATLAB Function: '<S1>/Torque Track L' incorporates:
   *  Constant: '<S1>/torque_offset'
   */
  /* MATLAB Function 'Control Module/Torque Track L': '<S15>:1' */
  /* '<S15>:1:43' */
  /* '<S15>:1:19' */
  mode = Bilateral_Ankle_Exo_B.RT7[0];

  /* '<S15>:1:20' */
  footstate = Bilateral_Ankle_Exo_B.RT7[1];

  /* '<S15>:1:21' */
  /* '<S15>:1:22' */
  /* '<S15>:1:24' */
  peak_torque = Bilateral_Ankle_Exo_B.RT3[0];

  /* '<S15>:1:25' */
  /* '<S15>:1:26' */
  /* '<S15>:1:27' */
  /* '<S15>:1:29' */
  torque_measure = Bilateral_Ankle_Exo_B.RT8[0];

  /* '<S15>:1:30' */
  troque_delta = Bilateral_Ankle_Exo_B.RT8[1];

  /* '<S15>:1:31' */
  stride_index = Bilateral_Ankle_Exo_B.RT7[3] * 500.0 + 1.0;
  if (stride_index > 750.0) {
    /* '<S15>:1:32' */
    /* '<S15>:1:33' */
    stride_index = 750.0;
  }

  if ((Bilateral_Ankle_Exo_DW.last_footstate_h == 0.0) &&
      (Bilateral_Ankle_Exo_B.RT7[1] == 1.0) && ((Bilateral_Ankle_Exo_B.RT7[0] ==
        2.0) || (Bilateral_Ankle_Exo_B.RT7[0] == 1.0))) {
    /* '<S15>:1:37' */
    /* '<S15>:1:39' */
    /* '<S15>:1:41' */
    memset(&Bilateral_Ankle_Exo_B.torque_track[0], 0, 750U * sizeof(real_T));
    memset(&Bilateral_Ankle_Exo_B.torque_delta_track[0], 0, 750U * sizeof(real_T));

    /* '<S15>:1:42' */
    /* '<S15>:1:43' */
    /* '<S15>:1:44' */
    index_peak = floor(Bilateral_Ankle_Exo_B.RT3[2] / 100.0 *
                       Bilateral_Ankle_Exo_B.RT7[2] * 500.0);

    /* '<S15>:1:45' */
    index_rise = index_peak - floor(Bilateral_Ankle_Exo_B.RT3[1] / 100.0 *
      Bilateral_Ankle_Exo_B.RT7[2] * 500.0);

    /* '<S15>:1:46' */
    index_fall = floor(Bilateral_Ankle_Exo_B.RT3[3] / 100.0 *
                       Bilateral_Ankle_Exo_B.RT7[2] * 500.0) + index_peak;
    if (1.0 > index_rise - 1.0) {
      q1 = 0;
    } else {
      q1 = (int32_T)(index_rise - 1.0);
    }

    /* '<S15>:1:49' */
    for (g = 0; g < q1; g++) {
      Bilateral_Ankle_Exo_B.tmp_data_cx[g] = (real_T)(int16_T)(1 + (int16_T)g) /
        index_rise * Bilateral_Ankle_Exo_P.torque_offset_Value;
    }

    if (0 <= q1 - 1) {
      memcpy(&Bilateral_Ankle_Exo_B.torque_track[0],
             &Bilateral_Ankle_Exo_B.tmp_data_cx[0], q1 * sizeof(real_T));
    }

    /* '<S15>:1:53' */
    /* '<S15>:1:57' */
    /* '<S15>:1:58' */
    parm1[0] = Bilateral_Ankle_Exo_P.torque_offset_Value;
    parm1[1] = Bilateral_Ankle_Exo_B.RT3[0];
    parm1[2] = 0.0;
    parm1[3] = 0.0;
    tmp[0] = 1.0;
    tmp[4] = index_rise;
    tmp[8] = index_rise * index_rise;
    tmp[12] = rt_powd_snf(index_rise, 3.0);
    tmp[1] = 1.0;
    tmp[5] = index_peak;
    tmp[9] = index_peak * index_peak;
    tmp[13] = rt_powd_snf(index_peak, 3.0);
    tmp[2] = 0.0;
    tmp[6] = 1.0;
    tmp[10] = 2.0 * index_rise;
    tmp[14] = index_rise * index_rise * 3.0;
    tmp[3] = 0.0;
    tmp[7] = 1.0;
    tmp[11] = 2.0 * index_peak;
    tmp[15] = index_peak * index_peak * 3.0;
    Bilateral_Ankle_Exo_mldivide(tmp, parm1);
    c = index_peak - index_rise;
    if (1.0 > c) {
      b_n = 0;
    } else {
      b_n = (int32_T)c;
    }

    if (index_rise > index_peak - 1.0) {
      br = 1;
      e = 0;
      ar = 0;
      g = 0;
      ia = 0;
      i = 0;
      q1 = 0;
    } else {
      br = (int32_T)index_rise;
      e = (int32_T)(index_peak - 1.0);
      ar = (int32_T)index_rise - 1;
      g = (int32_T)(index_peak - 1.0);
      ia = (int32_T)index_rise - 1;
      i = (int32_T)(index_peak - 1.0);
      q1 = (int32_T)index_rise - 1;
    }

    tmp_size_idx_1 = g - ar;
    loop_ub = g - ar;
    for (g = 0; g < loop_ub; g++) {
      tmp_data[g] = (int16_T)((int16_T)(ar + g) + 1);
    }

    tmp_size_7[0] = 1;
    tmp_size_7[1] = tmp_size_idx_1;
    for (g = 0; g < tmp_size_idx_1; g++) {
      Bilateral_Ankle_Exo_B.tmp_data_cx[g] = tmp_data[g];
    }

    Bilateral_Ankle_Exo_power(Bilateral_Ankle_Exo_B.tmp_data_cx, tmp_size_7,
      Bilateral_Ankle_Exo_B.tmp_data_c, tmp_size_8);
    tmp_size_idx_1 = i - ia;
    loop_ub = i - ia;
    for (g = 0; g < loop_ub; g++) {
      tmp_data[g] = (int16_T)((int16_T)(ia + g) + 1);
    }

    tmp_size_9[0] = 1;
    tmp_size_9[1] = tmp_size_idx_1;
    for (g = 0; g < tmp_size_idx_1; g++) {
      Bilateral_Ankle_Exo_B.tmp_data_cx[g] = tmp_data[g];
    }

    Bilateral_Ankle_Exo_power_e(Bilateral_Ankle_Exo_B.tmp_data_cx, tmp_size_9,
      Bilateral_Ankle_Exo_B.tmp_data_k, tmp_size_7);
    for (g = 0; g < b_n; g++) {
      Bilateral_Ankle_Exo_B.tmp_data[g << 2] = 1.0;
    }

    loop_ub = e - br;
    for (g = 0; g <= loop_ub; g++) {
      Bilateral_Ankle_Exo_B.tmp_data[1 + (g << 2)] = (int16_T)((int16_T)((br + g)
        - 1) + 1);
    }

    loop_ub = tmp_size_8[1];
    for (g = 0; g < loop_ub; g++) {
      Bilateral_Ankle_Exo_B.tmp_data[2 + (g << 2)] =
        Bilateral_Ankle_Exo_B.tmp_data_c[tmp_size_8[0] * g];
    }

    loop_ub = tmp_size_7[1];
    for (g = 0; g < loop_ub; g++) {
      Bilateral_Ankle_Exo_B.tmp_data[3 + (g << 2)] =
        Bilateral_Ankle_Exo_B.tmp_data_k[tmp_size_7[0] * g];
    }

    br = b_n;
    for (g = 0; g < b_n; g++) {
      Bilateral_Ankle_Exo_B.result_data[g << 2] =
        Bilateral_Ankle_Exo_B.tmp_data[g << 2];
      Bilateral_Ankle_Exo_B.result_data[1 + (g << 2)] =
        Bilateral_Ankle_Exo_B.tmp_data[(g << 2) + 1];
      Bilateral_Ankle_Exo_B.result_data[2 + (g << 2)] =
        Bilateral_Ankle_Exo_B.tmp_data[(g << 2) + 2];
      Bilateral_Ankle_Exo_B.result_data[3 + (g << 2)] =
        Bilateral_Ankle_Exo_B.tmp_data[(g << 2) + 3];
    }

    tmp_0 = (int16_T)br;
    tmp_size_idx_1 = tmp_0;
    b_n = br - 1;
    if (0 <= tmp_size_idx_1 - 1) {
      memset(&Bilateral_Ankle_Exo_B.tmp_data_cx[0], 0, tmp_size_idx_1 * sizeof
             (real_T));
    }

    if (br != 0) {
      for (br = 1; br - 1 <= b_n; br++) {
        for (e = br; e <= br; e++) {
          Bilateral_Ankle_Exo_B.tmp_data_cx[e - 1] = 0.0;
        }
      }

      br = 0;
      for (e = 0; e <= b_n; e++) {
        ar = -1;
        for (g = br; g + 1 <= br + 4; g++) {
          if (Bilateral_Ankle_Exo_B.result_data[g] != 0.0) {
            ia = ar;
            for (i = e; i + 1 <= e + 1; i++) {
              ia++;
              Bilateral_Ankle_Exo_B.tmp_data_cx[i] +=
                Bilateral_Ankle_Exo_B.result_data[g] * parm1[ia];
            }
          }

          ar++;
        }

        br += 4;
      }
    }

    /* '<S15>:1:59' */
    for (g = 0; g < tmp_size_idx_1; g++) {
      Bilateral_Ankle_Exo_B.torque_track[q1 + g] =
        Bilateral_Ankle_Exo_B.tmp_data_cx[g];
    }

    c = index_peak - index_rise;
    if (1.0 > c) {
      b_n = 0;
    } else {
      b_n = (int32_T)c;
    }

    if (index_rise > index_peak - 1.0) {
      br = 1;
      e = 0;
      ar = 0;
      g = 0;
      q1 = 0;
    } else {
      br = (int32_T)index_rise;
      e = (int32_T)(index_peak - 1.0);
      ar = (int32_T)index_rise - 1;
      g = (int32_T)(index_peak - 1.0);
      q1 = (int32_T)index_rise - 1;
    }

    tmp_size_idx_1 = g - ar;
    loop_ub = g - ar;
    for (g = 0; g < loop_ub; g++) {
      tmp_data[g] = (int16_T)((int16_T)(ar + g) + 1);
    }

    tmp_size_6[0] = 1;
    tmp_size_6[1] = tmp_size_idx_1;
    for (g = 0; g < tmp_size_idx_1; g++) {
      Bilateral_Ankle_Exo_B.tmp_data_cx[g] = tmp_data[g];
    }

    Bilateral_Ankle_Exo_power(Bilateral_Ankle_Exo_B.tmp_data_cx, tmp_size_6,
      Bilateral_Ankle_Exo_B.tmp_data_c, tmp_size_7);
    for (g = 0; g < b_n; g++) {
      Bilateral_Ankle_Exo_B.tmp_data_m[3 * g] = 1.0;
    }

    loop_ub = e - br;
    for (g = 0; g <= loop_ub; g++) {
      Bilateral_Ankle_Exo_B.tmp_data_m[1 + 3 * g] = (real_T)(int16_T)((int16_T)
        ((br + g) - 1) + 1) * 2.0;
    }

    loop_ub = tmp_size_7[1];
    for (g = 0; g < loop_ub; g++) {
      Bilateral_Ankle_Exo_B.tmp_data_m[2 + 3 * g] =
        Bilateral_Ankle_Exo_B.tmp_data_c[tmp_size_7[0] * g] * 3.0;
    }

    br = b_n;
    for (g = 0; g < b_n; g++) {
      Bilateral_Ankle_Exo_B.b_result_data[3 * g] =
        Bilateral_Ankle_Exo_B.tmp_data_m[3 * g];
      Bilateral_Ankle_Exo_B.b_result_data[1 + 3 * g] =
        Bilateral_Ankle_Exo_B.tmp_data_m[3 * g + 1];
      Bilateral_Ankle_Exo_B.b_result_data[2 + 3 * g] =
        Bilateral_Ankle_Exo_B.tmp_data_m[3 * g + 2];
    }

    tmp_0 = (int16_T)br;
    tmp_size_idx_1 = tmp_0;
    b_n = br - 1;
    if (0 <= tmp_size_idx_1 - 1) {
      memset(&Bilateral_Ankle_Exo_B.tmp_data_cx[0], 0, tmp_size_idx_1 * sizeof
             (real_T));
    }

    if (br != 0) {
      for (br = 1; br - 1 <= b_n; br++) {
        for (e = br; e <= br; e++) {
          Bilateral_Ankle_Exo_B.tmp_data_cx[e - 1] = 0.0;
        }
      }

      br = 0;
      for (e = 0; e <= b_n; e++) {
        ar = -1;
        for (g = br; g + 1 <= br + 3; g++) {
          if (Bilateral_Ankle_Exo_B.b_result_data[g] != 0.0) {
            ia = ar;
            for (i = e; i + 1 <= e + 1; i++) {
              ia++;
              Bilateral_Ankle_Exo_B.tmp_data_cx[i] += parm1[1 + ia] *
                Bilateral_Ankle_Exo_B.b_result_data[g];
            }
          }

          ar++;
        }

        br += 3;
      }
    }

    /* '<S15>:1:60' */
    for (g = 0; g < tmp_size_idx_1; g++) {
      Bilateral_Ankle_Exo_B.torque_delta_track[q1 + g] =
        Bilateral_Ankle_Exo_B.tmp_data_cx[g] * 500.0;
    }

    /* '<S15>:1:63' */
    /* '<S15>:1:67' */
    /* '<S15>:1:68' */
    parm1[0] = peak_torque;
    parm1[1] = 0.0;
    parm1[2] = 0.0;
    parm1[3] = 0.0;
    tmp[0] = 1.0;
    tmp[4] = index_peak;
    tmp[8] = index_peak * index_peak;
    tmp[12] = rt_powd_snf(index_peak, 3.0);
    tmp[1] = 1.0;
    tmp[5] = index_fall;
    tmp[9] = index_fall * index_fall;
    tmp[13] = rt_powd_snf(index_fall, 3.0);
    tmp[2] = 0.0;
    tmp[6] = 1.0;
    tmp[10] = 2.0 * index_peak;
    tmp[14] = index_peak * index_peak * 3.0;
    tmp[3] = 0.0;
    tmp[7] = 1.0;
    tmp[11] = 2.0 * index_fall;
    tmp[15] = index_fall * index_fall * 3.0;
    Bilateral_Ankle_Exo_mldivide(tmp, parm1);
    peak_torque = (index_fall + 1.0) - index_peak;
    if (1.0 > peak_torque) {
      b_n = 0;
    } else {
      b_n = (int32_T)peak_torque;
    }

    if (index_peak > index_fall) {
      br = 1;
      e = 0;
      ar = 0;
      g = 0;
      ia = 0;
      i = 0;
      q1 = 0;
    } else {
      br = (int32_T)index_peak;
      e = (int32_T)index_fall;
      ar = (int32_T)index_peak - 1;
      g = (int32_T)index_fall;
      ia = (int32_T)index_peak - 1;
      i = (int32_T)index_fall;
      q1 = (int32_T)index_peak - 1;
    }

    tmp_size_idx_1 = g - ar;
    loop_ub = g - ar;
    for (g = 0; g < loop_ub; g++) {
      tmp_data[g] = (int16_T)((int16_T)(ar + g) + 1);
    }

    tmp_size_4[0] = 1;
    tmp_size_4[1] = tmp_size_idx_1;
    for (g = 0; g < tmp_size_idx_1; g++) {
      Bilateral_Ankle_Exo_B.tmp_data_cx[g] = tmp_data[g];
    }

    Bilateral_Ankle_Exo_power(Bilateral_Ankle_Exo_B.tmp_data_cx, tmp_size_4,
      Bilateral_Ankle_Exo_B.tmp_data_c, tmp_size_7);
    tmp_size_idx_1 = i - ia;
    loop_ub = i - ia;
    for (g = 0; g < loop_ub; g++) {
      tmp_data[g] = (int16_T)((int16_T)(ia + g) + 1);
    }

    tmp_size_5[0] = 1;
    tmp_size_5[1] = tmp_size_idx_1;
    for (g = 0; g < tmp_size_idx_1; g++) {
      Bilateral_Ankle_Exo_B.tmp_data_cx[g] = tmp_data[g];
    }

    Bilateral_Ankle_Exo_power_e(Bilateral_Ankle_Exo_B.tmp_data_cx, tmp_size_5,
      Bilateral_Ankle_Exo_B.tmp_data_k, tmp_size_8);
    for (g = 0; g < b_n; g++) {
      Bilateral_Ankle_Exo_B.tmp_data[g << 2] = 1.0;
    }

    loop_ub = e - br;
    for (g = 0; g <= loop_ub; g++) {
      Bilateral_Ankle_Exo_B.tmp_data[1 + (g << 2)] = (int16_T)((int16_T)((br + g)
        - 1) + 1);
    }

    loop_ub = tmp_size_7[1];
    for (g = 0; g < loop_ub; g++) {
      Bilateral_Ankle_Exo_B.tmp_data[2 + (g << 2)] =
        Bilateral_Ankle_Exo_B.tmp_data_c[tmp_size_7[0] * g];
    }

    loop_ub = tmp_size_8[1];
    for (g = 0; g < loop_ub; g++) {
      Bilateral_Ankle_Exo_B.tmp_data[3 + (g << 2)] =
        Bilateral_Ankle_Exo_B.tmp_data_k[tmp_size_8[0] * g];
    }

    br = b_n;
    for (g = 0; g < b_n; g++) {
      Bilateral_Ankle_Exo_B.result_data[g << 2] =
        Bilateral_Ankle_Exo_B.tmp_data[g << 2];
      Bilateral_Ankle_Exo_B.result_data[1 + (g << 2)] =
        Bilateral_Ankle_Exo_B.tmp_data[(g << 2) + 1];
      Bilateral_Ankle_Exo_B.result_data[2 + (g << 2)] =
        Bilateral_Ankle_Exo_B.tmp_data[(g << 2) + 2];
      Bilateral_Ankle_Exo_B.result_data[3 + (g << 2)] =
        Bilateral_Ankle_Exo_B.tmp_data[(g << 2) + 3];
    }

    tmp_0 = (int16_T)br;
    tmp_size_idx_1 = tmp_0;
    b_n = br - 1;
    if (0 <= tmp_size_idx_1 - 1) {
      memset(&Bilateral_Ankle_Exo_B.tmp_data_cx[0], 0, tmp_size_idx_1 * sizeof
             (real_T));
    }

    if (br != 0) {
      for (br = 1; br - 1 <= b_n; br++) {
        for (e = br; e <= br; e++) {
          Bilateral_Ankle_Exo_B.tmp_data_cx[e - 1] = 0.0;
        }
      }

      br = 0;
      for (e = 0; e <= b_n; e++) {
        ar = -1;
        for (g = br; g + 1 <= br + 4; g++) {
          if (Bilateral_Ankle_Exo_B.result_data[g] != 0.0) {
            ia = ar;
            for (i = e; i + 1 <= e + 1; i++) {
              ia++;
              Bilateral_Ankle_Exo_B.tmp_data_cx[i] +=
                Bilateral_Ankle_Exo_B.result_data[g] * parm1[ia];
            }
          }

          ar++;
        }

        br += 4;
      }
    }

    /* '<S15>:1:69' */
    for (g = 0; g < tmp_size_idx_1; g++) {
      Bilateral_Ankle_Exo_B.torque_track[q1 + g] =
        Bilateral_Ankle_Exo_B.tmp_data_cx[g];
    }

    /* '<S15>:1:72' */
    /* '<S15>:1:74' */
    for (g = 0; g < 750; g++) {
      Bilateral_Ankle_Exo_DW.TorqueMem_L[g << 2] =
        Bilateral_Ankle_Exo_B.torque_track[g];
      Bilateral_Ankle_Exo_DW.TorqueMem_L[2 + (g << 2)] =
        Bilateral_Ankle_Exo_B.torque_delta_track[g];
    }
  }

  /* '<S15>:1:78' */
  Bilateral_Ankle_Exo_DW.last_footstate_h = footstate;

  /* '<S15>:1:79' */
  Bilateral_Ankle_Exo_DW.TorqueMem_L[1 + (((int32_T)stride_index - 1) << 2)] =
    torque_measure;

  /* '<S15>:1:80' */
  Bilateral_Ankle_Exo_DW.TorqueMem_L[3 + (((int32_T)stride_index - 1) << 2)] =
    troque_delta;
  if (mode == 2.0) {
    /* '<S15>:1:82' */
    /* '<S15>:1:83' */
    mode = Bilateral_Ankle_Exo_DW.TorqueMem_L[((int32_T)stride_index - 1) << 2];

    /* '<S15>:1:84' */
    stride_index = Bilateral_Ankle_Exo_DW.TorqueMem_L[(((int32_T)stride_index -
      1) << 2) + 2];
  } else {
    /* '<S15>:1:86' */
    mode = 0.0;

    /* '<S15>:1:87' */
    stride_index = 0.0;
  }

  /* '<S15>:1:90' */
  /* '<S15>:1:91' */
  /* '<S15>:1:92' */
  Bilateral_Ankle_Exo_B.torque_des_l = mode;
  Bilateral_Ankle_Exo_B.torque_delta_des_l = stride_index;
  for (g = 0; g < 750; g++) {
    Bilateral_Ankle_Exo_B.torque_trace_l[g << 1] =
      Bilateral_Ankle_Exo_DW.TorqueMem_L[g << 2];
    Bilateral_Ankle_Exo_B.torque_trace_l[1 + (g << 1)] =
      Bilateral_Ankle_Exo_DW.TorqueMem_L[(g << 2) + 1];
  }

  for (g = 0; g < 750; g++) {
    Bilateral_Ankle_Exo_B.torque_delta_trace_l[g << 1] =
      Bilateral_Ankle_Exo_DW.TorqueMem_L[(g << 2) + 2];
    Bilateral_Ankle_Exo_B.torque_delta_trace_l[1 + (g << 1)] =
      Bilateral_Ankle_Exo_DW.TorqueMem_L[(g << 2) + 3];
  }

  Bilateral_Ankle_Exo_B.torque_error_l[0] = mode - Bilateral_Ankle_Exo_B.RT8[0];
  Bilateral_Ankle_Exo_B.torque_error_l[1] = mode - Bilateral_Ankle_Exo_B.RT8[1];

  /* End of MATLAB Function: '<S1>/Torque Track L' */

  /* MATLAB Function: '<S1>/Controller_L' */
  /* MATLAB Function 'Control Module/Controller_L': '<S9>:1' */
  /* '<S9>:1:25' */
  /* '<S9>:1:26' */
  /* '<S9>:1:28' */
  /* '<S9>:1:29' */
  /* '<S9>:1:30' */
  /* '<S9>:1:31' */
  /* '<S9>:1:34' */
  /* '<S9>:1:35' */
  /* '<S9>:1:39' */
  /* '<S9>:1:40' */
  /* '<S9>:1:41' */
  /* '<S9>:1:44' */
  /* '<S9>:1:45' */
  /* '<S9>:1:49' */
  /* '<S9>:1:50' */
  /* '<S9>:1:51' */
  /* '<S9>:1:52' */
  /* '<S9>:1:53' */
  switch ((int32_T)Bilateral_Ankle_Exo_B.RT7[0]) {
   case 1:
    /* '<S9>:1:58' */
    Bilateral_Ankle_Exo_B.motor_vel_cmd_l = 0.0;

    /* '<S9>:1:59' */
    Bilateral_Ankle_Exo_DW.calib_state_p = 0.0;
    break;

   case 3:
    /* '<S9>:1:62' */
    Bilateral_Ankle_Exo_B.motor_vel_cmd_l = -150.0;
    break;

   case 4:
    if ((Bilateral_Ankle_Exo_DW.calib_state_p == 0.0) &&
        (Bilateral_Ankle_Exo_B.RT8[0] < 5.0)) {
      /* '<S9>:1:65' */
      /* '<S9>:1:66' */
      Bilateral_Ankle_Exo_B.motor_vel_cmd_l = 150.0;
    } else if ((Bilateral_Ankle_Exo_DW.calib_state_p == 0.0) &&
               (Bilateral_Ankle_Exo_B.RT8[0] > 5.0)) {
      /* '<S9>:1:67' */
      /* '<S9>:1:68' */
      Bilateral_Ankle_Exo_DW.calib_state_p = 1.0;

      /* '<S9>:1:69' */
      Bilateral_Ankle_Exo_B.motor_vel_cmd_l = 0.0;

      /* '<S9>:1:70' */
      /* '<S9>:1:71' */
      Bilateral_Ankle_Exo_DW.ParmReg_L[1] = (Bilateral_Ankle_Exo_DW.ParmReg_L[1]
        + Bilateral_Ankle_Exo_B.RT10[0]) - 20.0;
    } else {
      /* '<S9>:1:73' */
      Bilateral_Ankle_Exo_B.motor_vel_cmd_l = 0.0;
    }
    break;

   case 2:
    /* '<S9>:1:77' */
    switch (Bilateral_Ankle_Exo_P.Controller_L_MODE_L) {
     case 1:
      /* '<S9>:1:80' */
      /* '<S9>:1:81' */
      /* '<S9>:1:82' */
      Bilateral_Ankle_Exo_B.motor_vel_cmd_l = (((Bilateral_Ankle_Exo_B.RT9[0] -
        Bilateral_Ankle_Exo_P.Controller_L_FOLLOW_SLACK_ANGLE) -
        Bilateral_Ankle_Exo_B.RT10[0] * 0.37037037037037035) *
        Bilateral_Ankle_Exo_B.RT2[3] + Bilateral_Ankle_Exo_B.RT9[1] *
        0.37037037037037035 * Bilateral_Ankle_Exo_B.RT2[4]) * 5.0 / 0.05;
      break;

     case 2:
      if (Bilateral_Ankle_Exo_B.RT7[1] == 1.0) {
        /* '<S9>:1:85' */
        /* '<S9>:1:86' */
        /* '<S9>:1:87' */
        /* '<S9>:1:88' */
        /* '<S9>:1:90' */
        /* '<S9>:1:91' */
        if (Bilateral_Ankle_Exo_B.torque_des_l < 0.001) {
          /* '<S9>:1:94' */
          /* '<S9>:1:95' */
          Bilateral_Ankle_Exo_DW.smooth_filter_b += 0.05;
          if (Bilateral_Ankle_Exo_DW.smooth_filter_b > 1.0) {
            /* '<S9>:1:96' */
            /* '<S9>:1:97' */
            Bilateral_Ankle_Exo_DW.smooth_filter_b = 1.0;
          }
        } else {
          /* '<S9>:1:100' */
          Bilateral_Ankle_Exo_DW.smooth_filter_b = 0.0;
        }

        /* '<S9>:1:103' */
        Bilateral_Ankle_Exo_B.motor_vel_cmd_l =
          (((((Bilateral_Ankle_Exo_B.torque_des_l - Bilateral_Ankle_Exo_B.RT8[0])
              * Bilateral_Ankle_Exo_B.RT2[0] +
              (Bilateral_Ankle_Exo_B.torque_delta_des_l -
               Bilateral_Ankle_Exo_B.RT8[1]) * Bilateral_Ankle_Exo_B.RT2[1]) +
             Bilateral_Ankle_Exo_B.lrn_cmd_l) + Bilateral_Ankle_Exo_B.RT2[5] *
            Bilateral_Ankle_Exo_B.torque_delta_des_l) * (1.0 -
            Bilateral_Ankle_Exo_DW.smooth_filter_b) +
           (((Bilateral_Ankle_Exo_B.RT9[0] -
              Bilateral_Ankle_Exo_P.Controller_L_FOLLOW_SLACK_ANGLE) -
             Bilateral_Ankle_Exo_B.RT10[0] * 0.37037037037037035) *
            Bilateral_Ankle_Exo_B.RT2[3] + Bilateral_Ankle_Exo_B.RT9[1] *
            0.37037037037037035 * Bilateral_Ankle_Exo_B.RT2[4]) *
           Bilateral_Ankle_Exo_DW.smooth_filter_b) * 5.0 / 0.05;
      } else {
        /* '<S9>:1:107' */
        Bilateral_Ankle_Exo_DW.smooth_filter_b = 0.0;

        /* '<S9>:1:108' */
        /* '<S9>:1:109' */
        /* '<S9>:1:110' */
        Bilateral_Ankle_Exo_B.motor_vel_cmd_l = (((Bilateral_Ankle_Exo_B.RT9[0]
          - Bilateral_Ankle_Exo_P.Controller_L_FOLLOW_SLACK_ANGLE) -
          Bilateral_Ankle_Exo_B.RT10[0] * 0.37037037037037035) *
          Bilateral_Ankle_Exo_B.RT2[3] + Bilateral_Ankle_Exo_B.RT9[1] *
          0.37037037037037035 * Bilateral_Ankle_Exo_B.RT2[4]) * 5.0 / 0.05;
      }
      break;

     default:
      /* '<S9>:1:113' */
      Bilateral_Ankle_Exo_B.motor_vel_cmd_l = 0.0;
      break;
    }
    break;

   case 0:
    /* '<S9>:1:117' */
    Bilateral_Ankle_Exo_B.motor_vel_cmd_l = 0.0;
    break;

   default:
    /* '<S9>:1:120' */
    Bilateral_Ankle_Exo_B.motor_vel_cmd_l = 0.0;
    break;
  }

  /* End of MATLAB Function: '<S1>/Controller_L' */

  /* MATLAB Function: '<S13>/MATLAB Function' */
  Bilateral_Ankle__MATLABFunction(Bilateral_Ankle_Exo_B.RT8,
    Bilateral_Ankle_Exo_B.RT10, Bilateral_Ankle_Exo_B.motor_vel_cmd_l,
    &Bilateral_Ankle_Exo_B.sf_MATLABFunction_h,
    Bilateral_Ankle_Exo_P.MATLABFunction_MAX_MOTOR_ANGLE,
    Bilateral_Ankle_Exo_P.MATLABFunction_MAX_SPEED,
    Bilateral_Ankle_Exo_P.MATLABFunction_MAX_TORQUE,
    Bilateral_Ankle_Exo_P.MATLABFunction_MIN_MOTOR_ANGLE);

  /* Gain: '<S13>/Gain2' */
  Bilateral_Ankle_Exo_B.Gain2_ch = Bilateral_Ankle_Exo_P.Gain2_Gain *
    Bilateral_Ankle_Exo_B.sf_MATLABFunction_h.vel;

  /* Gain: '<S13>/Gain1' */
  Bilateral_Ankle_Exo_B.Gain1_la = Bilateral_Ankle_Exo_P.Gain1_Gain *
    Bilateral_Ankle_Exo_B.Gain2_ch;

  /* S-Function (rti_commonblock): '<S17>/S-Function1' */
  /* This comment workarounds a code generation problem */

  /* --- Bilateral_Ankle_Exo/Control Module/Motor_L/DAC_CLASS1_BL1 --- */
  /* --- [RTI120X, DAC C1] - Channel: 16 --- */
  {
    /* define variables required for DAC realtime functions */
    Float64 inportDacData= 0.0;
    inportDacData = (real_T) Bilateral_Ankle_Exo_B.Gain1_la;

    /* write value of CL1 DAC for output channel 16 */
    DacCl1AnalogOut_setOutputValue(pRTIDacC1AnalogOut_Ch_16,
      DAC_CLASS1_CHANNEL_16, inportDacData);
    DacCl1AnalogOut_write(pRTIDacC1AnalogOut_Ch_16);
  }

  /* MATLAB Function: '<S1>/Torque Track R' incorporates:
   *  Constant: '<S1>/torque_offset'
   */
  /* MATLAB Function 'Control Module/Torque Track R': '<S16>:1' */
  /* '<S16>:1:43' */
  /* '<S16>:1:19' */
  mode = Bilateral_Ankle_Exo_B.RT1[0];

  /* '<S16>:1:20' */
  footstate = Bilateral_Ankle_Exo_B.RT1[1];

  /* '<S16>:1:21' */
  /* '<S16>:1:22' */
  /* '<S16>:1:24' */
  peak_torque = Bilateral_Ankle_Exo_B.RT3[0];

  /* '<S16>:1:25' */
  /* '<S16>:1:26' */
  /* '<S16>:1:27' */
  /* '<S16>:1:29' */
  torque_measure = Bilateral_Ankle_Exo_B.RT4[0];

  /* '<S16>:1:30' */
  troque_delta = Bilateral_Ankle_Exo_B.RT4[1];

  /* '<S16>:1:31' */
  stride_index = Bilateral_Ankle_Exo_B.RT1[3] * 500.0 + 1.0;
  if (stride_index > 750.0) {
    /* '<S16>:1:32' */
    /* '<S16>:1:33' */
    stride_index = 750.0;
  }

  if ((Bilateral_Ankle_Exo_DW.last_footstate == 0.0) &&
      (Bilateral_Ankle_Exo_B.RT1[1] == 1.0) && ((Bilateral_Ankle_Exo_B.RT1[0] ==
        2.0) || (Bilateral_Ankle_Exo_B.RT1[0] == 1.0))) {
    /* '<S16>:1:37' */
    /* '<S16>:1:39' */
    /* '<S16>:1:41' */
    memset(&Bilateral_Ankle_Exo_B.torque_track[0], 0, 750U * sizeof(real_T));
    memset(&Bilateral_Ankle_Exo_B.torque_delta_track[0], 0, 750U * sizeof(real_T));

    /* '<S16>:1:42' */
    /* '<S16>:1:43' */
    /* '<S16>:1:44' */
    index_peak = floor(Bilateral_Ankle_Exo_B.RT3[2] / 100.0 *
                       Bilateral_Ankle_Exo_B.RT1[2] * 500.0);

    /* '<S16>:1:45' */
    index_rise = index_peak - floor(Bilateral_Ankle_Exo_B.RT3[1] / 100.0 *
      Bilateral_Ankle_Exo_B.RT1[2] * 500.0);

    /* '<S16>:1:46' */
    index_fall = floor(Bilateral_Ankle_Exo_B.RT3[3] / 100.0 *
                       Bilateral_Ankle_Exo_B.RT1[2] * 500.0) + index_peak;
    if (1.0 > index_rise - 1.0) {
      q1 = 0;
    } else {
      q1 = (int32_T)(index_rise - 1.0);
    }

    /* '<S16>:1:49' */
    for (g = 0; g < q1; g++) {
      Bilateral_Ankle_Exo_B.tmp_data_cx[g] = (real_T)(int16_T)(1 + (int16_T)g) /
        index_rise * Bilateral_Ankle_Exo_P.torque_offset_Value;
    }

    if (0 <= q1 - 1) {
      memcpy(&Bilateral_Ankle_Exo_B.torque_track[0],
             &Bilateral_Ankle_Exo_B.tmp_data_cx[0], q1 * sizeof(real_T));
    }

    /* '<S16>:1:53' */
    /* '<S16>:1:57' */
    /* '<S16>:1:58' */
    parm1[0] = Bilateral_Ankle_Exo_P.torque_offset_Value;
    parm1[1] = Bilateral_Ankle_Exo_B.RT3[0];
    parm1[2] = 0.0;
    parm1[3] = 0.0;
    tmp[0] = 1.0;
    tmp[4] = index_rise;
    tmp[8] = index_rise * index_rise;
    tmp[12] = rt_powd_snf(index_rise, 3.0);
    tmp[1] = 1.0;
    tmp[5] = index_peak;
    tmp[9] = index_peak * index_peak;
    tmp[13] = rt_powd_snf(index_peak, 3.0);
    tmp[2] = 0.0;
    tmp[6] = 1.0;
    tmp[10] = 2.0 * index_rise;
    tmp[14] = index_rise * index_rise * 3.0;
    tmp[3] = 0.0;
    tmp[7] = 1.0;
    tmp[11] = 2.0 * index_peak;
    tmp[15] = index_peak * index_peak * 3.0;
    Bilateral_Ankle_Exo_mldivide_l(tmp, parm1);
    c = index_peak - index_rise;
    if (1.0 > c) {
      b_n = 0;
    } else {
      b_n = (int32_T)c;
    }

    if (index_rise > index_peak - 1.0) {
      br = 1;
      e = 0;
      ar = 0;
      g = 0;
      ia = 0;
      i = 0;
      q1 = 0;
    } else {
      br = (int32_T)index_rise;
      e = (int32_T)(index_peak - 1.0);
      ar = (int32_T)index_rise - 1;
      g = (int32_T)(index_peak - 1.0);
      ia = (int32_T)index_rise - 1;
      i = (int32_T)(index_peak - 1.0);
      q1 = (int32_T)index_rise - 1;
    }

    tmp_size_idx_1 = g - ar;
    loop_ub = g - ar;
    for (g = 0; g < loop_ub; g++) {
      tmp_data[g] = (int16_T)((int16_T)(ar + g) + 1);
    }

    tmp_size_2[0] = 1;
    tmp_size_2[1] = tmp_size_idx_1;
    for (g = 0; g < tmp_size_idx_1; g++) {
      Bilateral_Ankle_Exo_B.tmp_data_cx[g] = tmp_data[g];
    }

    Bilateral_Ankle_Exo_power_j(Bilateral_Ankle_Exo_B.tmp_data_cx, tmp_size_2,
      Bilateral_Ankle_Exo_B.tmp_data_c, tmp_size_7);
    tmp_size_idx_1 = i - ia;
    loop_ub = i - ia;
    for (g = 0; g < loop_ub; g++) {
      tmp_data[g] = (int16_T)((int16_T)(ia + g) + 1);
    }

    tmp_size_3[0] = 1;
    tmp_size_3[1] = tmp_size_idx_1;
    for (g = 0; g < tmp_size_idx_1; g++) {
      Bilateral_Ankle_Exo_B.tmp_data_cx[g] = tmp_data[g];
    }

    Bilateral_Ankle_Exo_power_ju(Bilateral_Ankle_Exo_B.tmp_data_cx, tmp_size_3,
      Bilateral_Ankle_Exo_B.tmp_data_k, tmp_size_8);
    for (g = 0; g < b_n; g++) {
      Bilateral_Ankle_Exo_B.tmp_data[g << 2] = 1.0;
    }

    loop_ub = e - br;
    for (g = 0; g <= loop_ub; g++) {
      Bilateral_Ankle_Exo_B.tmp_data[1 + (g << 2)] = (int16_T)((int16_T)((br + g)
        - 1) + 1);
    }

    loop_ub = tmp_size_7[1];
    for (g = 0; g < loop_ub; g++) {
      Bilateral_Ankle_Exo_B.tmp_data[2 + (g << 2)] =
        Bilateral_Ankle_Exo_B.tmp_data_c[tmp_size_7[0] * g];
    }

    loop_ub = tmp_size_8[1];
    for (g = 0; g < loop_ub; g++) {
      Bilateral_Ankle_Exo_B.tmp_data[3 + (g << 2)] =
        Bilateral_Ankle_Exo_B.tmp_data_k[tmp_size_8[0] * g];
    }

    br = b_n;
    for (g = 0; g < b_n; g++) {
      Bilateral_Ankle_Exo_B.result_data[g << 2] =
        Bilateral_Ankle_Exo_B.tmp_data[g << 2];
      Bilateral_Ankle_Exo_B.result_data[1 + (g << 2)] =
        Bilateral_Ankle_Exo_B.tmp_data[(g << 2) + 1];
      Bilateral_Ankle_Exo_B.result_data[2 + (g << 2)] =
        Bilateral_Ankle_Exo_B.tmp_data[(g << 2) + 2];
      Bilateral_Ankle_Exo_B.result_data[3 + (g << 2)] =
        Bilateral_Ankle_Exo_B.tmp_data[(g << 2) + 3];
    }

    tmp_0 = (int16_T)br;
    tmp_size_idx_1 = tmp_0;
    b_n = br - 1;
    if (0 <= tmp_size_idx_1 - 1) {
      memset(&Bilateral_Ankle_Exo_B.tmp_data_cx[0], 0, tmp_size_idx_1 * sizeof
             (real_T));
    }

    if (br != 0) {
      for (br = 1; br - 1 <= b_n; br++) {
        for (e = br; e <= br; e++) {
          Bilateral_Ankle_Exo_B.tmp_data_cx[e - 1] = 0.0;
        }
      }

      br = 0;
      for (e = 0; e <= b_n; e++) {
        ar = -1;
        for (g = br; g + 1 <= br + 4; g++) {
          if (Bilateral_Ankle_Exo_B.result_data[g] != 0.0) {
            ia = ar;
            for (i = e; i + 1 <= e + 1; i++) {
              ia++;
              Bilateral_Ankle_Exo_B.tmp_data_cx[i] +=
                Bilateral_Ankle_Exo_B.result_data[g] * parm1[ia];
            }
          }

          ar++;
        }

        br += 4;
      }
    }

    /* '<S16>:1:59' */
    for (g = 0; g < tmp_size_idx_1; g++) {
      Bilateral_Ankle_Exo_B.torque_track[q1 + g] =
        Bilateral_Ankle_Exo_B.tmp_data_cx[g];
    }

    c = index_peak - index_rise;
    if (1.0 > c) {
      b_n = 0;
    } else {
      b_n = (int32_T)c;
    }

    if (index_rise > index_peak - 1.0) {
      br = 1;
      e = 0;
      ar = 0;
      g = 0;
      q1 = 0;
    } else {
      br = (int32_T)index_rise;
      e = (int32_T)(index_peak - 1.0);
      ar = (int32_T)index_rise - 1;
      g = (int32_T)(index_peak - 1.0);
      q1 = (int32_T)index_rise - 1;
    }

    tmp_size_idx_1 = g - ar;
    loop_ub = g - ar;
    for (g = 0; g < loop_ub; g++) {
      tmp_data[g] = (int16_T)((int16_T)(ar + g) + 1);
    }

    tmp_size_1[0] = 1;
    tmp_size_1[1] = tmp_size_idx_1;
    for (g = 0; g < tmp_size_idx_1; g++) {
      Bilateral_Ankle_Exo_B.tmp_data_cx[g] = tmp_data[g];
    }

    Bilateral_Ankle_Exo_power_j(Bilateral_Ankle_Exo_B.tmp_data_cx, tmp_size_1,
      Bilateral_Ankle_Exo_B.tmp_data_c, tmp_size_7);
    for (g = 0; g < b_n; g++) {
      Bilateral_Ankle_Exo_B.tmp_data_m[3 * g] = 1.0;
    }

    loop_ub = e - br;
    for (g = 0; g <= loop_ub; g++) {
      Bilateral_Ankle_Exo_B.tmp_data_m[1 + 3 * g] = (real_T)(int16_T)((int16_T)
        ((br + g) - 1) + 1) * 2.0;
    }

    loop_ub = tmp_size_7[1];
    for (g = 0; g < loop_ub; g++) {
      Bilateral_Ankle_Exo_B.tmp_data_m[2 + 3 * g] =
        Bilateral_Ankle_Exo_B.tmp_data_c[tmp_size_7[0] * g] * 3.0;
    }

    br = b_n;
    for (g = 0; g < b_n; g++) {
      Bilateral_Ankle_Exo_B.b_result_data[3 * g] =
        Bilateral_Ankle_Exo_B.tmp_data_m[3 * g];
      Bilateral_Ankle_Exo_B.b_result_data[1 + 3 * g] =
        Bilateral_Ankle_Exo_B.tmp_data_m[3 * g + 1];
      Bilateral_Ankle_Exo_B.b_result_data[2 + 3 * g] =
        Bilateral_Ankle_Exo_B.tmp_data_m[3 * g + 2];
    }

    tmp_0 = (int16_T)br;
    tmp_size_idx_1 = tmp_0;
    b_n = br - 1;
    if (0 <= tmp_size_idx_1 - 1) {
      memset(&Bilateral_Ankle_Exo_B.tmp_data_cx[0], 0, tmp_size_idx_1 * sizeof
             (real_T));
    }

    if (br != 0) {
      for (br = 1; br - 1 <= b_n; br++) {
        for (e = br; e <= br; e++) {
          Bilateral_Ankle_Exo_B.tmp_data_cx[e - 1] = 0.0;
        }
      }

      br = 0;
      for (e = 0; e <= b_n; e++) {
        ar = -1;
        for (g = br; g + 1 <= br + 3; g++) {
          if (Bilateral_Ankle_Exo_B.b_result_data[g] != 0.0) {
            ia = ar;
            for (i = e; i + 1 <= e + 1; i++) {
              ia++;
              Bilateral_Ankle_Exo_B.tmp_data_cx[i] += parm1[1 + ia] *
                Bilateral_Ankle_Exo_B.b_result_data[g];
            }
          }

          ar++;
        }

        br += 3;
      }
    }

    /* '<S16>:1:60' */
    for (g = 0; g < tmp_size_idx_1; g++) {
      Bilateral_Ankle_Exo_B.torque_delta_track[q1 + g] =
        Bilateral_Ankle_Exo_B.tmp_data_cx[g] * 500.0;
    }

    /* '<S16>:1:63' */
    /* '<S16>:1:67' */
    /* '<S16>:1:68' */
    parm1[0] = peak_torque;
    parm1[1] = 0.0;
    parm1[2] = 0.0;
    parm1[3] = 0.0;
    tmp[0] = 1.0;
    tmp[4] = index_peak;
    tmp[8] = index_peak * index_peak;
    tmp[12] = rt_powd_snf(index_peak, 3.0);
    tmp[1] = 1.0;
    tmp[5] = index_fall;
    tmp[9] = index_fall * index_fall;
    tmp[13] = rt_powd_snf(index_fall, 3.0);
    tmp[2] = 0.0;
    tmp[6] = 1.0;
    tmp[10] = 2.0 * index_peak;
    tmp[14] = index_peak * index_peak * 3.0;
    tmp[3] = 0.0;
    tmp[7] = 1.0;
    tmp[11] = 2.0 * index_fall;
    tmp[15] = index_fall * index_fall * 3.0;
    Bilateral_Ankle_Exo_mldivide_l(tmp, parm1);
    peak_torque = (index_fall + 1.0) - index_peak;
    if (1.0 > peak_torque) {
      b_n = 0;
    } else {
      b_n = (int32_T)peak_torque;
    }

    if (index_peak > index_fall) {
      br = 1;
      e = 0;
      ar = 0;
      g = 0;
      ia = 0;
      i = 0;
      q1 = 0;
    } else {
      br = (int32_T)index_peak;
      e = (int32_T)index_fall;
      ar = (int32_T)index_peak - 1;
      g = (int32_T)index_fall;
      ia = (int32_T)index_peak - 1;
      i = (int32_T)index_fall;
      q1 = (int32_T)index_peak - 1;
    }

    tmp_size_idx_1 = g - ar;
    loop_ub = g - ar;
    for (g = 0; g < loop_ub; g++) {
      tmp_data[g] = (int16_T)((int16_T)(ar + g) + 1);
    }

    tmp_size[0] = 1;
    tmp_size[1] = tmp_size_idx_1;
    for (g = 0; g < tmp_size_idx_1; g++) {
      Bilateral_Ankle_Exo_B.tmp_data_cx[g] = tmp_data[g];
    }

    Bilateral_Ankle_Exo_power_j(Bilateral_Ankle_Exo_B.tmp_data_cx, tmp_size,
      Bilateral_Ankle_Exo_B.tmp_data_c, tmp_size_7);
    tmp_size_idx_1 = i - ia;
    loop_ub = i - ia;
    for (g = 0; g < loop_ub; g++) {
      tmp_data[g] = (int16_T)((int16_T)(ia + g) + 1);
    }

    tmp_size_0[0] = 1;
    tmp_size_0[1] = tmp_size_idx_1;
    for (g = 0; g < tmp_size_idx_1; g++) {
      Bilateral_Ankle_Exo_B.tmp_data_cx[g] = tmp_data[g];
    }

    Bilateral_Ankle_Exo_power_ju(Bilateral_Ankle_Exo_B.tmp_data_cx, tmp_size_0,
      Bilateral_Ankle_Exo_B.tmp_data_k, tmp_size_8);
    for (g = 0; g < b_n; g++) {
      Bilateral_Ankle_Exo_B.tmp_data[g << 2] = 1.0;
    }

    loop_ub = e - br;
    for (g = 0; g <= loop_ub; g++) {
      Bilateral_Ankle_Exo_B.tmp_data[1 + (g << 2)] = (int16_T)((int16_T)((br + g)
        - 1) + 1);
    }

    loop_ub = tmp_size_7[1];
    for (g = 0; g < loop_ub; g++) {
      Bilateral_Ankle_Exo_B.tmp_data[2 + (g << 2)] =
        Bilateral_Ankle_Exo_B.tmp_data_c[tmp_size_7[0] * g];
    }

    loop_ub = tmp_size_8[1];
    for (g = 0; g < loop_ub; g++) {
      Bilateral_Ankle_Exo_B.tmp_data[3 + (g << 2)] =
        Bilateral_Ankle_Exo_B.tmp_data_k[tmp_size_8[0] * g];
    }

    br = b_n;
    for (g = 0; g < b_n; g++) {
      Bilateral_Ankle_Exo_B.result_data[g << 2] =
        Bilateral_Ankle_Exo_B.tmp_data[g << 2];
      Bilateral_Ankle_Exo_B.result_data[1 + (g << 2)] =
        Bilateral_Ankle_Exo_B.tmp_data[(g << 2) + 1];
      Bilateral_Ankle_Exo_B.result_data[2 + (g << 2)] =
        Bilateral_Ankle_Exo_B.tmp_data[(g << 2) + 2];
      Bilateral_Ankle_Exo_B.result_data[3 + (g << 2)] =
        Bilateral_Ankle_Exo_B.tmp_data[(g << 2) + 3];
    }

    tmp_0 = (int16_T)br;
    tmp_size_idx_1 = tmp_0;
    b_n = br - 1;
    if (0 <= tmp_size_idx_1 - 1) {
      memset(&Bilateral_Ankle_Exo_B.tmp_data_cx[0], 0, tmp_size_idx_1 * sizeof
             (real_T));
    }

    if (br != 0) {
      for (br = 1; br - 1 <= b_n; br++) {
        for (e = br; e <= br; e++) {
          Bilateral_Ankle_Exo_B.tmp_data_cx[e - 1] = 0.0;
        }
      }

      br = 0;
      for (e = 0; e <= b_n; e++) {
        ar = -1;
        for (g = br; g + 1 <= br + 4; g++) {
          if (Bilateral_Ankle_Exo_B.result_data[g] != 0.0) {
            ia = ar;
            for (i = e; i + 1 <= e + 1; i++) {
              ia++;
              Bilateral_Ankle_Exo_B.tmp_data_cx[i] +=
                Bilateral_Ankle_Exo_B.result_data[g] * parm1[ia];
            }
          }

          ar++;
        }

        br += 4;
      }
    }

    /* '<S16>:1:69' */
    for (g = 0; g < tmp_size_idx_1; g++) {
      Bilateral_Ankle_Exo_B.torque_track[q1 + g] =
        Bilateral_Ankle_Exo_B.tmp_data_cx[g];
    }

    /* '<S16>:1:72' */
    /* '<S16>:1:74' */
    for (g = 0; g < 750; g++) {
      Bilateral_Ankle_Exo_DW.TorqueMem_R[g << 2] =
        Bilateral_Ankle_Exo_B.torque_track[g];
      Bilateral_Ankle_Exo_DW.TorqueMem_R[2 + (g << 2)] =
        Bilateral_Ankle_Exo_B.torque_delta_track[g];
    }
  }

  /* '<S16>:1:78' */
  Bilateral_Ankle_Exo_DW.last_footstate = footstate;

  /* '<S16>:1:79' */
  Bilateral_Ankle_Exo_DW.TorqueMem_R[1 + (((int32_T)stride_index - 1) << 2)] =
    torque_measure;

  /* '<S16>:1:80' */
  Bilateral_Ankle_Exo_DW.TorqueMem_R[3 + (((int32_T)stride_index - 1) << 2)] =
    troque_delta;
  if (mode == 2.0) {
    /* '<S16>:1:82' */
    /* '<S16>:1:83' */
    mode = Bilateral_Ankle_Exo_DW.TorqueMem_R[((int32_T)stride_index - 1) << 2];

    /* '<S16>:1:84' */
    stride_index = Bilateral_Ankle_Exo_DW.TorqueMem_R[(((int32_T)stride_index -
      1) << 2) + 2];
  } else {
    /* '<S16>:1:86' */
    mode = 0.0;

    /* '<S16>:1:87' */
    stride_index = 0.0;
  }

  /* '<S16>:1:90' */
  /* '<S16>:1:91' */
  /* '<S16>:1:93' */
  Bilateral_Ankle_Exo_B.torque_des_r = mode;
  Bilateral_Ankle_Exo_B.torque_delta_des_r = stride_index;
  for (g = 0; g < 750; g++) {
    Bilateral_Ankle_Exo_B.torque_trace_r[g << 1] =
      Bilateral_Ankle_Exo_DW.TorqueMem_R[g << 2];
    Bilateral_Ankle_Exo_B.torque_trace_r[1 + (g << 1)] =
      Bilateral_Ankle_Exo_DW.TorqueMem_R[(g << 2) + 1];
  }

  for (g = 0; g < 750; g++) {
    Bilateral_Ankle_Exo_B.torque_delta_trace_r[g << 1] =
      Bilateral_Ankle_Exo_DW.TorqueMem_R[(g << 2) + 2];
    Bilateral_Ankle_Exo_B.torque_delta_trace_r[1 + (g << 1)] =
      Bilateral_Ankle_Exo_DW.TorqueMem_R[(g << 2) + 3];
  }

  Bilateral_Ankle_Exo_B.torque_error_r[0] = mode - Bilateral_Ankle_Exo_B.RT4[0];
  Bilateral_Ankle_Exo_B.torque_error_r[1] = mode - Bilateral_Ankle_Exo_B.RT4[1];

  /* End of MATLAB Function: '<S1>/Torque Track R' */

  /* MATLAB Function: '<S1>/LRN_R' */
  /* MATLAB Function 'Control Module/LRN_R': '<S12>:1' */
  if (!Bilateral_Ankle_Exo_DW.last_footstate_not_empty) {
    /* '<S12>:1:10' */
    Bilateral_Ankle_Exo_DW.last_footstate_not_empty = true;

    /* '<S12>:1:14' */
    Bilateral_Ankle_Exo_DW.last_torque_parm[0] = Bilateral_Ankle_Exo_B.RT3[0];
    Bilateral_Ankle_Exo_DW.last_torque_parm[1] = Bilateral_Ankle_Exo_B.RT3[2];
  }

  /* '<S12>:1:18' */
  /* '<S12>:1:22' */
  /* '<S12>:1:25' */
  /* '<S12>:1:26' */
  /* '<S12>:1:28' */
  /* '<S12>:1:30' */
  /* '<S12>:1:32' */
  stride_index = Bilateral_Ankle_Exo_B.RT1[3] * 500.0 + 1.0;
  if (stride_index > 750.0) {
    /* '<S12>:1:33' */
    /* '<S12>:1:34' */
    stride_index = 750.0;
  }

  if ((Bilateral_Ankle_Exo_DW.last_footstate_a == 0.0) &&
      (Bilateral_Ankle_Exo_B.RT1[1] == 1.0) && (Bilateral_Ankle_Exo_B.RT1[0] ==
       2.0) && Bilateral_Ankle_Exo_P.LRN_R_BT_LRN_ON_R) {
    /* '<S12>:1:37' */
    /* '<S12>:1:38' */
    /* '<S12>:1:39' */
    mode = 1.0 - Bilateral_Ankle_Exo_P.LRN_R_error_filter_k_r;

    /* '<S12>:1:40' */
    footstate = Bilateral_Ankle_Exo_B.RT2[2];
    for (g = 0; g < 750; g++) {
      peak_torque = (Bilateral_Ankle_Exo_DW.TorqueMem_R[g << 2] -
                     Bilateral_Ankle_Exo_DW.TorqueMem_R[(g << 2) + 1]) *
        Bilateral_Ankle_Exo_P.LRN_R_error_filter_k_r + mode *
        Bilateral_Ankle_Exo_DW.torque_error_memory[g];
      Bilateral_Ankle_Exo_DW.torque_error_memory[g] = peak_torque;
      Bilateral_Ankle_Exo_DW.lrn_cmd_memory[g] =
        Bilateral_Ankle_Exo_P.LRN_R_lrn_shrink_r *
        Bilateral_Ankle_Exo_DW.lrn_cmd_memory[g] + footstate *
        Bilateral_Ankle_Exo_DW.torque_error_memory[g];
    }
  }

  if (Bilateral_Ankle_Exo_P.LRN_R_BT_LRN_CLEAR_R ||
      (Bilateral_Ankle_Exo_DW.last_torque_parm[0] != Bilateral_Ankle_Exo_B.RT3[0])
      || (Bilateral_Ankle_Exo_DW.last_torque_parm[1] !=
          Bilateral_Ankle_Exo_B.RT3[2])) {
    /* '<S12>:1:43' */
    /* '<S12>:1:44' */
    /* '<S12>:1:45' */
    memset(&Bilateral_Ankle_Exo_DW.torque_error_memory[0], 0, 1000U * sizeof
           (real_T));
    memset(&Bilateral_Ankle_Exo_DW.lrn_cmd_memory[0], 0, 1000U * sizeof(real_T));
  }

  if (Bilateral_Ankle_Exo_B.RT1[0] == 2.0) {
    /* '<S12>:1:48' */
    q1 = Bilateral_Ankle_Exo_P.LRN_R_time_delay_r;
    if (q1 < -2147482897) {
      q1 = MAX_int32_T;
    } else {
      q1 = 750 - q1;
    }

    if (stride_index >= q1) {
      /* '<S12>:1:49' */
      /* '<S12>:1:50' */
      Bilateral_Ankle_Exo_B.lrn_cmd_r = 0.0;
    } else {
      /* '<S12>:1:52' */
      mode = rt_roundd_snf(stride_index + (real_T)
                           Bilateral_Ankle_Exo_P.LRN_R_time_delay_r);
      if (mode < 2.147483648E+9) {
        if (mode >= -2.147483648E+9) {
          g = (int32_T)mode;
        } else {
          g = MIN_int32_T;
        }
      } else {
        g = MAX_int32_T;
      }

      Bilateral_Ankle_Exo_B.lrn_cmd_r = Bilateral_Ankle_Exo_DW.lrn_cmd_memory[g
        - 1];
    }
  } else {
    /* '<S12>:1:55' */
    Bilateral_Ankle_Exo_B.lrn_cmd_r = 0.0;
  }

  /* '<S12>:1:58' */
  Bilateral_Ankle_Exo_DW.last_footstate_a = Bilateral_Ankle_Exo_B.RT1[1];

  /* '<S12>:1:59' */
  Bilateral_Ankle_Exo_DW.last_torque_parm[0] = Bilateral_Ankle_Exo_B.RT3[0];
  Bilateral_Ankle_Exo_DW.last_torque_parm[1] = Bilateral_Ankle_Exo_B.RT3[2];

  /* '<S12>:1:60' */
  memcpy(&Bilateral_Ankle_Exo_B.lrn_mem_r[0],
         &Bilateral_Ankle_Exo_DW.lrn_cmd_memory[0], 750U * sizeof(real_T));

  /* End of MATLAB Function: '<S1>/LRN_R' */

  /* MATLAB Function: '<S1>/Controller_R' */
  /* MATLAB Function 'Control Module/Controller_R': '<S10>:1' */
  /* '<S10>:1:25' */
  /* '<S10>:1:26' */
  /* '<S10>:1:28' */
  /* '<S10>:1:29' */
  /* '<S10>:1:30' */
  /* '<S10>:1:31' */
  /* '<S10>:1:34' */
  /* '<S10>:1:35' */
  /* '<S10>:1:39' */
  /* '<S10>:1:40' */
  /* '<S10>:1:41' */
  /* '<S10>:1:44' */
  /* '<S10>:1:45' */
  /* '<S10>:1:49' */
  /* '<S10>:1:50' */
  /* '<S10>:1:51' */
  /* '<S10>:1:52' */
  /* '<S10>:1:53' */
  switch ((int32_T)Bilateral_Ankle_Exo_B.RT1[0]) {
   case 1:
    /* '<S10>:1:58' */
    Bilateral_Ankle_Exo_B.motor_vel_cmd_r = 0.0;

    /* '<S10>:1:59' */
    Bilateral_Ankle_Exo_DW.calib_state = 0.0;
    break;

   case 3:
    /* '<S10>:1:62' */
    Bilateral_Ankle_Exo_B.motor_vel_cmd_r = -150.0;
    break;

   case 4:
    if ((Bilateral_Ankle_Exo_DW.calib_state == 0.0) &&
        (Bilateral_Ankle_Exo_B.RT4[0] < 5.0)) {
      /* '<S10>:1:65' */
      /* '<S10>:1:66' */
      Bilateral_Ankle_Exo_B.motor_vel_cmd_r = 150.0;
    } else if ((Bilateral_Ankle_Exo_DW.calib_state == 0.0) &&
               (Bilateral_Ankle_Exo_B.RT4[0] > 5.0)) {
      /* '<S10>:1:67' */
      /* '<S10>:1:68' */
      Bilateral_Ankle_Exo_DW.calib_state = 1.0;

      /* '<S10>:1:69' */
      Bilateral_Ankle_Exo_B.motor_vel_cmd_r = 0.0;

      /* '<S10>:1:70' */
      /* '<S10>:1:71' */
      Bilateral_Ankle_Exo_DW.ParmReg_R[1] = (Bilateral_Ankle_Exo_DW.ParmReg_R[1]
        + Bilateral_Ankle_Exo_B.RT6[0]) - 20.0;
    } else {
      /* '<S10>:1:73' */
      Bilateral_Ankle_Exo_B.motor_vel_cmd_r = 0.0;
    }
    break;

   case 2:
    /* '<S10>:1:77' */
    switch (Bilateral_Ankle_Exo_P.Controller_R_MODE_R) {
     case 1:
      /* '<S10>:1:80' */
      /* '<S10>:1:81' */
      /* '<S10>:1:82' */
      Bilateral_Ankle_Exo_B.motor_vel_cmd_r = (((Bilateral_Ankle_Exo_B.RT5[0] -
        Bilateral_Ankle_Exo_P.Controller_R_FOLLOW_SLACK_ANGLE) -
        Bilateral_Ankle_Exo_B.RT6[0] * 0.37037037037037035) *
        Bilateral_Ankle_Exo_B.RT2[3] + Bilateral_Ankle_Exo_B.RT5[1] *
        0.37037037037037035 * Bilateral_Ankle_Exo_B.RT2[4]) * 5.0 / 0.05;
      break;

     case 2:
      if (Bilateral_Ankle_Exo_B.RT1[1] == 1.0) {
        /* '<S10>:1:85' */
        /* '<S10>:1:86' */
        /* '<S10>:1:87' */
        /* '<S10>:1:88' */
        /* '<S10>:1:90' */
        /* '<S10>:1:91' */
        if (Bilateral_Ankle_Exo_B.torque_des_r < 0.001) {
          /* '<S10>:1:94' */
          /* '<S10>:1:95' */
          Bilateral_Ankle_Exo_DW.smooth_filter += 0.05;
          if (Bilateral_Ankle_Exo_DW.smooth_filter > 1.0) {
            /* '<S10>:1:96' */
            /* '<S10>:1:97' */
            Bilateral_Ankle_Exo_DW.smooth_filter = 1.0;
          }
        } else {
          /* '<S10>:1:100' */
          Bilateral_Ankle_Exo_DW.smooth_filter = 0.0;
        }

        /* '<S10>:1:103' */
        Bilateral_Ankle_Exo_B.motor_vel_cmd_r =
          (((((Bilateral_Ankle_Exo_B.torque_des_r - Bilateral_Ankle_Exo_B.RT4[0])
              * Bilateral_Ankle_Exo_B.RT2[0] +
              (Bilateral_Ankle_Exo_B.torque_delta_des_r -
               Bilateral_Ankle_Exo_B.RT4[1]) * Bilateral_Ankle_Exo_B.RT2[1]) +
             Bilateral_Ankle_Exo_B.lrn_cmd_r) + Bilateral_Ankle_Exo_B.RT2[5] *
            Bilateral_Ankle_Exo_B.torque_delta_des_r) * (1.0 -
            Bilateral_Ankle_Exo_DW.smooth_filter) +
           (((Bilateral_Ankle_Exo_B.RT5[0] -
              Bilateral_Ankle_Exo_P.Controller_R_FOLLOW_SLACK_ANGLE) -
             Bilateral_Ankle_Exo_B.RT6[0] * 0.37037037037037035) *
            Bilateral_Ankle_Exo_B.RT2[3] + Bilateral_Ankle_Exo_B.RT5[1] *
            0.37037037037037035 * Bilateral_Ankle_Exo_B.RT2[4]) *
           Bilateral_Ankle_Exo_DW.smooth_filter) * 5.0 / 0.05;
      } else {
        /* '<S10>:1:107' */
        Bilateral_Ankle_Exo_DW.smooth_filter = 0.0;

        /* '<S10>:1:108' */
        /* '<S10>:1:109' */
        /* '<S10>:1:110' */
        Bilateral_Ankle_Exo_B.motor_vel_cmd_r = (((Bilateral_Ankle_Exo_B.RT5[0]
          - Bilateral_Ankle_Exo_P.Controller_R_FOLLOW_SLACK_ANGLE) -
          Bilateral_Ankle_Exo_B.RT6[0] * 0.37037037037037035) *
          Bilateral_Ankle_Exo_B.RT2[3] + Bilateral_Ankle_Exo_B.RT5[1] *
          0.37037037037037035 * Bilateral_Ankle_Exo_B.RT2[4]) * 5.0 / 0.05;
      }
      break;

     default:
      /* '<S10>:1:113' */
      Bilateral_Ankle_Exo_B.motor_vel_cmd_r = 0.0;
      break;
    }
    break;

   case 0:
    /* '<S10>:1:117' */
    Bilateral_Ankle_Exo_B.motor_vel_cmd_r = 0.0;
    break;

   default:
    /* '<S10>:1:120' */
    Bilateral_Ankle_Exo_B.motor_vel_cmd_r = 0.0;
    break;
  }

  /* End of MATLAB Function: '<S1>/Controller_R' */

  /* MATLAB Function: '<S14>/MATLAB Function' */
  Bilateral_Ankle__MATLABFunction(Bilateral_Ankle_Exo_B.RT4,
    Bilateral_Ankle_Exo_B.RT6, Bilateral_Ankle_Exo_B.motor_vel_cmd_r,
    &Bilateral_Ankle_Exo_B.sf_MATLABFunction_b,
    Bilateral_Ankle_Exo_P.MATLABFunction_MAX_MOTOR_ANGL_a,
    Bilateral_Ankle_Exo_P.MATLABFunction_MAX_SPEED_a,
    Bilateral_Ankle_Exo_P.MATLABFunction_MAX_TORQUE_p,
    Bilateral_Ankle_Exo_P.MATLABFunction_MIN_MOTOR_ANGL_g);

  /* Gain: '<S14>/Gain2' */
  Bilateral_Ankle_Exo_B.Gain2_o = Bilateral_Ankle_Exo_P.Gain2_Gain_g *
    Bilateral_Ankle_Exo_B.sf_MATLABFunction_b.vel;

  /* Gain: '<S14>/Gain1' */
  Bilateral_Ankle_Exo_B.Gain1_h = Bilateral_Ankle_Exo_P.Gain1_Gain_c *
    Bilateral_Ankle_Exo_B.Gain2_o;

  /* S-Function (rti_commonblock): '<S19>/S-Function1' */
  /* This comment workarounds a code generation problem */

  /* --- Bilateral_Ankle_Exo/Control Module/Motor_R/DAC_CLASS1_BL1 --- */
  /* --- [RTI120X, DAC C1] - Channel: 15 --- */
  {
    /* define variables required for DAC realtime functions */
    Float64 inportDacData= 0.0;
    inportDacData = (real_T) Bilateral_Ankle_Exo_B.Gain1_h;

    /* write value of CL1 DAC for output channel 15 */
    DacCl1AnalogOut_setOutputValue(pRTIDacC1AnalogOut_Ch_15,
      DAC_CLASS1_CHANNEL_15, inportDacData);
    DacCl1AnalogOut_write(pRTIDacC1AnalogOut_Ch_15);
  }
}

/* Termination for function-call system: '<Root>/Control Module' */
void Bilateral_An_ControlModule_Term(void)
{
  /* Terminate for S-Function (rti_commonblock): '<S17>/S-Function1' */

  /* --- Bilateral_Ankle_Exo/Control Module/Motor_L/DAC_CLASS1_BL1 --- */
  /* --- [RTI120X, DAC C1] - Channel: 16 --- */

  /* All channel outputs are set to high impedance state */
  DacCl1AnalogOut_setOutputHighZ(pRTIDacC1AnalogOut_Ch_16, DAC_CLASS1_HIGH_Z_ON);

  /* Deactivates AnalogOut functionality */
  DacCl1AnalogOut_stop(pRTIDacC1AnalogOut_Ch_16);

  /* Terminate for S-Function (rti_commonblock): '<S19>/S-Function1' */

  /* --- Bilateral_Ankle_Exo/Control Module/Motor_R/DAC_CLASS1_BL1 --- */
  /* --- [RTI120X, DAC C1] - Channel: 15 --- */

  /* All channel outputs are set to high impedance state */
  DacCl1AnalogOut_setOutputHighZ(pRTIDacC1AnalogOut_Ch_15, DAC_CLASS1_HIGH_Z_ON);

  /* Deactivates AnalogOut functionality */
  DacCl1AnalogOut_stop(pRTIDacC1AnalogOut_Ch_15);
}

/* Function for MATLAB Function: '<S33>/MATLAB Function' */
static real_T Bilateral_Ankle_Exo_xnrm2(const real_T x[30], int32_T ix0)
{
  real_T y;
  real_T scale;
  real_T absxk;
  real_T t;
  int32_T k;
  y = 0.0;
  scale = 3.3121686421112381E-170;
  for (k = ix0; k <= ix0 + 14; k++) {
    absxk = fabs(x[k - 1]);
    if (absxk > scale) {
      t = scale / absxk;
      y = y * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      y += t * t;
    }
  }

  return scale * sqrt(y);
}

/* Function for MATLAB Function: '<S33>/MATLAB Function' */
static real_T Bilateral_Ankle_Exo_xnrm2_o(int32_T n, const real_T x[30], int32_T
  ix0)
{
  real_T y;
  real_T scale;
  int32_T kend;
  real_T absxk;
  real_T t;
  int32_T k;
  y = 0.0;
  if (!(n < 1)) {
    if (n == 1) {
      y = fabs(x[ix0 - 1]);
    } else {
      scale = 3.3121686421112381E-170;
      kend = (ix0 + n) - 1;
      for (k = ix0; k <= kend; k++) {
        absxk = fabs(x[k - 1]);
        if (absxk > scale) {
          t = scale / absxk;
          y = y * t * t + 1.0;
          scale = absxk;
        } else {
          t = absxk / scale;
          y += t * t;
        }
      }

      y = scale * sqrt(y);
    }
  }

  return y;
}

real_T rt_hypotd_snf(real_T u0, real_T u1)
{
  real_T y;
  real_T a;
  a = fabs(u0);
  y = fabs(u1);
  if (a < y) {
    a /= y;
    y *= sqrt(a * a + 1.0);
  } else if (a > y) {
    y /= a;
    y = sqrt(y * y + 1.0) * a;
  } else {
    if (!rtIsNaN(y)) {
      y = a * 1.4142135623730951;
    }
  }

  return y;
}

/* Function for MATLAB Function: '<S33>/MATLAB Function' */
static void Bilateral_Ankle_Exo_xgeqp3(real_T A[30], real_T tau[2], int32_T
  jpvt[2])
{
  real_T work[2];
  real_T vn1[2];
  real_T vn2[2];
  int32_T k;
  int32_T i_i;
  int32_T pvt;
  int32_T ix;
  real_T smax;
  int32_T iy;
  real_T xnorm;
  int32_T c_ix;
  real_T b_c;
  int32_T d_ix;
  int32_T f;
  int32_T ijA;
  int32_T exitg1;
  boolean_T exitg2;
  jpvt[0] = 1;
  work[0] = 0.0;
  smax = Bilateral_Ankle_Exo_xnrm2(A, 1);
  vn2[0] = smax;
  vn1[0] = smax;
  jpvt[1] = 2;
  work[1] = 0.0;
  smax = Bilateral_Ankle_Exo_xnrm2(A, 16);
  vn2[1] = smax;
  vn1[1] = smax;
  for (k = 0; k < 2; k++) {
    i_i = k * 15 + k;
    pvt = 0;
    if (2 - k > 1) {
      ix = k;
      smax = fabs(vn1[k]);
      iy = 2;
      while (iy <= 2 - k) {
        ix++;
        b_c = fabs(vn1[ix]);
        if (b_c > smax) {
          pvt = 1;
          smax = b_c;
        }

        iy = 3;
      }
    }

    pvt += k;
    if (pvt + 1 != k + 1) {
      ix = 15 * pvt;
      iy = 15 * k;
      for (c_ix = 0; c_ix < 15; c_ix++) {
        smax = A[ix];
        A[ix] = A[iy];
        A[iy] = smax;
        ix++;
        iy++;
      }

      ix = jpvt[pvt];
      jpvt[pvt] = jpvt[k];
      jpvt[k] = ix;
      vn1[pvt] = vn1[k];
      vn2[pvt] = vn2[k];
    }

    smax = A[i_i];
    b_c = 0.0;
    xnorm = Bilateral_Ankle_Exo_xnrm2_o(14 - k, A, i_i + 2);
    if (xnorm != 0.0) {
      xnorm = rt_hypotd_snf(A[i_i], xnorm);
      if (A[i_i] >= 0.0) {
        xnorm = -xnorm;
      }

      if (fabs(xnorm) < 1.0020841800044864E-292) {
        pvt = 0;
        ix = (i_i - k) + 15;
        do {
          pvt++;
          for (iy = i_i + 1; iy + 1 <= ix; iy++) {
            A[iy] *= 9.9792015476736E+291;
          }

          xnorm *= 9.9792015476736E+291;
          smax *= 9.9792015476736E+291;
        } while (!(fabs(xnorm) >= 1.0020841800044864E-292));

        xnorm = rt_hypotd_snf(smax, Bilateral_Ankle_Exo_xnrm2_o(14 - k, A, i_i +
          2));
        if (smax >= 0.0) {
          xnorm = -xnorm;
        }

        b_c = (xnorm - smax) / xnorm;
        smax = 1.0 / (smax - xnorm);
        ix = (i_i - k) + 15;
        for (iy = i_i + 1; iy + 1 <= ix; iy++) {
          A[iy] *= smax;
        }

        for (ix = 1; ix <= pvt; ix++) {
          xnorm *= 1.0020841800044864E-292;
        }

        smax = xnorm;
      } else {
        b_c = (xnorm - A[i_i]) / xnorm;
        smax = 1.0 / (A[i_i] - xnorm);
        pvt = (i_i - k) + 15;
        for (ix = i_i + 1; ix + 1 <= pvt; ix++) {
          A[ix] *= smax;
        }

        smax = xnorm;
      }
    }

    tau[k] = b_c;
    A[i_i] = smax;
    if (k + 1 < 2) {
      smax = A[i_i];
      A[i_i] = 1.0;
      if (tau[0] != 0.0) {
        pvt = 30;
        ix = i_i + 14;
        while ((pvt - 15 > 0) && (A[ix] == 0.0)) {
          pvt--;
          ix--;
        }

        ix = 1;
        exitg2 = false;
        while ((!exitg2) && (ix > 0)) {
          iy = 16;
          do {
            exitg1 = 0;
            if (iy <= pvt) {
              if (A[iy - 1] != 0.0) {
                exitg1 = 1;
              } else {
                iy++;
              }
            } else {
              ix = 0;
              exitg1 = 2;
            }
          } while (exitg1 == 0);

          if (exitg1 == 1) {
            exitg2 = true;
          }
        }
      } else {
        pvt = 15;
        ix = 0;
      }

      if (pvt - 15 > 0) {
        if (ix != 0) {
          work[0] = 0.0;
          iy = 0;
          c_ix = 16;
          while (c_ix <= 16) {
            c_ix = i_i;
            b_c = 0.0;
            for (d_ix = 16; d_ix <= pvt; d_ix++) {
              b_c += A[d_ix - 1] * A[c_ix];
              c_ix++;
            }

            work[iy] += b_c;
            iy++;
            c_ix = 31;
          }
        }

        if (!(-tau[0] == 0.0)) {
          iy = 0;
          c_ix = 0;
          d_ix = 1;
          while (d_ix <= ix) {
            if (work[c_ix] != 0.0) {
              b_c = work[c_ix] * -tau[0];
              d_ix = i_i;
              f = pvt + iy;
              for (ijA = iy + 15; ijA + 1 <= f; ijA++) {
                A[ijA] += A[d_ix] * b_c;
                d_ix++;
              }
            }

            c_ix++;
            iy += 15;
            d_ix = 2;
          }
        }
      }

      A[i_i] = smax;
    }

    i_i = k + 2;
    while (i_i < 3) {
      if (vn1[1] != 0.0) {
        smax = fabs(A[15 + k]) / vn1[1];
        smax = 1.0 - smax * smax;
        if (smax < 0.0) {
          smax = 0.0;
        }

        b_c = vn1[1] / vn2[1];
        b_c = b_c * b_c * smax;
        if (b_c <= 1.4901161193847656E-8) {
          vn1[1] = Bilateral_Ankle_Exo_xnrm2_o(14 - k, A, k + 17);
          vn2[1] = vn1[1];
        } else {
          vn1[1] *= sqrt(smax);
        }
      }

      i_i = 3;
    }
  }
}

/* Model output function */
void Bilateral_Ankle_Exo_output(void)
{
  int_T tid = 0;
  real_T torque_zero;
  real_T x[2];
  real_T A[30];
  real_T tau[2];
  int32_T jpvt[2];
  real_T B[15];
  int32_T c_i;
  static const int8_T b_A[30] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 };

  real_T B_0;
  int32_T i;
  if (rtmIsMajorTimeStep(Bilateral_Ankle_Exo_M)) {
    /* set solver stop time */
    if (!(Bilateral_Ankle_Exo_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&Bilateral_Ankle_Exo_M->solverInfo,
                            ((Bilateral_Ankle_Exo_M->Timing.clockTickH0 + 1) *
        Bilateral_Ankle_Exo_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&Bilateral_Ankle_Exo_M->solverInfo,
                            ((Bilateral_Ankle_Exo_M->Timing.clockTick0 + 1) *
        Bilateral_Ankle_Exo_M->Timing.stepSize0 +
        Bilateral_Ankle_Exo_M->Timing.clockTickH0 *
        Bilateral_Ankle_Exo_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(Bilateral_Ankle_Exo_M)) {
    Bilateral_Ankle_Exo_M->Timing.t[0] = rtsiGetT
      (&Bilateral_Ankle_Exo_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(Bilateral_Ankle_Exo_M) &&
      Bilateral_Ankle_Exo_M->Timing.TaskCounters.TID[1] == 0) {
    /* S-Function (rti_commonblock): '<S89>/S-Function1' */
    /* This comment workarounds a code generation problem */

    /* --- Bilateral_Ankle_Exo/Sensor Data/Torque module/ADC_CLASS1_BL6 --- */
    /* --- [RTI120X, ADC C1] - Channel: 6 --- */
    {
      UInt32 readStateFlag[] = { 1 };

      /* define variable required for adc cl1 realtime functions */
      UInt32 IsNew = 0;

      /* wait until conversion result is available */
      while (IsNew == 0) {
        AdcCl1AnalogIn_isDataReady(pRTIAdcC1AnalogIn_Ch_6, &IsNew);
      }

      /* read conversion result from hardware */
      AdcCl1AnalogIn_read(pRTIAdcC1AnalogIn_Ch_6);

      /* retrieve conversion result */
      AdcCl1AnalogIn_getSingleValue(pRTIAdcC1AnalogIn_Ch_6, readStateFlag,
        (real_T*) &Bilateral_Ankle_Exo_B.SFunction1);
    }

    /* Gain: '<S33>/Gain' */
    Bilateral_Ankle_Exo_B.Gain = Bilateral_Ankle_Exo_P.Gain_Gain *
      Bilateral_Ankle_Exo_B.SFunction1;

    /* DiscreteFilter: '<S33>/0.4low2' */
    torque_zero = Bilateral_Ankle_Exo_B.Gain;
    torque_zero -= Bilateral_Ankle_Exo_P.u4low2_DenCoef[1] *
      Bilateral_Ankle_Exo_DW.u4low2_states[0];
    torque_zero -= Bilateral_Ankle_Exo_P.u4low2_DenCoef[2] *
      Bilateral_Ankle_Exo_DW.u4low2_states[1];
    torque_zero -= Bilateral_Ankle_Exo_P.u4low2_DenCoef[3] *
      Bilateral_Ankle_Exo_DW.u4low2_states[2];
    torque_zero /= Bilateral_Ankle_Exo_P.u4low2_DenCoef[0];
    Bilateral_Ankle_Exo_DW.u4low2_tmp = torque_zero;
    torque_zero = Bilateral_Ankle_Exo_P.u4low2_NumCoef[0] *
      Bilateral_Ankle_Exo_DW.u4low2_tmp;
    torque_zero += Bilateral_Ankle_Exo_P.u4low2_NumCoef[1] *
      Bilateral_Ankle_Exo_DW.u4low2_states[0];
    torque_zero += Bilateral_Ankle_Exo_P.u4low2_NumCoef[2] *
      Bilateral_Ankle_Exo_DW.u4low2_states[1];
    torque_zero += Bilateral_Ankle_Exo_P.u4low2_NumCoef[3] *
      Bilateral_Ankle_Exo_DW.u4low2_states[2];
    Bilateral_Ankle_Exo_B.u4low2 = torque_zero;

    /* MATLAB Function: '<S33>/Calibration_R' */
    /* MATLAB Function 'Sensor Data/Torque module/Calibration_R': '<S91>:1' */
    /* '<S91>:1:4' */
    torque_zero = Bilateral_Ankle_Exo_DW.ParmReg_R[0];
    if (Bilateral_Ankle_Exo_P.Calibration_R_BT_RESET_TORQUE_R) {
      /* '<S91>:1:7' */
      /* '<S91>:1:8' */
      torque_zero = Bilateral_Ankle_Exo_B.u4low2 *
        Bilateral_Ankle_Exo_P.Calibration_R_load_vol_gain +
        Bilateral_Ankle_Exo_P.Calibration_R_load_vol_offset;

      /* '<S91>:1:9' */
      Bilateral_Ankle_Exo_DW.ParmReg_R[0] = torque_zero;
    }

    /* '<S91>:1:12' */
    Bilateral_Ankle_Exo_B.torque = (Bilateral_Ankle_Exo_B.u4low2 *
      Bilateral_Ankle_Exo_P.Calibration_R_load_vol_gain +
      Bilateral_Ankle_Exo_P.Calibration_R_load_vol_offset) - torque_zero;

    /* End of MATLAB Function: '<S33>/Calibration_R' */

    /* UnitDelay: '<S86>/Unit Delay1' */
    Bilateral_Ankle_Exo_B.x2k1 = Bilateral_Ankle_Exo_DW.UnitDelay1_DSTATE;

    /* UnitDelay: '<S86>/Unit Delay' */
    Bilateral_Ankle_Exo_B.x1k1 = Bilateral_Ankle_Exo_DW.UnitDelay_DSTATE;

    /* Gain: '<S86>/Gain1' */
    B_0 = Bilateral_Ankle_Exo_P.uOrderTD_T1 * Bilateral_Ankle_Exo_P.uOrderTD_T2;
    torque_zero = 1.0 / B_0;
    Bilateral_Ankle_Exo_B.Gain1 = torque_zero * Bilateral_Ankle_Exo_B.x1k1;

    /* Gain: '<S86>/Gain2' */
    torque_zero = Bilateral_Ankle_Exo_P.uOrderTD_T1 +
      Bilateral_Ankle_Exo_P.uOrderTD_T2;
    B_0 = Bilateral_Ankle_Exo_P.uOrderTD_T1 * Bilateral_Ankle_Exo_P.uOrderTD_T2;
    torque_zero /= B_0;
    Bilateral_Ankle_Exo_B.Gain2 = torque_zero * Bilateral_Ankle_Exo_B.x2k1;

    /* UnitDelay: '<S86>/Unit Delay2' */
    Bilateral_Ankle_Exo_B.UnitDelay2 = Bilateral_Ankle_Exo_DW.UnitDelay2_DSTATE;

    /* Gain: '<S86>/Gain4' */
    B_0 = Bilateral_Ankle_Exo_P.uOrderTD_T1 * Bilateral_Ankle_Exo_P.uOrderTD_T2;
    torque_zero = 1.0 / B_0;
    Bilateral_Ankle_Exo_B.Gain4 = torque_zero * Bilateral_Ankle_Exo_B.UnitDelay2;

    /* Sum: '<S86>/Add2' */
    Bilateral_Ankle_Exo_B.Add2 = (Bilateral_Ankle_Exo_B.Gain1 +
      Bilateral_Ankle_Exo_B.Gain2) - Bilateral_Ankle_Exo_B.Gain4;

    /* Gain: '<S86>/Gain3' */
    Bilateral_Ankle_Exo_B.Gain3 = Bilateral_Ankle_Exo_P.uOrderTD_Ts *
      Bilateral_Ankle_Exo_B.Add2;

    /* Sum: '<S86>/Add1' */
    Bilateral_Ankle_Exo_B.x2k = Bilateral_Ankle_Exo_B.x2k1 -
      Bilateral_Ankle_Exo_B.Gain3;

    /* MATLAB Function: '<S33>/Mux_R' */
    Bilateral_Ankle_Exo_Mux(Bilateral_Ankle_Exo_B.torque,
      Bilateral_Ankle_Exo_B.x2k, &Bilateral_Ankle_Exo_B.sf_Mux_R);

    /* RateTransition: '<Root>/RT4' */
    switch (Bilateral_Ankle_Exo_DW.RT4_read_buf) {
     case 0:
      Bilateral_Ankle_Exo_DW.RT4_write_buf = 1;
      break;

     case 1:
      Bilateral_Ankle_Exo_DW.RT4_write_buf = 0;
      break;

     default:
      Bilateral_Ankle_Exo_DW.RT4_write_buf = (int8_T)
        (Bilateral_Ankle_Exo_DW.RT4_last_buf_wr == 0);
      break;
    }

    if (Bilateral_Ankle_Exo_DW.RT4_write_buf != 0) {
      Bilateral_Ankle_Exo_DW.RT4_Buffer1[0] = Bilateral_Ankle_Exo_B.sf_Mux_R.x[0];
      Bilateral_Ankle_Exo_DW.RT4_Buffer1[1] = Bilateral_Ankle_Exo_B.sf_Mux_R.x[1];
    } else {
      Bilateral_Ankle_Exo_DW.RT4_Buffer0[0] = Bilateral_Ankle_Exo_B.sf_Mux_R.x[0];
      Bilateral_Ankle_Exo_DW.RT4_Buffer0[1] = Bilateral_Ankle_Exo_B.sf_Mux_R.x[1];
    }

    Bilateral_Ankle_Exo_DW.RT4_last_buf_wr =
      Bilateral_Ankle_Exo_DW.RT4_write_buf;
    Bilateral_Ankle_Exo_DW.RT4_write_buf = -1;

    /* End of RateTransition: '<Root>/RT4' */

    /* S-Function (rti_commonblock): '<S36>/S-Function1' */
    /* This comment workarounds a code generation problem */

    /* Gain: '<S28>/Gain' */
    Bilateral_Ankle_Exo_B.Gain_g = Bilateral_Ankle_Exo_P.Gain_Gain_o *
      Bilateral_Ankle_Exo_B.SFunction1_o1;

    /* MATLAB Function: '<S28>/Calibration_R' */
    /* MATLAB Function 'Sensor Data/Ankle Encoder/Calibration_R': '<S35>:1' */
    /* '<S35>:1:3' */
    torque_zero = Bilateral_Ankle_Exo_DW.ParmReg_R[2];
    if (Bilateral_Ankle_Exo_P.Calibration_R_BT_RESET_ANKLE_R) {
      /* '<S35>:1:6' */
      /* '<S35>:1:7' */
      torque_zero = Bilateral_Ankle_Exo_B.Gain_g;

      /* '<S35>:1:8' */
      Bilateral_Ankle_Exo_DW.ParmReg_R[2] = Bilateral_Ankle_Exo_B.Gain_g;
    }

    /* '<S35>:1:11' */
    Bilateral_Ankle_Exo_B.angle_k = Bilateral_Ankle_Exo_B.Gain_g - torque_zero;

    /* End of MATLAB Function: '<S28>/Calibration_R' */

    /* Gain: '<S28>/Gain1' */
    Bilateral_Ankle_Exo_B.Gain1_o = Bilateral_Ankle_Exo_P.Gain1_Gain_m *
      Bilateral_Ankle_Exo_B.SFunction1_o2;

    /* MATLAB Function: '<S28>/Mux' */
    Bilateral_Ankle_Exo_Mux(Bilateral_Ankle_Exo_B.angle_k,
      Bilateral_Ankle_Exo_B.Gain1_o, &Bilateral_Ankle_Exo_B.sf_Mux);

    /* RateTransition: '<Root>/RT5' */
    switch (Bilateral_Ankle_Exo_DW.RT5_read_buf) {
     case 0:
      Bilateral_Ankle_Exo_DW.RT5_write_buf = 1;
      break;

     case 1:
      Bilateral_Ankle_Exo_DW.RT5_write_buf = 0;
      break;

     default:
      Bilateral_Ankle_Exo_DW.RT5_write_buf = (int8_T)
        (Bilateral_Ankle_Exo_DW.RT5_last_buf_wr == 0);
      break;
    }

    if (Bilateral_Ankle_Exo_DW.RT5_write_buf != 0) {
      Bilateral_Ankle_Exo_DW.RT5_Buffer1[0] = Bilateral_Ankle_Exo_B.sf_Mux.x[0];
      Bilateral_Ankle_Exo_DW.RT5_Buffer1[1] = Bilateral_Ankle_Exo_B.sf_Mux.x[1];
    } else {
      Bilateral_Ankle_Exo_DW.RT5_Buffer0[0] = Bilateral_Ankle_Exo_B.sf_Mux.x[0];
      Bilateral_Ankle_Exo_DW.RT5_Buffer0[1] = Bilateral_Ankle_Exo_B.sf_Mux.x[1];
    }

    Bilateral_Ankle_Exo_DW.RT5_last_buf_wr =
      Bilateral_Ankle_Exo_DW.RT5_write_buf;
    Bilateral_Ankle_Exo_DW.RT5_write_buf = -1;

    /* End of RateTransition: '<Root>/RT5' */

    /* S-Function (rti_commonblock): '<S80>/S-Function1' */
    /* This comment workarounds a code generation problem */

    /* Gain: '<S32>/Gain1' */
    Bilateral_Ankle_Exo_B.Gain1_k = Bilateral_Ankle_Exo_P.Gain1_Gain_cu *
      Bilateral_Ankle_Exo_B.SFunction1_o1_j;

    /* MATLAB Function: '<S32>/Calibration_R' */
    /* MATLAB Function 'Sensor Data/Motor Encoder/Calibration_R': '<S79>:1' */
    /* '<S79>:1:3' */
    torque_zero = Bilateral_Ankle_Exo_DW.ParmReg_R[1];
    if (Bilateral_Ankle_Exo_P.Calibration_R_BT_RESET_MOTOR_R) {
      /* '<S79>:1:5' */
      /* '<S79>:1:6' */
      torque_zero = Bilateral_Ankle_Exo_B.Gain1_k;

      /* '<S79>:1:7' */
      Bilateral_Ankle_Exo_DW.ParmReg_R[1] = Bilateral_Ankle_Exo_B.Gain1_k;
    }

    /* '<S79>:1:10' */
    Bilateral_Ankle_Exo_B.angle = Bilateral_Ankle_Exo_B.Gain1_k - torque_zero;

    /* End of MATLAB Function: '<S32>/Calibration_R' */

    /* Gain: '<S32>/Gain4' */
    Bilateral_Ankle_Exo_B.Gain4_m = Bilateral_Ankle_Exo_P.Gain4_Gain *
      Bilateral_Ankle_Exo_B.SFunction1_o2_h;

    /* UnitDelay: '<S77>/Unit Delay1' */
    Bilateral_Ankle_Exo_B.x2k1_h = Bilateral_Ankle_Exo_DW.UnitDelay1_DSTATE_n;

    /* UnitDelay: '<S77>/Unit Delay' */
    Bilateral_Ankle_Exo_B.x1k1_g = Bilateral_Ankle_Exo_DW.UnitDelay_DSTATE_o;

    /* Gain: '<S77>/Gain1' */
    B_0 = Bilateral_Ankle_Exo_P.uOrderTD1_T1 *
      Bilateral_Ankle_Exo_P.uOrderTD1_T2;
    torque_zero = 1.0 / B_0;
    Bilateral_Ankle_Exo_B.Gain1_m = torque_zero * Bilateral_Ankle_Exo_B.x1k1_g;

    /* Gain: '<S77>/Gain2' */
    torque_zero = Bilateral_Ankle_Exo_P.uOrderTD1_T1 +
      Bilateral_Ankle_Exo_P.uOrderTD1_T2;
    B_0 = Bilateral_Ankle_Exo_P.uOrderTD1_T1 *
      Bilateral_Ankle_Exo_P.uOrderTD1_T2;
    torque_zero /= B_0;
    Bilateral_Ankle_Exo_B.Gain2_h = torque_zero * Bilateral_Ankle_Exo_B.x2k1_h;

    /* UnitDelay: '<S77>/Unit Delay2' */
    Bilateral_Ankle_Exo_B.UnitDelay2_e =
      Bilateral_Ankle_Exo_DW.UnitDelay2_DSTATE_i;

    /* Gain: '<S77>/Gain4' */
    B_0 = Bilateral_Ankle_Exo_P.uOrderTD1_T1 *
      Bilateral_Ankle_Exo_P.uOrderTD1_T2;
    torque_zero = 1.0 / B_0;
    Bilateral_Ankle_Exo_B.Gain4_p = torque_zero *
      Bilateral_Ankle_Exo_B.UnitDelay2_e;

    /* Sum: '<S77>/Add2' */
    Bilateral_Ankle_Exo_B.Add2_f = (Bilateral_Ankle_Exo_B.Gain1_m +
      Bilateral_Ankle_Exo_B.Gain2_h) - Bilateral_Ankle_Exo_B.Gain4_p;

    /* Gain: '<S77>/Gain3' */
    Bilateral_Ankle_Exo_B.Gain3_i = Bilateral_Ankle_Exo_P.uOrderTD1_Ts *
      Bilateral_Ankle_Exo_B.Add2_f;

    /* Sum: '<S77>/Add1' */
    Bilateral_Ankle_Exo_B.x2k_k = Bilateral_Ankle_Exo_B.x2k1_h -
      Bilateral_Ankle_Exo_B.Gain3_i;

    /* MATLAB Function: '<S32>/Mux3' */
    Bilateral_Ankle_Exo_Mux1(Bilateral_Ankle_Exo_B.angle,
      Bilateral_Ankle_Exo_B.Gain4_m, Bilateral_Ankle_Exo_B.x2k_k,
      &Bilateral_Ankle_Exo_B.sf_Mux3);

    /* RateTransition: '<Root>/RT6' */
    switch (Bilateral_Ankle_Exo_DW.RT6_read_buf) {
     case 0:
      Bilateral_Ankle_Exo_DW.RT6_write_buf = 1;
      break;

     case 1:
      Bilateral_Ankle_Exo_DW.RT6_write_buf = 0;
      break;

     default:
      Bilateral_Ankle_Exo_DW.RT6_write_buf = (int8_T)
        (Bilateral_Ankle_Exo_DW.RT6_last_buf_wr == 0);
      break;
    }

    if (Bilateral_Ankle_Exo_DW.RT6_write_buf != 0) {
      Bilateral_Ankle_Exo_DW.RT6_Buffer1[0] = Bilateral_Ankle_Exo_B.sf_Mux3.x[0];
      Bilateral_Ankle_Exo_DW.RT6_Buffer1[1] = Bilateral_Ankle_Exo_B.sf_Mux3.x[1];
      Bilateral_Ankle_Exo_DW.RT6_Buffer1[2] = Bilateral_Ankle_Exo_B.sf_Mux3.x[2];
    } else {
      Bilateral_Ankle_Exo_DW.RT6_Buffer0[0] = Bilateral_Ankle_Exo_B.sf_Mux3.x[0];
      Bilateral_Ankle_Exo_DW.RT6_Buffer0[1] = Bilateral_Ankle_Exo_B.sf_Mux3.x[1];
      Bilateral_Ankle_Exo_DW.RT6_Buffer0[2] = Bilateral_Ankle_Exo_B.sf_Mux3.x[2];
    }

    Bilateral_Ankle_Exo_DW.RT6_last_buf_wr =
      Bilateral_Ankle_Exo_DW.RT6_write_buf;
    Bilateral_Ankle_Exo_DW.RT6_write_buf = -1;

    /* End of RateTransition: '<Root>/RT6' */

    /* S-Function (rti_commonblock): '<S60>/S-Function1' */
    /* This comment workarounds a code generation problem */

    /* MATLAB Function: '<S30>/Filter_R' */
    Bilateral_Ankle_Exo_Filter_L(Bilateral_Ankle_Exo_B.SFunction1_it,
      &Bilateral_Ankle_Exo_B.sf_Filter_R, &Bilateral_Ankle_Exo_DW.sf_Filter_R);

    /* MATLAB Function: '<S7>/State Machine' */
    /* MATLAB Function 'State_Module_r/State Machine': '<S99>:1' */
    /* '<S99>:1:21' */
    /* '<S99>:1:22' */
    /* '<S99>:1:23' */
    /* '<S99>:1:24' */
    /* '<S99>:1:27' */
    /* '<S99>:1:28' */
    /* '<S99>:1:29' */
    /* '<S99>:1:30' */
    /* '<S99>:1:31' */
    if (Bilateral_Ankle_Exo_P.StateMachine_BT_RUN_R) {
      /* '<S99>:1:34' */
      /* '<S99>:1:35' */
      Bilateral_Ankle_Exo_DW.bt_run = 1.0;
    }

    if (Bilateral_Ankle_Exo_P.StateMachine_BT_CALIB_R) {
      /* '<S99>:1:37' */
      /* '<S99>:1:38' */
      Bilateral_Ankle_Exo_DW.reg_mode = 4.0;
    }

    if (Bilateral_Ankle_Exo_P.StateMachine_BT_SLACK_R) {
      /* '<S99>:1:40' */
      /* '<S99>:1:41' */
      Bilateral_Ankle_Exo_DW.reg_mode = 3.0;
    }

    if (Bilateral_Ankle_Exo_P.StateMachine_BT_IDLE_R) {
      /* '<S99>:1:43' */
      /* '<S99>:1:44' */
      Bilateral_Ankle_Exo_DW.reg_mode = 1.0;
    }

    if (Bilateral_Ankle_Exo_P.StateMachine_BT_ERROR_R) {
      /* '<S99>:1:46' */
      /* '<S99>:1:47' */
      Bilateral_Ankle_Exo_DW.reg_mode = 0.0;
    }

    if ((Bilateral_Ankle_Exo_DW.bt_run == 1.0) &&
        (Bilateral_Ankle_Exo_DW.reg_last_switch == 0.0) &&
        (Bilateral_Ankle_Exo_B.sf_Filter_R.state == 1.0)) {
      /* '<S99>:1:50' */
      /* '<S99>:1:51' */
      Bilateral_Ankle_Exo_DW.reg_mode = 2.0;

      /* '<S99>:1:52' */
      Bilateral_Ankle_Exo_DW.bt_run = 0.0;
    }

    if ((Bilateral_Ankle_Exo_DW.reg_mode == 2.0) ||
        (Bilateral_Ankle_Exo_DW.reg_mode == 1.0)) {
      /* '<S99>:1:55' */
      if ((Bilateral_Ankle_Exo_DW.reg_last_switch == 0.0) &&
          (Bilateral_Ankle_Exo_B.sf_Filter_R.state == 1.0)) {
        /* '<S99>:1:56' */
        /* '<S99>:1:57' */
        Bilateral_Ankle_Exo_DW.reg_state = 1.0;
        if ((Bilateral_Ankle_Exo_DW.reg_stride_time_count < 1.5) &&
            (Bilateral_Ankle_Exo_DW.reg_stride_time_count > 0.5)) {
          /* '<S99>:1:59' */
          /* '<S99>:1:60' */
          Bilateral_Ankle_Exo_DW.reg_stride_time = 0.618 *
            Bilateral_Ankle_Exo_DW.reg_stride_time + 0.382 *
            Bilateral_Ankle_Exo_DW.reg_stride_time_count;
        }

        /* '<S99>:1:63' */
        Bilateral_Ankle_Exo_DW.reg_stride_time_count = 0.0;
      } else if ((Bilateral_Ankle_Exo_DW.reg_state == 1.0) &&
                 (Bilateral_Ankle_Exo_DW.reg_stride_time_count > 0.65 *
                  Bilateral_Ankle_Exo_DW.reg_stride_time)) {
        /* '<S99>:1:65' */
        /* '<S99>:1:66' */
        Bilateral_Ankle_Exo_DW.reg_state = 0.0;

        /* '<S99>:1:67' */
        Bilateral_Ankle_Exo_DW.reg_stride_time_count += 0.0002;
      } else {
        /* '<S99>:1:69' */
        Bilateral_Ankle_Exo_DW.reg_stride_time_count += 0.0002;
      }
    }

    /* '<S99>:1:73' */
    Bilateral_Ankle_Exo_DW.reg_last_switch =
      Bilateral_Ankle_Exo_B.sf_Filter_R.state;
    if (Bilateral_Ankle_Exo_DW.reg_stride_time > 1.5) {
      /* '<S99>:1:74' */
      /* '<S99>:1:75' */
      Bilateral_Ankle_Exo_DW.reg_stride_time = 1.5;
    } else {
      if (Bilateral_Ankle_Exo_DW.reg_stride_time < 0.5) {
        /* '<S99>:1:76' */
        /* '<S99>:1:77' */
        Bilateral_Ankle_Exo_DW.reg_stride_time = 0.5;
      }
    }

    /* '<S99>:1:80' */
    Bilateral_Ankle_Exo_B.mode_r = Bilateral_Ankle_Exo_DW.reg_mode;

    /* '<S99>:1:81' */
    Bilateral_Ankle_Exo_B.state_r = Bilateral_Ankle_Exo_DW.reg_state;

    /* '<S99>:1:82' */
    Bilateral_Ankle_Exo_B.stride_time_r = Bilateral_Ankle_Exo_DW.reg_stride_time;

    /* '<S99>:1:83' */
    Bilateral_Ankle_Exo_B.stride_timer_r =
      Bilateral_Ankle_Exo_DW.reg_stride_time_count;

    /* End of MATLAB Function: '<S7>/State Machine' */

    /* MATLAB Function: '<S7>/Mux1' */
    Bilateral_Ankle_Exo_Mux1_p(Bilateral_Ankle_Exo_B.mode_r,
      Bilateral_Ankle_Exo_B.state_r, Bilateral_Ankle_Exo_B.stride_time_r,
      Bilateral_Ankle_Exo_B.stride_timer_r, &Bilateral_Ankle_Exo_B.sf_Mux1);

    /* RateTransition: '<Root>/RT1' */
    switch (Bilateral_Ankle_Exo_DW.RT1_read_buf) {
     case 0:
      Bilateral_Ankle_Exo_DW.RT1_write_buf = 1;
      break;

     case 1:
      Bilateral_Ankle_Exo_DW.RT1_write_buf = 0;
      break;

     default:
      Bilateral_Ankle_Exo_DW.RT1_write_buf = (int8_T)
        (Bilateral_Ankle_Exo_DW.RT1_last_buf_wr == 0);
      break;
    }

    if (Bilateral_Ankle_Exo_DW.RT1_write_buf != 0) {
      Bilateral_Ankle_Exo_DW.RT1_Buffer1[0] = Bilateral_Ankle_Exo_B.sf_Mux1.x[0];
      Bilateral_Ankle_Exo_DW.RT1_Buffer1[1] = Bilateral_Ankle_Exo_B.sf_Mux1.x[1];
      Bilateral_Ankle_Exo_DW.RT1_Buffer1[2] = Bilateral_Ankle_Exo_B.sf_Mux1.x[2];
      Bilateral_Ankle_Exo_DW.RT1_Buffer1[3] = Bilateral_Ankle_Exo_B.sf_Mux1.x[3];
    } else {
      Bilateral_Ankle_Exo_DW.RT1_Buffer0[0] = Bilateral_Ankle_Exo_B.sf_Mux1.x[0];
      Bilateral_Ankle_Exo_DW.RT1_Buffer0[1] = Bilateral_Ankle_Exo_B.sf_Mux1.x[1];
      Bilateral_Ankle_Exo_DW.RT1_Buffer0[2] = Bilateral_Ankle_Exo_B.sf_Mux1.x[2];
      Bilateral_Ankle_Exo_DW.RT1_Buffer0[3] = Bilateral_Ankle_Exo_B.sf_Mux1.x[3];
    }

    Bilateral_Ankle_Exo_DW.RT1_last_buf_wr =
      Bilateral_Ankle_Exo_DW.RT1_write_buf;
    Bilateral_Ankle_Exo_DW.RT1_write_buf = -1;

    /* End of RateTransition: '<Root>/RT1' */

    /* MATLAB Function: '<S21>/Mux1' incorporates:
     *  Constant: '<S21>/Kd'
     *  Constant: '<S21>/Kl'
     *  Constant: '<S21>/Ko'
     *  Constant: '<S21>/Kp'
     *  Constant: '<S21>/Ksd'
     *  Constant: '<S21>/Ksp'
     *  Constant: '<S21>/control reset'
     */
    /* MATLAB Function 'Parameter Module/Control Parameter/Mux1': '<S23>:1' */
    if (Bilateral_Ankle_Exo_P.controlreset_Value == 1.0) {
      /* '<S23>:1:3' */
      /* '<S23>:1:4' */
      for (i = 0; i < 6; i++) {
        Bilateral_Ankle_Exo_B.x_h[i] = 0.0;
      }
    } else {
      /* '<S23>:1:6' */
      Bilateral_Ankle_Exo_B.x_h[0] = Bilateral_Ankle_Exo_P.Kp_Value;
      Bilateral_Ankle_Exo_B.x_h[1] = Bilateral_Ankle_Exo_P.Kd_Value;
      Bilateral_Ankle_Exo_B.x_h[2] = Bilateral_Ankle_Exo_P.Kl_Value;
      Bilateral_Ankle_Exo_B.x_h[3] = Bilateral_Ankle_Exo_P.Ksp_Value;
      Bilateral_Ankle_Exo_B.x_h[4] = Bilateral_Ankle_Exo_P.Ksd_Value;
      Bilateral_Ankle_Exo_B.x_h[5] = Bilateral_Ankle_Exo_P.Ko_Value;
    }

    /* End of MATLAB Function: '<S21>/Mux1' */

    /* RateTransition: '<Root>/RT2' */
    switch (Bilateral_Ankle_Exo_DW.RT2_read_buf) {
     case 0:
      Bilateral_Ankle_Exo_DW.RT2_write_buf = 1;
      break;

     case 1:
      Bilateral_Ankle_Exo_DW.RT2_write_buf = 0;
      break;

     default:
      Bilateral_Ankle_Exo_DW.RT2_write_buf = (int8_T)
        (Bilateral_Ankle_Exo_DW.RT2_last_buf_wr == 0);
      break;
    }

    if (Bilateral_Ankle_Exo_DW.RT2_write_buf != 0) {
      for (i = 0; i < 6; i++) {
        Bilateral_Ankle_Exo_DW.RT2_Buffer1[i] = Bilateral_Ankle_Exo_B.x_h[i];
      }
    } else {
      for (i = 0; i < 6; i++) {
        Bilateral_Ankle_Exo_DW.RT2_Buffer0[i] = Bilateral_Ankle_Exo_B.x_h[i];
      }
    }

    Bilateral_Ankle_Exo_DW.RT2_last_buf_wr =
      Bilateral_Ankle_Exo_DW.RT2_write_buf;
    Bilateral_Ankle_Exo_DW.RT2_write_buf = -1;

    /* End of RateTransition: '<Root>/RT2' */

    /* MATLAB Function: '<S22>/Mux1' incorporates:
     *  Constant: '<S22>/fall_time'
     *  Constant: '<S22>/peak_time'
     *  Constant: '<S22>/peak_torque'
     *  Constant: '<S22>/rise_time'
     */
    /* MATLAB Function 'Parameter Module/Torque Parameter/Mux1': '<S24>:1' */
    /* '<S24>:1:3' */
    Bilateral_Ankle_Exo_B.x_k[0] = Bilateral_Ankle_Exo_P.peak_torque_Value;
    Bilateral_Ankle_Exo_B.x_k[1] = Bilateral_Ankle_Exo_P.rise_time_Value;
    Bilateral_Ankle_Exo_B.x_k[2] = Bilateral_Ankle_Exo_P.peak_time_Value;
    Bilateral_Ankle_Exo_B.x_k[3] = Bilateral_Ankle_Exo_P.fall_time_Value;

    /* RateTransition: '<Root>/RT3' */
    switch (Bilateral_Ankle_Exo_DW.RT3_read_buf) {
     case 0:
      Bilateral_Ankle_Exo_DW.RT3_write_buf = 1;
      break;

     case 1:
      Bilateral_Ankle_Exo_DW.RT3_write_buf = 0;
      break;

     default:
      Bilateral_Ankle_Exo_DW.RT3_write_buf = (int8_T)
        (Bilateral_Ankle_Exo_DW.RT3_last_buf_wr == 0);
      break;
    }

    if (Bilateral_Ankle_Exo_DW.RT3_write_buf != 0) {
      Bilateral_Ankle_Exo_DW.RT3_Buffer1[0] = Bilateral_Ankle_Exo_B.x_k[0];
      Bilateral_Ankle_Exo_DW.RT3_Buffer1[1] = Bilateral_Ankle_Exo_B.x_k[1];
      Bilateral_Ankle_Exo_DW.RT3_Buffer1[2] = Bilateral_Ankle_Exo_B.x_k[2];
      Bilateral_Ankle_Exo_DW.RT3_Buffer1[3] = Bilateral_Ankle_Exo_B.x_k[3];
    } else {
      Bilateral_Ankle_Exo_DW.RT3_Buffer0[0] = Bilateral_Ankle_Exo_B.x_k[0];
      Bilateral_Ankle_Exo_DW.RT3_Buffer0[1] = Bilateral_Ankle_Exo_B.x_k[1];
      Bilateral_Ankle_Exo_DW.RT3_Buffer0[2] = Bilateral_Ankle_Exo_B.x_k[2];
      Bilateral_Ankle_Exo_DW.RT3_Buffer0[3] = Bilateral_Ankle_Exo_B.x_k[3];
    }

    Bilateral_Ankle_Exo_DW.RT3_last_buf_wr =
      Bilateral_Ankle_Exo_DW.RT3_write_buf;
    Bilateral_Ankle_Exo_DW.RT3_write_buf = -1;

    /* End of RateTransition: '<Root>/RT3' */

    /* S-Function (rti_commonblock): '<S61>/S-Function1' */
    /* This comment workarounds a code generation problem */

    /* MATLAB Function: '<S30>/Filter_L' */
    Bilateral_Ankle_Exo_Filter_L(Bilateral_Ankle_Exo_B.SFunction1_jo,
      &Bilateral_Ankle_Exo_B.sf_Filter_L, &Bilateral_Ankle_Exo_DW.sf_Filter_L);

    /* MATLAB Function: '<S6>/State Machine' */
    /* MATLAB Function 'State_Module_l/State Machine': '<S97>:1' */
    /* '<S97>:1:21' */
    /* '<S97>:1:22' */
    /* '<S97>:1:23' */
    /* '<S97>:1:24' */
    /* '<S97>:1:27' */
    /* '<S97>:1:28' */
    /* '<S97>:1:29' */
    /* '<S97>:1:30' */
    /* '<S97>:1:31' */
    if (Bilateral_Ankle_Exo_P.StateMachine_BT_RUN_L) {
      /* '<S97>:1:34' */
      /* '<S97>:1:35' */
      Bilateral_Ankle_Exo_DW.bt_run_c = 1.0;
    }

    if (Bilateral_Ankle_Exo_P.StateMachine_BT_CALIB_L) {
      /* '<S97>:1:37' */
      /* '<S97>:1:38' */
      Bilateral_Ankle_Exo_DW.reg_mode_d = 4.0;
    }

    if (Bilateral_Ankle_Exo_P.StateMachine_BT_SLACK_L) {
      /* '<S97>:1:40' */
      /* '<S97>:1:41' */
      Bilateral_Ankle_Exo_DW.reg_mode_d = 3.0;
    }

    if (Bilateral_Ankle_Exo_P.StateMachine_BT_IDLE_L) {
      /* '<S97>:1:43' */
      /* '<S97>:1:44' */
      Bilateral_Ankle_Exo_DW.reg_mode_d = 1.0;
    }

    if (Bilateral_Ankle_Exo_P.StateMachine_BT_ERROR_L) {
      /* '<S97>:1:46' */
      /* '<S97>:1:47' */
      Bilateral_Ankle_Exo_DW.reg_mode_d = 0.0;
    }

    if ((Bilateral_Ankle_Exo_DW.bt_run_c == 1.0) &&
        (Bilateral_Ankle_Exo_DW.reg_last_switch_p == 0.0) &&
        (Bilateral_Ankle_Exo_B.sf_Filter_L.state == 1.0)) {
      /* '<S97>:1:50' */
      /* '<S97>:1:51' */
      Bilateral_Ankle_Exo_DW.reg_mode_d = 2.0;

      /* '<S97>:1:52' */
      Bilateral_Ankle_Exo_DW.bt_run_c = 0.0;
    }

    if ((Bilateral_Ankle_Exo_DW.reg_mode_d == 2.0) ||
        (Bilateral_Ankle_Exo_DW.reg_mode_d == 1.0)) {
      /* '<S97>:1:55' */
      if ((Bilateral_Ankle_Exo_DW.reg_last_switch_p == 0.0) &&
          (Bilateral_Ankle_Exo_B.sf_Filter_L.state == 1.0)) {
        /* '<S97>:1:56' */
        /* '<S97>:1:57' */
        Bilateral_Ankle_Exo_DW.reg_state_p = 1.0;
        if ((Bilateral_Ankle_Exo_DW.reg_stride_time_count_a < 1.5) &&
            (Bilateral_Ankle_Exo_DW.reg_stride_time_count_a > 0.5)) {
          /* '<S97>:1:59' */
          /* '<S97>:1:60' */
          Bilateral_Ankle_Exo_DW.reg_stride_time_e = 0.618 *
            Bilateral_Ankle_Exo_DW.reg_stride_time_e + 0.382 *
            Bilateral_Ankle_Exo_DW.reg_stride_time_count_a;
        }

        /* '<S97>:1:63' */
        Bilateral_Ankle_Exo_DW.reg_stride_time_count_a = 0.0;
      } else if ((Bilateral_Ankle_Exo_DW.reg_state_p == 1.0) &&
                 (Bilateral_Ankle_Exo_DW.reg_stride_time_count_a > 0.65 *
                  Bilateral_Ankle_Exo_DW.reg_stride_time_e)) {
        /* '<S97>:1:65' */
        /* '<S97>:1:66' */
        Bilateral_Ankle_Exo_DW.reg_state_p = 0.0;

        /* '<S97>:1:67' */
        Bilateral_Ankle_Exo_DW.reg_stride_time_count_a += 0.0002;
      } else {
        /* '<S97>:1:69' */
        Bilateral_Ankle_Exo_DW.reg_stride_time_count_a += 0.0002;
      }
    }

    /* '<S97>:1:73' */
    Bilateral_Ankle_Exo_DW.reg_last_switch_p =
      Bilateral_Ankle_Exo_B.sf_Filter_L.state;
    if (Bilateral_Ankle_Exo_DW.reg_stride_time_e > 1.5) {
      /* '<S97>:1:74' */
      /* '<S97>:1:75' */
      Bilateral_Ankle_Exo_DW.reg_stride_time_e = 1.5;
    } else {
      if (Bilateral_Ankle_Exo_DW.reg_stride_time_e < 0.5) {
        /* '<S97>:1:76' */
        /* '<S97>:1:77' */
        Bilateral_Ankle_Exo_DW.reg_stride_time_e = 0.5;
      }
    }

    /* '<S97>:1:80' */
    Bilateral_Ankle_Exo_B.mode_l = Bilateral_Ankle_Exo_DW.reg_mode_d;

    /* '<S97>:1:81' */
    Bilateral_Ankle_Exo_B.state_l = Bilateral_Ankle_Exo_DW.reg_state_p;

    /* '<S97>:1:82' */
    Bilateral_Ankle_Exo_B.stride_time_l =
      Bilateral_Ankle_Exo_DW.reg_stride_time_e;

    /* '<S97>:1:83' */
    Bilateral_Ankle_Exo_B.stride_timer_l =
      Bilateral_Ankle_Exo_DW.reg_stride_time_count_a;

    /* End of MATLAB Function: '<S6>/State Machine' */

    /* MATLAB Function: '<S6>/Mux1' */
    Bilateral_Ankle_Exo_Mux1_p(Bilateral_Ankle_Exo_B.mode_l,
      Bilateral_Ankle_Exo_B.state_l, Bilateral_Ankle_Exo_B.stride_time_l,
      Bilateral_Ankle_Exo_B.stride_timer_l, &Bilateral_Ankle_Exo_B.sf_Mux1_p);

    /* RateTransition: '<Root>/RT7' */
    switch (Bilateral_Ankle_Exo_DW.RT7_read_buf) {
     case 0:
      Bilateral_Ankle_Exo_DW.RT7_write_buf = 1;
      break;

     case 1:
      Bilateral_Ankle_Exo_DW.RT7_write_buf = 0;
      break;

     default:
      Bilateral_Ankle_Exo_DW.RT7_write_buf = (int8_T)
        (Bilateral_Ankle_Exo_DW.RT7_last_buf_wr == 0);
      break;
    }

    if (Bilateral_Ankle_Exo_DW.RT7_write_buf != 0) {
      Bilateral_Ankle_Exo_DW.RT7_Buffer1[0] = Bilateral_Ankle_Exo_B.sf_Mux1_p.x
        [0];
      Bilateral_Ankle_Exo_DW.RT7_Buffer1[1] = Bilateral_Ankle_Exo_B.sf_Mux1_p.x
        [1];
      Bilateral_Ankle_Exo_DW.RT7_Buffer1[2] = Bilateral_Ankle_Exo_B.sf_Mux1_p.x
        [2];
      Bilateral_Ankle_Exo_DW.RT7_Buffer1[3] = Bilateral_Ankle_Exo_B.sf_Mux1_p.x
        [3];
    } else {
      Bilateral_Ankle_Exo_DW.RT7_Buffer0[0] = Bilateral_Ankle_Exo_B.sf_Mux1_p.x
        [0];
      Bilateral_Ankle_Exo_DW.RT7_Buffer0[1] = Bilateral_Ankle_Exo_B.sf_Mux1_p.x
        [1];
      Bilateral_Ankle_Exo_DW.RT7_Buffer0[2] = Bilateral_Ankle_Exo_B.sf_Mux1_p.x
        [2];
      Bilateral_Ankle_Exo_DW.RT7_Buffer0[3] = Bilateral_Ankle_Exo_B.sf_Mux1_p.x
        [3];
    }

    Bilateral_Ankle_Exo_DW.RT7_last_buf_wr =
      Bilateral_Ankle_Exo_DW.RT7_write_buf;
    Bilateral_Ankle_Exo_DW.RT7_write_buf = -1;

    /* End of RateTransition: '<Root>/RT7' */

    /* S-Function (rti_commonblock): '<S88>/S-Function1' */
    /* This comment workarounds a code generation problem */

    /* --- Bilateral_Ankle_Exo/Sensor Data/Torque module/ADC_CLASS1_BL1 --- */
    /* --- [RTI120X, ADC C1] - Channel: 7 --- */
    {
      UInt32 readStateFlag[] = { 1 };

      /* define variable required for adc cl1 realtime functions */
      UInt32 IsNew = 0;

      /* wait until conversion result is available */
      while (IsNew == 0) {
        AdcCl1AnalogIn_isDataReady(pRTIAdcC1AnalogIn_Ch_7, &IsNew);
      }

      /* read conversion result from hardware */
      AdcCl1AnalogIn_read(pRTIAdcC1AnalogIn_Ch_7);

      /* retrieve conversion result */
      AdcCl1AnalogIn_getSingleValue(pRTIAdcC1AnalogIn_Ch_7, readStateFlag,
        (real_T*) &Bilateral_Ankle_Exo_B.SFunction1_o);
    }

    /* Gain: '<S33>/Gain1' */
    Bilateral_Ankle_Exo_B.Gain1_l = Bilateral_Ankle_Exo_P.Gain1_Gain_e *
      Bilateral_Ankle_Exo_B.SFunction1_o;

    /* DiscreteFilter: '<S33>/0.4low1' */
    torque_zero = Bilateral_Ankle_Exo_B.Gain1_l;
    torque_zero -= Bilateral_Ankle_Exo_P.u4low1_DenCoef[1] *
      Bilateral_Ankle_Exo_DW.u4low1_states[0];
    torque_zero -= Bilateral_Ankle_Exo_P.u4low1_DenCoef[2] *
      Bilateral_Ankle_Exo_DW.u4low1_states[1];
    torque_zero -= Bilateral_Ankle_Exo_P.u4low1_DenCoef[3] *
      Bilateral_Ankle_Exo_DW.u4low1_states[2];
    torque_zero /= Bilateral_Ankle_Exo_P.u4low1_DenCoef[0];
    Bilateral_Ankle_Exo_DW.u4low1_tmp = torque_zero;
    torque_zero = Bilateral_Ankle_Exo_P.u4low1_NumCoef[0] *
      Bilateral_Ankle_Exo_DW.u4low1_tmp;
    torque_zero += Bilateral_Ankle_Exo_P.u4low1_NumCoef[1] *
      Bilateral_Ankle_Exo_DW.u4low1_states[0];
    torque_zero += Bilateral_Ankle_Exo_P.u4low1_NumCoef[2] *
      Bilateral_Ankle_Exo_DW.u4low1_states[1];
    torque_zero += Bilateral_Ankle_Exo_P.u4low1_NumCoef[3] *
      Bilateral_Ankle_Exo_DW.u4low1_states[2];
    Bilateral_Ankle_Exo_B.u4low1 = torque_zero;

    /* MATLAB Function: '<S33>/Calibration_L' */
    /* MATLAB Function 'Sensor Data/Torque module/Calibration_L': '<S90>:1' */
    /* '<S90>:1:4' */
    torque_zero = Bilateral_Ankle_Exo_DW.ParmReg_L[0];
    if (Bilateral_Ankle_Exo_P.Calibration_L_BT_RESET_TORQUE_L) {
      /* '<S90>:1:7' */
      /* '<S90>:1:8' */
      torque_zero = Bilateral_Ankle_Exo_B.u4low1 *
        Bilateral_Ankle_Exo_P.Calibration_L_load_vol_gain +
        Bilateral_Ankle_Exo_P.Calibration_L_load_vol_offset;

      /* '<S90>:1:9' */
      Bilateral_Ankle_Exo_DW.ParmReg_L[0] = torque_zero;
    }

    /* '<S90>:1:12' */
    Bilateral_Ankle_Exo_B.torque_k = (Bilateral_Ankle_Exo_B.u4low1 *
      Bilateral_Ankle_Exo_P.Calibration_L_load_vol_gain +
      Bilateral_Ankle_Exo_P.Calibration_L_load_vol_offset) - torque_zero;

    /* End of MATLAB Function: '<S33>/Calibration_L' */

    /* UnitDelay: '<S87>/Unit Delay1' */
    Bilateral_Ankle_Exo_B.x2k1_m = Bilateral_Ankle_Exo_DW.UnitDelay1_DSTATE_m;

    /* UnitDelay: '<S87>/Unit Delay' */
    Bilateral_Ankle_Exo_B.x1k1_f = Bilateral_Ankle_Exo_DW.UnitDelay_DSTATE_n;

    /* Gain: '<S87>/Gain1' */
    B_0 = Bilateral_Ankle_Exo_P.uOrderTD1_T1_a *
      Bilateral_Ankle_Exo_P.uOrderTD1_T2_f;
    torque_zero = 1.0 / B_0;
    Bilateral_Ankle_Exo_B.Gain1_a = torque_zero * Bilateral_Ankle_Exo_B.x1k1_f;

    /* Gain: '<S87>/Gain2' */
    torque_zero = Bilateral_Ankle_Exo_P.uOrderTD1_T1_a +
      Bilateral_Ankle_Exo_P.uOrderTD1_T2_f;
    B_0 = Bilateral_Ankle_Exo_P.uOrderTD1_T1_a *
      Bilateral_Ankle_Exo_P.uOrderTD1_T2_f;
    torque_zero /= B_0;
    Bilateral_Ankle_Exo_B.Gain2_j = torque_zero * Bilateral_Ankle_Exo_B.x2k1_m;

    /* UnitDelay: '<S87>/Unit Delay2' */
    Bilateral_Ankle_Exo_B.UnitDelay2_b =
      Bilateral_Ankle_Exo_DW.UnitDelay2_DSTATE_l;

    /* Gain: '<S87>/Gain4' */
    B_0 = Bilateral_Ankle_Exo_P.uOrderTD1_T1_a *
      Bilateral_Ankle_Exo_P.uOrderTD1_T2_f;
    torque_zero = 1.0 / B_0;
    Bilateral_Ankle_Exo_B.Gain4_g = torque_zero *
      Bilateral_Ankle_Exo_B.UnitDelay2_b;

    /* Sum: '<S87>/Add2' */
    Bilateral_Ankle_Exo_B.Add2_c = (Bilateral_Ankle_Exo_B.Gain1_a +
      Bilateral_Ankle_Exo_B.Gain2_j) - Bilateral_Ankle_Exo_B.Gain4_g;

    /* Gain: '<S87>/Gain3' */
    Bilateral_Ankle_Exo_B.Gain3_f = Bilateral_Ankle_Exo_P.uOrderTD1_Ts_a *
      Bilateral_Ankle_Exo_B.Add2_c;

    /* Sum: '<S87>/Add1' */
    Bilateral_Ankle_Exo_B.x2k_l = Bilateral_Ankle_Exo_B.x2k1_m -
      Bilateral_Ankle_Exo_B.Gain3_f;

    /* MATLAB Function: '<S33>/Mux_L' */
    Bilateral_Ankle_Exo_Mux(Bilateral_Ankle_Exo_B.torque_k,
      Bilateral_Ankle_Exo_B.x2k_l, &Bilateral_Ankle_Exo_B.sf_Mux_L);

    /* RateTransition: '<Root>/RT8' */
    switch (Bilateral_Ankle_Exo_DW.RT8_read_buf) {
     case 0:
      Bilateral_Ankle_Exo_DW.RT8_write_buf = 1;
      break;

     case 1:
      Bilateral_Ankle_Exo_DW.RT8_write_buf = 0;
      break;

     default:
      Bilateral_Ankle_Exo_DW.RT8_write_buf = (int8_T)
        (Bilateral_Ankle_Exo_DW.RT8_last_buf_wr == 0);
      break;
    }

    if (Bilateral_Ankle_Exo_DW.RT8_write_buf != 0) {
      Bilateral_Ankle_Exo_DW.RT8_Buffer1[0] = Bilateral_Ankle_Exo_B.sf_Mux_L.x[0];
      Bilateral_Ankle_Exo_DW.RT8_Buffer1[1] = Bilateral_Ankle_Exo_B.sf_Mux_L.x[1];
    } else {
      Bilateral_Ankle_Exo_DW.RT8_Buffer0[0] = Bilateral_Ankle_Exo_B.sf_Mux_L.x[0];
      Bilateral_Ankle_Exo_DW.RT8_Buffer0[1] = Bilateral_Ankle_Exo_B.sf_Mux_L.x[1];
    }

    Bilateral_Ankle_Exo_DW.RT8_last_buf_wr =
      Bilateral_Ankle_Exo_DW.RT8_write_buf;
    Bilateral_Ankle_Exo_DW.RT8_write_buf = -1;

    /* End of RateTransition: '<Root>/RT8' */

    /* S-Function (rti_commonblock): '<S37>/S-Function1' */
    /* This comment workarounds a code generation problem */

    /* Gain: '<S28>/Gain2' */
    Bilateral_Ankle_Exo_B.Gain2_n = Bilateral_Ankle_Exo_P.Gain2_Gain_l *
      Bilateral_Ankle_Exo_B.SFunction1_o1_jc;

    /* MATLAB Function: '<S28>/Calibration_L' */
    /* MATLAB Function 'Sensor Data/Ankle Encoder/Calibration_L': '<S34>:1' */
    /* '<S34>:1:3' */
    torque_zero = Bilateral_Ankle_Exo_DW.ParmReg_L[2];
    if (Bilateral_Ankle_Exo_P.Calibration_L_BT_RESET_ANKLE_L) {
      /* '<S34>:1:5' */
      /* '<S34>:1:6' */
      torque_zero = Bilateral_Ankle_Exo_B.Gain2_n;

      /* '<S34>:1:7' */
      Bilateral_Ankle_Exo_DW.ParmReg_L[2] = Bilateral_Ankle_Exo_B.Gain2_n;
    }

    /* '<S34>:1:10' */
    Bilateral_Ankle_Exo_B.angle_b = Bilateral_Ankle_Exo_B.Gain2_n - torque_zero;

    /* End of MATLAB Function: '<S28>/Calibration_L' */

    /* Gain: '<S28>/Gain3' */
    Bilateral_Ankle_Exo_B.Gain3_o = Bilateral_Ankle_Exo_P.Gain3_Gain *
      Bilateral_Ankle_Exo_B.SFunction1_o2_o;

    /* MATLAB Function: '<S28>/Mux1' */
    Bilateral_Ankle_Exo_Mux(Bilateral_Ankle_Exo_B.angle_b,
      Bilateral_Ankle_Exo_B.Gain3_o, &Bilateral_Ankle_Exo_B.sf_Mux1_b);

    /* RateTransition: '<Root>/RT9' */
    switch (Bilateral_Ankle_Exo_DW.RT9_read_buf) {
     case 0:
      Bilateral_Ankle_Exo_DW.RT9_write_buf = 1;
      break;

     case 1:
      Bilateral_Ankle_Exo_DW.RT9_write_buf = 0;
      break;

     default:
      Bilateral_Ankle_Exo_DW.RT9_write_buf = (int8_T)
        (Bilateral_Ankle_Exo_DW.RT9_last_buf_wr == 0);
      break;
    }

    if (Bilateral_Ankle_Exo_DW.RT9_write_buf != 0) {
      Bilateral_Ankle_Exo_DW.RT9_Buffer1[0] = Bilateral_Ankle_Exo_B.sf_Mux1_b.x
        [0];
      Bilateral_Ankle_Exo_DW.RT9_Buffer1[1] = Bilateral_Ankle_Exo_B.sf_Mux1_b.x
        [1];
    } else {
      Bilateral_Ankle_Exo_DW.RT9_Buffer0[0] = Bilateral_Ankle_Exo_B.sf_Mux1_b.x
        [0];
      Bilateral_Ankle_Exo_DW.RT9_Buffer0[1] = Bilateral_Ankle_Exo_B.sf_Mux1_b.x
        [1];
    }

    Bilateral_Ankle_Exo_DW.RT9_last_buf_wr =
      Bilateral_Ankle_Exo_DW.RT9_write_buf;
    Bilateral_Ankle_Exo_DW.RT9_write_buf = -1;

    /* End of RateTransition: '<Root>/RT9' */

    /* S-Function (rti_commonblock): '<S81>/S-Function1' */
    /* This comment workarounds a code generation problem */

    /* Gain: '<S32>/Gain2' */
    Bilateral_Ankle_Exo_B.Gain2_c = Bilateral_Ankle_Exo_P.Gain2_Gain_h *
      Bilateral_Ankle_Exo_B.SFunction1_o1_jr;

    /* MATLAB Function: '<S32>/Calibration_L' */
    /* MATLAB Function 'Sensor Data/Motor Encoder/Calibration_L': '<S78>:1' */
    /* '<S78>:1:3' */
    torque_zero = Bilateral_Ankle_Exo_DW.ParmReg_L[1];
    if (Bilateral_Ankle_Exo_P.Calibration_L_BT_RESET_MOTOR_L) {
      /* '<S78>:1:5' */
      /* '<S78>:1:6' */
      torque_zero = Bilateral_Ankle_Exo_B.Gain2_c;

      /* '<S78>:1:7' */
      Bilateral_Ankle_Exo_DW.ParmReg_L[1] = Bilateral_Ankle_Exo_B.Gain2_c;
    }

    /* '<S78>:1:10' */
    Bilateral_Ankle_Exo_B.angle_a = Bilateral_Ankle_Exo_B.Gain2_c - torque_zero;

    /* End of MATLAB Function: '<S32>/Calibration_L' */

    /* Gain: '<S32>/Gain3' */
    Bilateral_Ankle_Exo_B.Gain3_h = Bilateral_Ankle_Exo_P.Gain3_Gain_e *
      Bilateral_Ankle_Exo_B.SFunction1_o2_j;

    /* UnitDelay: '<S76>/Unit Delay1' */
    Bilateral_Ankle_Exo_B.x2k1_d = Bilateral_Ankle_Exo_DW.UnitDelay1_DSTATE_f;

    /* UnitDelay: '<S76>/Unit Delay' */
    Bilateral_Ankle_Exo_B.x1k1_e = Bilateral_Ankle_Exo_DW.UnitDelay_DSTATE_a;

    /* Gain: '<S76>/Gain1' */
    B_0 = Bilateral_Ankle_Exo_P.uOrderTD_T1_p *
      Bilateral_Ankle_Exo_P.uOrderTD_T2_k;
    torque_zero = 1.0 / B_0;
    Bilateral_Ankle_Exo_B.Gain1_p = torque_zero * Bilateral_Ankle_Exo_B.x1k1_e;

    /* Gain: '<S76>/Gain2' */
    torque_zero = Bilateral_Ankle_Exo_P.uOrderTD_T1_p +
      Bilateral_Ankle_Exo_P.uOrderTD_T2_k;
    B_0 = Bilateral_Ankle_Exo_P.uOrderTD_T1_p *
      Bilateral_Ankle_Exo_P.uOrderTD_T2_k;
    torque_zero /= B_0;
    Bilateral_Ankle_Exo_B.Gain2_na = torque_zero * Bilateral_Ankle_Exo_B.x2k1_d;

    /* UnitDelay: '<S76>/Unit Delay2' */
    Bilateral_Ankle_Exo_B.UnitDelay2_i =
      Bilateral_Ankle_Exo_DW.UnitDelay2_DSTATE_e;

    /* Gain: '<S76>/Gain4' */
    B_0 = Bilateral_Ankle_Exo_P.uOrderTD_T1_p *
      Bilateral_Ankle_Exo_P.uOrderTD_T2_k;
    torque_zero = 1.0 / B_0;
    Bilateral_Ankle_Exo_B.Gain4_o = torque_zero *
      Bilateral_Ankle_Exo_B.UnitDelay2_i;

    /* Sum: '<S76>/Add2' */
    Bilateral_Ankle_Exo_B.Add2_fk = (Bilateral_Ankle_Exo_B.Gain1_p +
      Bilateral_Ankle_Exo_B.Gain2_na) - Bilateral_Ankle_Exo_B.Gain4_o;

    /* Gain: '<S76>/Gain3' */
    Bilateral_Ankle_Exo_B.Gain3_hf = Bilateral_Ankle_Exo_P.uOrderTD_Ts_n *
      Bilateral_Ankle_Exo_B.Add2_fk;

    /* Sum: '<S76>/Add1' */
    Bilateral_Ankle_Exo_B.x2k_a = Bilateral_Ankle_Exo_B.x2k1_d -
      Bilateral_Ankle_Exo_B.Gain3_hf;

    /* MATLAB Function: '<S32>/Mux1' */
    Bilateral_Ankle_Exo_Mux1(Bilateral_Ankle_Exo_B.angle_a,
      Bilateral_Ankle_Exo_B.Gain3_h, Bilateral_Ankle_Exo_B.x2k_a,
      &Bilateral_Ankle_Exo_B.sf_Mux1_o);

    /* RateTransition: '<Root>/RT10' */
    switch (Bilateral_Ankle_Exo_DW.RT10_read_buf) {
     case 0:
      Bilateral_Ankle_Exo_DW.RT10_write_buf = 1;
      break;

     case 1:
      Bilateral_Ankle_Exo_DW.RT10_write_buf = 0;
      break;

     default:
      Bilateral_Ankle_Exo_DW.RT10_write_buf = (int8_T)
        (Bilateral_Ankle_Exo_DW.RT10_last_buf_wr == 0);
      break;
    }

    if (Bilateral_Ankle_Exo_DW.RT10_write_buf != 0) {
      Bilateral_Ankle_Exo_DW.RT10_Buffer1[0] =
        Bilateral_Ankle_Exo_B.sf_Mux1_o.x[0];
      Bilateral_Ankle_Exo_DW.RT10_Buffer1[1] =
        Bilateral_Ankle_Exo_B.sf_Mux1_o.x[1];
      Bilateral_Ankle_Exo_DW.RT10_Buffer1[2] =
        Bilateral_Ankle_Exo_B.sf_Mux1_o.x[2];
    } else {
      Bilateral_Ankle_Exo_DW.RT10_Buffer0[0] =
        Bilateral_Ankle_Exo_B.sf_Mux1_o.x[0];
      Bilateral_Ankle_Exo_DW.RT10_Buffer0[1] =
        Bilateral_Ankle_Exo_B.sf_Mux1_o.x[1];
      Bilateral_Ankle_Exo_DW.RT10_Buffer0[2] =
        Bilateral_Ankle_Exo_B.sf_Mux1_o.x[2];
    }

    Bilateral_Ankle_Exo_DW.RT10_last_buf_wr =
      Bilateral_Ankle_Exo_DW.RT10_write_buf;
    Bilateral_Ankle_Exo_DW.RT10_write_buf = -1;

    /* End of RateTransition: '<Root>/RT10' */

    /* S-Function (rti_commonblock): '<S8>/S-Function1' */

    /* This comment workarounds a code generation problem */

    /* End of Outputs for S-Function (rti_commonblock): '<S8>/S-Function1' */

    /* Gain: '<S86>/Gain' */
    Bilateral_Ankle_Exo_B.Gain_h = Bilateral_Ankle_Exo_P.uOrderTD_Ts *
      Bilateral_Ankle_Exo_B.x2k1;

    /* Sum: '<S86>/Add' */
    Bilateral_Ankle_Exo_B.x1k = Bilateral_Ankle_Exo_B.Gain_h +
      Bilateral_Ankle_Exo_B.x1k1;

    /* MATLAB Function: '<S33>/MATLAB Function' */
    /* MATLAB Function 'Sensor Data/Torque module/MATLAB Function': '<S93>:1' */
    /* '<S93>:1:13' */
    /* '<S93>:1:8' */
    memcpy(&B[0], &Bilateral_Ankle_Exo_DW.data[1], 14U * sizeof(real_T));
    B[14] = Bilateral_Ankle_Exo_B.torque;
    memcpy(&Bilateral_Ankle_Exo_DW.data[0], &B[0], 15U * sizeof(real_T));

    /* '<S93>:1:13' */
    for (i = 0; i < 30; i++) {
      A[i] = b_A[i];
    }

    Bilateral_Ankle_Exo_xgeqp3(A, tau, jpvt);
    i = 0;
    torque_zero = 15.0 * fabs(A[0]) * 2.2204460492503131E-16;
    while ((i < 2) && (!(fabs(A[15 * i + i]) <= torque_zero))) {
      i++;
    }

    x[0] = 0.0;
    x[1] = 0.0;
    memcpy(&B[0], &Bilateral_Ankle_Exo_DW.data[0], 15U * sizeof(real_T));
    if (tau[0] != 0.0) {
      torque_zero = B[0];
      for (c_i = 1; c_i + 1 < 16; c_i++) {
        torque_zero += A[c_i] * B[c_i];
      }

      torque_zero *= tau[0];
      if (torque_zero != 0.0) {
        B[0] -= torque_zero;
        for (c_i = 1; c_i + 1 < 16; c_i++) {
          B[c_i] -= A[c_i] * torque_zero;
        }
      }
    }

    if (tau[1] != 0.0) {
      torque_zero = B[1];
      for (c_i = 2; c_i + 1 < 16; c_i++) {
        torque_zero += A[c_i + 15] * B[c_i];
      }

      torque_zero *= tau[1];
      if (torque_zero != 0.0) {
        B[1] -= torque_zero;
        for (c_i = 2; c_i + 1 < 16; c_i++) {
          B[c_i] -= A[c_i + 15] * torque_zero;
        }
      }
    }

    for (c_i = 0; c_i + 1 <= i; c_i++) {
      x[jpvt[c_i] - 1] = B[c_i];
    }

    for (i--; i + 1 > 0; i--) {
      x[jpvt[i] - 1] /= A[15 * i + i];
      c_i = 1;
      while (c_i <= i) {
        x[jpvt[0] - 1] -= x[jpvt[i] - 1] * A[15 * i];
        c_i = 2;
      }
    }

    /* '<S93>:1:15' */
    Bilateral_Ankle_Exo_B.torque_dot = x[1] * 5000.0;

    /* End of MATLAB Function: '<S33>/MATLAB Function' */

    /* Gain: '<S87>/Gain' */
    Bilateral_Ankle_Exo_B.Gain_n = Bilateral_Ankle_Exo_P.uOrderTD1_Ts_a *
      Bilateral_Ankle_Exo_B.x2k1_m;

    /* Sum: '<S87>/Add' */
    Bilateral_Ankle_Exo_B.x1k_o = Bilateral_Ankle_Exo_B.Gain_n +
      Bilateral_Ankle_Exo_B.x1k1_f;

    /* S-Function (rti_commonblock): '<S92>/S-Function1' */
    /* This comment workarounds a code generation problem */

    /* S-Function (rti_commonblock): '<S38>/S-Function1' incorporates:
     *  Constant: '<S28>/VCC1'
     */
    /* This comment workarounds a code generation problem */

    /* --- Bilateral_Ankle_Exo/Sensor Data/Ankle Encoder/Encoder Power Setup1 --- */
    /* --- [RTI120X, BITOUT] - Port: 3 - Channel: 15 --- */
    {
      /* define variables required for BitOut realtime functions */
      UInt32 outputData = 0;

      /* write output state value to digital output channel 15-15 on port 3 */
      outputData = ( ( ( (UInt32)Bilateral_Ankle_Exo_P.VCC1_Value) << (15 - 1)) |
                    outputData);
      DioCl1DigOut_setChMaskOutData(pRTIDioC1DigOut_Port_3_Ch_15, outputData);
      DioCl1DigOut_write(pRTIDioC1DigOut_Port_3_Ch_15);
    }

    /* S-Function (rti_commonblock): '<S39>/S-Function1' incorporates:
     *  Constant: '<S28>/VCC2'
     */
    /* This comment workarounds a code generation problem */

    /* --- Bilateral_Ankle_Exo/Sensor Data/Ankle Encoder/Encoder Power Setup2 --- */
    /* --- [RTI120X, BITOUT] - Port: 3 - Channel: 16 --- */
    {
      /* define variables required for BitOut realtime functions */
      UInt32 outputData = 0;

      /* write output state value to digital output channel 16-16 on port 3 */
      outputData = ( ( ( (UInt32)Bilateral_Ankle_Exo_P.VCC2_Value) << (16 - 1)) |
                    outputData);
      DioCl1DigOut_setChMaskOutData(pRTIDioC1DigOut_Port_3_Ch_16, outputData);
      DioCl1DigOut_write(pRTIDioC1DigOut_Port_3_Ch_16);
    }

    /* Gain: '<S77>/Gain' */
    Bilateral_Ankle_Exo_B.Gain_hf = Bilateral_Ankle_Exo_P.uOrderTD1_Ts *
      Bilateral_Ankle_Exo_B.x2k1_h;

    /* Sum: '<S77>/Add' */
    Bilateral_Ankle_Exo_B.x1k_i = Bilateral_Ankle_Exo_B.Gain_hf +
      Bilateral_Ankle_Exo_B.x1k1_g;

    /* Gain: '<S76>/Gain' */
    Bilateral_Ankle_Exo_B.Gain_o = Bilateral_Ankle_Exo_P.uOrderTD_Ts_n *
      Bilateral_Ankle_Exo_B.x2k1_d;

    /* Sum: '<S76>/Add' */
    Bilateral_Ankle_Exo_B.x1k_k = Bilateral_Ankle_Exo_B.Gain_o +
      Bilateral_Ankle_Exo_B.x1k1_e;

    /* S-Function (rti_commonblock): '<S82>/S-Function1' incorporates:
     *  Constant: '<S32>/VCC2'
     */
    /* This comment workarounds a code generation problem */

    /* --- Bilateral_Ankle_Exo/Sensor Data/Motor Encoder/Encoder Power Setup2 --- */
    /* --- [RTI120X, BITOUT] - Port: 3 - Channel: 12 --- */
    {
      /* define variables required for BitOut realtime functions */
      UInt32 outputData = 0;

      /* write output state value to digital output channel 12-12 on port 3 */
      outputData = ( ( ( (UInt32)Bilateral_Ankle_Exo_P.VCC2_Value_c) << (12 - 1))
                    | outputData);
      DioCl1DigOut_setChMaskOutData(pRTIDioC1DigOut_Port_3_Ch_12, outputData);
      DioCl1DigOut_write(pRTIDioC1DigOut_Port_3_Ch_12);
    }

    /* S-Function (rti_commonblock): '<S83>/S-Function1' incorporates:
     *  Constant: '<S32>/VCC3'
     */
    /* This comment workarounds a code generation problem */

    /* --- Bilateral_Ankle_Exo/Sensor Data/Motor Encoder/Encoder Power Setup3 --- */
    /* --- [RTI120X, BITOUT] - Port: 3 - Channel: 13 --- */
    {
      /* define variables required for BitOut realtime functions */
      UInt32 outputData = 0;

      /* write output state value to digital output channel 13-13 on port 3 */
      outputData = ( ( ( (UInt32)Bilateral_Ankle_Exo_P.VCC3_Value) << (13 - 1)) |
                    outputData);
      DioCl1DigOut_setChMaskOutData(pRTIDioC1DigOut_Port_3_Ch_13, outputData);
      DioCl1DigOut_write(pRTIDioC1DigOut_Port_3_Ch_13);
    }

    /* S-Function (rti_commonblock): '<S62>/S-Function1' incorporates:
     *  Constant: '<S30>/Constant'
     */
    /* This comment workarounds a code generation problem */

    /* --- Bilateral_Ankle_Exo/Sensor Data/FootSwitch module/DIO_CLASS1_BIT_OUT_BL1 --- */
    /* --- [RTI120X, BITOUT] - Port: 1 - Channel: 1 --- */
    {
      /* define variables required for BitOut realtime functions */
      UInt32 outputData = 0;

      /* write output state value to digital output channel 1-1 on port 1 */
      outputData = ( ( ( (UInt32)Bilateral_Ankle_Exo_P.Constant_Value_e) << (1 -
        1)) | outputData);
      DioCl1DigOut_setChMaskOutData(pRTIDioC1DigOut_Port_1_Ch_1, outputData);
      DioCl1DigOut_write(pRTIDioC1DigOut_Port_1_Ch_1);
    }

    /* S-Function (rti_commonblock): '<S63>/S-Function1' incorporates:
     *  Constant: '<S30>/Constant1'
     */
    /* This comment workarounds a code generation problem */

    /* --- Bilateral_Ankle_Exo/Sensor Data/FootSwitch module/DIO_CLASS1_BIT_OUT_BL2 --- */
    /* --- [RTI120X, BITOUT] - Port: 1 - Channel: 3 --- */
    {
      /* define variables required for BitOut realtime functions */
      UInt32 outputData = 0;

      /* write output state value to digital output channel 3-3 on port 1 */
      outputData = ( ( ( (UInt32)Bilateral_Ankle_Exo_P.Constant1_Value_k) << (3
        - 1)) | outputData);
      DioCl1DigOut_setChMaskOutData(pRTIDioC1DigOut_Port_1_Ch_3, outputData);
      DioCl1DigOut_write(pRTIDioC1DigOut_Port_1_Ch_3);
    }

    /* S-Function (rti_commonblock): '<S42>/S-Function1' */
    /* This comment workarounds a code generation problem */

    /* --- Bilateral_Ankle_Exo/Sensor Data/EMG module/ADC_CLASS1_BL1 --- */
    /* --- [RTI120X, ADC C1] - Channel: 1 --- */
    {
      UInt32 readStateFlag[] = { 1 };

      /* define variable required for adc cl1 realtime functions */
      UInt32 IsNew = 0;

      /* wait until conversion result is available */
      while (IsNew == 0) {
        AdcCl1AnalogIn_isDataReady(pRTIAdcC1AnalogIn_Ch_1, &IsNew);
      }

      /* read conversion result from hardware */
      AdcCl1AnalogIn_read(pRTIAdcC1AnalogIn_Ch_1);

      /* retrieve conversion result */
      AdcCl1AnalogIn_getSingleValue(pRTIAdcC1AnalogIn_Ch_1, readStateFlag,
        (real_T*) &Bilateral_Ankle_Exo_B.SFunction1_g);
    }

    /* S-Function (rti_commonblock): '<S43>/S-Function1' */
    /* This comment workarounds a code generation problem */

    /* --- Bilateral_Ankle_Exo/Sensor Data/EMG module/ADC_CLASS1_BL2 --- */
    /* --- [RTI120X, ADC C1] - Channel: 2 --- */
    {
      UInt32 readStateFlag[] = { 1 };

      /* define variable required for adc cl1 realtime functions */
      UInt32 IsNew = 0;

      /* wait until conversion result is available */
      while (IsNew == 0) {
        AdcCl1AnalogIn_isDataReady(pRTIAdcC1AnalogIn_Ch_2, &IsNew);
      }

      /* read conversion result from hardware */
      AdcCl1AnalogIn_read(pRTIAdcC1AnalogIn_Ch_2);

      /* retrieve conversion result */
      AdcCl1AnalogIn_getSingleValue(pRTIAdcC1AnalogIn_Ch_2, readStateFlag,
        (real_T*) &Bilateral_Ankle_Exo_B.SFunction1_i);
    }

    /* S-Function (rti_commonblock): '<S44>/S-Function1' */
    /* This comment workarounds a code generation problem */

    /* --- Bilateral_Ankle_Exo/Sensor Data/EMG module/ADC_CLASS1_BL3 --- */
    /* --- [RTI120X, ADC C1] - Channel: 3 --- */
    {
      UInt32 readStateFlag[] = { 1 };

      /* define variable required for adc cl1 realtime functions */
      UInt32 IsNew = 0;

      /* wait until conversion result is available */
      while (IsNew == 0) {
        AdcCl1AnalogIn_isDataReady(pRTIAdcC1AnalogIn_Ch_3, &IsNew);
      }

      /* read conversion result from hardware */
      AdcCl1AnalogIn_read(pRTIAdcC1AnalogIn_Ch_3);

      /* retrieve conversion result */
      AdcCl1AnalogIn_getSingleValue(pRTIAdcC1AnalogIn_Ch_3, readStateFlag,
        (real_T*) &Bilateral_Ankle_Exo_B.SFunction1_m);
    }

    /* S-Function (rti_commonblock): '<S45>/S-Function1' */
    /* This comment workarounds a code generation problem */

    /* --- Bilateral_Ankle_Exo/Sensor Data/EMG module/ADC_CLASS1_BL4 --- */
    /* --- [RTI120X, ADC C1] - Channel: 4 --- */
    {
      UInt32 readStateFlag[] = { 1 };

      /* define variable required for adc cl1 realtime functions */
      UInt32 IsNew = 0;

      /* wait until conversion result is available */
      while (IsNew == 0) {
        AdcCl1AnalogIn_isDataReady(pRTIAdcC1AnalogIn_Ch_4, &IsNew);
      }

      /* read conversion result from hardware */
      AdcCl1AnalogIn_read(pRTIAdcC1AnalogIn_Ch_4);

      /* retrieve conversion result */
      AdcCl1AnalogIn_getSingleValue(pRTIAdcC1AnalogIn_Ch_4, readStateFlag,
        (real_T*) &Bilateral_Ankle_Exo_B.SFunction1_j);
    }

    /* S-Function (rti_commonblock): '<S46>/S-Function1' */
    /* This comment workarounds a code generation problem */

    /* --- Bilateral_Ankle_Exo/Sensor Data/EMG module/ADC_CLASS1_BL5 --- */
    /* --- [RTI120X, ADC C1] - Channel: 9 --- */
    {
      UInt32 readStateFlag[] = { 1 };

      /* define variable required for adc cl1 realtime functions */
      UInt32 IsNew = 0;

      /* wait until conversion result is available */
      while (IsNew == 0) {
        AdcCl1AnalogIn_isDataReady(pRTIAdcC1AnalogIn_Ch_9, &IsNew);
      }

      /* read conversion result from hardware */
      AdcCl1AnalogIn_read(pRTIAdcC1AnalogIn_Ch_9);

      /* retrieve conversion result */
      AdcCl1AnalogIn_getSingleValue(pRTIAdcC1AnalogIn_Ch_9, readStateFlag,
        (real_T*) &Bilateral_Ankle_Exo_B.SFunction1_l);
    }

    /* S-Function (rti_commonblock): '<S47>/S-Function1' */
    /* This comment workarounds a code generation problem */

    /* --- Bilateral_Ankle_Exo/Sensor Data/EMG module/ADC_CLASS1_BL6 --- */
    /* --- [RTI120X, ADC C1] - Channel: 10 --- */
    {
      UInt32 readStateFlag[] = { 1 };

      /* define variable required for adc cl1 realtime functions */
      UInt32 IsNew = 0;

      /* wait until conversion result is available */
      while (IsNew == 0) {
        AdcCl1AnalogIn_isDataReady(pRTIAdcC1AnalogIn_Ch_10, &IsNew);
      }

      /* read conversion result from hardware */
      AdcCl1AnalogIn_read(pRTIAdcC1AnalogIn_Ch_10);

      /* retrieve conversion result */
      AdcCl1AnalogIn_getSingleValue(pRTIAdcC1AnalogIn_Ch_10, readStateFlag,
        (real_T*) &Bilateral_Ankle_Exo_B.SFunction1_k);
    }

    /* Gain: '<S29>/Gain' */
    Bilateral_Ankle_Exo_B.Gain_m = Bilateral_Ankle_Exo_P.EMGmodule_Kemg *
      Bilateral_Ankle_Exo_B.SFunction1_g;

    /* Gain: '<S29>/Gain1' */
    Bilateral_Ankle_Exo_B.Gain1_aa = Bilateral_Ankle_Exo_P.EMGmodule_Kemg *
      Bilateral_Ankle_Exo_B.SFunction1_i;

    /* Gain: '<S29>/Gain2' */
    Bilateral_Ankle_Exo_B.Gain2_p = Bilateral_Ankle_Exo_P.EMGmodule_Kemg *
      Bilateral_Ankle_Exo_B.SFunction1_m;

    /* Gain: '<S29>/Gain3' */
    Bilateral_Ankle_Exo_B.Gain3_n = Bilateral_Ankle_Exo_P.EMGmodule_Kemg *
      Bilateral_Ankle_Exo_B.SFunction1_j;

    /* Gain: '<S29>/Gain4' */
    Bilateral_Ankle_Exo_B.Gain4_mo = Bilateral_Ankle_Exo_P.EMGmodule_Kemg *
      Bilateral_Ankle_Exo_B.SFunction1_l;

    /* Gain: '<S29>/Gain5' */
    Bilateral_Ankle_Exo_B.Gain5 = Bilateral_Ankle_Exo_P.EMGmodule_Kemg *
      Bilateral_Ankle_Exo_B.SFunction1_k;
  }

  /* StateSpace: '<S49>/low_pass' */
  Bilateral_Ankle_Exo_B.low_pass = 0.0;
  Bilateral_Ankle_Exo_B.low_pass += Bilateral_Ankle_Exo_P.low_pass_C *
    Bilateral_Ankle_Exo_X.low_pass_CSTATE[1];

  /* MATLAB Function: '<S49>/MVC' */
  /* MATLAB Function 'Sensor Data/EMG module/Preprocessing/MVC': '<S55>:1' */
  /* '<S55>:1:3' */
  Bilateral_Ankle_Exo_B.y_b = (Bilateral_Ankle_Exo_B.low_pass -
    Bilateral_Ankle_Exo_P.MVC_r_SOL_MIN) / (Bilateral_Ankle_Exo_P.MVC_r_SOL_MAX
    - Bilateral_Ankle_Exo_P.MVC_r_SOL_MIN);

  /* StateSpace: '<S50>/low_pass' */
  Bilateral_Ankle_Exo_B.low_pass_e = 0.0;
  Bilateral_Ankle_Exo_B.low_pass_e += Bilateral_Ankle_Exo_P.low_pass_C_a *
    Bilateral_Ankle_Exo_X.low_pass_CSTATE_b[1];

  /* MATLAB Function: '<S50>/MVC' */
  /* MATLAB Function 'Sensor Data/EMG module/Preprocessing1/MVC': '<S56>:1' */
  /* '<S56>:1:3' */
  Bilateral_Ankle_Exo_B.y_g = (Bilateral_Ankle_Exo_B.low_pass_e -
    Bilateral_Ankle_Exo_P.MVC_r_M_GAS_MIN) /
    (Bilateral_Ankle_Exo_P.MVC_r_M_GAS_MAX -
     Bilateral_Ankle_Exo_P.MVC_r_M_GAS_MIN);

  /* StateSpace: '<S51>/low_pass' */
  Bilateral_Ankle_Exo_B.low_pass_m = 0.0;
  Bilateral_Ankle_Exo_B.low_pass_m += Bilateral_Ankle_Exo_P.low_pass_C_g *
    Bilateral_Ankle_Exo_X.low_pass_CSTATE_m[1];

  /* MATLAB Function: '<S51>/MVC' */
  /* MATLAB Function 'Sensor Data/EMG module/Preprocessing2/MVC': '<S57>:1' */
  /* '<S57>:1:3' */
  Bilateral_Ankle_Exo_B.y_j = (Bilateral_Ankle_Exo_B.low_pass_m -
    Bilateral_Ankle_Exo_P.MVC_r_L_GAS_MIN) /
    (Bilateral_Ankle_Exo_P.MVC_r_L_GAS_MAX -
     Bilateral_Ankle_Exo_P.MVC_r_L_GAS_MIN);

  /* StateSpace: '<S52>/low_pass' */
  Bilateral_Ankle_Exo_B.low_pass_d = 0.0;
  Bilateral_Ankle_Exo_B.low_pass_d += Bilateral_Ankle_Exo_P.low_pass_C_e *
    Bilateral_Ankle_Exo_X.low_pass_CSTATE_d[1];

  /* MATLAB Function: '<S52>/MVC' */
  /* MATLAB Function 'Sensor Data/EMG module/Preprocessing3/MVC': '<S58>:1' */
  /* '<S58>:1:3' */
  Bilateral_Ankle_Exo_B.y_e = (Bilateral_Ankle_Exo_B.low_pass_d -
    Bilateral_Ankle_Exo_P.MVC_l_M_GAS_MIN) /
    (Bilateral_Ankle_Exo_P.MVC_l_M_GAS_MAX -
     Bilateral_Ankle_Exo_P.MVC_l_M_GAS_MIN);

  /* StateSpace: '<S54>/low_pass' */
  Bilateral_Ankle_Exo_B.low_pass_p = 0.0;
  Bilateral_Ankle_Exo_B.low_pass_p += Bilateral_Ankle_Exo_P.low_pass_C_o *
    Bilateral_Ankle_Exo_X.low_pass_CSTATE_j[1];

  /* MATLAB Function: '<S54>/MVC' */
  /* MATLAB Function 'Sensor Data/EMG module/Preprocessing9/MVC': '<S59>:1' */
  /* '<S59>:1:3' */
  Bilateral_Ankle_Exo_B.y = (Bilateral_Ankle_Exo_B.low_pass_p -
    Bilateral_Ankle_Exo_P.MVC_l_L_GAS_MIN) /
    (Bilateral_Ankle_Exo_P.MVC_l_L_GAS_MAX -
     Bilateral_Ankle_Exo_P.MVC_l_L_GAS_MIN);

  /* StateSpace: '<S53>/low_pass' */
  Bilateral_Ankle_Exo_B.low_pass_i = 0.0;
  Bilateral_Ankle_Exo_B.low_pass_i += Bilateral_Ankle_Exo_P.low_pass_C_p *
    Bilateral_Ankle_Exo_X.low_pass_CSTATE_a[1];

  /* MATLAB Function: '<S29>/Mux1' */
  /* MATLAB Function 'Sensor Data/EMG module/Mux1': '<S48>:1' */
  /* '<S48>:1:3' */
  Bilateral_Ankle_Exo_B.x[0] = Bilateral_Ankle_Exo_B.y_b;
  Bilateral_Ankle_Exo_B.x[1] = Bilateral_Ankle_Exo_B.y_g;
  Bilateral_Ankle_Exo_B.x[2] = Bilateral_Ankle_Exo_B.y_j;
  Bilateral_Ankle_Exo_B.x[3] = Bilateral_Ankle_Exo_B.y_e;
  Bilateral_Ankle_Exo_B.x[4] = Bilateral_Ankle_Exo_B.y;
  Bilateral_Ankle_Exo_B.x[5] = Bilateral_Ankle_Exo_B.low_pass_i;

  /* StateSpace: '<S49>/high_pass' */
  Bilateral_Ankle_Exo_B.high_pass = 0.0;
  Bilateral_Ankle_Exo_B.high_pass += Bilateral_Ankle_Exo_P.high_pass_C[0] *
    Bilateral_Ankle_Exo_X.high_pass_CSTATE[0];
  Bilateral_Ankle_Exo_B.high_pass += Bilateral_Ankle_Exo_P.high_pass_C[1] *
    Bilateral_Ankle_Exo_X.high_pass_CSTATE[1];
  Bilateral_Ankle_Exo_B.high_pass += Bilateral_Ankle_Exo_P.high_pass_D *
    Bilateral_Ankle_Exo_B.Gain_m;

  /* Abs: '<S49>/Abs' */
  Bilateral_Ankle_Exo_B.Abs = fabs(Bilateral_Ankle_Exo_B.high_pass);

  /* StateSpace: '<S50>/high_pass' */
  Bilateral_Ankle_Exo_B.high_pass_h = 0.0;
  Bilateral_Ankle_Exo_B.high_pass_h += Bilateral_Ankle_Exo_P.high_pass_C_b[0] *
    Bilateral_Ankle_Exo_X.high_pass_CSTATE_p[0];
  Bilateral_Ankle_Exo_B.high_pass_h += Bilateral_Ankle_Exo_P.high_pass_C_b[1] *
    Bilateral_Ankle_Exo_X.high_pass_CSTATE_p[1];
  Bilateral_Ankle_Exo_B.high_pass_h += Bilateral_Ankle_Exo_P.high_pass_D_d *
    Bilateral_Ankle_Exo_B.Gain1_aa;

  /* Abs: '<S50>/Abs' */
  Bilateral_Ankle_Exo_B.Abs_i = fabs(Bilateral_Ankle_Exo_B.high_pass_h);

  /* StateSpace: '<S51>/high_pass' */
  Bilateral_Ankle_Exo_B.high_pass_hy = 0.0;
  Bilateral_Ankle_Exo_B.high_pass_hy += Bilateral_Ankle_Exo_P.high_pass_C_by[0] *
    Bilateral_Ankle_Exo_X.high_pass_CSTATE_f[0];
  Bilateral_Ankle_Exo_B.high_pass_hy += Bilateral_Ankle_Exo_P.high_pass_C_by[1] *
    Bilateral_Ankle_Exo_X.high_pass_CSTATE_f[1];
  Bilateral_Ankle_Exo_B.high_pass_hy += Bilateral_Ankle_Exo_P.high_pass_D_o *
    Bilateral_Ankle_Exo_B.Gain2_p;

  /* Abs: '<S51>/Abs' */
  Bilateral_Ankle_Exo_B.Abs_l = fabs(Bilateral_Ankle_Exo_B.high_pass_hy);

  /* StateSpace: '<S52>/high_pass' */
  Bilateral_Ankle_Exo_B.high_pass_j = 0.0;
  Bilateral_Ankle_Exo_B.high_pass_j += Bilateral_Ankle_Exo_P.high_pass_C_p[0] *
    Bilateral_Ankle_Exo_X.high_pass_CSTATE_a[0];
  Bilateral_Ankle_Exo_B.high_pass_j += Bilateral_Ankle_Exo_P.high_pass_C_p[1] *
    Bilateral_Ankle_Exo_X.high_pass_CSTATE_a[1];
  Bilateral_Ankle_Exo_B.high_pass_j += Bilateral_Ankle_Exo_P.high_pass_D_n *
    Bilateral_Ankle_Exo_B.Gain3_n;

  /* Abs: '<S52>/Abs' */
  Bilateral_Ankle_Exo_B.Abs_b = fabs(Bilateral_Ankle_Exo_B.high_pass_j);

  /* StateSpace: '<S53>/high_pass' */
  Bilateral_Ankle_Exo_B.high_pass_e = 0.0;
  Bilateral_Ankle_Exo_B.high_pass_e += Bilateral_Ankle_Exo_P.high_pass_C_e[0] *
    Bilateral_Ankle_Exo_X.high_pass_CSTATE_o[0];
  Bilateral_Ankle_Exo_B.high_pass_e += Bilateral_Ankle_Exo_P.high_pass_C_e[1] *
    Bilateral_Ankle_Exo_X.high_pass_CSTATE_o[1];
  Bilateral_Ankle_Exo_B.high_pass_e += Bilateral_Ankle_Exo_P.high_pass_D_l *
    Bilateral_Ankle_Exo_B.Gain5;

  /* Abs: '<S53>/Abs' */
  Bilateral_Ankle_Exo_B.Abs_lh = fabs(Bilateral_Ankle_Exo_B.high_pass_e);

  /* StateSpace: '<S54>/high_pass' */
  Bilateral_Ankle_Exo_B.high_pass_b = 0.0;
  Bilateral_Ankle_Exo_B.high_pass_b += Bilateral_Ankle_Exo_P.high_pass_C_h[0] *
    Bilateral_Ankle_Exo_X.high_pass_CSTATE_ff[0];
  Bilateral_Ankle_Exo_B.high_pass_b += Bilateral_Ankle_Exo_P.high_pass_C_h[1] *
    Bilateral_Ankle_Exo_X.high_pass_CSTATE_ff[1];
  Bilateral_Ankle_Exo_B.high_pass_b += Bilateral_Ankle_Exo_P.high_pass_D_e *
    Bilateral_Ankle_Exo_B.Gain4_mo;

  /* Abs: '<S54>/Abs' */
  Bilateral_Ankle_Exo_B.Abs_p = fabs(Bilateral_Ankle_Exo_B.high_pass_b);
  if (rtmIsMajorTimeStep(Bilateral_Ankle_Exo_M) &&
      Bilateral_Ankle_Exo_M->Timing.TaskCounters.TID[1] == 0) {
    /* Constant: '<S5>/Constant' */
    Bilateral_Ankle_Exo_B.Constant = Bilateral_Ankle_Exo_P.Constant_Value;

    /* Constant: '<S5>/Constant1' */
    Bilateral_Ankle_Exo_B.Constant1 = Bilateral_Ankle_Exo_P.Constant1_Value;

    /* S-Function (rti_commonblock): '<S72>/S-Function1' */
    /* This comment workarounds a code generation problem */

    /* dSPACE RTICAN RX Message Block: "RX Message" Id:3 */
    {
      UInt32 *CAN_Msg;

      /* ... Read status and timestamp info (previous message) */
      can_tp1_msg_read_from_mem(can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X3]);

      /* Convert timestamp */
      if (can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X3]->processed) {
        can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X3]->timestamp =
          rtk_dsts_time_to_simtime_convert
          (can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X3]->timestamp);
      }

      /* Messages with timestamp zero have been received in pause/stop state
         and must not be handled.
       */
      if (can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X3]->timestamp > 0.0) {
        if (can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X3]->processed) {
          Bilateral_Ankle_Exo_B.SFunction1_o4 = (real_T)
            can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X3]->processed;
          Bilateral_Ankle_Exo_B.SFunction1_o5 = (real_T)
            can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X3]->timestamp;
          CAN_Msg = can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X3]->data;

          /* ... Decode CAN Message */
          {
            rtican_Signal_t CAN_Sgn;

            /* ...... "Accel_x" (0|16, standard signal, signed int, little endian) */
            CAN_Sgn.SgnBytes.Byte0 = CAN_Msg[0];
            CAN_Sgn.SgnBytes.Byte1 = CAN_Msg[1];
            CAN_Sgn.SignedSgn &= 0x0000FFFF;
            if (CAN_Sgn.SignedSgn >> 15) {
              CAN_Sgn.SignedSgn |= 0xFFFF0000;
            }

            Bilateral_Ankle_Exo_B.SFunction1_o1_c = ((real_T) CAN_Sgn.SignedSgn);

            /* ...... "Accel_y" (16|16, standard signal, signed int, little endian) */
            CAN_Sgn.SgnBytes.Byte0 = CAN_Msg[2];
            CAN_Sgn.SgnBytes.Byte1 = CAN_Msg[3];
            CAN_Sgn.SignedSgn &= 0x0000FFFF;
            if (CAN_Sgn.SignedSgn >> 15) {
              CAN_Sgn.SignedSgn |= 0xFFFF0000;
            }

            Bilateral_Ankle_Exo_B.SFunction1_o2_l = ((real_T) CAN_Sgn.SignedSgn);

            /* ...... "Accel_z" (32|16, standard signal, signed int, little endian) */
            CAN_Sgn.SgnBytes.Byte0 = CAN_Msg[4];
            CAN_Sgn.SgnBytes.Byte1 = CAN_Msg[5];
            CAN_Sgn.SignedSgn &= 0x0000FFFF;
            if (CAN_Sgn.SignedSgn >> 15) {
              CAN_Sgn.SignedSgn |= 0xFFFF0000;
            }

            Bilateral_Ankle_Exo_B.SFunction1_o3 = ((real_T) CAN_Sgn.SignedSgn);
          }
        }
      }

      if (!can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X3]->processed) {
        /* ... set RX status to 0 because no new message has arrived */
        Bilateral_Ankle_Exo_B.SFunction1_o4 = 0.0;
      }
    }

    /* DataTypeConversion: '<S73>/Data Type Conversion' */
    Bilateral_Ankle_Exo_B.DataTypeConversion =
      Bilateral_Ankle_Exo_B.SFunction1_o1_c;

    /* Gain: '<S73>/Gain' */
    Bilateral_Ankle_Exo_B.Gain_gd = Bilateral_Ankle_Exo_P.Gain_Gain_a *
      Bilateral_Ankle_Exo_B.DataTypeConversion;

    /* DataTypeConversion: '<S74>/Data Type Conversion' */
    Bilateral_Ankle_Exo_B.DataTypeConversion_j =
      Bilateral_Ankle_Exo_B.SFunction1_o2_l;

    /* Gain: '<S74>/Gain' */
    Bilateral_Ankle_Exo_B.Gain_b = Bilateral_Ankle_Exo_P.Gain_Gain_h *
      Bilateral_Ankle_Exo_B.DataTypeConversion_j;

    /* DataTypeConversion: '<S75>/Data Type Conversion' */
    Bilateral_Ankle_Exo_B.DataTypeConversion_m =
      Bilateral_Ankle_Exo_B.SFunction1_o3;

    /* Gain: '<S75>/Gain' */
    Bilateral_Ankle_Exo_B.Gain_n4 = Bilateral_Ankle_Exo_P.Gain_Gain_j *
      Bilateral_Ankle_Exo_B.DataTypeConversion_m;

    /* S-Function (rti_commonblock): '<S66>/S-Function1' */
    /* This comment workarounds a code generation problem */

    /* S-Function (rti_commonblock): '<S67>/S-Function1' */
    /* This comment workarounds a code generation problem */

    /* S-Function (rti_commonblock): '<S70>/S-Function1' */
    /* This comment workarounds a code generation problem */

    /* dSPACE RTICAN RX Message Block: "RX Message" Id:100 */
    {
      UInt32 *CAN_Msg;

      /* ... Read status and timestamp info (previous message) */
      can_tp1_msg_read_from_mem(can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X64]);

      /* Convert timestamp */
      if (can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X64]->processed) {
        can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X64]->timestamp =
          rtk_dsts_time_to_simtime_convert
          (can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X64]->timestamp);
      }

      /* Messages with timestamp zero have been received in pause/stop state
         and must not be handled.
       */
      if (can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X64]->timestamp > 0.0) {
        if (can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X64]->processed) {
          Bilateral_Ankle_Exo_B.SFunction1_o2_f = (real_T)
            can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X64]->processed;
          Bilateral_Ankle_Exo_B.SFunction1_o3_g = (real_T)
            can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X64]->timestamp;
          CAN_Msg = can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X64]->data;

          /* ... Decode CAN Message */
          {
            rtican_Signal_t CAN_Sgn;

            /* ...... "RX signal" (0|32, standard signal, IEEE 32, little endian) */
            CAN_Sgn.SgnBytes.Byte0 = CAN_Msg[0];
            CAN_Sgn.SgnBytes.Byte1 = CAN_Msg[1];
            CAN_Sgn.SgnBytes.Byte2 = CAN_Msg[2];
            CAN_Sgn.SgnBytes.Byte3 = CAN_Msg[3];
            Bilateral_Ankle_Exo_B.SFunction1_o1_h = ((real_T) CAN_Sgn.IeeeVal32);
          }
        }
      }

      if (!can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X64]->processed) {
        /* ... set RX status to 0 because no new message has arrived */
        Bilateral_Ankle_Exo_B.SFunction1_o2_f = 0.0;
      }
    }
  }

  /* Sin: '<S68>/Sine Wave' */
  Bilateral_Ankle_Exo_B.SineWave = sin(Bilateral_Ankle_Exo_P.SineWave_Freq *
    Bilateral_Ankle_Exo_M->Timing.t[0] + Bilateral_Ankle_Exo_P.SineWave_Phase) *
    Bilateral_Ankle_Exo_P.SineWave_Amp + Bilateral_Ankle_Exo_P.SineWave_Bias;
  if (rtmIsMajorTimeStep(Bilateral_Ankle_Exo_M) &&
      Bilateral_Ankle_Exo_M->Timing.TaskCounters.TID[1] == 0) {
    /* S-Function (rti_commonblock): '<S71>/S-Function1' */
    /* This comment workarounds a code generation problem */

    /* dSPACE RTICAN TX Message Block: "TX Message" Id:100 */
    {
      UInt32 CAN_Msg[8] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };

      Float32 delayTime = 0.0;

      /* ... Read status and timestamp info (previous message) */
      can_tp1_msg_read(can_type1_msg_M1[CANTP1_M1_C2_TX_STD_0X64]);

      /* Convert timestamp */
      if (can_type1_msg_M1[CANTP1_M1_C2_TX_STD_0X64]->processed) {
        can_type1_msg_M1[CANTP1_M1_C2_TX_STD_0X64]->timestamp =
          rtk_dsts_time_to_simtime_convert
          (can_type1_msg_M1[CANTP1_M1_C2_TX_STD_0X64]->timestamp);
      }

      /* Messages with timestamp zero have been received in pause/stop state
         and must not be handled.
       */
      if (can_type1_msg_M1[CANTP1_M1_C2_TX_STD_0X64]->timestamp > 0.0) {
        Bilateral_Ankle_Exo_B.SFunction1_o1_l = (real_T)
          can_type1_msg_M1[CANTP1_M1_C2_TX_STD_0X64]->processed;
        Bilateral_Ankle_Exo_B.SFunction1_o2_jb = (real_T)
          can_type1_msg_M1[CANTP1_M1_C2_TX_STD_0X64]->timestamp;
        Bilateral_Ankle_Exo_B.SFunction1_o3_p = (real_T)
          can_type1_msg_M1[CANTP1_M1_C2_TX_STD_0X64]->deltatime;
        Bilateral_Ankle_Exo_B.SFunction1_o4_k = (real_T)
          can_type1_msg_M1[CANTP1_M1_C2_TX_STD_0X64]->delaytime;
      }

      /* ... Encode Simulink signals of TX and RM blocks*/
      {
        rtican_Signal_t CAN_Sgn;

        /* ...... "TX signal" (0|32, standard signal, IEEE 32, little endian) */
        /* Add or substract 0.5 in order to round to nearest integer */
        CAN_Sgn.IeeeVal32 = (Float32) (( Bilateral_Ankle_Exo_B.SineWave ));
        CAN_Msg[0] |= CAN_Sgn.SgnBytes.Byte0;
        CAN_Msg[1] |= CAN_Sgn.SgnBytes.Byte1;
        CAN_Msg[2] |= CAN_Sgn.SgnBytes.Byte2;
        CAN_Msg[3] |= CAN_Sgn.SgnBytes.Byte3;
      }

      /* ... Write the data to the CAN microcontroller and trigger the sending of the message */
      can_tp1_msg_send(can_type1_msg_M1[CANTP1_M1_C2_TX_STD_0X64], 8, &(CAN_Msg
        [0]), delayTime);
    }
  }

  if (rtmIsMajorTimeStep(Bilateral_Ankle_Exo_M) &&
      Bilateral_Ankle_Exo_M->Timing.TaskCounters.TID[2] == 0) {
    /* S-Function (rti_commonblock): '<S2>/S-Function1' */
    /* This comment workarounds a code generation problem */
  }

  /* user code (Output function Trailer for TID0) */

  /* dSPACE Data Capture block: Bilateral_Ankle_Exo/Data Capture1 */
  /* ... Service number: 1 */
  /* ... Service name:   500Hz */
  if (rtmIsMajorTimeStep(Bilateral_Ankle_Exo_M) &&
      Bilateral_Ankle_Exo_M->Timing.TaskCounters.TID[2] == 0) {
    DsDaq_Service(0, 0, 1, (DsDaqSTimestampStruct *)
                  rtk_current_task_absolute_time_ptr_get());
  }
}

/* Model update function */
void Bilateral_Ankle_Exo_update(void)
{
  if (rtmIsMajorTimeStep(Bilateral_Ankle_Exo_M) &&
      Bilateral_Ankle_Exo_M->Timing.TaskCounters.TID[1] == 0) {
    /* Update for DiscreteFilter: '<S33>/0.4low2' */
    Bilateral_Ankle_Exo_DW.u4low2_states[2] =
      Bilateral_Ankle_Exo_DW.u4low2_states[1];
    Bilateral_Ankle_Exo_DW.u4low2_states[1] =
      Bilateral_Ankle_Exo_DW.u4low2_states[0];
    Bilateral_Ankle_Exo_DW.u4low2_states[0] = Bilateral_Ankle_Exo_DW.u4low2_tmp;

    /* Update for UnitDelay: '<S86>/Unit Delay1' */
    Bilateral_Ankle_Exo_DW.UnitDelay1_DSTATE = Bilateral_Ankle_Exo_B.x2k;

    /* Update for UnitDelay: '<S86>/Unit Delay' */
    Bilateral_Ankle_Exo_DW.UnitDelay_DSTATE = Bilateral_Ankle_Exo_B.x1k;

    /* Update for UnitDelay: '<S86>/Unit Delay2' */
    Bilateral_Ankle_Exo_DW.UnitDelay2_DSTATE = Bilateral_Ankle_Exo_B.torque;

    /* Update for UnitDelay: '<S77>/Unit Delay1' */
    Bilateral_Ankle_Exo_DW.UnitDelay1_DSTATE_n = Bilateral_Ankle_Exo_B.x2k_k;

    /* Update for UnitDelay: '<S77>/Unit Delay' */
    Bilateral_Ankle_Exo_DW.UnitDelay_DSTATE_o = Bilateral_Ankle_Exo_B.x1k_i;

    /* Update for UnitDelay: '<S77>/Unit Delay2' */
    Bilateral_Ankle_Exo_DW.UnitDelay2_DSTATE_i = Bilateral_Ankle_Exo_B.Gain4_m;

    /* Update for DiscreteFilter: '<S33>/0.4low1' */
    Bilateral_Ankle_Exo_DW.u4low1_states[2] =
      Bilateral_Ankle_Exo_DW.u4low1_states[1];
    Bilateral_Ankle_Exo_DW.u4low1_states[1] =
      Bilateral_Ankle_Exo_DW.u4low1_states[0];
    Bilateral_Ankle_Exo_DW.u4low1_states[0] = Bilateral_Ankle_Exo_DW.u4low1_tmp;

    /* Update for UnitDelay: '<S87>/Unit Delay1' */
    Bilateral_Ankle_Exo_DW.UnitDelay1_DSTATE_m = Bilateral_Ankle_Exo_B.x2k_l;

    /* Update for UnitDelay: '<S87>/Unit Delay' */
    Bilateral_Ankle_Exo_DW.UnitDelay_DSTATE_n = Bilateral_Ankle_Exo_B.x1k_o;

    /* Update for UnitDelay: '<S87>/Unit Delay2' */
    Bilateral_Ankle_Exo_DW.UnitDelay2_DSTATE_l = Bilateral_Ankle_Exo_B.torque_k;

    /* Update for UnitDelay: '<S76>/Unit Delay1' */
    Bilateral_Ankle_Exo_DW.UnitDelay1_DSTATE_f = Bilateral_Ankle_Exo_B.x2k_a;

    /* Update for UnitDelay: '<S76>/Unit Delay' */
    Bilateral_Ankle_Exo_DW.UnitDelay_DSTATE_a = Bilateral_Ankle_Exo_B.x1k_k;

    /* Update for UnitDelay: '<S76>/Unit Delay2' */
    Bilateral_Ankle_Exo_DW.UnitDelay2_DSTATE_e = Bilateral_Ankle_Exo_B.Gain3_h;
  }

  if (rtmIsMajorTimeStep(Bilateral_Ankle_Exo_M)) {
    rt_ertODEUpdateContinuousStates(&Bilateral_Ankle_Exo_M->solverInfo);
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++Bilateral_Ankle_Exo_M->Timing.clockTick0)) {
    ++Bilateral_Ankle_Exo_M->Timing.clockTickH0;
  }

  Bilateral_Ankle_Exo_M->Timing.t[0] = rtsiGetSolverStopTime
    (&Bilateral_Ankle_Exo_M->solverInfo);

  {
    /* Update absolute timer for sample time: [0.0002s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.0002, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    Bilateral_Ankle_Exo_M->Timing.clockTick1++;
    if (!Bilateral_Ankle_Exo_M->Timing.clockTick1) {
      Bilateral_Ankle_Exo_M->Timing.clockTickH1++;
    }
  }

  rate_scheduler();
}

/* Derivatives for root system: '<Root>' */
void Bilateral_Ankle_Exo_derivatives(void)
{
  XDot_Bilateral_Ankle_Exo_T *_rtXdot;
  _rtXdot = ((XDot_Bilateral_Ankle_Exo_T *) Bilateral_Ankle_Exo_M->derivs);

  /* Derivatives for StateSpace: '<S49>/low_pass' */
  _rtXdot->low_pass_CSTATE[0] = 0.0;
  _rtXdot->low_pass_CSTATE[1] = 0.0;
  _rtXdot->low_pass_CSTATE[0] += Bilateral_Ankle_Exo_P.low_pass_A[0] *
    Bilateral_Ankle_Exo_X.low_pass_CSTATE[0];
  _rtXdot->low_pass_CSTATE[0] += Bilateral_Ankle_Exo_P.low_pass_A[1] *
    Bilateral_Ankle_Exo_X.low_pass_CSTATE[1];
  _rtXdot->low_pass_CSTATE[1] += Bilateral_Ankle_Exo_P.low_pass_A[2] *
    Bilateral_Ankle_Exo_X.low_pass_CSTATE[0];
  _rtXdot->low_pass_CSTATE[0] += Bilateral_Ankle_Exo_P.low_pass_B *
    Bilateral_Ankle_Exo_B.Abs;

  /* Derivatives for StateSpace: '<S50>/low_pass' */
  _rtXdot->low_pass_CSTATE_b[0] = 0.0;
  _rtXdot->low_pass_CSTATE_b[1] = 0.0;
  _rtXdot->low_pass_CSTATE_b[0] += Bilateral_Ankle_Exo_P.low_pass_A_k[0] *
    Bilateral_Ankle_Exo_X.low_pass_CSTATE_b[0];
  _rtXdot->low_pass_CSTATE_b[0] += Bilateral_Ankle_Exo_P.low_pass_A_k[1] *
    Bilateral_Ankle_Exo_X.low_pass_CSTATE_b[1];
  _rtXdot->low_pass_CSTATE_b[1] += Bilateral_Ankle_Exo_P.low_pass_A_k[2] *
    Bilateral_Ankle_Exo_X.low_pass_CSTATE_b[0];
  _rtXdot->low_pass_CSTATE_b[0] += Bilateral_Ankle_Exo_P.low_pass_B_j *
    Bilateral_Ankle_Exo_B.Abs_i;

  /* Derivatives for StateSpace: '<S51>/low_pass' */
  _rtXdot->low_pass_CSTATE_m[0] = 0.0;
  _rtXdot->low_pass_CSTATE_m[1] = 0.0;
  _rtXdot->low_pass_CSTATE_m[0] += Bilateral_Ankle_Exo_P.low_pass_A_e[0] *
    Bilateral_Ankle_Exo_X.low_pass_CSTATE_m[0];
  _rtXdot->low_pass_CSTATE_m[0] += Bilateral_Ankle_Exo_P.low_pass_A_e[1] *
    Bilateral_Ankle_Exo_X.low_pass_CSTATE_m[1];
  _rtXdot->low_pass_CSTATE_m[1] += Bilateral_Ankle_Exo_P.low_pass_A_e[2] *
    Bilateral_Ankle_Exo_X.low_pass_CSTATE_m[0];
  _rtXdot->low_pass_CSTATE_m[0] += Bilateral_Ankle_Exo_P.low_pass_B_f *
    Bilateral_Ankle_Exo_B.Abs_l;

  /* Derivatives for StateSpace: '<S52>/low_pass' */
  _rtXdot->low_pass_CSTATE_d[0] = 0.0;
  _rtXdot->low_pass_CSTATE_d[1] = 0.0;
  _rtXdot->low_pass_CSTATE_d[0] += Bilateral_Ankle_Exo_P.low_pass_A_l[0] *
    Bilateral_Ankle_Exo_X.low_pass_CSTATE_d[0];
  _rtXdot->low_pass_CSTATE_d[0] += Bilateral_Ankle_Exo_P.low_pass_A_l[1] *
    Bilateral_Ankle_Exo_X.low_pass_CSTATE_d[1];
  _rtXdot->low_pass_CSTATE_d[1] += Bilateral_Ankle_Exo_P.low_pass_A_l[2] *
    Bilateral_Ankle_Exo_X.low_pass_CSTATE_d[0];
  _rtXdot->low_pass_CSTATE_d[0] += Bilateral_Ankle_Exo_P.low_pass_B_n *
    Bilateral_Ankle_Exo_B.Abs_b;

  /* Derivatives for StateSpace: '<S54>/low_pass' */
  _rtXdot->low_pass_CSTATE_j[0] = 0.0;
  _rtXdot->low_pass_CSTATE_j[1] = 0.0;
  _rtXdot->low_pass_CSTATE_j[0] += Bilateral_Ankle_Exo_P.low_pass_A_c[0] *
    Bilateral_Ankle_Exo_X.low_pass_CSTATE_j[0];
  _rtXdot->low_pass_CSTATE_j[0] += Bilateral_Ankle_Exo_P.low_pass_A_c[1] *
    Bilateral_Ankle_Exo_X.low_pass_CSTATE_j[1];
  _rtXdot->low_pass_CSTATE_j[1] += Bilateral_Ankle_Exo_P.low_pass_A_c[2] *
    Bilateral_Ankle_Exo_X.low_pass_CSTATE_j[0];
  _rtXdot->low_pass_CSTATE_j[0] += Bilateral_Ankle_Exo_P.low_pass_B_m *
    Bilateral_Ankle_Exo_B.Abs_p;

  /* Derivatives for StateSpace: '<S53>/low_pass' */
  _rtXdot->low_pass_CSTATE_a[0] = 0.0;
  _rtXdot->low_pass_CSTATE_a[1] = 0.0;
  _rtXdot->low_pass_CSTATE_a[0] += Bilateral_Ankle_Exo_P.low_pass_A_ec[0] *
    Bilateral_Ankle_Exo_X.low_pass_CSTATE_a[0];
  _rtXdot->low_pass_CSTATE_a[0] += Bilateral_Ankle_Exo_P.low_pass_A_ec[1] *
    Bilateral_Ankle_Exo_X.low_pass_CSTATE_a[1];
  _rtXdot->low_pass_CSTATE_a[1] += Bilateral_Ankle_Exo_P.low_pass_A_ec[2] *
    Bilateral_Ankle_Exo_X.low_pass_CSTATE_a[0];
  _rtXdot->low_pass_CSTATE_a[0] += Bilateral_Ankle_Exo_P.low_pass_B_h *
    Bilateral_Ankle_Exo_B.Abs_lh;

  /* Derivatives for StateSpace: '<S49>/high_pass' */
  _rtXdot->high_pass_CSTATE[0] = 0.0;

  /* Derivatives for StateSpace: '<S50>/high_pass' */
  _rtXdot->high_pass_CSTATE_p[0] = 0.0;

  /* Derivatives for StateSpace: '<S51>/high_pass' */
  _rtXdot->high_pass_CSTATE_f[0] = 0.0;

  /* Derivatives for StateSpace: '<S52>/high_pass' */
  _rtXdot->high_pass_CSTATE_a[0] = 0.0;

  /* Derivatives for StateSpace: '<S53>/high_pass' */
  _rtXdot->high_pass_CSTATE_o[0] = 0.0;

  /* Derivatives for StateSpace: '<S54>/high_pass' */
  _rtXdot->high_pass_CSTATE_ff[0] = 0.0;

  /* Derivatives for StateSpace: '<S49>/high_pass' */
  _rtXdot->high_pass_CSTATE[1] = 0.0;

  /* Derivatives for StateSpace: '<S50>/high_pass' */
  _rtXdot->high_pass_CSTATE_p[1] = 0.0;

  /* Derivatives for StateSpace: '<S51>/high_pass' */
  _rtXdot->high_pass_CSTATE_f[1] = 0.0;

  /* Derivatives for StateSpace: '<S52>/high_pass' */
  _rtXdot->high_pass_CSTATE_a[1] = 0.0;

  /* Derivatives for StateSpace: '<S53>/high_pass' */
  _rtXdot->high_pass_CSTATE_o[1] = 0.0;

  /* Derivatives for StateSpace: '<S54>/high_pass' */
  _rtXdot->high_pass_CSTATE_ff[1] = 0.0;

  /* Derivatives for StateSpace: '<S49>/high_pass' */
  _rtXdot->high_pass_CSTATE[0] += Bilateral_Ankle_Exo_P.high_pass_A[0] *
    Bilateral_Ankle_Exo_X.high_pass_CSTATE[1];
  _rtXdot->high_pass_CSTATE[1] += Bilateral_Ankle_Exo_P.high_pass_A[1] *
    Bilateral_Ankle_Exo_X.high_pass_CSTATE[0];
  _rtXdot->high_pass_CSTATE[1] += Bilateral_Ankle_Exo_P.high_pass_A[2] *
    Bilateral_Ankle_Exo_X.high_pass_CSTATE[1];
  _rtXdot->high_pass_CSTATE[1] += Bilateral_Ankle_Exo_P.high_pass_B *
    Bilateral_Ankle_Exo_B.Gain_m;

  /* Derivatives for StateSpace: '<S50>/high_pass' */
  _rtXdot->high_pass_CSTATE_p[0] += Bilateral_Ankle_Exo_P.high_pass_A_g[0] *
    Bilateral_Ankle_Exo_X.high_pass_CSTATE_p[1];
  _rtXdot->high_pass_CSTATE_p[1] += Bilateral_Ankle_Exo_P.high_pass_A_g[1] *
    Bilateral_Ankle_Exo_X.high_pass_CSTATE_p[0];
  _rtXdot->high_pass_CSTATE_p[1] += Bilateral_Ankle_Exo_P.high_pass_A_g[2] *
    Bilateral_Ankle_Exo_X.high_pass_CSTATE_p[1];
  _rtXdot->high_pass_CSTATE_p[1] += Bilateral_Ankle_Exo_P.high_pass_B_i *
    Bilateral_Ankle_Exo_B.Gain1_aa;

  /* Derivatives for StateSpace: '<S51>/high_pass' */
  _rtXdot->high_pass_CSTATE_f[0] += Bilateral_Ankle_Exo_P.high_pass_A_p[0] *
    Bilateral_Ankle_Exo_X.high_pass_CSTATE_f[1];
  _rtXdot->high_pass_CSTATE_f[1] += Bilateral_Ankle_Exo_P.high_pass_A_p[1] *
    Bilateral_Ankle_Exo_X.high_pass_CSTATE_f[0];
  _rtXdot->high_pass_CSTATE_f[1] += Bilateral_Ankle_Exo_P.high_pass_A_p[2] *
    Bilateral_Ankle_Exo_X.high_pass_CSTATE_f[1];
  _rtXdot->high_pass_CSTATE_f[1] += Bilateral_Ankle_Exo_P.high_pass_B_h *
    Bilateral_Ankle_Exo_B.Gain2_p;

  /* Derivatives for StateSpace: '<S52>/high_pass' */
  _rtXdot->high_pass_CSTATE_a[0] += Bilateral_Ankle_Exo_P.high_pass_A_a[0] *
    Bilateral_Ankle_Exo_X.high_pass_CSTATE_a[1];
  _rtXdot->high_pass_CSTATE_a[1] += Bilateral_Ankle_Exo_P.high_pass_A_a[1] *
    Bilateral_Ankle_Exo_X.high_pass_CSTATE_a[0];
  _rtXdot->high_pass_CSTATE_a[1] += Bilateral_Ankle_Exo_P.high_pass_A_a[2] *
    Bilateral_Ankle_Exo_X.high_pass_CSTATE_a[1];
  _rtXdot->high_pass_CSTATE_a[1] += Bilateral_Ankle_Exo_P.high_pass_B_n *
    Bilateral_Ankle_Exo_B.Gain3_n;

  /* Derivatives for StateSpace: '<S53>/high_pass' */
  _rtXdot->high_pass_CSTATE_o[0] += Bilateral_Ankle_Exo_P.high_pass_A_a0[0] *
    Bilateral_Ankle_Exo_X.high_pass_CSTATE_o[1];
  _rtXdot->high_pass_CSTATE_o[1] += Bilateral_Ankle_Exo_P.high_pass_A_a0[1] *
    Bilateral_Ankle_Exo_X.high_pass_CSTATE_o[0];
  _rtXdot->high_pass_CSTATE_o[1] += Bilateral_Ankle_Exo_P.high_pass_A_a0[2] *
    Bilateral_Ankle_Exo_X.high_pass_CSTATE_o[1];
  _rtXdot->high_pass_CSTATE_o[1] += Bilateral_Ankle_Exo_P.high_pass_B_n3 *
    Bilateral_Ankle_Exo_B.Gain5;

  /* Derivatives for StateSpace: '<S54>/high_pass' */
  _rtXdot->high_pass_CSTATE_ff[0] += Bilateral_Ankle_Exo_P.high_pass_A_f[0] *
    Bilateral_Ankle_Exo_X.high_pass_CSTATE_ff[1];
  _rtXdot->high_pass_CSTATE_ff[1] += Bilateral_Ankle_Exo_P.high_pass_A_f[1] *
    Bilateral_Ankle_Exo_X.high_pass_CSTATE_ff[0];
  _rtXdot->high_pass_CSTATE_ff[1] += Bilateral_Ankle_Exo_P.high_pass_A_f[2] *
    Bilateral_Ankle_Exo_X.high_pass_CSTATE_ff[1];
  _rtXdot->high_pass_CSTATE_ff[1] += Bilateral_Ankle_Exo_P.high_pass_B_g *
    Bilateral_Ankle_Exo_B.Gain4_mo;
}

/* Model initialize function */
void Bilateral_Ankle_Exo_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Bilateral_Ankle_Exo_M, 0,
                sizeof(RT_MODEL_Bilateral_Ankle_Exo_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Bilateral_Ankle_Exo_M->solverInfo,
                          &Bilateral_Ankle_Exo_M->Timing.simTimeStep);
    rtsiSetTPtr(&Bilateral_Ankle_Exo_M->solverInfo, &rtmGetTPtr
                (Bilateral_Ankle_Exo_M));
    rtsiSetStepSizePtr(&Bilateral_Ankle_Exo_M->solverInfo,
                       &Bilateral_Ankle_Exo_M->Timing.stepSize0);
    rtsiSetdXPtr(&Bilateral_Ankle_Exo_M->solverInfo,
                 &Bilateral_Ankle_Exo_M->derivs);
    rtsiSetContStatesPtr(&Bilateral_Ankle_Exo_M->solverInfo, (real_T **)
                         &Bilateral_Ankle_Exo_M->contStates);
    rtsiSetNumContStatesPtr(&Bilateral_Ankle_Exo_M->solverInfo,
      &Bilateral_Ankle_Exo_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&Bilateral_Ankle_Exo_M->solverInfo,
      &Bilateral_Ankle_Exo_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&Bilateral_Ankle_Exo_M->solverInfo,
      &Bilateral_Ankle_Exo_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&Bilateral_Ankle_Exo_M->solverInfo,
      &Bilateral_Ankle_Exo_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&Bilateral_Ankle_Exo_M->solverInfo,
                          (&rtmGetErrorStatus(Bilateral_Ankle_Exo_M)));
    rtsiSetRTModelPtr(&Bilateral_Ankle_Exo_M->solverInfo, Bilateral_Ankle_Exo_M);
  }

  rtsiSetSimTimeStep(&Bilateral_Ankle_Exo_M->solverInfo, MAJOR_TIME_STEP);
  Bilateral_Ankle_Exo_M->intgData.f[0] = Bilateral_Ankle_Exo_M->odeF[0];
  Bilateral_Ankle_Exo_M->contStates = ((X_Bilateral_Ankle_Exo_T *)
    &Bilateral_Ankle_Exo_X);
  rtsiSetSolverData(&Bilateral_Ankle_Exo_M->solverInfo, (void *)
                    &Bilateral_Ankle_Exo_M->intgData);
  rtsiSetSolverName(&Bilateral_Ankle_Exo_M->solverInfo,"ode1");
  rtmSetTPtr(Bilateral_Ankle_Exo_M, &Bilateral_Ankle_Exo_M->Timing.tArray[0]);
  Bilateral_Ankle_Exo_M->Timing.stepSize0 = 0.0002;

  /* block I/O */
  (void) memset(((void *) &Bilateral_Ankle_Exo_B), 0,
                sizeof(B_Bilateral_Ankle_Exo_T));

  /* states (continuous) */
  {
    (void) memset((void *)&Bilateral_Ankle_Exo_X, 0,
                  sizeof(X_Bilateral_Ankle_Exo_T));
  }

  /* states (dwork) */
  (void) memset((void *)&Bilateral_Ankle_Exo_DW, 0,
                sizeof(DW_Bilateral_Ankle_Exo_T));

  {
    /* user code (registration function declaration) */
    /*Initialize global TRC pointers. */
    Bilateral_Ankle_Exo_rti_init_trc_pointers();
  }

  {
    int32_T i;

    /* Start for RateTransition: '<Root>/RT4' */
    Bilateral_Ankle_Exo_B.RT4[0] = Bilateral_Ankle_Exo_P.RT4_InitialCondition;
    Bilateral_Ankle_Exo_B.RT4[1] = Bilateral_Ankle_Exo_P.RT4_InitialCondition;

    /* Start for RateTransition: '<Root>/RT5' */
    Bilateral_Ankle_Exo_B.RT5[0] = Bilateral_Ankle_Exo_P.RT5_InitialCondition;
    Bilateral_Ankle_Exo_B.RT5[1] = Bilateral_Ankle_Exo_P.RT5_InitialCondition;

    /* Start for RateTransition: '<Root>/RT6' */
    Bilateral_Ankle_Exo_B.RT6[0] = Bilateral_Ankle_Exo_P.RT6_InitialCondition;
    Bilateral_Ankle_Exo_B.RT6[1] = Bilateral_Ankle_Exo_P.RT6_InitialCondition;
    Bilateral_Ankle_Exo_B.RT6[2] = Bilateral_Ankle_Exo_P.RT6_InitialCondition;

    /* Start for RateTransition: '<Root>/RT1' */
    Bilateral_Ankle_Exo_B.RT1[0] = Bilateral_Ankle_Exo_P.RT1_InitialCondition;
    Bilateral_Ankle_Exo_B.RT1[1] = Bilateral_Ankle_Exo_P.RT1_InitialCondition;
    Bilateral_Ankle_Exo_B.RT1[2] = Bilateral_Ankle_Exo_P.RT1_InitialCondition;
    Bilateral_Ankle_Exo_B.RT1[3] = Bilateral_Ankle_Exo_P.RT1_InitialCondition;

    /* Start for RateTransition: '<Root>/RT2' */
    for (i = 0; i < 6; i++) {
      Bilateral_Ankle_Exo_B.RT2[i] = Bilateral_Ankle_Exo_P.RT2_InitialCondition;
    }

    /* End of Start for RateTransition: '<Root>/RT2' */

    /* Start for RateTransition: '<Root>/RT3' */
    Bilateral_Ankle_Exo_B.RT3[0] = Bilateral_Ankle_Exo_P.RT3_InitialCondition;
    Bilateral_Ankle_Exo_B.RT3[1] = Bilateral_Ankle_Exo_P.RT3_InitialCondition;
    Bilateral_Ankle_Exo_B.RT3[2] = Bilateral_Ankle_Exo_P.RT3_InitialCondition;
    Bilateral_Ankle_Exo_B.RT3[3] = Bilateral_Ankle_Exo_P.RT3_InitialCondition;

    /* Start for RateTransition: '<Root>/RT7' */
    Bilateral_Ankle_Exo_B.RT7[0] = Bilateral_Ankle_Exo_P.RT7_InitialCondition;
    Bilateral_Ankle_Exo_B.RT7[1] = Bilateral_Ankle_Exo_P.RT7_InitialCondition;
    Bilateral_Ankle_Exo_B.RT7[2] = Bilateral_Ankle_Exo_P.RT7_InitialCondition;
    Bilateral_Ankle_Exo_B.RT7[3] = Bilateral_Ankle_Exo_P.RT7_InitialCondition;

    /* Start for RateTransition: '<Root>/RT8' */
    Bilateral_Ankle_Exo_B.RT8[0] = Bilateral_Ankle_Exo_P.RT8_InitialCondition;
    Bilateral_Ankle_Exo_B.RT8[1] = Bilateral_Ankle_Exo_P.RT8_InitialCondition;

    /* Start for RateTransition: '<Root>/RT9' */
    Bilateral_Ankle_Exo_B.RT9[0] = Bilateral_Ankle_Exo_P.RT9_InitialCondition;
    Bilateral_Ankle_Exo_B.RT9[1] = Bilateral_Ankle_Exo_P.RT9_InitialCondition;

    /* Start for RateTransition: '<Root>/RT10' */
    Bilateral_Ankle_Exo_B.RT10[0] = Bilateral_Ankle_Exo_P.RT10_InitialCondition;
    Bilateral_Ankle_Exo_B.RT10[1] = Bilateral_Ankle_Exo_P.RT10_InitialCondition;
    Bilateral_Ankle_Exo_B.RT10[2] = Bilateral_Ankle_Exo_P.RT10_InitialCondition;

    /* Start for DataStoreMemory: '<Root>/Data Store Memory' */
    memcpy(&Bilateral_Ankle_Exo_DW.TorqueMem_R[0],
           &Bilateral_Ankle_Exo_P.DataStoreMemory_InitialValue[0], 4400U *
           sizeof(real_T));

    /* Start for DataStoreMemory: '<Root>/Data Store Memory1' */
    memcpy(&Bilateral_Ankle_Exo_DW.ParmReg_R[0],
           &Bilateral_Ankle_Exo_P.DataStoreMemory1_InitialValue[0], 10U * sizeof
           (real_T));

    /* Start for DataStoreMemory: '<Root>/Data Store Memory2' */
    memcpy(&Bilateral_Ankle_Exo_DW.ParmReg_L[0],
           &Bilateral_Ankle_Exo_P.DataStoreMemory2_InitialValue[0], 10U * sizeof
           (real_T));

    /* Start for DataStoreMemory: '<Root>/Data Store Memory3' */
    memcpy(&Bilateral_Ankle_Exo_DW.TorqueMem_L[0],
           &Bilateral_Ankle_Exo_P.DataStoreMemory3_InitialValue[0], 4400U *
           sizeof(real_T));
  }

  {
    int32_T i;

    /* InitializeConditions for DiscreteFilter: '<S33>/0.4low2' */
    Bilateral_Ankle_Exo_DW.u4low2_states[0] =
      Bilateral_Ankle_Exo_P.u4low2_InitialStates;
    Bilateral_Ankle_Exo_DW.u4low2_states[1] =
      Bilateral_Ankle_Exo_P.u4low2_InitialStates;
    Bilateral_Ankle_Exo_DW.u4low2_states[2] =
      Bilateral_Ankle_Exo_P.u4low2_InitialStates;

    /* InitializeConditions for UnitDelay: '<S86>/Unit Delay1' */
    Bilateral_Ankle_Exo_DW.UnitDelay1_DSTATE =
      Bilateral_Ankle_Exo_P.UnitDelay1_InitialCondition;

    /* InitializeConditions for UnitDelay: '<S86>/Unit Delay' */
    Bilateral_Ankle_Exo_DW.UnitDelay_DSTATE =
      Bilateral_Ankle_Exo_P.UnitDelay_InitialCondition;

    /* InitializeConditions for UnitDelay: '<S86>/Unit Delay2' */
    Bilateral_Ankle_Exo_DW.UnitDelay2_DSTATE =
      Bilateral_Ankle_Exo_P.UnitDelay2_InitialCondition;

    /* InitializeConditions for RateTransition: '<Root>/RT4' */
    Bilateral_Ankle_Exo_DW.RT4_Buffer0[0] =
      Bilateral_Ankle_Exo_P.RT4_InitialCondition;
    Bilateral_Ankle_Exo_DW.RT4_Buffer0[1] =
      Bilateral_Ankle_Exo_P.RT4_InitialCondition;
    Bilateral_Ankle_Exo_DW.RT4_write_buf = -1;
    Bilateral_Ankle_Exo_DW.RT4_read_buf = -1;

    /* InitializeConditions for RateTransition: '<Root>/RT5' */
    Bilateral_Ankle_Exo_DW.RT5_Buffer0[0] =
      Bilateral_Ankle_Exo_P.RT5_InitialCondition;
    Bilateral_Ankle_Exo_DW.RT5_Buffer0[1] =
      Bilateral_Ankle_Exo_P.RT5_InitialCondition;
    Bilateral_Ankle_Exo_DW.RT5_write_buf = -1;
    Bilateral_Ankle_Exo_DW.RT5_read_buf = -1;

    /* InitializeConditions for UnitDelay: '<S77>/Unit Delay1' */
    Bilateral_Ankle_Exo_DW.UnitDelay1_DSTATE_n =
      Bilateral_Ankle_Exo_P.UnitDelay1_InitialCondition_e;

    /* InitializeConditions for UnitDelay: '<S77>/Unit Delay' */
    Bilateral_Ankle_Exo_DW.UnitDelay_DSTATE_o =
      Bilateral_Ankle_Exo_P.UnitDelay_InitialCondition_b;

    /* InitializeConditions for UnitDelay: '<S77>/Unit Delay2' */
    Bilateral_Ankle_Exo_DW.UnitDelay2_DSTATE_i =
      Bilateral_Ankle_Exo_P.UnitDelay2_InitialCondition_m;

    /* InitializeConditions for RateTransition: '<Root>/RT6' */
    Bilateral_Ankle_Exo_DW.RT6_Buffer0[0] =
      Bilateral_Ankle_Exo_P.RT6_InitialCondition;
    Bilateral_Ankle_Exo_DW.RT6_Buffer0[1] =
      Bilateral_Ankle_Exo_P.RT6_InitialCondition;
    Bilateral_Ankle_Exo_DW.RT6_Buffer0[2] =
      Bilateral_Ankle_Exo_P.RT6_InitialCondition;
    Bilateral_Ankle_Exo_DW.RT6_write_buf = -1;
    Bilateral_Ankle_Exo_DW.RT6_read_buf = -1;

    /* InitializeConditions for RateTransition: '<Root>/RT1' */
    Bilateral_Ankle_Exo_DW.RT1_Buffer0[0] =
      Bilateral_Ankle_Exo_P.RT1_InitialCondition;
    Bilateral_Ankle_Exo_DW.RT1_Buffer0[1] =
      Bilateral_Ankle_Exo_P.RT1_InitialCondition;
    Bilateral_Ankle_Exo_DW.RT1_Buffer0[2] =
      Bilateral_Ankle_Exo_P.RT1_InitialCondition;
    Bilateral_Ankle_Exo_DW.RT1_Buffer0[3] =
      Bilateral_Ankle_Exo_P.RT1_InitialCondition;
    Bilateral_Ankle_Exo_DW.RT1_write_buf = -1;
    Bilateral_Ankle_Exo_DW.RT1_read_buf = -1;

    /* InitializeConditions for RateTransition: '<Root>/RT2' */
    for (i = 0; i < 6; i++) {
      Bilateral_Ankle_Exo_DW.RT2_Buffer0[i] =
        Bilateral_Ankle_Exo_P.RT2_InitialCondition;
    }

    Bilateral_Ankle_Exo_DW.RT2_write_buf = -1;
    Bilateral_Ankle_Exo_DW.RT2_read_buf = -1;

    /* End of InitializeConditions for RateTransition: '<Root>/RT2' */

    /* InitializeConditions for RateTransition: '<Root>/RT3' */
    Bilateral_Ankle_Exo_DW.RT3_Buffer0[0] =
      Bilateral_Ankle_Exo_P.RT3_InitialCondition;
    Bilateral_Ankle_Exo_DW.RT3_Buffer0[1] =
      Bilateral_Ankle_Exo_P.RT3_InitialCondition;
    Bilateral_Ankle_Exo_DW.RT3_Buffer0[2] =
      Bilateral_Ankle_Exo_P.RT3_InitialCondition;
    Bilateral_Ankle_Exo_DW.RT3_Buffer0[3] =
      Bilateral_Ankle_Exo_P.RT3_InitialCondition;
    Bilateral_Ankle_Exo_DW.RT3_write_buf = -1;
    Bilateral_Ankle_Exo_DW.RT3_read_buf = -1;

    /* InitializeConditions for RateTransition: '<Root>/RT7' */
    Bilateral_Ankle_Exo_DW.RT7_Buffer0[0] =
      Bilateral_Ankle_Exo_P.RT7_InitialCondition;
    Bilateral_Ankle_Exo_DW.RT7_Buffer0[1] =
      Bilateral_Ankle_Exo_P.RT7_InitialCondition;
    Bilateral_Ankle_Exo_DW.RT7_Buffer0[2] =
      Bilateral_Ankle_Exo_P.RT7_InitialCondition;
    Bilateral_Ankle_Exo_DW.RT7_Buffer0[3] =
      Bilateral_Ankle_Exo_P.RT7_InitialCondition;
    Bilateral_Ankle_Exo_DW.RT7_write_buf = -1;
    Bilateral_Ankle_Exo_DW.RT7_read_buf = -1;

    /* InitializeConditions for DiscreteFilter: '<S33>/0.4low1' */
    Bilateral_Ankle_Exo_DW.u4low1_states[0] =
      Bilateral_Ankle_Exo_P.u4low1_InitialStates;
    Bilateral_Ankle_Exo_DW.u4low1_states[1] =
      Bilateral_Ankle_Exo_P.u4low1_InitialStates;
    Bilateral_Ankle_Exo_DW.u4low1_states[2] =
      Bilateral_Ankle_Exo_P.u4low1_InitialStates;

    /* InitializeConditions for UnitDelay: '<S87>/Unit Delay1' */
    Bilateral_Ankle_Exo_DW.UnitDelay1_DSTATE_m =
      Bilateral_Ankle_Exo_P.UnitDelay1_InitialCondition_i;

    /* InitializeConditions for UnitDelay: '<S87>/Unit Delay' */
    Bilateral_Ankle_Exo_DW.UnitDelay_DSTATE_n =
      Bilateral_Ankle_Exo_P.UnitDelay_InitialCondition_a;

    /* InitializeConditions for UnitDelay: '<S87>/Unit Delay2' */
    Bilateral_Ankle_Exo_DW.UnitDelay2_DSTATE_l =
      Bilateral_Ankle_Exo_P.UnitDelay2_InitialCondition_e;

    /* InitializeConditions for RateTransition: '<Root>/RT8' */
    Bilateral_Ankle_Exo_DW.RT8_Buffer0[0] =
      Bilateral_Ankle_Exo_P.RT8_InitialCondition;
    Bilateral_Ankle_Exo_DW.RT8_Buffer0[1] =
      Bilateral_Ankle_Exo_P.RT8_InitialCondition;
    Bilateral_Ankle_Exo_DW.RT8_write_buf = -1;
    Bilateral_Ankle_Exo_DW.RT8_read_buf = -1;

    /* InitializeConditions for RateTransition: '<Root>/RT9' */
    Bilateral_Ankle_Exo_DW.RT9_Buffer0[0] =
      Bilateral_Ankle_Exo_P.RT9_InitialCondition;
    Bilateral_Ankle_Exo_DW.RT9_Buffer0[1] =
      Bilateral_Ankle_Exo_P.RT9_InitialCondition;
    Bilateral_Ankle_Exo_DW.RT9_write_buf = -1;
    Bilateral_Ankle_Exo_DW.RT9_read_buf = -1;

    /* InitializeConditions for UnitDelay: '<S76>/Unit Delay1' */
    Bilateral_Ankle_Exo_DW.UnitDelay1_DSTATE_f =
      Bilateral_Ankle_Exo_P.UnitDelay1_InitialCondition_b;

    /* InitializeConditions for UnitDelay: '<S76>/Unit Delay' */
    Bilateral_Ankle_Exo_DW.UnitDelay_DSTATE_a =
      Bilateral_Ankle_Exo_P.UnitDelay_InitialCondition_c;

    /* InitializeConditions for UnitDelay: '<S76>/Unit Delay2' */
    Bilateral_Ankle_Exo_DW.UnitDelay2_DSTATE_e =
      Bilateral_Ankle_Exo_P.UnitDelay2_InitialCondition_c;

    /* InitializeConditions for RateTransition: '<Root>/RT10' */
    Bilateral_Ankle_Exo_DW.RT10_Buffer0[0] =
      Bilateral_Ankle_Exo_P.RT10_InitialCondition;
    Bilateral_Ankle_Exo_DW.RT10_Buffer0[1] =
      Bilateral_Ankle_Exo_P.RT10_InitialCondition;
    Bilateral_Ankle_Exo_DW.RT10_Buffer0[2] =
      Bilateral_Ankle_Exo_P.RT10_InitialCondition;
    Bilateral_Ankle_Exo_DW.RT10_write_buf = -1;
    Bilateral_Ankle_Exo_DW.RT10_read_buf = -1;

    /* InitializeConditions for StateSpace: '<S49>/low_pass' */
    Bilateral_Ankle_Exo_X.low_pass_CSTATE[0] =
      Bilateral_Ankle_Exo_P.low_pass_InitialCondition;

    /* InitializeConditions for StateSpace: '<S50>/low_pass' */
    Bilateral_Ankle_Exo_X.low_pass_CSTATE_b[0] =
      Bilateral_Ankle_Exo_P.low_pass_InitialCondition_i;

    /* InitializeConditions for StateSpace: '<S51>/low_pass' */
    Bilateral_Ankle_Exo_X.low_pass_CSTATE_m[0] =
      Bilateral_Ankle_Exo_P.low_pass_InitialCondition_n;

    /* InitializeConditions for StateSpace: '<S52>/low_pass' */
    Bilateral_Ankle_Exo_X.low_pass_CSTATE_d[0] =
      Bilateral_Ankle_Exo_P.low_pass_InitialCondition_o;

    /* InitializeConditions for StateSpace: '<S54>/low_pass' */
    Bilateral_Ankle_Exo_X.low_pass_CSTATE_j[0] =
      Bilateral_Ankle_Exo_P.low_pass_InitialCondition_ir;

    /* InitializeConditions for StateSpace: '<S53>/low_pass' */
    Bilateral_Ankle_Exo_X.low_pass_CSTATE_a[0] =
      Bilateral_Ankle_Exo_P.low_pass_InitialCondition_h;

    /* InitializeConditions for StateSpace: '<S49>/high_pass' */
    Bilateral_Ankle_Exo_X.high_pass_CSTATE[0] =
      Bilateral_Ankle_Exo_P.high_pass_InitialCondition;

    /* InitializeConditions for StateSpace: '<S50>/high_pass' */
    Bilateral_Ankle_Exo_X.high_pass_CSTATE_p[0] =
      Bilateral_Ankle_Exo_P.high_pass_InitialCondition_a;

    /* InitializeConditions for StateSpace: '<S51>/high_pass' */
    Bilateral_Ankle_Exo_X.high_pass_CSTATE_f[0] =
      Bilateral_Ankle_Exo_P.high_pass_InitialCondition_d;

    /* InitializeConditions for StateSpace: '<S52>/high_pass' */
    Bilateral_Ankle_Exo_X.high_pass_CSTATE_a[0] =
      Bilateral_Ankle_Exo_P.high_pass_InitialCondition_m;

    /* InitializeConditions for StateSpace: '<S53>/high_pass' */
    Bilateral_Ankle_Exo_X.high_pass_CSTATE_o[0] =
      Bilateral_Ankle_Exo_P.high_pass_InitialCondition_h;

    /* InitializeConditions for StateSpace: '<S54>/high_pass' */
    Bilateral_Ankle_Exo_X.high_pass_CSTATE_ff[0] =
      Bilateral_Ankle_Exo_P.high_pass_InitialCondition_e;

    /* InitializeConditions for StateSpace: '<S49>/low_pass' */
    Bilateral_Ankle_Exo_X.low_pass_CSTATE[1] =
      Bilateral_Ankle_Exo_P.low_pass_InitialCondition;

    /* InitializeConditions for StateSpace: '<S50>/low_pass' */
    Bilateral_Ankle_Exo_X.low_pass_CSTATE_b[1] =
      Bilateral_Ankle_Exo_P.low_pass_InitialCondition_i;

    /* InitializeConditions for StateSpace: '<S51>/low_pass' */
    Bilateral_Ankle_Exo_X.low_pass_CSTATE_m[1] =
      Bilateral_Ankle_Exo_P.low_pass_InitialCondition_n;

    /* InitializeConditions for StateSpace: '<S52>/low_pass' */
    Bilateral_Ankle_Exo_X.low_pass_CSTATE_d[1] =
      Bilateral_Ankle_Exo_P.low_pass_InitialCondition_o;

    /* InitializeConditions for StateSpace: '<S54>/low_pass' */
    Bilateral_Ankle_Exo_X.low_pass_CSTATE_j[1] =
      Bilateral_Ankle_Exo_P.low_pass_InitialCondition_ir;

    /* InitializeConditions for StateSpace: '<S53>/low_pass' */
    Bilateral_Ankle_Exo_X.low_pass_CSTATE_a[1] =
      Bilateral_Ankle_Exo_P.low_pass_InitialCondition_h;

    /* InitializeConditions for StateSpace: '<S49>/high_pass' */
    Bilateral_Ankle_Exo_X.high_pass_CSTATE[1] =
      Bilateral_Ankle_Exo_P.high_pass_InitialCondition;

    /* InitializeConditions for StateSpace: '<S50>/high_pass' */
    Bilateral_Ankle_Exo_X.high_pass_CSTATE_p[1] =
      Bilateral_Ankle_Exo_P.high_pass_InitialCondition_a;

    /* InitializeConditions for StateSpace: '<S51>/high_pass' */
    Bilateral_Ankle_Exo_X.high_pass_CSTATE_f[1] =
      Bilateral_Ankle_Exo_P.high_pass_InitialCondition_d;

    /* InitializeConditions for StateSpace: '<S52>/high_pass' */
    Bilateral_Ankle_Exo_X.high_pass_CSTATE_a[1] =
      Bilateral_Ankle_Exo_P.high_pass_InitialCondition_m;

    /* InitializeConditions for StateSpace: '<S53>/high_pass' */
    Bilateral_Ankle_Exo_X.high_pass_CSTATE_o[1] =
      Bilateral_Ankle_Exo_P.high_pass_InitialCondition_h;

    /* InitializeConditions for StateSpace: '<S54>/high_pass' */
    Bilateral_Ankle_Exo_X.high_pass_CSTATE_ff[1] =
      Bilateral_Ankle_Exo_P.high_pass_InitialCondition_e;

    /* SystemInitialize for MATLAB Function: '<S30>/Filter_R' */
    Bilateral_Ankle_E_Filter_L_Init(&Bilateral_Ankle_Exo_DW.sf_Filter_R);

    /* SystemInitialize for MATLAB Function: '<S7>/State Machine' */
    Bilateral_Ankle_Exo_DW.reg_stride_time = 1.0;
    Bilateral_Ankle_Exo_DW.reg_stride_time_count = 0.0;
    Bilateral_Ankle_Exo_DW.reg_mode = 1.0;
    Bilateral_Ankle_Exo_DW.reg_state = 1.0;
    Bilateral_Ankle_Exo_DW.bt_run = 0.0;
    Bilateral_Ankle_Exo_DW.reg_last_switch = 1.0;

    /* SystemInitialize for MATLAB Function: '<S30>/Filter_L' */
    Bilateral_Ankle_E_Filter_L_Init(&Bilateral_Ankle_Exo_DW.sf_Filter_L);

    /* SystemInitialize for MATLAB Function: '<S6>/State Machine' */
    Bilateral_Ankle_Exo_DW.reg_stride_time_e = 1.0;
    Bilateral_Ankle_Exo_DW.reg_stride_time_count_a = 0.0;
    Bilateral_Ankle_Exo_DW.reg_mode_d = 1.0;
    Bilateral_Ankle_Exo_DW.reg_state_p = 1.0;
    Bilateral_Ankle_Exo_DW.bt_run_c = 0.0;
    Bilateral_Ankle_Exo_DW.reg_last_switch_p = 1.0;

    /* SystemInitialize for S-Function (rti_commonblock): '<S8>/S-Function1' incorporates:
     *  SubSystem: '<Root>/Control Module'
     */
    Bilateral_An_ControlModule_Init();

    /* End of SystemInitialize for S-Function (rti_commonblock): '<S8>/S-Function1' */

    /* SystemInitialize for MATLAB Function: '<S33>/MATLAB Function' */
    for (i = 0; i < 15; i++) {
      Bilateral_Ankle_Exo_DW.data[i] = 1.0;
    }

    /* End of SystemInitialize for MATLAB Function: '<S33>/MATLAB Function' */
  }
}

/* Model terminate function */
void Bilateral_Ankle_Exo_terminate(void)
{
  /* Terminate for S-Function (rti_commonblock): '<S36>/S-Function1' */

  /* --- Bilateral_Ankle_Exo/Sensor Data/Ankle Encoder/EMC_ENCODER_BL1 --- */
  /* --- [RTIEMC, Encoder] - DIO class: 2 - Unit: 5 - Port: 1 - Channel: 10 --- */
  {
    /* Deactivates encoder interface functionality */
    DioCl2EncoderIn_stop(pRTIEmcEncoder_Unit_5_DioCl_2_Port_1_Ch10);
  }

  /* Terminate for S-Function (rti_commonblock): '<S80>/S-Function1' */

  /* --- Bilateral_Ankle_Exo/Sensor Data/Motor Encoder/EMC_ENCODER_BL2 --- */
  /* --- [RTIEMC, Encoder] - DIO class: 2 - Unit: 2 - Port: 1 - Channel: 3 --- */
  {
    /* Deactivates encoder interface functionality */
    DioCl2EncoderIn_stop(pRTIEmcEncoder_Unit_2_DioCl_2_Port_1_Ch3);
  }

  /* Terminate for S-Function (rti_commonblock): '<S37>/S-Function1' */

  /* --- Bilateral_Ankle_Exo/Sensor Data/Ankle Encoder/EMC_ENCODER_BL2 --- */
  /* --- [RTIEMC, Encoder] - DIO class: 2 - Unit: 4 - Port: 1 - Channel: 7 --- */
  {
    /* Deactivates encoder interface functionality */
    DioCl2EncoderIn_stop(pRTIEmcEncoder_Unit_4_DioCl_2_Port_1_Ch7);
  }

  /* Terminate for S-Function (rti_commonblock): '<S81>/S-Function1' */

  /* --- Bilateral_Ankle_Exo/Sensor Data/Motor Encoder/EMC_ENCODER_BL3 --- */
  /* --- [RTIEMC, Encoder] - DIO class: 2 - Unit: 3 - Port: 1 - Channel: 5 --- */
  {
    /* Deactivates encoder interface functionality */
    DioCl2EncoderIn_stop(pRTIEmcEncoder_Unit_3_DioCl_2_Port_1_Ch5);
  }

  /* Terminate for S-Function (rti_commonblock): '<S8>/S-Function1' incorporates:
   *  SubSystem: '<Root>/Control Module'
   */
  Bilateral_An_ControlModule_Term();

  /* End of Terminate for S-Function (rti_commonblock): '<S8>/S-Function1' */

  /* Terminate for S-Function (rti_commonblock): '<S38>/S-Function1' incorporates:
   *  Constant: '<S28>/VCC1'
   */

  /* --- Bilateral_Ankle_Exo/Sensor Data/Ankle Encoder/Encoder Power Setup1 --- */
  /* --- [RTI120X, BITOUT] - Port: 3 - Channel: 15 --- */

  /* disable digital output channel 15-15 on port 3 *
   * (set to high-impedance), when the simulation terminates       */
  DioCl1DigOut_setChMaskOutHighZ(pRTIDioC1DigOut_Port_3_Ch_15,
    DIO_CLASS1_HIGH_Z_ON);
  DioCl1DigOut_write(pRTIDioC1DigOut_Port_3_Ch_15);

  /* Terminate for S-Function (rti_commonblock): '<S39>/S-Function1' incorporates:
   *  Constant: '<S28>/VCC2'
   */

  /* --- Bilateral_Ankle_Exo/Sensor Data/Ankle Encoder/Encoder Power Setup2 --- */
  /* --- [RTI120X, BITOUT] - Port: 3 - Channel: 16 --- */

  /* disable digital output channel 16-16 on port 3 *
   * (set to high-impedance), when the simulation terminates       */
  DioCl1DigOut_setChMaskOutHighZ(pRTIDioC1DigOut_Port_3_Ch_16,
    DIO_CLASS1_HIGH_Z_ON);
  DioCl1DigOut_write(pRTIDioC1DigOut_Port_3_Ch_16);

  /* Terminate for S-Function (rti_commonblock): '<S82>/S-Function1' incorporates:
   *  Constant: '<S32>/VCC2'
   */

  /* --- Bilateral_Ankle_Exo/Sensor Data/Motor Encoder/Encoder Power Setup2 --- */
  /* --- [RTI120X, BITOUT] - Port: 3 - Channel: 12 --- */

  /* disable digital output channel 12-12 on port 3 *
   * (set to high-impedance), when the simulation terminates       */
  DioCl1DigOut_setChMaskOutHighZ(pRTIDioC1DigOut_Port_3_Ch_12,
    DIO_CLASS1_HIGH_Z_ON);
  DioCl1DigOut_write(pRTIDioC1DigOut_Port_3_Ch_12);

  /* Terminate for S-Function (rti_commonblock): '<S83>/S-Function1' incorporates:
   *  Constant: '<S32>/VCC3'
   */

  /* --- Bilateral_Ankle_Exo/Sensor Data/Motor Encoder/Encoder Power Setup3 --- */
  /* --- [RTI120X, BITOUT] - Port: 3 - Channel: 13 --- */

  /* disable digital output channel 13-13 on port 3 *
   * (set to high-impedance), when the simulation terminates       */
  DioCl1DigOut_setChMaskOutHighZ(pRTIDioC1DigOut_Port_3_Ch_13,
    DIO_CLASS1_HIGH_Z_ON);
  DioCl1DigOut_write(pRTIDioC1DigOut_Port_3_Ch_13);

  /* Terminate for S-Function (rti_commonblock): '<S62>/S-Function1' incorporates:
   *  Constant: '<S30>/Constant'
   */

  /* --- Bilateral_Ankle_Exo/Sensor Data/FootSwitch module/DIO_CLASS1_BIT_OUT_BL1 --- */
  /* --- [RTI120X, BITOUT] - Port: 1 - Channel: 1 --- */

  /* disable digital output channel 1-1 on port 1 *
   * (set to high-impedance), when the simulation terminates       */
  DioCl1DigOut_setChMaskOutHighZ(pRTIDioC1DigOut_Port_1_Ch_1,
    DIO_CLASS1_HIGH_Z_ON);
  DioCl1DigOut_write(pRTIDioC1DigOut_Port_1_Ch_1);

  /* Terminate for S-Function (rti_commonblock): '<S63>/S-Function1' incorporates:
   *  Constant: '<S30>/Constant1'
   */

  /* --- Bilateral_Ankle_Exo/Sensor Data/FootSwitch module/DIO_CLASS1_BIT_OUT_BL2 --- */
  /* --- [RTI120X, BITOUT] - Port: 1 - Channel: 3 --- */

  /* disable digital output channel 3-3 on port 1 *
   * (set to high-impedance), when the simulation terminates       */
  DioCl1DigOut_setChMaskOutHighZ(pRTIDioC1DigOut_Port_1_Ch_3,
    DIO_CLASS1_HIGH_Z_ON);
  DioCl1DigOut_write(pRTIDioC1DigOut_Port_1_Ch_3);

  /* Terminate for S-Function (rti_commonblock): '<S72>/S-Function1' */

  /* dSPACE RTICAN RX Message Block: "RX Message" Id:3 */
  {
    /* ... Set the message into sleep mode */
    while ((rtican_type1_tq_error[0][0] = can_tp1_msg_sleep
            (can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X3])) ==
           DSMCOM_BUFFER_OVERFLOW) ;
  }

  /* Terminate for S-Function (rti_commonblock): '<S66>/S-Function1' */

  /* dSPACE RTICAN STD Srvc-Message Block */
  {
    /* ... Set the message into sleep mode */
    while ((rtican_type1_tq_error[0][0] = can_tp1_msg_sleep
            (CANTP1_RX_SPMSG_M1_C1_STD)) == DSMCOM_BUFFER_OVERFLOW) ;
  }

  /* Terminate for S-Function (rti_commonblock): '<S67>/S-Function1' */

  /* dSPACE RTICAN STD Srvc-Message Block */
  {
    /* ... Set the message into sleep mode */
    while ((rtican_type1_tq_error[0][0] = can_tp1_msg_sleep
            (CANTP1_RX_SPMSG_M1_C2_STD)) == DSMCOM_BUFFER_OVERFLOW) ;
  }

  /* Terminate for S-Function (rti_commonblock): '<S70>/S-Function1' */

  /* dSPACE RTICAN RX Message Block: "RX Message" Id:100 */
  {
    /* ... Set the message into sleep mode */
    while ((rtican_type1_tq_error[0][1] = can_tp1_msg_sleep
            (can_type1_msg_M1[CANTP1_M1_C1_RX_STD_0X64])) ==
           DSMCOM_BUFFER_OVERFLOW) ;
  }

  /* Terminate for S-Function (rti_commonblock): '<S71>/S-Function1' */

  /* dSPACE RTICAN TX Message Block: "TX Message" Id:100 */
  {
    /* ... Set the message into sleep mode */
    while ((rtican_type1_tq_error[0][1] = can_tp1_msg_sleep
            (can_type1_msg_M1[CANTP1_M1_C2_TX_STD_0X64])) ==
           DSMCOM_BUFFER_OVERFLOW) ;
  }
}
