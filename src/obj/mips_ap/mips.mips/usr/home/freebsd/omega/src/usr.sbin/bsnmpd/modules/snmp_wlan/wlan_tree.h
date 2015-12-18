int	op_wlan_iface(struct snmp_context *, struct snmp_value *, u_int, u_int, enum snmp_op);
# define LEAF_wlanIfaceIndex 1
# define LEAF_wlanIfaceName 2
# define LEAF_wlanParentIfName 3
# define LEAF_wlanIfaceOperatingMode 4
# define LEAF_wlanIfaceFlags 5
# define LEAF_wlanIfaceBssid 6
# define LEAF_wlanIfaceLocalAddress 7
# define LEAF_wlanIfaceStatus 8
# define LEAF_wlanIfaceState 9
int	op_wlan_if_parent(struct snmp_context *, struct snmp_value *, u_int, u_int, enum snmp_op);
# define LEAF_wlanIfParentDriverCapabilities 1
# define LEAF_wlanIfParentCryptoCapabilities 2
# define LEAF_wlanIfParentHTCapabilities 3
int	op_wlan_iface_config(struct snmp_context *, struct snmp_value *, u_int, u_int, enum snmp_op);
# define LEAF_wlanIfacePacketBurst 1
# define LEAF_wlanIfaceCountryCode 2
# define LEAF_wlanIfaceRegDomain 3
# define LEAF_wlanIfaceDesiredSsid 4
# define LEAF_wlanIfaceDesiredChannel 5
# define LEAF_wlanIfaceDynamicFreqSelection 6
# define LEAF_wlanIfaceFastFrames 7
# define LEAF_wlanIfaceDturbo 8
# define LEAF_wlanIfaceTxPower 9
# define LEAF_wlanIfaceFragmentThreshold 10
# define LEAF_wlanIfaceRTSThreshold 11
# define LEAF_wlanIfaceWlanPrivacySubscribe 12
# define LEAF_wlanIfaceBgScan 13
# define LEAF_wlanIfaceBgScanIdle 14
# define LEAF_wlanIfaceBgScanInterval 15
# define LEAF_wlanIfaceBeaconMissedThreshold 16
# define LEAF_wlanIfaceDesiredBssid 17
# define LEAF_wlanIfaceRoamingMode 18
# define LEAF_wlanIfaceDot11d 19
# define LEAF_wlanIfaceDot11h 20
# define LEAF_wlanIfaceDynamicWds 21
# define LEAF_wlanIfacePowerSave 22
# define LEAF_wlanIfaceApBridge 23
# define LEAF_wlanIfaceBeaconInterval 24
# define LEAF_wlanIfaceDtimPeriod 25
# define LEAF_wlanIfaceHideSsid 26
# define LEAF_wlanIfaceInactivityProccess 27
# define LEAF_wlanIfaceDot11gProtMode 28
# define LEAF_wlanIfaceDot11gPureMode 29
# define LEAF_wlanIfaceDot11nPureMode 30
# define LEAF_wlanIfaceDot11nAmpdu 31
# define LEAF_wlanIfaceDot11nAmpduDensity 32
# define LEAF_wlanIfaceDot11nAmpduLimit 33
# define LEAF_wlanIfaceDot11nAmsdu 34
# define LEAF_wlanIfaceDot11nAmsduLimit 35
# define LEAF_wlanIfaceDot11nHighThroughput 36
# define LEAF_wlanIfaceDot11nHTCompatible 37
# define LEAF_wlanIfaceDot11nHTProtMode 38
# define LEAF_wlanIfaceDot11nRIFS 39
# define LEAF_wlanIfaceDot11nShortGI 40
# define LEAF_wlanIfaceDot11nSMPSMode 41
# define LEAF_wlanIfaceTdmaSlot 42
# define LEAF_wlanIfaceTdmaSlotCount 43
# define LEAF_wlanIfaceTdmaSlotLength 44
# define LEAF_wlanIfaceTdmaBeaconInterval 45
int	op_wlan_if_peer(struct snmp_context *, struct snmp_value *, u_int, u_int, enum snmp_op);
# define LEAF_wlanIfacePeerAddress 1
# define LEAF_wlanIfacePeerAssociationId 2
# define LEAF_wlanIfacePeerVlanTag 3
# define LEAF_wlanIfacePeerFrequency 4
# define LEAF_wlanIfacePeerCurrentTXRate 5
# define LEAF_wlanIfacePeerRxSignalStrength 6
# define LEAF_wlanIfacePeerIdleTimer 7
# define LEAF_wlanIfacePeerTxSequenceNo 8
# define LEAF_wlanIfacePeerRxSequenceNo 9
# define LEAF_wlanIfacePeerTxPower 10
# define LEAF_wlanIfacePeerCapabilities 11
# define LEAF_wlanIfacePeerFlags 12
int	op_wlan_channels(struct snmp_context *, struct snmp_value *, u_int, u_int, enum snmp_op);
# define LEAF_wlanIfaceChannelIeeeId 2
# define LEAF_wlanIfaceChannelType 3
# define LEAF_wlanIfaceChannelFlags 4
# define LEAF_wlanIfaceChannelFrequency 5
# define LEAF_wlanIfaceChannelMaxRegPower 6
# define LEAF_wlanIfaceChannelMaxTxPower 7
# define LEAF_wlanIfaceChannelMinTxPower 8
# define LEAF_wlanIfaceChannelState 9
# define LEAF_wlanIfaceChannelHTExtension 10
# define LEAF_wlanIfaceChannelMaxAntennaGain 11
int	op_wlan_roam_params(struct snmp_context *, struct snmp_value *, u_int, u_int, enum snmp_op);
# define LEAF_wlanIfRoamRxSignalStrength 2
# define LEAF_wlanIfRoamTxRateThreshold 3
int	op_wlan_tx_params(struct snmp_context *, struct snmp_value *, u_int, u_int, enum snmp_op);
# define LEAF_wlanIfTxUnicastRate 2
# define LEAF_wlanIfTxMcastRate 3
# define LEAF_wlanIfTxMgmtRate 4
# define LEAF_wlanIfTxMaxRetryCount 5
int	op_wlan_scan_config(struct snmp_context *, struct snmp_value *, u_int, u_int, enum snmp_op);
# define LEAF_wlanScanFlags 1
# define LEAF_wlanScanDuration 2
# define LEAF_wlanScanMinChannelDwellTime 3
# define LEAF_wlanScanMaxChannelDwellTime 4
# define LEAF_wlanScanConfigStatus 5
int	op_wlan_scan_results(struct snmp_context *, struct snmp_value *, u_int, u_int, enum snmp_op);
# define LEAF_wlanScanResultID 1
# define LEAF_wlanScanResultBssid 2
# define LEAF_wlanScanResultChannel 3
# define LEAF_wlanScanResultRate 4
# define LEAF_wlanScanResultNoise 5
# define LEAF_wlanScanResultBeaconInterval 6
# define LEAF_wlanScanResultCapabilities 7
int	op_wlan_iface_stats(struct snmp_context *, struct snmp_value *, u_int, u_int, enum snmp_op);
# define LEAF_wlanStatsRxBadVersion 1
# define LEAF_wlanStatsRxTooShort 2
# define LEAF_wlanStatsRxWrongBssid 3
# define LEAF_wlanStatsRxDiscardedDups 4
# define LEAF_wlanStatsRxWrongDir 5
# define LEAF_wlanStatsRxDiscardMcastEcho 6
# define LEAF_wlanStatsRxDiscardNoAssoc 7
# define LEAF_wlanStatsRxWepNoPrivacy 8
# define LEAF_wlanStatsRxWepUnencrypted 9
# define LEAF_wlanStatsRxWepFailed 10
# define LEAF_wlanStatsRxDecapsulationFailed 11
# define LEAF_wlanStatsRxDiscardMgmt 12
# define LEAF_wlanStatsRxControl 13
# define LEAF_wlanStatsRxBeacon 14
# define LEAF_wlanStatsRxRateSetTooBig 15
# define LEAF_wlanStatsRxElemMissing 16
# define LEAF_wlanStatsRxElemTooBig 17
# define LEAF_wlanStatsRxElemTooSmall 18
# define LEAF_wlanStatsRxElemUnknown 19
# define LEAF_wlanStatsRxChannelMismatch 20
# define LEAF_wlanStatsRxDropped 21
# define LEAF_wlanStatsRxSsidMismatch 22
# define LEAF_wlanStatsRxAuthNotSupported 23
# define LEAF_wlanStatsRxAuthFailed 24
# define LEAF_wlanStatsRxAuthCM 25
# define LEAF_wlanStatsRxAssocWrongBssid 26
# define LEAF_wlanStatsRxAssocNoAuth 27
# define LEAF_wlanStatsRxAssocCapMismatch 28
# define LEAF_wlanStatsRxAssocNoRateMatch 29
# define LEAF_wlanStatsRxBadWpaIE 30
# define LEAF_wlanStatsRxDeauthenticate 31
# define LEAF_wlanStatsRxDisassociate 32
# define LEAF_wlanStatsRxUnknownSubtype 33
# define LEAF_wlanStatsRxFailedNoBuf 34
# define LEAF_wlanStatsRxBadAuthRequest 35
# define LEAF_wlanStatsRxUnAuthorized 36
# define LEAF_wlanStatsRxBadKeyId 37
# define LEAF_wlanStatsRxCCMPSeqViolation 38
# define LEAF_wlanStatsRxCCMPBadFormat 39
# define LEAF_wlanStatsRxCCMPFailedMIC 40
# define LEAF_wlanStatsRxTKIPSeqViolation 41
# define LEAF_wlanStatsRxTKIPBadFormat 42
# define LEAF_wlanStatsRxTKIPFailedMIC 43
# define LEAF_wlanStatsRxTKIPFailedICV 44
# define LEAF_wlanStatsRxDiscardACL 45
# define LEAF_wlanStatsTxFailedNoBuf 46
# define LEAF_wlanStatsTxFailedNoNode 47
# define LEAF_wlanStatsTxUnknownMgmt 48
# define LEAF_wlanStatsTxBadCipher 49
# define LEAF_wlanStatsTxNoDefKey 50
# define LEAF_wlanStatsTxFragmented 51
# define LEAF_wlanStatsTxFragmentsCreated 52
# define LEAF_wlanStatsActiveScans 53
# define LEAF_wlanStatsPassiveScans 54
# define LEAF_wlanStatsTimeoutInactivity 55
# define LEAF_wlanStatsCryptoNoMem 56
# define LEAF_wlanStatsSwCryptoTKIP 57
# define LEAF_wlanStatsSwCryptoTKIPEnMIC 58
# define LEAF_wlanStatsSwCryptoTKIPDeMIC 59
# define LEAF_wlanStatsCryptoTKIPCM 60
# define LEAF_wlanStatsSwCryptoCCMP 61
# define LEAF_wlanStatsSwCryptoWEP 62
# define LEAF_wlanStatsCryptoCipherKeyRejected 63
# define LEAF_wlanStatsCryptoNoKey 64
# define LEAF_wlanStatsCryptoDeleteKeyFailed 65
# define LEAF_wlanStatsCryptoUnknownCipher 66
# define LEAF_wlanStatsCryptoAttachFailed 67
# define LEAF_wlanStatsCryptoKeyFailed 68
# define LEAF_wlanStatsCryptoEnMICFailed 69
# define LEAF_wlanStatsIBSSCapMismatch 70
# define LEAF_wlanStatsUnassocStaPSPoll 71
# define LEAF_wlanStatsBadAidPSPoll 72
# define LEAF_wlanStatsEmptyPSPoll 73
# define LEAF_wlanStatsRxFFBadHdr 74
# define LEAF_wlanStatsRxFFTooShort 75
# define LEAF_wlanStatsRxFFSplitError 76
# define LEAF_wlanStatsRxFFDecap 77
# define LEAF_wlanStatsTxFFEncap 78
# define LEAF_wlanStatsRxBadBintval 79
# define LEAF_wlanStatsRxDemicFailed 80
# define LEAF_wlanStatsRxDefragFailed 81
# define LEAF_wlanStatsRxMgmt 82
# define LEAF_wlanStatsRxActionMgmt 83
# define LEAF_wlanStatsRxAMSDUTooShort 84
# define LEAF_wlanStatsRxAMSDUSplitError 85
# define LEAF_wlanStatsRxAMSDUDecap 86
# define LEAF_wlanStatsTxAMSDUEncap 87
# define LEAF_wlanStatsAMPDUBadBAR 88
# define LEAF_wlanStatsAMPDUOowBar 89
# define LEAF_wlanStatsAMPDUMovedBAR 90
# define LEAF_wlanStatsAMPDURxBAR 91
# define LEAF_wlanStatsAMPDURxOor 92
# define LEAF_wlanStatsAMPDURxCopied 93
# define LEAF_wlanStatsAMPDURxDropped 94
# define LEAF_wlanStatsTxDiscardBadState 95
# define LEAF_wlanStatsTxFailedNoAssoc 96
# define LEAF_wlanStatsTxClassifyFailed 97
# define LEAF_wlanStatsDwdsMcastDiscard 98
# define LEAF_wlanStatsHTAssocRejectNoHT 99
# define LEAF_wlanStatsHTAssocDowngrade 100
# define LEAF_wlanStatsHTAssocRateMismatch 101
# define LEAF_wlanStatsAMPDURxAge 102
# define LEAF_wlanStatsAMPDUMoved 103
# define LEAF_wlanStatsADDBADisabledReject 104
# define LEAF_wlanStatsADDBANoRequest 105
# define LEAF_wlanStatsADDBABadToken 106
# define LEAF_wlanStatsADDBABadPolicy 107
# define LEAF_wlanStatsAMPDUStopped 108
# define LEAF_wlanStatsAMPDUStopFailed 109
# define LEAF_wlanStatsAMPDURxReorder 110
# define LEAF_wlanStatsScansBackground 111
# define LEAF_wlanLastDeauthReason 112
# define LEAF_wlanLastDissasocReason 113
# define LEAF_wlanLastAuthFailReason 114
# define LEAF_wlanStatsBeaconMissedEvents 115
# define LEAF_wlanStatsRxDiscardBadStates 116
# define LEAF_wlanStatsFFFlushed 117
# define LEAF_wlanStatsTxControlFrames 118
# define LEAF_wlanStatsAMPDURexmt 119
# define LEAF_wlanStatsAMPDURexmtFailed 120
# define LEAF_wlanStatsReset 121
int	op_wlan_wep_iface(struct snmp_context *, struct snmp_value *, u_int, u_int, enum snmp_op);
# define LEAF_wlanWepMode 1
# define LEAF_wlanWepDefTxKey 2
int	op_wlan_wep_key(struct snmp_context *, struct snmp_value *, u_int, u_int, enum snmp_op);
# define LEAF_wlanWepKeyID 1
# define LEAF_wlanWepKeyLength 2
# define LEAF_wlanWepKeySet 3
# define LEAF_wlanWepKeyHash 4
# define LEAF_wlanWepKeyStatus 5
int	op_wlan_mac_access_control(struct snmp_context *, struct snmp_value *, u_int, u_int, enum snmp_op);
# define LEAF_wlanMACAccessControlPolicy 1
# define LEAF_wlanMACAccessControlNacl 2
# define LEAF_wlanMACAccessControlFlush 3
int	op_wlan_mac_acl_mac(struct snmp_context *, struct snmp_value *, u_int, u_int, enum snmp_op);
# define LEAF_wlanMACAccessControlMAC 1
# define LEAF_wlanMACAccessControlMACStatus 2
int	op_wlan_mesh_config(struct snmp_context *, struct snmp_value *, u_int, u_int, enum snmp_op);
# define LEAF_wlanMeshMaxRetries 1
# define LEAF_wlanMeshConfirmTimeout 2
# define LEAF_wlanMeshHoldingTimeout 3
# define LEAF_wlanMeshRetryTimeout 4
int	op_wlan_mesh_iface(struct snmp_context *, struct snmp_value *, u_int, u_int, enum snmp_op);
# define LEAF_wlanMeshId 1
# define LEAF_wlanMeshTTL 2
# define LEAF_wlanMeshPeeringEnabled 3
# define LEAF_wlanMeshForwardingEnabled 4
# define LEAF_wlanMeshMetric 5
# define LEAF_wlanMeshPath 6
# define LEAF_wlanMeshRoutesFlush 7
int	op_wlan_mesh_neighbor(struct snmp_context *, struct snmp_value *, u_int, u_int, enum snmp_op);
# define LEAF_wlanMeshNeighborAddress 1
# define LEAF_wlanMeshNeighborFrequency 2
# define LEAF_wlanMeshNeighborLocalId 3
# define LEAF_wlanMeshNeighborPeerId 4
# define LEAF_wlanMeshNeighborPeerState 5
# define LEAF_wlanMeshNeighborCurrentTXRate 6
# define LEAF_wlanMeshNeighborRxSignalStrength 7
# define LEAF_wlanMeshNeighborIdleTimer 8
# define LEAF_wlanMeshNeighborTxSequenceNo 9
# define LEAF_wlanMeshNeighborRxSequenceNo 10
int	op_wlan_mesh_route(struct snmp_context *, struct snmp_value *, u_int, u_int, enum snmp_op);
# define LEAF_wlanMeshRouteDestination 1
# define LEAF_wlanMeshRouteNextHop 2
# define LEAF_wlanMeshRouteHops 3
# define LEAF_wlanMeshRouteMetric 4
# define LEAF_wlanMeshRouteLifeTime 5
# define LEAF_wlanMeshRouteLastMseq 6
# define LEAF_wlanMeshRouteFlags 7
# define LEAF_wlanMeshRouteStatus 8
int	op_wlan_mesh_stats(struct snmp_context *, struct snmp_value *, u_int, u_int, enum snmp_op);
# define LEAF_wlanMeshDroppedBadSta 1
# define LEAF_wlanMeshDroppedNoLink 2
# define LEAF_wlanMeshNoFwdTtl 3
# define LEAF_wlanMeshNoFwdBuf 4
# define LEAF_wlanMeshNoFwdTooShort 5
# define LEAF_wlanMeshNoFwdDisabled 6
# define LEAF_wlanMeshNoFwdPathUnknown 7
# define LEAF_wlanMeshDroppedBadAE 8
# define LEAF_wlanMeshRouteAddFailed 9
# define LEAF_wlanMeshDroppedNoProxy 10
# define LEAF_wlanMeshDroppedMisaligned 11
int	op_wlan_hwmp_config(struct snmp_context *, struct snmp_value *, u_int, u_int, enum snmp_op);
# define LEAF_wlanHWMPRouteInactiveTimeout 1
# define LEAF_wlanHWMPRootAnnounceInterval 2
# define LEAF_wlanHWMPRootInterval 3
# define LEAF_wlanHWMPRootTimeout 4
# define LEAF_wlanHWMPPathLifetime 5
# define LEAF_wlanHWMPReplyForwardBit 6
# define LEAF_wlanHWMPTargetOnlyBit 7
int	op_wlan_hwmp_iface(struct snmp_context *, struct snmp_value *, u_int, u_int, enum snmp_op);
# define LEAF_wlanHWMPRootMode 1
# define LEAF_wlanHWMPMaxHops 2
int	op_wlan_hwmp_stats(struct snmp_context *, struct snmp_value *, u_int, u_int, enum snmp_op);
# define LEAF_wlanMeshHWMPWrongSeqNo 1
# define LEAF_wlanMeshHWMPTxRootPREQ 2
# define LEAF_wlanMeshHWMPTxRootRANN 3
# define LEAF_wlanMeshHWMPProxy 4

