/*
 * EE3CL4_Lab.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "EE3CL4_Lab".
 *
 * Model version              : 11.1
 * Simulink Coder version : 23.2 (R2023b) 01-Aug-2023
 * C source code generated on : Thu Feb 12 15:37:04 2026
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "EE3CL4_Lab.h"
#include "rtwtypes.h"
#include "EE3CL4_Lab_private.h"
#include <string.h>
#include "rt_nonfinite.h"
#include "EE3CL4_Lab_dt.h"

/* Block signals (default storage) */
B_EE3CL4_Lab_T EE3CL4_Lab_B;

/* Block states (default storage) */
DW_EE3CL4_Lab_T EE3CL4_Lab_DW;

/* Real-time model */
static RT_MODEL_EE3CL4_Lab_T EE3CL4_Lab_M_;
RT_MODEL_EE3CL4_Lab_T *const EE3CL4_Lab_M = &EE3CL4_Lab_M_;

/* Model output function */
void EE3CL4_Lab_output(void)
{
  real_T rtb_proportionalcontroller;

  /* S-Function (hil_read_encoder_block): '<Root>/read motor encoder' */

  /* S-Function Block: EE3CL4_Lab/read motor encoder (hil_read_encoder_block) */
  {
    t_error result = hil_read_encoder(EE3CL4_Lab_DW.HILInitialize_Card,
      &EE3CL4_Lab_P.readmotorencoder_channels, 1,
      &EE3CL4_Lab_DW.readmotorencoder_Buffer);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(EE3CL4_Lab_M, _rt_error_message);
    } else {
      rtb_proportionalcontroller = EE3CL4_Lab_DW.readmotorencoder_Buffer;
    }
  }

  /* Gain: '<Root>/count to rad' */
  EE3CL4_Lab_B.counttorad = EE3CL4_Lab_P.counttorad_Gain *
    rtb_proportionalcontroller;

  /* DiscretePulseGenerator: '<Root>/Pulse Generator' */
  if ((EE3CL4_Lab_DW.clockTickCounter < EE3CL4_Lab_P.PulseGenerator_Duty) &&
      (EE3CL4_Lab_DW.clockTickCounter >= 0)) {
    rtb_proportionalcontroller = EE3CL4_Lab_P.PulseGenerator_Amp;
  } else {
    rtb_proportionalcontroller = 0.0;
  }

  if (EE3CL4_Lab_DW.clockTickCounter >= EE3CL4_Lab_P.PulseGenerator_Period - 1.0)
  {
    EE3CL4_Lab_DW.clockTickCounter = 0;
  } else {
    EE3CL4_Lab_DW.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<Root>/Pulse Generator' */

  /* Gain: '<Root>/proportional controller' incorporates:
   *  Sum: '<Root>/Sum'
   */
  rtb_proportionalcontroller = (rtb_proportionalcontroller -
    EE3CL4_Lab_B.counttorad) * EE3CL4_Lab_P.proportionalcontroller_Gain;

  /* S-Function (hil_write_analog_block): '<Root>/send signal to motor' */

  /* S-Function Block: EE3CL4_Lab/send signal to motor (hil_write_analog_block) */
  {
    t_error result;
    result = hil_write_analog(EE3CL4_Lab_DW.HILInitialize_Card,
      &EE3CL4_Lab_P.sendsignaltomotor_channels, 1, &rtb_proportionalcontroller);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(EE3CL4_Lab_M, _rt_error_message);
    }
  }
}

