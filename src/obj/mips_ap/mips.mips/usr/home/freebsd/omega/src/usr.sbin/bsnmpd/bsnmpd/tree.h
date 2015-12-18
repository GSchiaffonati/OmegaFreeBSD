int	op_system_group(struct snmp_context *, struct snmp_value *, u_int, u_int, enum snmp_op);
# define LEAF_sysDescr 1
# define LEAF_sysObjectId 2
# define LEAF_sysUpTime 3
# define LEAF_sysContact 4
# define LEAF_sysName 5
# define LEAF_sysLocation 6
# define LEAF_sysServices 7
# define LEAF_sysORLastChange 8
int	op_or_table(struct snmp_context *, struct snmp_value *, u_int, u_int, enum snmp_op);
# define LEAF_sysORID 2
# define LEAF_sysORDescr 3
# define LEAF_sysORUpTime 4
int	op_snmp(struct snmp_context *, struct snmp_value *, u_int, u_int, enum snmp_op);
# define LEAF_snmpInPkts 1
# define LEAF_snmpInBadVersions 3
# define LEAF_snmpInBadCommunityNames 4
# define LEAF_snmpInBadCommunityUses 5
# define LEAF_snmpInASNParseErrs 6
# define LEAF_snmpEnableAuthenTraps 30
# define LEAF_snmpSilentDrops 31
# define LEAF_snmpProxyDrops 32
int	op_snmpd_config(struct snmp_context *, struct snmp_value *, u_int, u_int, enum snmp_op);
# define LEAF_begemotSnmpdTransmitBuffer 1
# define LEAF_begemotSnmpdReceiveBuffer 2
# define LEAF_begemotSnmpdCommunityDisable 3
# define LEAF_begemotSnmpdTrap1Addr 4
# define LEAF_begemotSnmpdVersionEnable 5
int	op_trapsink(struct snmp_context *, struct snmp_value *, u_int, u_int, enum snmp_op);
# define LEAF_begemotTrapSinkStatus 3
# define LEAF_begemotTrapSinkComm 4
# define LEAF_begemotTrapSinkVersion 5
int	op_snmp_port(struct snmp_context *, struct snmp_value *, u_int, u_int, enum snmp_op);
# define LEAF_begemotSnmpdPortStatus 3
int	op_community(struct snmp_context *, struct snmp_value *, u_int, u_int, enum snmp_op);
# define LEAF_begemotSnmpdCommunityString 3
# define LEAF_begemotSnmpdCommunityDescr 4
int	op_modules(struct snmp_context *, struct snmp_value *, u_int, u_int, enum snmp_op);
# define LEAF_begemotSnmpdModulePath 2
# define LEAF_begemotSnmpdModuleComment 3
int	op_snmpd_stats(struct snmp_context *, struct snmp_value *, u_int, u_int, enum snmp_op);
# define LEAF_begemotSnmpdStatsNoRxBufs 1
# define LEAF_begemotSnmpdStatsNoTxBufs 2
# define LEAF_begemotSnmpdStatsInTooLongPkts 3
# define LEAF_begemotSnmpdStatsInBadPduTypes 4
int	op_debug(struct snmp_context *, struct snmp_value *, u_int, u_int, enum snmp_op);
# define LEAF_begemotSnmpdDebugDumpPdus 1
# define LEAF_begemotSnmpdDebugSnmpTrace 2
# define LEAF_begemotSnmpdDebugSyslogPri 3
int	op_lsock_port(struct snmp_context *, struct snmp_value *, u_int, u_int, enum snmp_op);
# define LEAF_begemotSnmpdLocalPortStatus 2
# define LEAF_begemotSnmpdLocalPortType 3
int	op_transport_table(struct snmp_context *, struct snmp_value *, u_int, u_int, enum snmp_op);
# define LEAF_begemotSnmpdTransportStatus 2
# define LEAF_begemotSnmpdTransportOid 3
int	op_snmp_set(struct snmp_context *, struct snmp_value *, u_int, u_int, enum snmp_op);
# define LEAF_snmpSetSerialNo 1
int	op_snmp_engine(struct snmp_context *, struct snmp_value *, u_int, u_int, enum snmp_op);
# define LEAF_snmpEngineID 1
# define LEAF_snmpEngineBoots 2
# define LEAF_snmpEngineTime 3
# define LEAF_snmpEngineMaxMessageSize 4

#ifdef SNMPTREE_TYPES

#ifndef RowStatus_defined__
#define RowStatus_defined__
/*
 * From <stdin>:36
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

#define CTREE_SIZE 48
extern const struct snmp_node ctree[];
