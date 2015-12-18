/*
 * This file is produced automatically.
 * Do not modify anything in here by hand.
 *
 * Created from source file
 *   /usr/home/freebsd/omega/src/sys/dev/pccard/card_if.m
 * with
 *   makeobjops.awk
 *
 * See the source file for legal information
 */

#include <sys/param.h>
#include <sys/queue.h>
#include <sys/kernel.h>
#include <sys/kobj.h>
#include <sys/bus.h>
#include <machine/bus.h>
#include <dev/pccard/pccardvar.h>
#include "card_if.h"

struct kobjop_desc card_set_res_flags_desc = {
	0, { &card_set_res_flags_desc, (kobjop_t)kobj_error_method }
};

struct kobjop_desc card_get_res_flags_desc = {
	0, { &card_get_res_flags_desc, (kobjop_t)kobj_error_method }
};

struct kobjop_desc card_set_memory_offset_desc = {
	0, { &card_set_memory_offset_desc, (kobjop_t)kobj_error_method }
};

struct kobjop_desc card_get_memory_offset_desc = {
	0, { &card_get_memory_offset_desc, (kobjop_t)kobj_error_method }
};

struct kobjop_desc card_attach_card_desc = {
	0, { &card_attach_card_desc, (kobjop_t)kobj_error_method }
};

struct kobjop_desc card_detach_card_desc = {
	0, { &card_detach_card_desc, (kobjop_t)kobj_error_method }
};

struct kobjop_desc card_do_product_lookup_desc = {
	0, { &card_do_product_lookup_desc, (kobjop_t)kobj_error_method }
};

struct kobjop_desc card_cis_scan_desc = {
	0, { &card_cis_scan_desc, (kobjop_t)kobj_error_method }
};

struct kobjop_desc card_attr_read_desc = {
	0, { &card_attr_read_desc, (kobjop_t)kobj_error_method }
};

struct kobjop_desc card_attr_write_desc = {
	0, { &card_attr_write_desc, (kobjop_t)kobj_error_method }
};

struct kobjop_desc card_ccr_read_desc = {
	0, { &card_ccr_read_desc, (kobjop_t)kobj_error_method }
};

struct kobjop_desc card_ccr_write_desc = {
	0, { &card_ccr_write_desc, (kobjop_t)kobj_error_method }
};