/* Model update function */
void EE3CL4_Lab_update(void)
{
  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++EE3CL4_Lab_M->Timing.clockTick0)) {
    ++EE3CL4_Lab_M->Timing.clockTickH0;
  }

  EE3CL4_Lab_M->Timing.t[0] = EE3CL4_Lab_M->Timing.clockTick0 *
    EE3CL4_Lab_M->Timing.stepSize0 + EE3CL4_Lab_M->Timing.clockTickH0 *
    EE3CL4_Lab_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void EE3CL4_Lab_initialize(void)
{
  /* Start for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: EE3CL4_Lab/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("qube_servo3_usb", "0", &EE3CL4_Lab_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(EE3CL4_Lab_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options(EE3CL4_Lab_DW.HILInitialize_Card,
      "deadband_compensation=0.65;pwm_en=0;enc0_velocity=3.0;enc1_velocity=3.0;",
      73);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(EE3CL4_Lab_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(EE3CL4_Lab_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(EE3CL4_Lab_M, _rt_error_message);
      return;
    }

    if ((EE3CL4_Lab_P.HILInitialize_AIPStart && !is_switching) ||
        (EE3CL4_Lab_P.HILInitialize_AIPEnter && is_switching)) {
      result = hil_set_analog_input_ranges(EE3CL4_Lab_DW.HILInitialize_Card,
        &EE3CL4_Lab_P.HILInitialize_AIChannels, 1U,
        &EE3CL4_Lab_P.HILInitialize_AILow, &EE3CL4_Lab_P.HILInitialize_AIHigh);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(EE3CL4_Lab_M, _rt_error_message);
        return;
      }
    }

    if ((EE3CL4_Lab_P.HILInitialize_AOPStart && !is_switching) ||
        (EE3CL4_Lab_P.HILInitialize_AOPEnter && is_switching)) {
      result = hil_set_analog_output_ranges(EE3CL4_Lab_DW.HILInitialize_Card,
        &EE3CL4_Lab_P.HILInitialize_AOChannels, 1U,
        &EE3CL4_Lab_P.HILInitialize_AOLow, &EE3CL4_Lab_P.HILInitialize_AOHigh);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(EE3CL4_Lab_M, _rt_error_message);
        return;
      }
    }

    if ((EE3CL4_Lab_P.HILInitialize_AOStart && !is_switching) ||
        (EE3CL4_Lab_P.HILInitialize_AOEnter && is_switching)) {
      result = hil_write_analog(EE3CL4_Lab_DW.HILInitialize_Card,
        &EE3CL4_Lab_P.HILInitialize_AOChannels, 1U,
        &EE3CL4_Lab_P.HILInitialize_AOInitial);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(EE3CL4_Lab_M, _rt_error_message);
        return;
      }
    }

    if (EE3CL4_Lab_P.HILInitialize_AOReset) {
      result = hil_watchdog_set_analog_expiration_state
        (EE3CL4_Lab_DW.HILInitialize_Card,
         &EE3CL4_Lab_P.HILInitialize_AOChannels, 1U,
         &EE3CL4_Lab_P.HILInitialize_AOWatchdog);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(EE3CL4_Lab_M, _rt_error_message);
        return;
      }
    }

    result = hil_set_digital_directions(EE3CL4_Lab_DW.HILInitialize_Card, NULL,
      0U, &EE3CL4_Lab_P.HILInitialize_DOChannels, 1U);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(EE3CL4_Lab_M, _rt_error_message);
      return;
    }

    if ((EE3CL4_Lab_P.HILInitialize_DOStart && !is_switching) ||
        (EE3CL4_Lab_P.HILInitialize_DOEnter && is_switching)) {
      result = hil_write_digital(EE3CL4_Lab_DW.HILInitialize_Card,
        &EE3CL4_Lab_P.HILInitialize_DOChannels, 1U, (t_boolean *)
        &EE3CL4_Lab_P.HILInitialize_DOInitial);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(EE3CL4_Lab_M, _rt_error_message);
        return;
      }
    }

    if (EE3CL4_Lab_P.HILInitialize_DOReset) {
      result = hil_watchdog_set_digital_expiration_state
        (EE3CL4_Lab_DW.HILInitialize_Card,
         &EE3CL4_Lab_P.HILInitialize_DOChannels, 1U, (const t_digital_state *)
         &EE3CL4_Lab_P.HILInitialize_DOWatchdog);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(EE3CL4_Lab_M, _rt_error_message);
        return;
      }
    }

    if ((EE3CL4_Lab_P.HILInitialize_EIPStart && !is_switching) ||
        (EE3CL4_Lab_P.HILInitialize_EIPEnter && is_switching)) {
      EE3CL4_Lab_DW.HILInitialize_QuadratureModes[0] =
        EE3CL4_Lab_P.HILInitialize_EIQuadrature;
      EE3CL4_Lab_DW.HILInitialize_QuadratureModes[1] =
        EE3CL4_Lab_P.HILInitialize_EIQuadrature;
      result = hil_set_encoder_quadrature_mode(EE3CL4_Lab_DW.HILInitialize_Card,
        EE3CL4_Lab_P.HILInitialize_EIChannels, 2U, (t_encoder_quadrature_mode *)
        &EE3CL4_Lab_DW.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(EE3CL4_Lab_M, _rt_error_message);
        return;
      }
    }

    if ((EE3CL4_Lab_P.HILInitialize_EIStart && !is_switching) ||
        (EE3CL4_Lab_P.HILInitialize_EIEnter && is_switching)) {
      EE3CL4_Lab_DW.HILInitialize_InitialEICounts[0] =
        EE3CL4_Lab_P.HILInitialize_EIInitial;
      EE3CL4_Lab_DW.HILInitialize_InitialEICounts[1] =
        EE3CL4_Lab_P.HILInitialize_EIInitial;
      result = hil_set_encoder_counts(EE3CL4_Lab_DW.HILInitialize_Card,
        EE3CL4_Lab_P.HILInitialize_EIChannels, 2U,
        &EE3CL4_Lab_DW.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(EE3CL4_Lab_M, _rt_error_message);
        return;
      }
    }

    if ((EE3CL4_Lab_P.HILInitialize_OOStart && !is_switching) ||
        (EE3CL4_Lab_P.HILInitialize_OOEnter && is_switching)) {
      result = hil_write_other(EE3CL4_Lab_DW.HILInitialize_Card,
        EE3CL4_Lab_P.HILInitialize_OOChannels, 3U,
        EE3CL4_Lab_P.HILInitialize_OOInitial);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(EE3CL4_Lab_M, _rt_error_message);
        return;
      }
    }

    if (EE3CL4_Lab_P.HILInitialize_OOReset) {
      result = hil_watchdog_set_other_expiration_state
        (EE3CL4_Lab_DW.HILInitialize_Card, EE3CL4_Lab_P.HILInitialize_OOChannels,
         3U, EE3CL4_Lab_P.HILInitialize_OOWatchdog);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(EE3CL4_Lab_M, _rt_error_message);
        return;
      }
    }
  }

  /* Start for DiscretePulseGenerator: '<Root>/Pulse Generator' */
  EE3CL4_Lab_DW.clockTickCounter = 0;
}