#ifdef SNMPTREE_TYPES

#ifndef wlanHWMPRootMode_defined__
#define wlanHWMPRootMode_defined__
/*
 * From <stdin>:661
 */
enum wlanHWMPRootMode {
	wlanHWMPRootMode_disabled = 1,
	wlanHWMPRootMode_normal = 2,
	wlanHWMPRootMode_proactive = 3,
	wlanHWMPRootMode_rann = 4,
};
#define	STROFF_wlanHWMPRootMode 1
#define	STRING_wlanHWMPRootMode \
	[0] "wlanHWMPRootMode_disabled",\
	[1] "wlanHWMPRootMode_normal",\
	[2] "wlanHWMPRootMode_proactive",\
	[3] "wlanHWMPRootMode_rann",\

#endif /* wlanHWMPRootMode_defined__ */

#ifndef wlanMeshRouteFlags_defined__
#define wlanMeshRouteFlags_defined__
/*
 * From <stdin>:627
 */
enum wlanMeshRouteFlags {
	wlanMeshRouteFlags_valid = 1,
	wlanMeshRouteFlags_proxy = 2,
};
#define	STROFF_wlanMeshRouteFlags 1
#define	STRING_wlanMeshRouteFlags \
	[0] "wlanMeshRouteFlags_valid",\
	[1] "wlanMeshRouteFlags_proxy",\

