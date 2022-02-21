

#ifndef _COM_CFG_H_
#define _COM_CFG_H_

#ifdef COM
    #define EXTERN
#else
    #define EXTERN extern
#endif

/* MACRO definition of the BIT Order */
#define COM_BIGENDIAN           1
#define COM_LITTLEENDIAN        0

/* MACRO definition of the signal type */
#define COM_SIGNALTYPE_UB       ((unsigned char)0)
#define COM_SIGNALTYPE_UW       ((unsigned char)1)
#define COM_SIGNALTYPE_UL       ((unsigned char)2)
#define COM_SIGNALTYPE_ULL      ((unsigned char)3)

#define COM_SIGNALTYPE_SB       ((unsigned char)4)
#define COM_SIGNALTYPE_SW       ((unsigned char)5)
#define COM_SIGNALTYPE_SL       ((unsigned char)6)

//Rx signal define
/*ULL signals start*/

//Rx Signals
#define COM_NUM_SIGNALS_RX_ULL      6
#define COM_CE_DgnInf_All         ((unsigned char)0)
#define COM_CE_DgnInf_APA         ((unsigned char)1)
#define COM_LS_VehIdNmDig2_9      ((unsigned char)2)
#define COM_LS_DgnInf_All         ((unsigned char)3)
#define COM_LS_DgnInf_Upa_Apa     ((unsigned char)4)
#define COM_LS_VehIdNmDig10_17    ((unsigned char)5)

EXTERN signed short Com_SignalsRxULL[COM_NUM_SIGNALS_RX_ULL];
/*ULL signals end*/
/*UL signals start*/

//Rx Signals
#define COM_NUM_SIGNALS_RX_UL      3

#define COM_LS_ODIAC_ActnVal     ((unsigned char)0)
#define COM_LS_ODIAI_ActnVal     ((unsigned char)1)
#define COM_LS_ODIAA_ActnVal     ((unsigned char)2)
EXTERN unsigned long  Com_SignalsRxUL[COM_NUM_SIGNALS_RX_UL];

//Tx Signals
#define COM_NUM_SIGNALS_TX_UL      2

#define COM_CE_StrWhlAngReqPrtVal                ((unsigned char)0)
#define COM_LS_ODD_DataVal                       ((unsigned char)1)

EXTERN unsigned int Com_SignalsTxUL[COM_NUM_SIGNALS_TX_UL];

/* UL signals end */


/*SW signals start*/

//Rx signals
#define COM_NUM_SIGNALS_RX_SW      8

#define COM_CE_IMULonAccPri     ((unsigned char)0)
#define COM_CE_IMUYawRtPri      ((unsigned char)1)
#define COM_CE_IMULatAccPrim    ((unsigned char)2)
#define COM_CE_StrWhAngGrd      ((unsigned char)3)
#define COM_CE_StrWhAng         ((unsigned char)4)
#define COM_LS_VSELongAccLoRes  ((unsigned char)5)
#define COM_LS_StrWhAng         ((unsigned char)6)
#define COM_LS_VehDynYawRate    ((unsigned char)7)
EXTERN signed short Com_SignalsRxSW[COM_NUM_SIGNALS_RX_SW];
//TX signals
#define COM_NUM_SIGNALS_TX_SW      1

#define COM_CE_SWAR_TrgtAng                      ((unsigned char)0)

EXTERN signed short Com_SignalsTxSW[ COM_NUM_SIGNALS_TX_SW ];
/* SW signals end */


/* UW signals start */

//Rx Signals
#define COM_NUM_SIGNALS_RX_UW      34

#define COM_CE_WhlDistPrRevNDrvn         ((unsigned char)0)
#define COM_CE_WhlDistPrRevDrvn          ((unsigned char)1)
#define COM_CE_IMUChksumSec              ((unsigned char)2)
#define COM_CE_IMUChksumPri              ((unsigned char)3)
#define COM_CEWhlRotStatTmstmpRes        ((unsigned char)4)
#define COM_CE_WhlGrndVlctyRtDrvn        ((unsigned char)5)
#define COM_CE_WhlGrndVlctyLftDrvn       ((unsigned char)6)
#define COM_CE_WRSLDWhlDistTmstm         ((unsigned char)7)
#define COM_CE_WRSLDWhlDistPlsCntr       ((unsigned char)8)
#define COM_CE_WRSRDWhlDistTmstm         ((unsigned char)9)
#define COM_CE_WRSRDWhlDistPlsCntr       ((unsigned char)10)
#define COM_CE_WRSLNDWhlDistTstm         ((unsigned char)11)
#define COM_CE_WRSLNDWhlDistPCntr        ((unsigned char)12)
#define COM_CE_StrAngSnsChksm            ((unsigned char)13)
#define COM_CE_WRSRNDWhlDistTstm         ((unsigned char)14)
#define COM_CE_WRSRNDWhlDistPCntr        ((unsigned char)15)
#define COM_CE_WhlGrndVlctyRtNnDrvn      ((unsigned char)16)
#define COM_CE_WhlGrndVlctyLftNnDrvn     ((unsigned char)17)
#define COM_LS_WhlGrndVlctyRtNnDrvn      ((unsigned char)18)
#define COM_LS_WhlGrndVlctyRtDrvn        ((unsigned char)19)
#define COM_LS_WhlGrndVlctyLftNnDrvn     ((unsigned char)20)
#define COM_LS_WhlGrndVlctyLftDrvn       ((unsigned char)21)
#define COM_LS_WRSLNDWhlDistTstm         ((unsigned char)22)
#define COM_LS_WRSLNDWhlDistPCntr        ((unsigned char)23)
#define COM_LS_WRSRNDWhlDistTstm         ((unsigned char)24)
#define COM_LS_WRSRNDWhlDistPCntr        ((unsigned char)25)
#define COM_LS_WRSLDWhlDistTmstm         ((unsigned char)26)
#define COM_LS_WRSLDWhlDistPlsCntr       ((unsigned char)27)
#define COM_LS_WRSRDWhlDistTmstm         ((unsigned char)28)
#define COM_LS_WRSRDWhlDistPlsCntr       ((unsigned char)29)
#define COM_LS_VehSpdAvgNDrvn            ((unsigned char)30)
#define COM_LS_DistRollCntAvgDrvn        ((unsigned char)31)
#define COM_LS_VehSpdAvgDrvn             ((unsigned char)32)
#define COM_LS_RrEndCrrStat              ((unsigned char)33) 
EXTERN unsigned short Com_SignalsRxUW[COM_NUM_SIGNALS_RX_UW];

//Tx signal
#define COM_NUM_SIGNALS_TX_UW      4

#define COM_LS_PrkAsstRrExtdDist                         ((unsigned char)0)
#define COM_LS_PrkAsstFrtExtdDist                        ((unsigned char)1)
#define COM_LS_PrkAstRrExtdDstUnfltd                     ((unsigned char)2)
#define COM_LS_DTCI_DTCNumber                            ((unsigned char)3)


EXTERN unsigned short Com_SignalsTxUW[COM_NUM_SIGNALS_TX_UW];

/* UW signals end */


/* UB signals start */
//Rx signal
#define COM_NUM_SIGNALS_RX_UB      174

