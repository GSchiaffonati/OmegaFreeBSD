/*
 * This file is produced automatically.
 * Do not modify anything in here by hand.
 *
 * Created from source file
 *   /usr/home/freebsd/omega/src/sys/geom/part/g_part_if.m
 * with
 *   makeobjops.awk
 *
 * See the source file for legal information
 */

#include <sys/param.h>
#include <sys/queue.h>
#include <sys/kernel.h>
#include <sys/kobj.h>
#include <sys/param.h>
#include <sys/lock.h>
#include <sys/malloc.h>
#include <sys/mutex.h>
#include <sys/sbuf.h>
#include <sys/bus.h>
#include <machine/bus.h>
#include <sys/systm.h>
#include <geom/geom.h>
#include <geom/part/g_part.h>
#include "g_part_if.h"


static void
default_fullname(struct g_part_table *table,
    struct g_part_entry *entry, struct sbuf *sb, const char *pfx)
{
	char buf[32];

	sbuf_printf(sb, "%s%s", pfx,
	    G_PART_NAME(table, entry, buf, sizeof(buf)));
}

static int
default_precheck(struct g_part_table *t __unused,
    enum g_part_ctl r __unused, struct g_part_parms *p __unused)
{
	return (0);
}

static int
default_resize(struct g_part_table *t __unused,
    struct g_part_entry *e __unused, struct g_part_parms *p __unused)
{
	return (ENOSYS);
}

static int
default_recover(struct g_part_table *t __unused)
{
	return (ENOSYS);
}

static int
default_ioctl(struct g_part_table *table __unused, struct g_provider *pp __unused,
    u_long cmd __unused, void *data __unused, int fflag __unused,
    struct thread *td __unused)
{
	return (ENOIOCTL);
}

struct kobjop_desc g_part_add_desc = {
	0, { &g_part_add_desc, (kobjop_t)kobj_error_method }
};

struct kobjop_desc g_part_bootcode_desc = {
	0, { &g_part_bootcode_desc, (kobjop_t)kobj_error_method }
};

struct kobjop_desc g_part_create_desc = {
	0, { &g_part_create_desc, (kobjop_t)kobj_error_method }
};

struct kobjop_desc g_part_destroy_desc = {
	0, { &g_part_destroy_desc, (kobjop_t)kobj_error_method }
};

struct kobjop_desc g_part_dumpconf_desc = {
	0, { &g_part_dumpconf_desc, (kobjop_t)kobj_error_method }
};

struct kobjop_desc g_part_dumpto_desc = {
	0, { &g_part_dumpto_desc, (kobjop_t)kobj_error_method }
};

struct kobjop_desc g_part_fullname_desc = {
	0, { &g_part_fullname_desc, (kobjop_t)default_fullname }
};

struct kobjop_desc g_part_ioctl_desc = {
	0, { &g_part_ioctl_desc, (kobjop_t)default_ioctl }
};

struct kobjop_desc g_part_modify_desc = {
	0, { &g_part_modify_desc, (kobjop_t)kobj_error_method }
};

struct kobjop_desc g_part_resize_desc = {
	0, { &g_part_resize_desc, (kobjop_t)default_resize }
};

struct kobjop_desc g_part_name_desc = {
	0, { &g_part_name_desc, (kobjop_t)kobj_error_method }
};

struct kobjop_desc g_part_precheck_desc = {
	0, { &g_part_precheck_desc, (kobjop_t)default_precheck }
};

struct kobjop_desc g_part_probe_desc = {
	0, { &g_part_probe_desc, (kobjop_t)kobj_error_method }
};

struct kobjop_desc g_part_read_desc = {
	0, { &g_part_read_desc, (kobjop_t)kobj_error_method }
};

struct kobjop_desc g_part_recover_desc = {
	0, { &g_part_recover_desc, (kobjop_t)default_recover }
};

struct kobjop_desc g_part_setunset_desc = {
	0, { &g_part_setunset_desc, (kobjop_t)kobj_error_method }
};

struct kobjop_desc g_part_type_desc = {
	0, { &g_part_type_desc, (kobjop_t)kobj_error_method }
};

struct kobjop_desc g_part_write_desc = {
	0, { &g_part_write_desc, (kobjop_t)kobj_error_method }
};

