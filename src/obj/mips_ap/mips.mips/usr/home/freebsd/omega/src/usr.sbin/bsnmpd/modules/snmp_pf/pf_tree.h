int	pf_status(struct snmp_context *, struct snmp_value *, u_int, u_int, enum snmp_op);
# define LEAF_pfStatusRunning 1
# define LEAF_pfStatusRuntime 2
# define LEAF_pfStatusDebug 3
# define LEAF_pfStatusHostId 4
int	pf_counter(struct snmp_context *, struct snmp_value *, u_int, u_int, enum snmp_op);
# define LEAF_pfCounterMatch 1
# define LEAF_pfCounterBadOffset 2
# define LEAF_pfCounterFragment 3
# define LEAF_pfCounterShort 4
# define LEAF_pfCounterNormalize 5
# define LEAF_pfCounterMemDrop 6
int	pf_statetable(struct snmp_context *, struct snmp_value *, u_int, u_int, enum snmp_op);
# define LEAF_pfStateTableCount 1
# define LEAF_pfStateTableSearches 2
# define LEAF_pfStateTableInserts 3
# define LEAF_pfStateTableRemovals 4
int	pf_srcnodes(struct snmp_context *, struct snmp_value *, u_int, u_int, enum snmp_op);
# define LEAF_pfSrcNodesCount 1
# define LEAF_pfSrcNodesSearches 2
# define LEAF_pfSrcNodesInserts 3
# define LEAF_pfSrcNodesRemovals 4
int	pf_limits(struct snmp_context *, struct snmp_value *, u_int, u_int, enum snmp_op);
# define LEAF_pfLimitsStates 1
# define LEAF_pfLimitsSrcNodes 2
# define LEAF_pfLimitsFrags 3
int	pf_timeouts(struct snmp_context *, struct snmp_value *, u_int, u_int, enum snmp_op);
# define LEAF_pfTimeoutsTcpFirst 1
# define LEAF_pfTimeoutsTcpOpening 2
# define LEAF_pfTimeoutsTcpEstablished 3
# define LEAF_pfTimeoutsTcpClosing 4
# define LEAF_pfTimeoutsTcpFinWait 5
# define LEAF_pfTimeoutsTcpClosed 6
# define LEAF_pfTimeoutsUdpFirst 7
# define LEAF_pfTimeoutsUdpSingle 8
# define LEAF_pfTimeoutsUdpMultiple 9
# define LEAF_pfTimeoutsIcmpFirst 10
# define LEAF_pfTimeoutsIcmpError 11
# define LEAF_pfTimeoutsOtherFirst 12
# define LEAF_pfTimeoutsOtherSingle 13
# define LEAF_pfTimeoutsOtherMultiple 14
# define LEAF_pfTimeoutsFragment 15
# define LEAF_pfTimeoutsInterval 16
# define LEAF_pfTimeoutsAdaptiveStart 17
# define LEAF_pfTimeoutsAdaptiveEnd 18
# define LEAF_pfTimeoutsSrcNode 19
int	pf_logif(struct snmp_context *, struct snmp_value *, u_int, u_int, enum snmp_op);
# define LEAF_pfLogInterfaceName 1
# define LEAF_pfLogInterfaceIp4BytesIn 2
# define LEAF_pfLogInterfaceIp4BytesOut 3
# define LEAF_pfLogInterfaceIp4PktsInPass 4
# define LEAF_pfLogInterfaceIp4PktsInDrop 5
# define LEAF_pfLogInterfaceIp4PktsOutPass 6
# define LEAF_pfLogInterfaceIp4PktsOutDrop 7
# define LEAF_pfLogInterfaceIp6BytesIn 8
# define LEAF_pfLogInterfaceIp6BytesOut 9
# define LEAF_pfLogInterfaceIp6PktsInPass 10
# define LEAF_pfLogInterfaceIp6PktsInDrop 11
# define LEAF_pfLogInterfaceIp6PktsOutPass 12
# define LEAF_pfLogInterfaceIp6PktsOutDrop 13
int	pf_interfaces(struct snmp_context *, struct snmp_value *, u_int, u_int, enum snmp_op);
# define LEAF_pfInterfacesIfNumber 1
int	pf_iftable(struct snmp_context *, struct snmp_value *, u_int, u_int, enum snmp_op);
# define LEAF_pfInterfacesIfDescr 2
# define LEAF_pfInterfacesIfType 3
# define LEAF_pfInterfacesIfTZero 4
# define LEAF_pfInterfacesIfRefsState 5
# define LEAF_pfInterfacesIfRefsRule 6
# define LEAF_pfInterfacesIf4BytesInPass 7
# define LEAF_pfInterfacesIf4BytesInBlock 8
# define LEAF_pfInterfacesIf4BytesOutPass 9
# define LEAF_pfInterfacesIf4BytesOutBlock 10
# define LEAF_pfInterfacesIf4PktsInPass 11
# define LEAF_pfInterfacesIf4PktsInBlock 12
# define LEAF_pfInterfacesIf4PktsOutPass 13
# define LEAF_pfInterfacesIf4PktsOutBlock 14
# define LEAF_pfInterfacesIf6BytesInPass 15
# define LEAF_pfInterfacesIf6BytesInBlock 16
# define LEAF_pfInterfacesIf6BytesOutPass 17
# define LEAF_pfInterfacesIf6BytesOutBlock 18
# define LEAF_pfInterfacesIf6PktsInPass 19
# define LEAF_pfInterfacesIf6PktsInBlock 20
# define LEAF_pfInterfacesIf6PktsOutPass 21
# define LEAF_pfInterfacesIf6PktsOutBlock 22
int	pf_tables(struct snmp_context *, struct snmp_value *, u_int, u_int, enum snmp_op);
# define LEAF_pfTablesTblNumber 1
int	pf_tbltable(struct snmp_context *, struct snmp_value *, u_int, u_int, enum snmp_op);
# define LEAF_pfTablesTblDescr 2
# define LEAF_pfTablesTblCount 3
# define LEAF_pfTablesTblTZero 4
# define LEAF_pfTablesTblRefsAnchor 5
# define LEAF_pfTablesTblRefsRule 6
# define LEAF_pfTablesTblEvalMatch 7
# define LEAF_pfTablesTblEvalNoMatch 8
# define LEAF_pfTablesTblBytesInPass 9
# define LEAF_pfTablesTblBytesInBlock 10
# define LEAF_pfTablesTblBytesInXPass 11
# define LEAF_pfTablesTblBytesOutPass 12
# define LEAF_pfTablesTblBytesOutBlock 13
# define LEAF_pfTablesTblBytesOutXPass 14
# define LEAF_pfTablesTblPktsInPass 15
# define LEAF_pfTablesTblPktsInBlock 16
# define LEAF_pfTablesTblPktsInXPass 17
# define LEAF_pfTablesTblPktsOutPass 18
# define LEAF_pfTablesTblPktsOutBlock 19
# define LEAF_pfTablesTblPktsOutXPass 20
int	pf_tbladdr(struct snmp_context *, struct snmp_value *, u_int, u_int, enum snmp_op);
# define LEAF_pfTablesAddrNetType 2
# define LEAF_pfTablesAddrNet 3
# define LEAF_pfTablesAddrPrefix 4
# define LEAF_pfTablesAddrTZero 5
# define LEAF_pfTablesAddrBytesInPass 6
# define LEAF_pfTablesAddrBytesInBlock 7
# define LEAF_pfTablesAddrBytesOutPass 8
# define LEAF_pfTablesAddrBytesOutBlock 9
# define LEAF_pfTablesAddrPktsInPass 10
# define LEAF_pfTablesAddrPktsInBlock 11
# define LEAF_pfTablesAddrPktsOutPass 12
# define LEAF_pfTablesAddrPktsOutBlock 13
int	pf_altq(struct snmp_context *, struct snmp_value *, u_int, u_int, enum snmp_op);
# define LEAF_pfAltqQueueNumber 1
int	pf_altqq(struct snmp_context *, struct snmp_value *, u_int, u_int, enum snmp_op);
# define LEAF_pfAltqQueueDescr 2
# define LEAF_pfAltqQueueParent 3
# define LEAF_pfAltqQueueScheduler 4
# define LEAF_pfAltqQueueBandwidth 5
# define LEAF_pfAltqQueuePriority 6
# define LEAF_pfAltqQueueLimit 7
int	pf_labels(struct snmp_context *, struct snmp_value *, u_int, u_int, enum snmp_op);
# define LEAF_pfLabelsLblNumber 1
int	pf_lbltable(struct snmp_context *, struct snmp_value *, u_int, u_int, enum snmp_op);
# define LEAF_pfLabelsLblName 2
# define LEAF_pfLabelsLblEvals 3
# define LEAF_pfLabelsLblBytesIn 4
# define LEAF_pfLabelsLblBytesOut 5
# define LEAF_pfLabelsLblPktsIn 6
# define LEAF_pfLabelsLblPktsOut 7

