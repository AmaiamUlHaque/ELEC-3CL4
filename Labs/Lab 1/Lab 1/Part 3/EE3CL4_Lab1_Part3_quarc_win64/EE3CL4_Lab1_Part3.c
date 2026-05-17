/*
 * EE3CL4_Lab1_Part3.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "EE3CL4_Lab1_Part3".
 *
 * Model version              : 11.4
 * Simulink Coder version : 23.2 (R2023b) 01-Aug-2023
 * C source code generated on : Thu Jan 29 15:57:16 2026
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "EE3CL4_Lab1_Part3.h"
#include "rtwtypes.h"
#include "EE3CL4_Lab1_Part3_private.h"
#include <string.h>
#include "rt_nonfinite.h"
#include "EE3CL4_Lab1_Part3_dt.h"

/* Block signals (default storage) */
B_EE3CL4_Lab1_Part3_T EE3CL4_Lab1_Part3_B;

/* Block states (default storage) */
DW_EE3CL4_Lab1_Part3_T EE3CL4_Lab1_Part3_DW;

/* Real-time model */
static RT_MODEL_EE3CL4_Lab1_Part3_T EE3CL4_Lab1_Part3_M_;
RT_MODEL_EE3CL4_Lab1_Part3_T *const EE3CL4_Lab1_Part3_M = &EE3CL4_Lab1_Part3_M_;

/* Model output function */
void EE3CL4_Lab1_Part3_output(void)
{
  real_T lastTime;
  real_T rtb_PulseGenerator;
  real_T *lastU;

  /* S-Function (hil_read_encoder_block): '<Root>/read encoder' */

  /* S-Function Block: EE3CL4_Lab1_Part3/read encoder (hil_read_encoder_block) */
  {
    t_error result = hil_read_encoder(EE3CL4_Lab1_Part3_DW.HILInitialize_Card,
      &EE3CL4_Lab1_Part3_P.readencoder_channels, 1,
      &EE3CL4_Lab1_Part3_DW.readencoder_Buffer);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(EE3CL4_Lab1_Part3_M, _rt_error_message);
    } else {
      rtb_PulseGenerator = EE3CL4_Lab1_Part3_DW.readencoder_Buffer;
    }
  }

  /* Gain: '<Root>/counts to rad' */
  EE3CL4_Lab1_Part3_B.countstorad = EE3CL4_Lab1_Part3_P.countstorad_Gain *
    rtb_PulseGenerator;

  /* Derivative: '<Root>/Derivative' */
  rtb_PulseGenerator = EE3CL4_Lab1_Part3_M->Timing.t[0];
  if ((EE3CL4_Lab1_Part3_DW.TimeStampA >= rtb_PulseGenerator) &&
      (EE3CL4_Lab1_Part3_DW.TimeStampB >= rtb_PulseGenerator)) {
    /* Derivative: '<Root>/Derivative' */
    EE3CL4_Lab1_Part3_B.Derivative = 0.0;
  } else {
    lastTime = EE3CL4_Lab1_Part3_DW.TimeStampA;
    lastU = &EE3CL4_Lab1_Part3_DW.LastUAtTimeA;
    if (EE3CL4_Lab1_Part3_DW.TimeStampA < EE3CL4_Lab1_Part3_DW.TimeStampB) {
      if (EE3CL4_Lab1_Part3_DW.TimeStampB < rtb_PulseGenerator) {
        lastTime = EE3CL4_Lab1_Part3_DW.TimeStampB;
        lastU = &EE3CL4_Lab1_Part3_DW.LastUAtTimeB;
      }
    } else if (EE3CL4_Lab1_Part3_DW.TimeStampA >= rtb_PulseGenerator) {
      lastTime = EE3CL4_Lab1_Part3_DW.TimeStampB;
      lastU = &EE3CL4_Lab1_Part3_DW.LastUAtTimeB;
    }

    /* Derivative: '<Root>/Derivative' */
    EE3CL4_Lab1_Part3_B.Derivative = (EE3CL4_Lab1_Part3_B.countstorad - *lastU) /
      (rtb_PulseGenerator - lastTime);
  }

  /* End of Derivative: '<Root>/Derivative' */
  /* DiscretePulseGenerator: '<Root>/Pulse Generator' */
  if ((EE3CL4_Lab1_Part3_DW.clockTickCounter <
       EE3CL4_Lab1_Part3_P.PulseGenerator_Duty) &&
      (EE3CL4_Lab1_Part3_DW.clockTickCounter >= 0)) {
    rtb_PulseGenerator = EE3CL4_Lab1_Part3_P.PulseGenerator_Amp;
  } else {
    rtb_PulseGenerator = 0.0;
  }

  if (EE3CL4_Lab1_Part3_DW.clockTickCounter >=
      EE3CL4_Lab1_Part3_P.PulseGenerator_Period - 1.0) {
    EE3CL4_Lab1_Part3_DW.clockTickCounter = 0;
  } else {
    EE3CL4_Lab1_Part3_DW.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<Root>/Pulse Generator' */

  /* Sum: '<Root>/Sum' incorporates:
   *  Constant: '<Root>/motor input'
   */
  EE3CL4_Lab1_Part3_B.Sum = rtb_PulseGenerator +
    EE3CL4_Lab1_Part3_P.motorinput_Value;

  /* S-Function (hil_write_analog_block): '<Root>/HIL Write Analog' */

  /* S-Function Block: EE3CL4_Lab1_Part3/HIL Write Analog (hil_write_analog_block) */
  {
    t_error result;
    result = hil_write_analog(EE3CL4_Lab1_Part3_DW.HILInitialize_Card,
      &EE3CL4_Lab1_Part3_P.HILWriteAnalog_channels, 1, &EE3CL4_Lab1_Part3_B.Sum);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(EE3CL4_Lab1_Part3_M, _rt_error_message);
    }
  }
}

