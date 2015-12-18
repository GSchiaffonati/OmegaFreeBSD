/*
 * This file is produced automatically.
 * Do not modify anything in here by hand.
 *
 * Created from source file
 *   /usr/home/freebsd/omega/src/sys/dev/etherswitch/etherswitch_if.m
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
#include <sys/socket.h>
#include <net/if.h>
#include <dev/etherswitch/etherswitch.h>
#include "etherswitch_if.h"


static void
null_etherswitch_lock(device_t dev)
{
}

static void
null_etherswitch_unlock(device_t dev)
{
}

static int
null_etherswitch_getconf(device_t dev, etherswitch_conf_t *conf)
{
	return (0);
}

static int
null_etherswitch_setconf(device_t dev, etherswitch_conf_t *conf)
{
	return (0);
}

struct kobjop_desc etherswitch_getinfo_desc = {
	0, { &etherswitch_getinfo_desc, (kobjop_t)kobj_error_method }
};

struct kobjop_desc etherswitch_lock_desc = {
	0, { &etherswitch_lock_desc, (kobjop_t)null_etherswitch_lock }
};

struct kobjop_desc etherswitch_unlock_desc = {
	0, { &etherswitch_unlock_desc, (kobjop_t)null_etherswitch_unlock }
};

struct kobjop_desc etherswitch_readreg_desc = {
	0, { &etherswitch_readreg_desc, (kobjop_t)kobj_error_method }
};

struct kobjop_desc etherswitch_writereg_desc = {
	0, { &etherswitch_writereg_desc, (kobjop_t)kobj_error_method }
};

struct kobjop_desc etherswitch_readphyreg_desc = {
	0, { &etherswitch_readphyreg_desc, (kobjop_t)kobj_error_method }
};

struct kobjop_desc etherswitch_writephyreg_desc = {
	0, { &etherswitch_writephyreg_desc, (kobjop_t)kobj_error_method }
};

struct kobjop_desc etherswitch_getport_desc = {
	0, { &etherswitch_getport_desc, (kobjop_t)kobj_error_method }
};

struct kobjop_desc etherswitch_setport_desc = {
	0, { &etherswitch_setport_desc, (kobjop_t)kobj_error_method }
};

struct kobjop_desc etherswitch_getvgroup_desc = {
	0, { &etherswitch_getvgroup_desc, (kobjop_t)kobj_error_method }
};

struct kobjop_desc etherswitch_setvgroup_desc = {
	0, { &etherswitch_setvgroup_desc, (kobjop_t)kobj_error_method }
};

struct kobjop_desc etherswitch_getconf_desc = {
	0, { &etherswitch_getconf_desc, (kobjop_t)null_etherswitch_getconf }
};

struct kobjop_desc etherswitch_setconf_desc = {
	0, { &etherswitch_setconf_desc, (kobjop_t)null_etherswitch_setconf }
};

