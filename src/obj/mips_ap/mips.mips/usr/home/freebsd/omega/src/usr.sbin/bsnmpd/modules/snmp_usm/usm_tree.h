int	op_usm_stats(struct snmp_context *, struct snmp_value *, u_int, u_int, enum snmp_op);
# define LEAF_usmStatsUnsupportedSecLevels 1
# define LEAF_usmStatsNotInTimeWindows 2
# define LEAF_usmStatsUnknownUserNames 3
# define LEAF_usmStatsUnknownEngineIDs 4
# define LEAF_usmStatsWrongDigests 5
# define LEAF_usmStatsDecryptionErrors 6
int	op_usm_lock(struct snmp_context *, struct snmp_value *, u_int, u_int, enum snmp_op);
# define LEAF_usmUserSpinLock 1
int	op_usm_users(struct snmp_context *, struct snmp_value *, u_int, u_int, enum snmp_op);
# define LEAF_usmUserSecurityName 3
# define LEAF_usmUserCloneFrom 4
# define LEAF_usmUserAuthProtocol 5
# define LEAF_usmUserAuthKeyChange 6
# define LEAF_usmUserOwnAuthKeyChange 7
# define LEAF_usmUserPrivProtocol 8
# define LEAF_usmUserPrivKeyChange 9
# define LEAF_usmUserOwnPrivKeyChange 10
# define LEAF_usmUserPublic 11
# define LEAF_usmUserStorageType 12
# define LEAF_usmUserStatus 13

#ifdef SNMPTREE_TYPES

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

#define usm_CTREE_SIZE 18
extern const struct snmp_node usm_ctree[];
