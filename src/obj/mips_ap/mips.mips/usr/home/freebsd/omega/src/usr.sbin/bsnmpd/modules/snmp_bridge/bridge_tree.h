int	op_dot1d_base(struct snmp_context *, struct snmp_value *, u_int, u_int, enum snmp_op);
# define LEAF_dot1dBaseBridgeAddress 1
# define LEAF_dot1dBaseNumPorts 2
# define LEAF_dot1dBaseType 3
int	op_dot1d_base_port(struct snmp_context *, struct snmp_value *, u_int, u_int, enum snmp_op);
# define LEAF_dot1dBasePort 1
# define LEAF_dot1dBasePortIfIndex 2
# define LEAF_dot1dBasePortCircuit 3
# define LEAF_dot1dBasePortDelayExceededDiscards 4
# define LEAF_dot1dBasePortMtuExceededDiscards 5
int	op_dot1d_stp(struct snmp_context *, struct snmp_value *, u_int, u_int, enum snmp_op);
# define LEAF_dot1dStpProtocolSpecification 1
# define LEAF_dot1dStpPriority 2
# define LEAF_dot1dStpTimeSinceTopologyChange 3
# define LEAF_dot1dStpTopChanges 4
# define LEAF_dot1dStpDesignatedRoot 5
# define LEAF_dot1dStpRootCost 6
# define LEAF_dot1dStpRootPort 7
# define LEAF_dot1dStpMaxAge 8
# define LEAF_dot1dStpHelloTime 9
# define LEAF_dot1dStpHoldTime 10
# define LEAF_dot1dStpForwardDelay 11
# define LEAF_dot1dStpBridgeMaxAge 12
# define LEAF_dot1dStpBridgeHelloTime 13
# define LEAF_dot1dStpBridgeForwardDelay 14
int	op_dot1d_stp_port(struct snmp_context *, struct snmp_value *, u_int, u_int, enum snmp_op);
# define LEAF_dot1dStpPort 1
# define LEAF_dot1dStpPortPriority 2
# define LEAF_dot1dStpPortState 3
# define LEAF_dot1dStpPortEnable 4
# define LEAF_dot1dStpPortPathCost 5
# define LEAF_dot1dStpPortDesignatedRoot 6
# define LEAF_dot1dStpPortDesignatedCost 7
# define LEAF_dot1dStpPortDesignatedBridge 8
# define LEAF_dot1dStpPortDesignatedPort 9
# define LEAF_dot1dStpPortForwardTransitions 10
# define LEAF_dot1dStpVersion 16
# define LEAF_dot1dStpTxHoldCount 17
int	op_dot1d_stp_ext_port(struct snmp_context *, struct snmp_value *, u_int, u_int, enum snmp_op);
# define LEAF_dot1dStpPortProtocolMigration 1
# define LEAF_dot1dStpPortAdminEdgePort 2
# define LEAF_dot1dStpPortOperEdgePort 3
# define LEAF_dot1dStpPortAdminPointToPoint 4
# define LEAF_dot1dStpPortOperPointToPoint 5
# define LEAF_dot1dStpPortAdminPathCost 6
int	op_dot1d_tp(struct snmp_context *, struct snmp_value *, u_int, u_int, enum snmp_op);
# define LEAF_dot1dTpLearnedEntryDiscards 1
# define LEAF_dot1dTpAgingTime 2
int	op_dot1d_tp_fdb(struct snmp_context *, struct snmp_value *, u_int, u_int, enum snmp_op);
# define LEAF_dot1dTpFdbAddress 1
# define LEAF_dot1dTpFdbPort 2
# define LEAF_dot1dTpFdbStatus 3
int	op_dot1d_tp_port(struct snmp_context *, struct snmp_value *, u_int, u_int, enum snmp_op);
# define LEAF_dot1dTpPort 1
# define LEAF_dot1dTpPortMaxInfo 2
# define LEAF_dot1dTpPortInFrames 3
# define LEAF_dot1dTpPortOutFrames 4
# define LEAF_dot1dTpPortInDiscards 5
int	op_begemot_base_bridge(struct snmp_context *, struct snmp_value *, u_int, u_int, enum snmp_op);
# define LEAF_begemotBridgeBaseName 1
# define LEAF_begemotBridgeBaseAddress 2
# define LEAF_begemotBridgeBaseNumPorts 3
# define LEAF_begemotBridgeBaseType 4
# define LEAF_begemotBridgeBaseStatus 5
int	op_begemot_base_port(struct snmp_context *, struct snmp_value *, u_int, u_int, enum snmp_op);
# define LEAF_begemotBridgeBasePort 1
# define LEAF_begemotBridgeBasePortIfIndex 2
# define LEAF_begemotBridgeBaseSpanEnabled 3
# define LEAF_begemotBridgeBasePortDelayExceededDiscards 4
# define LEAF_begemotBridgeBasePortMtuExceededDiscards 5
# define LEAF_begemotBridgeBasePortStatus 6
# define LEAF_begemotBridgeBasePortPrivate 7
int	op_begemot_stp(struct snmp_context *, struct snmp_value *, u_int, u_int, enum snmp_op);
# define LEAF_begemotBridgeStpProtocolSpecification 1
# define LEAF_begemotBridgeStpPriority 2
# define LEAF_begemotBridgeStpTimeSinceTopologyChange 3
# define LEAF_begemotBridgeStpTopChanges 4
# define LEAF_begemotBridgeStpDesignatedRoot 5
# define LEAF_begemotBridgeStpRootCost 6
# define LEAF_begemotBridgeStpRootPort 7
# define LEAF_begemotBridgeStpMaxAge 8
# define LEAF_begemotBridgeStpHelloTime 9
# define LEAF_begemotBridgeStpHoldTime 10
# define LEAF_begemotBridgeStpForwardDelay 11
# define LEAF_begemotBridgeStpBridgeMaxAge 12
# define LEAF_begemotBridgeStpBridgeHelloTime 13
# define LEAF_begemotBridgeStpBridgeForwardDelay 14
# define LEAF_begemotBridgeStpVersion 15
# define LEAF_begemotBridgeStpTxHoldCount 16
int	op_begemot_stp_port(struct snmp_context *, struct snmp_value *, u_int, u_int, enum snmp_op);
# define LEAF_begemotBridgeStpPort 1
# define LEAF_begemotBridgeStpPortPriority 2
# define LEAF_begemotBridgeStpPortState 3
# define LEAF_begemotBridgeStpPortEnable 4
# define LEAF_begemotBridgeStpPortPathCost 5
# define LEAF_begemotBridgeStpPortDesignatedRoot 6
# define LEAF_begemotBridgeStpPortDesignatedCost 7
# define LEAF_begemotBridgeStpPortDesignatedBridge 8
# define LEAF_begemotBridgeStpPortDesignatedPort 9
# define LEAF_begemotBridgeStpPortForwardTransitions 10
int	op_begemot_stp_ext_port(struct snmp_context *, struct snmp_value *, u_int, u_int, enum snmp_op);
# define LEAF_begemotBridgeStpPortProtocolMigration 1
# define LEAF_begemotBridgeStpPortAdminEdgePort 2
# define LEAF_begemotBridgeStpPortOperEdgePort 3
# define LEAF_begemotBridgeStpPortAdminPointToPoint 4
# define LEAF_begemotBridgeStpPortOperPointToPoint 5
# define LEAF_begemotBridgeStpPortAdminPathCost 6
int	op_begemot_tp(struct snmp_context *, struct snmp_value *, u_int, u_int, enum snmp_op);
# define LEAF_begemotBridgeTpLearnedEntryDiscards 1
# define LEAF_begemotBridgeTpAgingTime 2
# define LEAF_begemotBridgeTpMaxAddresses 3
int	op_begemot_tp_fdb(struct snmp_context *, struct snmp_value *, u_int, u_int, enum snmp_op);
# define LEAF_begemotBridgeTpFdbAddress 1
# define LEAF_begemotBridgeTpFdbPort 2
# define LEAF_begemotBridgeTpFdbStatus 3
int	op_begemot_tp_port(struct snmp_context *, struct snmp_value *, u_int, u_int, enum snmp_op);
# define LEAF_begemotBridgeTpPort 1
# define LEAF_begemotBridgeTpPortMaxInfo 2
# define LEAF_begemotBridgeTpPortInFrames 3
# define LEAF_begemotBridgeTpPortOutFrames 4
# define LEAF_begemotBridgeTpPortInDiscards 5
int	op_begemot_bridge_pf(struct snmp_context *, struct snmp_value *, u_int, u_int, enum snmp_op);
# define LEAF_begemotBridgePfilStatus 1
# define LEAF_begemotBridgePfilMembers 2
# define LEAF_begemotBridgePfilIpOnly 3
# define LEAF_begemotBridgeLayer2PfStatus 4
int	op_begemot_bridge_config(struct snmp_context *, struct snmp_value *, u_int, u_int, enum snmp_op);
# define LEAF_begemotBridgeDefaultBridgeIf 1
# define LEAF_begemotBridgeDataUpdate 2
# define LEAF_begemotBridgeDataPoll 3