#define COM_LS_OAT_PT_EstM               ((unsigned char)0)
#define COM_CE_ElcPwrStrAvalStatPVal     ((unsigned char)1)
#define COM_CE_ElcPwrStrAvalStatARC      ((unsigned char)2)
#define COM_CE_ElecPwrStrAvalStat        ((unsigned char)3)
#define COM_CE_DrvStrIntfrDetARC         ((unsigned char)4)
#define COM_CE_DrvStrIntfrDetPrtVal      ((unsigned char)5)
#define COM_CE_DrvStrIntfrDtcdV          ((unsigned char)6)
#define COM_CE_DrvStrIntfrDtcd           ((unsigned char)7)
#define COM_CE_IMULonAccPriV             ((unsigned char)8)
#define COM_CE_IMURollCntSec             ((unsigned char)9)
#define COM_CE_IMUYawRtPriV              ((unsigned char)10)
#define COM_CE_IMURollCntPri             ((unsigned char)11)
#define COM_CE_IMULatAccPrimV            ((unsigned char)12)
#define COM_CE_WhlPlsPerRevDrvn          ((unsigned char)13)
#define COM_CE_WhlGrndVlctyRtDrvnV       ((unsigned char)14)
#define COM_CE_WhlGrndVlctyLftDrvnV      ((unsigned char)15)
#define COM_CE_WRSLDWhlDisTpRC           ((unsigned char)16)
#define COM_CE_WRSLDSeqNum               ((unsigned char)17)
#define COM_CE_WRSLDWhlDistVal           ((unsigned char)18)
#define COM_CE_WRSLDWhlRotStatRst        ((unsigned char)19)
#define COM_CE_WRSRDWhlDisTpRC           ((unsigned char)20)
#define COM_CE_WRSRDSeqNum               ((unsigned char)21)
#define COM_CE_WRSRDWhlRotStatRst        ((unsigned char)22)
#define COM_CE_WRSRDWhlDistVal           ((unsigned char)23)
#define COM_CE_TrnsShftLvrPosV           ((unsigned char)24)
#define COM_CE_TrnsShftLvrPos            ((unsigned char)25)
#define COM_CE_StrWhAngGrdV              ((unsigned char)26)
#define COM_CE_StrWhlAngSenCalStat       ((unsigned char)27)
#define COM_CE_StWhlAngAliveRollCnt      ((unsigned char)28)
#define COM_CE_StrWhAngMsk               ((unsigned char)29)
#define COM_CE_StrWhAngV                 ((unsigned char)30)
#define COM_CE_WRSLNDWhlDisTpRC          ((unsigned char)31)
#define COM_CE_WRSLNDWhlRotStRst         ((unsigned char)32)
#define COM_CE_WRSLNDWhlDistVal          ((unsigned char)33)
#define COM_CE_WRSLNDSeqNum              ((unsigned char)34)
#define COM_CE_WRSRNDWhlDisTpRC          ((unsigned char)35)
#define COM_CE_WRSRNDWhlRotStRst         ((unsigned char)36)
#define COM_CE_WRSRNDWhlDistVal          ((unsigned char)37)
#define COM_CE_WRSRNDSeqNum              ((unsigned char)38)
#define COM_CE_WhlPlsPerRevNonDrvn       ((unsigned char)39)
#define COM_CE_WhlGrndVlctyRtNnDrvnV     ((unsigned char)40)
#define COM_CE_WhlGrndVlctyLftNnDrvnV    ((unsigned char)41)
#define COM_LS_PrkAstRrObjSnsngRqAct     ((unsigned char)42)
#define COM_LS_PrkAstOprtrDsrdStat       ((unsigned char)43)
#define COM_LS_PrkAstInhbtReq            ((unsigned char)44)
#define COM_LS_ClsnMtgtnInhbtd           ((unsigned char)45)
#define COM_LS_WhlPlsPerRevNonDrvn       ((unsigned char)46)
#define COM_LS_WhlPlsPerRevDrvn          ((unsigned char)47)
#define COM_LS_EngOffTmExtRngV           ((unsigned char)48)
#define COM_LS_EngOffTmExtRng            ((unsigned char)49)
#define COM_LS_ChmAct                    ((unsigned char)50)
#define COM_LS_ODIAC_FUCID               ((unsigned char)51)
#define COM_LS_ODIAC_DspMID              ((unsigned char)52)
#define COM_LS_ODIAC_DaTy                ((unsigned char)53)
#define COM_LS_ODIAC_ActnID              ((unsigned char)54)
#define COM_LS_PrkBrkSwAtv               ((unsigned char)55)
#define COM_LS_VSELongAccLoResV          ((unsigned char)56)
#define COM_LS_StrWhAngV                 ((unsigned char)57)
#define COM_LS_TCSysAtv                  ((unsigned char)58)
#define COM_LS_StrWhlAngSenCalStat       ((unsigned char)59)
#define COM_LS_VehStabEnhmntStat         ((unsigned char)60)
#define COM_LS_VSEAct                    ((unsigned char)61)
#define COM_LS_TCSysOpStat               ((unsigned char)62)
#define COM_LS_StWhAnVDA                 ((unsigned char)63)
#define COM_LS_WhlGrndVlctyRtNnDrvnV     ((unsigned char)64)
#define COM_LS_WhlGrndVlctyRtDrvnV       ((unsigned char)65)
#define COM_LS_WhlGrndVlctyLftNnDrvnV    ((unsigned char)66)
#define COM_LS_WhlGrndVlctyLftDrvnV      ((unsigned char)67)
#define COM_LS_WRSLNDWhlDisTpRC          ((unsigned char)68)
#define COM_LS_WRSLNDWhlRotStRst         ((unsigned char)69)
#define COM_LS_WRSLNDWhlDistVal          ((unsigned char)70)
#define COM_LS_WRSLNDSeqNum              ((unsigned char)71)
#define COM_LS_WRSRNDWhlDisTpRC          ((unsigned char)72)
#define COM_LS_WRSRNDWhlRotStRst         ((unsigned char)73)
#define COM_LS_WRSRNDWhlDistVal          ((unsigned char)74)
#define COM_LS_WRSRNDSeqNum              ((unsigned char)75)
#define COM_LS_WRSLDWhlDisTpRC           ((unsigned char)76)
#define COM_LS_WRSLDSeqNum               ((unsigned char)77)
#define COM_LS_WRSLDWhlDistVal           ((unsigned char)78)
#define COM_LS_WRSLDWhlRotStatRst        ((unsigned char)79)
#define COM_LS_WRSRDWhlDisTpRC           ((unsigned char)80)
#define COM_LS_WRSRDSeqNum               ((unsigned char)81)
#define COM_LS_WRSRDWhlRotStatRst        ((unsigned char)82)
#define COM_LS_WRSRDWhlDistVal           ((unsigned char)83)
#define COM_LS_VehMovState               ((unsigned char)84)
#define COM_LS_TrStLgMdAtv               ((unsigned char)85)
#define COM_LS_ElecPrkBrkStat            ((unsigned char)86)
#define COM_LS_ABSAtv                    ((unsigned char)87)
#define COM_LS_SprTireSt                 ((unsigned char)88)
#define COM_LS_BrkSysVDA                 ((unsigned char)89)
#define COM_LS_PrkBrkVDA                 ((unsigned char)90)
#define COM_LS_ODDMA_ReqType             ((unsigned char)91)
#define COM_LS_ODDMA_FUCID               ((unsigned char)92)
#define COM_LS_ODDMA_DispMID             ((unsigned char)93)
#define COM_LS_ODDMA_DataID2Vld          ((unsigned char)94)
#define COM_LS_ODDMA_DataID2             ((unsigned char)95)
#define COM_LS_ODDMA_DataID3Vld          ((unsigned char)96)
#define COM_LS_ODDMA_DataID3             ((unsigned char)97)
#define COM_LS_ODDMA_DataID1             ((unsigned char)98)
#define COM_LS_ODDMA_DataID4Vld          ((unsigned char)99)
#define COM_LS_ODDMA_DataID4             ((unsigned char)100)
#define COM_LS_ODDMA_DataID5Vld          ((unsigned char)101)
#define COM_LS_ODDMA_DataID5             ((unsigned char)102)
#define COM_LS_ODDMC_ReqType             ((unsigned char)103)
#define COM_LS_ODDMC_DispMID             ((unsigned char)104)
#define COM_LS_ODDMC_DataID2Vld          ((unsigned char)105)
#define COM_LS_ODDMC_DataID2             ((unsigned char)106)
#define COM_LS_ODDMC_DataID3Vld          ((unsigned char)107)
#define COM_LS_ODDMC_DataID3             ((unsigned char)108)
#define COM_LS_ODDMC_DataID1             ((unsigned char)119)
#define COM_LS_ODDMC_DataID4Vld          ((unsigned char)110)
#define COM_LS_ODDMC_DataID4             ((unsigned char)111)
#define COM_LS_ODDMC_DataID5Vld          ((unsigned char)112)
#define COM_LS_ODDMC_DataID5             ((unsigned char)113)
#define COM_LS_ODDMC_FUCID               ((unsigned char)114)
#define COM_LS_ODDMI_ReqType             ((unsigned char)115)
#define COM_LS_ODDMI_FUCID               ((unsigned char)116)
#define COM_LS_ODDMI_DispMID             ((unsigned char)117)
#define COM_LS_ODDMI_DataID2Vld          ((unsigned char)118)
#define COM_LS_ODDMI_DataID2             ((unsigned char)119)
#define COM_LS_ODDMI_DataID3Vld          ((unsigned char)120)
#define COM_LS_ODDMI_DataID3             ((unsigned char)121)
#define COM_LS_ODDMI_DataID1             ((unsigned char)122)
#define COM_LS_ODDMI_DataID4Vld          ((unsigned char)123)
#define COM_LS_ODDMI_DataID4             ((unsigned char)124)
#define COM_LS_ODDMI_DataID5Vld          ((unsigned char)125)
#define COM_LS_ODDMI_DataID5             ((unsigned char)126)
#define COM_LS_OtsAirTmpV                ((unsigned char)127)
#define COM_LS_OtsAirTmp                 ((unsigned char)128)
#define COM_LS_OtsAirTmpCrValV           ((unsigned char)139)
#define COM_LS_OtsAirTmpCrVal            ((unsigned char)130)
#define COM_LS_OtsAirTmpCrValMsk         ((unsigned char)131)
#define COM_LS_VehDynYawRateV            ((unsigned char)132)
#define COM_LS_ACCAct370                 ((unsigned char)133)
#define COM_LS_SysBkUpPwrMdV             ((unsigned char)134)
#define COM_LS_SysBkupPwrMdEn            ((unsigned char)135)
#define COM_LS_SysBkUpPwrMd              ((unsigned char)136)
#define COM_LS_ODIAI_DaTy                ((unsigned char)137)
#define COM_LS_ODIAI_FUCID               ((unsigned char)138)
#define COM_LS_ODIAI_DspMID              ((unsigned char)139)
#define COM_LS_ODIAI_ActnID              ((unsigned char)140)
#define COM_LS_ODIAA_FUCID               ((unsigned char)141)
#define COM_LS_ODIAA_DspMID              ((unsigned char)142)
#define COM_LS_ODIAA_ActnID              ((unsigned char)143)
#define COM_LS_ODIAA_DaTy                ((unsigned char)144)
#define COM_LS_EngRunAtv                 ((unsigned char)145)
#define COM_LS_TrnsVDA                   ((unsigned char)146)
#define COM_LS_EngVDA                    ((unsigned char)147)
#define COM_LS_TrnsShftLvrPosV           ((unsigned char)148)
#define COM_LS_TrnsShftLvrPos            ((unsigned char)149)	 
#define COM_LS_DDAjrSwAtvM               ((unsigned char)150)
#define COM_LS_DDAjrSwAtv                ((unsigned char)151)
#define COM_LS_TrnSwAct                  ((unsigned char)152)
#define COM_LS_HazSwAtv                  ((unsigned char)153)
#define COM_LS_LftTrnLmpAtv              ((unsigned char)154)
#define COM_LS_RtTrnLmpAtv               ((unsigned char)155)
#define COM_LS_OtsdAmbtLtLvlStatV        ((unsigned char)156)
#define COM_LS_OtsdAmbtLtLvlStat         ((unsigned char)157)
#define COM_LS_VehSpdAvgNDrvnV           ((unsigned char)158)
#define COM_LS_DistRollCntAvgDrvnV       ((unsigned char)159)
#define COM_LS_VehSpdAvgDrvnV            ((unsigned char)160)
#define COM_LS_SysPwrMd                  ((unsigned char)161)
#define COM_LS_SysPwrMdV                 ((unsigned char)162)
#define COM_LS_TeenDrvAct                ((unsigned char)163)
#define COM_LS_TrlrHtchSwAtv             ((unsigned char)164)
#define COM_LS_OAT_PT_EstV               ((unsigned char)165)
#define COM_LS_OAT_PT_Est                ((unsigned char)166)
#define COM_LS_EngCltTmpV                ((unsigned char)167)
#define COM_LS_EngCltTmp                 ((unsigned char)168)
#define COM_LS_EngIntAirTmpV             ((unsigned char)169)
#define COM_LS_EngIntAirTmp              ((unsigned char)170)
#define COM_LS_HptcStVbnStat             ((unsigned char)171)
#define COM_LS_CrshAlrtDrvrSlctdType     ((unsigned char)172)
#define COM_LS_CrshAlrtStPrsnt           ((unsigned char)173)


