#include <stdint.h>
#include <stdio.h>
#include <sys/fcntl.h>
#include <sys/stat.h>
#include <sys/unistd.h>
#include <sys/mman.h>
#include <sys/wait.h>
#define _KERNEL
#include <sys/socket.h>
#undef _KERNEL
#include <netinet/in.h>
#include <sys/param.h>
#include <sys/mount.h>
#include <sys/procctl.h>
#include <sys/ptrace.h>
#include <sys/resource.h>
#include <sys/reboot.h>
#include <sched.h>
#include <sys/linker.h>
#define _KERNEL
#include <sys/thr.h>
#undef _KERNEL
#include <sys/extattr.h>
#include <sys/acl.h>
#include <aio.h>
#include <sys/sem.h>
#include <sys/ipc.h>
#include <sys/rtprio.h>
#include <sys/shm.h>
#include <sys/umtx.h>
#include <nfsserver/nfs.h>
#include <ufs/ufs/quota.h>
#include <sys/capsicum.h>
#include <vm/vm.h>
#include <vm/vm_param.h>

#include "kdump_subr.h"

/*
 * These are simple support macros. print_or utilizes a variable
 * defined in the calling function to track whether or not it should
 * print a logical-OR character ('|') before a string. if_print_or
 * simply handles the necessary "if" statement used in many lines
 * of this file.
 */
#define print_or(str,orflag) do {                  \
	if (orflag) putchar('|'); else orflag = 1; \
	printf (str); }                            \
	while (0)
