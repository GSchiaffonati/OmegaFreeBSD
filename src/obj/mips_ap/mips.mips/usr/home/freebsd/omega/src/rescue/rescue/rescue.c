/* rescue.c - generated from rescue.conf by crunchgen 0.2 */
#define EXECNAME "rescue"
/*
 * Copyright (c) 1994 University of Maryland
 * All Rights Reserved.
 *
 * Permission to use, copy, modify, distribute, and sell this software and its
 * documentation for any purpose is hereby granted without fee, provided that
 * the above copyright notice appear in all copies and that both that
 * copyright notice and this permission notice appear in supporting
 * documentation, and that the name of U.M. not be used in advertising or
 * publicity pertaining to distribution of the software without specific,
 * written prior permission.  U.M. makes no representations about the
 * suitability of this software for any purpose.  It is provided "as is"
 * without express or implied warranty.
 *
 * U.M. DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL U.M.
 * BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION
 * OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN
 * CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 *
 * Author: James da Silva, Systems Design and Analysis Group
 *			   Computer Science Department
 *			   University of Maryland at College Park
 */
/*
 * crunched_main.c - main program for crunched binaries, it branches to a
 * 	particular subprogram based on the value of argv[0].  Also included
 *	is a little program invoked when the crunched binary is called via
 *	its EXECNAME.  This one prints out the list of compiled-in binaries,
 *	or calls one of them based on argv[1].   This allows the testing of
 *	the crunched binary without creating all the links.
 */

#include <sys/cdefs.h>
__FBSDID("$FreeBSD$");

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stub {
    char *name;
    int (*f)();
};

extern char *__progname;
extern struct stub entry_points[];

int
main(int argc, char **argv, char **envp)
{
    char *slash, *basename;
    struct stub *ep;

    if(argv[0] == NULL || *argv[0] == '\0')
	crunched_usage();

    slash = strrchr(argv[0], '/');
    basename = slash? slash+1 : argv[0];

    for(ep=entry_points; ep->name != NULL; ep++)
	if(!strcmp(basename, ep->name)) break;

    if(ep->name)
	return ep->f(argc, argv, envp);
    else {
	fprintf(stderr, "%s: %s not compiled in\n", EXECNAME, basename);
	crunched_usage();
    }
}


int
crunched_here(char *path)
{
    char *slash, *basename;
    struct stub *ep;

    slash = strrchr(path, '/');
    basename = slash? slash+1 : path;

    for(ep=entry_points; ep->name != NULL; ep++)
	if(!strcmp(basename, ep->name))
	    return 1;
    return 0;
}


int
crunched_main(int argc, char **argv, char **envp)
{
    char *slash;
    struct stub *ep;
    int columns, len;

    if(argc <= 1)
	crunched_usage();

    slash = strrchr(argv[1], '/');
    __progname = slash? slash+1 : argv[1];

    return main(--argc, ++argv, envp);
}


int
crunched_usage()
{
    int columns, len;
    struct stub *ep;

    fprintf(stderr, "usage: %s <prog> <args> ..., where <prog> is one of:\n",
	    EXECNAME);
    columns = 0;
    for(ep=entry_points; ep->name != NULL; ep++) {
	len = strlen(ep->name) + 1;
	if(columns+len < 80)
	    columns += len;
	else {
	    fprintf(stderr, "\n");
	    columns = len;
	}
	fprintf(stderr, " %s", ep->name);
    }
    fprintf(stderr, "\n");
    exit(1);
}