/* Model update function */
void EE3CL4_Lab1_Part3_update(void)
{
  real_T *lastU;

  /* Update for Derivative: '<Root>/Derivative' */
  if (EE3CL4_Lab1_Part3_DW.TimeStampA == (rtInf)) {
    EE3CL4_Lab1_Part3_DW.TimeStampA = EE3CL4_Lab1_Part3_M->Timing.t[0];
    lastU = &EE3CL4_Lab1_Part3_DW.LastUAtTimeA;
  } else if (EE3CL4_Lab1_Part3_DW.TimeStampB == (rtInf)) {
    EE3CL4_Lab1_Part3_DW.TimeStampB = EE3CL4_Lab1_Part3_M->Timing.t[0];
    lastU = &EE3CL4_Lab1_Part3_DW.LastUAtTimeB;
  } else if (EE3CL4_Lab1_Part3_DW.TimeStampA < EE3CL4_Lab1_Part3_DW.TimeStampB)
  {
    EE3CL4_Lab1_Part3_DW.TimeStampA = EE3CL4_Lab1_Part3_M->Timing.t[0];
    lastU = &EE3CL4_Lab1_Part3_DW.LastUAtTimeA;
  } else {
    EE3CL4_Lab1_Part3_DW.TimeStampB = EE3CL4_Lab1_Part3_M->Timing.t[0];
    lastU = &EE3CL4_Lab1_Part3_DW.LastUAtTimeB;
  }

  *lastU = EE3CL4_Lab1_Part3_B.countstorad;

  /* End of Update for Derivative: '<Root>/Derivative' */

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++EE3CL4_Lab1_Part3_M->Timing.clockTick0)) {
    ++EE3CL4_Lab1_Part3_M->Timing.clockTickH0;
  }

  EE3CL4_Lab1_Part3_M->Timing.t[0] = EE3CL4_Lab1_Part3_M->Timing.clockTick0 *
    EE3CL4_Lab1_Part3_M->Timing.stepSize0 +
    EE3CL4_Lab1_Part3_M->Timing.clockTickH0 *
    EE3CL4_Lab1_Part3_M->Timing.stepSize0 * 4294967296.0;

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
    if (!(++EE3CL4_Lab1_Part3_M->Timing.clockTick1)) {
      ++EE3CL4_Lab1_Part3_M->Timing.clockTickH1;
    }

    EE3CL4_Lab1_Part3_M->Timing.t[1] = EE3CL4_Lab1_Part3_M->Timing.clockTick1 *
      EE3CL4_Lab1_Part3_M->Timing.stepSize1 +
      EE3CL4_Lab1_Part3_M->Timing.clockTickH1 *
      EE3CL4_Lab1_Part3_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Model initialize function */
