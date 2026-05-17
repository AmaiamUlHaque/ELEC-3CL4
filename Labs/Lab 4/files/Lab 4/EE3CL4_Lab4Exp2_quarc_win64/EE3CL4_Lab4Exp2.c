/*
 * EE3CL4_Lab4Exp2.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "EE3CL4_Lab4Exp2".
 *
 * Model version              : 11.10
 * Simulink Coder version : 23.2 (R2023b) 01-Aug-2023
 * C source code generated on : Thu Mar 19 16:12:19 2026
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "EE3CL4_Lab4Exp2.h"
#include "rtwtypes.h"
#include "EE3CL4_Lab4Exp2_private.h"
#include <string.h>
#include "rt_nonfinite.h"
#include "EE3CL4_Lab4Exp2_dt.h"

/* Block signals (default storage) */
B_EE3CL4_Lab4Exp2_T EE3CL4_Lab4Exp2_B;

/* Continuous states */
X_EE3CL4_Lab4Exp2_T EE3CL4_Lab4Exp2_X;

/* Disabled State Vector */
XDis_EE3CL4_Lab4Exp2_T EE3CL4_Lab4Exp2_XDis;

/* Block states (default storage) */
DW_EE3CL4_Lab4Exp2_T EE3CL4_Lab4Exp2_DW;