/* Model terminate function */
void EE3CL4_Lab_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: EE3CL4_Lab/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    t_uint32 num_final_digital_outputs = 0;
    t_uint32 num_final_other_outputs = 0;
    hil_task_stop_all(EE3CL4_Lab_DW.HILInitialize_Card);
    hil_monitor_stop_all(EE3CL4_Lab_DW.HILInitialize_Card);
    is_switching = false;
    if ((EE3CL4_Lab_P.HILInitialize_AOTerminate && !is_switching) ||
        (EE3CL4_Lab_P.HILInitialize_AOExit && is_switching)) {
      num_final_analog_outputs = 1U;
    } else {
      num_final_analog_outputs = 0;
    }

    if ((EE3CL4_Lab_P.HILInitialize_DOTerminate && !is_switching) ||
        (EE3CL4_Lab_P.HILInitialize_DOExit && is_switching)) {
      num_final_digital_outputs = 1U;
    } else {
      num_final_digital_outputs = 0;
    }

    if ((EE3CL4_Lab_P.HILInitialize_OOTerminate && !is_switching) ||
        (EE3CL4_Lab_P.HILInitialize_OOExit && is_switching)) {
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
      result = hil_write(EE3CL4_Lab_DW.HILInitialize_Card
                         , &EE3CL4_Lab_P.HILInitialize_AOChannels,
                         num_final_analog_outputs
                         , NULL, 0
                         , &EE3CL4_Lab_P.HILInitialize_DOChannels,
                         num_final_digital_outputs
                         , EE3CL4_Lab_P.HILInitialize_OOChannels,
                         num_final_other_outputs
                         , &EE3CL4_Lab_P.HILInitialize_AOFinal
                         , NULL
                         , (t_boolean *) &EE3CL4_Lab_P.HILInitialize_DOFinal
                         , EE3CL4_Lab_P.HILInitialize_OOFinal
                         );
      if (result == -QERR_HIL_WRITE_NOT_SUPPORTED) {
        t_error local_result;
        result = 0;

        /* The hil_write operation is not supported by this card. Write final outputs for each channel type */
        if (num_final_analog_outputs > 0) {
          local_result = hil_write_analog(EE3CL4_Lab_DW.HILInitialize_Card,
            &EE3CL4_Lab_P.HILInitialize_AOChannels, num_final_analog_outputs,
            &EE3CL4_Lab_P.HILInitialize_AOFinal);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_digital_outputs > 0) {
          local_result = hil_write_digital(EE3CL4_Lab_DW.HILInitialize_Card,
            &EE3CL4_Lab_P.HILInitialize_DOChannels, num_final_digital_outputs,
            (t_boolean *) &EE3CL4_Lab_P.HILInitialize_DOFinal);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_other_outputs > 0) {
          local_result = hil_write_other(EE3CL4_Lab_DW.HILInitialize_Card,
            EE3CL4_Lab_P.HILInitialize_OOChannels, num_final_other_outputs,
            EE3CL4_Lab_P.HILInitialize_OOFinal);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(EE3CL4_Lab_M, _rt_error_message);
        }
      }
    }

    hil_task_delete_all(EE3CL4_Lab_DW.HILInitialize_Card);
    hil_monitor_delete_all(EE3CL4_Lab_DW.HILInitialize_Card);
    hil_close(EE3CL4_Lab_DW.HILInitialize_Card);
    EE3CL4_Lab_DW.HILInitialize_Card = NULL;
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  EE3CL4_Lab_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  EE3CL4_Lab_update();
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
  EE3CL4_Lab_initialize();
}

