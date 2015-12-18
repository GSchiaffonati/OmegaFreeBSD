int	op_vacm_context(struct snmp_context *, struct snmp_value *, u_int, u_int, enum snmp_op);
# define LEAF_vacmContextName 1
int	op_vacm_security_to_group(struct snmp_context *, struct snmp_value *, u_int, u_int, enum snmp_op);
# define LEAF_vacmGroupName 3
# define LEAF_vacmSecurityToGroupStorageType 4
# define LEAF_vacmSecurityToGroupStatus 5
int	op_vacm_access(struct snmp_context *, struct snmp_value *, u_int, u_int, enum snmp_op);
# define LEAF_vacmAccessContextMatch 4
# define LEAF_vacmAccessReadViewName 5
# define LEAF_vacmAccessWriteViewName 6
# define LEAF_vacmAccessNotifyViewName 7
# define LEAF_vacmAccessStorageType 8
# define LEAF_vacmAccessStatus 9
int	op_vacm_view_lock(struct snmp_context *, struct snmp_value *, u_int, u_int, enum snmp_op);
# define LEAF_vacmViewSpinLock 1
int	op_vacm_view(struct snmp_context *, struct snmp_value *, u_int, u_int, enum snmp_op);
# define LEAF_vacmViewTreeFamilyMask 3
# define LEAF_vacmViewTreeFamilyType 4
# define LEAF_vacmViewTreeFamilyStorageType 5
# define LEAF_vacmViewTreeFamilyStatus 6

#ifdef SNMPTREE_TYPES

#ifndef vacmViewTreeFamilyType_defined__
#define vacmViewTreeFamilyType_defined__
/*
 * From <stdin>:90
 */
enum vacmViewTreeFamilyType {
	vacmViewTreeFamilyType_included = 1,
	vacmViewTreeFamilyType_excluded = 2,
};
#define	STROFF_vacmViewTreeFamilyType 1
#define	STRING_vacmViewTreeFamilyType \
	[0] "vacmViewTreeFamilyType_included",\
	[1] "vacmViewTreeFamilyType_excluded",\

#endif /* vacmViewTreeFamilyType_defined__ */

#ifndef vacmAccessContextMatch_defined__
#define vacmAccessContextMatch_defined__
/*
 * From <stdin>:75
 */
enum vacmAccessContextMatch {
	vacmAccessContextMatch_exact = 1,
	vacmAccessContextMatch_prefix = 2,
};
#define	STROFF_vacmAccessContextMatch 1
#define	STRING_vacmAccessContextMatch \
	[0] "vacmAccessContextMatch_exact",\
	[1] "vacmAccessContextMatch_prefix",\

#endif /* vacmAccessContextMatch_defined__ */

#ifndef vacmAccessSecurityLevel_defined__
#define vacmAccessSecurityLevel_defined__
/*
 * From <stdin>:74
 */
enum vacmAccessSecurityLevel {
	vacmAccessSecurityLevel_noAuthNoPriv = 1,
	vacmAccessSecurityLevel_authNoPriv = 2,
	vacmAccessSecurityLevel_authPriv = 3,
};
#define	STROFF_vacmAccessSecurityLevel 1
#define	STRING_vacmAccessSecurityLevel \
	[0] "vacmAccessSecurityLevel_noAuthNoPriv",\
	[1] "vacmAccessSecurityLevel_authNoPriv",\
	[2] "vacmAccessSecurityLevel_authPriv",\

#endif /* vacmAccessSecurityLevel_defined__ */

#ifndef vacmAccessEntry_defined__
#define vacmAccessEntry_defined__
/*
 * From <stdin>:71
 */
enum vacmAccessEntry {
	vacmAccessEntry_noAuthNoPriv = 1,
	vacmAccessEntry_authNoPriv = 2,
	vacmAccessEntry_authPriv = 3,
};
#define	STROFF_vacmAccessEntry 1
#define	STRING_vacmAccessEntry \
	[0] "vacmAccessEntry_noAuthNoPriv",\
	[1] "vacmAccessEntry_authNoPriv",\
	[2] "vacmAccessEntry_authPriv",\

#endif /* vacmAccessEntry_defined__ */

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

#define vacm_CTREE_SIZE 15
extern const struct snmp_node vacm_ctree[];