#ifdef SNMPTREE_TYPES

#ifndef pfAltqQueueScheduler_defined__
#define pfAltqQueueScheduler_defined__
/*
 * From <stdin>:183
 */
enum pfAltqQueueScheduler {
	pfAltqQueueScheduler_cbq = 1,
	pfAltqQueueScheduler_hfsc = 8,
	pfAltqQueueScheduler_priq = 11,
};
#define	STROFF_pfAltqQueueScheduler 1
#define	STRING_pfAltqQueueScheduler \
	[0] "pfAltqQueueScheduler_cbq",\
	[7] "pfAltqQueueScheduler_hfsc",\
	[10] "pfAltqQueueScheduler_priq",\

#endif /* pfAltqQueueScheduler_defined__ */

#ifndef pfTablesAddrNetType_defined__
#define pfTablesAddrNetType_defined__
/*
 * From <stdin>:161
 */
enum pfTablesAddrNetType {
	pfTablesAddrNetType_unknown = 0,
	pfTablesAddrNetType_ipv4 = 1,
	pfTablesAddrNetType_ipv6 = 2,
};
#define	STROFF_pfTablesAddrNetType 0
#define	STRING_pfTablesAddrNetType \
	[0] "pfTablesAddrNetType_unknown",\
	[1] "pfTablesAddrNetType_ipv4",\
	[2] "pfTablesAddrNetType_ipv6",\