void MdlTerminate(void)
{
  EE3CL4_Lab_terminate();
}

/* Registration function */
RT_MODEL_EE3CL4_Lab_T *EE3CL4_Lab(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)EE3CL4_Lab_M, 0,
                sizeof(RT_MODEL_EE3CL4_Lab_T));

  /* Initialize timing info */
  {
    int_T *mdlTsMap = EE3CL4_Lab_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;

    /* polyspace +2 MISRA2012:D4.1 [Justified:Low] "EE3CL4_Lab_M points to
       static memory which is guaranteed to be non-NULL" */
    EE3CL4_Lab_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    EE3CL4_Lab_M->Timing.sampleTimes = (&EE3CL4_Lab_M->Timing.sampleTimesArray[0]);
    EE3CL4_Lab_M->Timing.offsetTimes = (&EE3CL4_Lab_M->Timing.offsetTimesArray[0]);

    /* task periods */
    EE3CL4_Lab_M->Timing.sampleTimes[0] = (0.002);

    /* task offsets */
    EE3CL4_Lab_M->Timing.offsetTimes[0] = (0.0);
  }

  rtmSetTPtr(EE3CL4_Lab_M, &EE3CL4_Lab_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = EE3CL4_Lab_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    EE3CL4_Lab_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(EE3CL4_Lab_M, 6.0);
  EE3CL4_Lab_M->Timing.stepSize0 = 0.002;

  /* External mode info */
  EE3CL4_Lab_M->Sizes.checksums[0] = (3395190157U);
  EE3CL4_Lab_M->Sizes.checksums[1] = (3835633984U);
  EE3CL4_Lab_M->Sizes.checksums[2] = (587922128U);
  EE3CL4_Lab_M->Sizes.checksums[3] = (645736332U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    EE3CL4_Lab_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(EE3CL4_Lab_M->extModeInfo,
      &EE3CL4_Lab_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(EE3CL4_Lab_M->extModeInfo, EE3CL4_Lab_M->Sizes.checksums);
    rteiSetTPtr(EE3CL4_Lab_M->extModeInfo, rtmGetTPtr(EE3CL4_Lab_M));
  }

  EE3CL4_Lab_M->solverInfoPtr = (&EE3CL4_Lab_M->solverInfo);
  EE3CL4_Lab_M->Timing.stepSize = (0.002);
  rtsiSetFixedStepSize(&EE3CL4_Lab_M->solverInfo, 0.002);
  rtsiSetSolverMode(&EE3CL4_Lab_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  EE3CL4_Lab_M->blockIO = ((void *) &EE3CL4_Lab_B);
  (void) memset(((void *) &EE3CL4_Lab_B), 0,
                sizeof(B_EE3CL4_Lab_T));

  /* parameters */
  EE3CL4_Lab_M->defaultParam = ((real_T *)&EE3CL4_Lab_P);

  /* states (dwork) */
  EE3CL4_Lab_M->dwork = ((void *) &EE3CL4_Lab_DW);
  (void) memset((void *)&EE3CL4_Lab_DW, 0,
                sizeof(DW_EE3CL4_Lab_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    EE3CL4_Lab_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 20;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  EE3CL4_Lab_M->Sizes.numContStates = (0);/* Number of continuous states */
  EE3CL4_Lab_M->Sizes.numY = (0);      /* Number of model outputs */
  EE3CL4_Lab_M->Sizes.numU = (0);      /* Number of model inputs */
  EE3CL4_Lab_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  EE3CL4_Lab_M->Sizes.numSampTimes = (1);/* Number of sample times */
  EE3CL4_Lab_M->Sizes.numBlocks = (9); /* Number of blocks */
  EE3CL4_Lab_M->Sizes.numBlockIO = (1);/* Number of block outputs */
  EE3CL4_Lab_M->Sizes.numBlockPrms = (86);/* Sum of parameter "widths" */
  return EE3CL4_Lab_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