void EE3CL4_Lab1_Part3_initialize(void)
{
  /* Start for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: EE3CL4_Lab1_Part3/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("qube_servo3_usb", "0",
                      &EE3CL4_Lab1_Part3_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(EE3CL4_Lab1_Part3_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options
      (EE3CL4_Lab1_Part3_DW.HILInitialize_Card,
       "deadband_compensation=0.65;pwm_en=0;enc0_velocity=3.0;enc1_velocity=3.0;",
       73);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(EE3CL4_Lab1_Part3_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(EE3CL4_Lab1_Part3_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(EE3CL4_Lab1_Part3_M, _rt_error_message);
      return;
    }

    if ((EE3CL4_Lab1_Part3_P.HILInitialize_AIPStart && !is_switching) ||
        (EE3CL4_Lab1_Part3_P.HILInitialize_AIPEnter && is_switching)) {
      result = hil_set_analog_input_ranges
        (EE3CL4_Lab1_Part3_DW.HILInitialize_Card,
         &EE3CL4_Lab1_Part3_P.HILInitialize_AIChannels, 1U,
         &EE3CL4_Lab1_Part3_P.HILInitialize_AILow,
         &EE3CL4_Lab1_Part3_P.HILInitialize_AIHigh);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(EE3CL4_Lab1_Part3_M, _rt_error_message);
        return;
      }
    }

    if ((EE3CL4_Lab1_Part3_P.HILInitialize_AOPStart && !is_switching) ||
        (EE3CL4_Lab1_Part3_P.HILInitialize_AOPEnter && is_switching)) {
      result = hil_set_analog_output_ranges
        (EE3CL4_Lab1_Part3_DW.HILInitialize_Card,
         &EE3CL4_Lab1_Part3_P.HILInitialize_AOChannels, 1U,
         &EE3CL4_Lab1_Part3_P.HILInitialize_AOLow,
         &EE3CL4_Lab1_Part3_P.HILInitialize_AOHigh);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(EE3CL4_Lab1_Part3_M, _rt_error_message);
        return;
      }
    }

    if ((EE3CL4_Lab1_Part3_P.HILInitialize_AOStart && !is_switching) ||
        (EE3CL4_Lab1_Part3_P.HILInitialize_AOEnter && is_switching)) {
      result = hil_write_analog(EE3CL4_Lab1_Part3_DW.HILInitialize_Card,
        &EE3CL4_Lab1_Part3_P.HILInitialize_AOChannels, 1U,
        &EE3CL4_Lab1_Part3_P.HILInitialize_AOInitial);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(EE3CL4_Lab1_Part3_M, _rt_error_message);
        return;
      }
    }

    if (EE3CL4_Lab1_Part3_P.HILInitialize_AOReset) {
      result = hil_watchdog_set_analog_expiration_state
        (EE3CL4_Lab1_Part3_DW.HILInitialize_Card,
         &EE3CL4_Lab1_Part3_P.HILInitialize_AOChannels, 1U,
         &EE3CL4_Lab1_Part3_P.HILInitialize_AOWatchdog);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(EE3CL4_Lab1_Part3_M, _rt_error_message);
        return;
      }
    }

    result = hil_set_digital_directions(EE3CL4_Lab1_Part3_DW.HILInitialize_Card,
      NULL, 0U, &EE3CL4_Lab1_Part3_P.HILInitialize_DOChannels, 1U);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(EE3CL4_Lab1_Part3_M, _rt_error_message);
      return;
    }

    if ((EE3CL4_Lab1_Part3_P.HILInitialize_DOStart && !is_switching) ||
        (EE3CL4_Lab1_Part3_P.HILInitialize_DOEnter && is_switching)) {
      result = hil_write_digital(EE3CL4_Lab1_Part3_DW.HILInitialize_Card,
        &EE3CL4_Lab1_Part3_P.HILInitialize_DOChannels, 1U, (t_boolean *)
        &EE3CL4_Lab1_Part3_P.HILInitialize_DOInitial);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(EE3CL4_Lab1_Part3_M, _rt_error_message);
        return;
      }
    }

    if (EE3CL4_Lab1_Part3_P.HILInitialize_DOReset) {
      result = hil_watchdog_set_digital_expiration_state
        (EE3CL4_Lab1_Part3_DW.HILInitialize_Card,
         &EE3CL4_Lab1_Part3_P.HILInitialize_DOChannels, 1U, (const
          t_digital_state *) &EE3CL4_Lab1_Part3_P.HILInitialize_DOWatchdog);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(EE3CL4_Lab1_Part3_M, _rt_error_message);
        return;
      }
    }

    if ((EE3CL4_Lab1_Part3_P.HILInitialize_EIPStart && !is_switching) ||
        (EE3CL4_Lab1_Part3_P.HILInitialize_EIPEnter && is_switching)) {
      EE3CL4_Lab1_Part3_DW.HILInitialize_QuadratureModes[0] =
        EE3CL4_Lab1_Part3_P.HILInitialize_EIQuadrature;
      EE3CL4_Lab1_Part3_DW.HILInitialize_QuadratureModes[1] =
        EE3CL4_Lab1_Part3_P.HILInitialize_EIQuadrature;
      result = hil_set_encoder_quadrature_mode
        (EE3CL4_Lab1_Part3_DW.HILInitialize_Card,
         EE3CL4_Lab1_Part3_P.HILInitialize_EIChannels, 2U,
         (t_encoder_quadrature_mode *)
         &EE3CL4_Lab1_Part3_DW.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(EE3CL4_Lab1_Part3_M, _rt_error_message);
        return;
      }
    }

    if ((EE3CL4_Lab1_Part3_P.HILInitialize_EIStart && !is_switching) ||
        (EE3CL4_Lab1_Part3_P.HILInitialize_EIEnter && is_switching)) {
      EE3CL4_Lab1_Part3_DW.HILInitialize_InitialEICounts[0] =
        EE3CL4_Lab1_Part3_P.HILInitialize_EIInitial;
      EE3CL4_Lab1_Part3_DW.HILInitialize_InitialEICounts[1] =
        EE3CL4_Lab1_Part3_P.HILInitialize_EIInitial;
      result = hil_set_encoder_counts(EE3CL4_Lab1_Part3_DW.HILInitialize_Card,
        EE3CL4_Lab1_Part3_P.HILInitialize_EIChannels, 2U,
        &EE3CL4_Lab1_Part3_DW.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(EE3CL4_Lab1_Part3_M, _rt_error_message);
        return;
      }
    }

    if ((EE3CL4_Lab1_Part3_P.HILInitialize_OOStart && !is_switching) ||
        (EE3CL4_Lab1_Part3_P.HILInitialize_OOEnter && is_switching)) {
      result = hil_write_other(EE3CL4_Lab1_Part3_DW.HILInitialize_Card,
        EE3CL4_Lab1_Part3_P.HILInitialize_OOChannels, 3U,
        EE3CL4_Lab1_Part3_P.HILInitialize_OOInitial);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(EE3CL4_Lab1_Part3_M, _rt_error_message);
        return;
      }
    }

    if (EE3CL4_Lab1_Part3_P.HILInitialize_OOReset) {
      result = hil_watchdog_set_other_expiration_state
        (EE3CL4_Lab1_Part3_DW.HILInitialize_Card,
         EE3CL4_Lab1_Part3_P.HILInitialize_OOChannels, 3U,
         EE3CL4_Lab1_Part3_P.HILInitialize_OOWatchdog);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(EE3CL4_Lab1_Part3_M, _rt_error_message);
        return;
      }
    }
  }

  /* Start for DiscretePulseGenerator: '<Root>/Pulse Generator' */
  EE3CL4_Lab1_Part3_DW.clockTickCounter = 0;

  /* InitializeConditions for Derivative: '<Root>/Derivative' */
  EE3CL4_Lab1_Part3_DW.TimeStampA = (rtInf);
  EE3CL4_Lab1_Part3_DW.TimeStampB = (rtInf);
}