#endif /* pfTablesAddrNetType_defined__ */

#ifndef pfInterfacesIfType_defined__
#define pfInterfacesIfType_defined__
/*
 * From <stdin>:109
 */
enum pfInterfacesIfType {
	pfInterfacesIfType_group = 0,
	pfInterfacesIfType_instance = 1,
	pfInterfacesIfType_detached = 2,
};
#define	STROFF_pfInterfacesIfType 0
#define	STRING_pfInterfacesIfType \
	[0] "pfInterfacesIfType_group",\
	[1] "pfInterfacesIfType_instance",\
	[2] "pfInterfacesIfType_detached",\

#endif /* pfInterfacesIfType_defined__ */

#ifndef pfStatusDebug_defined__
#define pfStatusDebug_defined__
/*
 * From <stdin>:39
 */
enum pfStatusDebug {
	pfStatusDebug_none = 0,
	pfStatusDebug_urgent = 1,
	pfStatusDebug_misc = 2,
	pfStatusDebug_loud = 3,
};
#define	STROFF_pfStatusDebug 0
#define	STRING_pfStatusDebug \
	[0] "pfStatusDebug_none",\
	[1] "pfStatusDebug_urgent",\
	[2] "pfStatusDebug_misc",\
	[3] "pfStatusDebug_loud",\

#endif /* pfStatusDebug_defined__ */

#ifndef pfStatusRunning_defined__
#define pfStatusRunning_defined__
/*
 * From <stdin>:37
 */
enum pfStatusRunning {
	pfStatusRunning_true = 1,
	pfStatusRunning_false = 2,
};
#define	STROFF_pfStatusRunning 1
#define	STRING_pfStatusRunning \
	[0] "pfStatusRunning_true",\
	[1] "pfStatusRunning_false",\

#endif /* pfStatusRunning_defined__ */

#endif /* SNMPTREE_TYPES */

#define pf_CTREE_SIZE 121
extern const struct snmp_node pf_ctree[];