EXTERN unsigned char Com_SignalsRxUB[COM_NUM_SIGNALS_RX_UB];


//Tx signal
#define COM_NUM_SIGNALS_TX_UB    117

#define COM_CE_StrWhlTctlFdbkReqActRC                    ((unsigned char)0)
#define COM_CE_StrWhlTctlFdbkReqAct                      ((unsigned char)1) 
#define COM_CE_StrWhlTctlFdbkReqActProtVal               ((unsigned char)2) 
#define COM_CE_SWAR_ReqActV                              ((unsigned char)3)
#define COM_CE_SWAR_ReqAct                               ((unsigned char)4)
#define COM_CE_StrWhlAngReqARC                           ((unsigned char)5)
#define COM_LS_SC_SndTne                                 ((unsigned char)6)
#define COM_LS_SndLocRtRr                                ((unsigned char)7)
#define COM_LS_SndLocLftRr                               ((unsigned char)8)
#define COM_LS_SndLocPasFr                               ((unsigned char)9)
#define COM_LS_SndLocDrFr                                ((unsigned char)10)
#define COM_LS_SC_SndCdnPrd                              ((unsigned char)11)
#define COM_LS_SC_NmofRp                                 ((unsigned char)12)
#define COM_LS_SC_SndDutCyc                              ((unsigned char)13)
#define COM_LS_SndPriority                               ((unsigned char)14)
#define COM_LS_FPAHptcStVbnRqSeqN                        ((unsigned char)15)
#define COM_LS_FPAHptcStVbnReq                           ((unsigned char)16)
#define COM_LS_APAIconDispRq                             ((unsigned char)17)
#define COM_LS_APAIconFilPctRq                           ((unsigned char)18)
#define COM_LS_RPAHptcStVbRqSeqN                         ((unsigned char)19)
#define COM_LS_RPAHptcStVbnReq                           ((unsigned char)20)
#define COM_LS_SBZASysClnIndOn                           ((unsigned char)21)
#define COM_LS_SBZASysOffIndOn                           ((unsigned char)22)
#define COM_LS_SBZASysSrvIndOn                           ((unsigned char)23)
#define COM_LS_SBZATmpUnvIndOn                           ((unsigned char)24)
#define COM_LS_LftLnChgThrt                              ((unsigned char)25)
#define COM_LS_PARtRgn1ObjStat                           ((unsigned char)26)
#define COM_LS_PrkAstRtSysStat                           ((unsigned char)27)
#define COM_LS_PARtRgn3ObjStat                           ((unsigned char)28)
#define COM_LS_PARtRgn2ObjStat                           ((unsigned char)29)
#define COM_LS_PrkAstRrSysStat                           ((unsigned char)30)
#define COM_LS_PARrRgn1ObjStat                           ((unsigned char)31)
#define COM_LS_PARrRgn2ObjStat                           ((unsigned char)32)
#define COM_LS_PARrRgn3ObjStat                           ((unsigned char)33)
#define COM_LS_PARrRgn4ObjStat                           ((unsigned char)34)
#define COM_LS_PALtRgn1ObjStat                           ((unsigned char)35)
#define COM_LS_PrkAstLtSysStat                           ((unsigned char)36)
#define COM_LS_PALtRgn3ObjStat                           ((unsigned char)37)
#define COM_LS_PALtRgn2ObjStat                           ((unsigned char)38)
#define COM_LS_PrkAsstClnPrkAstIO                        ((unsigned char)39)
#define COM_LS_PrkAsstDisablIO                           ((unsigned char)40)
#define COM_LS_PrkAstFld                                 ((unsigned char)41)
#define COM_LS_PrkAstSnrsBlk                             ((unsigned char)42)
#define COM_LS_PrkAstSnsDistrbdIO                        ((unsigned char)43)
#define COM_LS_TnDrvPrkAstOffUnbIO                       ((unsigned char)44)
#define COM_LS_PrkAstOprtrDsrdStat_1D0                   ((unsigned char)45)
#define COM_LS_PrkAstFrSysStat                           ((unsigned char)46)
#define COM_LS_PrkAstAdvSysAct                           ((unsigned char)47)
#define COM_LS_PAFrtRgn1ObjStat                          ((unsigned char)48)
#define COM_LS_PAFrtRgn2ObjStat                          ((unsigned char)49)
#define COM_LS_PAFrtRgn3ObjStat                          ((unsigned char)50)
#define COM_LS_PAFrtRgn4ObjStat                          ((unsigned char)51)
#define COM_LS_PrkAstRrSysStatUnfltd                     ((unsigned char)52)
#define COM_LS_PrkAstFntnSnsDstrbdIO                     ((unsigned char)53)
#define COM_LS_PrkAstFntnSnrsBlkd                        ((unsigned char)54)
#define COM_LS_PrkAstFntnFld                             ((unsigned char)55)
#define COM_LS_PrkAstFntnDsbldIO                         ((unsigned char)56)
#define COM_LS_PrkAstFntnClnPrkAstIO                     ((unsigned char)57)
#define COM_LS_ClsnMtgtnInhbtReqtd                       ((unsigned char)58)
#define COM_LS_PrkAstRrObjSnsngAct                       ((unsigned char)59)
#define COM_LS_PARrRgn3ObjStatUnfltd                     ((unsigned char)60)
#define COM_LS_PARrRgn4ObjStatUnfltd                     ((unsigned char)61)
#define COM_LS_PARrRgn1ObjStatUnfltd                     ((unsigned char)62)
#define COM_LS_PARrRgn2ObjStatUnfltd                     ((unsigned char)63)
#define COM_LS_ODD_InvldData                             ((unsigned char)64)
#define COM_LS_ODD_DataType                              ((unsigned char)65)
#define COM_LS_ODD_FUCID                                 ((unsigned char)66)
#define COM_LS_ODD_DataId                                ((unsigned char)67)
#define COM_LS_ODD_ODIE_EvID                             ((unsigned char)68)
#define COM_LS_ODIE_FUCID                                ((unsigned char)69)
#define COM_LS_ODIE_MultiFrRetCh                         ((unsigned char)70)
#define COM_LS_ODIEDD_Data2Value                         ((unsigned char)71)
#define COM_LS_ODIEDD_Data1Value                         ((unsigned char)72)
#define COM_LS_ODIEDD_Data4Value                         ((unsigned char)73)
#define COM_LS_ODIEDD_Data3Value                         ((unsigned char)74)
#define COM_LS_ODIEDD_Data7Value                         ((unsigned char)75)
#define COM_LS_ODIEDD_Data6Value                         ((unsigned char)76)
#define COM_LS_ODIEDD_Data5Value                         ((unsigned char)77)
#define COM_LS_ODIEDD_Data10Value                        ((unsigned char)78)
#define COM_LS_ODIEDD_Data9Value                         ((unsigned char)79)
#define COM_LS_ODIEDD_Data8Value                         ((unsigned char)80)
#define COM_LS_ODIEDD_Data12Value                        ((unsigned char)81)
#define COM_LS_ODIEDD_Data11Value                        ((unsigned char)82)
#define COM_LS_ODIEDD_Data15Value                        ((unsigned char)83)
#define COM_LS_ODIEDD_Data14Value                        ((unsigned char)84)
#define COM_LS_ODIEDD_Data13Value                        ((unsigned char)85)
#define COM_LS_ODIEDD_Data18Value                        ((unsigned char)86)
#define COM_LS_ODIEDD_Data17Value                        ((unsigned char)87)
#define COM_LS_ODIEDD_Data16Value                        ((unsigned char)88)
#define COM_LS_ODIEDD_FUCID                              ((unsigned char)89)
#define COM_LS_ODII_FUCID                                ((unsigned char)90)
#define COM_LS_ODII_ODIInd8                              ((unsigned char)91)
#define COM_LS_ODII_ODIInd7                              ((unsigned char)92)
#define COM_LS_ODII_ODIInd6                              ((unsigned char)93)
#define COM_LS_ODII_ODIInd5                              ((unsigned char)94)
#define COM_LS_ODII_ODIInd4                              ((unsigned char)95)
#define COM_LS_ODII_ODIInd3                              ((unsigned char)96)
#define COM_LS_ODII_ODIInd2                              ((unsigned char)97)
#define COM_LS_ODII_ODIInd1                              ((unsigned char)98)
#define COM_LS_ODII_ODIInd14                             ((unsigned char)99)
#define COM_LS_ODII_ODIInd13                             ((unsigned char)100)
#define COM_LS_ODII_ODIInd12                             ((unsigned char)101)
#define COM_LS_ODII_ODIInd11                             ((unsigned char)102)
#define COM_LS_ODII_ODIInd10                             ((unsigned char)103)
#define COM_LS_ODII_ODIInd9                              ((unsigned char)104)
#define COM_LS_DTCI_DTCTriggered                         ((unsigned char)105)
#define COM_LS_DTCI_DTCI_DTCSource                       ((unsigned char)106)
#define COM_LS_DTCI_DTCFailType                          ((unsigned char)107)
#define COM_LS_DTCI_CodeSupported                        ((unsigned char)108)
#define COM_LS_DTCI_CurrentStatus                        ((unsigned char)109)
#define COM_LS_DTCI_TstNPsdCdClrdSt                      ((unsigned char)110)
#define COM_LS_DTCI_TstFldCdClrdStat                     ((unsigned char)111)
#define COM_LS_DTCI_HistStat                             ((unsigned char)112)
#define COM_LS_DTCI_TstNPsdPwrUpSt                       ((unsigned char)113)
#define COM_LS_DTCI_TstFldPwrUpSt                        ((unsigned char)114)
#define COM_LS_DTCI_WrnIndRqdSt                          ((unsigned char)115)
#define COM_LS_DTCI_DTCFaultType                         ((unsigned char)116)