#endif /* wlanMeshRouteFlags_defined__ */

#ifndef wlanMeshRoutesFlush_defined__
#define wlanMeshRoutesFlush_defined__
/*
 * From <stdin>:602
 */
enum wlanMeshRoutesFlush {
	wlanMeshRoutesFlush_no_op = 0,
	wlanMeshRoutesFlush_flush = 1,
};
#define	STROFF_wlanMeshRoutesFlush 0
#define	STRING_wlanMeshRoutesFlush \
	[0] "wlanMeshRoutesFlush_no_op",\
	[1] "wlanMeshRoutesFlush_flush",\

#endif /* wlanMeshRoutesFlush_defined__ */

#ifndef wlanMeshPath_defined__
#define wlanMeshPath_defined__
/*
 * From <stdin>:601
 */
enum wlanMeshPath {
	wlanMeshPath_unknown = 0,
	wlanMeshPath_hwmp = 1,
};
#define	STROFF_wlanMeshPath 0
#define	STRING_wlanMeshPath \
	[0] "wlanMeshPath_unknown",\
	[1] "wlanMeshPath_hwmp",\

#endif /* wlanMeshPath_defined__ */

#ifndef wlanMeshMetric_defined__
#define wlanMeshMetric_defined__
/*
 * From <stdin>:600
 */
enum wlanMeshMetric {
	wlanMeshMetric_unknown = 0,
	wlanMeshMetric_airtime = 1,
};
#define	STROFF_wlanMeshMetric 0
#define	STRING_wlanMeshMetric \
	[0] "wlanMeshMetric_unknown",\
	[1] "wlanMeshMetric_airtime",\

#endif /* wlanMeshMetric_defined__ */

#ifndef wlanMeshForwardingEnabled_defined__
#define wlanMeshForwardingEnabled_defined__
/*
 * From <stdin>:599
 */
enum wlanMeshForwardingEnabled {
	wlanMeshForwardingEnabled_true = 1,
	wlanMeshForwardingEnabled_false = 2,
};
#define	STROFF_wlanMeshForwardingEnabled 1
#define	STRING_wlanMeshForwardingEnabled \
	[0] "wlanMeshForwardingEnabled_true",\
	[1] "wlanMeshForwardingEnabled_false",\

#endif /* wlanMeshForwardingEnabled_defined__ */

#ifndef wlanMeshPeeringEnabled_defined__
#define wlanMeshPeeringEnabled_defined__
/*
 * From <stdin>:598
 */
enum wlanMeshPeeringEnabled {
	wlanMeshPeeringEnabled_true = 1,
	wlanMeshPeeringEnabled_false = 2,
};
#define	STROFF_wlanMeshPeeringEnabled 1
#define	STRING_wlanMeshPeeringEnabled \
	[0] "wlanMeshPeeringEnabled_true",\
	[1] "wlanMeshPeeringEnabled_false",\

#endif /* wlanMeshPeeringEnabled_defined__ */

#ifndef wlanMACAccessControlFlush_defined__
#define wlanMACAccessControlFlush_defined__
/*
 * From <stdin>:578
 */
enum wlanMACAccessControlFlush {
	wlanMACAccessControlFlush_no_op = 0,
	wlanMACAccessControlFlush_flush = 1,
};
#define	STROFF_wlanMACAccessControlFlush 0
#define	STRING_wlanMACAccessControlFlush \
	[0] "wlanMACAccessControlFlush_no_op",\
	[1] "wlanMACAccessControlFlush_flush",\

#endif /* wlanMACAccessControlFlush_defined__ */

#ifndef wlanMACAccessControlPolicy_defined__
#define wlanMACAccessControlPolicy_defined__
/*
 * From <stdin>:576
 */
enum wlanMACAccessControlPolicy {
	wlanMACAccessControlPolicy_open = 0,
	wlanMACAccessControlPolicy_allow = 1,
	wlanMACAccessControlPolicy_deny = 2,
	wlanMACAccessControlPolicy_radius = 7,
};
#define	STROFF_wlanMACAccessControlPolicy 0
#define	STRING_wlanMACAccessControlPolicy \
	[0] "wlanMACAccessControlPolicy_open",\
	[1] "wlanMACAccessControlPolicy_allow",\
	[2] "wlanMACAccessControlPolicy_deny",\
	[7] "wlanMACAccessControlPolicy_radius",\

#endif /* wlanMACAccessControlPolicy_defined__ */

#ifndef wlanWepMode_defined__
#define wlanWepMode_defined__
/*
 * From <stdin>:561
 */
enum wlanWepMode {
	wlanWepMode_off = 0,
	wlanWepMode_on = 1,
	wlanWepMode_mixed = 2,
};
#define	STROFF_wlanWepMode 0
#define	STRING_wlanWepMode \
	[0] "wlanWepMode_off",\
	[1] "wlanWepMode_on",\
	[2] "wlanWepMode_mixed",\

#endif /* wlanWepMode_defined__ */

#ifndef wlanStatsReset_defined__
#define wlanStatsReset_defined__
/*
 * From <stdin>:555
 */
enum wlanStatsReset {
	wlanStatsReset_no_op = 1,
	wlanStatsReset_clear = 2,
};
#define	STROFF_wlanStatsReset 1
#define	STRING_wlanStatsReset \
	[0] "wlanStatsReset_no_op",\
	[1] "wlanStatsReset_clear",\

#endif /* wlanStatsReset_defined__ */

#ifndef wlanScanConfigStatus_defined__
#define wlanScanConfigStatus_defined__
/*
 * From <stdin>:419
 */
enum wlanScanConfigStatus {
	wlanScanConfigStatus_unknown = 0,
	wlanScanConfigStatus_notStarted = 1,
	wlanScanConfigStatus_running = 2,
	wlanScanConfigStatus_finished = 3,
	wlanScanConfigStatus_cancel = 4,
};
#define	STROFF_wlanScanConfigStatus 0
#define	STRING_wlanScanConfigStatus \
	[0] "wlanScanConfigStatus_unknown",\
	[1] "wlanScanConfigStatus_notStarted",\
	[2] "wlanScanConfigStatus_running",\
	[3] "wlanScanConfigStatus_finished",\
	[4] "wlanScanConfigStatus_cancel",\

#endif /* wlanScanConfigStatus_defined__ */

