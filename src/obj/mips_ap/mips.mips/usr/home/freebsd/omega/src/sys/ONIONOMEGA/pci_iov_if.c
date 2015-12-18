/*
 * This file is produced automatically.
 * Do not modify anything in here by hand.
 *
 * Created from source file
 *   /usr/home/freebsd/omega/src/sys/dev/pci/pci_iov_if.m
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
#include "pci_iov_if.h"

struct kobjop_desc pci_iov_init_desc = {
	0, { &pci_iov_init_desc, (kobjop_t)kobj_error_method }
};

struct kobjop_desc pci_iov_uninit_desc = {
	0, { &pci_iov_uninit_desc, (kobjop_t)kobj_error_method }
};

struct kobjop_desc pci_iov_add_vf_desc = {
	0, { &pci_iov_add_vf_desc, (kobjop_t)kobj_error_method }
};