EXTERN unsigned char Com_SignalsTxUB[COM_NUM_SIGNALS_TX_UB];

/* UB signals end */

/* Signals ID and NUM of signals start */
//Rx signal
#define COM_SIGID_CE_ElcPwrStrAvalStatPVal  (0x00) 
#define COM_SIGID_CE_ElcPwrStrAvalStatARC   (0x01) 
#define COM_SIGID_CE_ElecPwrStrAvalStat     (0x02) 
#define COM_SIGID_CE_DrvStrIntfrDetARC      (0x03) 
#define COM_SIGID_CE_DrvStrIntfrDetPrtVal   (0x04) 
#define COM_SIGID_CE_DrvStrIntfrDtcdV       (0x05) 
#define COM_SIGID_CE_DrvStrIntfrDtcd        (0x06) 
#define COM_SIGID_CE_WhlDistPrRevNDrvn      (0x07) 
#define COM_SIGID_CE_WhlDistPrRevDrvn       (0x08) 
#define COM_SIGID_CE_DgnInf_All             (0x09) 
#define COM_SIGID_CE_DgnInf_APA             (0x0A) 
#define COM_SIGID_CE_IMULonAccPriV          (0x0B) 
#define COM_SIGID_CE_IMULonAccPri           (0x0C) 
#define COM_SIGID_CE_IMUChksumSec           (0x0D) 
#define COM_SIGID_CE_IMURollCntSec          (0x0E) 
#define COM_SIGID_CE_IMUYawRtPriV           (0x0F) 
#define COM_SIGID_CE_IMUYawRtPri            (0x10) 
#define COM_SIGID_CE_IMURollCntPri          (0x11) 
#define COM_SIGID_CE_IMUChksumPri           (0x12) 
#define COM_SIGID_CE_IMULatAccPrim          (0x13) 
#define COM_SIGID_CE_IMULatAccPrimV         (0x14) 
#define COM_SIGID_CE_WhlRotStatTmstmpRes    (0x15) 
#define COM_SIGID_CE_WhlPlsPerRevDrvn       (0x16) 
#define COM_SIGID_CE_WhlGrndVlctyRtDrvnV    (0x17) 
#define COM_SIGID_CE_WhlGrndVlctyRtDrvn     (0x18) 
#define COM_SIGID_CE_WhlGrndVlctyLftDrvnV   (0x19) 
#define COM_SIGID_CE_WhlGrndVlctyLftDrvn    (0x1A) 
#define COM_SIGID_CE_WRSLDWhlDisTpRC        (0x1B) 
#define COM_SIGID_CE_WRSLDSeqNum            (0x1C) 
#define COM_SIGID_CE_WRSLDWhlDistVal        (0x1D) 
#define COM_SIGID_CE_WRSLDWhlRotStatRst     (0x1E) 
#define COM_SIGID_CE_WRSLDWhlDistTmstm      (0x1F) 
#define COM_SIGID_CE_WRSLDWhlDistPlsCntr    (0x20) 
#define COM_SIGID_CE_WRSRDWhlDisTpRC        (0x21) 
#define COM_SIGID_CE_WRSRDSeqNum            (0x22) 
#define COM_SIGID_CE_WRSRDWhlRotStatRst     (0x23) 
#define COM_SIGID_CE_WRSRDWhlDistVal        (0x24) 
#define COM_SIGID_CE_WRSRDWhlDistTmstm      (0x25) 
#define COM_SIGID_CE_WRSRDWhlDistPlsCntr    (0x26) 
#define COM_SIGID_CE_TrnsShftLvrPosV        (0x27) 
#define COM_SIGID_CE_TrnsShftLvrPos         (0x28) 
#define COM_SIGID_CE_StrAngSnsChksm         (0x29) 
#define COM_SIGID_CE_StrWhAngGrdV           (0x2A) 
#define COM_SIGID_CE_StrWhlAngSenCalStat    (0x2B) 
#define COM_SIGID_CE_StrWhAngGrd            (0x2C) 
#define COM_SIGID_CE_StWhlAngAliveRollCnt   (0x2D) 
#define COM_SIGID_CE_StrWhAngMsk            (0x2E) 
#define COM_SIGID_CE_StrWhAngV              (0x2F) 
#define COM_SIGID_CE_StrWhAng               (0x30) 
#define COM_SIGID_CE_WRSLNDWhlDisTpRC       (0x31) 
#define COM_SIGID_CE_WRSLNDWhlRotStRst      (0x32) 
#define COM_SIGID_CE_WRSLNDWhlDistVal       (0x33) 
#define COM_SIGID_CE_WRSLNDWhlDistTstm      (0x34) 
#define COM_SIGID_CE_WRSLNDWhlDistPCntr     (0x35) 
#define COM_SIGID_CE_WRSLNDSeqNum           (0x36) 
#define COM_SIGID_CE_WRSRNDWhlDisTpRC       (0x37) 
#define COM_SIGID_CE_WRSRNDWhlRotStRst      (0x38) 
#define COM_SIGID_CE_WRSRNDWhlDistVal       (0x39) 
#define COM_SIGID_CE_WRSRNDWhlDistTstm      (0x3A) 
#define COM_SIGID_CE_WRSRNDWhlDistPCntr     (0x3B) 
#define COM_SIGID_CE_WRSRNDSeqNum           (0x3C) 
#define COM_SIGID_CE_WhlPlsPerRevNonDrvn    (0x3D)  
#define COM_SIGID_CE_WhlGrndVlctyRtNnDrvnV  (0x3E) 
#define COM_SIGID_CE_WhlGrndVlctyRtNnDrvn   (0x3F) 
#define COM_SIGID_CE_WhlGrndVlctyLftNnDrvnV (0x40) 
#define COM_SIGID_CE_WhlGrndVlctyLftNnDrvn  (0x41) 
#define COM_SIGID_LS_PrkAstRrObjSnsngRqAct  (0x42)  
#define COM_SIGID_LS_PrkAstOprtrDsrdStat    (0x43)   
#define COM_SIGID_LS_PrkAstInhbtReq         (0x44)    
#define COM_SIGID_LS_ClsnMtgtnInhbtd        (0x45)  
#define COM_SIGID_LS_WhlPlsPerRevNonDrvn    (0x46) 
#define COM_SIGID_LS_WhlPlsPerRevDrvn       (0x47) 
#define COM_SIGID_LS_EngOffTmExtRngV        (0x48) 
#define COM_SIGID_LS_EngOffTmExtRng         (0x49)
#define COM_SIGID_LS_ChmAct                 (0x4A) 
#define COM_SIGID_LS_ODIAC_FUCID            (0x4B) 
#define COM_SIGID_LS_ODIAC_DspMID           (0x4C) 
#define COM_SIGID_LS_ODIAC_DaTy             (0x4D) 
#define COM_SIGID_LS_ODIAC_ActnVal          (0x4E) 
#define COM_SIGID_LS_ODIAC_ActnID           (0x4F) 
#define COM_SIGID_LS_PrkBrkSwAtv            (0x50) 
#define COM_SIGID_LS_VSELongAccLoResV       (0x51) 
#define COM_SIGID_LS_VSELongAccLoRes        (0x52) 
#define COM_SIGID_LS_StrWhAngV              (0x53) 
#define COM_SIGID_LS_TCSysAtv               (0x54) 
#define COM_SIGID_LS_StrWhlAngSenCalStat    (0x55) 
#define COM_SIGID_LS_VehStabEnhmntStat      (0x56) 
#define COM_SIGID_LS_VSEAct                 (0x57) 
#define COM_SIGID_LS_TCSysOpStat            (0x58) 
#define COM_SIGID_LS_StWhAnVDA              (0x59) 
#define COM_SIGID_LS_StrWhAng               (0x5A) 
#define COM_SIGID_LS_WhlGrndVlctyRtNnDrvnV  (0x5B) 
#define COM_SIGID_LS_WhlGrndVlctyRtNnDrvn   (0x5C) 
#define COM_SIGID_LS_WhlGrndVlctyRtDrvnV    (0x5D) 
#define COM_SIGID_LS_WhlGrndVlctyRtDrvn     (0x5E) 
#define COM_SIGID_LS_WhlGrndVlctyLftNnDrvnV (0x5F) 
#define COM_SIGID_LS_WhlGrndVlctyLftNnDrvn  (0x60) 
#define COM_SIGID_LS_WhlGrndVlctyLftDrvnV   (0x61) 
#define COM_SIGID_LS_WhlGrndVlctyLftDrvn    (0x62) 
#define COM_SIGID_LS_WRSLNDWhlDisTpRC       (0x63) 
#define COM_SIGID_LS_WRSLNDWhlRotStRst      (0x64) 
#define COM_SIGID_LS_WRSLNDWhlDistVal       (0x65)
#define COM_SIGID_LS_WRSLNDWhlDistTstm      (0x66) 
#define COM_SIGID_LS_WRSLNDWhlDistPCntr     (0x67) 
#define COM_SIGID_LS_WRSLNDSeqNum           (0x68) 
#define COM_SIGID_LS_WRSRNDWhlDisTpRC       (0x69) 
#define COM_SIGID_LS_WRSRNDWhlRotStRst      (0x6A) 
#define COM_SIGID_LS_WRSRNDWhlDistVal       (0x6B) 
#define COM_SIGID_LS_WRSRNDWhlDistTstm      (0x6C) 
#define COM_SIGID_LS_WRSRNDWhlDistPCntr     (0x6D) 
#define COM_SIGID_LS_WRSRNDSeqNum           (0x6E) 
#define COM_SIGID_LS_WRSLDWhlDisTpRC        (0x6F) 
#define COM_SIGID_LS_WRSLDSeqNum            (0x70) 
#define COM_SIGID_LS_WRSLDWhlDistVal        (0x71) 
#define COM_SIGID_LS_WRSLDWhlRotStatRst     (0x72)   
#define COM_SIGID_LS_WRSLDWhlDistTmstm      (0x73)   
#define COM_SIGID_LS_WRSLDWhlDistPlsCntr    (0x74)  
#define COM_SIGID_LS_WRSRDWhlDisTpRC        (0x75)  
#define COM_SIGID_LS_WRSRDSeqNum            (0x76)   
#define COM_SIGID_LS_WRSRDWhlRotStatRst     (0x77)    
#define COM_SIGID_LS_WRSRDWhlDistVal        (0x78)   
#define COM_SIGID_LS_WRSRDWhlDistTmstm      (0x79)  
#define COM_SIGID_LS_WRSRDWhlDistPlsCntr    (0x7A)  
#define COM_SIGID_LS_VehMovState            (0x7B) 
#define COM_SIGID_LS_TrStLgMdAtv            (0x7C)
#define COM_SIGID_LS_ElecPrkBrkStat         (0x7D) 
#define COM_SIGID_LS_ABSAtv                 (0x7E) 
#define COM_SIGID_LS_SprTireSt              (0x7F) 
#define COM_SIGID_LS_BrkSysVDA              (0x80) 
#define COM_SIGID_LS_PrkBrkVDA              (0x81) 
#define COM_SIGID_LS_ODDMA_ReqType          (0x82) 
#define COM_SIGID_LS_ODDMA_FUCID            (0x83) 
#define COM_SIGID_LS_ODDMA_DispMID          (0x84) 
#define COM_SIGID_LS_ODDMA_DataID2Vld       (0x85) 
#define COM_SIGID_LS_ODDMA_DataID2          (0x86) 
#define COM_SIGID_LS_ODDMA_DataID3Vld       (0x87) 
#define COM_SIGID_LS_ODDMA_DataID3          (0x88) 
#define COM_SIGID_LS_ODDMA_DataID1          (0x89) 
#define COM_SIGID_LS_ODDMA_DataID4Vld       (0x8A) 
#define COM_SIGID_LS_ODDMA_DataID4          (0x8B)
#define COM_SIGID_LS_ODDMA_DataID5Vld       (0x8C) 
#define COM_SIGID_LS_ODDMA_DataID5          (0x8D) 
#define COM_SIGID_LS_ODDMC_ReqType          (0x8E) 
#define COM_SIGID_LS_ODDMC_DispMID          (0x8F) 
#define COM_SIGID_LS_ODDMC_DataID2Vld       (0x90) 
#define COM_SIGID_LS_ODDMC_DataID2          (0x91) 
#define COM_SIGID_LS_ODDMC_DataID3Vld       (0x92) 
#define COM_SIGID_LS_ODDMC_DataID3          (0x93) 
#define COM_SIGID_LS_ODDMC_DataID1          (0x94) 
#define COM_SIGID_LS_ODDMC_DataID4Vld       (0x95) 
#define COM_SIGID_LS_ODDMC_DataID4          (0x96)
#define COM_SIGID_LS_ODDMC_DataID5Vld       (0x97)
#define COM_SIGID_LS_ODDMC_DataID5          (0x98) 
#define COM_SIGID_LS_ODDMC_FUCID            (0x99) 
#define COM_SIGID_LS_ODDMI_ReqType          (0x9A) 
#define COM_SIGID_LS_ODDMI_FUCID            (0x9B) 
#define COM_SIGID_LS_ODDMI_DispMID          (0x9C) 
#define COM_SIGID_LS_ODDMI_DataID2Vld       (0x9D) 
#define COM_SIGID_LS_ODDMI_DataID2          (0x9E) 
#define COM_SIGID_LS_ODDMI_DataID3Vld       (0x9F) 
#define COM_SIGID_LS_ODDMI_DataID3          (0xA0) 
#define COM_SIGID_LS_ODDMI_DataID1          (0xA1) 
#define COM_SIGID_LS_ODDMI_DataID4Vld       (0xA2) 
#define COM_SIGID_LS_ODDMI_DataID4          (0xA3) 
#define COM_SIGID_LS_ODDMI_DataID5Vld       (0xA4) 
#define COM_SIGID_LS_ODDMI_DataID5          (0xA5)  
#define COM_SIGID_LS_OtsAirTmpV             (0xA6) 
#define COM_SIGID_LS_OtsAirTmp              (0xA7) 
#define COM_SIGID_LS_OtsAirTmpCrValV        (0xA8) 
#define COM_SIGID_LS_OtsAirTmpCrVal         (0xA9) 
#define COM_SIGID_LS_OtsAirTmpCrValMsk      (0xAA)
#define COM_SIGID_LS_VehDynYawRateV         (0xAB) 
#define COM_SIGID_LS_VehDynYawRate          (0xAC) 
#define COM_SIGID_LS_ACCAct370              (0xAD) 
#define COM_SIGID_LS_VehIdNmDig10_17        (0xAE) 
#define COM_SIGID_LS_VehIdNmDig2_9          (0xAF) 
#define COM_SIGID_LS_DgnInf_All             (0xB0) 
#define COM_SIGID_LS_DgnInf_Upa_Apa         (0xB1) 
#define COM_SIGID_LS_SysBkUpPwrMdV          (0xB2) 
#define COM_SIGID_LS_SysBkupPwrMdEn         (0xB3) 
#define COM_SIGID_LS_SysBkUpPwrMd           (0xB4) 
#define COM_SIGID_LS_ODIAI_DaTy             (0xB5) 
#define COM_SIGID_LS_ODIAI_FUCID            (0xB6) 
#define COM_SIGID_LS_ODIAI_DspMID           (0xB7) 
#define COM_SIGID_LS_ODIAI_ActnVal          (0xB8) 
#define COM_SIGID_LS_ODIAI_ActnID           (0xB9) 
#define COM_SIGID_LS_ODIAA_FUCID            (0xBA) 
#define COM_SIGID_LS_ODIAA_DspMID           (0xBB) 
#define COM_SIGID_LS_ODIAA_ActnVal          (0xBC) 
#define COM_SIGID_LS_ODIAA_ActnID           (0xBD) 
#define COM_SIGID_LS_ODIAA_DaTy             (0xBE) 
#define COM_SIGID_LS_EngRunAtv              (0xBF)
#define COM_SIGID_LS_TrnsVDA                (0xC0)
#define COM_SIGID_LS_EngVDA                 (0xC1) 
#define COM_SIGID_LS_TrnsShftLvrPosV        (0xC2)
#define COM_SIGID_LS_TrnsShftLvrPos         (0xC3)
#define COM_SIGID_LS_DDAjrSwAtvM            (0xC4) 
#define COM_SIGID_LS_DDAjrSwAtv             (0xC5) 
#define COM_SIGID_LS_TrnSwAct               (0xC6) 
#define COM_SIGID_LS_HazSwAtv               (0xC7)
#define COM_SIGID_LS_LftTrnLmpAtv           (0xC8) 
#define COM_SIGID_LS_RtTrnLmpAtv            (0xC9)
#define COM_SIGID_LS_OtsdAmbtLtLvlStatV     (0xCA) 
#define COM_SIGID_LS_OtsdAmbtLtLvlStat      (0xCB) 
#define COM_SIGID_LS_VehSpdAvgNDrvnV        (0xCC) 
#define COM_SIGID_LS_VehSpdAvgNDrvn         (0xCD)
#define COM_SIGID_LS_DistRollCntAvgDrvnV    (0xCE)
#define COM_SIGID_LS_DistRollCntAvgDrvn     (0xCF)
#define COM_SIGID_LS_VehSpdAvgDrvnV         (0xD0) 
#define COM_SIGID_LS_VehSpdAvgDrvn          (0xD1) 
#define COM_SIGID_LS_SysPwrMd               (0xD2) 
#define COM_SIGID_LS_SysPwrMdV              (0xD3)
#define COM_SIGID_LS_TeenDrvAct             (0xD4)
#define COM_SIGID_LS_RrEndCrrStat           (0xD5)
#define COM_SIGID_LS_TrlrHtchSwAtv          (0xD6)
#define COM_SIGID_LS_OAT_PT_EstV            (0xD7)
#define COM_SIGID_LS_OAT_PT_Est             (0xD8)
#define COM_SIGID_LS_EngCltTmpV             (0xD9)
#define COM_SIGID_LS_EngCltTmp              (0xDA)
#define COM_SIGID_LS_EngIntAirTmpV          (0xDB)
#define COM_SIGID_LS_EngIntAirTmp           (0xDC)
#define COM_SIGID_LS_OAT_PT_EstM            (0xDD)
#define COM_SIGID_LS_HptcStVbnStat          (0xDE)
#define COM_SIGID_LS_CrshAlrtDrvrSlctdType  (0xDF) 
#define COM_SIGID_LS_CrshAlrtStPrsnt        (0xE0)


