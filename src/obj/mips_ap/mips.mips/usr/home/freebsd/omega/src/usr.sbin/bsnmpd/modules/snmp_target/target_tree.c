#include <sys/types.h>
#include <stdio.h>
#include <stdint.h>
#include <bsnmp/asn1.h>
#include <bsnmp/snmp.h>
#include <bsnmp/snmpagent.h>
#include "target_tree.h"

const struct snmp_node target_ctree[] = {
    {{ 9, { 1, 3, 6, 1, 6, 3, 12, 1, 1, }}, "snmpTargetSpinLock", SNMP_NODE_LEAF, SNMP_SYNTAX_INTEGER, op_snmp_target, 0|SNMP_NODE_CANSET, 0, NULL, NULL },
    {{ 11, { 1, 3, 6, 1, 6, 3, 12, 1, 2, 1, 2, }}, "snmpTargetAddrTDomain", SNMP_NODE_COLUMN, SNMP_SYNTAX_OID, op_snmp_target_addrs, 0|SNMP_NODE_CANSET, 0x21, NULL, NULL },
    {{ 11, { 1, 3, 6, 1, 6, 3, 12, 1, 2, 1, 3, }}, "snmpTargetAddrTAddress", SNMP_NODE_COLUMN, SNMP_SYNTAX_OCTETSTRING, op_snmp_target_addrs, 0|SNMP_NODE_CANSET, 0x21, NULL, NULL },
    {{ 11, { 1, 3, 6, 1, 6, 3, 12, 1, 2, 1, 4, }}, "snmpTargetAddrTimeout", SNMP_NODE_COLUMN, SNMP_SYNTAX_INTEGER, op_snmp_target_addrs, 0|SNMP_NODE_CANSET, 0x21, NULL, NULL },
    {{ 11, { 1, 3, 6, 1, 6, 3, 12, 1, 2, 1, 5, }}, "snmpTargetAddrRetryCount", SNMP_NODE_COLUMN, SNMP_SYNTAX_INTEGER, op_snmp_target_addrs, 0|SNMP_NODE_CANSET, 0x21, NULL, NULL },
    {{ 11, { 1, 3, 6, 1, 6, 3, 12, 1, 2, 1, 6, }}, "snmpTargetAddrTagList", SNMP_NODE_COLUMN, SNMP_SYNTAX_OCTETSTRING, op_snmp_target_addrs, 0|SNMP_NODE_CANSET, 0x21, NULL, NULL },
    {{ 11, { 1, 3, 6, 1, 6, 3, 12, 1, 2, 1, 7, }}, "snmpTargetAddrParams", SNMP_NODE_COLUMN, SNMP_SYNTAX_OCTETSTRING, op_snmp_target_addrs, 0|SNMP_NODE_CANSET, 0x21, NULL, NULL },
    {{ 11, { 1, 3, 6, 1, 6, 3, 12, 1, 2, 1, 8, }}, "snmpTargetAddrStorageType", SNMP_NODE_COLUMN, SNMP_SYNTAX_INTEGER, op_snmp_target_addrs, 0|SNMP_NODE_CANSET, 0x21, NULL, NULL },
    {{ 11, { 1, 3, 6, 1, 6, 3, 12, 1, 2, 1, 9, }}, "snmpTargetAddrRowStatus", SNMP_NODE_COLUMN, SNMP_SYNTAX_INTEGER, op_snmp_target_addrs, 0|SNMP_NODE_CANSET, 0x21, NULL, NULL },
    {{ 11, { 1, 3, 6, 1, 6, 3, 12, 1, 3, 1, 2, }}, "snmpTargetParamsMPModel", SNMP_NODE_COLUMN, SNMP_SYNTAX_INTEGER, op_snmp_target_params, 0|SNMP_NODE_CANSET, 0x21, NULL, NULL },
    {{ 11, { 1, 3, 6, 1, 6, 3, 12, 1, 3, 1, 3, }}, "snmpTargetParamsSecurityModel", SNMP_NODE_COLUMN, SNMP_SYNTAX_INTEGER, op_snmp_target_params, 0|SNMP_NODE_CANSET, 0x21, NULL, NULL },
    {{ 11, { 1, 3, 6, 1, 6, 3, 12, 1, 3, 1, 4, }}, "snmpTargetParamsSecurityName", SNMP_NODE_COLUMN, SNMP_SYNTAX_OCTETSTRING, op_snmp_target_params, 0|SNMP_NODE_CANSET, 0x21, NULL, NULL },
    {{ 11, { 1, 3, 6, 1, 6, 3, 12, 1, 3, 1, 5, }}, "snmpTargetParamsSecurityLevel", SNMP_NODE_COLUMN, SNMP_SYNTAX_INTEGER, op_snmp_target_params, 0|SNMP_NODE_CANSET, 0x21, NULL, NULL },
    {{ 11, { 1, 3, 6, 1, 6, 3, 12, 1, 3, 1, 6, }}, "snmpTargetParamsStorageType", SNMP_NODE_COLUMN, SNMP_SYNTAX_INTEGER, op_snmp_target_params, 0|SNMP_NODE_CANSET, 0x21, NULL, NULL },
    {{ 11, { 1, 3, 6, 1, 6, 3, 12, 1, 3, 1, 7, }}, "snmpTargetParamsRowStatus", SNMP_NODE_COLUMN, SNMP_SYNTAX_INTEGER, op_snmp_target_params, 0|SNMP_NODE_CANSET, 0x21, NULL, NULL },
    {{ 9, { 1, 3, 6, 1, 6, 3, 12, 1, 4, }}, "snmpUnavailableContexts", SNMP_NODE_LEAF, SNMP_SYNTAX_COUNTER, op_snmp_target, 0, 0, NULL, NULL },
    {{ 9, { 1, 3, 6, 1, 6, 3, 12, 1, 5, }}, "snmpUnknownContexts", SNMP_NODE_LEAF, SNMP_SYNTAX_COUNTER, op_snmp_target, 0, 0, NULL, NULL },
    {{ 11, { 1, 3, 6, 1, 6, 3, 13, 1, 1, 1, 2, }}, "snmpNotifyTag", SNMP_NODE_COLUMN, SNMP_SYNTAX_OCTETSTRING, op_snmp_notify, 0|SNMP_NODE_CANSET, 0x21, NULL, NULL },
    {{ 11, { 1, 3, 6, 1, 6, 3, 13, 1, 1, 1, 3, }}, "snmpNotifyType", SNMP_NODE_COLUMN, SNMP_SYNTAX_INTEGER, op_snmp_notify, 0|SNMP_NODE_CANSET, 0x21, NULL, NULL },
    {{ 11, { 1, 3, 6, 1, 6, 3, 13, 1, 1, 1, 4, }}, "snmpNotifyStorageType", SNMP_NODE_COLUMN, SNMP_SYNTAX_INTEGER, op_snmp_notify, 0|SNMP_NODE_CANSET, 0x21, NULL, NULL },
    {{ 11, { 1, 3, 6, 1, 6, 3, 13, 1, 1, 1, 5, }}, "snmpNotifyRowStatus", SNMP_NODE_COLUMN, SNMP_SYNTAX_INTEGER, op_snmp_notify, 0|SNMP_NODE_CANSET, 0x21, NULL, NULL },
};