#ifndef wlanIfaceDot11nSMPSMode_defined__
#define wlanIfaceDot11nSMPSMode_defined__
/*
 * From <stdin>:362
 */
enum wlanIfaceDot11nSMPSMode {
	wlanIfaceDot11nSMPSMode_disabled = 1,
	wlanIfaceDot11nSMPSMode_static = 2,
	wlanIfaceDot11nSMPSMode_dynamic = 3,
};
#define	STROFF_wlanIfaceDot11nSMPSMode 1
#define	STRING_wlanIfaceDot11nSMPSMode \
	[0] "wlanIfaceDot11nSMPSMode_disabled",\
	[1] "wlanIfaceDot11nSMPSMode_static",\
	[2] "wlanIfaceDot11nSMPSMode_dynamic",\

#endif /* wlanIfaceDot11nSMPSMode_defined__ */

#ifndef wlanIfaceDot11nShortGI_defined__
#define wlanIfaceDot11nShortGI_defined__
/*
 * From <stdin>:361
 */
enum wlanIfaceDot11nShortGI {
	wlanIfaceDot11nShortGI_true = 1,
	wlanIfaceDot11nShortGI_false = 2,
};
#define	STROFF_wlanIfaceDot11nShortGI 1
#define	STRING_wlanIfaceDot11nShortGI \
	[0] "wlanIfaceDot11nShortGI_true",\
	[1] "wlanIfaceDot11nShortGI_false",\

#endif /* wlanIfaceDot11nShortGI_defined__ */

#ifndef wlanIfaceDot11nRIFS_defined__
#define wlanIfaceDot11nRIFS_defined__
/*
 * From <stdin>:360
 */
enum wlanIfaceDot11nRIFS {
	wlanIfaceDot11nRIFS_true = 1,
	wlanIfaceDot11nRIFS_false = 2,
};
#define	STROFF_wlanIfaceDot11nRIFS 1
#define	STRING_wlanIfaceDot11nRIFS \
	[0] "wlanIfaceDot11nRIFS_true",\
	[1] "wlanIfaceDot11nRIFS_false",\

#endif /* wlanIfaceDot11nRIFS_defined__ */

#ifndef wlanIfaceDot11nHTProtMode_defined__
#define wlanIfaceDot11nHTProtMode_defined__
/*
 * From <stdin>:359
 */
enum wlanIfaceDot11nHTProtMode {
	wlanIfaceDot11nHTProtMode_off = 1,
	wlanIfaceDot11nHTProtMode_rts = 2,
};
#define	STROFF_wlanIfaceDot11nHTProtMode 1
#define	STRING_wlanIfaceDot11nHTProtMode \
	[0] "wlanIfaceDot11nHTProtMode_off",\
	[1] "wlanIfaceDot11nHTProtMode_rts",\

#endif /* wlanIfaceDot11nHTProtMode_defined__ */

#ifndef wlanIfaceDot11nHTCompatible_defined__
#define wlanIfaceDot11nHTCompatible_defined__
/*
 * From <stdin>:358
 */
enum wlanIfaceDot11nHTCompatible {
	wlanIfaceDot11nHTCompatible_true = 1,
	wlanIfaceDot11nHTCompatible_false = 2,
};
#define	STROFF_wlanIfaceDot11nHTCompatible 1
#define	STRING_wlanIfaceDot11nHTCompatible \
	[0] "wlanIfaceDot11nHTCompatible_true",\
	[1] "wlanIfaceDot11nHTCompatible_false",\

#endif /* wlanIfaceDot11nHTCompatible_defined__ */

#ifndef wlanIfaceDot11nHighThroughput_defined__
#define wlanIfaceDot11nHighThroughput_defined__
/*
 * From <stdin>:357
 */
enum wlanIfaceDot11nHighThroughput {
	wlanIfaceDot11nHighThroughput_true = 1,
	wlanIfaceDot11nHighThroughput_false = 2,
};
#define	STROFF_wlanIfaceDot11nHighThroughput 1
#define	STRING_wlanIfaceDot11nHighThroughput \
	[0] "wlanIfaceDot11nHighThroughput_true",\
	[1] "wlanIfaceDot11nHighThroughput_false",\

#endif /* wlanIfaceDot11nHighThroughput_defined__ */

#ifndef wlanIfaceDot11nPureMode_defined__
#define wlanIfaceDot11nPureMode_defined__
/*
 * From <stdin>:351
 */
enum wlanIfaceDot11nPureMode {
	wlanIfaceDot11nPureMode_true = 1,
	wlanIfaceDot11nPureMode_false = 2,
};
#define	STROFF_wlanIfaceDot11nPureMode 1
#define	STRING_wlanIfaceDot11nPureMode \
	[0] "wlanIfaceDot11nPureMode_true",\
	[1] "wlanIfaceDot11nPureMode_false",\

#endif /* wlanIfaceDot11nPureMode_defined__ */

#ifndef wlanIfaceDot11gPureMode_defined__
#define wlanIfaceDot11gPureMode_defined__
/*
 * From <stdin>:350
 */
enum wlanIfaceDot11gPureMode {
	wlanIfaceDot11gPureMode_true = 1,
	wlanIfaceDot11gPureMode_false = 2,
};
#define	STROFF_wlanIfaceDot11gPureMode 1
#define	STRING_wlanIfaceDot11gPureMode \
	[0] "wlanIfaceDot11gPureMode_true",\
	[1] "wlanIfaceDot11gPureMode_false",\

#endif /* wlanIfaceDot11gPureMode_defined__ */

#ifndef wlanIfaceDot11gProtMode_defined__
#define wlanIfaceDot11gProtMode_defined__
/*
 * From <stdin>:349
 */
enum wlanIfaceDot11gProtMode {
	wlanIfaceDot11gProtMode_off = 1,
	wlanIfaceDot11gProtMode_cts = 2,
	wlanIfaceDot11gProtMode_rtscts = 3,
};
#define	STROFF_wlanIfaceDot11gProtMode 1
#define	STRING_wlanIfaceDot11gProtMode \
	[0] "wlanIfaceDot11gProtMode_off",\
	[1] "wlanIfaceDot11gProtMode_cts",\
	[2] "wlanIfaceDot11gProtMode_rtscts",\

#endif /* wlanIfaceDot11gProtMode_defined__ */

#ifndef wlanIfaceInactivityProccess_defined__
#define wlanIfaceInactivityProccess_defined__
/*
 * From <stdin>:348
 */
enum wlanIfaceInactivityProccess {
	wlanIfaceInactivityProccess_true = 1,
	wlanIfaceInactivityProccess_false = 2,
};
#define	STROFF_wlanIfaceInactivityProccess 1
#define	STRING_wlanIfaceInactivityProccess \
	[0] "wlanIfaceInactivityProccess_true",\
	[1] "wlanIfaceInactivityProccess_false",\

#endif /* wlanIfaceInactivityProccess_defined__ */

#ifndef wlanIfaceHideSsid_defined__
#define wlanIfaceHideSsid_defined__
/*
 * From <stdin>:347
 */
enum wlanIfaceHideSsid {
	wlanIfaceHideSsid_true = 1,
	wlanIfaceHideSsid_false = 2,
};
#define	STROFF_wlanIfaceHideSsid 1
#define	STRING_wlanIfaceHideSsid \
	[0] "wlanIfaceHideSsid_true",\
	[1] "wlanIfaceHideSsid_false",\

#endif /* wlanIfaceHideSsid_defined__ */

#ifndef wlanIfaceApBridge_defined__
#define wlanIfaceApBridge_defined__
/*
 * From <stdin>:344
 */
enum wlanIfaceApBridge {
	wlanIfaceApBridge_true = 1,
	wlanIfaceApBridge_false = 2,
};
#define	STROFF_wlanIfaceApBridge 1
#define	STRING_wlanIfaceApBridge \
	[0] "wlanIfaceApBridge_true",\
	[1] "wlanIfaceApBridge_false",\

#endif /* wlanIfaceApBridge_defined__ */

#ifndef wlanIfacePowerSave_defined__
#define wlanIfacePowerSave_defined__
/*
 * From <stdin>:343
 */
enum wlanIfacePowerSave {
	wlanIfacePowerSave_true = 1,
	wlanIfacePowerSave_false = 2,
};
#define	STROFF_wlanIfacePowerSave 1
#define	STRING_wlanIfacePowerSave \
	[0] "wlanIfacePowerSave_true",\
	[1] "wlanIfacePowerSave_false",\

#endif /* wlanIfacePowerSave_defined__ */

#ifndef wlanIfaceDynamicWds_defined__
#define wlanIfaceDynamicWds_defined__
/*
 * From <stdin>:342
 */
enum wlanIfaceDynamicWds {
	wlanIfaceDynamicWds_true = 1,
	wlanIfaceDynamicWds_false = 2,
};
#define	STROFF_wlanIfaceDynamicWds 1
#define	STRING_wlanIfaceDynamicWds \
	[0] "wlanIfaceDynamicWds_true",\
	[1] "wlanIfaceDynamicWds_false",\

#endif /* wlanIfaceDynamicWds_defined__ */

#ifndef wlanIfaceDot11h_defined__
#define wlanIfaceDot11h_defined__
/*
 * From <stdin>:341
 */