#define COM_NUM_SIGNALS_RX (COM_NUM_SIGNALS_RX_UB + COM_NUM_SIGNALS_RX_UW + COM_NUM_SIGNALS_RX_SW + COM_NUM_SIGNALS_RX_UL + COM_NUM_SIGNALS_RX_ULL )

//Tx signal

//Send to CE
#define COM_SIGID_CE_StrWhlTctlFdbkReqActRC                            (0x0)        
#define COM_SIGID_CE_StrWhlTctlFdbkReqAct                              (0x1)        
#define COM_SIGID_CE_StrWhlTctlFdbkReqActProtVal                       (0x2)      
#define COM_SIGID_CE_SWAR_ReqActV                                      (0x3) 
#define COM_SIGID_CE_SWAR_ReqAct                                       (0x4) 
#define COM_SIGID_CE_SWAR_TrgtAng                                      (0x5) 
#define COM_SIGID_CE_StrWhlAngReqARC                                   (0x6)
#define COM_SIGID_CE_StrWhlAngReqPrtVal                                (0x7)
//Send to LS
#define COM_SIGID_LS_SC_SndTne                                         (0x8)        
#define COM_SIGID_LS_SndLocRtRr                                        (0x9)        
#define COM_SIGID_LS_SndLocLftRr                                       (0xA)      
#define COM_SIGID_LS_SndLocPasFr                                       (0xB) 
#define COM_SIGID_LS_SndLocDrFr                                        (0xC) 
#define COM_SIGID_LS_SC_SndCdnPrd                                      (0xD) 
#define COM_SIGID_LS_SC_NmofRp                                         (0xE)
#define COM_SIGID_LS_SC_SndDutCyc                                      (0xF)
#define COM_SIGID_LS_SndPriority                                       (0x10)
#define COM_SIGID_LS_FPAHptcStVbnRqSeqN                                (0x11) 
#define COM_SIGID_LS_FPAHptcStVbnReq                                   (0x12) 
#define COM_SIGID_LS_APAIconDispRq                                     (0x13)
#define COM_SIGID_LS_APAIconFilPctRq                                   (0x14)
#define COM_SIGID_LS_RPAHptcStVbRqSeqN                                 (0x15) 
#define COM_SIGID_LS_RPAHptcStVbnReq                                   (0x16) 
#define COM_SIGID_LS_SBZASysClnIndOn                                   (0x17) 
#define COM_SIGID_LS_SBZASysOffIndOn                                   (0x18)
#define COM_SIGID_LS_SBZASysSrvIndOn                                   (0x19)
#define COM_SIGID_LS_SBZATmpUnvIndOn                                   (0x1A) 
#define COM_SIGID_LS_LftLnChgThrt                                      (0x1B) 
#define COM_SIGID_LS_PARtRgn1ObjStat                                   (0x1C)
#define COM_SIGID_LS_PrkAstRtSysStat                                   (0x1D)
#define COM_SIGID_LS_PARtRgn3ObjStat                                   (0x1E) 
#define COM_SIGID_LS_PARtRgn2ObjStat                                   (0x1F) 
#define COM_SIGID_LS_PrkAstRrSysStat                                   (0x20) 
#define COM_SIGID_LS_PrkAsstRrExtdDist                                 (0x21)
#define COM_SIGID_LS_PARrRgn1ObjStat                                   (0x22)
#define COM_SIGID_LS_PARrRgn2ObjStat                                   (0x23) 
#define COM_SIGID_LS_PARrRgn3ObjStat                                   (0x24) 
#define COM_SIGID_LS_PARrRgn4ObjStat                                   (0x25) 
#define COM_SIGID_LS_PALtRgn1ObjStat                                   (0x26)
#define COM_SIGID_LS_PrkAstLtSysStat                                   (0x27) 
#define COM_SIGID_LS_PALtRgn3ObjStat                                   (0x28) 
#define COM_SIGID_LS_PALtRgn2ObjStat                                   (0x29) 
#define COM_SIGID_LS_PrkAsstClnPrkAstIO                                (0x2A) 
#define COM_SIGID_LS_PrkAsstDisablIO                                   (0x2B) 
#define COM_SIGID_LS_PrkAstFld                                         (0x2C) 
#define COM_SIGID_LS_PrkAstSnrsBlk                                     (0x2D)
#define COM_SIGID_LS_PrkAstSnsDistrbdIO                                (0x2E) 
#define COM_SIGID_LS_TnDrvPrkAstOffUnbIO                               (0x2F) 
#define COM_SIGID_LS_PrkAstOprtrDsrdStat_1D0                           (0x30) 
#define COM_SIGID_LS_PrkAstFrSysStat                                   (0x31)
#define COM_SIGID_LS_PrkAstAdvSysAct                                   (0x32)
#define COM_SIGID_LS_PrkAsstFrtExtdDist                                (0x33)
#define COM_SIGID_LS_PAFrtRgn1ObjStat                                  (0x34)
#define COM_SIGID_LS_PAFrtRgn2ObjStat                                  (0x35)
#define COM_SIGID_LS_PAFrtRgn3ObjStat                                  (0x36)
#define COM_SIGID_LS_PAFrtRgn4ObjStat                                  (0x37)
#define COM_SIGID_LS_PrkAstRrSysStatUnfltd                             (0x38) 
#define COM_SIGID_LS_PrkAstRrExtdDstUnfltd                             (0x39)
#define COM_SIGID_LS_PrkAstFntnSnsDstrbdIO                             (0x3A) 
#define COM_SIGID_LS_PrkAstFntnSnrsBlkd                                (0x3B) 
#define COM_SIGID_LS_PrkAstFntnFld                                     (0x3C) 
#define COM_SIGID_LS_PrkAstFntnDsbldIO                                 (0x3D)
#define COM_SIGID_LS_PrkAstFntnClnPrkAstIO                             (0x3E)
#define COM_SIGID_LS_ClsnMtgtnInhbtReqtd                               (0x3F)
#define COM_SIGID_LS_PrkAstRrObjSnsngAct                               (0x40)
#define COM_SIGID_LS_PARrRgn3ObjStatUnfltd                             (0x41)
#define COM_SIGID_LS_PARrRgn4ObjStatUnfltd                             (0x42)
#define COM_SIGID_LS_PARrRgn1ObjStatUnfltd                             (0x43)
#define COM_SIGID_LS_PARrRgn2ObjStatUnfltd                             (0x44)
#define COM_SIGID_LS_ODD_InvldData                                     (0x45)
#define COM_SIGID_LS_ODD_DataType                                      (0x46)
#define COM_SIGID_LS_ODD_FUCID                                         (0x47)
#define COM_SIGID_LS_ODD_DataId                                        (0x48)
#define COM_SIGID_LS_ODD_DataVal                                       (0x49)
#define COM_SIGID_LS_ODIE_EvID                                         (0x4A)
#define COM_SIGID_LS_ODIE_FUCID                                        (0x4B)
#define COM_SIGID_LS_ODIE_MultiFrRetCh                                 (0x4C)
#define COM_SIGID_LS_ODIEDD_Data2Value                                 (0x4D)
#define COM_SIGID_LS_ODIEDD_Data1Value                                 (0x4E)
#define COM_SIGID_LS_ODIEDD_Data4Value                                 (0x4F)
#define COM_SIGID_LS_ODIEDD_Data3Value                                 (0x50)
#define COM_SIGID_LS_ODIEDD_Data7Value                                 (0x51)
#define COM_SIGID_LS_ODIEDD_Data6Value                                 (0x52)
#define COM_SIGID_LS_ODIEDD_Data5Value                                 (0x53)
#define COM_SIGID_LS_ODIEDD_Data10Value                                (0x54)
#define COM_SIGID_LS_ODIEDD_Data9Value                                 (0x55)
#define COM_SIGID_LS_ODIEDD_Data8Value                                 (0x56)
#define COM_SIGID_LS_ODIEDD_Data12Value                                (0x57)
#define COM_SIGID_LS_ODIEDD_Data11Value                                (0x58)
#define COM_SIGID_LS_ODIEDD_Data15Value                                (0x59)
#define COM_SIGID_LS_ODIEDD_Data14Value                                (0x5A)
#define COM_SIGID_LS_ODIEDD_Data13Value                                (0x5B)
#define COM_SIGID_LS_ODIEDD_Data18Value                                (0x5C)
#define COM_SIGID_LS_ODIEDD_Data17Value                                (0x5D)
#define COM_SIGID_LS_ODIEDD_Data16Value                                (0x5E)
#define COM_SIGID_LS_ODIEDD_FUCID                                      (0x5F)
#define COM_SIGID_LS_ODII_FUCID                                        (0x60)
#define COM_SIGID_LS_ODII_ODIInd8                                      (0x61)
#define COM_SIGID_LS_ODII_ODIInd7                                      (0x62)
#define COM_SIGID_LS_ODII_ODIInd6                                      (0x63)
#define COM_SIGID_LS_ODII_ODIInd5                                      (0x64)
#define COM_SIGID_LS_ODII_ODIInd4                                      (0x65)
#define COM_SIGID_LS_ODII_ODIInd3                                      (0x66)
#define COM_SIGID_LS_ODII_ODIInd2                                      (0x67)
#define COM_SIGID_LS_ODII_ODIInd1                                      (0x68)
#define COM_SIGID_LS_ODII_ODIInd14                                     (0x69)
#define COM_SIGID_LS_ODII_ODIInd13                                     (0x6A)
#define COM_SIGID_LS_ODII_ODIInd12                                     (0x6B)
#define COM_SIGID_LS_ODII_ODIInd11                                     (0x6C)
#define COM_SIGID_LS_ODII_ODIInd10                                     (0x6D)
#define COM_SIGID_LS_ODII_ODIInd9                                      (0x6E)
#define COM_SIGID_LS_DTCI_DTCTriggered                                 (0x6F)
#define COM_SIGID_LS_DTCI_DTCSource                                    (0x70)
#define COM_SIGID_LS_DTCI_DTCNumber                                    (0x71)
#define COM_SIGID_LS_DTCI_DTCFailType                                  (0x72)
#define COM_SIGID_LS_DTCI_CodeSupported                                (0x73)
#define COM_SIGID_LS_DTCI_CurrentStatus                                (0x74)
#define COM_SIGID_LS_DTCI_TstNPsdCdClrdSt                              (0x75)
#define COM_SIGID_LS_DTCI_TstFldCdClrdStat                             (0x76)
#define COM_SIGID_LS_DTCI_HistStat                                     (0x77)
#define COM_SIGID_LS_DTCI_TstNPsdPwrUpSt                               (0x78)
#define COM_SIGID_LS_DTCI_TstFldPwrUpSt                                (0x79)
#define COM_SIGID_LS_DTCI_WrnIndRqdSt                                  (0x7A)
#define COM_SIGID_LS_DTCI_DTCFaultType                                 (0x7B)


