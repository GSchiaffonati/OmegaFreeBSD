int	op_hrSystem(struct snmp_context *, struct snmp_value *, u_int, u_int, enum snmp_op);
# define LEAF_hrSystemUptime 1
# define LEAF_hrSystemDate 2
# define LEAF_hrSystemInitialLoadDevice 3
# define LEAF_hrSystemInitialLoadParameters 4
# define LEAF_hrSystemNumUsers 5
# define LEAF_hrSystemProcesses 6
# define LEAF_hrSystemMaxProcesses 7
int	op_hrStorage(struct snmp_context *, struct snmp_value *, u_int, u_int, enum snmp_op);
# define LEAF_hrMemorySize 2
int	op_hrStorageTable(struct snmp_context *, struct snmp_value *, u_int, u_int, enum snmp_op);
# define LEAF_hrStorageIndex 1
# define LEAF_hrStorageType 2
# define LEAF_hrStorageDescr 3
# define LEAF_hrStorageAllocationUnits 4
# define LEAF_hrStorageSize 5
# define LEAF_hrStorageUsed 6
# define LEAF_hrStorageAllocationFailures 7
int	op_hrDeviceTable(struct snmp_context *, struct snmp_value *, u_int, u_int, enum snmp_op);
# define LEAF_hrDeviceIndex 1
# define LEAF_hrDeviceType 2
# define LEAF_hrDeviceDescr 3
# define LEAF_hrDeviceID 4
# define LEAF_hrDeviceStatus 5
# define LEAF_hrDeviceErrors 6
int	op_hrProcessorTable(struct snmp_context *, struct snmp_value *, u_int, u_int, enum snmp_op);
# define LEAF_hrProcessorFrwID 1
# define LEAF_hrProcessorLoad 2
int	op_hrNetworkTable(struct snmp_context *, struct snmp_value *, u_int, u_int, enum snmp_op);
# define LEAF_hrNetworkIfIndex 1
int	op_hrPrinterTable(struct snmp_context *, struct snmp_value *, u_int, u_int, enum snmp_op);
# define LEAF_hrPrinterStatus 1
# define LEAF_hrPrinterDetectedErrorState 2
int	op_hrDiskStorageTable(struct snmp_context *, struct snmp_value *, u_int, u_int, enum snmp_op);
# define LEAF_hrDiskStorageAccess 1
# define LEAF_hrDiskStorageMedia 2
# define LEAF_hrDiskStorageRemovable 3
# define LEAF_hrDiskStorageCapacity 4
int	op_hrPartitionTable(struct snmp_context *, struct snmp_value *, u_int, u_int, enum snmp_op);
# define LEAF_hrPartitionIndex 1
# define LEAF_hrPartitionLabel 2
# define LEAF_hrPartitionID 3
# define LEAF_hrPartitionSize 4
# define LEAF_hrPartitionFSIndex 5
int	op_hrFSTable(struct snmp_context *, struct snmp_value *, u_int, u_int, enum snmp_op);
# define LEAF_hrFSIndex 1
# define LEAF_hrFSMountPoint 2
# define LEAF_hrFSRemoteMountPoint 3
# define LEAF_hrFSType 4
# define LEAF_hrFSAccess 5
# define LEAF_hrFSBootable 6
# define LEAF_hrFSStorageIndex 7
# define LEAF_hrFSLastFullBackupDate 8
# define LEAF_hrFSLastPartialBackupDate 9
int	op_hrSWRun(struct snmp_context *, struct snmp_value *, u_int, u_int, enum snmp_op);
# define LEAF_hrSWOSIndex 1
int	op_hrSWRunTable(struct snmp_context *, struct snmp_value *, u_int, u_int, enum snmp_op);
# define LEAF_hrSWRunIndex 1
# define LEAF_hrSWRunName 2
# define LEAF_hrSWRunID 3
# define LEAF_hrSWRunPath 4
# define LEAF_hrSWRunParameters 5
# define LEAF_hrSWRunType 6
# define LEAF_hrSWRunStatus 7
int	op_hrSWRunPerfTable(struct snmp_context *, struct snmp_value *, u_int, u_int, enum snmp_op);
# define LEAF_hrSWRunPerfCPU 1
# define LEAF_hrSWRunPerfMem 2
int	op_hrSWInstalled(struct snmp_context *, struct snmp_value *, u_int, u_int, enum snmp_op);
# define LEAF_hrSWInstalledLastChange 1
# define LEAF_hrSWInstalledLastUpdateTime 2
int	op_hrSWInstalledTable(struct snmp_context *, struct snmp_value *, u_int, u_int, enum snmp_op);
# define LEAF_hrSWInstalledIndex 1
# define LEAF_hrSWInstalledName 2
# define LEAF_hrSWInstalledID 3
# define LEAF_hrSWInstalledType 4
# define LEAF_hrSWInstalledDate 5
int	op_begemot(struct snmp_context *, struct snmp_value *, u_int, u_int, enum snmp_op);
# define LEAF_begemotHrStorageUpdate 1
# define LEAF_begemotHrFSUpdate 2
# define LEAF_begemotHrDiskStorageUpdate 3
# define LEAF_begemotHrNetworkUpdate 4
# define LEAF_begemotHrSWInstalledUpdate 5
# define LEAF_begemotHrSWRunUpdate 6
# define LEAF_begemotHrPkgDir 7

#ifdef SNMPTREE_TYPES

#endif /* SNMPTREE_TYPES */

#define hostres_CTREE_SIZE 68
extern const struct snmp_node hostres_ctree[];