/* end of crunched_main.c */
extern int _crunched_cat_stub();
extern int _crunched_chflags_stub();
extern int _crunched_chio_stub();
extern int _crunched_chmod_stub();
extern int _crunched_cp_stub();
extern int _crunched_date_stub();
extern int _crunched_dd_stub();
extern int _crunched_df_stub();
extern int _crunched_echo_stub();
extern int _crunched_ed_stub();
extern int _crunched_expr_stub();
extern int _crunched_getfacl_stub();
extern int _crunched_hostname_stub();
extern int _crunched_kenv_stub();
extern int _crunched_kill_stub();
extern int _crunched_ln_stub();
extern int _crunched_ls_stub();
extern int _crunched_mkdir_stub();
extern int _crunched_mv_stub();
extern int _crunched_pkill_stub();
extern int _crunched_ps_stub();
extern int _crunched_pwd_stub();
extern int _crunched_realpath_stub();
extern int _crunched_rm_stub();
extern int _crunched_rmdir_stub();
extern int _crunched_setfacl_stub();
extern int _crunched_sh_stub();
extern int _crunched_sleep_stub();
extern int _crunched_stty_stub();
extern int _crunched_sync_stub();
extern int _crunched_test_stub();
extern int _crunched_rcp_stub();
extern int _crunched_csh_stub();
extern int _crunched_badsect_stub();
extern int _crunched_camcontrol_stub();
extern int _crunched_ccdconfig_stub();
extern int _crunched_clri_stub();
extern int _crunched_devfs_stub();
extern int _crunched_dmesg_stub();
extern int _crunched_dump_stub();
extern int _crunched_dumpfs_stub();
extern int _crunched_dumpon_stub();
extern int _crunched_fsck_stub();
extern int _crunched_fsck_ffs_stub();
extern int _crunched_fsck_msdosfs_stub();
extern int _crunched_fsdb_stub();
extern int _crunched_fsirand_stub();
extern int _crunched_gbde_stub();
extern int _crunched_geom_stub();
extern int _crunched_ifconfig_stub();
extern int _crunched_init_stub();
extern int _crunched_kldconfig_stub();
extern int _crunched_kldload_stub();
extern int _crunched_kldstat_stub();
extern int _crunched_kldunload_stub();
extern int _crunched_ldconfig_stub();
extern int _crunched_md5_stub();
extern int _crunched_mdconfig_stub();
extern int _crunched_mdmfs_stub();
extern int _crunched_mknod_stub();
extern int _crunched_mount_stub();
extern int _crunched_mount_cd9660_stub();
extern int _crunched_mount_msdosfs_stub();
extern int _crunched_mount_nfs_stub();
extern int _crunched_mount_nullfs_stub();
extern int _crunched_mount_udf_stub();
extern int _crunched_mount_unionfs_stub();
extern int _crunched_newfs_stub();
extern int _crunched_newfs_msdos_stub();
extern int _crunched_nos_tun_stub();
extern int _crunched_ping_stub();
extern int _crunched_reboot_stub();
extern int _crunched_restore_stub();
extern int _crunched_rcorder_stub();
extern int _crunched_route_stub();
extern int _crunched_routed_stub();
extern int _crunched_rtquery_stub();
extern int _crunched_rtsol_stub();
extern int _crunched_savecore_stub();
extern int _crunched_spppcontrol_stub();
extern int _crunched_swapon_stub();
extern int _crunched_sysctl_stub();
extern int _crunched_tunefs_stub();
extern int _crunched_umount_stub();
extern int _crunched_ping6_stub();
extern int _crunched_ipf_stub();
extern int _crunched_zfs_stub();
extern int _crunched_zpool_stub();
extern int _crunched_dhclient_stub();
extern int _crunched_head_stub();
extern int _crunched_mt_stub();
extern int _crunched_nc_stub();
extern int _crunched_sed_stub();
extern int _crunched_tail_stub();
extern int _crunched_tee_stub();
extern int _crunched_gzip_stub();
extern int _crunched_bzip2_stub();
extern int _crunched_less_stub();
extern int _crunched_xz_stub();
extern int _crunched_tar_stub();
extern int _crunched_vi_stub();
extern int _crunched_id_stub();
extern int _crunched_iscsictl_stub();
extern int _crunched_zdb_stub();
extern int _crunched_chroot_stub();
extern int _crunched_chown_stub();
extern int _crunched_iscsid_stub();