#define COM_NUM_SIGNALS_TX (COM_NUM_SIGNALS_TX_UB + COM_NUM_SIGNALS_TX_UW + COM_NUM_SIGNALS_TX_SW + COM_NUM_SIGNALS_TX_UL)

/* Signals ID and NUM of signals end */
#define CANIF_DLC_LEN        (8)

/* Messgae buffer define start */

/*Rx message buffer definition*/
//Msg from CE
#define COM_Rx_CE_MSG_259_DLC_LEN        (7)
EXTERN unsigned char Com_Rx_CE_Msg_259_Buf[COM_Rx_CE_MSG_259_DLC_LEN];
#define COM_Rx_CE_MSG_101_DLC_LEN        (8)
EXTERN unsigned char Com_Rx_CE_Msg_101_Buf[COM_Rx_CE_MSG_101_DLC_LEN];
#define COM_Rx_CE_MSG_212_DLC_LEN        (8)
EXTERN unsigned char Com_Rx_CE_Msg_212_Buf[COM_Rx_CE_MSG_212_DLC_LEN];
#define COM_Rx_CE_MSG_348_DLC_LEN        (6)
EXTERN unsigned char Com_Rx_CE_Msg_348_Buf[COM_Rx_CE_MSG_348_DLC_LEN];
#define COM_Rx_CE_MSG_0C1_DLC_LEN        (8)
EXTERN unsigned char Com_Rx_CE_Msg_0C1_Buf[COM_Rx_CE_MSG_0C1_DLC_LEN];
#define COM_Rx_CE_MSG_335_DLC_LEN        (4)
EXTERN unsigned char Com_Rx_CE_Msg_335_Buf[COM_Rx_CE_MSG_335_DLC_LEN];
#define COM_Rx_CE_MSG_340_DLC_LEN        (8)
EXTERN unsigned char Com_Rx_CE_Msg_340_Buf[COM_Rx_CE_MSG_340_DLC_LEN];
#define COM_Rx_CE_MSG_130_DLC_LEN        (8)
EXTERN unsigned char Com_Rx_CE_Msg_130_Buf[COM_Rx_CE_MSG_130_DLC_LEN];
#define COM_Rx_CE_MSG_140_DLC_LEN        (8)
EXTERN unsigned char Com_Rx_CE_Msg_140_Buf[COM_Rx_CE_MSG_140_DLC_LEN];
#define COM_Rx_CE_MSG_34A_DLC_LEN        (6)
EXTERN unsigned char Com_Rx_CE_Msg_34A_Buf[COM_Rx_CE_MSG_34A_DLC_LEN];
#define COM_Rx_CE_MSG_0C5_DLC_LEN        (8)
EXTERN unsigned char Com_Rx_CE_Msg_0C5_Buf[COM_Rx_CE_MSG_0C5_DLC_LEN];
#define COM_Rx_CE_MSG_1E5_DLC_LEN        (8)
EXTERN unsigned char Com_Rx_CE_Msg_1E5_Buf[COM_Rx_CE_MSG_1E5_DLC_LEN];
#define COM_Rx_CE_MSG_1F5_DLC_LEN        (3)
EXTERN unsigned char Com_Rx_CE_Msg_1F5_Buf[COM_Rx_CE_MSG_1F5_DLC_LEN];


