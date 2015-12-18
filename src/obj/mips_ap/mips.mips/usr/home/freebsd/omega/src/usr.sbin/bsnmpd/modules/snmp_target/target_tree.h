int	op_snmp_target(struct snmp_context *, struct snmp_value *, u_int, u_int, enum snmp_op);
# define LEAF_snmpTargetSpinLock 1
int	op_snmp_target_addrs(struct snmp_context *, struct snmp_value *, u_int, u_int, enum snmp_op);
# define LEAF_snmpTargetAddrTDomain 2
# define LEAF_snmpTargetAddrTAddress 3
# define LEAF_snmpTargetAddrTimeout 4
# define LEAF_snmpTargetAddrRetryCount 5
# define LEAF_snmpTargetAddrTagList 6
# define LEAF_snmpTargetAddrParams 7
# define LEAF_snmpTargetAddrStorageType 8
# define LEAF_snmpTargetAddrRowStatus 9
int	op_snmp_target_params(struct snmp_context *, struct snmp_value *, u_int, u_int, enum snmp_op);
# define LEAF_snmpTargetParamsMPModel 2
# define LEAF_snmpTargetParamsSecurityModel 3
# define LEAF_snmpTargetParamsSecurityName 4
# define LEAF_snmpTargetParamsSecurityLevel 5
# define LEAF_snmpTargetParamsStorageType 6
# define LEAF_snmpTargetParamsRowStatus 7
# define LEAF_snmpUnavailableContexts 4
# define LEAF_snmpUnknownContexts 5
int	op_snmp_notify(struct snmp_context *, struct snmp_value *, u_int, u_int, enum snmp_op);
# define LEAF_snmpNotifyTag 2
# define LEAF_snmpNotifyType 3
# define LEAF_snmpNotifyStorageType 4
# define LEAF_snmpNotifyRowStatus 5

#ifdef SNMPTREE_TYPES

#ifndef snmpNotifyType_defined__
#define snmpNotifyType_defined__
/*
 * From <stdin>:95
 */
enum snmpNotifyType {
	snmpNotifyType_trap = 1,
	snmpNotifyType_inform = 2,
};
#define	STROFF_snmpNotifyType 1
#define	STRING_snmpNotifyType \
	[0] "snmpNotifyType_trap",\
	[1] "snmpNotifyType_inform",\

#endif /* snmpNotifyType_defined__ */

#ifndef snmpTargetParamsSecurityLevel_defined__
#define snmpTargetParamsSecurityLevel_defined__
/*
 * From <stdin>:80
 */
enum snmpTargetParamsSecurityLevel {
	snmpTargetParamsSecurityLevel_noAuthNoPriv = 1,
	snmpTargetParamsSecurityLevel_authNoPriv = 2,
	snmpTargetParamsSecurityLevel_authPriv = 3,
};
#define	STROFF_snmpTargetParamsSecurityLevel 1
#define	STRING_snmpTargetParamsSecurityLevel \
	[0] "snmpTargetParamsSecurityLevel_noAuthNoPriv",\
	[1] "snmpTargetParamsSecurityLevel_authNoPriv",\
	[2] "snmpTargetParamsSecurityLevel_authPriv",\

#endif /* snmpTargetParamsSecurityLevel_defined__ */

#ifndef StorageType_defined__
#define StorageType_defined__
/*
 * From <stdin>:43
 */
enum StorageType {
	StorageType_other = 1,
	StorageType_volatile = 2,
	StorageType_nonVolatile = 3,
	StorageType_permanent = 4,
	StorageType_readOnly = 5,
};
#define	STROFF_StorageType 1
#define	STRING_StorageType \
	[0] "StorageType_other",\
	[1] "StorageType_volatile",\
	[2] "StorageType_nonVolatile",\
	[3] "StorageType_permanent",\
	[4] "StorageType_readOnly",\

#endif /* StorageType_defined__ */

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

#define target_CTREE_SIZE 21
extern const struct snmp_node target_ctree[];