enum wlanIfaceDot11h {
	wlanIfaceDot11h_true = 1,
	wlanIfaceDot11h_false = 2,
};
#define	STROFF_wlanIfaceDot11h 1
#define	STRING_wlanIfaceDot11h \
	[0] "wlanIfaceDot11h_true",\
	[1] "wlanIfaceDot11h_false",\

#endif /* wlanIfaceDot11h_defined__ */

#ifndef wlanIfaceDot11d_defined__
#define wlanIfaceDot11d_defined__
/*
 * From <stdin>:340
 */
enum wlanIfaceDot11d {
	wlanIfaceDot11d_true = 1,
	wlanIfaceDot11d_false = 2,
};
#define	STROFF_wlanIfaceDot11d 1
#define	STRING_wlanIfaceDot11d \
	[0] "wlanIfaceDot11d_true",\
	[1] "wlanIfaceDot11d_false",\

#endif /* wlanIfaceDot11d_defined__ */

#ifndef wlanIfaceRoamingMode_defined__
#define wlanIfaceRoamingMode_defined__
/*
 * From <stdin>:339
 */
enum wlanIfaceRoamingMode {
	wlanIfaceRoamingMode_device = 1,
	wlanIfaceRoamingMode_auto = 2,
	wlanIfaceRoamingMode_manual = 3,
};
#define	STROFF_wlanIfaceRoamingMode 1
#define	STRING_wlanIfaceRoamingMode \
	[0] "wlanIfaceRoamingMode_device",\
	[1] "wlanIfaceRoamingMode_auto",\
	[2] "wlanIfaceRoamingMode_manual",\

#endif /* wlanIfaceRoamingMode_defined__ */

#ifndef wlanIfaceBgScan_defined__
#define wlanIfaceBgScan_defined__
/*
 * From <stdin>:334
 */
enum wlanIfaceBgScan {
	wlanIfaceBgScan_true = 1,
	wlanIfaceBgScan_false = 2,
};
#define	STROFF_wlanIfaceBgScan 1
#define	STRING_wlanIfaceBgScan \
	[0] "wlanIfaceBgScan_true",\
	[1] "wlanIfaceBgScan_false",\

#endif /* wlanIfaceBgScan_defined__ */

#ifndef wlanIfaceWlanPrivacySubscribe_defined__
#define wlanIfaceWlanPrivacySubscribe_defined__
/*
 * From <stdin>:333
 */
enum wlanIfaceWlanPrivacySubscribe {
	wlanIfaceWlanPrivacySubscribe_true = 1,
	wlanIfaceWlanPrivacySubscribe_false = 2,
};
#define	STROFF_wlanIfaceWlanPrivacySubscribe 1
#define	STRING_wlanIfaceWlanPrivacySubscribe \
	[0] "wlanIfaceWlanPrivacySubscribe_true",\
	[1] "wlanIfaceWlanPrivacySubscribe_false",\

#endif /* wlanIfaceWlanPrivacySubscribe_defined__ */

#ifndef wlanIfaceDturbo_defined__
#define wlanIfaceDturbo_defined__
/*
 * From <stdin>:329
 */
enum wlanIfaceDturbo {
	wlanIfaceDturbo_true = 1,
	wlanIfaceDturbo_false = 2,
};
#define	STROFF_wlanIfaceDturbo 1
#define	STRING_wlanIfaceDturbo \
	[0] "wlanIfaceDturbo_true",\
	[1] "wlanIfaceDturbo_false",\

#endif /* wlanIfaceDturbo_defined__ */

#ifndef wlanIfaceFastFrames_defined__
#define wlanIfaceFastFrames_defined__
/*
 * From <stdin>:328
 */
enum wlanIfaceFastFrames {
	wlanIfaceFastFrames_true = 1,
	wlanIfaceFastFrames_false = 2,
};
#define	STROFF_wlanIfaceFastFrames 1
#define	STRING_wlanIfaceFastFrames \
	[0] "wlanIfaceFastFrames_true",\
	[1] "wlanIfaceFastFrames_false",\

#endif /* wlanIfaceFastFrames_defined__ */

#ifndef wlanIfaceDynamicFreqSelection_defined__
#define wlanIfaceDynamicFreqSelection_defined__
/*
 * From <stdin>:327
 */
enum wlanIfaceDynamicFreqSelection {
	wlanIfaceDynamicFreqSelection_true = 1,
	wlanIfaceDynamicFreqSelection_false = 2,
};
#define	STROFF_wlanIfaceDynamicFreqSelection 1
#define	STRING_wlanIfaceDynamicFreqSelection \
	[0] "wlanIfaceDynamicFreqSelection_true",\
	[1] "wlanIfaceDynamicFreqSelection_false",\

#endif /* wlanIfaceDynamicFreqSelection_defined__ */

#ifndef wlanIfacePacketBurst_defined__
#define wlanIfacePacketBurst_defined__
/*
 * From <stdin>:322
 */
enum wlanIfacePacketBurst {
	wlanIfacePacketBurst_true = 1,
	wlanIfacePacketBurst_false = 2,
};
#define	STROFF_wlanIfacePacketBurst 1
#define	STRING_wlanIfacePacketBurst \
	[0] "wlanIfacePacketBurst_true",\
	[1] "wlanIfacePacketBurst_false",\

#endif /* wlanIfacePacketBurst_defined__ */

#ifndef wlanIfaceState_defined__
#define wlanIfaceState_defined__
/*
 * From <stdin>:312
 */
enum wlanIfaceState {
	wlanIfaceState_up = 1,
	wlanIfaceState_down = 2,
};
#define	STROFF_wlanIfaceState 1
#define	STRING_wlanIfaceState \
	[0] "wlanIfaceState_up",\
	[1] "wlanIfaceState_down",\

#endif /* wlanIfaceState_defined__ */

#ifndef WlanMeshNeighborPeerStateType_defined__
#define WlanMeshNeighborPeerStateType_defined__
/*
 * From <stdin>:284
 */
enum WlanMeshNeighborPeerStateType {
	WlanMeshNeighborPeerStateType_idle = 0,
	WlanMeshNeighborPeerStateType_openTx = 1,
	WlanMeshNeighborPeerStateType_openRx = 2,
	WlanMeshNeighborPeerStateType_confirmRx = 3,
	WlanMeshNeighborPeerStateType_established = 4,
	WlanMeshNeighborPeerStateType_closing = 5,
};
#define	STROFF_WlanMeshNeighborPeerStateType 0
#define	STRING_WlanMeshNeighborPeerStateType \
	[0] "WlanMeshNeighborPeerStateType_idle",\
	[1] "WlanMeshNeighborPeerStateType_openTx",\
	[2] "WlanMeshNeighborPeerStateType_openRx",\
	[3] "WlanMeshNeighborPeerStateType_confirmRx",\
	[4] "WlanMeshNeighborPeerStateType_established",\
	[5] "WlanMeshNeighborPeerStateType_closing",\

#endif /* WlanMeshNeighborPeerStateType_defined__ */

#ifndef WlanScanFlagsType_defined__
#define WlanScanFlagsType_defined__
/*
 * From <stdin>:272
 */
enum WlanScanFlagsType {
	WlanScanFlagsType_noSelection = 1,
	WlanScanFlagsType_activeScan = 2,
	WlanScanFlagsType_pickFirst = 3,
	WlanScanFlagsType_backgroundScan = 4,
	WlanScanFlagsType_once = 5,
	WlanScanFlagsType_noBroadcast = 6,
	WlanScanFlagsType_noAutoSequencing = 7,
	WlanScanFlagsType_flushCashe = 8,
	WlanScanFlagsType_chechCashe = 9,
};
#define	STROFF_WlanScanFlagsType 1
#define	STRING_WlanScanFlagsType \
	[0] "WlanScanFlagsType_noSelection",\
	[1] "WlanScanFlagsType_activeScan",\
	[2] "WlanScanFlagsType_pickFirst",\
	[3] "WlanScanFlagsType_backgroundScan",\
	[4] "WlanScanFlagsType_once",\
	[5] "WlanScanFlagsType_noBroadcast",\
	[6] "WlanScanFlagsType_noAutoSequencing",\
	[7] "WlanScanFlagsType_flushCashe",\
	[8] "WlanScanFlagsType_chechCashe",\

#endif /* WlanScanFlagsType_defined__ */

#ifndef WlanChannelType_defined__
#define WlanChannelType_defined__
/*
 * From <stdin>:261
 */
enum WlanChannelType {
	WlanChannelType_fhss = 1,
	WlanChannelType_dot11a = 2,
	WlanChannelType_dot11b = 3,
	WlanChannelType_dot11g = 4,
	WlanChannelType_tenMHz = 5,
	WlanChannelType_fiveMHz = 6,
	WlanChannelType_turbo = 7,
	WlanChannelType_ht = 8,
};
#define	STROFF_WlanChannelType 1
#define	STRING_WlanChannelType \
	[0] "WlanChannelType_fhss",\
	[1] "WlanChannelType_dot11a",\
	[2] "WlanChannelType_dot11b",\
	[3] "WlanChannelType_dot11g",\
	[4] "WlanChannelType_tenMHz",\
	[5] "WlanChannelType_fiveMHz",\
	[6] "WlanChannelType_turbo",\
	[7] "WlanChannelType_ht",\

