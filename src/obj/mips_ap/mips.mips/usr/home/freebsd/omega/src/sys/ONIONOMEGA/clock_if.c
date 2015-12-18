/*
 * This file is produced automatically.
 * Do not modify anything in here by hand.
 *
 * Created from source file
 *   /usr/home/freebsd/omega/src/sys/kern/clock_if.m
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
#include <sys/time.h>
#include "clock_if.h"

struct kobjop_desc clock_gettime_desc = {
	0, { &clock_gettime_desc, (kobjop_t)kobj_error_method }
};

struct kobjop_desc clock_settime_desc = {
	0, { &clock_settime_desc, (kobjop_t)kobj_error_method }
};

