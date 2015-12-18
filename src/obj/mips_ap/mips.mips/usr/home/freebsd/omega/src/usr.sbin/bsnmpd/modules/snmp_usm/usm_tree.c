#include <sys/types.h>
#include <stdio.h>
#include <stdint.h>
#include <bsnmp/asn1.h>
#include <bsnmp/snmp.h>
#include <bsnmp/snmpagent.h>
#include "usm_tree.h"

const struct snmp_node usm_ctree[] = {
    {{ 10, { 1, 3, 6, 1, 6, 3, 15, 1, 1, 1, }}, "usmStatsUnsupportedSecLevels", SNMP_NODE_LEAF, SNMP_SYNTAX_COUNTER, op_usm_stats, 0, 0, NULL, NULL },
    {{ 10, { 1, 3, 6, 1, 6, 3, 15, 1, 1, 2, }}, "usmStatsNotInTimeWindows", SNMP_NODE_LEAF, SNMP_SYNTAX_COUNTER, op_usm_stats, 0, 0, NULL, NULL },
    {{ 10, { 1, 3, 6, 1, 6, 3, 15, 1, 1, 3, }}, "usmStatsUnknownUserNames", SNMP_NODE_LEAF, SNMP_SYNTAX_COUNTER, op_usm_stats, 0, 0, NULL, NULL },
    {{ 10, { 1, 3, 6, 1, 6, 3, 15, 1, 1, 4, }}, "usmStatsUnknownEngineIDs", SNMP_NODE_LEAF, SNMP_SYNTAX_COUNTER, op_usm_stats, 0, 0, NULL, NULL },
    {{ 10, { 1, 3, 6, 1, 6, 3, 15, 1, 1, 5, }}, "usmStatsWrongDigests", SNMP_NODE_LEAF, SNMP_SYNTAX_COUNTER, op_usm_stats, 0, 0, NULL, NULL },
    {{ 10, { 1, 3, 6, 1, 6, 3, 15, 1, 1, 6, }}, "usmStatsDecryptionErrors", SNMP_NODE_LEAF, SNMP_SYNTAX_COUNTER, op_usm_stats, 0, 0, NULL, NULL },
    {{ 10, { 1, 3, 6, 1, 6, 3, 15, 1, 2, 1, }}, "usmUserSpinLock", SNMP_NODE_LEAF, SNMP_SYNTAX_INTEGER, op_usm_lock, 0|SNMP_NODE_CANSET, 0, NULL, NULL },
    {{ 12, { 1, 3, 6, 1, 6, 3, 15, 1, 2, 2, 1, 3, }}, "usmUserSecurityName", SNMP_NODE_COLUMN, SNMP_SYNTAX_OCTETSTRING, op_usm_users, 0, 0x222, NULL, NULL },
    {{ 12, { 1, 3, 6, 1, 6, 3, 15, 1, 2, 2, 1, 4, }}, "usmUserCloneFrom", SNMP_NODE_COLUMN, SNMP_SYNTAX_OID, op_usm_users, 0|SNMP_NODE_CANSET, 0x222, NULL, NULL },
    {{ 12, { 1, 3, 6, 1, 6, 3, 15, 1, 2, 2, 1, 5, }}, "usmUserAuthProtocol", SNMP_NODE_COLUMN, SNMP_SYNTAX_OID, op_usm_users, 0|SNMP_NODE_CANSET, 0x222, NULL, NULL },
    {{ 12, { 1, 3, 6, 1, 6, 3, 15, 1, 2, 2, 1, 6, }}, "usmUserAuthKeyChange", SNMP_NODE_COLUMN, SNMP_SYNTAX_OCTETSTRING, op_usm_users, 0|SNMP_NODE_CANSET, 0x222, NULL, NULL },
    {{ 12, { 1, 3, 6, 1, 6, 3, 15, 1, 2, 2, 1, 7, }}, "usmUserOwnAuthKeyChange", SNMP_NODE_COLUMN, SNMP_SYNTAX_OCTETSTRING, op_usm_users, 0|SNMP_NODE_CANSET, 0x222, NULL, NULL },
    {{ 12, { 1, 3, 6, 1, 6, 3, 15, 1, 2, 2, 1, 8, }}, "usmUserPrivProtocol", SNMP_NODE_COLUMN, SNMP_SYNTAX_OID, op_usm_users, 0|SNMP_NODE_CANSET, 0x222, NULL, NULL },
    {{ 12, { 1, 3, 6, 1, 6, 3, 15, 1, 2, 2, 1, 9, }}, "usmUserPrivKeyChange", SNMP_NODE_COLUMN, SNMP_SYNTAX_OCTETSTRING, op_usm_users, 0|SNMP_NODE_CANSET, 0x222, NULL, NULL },
    {{ 12, { 1, 3, 6, 1, 6, 3, 15, 1, 2, 2, 1, 10, }}, "usmUserOwnPrivKeyChange", SNMP_NODE_COLUMN, SNMP_SYNTAX_OCTETSTRING, op_usm_users, 0|SNMP_NODE_CANSET, 0x222, NULL, NULL },
    {{ 12, { 1, 3, 6, 1, 6, 3, 15, 1, 2, 2, 1, 11, }}, "usmUserPublic", SNMP_NODE_COLUMN, SNMP_SYNTAX_OCTETSTRING, op_usm_users, 0|SNMP_NODE_CANSET, 0x222, NULL, NULL },
    {{ 12, { 1, 3, 6, 1, 6, 3, 15, 1, 2, 2, 1, 12, }}, "usmUserStorageType", SNMP_NODE_COLUMN, SNMP_SYNTAX_INTEGER, op_usm_users, 0|SNMP_NODE_CANSET, 0x222, NULL, NULL },
    {{ 12, { 1, 3, 6, 1, 6, 3, 15, 1, 2, 2, 1, 13, }}, "usmUserStatus", SNMP_NODE_COLUMN, SNMP_SYNTAX_INTEGER, op_usm_users, 0|SNMP_NODE_CANSET, 0x222, NULL, NULL },
};

