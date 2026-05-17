    function targMap = targDataMap(),

    ;%***********************
    ;% Create Parameter Map *
    ;%***********************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 5;
        sectIdxOffset = 0;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc paramMap
        ;%
        paramMap.nSections           = nTotSects;
        paramMap.sectIdxOffset       = sectIdxOffset;
            paramMap.sections(nTotSects) = dumSection; %prealloc
        paramMap.nTotData            = -1;

        ;%
        ;% Auto data (EE3CL4_Lab2_Exp2_P)
        ;%
            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% EE3CL4_Lab2_Exp2_P.readmotorencoder_channels
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% EE3CL4_Lab2_Exp2_P.sendsignaltomotor_channels
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            paramMap.sections(1) = section;
            clear section

            section.nData     = 25;
            section.data(25)  = dumData; %prealloc

                    ;% EE3CL4_Lab2_Exp2_P.HILInitialize_OOTerminate
                    section.data(1).logicalSrcIdx = 2;
                    section.data(1).dtTransOffset = 0;

                    ;% EE3CL4_Lab2_Exp2_P.HILInitialize_OOExit
                    section.data(2).logicalSrcIdx = 3;
                    section.data(2).dtTransOffset = 1;

                    ;% EE3CL4_Lab2_Exp2_P.HILInitialize_OOStart
                    section.data(3).logicalSrcIdx = 4;
                    section.data(3).dtTransOffset = 2;

                    ;% EE3CL4_Lab2_Exp2_P.HILInitialize_OOEnter
                    section.data(4).logicalSrcIdx = 5;
                    section.data(4).dtTransOffset = 3;

                    ;% EE3CL4_Lab2_Exp2_P.HILInitialize_AOFinal
                    section.data(5).logicalSrcIdx = 6;
                    section.data(5).dtTransOffset = 4;

                    ;% EE3CL4_Lab2_Exp2_P.HILInitialize_POFinal
                    section.data(6).logicalSrcIdx = 7;
                    section.data(6).dtTransOffset = 5;

                    ;% EE3CL4_Lab2_Exp2_P.HILInitialize_OOFinal
                    section.data(7).logicalSrcIdx = 8;
                    section.data(7).dtTransOffset = 6;

                    ;% EE3CL4_Lab2_Exp2_P.HILInitialize_AIHigh
                    section.data(8).logicalSrcIdx = 9;
                    section.data(8).dtTransOffset = 9;

                    ;% EE3CL4_Lab2_Exp2_P.HILInitialize_AILow
                    section.data(9).logicalSrcIdx = 10;
                    section.data(9).dtTransOffset = 10;

                    ;% EE3CL4_Lab2_Exp2_P.HILInitialize_AOHigh
                    section.data(10).logicalSrcIdx = 11;
                    section.data(10).dtTransOffset = 11;

                    ;% EE3CL4_Lab2_Exp2_P.HILInitialize_AOLow
                    section.data(11).logicalSrcIdx = 12;
                    section.data(11).dtTransOffset = 12;

                    ;% EE3CL4_Lab2_Exp2_P.HILInitialize_AOInitial
                    section.data(12).logicalSrcIdx = 13;
                    section.data(12).dtTransOffset = 13;

                    ;% EE3CL4_Lab2_Exp2_P.HILInitialize_AOWatchdog
                    section.data(13).logicalSrcIdx = 14;
                    section.data(13).dtTransOffset = 14;

                    ;% EE3CL4_Lab2_Exp2_P.HILInitialize_POFrequency
                    section.data(14).logicalSrcIdx = 15;
                    section.data(14).dtTransOffset = 15;

                    ;% EE3CL4_Lab2_Exp2_P.HILInitialize_POLeading
                    section.data(15).logicalSrcIdx = 16;
                    section.data(15).dtTransOffset = 16;

                    ;% EE3CL4_Lab2_Exp2_P.HILInitialize_POTrailing
                    section.data(16).logicalSrcIdx = 17;
                    section.data(16).dtTransOffset = 17;

                    ;% EE3CL4_Lab2_Exp2_P.HILInitialize_POInitial
                    section.data(17).logicalSrcIdx = 18;
                    section.data(17).dtTransOffset = 18;

                    ;% EE3CL4_Lab2_Exp2_P.HILInitialize_OOInitial
                    section.data(18).logicalSrcIdx = 19;
                    section.data(18).dtTransOffset = 19;

                    ;% EE3CL4_Lab2_Exp2_P.HILInitialize_OOWatchdog
                    section.data(19).logicalSrcIdx = 20;
                    section.data(19).dtTransOffset = 22;

                    ;% EE3CL4_Lab2_Exp2_P.counttorad_Gain
                    section.data(20).logicalSrcIdx = 21;
                    section.data(20).dtTransOffset = 25;

                    ;% EE3CL4_Lab2_Exp2_P.SineWave_Amp
                    section.data(21).logicalSrcIdx = 22;
                    section.data(21).dtTransOffset = 26;

                    ;% EE3CL4_Lab2_Exp2_P.SineWave_Bias
                    section.data(22).logicalSrcIdx = 23;
                    section.data(22).dtTransOffset = 27;

                    ;% EE3CL4_Lab2_Exp2_P.SineWave_Freq
                    section.data(23).logicalSrcIdx = 24;
                    section.data(23).dtTransOffset = 28;

                    ;% EE3CL4_Lab2_Exp2_P.SineWave_Phase
                    section.data(24).logicalSrcIdx = 25;
                    section.data(24).dtTransOffset = 29;

                    ;% EE3CL4_Lab2_Exp2_P.proportionalcontroller_Gain
                    section.data(25).logicalSrcIdx = 26;
                    section.data(25).dtTransOffset = 30;

            nTotData = nTotData + section.nData;
            paramMap.sections(2) = section;
            clear section

            section.nData     = 7;
            section.data(7)  = dumData; %prealloc

                    ;% EE3CL4_Lab2_Exp2_P.HILInitialize_CKChannels
                    section.data(1).logicalSrcIdx = 27;
                    section.data(1).dtTransOffset = 0;

                    ;% EE3CL4_Lab2_Exp2_P.HILInitialize_DOWatchdog
                    section.data(2).logicalSrcIdx = 28;
                    section.data(2).dtTransOffset = 1;

                    ;% EE3CL4_Lab2_Exp2_P.HILInitialize_EIInitial
                    section.data(3).logicalSrcIdx = 29;
                    section.data(3).dtTransOffset = 2;

                    ;% EE3CL4_Lab2_Exp2_P.HILInitialize_POModes
                    section.data(4).logicalSrcIdx = 30;
                    section.data(4).dtTransOffset = 3;

                    ;% EE3CL4_Lab2_Exp2_P.HILInitialize_POConfiguration
                    section.data(5).logicalSrcIdx = 31;
                    section.data(5).dtTransOffset = 4;

                    ;% EE3CL4_Lab2_Exp2_P.HILInitialize_POAlignment
                    section.data(6).logicalSrcIdx = 32;
                    section.data(6).dtTransOffset = 5;

                    ;% EE3CL4_Lab2_Exp2_P.HILInitialize_POPolarity
                    section.data(7).logicalSrcIdx = 33;
                    section.data(7).dtTransOffset = 6;

            nTotData = nTotData + section.nData;
            paramMap.sections(3) = section;
            clear section

            section.nData     = 6;
            section.data(6)  = dumData; %prealloc

                    ;% EE3CL4_Lab2_Exp2_P.HILInitialize_AIChannels
                    section.data(1).logicalSrcIdx = 34;
                    section.data(1).dtTransOffset = 0;

                    ;% EE3CL4_Lab2_Exp2_P.HILInitialize_AOChannels
                    section.data(2).logicalSrcIdx = 35;
                    section.data(2).dtTransOffset = 1;

                    ;% EE3CL4_Lab2_Exp2_P.HILInitialize_DOChannels
                    section.data(3).logicalSrcIdx = 36;
                    section.data(3).dtTransOffset = 2;

                    ;% EE3CL4_Lab2_Exp2_P.HILInitialize_EIChannels
                    section.data(4).logicalSrcIdx = 37;
                    section.data(4).dtTransOffset = 3;

                    ;% EE3CL4_Lab2_Exp2_P.HILInitialize_EIQuadrature
                    section.data(5).logicalSrcIdx = 38;
                    section.data(5).dtTransOffset = 5;

                    ;% EE3CL4_Lab2_Exp2_P.HILInitialize_OOChannels
                    section.data(6).logicalSrcIdx = 39;
                    section.data(6).dtTransOffset = 6;

            nTotData = nTotData + section.nData;
            paramMap.sections(4) = section;
            clear section

            section.nData     = 37;
            section.data(37)  = dumData; %prealloc

                    ;% EE3CL4_Lab2_Exp2_P.HILInitialize_Active
                    section.data(1).logicalSrcIdx = 40;
                    section.data(1).dtTransOffset = 0;

                    ;% EE3CL4_Lab2_Exp2_P.HILInitialize_AOTerminate
                    section.data(2).logicalSrcIdx = 41;
                    section.data(2).dtTransOffset = 1;

                    ;% EE3CL4_Lab2_Exp2_P.HILInitialize_AOExit
                    section.data(3).logicalSrcIdx = 42;
                    section.data(3).dtTransOffset = 2;

                    ;% EE3CL4_Lab2_Exp2_P.HILInitialize_DOTerminate
                    section.data(4).logicalSrcIdx = 43;
                    section.data(4).dtTransOffset = 3;

                    ;% EE3CL4_Lab2_Exp2_P.HILInitialize_DOExit
                    section.data(5).logicalSrcIdx = 44;
                    section.data(5).dtTransOffset = 4;

                    ;% EE3CL4_Lab2_Exp2_P.HILInitialize_POTerminate
                    section.data(6).logicalSrcIdx = 45;
                    section.data(6).dtTransOffset = 5;

                    ;% EE3CL4_Lab2_Exp2_P.HILInitialize_POExit
                    section.data(7).logicalSrcIdx = 46;
                    section.data(7).dtTransOffset = 6;

                    ;% EE3CL4_Lab2_Exp2_P.HILInitialize_CKPStart
                    section.data(8).logicalSrcIdx = 47;
                    section.data(8).dtTransOffset = 7;

                    ;% EE3CL4_Lab2_Exp2_P.HILInitialize_CKPEnter
                    section.data(9).logicalSrcIdx = 48;
                    section.data(9).dtTransOffset = 8;

                    ;% EE3CL4_Lab2_Exp2_P.HILInitialize_CKStart
                    section.data(10).logicalSrcIdx = 49;
                    section.data(10).dtTransOffset = 9;

                    ;% EE3CL4_Lab2_Exp2_P.HILInitialize_CKEnter
                    section.data(11).logicalSrcIdx = 50;
                    section.data(11).dtTransOffset = 10;

                    ;% EE3CL4_Lab2_Exp2_P.HILInitialize_AIPStart
                    section.data(12).logicalSrcIdx = 51;
                    section.data(12).dtTransOffset = 11;

                    ;% EE3CL4_Lab2_Exp2_P.HILInitialize_AIPEnter
                    section.data(13).logicalSrcIdx = 52;
                    section.data(13).dtTransOffset = 12;

                    ;% EE3CL4_Lab2_Exp2_P.HILInitialize_AOPStart
                    section.data(14).logicalSrcIdx = 53;
                    section.data(14).dtTransOffset = 13;

                    ;% EE3CL4_Lab2_Exp2_P.HILInitialize_AOPEnter
                    section.data(15).logicalSrcIdx = 54;
                    section.data(15).dtTransOffset = 14;

                    ;% EE3CL4_Lab2_Exp2_P.HILInitialize_AOStart
                    section.data(16).logicalSrcIdx = 55;
                    section.data(16).dtTransOffset = 15;

                    ;% EE3CL4_Lab2_Exp2_P.HILInitialize_AOEnter
                    section.data(17).logicalSrcIdx = 56;
                    section.data(17).dtTransOffset = 16;

                    ;% EE3CL4_Lab2_Exp2_P.HILInitialize_AOReset
                    section.data(18).logicalSrcIdx = 57;
                    section.data(18).dtTransOffset = 17;

                    ;% EE3CL4_Lab2_Exp2_P.HILInitialize_DOPStart
                    section.data(19).logicalSrcIdx = 58;
                    section.data(19).dtTransOffset = 18;

                    ;% EE3CL4_Lab2_Exp2_P.HILInitialize_DOPEnter
                    section.data(20).logicalSrcIdx = 59;
                    section.data(20).dtTransOffset = 19;

                    ;% EE3CL4_Lab2_Exp2_P.HILInitialize_DOStart
                    section.data(21).logicalSrcIdx = 60;
                    section.data(21).dtTransOffset = 20;

                    ;% EE3CL4_Lab2_Exp2_P.HILInitialize_DOEnter
                    section.data(22).logicalSrcIdx = 61;
                    section.data(22).dtTransOffset = 21;

                    ;% EE3CL4_Lab2_Exp2_P.HILInitialize_DOReset
                    section.data(23).logicalSrcIdx = 62;
                    section.data(23).dtTransOffset = 22;

                    ;% EE3CL4_Lab2_Exp2_P.HILInitialize_EIPStart
                    section.data(24).logicalSrcIdx = 63;
                    section.data(24).dtTransOffset = 23;

                    ;% EE3CL4_Lab2_Exp2_P.HILInitialize_EIPEnter
                    section.data(25).logicalSrcIdx = 64;
                    section.data(25).dtTransOffset = 24;

                    ;% EE3CL4_Lab2_Exp2_P.HILInitialize_EIStart
                    section.data(26).logicalSrcIdx = 65;
                    section.data(26).dtTransOffset = 25;

                    ;% EE3CL4_Lab2_Exp2_P.HILInitialize_EIEnter
                    section.data(27).logicalSrcIdx = 66;
                    section.data(27).dtTransOffset = 26;

                    ;% EE3CL4_Lab2_Exp2_P.HILInitialize_POPStart
                    section.data(28).logicalSrcIdx = 67;
                    section.data(28).dtTransOffset = 27;

                    ;% EE3CL4_Lab2_Exp2_P.HILInitialize_POPEnter
                    section.data(29).logicalSrcIdx = 68;
                    section.data(29).dtTransOffset = 28;

                    ;% EE3CL4_Lab2_Exp2_P.HILInitialize_POStart
                    section.data(30).logicalSrcIdx = 69;
                    section.data(30).dtTransOffset = 29;

                    ;% EE3CL4_Lab2_Exp2_P.HILInitialize_POEnter
                    section.data(31).logicalSrcIdx = 70;
                    section.data(31).dtTransOffset = 30;

                    ;% EE3CL4_Lab2_Exp2_P.HILInitialize_POReset
                    section.data(32).logicalSrcIdx = 71;
                    section.data(32).dtTransOffset = 31;

                    ;% EE3CL4_Lab2_Exp2_P.HILInitialize_OOReset
                    section.data(33).logicalSrcIdx = 72;
                    section.data(33).dtTransOffset = 32;

                    ;% EE3CL4_Lab2_Exp2_P.HILInitialize_DOFinal
                    section.data(34).logicalSrcIdx = 73;
                    section.data(34).dtTransOffset = 33;

                    ;% EE3CL4_Lab2_Exp2_P.HILInitialize_DOInitial
                    section.data(35).logicalSrcIdx = 74;
                    section.data(35).dtTransOffset = 34;

                    ;% EE3CL4_Lab2_Exp2_P.readmotorencoder_Active
                    section.data(36).logicalSrcIdx = 75;
                    section.data(36).dtTransOffset = 35;

                    ;% EE3CL4_Lab2_Exp2_P.sendsignaltomotor_Active
                    section.data(37).logicalSrcIdx = 76;
                    section.data(37).dtTransOffset = 36;

            nTotData = nTotData + section.nData;
            paramMap.sections(5) = section;
            clear section


            ;%
            ;% Non-auto Data (parameter)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        paramMap.nTotData = nTotData;



    ;%**************************
    ;% Create Block Output Map *
    ;%**************************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 1;
        sectIdxOffset = 0;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc sigMap
        ;%
        sigMap.nSections           = nTotSects;
        sigMap.sectIdxOffset       = sectIdxOffset;
            sigMap.sections(nTotSects) = dumSection; %prealloc
        sigMap.nTotData            = -1;

        ;%
        ;% Auto data (EE3CL4_Lab2_Exp2_B)
        ;%
            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% EE3CL4_Lab2_Exp2_B.counttorad
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% EE3CL4_Lab2_Exp2_B.proportionalcontroller
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            sigMap.sections(1) = section;
            clear section


            ;%
            ;% Non-auto Data (signal)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        sigMap.nTotData = nTotData;



    ;%*******************
    ;% Create DWork Map *
    ;%*******************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 4;
        sectIdxOffset = 1;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc dworkMap
        ;%
        dworkMap.nSections           = nTotSects;
        dworkMap.sectIdxOffset       = sectIdxOffset;
            dworkMap.sections(nTotSects) = dumSection; %prealloc
        dworkMap.nTotData            = -1;

        ;%
        ;% Auto data (EE3CL4_Lab2_Exp2_DW)
        ;%
            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% EE3CL4_Lab2_Exp2_DW.HILInitialize_FilterFrequency
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(1) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% EE3CL4_Lab2_Exp2_DW.HILInitialize_Card
                    section.data(1).logicalSrcIdx = 1;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(2) = section;
            clear section

            section.nData     = 4;
            section.data(4)  = dumData; %prealloc

                    ;% EE3CL4_Lab2_Exp2_DW.readmotorencoder_PWORK
                    section.data(1).logicalSrcIdx = 2;
                    section.data(1).dtTransOffset = 0;

                    ;% EE3CL4_Lab2_Exp2_DW.ToWorkspace_PWORK.LoggedData
                    section.data(2).logicalSrcIdx = 3;
                    section.data(2).dtTransOffset = 1;

                    ;% EE3CL4_Lab2_Exp2_DW.actualposition_PWORK.LoggedData
                    section.data(3).logicalSrcIdx = 4;
                    section.data(3).dtTransOffset = 2;

                    ;% EE3CL4_Lab2_Exp2_DW.sendsignaltomotor_PWORK
                    section.data(4).logicalSrcIdx = 5;
                    section.data(4).dtTransOffset = 3;

            nTotData = nTotData + section.nData;
            dworkMap.sections(3) = section;
            clear section

            section.nData     = 5;
            section.data(5)  = dumData; %prealloc

                    ;% EE3CL4_Lab2_Exp2_DW.HILInitialize_ClockModes
                    section.data(1).logicalSrcIdx = 6;
                    section.data(1).dtTransOffset = 0;

                    ;% EE3CL4_Lab2_Exp2_DW.HILInitialize_DOStates
                    section.data(2).logicalSrcIdx = 7;
                    section.data(2).dtTransOffset = 1;

                    ;% EE3CL4_Lab2_Exp2_DW.HILInitialize_QuadratureModes
                    section.data(3).logicalSrcIdx = 8;
                    section.data(3).dtTransOffset = 2;

                    ;% EE3CL4_Lab2_Exp2_DW.HILInitialize_InitialEICounts
                    section.data(4).logicalSrcIdx = 9;
                    section.data(4).dtTransOffset = 4;

                    ;% EE3CL4_Lab2_Exp2_DW.readmotorencoder_Buffer
                    section.data(5).logicalSrcIdx = 10;
                    section.data(5).dtTransOffset = 6;

            nTotData = nTotData + section.nData;
            dworkMap.sections(4) = section;
            clear section


            ;%
            ;% Non-auto Data (dwork)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        dworkMap.nTotData = nTotData;



    ;%
    ;% Add individual maps to base struct.
    ;%

    targMap.paramMap  = paramMap;
    targMap.signalMap = sigMap;
    targMap.dworkMap  = dworkMap;

    ;%
    ;% Add checksums to base struct.
    ;%


    targMap.checksum0 = 2075487389;
    targMap.checksum1 = 1248363255;
    targMap.checksum2 = 3977383655;
    targMap.checksum3 = 1254086516;