struct stub entry_points[] = {
	{ "cat", _crunched_cat_stub },
	{ "chflags", _crunched_chflags_stub },
	{ "chio", _crunched_chio_stub },
	{ "chmod", _crunched_chmod_stub },
	{ "cp", _crunched_cp_stub },
	{ "date", _crunched_date_stub },
	{ "dd", _crunched_dd_stub },
	{ "df", _crunched_df_stub },
	{ "echo", _crunched_echo_stub },
	{ "ed", _crunched_ed_stub },
	{ "red", _crunched_ed_stub },
	{ "expr", _crunched_expr_stub },
	{ "getfacl", _crunched_getfacl_stub },
	{ "hostname", _crunched_hostname_stub },
	{ "kenv", _crunched_kenv_stub },
	{ "kill", _crunched_kill_stub },
	{ "ln", _crunched_ln_stub },
	{ "link", _crunched_ln_stub },
	{ "ls", _crunched_ls_stub },
	{ "mkdir", _crunched_mkdir_stub },
	{ "mv", _crunched_mv_stub },
	{ "pkill", _crunched_pkill_stub },
	{ "pgrep", _crunched_pkill_stub },
	{ "ps", _crunched_ps_stub },
	{ "pwd", _crunched_pwd_stub },
	{ "realpath", _crunched_realpath_stub },
	{ "rm", _crunched_rm_stub },
	{ "unlink", _crunched_rm_stub },
	{ "rmdir", _crunched_rmdir_stub },
	{ "setfacl", _crunched_setfacl_stub },
	{ "sh", _crunched_sh_stub },
	{ "-sh", _crunched_sh_stub },
	{ "sleep", _crunched_sleep_stub },
	{ "stty", _crunched_stty_stub },
	{ "sync", _crunched_sync_stub },
	{ "test", _crunched_test_stub },
	{ "[", _crunched_test_stub },
	{ "rcp", _crunched_rcp_stub },
	{ "csh", _crunched_csh_stub },
	{ "-csh", _crunched_csh_stub },
	{ "tcsh", _crunched_csh_stub },
	{ "-tcsh", _crunched_csh_stub },
	{ "badsect", _crunched_badsect_stub },
	{ "camcontrol", _crunched_camcontrol_stub },
	{ "ccdconfig", _crunched_ccdconfig_stub },
	{ "clri", _crunched_clri_stub },
	{ "devfs", _crunched_devfs_stub },
	{ "dmesg", _crunched_dmesg_stub },
	{ "dump", _crunched_dump_stub },
	{ "rdump", _crunched_dump_stub },
	{ "dumpfs", _crunched_dumpfs_stub },
	{ "dumpon", _crunched_dumpon_stub },
	{ "fsck", _crunched_fsck_stub },
	{ "fsck_ffs", _crunched_fsck_ffs_stub },
	{ "fsck_4.2bsd", _crunched_fsck_ffs_stub },
	{ "fsck_ufs", _crunched_fsck_ffs_stub },
	{ "fsck_msdosfs", _crunched_fsck_msdosfs_stub },
	{ "fsdb", _crunched_fsdb_stub },
	{ "fsirand", _crunched_fsirand_stub },
	{ "gbde", _crunched_gbde_stub },
	{ "geom", _crunched_geom_stub },
	{ "glabel", _crunched_geom_stub },
	{ "gpart", _crunched_geom_stub },
	{ "ifconfig", _crunched_ifconfig_stub },
	{ "init", _crunched_init_stub },
	{ "kldconfig", _crunched_kldconfig_stub },
	{ "kldload", _crunched_kldload_stub },
	{ "kldstat", _crunched_kldstat_stub },
	{ "kldunload", _crunched_kldunload_stub },
	{ "ldconfig", _crunched_ldconfig_stub },
	{ "md5", _crunched_md5_stub },
	{ "mdconfig", _crunched_mdconfig_stub },
	{ "mdmfs", _crunched_mdmfs_stub },
	{ "mknod", _crunched_mknod_stub },
	{ "mount", _crunched_mount_stub },
	{ "mount_cd9660", _crunched_mount_cd9660_stub },
	{ "mount_msdosfs", _crunched_mount_msdosfs_stub },
	{ "mount_nfs", _crunched_mount_nfs_stub },
	{ "mount_nullfs", _crunched_mount_nullfs_stub },
	{ "mount_udf", _crunched_mount_udf_stub },
	{ "mount_unionfs", _crunched_mount_unionfs_stub },
	{ "newfs", _crunched_newfs_stub },
	{ "newfs_msdos", _crunched_newfs_msdos_stub },
	{ "nos-tun", _crunched_nos_tun_stub },
	{ "ping", _crunched_ping_stub },
	{ "reboot", _crunched_reboot_stub },
	{ "fastboot", _crunched_reboot_stub },
	{ "halt", _crunched_reboot_stub },
	{ "fasthalt", _crunched_reboot_stub },
	{ "restore", _crunched_restore_stub },
	{ "rrestore", _crunched_restore_stub },
	{ "rcorder", _crunched_rcorder_stub },
	{ "route", _crunched_route_stub },
	{ "routed", _crunched_routed_stub },
	{ "rtquery", _crunched_rtquery_stub },
	{ "rtsol", _crunched_rtsol_stub },
	{ "savecore", _crunched_savecore_stub },
	{ "spppcontrol", _crunched_spppcontrol_stub },
	{ "swapon", _crunched_swapon_stub },
	{ "sysctl", _crunched_sysctl_stub },
	{ "tunefs", _crunched_tunefs_stub },
	{ "umount", _crunched_umount_stub },
	{ "ping6", _crunched_ping6_stub },
	{ "ipf", _crunched_ipf_stub },
	{ "zfs", _crunched_zfs_stub },
	{ "zpool", _crunched_zpool_stub },
	{ "dhclient", _crunched_dhclient_stub },
	{ "head", _crunched_head_stub },
	{ "mt", _crunched_mt_stub },
	{ "nc", _crunched_nc_stub },
	{ "sed", _crunched_sed_stub },
	{ "tail", _crunched_tail_stub },
	{ "tee", _crunched_tee_stub },
	{ "gzip", _crunched_gzip_stub },
	{ "gunzip", _crunched_gzip_stub },
	{ "gzcat", _crunched_gzip_stub },
	{ "zcat", _crunched_gzip_stub },
	{ "bzip2", _crunched_bzip2_stub },
	{ "bunzip2", _crunched_bzip2_stub },
	{ "bzcat", _crunched_bzip2_stub },
	{ "less", _crunched_less_stub },
	{ "more", _crunched_less_stub },
	{ "xz", _crunched_xz_stub },
	{ "unxz", _crunched_xz_stub },
	{ "lzma", _crunched_xz_stub },
	{ "unlzma", _crunched_xz_stub },
	{ "xzcat", _crunched_xz_stub },
	{ "lzcat", _crunched_xz_stub },
	{ "tar", _crunched_tar_stub },
	{ "vi", _crunched_vi_stub },
	{ "ex", _crunched_vi_stub },
	{ "id", _crunched_id_stub },
	{ "groups", _crunched_id_stub },
	{ "whoami", _crunched_id_stub },
	{ "iscsictl", _crunched_iscsictl_stub },
	{ "zdb", _crunched_zdb_stub },
	{ "chroot", _crunched_chroot_stub },
	{ "chown", _crunched_chown_stub },
	{ "chgrp", _crunched_chown_stub },
	{ "iscsid", _crunched_iscsid_stub },
	{ EXECNAME, crunched_main },
	{ NULL, NULL }
};