#ifdef SNMPTREE_TYPES

#ifndef begemotBridgeLayer2PfStatus_defined__
#define begemotBridgeLayer2PfStatus_defined__
/*
 * From <stdin>:275
 */
enum begemotBridgeLayer2PfStatus {
	begemotBridgeLayer2PfStatus_enabled = 1,
	begemotBridgeLayer2PfStatus_disabled = 2,
};
#define	STROFF_begemotBridgeLayer2PfStatus 1
#define	STRING_begemotBridgeLayer2PfStatus \
	[0] "begemotBridgeLayer2PfStatus_enabled",\
	[1] "begemotBridgeLayer2PfStatus_disabled",\

#endif /* begemotBridgeLayer2PfStatus_defined__ */

#ifndef begemotBridgeStpPortEnable_defined__
#define begemotBridgeStpPortEnable_defined__
/*
 * From <stdin>:231
 */
enum begemotBridgeStpPortEnable {
	begemotBridgeStpPortEnable_enabled = 1,
	begemotBridgeStpPortEnable_disabled = 2,
};
#define	STROFF_begemotBridgeStpPortEnable 1
#define	STRING_begemotBridgeStpPortEnable \
	[0] "begemotBridgeStpPortEnable_enabled",\
	[1] "begemotBridgeStpPortEnable_disabled",\