/* Model terminate function */
void EE3CL4_Lab1_Part3_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: EE3CL4_Lab1_Part3/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    t_uint32 num_final_digital_outputs = 0;
    t_uint32 num_final_other_outputs = 0;
    hil_task_stop_all(EE3CL4_Lab1_Part3_DW.HILInitialize_Card);
    hil_monitor_stop_all(EE3CL4_Lab1_Part3_DW.HILInitialize_Card);
    is_switching = false;
    if ((EE3CL4_Lab1_Part3_P.HILInitialize_AOTerminate && !is_switching) ||
        (EE3CL4_Lab1_Part3_P.HILInitialize_AOExit && is_switching)) {
      num_final_analog_outputs = 1U;
    } else {
      num_final_analog_outputs = 0;
    }

    if ((EE3CL4_Lab1_Part3_P.HILInitialize_DOTerminate && !is_switching) ||
        (EE3CL4_Lab1_Part3_P.HILInitialize_DOExit && is_switching)) {
      num_final_digital_outputs = 1U;
    } else {
      num_final_digital_outputs = 0;
    }

    if ((EE3CL4_Lab1_Part3_P.HILInitialize_OOTerminate && !is_switching) ||
        (EE3CL4_Lab1_Part3_P.HILInitialize_OOExit && is_switching)) {
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
      result = hil_write(EE3CL4_Lab1_Part3_DW.HILInitialize_Card
                         , &EE3CL4_Lab1_Part3_P.HILInitialize_AOChannels,
                         num_final_analog_outputs
                         , NULL, 0
                         , &EE3CL4_Lab1_Part3_P.HILInitialize_DOChannels,
                         num_final_digital_outputs
                         , EE3CL4_Lab1_Part3_P.HILInitialize_OOChannels,
                         num_final_other_outputs
                         , &EE3CL4_Lab1_Part3_P.HILInitialize_AOFinal
                         , NULL
                         , (t_boolean *)
                         &EE3CL4_Lab1_Part3_P.HILInitialize_DOFinal
                         , EE3CL4_Lab1_Part3_P.HILInitialize_OOFinal
                         );
      if (result == -QERR_HIL_WRITE_NOT_SUPPORTED) {
        t_error local_result;
        result = 0;

        /* The hil_write operation is not supported by this card. Write final outputs for each channel type */
        if (num_final_analog_outputs > 0) {
          local_result = hil_write_analog
            (EE3CL4_Lab1_Part3_DW.HILInitialize_Card,
             &EE3CL4_Lab1_Part3_P.HILInitialize_AOChannels,
             num_final_analog_outputs,
             &EE3CL4_Lab1_Part3_P.HILInitialize_AOFinal);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_digital_outputs > 0) {
          local_result = hil_write_digital
            (EE3CL4_Lab1_Part3_DW.HILInitialize_Card,
             &EE3CL4_Lab1_Part3_P.HILInitialize_DOChannels,
             num_final_digital_outputs, (t_boolean *)
             &EE3CL4_Lab1_Part3_P.HILInitialize_DOFinal);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_other_outputs > 0) {
          local_result = hil_write_other(EE3CL4_Lab1_Part3_DW.HILInitialize_Card,
            EE3CL4_Lab1_Part3_P.HILInitialize_OOChannels,
            num_final_other_outputs, EE3CL4_Lab1_Part3_P.HILInitialize_OOFinal);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(EE3CL4_Lab1_Part3_M, _rt_error_message);
        }
      }
    }

    hil_task_delete_all(EE3CL4_Lab1_Part3_DW.HILInitialize_Card);
    hil_monitor_delete_all(EE3CL4_Lab1_Part3_DW.HILInitialize_Card);
    hil_close(EE3CL4_Lab1_Part3_DW.HILInitialize_Card);
    EE3CL4_Lab1_Part3_DW.HILInitialize_Card = NULL;
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  EE3CL4_Lab1_Part3_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  EE3CL4_Lab1_Part3_update();
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
  EE3CL4_Lab1_Part3_initialize();
}

