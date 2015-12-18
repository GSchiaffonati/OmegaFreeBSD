int	op_hastConfig(struct snmp_context *, struct snmp_value *, u_int, u_int, enum snmp_op);
# define LEAF_hastConfigFile 1
int	op_hastResourceTable(struct snmp_context *, struct snmp_value *, u_int, u_int, enum snmp_op);
# define LEAF_hastResourceIndex 1
# define LEAF_hastResourceName 2
# define LEAF_hastResourceRole 3
# define LEAF_hastResourceProvName 4
# define LEAF_hastResourceLocalPath 5
# define LEAF_hastResourceExtentSize 6
# define LEAF_hastResourceKeepDirty 7
# define LEAF_hastResourceRemoteAddr 8
# define LEAF_hastResourceSourceAddr 9
# define LEAF_hastResourceReplication 10
# define LEAF_hastResourceStatus 11
# define LEAF_hastResourceDirty 12
# define LEAF_hastResourceReads 13
# define LEAF_hastResourceWrites 14
# define LEAF_hastResourceDeletes 15
# define LEAF_hastResourceFlushes 16
# define LEAF_hastResourceActivemapUpdates 17
# define LEAF_hastResourceReadErrors 18
# define LEAF_hastResourceWriteErrors 19
# define LEAF_hastResourceDeleteErrors 20
# define LEAF_hastResourceFlushErrors 21
# define LEAF_hastResourceWorkerPid 22
# define LEAF_hastResourceLocalQueue 23
# define LEAF_hastResourceSendQueue 24
# define LEAF_hastResourceRecvQueue 25
# define LEAF_hastResourceDoneQueue 26
# define LEAF_hastResourceIdleQueue 27

#ifdef SNMPTREE_TYPES

#endif /* SNMPTREE_TYPES */

#define hast_CTREE_SIZE 28
extern const struct snmp_node hast_ctree[];