#endif /* begemotBridgeStpPortEnable_defined__ */

#ifndef begemotBridgeStpVersion_defined__
#define begemotBridgeStpVersion_defined__
/*
 * From <stdin>:223
 */
enum begemotBridgeStpVersion {
	begemotBridgeStpVersion_stpCompatible = 0,
	begemotBridgeStpVersion_rstp = 2,
};
#define	STROFF_begemotBridgeStpVersion 0
#define	STRING_begemotBridgeStpVersion \
	[0] "begemotBridgeStpVersion_stpCompatible",\
	[2] "begemotBridgeStpVersion_rstp",\

#endif /* begemotBridgeStpVersion_defined__ */

#ifndef begemotBridgeStpProtocolSpecification_defined__
#define begemotBridgeStpProtocolSpecification_defined__
/*
 * From <stdin>:209
 */
enum begemotBridgeStpProtocolSpecification {
	begemotBridgeStpProtocolSpecification_unknown = 1,
	begemotBridgeStpProtocolSpecification_decLb100 = 2,
	begemotBridgeStpProtocolSpecification_ieee8021d = 3,
};
#define	STROFF_begemotBridgeStpProtocolSpecification 1
#define	STRING_begemotBridgeStpProtocolSpecification \
	[0] "begemotBridgeStpProtocolSpecification_unknown",\
	[1] "begemotBridgeStpProtocolSpecification_decLb100",\
	[2] "begemotBridgeStpProtocolSpecification_ieee8021d",\

#endif /* begemotBridgeStpProtocolSpecification_defined__ */

#ifndef begemotBridgeBaseSpanEnabled_defined__
#define begemotBridgeBaseSpanEnabled_defined__
/*
 * From <stdin>:199
 */
enum begemotBridgeBaseSpanEnabled {
	begemotBridgeBaseSpanEnabled_enabled = 1,
	begemotBridgeBaseSpanEnabled_disabled = 2,
};
#define	STROFF_begemotBridgeBaseSpanEnabled 1
#define	STRING_begemotBridgeBaseSpanEnabled \
	[0] "begemotBridgeBaseSpanEnabled_enabled",\
	[1] "begemotBridgeBaseSpanEnabled_disabled",\

#endif /* begemotBridgeBaseSpanEnabled_defined__ */

#ifndef dot1dStpVersion_defined__
#define dot1dStpVersion_defined__
/*
 * From <stdin>:124
 */
enum dot1dStpVersion {
	dot1dStpVersion_stpCompatible = 0,
	dot1dStpVersion_rstp = 2,
};
#define	STROFF_dot1dStpVersion 0
#define	STRING_dot1dStpVersion \
	[0] "dot1dStpVersion_stpCompatible",\
	[2] "dot1dStpVersion_rstp",\