void MdlTerminate(void)
{
  EE3CL4_Lab1_Part3_terminate();
}

/* Registration function */
RT_MODEL_EE3CL4_Lab1_Part3_T *EE3CL4_Lab1_Part3(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)EE3CL4_Lab1_Part3_M, 0,
                sizeof(RT_MODEL_EE3CL4_Lab1_Part3_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&EE3CL4_Lab1_Part3_M->solverInfo,
                          &EE3CL4_Lab1_Part3_M->Timing.simTimeStep);
    rtsiSetTPtr(&EE3CL4_Lab1_Part3_M->solverInfo, &rtmGetTPtr
                (EE3CL4_Lab1_Part3_M));
    rtsiSetStepSizePtr(&EE3CL4_Lab1_Part3_M->solverInfo,
                       &EE3CL4_Lab1_Part3_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&EE3CL4_Lab1_Part3_M->solverInfo, (&rtmGetErrorStatus
      (EE3CL4_Lab1_Part3_M)));
    rtsiSetRTModelPtr(&EE3CL4_Lab1_Part3_M->solverInfo, EE3CL4_Lab1_Part3_M);
  }

  rtsiSetSimTimeStep(&EE3CL4_Lab1_Part3_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&EE3CL4_Lab1_Part3_M->solverInfo,"FixedStepDiscrete");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = EE3CL4_Lab1_Part3_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;

    /* polyspace +2 MISRA2012:D4.1 [Justified:Low] "EE3CL4_Lab1_Part3_M points to
       static memory which is guaranteed to be non-NULL" */
    EE3CL4_Lab1_Part3_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    EE3CL4_Lab1_Part3_M->Timing.sampleTimes =
      (&EE3CL4_Lab1_Part3_M->Timing.sampleTimesArray[0]);
    EE3CL4_Lab1_Part3_M->Timing.offsetTimes =
      (&EE3CL4_Lab1_Part3_M->Timing.offsetTimesArray[0]);

    /* task periods */
    EE3CL4_Lab1_Part3_M->Timing.sampleTimes[0] = (0.0);
    EE3CL4_Lab1_Part3_M->Timing.sampleTimes[1] = (0.002);

    /* task offsets */
    EE3CL4_Lab1_Part3_M->Timing.offsetTimes[0] = (0.0);
    EE3CL4_Lab1_Part3_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(EE3CL4_Lab1_Part3_M, &EE3CL4_Lab1_Part3_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = EE3CL4_Lab1_Part3_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    EE3CL4_Lab1_Part3_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(EE3CL4_Lab1_Part3_M, 10.0);
  EE3CL4_Lab1_Part3_M->Timing.stepSize0 = 0.002;
  EE3CL4_Lab1_Part3_M->Timing.stepSize1 = 0.002;

  /* External mode info */
  EE3CL4_Lab1_Part3_M->Sizes.checksums[0] = (3645938720U);
  EE3CL4_Lab1_Part3_M->Sizes.checksums[1] = (3446028300U);
  EE3CL4_Lab1_Part3_M->Sizes.checksums[2] = (1810866488U);
  EE3CL4_Lab1_Part3_M->Sizes.checksums[3] = (69992707U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    EE3CL4_Lab1_Part3_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(EE3CL4_Lab1_Part3_M->extModeInfo,
      &EE3CL4_Lab1_Part3_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(EE3CL4_Lab1_Part3_M->extModeInfo,
                        EE3CL4_Lab1_Part3_M->Sizes.checksums);
    rteiSetTPtr(EE3CL4_Lab1_Part3_M->extModeInfo, rtmGetTPtr(EE3CL4_Lab1_Part3_M));
  }

  EE3CL4_Lab1_Part3_M->solverInfoPtr = (&EE3CL4_Lab1_Part3_M->solverInfo);
  EE3CL4_Lab1_Part3_M->Timing.stepSize = (0.002);
  rtsiSetFixedStepSize(&EE3CL4_Lab1_Part3_M->solverInfo, 0.002);
  rtsiSetSolverMode(&EE3CL4_Lab1_Part3_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  EE3CL4_Lab1_Part3_M->blockIO = ((void *) &EE3CL4_Lab1_Part3_B);
  (void) memset(((void *) &EE3CL4_Lab1_Part3_B), 0,
                sizeof(B_EE3CL4_Lab1_Part3_T));

  /* parameters */
  EE3CL4_Lab1_Part3_M->defaultParam = ((real_T *)&EE3CL4_Lab1_Part3_P);

  /* states (dwork) */
  EE3CL4_Lab1_Part3_M->dwork = ((void *) &EE3CL4_Lab1_Part3_DW);
  (void) memset((void *)&EE3CL4_Lab1_Part3_DW, 0,
                sizeof(DW_EE3CL4_Lab1_Part3_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    EE3CL4_Lab1_Part3_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 20;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  EE3CL4_Lab1_Part3_M->Sizes.numContStates = (0);/* Number of continuous states */
  EE3CL4_Lab1_Part3_M->Sizes.numY = (0);/* Number of model outputs */
  EE3CL4_Lab1_Part3_M->Sizes.numU = (0);/* Number of model inputs */
  EE3CL4_Lab1_Part3_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  EE3CL4_Lab1_Part3_M->Sizes.numSampTimes = (2);/* Number of sample times */
  EE3CL4_Lab1_Part3_M->Sizes.numBlocks = (12);/* Number of blocks */
  EE3CL4_Lab1_Part3_M->Sizes.numBlockIO = (3);/* Number of block outputs */
  EE3CL4_Lab1_Part3_M->Sizes.numBlockPrms = (86);/* Sum of parameter "widths" */
  return EE3CL4_Lab1_Part3_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