/* Real-time model */
static RT_MODEL_EE3CL4_Lab4Exp2_T EE3CL4_Lab4Exp2_M_;
RT_MODEL_EE3CL4_Lab4Exp2_T *const EE3CL4_Lab4Exp2_M = &EE3CL4_Lab4Exp2_M_;

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
  int_T nXc = 1;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  EE3CL4_Lab4Exp2_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; ++i) {
    x[i] += h * f0[i];
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function */
void EE3CL4_Lab4Exp2_output(void)
{
  real_T rtb_HILReadEncoder;
  if (rtmIsMajorTimeStep(EE3CL4_Lab4Exp2_M)) {
    /* set solver stop time */
    if (!(EE3CL4_Lab4Exp2_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&EE3CL4_Lab4Exp2_M->solverInfo,
                            ((EE3CL4_Lab4Exp2_M->Timing.clockTickH0 + 1) *
        EE3CL4_Lab4Exp2_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&EE3CL4_Lab4Exp2_M->solverInfo,
                            ((EE3CL4_Lab4Exp2_M->Timing.clockTick0 + 1) *
        EE3CL4_Lab4Exp2_M->Timing.stepSize0 +
        EE3CL4_Lab4Exp2_M->Timing.clockTickH0 *
        EE3CL4_Lab4Exp2_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(EE3CL4_Lab4Exp2_M)) {
    EE3CL4_Lab4Exp2_M->Timing.t[0] = rtsiGetT(&EE3CL4_Lab4Exp2_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(EE3CL4_Lab4Exp2_M)) {
    /* S-Function (smooth_signal_generator_block): '<Root>/desired pos' */
    /* S-Function Block: EE3CL4_Lab4Exp2/desired pos (smooth_signal_generator_block) */
    {
      real_T w = TWO_PI * EE3CL4_Lab4Exp2_P.desiredpos_Frequency;
      boolean_T params_changed = (EE3CL4_Lab4Exp2_P.desiredpos_Amplitude !=
        EE3CL4_Lab4Exp2_DW.desiredpos_RWORK.Amp || w !=
        EE3CL4_Lab4Exp2_DW.desiredpos_RWORK.W);
      real_T T = TWO_PI / EE3CL4_Lab4Exp2_DW.desiredpos_RWORK.W;
      boolean_T first_half;
      if (EE3CL4_Lab4Exp2_DW.desiredpos_RWORK.T < 0.5 * T) {
        EE3CL4_Lab4Exp2_B.desiredpos = EE3CL4_Lab4Exp2_DW.desiredpos_RWORK.Amp *
          (4 * EE3CL4_Lab4Exp2_DW.desiredpos_RWORK.T - T) / T;
        first_half = true;
      } else {
        EE3CL4_Lab4Exp2_B.desiredpos = EE3CL4_Lab4Exp2_DW.desiredpos_RWORK.Amp *
          (3 * T - 4 * EE3CL4_Lab4Exp2_DW.desiredpos_RWORK.T) / T;
        first_half = false;
      }

      /*
         If the amplitude or frequency parameter changes, then adjust the
         sawtooth parameters such that the sawtooth output is continuous.
       */
      if (params_changed) {
        /*
           Change the amplitude or frequency when the sign of the output
           changes. This technique ensures that the amplitude and frequency
           can be changed continuously via external inputs without getting
           heavily distorted waveforms.
         */
        /* If the sign of the output changes, then change the amplitude to zero. */
        if (EE3CL4_Lab4Exp2_B.desiredpos == 0 ||
            EE3CL4_Lab4Exp2_DW.desiredpos_RWORK.Y == 0 ||
            (EE3CL4_Lab4Exp2_B.desiredpos < 0) !=
            (EE3CL4_Lab4Exp2_DW.desiredpos_RWORK.Y < 0)) {
          T = TWO_PI / w;
          if (fabs(EE3CL4_Lab4Exp2_B.desiredpos) <
              EE3CL4_Lab4Exp2_P.desiredpos_Amplitude) {
            if (first_half) {
              EE3CL4_Lab4Exp2_DW.desiredpos_RWORK.T = T *
                (EE3CL4_Lab4Exp2_P.desiredpos_Amplitude +
                 EE3CL4_Lab4Exp2_B.desiredpos) / (4 *
                EE3CL4_Lab4Exp2_P.desiredpos_Amplitude);
            } else {
              EE3CL4_Lab4Exp2_DW.desiredpos_RWORK.T = T * (3 *
                EE3CL4_Lab4Exp2_P.desiredpos_Amplitude -
                EE3CL4_Lab4Exp2_B.desiredpos) / (4 *
                EE3CL4_Lab4Exp2_P.desiredpos_Amplitude);
            }
          } else {
            /* really low amplitudes where sawtooth wave goes further in one time step after crossing zero than the new amplitude */
            EE3CL4_Lab4Exp2_B.desiredpos = 0.0;
          }

          EE3CL4_Lab4Exp2_DW.desiredpos_RWORK.Amp =
            EE3CL4_Lab4Exp2_P.desiredpos_Amplitude;
          EE3CL4_Lab4Exp2_DW.desiredpos_RWORK.W = w;
        }
      }

      EE3CL4_Lab4Exp2_DW.desiredpos_RWORK.T += 0.002;
      if (EE3CL4_Lab4Exp2_DW.desiredpos_RWORK.T >= T) {
        EE3CL4_Lab4Exp2_DW.desiredpos_RWORK.T = 0;
      }

      EE3CL4_Lab4Exp2_DW.desiredpos_RWORK.Y = EE3CL4_Lab4Exp2_B.desiredpos;
    }

    /* S-Function (hil_read_encoder_block): '<Root>/HIL Read Encoder' */

    /* S-Function Block: EE3CL4_Lab4Exp2/HIL Read Encoder (hil_read_encoder_block) */
    {
      t_error result = hil_read_encoder(EE3CL4_Lab4Exp2_DW.HILInitialize_Card,
        &EE3CL4_Lab4Exp2_P.HILReadEncoder_channels, 1,
        &EE3CL4_Lab4Exp2_DW.HILReadEncoder_Buffer);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(EE3CL4_Lab4Exp2_M, _rt_error_message);
      } else {
        rtb_HILReadEncoder = EE3CL4_Lab4Exp2_DW.HILReadEncoder_Buffer;
      }
    }

    /* Gain: '<Root>/Gain' */
    EE3CL4_Lab4Exp2_B.Gain = EE3CL4_Lab4Exp2_P.Gain_Gain * rtb_HILReadEncoder;

    /* Sum: '<Root>/Sum' */
    EE3CL4_Lab4Exp2_B.Sum = EE3CL4_Lab4Exp2_B.desiredpos -
      EE3CL4_Lab4Exp2_B.Gain;
  }

  /* TransferFcn: '<Root>/Transfer Fcn' */
  EE3CL4_Lab4Exp2_B.TransferFcn = 0.0;
  EE3CL4_Lab4Exp2_B.TransferFcn += EE3CL4_Lab4Exp2_P.TransferFcn_C *
    EE3CL4_Lab4Exp2_X.TransferFcn_CSTATE;
  EE3CL4_Lab4Exp2_B.TransferFcn += EE3CL4_Lab4Exp2_P.TransferFcn_D *
    EE3CL4_Lab4Exp2_B.Sum;
  if (rtmIsMajorTimeStep(EE3CL4_Lab4Exp2_M)) {
    /* S-Function (hil_write_analog_block): '<Root>/HIL Write Analog' */

    /* S-Function Block: EE3CL4_Lab4Exp2/HIL Write Analog (hil_write_analog_block) */
    {
      t_error result;
      result = hil_write_analog(EE3CL4_Lab4Exp2_DW.HILInitialize_Card,
        &EE3CL4_Lab4Exp2_P.HILWriteAnalog_channels, 1,
        &EE3CL4_Lab4Exp2_B.TransferFcn);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(EE3CL4_Lab4Exp2_M, _rt_error_message);
      }
    }
  }
}

/* Model update function */
void EE3CL4_Lab4Exp2_update(void)
{
  if (rtmIsMajorTimeStep(EE3CL4_Lab4Exp2_M)) {
    rt_ertODEUpdateContinuousStates(&EE3CL4_Lab4Exp2_M->solverInfo);
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
  if (!(++EE3CL4_Lab4Exp2_M->Timing.clockTick0)) {
    ++EE3CL4_Lab4Exp2_M->Timing.clockTickH0;
  }

  EE3CL4_Lab4Exp2_M->Timing.t[0] = rtsiGetSolverStopTime
    (&EE3CL4_Lab4Exp2_M->solverInfo);

  {
    /* Update absolute timer for sample time: [0.002s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++EE3CL4_Lab4Exp2_M->Timing.clockTick1)) {
      ++EE3CL4_Lab4Exp2_M->Timing.clockTickH1;
    }

    EE3CL4_Lab4Exp2_M->Timing.t[1] = EE3CL4_Lab4Exp2_M->Timing.clockTick1 *
      EE3CL4_Lab4Exp2_M->Timing.stepSize1 +
      EE3CL4_Lab4Exp2_M->Timing.clockTickH1 *
      EE3CL4_Lab4Exp2_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void EE3CL4_Lab4Exp2_derivatives(void)
{
  XDot_EE3CL4_Lab4Exp2_T *_rtXdot;
  _rtXdot = ((XDot_EE3CL4_Lab4Exp2_T *) EE3CL4_Lab4Exp2_M->derivs);

  /* Derivatives for TransferFcn: '<Root>/Transfer Fcn' */
  _rtXdot->TransferFcn_CSTATE = EE3CL4_Lab4Exp2_P.TransferFcn_A *
    EE3CL4_Lab4Exp2_X.TransferFcn_CSTATE;
  _rtXdot->TransferFcn_CSTATE += EE3CL4_Lab4Exp2_B.Sum;
}

/* Model initialize function */
void EE3CL4_Lab4Exp2_initialize(void)
{
  /* Start for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: EE3CL4_Lab4Exp2/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("qube_servo3_usb", "0",
                      &EE3CL4_Lab4Exp2_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(EE3CL4_Lab4Exp2_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options(EE3CL4_Lab4Exp2_DW.HILInitialize_Card,
      "deadband_compensation=0.65;pwm_en=0;enc0_velocity=3.0;enc1_velocity=3.0;",
      73);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(EE3CL4_Lab4Exp2_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(EE3CL4_Lab4Exp2_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(EE3CL4_Lab4Exp2_M, _rt_error_message);
      return;
    }

    if ((EE3CL4_Lab4Exp2_P.HILInitialize_AIPStart && !is_switching) ||
        (EE3CL4_Lab4Exp2_P.HILInitialize_AIPEnter && is_switching)) {
      result = hil_set_analog_input_ranges(EE3CL4_Lab4Exp2_DW.HILInitialize_Card,
        &EE3CL4_Lab4Exp2_P.HILInitialize_AIChannels, 1U,
        &EE3CL4_Lab4Exp2_P.HILInitialize_AILow,
        &EE3CL4_Lab4Exp2_P.HILInitialize_AIHigh);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(EE3CL4_Lab4Exp2_M, _rt_error_message);
        return;
      }
    }

    if ((EE3CL4_Lab4Exp2_P.HILInitialize_AOPStart && !is_switching) ||
        (EE3CL4_Lab4Exp2_P.HILInitialize_AOPEnter && is_switching)) {
      result = hil_set_analog_output_ranges
        (EE3CL4_Lab4Exp2_DW.HILInitialize_Card,
         &EE3CL4_Lab4Exp2_P.HILInitialize_AOChannels, 1U,
         &EE3CL4_Lab4Exp2_P.HILInitialize_AOLow,
         &EE3CL4_Lab4Exp2_P.HILInitialize_AOHigh);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(EE3CL4_Lab4Exp2_M, _rt_error_message);
        return;
      }
    }

    if ((EE3CL4_Lab4Exp2_P.HILInitialize_AOStart && !is_switching) ||
        (EE3CL4_Lab4Exp2_P.HILInitialize_AOEnter && is_switching)) {
      result = hil_write_analog(EE3CL4_Lab4Exp2_DW.HILInitialize_Card,
        &EE3CL4_Lab4Exp2_P.HILInitialize_AOChannels, 1U,
        &EE3CL4_Lab4Exp2_P.HILInitialize_AOInitial);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(EE3CL4_Lab4Exp2_M, _rt_error_message);
        return;
      }
    }

    if (EE3CL4_Lab4Exp2_P.HILInitialize_AOReset) {
      result = hil_watchdog_set_analog_expiration_state
        (EE3CL4_Lab4Exp2_DW.HILInitialize_Card,
         &EE3CL4_Lab4Exp2_P.HILInitialize_AOChannels, 1U,
         &EE3CL4_Lab4Exp2_P.HILInitialize_AOWatchdog);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(EE3CL4_Lab4Exp2_M, _rt_error_message);
        return;
      }
    }

    result = hil_set_digital_directions(EE3CL4_Lab4Exp2_DW.HILInitialize_Card,
      NULL, 0U, &EE3CL4_Lab4Exp2_P.HILInitialize_DOChannels, 1U);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(EE3CL4_Lab4Exp2_M, _rt_error_message);
      return;
    }

    if ((EE3CL4_Lab4Exp2_P.HILInitialize_DOStart && !is_switching) ||
        (EE3CL4_Lab4Exp2_P.HILInitialize_DOEnter && is_switching)) {
      result = hil_write_digital(EE3CL4_Lab4Exp2_DW.HILInitialize_Card,
        &EE3CL4_Lab4Exp2_P.HILInitialize_DOChannels, 1U, (t_boolean *)
        &EE3CL4_Lab4Exp2_P.HILInitialize_DOInitial);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(EE3CL4_Lab4Exp2_M, _rt_error_message);
        return;
      }
    }

    if (EE3CL4_Lab4Exp2_P.HILInitialize_DOReset) {
      result = hil_watchdog_set_digital_expiration_state
        (EE3CL4_Lab4Exp2_DW.HILInitialize_Card,
         &EE3CL4_Lab4Exp2_P.HILInitialize_DOChannels, 1U, (const t_digital_state
          *) &EE3CL4_Lab4Exp2_P.HILInitialize_DOWatchdog);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(EE3CL4_Lab4Exp2_M, _rt_error_message);
        return;
      }
    }

    if ((EE3CL4_Lab4Exp2_P.HILInitialize_EIPStart && !is_switching) ||
        (EE3CL4_Lab4Exp2_P.HILInitialize_EIPEnter && is_switching)) {
      EE3CL4_Lab4Exp2_DW.HILInitialize_QuadratureModes[0] =
        EE3CL4_Lab4Exp2_P.HILInitialize_EIQuadrature;
      EE3CL4_Lab4Exp2_DW.HILInitialize_QuadratureModes[1] =
        EE3CL4_Lab4Exp2_P.HILInitialize_EIQuadrature;
      result = hil_set_encoder_quadrature_mode
        (EE3CL4_Lab4Exp2_DW.HILInitialize_Card,
         EE3CL4_Lab4Exp2_P.HILInitialize_EIChannels, 2U,
         (t_encoder_quadrature_mode *)
         &EE3CL4_Lab4Exp2_DW.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(EE3CL4_Lab4Exp2_M, _rt_error_message);
        return;
      }
    }

    if ((EE3CL4_Lab4Exp2_P.HILInitialize_EIStart && !is_switching) ||
        (EE3CL4_Lab4Exp2_P.HILInitialize_EIEnter && is_switching)) {
      EE3CL4_Lab4Exp2_DW.HILInitialize_InitialEICounts[0] =
        EE3CL4_Lab4Exp2_P.HILInitialize_EIInitial;
      EE3CL4_Lab4Exp2_DW.HILInitialize_InitialEICounts[1] =
        EE3CL4_Lab4Exp2_P.HILInitialize_EIInitial;
      result = hil_set_encoder_counts(EE3CL4_Lab4Exp2_DW.HILInitialize_Card,
        EE3CL4_Lab4Exp2_P.HILInitialize_EIChannels, 2U,
        &EE3CL4_Lab4Exp2_DW.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(EE3CL4_Lab4Exp2_M, _rt_error_message);
        return;
      }
    }

    if ((EE3CL4_Lab4Exp2_P.HILInitialize_OOStart && !is_switching) ||
        (EE3CL4_Lab4Exp2_P.HILInitialize_OOEnter && is_switching)) {
      result = hil_write_other(EE3CL4_Lab4Exp2_DW.HILInitialize_Card,
        EE3CL4_Lab4Exp2_P.HILInitialize_OOChannels, 3U,
        EE3CL4_Lab4Exp2_P.HILInitialize_OOInitial);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(EE3CL4_Lab4Exp2_M, _rt_error_message);
        return;
      }
    }

    if (EE3CL4_Lab4Exp2_P.HILInitialize_OOReset) {
      result = hil_watchdog_set_other_expiration_state
        (EE3CL4_Lab4Exp2_DW.HILInitialize_Card,
         EE3CL4_Lab4Exp2_P.HILInitialize_OOChannels, 3U,
         EE3CL4_Lab4Exp2_P.HILInitialize_OOWatchdog);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(EE3CL4_Lab4Exp2_M, _rt_error_message);
        return;
      }
    }
  }

  /* Start for S-Function (smooth_signal_generator_block): '<Root>/desired pos' */

  /* S-Function Block: EE3CL4_Lab4Exp2/desired pos (smooth_signal_generator_block) */
  {
    real_T T = 1.0 / EE3CL4_Lab4Exp2_P.desiredpos_Frequency;
    EE3CL4_Lab4Exp2_DW.desiredpos_RWORK.Amp =
      EE3CL4_Lab4Exp2_P.desiredpos_Amplitude;
    EE3CL4_Lab4Exp2_DW.desiredpos_RWORK.W = TWO_PI *
      EE3CL4_Lab4Exp2_P.desiredpos_Frequency;
    EE3CL4_Lab4Exp2_DW.desiredpos_RWORK.T = fmod
      (EE3CL4_Lab4Exp2_P.desiredpos_InitialPhase, TWO_PI) * T / TWO_PI;
    if (EE3CL4_Lab4Exp2_DW.desiredpos_RWORK.T < 0) {
      EE3CL4_Lab4Exp2_DW.desiredpos_RWORK.T += T;
    }

    if (EE3CL4_Lab4Exp2_DW.desiredpos_RWORK.T < 0.5 * T) {
      EE3CL4_Lab4Exp2_DW.desiredpos_RWORK.Y =
        EE3CL4_Lab4Exp2_P.desiredpos_Amplitude * (4 *
        EE3CL4_Lab4Exp2_DW.desiredpos_RWORK.T - T) / T;
    } else {
      EE3CL4_Lab4Exp2_DW.desiredpos_RWORK.Y =
        EE3CL4_Lab4Exp2_P.desiredpos_Amplitude * (3 * T - 4 *
        EE3CL4_Lab4Exp2_DW.desiredpos_RWORK.T) / T;
    }
  }

  /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn' */
  EE3CL4_Lab4Exp2_X.TransferFcn_CSTATE = 0.0;
}

/* Model terminate function */
void EE3CL4_Lab4Exp2_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: EE3CL4_Lab4Exp2/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    t_uint32 num_final_digital_outputs = 0;
    t_uint32 num_final_other_outputs = 0;
    hil_task_stop_all(EE3CL4_Lab4Exp2_DW.HILInitialize_Card);
    hil_monitor_stop_all(EE3CL4_Lab4Exp2_DW.HILInitialize_Card);
    is_switching = false;
    if ((EE3CL4_Lab4Exp2_P.HILInitialize_AOTerminate && !is_switching) ||
        (EE3CL4_Lab4Exp2_P.HILInitialize_AOExit && is_switching)) {
      num_final_analog_outputs = 1U;
    } else {
      num_final_analog_outputs = 0;
    }

    if ((EE3CL4_Lab4Exp2_P.HILInitialize_DOTerminate && !is_switching) ||
        (EE3CL4_Lab4Exp2_P.HILInitialize_DOExit && is_switching)) {
      num_final_digital_outputs = 1U;
    } else {
      num_final_digital_outputs = 0;
    }

    if ((EE3CL4_Lab4Exp2_P.HILInitialize_OOTerminate && !is_switching) ||
        (EE3CL4_Lab4Exp2_P.HILInitialize_OOExit && is_switching)) {
      num_final_other_outputs = 3U;
    } else {
      num_final_other_outputs = 0;
    }

    if (0
        || num_final_analog_outputs > 0
        || num_final_digital_outputs > 0
        || num_final_other_outputs > 0
        ) {
      /* Attempt to write the final outputs atomically (due to firmware issue in old Q2-USB). Otherwise write channels individually */
      result = hil_write(EE3CL4_Lab4Exp2_DW.HILInitialize_Card
                         , &EE3CL4_Lab4Exp2_P.HILInitialize_AOChannels,
                         num_final_analog_outputs
                         , NULL, 0
                         , &EE3CL4_Lab4Exp2_P.HILInitialize_DOChannels,
                         num_final_digital_outputs
                         , EE3CL4_Lab4Exp2_P.HILInitialize_OOChannels,
                         num_final_other_outputs
                         , &EE3CL4_Lab4Exp2_P.HILInitialize_AOFinal
                         , NULL
                         , (t_boolean *)
                         &EE3CL4_Lab4Exp2_P.HILInitialize_DOFinal
                         , EE3CL4_Lab4Exp2_P.HILInitialize_OOFinal
                         );
      if (result == -QERR_HIL_WRITE_NOT_SUPPORTED) {
        t_error local_result;
        result = 0;

        /* The hil_write operation is not supported by this card. Write final outputs for each channel type */
        if (num_final_analog_outputs > 0) {
          local_result = hil_write_analog(EE3CL4_Lab4Exp2_DW.HILInitialize_Card,
            &EE3CL4_Lab4Exp2_P.HILInitialize_AOChannels,
            num_final_analog_outputs, &EE3CL4_Lab4Exp2_P.HILInitialize_AOFinal);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_digital_outputs > 0) {
          local_result = hil_write_digital(EE3CL4_Lab4Exp2_DW.HILInitialize_Card,
            &EE3CL4_Lab4Exp2_P.HILInitialize_DOChannels,
            num_final_digital_outputs, (t_boolean *)
            &EE3CL4_Lab4Exp2_P.HILInitialize_DOFinal);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_other_outputs > 0) {
          local_result = hil_write_other(EE3CL4_Lab4Exp2_DW.HILInitialize_Card,
            EE3CL4_Lab4Exp2_P.HILInitialize_OOChannels, num_final_other_outputs,
            EE3CL4_Lab4Exp2_P.HILInitialize_OOFinal);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(EE3CL4_Lab4Exp2_M, _rt_error_message);
        }
      }
    }

    hil_task_delete_all(EE3CL4_Lab4Exp2_DW.HILInitialize_Card);
    hil_monitor_delete_all(EE3CL4_Lab4Exp2_DW.HILInitialize_Card);
    hil_close(EE3CL4_Lab4Exp2_DW.HILInitialize_Card);
    EE3CL4_Lab4Exp2_DW.HILInitialize_Card = NULL;
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/

/* Solver interface called by GRT_Main */
#ifndef USE_GENERATED_SOLVER

void rt_ODECreateIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEDestroyIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEUpdateContinuousStates(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

#endif

void MdlOutputs(int_T tid)
{
  EE3CL4_Lab4Exp2_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  EE3CL4_Lab4Exp2_update();
  UNUSED_PARAMETER(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  EE3CL4_Lab4Exp2_initialize();
}

void MdlTerminate(void)
{
  EE3CL4_Lab4Exp2_terminate();
}

/* Registration function */
RT_MODEL_EE3CL4_Lab4Exp2_T *EE3CL4_Lab4Exp2(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)EE3CL4_Lab4Exp2_M, 0,
                sizeof(RT_MODEL_EE3CL4_Lab4Exp2_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&EE3CL4_Lab4Exp2_M->solverInfo,
                          &EE3CL4_Lab4Exp2_M->Timing.simTimeStep);
    rtsiSetTPtr(&EE3CL4_Lab4Exp2_M->solverInfo, &rtmGetTPtr(EE3CL4_Lab4Exp2_M));
    rtsiSetStepSizePtr(&EE3CL4_Lab4Exp2_M->solverInfo,
                       &EE3CL4_Lab4Exp2_M->Timing.stepSize0);
    rtsiSetdXPtr(&EE3CL4_Lab4Exp2_M->solverInfo, &EE3CL4_Lab4Exp2_M->derivs);
    rtsiSetContStatesPtr(&EE3CL4_Lab4Exp2_M->solverInfo, (real_T **)
                         &EE3CL4_Lab4Exp2_M->contStates);
    rtsiSetNumContStatesPtr(&EE3CL4_Lab4Exp2_M->solverInfo,
      &EE3CL4_Lab4Exp2_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&EE3CL4_Lab4Exp2_M->solverInfo,
      &EE3CL4_Lab4Exp2_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&EE3CL4_Lab4Exp2_M->solverInfo,
      &EE3CL4_Lab4Exp2_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&EE3CL4_Lab4Exp2_M->solverInfo,
      &EE3CL4_Lab4Exp2_M->periodicContStateRanges);
    rtsiSetContStateDisabledPtr(&EE3CL4_Lab4Exp2_M->solverInfo, (boolean_T**)
      &EE3CL4_Lab4Exp2_M->contStateDisabled);
    rtsiSetErrorStatusPtr(&EE3CL4_Lab4Exp2_M->solverInfo, (&rtmGetErrorStatus
      (EE3CL4_Lab4Exp2_M)));
    rtsiSetRTModelPtr(&EE3CL4_Lab4Exp2_M->solverInfo, EE3CL4_Lab4Exp2_M);
  }

  rtsiSetSimTimeStep(&EE3CL4_Lab4Exp2_M->solverInfo, MAJOR_TIME_STEP);
  EE3CL4_Lab4Exp2_M->intgData.f[0] = EE3CL4_Lab4Exp2_M->odeF[0];
  EE3CL4_Lab4Exp2_M->contStates = ((real_T *) &EE3CL4_Lab4Exp2_X);
  EE3CL4_Lab4Exp2_M->contStateDisabled = ((boolean_T *) &EE3CL4_Lab4Exp2_XDis);
  EE3CL4_Lab4Exp2_M->Timing.tStart = (0.0);
  rtsiSetSolverData(&EE3CL4_Lab4Exp2_M->solverInfo, (void *)
                    &EE3CL4_Lab4Exp2_M->intgData);
  rtsiSetIsMinorTimeStepWithModeChange(&EE3CL4_Lab4Exp2_M->solverInfo, false);
  rtsiSetSolverName(&EE3CL4_Lab4Exp2_M->solverInfo,"ode1");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = EE3CL4_Lab4Exp2_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;

    /* polyspace +2 MISRA2012:D4.1 [Justified:Low] "EE3CL4_Lab4Exp2_M points to
       static memory which is guaranteed to be non-NULL" */
    EE3CL4_Lab4Exp2_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    EE3CL4_Lab4Exp2_M->Timing.sampleTimes =
      (&EE3CL4_Lab4Exp2_M->Timing.sampleTimesArray[0]);
    EE3CL4_Lab4Exp2_M->Timing.offsetTimes =
      (&EE3CL4_Lab4Exp2_M->Timing.offsetTimesArray[0]);

    /* task periods */
    EE3CL4_Lab4Exp2_M->Timing.sampleTimes[0] = (0.0);
    EE3CL4_Lab4Exp2_M->Timing.sampleTimes[1] = (0.002);

    /* task offsets */
    EE3CL4_Lab4Exp2_M->Timing.offsetTimes[0] = (0.0);
    EE3CL4_Lab4Exp2_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(EE3CL4_Lab4Exp2_M, &EE3CL4_Lab4Exp2_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = EE3CL4_Lab4Exp2_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    EE3CL4_Lab4Exp2_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(EE3CL4_Lab4Exp2_M, 6.0);
  EE3CL4_Lab4Exp2_M->Timing.stepSize0 = 0.002;
  EE3CL4_Lab4Exp2_M->Timing.stepSize1 = 0.002;

  /* External mode info */
  EE3CL4_Lab4Exp2_M->Sizes.checksums[0] = (696994864U);
  EE3CL4_Lab4Exp2_M->Sizes.checksums[1] = (1315396909U);
  EE3CL4_Lab4Exp2_M->Sizes.checksums[2] = (2616448972U);
  EE3CL4_Lab4Exp2_M->Sizes.checksums[3] = (1717187799U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    EE3CL4_Lab4Exp2_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(EE3CL4_Lab4Exp2_M->extModeInfo,
      &EE3CL4_Lab4Exp2_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(EE3CL4_Lab4Exp2_M->extModeInfo,
                        EE3CL4_Lab4Exp2_M->Sizes.checksums);
    rteiSetTPtr(EE3CL4_Lab4Exp2_M->extModeInfo, rtmGetTPtr(EE3CL4_Lab4Exp2_M));
  }

  EE3CL4_Lab4Exp2_M->solverInfoPtr = (&EE3CL4_Lab4Exp2_M->solverInfo);
  EE3CL4_Lab4Exp2_M->Timing.stepSize = (0.002);
  rtsiSetFixedStepSize(&EE3CL4_Lab4Exp2_M->solverInfo, 0.002);
  rtsiSetSolverMode(&EE3CL4_Lab4Exp2_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  EE3CL4_Lab4Exp2_M->blockIO = ((void *) &EE3CL4_Lab4Exp2_B);
  (void) memset(((void *) &EE3CL4_Lab4Exp2_B), 0,
                sizeof(B_EE3CL4_Lab4Exp2_T));

  /* parameters */
  EE3CL4_Lab4Exp2_M->defaultParam = ((real_T *)&EE3CL4_Lab4Exp2_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &EE3CL4_Lab4Exp2_X;
    EE3CL4_Lab4Exp2_M->contStates = (x);
    (void) memset((void *)&EE3CL4_Lab4Exp2_X, 0,
                  sizeof(X_EE3CL4_Lab4Exp2_T));
  }

  /* disabled states */
  {
    boolean_T *xdis = (boolean_T *) &EE3CL4_Lab4Exp2_XDis;
    EE3CL4_Lab4Exp2_M->contStateDisabled = (xdis);
    (void) memset((void *)&EE3CL4_Lab4Exp2_XDis, 0,
                  sizeof(XDis_EE3CL4_Lab4Exp2_T));
  }

  /* states (dwork) */
  EE3CL4_Lab4Exp2_M->dwork = ((void *) &EE3CL4_Lab4Exp2_DW);
  (void) memset((void *)&EE3CL4_Lab4Exp2_DW, 0,
                sizeof(DW_EE3CL4_Lab4Exp2_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    EE3CL4_Lab4Exp2_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 20;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  EE3CL4_Lab4Exp2_M->Sizes.numContStates = (1);/* Number of continuous states */
  EE3CL4_Lab4Exp2_M->Sizes.numPeriodicContStates = (0);
                                      /* Number of periodic continuous states */
  EE3CL4_Lab4Exp2_M->Sizes.numY = (0); /* Number of model outputs */
  EE3CL4_Lab4Exp2_M->Sizes.numU = (0); /* Number of model inputs */
  EE3CL4_Lab4Exp2_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  EE3CL4_Lab4Exp2_M->Sizes.numSampTimes = (2);/* Number of sample times */
  EE3CL4_Lab4Exp2_M->Sizes.numBlocks = (10);/* Number of blocks */
  EE3CL4_Lab4Exp2_M->Sizes.numBlockIO = (4);/* Number of block outputs */
  EE3CL4_Lab4Exp2_M->Sizes.numBlockPrms = (87);/* Sum of parameter "widths" */
  return EE3CL4_Lab4Exp2_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
