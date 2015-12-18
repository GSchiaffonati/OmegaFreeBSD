#include <sys/types.h>
#include <stdio.h>
#include <stdint.h>
#include <bsnmp/asn1.h>
#include <bsnmp/snmp.h>
#include <bsnmp/snmpagent.h>
#include "hast_tree.h"

const struct snmp_node hast_ctree[] = {
    {{ 12, { 1, 3, 6, 1, 4, 1, 12325, 1, 220, 1, 1, 1, }}, "hastConfigFile", SNMP_NODE_LEAF, SNMP_SYNTAX_OCTETSTRING, op_hastConfig, 0, 0, NULL, NULL },
    {{ 13, { 1, 3, 6, 1, 4, 1, 12325, 1, 220, 1, 2, 1, 1, }}, "hastResourceIndex", SNMP_NODE_COLUMN, SNMP_SYNTAX_INTEGER, op_hastResourceTable, 0, 0x21, NULL, NULL },
    {{ 13, { 1, 3, 6, 1, 4, 1, 12325, 1, 220, 1, 2, 1, 2, }}, "hastResourceName", SNMP_NODE_COLUMN, SNMP_SYNTAX_OCTETSTRING, op_hastResourceTable, 0, 0x21, NULL, NULL },
    {{ 13, { 1, 3, 6, 1, 4, 1, 12325, 1, 220, 1, 2, 1, 3, }}, "hastResourceRole", SNMP_NODE_COLUMN, SNMP_SYNTAX_INTEGER, op_hastResourceTable, 0|SNMP_NODE_CANSET, 0x21, NULL, NULL },
    {{ 13, { 1, 3, 6, 1, 4, 1, 12325, 1, 220, 1, 2, 1, 4, }}, "hastResourceProvName", SNMP_NODE_COLUMN, SNMP_SYNTAX_OCTETSTRING, op_hastResourceTable, 0, 0x21, NULL, NULL },
    {{ 13, { 1, 3, 6, 1, 4, 1, 12325, 1, 220, 1, 2, 1, 5, }}, "hastResourceLocalPath", SNMP_NODE_COLUMN, SNMP_SYNTAX_OCTETSTRING, op_hastResourceTable, 0, 0x21, NULL, NULL },
    {{ 13, { 1, 3, 6, 1, 4, 1, 12325, 1, 220, 1, 2, 1, 6, }}, "hastResourceExtentSize", SNMP_NODE_COLUMN, SNMP_SYNTAX_INTEGER, op_hastResourceTable, 0, 0x21, NULL, NULL },
    {{ 13, { 1, 3, 6, 1, 4, 1, 12325, 1, 220, 1, 2, 1, 7, }}, "hastResourceKeepDirty", SNMP_NODE_COLUMN, SNMP_SYNTAX_INTEGER, op_hastResourceTable, 0, 0x21, NULL, NULL },
    {{ 13, { 1, 3, 6, 1, 4, 1, 12325, 1, 220, 1, 2, 1, 8, }}, "hastResourceRemoteAddr", SNMP_NODE_COLUMN, SNMP_SYNTAX_OCTETSTRING, op_hastResourceTable, 0, 0x21, NULL, NULL },
    {{ 13, { 1, 3, 6, 1, 4, 1, 12325, 1, 220, 1, 2, 1, 9, }}, "hastResourceSourceAddr", SNMP_NODE_COLUMN, SNMP_SYNTAX_OCTETSTRING, op_hastResourceTable, 0, 0x21, NULL, NULL },
    {{ 13, { 1, 3, 6, 1, 4, 1, 12325, 1, 220, 1, 2, 1, 10, }}, "hastResourceReplication", SNMP_NODE_COLUMN, SNMP_SYNTAX_INTEGER, op_hastResourceTable, 0, 0x21, NULL, NULL },
    {{ 13, { 1, 3, 6, 1, 4, 1, 12325, 1, 220, 1, 2, 1, 11, }}, "hastResourceStatus", SNMP_NODE_COLUMN, SNMP_SYNTAX_INTEGER, op_hastResourceTable, 0, 0x21, NULL, NULL },
    {{ 13, { 1, 3, 6, 1, 4, 1, 12325, 1, 220, 1, 2, 1, 12, }}, "hastResourceDirty", SNMP_NODE_COLUMN, SNMP_SYNTAX_COUNTER64, op_hastResourceTable, 0, 0x21, NULL, NULL },
    {{ 13, { 1, 3, 6, 1, 4, 1, 12325, 1, 220, 1, 2, 1, 13, }}, "hastResourceReads", SNMP_NODE_COLUMN, SNMP_SYNTAX_COUNTER64, op_hastResourceTable, 0, 0x21, NULL, NULL },
    {{ 13, { 1, 3, 6, 1, 4, 1, 12325, 1, 220, 1, 2, 1, 14, }}, "hastResourceWrites", SNMP_NODE_COLUMN, SNMP_SYNTAX_COUNTER64, op_hastResourceTable, 0, 0x21, NULL, NULL },
    {{ 13, { 1, 3, 6, 1, 4, 1, 12325, 1, 220, 1, 2, 1, 15, }}, "hastResourceDeletes", SNMP_NODE_COLUMN, SNMP_SYNTAX_COUNTER64, op_hastResourceTable, 0, 0x21, NULL, NULL },
    {{ 13, { 1, 3, 6, 1, 4, 1, 12325, 1, 220, 1, 2, 1, 16, }}, "hastResourceFlushes", SNMP_NODE_COLUMN, SNMP_SYNTAX_COUNTER64, op_hastResourceTable, 0, 0x21, NULL, NULL },
    {{ 13, { 1, 3, 6, 1, 4, 1, 12325, 1, 220, 1, 2, 1, 17, }}, "hastResourceActivemapUpdates", SNMP_NODE_COLUMN, SNMP_SYNTAX_COUNTER64, op_hastResourceTable, 0, 0x21, NULL, NULL },
    {{ 13, { 1, 3, 6, 1, 4, 1, 12325, 1, 220, 1, 2, 1, 18, }}, "hastResourceReadErrors", SNMP_NODE_COLUMN, SNMP_SYNTAX_COUNTER64, op_hastResourceTable, 0, 0x21, NULL, NULL },
    {{ 13, { 1, 3, 6, 1, 4, 1, 12325, 1, 220, 1, 2, 1, 19, }}, "hastResourceWriteErrors", SNMP_NODE_COLUMN, SNMP_SYNTAX_COUNTER64, op_hastResourceTable, 0, 0x21, NULL, NULL },
    {{ 13, { 1, 3, 6, 1, 4, 1, 12325, 1, 220, 1, 2, 1, 20, }}, "hastResourceDeleteErrors", SNMP_NODE_COLUMN, SNMP_SYNTAX_COUNTER64, op_hastResourceTable, 0, 0x21, NULL, NULL },
    {{ 13, { 1, 3, 6, 1, 4, 1, 12325, 1, 220, 1, 2, 1, 21, }}, "hastResourceFlushErrors", SNMP_NODE_COLUMN, SNMP_SYNTAX_COUNTER64, op_hastResourceTable, 0, 0x21, NULL, NULL },
    {{ 13, { 1, 3, 6, 1, 4, 1, 12325, 1, 220, 1, 2, 1, 22, }}, "hastResourceWorkerPid", SNMP_NODE_COLUMN, SNMP_SYNTAX_INTEGER, op_hastResourceTable, 0, 0x21, NULL, NULL },
    {{ 13, { 1, 3, 6, 1, 4, 1, 12325, 1, 220, 1, 2, 1, 23, }}, "hastResourceLocalQueue", SNMP_NODE_COLUMN, SNMP_SYNTAX_GAUGE, op_hastResourceTable, 0, 0x21, NULL, NULL },
    {{ 13, { 1, 3, 6, 1, 4, 1, 12325, 1, 220, 1, 2, 1, 24, }}, "hastResourceSendQueue", SNMP_NODE_COLUMN, SNMP_SYNTAX_GAUGE, op_hastResourceTable, 0, 0x21, NULL, NULL },
    {{ 13, { 1, 3, 6, 1, 4, 1, 12325, 1, 220, 1, 2, 1, 25, }}, "hastResourceRecvQueue", SNMP_NODE_COLUMN, SNMP_SYNTAX_GAUGE, op_hastResourceTable, 0, 0x21, NULL, NULL },
    {{ 13, { 1, 3, 6, 1, 4, 1, 12325, 1, 220, 1, 2, 1, 26, }}, "hastResourceDoneQueue", SNMP_NODE_COLUMN, SNMP_SYNTAX_GAUGE, op_hastResourceTable, 0, 0x21, NULL, NULL },
    {{ 13, { 1, 3, 6, 1, 4, 1, 12325, 1, 220, 1, 2, 1, 27, }}, "hastResourceIdleQueue", SNMP_NODE_COLUMN, SNMP_SYNTAX_GAUGE, op_hastResourceTable, 0, 0x21, NULL, NULL },
};

