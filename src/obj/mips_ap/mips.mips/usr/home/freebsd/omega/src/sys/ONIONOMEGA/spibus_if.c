/*
 * This file is produced automatically.
 * Do not modify anything in here by hand.
 *
 * Created from source file
 *   /usr/home/freebsd/omega/src/sys/dev/spibus/spibus_if.m
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
#include <dev/spibus/spi.h>
#include "spibus_if.h"

struct kobjop_desc spibus_transfer_desc = {
	0, { &spibus_transfer_desc, (kobjop_t)kobj_error_method }
};