#endif /* WlanChannelType_defined__ */

#ifndef WlanIfPhyMode_defined__
#define WlanIfPhyMode_defined__
/*
 * From <stdin>:246
 */
enum WlanIfPhyMode {
	WlanIfPhyMode_auto = 1,
	WlanIfPhyMode_dot11a = 2,
	WlanIfPhyMode_dot11b = 3,
	WlanIfPhyMode_dot11g = 4,
	WlanIfPhyMode_fh = 5,
	WlanIfPhyMode_turboA = 6,
	WlanIfPhyMode_turboG = 7,
	WlanIfPhyMode_sturboA = 8,
	WlanIfPhyMode_dot11na = 9,
	WlanIfPhyMode_dot11ng = 10,
	WlanIfPhyMode_ofdmHalf = 11,
	WlanIfPhyMode_ofdmQuarter = 12,
};
#define	STROFF_WlanIfPhyMode 1
#define	STRING_WlanIfPhyMode \
	[0] "WlanIfPhyMode_auto",\
	[1] "WlanIfPhyMode_dot11a",\
	[2] "WlanIfPhyMode_dot11b",\
	[3] "WlanIfPhyMode_dot11g",\
	[4] "WlanIfPhyMode_fh",\
	[5] "WlanIfPhyMode_turboA",\
	[6] "WlanIfPhyMode_turboG",\
	[7] "WlanIfPhyMode_sturboA",\
	[8] "WlanIfPhyMode_dot11na",\
	[9] "WlanIfPhyMode_dot11ng",\
	[10] "WlanIfPhyMode_ofdmHalf",\
	[11] "WlanIfPhyMode_ofdmQuarter",\

#endif /* WlanIfPhyMode_defined__ */

#ifndef WlanIfaceChannelStateType_defined__
#define WlanIfaceChannelStateType_defined__
/*
 * From <stdin>:239
 */
enum WlanIfaceChannelStateType {
	WlanIfaceChannelStateType_radar = 1,
	WlanIfaceChannelStateType_cacDone = 2,
	WlanIfaceChannelStateType_interferenceDetected = 3,
	WlanIfaceChannelStateType_radarClear = 4,
};
#define	STROFF_WlanIfaceChannelStateType 1
#define	STRING_WlanIfaceChannelStateType \
	[0] "WlanIfaceChannelStateType_radar",\
	[1] "WlanIfaceChannelStateType_cacDone",\
	[2] "WlanIfaceChannelStateType_interferenceDetected",\
	[3] "WlanIfaceChannelStateType_radarClear",\

#endif /* WlanIfaceChannelStateType_defined__ */

#ifndef WlanIfaceChannelFlagsType_defined__
#define WlanIfaceChannelFlagsType_defined__
/*
 * From <stdin>:216
 */
enum WlanIfaceChannelFlagsType {
	WlanIfaceChannelFlagsType_turbo = 1,
	WlanIfaceChannelFlagsType_cck = 2,
	WlanIfaceChannelFlagsType_ofdm = 3,
	WlanIfaceChannelFlagsType_spectrum2Ghz = 4,
	WlanIfaceChannelFlagsType_spectrum5Ghz = 5,
	WlanIfaceChannelFlagsType_passiveScan = 6,
	WlanIfaceChannelFlagsType_dynamicCckOfdm = 7,
	WlanIfaceChannelFlagsType_gfsk = 8,
	WlanIfaceChannelFlagsType_spectrum900Mhz = 9,
	WlanIfaceChannelFlagsType_dot11aStaticTurbo = 10,
	WlanIfaceChannelFlagsType_halfRate = 11,
	WlanIfaceChannelFlagsType_quarterRate = 12,
	WlanIfaceChannelFlagsType_ht20 = 13,
	WlanIfaceChannelFlagsType_ht40u = 14,
	WlanIfaceChannelFlagsType_ht40d = 15,
	WlanIfaceChannelFlagsType_dfs = 16,
	WlanIfaceChannelFlagsType_xmit4ms = 17,
	WlanIfaceChannelFlagsType_noAdhoc = 18,
	WlanIfaceChannelFlagsType_noHostAp = 19,
	WlanIfaceChannelFlagsType_dot11d = 20,
};
#define	STROFF_WlanIfaceChannelFlagsType 1
#define	STRING_WlanIfaceChannelFlagsType \
	[0] "WlanIfaceChannelFlagsType_turbo",\
	[1] "WlanIfaceChannelFlagsType_cck",\
	[2] "WlanIfaceChannelFlagsType_ofdm",\
	[3] "WlanIfaceChannelFlagsType_spectrum2Ghz",\
	[4] "WlanIfaceChannelFlagsType_spectrum5Ghz",\
	[5] "WlanIfaceChannelFlagsType_passiveScan",\
	[6] "WlanIfaceChannelFlagsType_dynamicCckOfdm",\
	[7] "WlanIfaceChannelFlagsType_gfsk",\
	[8] "WlanIfaceChannelFlagsType_spectrum900Mhz",\
	[9] "WlanIfaceChannelFlagsType_dot11aStaticTurbo",\
	[10] "WlanIfaceChannelFlagsType_halfRate",\
	[11] "WlanIfaceChannelFlagsType_quarterRate",\
	[12] "WlanIfaceChannelFlagsType_ht20",\
	[13] "WlanIfaceChannelFlagsType_ht40u",\
	[14] "WlanIfaceChannelFlagsType_ht40d",\
	[15] "WlanIfaceChannelFlagsType_dfs",\
	[16] "WlanIfaceChannelFlagsType_xmit4ms",\
	[17] "WlanIfaceChannelFlagsType_noAdhoc",\
	[18] "WlanIfaceChannelFlagsType_noHostAp",\
	[19] "WlanIfaceChannelFlagsType_dot11d",\

#endif /* WlanIfaceChannelFlagsType_defined__ */

#ifndef WlanIfacePeerFlagsType_defined__
#define WlanIfacePeerFlagsType_defined__
/*
 * From <stdin>:195
 */
enum WlanIfacePeerFlagsType {
	WlanIfacePeerFlagsType_authorizedForData = 1,
	WlanIfacePeerFlagsType_qosEnabled = 2,
	WlanIfacePeerFlagsType_erpEnabled = 3,
	WlanIfacePeerFlagsType_powerSaveMode = 4,
	WlanIfacePeerFlagsType_authRefHeld = 5,
	WlanIfacePeerFlagsType_htEnabled = 6,
	WlanIfacePeerFlagsType_htCompat = 7,
	WlanIfacePeerFlagsType_wpsAssoc = 8,
	WlanIfacePeerFlagsType_tsnAssoc = 9,
	WlanIfacePeerFlagsType_ampduRx = 10,
	WlanIfacePeerFlagsType_ampduTx = 11,
	WlanIfacePeerFlagsType_mimoPowerSave = 12,
	WlanIfacePeerFlagsType_sendRts = 13,
	WlanIfacePeerFlagsType_rifs = 14,
	WlanIfacePeerFlagsType_shortGiHT20 = 15,
	WlanIfacePeerFlagsType_shortGiHT40 = 16,
	WlanIfacePeerFlagsType_amsduRx = 17,
	WlanIfacePeerFlagsType_amsduTx = 18,
};
#define	STROFF_WlanIfacePeerFlagsType 1
#define	STRING_WlanIfacePeerFlagsType \
	[0] "WlanIfacePeerFlagsType_authorizedForData",\
	[1] "WlanIfacePeerFlagsType_qosEnabled",\
	[2] "WlanIfacePeerFlagsType_erpEnabled",\
	[3] "WlanIfacePeerFlagsType_powerSaveMode",\
	[4] "WlanIfacePeerFlagsType_authRefHeld",\
	[5] "WlanIfacePeerFlagsType_htEnabled",\
	[6] "WlanIfacePeerFlagsType_htCompat",\
	[7] "WlanIfacePeerFlagsType_wpsAssoc",\
	[8] "WlanIfacePeerFlagsType_tsnAssoc",\
	[9] "WlanIfacePeerFlagsType_ampduRx",\
	[10] "WlanIfacePeerFlagsType_ampduTx",\
	[11] "WlanIfacePeerFlagsType_mimoPowerSave",\
	[12] "WlanIfacePeerFlagsType_sendRts",\
	[13] "WlanIfacePeerFlagsType_rifs",\
	[14] "WlanIfacePeerFlagsType_shortGiHT20",\
	[15] "WlanIfacePeerFlagsType_shortGiHT40",\
	[16] "WlanIfacePeerFlagsType_amsduRx",\
	[17] "WlanIfacePeerFlagsType_amsduTx",\

#endif /* WlanIfacePeerFlagsType_defined__ */

#ifndef WlanPeerCapabilityFlags_defined__
#define WlanPeerCapabilityFlags_defined__
/*
 * From <stdin>:181
 */
