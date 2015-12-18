/*
 * This file is produced automatically.
 * Do not modify anything in here by hand.
 *
 * Created from source file
 *   /usr/home/freebsd/omega/src/sys/dev/mmc/mmcbr_if.m
 * with
 *   makeobjops.awk
 *
 * See the source file for legal information
 */

#include <sys/param.h>
#include <sys/queue.h>
#include <sys/kernel.h>
#include <sys/kobj.h>
#include <sys/types.h>
#include <dev/mmc/bridge.h>
#include <dev/mmc/mmcreg.h>
#include "mmcbr_if.h"

struct kobjop_desc mmcbr_update_ios_desc = {
	0, { &mmcbr_update_ios_desc, (kobjop_t)kobj_error_method }
};

struct kobjop_desc mmcbr_request_desc = {
	0, { &mmcbr_request_desc, (kobjop_t)kobj_error_method }
};

struct kobjop_desc mmcbr_get_ro_desc = {
	0, { &mmcbr_get_ro_desc, (kobjop_t)kobj_error_method }
};

struct kobjop_desc mmcbr_acquire_host_desc = {
	0, { &mmcbr_acquire_host_desc, (kobjop_t)kobj_error_method }
};

struct kobjop_desc mmcbr_release_host_desc = {
	0, { &mmcbr_release_host_desc, (kobjop_t)kobj_error_method }
};

