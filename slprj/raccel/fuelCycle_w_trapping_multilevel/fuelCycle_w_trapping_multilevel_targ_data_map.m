    function targMap = targDataMap(),

    ;%***********************
    ;% Create Parameter Map *
    ;%***********************
    
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
        ;% Init/prealloc paramMap
        ;%
        paramMap.nSections           = nTotSects;
        paramMap.sectIdxOffset       = sectIdxOffset;
            paramMap.sections(nTotSects) = dumSection; %prealloc
        paramMap.nTotData            = -1;

        ;%
        ;% Auto data (rtP)
        ;%
            section.nData     = 103;
            section.data(103)  = dumData; %prealloc

                    ;% rtP.AF
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% rtP.A_0
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% rtP.E_annealing
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 2;

                    ;% rtP.I_s_0
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 3;

                    ;% rtP.M_structural
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 4;

                    ;% rtP.M_tungsten
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 5;

                    ;% rtP.N_dot
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 6;

                    ;% rtP.PM_structural
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 7;

                    ;% rtP.PM_tritium
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 8;

                    ;% rtP.PM_tungsten
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 9;

                    ;% rtP.T1
                    section.data(11).logicalSrcIdx = 10;
                    section.data(11).dtTransOffset = 10;

                    ;% rtP.T12
                    section.data(12).logicalSrcIdx = 11;
                    section.data(12).dtTransOffset = 11;

                    ;% rtP.T2
                    section.data(13).logicalSrcIdx = 12;
                    section.data(13).dtTransOffset = 12;

                    ;% rtP.T3
                    section.data(14).logicalSrcIdx = 13;
                    section.data(14).dtTransOffset = 13;

                    ;% rtP.T4
                    section.data(15).logicalSrcIdx = 14;
                    section.data(15).dtTransOffset = 14;

                    ;% rtP.T5
                    section.data(16).logicalSrcIdx = 15;
                    section.data(16).dtTransOffset = 15;

                    ;% rtP.T6
                    section.data(17).logicalSrcIdx = 16;
                    section.data(17).dtTransOffset = 16;

                    ;% rtP.T7
                    section.data(18).logicalSrcIdx = 17;
                    section.data(18).dtTransOffset = 17;

                    ;% rtP.T8
                    section.data(19).logicalSrcIdx = 18;
                    section.data(19).dtTransOffset = 18;

                    ;% rtP.T9
                    section.data(20).logicalSrcIdx = 19;
                    section.data(20).dtTransOffset = 19;

                    ;% rtP.TBE
                    section.data(21).logicalSrcIdx = 20;
                    section.data(21).dtTransOffset = 20;

                    ;% rtP.TBR
                    section.data(22).logicalSrcIdx = 21;
                    section.data(22).dtTransOffset = 21;

                    ;% rtP.T_replacement
                    section.data(23).logicalSrcIdx = 22;
                    section.data(23).dtTransOffset = 22;

                    ;% rtP.T_tungsten
                    section.data(24).logicalSrcIdx = 23;
                    section.data(24).dtTransOffset = 23;

                    ;% rtP.damage_rate
                    section.data(25).logicalSrcIdx = 24;
                    section.data(25).dtTransOffset = 24;

                    ;% rtP.eta2
                    section.data(26).logicalSrcIdx = 25;
                    section.data(26).dtTransOffset = 25;

                    ;% rtP.f51
                    section.data(27).logicalSrcIdx = 26;
                    section.data(27).dtTransOffset = 26;

                    ;% rtP.f53
                    section.data(28).logicalSrcIdx = 27;
                    section.data(28).dtTransOffset = 27;

                    ;% rtP.f54
                    section.data(29).logicalSrcIdx = 28;
                    section.data(29).dtTransOffset = 28;

                    ;% rtP.f56
                    section.data(30).logicalSrcIdx = 29;
                    section.data(30).dtTransOffset = 29;

                    ;% rtP.f96
                    section.data(31).logicalSrcIdx = 30;
                    section.data(31).dtTransOffset = 30;

                    ;% rtP.f_dir
                    section.data(32).logicalSrcIdx = 31;
                    section.data(32).dtTransOffset = 31;

                    ;% rtP.fp3
                    section.data(33).logicalSrcIdx = 32;
                    section.data(33).dtTransOffset = 32;

                    ;% rtP.fp4
                    section.data(34).logicalSrcIdx = 33;
                    section.data(34).dtTransOffset = 33;

                    ;% rtP.k_B
                    section.data(35).logicalSrcIdx = 34;
                    section.data(35).dtTransOffset = 34;

                    ;% rtP.lambda
                    section.data(36).logicalSrcIdx = 35;
                    section.data(36).dtTransOffset = 35;

                    ;% rtP.n_solute_structural
                    section.data(37).logicalSrcIdx = 36;
                    section.data(37).dtTransOffset = 36;

                    ;% rtP.n_solute_tungsten
                    section.data(38).logicalSrcIdx = 37;
                    section.data(38).dtTransOffset = 37;

                    ;% rtP.n_trap_structural
                    section.data(39).logicalSrcIdx = 38;
                    section.data(39).dtTransOffset = 38;

                    ;% rtP.n_trap_tungsten_intrinsic
                    section.data(40).logicalSrcIdx = 39;
                    section.data(40).dtTransOffset = 39;

                    ;% rtP.n_tungsten
                    section.data(41).logicalSrcIdx = 40;
                    section.data(41).dtTransOffset = 40;

                    ;% rtP.n_tungsten_max
                    section.data(42).logicalSrcIdx = 41;
                    section.data(42).dtTransOffset = 41;

                    ;% rtP.tau1
                    section.data(43).logicalSrcIdx = 42;
                    section.data(43).dtTransOffset = 45;

                    ;% rtP.tau12
                    section.data(44).logicalSrcIdx = 43;
                    section.data(44).dtTransOffset = 46;

                    ;% rtP.tau2
                    section.data(45).logicalSrcIdx = 44;
                    section.data(45).dtTransOffset = 47;

                    ;% rtP.tau3
                    section.data(46).logicalSrcIdx = 45;
                    section.data(46).dtTransOffset = 48;

                    ;% rtP.tau4
                    section.data(47).logicalSrcIdx = 46;
                    section.data(47).dtTransOffset = 49;

                    ;% rtP.tau5
                    section.data(48).logicalSrcIdx = 47;
                    section.data(48).dtTransOffset = 50;

                    ;% rtP.tau6
                    section.data(49).logicalSrcIdx = 48;
                    section.data(49).dtTransOffset = 51;

                    ;% rtP.tau7
                    section.data(50).logicalSrcIdx = 49;
                    section.data(50).dtTransOffset = 52;

                    ;% rtP.tau8
                    section.data(51).logicalSrcIdx = 50;
                    section.data(51).dtTransOffset = 53;

                    ;% rtP.tau9
                    section.data(52).logicalSrcIdx = 51;
                    section.data(52).dtTransOffset = 54;

                    ;% rtP.tau_detrap_structural
                    section.data(53).logicalSrcIdx = 52;
                    section.data(53).dtTransOffset = 55;

                    ;% rtP.tau_detrap_tungsten
                    section.data(54).logicalSrcIdx = 53;
                    section.data(54).dtTransOffset = 56;

                    ;% rtP.tau_trap_structural
                    section.data(55).logicalSrcIdx = 54;
                    section.data(55).dtTransOffset = 61;

                    ;% rtP.tau_trap_tungsten
                    section.data(56).logicalSrcIdx = 55;
                    section.data(56).dtTransOffset = 62;

                    ;% rtP.trap_creation_factor_W
                    section.data(57).logicalSrcIdx = 56;
                    section.data(57).dtTransOffset = 63;

                    ;% rtP.trap_density_A_0
                    section.data(58).logicalSrcIdx = 57;
                    section.data(58).dtTransOffset = 67;

                    ;% rtP.trap_density_E_annealing
                    section.data(59).logicalSrcIdx = 58;
                    section.data(59).dtTransOffset = 68;

                    ;% rtP.trap_density_T_material
                    section.data(60).logicalSrcIdx = 59;
                    section.data(60).dtTransOffset = 69;

                    ;% rtP.trap_density_damage_rate
                    section.data(61).logicalSrcIdx = 60;
                    section.data(61).dtTransOffset = 70;

                    ;% rtP.trap_density_n_max
                    section.data(62).logicalSrcIdx = 61;
                    section.data(62).dtTransOffset = 71;

                    ;% rtP.Integrator_IC
                    section.data(63).logicalSrcIdx = 62;
                    section.data(63).dtTransOffset = 72;

                    ;% rtP.Integrator_IC_gjn51xvom5
                    section.data(64).logicalSrcIdx = 63;
                    section.data(64).dtTransOffset = 73;

                    ;% rtP.Integrator_IC_mry3mue1xt
                    section.data(65).logicalSrcIdx = 64;
                    section.data(65).dtTransOffset = 74;

                    ;% rtP.Integrator_IC_lv4yux4fd2
                    section.data(66).logicalSrcIdx = 65;
                    section.data(66).dtTransOffset = 75;

                    ;% rtP.Integrator_IC_gsmhqvj2p2
                    section.data(67).logicalSrcIdx = 66;
                    section.data(67).dtTransOffset = 76;

                    ;% rtP.Integrator_IC_guilf0dsxs
                    section.data(68).logicalSrcIdx = 67;
                    section.data(68).dtTransOffset = 77;

                    ;% rtP.Integrator_IC_aoe5ma2bpt
                    section.data(69).logicalSrcIdx = 68;
                    section.data(69).dtTransOffset = 78;

                    ;% rtP.Integrator_IC_ln32mnhczm
                    section.data(70).logicalSrcIdx = 69;
                    section.data(70).dtTransOffset = 79;

                    ;% rtP.Integrator_IC_pzvlozo2nc
                    section.data(71).logicalSrcIdx = 70;
                    section.data(71).dtTransOffset = 80;

                    ;% rtP.Integrator_IC_fznpj504vt
                    section.data(72).logicalSrcIdx = 71;
                    section.data(72).dtTransOffset = 81;

                    ;% rtP.Integrator1_IC
                    section.data(73).logicalSrcIdx = 72;
                    section.data(73).dtTransOffset = 82;

                    ;% rtP.Integrator1_IC_bjh1younxk
                    section.data(74).logicalSrcIdx = 73;
                    section.data(74).dtTransOffset = 83;

                    ;% rtP.Integrator1_IC_luy00dmifv
                    section.data(75).logicalSrcIdx = 74;
                    section.data(75).dtTransOffset = 84;

                    ;% rtP.Integrator1_IC_hfd0yebv3k
                    section.data(76).logicalSrcIdx = 75;
                    section.data(76).dtTransOffset = 85;

                    ;% rtP.Integrator1_IC_apqnwc35ax
                    section.data(77).logicalSrcIdx = 76;
                    section.data(77).dtTransOffset = 86;

                    ;% rtP.PulseGenerator_Period
                    section.data(78).logicalSrcIdx = 77;
                    section.data(78).dtTransOffset = 87;

                    ;% rtP.PulseGenerator_PhaseDelay
                    section.data(79).logicalSrcIdx = 78;
                    section.data(79).dtTransOffset = 88;

                    ;% rtP.Integrator_IC_kcrxo3wege
                    section.data(80).logicalSrcIdx = 79;
                    section.data(80).dtTransOffset = 89;

                    ;% rtP.Integrator_IC_iauzmgwt3b
                    section.data(81).logicalSrcIdx = 80;
                    section.data(81).dtTransOffset = 90;

                    ;% rtP.Integrator_IC_bfdxoyeb45
                    section.data(82).logicalSrcIdx = 81;
                    section.data(82).dtTransOffset = 91;

                    ;% rtP.Integrator_IC_hsgeimv2ra
                    section.data(83).logicalSrcIdx = 82;
                    section.data(83).dtTransOffset = 92;

                    ;% rtP.Integrator1_IC_i02smi320p
                    section.data(84).logicalSrcIdx = 83;
                    section.data(84).dtTransOffset = 93;

                    ;% rtP.Integrator1_IC_nfzhle1k50
                    section.data(85).logicalSrcIdx = 84;
                    section.data(85).dtTransOffset = 94;

                    ;% rtP.Integrator1_IC_p02hk220lo
                    section.data(86).logicalSrcIdx = 85;
                    section.data(86).dtTransOffset = 95;

                    ;% rtP.Integrator1_IC_oqtjqencln
                    section.data(87).logicalSrcIdx = 86;
                    section.data(87).dtTransOffset = 96;

                    ;% rtP.Integrator1_IC_lccyfk1lmn
                    section.data(88).logicalSrcIdx = 87;
                    section.data(88).dtTransOffset = 97;

                    ;% rtP.PulseGenerator_Period_mwqel1dvmq
                    section.data(89).logicalSrcIdx = 88;
                    section.data(89).dtTransOffset = 98;

                    ;% rtP.PulseGenerator_PhaseDelay_k0s5cgqn5u
                    section.data(90).logicalSrcIdx = 89;
                    section.data(90).dtTransOffset = 99;

                    ;% rtP.Integrator_IC_p0pugwgzsn
                    section.data(91).logicalSrcIdx = 90;
                    section.data(91).dtTransOffset = 100;

                    ;% rtP.Integrator_IC_lmncc23ueu
                    section.data(92).logicalSrcIdx = 91;
                    section.data(92).dtTransOffset = 101;

                    ;% rtP.Integrator_IC_nchr54klbk
                    section.data(93).logicalSrcIdx = 92;
                    section.data(93).dtTransOffset = 102;

                    ;% rtP.Integrator_IC_jrf030n4yu
                    section.data(94).logicalSrcIdx = 93;
                    section.data(94).dtTransOffset = 103;

                    ;% rtP.Integrator1_IC_caj4cloteg
                    section.data(95).logicalSrcIdx = 94;
                    section.data(95).dtTransOffset = 104;

                    ;% rtP.Integrator_IC_prbytjhtp3
                    section.data(96).logicalSrcIdx = 95;
                    section.data(96).dtTransOffset = 105;

                    ;% rtP.Integrator1_IC_m4ot5s3dkq
                    section.data(97).logicalSrcIdx = 96;
                    section.data(97).dtTransOffset = 106;

                    ;% rtP.PulseGenerator_Period_mpnlrkwdty
                    section.data(98).logicalSrcIdx = 97;
                    section.data(98).dtTransOffset = 107;

                    ;% rtP.PulseGenerator_PhaseDelay_emic4rw15d
                    section.data(99).logicalSrcIdx = 98;
                    section.data(99).dtTransOffset = 108;

                    ;% rtP.PulseGenerator_Period_d0fefccnsl
                    section.data(100).logicalSrcIdx = 99;
                    section.data(100).dtTransOffset = 109;

                    ;% rtP.PulseGenerator_PhaseDelay_dcsuc5mmvs
                    section.data(101).logicalSrcIdx = 100;
                    section.data(101).dtTransOffset = 110;

                    ;% rtP.PulseGenerator_Period_f2wfzoa3qm
                    section.data(102).logicalSrcIdx = 101;
                    section.data(102).dtTransOffset = 111;

                    ;% rtP.PulseGenerator_PhaseDelay_oegmxwaov1
                    section.data(103).logicalSrcIdx = 102;
                    section.data(103).dtTransOffset = 112;

            nTotData = nTotData + section.nData;
            paramMap.sections(1) = section;
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
        ;% Auto data (rtB)
        ;%
            section.nData     = 219;
            section.data(219)  = dumData; %prealloc

                    ;% rtB.iiiwxuggrg
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% rtB.nf4zcvrrw1
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% rtB.fvf3nbzioe
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 2;

                    ;% rtB.k4b4lf14vj
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 3;

                    ;% rtB.etvkdwnkpj
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 4;

                    ;% rtB.psuxlzsuxz
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 5;

                    ;% rtB.ebk01qyesg
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 6;

                    ;% rtB.idcpjxrtqy
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 7;

                    ;% rtB.iajp4d0mcl
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 8;

                    ;% rtB.osbfg4zlct
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 9;

                    ;% rtB.eqaeyezh1s
                    section.data(11).logicalSrcIdx = 10;
                    section.data(11).dtTransOffset = 10;

                    ;% rtB.csnrgnegvo
                    section.data(12).logicalSrcIdx = 11;
                    section.data(12).dtTransOffset = 11;

                    ;% rtB.b2vzo0hy2s
                    section.data(13).logicalSrcIdx = 12;
                    section.data(13).dtTransOffset = 12;

                    ;% rtB.eqm2qb1xmg
                    section.data(14).logicalSrcIdx = 13;
                    section.data(14).dtTransOffset = 13;

                    ;% rtB.osty4w0h40
                    section.data(15).logicalSrcIdx = 14;
                    section.data(15).dtTransOffset = 14;

                    ;% rtB.hpv03qx2eh
                    section.data(16).logicalSrcIdx = 15;
                    section.data(16).dtTransOffset = 15;

                    ;% rtB.owkrxvvxqg
                    section.data(17).logicalSrcIdx = 16;
                    section.data(17).dtTransOffset = 16;

                    ;% rtB.oee1351fty
                    section.data(18).logicalSrcIdx = 17;
                    section.data(18).dtTransOffset = 17;

                    ;% rtB.lrc5riqsm0
                    section.data(19).logicalSrcIdx = 18;
                    section.data(19).dtTransOffset = 18;

                    ;% rtB.gti1d5wxoc
                    section.data(20).logicalSrcIdx = 19;
                    section.data(20).dtTransOffset = 19;

                    ;% rtB.bohvfvgygo
                    section.data(21).logicalSrcIdx = 20;
                    section.data(21).dtTransOffset = 20;

                    ;% rtB.cg5lpoodm2
                    section.data(22).logicalSrcIdx = 21;
                    section.data(22).dtTransOffset = 21;

                    ;% rtB.niogfz3nzj
                    section.data(23).logicalSrcIdx = 22;
                    section.data(23).dtTransOffset = 22;

                    ;% rtB.cpciqgvd1i
                    section.data(24).logicalSrcIdx = 23;
                    section.data(24).dtTransOffset = 23;

                    ;% rtB.ixhq3mtynq
                    section.data(25).logicalSrcIdx = 24;
                    section.data(25).dtTransOffset = 24;

                    ;% rtB.aciokmkyoi
                    section.data(26).logicalSrcIdx = 25;
                    section.data(26).dtTransOffset = 25;

                    ;% rtB.fgstkpld00
                    section.data(27).logicalSrcIdx = 26;
                    section.data(27).dtTransOffset = 26;

                    ;% rtB.c2macncjx1
                    section.data(28).logicalSrcIdx = 27;
                    section.data(28).dtTransOffset = 27;

                    ;% rtB.gvzulll142
                    section.data(29).logicalSrcIdx = 28;
                    section.data(29).dtTransOffset = 28;

                    ;% rtB.dzzfskofco
                    section.data(30).logicalSrcIdx = 29;
                    section.data(30).dtTransOffset = 29;

                    ;% rtB.hdb3kkl1an
                    section.data(31).logicalSrcIdx = 30;
                    section.data(31).dtTransOffset = 30;

                    ;% rtB.hdfhl1b201
                    section.data(32).logicalSrcIdx = 31;
                    section.data(32).dtTransOffset = 31;

                    ;% rtB.jyxotbfmiy
                    section.data(33).logicalSrcIdx = 32;
                    section.data(33).dtTransOffset = 32;

                    ;% rtB.fni551xrky
                    section.data(34).logicalSrcIdx = 33;
                    section.data(34).dtTransOffset = 33;

                    ;% rtB.i5gekqrszk
                    section.data(35).logicalSrcIdx = 34;
                    section.data(35).dtTransOffset = 34;

                    ;% rtB.opvsbdmt4f
                    section.data(36).logicalSrcIdx = 35;
                    section.data(36).dtTransOffset = 35;

                    ;% rtB.f4qjawxtxc
                    section.data(37).logicalSrcIdx = 36;
                    section.data(37).dtTransOffset = 36;

                    ;% rtB.b4o0mwd5s1
                    section.data(38).logicalSrcIdx = 37;
                    section.data(38).dtTransOffset = 37;

                    ;% rtB.ibntl0qzrn
                    section.data(39).logicalSrcIdx = 38;
                    section.data(39).dtTransOffset = 38;

                    ;% rtB.eoyhxc3y5c
                    section.data(40).logicalSrcIdx = 39;
                    section.data(40).dtTransOffset = 39;

                    ;% rtB.fqf2ig4ozo
                    section.data(41).logicalSrcIdx = 40;
                    section.data(41).dtTransOffset = 40;

                    ;% rtB.pylqoentdj
                    section.data(42).logicalSrcIdx = 41;
                    section.data(42).dtTransOffset = 41;

                    ;% rtB.cph5fceo1k
                    section.data(43).logicalSrcIdx = 42;
                    section.data(43).dtTransOffset = 42;

                    ;% rtB.dqaeumpfwq
                    section.data(44).logicalSrcIdx = 43;
                    section.data(44).dtTransOffset = 43;

                    ;% rtB.oz2ioyl1d1
                    section.data(45).logicalSrcIdx = 44;
                    section.data(45).dtTransOffset = 44;

                    ;% rtB.kldtvssa3v
                    section.data(46).logicalSrcIdx = 45;
                    section.data(46).dtTransOffset = 45;

                    ;% rtB.dssu0124ca
                    section.data(47).logicalSrcIdx = 46;
                    section.data(47).dtTransOffset = 46;

                    ;% rtB.jubael0s5t
                    section.data(48).logicalSrcIdx = 47;
                    section.data(48).dtTransOffset = 47;

                    ;% rtB.imvzvxfth1
                    section.data(49).logicalSrcIdx = 48;
                    section.data(49).dtTransOffset = 48;

                    ;% rtB.hhlfdxq4tq
                    section.data(50).logicalSrcIdx = 49;
                    section.data(50).dtTransOffset = 49;

                    ;% rtB.lv3saiokkc
                    section.data(51).logicalSrcIdx = 50;
                    section.data(51).dtTransOffset = 50;

                    ;% rtB.mmzzdny3gv
                    section.data(52).logicalSrcIdx = 51;
                    section.data(52).dtTransOffset = 51;

                    ;% rtB.bxhcn03bs3
                    section.data(53).logicalSrcIdx = 52;
                    section.data(53).dtTransOffset = 52;

                    ;% rtB.jw1mkvjqxd
                    section.data(54).logicalSrcIdx = 53;
                    section.data(54).dtTransOffset = 53;

                    ;% rtB.ap4ejq14cx
                    section.data(55).logicalSrcIdx = 54;
                    section.data(55).dtTransOffset = 54;

                    ;% rtB.d11crs30zx
                    section.data(56).logicalSrcIdx = 55;
                    section.data(56).dtTransOffset = 55;

                    ;% rtB.pkusgmygp4
                    section.data(57).logicalSrcIdx = 56;
                    section.data(57).dtTransOffset = 56;

                    ;% rtB.o3mlawuzsu
                    section.data(58).logicalSrcIdx = 57;
                    section.data(58).dtTransOffset = 57;

                    ;% rtB.klulqzlxhy
                    section.data(59).logicalSrcIdx = 58;
                    section.data(59).dtTransOffset = 58;

                    ;% rtB.mg2xxgovdn
                    section.data(60).logicalSrcIdx = 59;
                    section.data(60).dtTransOffset = 59;

                    ;% rtB.nh1yusewyx
                    section.data(61).logicalSrcIdx = 60;
                    section.data(61).dtTransOffset = 60;

                    ;% rtB.mq55kovd3p
                    section.data(62).logicalSrcIdx = 61;
                    section.data(62).dtTransOffset = 61;

                    ;% rtB.ffijpdjagp
                    section.data(63).logicalSrcIdx = 62;
                    section.data(63).dtTransOffset = 62;

                    ;% rtB.clohbn4dfr
                    section.data(64).logicalSrcIdx = 63;
                    section.data(64).dtTransOffset = 63;

                    ;% rtB.jtu2fng3ej
                    section.data(65).logicalSrcIdx = 64;
                    section.data(65).dtTransOffset = 64;

                    ;% rtB.fybyalbgb2
                    section.data(66).logicalSrcIdx = 65;
                    section.data(66).dtTransOffset = 65;

                    ;% rtB.k3yjc0yg3g
                    section.data(67).logicalSrcIdx = 66;
                    section.data(67).dtTransOffset = 66;

                    ;% rtB.p2krjfpfgh
                    section.data(68).logicalSrcIdx = 67;
                    section.data(68).dtTransOffset = 67;

                    ;% rtB.gtcb3jdxp3
                    section.data(69).logicalSrcIdx = 68;
                    section.data(69).dtTransOffset = 68;

                    ;% rtB.l0llkpzm13
                    section.data(70).logicalSrcIdx = 69;
                    section.data(70).dtTransOffset = 69;

                    ;% rtB.ciffbyucrp
                    section.data(71).logicalSrcIdx = 70;
                    section.data(71).dtTransOffset = 70;

                    ;% rtB.mtsxpijwck
                    section.data(72).logicalSrcIdx = 71;
                    section.data(72).dtTransOffset = 71;

                    ;% rtB.kab2nly4jj
                    section.data(73).logicalSrcIdx = 72;
                    section.data(73).dtTransOffset = 72;

                    ;% rtB.ow3uqqg2aj
                    section.data(74).logicalSrcIdx = 73;
                    section.data(74).dtTransOffset = 73;

                    ;% rtB.ciw3n3wmul
                    section.data(75).logicalSrcIdx = 74;
                    section.data(75).dtTransOffset = 74;

                    ;% rtB.jjs4ssptlk
                    section.data(76).logicalSrcIdx = 75;
                    section.data(76).dtTransOffset = 75;

                    ;% rtB.mug54mzksq
                    section.data(77).logicalSrcIdx = 76;
                    section.data(77).dtTransOffset = 76;

                    ;% rtB.cpkkbsqjby
                    section.data(78).logicalSrcIdx = 77;
                    section.data(78).dtTransOffset = 77;

                    ;% rtB.h1pesm521l
                    section.data(79).logicalSrcIdx = 78;
                    section.data(79).dtTransOffset = 78;

                    ;% rtB.mrg2inxnui
                    section.data(80).logicalSrcIdx = 79;
                    section.data(80).dtTransOffset = 79;

                    ;% rtB.f3bngaj4zp
                    section.data(81).logicalSrcIdx = 80;
                    section.data(81).dtTransOffset = 80;

                    ;% rtB.ees2bp2bzh
                    section.data(82).logicalSrcIdx = 81;
                    section.data(82).dtTransOffset = 81;

                    ;% rtB.m34nqp4n5z
                    section.data(83).logicalSrcIdx = 82;
                    section.data(83).dtTransOffset = 82;

                    ;% rtB.ky32tdgwev
                    section.data(84).logicalSrcIdx = 83;
                    section.data(84).dtTransOffset = 83;

                    ;% rtB.icsnarysuk
                    section.data(85).logicalSrcIdx = 84;
                    section.data(85).dtTransOffset = 84;

                    ;% rtB.l1mbg2lxtf
                    section.data(86).logicalSrcIdx = 85;
                    section.data(86).dtTransOffset = 85;

                    ;% rtB.jjz3f2w1ww
                    section.data(87).logicalSrcIdx = 86;
                    section.data(87).dtTransOffset = 86;

                    ;% rtB.ebsdotywiy
                    section.data(88).logicalSrcIdx = 87;
                    section.data(88).dtTransOffset = 87;

                    ;% rtB.kmllksrcpg
                    section.data(89).logicalSrcIdx = 88;
                    section.data(89).dtTransOffset = 88;

                    ;% rtB.dlpsaa4wne
                    section.data(90).logicalSrcIdx = 89;
                    section.data(90).dtTransOffset = 89;

                    ;% rtB.ew51x2a0pq
                    section.data(91).logicalSrcIdx = 90;
                    section.data(91).dtTransOffset = 90;

                    ;% rtB.h0g0vscc5a
                    section.data(92).logicalSrcIdx = 91;
                    section.data(92).dtTransOffset = 91;

                    ;% rtB.emvjgmkgqb
                    section.data(93).logicalSrcIdx = 92;
                    section.data(93).dtTransOffset = 92;

                    ;% rtB.f2htpqh3ht
                    section.data(94).logicalSrcIdx = 93;
                    section.data(94).dtTransOffset = 93;

                    ;% rtB.nh2mkz0gux
                    section.data(95).logicalSrcIdx = 94;
                    section.data(95).dtTransOffset = 94;

                    ;% rtB.mklt5qpuqz
                    section.data(96).logicalSrcIdx = 95;
                    section.data(96).dtTransOffset = 95;

                    ;% rtB.iip1ojxipj
                    section.data(97).logicalSrcIdx = 96;
                    section.data(97).dtTransOffset = 96;

                    ;% rtB.hirm4x5pho
                    section.data(98).logicalSrcIdx = 97;
                    section.data(98).dtTransOffset = 97;

                    ;% rtB.h0nudpvspr
                    section.data(99).logicalSrcIdx = 98;
                    section.data(99).dtTransOffset = 98;

                    ;% rtB.jofuuncwgf
                    section.data(100).logicalSrcIdx = 99;
                    section.data(100).dtTransOffset = 99;

                    ;% rtB.mfsnnr03g3
                    section.data(101).logicalSrcIdx = 100;
                    section.data(101).dtTransOffset = 100;

                    ;% rtB.ax2athfpkk
                    section.data(102).logicalSrcIdx = 101;
                    section.data(102).dtTransOffset = 101;

                    ;% rtB.hyj42o3iuz
                    section.data(103).logicalSrcIdx = 102;
                    section.data(103).dtTransOffset = 102;

                    ;% rtB.kkb5zwrqmi
                    section.data(104).logicalSrcIdx = 103;
                    section.data(104).dtTransOffset = 103;

                    ;% rtB.ehw2zbw0iw
                    section.data(105).logicalSrcIdx = 104;
                    section.data(105).dtTransOffset = 104;

                    ;% rtB.jpn42chgkq
                    section.data(106).logicalSrcIdx = 105;
                    section.data(106).dtTransOffset = 105;

                    ;% rtB.bzgkngokio
                    section.data(107).logicalSrcIdx = 106;
                    section.data(107).dtTransOffset = 106;

                    ;% rtB.noa4ncpcn2
                    section.data(108).logicalSrcIdx = 107;
                    section.data(108).dtTransOffset = 107;

                    ;% rtB.d5nn4kjojo
                    section.data(109).logicalSrcIdx = 108;
                    section.data(109).dtTransOffset = 108;

                    ;% rtB.h2up4wt3zu
                    section.data(110).logicalSrcIdx = 109;
                    section.data(110).dtTransOffset = 109;

                    ;% rtB.dxfhrl5haj
                    section.data(111).logicalSrcIdx = 110;
                    section.data(111).dtTransOffset = 110;

                    ;% rtB.k1rudquzn3
                    section.data(112).logicalSrcIdx = 111;
                    section.data(112).dtTransOffset = 111;

                    ;% rtB.ntb3nynmn0
                    section.data(113).logicalSrcIdx = 112;
                    section.data(113).dtTransOffset = 112;

                    ;% rtB.ocbiqwo1jy
                    section.data(114).logicalSrcIdx = 113;
                    section.data(114).dtTransOffset = 113;

                    ;% rtB.bc0o2qz0ty
                    section.data(115).logicalSrcIdx = 114;
                    section.data(115).dtTransOffset = 114;

                    ;% rtB.koz3fa4yyj
                    section.data(116).logicalSrcIdx = 115;
                    section.data(116).dtTransOffset = 115;

                    ;% rtB.eja2c4jp5c
                    section.data(117).logicalSrcIdx = 116;
                    section.data(117).dtTransOffset = 116;

                    ;% rtB.cidmzevvxk
                    section.data(118).logicalSrcIdx = 117;
                    section.data(118).dtTransOffset = 117;

                    ;% rtB.guydscbpbh
                    section.data(119).logicalSrcIdx = 118;
                    section.data(119).dtTransOffset = 118;

                    ;% rtB.dktkpw1bhi
                    section.data(120).logicalSrcIdx = 119;
                    section.data(120).dtTransOffset = 119;

                    ;% rtB.kgob5xrqph
                    section.data(121).logicalSrcIdx = 120;
                    section.data(121).dtTransOffset = 120;

                    ;% rtB.fkha0sace3
                    section.data(122).logicalSrcIdx = 121;
                    section.data(122).dtTransOffset = 121;

                    ;% rtB.jivx3sbmm4
                    section.data(123).logicalSrcIdx = 122;
                    section.data(123).dtTransOffset = 122;

                    ;% rtB.ftazg5c0fu
                    section.data(124).logicalSrcIdx = 123;
                    section.data(124).dtTransOffset = 123;

                    ;% rtB.mzhqvdifiz
                    section.data(125).logicalSrcIdx = 124;
                    section.data(125).dtTransOffset = 124;

                    ;% rtB.edivwoqmoy
                    section.data(126).logicalSrcIdx = 125;
                    section.data(126).dtTransOffset = 125;

                    ;% rtB.fd5fpby1xt
                    section.data(127).logicalSrcIdx = 126;
                    section.data(127).dtTransOffset = 126;

                    ;% rtB.ochdwrnmss
                    section.data(128).logicalSrcIdx = 127;
                    section.data(128).dtTransOffset = 127;

                    ;% rtB.dzeqvdtusv
                    section.data(129).logicalSrcIdx = 128;
                    section.data(129).dtTransOffset = 128;

                    ;% rtB.cpbzlxsa4z
                    section.data(130).logicalSrcIdx = 129;
                    section.data(130).dtTransOffset = 129;

                    ;% rtB.pn0u52zpkg
                    section.data(131).logicalSrcIdx = 130;
                    section.data(131).dtTransOffset = 130;

                    ;% rtB.kk4oglgrgt
                    section.data(132).logicalSrcIdx = 131;
                    section.data(132).dtTransOffset = 131;

                    ;% rtB.d3fgwuvnry
                    section.data(133).logicalSrcIdx = 132;
                    section.data(133).dtTransOffset = 132;

                    ;% rtB.kwpcxbpmca
                    section.data(134).logicalSrcIdx = 133;
                    section.data(134).dtTransOffset = 133;

                    ;% rtB.cu0edalrlz
                    section.data(135).logicalSrcIdx = 134;
                    section.data(135).dtTransOffset = 134;

                    ;% rtB.eycob2wxh3
                    section.data(136).logicalSrcIdx = 135;
                    section.data(136).dtTransOffset = 135;

                    ;% rtB.exrud042ox
                    section.data(137).logicalSrcIdx = 136;
                    section.data(137).dtTransOffset = 136;

                    ;% rtB.bzj35bjr4u
                    section.data(138).logicalSrcIdx = 137;
                    section.data(138).dtTransOffset = 137;

                    ;% rtB.dna4jmsata
                    section.data(139).logicalSrcIdx = 138;
                    section.data(139).dtTransOffset = 138;

                    ;% rtB.gnyiwna5cn
                    section.data(140).logicalSrcIdx = 139;
                    section.data(140).dtTransOffset = 139;

                    ;% rtB.eu0tusin0r
                    section.data(141).logicalSrcIdx = 140;
                    section.data(141).dtTransOffset = 140;

                    ;% rtB.oyn54nojeb
                    section.data(142).logicalSrcIdx = 141;
                    section.data(142).dtTransOffset = 141;

                    ;% rtB.efehig0u42
                    section.data(143).logicalSrcIdx = 142;
                    section.data(143).dtTransOffset = 142;

                    ;% rtB.btsm5i54nc
                    section.data(144).logicalSrcIdx = 143;
                    section.data(144).dtTransOffset = 143;

                    ;% rtB.mrdniw23zs
                    section.data(145).logicalSrcIdx = 144;
                    section.data(145).dtTransOffset = 144;

                    ;% rtB.bg3da3n0wb
                    section.data(146).logicalSrcIdx = 145;
                    section.data(146).dtTransOffset = 145;

                    ;% rtB.k0hgu4xe0f
                    section.data(147).logicalSrcIdx = 146;
                    section.data(147).dtTransOffset = 146;

                    ;% rtB.d1yia3o3xe
                    section.data(148).logicalSrcIdx = 147;
                    section.data(148).dtTransOffset = 147;

                    ;% rtB.hepvlmbt4i
                    section.data(149).logicalSrcIdx = 148;
                    section.data(149).dtTransOffset = 148;

                    ;% rtB.hbyxmtmphz
                    section.data(150).logicalSrcIdx = 149;
                    section.data(150).dtTransOffset = 149;

                    ;% rtB.pnzergluua
                    section.data(151).logicalSrcIdx = 150;
                    section.data(151).dtTransOffset = 150;

                    ;% rtB.knfus34vwq
                    section.data(152).logicalSrcIdx = 151;
                    section.data(152).dtTransOffset = 151;

                    ;% rtB.pmgkqaam2i
                    section.data(153).logicalSrcIdx = 152;
                    section.data(153).dtTransOffset = 152;

                    ;% rtB.lwmqjnrld0
                    section.data(154).logicalSrcIdx = 153;
                    section.data(154).dtTransOffset = 153;

                    ;% rtB.jc55rsew1w
                    section.data(155).logicalSrcIdx = 154;
                    section.data(155).dtTransOffset = 154;

                    ;% rtB.k5203dxgbx
                    section.data(156).logicalSrcIdx = 155;
                    section.data(156).dtTransOffset = 155;

                    ;% rtB.nj0umut5gp
                    section.data(157).logicalSrcIdx = 156;
                    section.data(157).dtTransOffset = 156;

                    ;% rtB.fo1qcnd3al
                    section.data(158).logicalSrcIdx = 157;
                    section.data(158).dtTransOffset = 157;

                    ;% rtB.i5zgf04o3x
                    section.data(159).logicalSrcIdx = 158;
                    section.data(159).dtTransOffset = 158;

                    ;% rtB.d04wog3ps1
                    section.data(160).logicalSrcIdx = 159;
                    section.data(160).dtTransOffset = 159;

                    ;% rtB.grykhheeys
                    section.data(161).logicalSrcIdx = 160;
                    section.data(161).dtTransOffset = 160;

                    ;% rtB.krfvi4cflh
                    section.data(162).logicalSrcIdx = 161;
                    section.data(162).dtTransOffset = 161;

                    ;% rtB.gqgfxwccv4
                    section.data(163).logicalSrcIdx = 162;
                    section.data(163).dtTransOffset = 162;

                    ;% rtB.lel3phg0r1
                    section.data(164).logicalSrcIdx = 163;
                    section.data(164).dtTransOffset = 163;

                    ;% rtB.jsspycell1
                    section.data(165).logicalSrcIdx = 164;
                    section.data(165).dtTransOffset = 164;

                    ;% rtB.pfdj2j3kbo
                    section.data(166).logicalSrcIdx = 165;
                    section.data(166).dtTransOffset = 165;

                    ;% rtB.ateto3w1pm
                    section.data(167).logicalSrcIdx = 166;
                    section.data(167).dtTransOffset = 166;

                    ;% rtB.mb335ejyey
                    section.data(168).logicalSrcIdx = 167;
                    section.data(168).dtTransOffset = 167;

                    ;% rtB.lteedkhhy3
                    section.data(169).logicalSrcIdx = 168;
                    section.data(169).dtTransOffset = 168;

                    ;% rtB.oa1gustxiq
                    section.data(170).logicalSrcIdx = 169;
                    section.data(170).dtTransOffset = 169;

                    ;% rtB.fruoe5r5t3
                    section.data(171).logicalSrcIdx = 170;
                    section.data(171).dtTransOffset = 170;

                    ;% rtB.ixcgdfbffk
                    section.data(172).logicalSrcIdx = 171;
                    section.data(172).dtTransOffset = 171;

                    ;% rtB.jzmkioa5k1
                    section.data(173).logicalSrcIdx = 172;
                    section.data(173).dtTransOffset = 172;

                    ;% rtB.miby44ssmo
                    section.data(174).logicalSrcIdx = 173;
                    section.data(174).dtTransOffset = 173;

                    ;% rtB.dozduzanyp
                    section.data(175).logicalSrcIdx = 174;
                    section.data(175).dtTransOffset = 174;

                    ;% rtB.cetoh1esws
                    section.data(176).logicalSrcIdx = 175;
                    section.data(176).dtTransOffset = 175;

                    ;% rtB.ffp2uq1eay
                    section.data(177).logicalSrcIdx = 176;
                    section.data(177).dtTransOffset = 176;

                    ;% rtB.kyfaz2mb1x
                    section.data(178).logicalSrcIdx = 177;
                    section.data(178).dtTransOffset = 177;

                    ;% rtB.ku24anqdmm
                    section.data(179).logicalSrcIdx = 178;
                    section.data(179).dtTransOffset = 178;

                    ;% rtB.ozrmr5adg2
                    section.data(180).logicalSrcIdx = 179;
                    section.data(180).dtTransOffset = 179;

                    ;% rtB.iqsukc15fj
                    section.data(181).logicalSrcIdx = 180;
                    section.data(181).dtTransOffset = 180;

                    ;% rtB.kl5lj4yyqc
                    section.data(182).logicalSrcIdx = 181;
                    section.data(182).dtTransOffset = 181;

                    ;% rtB.ghlblpxsfm
                    section.data(183).logicalSrcIdx = 182;
                    section.data(183).dtTransOffset = 182;

                    ;% rtB.ennagfiv25
                    section.data(184).logicalSrcIdx = 183;
                    section.data(184).dtTransOffset = 183;

                    ;% rtB.cj00le33zn
                    section.data(185).logicalSrcIdx = 184;
                    section.data(185).dtTransOffset = 184;

                    ;% rtB.dj24yjdkk0
                    section.data(186).logicalSrcIdx = 185;
                    section.data(186).dtTransOffset = 185;

                    ;% rtB.enuxhkywvm
                    section.data(187).logicalSrcIdx = 186;
                    section.data(187).dtTransOffset = 186;

                    ;% rtB.gvsnodzuaj
                    section.data(188).logicalSrcIdx = 187;
                    section.data(188).dtTransOffset = 187;

                    ;% rtB.ki5rpihgmh
                    section.data(189).logicalSrcIdx = 188;
                    section.data(189).dtTransOffset = 188;

                    ;% rtB.fs1oeicixp
                    section.data(190).logicalSrcIdx = 189;
                    section.data(190).dtTransOffset = 189;

                    ;% rtB.cszo5vy5h3
                    section.data(191).logicalSrcIdx = 190;
                    section.data(191).dtTransOffset = 190;

                    ;% rtB.cqrhrhc1sq
                    section.data(192).logicalSrcIdx = 191;
                    section.data(192).dtTransOffset = 191;

                    ;% rtB.je4cbmtlt4
                    section.data(193).logicalSrcIdx = 192;
                    section.data(193).dtTransOffset = 192;

                    ;% rtB.brlwqytyds
                    section.data(194).logicalSrcIdx = 193;
                    section.data(194).dtTransOffset = 193;

                    ;% rtB.mhjkxa1meq
                    section.data(195).logicalSrcIdx = 194;
                    section.data(195).dtTransOffset = 194;

                    ;% rtB.ooku50enka
                    section.data(196).logicalSrcIdx = 195;
                    section.data(196).dtTransOffset = 195;

                    ;% rtB.iirvitebr2
                    section.data(197).logicalSrcIdx = 196;
                    section.data(197).dtTransOffset = 196;

                    ;% rtB.ki4tl0rbga
                    section.data(198).logicalSrcIdx = 197;
                    section.data(198).dtTransOffset = 197;

                    ;% rtB.lgyyr12kek
                    section.data(199).logicalSrcIdx = 198;
                    section.data(199).dtTransOffset = 198;

                    ;% rtB.ohvaeydtca
                    section.data(200).logicalSrcIdx = 199;
                    section.data(200).dtTransOffset = 199;

                    ;% rtB.fkwpmfy3ic
                    section.data(201).logicalSrcIdx = 200;
                    section.data(201).dtTransOffset = 200;

                    ;% rtB.ojyufdjynv
                    section.data(202).logicalSrcIdx = 201;
                    section.data(202).dtTransOffset = 201;

                    ;% rtB.bmkrxgfo2l
                    section.data(203).logicalSrcIdx = 202;
                    section.data(203).dtTransOffset = 202;

                    ;% rtB.m2fionkrn0
                    section.data(204).logicalSrcIdx = 203;
                    section.data(204).dtTransOffset = 203;

                    ;% rtB.gcmv4lfn4n
                    section.data(205).logicalSrcIdx = 204;
                    section.data(205).dtTransOffset = 204;

                    ;% rtB.kdkynqxxwq
                    section.data(206).logicalSrcIdx = 205;
                    section.data(206).dtTransOffset = 205;

                    ;% rtB.fgkaot3e42
                    section.data(207).logicalSrcIdx = 206;
                    section.data(207).dtTransOffset = 206;

                    ;% rtB.mwmx0yzb4f
                    section.data(208).logicalSrcIdx = 207;
                    section.data(208).dtTransOffset = 207;

                    ;% rtB.ogv1c0tddw
                    section.data(209).logicalSrcIdx = 208;
                    section.data(209).dtTransOffset = 208;

                    ;% rtB.cy3t3xxpoy
                    section.data(210).logicalSrcIdx = 209;
                    section.data(210).dtTransOffset = 209;

                    ;% rtB.a3i0ozq14p
                    section.data(211).logicalSrcIdx = 210;
                    section.data(211).dtTransOffset = 210;

                    ;% rtB.dxel3zbjrm
                    section.data(212).logicalSrcIdx = 211;
                    section.data(212).dtTransOffset = 211;

                    ;% rtB.opybz520jx
                    section.data(213).logicalSrcIdx = 212;
                    section.data(213).dtTransOffset = 212;

                    ;% rtB.cmf1wo0hiz
                    section.data(214).logicalSrcIdx = 213;
                    section.data(214).dtTransOffset = 213;

                    ;% rtB.jsvjvkl4fq
                    section.data(215).logicalSrcIdx = 214;
                    section.data(215).dtTransOffset = 214;

                    ;% rtB.h1j1ahvfhl
                    section.data(216).logicalSrcIdx = 215;
                    section.data(216).dtTransOffset = 215;

                    ;% rtB.ae20paxfcr
                    section.data(217).logicalSrcIdx = 216;
                    section.data(217).dtTransOffset = 216;

                    ;% rtB.iayqmj4rue
                    section.data(218).logicalSrcIdx = 217;
                    section.data(218).dtTransOffset = 217;

                    ;% rtB.n4io0wcopq
                    section.data(219).logicalSrcIdx = 218;
                    section.data(219).dtTransOffset = 218;

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
        ;% Auto data (rtDW)
        ;%
            section.nData     = 5;
            section.data(5)  = dumData; %prealloc

                    ;% rtDW.jbfemjfqdu
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.h2l1jz22tz
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% rtDW.pqedya33bp
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 2;

                    ;% rtDW.dmxo1ux3qp
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 3;

                    ;% rtDW.ffcbwyd3ut
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 4;

            nTotData = nTotData + section.nData;
            dworkMap.sections(1) = section;
            clear section

            section.nData     = 5;
            section.data(5)  = dumData; %prealloc

                    ;% rtDW.b0dld00fnu
                    section.data(1).logicalSrcIdx = 5;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.hmy2bsk3ta
                    section.data(2).logicalSrcIdx = 6;
                    section.data(2).dtTransOffset = 1;

                    ;% rtDW.lhoaby1ffk
                    section.data(3).logicalSrcIdx = 7;
                    section.data(3).dtTransOffset = 2;

                    ;% rtDW.c5wtluimqm
                    section.data(4).logicalSrcIdx = 8;
                    section.data(4).dtTransOffset = 3;

                    ;% rtDW.olc1lgjia0
                    section.data(5).logicalSrcIdx = 9;
                    section.data(5).dtTransOffset = 4;

            nTotData = nTotData + section.nData;
            dworkMap.sections(2) = section;
            clear section

            section.nData     = 51;
            section.data(51)  = dumData; %prealloc

                    ;% rtDW.jxsf3xpnit.LoggedData
                    section.data(1).logicalSrcIdx = 10;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.cmbe2a5ker.LoggedData
                    section.data(2).logicalSrcIdx = 11;
                    section.data(2).dtTransOffset = 1;

                    ;% rtDW.gt130sbvyf.LoggedData
                    section.data(3).logicalSrcIdx = 12;
                    section.data(3).dtTransOffset = 2;

                    ;% rtDW.m0ivdqq1ds.LoggedData
                    section.data(4).logicalSrcIdx = 13;
                    section.data(4).dtTransOffset = 3;

                    ;% rtDW.bpvydpjffg.AQHandles
                    section.data(5).logicalSrcIdx = 14;
                    section.data(5).dtTransOffset = 4;

                    ;% rtDW.bfgk1czl4m.AQHandles
                    section.data(6).logicalSrcIdx = 15;
                    section.data(6).dtTransOffset = 5;

                    ;% rtDW.ja1ege25yh.AQHandles
                    section.data(7).logicalSrcIdx = 16;
                    section.data(7).dtTransOffset = 6;

                    ;% rtDW.dn0qqupwms.AQHandles
                    section.data(8).logicalSrcIdx = 17;
                    section.data(8).dtTransOffset = 7;

                    ;% rtDW.in2jxpqlzw.AQHandles
                    section.data(9).logicalSrcIdx = 18;
                    section.data(9).dtTransOffset = 8;

                    ;% rtDW.phht5zmf24.AQHandles
                    section.data(10).logicalSrcIdx = 19;
                    section.data(10).dtTransOffset = 9;

                    ;% rtDW.g1upx2ora0.AQHandles
                    section.data(11).logicalSrcIdx = 20;
                    section.data(11).dtTransOffset = 10;

                    ;% rtDW.gb53i5u3uk.AQHandles
                    section.data(12).logicalSrcIdx = 21;
                    section.data(12).dtTransOffset = 11;

                    ;% rtDW.e0iok5rpsx.AQHandles
                    section.data(13).logicalSrcIdx = 22;
                    section.data(13).dtTransOffset = 12;

                    ;% rtDW.bvdj0li5qv.AQHandles
                    section.data(14).logicalSrcIdx = 23;
                    section.data(14).dtTransOffset = 13;

                    ;% rtDW.ohawovjfhh.AQHandles
                    section.data(15).logicalSrcIdx = 24;
                    section.data(15).dtTransOffset = 14;

                    ;% rtDW.ofgcg2rwnf.AQHandles
                    section.data(16).logicalSrcIdx = 25;
                    section.data(16).dtTransOffset = 15;

                    ;% rtDW.lxy40zsik3.AQHandles
                    section.data(17).logicalSrcIdx = 26;
                    section.data(17).dtTransOffset = 16;

                    ;% rtDW.lr5q5utmxh.AQHandles
                    section.data(18).logicalSrcIdx = 27;
                    section.data(18).dtTransOffset = 17;

                    ;% rtDW.ojaixcrugo.AQHandles
                    section.data(19).logicalSrcIdx = 28;
                    section.data(19).dtTransOffset = 18;

                    ;% rtDW.jhnokpp1dp.AQHandles
                    section.data(20).logicalSrcIdx = 29;
                    section.data(20).dtTransOffset = 19;

                    ;% rtDW.iohckarwzg.AQHandles
                    section.data(21).logicalSrcIdx = 30;
                    section.data(21).dtTransOffset = 20;

                    ;% rtDW.je2kiqe4dx.AQHandles
                    section.data(22).logicalSrcIdx = 31;
                    section.data(22).dtTransOffset = 21;

                    ;% rtDW.njvgyvffo2.AQHandles
                    section.data(23).logicalSrcIdx = 32;
                    section.data(23).dtTransOffset = 22;

                    ;% rtDW.diar2azokk.AQHandles
                    section.data(24).logicalSrcIdx = 33;
                    section.data(24).dtTransOffset = 23;

                    ;% rtDW.a0s45dbdod.AQHandles
                    section.data(25).logicalSrcIdx = 34;
                    section.data(25).dtTransOffset = 24;

                    ;% rtDW.jgrlhmdnhu.LoggedData
                    section.data(26).logicalSrcIdx = 35;
                    section.data(26).dtTransOffset = 25;

                    ;% rtDW.fgazjk5423.LoggedData
                    section.data(27).logicalSrcIdx = 36;
                    section.data(27).dtTransOffset = 26;

                    ;% rtDW.n2tu4152xd.AQHandles
                    section.data(28).logicalSrcIdx = 37;
                    section.data(28).dtTransOffset = 27;

                    ;% rtDW.favhxcmqok.AQHandles
                    section.data(29).logicalSrcIdx = 38;
                    section.data(29).dtTransOffset = 28;

                    ;% rtDW.cfsxur0ivk.LoggedData
                    section.data(30).logicalSrcIdx = 39;
                    section.data(30).dtTransOffset = 29;

                    ;% rtDW.obnnkkxer4.LoggedData
                    section.data(31).logicalSrcIdx = 40;
                    section.data(31).dtTransOffset = 30;

                    ;% rtDW.e5hnmu1lyf.LoggedData
                    section.data(32).logicalSrcIdx = 41;
                    section.data(32).dtTransOffset = 31;

                    ;% rtDW.fs1etcfe3q.LoggedData
                    section.data(33).logicalSrcIdx = 42;
                    section.data(33).dtTransOffset = 32;

                    ;% rtDW.bni3utz05a.AQHandles
                    section.data(34).logicalSrcIdx = 43;
                    section.data(34).dtTransOffset = 33;

                    ;% rtDW.lwx4ofpmhf.LoggedData
                    section.data(35).logicalSrcIdx = 44;
                    section.data(35).dtTransOffset = 34;

                    ;% rtDW.k30bdvjxid.LoggedData
                    section.data(36).logicalSrcIdx = 45;
                    section.data(36).dtTransOffset = 35;

                    ;% rtDW.mwiuydgnkh.LoggedData
                    section.data(37).logicalSrcIdx = 46;
                    section.data(37).dtTransOffset = 36;

                    ;% rtDW.pnoevo4udr.LoggedData
                    section.data(38).logicalSrcIdx = 47;
                    section.data(38).dtTransOffset = 37;

                    ;% rtDW.ghgxdsveji.LoggedData
                    section.data(39).logicalSrcIdx = 48;
                    section.data(39).dtTransOffset = 38;

                    ;% rtDW.o3jmjepwte.LoggedData
                    section.data(40).logicalSrcIdx = 49;
                    section.data(40).dtTransOffset = 39;

                    ;% rtDW.mshmkcmhdt.LoggedData
                    section.data(41).logicalSrcIdx = 50;
                    section.data(41).dtTransOffset = 40;

                    ;% rtDW.dbut54doru.LoggedData
                    section.data(42).logicalSrcIdx = 51;
                    section.data(42).dtTransOffset = 41;

                    ;% rtDW.lumyjs23ja.AQHandles
                    section.data(43).logicalSrcIdx = 52;
                    section.data(43).dtTransOffset = 42;

                    ;% rtDW.bk4jfotvgv.AQHandles
                    section.data(44).logicalSrcIdx = 53;
                    section.data(44).dtTransOffset = 43;

                    ;% rtDW.dycpvmyaei.LoggedData
                    section.data(45).logicalSrcIdx = 54;
                    section.data(45).dtTransOffset = 44;

                    ;% rtDW.akyms3mka4.LoggedData
                    section.data(46).logicalSrcIdx = 55;
                    section.data(46).dtTransOffset = 45;

                    ;% rtDW.l0q4q2mauq.AQHandles
                    section.data(47).logicalSrcIdx = 56;
                    section.data(47).dtTransOffset = 46;

                    ;% rtDW.expqsi0g3r.AQHandles
                    section.data(48).logicalSrcIdx = 57;
                    section.data(48).dtTransOffset = 47;

                    ;% rtDW.ibsnvtyivb.LoggedData
                    section.data(49).logicalSrcIdx = 58;
                    section.data(49).dtTransOffset = 48;

                    ;% rtDW.h5y21eaq2h.LoggedData
                    section.data(50).logicalSrcIdx = 59;
                    section.data(50).dtTransOffset = 49;

                    ;% rtDW.ib0h0blurd.LoggedData
                    section.data(51).logicalSrcIdx = 60;
                    section.data(51).dtTransOffset = 50;

            nTotData = nTotData + section.nData;
            dworkMap.sections(3) = section;
            clear section

            section.nData     = 10;
            section.data(10)  = dumData; %prealloc

                    ;% rtDW.gjpvvsicgx
                    section.data(1).logicalSrcIdx = 61;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.ivnf1ct5mk
                    section.data(2).logicalSrcIdx = 62;
                    section.data(2).dtTransOffset = 1;

                    ;% rtDW.lk33nb0dif
                    section.data(3).logicalSrcIdx = 63;
                    section.data(3).dtTransOffset = 2;

                    ;% rtDW.lxjgrndv13
                    section.data(4).logicalSrcIdx = 64;
                    section.data(4).dtTransOffset = 3;

                    ;% rtDW.basopanm0u
                    section.data(5).logicalSrcIdx = 65;
                    section.data(5).dtTransOffset = 4;

                    ;% rtDW.gdlhm5czey
                    section.data(6).logicalSrcIdx = 66;
                    section.data(6).dtTransOffset = 5;

                    ;% rtDW.az3nbubu5p
                    section.data(7).logicalSrcIdx = 67;
                    section.data(7).dtTransOffset = 6;

                    ;% rtDW.faseuqsse1
                    section.data(8).logicalSrcIdx = 68;
                    section.data(8).dtTransOffset = 7;

                    ;% rtDW.hyxofhb30f
                    section.data(9).logicalSrcIdx = 69;
                    section.data(9).dtTransOffset = 8;

                    ;% rtDW.b0palefbsp
                    section.data(10).logicalSrcIdx = 70;
                    section.data(10).dtTransOffset = 9;

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


    targMap.checksum0 = 1424953456;
    targMap.checksum1 = 2663102336;
    targMap.checksum2 = 103002778;
    targMap.checksum3 = 3508950546;

