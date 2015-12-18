/* bsdbox.c - generated from bsdbox.conf by crunchgen 0.2 */
#define EXECNAME "bsdbox"
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
extern int _crunched_ls_stub();
extern int _crunched_cat_stub();
extern int _crunched_dd_stub();
extern int _crunched_df_stub();
extern int _crunched_cp_stub();
extern int _crunched_hostname_stub();
extern int _crunched_kill_stub();
extern int _crunched_mkdir_stub();
extern int _crunched_sleep_stub();
extern int _crunched_ps_stub();
extern int _crunched_ln_stub();
extern int _crunched_rm_stub();
extern int _crunched_kenv_stub();
extern int _crunched_mv_stub();
extern int _crunched_expr_stub();
extern int _crunched_sh_stub();
extern int _crunched_dmesg_stub();
extern int _crunched_sysctl_stub();
extern int _crunched_init_stub();
extern int _crunched_reboot_stub();
extern int _crunched_mount_stub();
extern int _crunched_umount_stub();
extern int _crunched_route_stub();
extern int _crunched_ping_stub();
extern int _crunched_ifconfig_stub();
extern int _crunched_kldload_stub();
extern int _crunched_kldunload_stub();
extern int _crunched_kldstat_stub();
extern int _crunched_mdmfs_stub();
extern int _crunched_mdconfig_stub();
extern int _crunched_newfs_stub();
extern int _crunched_true_stub();
extern int _crunched_false_stub();
extern int _crunched_hexdump_stub();
extern int _crunched_tail_stub();
extern int _crunched_nc_stub();
extern int _crunched_w_stub();
extern int _crunched_head_stub();
extern int _crunched_uname_stub();
extern int _crunched_tset_stub();
extern int _crunched_vmstat_stub();
extern int _crunched_cpio_stub();
extern int _crunched_tput_stub();
extern int _crunched_passwd_stub();
extern int _crunched_gzip_stub();
extern int _crunched_netstat_stub();
extern int _crunched_cap_mkdb_stub();
extern int _crunched_gpioctl_stub();
extern int _crunched_chown_stub();
extern int _crunched_arp_stub();
extern int _crunched_inetd_stub();
extern int _crunched_wlandebug_stub();
extern int _crunched_tcpdump_stub();
extern int _crunched_hostapd_stub();
extern int _crunched_hostapd_cli_stub();
extern int _crunched_pwd_mkdb_stub();
extern int _crunched_getty_stub();

struct stub entry_points[] = {
	{ "ls", _crunched_ls_stub },
	{ "cat", _crunched_cat_stub },
	{ "dd", _crunched_dd_stub },
	{ "df", _crunched_df_stub },
	{ "cp", _crunched_cp_stub },
	{ "hostname", _crunched_hostname_stub },
	{ "kill", _crunched_kill_stub },
	{ "mkdir", _crunched_mkdir_stub },
	{ "sleep", _crunched_sleep_stub },
	{ "ps", _crunched_ps_stub },
	{ "ln", _crunched_ln_stub },
	{ "rm", _crunched_rm_stub },
	{ "kenv", _crunched_kenv_stub },
	{ "mv", _crunched_mv_stub },
	{ "expr", _crunched_expr_stub },
	{ "sh", _crunched_sh_stub },
	{ "-sh", _crunched_sh_stub },
	{ "dmesg", _crunched_dmesg_stub },
	{ "sysctl", _crunched_sysctl_stub },
	{ "init", _crunched_init_stub },
	{ "reboot", _crunched_reboot_stub },
	{ "mount", _crunched_mount_stub },
	{ "umount", _crunched_umount_stub },
	{ "route", _crunched_route_stub },
	{ "ping", _crunched_ping_stub },
	{ "ifconfig", _crunched_ifconfig_stub },
	{ "kldload", _crunched_kldload_stub },
	{ "kldunload", _crunched_kldunload_stub },
	{ "kldstat", _crunched_kldstat_stub },
	{ "mdmfs", _crunched_mdmfs_stub },
	{ "mount_mfs", _crunched_mdmfs_stub },
	{ "mdconfig", _crunched_mdconfig_stub },
	{ "newfs", _crunched_newfs_stub },
	{ "true", _crunched_true_stub },
	{ "false", _crunched_false_stub },
	{ "hexdump", _crunched_hexdump_stub },
	{ "tail", _crunched_tail_stub },
	{ "nc", _crunched_nc_stub },
	{ "w", _crunched_w_stub },
	{ "uptime", _crunched_w_stub },
	{ "head", _crunched_head_stub },
	{ "uname", _crunched_uname_stub },
	{ "tset", _crunched_tset_stub },
	{ "reset", _crunched_tset_stub },
	{ "vmstat", _crunched_vmstat_stub },
	{ "cpio", _crunched_cpio_stub },
	{ "tput", _crunched_tput_stub },
	{ "passwd", _crunched_passwd_stub },
	{ "gzip", _crunched_gzip_stub },
	{ "gunzip", _crunched_gzip_stub },
	{ "gzcat", _crunched_gzip_stub },
	{ "zcat", _crunched_gzip_stub },
	{ "netstat", _crunched_netstat_stub },
	{ "cap_mkdb", _crunched_cap_mkdb_stub },
	{ "gpioctl", _crunched_gpioctl_stub },
	{ "chown", _crunched_chown_stub },
	{ "chgrp", _crunched_chown_stub },
	{ "arp", _crunched_arp_stub },
	{ "inetd", _crunched_inetd_stub },
	{ "wlandebug", _crunched_wlandebug_stub },
	{ "tcpdump", _crunched_tcpdump_stub },
	{ "hostapd", _crunched_hostapd_stub },
	{ "hostapd_cli", _crunched_hostapd_cli_stub },
	{ "pwd_mkdb", _crunched_pwd_mkdb_stub },
	{ "getty", _crunched_getty_stub },
	{ EXECNAME, crunched_main },
	{ NULL, NULL }
};
