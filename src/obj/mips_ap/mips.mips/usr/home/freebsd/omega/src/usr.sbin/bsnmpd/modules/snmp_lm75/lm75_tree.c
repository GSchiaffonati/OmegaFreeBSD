#include <sys/types.h>
#include <stdio.h>
#include <stdint.h>
#include <bsnmp/asn1.h>
#include <bsnmp/snmp.h>
#include <bsnmp/snmpagent.h>
#include "lm75_tree.h"

const struct snmp_node lm75_ctree[] = {
    {{ 12, { 1, 3, 6, 1, 4, 1, 12325, 1, 400, 1, 1, 1, }}, "lm75Sensors", SNMP_NODE_LEAF, SNMP_SYNTAX_INTEGER, op_lm75Sensors, 0, 0, NULL, NULL },
    {{ 13, { 1, 3, 6, 1, 4, 1, 12325, 1, 400, 1, 2, 1, 1, }}, "lm75SensorIndex", SNMP_NODE_COLUMN, SNMP_SYNTAX_INTEGER, op_lm75SensorTable, 0, 0x21, NULL, NULL },
    {{ 13, { 1, 3, 6, 1, 4, 1, 12325, 1, 400, 1, 2, 1, 2, }}, "lm75SensorSysctlIndex", SNMP_NODE_COLUMN, SNMP_SYNTAX_INTEGER, op_lm75SensorTable, 0, 0x21, NULL, NULL },
    {{ 13, { 1, 3, 6, 1, 4, 1, 12325, 1, 400, 1, 2, 1, 3, }}, "lm75SensorDesc", SNMP_NODE_COLUMN, SNMP_SYNTAX_OCTETSTRING, op_lm75SensorTable, 0, 0x21, NULL, NULL },
    {{ 13, { 1, 3, 6, 1, 4, 1, 12325, 1, 400, 1, 2, 1, 4, }}, "lm75SensorLocation", SNMP_NODE_COLUMN, SNMP_SYNTAX_OCTETSTRING, op_lm75SensorTable, 0, 0x21, NULL, NULL },
    {{ 13, { 1, 3, 6, 1, 4, 1, 12325, 1, 400, 1, 2, 1, 5, }}, "lm75SensorPnpInfo", SNMP_NODE_COLUMN, SNMP_SYNTAX_OCTETSTRING, op_lm75SensorTable, 0, 0x21, NULL, NULL },
    {{ 13, { 1, 3, 6, 1, 4, 1, 12325, 1, 400, 1, 2, 1, 6, }}, "lm75SensorParent", SNMP_NODE_COLUMN, SNMP_SYNTAX_OCTETSTRING, op_lm75SensorTable, 0, 0x21, NULL, NULL },
    {{ 13, { 1, 3, 6, 1, 4, 1, 12325, 1, 400, 1, 2, 1, 7, }}, "lm75SensorTemperature", SNMP_NODE_COLUMN, SNMP_SYNTAX_INTEGER, op_lm75SensorTable, 0, 0x21, NULL, NULL },
};

