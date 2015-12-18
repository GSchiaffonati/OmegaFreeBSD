#include <sys/types.h>
#include <stdio.h>
#include <stdint.h>
#include <bsnmp/asn1.h>
#include <bsnmp/snmp.h>
#include <bsnmp/snmpagent.h>
#include "vacm_tree.h"

const struct snmp_node vacm_ctree[] = {
    {{ 11, { 1, 3, 6, 1, 6, 3, 16, 1, 1, 1, 1, }}, "vacmContextName", SNMP_NODE_COLUMN, SNMP_SYNTAX_OCTETSTRING, op_vacm_context, 0, 0x21, NULL, NULL },
    {{ 11, { 1, 3, 6, 1, 6, 3, 16, 1, 2, 1, 3, }}, "vacmGroupName", SNMP_NODE_COLUMN, SNMP_SYNTAX_OCTETSTRING, op_vacm_security_to_group, 0|SNMP_NODE_CANSET, 0x212, NULL, NULL },
    {{ 11, { 1, 3, 6, 1, 6, 3, 16, 1, 2, 1, 4, }}, "vacmSecurityToGroupStorageType", SNMP_NODE_COLUMN, SNMP_SYNTAX_INTEGER, op_vacm_security_to_group, 0|SNMP_NODE_CANSET, 0x212, NULL, NULL },
    {{ 11, { 1, 3, 6, 1, 6, 3, 16, 1, 2, 1, 5, }}, "vacmSecurityToGroupStatus", SNMP_NODE_COLUMN, SNMP_SYNTAX_INTEGER, op_vacm_security_to_group, 0|SNMP_NODE_CANSET, 0x212, NULL, NULL },
    {{ 11, { 1, 3, 6, 1, 6, 3, 16, 1, 4, 1, 4, }}, "vacmAccessContextMatch", SNMP_NODE_COLUMN, SNMP_SYNTAX_INTEGER, op_vacm_access, 0|SNMP_NODE_CANSET, 0x11224, NULL, NULL },
    {{ 11, { 1, 3, 6, 1, 6, 3, 16, 1, 4, 1, 5, }}, "vacmAccessReadViewName", SNMP_NODE_COLUMN, SNMP_SYNTAX_OCTETSTRING, op_vacm_access, 0|SNMP_NODE_CANSET, 0x11224, NULL, NULL },
    {{ 11, { 1, 3, 6, 1, 6, 3, 16, 1, 4, 1, 6, }}, "vacmAccessWriteViewName", SNMP_NODE_COLUMN, SNMP_SYNTAX_OCTETSTRING, op_vacm_access, 0|SNMP_NODE_CANSET, 0x11224, NULL, NULL },
    {{ 11, { 1, 3, 6, 1, 6, 3, 16, 1, 4, 1, 7, }}, "vacmAccessNotifyViewName", SNMP_NODE_COLUMN, SNMP_SYNTAX_OCTETSTRING, op_vacm_access, 0|SNMP_NODE_CANSET, 0x11224, NULL, NULL },
    {{ 11, { 1, 3, 6, 1, 6, 3, 16, 1, 4, 1, 8, }}, "vacmAccessStorageType", SNMP_NODE_COLUMN, SNMP_SYNTAX_INTEGER, op_vacm_access, 0|SNMP_NODE_CANSET, 0x11224, NULL, NULL },
    {{ 11, { 1, 3, 6, 1, 6, 3, 16, 1, 4, 1, 9, }}, "vacmAccessStatus", SNMP_NODE_COLUMN, SNMP_SYNTAX_INTEGER, op_vacm_access, 0|SNMP_NODE_CANSET, 0x11224, NULL, NULL },
    {{ 10, { 1, 3, 6, 1, 6, 3, 16, 1, 5, 1, }}, "vacmViewSpinLock", SNMP_NODE_LEAF, SNMP_SYNTAX_INTEGER, op_vacm_view_lock, 0|SNMP_NODE_CANSET, 0, NULL, NULL },
    {{ 12, { 1, 3, 6, 1, 6, 3, 16, 1, 5, 2, 1, 3, }}, "vacmViewTreeFamilyMask", SNMP_NODE_COLUMN, SNMP_SYNTAX_OCTETSTRING, op_vacm_view, 0|SNMP_NODE_CANSET, 0x322, NULL, NULL },
    {{ 12, { 1, 3, 6, 1, 6, 3, 16, 1, 5, 2, 1, 4, }}, "vacmViewTreeFamilyType", SNMP_NODE_COLUMN, SNMP_SYNTAX_INTEGER, op_vacm_view, 0|SNMP_NODE_CANSET, 0x322, NULL, NULL },
    {{ 12, { 1, 3, 6, 1, 6, 3, 16, 1, 5, 2, 1, 5, }}, "vacmViewTreeFamilyStorageType", SNMP_NODE_COLUMN, SNMP_SYNTAX_INTEGER, op_vacm_view, 0|SNMP_NODE_CANSET, 0x322, NULL, NULL },
    {{ 12, { 1, 3, 6, 1, 6, 3, 16, 1, 5, 2, 1, 6, }}, "vacmViewTreeFamilyStatus", SNMP_NODE_COLUMN, SNMP_SYNTAX_INTEGER, op_vacm_view, 0|SNMP_NODE_CANSET, 0x322, NULL, NULL },
};