enum WlanPeerCapabilityFlags {
	WlanPeerCapabilityFlags_ess = 1,
	WlanPeerCapabilityFlags_ibss = 2,
	WlanPeerCapabilityFlags_cfPollable = 3,
	WlanPeerCapabilityFlags_cfPollRequest = 4,
	WlanPeerCapabilityFlags_privacy = 5,
	WlanPeerCapabilityFlags_shortPreamble = 6,
	WlanPeerCapabilityFlags_pbcc = 7,
	WlanPeerCapabilityFlags_channelAgility = 8,
	WlanPeerCapabilityFlags_shortSlotTime = 9,
	WlanPeerCapabilityFlags_rsn = 10,
	WlanPeerCapabilityFlags_dsssofdm = 11,
};
#define	STROFF_WlanPeerCapabilityFlags 1
#define	STRING_WlanPeerCapabilityFlags \
	[0] "WlanPeerCapabilityFlags_ess",\
	[1] "WlanPeerCapabilityFlags_ibss",\
	[2] "WlanPeerCapabilityFlags_cfPollable",\
	[3] "WlanPeerCapabilityFlags_cfPollRequest",\
	[4] "WlanPeerCapabilityFlags_privacy",\
	[5] "WlanPeerCapabilityFlags_shortPreamble",\
	[6] "WlanPeerCapabilityFlags_pbcc",\
	[7] "WlanPeerCapabilityFlags_channelAgility",\
	[8] "WlanPeerCapabilityFlags_shortSlotTime",\
	[9] "WlanPeerCapabilityFlags_rsn",\
	[10] "WlanPeerCapabilityFlags_dsssofdm",\

#endif /* WlanPeerCapabilityFlags_defined__ */

#ifndef WlanIfaceDot11nPduType_defined__
#define WlanIfaceDot11nPduType_defined__
/*
 * From <stdin>:174
 */
enum WlanIfaceDot11nPduType {
	WlanIfaceDot11nPduType_disabled = 0,
	WlanIfaceDot11nPduType_rxOnly = 1,
	WlanIfaceDot11nPduType_txOnly = 2,
	WlanIfaceDot11nPduType_txAndRx = 3,
};
#define	STROFF_WlanIfaceDot11nPduType 0
#define	STRING_WlanIfaceDot11nPduType \
	[0] "WlanIfaceDot11nPduType_disabled",\
	[1] "WlanIfaceDot11nPduType_rxOnly",\
	[2] "WlanIfaceDot11nPduType_txOnly",\
	[3] "WlanIfaceDot11nPduType_txAndRx",\

#endif /* WlanIfaceDot11nPduType_defined__ */

#ifndef WlanHTCaps_defined__
#define WlanHTCaps_defined__
/*
 * From <stdin>:154
 */
enum WlanHTCaps {
	WlanHTCaps_ldpc = 1,
	WlanHTCaps_chwidth40 = 2,
	WlanHTCaps_greenField = 3,
	WlanHTCaps_shortGi20 = 4,
	WlanHTCaps_shortGi40 = 5,
	WlanHTCaps_txStbc = 6,
	WlanHTCaps_delba = 7,
	WlanHTCaps_amsdu7935 = 8,
	WlanHTCaps_dssscck40 = 9,
	WlanHTCaps_psmp = 10,
	WlanHTCaps_fortyMHzIntolerant = 11,
	WlanHTCaps_lsigTxOpProt = 12,
	WlanHTCaps_htcAmpdu = 13,
	WlanHTCaps_htcAmsdu = 14,
	WlanHTCaps_htcHt = 15,
	WlanHTCaps_htcSmps = 16,
	WlanHTCaps_htcRifs = 17,
};
#define	STROFF_WlanHTCaps 1
#define	STRING_WlanHTCaps \
	[0] "WlanHTCaps_ldpc",\
	[1] "WlanHTCaps_chwidth40",\
	[2] "WlanHTCaps_greenField",\
	[3] "WlanHTCaps_shortGi20",\
	[4] "WlanHTCaps_shortGi40",\
	[5] "WlanHTCaps_txStbc",\
	[6] "WlanHTCaps_delba",\
	[7] "WlanHTCaps_amsdu7935",\
	[8] "WlanHTCaps_dssscck40",\
	[9] "WlanHTCaps_psmp",\
	[10] "WlanHTCaps_fortyMHzIntolerant",\
	[11] "WlanHTCaps_lsigTxOpProt",\
	[12] "WlanHTCaps_htcAmpdu",\
	[13] "WlanHTCaps_htcAmsdu",\
	[14] "WlanHTCaps_htcHt",\
	[15] "WlanHTCaps_htcSmps",\
	[16] "WlanHTCaps_htcRifs",\

#endif /* WlanHTCaps_defined__ */

#ifndef WlanCryptoCaps_defined__
#define WlanCryptoCaps_defined__
/*
 * From <stdin>:145
 */
enum WlanCryptoCaps {
	WlanCryptoCaps_wep = 1,
	WlanCryptoCaps_tkip = 2,
	WlanCryptoCaps_aes = 3,
	WlanCryptoCaps_aesCcm = 4,
	WlanCryptoCaps_tkipMic = 5,
	WlanCryptoCaps_ckip = 6,
};
#define	STROFF_WlanCryptoCaps 1
#define	STRING_WlanCryptoCaps \
	[0] "WlanCryptoCaps_wep",\
	[1] "WlanCryptoCaps_tkip",\
	[2] "WlanCryptoCaps_aes",\
	[3] "WlanCryptoCaps_aesCcm",\
	[4] "WlanCryptoCaps_tkipMic",\
	[5] "WlanCryptoCaps_ckip",\

#endif /* WlanCryptoCaps_defined__ */

#ifndef WlanDriverCaps_defined__
#define WlanDriverCaps_defined__
/*
 * From <stdin>:119
 */
enum WlanDriverCaps {
	WlanDriverCaps_station = 1,
	WlanDriverCaps_ieee8023encap = 2,
	WlanDriverCaps_athFastFrames = 3,
	WlanDriverCaps_athTurbo = 4,
	WlanDriverCaps_ibss = 5,
	WlanDriverCaps_pmgt = 6,
	WlanDriverCaps_hostAp = 7,
	WlanDriverCaps_ahDemo = 8,
	WlanDriverCaps_swRetry = 9,
	WlanDriverCaps_txPmgt = 10,
	WlanDriverCaps_shortSlot = 11,
	WlanDriverCaps_shortPreamble = 12,
	WlanDriverCaps_monitor = 13,
	WlanDriverCaps_dfs = 14,
	WlanDriverCaps_mbss = 15,
	WlanDriverCaps_wpa1 = 16,
	WlanDriverCaps_wpa2 = 17,
	WlanDriverCaps_burst = 18,
	WlanDriverCaps_wme = 19,
	WlanDriverCaps_wds = 20,
	WlanDriverCaps_bgScan = 21,
	WlanDriverCaps_txFrag = 22,
	WlanDriverCaps_tdma = 23,
};
#define	STROFF_WlanDriverCaps 1
#define	STRING_WlanDriverCaps \
	[0] "WlanDriverCaps_station",\
	[1] "WlanDriverCaps_ieee8023encap",\
	[2] "WlanDriverCaps_athFastFrames",\
	[3] "WlanDriverCaps_athTurbo",\
	[4] "WlanDriverCaps_ibss",\
	[5] "WlanDriverCaps_pmgt",\
	[6] "WlanDriverCaps_hostAp",\
	[7] "WlanDriverCaps_ahDemo",\
	[8] "WlanDriverCaps_swRetry",\
	[9] "WlanDriverCaps_txPmgt",\
	[10] "WlanDriverCaps_shortSlot",\
	[11] "WlanDriverCaps_shortPreamble",\
	[12] "WlanDriverCaps_monitor",\
	[13] "WlanDriverCaps_dfs",\
	[14] "WlanDriverCaps_mbss",\
	[15] "WlanDriverCaps_wpa1",\
	[16] "WlanDriverCaps_wpa2",\
	[17] "WlanDriverCaps_burst",\
	[18] "WlanDriverCaps_wme",\
	[19] "WlanDriverCaps_wds",\
	[20] "WlanDriverCaps_bgScan",\
	[21] "WlanDriverCaps_txFrag",\
	[22] "WlanDriverCaps_tdma",\

#endif /* WlanDriverCaps_defined__ */

#ifndef WlanIfaceFlagsType_defined__
#define WlanIfaceFlagsType_defined__
/*
 * From <stdin>:113
 */
enum WlanIfaceFlagsType {
	WlanIfaceFlagsType_uniqueBssid = 1,
	WlanIfaceFlagsType_noBeacons = 2,
	WlanIfaceFlagsType_wdsLegacy = 3,
};
#define	STROFF_WlanIfaceFlagsType 1
#define	STRING_WlanIfaceFlagsType \
	[0] "WlanIfaceFlagsType_uniqueBssid",\
	[1] "WlanIfaceFlagsType_noBeacons",\
	[2] "WlanIfaceFlagsType_wdsLegacy",\

#endif /* WlanIfaceFlagsType_defined__ */

#ifndef WlanIfaceOperatingModeType_defined__
#define WlanIfaceOperatingModeType_defined__
/*
 * From <stdin>:102
 */