//Msg from LS

#define COM_Rx_LS_MSG_110_DLC_LEN        (8)
#define COM_Rx_LS_MSG_170_DLC_LEN        (8)
#define COM_Rx_LS_MSG_115_DLC_LEN        (8)
#define COM_Rx_LS_MSG_205_DLC_LEN        (1)
#define COM_Rx_LS_MSG_117_DLC_LEN        (8)
#define COM_Rx_LS_MSG_318_DLC_LEN        (1)
#define COM_Rx_LS_MSG_165_DLC_LEN        (8)
#define COM_Rx_LS_MSG_166_DLC_LEN        (8)
#define COM_Rx_LS_MSG_209_DLC_LEN        (3)
#define COM_Rx_LS_MSG_316_DLC_LEN        (5)
#define COM_Rx_LS_MSG_106_DLC_LEN        (5)
#define COM_Rx_LS_MSG_1DA_DLC_LEN        (1)
#define COM_Rx_LS_MSG_118_DLC_LEN        (8)
#define COM_Rx_LS_MSG_56A_DLC_LEN        (8)
#define COM_Rx_LS_MSG_56B_DLC_LEN        (8)
#define COM_Rx_LS_MSG_56C_DLC_LEN        (8)
#define COM_Rx_LS_MSG_573_DLC_LEN        (8)
#define COM_Rx_LS_MSG_572_DLC_LEN        (8)
#define COM_Rx_LS_MSG_574_DLC_LEN        (8)
#define COM_Rx_LS_MSG_212_DLC_LEN        (3)
#define COM_Rx_LS_MSG_12E_DLC_LEN        (1)
#define COM_Rx_LS_MSG_3AA_DLC_LEN        (3)
#define COM_Rx_LS_MSG_122_DLC_LEN        (1)
#define COM_Rx_LS_MSG_121_DLC_LEN        (1)
#define COM_Rx_LS_MSG_306_DLC_LEN        (8)
#define COM_Rx_LS_MSG_1C2_DLC_LEN        (2)
#define COM_Rx_LS_MSG_101_DLC_LEN        (8)
#define COM_Rx_LS_MSG_259_DLC_LEN        (8)
#define COM_Rx_LS_MSG_108_DLC_LEN        (8)
#define COM_Rx_LS_MSG_120_DLC_LEN        (8)
#define COM_Rx_LS_MSG_764_DLC_LEN        (8)
#define COM_Rx_LS_MSG_762_DLC_LEN        (8)
#define COM_Rx_LS_MSG_638_DLC_LEN        (8)
#define COM_Rx_LS_MSG_35C_DLC_LEN        (8)
#define COM_Rx_LS_MSG_3BE_DLC_LEN        (4)
EXTERN unsigned char Com_Rx_LS_Msg_110_Buf[COM_Rx_LS_MSG_110_DLC_LEN];
EXTERN unsigned char Com_Rx_LS_Msg_170_Buf[COM_Rx_LS_MSG_170_DLC_LEN];
EXTERN unsigned char Com_Rx_LS_Msg_115_Buf[COM_Rx_LS_MSG_115_DLC_LEN];
EXTERN unsigned char Com_Rx_LS_Msg_205_Buf[COM_Rx_LS_MSG_205_DLC_LEN];
EXTERN unsigned char Com_Rx_LS_Msg_117_Buf[COM_Rx_LS_MSG_117_DLC_LEN];
EXTERN unsigned char Com_Rx_LS_Msg_318_Buf[COM_Rx_LS_MSG_318_DLC_LEN];
EXTERN unsigned char Com_Rx_LS_Msg_165_Buf[COM_Rx_LS_MSG_165_DLC_LEN];
EXTERN unsigned char Com_Rx_LS_Msg_166_Buf[COM_Rx_LS_MSG_166_DLC_LEN];
EXTERN unsigned char Com_Rx_LS_Msg_209_Buf[COM_Rx_LS_MSG_209_DLC_LEN];
EXTERN unsigned char Com_Rx_LS_Msg_316_Buf[COM_Rx_LS_MSG_316_DLC_LEN];
EXTERN unsigned char Com_Rx_LS_Msg_106_Buf[COM_Rx_LS_MSG_106_DLC_LEN];
EXTERN unsigned char Com_Rx_LS_Msg_1DA_Buf[COM_Rx_LS_MSG_1DA_DLC_LEN];
EXTERN unsigned char Com_Rx_LS_Msg_118_Buf[COM_Rx_LS_MSG_118_DLC_LEN];
EXTERN unsigned char Com_Rx_LS_Msg_56A_Buf[COM_Rx_LS_MSG_56A_DLC_LEN];
EXTERN unsigned char Com_Rx_LS_Msg_56B_Buf[COM_Rx_LS_MSG_56B_DLC_LEN];
EXTERN unsigned char Com_Rx_LS_Msg_56C_Buf[COM_Rx_LS_MSG_56C_DLC_LEN];
EXTERN unsigned char Com_Rx_LS_Msg_573_Buf[COM_Rx_LS_MSG_573_DLC_LEN];
EXTERN unsigned char Com_Rx_LS_Msg_572_Buf[COM_Rx_LS_MSG_572_DLC_LEN];
EXTERN unsigned char Com_Rx_LS_Msg_574_Buf[COM_Rx_LS_MSG_574_DLC_LEN];
EXTERN unsigned char Com_Rx_LS_Msg_212_Buf[COM_Rx_LS_MSG_212_DLC_LEN];
EXTERN unsigned char Com_Rx_LS_Msg_12E_Buf[COM_Rx_LS_MSG_12E_DLC_LEN];
EXTERN unsigned char Com_Rx_LS_Msg_3AA_Buf[COM_Rx_LS_MSG_3AA_DLC_LEN];
EXTERN unsigned char Com_Rx_LS_Msg_122_Buf[COM_Rx_LS_MSG_122_DLC_LEN];
EXTERN unsigned char Com_Rx_LS_Msg_121_Buf[COM_Rx_LS_MSG_121_DLC_LEN];
EXTERN unsigned char Com_Rx_LS_Msg_306_Buf[COM_Rx_LS_MSG_306_DLC_LEN];
EXTERN unsigned char Com_Rx_LS_Msg_1C2_Buf[COM_Rx_LS_MSG_1C2_DLC_LEN];
EXTERN unsigned char Com_Rx_LS_Msg_101_Buf[COM_Rx_LS_MSG_101_DLC_LEN];
EXTERN unsigned char Com_Rx_LS_Msg_259_Buf[COM_Rx_LS_MSG_259_DLC_LEN];
EXTERN unsigned char Com_Rx_LS_Msg_108_Buf[COM_Rx_LS_MSG_108_DLC_LEN];
EXTERN unsigned char Com_Rx_LS_Msg_120_Buf[COM_Rx_LS_MSG_120_DLC_LEN];
EXTERN unsigned char Com_Rx_LS_Msg_764_Buf[COM_Rx_LS_MSG_764_DLC_LEN];
EXTERN unsigned char Com_Rx_LS_Msg_762_Buf[COM_Rx_LS_MSG_762_DLC_LEN];
EXTERN unsigned char Com_Rx_LS_Msg_638_Buf[COM_Rx_LS_MSG_638_DLC_LEN];
EXTERN unsigned char Com_Rx_LS_Msg_35C_Buf[COM_Rx_LS_MSG_35C_DLC_LEN];
EXTERN unsigned char Com_Rx_LS_Msg_3BE_Buf[COM_Rx_LS_MSG_3BE_DLC_LEN];