#endif /* dot1dStpVersion_defined__ */

#ifndef dot1dStpPortEnable_defined__
#define dot1dStpPortEnable_defined__
/*
 * From <stdin>:116
 */
enum dot1dStpPortEnable {
	dot1dStpPortEnable_enabled = 1,
	dot1dStpPortEnable_disabled = 2,
};
#define	STROFF_dot1dStpPortEnable 1
#define	STRING_dot1dStpPortEnable \
	[0] "dot1dStpPortEnable_enabled",\
	[1] "dot1dStpPortEnable_disabled",\

#endif /* dot1dStpPortEnable_defined__ */

#ifndef dot1dStpProtocolSpecification_defined__
#define dot1dStpProtocolSpecification_defined__
/*
 * From <stdin>:97
 */
enum dot1dStpProtocolSpecification {
	dot1dStpProtocolSpecification_unknown = 1,
	dot1dStpProtocolSpecification_decLb100 = 2,
	dot1dStpProtocolSpecification_ieee8021d = 3,
};
#define	STROFF_dot1dStpProtocolSpecification 1
#define	STRING_dot1dStpProtocolSpecification \
	[0] "dot1dStpProtocolSpecification_unknown",\
	[1] "dot1dStpProtocolSpecification_decLb100",\
	[2] "dot1dStpProtocolSpecification_ieee8021d",\

#endif /* dot1dStpProtocolSpecification_defined__ */

#ifndef TpFdbStatus_defined__
#define TpFdbStatus_defined__
/*
 * From <stdin>:67
 */
enum TpFdbStatus {
	TpFdbStatus_other = 1,
	TpFdbStatus_invalid = 2,
	TpFdbStatus_learned = 3,
	TpFdbStatus_self = 4,
	TpFdbStatus_mgmt = 5,
};
#define	STROFF_TpFdbStatus 1
#define	STRING_TpFdbStatus \
	[0] "TpFdbStatus_other",\
	[1] "TpFdbStatus_invalid",\
	[2] "TpFdbStatus_learned",\
	[3] "TpFdbStatus_self",\
	[4] "TpFdbStatus_mgmt",\

#endif /* TpFdbStatus_defined__ */

#ifndef BaseType_defined__
#define BaseType_defined__
/*
 * From <stdin>:60
 */
enum BaseType {
	BaseType_unknown = 1,
	BaseType_transparent_only = 2,
	BaseType_sourceroute_only = 3,
	BaseType_srt = 4,
};
#define	STROFF_BaseType 1
#define	STRING_BaseType \
	[0] "BaseType_unknown",\
	[1] "BaseType_transparent_only",\
	[2] "BaseType_sourceroute_only",\
	[3] "BaseType_srt",\

#endif /* BaseType_defined__ */

#ifndef StpPortAdminPointToPointType_defined__
#define StpPortAdminPointToPointType_defined__
/*
 * From <stdin>:54
 */
enum StpPortAdminPointToPointType {
	StpPortAdminPointToPointType_forceTrue = 0,
	StpPortAdminPointToPointType_forceFalse = 1,
	StpPortAdminPointToPointType_auto = 2,
};
#define	STROFF_StpPortAdminPointToPointType 0
#define	STRING_StpPortAdminPointToPointType \
	[0] "StpPortAdminPointToPointType_forceTrue",\
	[1] "StpPortAdminPointToPointType_forceFalse",\
	[2] "StpPortAdminPointToPointType_auto",\

#endif /* StpPortAdminPointToPointType_defined__ */

#ifndef StpPortState_defined__
#define StpPortState_defined__
/*
 * From <stdin>:45
 */
enum StpPortState {
	StpPortState_disabled = 1,
	StpPortState_blocking = 2,
	StpPortState_listening = 3,
	StpPortState_learning = 4,
	StpPortState_forwarding = 5,
	StpPortState_broken = 6,
};
#define	STROFF_StpPortState 1
#define	STRING_StpPortState \
	[0] "StpPortState_disabled",\
	[1] "StpPortState_blocking",\
	[2] "StpPortState_listening",\
	[3] "StpPortState_learning",\
	[4] "StpPortState_forwarding",\
	[5] "StpPortState_broken",\

#endif /* StpPortState_defined__ */

#ifndef TruthValue_defined__
#define TruthValue_defined__
/*
 * From <stdin>:40
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
 * From <stdin>:31
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

#define bridge_CTREE_SIZE 112
extern const struct snmp_node bridge_ctree[];
