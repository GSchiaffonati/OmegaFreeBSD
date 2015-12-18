int	op_lm75Sensors(struct snmp_context *, struct snmp_value *, u_int, u_int, enum snmp_op);
# define LEAF_lm75Sensors 1
int	op_lm75SensorTable(struct snmp_context *, struct snmp_value *, u_int, u_int, enum snmp_op);
# define LEAF_lm75SensorIndex 1
# define LEAF_lm75SensorSysctlIndex 2
# define LEAF_lm75SensorDesc 3
# define LEAF_lm75SensorLocation 4
# define LEAF_lm75SensorPnpInfo 5
# define LEAF_lm75SensorParent 6
# define LEAF_lm75SensorTemperature 7

#ifdef SNMPTREE_TYPES

#endif /* SNMPTREE_TYPES */

#define lm75_CTREE_SIZE 8
extern const struct snmp_node lm75_ctree[];
