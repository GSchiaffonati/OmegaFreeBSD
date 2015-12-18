/*
 * This file is produced automatically.
 * Do not modify anything in here by hand.
 *
 * Created from source file
 *   /usr/home/freebsd/omega/src/sys/dev/etherswitch/mdio_if.m
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
#include "mdio_if.h"

struct kobjop_desc mdio_readreg_desc = {
	0, { &mdio_readreg_desc, (kobjop_t)kobj_error_method }
};

struct kobjop_desc mdio_writereg_desc = {
	0, { &mdio_writereg_desc, (kobjop_t)kobj_error_method }
};