enum WlanIfaceOperatingModeType {
	WlanIfaceOperatingModeType_ibss = 0,
	WlanIfaceOperatingModeType_station = 1,
	WlanIfaceOperatingModeType_wds = 2,
	WlanIfaceOperatingModeType_adhocDemo = 3,
	WlanIfaceOperatingModeType_hostAp = 4,
	WlanIfaceOperatingModeType_monitor = 5,
	WlanIfaceOperatingModeType_meshPoint = 6,
	WlanIfaceOperatingModeType_tdma = 7,
};
#define	STROFF_WlanIfaceOperatingModeType 0
#define	STRING_WlanIfaceOperatingModeType \
	[0] "WlanIfaceOperatingModeType_ibss",\
	[1] "WlanIfaceOperatingModeType_station",\
	[2] "WlanIfaceOperatingModeType_wds",\
	[3] "WlanIfaceOperatingModeType_adhocDemo",\
	[4] "WlanIfaceOperatingModeType_hostAp",\
	[5] "WlanIfaceOperatingModeType_monitor",\
	[6] "WlanIfaceOperatingModeType_meshPoint",\
	[7] "WlanIfaceOperatingModeType_tdma",\

#endif /* WlanIfaceOperatingModeType_defined__ */

#ifndef WlanMgmtReasonCode_defined__
#define WlanMgmtReasonCode_defined__
/*
 * From <stdin>:68
 */
enum WlanMgmtReasonCode {
	WlanMgmtReasonCode_unspecified = 1,
	WlanMgmtReasonCode_authenticationExpire = 2,
	WlanMgmtReasonCode_authenticationLeave = 3,
	WlanMgmtReasonCode_associationExpire = 4,
	WlanMgmtReasonCode_associationTooMany = 5,
	WlanMgmtReasonCode_notAuthenticated = 6,
	WlanMgmtReasonCode_notAssociated = 7,
	WlanMgmtReasonCode_associationLeave = 8,
	WlanMgmtReasonCode_associationNotAuthenticated = 9,
	WlanMgmtReasonCode_dissassocPwrcapBad = 10,
	WlanMgmtReasonCode_dissassocSuperchanBad = 11,
	WlanMgmtReasonCode_ieInvalid = 13,
	WlanMgmtReasonCode_micFailure = 14,
	WlanMgmtReasonCode_fourWayHandshakeTimeout = 15,
	WlanMgmtReasonCode_groupKeyUpdateTimeout = 16,
	WlanMgmtReasonCode_ieIn4FourWayDiffers = 17,
	WlanMgmtReasonCode_groupCipherInvalid = 18,
	WlanMgmtReasonCode_pairwiseCiherInvalid = 19,
	WlanMgmtReasonCode_akmpInvalid = 20,
	WlanMgmtReasonCode_unsupportedRsnIeVersion = 21,
	WlanMgmtReasonCode_invalidRsnIeCap = 22,
	WlanMgmtReasonCode_dot1xAuthFailed = 23,
	WlanMgmtReasonCode_cipherSuiteRejected = 24,
	WlanMgmtReasonCode_unspeciffiedQos = 32,
	WlanMgmtReasonCode_insufficientBw = 33,
	WlanMgmtReasonCode_tooManyFrames = 34,
	WlanMgmtReasonCode_outsideTxOp = 35,
	WlanMgmtReasonCode_leavingQbss = 36,
	WlanMgmtReasonCode_badMechanism = 37,
	WlanMgmtReasonCode_setupNeeded = 38,
	WlanMgmtReasonCode_timeout = 39,
};
#define	STROFF_WlanMgmtReasonCode 1
#define	STRING_WlanMgmtReasonCode \
	[0] "WlanMgmtReasonCode_unspecified",\
	[1] "WlanMgmtReasonCode_authenticationExpire",\
	[2] "WlanMgmtReasonCode_authenticationLeave",\
	[3] "WlanMgmtReasonCode_associationExpire",\
	[4] "WlanMgmtReasonCode_associationTooMany",\
	[5] "WlanMgmtReasonCode_notAuthenticated",\
	[6] "WlanMgmtReasonCode_notAssociated",\
	[7] "WlanMgmtReasonCode_associationLeave",\
	[8] "WlanMgmtReasonCode_associationNotAuthenticated",\
	[9] "WlanMgmtReasonCode_dissassocPwrcapBad",\
	[10] "WlanMgmtReasonCode_dissassocSuperchanBad",\
	[12] "WlanMgmtReasonCode_ieInvalid",\
	[13] "WlanMgmtReasonCode_micFailure",\
	[14] "WlanMgmtReasonCode_fourWayHandshakeTimeout",\
	[15] "WlanMgmtReasonCode_groupKeyUpdateTimeout",\
	[16] "WlanMgmtReasonCode_ieIn4FourWayDiffers",\
	[17] "WlanMgmtReasonCode_groupCipherInvalid",\
	[18] "WlanMgmtReasonCode_pairwiseCiherInvalid",\
	[19] "WlanMgmtReasonCode_akmpInvalid",\
	[20] "WlanMgmtReasonCode_unsupportedRsnIeVersion",\
	[21] "WlanMgmtReasonCode_invalidRsnIeCap",\
	[22] "WlanMgmtReasonCode_dot1xAuthFailed",\
	[23] "WlanMgmtReasonCode_cipherSuiteRejected",\
	[31] "WlanMgmtReasonCode_unspeciffiedQos",\
	[32] "WlanMgmtReasonCode_insufficientBw",\
	[33] "WlanMgmtReasonCode_tooManyFrames",\
	[34] "WlanMgmtReasonCode_outsideTxOp",\
	[35] "WlanMgmtReasonCode_leavingQbss",\
	[36] "WlanMgmtReasonCode_badMechanism",\
	[37] "WlanMgmtReasonCode_setupNeeded",\
	[38] "WlanMgmtReasonCode_timeout",\

#endif /* WlanMgmtReasonCode_defined__ */

#ifndef WlanRegDomainCode_defined__
#define WlanRegDomainCode_defined__
/*
 * From <stdin>:48
 */
enum WlanRegDomainCode {
	WlanRegDomainCode_fcc = 1,
	WlanRegDomainCode_ca = 2,
	WlanRegDomainCode_etsi = 3,
	WlanRegDomainCode_etsi2 = 4,
	WlanRegDomainCode_etsi3 = 5,
	WlanRegDomainCode_fcc3 = 6,
	WlanRegDomainCode_japan = 7,
	WlanRegDomainCode_korea = 8,
	WlanRegDomainCode_apac = 9,
	WlanRegDomainCode_apac2 = 10,
	WlanRegDomainCode_apac3 = 11,
	WlanRegDomainCode_row = 12,
	WlanRegDomainCode_none = 13,
	WlanRegDomainCode_debug = 14,
	WlanRegDomainCode_sr9 = 15,
	WlanRegDomainCode_xr9 = 16,
	WlanRegDomainCode_gz901 = 17,
};
#define	STROFF_WlanRegDomainCode 1
#define	STRING_WlanRegDomainCode \
	[0] "WlanRegDomainCode_fcc",\
	[1] "WlanRegDomainCode_ca",\
	[2] "WlanRegDomainCode_etsi",\
	[3] "WlanRegDomainCode_etsi2",\
	[4] "WlanRegDomainCode_etsi3",\
	[5] "WlanRegDomainCode_fcc3",\
	[6] "WlanRegDomainCode_japan",\
	[7] "WlanRegDomainCode_korea",\
	[8] "WlanRegDomainCode_apac",\
	[9] "WlanRegDomainCode_apac2",\
	[10] "WlanRegDomainCode_apac3",\
	[11] "WlanRegDomainCode_row",\
	[12] "WlanRegDomainCode_none",\
	[13] "WlanRegDomainCode_debug",\
	[14] "WlanRegDomainCode_sr9",\
	[15] "WlanRegDomainCode_xr9",\
	[16] "WlanRegDomainCode_gz901",\

#endif /* WlanRegDomainCode_defined__ */

#ifndef TruthValue_defined__
#define TruthValue_defined__
/*
 * From <stdin>:43
 */
enum TruthValue {
	TruthValue_true = 1,
	TruthValue_false = 2,
};
#define	STROFF_TruthValue 1
#define	STRING_TruthValue \
	[0] "TruthValue_true",\
	[1] "TruthValue_false",\

#endif /* TruthValue_defined__ */

#ifndef RowStatus_defined__
#define RowStatus_defined__
/*
 * From <stdin>:34
 */
enum RowStatus {
	RowStatus_active = 1,
	RowStatus_notInService = 2,
	RowStatus_notReady = 3,
	RowStatus_createAndGo = 4,
	RowStatus_createAndWait = 5,
	RowStatus_destroy = 6,
};
#define	STROFF_RowStatus 1
#define	STRING_RowStatus \
	[0] "RowStatus_active",\
	[1] "RowStatus_notInService",\
	[2] "RowStatus_notReady",\
	[3] "RowStatus_createAndGo",\
	[4] "RowStatus_createAndWait",\
	[5] "RowStatus_destroy",\

#endif /* RowStatus_defined__ */

#endif /* SNMPTREE_TYPES */

#define wlan_CTREE_SIZE 283
extern const struct snmp_node wlan_ctree[];