#define if_print_or(i,flag,orflag) do {            \
	if ((i & flag) == flag)                    \
	print_or(#flag,orflag); }                  \
	while (0)

/* MANUAL */
void
atfdname(int fd, int decimal)
{
	if (fd == AT_FDCWD)
		printf("AT_FDCWD");
	else if (decimal)
		printf("%d", fd);
	else
		printf("%#x", fd);
}

/* MANUAL */
extern char *signames[]; /* from kdump.c */
void
signame(int sig)
{
	if (sig > 0 && sig < NSIG)
		printf("SIG%s",signames[sig]);
	else
		printf("SIG %d", sig);
}

/* MANUAL */
void
semctlname(int cmd)
{
	switch (cmd) {
	case GETNCNT:
		printf("GETNCNT");
		break;
	case GETPID:
		printf("GETPID");
		break;
	case GETVAL:
		printf("GETVAL");
		break;
	case GETALL:
		printf("GETALL");
		break;
	case GETZCNT:
		printf("GETZCNT");
		break;
	case SETVAL:
		printf("SETVAL");
		break;
	case SETALL:
		printf("SETALL");
		break;
	case IPC_RMID:
		printf("IPC_RMID");
		break;
	case IPC_SET:
		printf("IPC_SET");
		break;
	case IPC_STAT:
		printf("IPC_STAT");
		break;
	default: /* Should not reach */
		printf("<invalid=%d>", cmd);
	}
}

/* MANUAL */
void
shmctlname(int cmd)
{
	switch (cmd) {
	case IPC_RMID:
		printf("IPC_RMID");
		break;
	case IPC_SET:
		printf("IPC_SET");
		break;
	case IPC_STAT:
		printf("IPC_STAT");
		break;
	default: /* Should not reach */
		printf("<invalid=%d>", cmd);
	}
}

/* MANUAL */
void
semgetname(int flag)
{
	int or = 0;
	if_print_or(flag, IPC_CREAT, or);
	if_print_or(flag, IPC_EXCL, or);
	if_print_or(flag, SEM_R, or);
	if_print_or(flag, SEM_A, or);
	if_print_or(flag, (SEM_R>>3), or);
	if_print_or(flag, (SEM_A>>3), or);
	if_print_or(flag, (SEM_R>>6), or);
	if_print_or(flag, (SEM_A>>6), or);
}

/*
 * MANUAL
 *
 * Only used by SYS_open. Unless O_CREAT is set in flags, the
 * mode argument is unused (and often bogus and misleading).
 */
void
flagsandmodename(int flags, int mode, int decimal)
{
	flagsname(flags);
	putchar(',');
	if ((flags & O_CREAT) == O_CREAT) {
		modename (mode);
	} else {
		if (decimal) {
			printf("<unused>%d", mode);
		} else {
			printf("<unused>%#x", (unsigned int)mode);
		}
	}
}

/* MANUAL */
void
idtypename(idtype_t idtype, int decimal)
{
	switch(idtype) {
	case P_PID:
		printf("P_PID");
		break;
	case P_PPID:
		printf("P_PPID");
		break;
	case P_PGID:
		printf("P_PGID");
		break;
	case P_SID:
		printf("P_SID");
		break;
	case P_CID:
		printf("P_CID");
		break;
	case P_UID:
		printf("P_UID");
		break;
	case P_GID:
		printf("P_GID");
		break;
	case P_ALL:
		printf("P_ALL");
		break;
	case P_LWPID:
		printf("P_LWPID");
		break;
	case P_TASKID:
		printf("P_TASKID");
		break;
	case P_PROJID:
		printf("P_PROJID");
		break;
	case P_POOLID:
		printf("P_POOLID");
		break;
	case P_JAILID:
		printf("P_JAILID");
		break;
	case P_CTID:
		printf("P_CTID");
		break;
	case P_CPUID:
		printf("P_CPUID");
		break;
	case P_PSETID:
		printf("P_PSETID");
		break;
	default:
		if (decimal) {
			printf("%d", idtype);
		} else {
			printf("%#x", idtype);
		}
	}
}

/*
 * MANUAL
 *
 * [g|s]etsockopt's level argument can either be SOL_SOCKET or a value
 * referring to a line in /etc/protocols . It might be appropriate
 * to use getprotoent(3) here.
 */
void
sockoptlevelname(int level, int decimal)
{
	if (level == SOL_SOCKET) {
		printf("SOL_SOCKET");
	} else {
		if (decimal) {
			printf("%d", level);
		} else {
			printf("%#x", (unsigned int)level);
		}
	}
}

/*
 * MANUAL
 *
 * Used for page fault type.  Cannot use auto_or_type since the macro
 * values contain a cast.  Also, VM_PROT_NONE has to be handled specially.
 */
void
vmprotname (int type)
{
	int	or = 0;

	if (type == VM_PROT_NONE) {
		(void)printf("VM_PROT_NONE");
		return;
	}
	if_print_or(type, VM_PROT_READ, or);
	if_print_or(type, VM_PROT_WRITE, or);
	if_print_or(type, VM_PROT_EXECUTE, or);
	if_print_or(type, VM_PROT_COPY, or);
}

/*
 * MANUAL
 */
void
socktypenamewithflags(int type)
{
	if (type & SOCK_CLOEXEC)
		printf("SOCK_CLOEXEC|"), type &= ~SOCK_CLOEXEC;
	if (type & SOCK_NONBLOCK)
		printf("SOCK_NONBLOCK|"), type &= ~SOCK_NONBLOCK;
	socktypename(type);
}
/* AUTO */
void
accessmodename(intmax_t arg)
{
	int or = 0;
	printf("%#jx<", (uintmax_t)arg);
	if (!((arg > 0) ^ ((F_OK) > 0)))
		if_print_or(arg, F_OK, or);
	if (!((arg > 0) ^ ((X_OK) > 0)))
		if_print_or(arg, X_OK, or);
	if (!((arg > 0) ^ ((W_OK) > 0)))
		if_print_or(arg, W_OK, or);
	if (!((arg > 0) ^ ((R_OK) > 0)))
		if_print_or(arg, R_OK, or);
	printf(">");
	if (or == 0)
		printf("<invalid>%jd", arg);
}

/* AUTO */
void
acltypename(intmax_t arg)
{
	switch (arg) {
	case ACL_TYPE_ACCESS_OLD:
		printf("ACL_TYPE_ACCESS_OLD");
		break;
	case ACL_TYPE_DEFAULT_OLD:
		printf("ACL_TYPE_DEFAULT_OLD");
		break;
	case ACL_TYPE_ACCESS:
		printf("ACL_TYPE_ACCESS");
		break;
	case ACL_TYPE_DEFAULT:
		printf("ACL_TYPE_DEFAULT");
		break;
	case ACL_TYPE_NFS4:
		printf("ACL_TYPE_NFS4");
		break;
	default: /* Should not reach */
		printf("<invalid=%jd>", arg);
	}
}

/* AUTO */
void
capfcntlname(intmax_t arg)
{
	int or = 0;
	printf("%#jx<", (uintmax_t)arg);
	if (!((arg > 0) ^ ((CAP_FCNTL_GETFL) > 0)))
		if_print_or(arg, CAP_FCNTL_GETFL, or);
	if (!((arg > 0) ^ ((CAP_FCNTL_SETFL) > 0)))
		if_print_or(arg, CAP_FCNTL_SETFL, or);
	if (!((arg > 0) ^ ((CAP_FCNTL_GETOWN) > 0)))
		if_print_or(arg, CAP_FCNTL_GETOWN, or);
	if (!((arg > 0) ^ ((CAP_FCNTL_SETOWN) > 0)))
		if_print_or(arg, CAP_FCNTL_SETOWN, or);
	printf(">");
	if (or == 0)
		printf("<invalid>%jd", arg);
}

/* AUTO */
void
extattrctlname(intmax_t arg)
{
	switch (arg) {
	case EXTATTR_NAMESPACE_EMPTY:
		printf("EXTATTR_NAMESPACE_EMPTY");
		break;
	case EXTATTR_NAMESPACE_USER:
		printf("EXTATTR_NAMESPACE_USER");
		break;
	case EXTATTR_NAMESPACE_SYSTEM:
		printf("EXTATTR_NAMESPACE_SYSTEM");
		break;
	default: /* Should not reach */
		printf("<invalid=%jd>", arg);
	}
}

/* AUTO */
void
fadvisebehavname(intmax_t arg)
{
	switch (arg) {
	case POSIX_FADV_NORMAL:
		printf("POSIX_FADV_NORMAL");
		break;
	case POSIX_FADV_RANDOM:
		printf("POSIX_FADV_RANDOM");
		break;
	case POSIX_FADV_SEQUENTIAL:
		printf("POSIX_FADV_SEQUENTIAL");
		break;
	case POSIX_FADV_WILLNEED:
		printf("POSIX_FADV_WILLNEED");
		break;
	case POSIX_FADV_DONTNEED:
		printf("POSIX_FADV_DONTNEED");
		break;
	case POSIX_FADV_NOREUSE:
		printf("POSIX_FADV_NOREUSE");
		break;
	default: /* Should not reach */
		printf("<invalid=%jd>", arg);
	}
}

/* AUTO */
void
flagsname(intmax_t arg)
{
	int or = 0;
	printf("%#jx<", (uintmax_t)arg);
	if (!((arg > 0) ^ ((O_RDONLY) > 0)))
		if_print_or(arg, O_RDONLY, or);
	if (!((arg > 0) ^ ((O_WRONLY) > 0)))
		if_print_or(arg, O_WRONLY, or);
	if (!((arg > 0) ^ ((O_RDWR) > 0)))
		if_print_or(arg, O_RDWR, or);
	if (!((arg > 0) ^ ((O_ACCMODE) > 0)))
		if_print_or(arg, O_ACCMODE, or);
	if (!((arg > 0) ^ ((O_NONBLOCK) > 0)))
		if_print_or(arg, O_NONBLOCK, or);
	if (!((arg > 0) ^ ((O_APPEND) > 0)))
		if_print_or(arg, O_APPEND, or);
	if (!((arg > 0) ^ ((O_SHLOCK) > 0)))
		if_print_or(arg, O_SHLOCK, or);
	if (!((arg > 0) ^ ((O_EXLOCK) > 0)))
		if_print_or(arg, O_EXLOCK, or);
	if (!((arg > 0) ^ ((O_ASYNC) > 0)))
		if_print_or(arg, O_ASYNC, or);
	if (!((arg > 0) ^ ((O_FSYNC) > 0)))
		if_print_or(arg, O_FSYNC, or);
	if (!((arg > 0) ^ ((O_SYNC) > 0)))
		if_print_or(arg, O_SYNC, or);
	if (!((arg > 0) ^ ((O_NOFOLLOW) > 0)))
		if_print_or(arg, O_NOFOLLOW, or);
	if (!((arg > 0) ^ ((O_CREAT) > 0)))
		if_print_or(arg, O_CREAT, or);
	if (!((arg > 0) ^ ((O_TRUNC) > 0)))
		if_print_or(arg, O_TRUNC, or);
	if (!((arg > 0) ^ ((O_EXCL) > 0)))
		if_print_or(arg, O_EXCL, or);
	if (!((arg > 0) ^ ((O_NOCTTY) > 0)))
		if_print_or(arg, O_NOCTTY, or);
	if (!((arg > 0) ^ ((O_DIRECT) > 0)))
		if_print_or(arg, O_DIRECT, or);
	if (!((arg > 0) ^ ((O_DIRECTORY) > 0)))
		if_print_or(arg, O_DIRECTORY, or);
	if (!((arg > 0) ^ ((O_EXEC) > 0)))
		if_print_or(arg, O_EXEC, or);
	if (!((arg > 0) ^ ((O_CLOEXEC) > 0)))
		if_print_or(arg, O_CLOEXEC, or);
	if (!((arg > 0) ^ ((O_VERIFY) > 0)))
		if_print_or(arg, O_VERIFY, or);
	printf(">");
	if (or == 0)
		printf("<invalid>%jd", arg);
}

/* AUTO */
void
flockname(intmax_t arg)
{
	int or = 0;
	printf("%#jx<", (uintmax_t)arg);
	if (!((arg > 0) ^ ((LOCK_SH) > 0)))
		if_print_or(arg, LOCK_SH, or);
	if (!((arg > 0) ^ ((LOCK_EX) > 0)))
		if_print_or(arg, LOCK_EX, or);
	if (!((arg > 0) ^ ((LOCK_NB) > 0)))
		if_print_or(arg, LOCK_NB, or);
	if (!((arg > 0) ^ ((LOCK_UN) > 0)))
		if_print_or(arg, LOCK_UN, or);
	printf(">");
	if (or == 0)
		printf("<invalid>%jd", arg);
}

/* AUTO */
void
getfsstatflagsname(intmax_t arg)
{
	int or = 0;
	printf("%#jx<", (uintmax_t)arg);
	if (!((arg > 0) ^ ((MNT_WAIT) > 0)))
		if_print_or(arg, MNT_WAIT, or);
	if (!((arg > 0) ^ ((MNT_NOWAIT) > 0)))
		if_print_or(arg, MNT_NOWAIT, or);
	if (!((arg > 0) ^ ((MNT_LAZY) > 0)))
		if_print_or(arg, MNT_LAZY, or);
	if (!((arg > 0) ^ ((MNT_SUSPEND) > 0)))
		if_print_or(arg, MNT_SUSPEND, or);
	printf(">");
	if (or == 0)
		printf("<invalid>%jd", arg);
}

/* AUTO */
void
kldsymcmdname(intmax_t arg)
{
	switch (arg) {
	case KLDSYM_LOOKUP:
		printf("KLDSYM_LOOKUP");
		break;
	default: /* Should not reach */
		printf("<invalid=%jd>", arg);
	}
}

/* AUTO */
void
kldunloadfflagsname(intmax_t arg)
{
	switch (arg) {
	case LINKER_UNLOAD_NORMAL:
		printf("LINKER_UNLOAD_NORMAL");
		break;
	case LINKER_UNLOAD_FORCE:
		printf("LINKER_UNLOAD_FORCE");
		break;
	default: /* Should not reach */
		printf("<invalid=%jd>", arg);
	}
}

/* AUTO */
void
lio_listioname(intmax_t arg)
{
	switch (arg) {
	case LIO_NOWAIT:
		printf("LIO_NOWAIT");
		break;
	case LIO_WAIT:
		printf("LIO_WAIT");
		break;
	default: /* Should not reach */
		printf("<invalid=%jd>", arg);
	}
}

/* AUTO */
void
madvisebehavname(intmax_t arg)
{
	switch (arg) {
	case _MADV_NORMAL:
		printf("_MADV_NORMAL");
		break;
	case _MADV_RANDOM:
		printf("_MADV_RANDOM");
		break;
	case _MADV_SEQUENTIAL:
		printf("_MADV_SEQUENTIAL");
		break;
	case _MADV_WILLNEED:
		printf("_MADV_WILLNEED");
		break;
	case _MADV_DONTNEED:
		printf("_MADV_DONTNEED");
		break;
	case MADV_FREE:
		printf("MADV_FREE");
		break;
	case MADV_NOSYNC:
		printf("MADV_NOSYNC");
		break;
	case MADV_AUTOSYNC:
		printf("MADV_AUTOSYNC");
		break;
	case MADV_NOCORE:
		printf("MADV_NOCORE");
		break;
	case MADV_CORE:
		printf("MADV_CORE");
		break;
	case MADV_PROTECT:
		printf("MADV_PROTECT");
		break;
	default: /* Should not reach */
		printf("<invalid=%jd>", arg);
	}
}

/* AUTO */
void
minheritname(intmax_t arg)
{
	switch (arg) {
	case INHERIT_SHARE:
		printf("INHERIT_SHARE");
		break;
	case INHERIT_COPY:
		printf("INHERIT_COPY");
		break;
	case INHERIT_NONE:
		printf("INHERIT_NONE");
		break;
	default: /* Should not reach */
		printf("<invalid=%jd>", arg);
	}
}

/* AUTO */
void
mlockallname(intmax_t arg)
{
	int or = 0;
	printf("%#jx<", (uintmax_t)arg);
	if (!((arg > 0) ^ ((MCL_CURRENT) > 0)))
		if_print_or(arg, MCL_CURRENT, or);
	if (!((arg > 0) ^ ((MCL_FUTURE) > 0)))
		if_print_or(arg, MCL_FUTURE, or);
	printf(">");
	if (or == 0)
		printf("<invalid>%jd", arg);
}

/* AUTO */
void
mmapprotname(intmax_t arg)
{
	int or = 0;
	printf("%#jx<", (uintmax_t)arg);
	if (!((arg > 0) ^ ((PROT_NONE) > 0)))
		if_print_or(arg, PROT_NONE, or);
	if (!((arg > 0) ^ ((PROT_READ) > 0)))
		if_print_or(arg, PROT_READ, or);
	if (!((arg > 0) ^ ((PROT_WRITE) > 0)))
		if_print_or(arg, PROT_WRITE, or);
	if (!((arg > 0) ^ ((PROT_EXEC) > 0)))
		if_print_or(arg, PROT_EXEC, or);
	printf(">");
	if (or == 0)
		printf("<invalid>%jd", arg);
}

/* AUTO */
void
modename(intmax_t arg)
{
	int or = 0;
	printf("%#jx<", (uintmax_t)arg);
	if (!((arg > 0) ^ ((S_ISUID) > 0)))
		if_print_or(arg, S_ISUID, or);
	if (!((arg > 0) ^ ((S_ISGID) > 0)))
		if_print_or(arg, S_ISGID, or);
	if (!((arg > 0) ^ ((S_ISTXT) > 0)))
		if_print_or(arg, S_ISTXT, or);
	if (!((arg > 0) ^ ((S_IRUSR) > 0)))
		if_print_or(arg, S_IRUSR, or);
	if (!((arg > 0) ^ ((S_IWUSR) > 0)))
		if_print_or(arg, S_IWUSR, or);
	if (!((arg > 0) ^ ((S_IXUSR) > 0)))
		if_print_or(arg, S_IXUSR, or);
	if (!((arg > 0) ^ ((S_IRGRP) > 0)))
		if_print_or(arg, S_IRGRP, or);
	if (!((arg > 0) ^ ((S_IWGRP) > 0)))
		if_print_or(arg, S_IWGRP, or);
	if (!((arg > 0) ^ ((S_IXGRP) > 0)))
		if_print_or(arg, S_IXGRP, or);
	if (!((arg > 0) ^ ((S_IROTH) > 0)))
		if_print_or(arg, S_IROTH, or);
	if (!((arg > 0) ^ ((S_IWOTH) > 0)))
		if_print_or(arg, S_IWOTH, or);
	if (!((arg > 0) ^ ((S_IXOTH) > 0)))
		if_print_or(arg, S_IXOTH, or);
	if (!((arg > 0) ^ ((S_IFIFO) > 0)))
		if_print_or(arg, S_IFIFO, or);
	if (!((arg > 0) ^ ((S_IFCHR) > 0)))
		if_print_or(arg, S_IFCHR, or);
	if (!((arg > 0) ^ ((S_IFDIR) > 0)))
		if_print_or(arg, S_IFDIR, or);
	if (!((arg > 0) ^ ((S_IFBLK) > 0)))
		if_print_or(arg, S_IFBLK, or);
	if (!((arg > 0) ^ ((S_IFREG) > 0)))
		if_print_or(arg, S_IFREG, or);
	if (!((arg > 0) ^ ((S_IFLNK) > 0)))
		if_print_or(arg, S_IFLNK, or);
	if (!((arg > 0) ^ ((S_IFSOCK) > 0)))
		if_print_or(arg, S_IFSOCK, or);
	if (!((arg > 0) ^ ((S_ISVTX) > 0)))
		if_print_or(arg, S_ISVTX, or);
	if (!((arg > 0) ^ ((S_IFWHT) > 0)))
		if_print_or(arg, S_IFWHT, or);
	printf(">");
	if (or == 0)
		printf("<invalid>%jd", arg);
}

/* AUTO */
void
mountflagsname(intmax_t arg)
{
	int or = 0;
	printf("%#jx<", (uintmax_t)arg);
	if (!((arg > 0) ^ ((MNT_RDONLY) > 0)))
		if_print_or(arg, MNT_RDONLY, or);
	if (!((arg > 0) ^ ((MNT_SYNCHRONOUS) > 0)))
		if_print_or(arg, MNT_SYNCHRONOUS, or);
	if (!((arg > 0) ^ ((MNT_NOEXEC) > 0)))
		if_print_or(arg, MNT_NOEXEC, or);
	if (!((arg > 0) ^ ((MNT_NOSUID) > 0)))
		if_print_or(arg, MNT_NOSUID, or);
	if (!((arg > 0) ^ ((MNT_UNION) > 0)))
		if_print_or(arg, MNT_UNION, or);
	if (!((arg > 0) ^ ((MNT_ASYNC) > 0)))
		if_print_or(arg, MNT_ASYNC, or);
	if (!((arg > 0) ^ ((MNT_SUIDDIR) > 0)))
		if_print_or(arg, MNT_SUIDDIR, or);
	if (!((arg > 0) ^ ((MNT_SOFTDEP) > 0)))
		if_print_or(arg, MNT_SOFTDEP, or);
	if (!((arg > 0) ^ ((MNT_NOSYMFOLLOW) > 0)))
		if_print_or(arg, MNT_NOSYMFOLLOW, or);
	if (!((arg > 0) ^ ((MNT_GJOURNAL) > 0)))
		if_print_or(arg, MNT_GJOURNAL, or);
	if (!((arg > 0) ^ ((MNT_MULTILABEL) > 0)))
		if_print_or(arg, MNT_MULTILABEL, or);
	if (!((arg > 0) ^ ((MNT_ACLS) > 0)))
		if_print_or(arg, MNT_ACLS, or);
	if (!((arg > 0) ^ ((MNT_NOATIME) > 0)))
		if_print_or(arg, MNT_NOATIME, or);
	if (!((arg > 0) ^ ((MNT_NOCLUSTERR) > 0)))
		if_print_or(arg, MNT_NOCLUSTERR, or);
	if (!((arg > 0) ^ ((MNT_NOCLUSTERW) > 0)))
		if_print_or(arg, MNT_NOCLUSTERW, or);
	if (!((arg > 0) ^ ((MNT_SUJ) > 0)))
		if_print_or(arg, MNT_SUJ, or);
	if (!((arg > 0) ^ ((MNT_AUTOMOUNTED) > 0)))
		if_print_or(arg, MNT_AUTOMOUNTED, or);
	if (!((arg > 0) ^ ((MNT_EXRDONLY) > 0)))
		if_print_or(arg, MNT_EXRDONLY, or);
	if (!((arg > 0) ^ ((MNT_EXPORTED) > 0)))
		if_print_or(arg, MNT_EXPORTED, or);
	if (!((arg > 0) ^ ((MNT_DEFEXPORTED) > 0)))
		if_print_or(arg, MNT_DEFEXPORTED, or);
	if (!((arg > 0) ^ ((MNT_EXPORTANON) > 0)))
		if_print_or(arg, MNT_EXPORTANON, or);
	if (!((arg > 0) ^ ((MNT_EXKERB) > 0)))
		if_print_or(arg, MNT_EXKERB, or);
	if (!((arg > 0) ^ ((MNT_EXPUBLIC) > 0)))
		if_print_or(arg, MNT_EXPUBLIC, or);
	if (!((arg > 0) ^ ((MNT_LOCAL) > 0)))
		if_print_or(arg, MNT_LOCAL, or);
	if (!((arg > 0) ^ ((MNT_QUOTA) > 0)))
		if_print_or(arg, MNT_QUOTA, or);
	if (!((arg > 0) ^ ((MNT_ROOTFS) > 0)))
		if_print_or(arg, MNT_ROOTFS, or);
	if (!((arg > 0) ^ ((MNT_USER) > 0)))
		if_print_or(arg, MNT_USER, or);
	if (!((arg > 0) ^ ((MNT_IGNORE) > 0)))
		if_print_or(arg, MNT_IGNORE, or);
	if (!((arg > 0) ^ ((MNT_UPDATE) > 0)))
		if_print_or(arg, MNT_UPDATE, or);
	if (!((arg > 0) ^ ((MNT_DELEXPORT) > 0)))
		if_print_or(arg, MNT_DELEXPORT, or);
	if (!((arg > 0) ^ ((MNT_RELOAD) > 0)))
		if_print_or(arg, MNT_RELOAD, or);
	if (!((arg > 0) ^ ((MNT_FORCE) > 0)))
		if_print_or(arg, MNT_FORCE, or);
	if (!((arg > 0) ^ ((MNT_SNAPSHOT) > 0)))
		if_print_or(arg, MNT_SNAPSHOT, or);
	if (!((arg > 0) ^ ((MNT_BYFSID) > 0)))
		if_print_or(arg, MNT_BYFSID, or);
	printf(">");
	if (or == 0)
		printf("<invalid>%jd", arg);
}

/* AUTO */
void
msyncflagsname(intmax_t arg)
{
	switch (arg) {
	case MS_SYNC:
		printf("MS_SYNC");
		break;
	case MS_ASYNC:
		printf("MS_ASYNC");
		break;
	case MS_INVALIDATE:
		printf("MS_INVALIDATE");
		break;
	default: /* Should not reach */
		printf("<invalid=%jd>", arg);
	}
}

/* AUTO */
void
nfssvcname(intmax_t arg)
{
	int or = 0;
	printf("%#jx<", (uintmax_t)arg);
	if (!((arg > 0) ^ ((NFSSVC_OLDNFSD) > 0)))
		if_print_or(arg, NFSSVC_OLDNFSD, or);
	if (!((arg > 0) ^ ((NFSSVC_ADDSOCK) > 0)))
		if_print_or(arg, NFSSVC_ADDSOCK, or);
	if (!((arg > 0) ^ ((NFSSVC_NFSD) > 0)))
		if_print_or(arg, NFSSVC_NFSD, or);
	if (!((arg > 0) ^ ((NFSSVC_NOPUBLICFH) > 0)))
		if_print_or(arg, NFSSVC_NOPUBLICFH, or);
	if (!((arg > 0) ^ ((NFSSVC_STABLERESTART) > 0)))
		if_print_or(arg, NFSSVC_STABLERESTART, or);
	if (!((arg > 0) ^ ((NFSSVC_NFSDNFSD) > 0)))
		if_print_or(arg, NFSSVC_NFSDNFSD, or);
	if (!((arg > 0) ^ ((NFSSVC_NFSDADDSOCK) > 0)))
		if_print_or(arg, NFSSVC_NFSDADDSOCK, or);
	if (!((arg > 0) ^ ((NFSSVC_IDNAME) > 0)))
		if_print_or(arg, NFSSVC_IDNAME, or);
	if (!((arg > 0) ^ ((NFSSVC_GSSDDELETEALL) > 0)))
		if_print_or(arg, NFSSVC_GSSDDELETEALL, or);
	if (!((arg > 0) ^ ((NFSSVC_GSSDADDPORT) > 0)))
		if_print_or(arg, NFSSVC_GSSDADDPORT, or);
	if (!((arg > 0) ^ ((NFSSVC_NFSUSERDPORT) > 0)))
		if_print_or(arg, NFSSVC_NFSUSERDPORT, or);
	if (!((arg > 0) ^ ((NFSSVC_NFSUSERDDELPORT) > 0)))
		if_print_or(arg, NFSSVC_NFSUSERDDELPORT, or);
	if (!((arg > 0) ^ ((NFSSVC_V4ROOTEXPORT) > 0)))
		if_print_or(arg, NFSSVC_V4ROOTEXPORT, or);
	if (!((arg > 0) ^ ((NFSSVC_ADMINREVOKE) > 0)))
		if_print_or(arg, NFSSVC_ADMINREVOKE, or);
	if (!((arg > 0) ^ ((NFSSVC_DUMPCLIENTS) > 0)))
		if_print_or(arg, NFSSVC_DUMPCLIENTS, or);
	if (!((arg > 0) ^ ((NFSSVC_DUMPLOCKS) > 0)))
		if_print_or(arg, NFSSVC_DUMPLOCKS, or);
	if (!((arg > 0) ^ ((NFSSVC_GSSDADDFIRST) > 0)))
		if_print_or(arg, NFSSVC_GSSDADDFIRST, or);
	if (!((arg > 0) ^ ((NFSSVC_PUBLICFH) > 0)))
		if_print_or(arg, NFSSVC_PUBLICFH, or);
	if (!((arg > 0) ^ ((NFSSVC_NFSCBD) > 0)))
		if_print_or(arg, NFSSVC_NFSCBD, or);
	if (!((arg > 0) ^ ((NFSSVC_CBADDSOCK) > 0)))
		if_print_or(arg, NFSSVC_CBADDSOCK, or);
	if (!((arg > 0) ^ ((NFSSVC_GETSTATS) > 0)))
		if_print_or(arg, NFSSVC_GETSTATS, or);
	if (!((arg > 0) ^ ((NFSSVC_BACKUPSTABLE) > 0)))
		if_print_or(arg, NFSSVC_BACKUPSTABLE, or);
	if (!((arg > 0) ^ ((NFSSVC_ZEROCLTSTATS) > 0)))
		if_print_or(arg, NFSSVC_ZEROCLTSTATS, or);
	if (!((arg > 0) ^ ((NFSSVC_ZEROSRVSTATS) > 0)))
		if_print_or(arg, NFSSVC_ZEROSRVSTATS, or);
	if (!((arg > 0) ^ ((NFSSVC_SUSPENDNFSD) > 0)))
		if_print_or(arg, NFSSVC_SUSPENDNFSD, or);
	if (!((arg > 0) ^ ((NFSSVC_RESUMENFSD) > 0)))
		if_print_or(arg, NFSSVC_RESUMENFSD, or);
	if (!((arg > 0) ^ ((NFSSVC_DUMPMNTOPTS) > 0)))
		if_print_or(arg, NFSSVC_DUMPMNTOPTS, or);
	if (!((arg > 0) ^ ((NFSSVC_NEWSTRUCT) > 0)))
		if_print_or(arg, NFSSVC_NEWSTRUCT, or);
	printf(">");
	if (or == 0)
		printf("<invalid>%jd", arg);
}

/* AUTO */
void
prioname(intmax_t arg)
{
	switch (arg) {
	case PRIO_MAX:
		printf("PRIO_MAX");
		break;
	case PRIO_PROCESS:
		printf("PRIO_PROCESS");
		break;
	case PRIO_PGRP:
		printf("PRIO_PGRP");
		break;
	case PRIO_USER:
		printf("PRIO_USER");
		break;
	default: /* Should not reach */
		printf("<invalid=%jd>", arg);
	}
}

/* AUTO */
void
procctlcmdname(intmax_t arg)
{
	switch (arg) {
	case PROC_SPROTECT:
		printf("PROC_SPROTECT");
		break;
	default: /* Should not reach */
		printf("<invalid=%jd>", arg);
	}
}

/* AUTO */
void
ptraceopname(intmax_t arg)
{
	switch (arg) {
	case PT_TRACE_ME:
		printf("PT_TRACE_ME");
		break;
	case PT_READ_I:
		printf("PT_READ_I");
		break;
	case PT_READ_D:
		printf("PT_READ_D");
		break;
	case PT_WRITE_I:
		printf("PT_WRITE_I");
		break;
	case PT_WRITE_D:
		printf("PT_WRITE_D");
		break;
	case PT_CONTINUE:
		printf("PT_CONTINUE");
		break;
	case PT_KILL:
		printf("PT_KILL");
		break;
	case PT_STEP:
		printf("PT_STEP");
		break;
	case PT_ATTACH:
		printf("PT_ATTACH");
		break;
	case PT_DETACH:
		printf("PT_DETACH");
		break;
	case PT_IO:
		printf("PT_IO");
		break;
	case PT_LWPINFO:
		printf("PT_LWPINFO");
		break;
	case PT_GETNUMLWPS:
		printf("PT_GETNUMLWPS");
		break;
	case PT_GETLWPLIST:
		printf("PT_GETLWPLIST");
		break;
	case PT_CLEARSTEP:
		printf("PT_CLEARSTEP");
		break;
	case PT_SETSTEP:
		printf("PT_SETSTEP");
		break;
	case PT_SUSPEND:
		printf("PT_SUSPEND");
		break;
	case PT_RESUME:
		printf("PT_RESUME");
		break;
	case PT_TO_SCE:
		printf("PT_TO_SCE");
		break;
	case PT_TO_SCX:
		printf("PT_TO_SCX");
		break;
	case PT_SYSCALL:
		printf("PT_SYSCALL");
		break;
	case PT_FOLLOW_FORK:
		printf("PT_FOLLOW_FORK");
		break;
	case PT_GETREGS:
		printf("PT_GETREGS");
		break;
	case PT_SETREGS:
		printf("PT_SETREGS");
		break;
	case PT_GETFPREGS:
		printf("PT_GETFPREGS");
		break;
	case PT_SETFPREGS:
		printf("PT_SETFPREGS");
		break;
	case PT_GETDBREGS:
		printf("PT_GETDBREGS");
		break;
	case PT_SETDBREGS:
		printf("PT_SETDBREGS");
		break;
	case PT_VM_TIMESTAMP:
		printf("PT_VM_TIMESTAMP");
		break;
	case PT_VM_ENTRY:
		printf("PT_VM_ENTRY");
		break;
	case PT_FIRSTMACH:
		printf("PT_FIRSTMACH");
		break;
	default: /* Should not reach */
		printf("<invalid=%jd>", arg);
	}
}

/* AUTO */
void
quotactlname(intmax_t arg)
{
	switch (arg) {
	case Q_QUOTAON:
		printf("Q_QUOTAON");
		break;
	case Q_QUOTAOFF:
		printf("Q_QUOTAOFF");
		break;
	case Q_SYNC:
		printf("Q_SYNC");
		break;
	case Q_GETQUOTA:
		printf("Q_GETQUOTA");
		break;
	case Q_SETQUOTA:
		printf("Q_SETQUOTA");
		break;
	case Q_SETUSE:
		printf("Q_SETUSE");
		break;
	case Q_GETQUOTASIZE:
		printf("Q_GETQUOTASIZE");
		break;
	default: /* Should not reach */
		printf("<invalid=%jd>", arg);
	}
}

/* AUTO */
void
rebootoptname(intmax_t arg)
{
	int or = 0;
	printf("%#jx<", (uintmax_t)arg);
	if (!((arg > 0) ^ ((RB_ASKNAME) > 0)))
		if_print_or(arg, RB_ASKNAME, or);
	if (!((arg > 0) ^ ((RB_SINGLE) > 0)))
		if_print_or(arg, RB_SINGLE, or);
	if (!((arg > 0) ^ ((RB_NOSYNC) > 0)))
		if_print_or(arg, RB_NOSYNC, or);
	if (!((arg > 0) ^ ((RB_HALT) > 0)))
		if_print_or(arg, RB_HALT, or);
	if (!((arg > 0) ^ ((RB_INITNAME) > 0)))
		if_print_or(arg, RB_INITNAME, or);
	if (!((arg > 0) ^ ((RB_DFLTROOT) > 0)))
		if_print_or(arg, RB_DFLTROOT, or);
	if (!((arg > 0) ^ ((RB_KDB) > 0)))
		if_print_or(arg, RB_KDB, or);
	if (!((arg > 0) ^ ((RB_RDONLY) > 0)))
		if_print_or(arg, RB_RDONLY, or);
	if (!((arg > 0) ^ ((RB_DUMP) > 0)))
		if_print_or(arg, RB_DUMP, or);
	if (!((arg > 0) ^ ((RB_MINIROOT) > 0)))
		if_print_or(arg, RB_MINIROOT, or);
	if (!((arg > 0) ^ ((RB_VERBOSE) > 0)))
		if_print_or(arg, RB_VERBOSE, or);
	if (!((arg > 0) ^ ((RB_SERIAL) > 0)))
		if_print_or(arg, RB_SERIAL, or);
	if (!((arg > 0) ^ ((RB_CDROM) > 0)))
		if_print_or(arg, RB_CDROM, or);
	if (!((arg > 0) ^ ((RB_POWEROFF) > 0)))
		if_print_or(arg, RB_POWEROFF, or);
	if (!((arg > 0) ^ ((RB_GDB) > 0)))
		if_print_or(arg, RB_GDB, or);
	if (!((arg > 0) ^ ((RB_MUTE) > 0)))
		if_print_or(arg, RB_MUTE, or);
	if (!((arg > 0) ^ ((RB_SELFTEST) > 0)))
		if_print_or(arg, RB_SELFTEST, or);
	if (!((arg > 0) ^ ((RB_PAUSE) > 0)))
		if_print_or(arg, RB_PAUSE, or);
	if (!((arg > 0) ^ ((RB_REROOT) > 0)))
		if_print_or(arg, RB_REROOT, or);
	if (!((arg > 0) ^ ((RB_MULTIPLE) > 0)))
		if_print_or(arg, RB_MULTIPLE, or);
	if (!((arg > 0) ^ ((RB_BOOTINFO) > 0)))
		if_print_or(arg, RB_BOOTINFO, or);
	printf(">");
	if (or == 0)
		printf("<invalid>%jd", arg);
}

/* AUTO */
void
rforkname(intmax_t arg)
{
	int or = 0;
	printf("%#jx<", (uintmax_t)arg);
	if (!((arg > 0) ^ ((RFNAMEG) > 0)))
		if_print_or(arg, RFNAMEG, or);
	if (!((arg > 0) ^ ((RFENVG) > 0)))
		if_print_or(arg, RFENVG, or);
	if (!((arg > 0) ^ ((RFFDG) > 0)))
		if_print_or(arg, RFFDG, or);
	if (!((arg > 0) ^ ((RFNOTEG) > 0)))
		if_print_or(arg, RFNOTEG, or);
	if (!((arg > 0) ^ ((RFPROC) > 0)))
		if_print_or(arg, RFPROC, or);
	if (!((arg > 0) ^ ((RFMEM) > 0)))
		if_print_or(arg, RFMEM, or);
	if (!((arg > 0) ^ ((RFNOWAIT) > 0)))
		if_print_or(arg, RFNOWAIT, or);
	if (!((arg > 0) ^ ((RFCNAMEG) > 0)))
		if_print_or(arg, RFCNAMEG, or);
	if (!((arg > 0) ^ ((RFCENVG) > 0)))
		if_print_or(arg, RFCENVG, or);
	if (!((arg > 0) ^ ((RFCFDG) > 0)))
		if_print_or(arg, RFCFDG, or);
	if (!((arg > 0) ^ ((RFTHREAD) > 0)))
		if_print_or(arg, RFTHREAD, or);
	if (!((arg > 0) ^ ((RFSIGSHARE) > 0)))
		if_print_or(arg, RFSIGSHARE, or);
	if (!((arg > 0) ^ ((RFLINUXTHPN) > 0)))
		if_print_or(arg, RFLINUXTHPN, or);
	if (!((arg > 0) ^ ((RFSTOPPED) > 0)))
		if_print_or(arg, RFSTOPPED, or);
	if (!((arg > 0) ^ ((RFHIGHPID) > 0)))
		if_print_or(arg, RFHIGHPID, or);
	if (!((arg > 0) ^ ((RFTSIGZMB) > 0)))
		if_print_or(arg, RFTSIGZMB, or);
	if (!((arg > 0) ^ ((RFPROCDESC) > 0)))
		if_print_or(arg, RFPROCDESC, or);
	if (!((arg > 0) ^ ((RFPPWAIT) > 0)))
		if_print_or(arg, RFPPWAIT, or);
	printf(">");
	if (or == 0)
		printf("<invalid>%jd", arg);
}

/* AUTO */
void
rlimitname(intmax_t arg)
{
	switch (arg) {
	case RLIMIT_CPU:
		printf("RLIMIT_CPU");
		break;
	case RLIMIT_FSIZE:
		printf("RLIMIT_FSIZE");
		break;
	case RLIMIT_DATA:
		printf("RLIMIT_DATA");
		break;
	case RLIMIT_STACK:
		printf("RLIMIT_STACK");
		break;
	case RLIMIT_CORE:
		printf("RLIMIT_CORE");
		break;
	case RLIMIT_RSS:
		printf("RLIMIT_RSS");
		break;
	case RLIMIT_MEMLOCK:
		printf("RLIMIT_MEMLOCK");
		break;
	case RLIMIT_NPROC:
		printf("RLIMIT_NPROC");
		break;
	case RLIMIT_NOFILE:
		printf("RLIMIT_NOFILE");
		break;
	case RLIMIT_SBSIZE:
		printf("RLIMIT_SBSIZE");
		break;
	case RLIMIT_VMEM:
		printf("RLIMIT_VMEM");
		break;
	case RLIMIT_NPTS:
		printf("RLIMIT_NPTS");
		break;
	case RLIMIT_SWAP:
		printf("RLIMIT_SWAP");
		break;
	case RLIMIT_KQUEUES:
		printf("RLIMIT_KQUEUES");
		break;
	default: /* Should not reach */
		printf("<invalid=%jd>", arg);
	}
}

/* AUTO */
void
schedpolicyname(intmax_t arg)
{
	switch (arg) {
	case SCHED_FIFO:
		printf("SCHED_FIFO");
		break;
	case SCHED_OTHER:
		printf("SCHED_OTHER");
		break;
	case SCHED_RR:
		printf("SCHED_RR");
		break;
	default: /* Should not reach */
		printf("<invalid=%jd>", arg);
	}
}

/* AUTO */
void
sendfileflagsname(intmax_t arg)
{
	switch (arg) {
	case SF_NODISKIO:
		printf("SF_NODISKIO");
		break;
	case SF_MNOWAIT:
		printf("SF_MNOWAIT");
		break;
	case SF_SYNC:
		printf("SF_SYNC");
		break;
	default: /* Should not reach */
		printf("<invalid=%jd>", arg);
	}
}

/* AUTO */
void
shmatname(intmax_t arg)
{
	int or = 0;
	printf("%#jx<", (uintmax_t)arg);
	if (!((arg > 0) ^ ((SHM_RDONLY) > 0)))
		if_print_or(arg, SHM_RDONLY, or);
	if (!((arg > 0) ^ ((SHM_RND) > 0)))
		if_print_or(arg, SHM_RND, or);
	printf(">");
	if (or == 0)
		printf("<invalid>%jd", arg);
}

/* AUTO */
void
shutdownhowname(intmax_t arg)
{
	switch (arg) {
	case SHUT_RD:
		printf("SHUT_RD");
		break;
	case SHUT_WR:
		printf("SHUT_WR");
		break;
	case SHUT_RDWR:
		printf("SHUT_RDWR");
		break;
	default: /* Should not reach */
		printf("<invalid=%jd>", arg);
	}
}

/* AUTO */
void
sigbuscodename(intmax_t arg)
{
	switch (arg) {
	case BUS_ADRALN:
		printf("BUS_ADRALN");
		break;
	case BUS_ADRERR:
		printf("BUS_ADRERR");
		break;
	case BUS_OBJERR:
		printf("BUS_OBJERR");
		break;
	default: /* Should not reach */
		printf("<invalid=%jd>", arg);
	}
}

/* AUTO */
void
sigchldcodename(intmax_t arg)
{
	switch (arg) {
	case CLD_EXITED:
		printf("CLD_EXITED");
		break;
	case CLD_KILLED:
		printf("CLD_KILLED");
		break;
	case CLD_DUMPED:
		printf("CLD_DUMPED");
		break;
	case CLD_TRAPPED:
		printf("CLD_TRAPPED");
		break;
	case CLD_STOPPED:
		printf("CLD_STOPPED");
		break;
	case CLD_CONTINUED:
		printf("CLD_CONTINUED");
		break;
	default: /* Should not reach */
		printf("<invalid=%jd>", arg);
	}
}

/* AUTO */
void
sigfpecodename(intmax_t arg)
{
	switch (arg) {
	case FPE_INTOVF:
		printf("FPE_INTOVF");
		break;
	case FPE_INTDIV:
		printf("FPE_INTDIV");
		break;
	case FPE_FLTDIV:
		printf("FPE_FLTDIV");
		break;
	case FPE_FLTOVF:
		printf("FPE_FLTOVF");
		break;
	case FPE_FLTUND:
		printf("FPE_FLTUND");
		break;
	case FPE_FLTRES:
		printf("FPE_FLTRES");
		break;
	case FPE_FLTINV:
		printf("FPE_FLTINV");
		break;
	case FPE_FLTSUB:
		printf("FPE_FLTSUB");
		break;
	default: /* Should not reach */
		printf("<invalid=%jd>", arg);
	}
}

/* AUTO */
void
sigprocmaskhowname(intmax_t arg)
{
	switch (arg) {
	case SIG_BLOCK:
		printf("SIG_BLOCK");
		break;
	case SIG_UNBLOCK:
		printf("SIG_UNBLOCK");
		break;
	case SIG_SETMASK:
		printf("SIG_SETMASK");
		break;
	default: /* Should not reach */
		printf("<invalid=%jd>", arg);
	}
}

/* AUTO */
void
sigillcodename(intmax_t arg)
{
	switch (arg) {
	case ILL_ILLOPC:
		printf("ILL_ILLOPC");
		break;
	case ILL_ILLOPN:
		printf("ILL_ILLOPN");
		break;
	case ILL_ILLADR:
		printf("ILL_ILLADR");
		break;
	case ILL_ILLTRP:
		printf("ILL_ILLTRP");
		break;
	case ILL_PRVOPC:
		printf("ILL_PRVOPC");
		break;
	case ILL_PRVREG:
		printf("ILL_PRVREG");
		break;
	case ILL_COPROC:
		printf("ILL_COPROC");
		break;
	case ILL_BADSTK:
		printf("ILL_BADSTK");
		break;
	default: /* Should not reach */
		printf("<invalid=%jd>", arg);
	}
}

/* AUTO */
void
sigsegvcodename(intmax_t arg)
{
	switch (arg) {
	case SEGV_MAPERR:
		printf("SEGV_MAPERR");
		break;
	case SEGV_ACCERR:
		printf("SEGV_ACCERR");
		break;
	default: /* Should not reach */
		printf("<invalid=%jd>", arg);
	}
}

/* AUTO */
void
sigtrapcodename(intmax_t arg)
{
	switch (arg) {
	case TRAP_BRKPT:
		printf("TRAP_BRKPT");
		break;
	case TRAP_TRACE:
		printf("TRAP_TRACE");
		break;
	case TRAP_DTRACE:
		printf("TRAP_DTRACE");
		break;
	default: /* Should not reach */
		printf("<invalid=%jd>", arg);
	}
}

/* AUTO */
void
sockdomainname(intmax_t arg)
{
	if (arg == PF_UNSPEC) 
		printf("PF_UNSPEC");
	else if (arg == PF_LOCAL) 
		printf("PF_LOCAL");
	else if (arg == PF_UNIX) 
		printf("PF_UNIX");
	else if (arg == PF_INET) 
		printf("PF_INET");
	else if (arg == PF_IMPLINK) 
		printf("PF_IMPLINK");
	else if (arg == PF_PUP) 
		printf("PF_PUP");
	else if (arg == PF_CHAOS) 
		printf("PF_CHAOS");
	else if (arg == PF_NETBIOS) 
		printf("PF_NETBIOS");
	else if (arg == PF_ISO) 
		printf("PF_ISO");
	else if (arg == PF_OSI) 
		printf("PF_OSI");
	else if (arg == PF_ECMA) 
		printf("PF_ECMA");
	else if (arg == PF_DATAKIT) 
		printf("PF_DATAKIT");
	else if (arg == PF_CCITT) 
		printf("PF_CCITT");
	else if (arg == PF_SNA) 
		printf("PF_SNA");
	else if (arg == PF_DECnet) 
		printf("PF_DECnet");
	else if (arg == PF_DLI) 
		printf("PF_DLI");
	else if (arg == PF_LAT) 
		printf("PF_LAT");
	else if (arg == PF_HYLINK) 
		printf("PF_HYLINK");
	else if (arg == PF_APPLETALK) 
		printf("PF_APPLETALK");
	else if (arg == PF_ROUTE) 
		printf("PF_ROUTE");
	else if (arg == PF_LINK) 
		printf("PF_LINK");
	else if (arg == PF_XTP) 
		printf("PF_XTP");
	else if (arg == PF_COIP) 
		printf("PF_COIP");
	else if (arg == PF_CNT) 
		printf("PF_CNT");
	else if (arg == PF_SIP) 
		printf("PF_SIP");
	else if (arg == PF_IPX) 
		printf("PF_IPX");
	else if (arg == PF_RTIP) 
		printf("PF_RTIP");
	else if (arg == PF_PIP) 
		printf("PF_PIP");
	else if (arg == PF_ISDN) 
		printf("PF_ISDN");
	else if (arg == PF_KEY) 
		printf("PF_KEY");
	else if (arg == PF_INET6) 
		printf("PF_INET6");
	else if (arg == PF_NATM) 
		printf("PF_NATM");
	else if (arg == PF_ATM) 
		printf("PF_ATM");
	else if (arg == PF_NETGRAPH) 
		printf("PF_NETGRAPH");
	else if (arg == PF_SLOW) 
		printf("PF_SLOW");
	else if (arg == PF_SCLUSTER) 
		printf("PF_SCLUSTER");
	else if (arg == PF_ARP) 
		printf("PF_ARP");
	else if (arg == PF_BLUETOOTH) 
		printf("PF_BLUETOOTH");
	else if (arg == PF_IEEE80211) 
		printf("PF_IEEE80211");
	else if (arg == PF_MAX) 
		printf("PF_MAX");
	else /* Should not reach */
		printf("<invalid=%jd>", arg);
}

/* AUTO */
void
sockfamilyname(intmax_t arg)
{
	if (arg == AF_UNSPEC) 
		printf("AF_UNSPEC");
	else if (arg == AF_LOCAL) 
		printf("AF_LOCAL");
	else if (arg == AF_UNIX) 
		printf("AF_UNIX");
	else if (arg == AF_INET) 
		printf("AF_INET");
	else if (arg == AF_IMPLINK) 
		printf("AF_IMPLINK");
	else if (arg == AF_PUP) 
		printf("AF_PUP");
	else if (arg == AF_CHAOS) 
		printf("AF_CHAOS");
	else if (arg == AF_NETBIOS) 
		printf("AF_NETBIOS");
	else if (arg == AF_ISO) 
		printf("AF_ISO");
	else if (arg == AF_OSI) 
		printf("AF_OSI");
	else if (arg == AF_ECMA) 
		printf("AF_ECMA");
	else if (arg == AF_DATAKIT) 
		printf("AF_DATAKIT");
	else if (arg == AF_CCITT) 
		printf("AF_CCITT");
	else if (arg == AF_SNA) 
		printf("AF_SNA");
	else if (arg == AF_DECnet) 
		printf("AF_DECnet");
	else if (arg == AF_DLI) 
		printf("AF_DLI");
	else if (arg == AF_LAT) 
		printf("AF_LAT");
	else if (arg == AF_HYLINK) 
		printf("AF_HYLINK");
	else if (arg == AF_APPLETALK) 
		printf("AF_APPLETALK");
	else if (arg == AF_ROUTE) 
		printf("AF_ROUTE");
	else if (arg == AF_LINK) 
		printf("AF_LINK");
	else if (arg == AF_COIP) 
		printf("AF_COIP");
	else if (arg == AF_CNT) 
		printf("AF_CNT");
	else if (arg == AF_IPX) 
		printf("AF_IPX");
	else if (arg == AF_SIP) 
		printf("AF_SIP");
	else if (arg == AF_ISDN) 
		printf("AF_ISDN");
	else if (arg == AF_E164) 
		printf("AF_E164");
	else if (arg == AF_INET6) 
		printf("AF_INET6");
	else if (arg == AF_NATM) 
		printf("AF_NATM");
	else if (arg == AF_ATM) 
		printf("AF_ATM");
	else if (arg == AF_NETGRAPH) 
		printf("AF_NETGRAPH");
	else if (arg == AF_SLOW) 
		printf("AF_SLOW");
	else if (arg == AF_SCLUSTER) 
		printf("AF_SCLUSTER");
	else if (arg == AF_ARP) 
		printf("AF_ARP");
	else if (arg == AF_BLUETOOTH) 
		printf("AF_BLUETOOTH");
	else if (arg == AF_IEEE80211) 
		printf("AF_IEEE80211");
	else if (arg == AF_MAX) 
		printf("AF_MAX");
	else if (arg == AF_VENDOR00) 
		printf("AF_VENDOR00");
	else if (arg == AF_VENDOR01) 
		printf("AF_VENDOR01");
	else if (arg == AF_VENDOR02) 
		printf("AF_VENDOR02");
	else if (arg == AF_VENDOR03) 
		printf("AF_VENDOR03");
	else if (arg == AF_VENDOR04) 
		printf("AF_VENDOR04");
	else if (arg == AF_VENDOR05) 
		printf("AF_VENDOR05");
	else if (arg == AF_VENDOR06) 
		printf("AF_VENDOR06");
	else if (arg == AF_VENDOR07) 
		printf("AF_VENDOR07");
	else if (arg == AF_VENDOR08) 
		printf("AF_VENDOR08");
	else if (arg == AF_VENDOR09) 
		printf("AF_VENDOR09");
	else if (arg == AF_VENDOR10) 
		printf("AF_VENDOR10");
	else if (arg == AF_VENDOR11) 
		printf("AF_VENDOR11");
	else if (arg == AF_VENDOR12) 
		printf("AF_VENDOR12");
	else if (arg == AF_VENDOR13) 
		printf("AF_VENDOR13");
	else if (arg == AF_VENDOR14) 
		printf("AF_VENDOR14");
	else if (arg == AF_VENDOR15) 
		printf("AF_VENDOR15");
	else if (arg == AF_VENDOR16) 
		printf("AF_VENDOR16");
	else if (arg == AF_VENDOR17) 
		printf("AF_VENDOR17");
	else if (arg == AF_VENDOR18) 
		printf("AF_VENDOR18");
	else if (arg == AF_VENDOR19) 
		printf("AF_VENDOR19");
	else if (arg == AF_VENDOR20) 
		printf("AF_VENDOR20");
	else if (arg == AF_VENDOR21) 
		printf("AF_VENDOR21");
	else if (arg == AF_VENDOR22) 
		printf("AF_VENDOR22");
	else if (arg == AF_VENDOR23) 
		printf("AF_VENDOR23");
	else if (arg == AF_VENDOR24) 
		printf("AF_VENDOR24");
	else if (arg == AF_VENDOR25) 
		printf("AF_VENDOR25");
	else if (arg == AF_VENDOR26) 
		printf("AF_VENDOR26");
	else if (arg == AF_VENDOR27) 
		printf("AF_VENDOR27");
	else if (arg == AF_VENDOR28) 
		printf("AF_VENDOR28");
	else if (arg == AF_VENDOR29) 
		printf("AF_VENDOR29");
	else if (arg == AF_VENDOR30) 
		printf("AF_VENDOR30");
	else if (arg == AF_VENDOR31) 
		printf("AF_VENDOR31");
	else if (arg == AF_VENDOR32) 
		printf("AF_VENDOR32");
	else if (arg == AF_VENDOR33) 
		printf("AF_VENDOR33");
	else if (arg == AF_VENDOR34) 
		printf("AF_VENDOR34");
	else if (arg == AF_VENDOR35) 
		printf("AF_VENDOR35");
	else if (arg == AF_VENDOR36) 
		printf("AF_VENDOR36");
	else if (arg == AF_VENDOR37) 
		printf("AF_VENDOR37");
	else if (arg == AF_VENDOR38) 
		printf("AF_VENDOR38");
	else if (arg == AF_VENDOR39) 
		printf("AF_VENDOR39");
	else if (arg == AF_VENDOR40) 
		printf("AF_VENDOR40");
	else if (arg == AF_VENDOR41) 
		printf("AF_VENDOR41");
	else if (arg == AF_VENDOR42) 
		printf("AF_VENDOR42");
	else if (arg == AF_VENDOR43) 
		printf("AF_VENDOR43");
	else if (arg == AF_VENDOR44) 
		printf("AF_VENDOR44");
	else if (arg == AF_VENDOR45) 
		printf("AF_VENDOR45");
	else if (arg == AF_VENDOR46) 
		printf("AF_VENDOR46");
	else if (arg == AF_VENDOR47) 
		printf("AF_VENDOR47");
	else /* Should not reach */
		printf("<invalid=%jd>", arg);
}

/* AUTO */
void
sockipprotoname(intmax_t arg)
{
	if (arg == IPPROTO_IP) 
		printf("IPPROTO_IP");
	else if (arg == IPPROTO_ICMP) 
		printf("IPPROTO_ICMP");
	else if (arg == IPPROTO_TCP) 
		printf("IPPROTO_TCP");
	else if (arg == IPPROTO_UDP) 
		printf("IPPROTO_UDP");
	else if (arg == IPPROTO_IPV6) 
		printf("IPPROTO_IPV6");
	else if (arg == IPPROTO_RAW) 
		printf("IPPROTO_RAW");
	else if (arg == IPPROTO_HOPOPTS) 
		printf("IPPROTO_HOPOPTS");
	else if (arg == IPPROTO_IGMP) 
		printf("IPPROTO_IGMP");
	else if (arg == IPPROTO_GGP) 
		printf("IPPROTO_GGP");
	else if (arg == IPPROTO_IPV4) 
		printf("IPPROTO_IPV4");
	else if (arg == IPPROTO_IPIP) 
		printf("IPPROTO_IPIP");
	else if (arg == IPPROTO_ST) 
		printf("IPPROTO_ST");
	else if (arg == IPPROTO_EGP) 
		printf("IPPROTO_EGP");
	else if (arg == IPPROTO_PIGP) 
		printf("IPPROTO_PIGP");
	else if (arg == IPPROTO_RCCMON) 
		printf("IPPROTO_RCCMON");
	else if (arg == IPPROTO_NVPII) 
		printf("IPPROTO_NVPII");
	else if (arg == IPPROTO_PUP) 
		printf("IPPROTO_PUP");
	else if (arg == IPPROTO_ARGUS) 
		printf("IPPROTO_ARGUS");
	else if (arg == IPPROTO_EMCON) 
		printf("IPPROTO_EMCON");
	else if (arg == IPPROTO_XNET) 
		printf("IPPROTO_XNET");
	else if (arg == IPPROTO_CHAOS) 
		printf("IPPROTO_CHAOS");
	else if (arg == IPPROTO_MUX) 
		printf("IPPROTO_MUX");
	else if (arg == IPPROTO_MEAS) 
		printf("IPPROTO_MEAS");
	else if (arg == IPPROTO_HMP) 
		printf("IPPROTO_HMP");
	else if (arg == IPPROTO_PRM) 
		printf("IPPROTO_PRM");
	else if (arg == IPPROTO_IDP) 
		printf("IPPROTO_IDP");
	else if (arg == IPPROTO_TRUNK1) 
		printf("IPPROTO_TRUNK1");
	else if (arg == IPPROTO_TRUNK2) 
		printf("IPPROTO_TRUNK2");
	else if (arg == IPPROTO_LEAF1) 
		printf("IPPROTO_LEAF1");
	else if (arg == IPPROTO_LEAF2) 
		printf("IPPROTO_LEAF2");
	else if (arg == IPPROTO_RDP) 
		printf("IPPROTO_RDP");
	else if (arg == IPPROTO_IRTP) 
		printf("IPPROTO_IRTP");
	else if (arg == IPPROTO_TP) 
		printf("IPPROTO_TP");
	else if (arg == IPPROTO_BLT) 
		printf("IPPROTO_BLT");
	else if (arg == IPPROTO_NSP) 
		printf("IPPROTO_NSP");
	else if (arg == IPPROTO_INP) 
		printf("IPPROTO_INP");
	else if (arg == IPPROTO_SEP) 
		printf("IPPROTO_SEP");
	else if (arg == IPPROTO_3PC) 
		printf("IPPROTO_3PC");
	else if (arg == IPPROTO_IDPR) 
		printf("IPPROTO_IDPR");
	else if (arg == IPPROTO_XTP) 
		printf("IPPROTO_XTP");
	else if (arg == IPPROTO_DDP) 
		printf("IPPROTO_DDP");
	else if (arg == IPPROTO_CMTP) 
		printf("IPPROTO_CMTP");
	else if (arg == IPPROTO_TPXX) 
		printf("IPPROTO_TPXX");
	else if (arg == IPPROTO_IL) 
		printf("IPPROTO_IL");
	else if (arg == IPPROTO_SDRP) 
		printf("IPPROTO_SDRP");
	else if (arg == IPPROTO_ROUTING) 
		printf("IPPROTO_ROUTING");
	else if (arg == IPPROTO_FRAGMENT) 
		printf("IPPROTO_FRAGMENT");
	else if (arg == IPPROTO_IDRP) 
		printf("IPPROTO_IDRP");
	else if (arg == IPPROTO_RSVP) 
		printf("IPPROTO_RSVP");
	else if (arg == IPPROTO_GRE) 
		printf("IPPROTO_GRE");
	else if (arg == IPPROTO_MHRP) 
		printf("IPPROTO_MHRP");
	else if (arg == IPPROTO_BHA) 
		printf("IPPROTO_BHA");
	else if (arg == IPPROTO_ESP) 
		printf("IPPROTO_ESP");
	else if (arg == IPPROTO_AH) 
		printf("IPPROTO_AH");
	else if (arg == IPPROTO_INLSP) 
		printf("IPPROTO_INLSP");
	else if (arg == IPPROTO_SWIPE) 
		printf("IPPROTO_SWIPE");
	else if (arg == IPPROTO_NHRP) 
		printf("IPPROTO_NHRP");
	else if (arg == IPPROTO_MOBILE) 
		printf("IPPROTO_MOBILE");
	else if (arg == IPPROTO_TLSP) 
		printf("IPPROTO_TLSP");
	else if (arg == IPPROTO_SKIP) 
		printf("IPPROTO_SKIP");
	else if (arg == IPPROTO_ICMPV6) 
		printf("IPPROTO_ICMPV6");
	else if (arg == IPPROTO_NONE) 
		printf("IPPROTO_NONE");
	else if (arg == IPPROTO_DSTOPTS) 
		printf("IPPROTO_DSTOPTS");
	else if (arg == IPPROTO_AHIP) 
		printf("IPPROTO_AHIP");
	else if (arg == IPPROTO_CFTP) 
		printf("IPPROTO_CFTP");
	else if (arg == IPPROTO_HELLO) 
		printf("IPPROTO_HELLO");
	else if (arg == IPPROTO_SATEXPAK) 
		printf("IPPROTO_SATEXPAK");
	else if (arg == IPPROTO_KRYPTOLAN) 
		printf("IPPROTO_KRYPTOLAN");
	else if (arg == IPPROTO_RVD) 
		printf("IPPROTO_RVD");
	else if (arg == IPPROTO_IPPC) 
		printf("IPPROTO_IPPC");
	else if (arg == IPPROTO_ADFS) 
		printf("IPPROTO_ADFS");
	else if (arg == IPPROTO_SATMON) 
		printf("IPPROTO_SATMON");
	else if (arg == IPPROTO_VISA) 
		printf("IPPROTO_VISA");
	else if (arg == IPPROTO_IPCV) 
		printf("IPPROTO_IPCV");
	else if (arg == IPPROTO_CPNX) 
		printf("IPPROTO_CPNX");
	else if (arg == IPPROTO_CPHB) 
		printf("IPPROTO_CPHB");
	else if (arg == IPPROTO_WSN) 
		printf("IPPROTO_WSN");
	else if (arg == IPPROTO_PVP) 
		printf("IPPROTO_PVP");
	else if (arg == IPPROTO_BRSATMON) 
		printf("IPPROTO_BRSATMON");
	else if (arg == IPPROTO_ND) 
		printf("IPPROTO_ND");
	else if (arg == IPPROTO_WBMON) 
		printf("IPPROTO_WBMON");
	else if (arg == IPPROTO_WBEXPAK) 
		printf("IPPROTO_WBEXPAK");
	else if (arg == IPPROTO_EON) 
		printf("IPPROTO_EON");
	else if (arg == IPPROTO_VMTP) 
		printf("IPPROTO_VMTP");
	else if (arg == IPPROTO_SVMTP) 
		printf("IPPROTO_SVMTP");
	else if (arg == IPPROTO_VINES) 
		printf("IPPROTO_VINES");
	else if (arg == IPPROTO_TTP) 
		printf("IPPROTO_TTP");
	else if (arg == IPPROTO_IGP) 
		printf("IPPROTO_IGP");
	else if (arg == IPPROTO_DGP) 
		printf("IPPROTO_DGP");
	else if (arg == IPPROTO_TCF) 
		printf("IPPROTO_TCF");
	else if (arg == IPPROTO_IGRP) 
		printf("IPPROTO_IGRP");
	else if (arg == IPPROTO_OSPFIGP) 
		printf("IPPROTO_OSPFIGP");
	else if (arg == IPPROTO_SRPC) 
		printf("IPPROTO_SRPC");
	else if (arg == IPPROTO_LARP) 
		printf("IPPROTO_LARP");
	else if (arg == IPPROTO_MTP) 
		printf("IPPROTO_MTP");
	else if (arg == IPPROTO_AX25) 
		printf("IPPROTO_AX25");
	else if (arg == IPPROTO_IPEIP) 
		printf("IPPROTO_IPEIP");
	else if (arg == IPPROTO_MICP) 
		printf("IPPROTO_MICP");
	else if (arg == IPPROTO_SCCSP) 
		printf("IPPROTO_SCCSP");
	else if (arg == IPPROTO_ETHERIP) 
		printf("IPPROTO_ETHERIP");
	else if (arg == IPPROTO_ENCAP) 
		printf("IPPROTO_ENCAP");
	else if (arg == IPPROTO_APES) 
		printf("IPPROTO_APES");
	else if (arg == IPPROTO_GMTP) 
		printf("IPPROTO_GMTP");
	else if (arg == IPPROTO_IPCOMP) 
		printf("IPPROTO_IPCOMP");
	else if (arg == IPPROTO_SCTP) 
		printf("IPPROTO_SCTP");
	else if (arg == IPPROTO_MH) 
		printf("IPPROTO_MH");
	else if (arg == IPPROTO_UDPLITE) 
		printf("IPPROTO_UDPLITE");
	else if (arg == IPPROTO_HIP) 
		printf("IPPROTO_HIP");
	else if (arg == IPPROTO_SHIM6) 
		printf("IPPROTO_SHIM6");
	else if (arg == IPPROTO_PIM) 
		printf("IPPROTO_PIM");
	else if (arg == IPPROTO_CARP) 
		printf("IPPROTO_CARP");
	else if (arg == IPPROTO_PGM) 
		printf("IPPROTO_PGM");
	else if (arg == IPPROTO_MPLS) 
		printf("IPPROTO_MPLS");
	else if (arg == IPPROTO_PFSYNC) 
		printf("IPPROTO_PFSYNC");
	else if (arg == IPPROTO_MAX) 
		printf("IPPROTO_MAX");
	else if (arg == IPPROTO_DONE) 
		printf("IPPROTO_DONE");
	else if (arg == IPPROTO_DIVERT) 
		printf("IPPROTO_DIVERT");
	else if (arg == IPPROTO_SEND) 
		printf("IPPROTO_SEND");
	else if (arg == IPPROTO_SPACER) 
		printf("IPPROTO_SPACER");
	else /* Should not reach */
		printf("<invalid=%jd>", arg);
}

/* AUTO */
void
sockoptname(intmax_t arg)
{
	switch (arg) {
	case SO_DEBUG:
		printf("SO_DEBUG");
		break;
	case SO_ACCEPTCONN:
		printf("SO_ACCEPTCONN");
		break;
	case SO_REUSEADDR:
		printf("SO_REUSEADDR");
		break;
	case SO_KEEPALIVE:
		printf("SO_KEEPALIVE");
		break;
	case SO_DONTROUTE:
		printf("SO_DONTROUTE");
		break;
	case SO_BROADCAST:
		printf("SO_BROADCAST");
		break;
	case SO_USELOOPBACK:
		printf("SO_USELOOPBACK");
		break;
	case SO_LINGER:
		printf("SO_LINGER");
		break;
	case SO_OOBINLINE:
		printf("SO_OOBINLINE");
		break;
	case SO_REUSEPORT:
		printf("SO_REUSEPORT");
		break;
	case SO_TIMESTAMP:
		printf("SO_TIMESTAMP");
		break;
	case SO_NOSIGPIPE:
		printf("SO_NOSIGPIPE");
		break;
	case SO_ACCEPTFILTER:
		printf("SO_ACCEPTFILTER");
		break;
	case SO_BINTIME:
		printf("SO_BINTIME");
		break;
	case SO_SNDBUF:
		printf("SO_SNDBUF");
		break;
	case SO_RCVBUF:
		printf("SO_RCVBUF");
		break;
	case SO_SNDLOWAT:
		printf("SO_SNDLOWAT");
		break;
	case SO_RCVLOWAT:
		printf("SO_RCVLOWAT");
		break;
	case SO_SNDTIMEO:
		printf("SO_SNDTIMEO");
		break;
	case SO_RCVTIMEO:
		printf("SO_RCVTIMEO");
		break;
	case SO_ERROR:
		printf("SO_ERROR");
		break;
	case SO_TYPE:
		printf("SO_TYPE");
		break;
	case SO_LABEL:
		printf("SO_LABEL");
		break;
	case SO_PEERLABEL:
		printf("SO_PEERLABEL");
		break;
	case SO_LISTENQLIMIT:
		printf("SO_LISTENQLIMIT");
		break;
	case SO_LISTENQLEN:
		printf("SO_LISTENQLEN");
		break;
	case SO_LISTENINCQLEN:
		printf("SO_LISTENINCQLEN");
		break;
	case SO_SETFIB:
		printf("SO_SETFIB");
		break;
	case SO_PROTOCOL:
		printf("SO_PROTOCOL");
		break;
	case SO_VENDOR:
		printf("SO_VENDOR");
		break;
	default: /* Should not reach */
		printf("<invalid=%jd>", arg);
	}
}

/* AUTO */
void
socktypename(intmax_t arg)
{
	switch (arg) {
	case SOCK_STREAM:
		printf("SOCK_STREAM");
		break;
	case SOCK_DGRAM:
		printf("SOCK_DGRAM");
		break;
	case SOCK_RAW:
		printf("SOCK_RAW");
		break;
	case SOCK_RDM:
		printf("SOCK_RDM");
		break;
	case SOCK_SEQPACKET:
		printf("SOCK_SEQPACKET");
		break;
	case SOCK_MAXADDRLEN:
		printf("SOCK_MAXADDRLEN");
		break;
	default: /* Should not reach */
		printf("<invalid=%jd>", arg);
	}
}

/* AUTO */
void
thrcreateflagsname(intmax_t arg)
{
	int or = 0;
	printf("%#jx<", (uintmax_t)arg);
	if (!((arg > 0) ^ ((THR_SUSPENDED) > 0)))
		if_print_or(arg, THR_SUSPENDED, or);
	printf(">");
	if (or == 0)
		printf("<invalid>%jd", arg);
}

/* AUTO */
void
umtxopname(intmax_t arg)
{
	switch (arg) {
	case UMTX_OP_RESERVED0:
		printf("UMTX_OP_RESERVED0");
		break;
	case UMTX_OP_RESERVED1:
		printf("UMTX_OP_RESERVED1");
		break;
	case UMTX_OP_WAIT:
		printf("UMTX_OP_WAIT");
		break;
	case UMTX_OP_WAKE:
		printf("UMTX_OP_WAKE");
		break;
	case UMTX_OP_MUTEX_TRYLOCK:
		printf("UMTX_OP_MUTEX_TRYLOCK");
		break;
	case UMTX_OP_MUTEX_LOCK:
		printf("UMTX_OP_MUTEX_LOCK");
		break;
	case UMTX_OP_MUTEX_UNLOCK:
		printf("UMTX_OP_MUTEX_UNLOCK");
		break;
	case UMTX_OP_SET_CEILING:
		printf("UMTX_OP_SET_CEILING");
		break;
	case UMTX_OP_CV_WAIT:
		printf("UMTX_OP_CV_WAIT");
		break;
	case UMTX_OP_CV_SIGNAL:
		printf("UMTX_OP_CV_SIGNAL");
		break;
	case UMTX_OP_CV_BROADCAST:
		printf("UMTX_OP_CV_BROADCAST");
		break;
	case UMTX_OP_WAIT_UINT:
		printf("UMTX_OP_WAIT_UINT");
		break;
	case UMTX_OP_RW_RDLOCK:
		printf("UMTX_OP_RW_RDLOCK");
		break;
	case UMTX_OP_RW_WRLOCK:
		printf("UMTX_OP_RW_WRLOCK");
		break;
	case UMTX_OP_RW_UNLOCK:
		printf("UMTX_OP_RW_UNLOCK");
		break;
	case UMTX_OP_WAIT_UINT_PRIVATE:
		printf("UMTX_OP_WAIT_UINT_PRIVATE");
		break;
	case UMTX_OP_WAKE_PRIVATE:
		printf("UMTX_OP_WAKE_PRIVATE");
		break;
	case UMTX_OP_MUTEX_WAIT:
		printf("UMTX_OP_MUTEX_WAIT");
		break;
	case UMTX_OP_MUTEX_WAKE:
		printf("UMTX_OP_MUTEX_WAKE");
		break;
	case UMTX_OP_SEM_WAIT:
		printf("UMTX_OP_SEM_WAIT");
		break;
	case UMTX_OP_SEM_WAKE:
		printf("UMTX_OP_SEM_WAKE");
		break;
	case UMTX_OP_NWAKE_PRIVATE:
		printf("UMTX_OP_NWAKE_PRIVATE");
		break;
	case UMTX_OP_MUTEX_WAKE2:
		printf("UMTX_OP_MUTEX_WAKE2");
		break;
	case UMTX_OP_SEM2_WAIT:
		printf("UMTX_OP_SEM2_WAIT");
		break;
	case UMTX_OP_SEM2_WAKE:
		printf("UMTX_OP_SEM2_WAKE");
		break;
	default: /* Should not reach */
		printf("<invalid=%jd>", arg);
	}
}

/* AUTO */
void
vmresultname(intmax_t arg)
{
	switch (arg) {
	case KERN_SUCCESS:
		printf("KERN_SUCCESS");
		break;
	case KERN_FAILURE:
		printf("KERN_FAILURE");
		break;
	default: /* Should not reach */
		printf("<invalid=%jd>", arg);
	}
}

/* AUTO */
void
wait6optname(intmax_t arg)
{
	int or = 0;
	printf("%#jx<", (uintmax_t)arg);
	if (!((arg > 0) ^ ((WCOREFLAG) > 0)))
		if_print_or(arg, WCOREFLAG, or);
	if (!((arg > 0) ^ ((WNOHANG) > 0)))
		if_print_or(arg, WNOHANG, or);
	if (!((arg > 0) ^ ((WUNTRACED) > 0)))
		if_print_or(arg, WUNTRACED, or);
	if (!((arg > 0) ^ ((WCONTINUED) > 0)))
		if_print_or(arg, WCONTINUED, or);
	if (!((arg > 0) ^ ((WNOWAIT) > 0)))
		if_print_or(arg, WNOWAIT, or);
	if (!((arg > 0) ^ ((WEXITED) > 0)))
		if_print_or(arg, WEXITED, or);
	if (!((arg > 0) ^ ((WTRAPPED) > 0)))
		if_print_or(arg, WTRAPPED, or);
	if (!((arg > 0) ^ ((WLINUXCLONE) > 0)))
		if_print_or(arg, WLINUXCLONE, or);
	printf(">");
	if (or == 0)
		printf("<invalid>%jd", arg);
}

/* AUTO */
void
whencename(intmax_t arg)
{
	switch (arg) {
	case SEEK_SET:
		printf("SEEK_SET");
		break;
	case SEEK_CUR:
		printf("SEEK_CUR");
		break;
	case SEEK_END:
		printf("SEEK_END");
		break;
	case SEEK_DATA:
		printf("SEEK_DATA");
		break;
	case SEEK_HOLE:
		printf("SEEK_HOLE");
		break;
	default: /* Should not reach */
		printf("<invalid=%jd>", arg);
	}
}

/*
 * AUTO - Special
 * F_ is used to specify fcntl commands as well as arguments. Both sets are
 * grouped in fcntl.h, and this awk script grabs the first group.
 */
void
fcntlcmdname(int cmd, int arg, int decimal)
{
	switch (cmd) {
	case F_DUPFD:
		printf("F_DUPFD");
		break;
	case F_GETFD:
		printf("F_GETFD");
		break;
	case F_SETFD:
		printf("F_SETFD");
		break;
	case F_GETFL:
		printf("F_GETFL");
		break;
	case F_SETFL:
		printf("F_SETFL");
		break;
	case F_GETOWN:
		printf("F_GETOWN");
		break;
	case F_SETOWN:
		printf("F_SETOWN");
		break;
	case F_OGETLK:
		printf("F_OGETLK");
		break;
	case F_OSETLK:
		printf("F_OSETLK");
		break;
	case F_OSETLKW:
		printf("F_OSETLKW");
		break;
	case F_DUP2FD:
		printf("F_DUP2FD");
		break;
	case F_GETLK:
		printf("F_GETLK");
		break;
	case F_SETLK:
		printf("F_SETLK");
		break;
	case F_SETLKW:
		printf("F_SETLKW");
		break;
	case F_SETLK_REMOTE:
		printf("F_SETLK_REMOTE");
		break;
	case F_READAHEAD:
		printf("F_READAHEAD");
		break;
	case F_RDAHEAD:
		printf("F_RDAHEAD");
		break;
	case F_DUPFD_CLOEXEC:
		printf("F_DUPFD_CLOEXEC");
		break;
	case F_DUP2FD_CLOEXEC:
		printf("F_DUP2FD_CLOEXEC");
		break;
	default: /* Should not reach */
		printf("<invalid=%d>", cmd);
	}
	putchar(',');
	if (cmd == F_GETFD || cmd == F_SETFD) {
		if (arg == FD_CLOEXEC)
			printf("FD_CLOEXEC");
		else if (arg == 0)
			printf("0");
		else {
			if (decimal)
				printf("<invalid>%d", arg);
			else
				printf("<invalid>%#x", (unsigned int)arg);
		}
	} else if (cmd == F_SETFL) {
		flagsname(arg);
	} else {
		if (decimal)
			printf("%d", arg);
		else
			printf("%#x", (unsigned int)arg);
	}
}

/*
 * AUTO - Special
 *
 * The MAP_ALIGNED flag requires special handling.
 */
void
mmapflagsname(int flags)
{
	int align;
	int or = 0;
	printf("%#x<", flags);
	if (!((flags > 0) ^ ((MAP_SHARED) > 0)))
		if_print_or(flags, MAP_SHARED, or);
	if (!((flags > 0) ^ ((MAP_PRIVATE) > 0)))
		if_print_or(flags, MAP_PRIVATE, or);
	if (!((flags > 0) ^ ((MAP_FIXED) > 0)))
		if_print_or(flags, MAP_FIXED, or);
	if (!((flags > 0) ^ ((MAP_HASSEMAPHORE) > 0)))
		if_print_or(flags, MAP_HASSEMAPHORE, or);
	if (!((flags > 0) ^ ((MAP_STACK) > 0)))
		if_print_or(flags, MAP_STACK, or);
	if (!((flags > 0) ^ ((MAP_NOSYNC) > 0)))
		if_print_or(flags, MAP_NOSYNC, or);
	if (!((flags > 0) ^ ((MAP_FILE) > 0)))
		if_print_or(flags, MAP_FILE, or);
	if (!((flags > 0) ^ ((MAP_ANON) > 0)))
		if_print_or(flags, MAP_ANON, or);
	if (!((flags > 0) ^ ((MAP_EXCL) > 0)))
		if_print_or(flags, MAP_EXCL, or);
	if (!((flags > 0) ^ ((MAP_NOCORE) > 0)))
		if_print_or(flags, MAP_NOCORE, or);
	if (!((flags > 0) ^ ((MAP_PREFAULT_READ) > 0)))
		if_print_or(flags, MAP_PREFAULT_READ, or);
#ifdef MAP_32BIT
	if (!((flags > 0) ^ ((MAP_32BIT) > 0)))
		if_print_or(flags, MAP_32BIT, or);
#endif
	align = flags & MAP_ALIGNMENT_MASK;
	if (align != 0) {
		if (align == MAP_ALIGNED_SUPER)
			print_or("MAP_ALIGNED_SUPER", or);
		else {
			print_or("MAP_ALIGNED", or);
			printf("(%d)", align >> MAP_ALIGNMENT_SHIFT);
		}
	}
	printf(">");
	if (or == 0)
		printf("<invalid>%d", flags);
}

/*
 * AUTO - Special
 *
 * The only reason this is not fully automated is due to the
 * grep -v RTP_PRIO statement. A better egrep line should
 * make this capable of being a auto_switch_type() function.
 */
void
rtprioname(int func)
{
	switch (func) {
	default: /* Should not reach */
		printf("<invalid=%d>", func);
	}
}

/*
 * AUTO - Special
 *
 * The send and recv functions have a flags argument which can be
 * set to 0. There is no corresponding #define. The auto_ functions
 * detect this as "invalid", which is incorrect here.
 */
void
sendrecvflagsname(int flags)
{
	int or = 0;

	if (flags == 0) {
		printf("0");
		return;
	}

	printf("%#x<", flags);
	if(!((flags>0)^((MSG_OOB)>0)))
		if_print_or(flags, MSG_OOB, or);
	if(!((flags>0)^((MSG_PEEK)>0)))
		if_print_or(flags, MSG_PEEK, or);
	if(!((flags>0)^((MSG_DONTROUTE)>0)))
		if_print_or(flags, MSG_DONTROUTE, or);
	if(!((flags>0)^((MSG_EOR)>0)))
		if_print_or(flags, MSG_EOR, or);
	if(!((flags>0)^((MSG_TRUNC)>0)))
		if_print_or(flags, MSG_TRUNC, or);
	if(!((flags>0)^((MSG_CTRUNC)>0)))
		if_print_or(flags, MSG_CTRUNC, or);
	if(!((flags>0)^((MSG_WAITALL)>0)))
		if_print_or(flags, MSG_WAITALL, or);
	if(!((flags>0)^((MSG_NOSIGNAL)>0)))
		if_print_or(flags, MSG_NOSIGNAL, or);
	if(!((flags>0)^((MSG_DONTWAIT)>0)))
		if_print_or(flags, MSG_DONTWAIT, or);
	if(!((flags>0)^((MSG_EOF)>0)))
		if_print_or(flags, MSG_EOF, or);
	if(!((flags>0)^((MSG_NOTIFICATION)>0)))
		if_print_or(flags, MSG_NOTIFICATION, or);
	if(!((flags>0)^((MSG_NBIO)>0)))
		if_print_or(flags, MSG_NBIO, or);
	if(!((flags>0)^((MSG_COMPAT)>0)))
		if_print_or(flags, MSG_COMPAT, or);
	if(!((flags>0)^((MSG_SOCALLBCK)>0)))
		if_print_or(flags, MSG_SOCALLBCK, or);
	printf(">");
}

/*
 * AUTO - Special
 *
 * Check general codes first, then defer to signal-specific codes.
 */
void
sigcodename(int sig, int code)
{
	switch (code) {
	case SI_NOINFO:
		printf("SI_NOINFO");
		break;
	case SI_USER:
		printf("SI_USER");
		break;
	case SI_QUEUE:
		printf("SI_QUEUE");
		break;
	case SI_TIMER:
		printf("SI_TIMER");
		break;
	case SI_ASYNCIO:
		printf("SI_ASYNCIO");
		break;
	case SI_MESGQ:
		printf("SI_MESGQ");
		break;
	case SI_KERNEL:
		printf("SI_KERNEL");
		break;
	case SI_LWP:
		printf("SI_LWP");
		break;
	default:
		switch (sig) {
		case SIGILL:
			sigillcodename(code);
			break;
		case SIGBUS:
			sigbuscodename(code);
			break;
		case SIGSEGV:
			sigsegvcodename(code);
			break;
		case SIGFPE:
			sigfpecodename(code);
			break;
		case SIGTRAP:
			sigtrapcodename(code);
			break;
		case SIGCHLD:
			sigchldcodename(code);
			break;
		default:
			printf("<invalid=%#x>", code);
		}
	}
}

/*
 * AUTO - Special
 *
 * Just print 0 as 0.
 */
void
umtxcvwaitflags(intmax_t arg)
{
	int or = 0;
	if (arg == 0) {
		printf("0");
		return;
	}
	printf("%#jx<", (uintmax_t)arg);
	if (!((arg > 0) ^ ((CVWAIT_CHECK_UNPARKING) > 0)))
		if_print_or(arg, CVWAIT_CHECK_UNPARKING, or);
	if (!((arg > 0) ^ ((CVWAIT_ABSTIME) > 0)))
		if_print_or(arg, CVWAIT_ABSTIME, or);
	if (!((arg > 0) ^ ((CVWAIT_CLOCKID) > 0)))
		if_print_or(arg, CVWAIT_CLOCKID, or);
	printf(">");
	if (or == 0)
		printf("<invalid>%jd", arg);
}


/*
 * AUTO - Special
 *
 * Just print 0 as 0.
 */
void
umtxrwlockflags(intmax_t arg)
{
	int or = 0;
	if (arg == 0) {
		printf("0");
		return;
	}
	printf("%#jx<", (uintmax_t)arg);
	if (!((arg > 0) ^ ((URWLOCK_PREFER_READER) > 0)))
		if_print_or(arg, URWLOCK_PREFER_READER, or);
	printf(">");
	if (or == 0)
		printf("<invalid>%jd", arg);
}
void
capname(const cap_rights_t *rightsp)
{
	int comma = 0;

	printf("<");
	if ((rightsp->cr_rights[0] & CAP_READ) == CAP_READ) {
		if (comma) printf(","); else comma = 1;
		printf("CAP_READ");
	}
	if ((rightsp->cr_rights[0] & CAP_WRITE) == CAP_WRITE) {
		if (comma) printf(","); else comma = 1;
		printf("CAP_WRITE");
	}
	if ((rightsp->cr_rights[0] & CAP_SEEK_TELL) == CAP_SEEK_TELL) {
		if (comma) printf(","); else comma = 1;
		printf("CAP_SEEK_TELL");
	}
	if ((rightsp->cr_rights[0] & CAP_MMAP) == CAP_MMAP) {
		if (comma) printf(","); else comma = 1;
		printf("CAP_MMAP");
	}
	if ((rightsp->cr_rights[0] & CAP_CREATE) == CAP_CREATE) {
		if (comma) printf(","); else comma = 1;
		printf("CAP_CREATE");
	}
	if ((rightsp->cr_rights[0] & CAP_FEXECVE) == CAP_FEXECVE) {
		if (comma) printf(","); else comma = 1;
		printf("CAP_FEXECVE");
	}
	if ((rightsp->cr_rights[0] & CAP_FSYNC) == CAP_FSYNC) {
		if (comma) printf(","); else comma = 1;
		printf("CAP_FSYNC");
	}
	if ((rightsp->cr_rights[0] & CAP_FTRUNCATE) == CAP_FTRUNCATE) {
		if (comma) printf(","); else comma = 1;
		printf("CAP_FTRUNCATE");
	}
	if ((rightsp->cr_rights[0] & CAP_LOOKUP) == CAP_LOOKUP) {
		if (comma) printf(","); else comma = 1;
		printf("CAP_LOOKUP");
	}
	if ((rightsp->cr_rights[0] & CAP_FCHDIR) == CAP_FCHDIR) {
		if (comma) printf(","); else comma = 1;
		printf("CAP_FCHDIR");
	}
	if ((rightsp->cr_rights[0] & CAP_FCHFLAGS) == CAP_FCHFLAGS) {
		if (comma) printf(","); else comma = 1;
		printf("CAP_FCHFLAGS");
	}
	if ((rightsp->cr_rights[0] & CAP_FCHMOD) == CAP_FCHMOD) {
		if (comma) printf(","); else comma = 1;
		printf("CAP_FCHMOD");
	}
	if ((rightsp->cr_rights[0] & CAP_FCHOWN) == CAP_FCHOWN) {
		if (comma) printf(","); else comma = 1;
		printf("CAP_FCHOWN");
	}
	if ((rightsp->cr_rights[0] & CAP_FCNTL) == CAP_FCNTL) {
		if (comma) printf(","); else comma = 1;
		printf("CAP_FCNTL");
	}
	if ((rightsp->cr_rights[0] & CAP_FLOCK) == CAP_FLOCK) {
		if (comma) printf(","); else comma = 1;
		printf("CAP_FLOCK");
	}
	if ((rightsp->cr_rights[0] & CAP_FPATHCONF) == CAP_FPATHCONF) {
		if (comma) printf(","); else comma = 1;
		printf("CAP_FPATHCONF");
	}
	if ((rightsp->cr_rights[0] & CAP_FSCK) == CAP_FSCK) {
		if (comma) printf(","); else comma = 1;
		printf("CAP_FSCK");
	}
	if ((rightsp->cr_rights[0] & CAP_FSTAT) == CAP_FSTAT) {
		if (comma) printf(","); else comma = 1;
		printf("CAP_FSTAT");
	}
	if ((rightsp->cr_rights[0] & CAP_FSTATFS) == CAP_FSTATFS) {
		if (comma) printf(","); else comma = 1;
		printf("CAP_FSTATFS");
	}
	if ((rightsp->cr_rights[0] & CAP_FUTIMES) == CAP_FUTIMES) {
		if (comma) printf(","); else comma = 1;
		printf("CAP_FUTIMES");
	}
	if ((rightsp->cr_rights[0] & CAP_ACCEPT) == CAP_ACCEPT) {
		if (comma) printf(","); else comma = 1;
		printf("CAP_ACCEPT");
	}
	if ((rightsp->cr_rights[0] & CAP_BIND) == CAP_BIND) {
		if (comma) printf(","); else comma = 1;
		printf("CAP_BIND");
	}
	if ((rightsp->cr_rights[0] & CAP_CONNECT) == CAP_CONNECT) {
		if (comma) printf(","); else comma = 1;
		printf("CAP_CONNECT");
	}
	if ((rightsp->cr_rights[0] & CAP_GETPEERNAME) == CAP_GETPEERNAME) {
		if (comma) printf(","); else comma = 1;
		printf("CAP_GETPEERNAME");
	}
	if ((rightsp->cr_rights[0] & CAP_GETSOCKNAME) == CAP_GETSOCKNAME) {
		if (comma) printf(","); else comma = 1;
		printf("CAP_GETSOCKNAME");
	}
	if ((rightsp->cr_rights[0] & CAP_GETSOCKOPT) == CAP_GETSOCKOPT) {
		if (comma) printf(","); else comma = 1;
		printf("CAP_GETSOCKOPT");
	}
	if ((rightsp->cr_rights[0] & CAP_LISTEN) == CAP_LISTEN) {
		if (comma) printf(","); else comma = 1;
		printf("CAP_LISTEN");
	}
	if ((rightsp->cr_rights[0] & CAP_PEELOFF) == CAP_PEELOFF) {
		if (comma) printf(","); else comma = 1;
		printf("CAP_PEELOFF");
	}
	if ((rightsp->cr_rights[0] & CAP_SETSOCKOPT) == CAP_SETSOCKOPT) {
		if (comma) printf(","); else comma = 1;
		printf("CAP_SETSOCKOPT");
	}
	if ((rightsp->cr_rights[0] & CAP_SHUTDOWN) == CAP_SHUTDOWN) {
		if (comma) printf(","); else comma = 1;
		printf("CAP_SHUTDOWN");
	}
	if ((rightsp->cr_rights[1] & CAP_MAC_GET) == CAP_MAC_GET) {
		if (comma) printf(","); else comma = 1;
		printf("CAP_MAC_GET");
	}
	if ((rightsp->cr_rights[1] & CAP_MAC_SET) == CAP_MAC_SET) {
		if (comma) printf(","); else comma = 1;
		printf("CAP_MAC_SET");
	}
	if ((rightsp->cr_rights[1] & CAP_SEM_GETVALUE) == CAP_SEM_GETVALUE) {
		if (comma) printf(","); else comma = 1;
		printf("CAP_SEM_GETVALUE");
	}
	if ((rightsp->cr_rights[1] & CAP_SEM_POST) == CAP_SEM_POST) {
		if (comma) printf(","); else comma = 1;
		printf("CAP_SEM_POST");
	}
	if ((rightsp->cr_rights[1] & CAP_SEM_WAIT) == CAP_SEM_WAIT) {
		if (comma) printf(","); else comma = 1;
		printf("CAP_SEM_WAIT");
	}
	if ((rightsp->cr_rights[1] & CAP_EVENT) == CAP_EVENT) {
		if (comma) printf(","); else comma = 1;
		printf("CAP_EVENT");
	}
	if ((rightsp->cr_rights[1] & CAP_KQUEUE_EVENT) == CAP_KQUEUE_EVENT) {
		if (comma) printf(","); else comma = 1;
		printf("CAP_KQUEUE_EVENT");
	}
	if ((rightsp->cr_rights[1] & CAP_IOCTL) == CAP_IOCTL) {
		if (comma) printf(","); else comma = 1;
		printf("CAP_IOCTL");
	}
	if ((rightsp->cr_rights[1] & CAP_TTYHOOK) == CAP_TTYHOOK) {
		if (comma) printf(","); else comma = 1;
		printf("CAP_TTYHOOK");
	}
	if ((rightsp->cr_rights[1] & CAP_PDGETPID) == CAP_PDGETPID) {
		if (comma) printf(","); else comma = 1;
		printf("CAP_PDGETPID");
	}
	if ((rightsp->cr_rights[1] & CAP_PDWAIT) == CAP_PDWAIT) {
		if (comma) printf(","); else comma = 1;
		printf("CAP_PDWAIT");
	}
	if ((rightsp->cr_rights[1] & CAP_PDKILL) == CAP_PDKILL) {
		if (comma) printf(","); else comma = 1;
		printf("CAP_PDKILL");
	}
	if ((rightsp->cr_rights[1] & CAP_EXTATTR_DELETE) == CAP_EXTATTR_DELETE) {
		if (comma) printf(","); else comma = 1;
		printf("CAP_EXTATTR_DELETE");
	}
	if ((rightsp->cr_rights[1] & CAP_EXTATTR_GET) == CAP_EXTATTR_GET) {
		if (comma) printf(","); else comma = 1;
		printf("CAP_EXTATTR_GET");
	}
	if ((rightsp->cr_rights[1] & CAP_EXTATTR_LIST) == CAP_EXTATTR_LIST) {
		if (comma) printf(","); else comma = 1;
		printf("CAP_EXTATTR_LIST");
	}
	if ((rightsp->cr_rights[1] & CAP_EXTATTR_SET) == CAP_EXTATTR_SET) {
		if (comma) printf(","); else comma = 1;
		printf("CAP_EXTATTR_SET");
	}
	if ((rightsp->cr_rights[1] & CAP_ACL_CHECK) == CAP_ACL_CHECK) {
		if (comma) printf(","); else comma = 1;
		printf("CAP_ACL_CHECK");
	}
	if ((rightsp->cr_rights[1] & CAP_ACL_DELETE) == CAP_ACL_DELETE) {
		if (comma) printf(","); else comma = 1;
		printf("CAP_ACL_DELETE");
	}
	if ((rightsp->cr_rights[1] & CAP_ACL_GET) == CAP_ACL_GET) {
		if (comma) printf(","); else comma = 1;
		printf("CAP_ACL_GET");
	}
	if ((rightsp->cr_rights[1] & CAP_ACL_SET) == CAP_ACL_SET) {
		if (comma) printf(","); else comma = 1;
		printf("CAP_ACL_SET");
	}
	if ((rightsp->cr_rights[1] & CAP_KQUEUE_CHANGE) == CAP_KQUEUE_CHANGE) {
		if (comma) printf(","); else comma = 1;
		printf("CAP_KQUEUE_CHANGE");
	}
	printf(">");
}
