/*
 * This file is produced automatically.
 * Do not modify anything in here by hand.
 *
 * Created from source file
 *   /usr/home/freebsd/omega/src/sys/isa/isa_if.m
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
#include <isa/isavar.h>
#include "isa_if.h"

struct kobjop_desc isa_add_config_desc = {
	0, { &isa_add_config_desc, (kobjop_t)kobj_error_method }
};

struct kobjop_desc isa_set_config_callback_desc = {
	0, { &isa_set_config_callback_desc, (kobjop_t)kobj_error_method }
};

struct kobjop_desc isa_pnp_probe_desc = {
	0, { &isa_pnp_probe_desc, (kobjop_t)kobj_error_method }
};