//Msg from TESTER
#define COM_Rx_Dbg_MSG_75_DLC_LEN        (8)
EXTERN unsigned char Com_Rx_DBG_Msg_75_Buf[COM_Rx_Dbg_MSG_75_DLC_LEN];

/*Tx message buffer definition*/
//CE
#define COM_Tx_CE_MSG_337_DLC_LEN        (7)
EXTERN unsigned char Com_Tx_CE_Msg_337_Buf[COM_Tx_CE_MSG_337_DLC_LEN];

#define COM_Tx_CE_MSG_171_DLC_LEN        (7)
EXTERN unsigned char Com_Tx_CE_Msg_171_Buf[COM_Tx_CE_MSG_171_DLC_LEN];


//LS
#define COM_Tx_LS_MSG_12C_DLC_LEN        (5)
EXTERN unsigned char Com_Tx_LS_Msg_12C_Buf[COM_Tx_LS_MSG_12C_DLC_LEN];
#define COM_Tx_LS_MSG_1D0_DLC_LEN        (1)
EXTERN unsigned char Com_Tx_LS_Msg_1D0_Buf[COM_Tx_LS_MSG_1D0_DLC_LEN];
#define COM_Tx_LS_MSG_1D2_DLC_LEN        (4)
EXTERN unsigned char Com_Tx_LS_Msg_1D2_Buf[COM_Tx_LS_MSG_1D2_DLC_LEN];
#define COM_Tx_LS_MSG_1D4_DLC_LEN        (4)
EXTERN unsigned char Com_Tx_LS_Msg_1D4_Buf[COM_Tx_LS_MSG_1D4_DLC_LEN];
#define COM_Tx_LS_MSG_1D5_DLC_LEN        (2)
EXTERN unsigned char Com_Tx_LS_Msg_1D5_Buf[COM_Tx_LS_MSG_1D5_DLC_LEN];
#define COM_Tx_LS_MSG_1D6_DLC_LEN        (1)
EXTERN unsigned char Com_Tx_LS_Msg_1D6_Buf[COM_Tx_LS_MSG_1D6_DLC_LEN];
#define COM_Tx_LS_MSG_1D7_DLC_LEN        (2)
EXTERN unsigned char Com_Tx_LS_Msg_1D7_Buf[COM_Tx_LS_MSG_1D7_DLC_LEN];
#define COM_Tx_LS_MSG_1D8_DLC_LEN        (1)
EXTERN unsigned char Com_Tx_LS_Msg_1D8_Buf[COM_Tx_LS_MSG_1D8_DLC_LEN];
#define COM_Tx_LS_MSG_200_DLC_LEN        (5)
EXTERN unsigned char Com_Tx_LS_Msg_200_Buf[COM_Tx_LS_MSG_200_DLC_LEN];
#define COM_Tx_LS_MSG_396_DLC_LEN        (1)
EXTERN unsigned char Com_Tx_LS_Msg_396_Buf[COM_Tx_LS_MSG_396_DLC_LEN];
#define COM_Tx_LS_MSG_300_DLC_LEN        (7)
EXTERN unsigned char Com_Tx_LS_Msg_300_Buf[COM_Tx_LS_MSG_300_DLC_LEN];
#define COM_Tx_LS_MSG_559_DLC_LEN        (8)
EXTERN unsigned char Com_Tx_LS_Msg_559_Buf[COM_Tx_LS_MSG_559_DLC_LEN];
#define COM_Tx_LS_MSG_560_DLC_LEN        (4)
EXTERN unsigned char Com_Tx_LS_Msg_560_Buf[COM_Tx_LS_MSG_560_DLC_LEN];
#define COM_Tx_LS_MSG_565_DLC_LEN        (8)
EXTERN unsigned char Com_Tx_LS_Msg_565_Buf[COM_Tx_LS_MSG_565_DLC_LEN];
#define COM_Tx_LS_MSG_576_DLC_LEN        (8)
EXTERN unsigned char Com_Tx_LS_Msg_576_Buf[COM_Tx_LS_MSG_576_DLC_LEN];
#define COM_Tx_LS_MSG_581_DLC_LEN        (8)
EXTERN unsigned char Com_Tx_LS_Msg_581_Buf[COM_Tx_LS_MSG_581_DLC_LEN];
#define COM_Tx_LS_MSG_639_DLC_LEN        (8)
EXTERN unsigned char Com_Tx_LS_Msg_639_Buf[COM_Tx_LS_MSG_639_DLC_LEN];
#define COM_Tx_LS_MSG_659_DLC_LEN        (8)
EXTERN unsigned char Com_Tx_LS_Msg_659_Buf[COM_Tx_LS_MSG_659_DLC_LEN];

/* Messgae buffer define end */

/* Message transmit cyclic define start */
#define COM_MSG_CYCLIC_10MS                      (1)
#define COM_MSG_CYCLIC_20MS                      (2)
#define COM_MSG_CYCLIC_60MS                      (6)
#define COM_MSG_CYCLIC_100MS                     (10)
#define COM_MSG_CYCLIC_200MS                     (20)
#define COM_MSG_CYCLIC_500MS                     (50)
#define COM_MSG_CYCLIC_1000MS                    (100)
#define COM_MSG_CYCLIC_3000MS                    (300)


#define COM_MSG_CYCLIC_CASE_0                    (0)
#define COM_MSG_CYCLIC_CASE_1                    (1)
#define COM_MSG_CYCLIC_CASE_2                    (2)
#define COM_MSG_CYCLIC_CASE_3                    (3)
#define COM_MSG_CYCLIC_CASE_4                    (4)
#define COM_MSG_CYCLIC_CASE_5                    (5)
#define COM_MSG_CYCLIC_CASE_6                    (6)
#define COM_MSG_CYCLIC_CASE_7                    (7)
#define COM_MSG_CYCLIC_CASE_8                    (8)
#define COM_MSG_CYCLIC_CASE_9                    (9)
#define COM_MSG_CYCLIC_CASE_15                   (15)
#define COM_MSG_CYCLIC_CASE_30                   (30)
#define COM_MSG_CYCLIC_CASE_40                   (40)
#define COM_MSG_CYCLIC_CASE_50                   (50)
#define COM_MSG_CYCLIC_CASE_70                   (70)



/* Message transmit cyclic define end */

/* Message checksum pduID define start */
#define COM_MSG_CHKSUM_PDUID                     (0x16)

/* Message checksum pduID define end */

/*Tx Confirmation function Define Begin*/
extern void IlMsgODIIndication_LSConfirmation(void);
extern void IlMsgODIEvent_LSConfirmation(void);


#define Com_TxConfirmation_CeMsg337()                              
#define Com_TxConfirmation_CeMsg171()
#define Com_TxConfirmation_LsMsg559()
#define Com_TxConfirmation_LsMsg560()                IlMsgODIEvent_LSConfirmation()
#define Com_TxConfirmation_LsMsg565()                IlMsgODIIndication_LSConfirmation()
#define Com_TxConfirmation_LsMsg639()
#define Com_TxConfirmation_LsMsg659()

/*Tx Confirmation Function Define End*/

#undef EXTERN
#endif
