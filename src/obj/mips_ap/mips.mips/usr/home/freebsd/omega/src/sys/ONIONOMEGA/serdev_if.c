/*
 * This file is produced automatically.
 * Do not modify anything in here by hand.
 *
 * Created from source file
 *   /usr/home/freebsd/omega/src/sys/kern/serdev_if.m
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
#include <sys/serial.h>
#include "serdev_if.h"


static serdev_intr_t *
default_ihand(device_t dev, int ipend)
{
	return (NULL);
}

static int
default_ipend(device_t dev)
{
	return (-1);
}

static int
default_sysdev(device_t dev)
{
	return (0);
}

struct kobjop_desc serdev_ihand_desc = {
	0, { &serdev_ihand_desc, (kobjop_t)default_ihand }
};

struct kobjop_desc serdev_ipend_desc = {
	0, { &serdev_ipend_desc, (kobjop_t)default_ipend }
};

struct kobjop_desc serdev_sysdev_desc = {
	0, { &serdev_sysdev_desc, (kobjop_t)default_sysdev }
};

