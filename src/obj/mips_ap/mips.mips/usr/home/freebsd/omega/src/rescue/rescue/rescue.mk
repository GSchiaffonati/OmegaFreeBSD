# rescue.mk - generated from rescue.conf by crunchgen 0.2

LD?= ld
STRIPBIN?= strip
LIBS+= /home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/rescue/rescue/../librescue/exec.o /home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/rescue/rescue/../librescue/getusershell.o /home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/rescue/rescue/../librescue/login_class.o /home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/rescue/rescue/../librescue/popen.o /home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/rescue/rescue/../librescue/rcmdsh.o /home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/rescue/rescue/../librescue/sysctl.o /home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/rescue/rescue/../librescue/system.o -lcrypt -ledit -ljail -lkvm -lelf -ll -ltermcapw -lutil -lxo -l80211 -lalias -lcam -lncursesw -ldevstat -lipsec -llzma -lavl -lzpool -lzfs_core -lzfs -lnvpair -lpthread -luutil -lumem -lgeom -lbsdxml -lkiconv -lmt -lsbuf -lufs -lz -lbz2 -larchive -lcrypto -lmd -lm
LIBS_SO+=
CRUNCHMAKE=$(MAKE)
BUILDOPTS+= -DRESCUE CRUNCH_CFLAGS=-DRESCUE
CRUNCHED_OBJS= cat.lo chflags.lo chio.lo chmod.lo cp.lo date.lo dd.lo df.lo echo.lo ed.lo expr.lo getfacl.lo hostname.lo kenv.lo kill.lo ln.lo ls.lo mkdir.lo mv.lo pkill.lo ps.lo pwd.lo realpath.lo rm.lo rmdir.lo setfacl.lo sh.lo sleep.lo stty.lo sync.lo test.lo rcp.lo csh.lo badsect.lo camcontrol.lo ccdconfig.lo clri.lo devfs.lo dmesg.lo dump.lo dumpfs.lo dumpon.lo fsck.lo fsck_ffs.lo fsck_msdosfs.lo fsdb.lo fsirand.lo gbde.lo geom.lo ifconfig.lo init.lo kldconfig.lo kldload.lo kldstat.lo kldunload.lo ldconfig.lo md5.lo mdconfig.lo mdmfs.lo mknod.lo mount.lo mount_cd9660.lo mount_msdosfs.lo mount_nfs.lo mount_nullfs.lo mount_udf.lo mount_unionfs.lo newfs.lo newfs_msdos.lo nos-tun.lo ping.lo reboot.lo restore.lo rcorder.lo route.lo routed.lo rtquery.lo rtsol.lo savecore.lo spppcontrol.lo swapon.lo sysctl.lo tunefs.lo umount.lo ping6.lo ipf.lo zfs.lo zpool.lo dhclient.lo head.lo mt.lo nc.lo sed.lo tail.lo tee.lo gzip.lo bzip2.lo less.lo xz.lo tar.lo vi.lo id.lo iscsictl.lo zdb.lo chroot.lo chown.lo iscsid.lo
SUBMAKE_TARGETS= cat_make chflags_make chio_make chmod_make cp_make date_make dd_make df_make echo_make ed_make expr_make getfacl_make hostname_make kenv_make kill_make ln_make ls_make mkdir_make mv_make pkill_make ps_make pwd_make realpath_make rm_make rmdir_make setfacl_make sh_make sleep_make stty_make sync_make test_make rcp_make csh_make badsect_make camcontrol_make ccdconfig_make clri_make devfs_make dmesg_make dump_make dumpfs_make dumpon_make fsck_make fsck_ffs_make fsck_msdosfs_make fsdb_make fsirand_make gbde_make geom_make ifconfig_make init_make kldconfig_make kldload_make kldstat_make kldunload_make ldconfig_make md5_make mdconfig_make mdmfs_make mknod_make mount_make mount_cd9660_make mount_msdosfs_make mount_nfs_make mount_nullfs_make mount_udf_make mount_unionfs_make newfs_make newfs_msdos_make nos_tun_make ping_make reboot_make restore_make rcorder_make route_make routed_make rtquery_make rtsol_make savecore_make spppcontrol_make swapon_make sysctl_make tunefs_make umount_make ping6_make ipf_make zfs_make zpool_make dhclient_make head_make mt_make nc_make sed_make tail_make tee_make gzip_make bzip2_make less_make xz_make tar_make vi_make id_make iscsictl_make zdb_make chroot_make chown_make iscsid_make
SUBCLEAN_TARGETS= cat_clean chflags_clean chio_clean chmod_clean cp_clean date_clean dd_clean df_clean echo_clean ed_clean expr_clean getfacl_clean hostname_clean kenv_clean kill_clean ln_clean ls_clean mkdir_clean mv_clean pkill_clean ps_clean pwd_clean realpath_clean rm_clean rmdir_clean setfacl_clean sh_clean sleep_clean stty_clean sync_clean test_clean rcp_clean csh_clean badsect_clean camcontrol_clean ccdconfig_clean clri_clean devfs_clean dmesg_clean dump_clean dumpfs_clean dumpon_clean fsck_clean fsck_ffs_clean fsck_msdosfs_clean fsdb_clean fsirand_clean gbde_clean geom_clean ifconfig_clean init_clean kldconfig_clean kldload_clean kldstat_clean kldunload_clean ldconfig_clean md5_clean mdconfig_clean mdmfs_clean mknod_clean mount_clean mount_cd9660_clean mount_msdosfs_clean mount_nfs_clean mount_nullfs_clean mount_udf_clean mount_unionfs_clean newfs_clean newfs_msdos_clean nos_tun_clean ping_clean reboot_clean restore_clean rcorder_clean route_clean routed_clean rtquery_clean rtsol_clean savecore_clean spppcontrol_clean swapon_clean sysctl_clean tunefs_clean umount_clean ping6_clean ipf_clean zfs_clean zpool_clean dhclient_clean head_clean mt_clean nc_clean sed_clean tail_clean tee_clean gzip_clean bzip2_clean less_clean xz_clean tar_clean vi_clean id_clean iscsictl_clean zdb_clean chroot_clean chown_clean iscsid_clean

all: objs exe
objs: $(SUBMAKE_TARGETS)
exe: rescue
rescue: rescue.o $(CRUNCHED_OBJS) $(SUBMAKE_TARGETS)
.if defined(LIBS_SO) && !empty(LIBS_SO)
	$(CC) -o rescue rescue.o $(CRUNCHED_OBJS) \
		-Xlinker -Bstatic $(LIBS) \
		-Xlinker -Bdynamic $(LIBS_SO)
.else
	$(CC) -static -o rescue rescue.o $(CRUNCHED_OBJS) $(LIBS)
.endif
	$(STRIPBIN) rescue
realclean: clean subclean
clean:
	rm -f rescue *.lo *.o *_stub.c
subclean: $(SUBCLEAN_TARGETS)

# -------- cat

cat_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/rescue/rescue//usr/home/freebsd/omega/src/bin/cat
cat_OBJPATHS= $(cat_OBJDIR)/cat.o
cat_SRCDIR=/usr/home/freebsd/omega/src/rescue/rescue/../../bin/cat
cat_REALSRCDIR=/usr/home/freebsd/omega/src/bin/cat
cat_OBJS= cat.o
cat_OPTS+= DIRPRFX=rescue/rescue/cat/
cat_make:
	(cd $(cat_SRCDIR) && \
		$(CRUNCHMAKE) $(BUILDOPTS) $(cat_OPTS) depend &&\
		$(CRUNCHMAKE) $(BUILDOPTS) $(cat_OPTS) $(cat_OBJS))
cat_clean:
	(cd $(cat_SRCDIR) && $(CRUNCHMAKE) $(BUILDOPTS) clean cleandepend)

cat_stub.c:
	echo "int _crunched_cat_stub(int argc, char **argv, char **envp){return main(argc,argv,envp);}" >cat_stub.c
cat.lo: cat_stub.o $(cat_OBJPATHS)
	$(CC) -nostdlib -Wl,-dc -r -o cat.lo cat_stub.o $(cat_OBJPATHS)
	crunchide -k _crunched_cat_stub cat.lo

# -------- chflags

chflags_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/rescue/rescue//usr/home/freebsd/omega/src/bin/chflags
chflags_OBJPATHS= $(chflags_OBJDIR)/chflags.o
chflags_SRCDIR=/usr/home/freebsd/omega/src/rescue/rescue/../../bin/chflags
chflags_REALSRCDIR=/usr/home/freebsd/omega/src/bin/chflags
chflags_OBJS= chflags.o
chflags_OPTS+= DIRPRFX=rescue/rescue/chflags/
chflags_make:
	(cd $(chflags_SRCDIR) && \
		$(CRUNCHMAKE) $(BUILDOPTS) $(chflags_OPTS) depend &&\
		$(CRUNCHMAKE) $(BUILDOPTS) $(chflags_OPTS) $(chflags_OBJS))
chflags_clean:
	(cd $(chflags_SRCDIR) && $(CRUNCHMAKE) $(BUILDOPTS) clean cleandepend)

chflags_stub.c:
	echo "int _crunched_chflags_stub(int argc, char **argv, char **envp){return main(argc,argv,envp);}" >chflags_stub.c
chflags.lo: chflags_stub.o $(chflags_OBJPATHS)
	$(CC) -nostdlib -Wl,-dc -r -o chflags.lo chflags_stub.o $(chflags_OBJPATHS)
	crunchide -k _crunched_chflags_stub chflags.lo

# -------- chio

chio_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/rescue/rescue//usr/home/freebsd/omega/src/bin/chio
chio_OBJPATHS= $(chio_OBJDIR)/chio.o
chio_SRCDIR=/usr/home/freebsd/omega/src/rescue/rescue/../../bin/chio
chio_REALSRCDIR=/usr/home/freebsd/omega/src/bin/chio
chio_OBJS= chio.o
chio_OPTS+= DIRPRFX=rescue/rescue/chio/
chio_make:
	(cd $(chio_SRCDIR) && \
		$(CRUNCHMAKE) $(BUILDOPTS) $(chio_OPTS) depend &&\
		$(CRUNCHMAKE) $(BUILDOPTS) $(chio_OPTS) $(chio_OBJS))
chio_clean:
	(cd $(chio_SRCDIR) && $(CRUNCHMAKE) $(BUILDOPTS) clean cleandepend)

chio_stub.c:
	echo "int _crunched_chio_stub(int argc, char **argv, char **envp){return main(argc,argv,envp);}" >chio_stub.c
chio.lo: chio_stub.o $(chio_OBJPATHS)
	$(CC) -nostdlib -Wl,-dc -r -o chio.lo chio_stub.o $(chio_OBJPATHS)
	crunchide -k _crunched_chio_stub chio.lo

# -------- chmod

chmod_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/rescue/rescue//usr/home/freebsd/omega/src/bin/chmod
chmod_OBJPATHS= $(chmod_OBJDIR)/chmod.o
chmod_SRCDIR=/usr/home/freebsd/omega/src/rescue/rescue/../../bin/chmod
chmod_REALSRCDIR=/usr/home/freebsd/omega/src/bin/chmod
chmod_OBJS= chmod.o
chmod_OPTS+= DIRPRFX=rescue/rescue/chmod/
chmod_make:
	(cd $(chmod_SRCDIR) && \
		$(CRUNCHMAKE) $(BUILDOPTS) $(chmod_OPTS) depend &&\
		$(CRUNCHMAKE) $(BUILDOPTS) $(chmod_OPTS) $(chmod_OBJS))
chmod_clean:
	(cd $(chmod_SRCDIR) && $(CRUNCHMAKE) $(BUILDOPTS) clean cleandepend)

chmod_stub.c:
	echo "int _crunched_chmod_stub(int argc, char **argv, char **envp){return main(argc,argv,envp);}" >chmod_stub.c
chmod.lo: chmod_stub.o $(chmod_OBJPATHS)
	$(CC) -nostdlib -Wl,-dc -r -o chmod.lo chmod_stub.o $(chmod_OBJPATHS)
	crunchide -k _crunched_chmod_stub chmod.lo

# -------- cp

cp_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/rescue/rescue//usr/home/freebsd/omega/src/bin/cp
cp_OBJPATHS= $(cp_OBJDIR)/cp.o $(cp_OBJDIR)/utils.o
cp_SRCDIR=/usr/home/freebsd/omega/src/rescue/rescue/../../bin/cp
cp_REALSRCDIR=/usr/home/freebsd/omega/src/bin/cp
cp_OBJS= cp.o utils.o
cp_OPTS+= DIRPRFX=rescue/rescue/cp/
cp_make:
	(cd $(cp_SRCDIR) && \
		$(CRUNCHMAKE) $(BUILDOPTS) $(cp_OPTS) depend &&\
		$(CRUNCHMAKE) $(BUILDOPTS) $(cp_OPTS) $(cp_OBJS))
cp_clean:
	(cd $(cp_SRCDIR) && $(CRUNCHMAKE) $(BUILDOPTS) clean cleandepend)

cp_stub.c:
	echo "int _crunched_cp_stub(int argc, char **argv, char **envp){return main(argc,argv,envp);}" >cp_stub.c
cp.lo: cp_stub.o $(cp_OBJPATHS)
	$(CC) -nostdlib -Wl,-dc -r -o cp.lo cp_stub.o $(cp_OBJPATHS)
	crunchide -k _crunched_cp_stub cp.lo

# -------- date

date_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/rescue/rescue//usr/home/freebsd/omega/src/bin/date
date_OBJPATHS= $(date_OBJDIR)/date.o $(date_OBJDIR)/netdate.o $(date_OBJDIR)/vary.o
date_SRCDIR=/usr/home/freebsd/omega/src/rescue/rescue/../../bin/date
date_REALSRCDIR=/usr/home/freebsd/omega/src/bin/date
date_OBJS= date.o netdate.o vary.o
date_OPTS+= DIRPRFX=rescue/rescue/date/
date_make:
	(cd $(date_SRCDIR) && \
		$(CRUNCHMAKE) $(BUILDOPTS) $(date_OPTS) depend &&\
		$(CRUNCHMAKE) $(BUILDOPTS) $(date_OPTS) $(date_OBJS))
date_clean:
	(cd $(date_SRCDIR) && $(CRUNCHMAKE) $(BUILDOPTS) clean cleandepend)

date_stub.c:
	echo "int _crunched_date_stub(int argc, char **argv, char **envp){return main(argc,argv,envp);}" >date_stub.c
date.lo: date_stub.o $(date_OBJPATHS)
	$(CC) -nostdlib -Wl,-dc -r -o date.lo date_stub.o $(date_OBJPATHS)
	crunchide -k _crunched_date_stub date.lo

# -------- dd

dd_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/rescue/rescue//usr/home/freebsd/omega/src/bin/dd
dd_OBJPATHS= $(dd_OBJDIR)/args.o $(dd_OBJDIR)/conv.o $(dd_OBJDIR)/conv_tab.o $(dd_OBJDIR)/dd.o $(dd_OBJDIR)/misc.o $(dd_OBJDIR)/position.o
dd_SRCDIR=/usr/home/freebsd/omega/src/rescue/rescue/../../bin/dd
dd_REALSRCDIR=/usr/home/freebsd/omega/src/bin/dd
dd_OBJS= args.o conv.o conv_tab.o dd.o misc.o position.o
dd_OPTS+= DIRPRFX=rescue/rescue/dd/
dd_make:
	(cd $(dd_SRCDIR) && \
		$(CRUNCHMAKE) $(BUILDOPTS) $(dd_OPTS) depend &&\
		$(CRUNCHMAKE) $(BUILDOPTS) $(dd_OPTS) $(dd_OBJS))
dd_clean:
	(cd $(dd_SRCDIR) && $(CRUNCHMAKE) $(BUILDOPTS) clean cleandepend)

dd_stub.c:
	echo "int _crunched_dd_stub(int argc, char **argv, char **envp){return main(argc,argv,envp);}" >dd_stub.c
dd.lo: dd_stub.o $(dd_OBJPATHS)
	$(CC) -nostdlib -Wl,-dc -r -o dd.lo dd_stub.o $(dd_OBJPATHS)
	crunchide -k _crunched_dd_stub dd.lo

# -------- df

df_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/rescue/rescue//usr/home/freebsd/omega/src/bin/df
df_OBJPATHS= $(df_OBJDIR)/df.o $(df_OBJDIR)/vfslist.o
df_SRCDIR=/usr/home/freebsd/omega/src/rescue/rescue/../../bin/df
df_REALSRCDIR=/usr/home/freebsd/omega/src/bin/df
df_OBJS= df.o vfslist.o
df_OPTS+= DIRPRFX=rescue/rescue/df/
df_make:
	(cd $(df_SRCDIR) && \
		$(CRUNCHMAKE) $(BUILDOPTS) $(df_OPTS) depend &&\
		$(CRUNCHMAKE) $(BUILDOPTS) $(df_OPTS) $(df_OBJS))
df_clean:
	(cd $(df_SRCDIR) && $(CRUNCHMAKE) $(BUILDOPTS) clean cleandepend)

df_stub.c:
	echo "int _crunched_df_stub(int argc, char **argv, char **envp){return main(argc,argv,envp);}" >df_stub.c
df.lo: df_stub.o $(df_OBJPATHS)
	$(CC) -nostdlib -Wl,-dc -r -o df.lo df_stub.o $(df_OBJPATHS)
	crunchide -k _crunched_df_stub df.lo

# -------- echo

echo_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/rescue/rescue//usr/home/freebsd/omega/src/bin/echo
echo_OBJPATHS= $(echo_OBJDIR)/echo.o
echo_SRCDIR=/usr/home/freebsd/omega/src/rescue/rescue/../../bin/echo
echo_REALSRCDIR=/usr/home/freebsd/omega/src/bin/echo
echo_OBJS= echo.o
echo_OPTS+= DIRPRFX=rescue/rescue/echo/
echo_make:
	(cd $(echo_SRCDIR) && \
		$(CRUNCHMAKE) $(BUILDOPTS) $(echo_OPTS) depend &&\
		$(CRUNCHMAKE) $(BUILDOPTS) $(echo_OPTS) $(echo_OBJS))
echo_clean:
	(cd $(echo_SRCDIR) && $(CRUNCHMAKE) $(BUILDOPTS) clean cleandepend)

echo_stub.c:
	echo "int _crunched_echo_stub(int argc, char **argv, char **envp){return main(argc,argv,envp);}" >echo_stub.c
echo.lo: echo_stub.o $(echo_OBJPATHS)
	$(CC) -nostdlib -Wl,-dc -r -o echo.lo echo_stub.o $(echo_OBJPATHS)
	crunchide -k _crunched_echo_stub echo.lo

# -------- ed

ed_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/rescue/rescue//usr/home/freebsd/omega/src/bin/ed
ed_OBJPATHS= $(ed_OBJDIR)/buf.o $(ed_OBJDIR)/cbc.o $(ed_OBJDIR)/glbl.o $(ed_OBJDIR)/io.o $(ed_OBJDIR)/main.o $(ed_OBJDIR)/re.o $(ed_OBJDIR)/sub.o $(ed_OBJDIR)/undo.o
ed_SRCDIR=/usr/home/freebsd/omega/src/rescue/rescue/../../bin/ed
ed_REALSRCDIR=/usr/home/freebsd/omega/src/bin/ed
ed_OBJS= buf.o cbc.o glbl.o io.o main.o re.o sub.o undo.o
ed_OPTS+= DIRPRFX=rescue/rescue/ed/
ed_make:
	(cd $(ed_SRCDIR) && \
		$(CRUNCHMAKE) $(BUILDOPTS) $(ed_OPTS) depend &&\
		$(CRUNCHMAKE) $(BUILDOPTS) $(ed_OPTS) $(ed_OBJS))
ed_clean:
	(cd $(ed_SRCDIR) && $(CRUNCHMAKE) $(BUILDOPTS) clean cleandepend)

ed_stub.c:
	echo "int _crunched_ed_stub(int argc, char **argv, char **envp){return main(argc,argv,envp);}" >ed_stub.c
ed.lo: ed_stub.o $(ed_OBJPATHS)
	$(CC) -nostdlib -Wl,-dc -r -o ed.lo ed_stub.o $(ed_OBJPATHS)
	crunchide -k _crunched_ed_stub ed.lo

# -------- expr

expr_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/rescue/rescue//usr/home/freebsd/omega/src/bin/expr
expr_OBJPATHS= $(expr_OBJDIR)/expr.o
expr_SRCDIR=/usr/home/freebsd/omega/src/rescue/rescue/../../bin/expr
expr_REALSRCDIR=/usr/home/freebsd/omega/src/bin/expr
expr_OBJS= expr.o
expr_OPTS+= DIRPRFX=rescue/rescue/expr/
expr_make:
	(cd $(expr_SRCDIR) && \
		$(CRUNCHMAKE) $(BUILDOPTS) $(expr_OPTS) depend &&\
		$(CRUNCHMAKE) $(BUILDOPTS) $(expr_OPTS) $(expr_OBJS))
expr_clean:
	(cd $(expr_SRCDIR) && $(CRUNCHMAKE) $(BUILDOPTS) clean cleandepend)

expr_stub.c:
	echo "int _crunched_expr_stub(int argc, char **argv, char **envp){return main(argc,argv,envp);}" >expr_stub.c
expr.lo: expr_stub.o $(expr_OBJPATHS)
	$(CC) -nostdlib -Wl,-dc -r -o expr.lo expr_stub.o $(expr_OBJPATHS)
	crunchide -k _crunched_expr_stub expr.lo

# -------- getfacl

getfacl_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/rescue/rescue//usr/home/freebsd/omega/src/bin/getfacl
getfacl_OBJPATHS= $(getfacl_OBJDIR)/getfacl.o
getfacl_SRCDIR=/usr/home/freebsd/omega/src/rescue/rescue/../../bin/getfacl
getfacl_REALSRCDIR=/usr/home/freebsd/omega/src/bin/getfacl
getfacl_OBJS= getfacl.o
getfacl_OPTS+= DIRPRFX=rescue/rescue/getfacl/
getfacl_make:
	(cd $(getfacl_SRCDIR) && \
		$(CRUNCHMAKE) $(BUILDOPTS) $(getfacl_OPTS) depend &&\
		$(CRUNCHMAKE) $(BUILDOPTS) $(getfacl_OPTS) $(getfacl_OBJS))
getfacl_clean:
	(cd $(getfacl_SRCDIR) && $(CRUNCHMAKE) $(BUILDOPTS) clean cleandepend)

getfacl_stub.c:
	echo "int _crunched_getfacl_stub(int argc, char **argv, char **envp){return main(argc,argv,envp);}" >getfacl_stub.c
getfacl.lo: getfacl_stub.o $(getfacl_OBJPATHS)
	$(CC) -nostdlib -Wl,-dc -r -o getfacl.lo getfacl_stub.o $(getfacl_OBJPATHS)
	crunchide -k _crunched_getfacl_stub getfacl.lo

# -------- hostname

hostname_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/rescue/rescue//usr/home/freebsd/omega/src/bin/hostname
hostname_OBJPATHS= $(hostname_OBJDIR)/hostname.o
hostname_SRCDIR=/usr/home/freebsd/omega/src/rescue/rescue/../../bin/hostname
hostname_REALSRCDIR=/usr/home/freebsd/omega/src/bin/hostname
hostname_OBJS= hostname.o
hostname_OPTS+= DIRPRFX=rescue/rescue/hostname/
hostname_make:
	(cd $(hostname_SRCDIR) && \
		$(CRUNCHMAKE) $(BUILDOPTS) $(hostname_OPTS) depend &&\
		$(CRUNCHMAKE) $(BUILDOPTS) $(hostname_OPTS) $(hostname_OBJS))
hostname_clean:
	(cd $(hostname_SRCDIR) && $(CRUNCHMAKE) $(BUILDOPTS) clean cleandepend)

hostname_stub.c:
	echo "int _crunched_hostname_stub(int argc, char **argv, char **envp){return main(argc,argv,envp);}" >hostname_stub.c
hostname.lo: hostname_stub.o $(hostname_OBJPATHS)
	$(CC) -nostdlib -Wl,-dc -r -o hostname.lo hostname_stub.o $(hostname_OBJPATHS)
	crunchide -k _crunched_hostname_stub hostname.lo

# -------- kenv

kenv_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/rescue/rescue//usr/home/freebsd/omega/src/bin/kenv
kenv_OBJPATHS= $(kenv_OBJDIR)/kenv.o
kenv_SRCDIR=/usr/home/freebsd/omega/src/rescue/rescue/../../bin/kenv
kenv_REALSRCDIR=/usr/home/freebsd/omega/src/bin/kenv
kenv_OBJS= kenv.o
kenv_OPTS+= DIRPRFX=rescue/rescue/kenv/
kenv_make:
	(cd $(kenv_SRCDIR) && \
		$(CRUNCHMAKE) $(BUILDOPTS) $(kenv_OPTS) depend &&\
		$(CRUNCHMAKE) $(BUILDOPTS) $(kenv_OPTS) $(kenv_OBJS))
kenv_clean:
	(cd $(kenv_SRCDIR) && $(CRUNCHMAKE) $(BUILDOPTS) clean cleandepend)

kenv_stub.c:
	echo "int _crunched_kenv_stub(int argc, char **argv, char **envp){return main(argc,argv,envp);}" >kenv_stub.c
kenv.lo: kenv_stub.o $(kenv_OBJPATHS)
	$(CC) -nostdlib -Wl,-dc -r -o kenv.lo kenv_stub.o $(kenv_OBJPATHS)
	crunchide -k _crunched_kenv_stub kenv.lo

# -------- kill

kill_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/rescue/rescue//usr/home/freebsd/omega/src/bin/kill
kill_OBJPATHS= $(kill_OBJDIR)/kill.o
kill_SRCDIR=/usr/home/freebsd/omega/src/rescue/rescue/../../bin/kill
kill_REALSRCDIR=/usr/home/freebsd/omega/src/bin/kill
kill_OBJS= kill.o
kill_OPTS+= DIRPRFX=rescue/rescue/kill/
kill_make:
	(cd $(kill_SRCDIR) && \
		$(CRUNCHMAKE) $(BUILDOPTS) $(kill_OPTS) depend &&\
		$(CRUNCHMAKE) $(BUILDOPTS) $(kill_OPTS) $(kill_OBJS))
kill_clean:
	(cd $(kill_SRCDIR) && $(CRUNCHMAKE) $(BUILDOPTS) clean cleandepend)

kill_stub.c:
	echo "int _crunched_kill_stub(int argc, char **argv, char **envp){return main(argc,argv,envp);}" >kill_stub.c
kill.lo: kill_stub.o $(kill_OBJPATHS)
	$(CC) -nostdlib -Wl,-dc -r -o kill.lo kill_stub.o $(kill_OBJPATHS)
	crunchide -k _crunched_kill_stub kill.lo

# -------- ln

ln_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/rescue/rescue//usr/home/freebsd/omega/src/bin/ln
ln_OBJPATHS= $(ln_OBJDIR)/ln.o
ln_SRCDIR=/usr/home/freebsd/omega/src/rescue/rescue/../../bin/ln
ln_REALSRCDIR=/usr/home/freebsd/omega/src/bin/ln
ln_OBJS= ln.o
ln_OPTS+= DIRPRFX=rescue/rescue/ln/
ln_make:
	(cd $(ln_SRCDIR) && \
		$(CRUNCHMAKE) $(BUILDOPTS) $(ln_OPTS) depend &&\
		$(CRUNCHMAKE) $(BUILDOPTS) $(ln_OPTS) $(ln_OBJS))
ln_clean:
	(cd $(ln_SRCDIR) && $(CRUNCHMAKE) $(BUILDOPTS) clean cleandepend)

ln_stub.c:
	echo "int _crunched_ln_stub(int argc, char **argv, char **envp){return main(argc,argv,envp);}" >ln_stub.c
ln.lo: ln_stub.o $(ln_OBJPATHS)
	$(CC) -nostdlib -Wl,-dc -r -o ln.lo ln_stub.o $(ln_OBJPATHS)
	crunchide -k _crunched_ln_stub ln.lo

# -------- ls

ls_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/rescue/rescue//usr/home/freebsd/omega/src/bin/ls
ls_OBJPATHS= $(ls_OBJDIR)/cmp.o $(ls_OBJDIR)/ls.o $(ls_OBJDIR)/print.o $(ls_OBJDIR)/util.o
ls_SRCDIR=/usr/home/freebsd/omega/src/rescue/rescue/../../bin/ls
ls_REALSRCDIR=/usr/home/freebsd/omega/src/bin/ls
ls_OBJS= cmp.o ls.o print.o util.o
ls_OPTS+= DIRPRFX=rescue/rescue/ls/
ls_make:
	(cd $(ls_SRCDIR) && \
		$(CRUNCHMAKE) $(BUILDOPTS) $(ls_OPTS) depend &&\
		$(CRUNCHMAKE) $(BUILDOPTS) $(ls_OPTS) $(ls_OBJS))
ls_clean:
	(cd $(ls_SRCDIR) && $(CRUNCHMAKE) $(BUILDOPTS) clean cleandepend)

ls_stub.c:
	echo "int _crunched_ls_stub(int argc, char **argv, char **envp){return main(argc,argv,envp);}" >ls_stub.c
ls.lo: ls_stub.o $(ls_OBJPATHS)
	$(CC) -nostdlib -Wl,-dc -r -o ls.lo ls_stub.o $(ls_OBJPATHS)
	crunchide -k _crunched_ls_stub ls.lo

# -------- mkdir

mkdir_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/rescue/rescue//usr/home/freebsd/omega/src/bin/mkdir
mkdir_OBJPATHS= $(mkdir_OBJDIR)/mkdir.o
mkdir_SRCDIR=/usr/home/freebsd/omega/src/rescue/rescue/../../bin/mkdir
mkdir_REALSRCDIR=/usr/home/freebsd/omega/src/bin/mkdir
mkdir_OBJS= mkdir.o
mkdir_OPTS+= DIRPRFX=rescue/rescue/mkdir/
mkdir_make:
	(cd $(mkdir_SRCDIR) && \
		$(CRUNCHMAKE) $(BUILDOPTS) $(mkdir_OPTS) depend &&\
		$(CRUNCHMAKE) $(BUILDOPTS) $(mkdir_OPTS) $(mkdir_OBJS))
mkdir_clean:
	(cd $(mkdir_SRCDIR) && $(CRUNCHMAKE) $(BUILDOPTS) clean cleandepend)

mkdir_stub.c:
	echo "int _crunched_mkdir_stub(int argc, char **argv, char **envp){return main(argc,argv,envp);}" >mkdir_stub.c
mkdir.lo: mkdir_stub.o $(mkdir_OBJPATHS)
	$(CC) -nostdlib -Wl,-dc -r -o mkdir.lo mkdir_stub.o $(mkdir_OBJPATHS)
	crunchide -k _crunched_mkdir_stub mkdir.lo

# -------- mv

mv_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/rescue/rescue//usr/home/freebsd/omega/src/bin/mv
mv_OBJPATHS= $(mv_OBJDIR)/mv.o
mv_SRCDIR=/usr/home/freebsd/omega/src/rescue/rescue/../../bin/mv
mv_REALSRCDIR=/usr/home/freebsd/omega/src/bin/mv
mv_OBJS= mv.o
mv_OPTS+= DIRPRFX=rescue/rescue/mv/
mv_make:
	(cd $(mv_SRCDIR) && \
		$(CRUNCHMAKE) $(BUILDOPTS) $(mv_OPTS) depend &&\
		$(CRUNCHMAKE) $(BUILDOPTS) $(mv_OPTS) $(mv_OBJS))
mv_clean:
	(cd $(mv_SRCDIR) && $(CRUNCHMAKE) $(BUILDOPTS) clean cleandepend)

mv_stub.c:
	echo "int _crunched_mv_stub(int argc, char **argv, char **envp){return main(argc,argv,envp);}" >mv_stub.c
mv.lo: mv_stub.o $(mv_OBJPATHS)
	$(CC) -nostdlib -Wl,-dc -r -o mv.lo mv_stub.o $(mv_OBJPATHS)
	crunchide -k _crunched_mv_stub mv.lo

# -------- pkill

pkill_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/rescue/rescue//usr/home/freebsd/omega/src/bin/pkill
pkill_OBJPATHS= $(pkill_OBJDIR)/pkill.o
pkill_SRCDIR=/usr/home/freebsd/omega/src/rescue/rescue/../../bin/pkill
pkill_REALSRCDIR=/usr/home/freebsd/omega/src/bin/pkill
pkill_OBJS= pkill.o
pkill_OPTS+= DIRPRFX=rescue/rescue/pkill/
pkill_make:
	(cd $(pkill_SRCDIR) && \
		$(CRUNCHMAKE) $(BUILDOPTS) $(pkill_OPTS) depend &&\
		$(CRUNCHMAKE) $(BUILDOPTS) $(pkill_OPTS) $(pkill_OBJS))
pkill_clean:
	(cd $(pkill_SRCDIR) && $(CRUNCHMAKE) $(BUILDOPTS) clean cleandepend)

pkill_stub.c:
	echo "int _crunched_pkill_stub(int argc, char **argv, char **envp){return main(argc,argv,envp);}" >pkill_stub.c
pkill.lo: pkill_stub.o $(pkill_OBJPATHS)
	$(CC) -nostdlib -Wl,-dc -r -o pkill.lo pkill_stub.o $(pkill_OBJPATHS)
	crunchide -k _crunched_pkill_stub pkill.lo

# -------- ps

ps_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/rescue/rescue//usr/home/freebsd/omega/src/bin/ps
ps_OBJPATHS= $(ps_OBJDIR)/fmt.o $(ps_OBJDIR)/keyword.o $(ps_OBJDIR)/nlist.o $(ps_OBJDIR)/print.o $(ps_OBJDIR)/ps.o
ps_SRCDIR=/usr/home/freebsd/omega/src/rescue/rescue/../../bin/ps
ps_REALSRCDIR=/usr/home/freebsd/omega/src/bin/ps
ps_OBJS= fmt.o keyword.o nlist.o print.o ps.o
ps_OPTS+= DIRPRFX=rescue/rescue/ps/
ps_make:
	(cd $(ps_SRCDIR) && \
		$(CRUNCHMAKE) $(BUILDOPTS) $(ps_OPTS) depend &&\
		$(CRUNCHMAKE) $(BUILDOPTS) $(ps_OPTS) $(ps_OBJS))
ps_clean:
	(cd $(ps_SRCDIR) && $(CRUNCHMAKE) $(BUILDOPTS) clean cleandepend)

ps_stub.c:
	echo "int _crunched_ps_stub(int argc, char **argv, char **envp){return main(argc,argv,envp);}" >ps_stub.c
ps.lo: ps_stub.o $(ps_OBJPATHS)
	$(CC) -nostdlib -Wl,-dc -r -o ps.lo ps_stub.o $(ps_OBJPATHS)
	crunchide -k _crunched_ps_stub ps.lo

# -------- pwd

pwd_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/rescue/rescue//usr/home/freebsd/omega/src/bin/pwd
pwd_OBJPATHS= $(pwd_OBJDIR)/pwd.o
pwd_SRCDIR=/usr/home/freebsd/omega/src/rescue/rescue/../../bin/pwd
pwd_REALSRCDIR=/usr/home/freebsd/omega/src/bin/pwd
pwd_OBJS= pwd.o
pwd_OPTS+= DIRPRFX=rescue/rescue/pwd/
pwd_make:
	(cd $(pwd_SRCDIR) && \
		$(CRUNCHMAKE) $(BUILDOPTS) $(pwd_OPTS) depend &&\
		$(CRUNCHMAKE) $(BUILDOPTS) $(pwd_OPTS) $(pwd_OBJS))
pwd_clean:
	(cd $(pwd_SRCDIR) && $(CRUNCHMAKE) $(BUILDOPTS) clean cleandepend)

pwd_stub.c:
	echo "int _crunched_pwd_stub(int argc, char **argv, char **envp){return main(argc,argv,envp);}" >pwd_stub.c
pwd.lo: pwd_stub.o $(pwd_OBJPATHS)
	$(CC) -nostdlib -Wl,-dc -r -o pwd.lo pwd_stub.o $(pwd_OBJPATHS)
	crunchide -k _crunched_pwd_stub pwd.lo

# -------- realpath

realpath_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/rescue/rescue//usr/home/freebsd/omega/src/bin/realpath
realpath_OBJPATHS= $(realpath_OBJDIR)/realpath.o
realpath_SRCDIR=/usr/home/freebsd/omega/src/rescue/rescue/../../bin/realpath
realpath_REALSRCDIR=/usr/home/freebsd/omega/src/bin/realpath
realpath_OBJS= realpath.o
realpath_OPTS+= DIRPRFX=rescue/rescue/realpath/
realpath_make:
	(cd $(realpath_SRCDIR) && \
		$(CRUNCHMAKE) $(BUILDOPTS) $(realpath_OPTS) depend &&\
		$(CRUNCHMAKE) $(BUILDOPTS) $(realpath_OPTS) $(realpath_OBJS))
realpath_clean:
	(cd $(realpath_SRCDIR) && $(CRUNCHMAKE) $(BUILDOPTS) clean cleandepend)

realpath_stub.c:
	echo "int _crunched_realpath_stub(int argc, char **argv, char **envp){return main(argc,argv,envp);}" >realpath_stub.c
realpath.lo: realpath_stub.o $(realpath_OBJPATHS)
	$(CC) -nostdlib -Wl,-dc -r -o realpath.lo realpath_stub.o $(realpath_OBJPATHS)
	crunchide -k _crunched_realpath_stub realpath.lo

# -------- rm

rm_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/rescue/rescue//usr/home/freebsd/omega/src/bin/rm
rm_OBJPATHS= $(rm_OBJDIR)/rm.o
rm_SRCDIR=/usr/home/freebsd/omega/src/rescue/rescue/../../bin/rm
rm_REALSRCDIR=/usr/home/freebsd/omega/src/bin/rm
rm_OBJS= rm.o
rm_OPTS+= DIRPRFX=rescue/rescue/rm/
rm_make:
	(cd $(rm_SRCDIR) && \
		$(CRUNCHMAKE) $(BUILDOPTS) $(rm_OPTS) depend &&\
		$(CRUNCHMAKE) $(BUILDOPTS) $(rm_OPTS) $(rm_OBJS))
rm_clean:
	(cd $(rm_SRCDIR) && $(CRUNCHMAKE) $(BUILDOPTS) clean cleandepend)

rm_stub.c:
	echo "int _crunched_rm_stub(int argc, char **argv, char **envp){return main(argc,argv,envp);}" >rm_stub.c
rm.lo: rm_stub.o $(rm_OBJPATHS)
	$(CC) -nostdlib -Wl,-dc -r -o rm.lo rm_stub.o $(rm_OBJPATHS)
	crunchide -k _crunched_rm_stub rm.lo

# -------- rmdir

rmdir_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/rescue/rescue//usr/home/freebsd/omega/src/bin/rmdir
rmdir_OBJPATHS= $(rmdir_OBJDIR)/rmdir.o
rmdir_SRCDIR=/usr/home/freebsd/omega/src/rescue/rescue/../../bin/rmdir
rmdir_REALSRCDIR=/usr/home/freebsd/omega/src/bin/rmdir
rmdir_OBJS= rmdir.o
rmdir_OPTS+= DIRPRFX=rescue/rescue/rmdir/
rmdir_make:
	(cd $(rmdir_SRCDIR) && \
		$(CRUNCHMAKE) $(BUILDOPTS) $(rmdir_OPTS) depend &&\
		$(CRUNCHMAKE) $(BUILDOPTS) $(rmdir_OPTS) $(rmdir_OBJS))
rmdir_clean:
	(cd $(rmdir_SRCDIR) && $(CRUNCHMAKE) $(BUILDOPTS) clean cleandepend)

rmdir_stub.c:
	echo "int _crunched_rmdir_stub(int argc, char **argv, char **envp){return main(argc,argv,envp);}" >rmdir_stub.c
rmdir.lo: rmdir_stub.o $(rmdir_OBJPATHS)
	$(CC) -nostdlib -Wl,-dc -r -o rmdir.lo rmdir_stub.o $(rmdir_OBJPATHS)
	crunchide -k _crunched_rmdir_stub rmdir.lo

# -------- setfacl

setfacl_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/rescue/rescue//usr/home/freebsd/omega/src/bin/setfacl
setfacl_OBJPATHS= $(setfacl_OBJDIR)/file.o $(setfacl_OBJDIR)/mask.o $(setfacl_OBJDIR)/merge.o $(setfacl_OBJDIR)/remove.o $(setfacl_OBJDIR)/setfacl.o $(setfacl_OBJDIR)/util.o
setfacl_SRCDIR=/usr/home/freebsd/omega/src/rescue/rescue/../../bin/setfacl
setfacl_REALSRCDIR=/usr/home/freebsd/omega/src/bin/setfacl
setfacl_OBJS= file.o mask.o merge.o remove.o setfacl.o util.o
setfacl_OPTS+= DIRPRFX=rescue/rescue/setfacl/
setfacl_make:
	(cd $(setfacl_SRCDIR) && \
		$(CRUNCHMAKE) $(BUILDOPTS) $(setfacl_OPTS) depend &&\
		$(CRUNCHMAKE) $(BUILDOPTS) $(setfacl_OPTS) $(setfacl_OBJS))
setfacl_clean:
	(cd $(setfacl_SRCDIR) && $(CRUNCHMAKE) $(BUILDOPTS) clean cleandepend)

setfacl_stub.c:
	echo "int _crunched_setfacl_stub(int argc, char **argv, char **envp){return main(argc,argv,envp);}" >setfacl_stub.c
setfacl.lo: setfacl_stub.o $(setfacl_OBJPATHS)
	$(CC) -nostdlib -Wl,-dc -r -o setfacl.lo setfacl_stub.o $(setfacl_OBJPATHS)
	crunchide -k _crunched_setfacl_stub setfacl.lo

# -------- sh

sh_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/rescue/rescue//usr/home/freebsd/omega/src/bin/sh
sh_OBJPATHS= $(sh_OBJDIR)/alias.o $(sh_OBJDIR)/arith_yacc.o $(sh_OBJDIR)/arith_yylex.o $(sh_OBJDIR)/cd.o $(sh_OBJDIR)/echo.o $(sh_OBJDIR)/error.o $(sh_OBJDIR)/eval.o $(sh_OBJDIR)/exec.o $(sh_OBJDIR)/expand.o $(sh_OBJDIR)/histedit.o $(sh_OBJDIR)/input.o $(sh_OBJDIR)/jobs.o $(sh_OBJDIR)/kill.o $(sh_OBJDIR)/mail.o $(sh_OBJDIR)/main.o $(sh_OBJDIR)/memalloc.o $(sh_OBJDIR)/miscbltin.o $(sh_OBJDIR)/mystring.o $(sh_OBJDIR)/options.o $(sh_OBJDIR)/output.o $(sh_OBJDIR)/parser.o $(sh_OBJDIR)/printf.o $(sh_OBJDIR)/redir.o $(sh_OBJDIR)/show.o $(sh_OBJDIR)/test.o $(sh_OBJDIR)/trap.o $(sh_OBJDIR)/var.o $(sh_OBJDIR)/builtins.o $(sh_OBJDIR)/nodes.o $(sh_OBJDIR)/syntax.o
sh_SRCDIR=/usr/home/freebsd/omega/src/rescue/rescue/../../bin/sh
sh_REALSRCDIR=/usr/home/freebsd/omega/src/bin/sh
sh_OBJS= alias.o arith_yacc.o arith_yylex.o cd.o echo.o error.o eval.o exec.o expand.o histedit.o input.o jobs.o kill.o mail.o main.o memalloc.o miscbltin.o mystring.o options.o output.o parser.o printf.o redir.o show.o test.o trap.o var.o builtins.o nodes.o syntax.o
sh_OPTS+= DIRPRFX=rescue/rescue/sh/
sh_make:
	(cd $(sh_SRCDIR) && \
		$(CRUNCHMAKE) $(BUILDOPTS) $(sh_OPTS) depend &&\
		$(CRUNCHMAKE) $(BUILDOPTS) $(sh_OPTS) $(sh_OBJS))
sh_clean:
	(cd $(sh_SRCDIR) && $(CRUNCHMAKE) $(BUILDOPTS) clean cleandepend)

sh_stub.c:
	echo "int _crunched_sh_stub(int argc, char **argv, char **envp){return main(argc,argv,envp);}" >sh_stub.c
sh.lo: sh_stub.o $(sh_OBJPATHS)
	$(CC) -nostdlib -Wl,-dc -r -o sh.lo sh_stub.o $(sh_OBJPATHS)
	crunchide -k _crunched_sh_stub sh.lo

# -------- sleep

sleep_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/rescue/rescue//usr/home/freebsd/omega/src/bin/sleep
sleep_OBJPATHS= $(sleep_OBJDIR)/sleep.o
sleep_SRCDIR=/usr/home/freebsd/omega/src/rescue/rescue/../../bin/sleep
sleep_REALSRCDIR=/usr/home/freebsd/omega/src/bin/sleep
sleep_OBJS= sleep.o
sleep_OPTS+= DIRPRFX=rescue/rescue/sleep/
sleep_make:
	(cd $(sleep_SRCDIR) && \
		$(CRUNCHMAKE) $(BUILDOPTS) $(sleep_OPTS) depend &&\
		$(CRUNCHMAKE) $(BUILDOPTS) $(sleep_OPTS) $(sleep_OBJS))
sleep_clean:
	(cd $(sleep_SRCDIR) && $(CRUNCHMAKE) $(BUILDOPTS) clean cleandepend)

sleep_stub.c:
	echo "int _crunched_sleep_stub(int argc, char **argv, char **envp){return main(argc,argv,envp);}" >sleep_stub.c
sleep.lo: sleep_stub.o $(sleep_OBJPATHS)
	$(CC) -nostdlib -Wl,-dc -r -o sleep.lo sleep_stub.o $(sleep_OBJPATHS)
	crunchide -k _crunched_sleep_stub sleep.lo

# -------- stty

stty_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/rescue/rescue//usr/home/freebsd/omega/src/bin/stty
stty_OBJPATHS= $(stty_OBJDIR)/cchar.o $(stty_OBJDIR)/gfmt.o $(stty_OBJDIR)/key.o $(stty_OBJDIR)/modes.o $(stty_OBJDIR)/print.o $(stty_OBJDIR)/stty.o $(stty_OBJDIR)/util.o
stty_SRCDIR=/usr/home/freebsd/omega/src/rescue/rescue/../../bin/stty
stty_REALSRCDIR=/usr/home/freebsd/omega/src/bin/stty
stty_OBJS= cchar.o gfmt.o key.o modes.o print.o stty.o util.o
stty_OPTS+= DIRPRFX=rescue/rescue/stty/
stty_make:
	(cd $(stty_SRCDIR) && \
		$(CRUNCHMAKE) $(BUILDOPTS) $(stty_OPTS) depend &&\
		$(CRUNCHMAKE) $(BUILDOPTS) $(stty_OPTS) $(stty_OBJS))
stty_clean:
	(cd $(stty_SRCDIR) && $(CRUNCHMAKE) $(BUILDOPTS) clean cleandepend)

stty_stub.c:
	echo "int _crunched_stty_stub(int argc, char **argv, char **envp){return main(argc,argv,envp);}" >stty_stub.c
stty.lo: stty_stub.o $(stty_OBJPATHS)
	$(CC) -nostdlib -Wl,-dc -r -o stty.lo stty_stub.o $(stty_OBJPATHS)
	crunchide -k _crunched_stty_stub stty.lo

# -------- sync

sync_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/rescue/rescue//usr/home/freebsd/omega/src/bin/sync
sync_OBJPATHS= $(sync_OBJDIR)/sync.o
sync_SRCDIR=/usr/home/freebsd/omega/src/rescue/rescue/../../bin/sync
sync_REALSRCDIR=/usr/home/freebsd/omega/src/bin/sync
sync_OBJS= sync.o
sync_OPTS+= DIRPRFX=rescue/rescue/sync/
sync_make:
	(cd $(sync_SRCDIR) && \
		$(CRUNCHMAKE) $(BUILDOPTS) $(sync_OPTS) depend &&\
		$(CRUNCHMAKE) $(BUILDOPTS) $(sync_OPTS) $(sync_OBJS))
sync_clean:
	(cd $(sync_SRCDIR) && $(CRUNCHMAKE) $(BUILDOPTS) clean cleandepend)

sync_stub.c:
	echo "int _crunched_sync_stub(int argc, char **argv, char **envp){return main(argc,argv,envp);}" >sync_stub.c
sync.lo: sync_stub.o $(sync_OBJPATHS)
	$(CC) -nostdlib -Wl,-dc -r -o sync.lo sync_stub.o $(sync_OBJPATHS)
	crunchide -k _crunched_sync_stub sync.lo

# -------- test

test_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/rescue/rescue//usr/home/freebsd/omega/src/bin/test
test_OBJPATHS= $(test_OBJDIR)/test.o
test_SRCDIR=/usr/home/freebsd/omega/src/rescue/rescue/../../bin/test
test_REALSRCDIR=/usr/home/freebsd/omega/src/bin/test
test_OBJS= test.o
test_OPTS+= DIRPRFX=rescue/rescue/test/
test_make:
	(cd $(test_SRCDIR) && \
		$(CRUNCHMAKE) $(BUILDOPTS) $(test_OPTS) depend &&\
		$(CRUNCHMAKE) $(BUILDOPTS) $(test_OPTS) $(test_OBJS))
test_clean:
	(cd $(test_SRCDIR) && $(CRUNCHMAKE) $(BUILDOPTS) clean cleandepend)

test_stub.c:
	echo "int _crunched_test_stub(int argc, char **argv, char **envp){return main(argc,argv,envp);}" >test_stub.c
test.lo: test_stub.o $(test_OBJPATHS)
	$(CC) -nostdlib -Wl,-dc -r -o test.lo test_stub.o $(test_OBJPATHS)
	crunchide -k _crunched_test_stub test.lo

# -------- rcp

rcp_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/rescue/rescue//usr/home/freebsd/omega/src/bin/rcp
rcp_OBJPATHS= $(rcp_OBJDIR)/rcp.o $(rcp_OBJDIR)/util.o
rcp_SRCDIR=/usr/home/freebsd/omega/src/rescue/rescue/../../bin/rcp
rcp_REALSRCDIR=/usr/home/freebsd/omega/src/bin/rcp
rcp_OBJS= rcp.o util.o
rcp_OPTS+= DIRPRFX=rescue/rescue/rcp/
rcp_make:
	(cd $(rcp_SRCDIR) && \
		$(CRUNCHMAKE) $(BUILDOPTS) $(rcp_OPTS) depend &&\
		$(CRUNCHMAKE) $(BUILDOPTS) $(rcp_OPTS) $(rcp_OBJS))
rcp_clean:
	(cd $(rcp_SRCDIR) && $(CRUNCHMAKE) $(BUILDOPTS) clean cleandepend)

rcp_stub.c:
	echo "int _crunched_rcp_stub(int argc, char **argv, char **envp){return main(argc,argv,envp);}" >rcp_stub.c
rcp.lo: rcp_stub.o $(rcp_OBJPATHS)
	$(CC) -nostdlib -Wl,-dc -r -o rcp.lo rcp_stub.o $(rcp_OBJPATHS)
	crunchide -k _crunched_rcp_stub rcp.lo

# -------- csh

csh_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/rescue/rescue//usr/home/freebsd/omega/src/bin/csh
csh_OBJPATHS= $(csh_OBJDIR)/sh.o $(csh_OBJDIR)/sh.dir.o $(csh_OBJDIR)/sh.dol.o $(csh_OBJDIR)/sh.err.o $(csh_OBJDIR)/sh.exec.o $(csh_OBJDIR)/sh.char.o $(csh_OBJDIR)/sh.exp.o $(csh_OBJDIR)/sh.file.o $(csh_OBJDIR)/sh.func.o $(csh_OBJDIR)/sh.glob.o $(csh_OBJDIR)/sh.hist.o $(csh_OBJDIR)/sh.init.o $(csh_OBJDIR)/sh.lex.o $(csh_OBJDIR)/sh.misc.o $(csh_OBJDIR)/sh.parse.o $(csh_OBJDIR)/sh.print.o $(csh_OBJDIR)/sh.proc.o $(csh_OBJDIR)/sh.sem.o $(csh_OBJDIR)/sh.set.o $(csh_OBJDIR)/sh.time.o $(csh_OBJDIR)/glob.o $(csh_OBJDIR)/mi.termios.o $(csh_OBJDIR)/tw.help.o $(csh_OBJDIR)/tw.init.o $(csh_OBJDIR)/tw.parse.o $(csh_OBJDIR)/tw.spell.o $(csh_OBJDIR)/tw.comp.o $(csh_OBJDIR)/tw.color.o $(csh_OBJDIR)/ed.chared.o $(csh_OBJDIR)/ed.defns.o $(csh_OBJDIR)/ed.init.o $(csh_OBJDIR)/ed.inputl.o $(csh_OBJDIR)/ed.refresh.o $(csh_OBJDIR)/ed.screen.o $(csh_OBJDIR)/ed.xmap.o $(csh_OBJDIR)/ed.term.o $(csh_OBJDIR)/tc.alloc.o $(csh_OBJDIR)/tc.bind.o $(csh_OBJDIR)/tc.const.o $(csh_OBJDIR)/tc.disc.o $(csh_OBJDIR)/tc.func.o $(csh_OBJDIR)/tc.nls.o $(csh_OBJDIR)/tc.os.o $(csh_OBJDIR)/tc.printf.o $(csh_OBJDIR)/tc.prompt.o $(csh_OBJDIR)/tc.sched.o $(csh_OBJDIR)/tc.sig.o $(csh_OBJDIR)/tc.str.o $(csh_OBJDIR)/tc.vers.o $(csh_OBJDIR)/tc.who.o $(csh_OBJDIR)/tc.defs.o
csh_SRCDIR=/usr/home/freebsd/omega/src/rescue/rescue/../../bin/csh
csh_REALSRCDIR=/usr/home/freebsd/omega/src/bin/csh
csh_OBJS= sh.o sh.dir.o sh.dol.o sh.err.o sh.exec.o sh.char.o sh.exp.o sh.file.o sh.func.o sh.glob.o sh.hist.o sh.init.o sh.lex.o sh.misc.o sh.parse.o sh.print.o sh.proc.o sh.sem.o sh.set.o sh.time.o glob.o mi.termios.o tw.help.o tw.init.o tw.parse.o tw.spell.o tw.comp.o tw.color.o ed.chared.o ed.defns.o ed.init.o ed.inputl.o ed.refresh.o ed.screen.o ed.xmap.o ed.term.o tc.alloc.o tc.bind.o tc.const.o tc.disc.o tc.func.o tc.nls.o tc.os.o tc.printf.o tc.prompt.o tc.sched.o tc.sig.o tc.str.o tc.vers.o tc.who.o tc.defs.o
csh_OPTS+= DIRPRFX=rescue/rescue/csh/
csh_make:
	(cd $(csh_SRCDIR) && \
		$(CRUNCHMAKE) $(BUILDOPTS) $(csh_OPTS) depend &&\
		$(CRUNCHMAKE) $(BUILDOPTS) $(csh_OPTS) $(csh_OBJS))
csh_clean:
	(cd $(csh_SRCDIR) && $(CRUNCHMAKE) $(BUILDOPTS) clean cleandepend)

csh_stub.c:
	echo "int _crunched_csh_stub(int argc, char **argv, char **envp){return main(argc,argv,envp);}" >csh_stub.c
csh.lo: csh_stub.o $(csh_OBJPATHS)
	$(CC) -nostdlib -Wl,-dc -r -o csh.lo csh_stub.o $(csh_OBJPATHS)
	crunchide -k _crunched_csh_stub csh.lo

# -------- badsect

badsect_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/rescue/rescue//usr/home/freebsd/omega/src/sbin/badsect
badsect_OBJPATHS= $(badsect_OBJDIR)/badsect.o
badsect_SRCDIR=/usr/home/freebsd/omega/src/rescue/rescue/../../sbin/badsect
badsect_REALSRCDIR=/usr/home/freebsd/omega/src/sbin/badsect
badsect_OBJS= badsect.o
badsect_OPTS+= DIRPRFX=rescue/rescue/badsect/
badsect_make:
	(cd $(badsect_SRCDIR) && \
		$(CRUNCHMAKE) $(BUILDOPTS) $(badsect_OPTS) depend &&\
		$(CRUNCHMAKE) $(BUILDOPTS) $(badsect_OPTS) $(badsect_OBJS))
badsect_clean:
	(cd $(badsect_SRCDIR) && $(CRUNCHMAKE) $(BUILDOPTS) clean cleandepend)

badsect_stub.c:
	echo "int _crunched_badsect_stub(int argc, char **argv, char **envp){return main(argc,argv,envp);}" >badsect_stub.c
badsect.lo: badsect_stub.o $(badsect_OBJPATHS)
	$(CC) -nostdlib -Wl,-dc -r -o badsect.lo badsect_stub.o $(badsect_OBJPATHS)
	crunchide -k _crunched_badsect_stub badsect.lo

# -------- camcontrol

camcontrol_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/rescue/rescue//usr/home/freebsd/omega/src/sbin/camcontrol
camcontrol_OBJPATHS= $(camcontrol_OBJDIR)/camcontrol.o $(camcontrol_OBJDIR)/util.o $(camcontrol_OBJDIR)/attrib.o $(camcontrol_OBJDIR)/fwdownload.o $(camcontrol_OBJDIR)/modeedit.o $(camcontrol_OBJDIR)/persist.o $(camcontrol_OBJDIR)/progress.o
camcontrol_SRCDIR=/usr/home/freebsd/omega/src/rescue/rescue/../../sbin/camcontrol
camcontrol_REALSRCDIR=/usr/home/freebsd/omega/src/sbin/camcontrol
camcontrol_OBJS= camcontrol.o util.o attrib.o fwdownload.o modeedit.o persist.o progress.o
camcontrol_OPTS+= DIRPRFX=rescue/rescue/camcontrol/
camcontrol_make:
	(cd $(camcontrol_SRCDIR) && \
		$(CRUNCHMAKE) $(BUILDOPTS) $(camcontrol_OPTS) depend &&\
		$(CRUNCHMAKE) $(BUILDOPTS) $(camcontrol_OPTS) $(camcontrol_OBJS))
camcontrol_clean:
	(cd $(camcontrol_SRCDIR) && $(CRUNCHMAKE) $(BUILDOPTS) clean cleandepend)

camcontrol_stub.c:
	echo "int _crunched_camcontrol_stub(int argc, char **argv, char **envp){return main(argc,argv,envp);}" >camcontrol_stub.c
camcontrol.lo: camcontrol_stub.o $(camcontrol_OBJPATHS)
	$(CC) -nostdlib -Wl,-dc -r -o camcontrol.lo camcontrol_stub.o $(camcontrol_OBJPATHS)
	crunchide -k _crunched_camcontrol_stub camcontrol.lo

# -------- ccdconfig

ccdconfig_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/rescue/rescue//usr/home/freebsd/omega/src/sbin/ccdconfig
ccdconfig_OBJPATHS= $(ccdconfig_OBJDIR)/ccdconfig.o
ccdconfig_SRCDIR=/usr/home/freebsd/omega/src/rescue/rescue/../../sbin/ccdconfig
ccdconfig_REALSRCDIR=/usr/home/freebsd/omega/src/sbin/ccdconfig
ccdconfig_OBJS= ccdconfig.o
ccdconfig_OPTS+= DIRPRFX=rescue/rescue/ccdconfig/
ccdconfig_make:
	(cd $(ccdconfig_SRCDIR) && \
		$(CRUNCHMAKE) $(BUILDOPTS) $(ccdconfig_OPTS) depend &&\
		$(CRUNCHMAKE) $(BUILDOPTS) $(ccdconfig_OPTS) $(ccdconfig_OBJS))
ccdconfig_clean:
	(cd $(ccdconfig_SRCDIR) && $(CRUNCHMAKE) $(BUILDOPTS) clean cleandepend)

ccdconfig_stub.c:
	echo "int _crunched_ccdconfig_stub(int argc, char **argv, char **envp){return main(argc,argv,envp);}" >ccdconfig_stub.c
ccdconfig.lo: ccdconfig_stub.o $(ccdconfig_OBJPATHS)
	$(CC) -nostdlib -Wl,-dc -r -o ccdconfig.lo ccdconfig_stub.o $(ccdconfig_OBJPATHS)
	crunchide -k _crunched_ccdconfig_stub ccdconfig.lo

# -------- clri

clri_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/rescue/rescue//usr/home/freebsd/omega/src/sbin/clri
clri_OBJPATHS= $(clri_OBJDIR)/clri.o
clri_SRCDIR=/usr/home/freebsd/omega/src/rescue/rescue/../../sbin/clri
clri_REALSRCDIR=/usr/home/freebsd/omega/src/sbin/clri
clri_OBJS= clri.o
clri_OPTS+= DIRPRFX=rescue/rescue/clri/
clri_make:
	(cd $(clri_SRCDIR) && \
		$(CRUNCHMAKE) $(BUILDOPTS) $(clri_OPTS) depend &&\
		$(CRUNCHMAKE) $(BUILDOPTS) $(clri_OPTS) $(clri_OBJS))
clri_clean:
	(cd $(clri_SRCDIR) && $(CRUNCHMAKE) $(BUILDOPTS) clean cleandepend)

clri_stub.c:
	echo "int _crunched_clri_stub(int argc, char **argv, char **envp){return main(argc,argv,envp);}" >clri_stub.c
clri.lo: clri_stub.o $(clri_OBJPATHS)
	$(CC) -nostdlib -Wl,-dc -r -o clri.lo clri_stub.o $(clri_OBJPATHS)
	crunchide -k _crunched_clri_stub clri.lo

# -------- devfs

devfs_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/rescue/rescue//usr/home/freebsd/omega/src/sbin/devfs
devfs_OBJPATHS= $(devfs_OBJDIR)/devfs.o $(devfs_OBJDIR)/rule.o
devfs_SRCDIR=/usr/home/freebsd/omega/src/rescue/rescue/../../sbin/devfs
devfs_REALSRCDIR=/usr/home/freebsd/omega/src/sbin/devfs
devfs_OBJS= devfs.o rule.o
devfs_OPTS+= DIRPRFX=rescue/rescue/devfs/
devfs_make:
	(cd $(devfs_SRCDIR) && \
		$(CRUNCHMAKE) $(BUILDOPTS) $(devfs_OPTS) depend &&\
		$(CRUNCHMAKE) $(BUILDOPTS) $(devfs_OPTS) $(devfs_OBJS))
devfs_clean:
	(cd $(devfs_SRCDIR) && $(CRUNCHMAKE) $(BUILDOPTS) clean cleandepend)

devfs_stub.c:
	echo "int _crunched_devfs_stub(int argc, char **argv, char **envp){return main(argc,argv,envp);}" >devfs_stub.c
devfs.lo: devfs_stub.o $(devfs_OBJPATHS)
	$(CC) -nostdlib -Wl,-dc -r -o devfs.lo devfs_stub.o $(devfs_OBJPATHS)
	crunchide -k _crunched_devfs_stub devfs.lo

# -------- dmesg

dmesg_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/rescue/rescue//usr/home/freebsd/omega/src/sbin/dmesg
dmesg_OBJPATHS= $(dmesg_OBJDIR)/dmesg.o
dmesg_SRCDIR=/usr/home/freebsd/omega/src/rescue/rescue/../../sbin/dmesg
dmesg_REALSRCDIR=/usr/home/freebsd/omega/src/sbin/dmesg
dmesg_OBJS= dmesg.o
dmesg_OPTS+= DIRPRFX=rescue/rescue/dmesg/
dmesg_make:
	(cd $(dmesg_SRCDIR) && \
		$(CRUNCHMAKE) $(BUILDOPTS) $(dmesg_OPTS) depend &&\
		$(CRUNCHMAKE) $(BUILDOPTS) $(dmesg_OPTS) $(dmesg_OBJS))
dmesg_clean:
	(cd $(dmesg_SRCDIR) && $(CRUNCHMAKE) $(BUILDOPTS) clean cleandepend)

dmesg_stub.c:
	echo "int _crunched_dmesg_stub(int argc, char **argv, char **envp){return main(argc,argv,envp);}" >dmesg_stub.c
dmesg.lo: dmesg_stub.o $(dmesg_OBJPATHS)
	$(CC) -nostdlib -Wl,-dc -r -o dmesg.lo dmesg_stub.o $(dmesg_OBJPATHS)
	crunchide -k _crunched_dmesg_stub dmesg.lo

# -------- dump

dump_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/rescue/rescue//usr/home/freebsd/omega/src/sbin/dump
dump_OBJPATHS= $(dump_OBJDIR)/itime.o $(dump_OBJDIR)/main.o $(dump_OBJDIR)/optr.o $(dump_OBJDIR)/dumprmt.o $(dump_OBJDIR)/tape.o $(dump_OBJDIR)/traverse.o $(dump_OBJDIR)/unctime.o $(dump_OBJDIR)/cache.o
dump_SRCDIR=/usr/home/freebsd/omega/src/rescue/rescue/../../sbin/dump
dump_REALSRCDIR=/usr/home/freebsd/omega/src/sbin/dump
dump_OBJS= itime.o main.o optr.o dumprmt.o tape.o traverse.o unctime.o cache.o
dump_OPTS+= DIRPRFX=rescue/rescue/dump/
dump_make:
	(cd $(dump_SRCDIR) && \
		$(CRUNCHMAKE) $(BUILDOPTS) $(dump_OPTS) depend &&\
		$(CRUNCHMAKE) $(BUILDOPTS) $(dump_OPTS) $(dump_OBJS))
dump_clean:
	(cd $(dump_SRCDIR) && $(CRUNCHMAKE) $(BUILDOPTS) clean cleandepend)

dump_stub.c:
	echo "int _crunched_dump_stub(int argc, char **argv, char **envp){return main(argc,argv,envp);}" >dump_stub.c
dump.lo: dump_stub.o $(dump_OBJPATHS)
	$(CC) -nostdlib -Wl,-dc -r -o dump.lo dump_stub.o $(dump_OBJPATHS)
	crunchide -k _crunched_dump_stub dump.lo

# -------- dumpfs

dumpfs_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/rescue/rescue//usr/home/freebsd/omega/src/sbin/dumpfs
dumpfs_OBJPATHS= $(dumpfs_OBJDIR)/dumpfs.o
dumpfs_SRCDIR=/usr/home/freebsd/omega/src/rescue/rescue/../../sbin/dumpfs
dumpfs_REALSRCDIR=/usr/home/freebsd/omega/src/sbin/dumpfs
dumpfs_OBJS= dumpfs.o
dumpfs_OPTS+= DIRPRFX=rescue/rescue/dumpfs/
dumpfs_make:
	(cd $(dumpfs_SRCDIR) && \
		$(CRUNCHMAKE) $(BUILDOPTS) $(dumpfs_OPTS) depend &&\
		$(CRUNCHMAKE) $(BUILDOPTS) $(dumpfs_OPTS) $(dumpfs_OBJS))
dumpfs_clean:
	(cd $(dumpfs_SRCDIR) && $(CRUNCHMAKE) $(BUILDOPTS) clean cleandepend)

dumpfs_stub.c:
	echo "int _crunched_dumpfs_stub(int argc, char **argv, char **envp){return main(argc,argv,envp);}" >dumpfs_stub.c
dumpfs.lo: dumpfs_stub.o $(dumpfs_OBJPATHS)
	$(CC) -nostdlib -Wl,-dc -r -o dumpfs.lo dumpfs_stub.o $(dumpfs_OBJPATHS)
	crunchide -k _crunched_dumpfs_stub dumpfs.lo

# -------- dumpon

dumpon_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/rescue/rescue//usr/home/freebsd/omega/src/sbin/dumpon
dumpon_OBJPATHS= $(dumpon_OBJDIR)/dumpon.o
dumpon_SRCDIR=/usr/home/freebsd/omega/src/rescue/rescue/../../sbin/dumpon
dumpon_REALSRCDIR=/usr/home/freebsd/omega/src/sbin/dumpon
dumpon_OBJS= dumpon.o
dumpon_OPTS+= DIRPRFX=rescue/rescue/dumpon/
dumpon_make:
	(cd $(dumpon_SRCDIR) && \
		$(CRUNCHMAKE) $(BUILDOPTS) $(dumpon_OPTS) depend &&\
		$(CRUNCHMAKE) $(BUILDOPTS) $(dumpon_OPTS) $(dumpon_OBJS))
dumpon_clean:
	(cd $(dumpon_SRCDIR) && $(CRUNCHMAKE) $(BUILDOPTS) clean cleandepend)

dumpon_stub.c:
	echo "int _crunched_dumpon_stub(int argc, char **argv, char **envp){return main(argc,argv,envp);}" >dumpon_stub.c
dumpon.lo: dumpon_stub.o $(dumpon_OBJPATHS)
	$(CC) -nostdlib -Wl,-dc -r -o dumpon.lo dumpon_stub.o $(dumpon_OBJPATHS)
	crunchide -k _crunched_dumpon_stub dumpon.lo

# -------- fsck

fsck_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/rescue/rescue//usr/home/freebsd/omega/src/sbin/fsck
fsck_OBJPATHS= $(fsck_OBJDIR)/fsck.o $(fsck_OBJDIR)/fsutil.o $(fsck_OBJDIR)/preen.o
fsck_SRCDIR=/usr/home/freebsd/omega/src/rescue/rescue/../../sbin/fsck
fsck_REALSRCDIR=/usr/home/freebsd/omega/src/sbin/fsck
fsck_OBJS= fsck.o fsutil.o preen.o
fsck_OPTS+= DIRPRFX=rescue/rescue/fsck/
fsck_make:
	(cd $(fsck_SRCDIR) && \
		$(CRUNCHMAKE) $(BUILDOPTS) $(fsck_OPTS) depend &&\
		$(CRUNCHMAKE) $(BUILDOPTS) $(fsck_OPTS) $(fsck_OBJS))
fsck_clean:
	(cd $(fsck_SRCDIR) && $(CRUNCHMAKE) $(BUILDOPTS) clean cleandepend)

fsck_stub.c:
	echo "int _crunched_fsck_stub(int argc, char **argv, char **envp){return main(argc,argv,envp);}" >fsck_stub.c
fsck.lo: fsck_stub.o $(fsck_OBJPATHS)
	$(CC) -nostdlib -Wl,-dc -r -o fsck.lo fsck_stub.o $(fsck_OBJPATHS)
	crunchide -k _crunched_fsck_stub fsck.lo

# -------- fsck_ffs

fsck_ffs_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/rescue/rescue//usr/home/freebsd/omega/src/sbin/fsck_ffs
fsck_ffs_OBJPATHS= $(fsck_ffs_OBJDIR)/dir.o $(fsck_ffs_OBJDIR)/ea.o $(fsck_ffs_OBJDIR)/fsutil.o $(fsck_ffs_OBJDIR)/inode.o $(fsck_ffs_OBJDIR)/main.o $(fsck_ffs_OBJDIR)/pass1.o $(fsck_ffs_OBJDIR)/pass1b.o $(fsck_ffs_OBJDIR)/pass2.o $(fsck_ffs_OBJDIR)/pass3.o $(fsck_ffs_OBJDIR)/pass4.o $(fsck_ffs_OBJDIR)/pass5.o $(fsck_ffs_OBJDIR)/setup.o $(fsck_ffs_OBJDIR)/suj.o $(fsck_ffs_OBJDIR)/utilities.o $(fsck_ffs_OBJDIR)/gjournal.o $(fsck_ffs_OBJDIR)/getmntopts.o $(fsck_ffs_OBJDIR)/globs.o
fsck_ffs_SRCDIR=/usr/home/freebsd/omega/src/rescue/rescue/../../sbin/fsck_ffs
fsck_ffs_REALSRCDIR=/usr/home/freebsd/omega/src/sbin/fsck_ffs
fsck_ffs_OBJS= dir.o ea.o fsutil.o inode.o main.o pass1.o pass1b.o pass2.o pass3.o pass4.o pass5.o setup.o suj.o utilities.o gjournal.o getmntopts.o globs.o
fsck_ffs_OPTS+= DIRPRFX=rescue/rescue/fsck_ffs/
fsck_ffs_make:
	(cd $(fsck_ffs_SRCDIR) && \
		$(CRUNCHMAKE) $(BUILDOPTS) $(fsck_ffs_OPTS) depend &&\
		$(CRUNCHMAKE) $(BUILDOPTS) $(fsck_ffs_OPTS) $(fsck_ffs_OBJS))
fsck_ffs_clean:
	(cd $(fsck_ffs_SRCDIR) && $(CRUNCHMAKE) $(BUILDOPTS) clean cleandepend)

fsck_ffs_stub.c:
	echo "int _crunched_fsck_ffs_stub(int argc, char **argv, char **envp){return main(argc,argv,envp);}" >fsck_ffs_stub.c
fsck_ffs.lo: fsck_ffs_stub.o $(fsck_ffs_OBJPATHS)
	$(CC) -nostdlib -Wl,-dc -r -o fsck_ffs.lo fsck_ffs_stub.o $(fsck_ffs_OBJPATHS)
	crunchide -k _crunched_fsck_ffs_stub fsck_ffs.lo

# -------- fsck_msdosfs

fsck_msdosfs_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/rescue/rescue//usr/home/freebsd/omega/src/sbin/fsck_msdosfs
fsck_msdosfs_OBJPATHS= $(fsck_msdosfs_OBJDIR)/main.o $(fsck_msdosfs_OBJDIR)/check.o $(fsck_msdosfs_OBJDIR)/boot.o $(fsck_msdosfs_OBJDIR)/fat.o $(fsck_msdosfs_OBJDIR)/dir.o $(fsck_msdosfs_OBJDIR)/fsutil.o
fsck_msdosfs_SRCDIR=/usr/home/freebsd/omega/src/rescue/rescue/../../sbin/fsck_msdosfs
fsck_msdosfs_REALSRCDIR=/usr/home/freebsd/omega/src/sbin/fsck_msdosfs
fsck_msdosfs_OBJS= main.o check.o boot.o fat.o dir.o fsutil.o
fsck_msdosfs_OPTS+= DIRPRFX=rescue/rescue/fsck_msdosfs/
fsck_msdosfs_make:
	(cd $(fsck_msdosfs_SRCDIR) && \
		$(CRUNCHMAKE) $(BUILDOPTS) $(fsck_msdosfs_OPTS) depend &&\
		$(CRUNCHMAKE) $(BUILDOPTS) $(fsck_msdosfs_OPTS) $(fsck_msdosfs_OBJS))
fsck_msdosfs_clean:
	(cd $(fsck_msdosfs_SRCDIR) && $(CRUNCHMAKE) $(BUILDOPTS) clean cleandepend)

fsck_msdosfs_stub.c:
	echo "int _crunched_fsck_msdosfs_stub(int argc, char **argv, char **envp){return main(argc,argv,envp);}" >fsck_msdosfs_stub.c
fsck_msdosfs.lo: fsck_msdosfs_stub.o $(fsck_msdosfs_OBJPATHS)
	$(CC) -nostdlib -Wl,-dc -r -o fsck_msdosfs.lo fsck_msdosfs_stub.o $(fsck_msdosfs_OBJPATHS)
	crunchide -k _crunched_fsck_msdosfs_stub fsck_msdosfs.lo

# -------- fsdb

fsdb_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/rescue/rescue//usr/home/freebsd/omega/src/sbin/fsdb
fsdb_OBJPATHS= $(fsdb_OBJDIR)/fsdb.o $(fsdb_OBJDIR)/fsdbutil.o $(fsdb_OBJDIR)/dir.o $(fsdb_OBJDIR)/ea.o $(fsdb_OBJDIR)/fsutil.o $(fsdb_OBJDIR)/inode.o $(fsdb_OBJDIR)/pass1.o $(fsdb_OBJDIR)/pass1b.o $(fsdb_OBJDIR)/pass2.o $(fsdb_OBJDIR)/pass3.o $(fsdb_OBJDIR)/pass4.o $(fsdb_OBJDIR)/pass5.o $(fsdb_OBJDIR)/setup.o $(fsdb_OBJDIR)/utilities.o $(fsdb_OBJDIR)/ffs_subr.o $(fsdb_OBJDIR)/ffs_tables.o $(fsdb_OBJDIR)/globs.o
fsdb_SRCDIR=/usr/home/freebsd/omega/src/rescue/rescue/../../sbin/fsdb
fsdb_REALSRCDIR=/usr/home/freebsd/omega/src/sbin/fsdb
fsdb_OBJS= fsdb.o fsdbutil.o dir.o ea.o fsutil.o inode.o pass1.o pass1b.o pass2.o pass3.o pass4.o pass5.o setup.o utilities.o ffs_subr.o ffs_tables.o globs.o
fsdb_OPTS+= DIRPRFX=rescue/rescue/fsdb/
fsdb_make:
	(cd $(fsdb_SRCDIR) && \
		$(CRUNCHMAKE) $(BUILDOPTS) $(fsdb_OPTS) depend &&\
		$(CRUNCHMAKE) $(BUILDOPTS) $(fsdb_OPTS) $(fsdb_OBJS))
fsdb_clean:
	(cd $(fsdb_SRCDIR) && $(CRUNCHMAKE) $(BUILDOPTS) clean cleandepend)

fsdb_stub.c:
	echo "int _crunched_fsdb_stub(int argc, char **argv, char **envp){return main(argc,argv,envp);}" >fsdb_stub.c
fsdb.lo: fsdb_stub.o $(fsdb_OBJPATHS)
	$(CC) -nostdlib -Wl,-dc -r -o fsdb.lo fsdb_stub.o $(fsdb_OBJPATHS)
	crunchide -k _crunched_fsdb_stub fsdb.lo

# -------- fsirand

fsirand_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/rescue/rescue//usr/home/freebsd/omega/src/sbin/fsirand
fsirand_OBJPATHS= $(fsirand_OBJDIR)/fsirand.o
fsirand_SRCDIR=/usr/home/freebsd/omega/src/rescue/rescue/../../sbin/fsirand
fsirand_REALSRCDIR=/usr/home/freebsd/omega/src/sbin/fsirand
fsirand_OBJS= fsirand.o
fsirand_OPTS+= DIRPRFX=rescue/rescue/fsirand/
fsirand_make:
	(cd $(fsirand_SRCDIR) && \
		$(CRUNCHMAKE) $(BUILDOPTS) $(fsirand_OPTS) depend &&\
		$(CRUNCHMAKE) $(BUILDOPTS) $(fsirand_OPTS) $(fsirand_OBJS))
fsirand_clean:
	(cd $(fsirand_SRCDIR) && $(CRUNCHMAKE) $(BUILDOPTS) clean cleandepend)

fsirand_stub.c:
	echo "int _crunched_fsirand_stub(int argc, char **argv, char **envp){return main(argc,argv,envp);}" >fsirand_stub.c
fsirand.lo: fsirand_stub.o $(fsirand_OBJPATHS)
	$(CC) -nostdlib -Wl,-dc -r -o fsirand.lo fsirand_stub.o $(fsirand_OBJPATHS)
	crunchide -k _crunched_fsirand_stub fsirand.lo

# -------- gbde

gbde_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/rescue/rescue//usr/home/freebsd/omega/src/sbin/gbde
gbde_OBJPATHS= $(gbde_OBJDIR)/gbde.o $(gbde_OBJDIR)/template.o $(gbde_OBJDIR)/rijndael-alg-fst.o $(gbde_OBJDIR)/rijndael-api-fst.o $(gbde_OBJDIR)/sha2.o $(gbde_OBJDIR)/g_bde_lock.o
gbde_SRCDIR=/usr/home/freebsd/omega/src/rescue/rescue/../../sbin/gbde
gbde_REALSRCDIR=/usr/home/freebsd/omega/src/sbin/gbde
gbde_OBJS= gbde.o template.o rijndael-alg-fst.o rijndael-api-fst.o sha2.o g_bde_lock.o
gbde_OPTS+= DIRPRFX=rescue/rescue/gbde/
gbde_make:
	(cd $(gbde_SRCDIR) && \
		$(CRUNCHMAKE) $(BUILDOPTS) $(gbde_OPTS) depend &&\
		$(CRUNCHMAKE) $(BUILDOPTS) $(gbde_OPTS) $(gbde_OBJS))
gbde_clean:
	(cd $(gbde_SRCDIR) && $(CRUNCHMAKE) $(BUILDOPTS) clean cleandepend)

gbde_stub.c:
	echo "int _crunched_gbde_stub(int argc, char **argv, char **envp){return main(argc,argv,envp);}" >gbde_stub.c
gbde.lo: gbde_stub.o $(gbde_OBJPATHS)
	$(CC) -nostdlib -Wl,-dc -r -o gbde.lo gbde_stub.o $(gbde_OBJPATHS)
	crunchide -k _crunched_gbde_stub gbde.lo

# -------- geom

geom_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/rescue/rescue//usr/home/freebsd/omega/src/sbin/geom
geom_OBJPATHS= $(geom_OBJDIR)/geom.o $(geom_OBJDIR)/geom_label.o $(geom_OBJDIR)/geom_part.o $(geom_OBJDIR)/subr.o
geom_SRCDIR=/usr/home/freebsd/omega/src/rescue/rescue/../../sbin/geom
geom_REALSRCDIR=/usr/home/freebsd/omega/src/sbin/geom
geom_OBJS= geom.o geom_label.o geom_part.o subr.o
geom_OPTS+= DIRPRFX=rescue/rescue/geom/
geom_make:
	(cd $(geom_SRCDIR) && \
		$(CRUNCHMAKE) $(BUILDOPTS) $(geom_OPTS) depend &&\
		$(CRUNCHMAKE) $(BUILDOPTS) $(geom_OPTS) $(geom_OBJS))
geom_clean:
	(cd $(geom_SRCDIR) && $(CRUNCHMAKE) $(BUILDOPTS) clean cleandepend)

geom_stub.c:
	echo "int _crunched_geom_stub(int argc, char **argv, char **envp){return main(argc,argv,envp);}" >geom_stub.c
geom.lo: geom_stub.o $(geom_OBJPATHS)
	$(CC) -nostdlib -Wl,-dc -r -o geom.lo geom_stub.o $(geom_OBJPATHS)
	crunchide -k _crunched_geom_stub geom.lo

# -------- ifconfig

ifconfig_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/rescue/rescue//usr/home/freebsd/omega/src/sbin/ifconfig
ifconfig_OBJPATHS= $(ifconfig_OBJDIR)/ifconfig.o $(ifconfig_OBJDIR)/af_link.o $(ifconfig_OBJDIR)/af_inet.o $(ifconfig_OBJDIR)/af_inet6.o $(ifconfig_OBJDIR)/af_nd6.o $(ifconfig_OBJDIR)/ifclone.o $(ifconfig_OBJDIR)/ifmac.o $(ifconfig_OBJDIR)/ifmedia.o $(ifconfig_OBJDIR)/iffib.o $(ifconfig_OBJDIR)/ifvlan.o $(ifconfig_OBJDIR)/ifvxlan.o $(ifconfig_OBJDIR)/ifgre.o $(ifconfig_OBJDIR)/ifgif.o $(ifconfig_OBJDIR)/sfp.o $(ifconfig_OBJDIR)/ifieee80211.o $(ifconfig_OBJDIR)/carp.o $(ifconfig_OBJDIR)/ifgroup.o $(ifconfig_OBJDIR)/ifpfsync.o $(ifconfig_OBJDIR)/ifbridge.o $(ifconfig_OBJDIR)/iflagg.o
ifconfig_SRCDIR=/usr/home/freebsd/omega/src/rescue/rescue/../../sbin/ifconfig
ifconfig_REALSRCDIR=/usr/home/freebsd/omega/src/sbin/ifconfig
ifconfig_OBJS= ifconfig.o af_link.o af_inet.o af_inet6.o af_nd6.o ifclone.o ifmac.o ifmedia.o iffib.o ifvlan.o ifvxlan.o ifgre.o ifgif.o sfp.o ifieee80211.o carp.o ifgroup.o ifpfsync.o ifbridge.o iflagg.o
ifconfig_OPTS+= DIRPRFX=rescue/rescue/ifconfig/
ifconfig_make:
	(cd $(ifconfig_SRCDIR) && \
		$(CRUNCHMAKE) $(BUILDOPTS) $(ifconfig_OPTS) depend &&\
		$(CRUNCHMAKE) $(BUILDOPTS) $(ifconfig_OPTS) $(ifconfig_OBJS))
ifconfig_clean:
	(cd $(ifconfig_SRCDIR) && $(CRUNCHMAKE) $(BUILDOPTS) clean cleandepend)

ifconfig_stub.c:
	echo "int _crunched_ifconfig_stub(int argc, char **argv, char **envp){return main(argc,argv,envp);}" >ifconfig_stub.c
ifconfig.lo: ifconfig_stub.o $(ifconfig_OBJPATHS)
	$(CC) -nostdlib -Wl,-dc -r -o ifconfig.lo ifconfig_stub.o $(ifconfig_OBJPATHS)
	crunchide -k _crunched_ifconfig_stub ifconfig.lo

# -------- init

init_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/rescue/rescue//usr/home/freebsd/omega/src/sbin/init
init_OBJPATHS= $(init_OBJDIR)/init.o $(init_OBJDIR)/getmntopts.o
init_SRCDIR=/usr/home/freebsd/omega/src/rescue/rescue/../../sbin/init
init_REALSRCDIR=/usr/home/freebsd/omega/src/sbin/init
init_OBJS= init.o getmntopts.o
init_OPTS+= DIRPRFX=rescue/rescue/init/
init_make:
	(cd $(init_SRCDIR) && \
		$(CRUNCHMAKE) $(BUILDOPTS) $(init_OPTS) depend &&\
		$(CRUNCHMAKE) $(BUILDOPTS) $(init_OPTS) $(init_OBJS))
init_clean:
	(cd $(init_SRCDIR) && $(CRUNCHMAKE) $(BUILDOPTS) clean cleandepend)

init_stub.c:
	echo "int _crunched_init_stub(int argc, char **argv, char **envp){return main(argc,argv,envp);}" >init_stub.c
init.lo: init_stub.o $(init_OBJPATHS)
	$(CC) -nostdlib -Wl,-dc -r -o init.lo init_stub.o $(init_OBJPATHS)
	crunchide -k _crunched_init_stub init.lo

# -------- kldconfig

kldconfig_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/rescue/rescue//usr/home/freebsd/omega/src/sbin/kldconfig
kldconfig_OBJPATHS= $(kldconfig_OBJDIR)/kldconfig.o
kldconfig_SRCDIR=/usr/home/freebsd/omega/src/rescue/rescue/../../sbin/kldconfig
kldconfig_REALSRCDIR=/usr/home/freebsd/omega/src/sbin/kldconfig
kldconfig_OBJS= kldconfig.o
kldconfig_OPTS+= DIRPRFX=rescue/rescue/kldconfig/
kldconfig_make:
	(cd $(kldconfig_SRCDIR) && \
		$(CRUNCHMAKE) $(BUILDOPTS) $(kldconfig_OPTS) depend &&\
		$(CRUNCHMAKE) $(BUILDOPTS) $(kldconfig_OPTS) $(kldconfig_OBJS))
kldconfig_clean:
	(cd $(kldconfig_SRCDIR) && $(CRUNCHMAKE) $(BUILDOPTS) clean cleandepend)

kldconfig_stub.c:
	echo "int _crunched_kldconfig_stub(int argc, char **argv, char **envp){return main(argc,argv,envp);}" >kldconfig_stub.c
kldconfig.lo: kldconfig_stub.o $(kldconfig_OBJPATHS)
	$(CC) -nostdlib -Wl,-dc -r -o kldconfig.lo kldconfig_stub.o $(kldconfig_OBJPATHS)
	crunchide -k _crunched_kldconfig_stub kldconfig.lo

# -------- kldload

kldload_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/rescue/rescue//usr/home/freebsd/omega/src/sbin/kldload
kldload_OBJPATHS= $(kldload_OBJDIR)/kldload.o
kldload_SRCDIR=/usr/home/freebsd/omega/src/rescue/rescue/../../sbin/kldload
kldload_REALSRCDIR=/usr/home/freebsd/omega/src/sbin/kldload
kldload_OBJS= kldload.o
kldload_OPTS+= DIRPRFX=rescue/rescue/kldload/
kldload_make:
	(cd $(kldload_SRCDIR) && \
		$(CRUNCHMAKE) $(BUILDOPTS) $(kldload_OPTS) depend &&\
		$(CRUNCHMAKE) $(BUILDOPTS) $(kldload_OPTS) $(kldload_OBJS))
kldload_clean:
	(cd $(kldload_SRCDIR) && $(CRUNCHMAKE) $(BUILDOPTS) clean cleandepend)

kldload_stub.c:
	echo "int _crunched_kldload_stub(int argc, char **argv, char **envp){return main(argc,argv,envp);}" >kldload_stub.c
kldload.lo: kldload_stub.o $(kldload_OBJPATHS)
	$(CC) -nostdlib -Wl,-dc -r -o kldload.lo kldload_stub.o $(kldload_OBJPATHS)
	crunchide -k _crunched_kldload_stub kldload.lo

# -------- kldstat

kldstat_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/rescue/rescue//usr/home/freebsd/omega/src/sbin/kldstat
kldstat_OBJPATHS= $(kldstat_OBJDIR)/kldstat.o
kldstat_SRCDIR=/usr/home/freebsd/omega/src/rescue/rescue/../../sbin/kldstat
kldstat_REALSRCDIR=/usr/home/freebsd/omega/src/sbin/kldstat
kldstat_OBJS= kldstat.o
kldstat_OPTS+= DIRPRFX=rescue/rescue/kldstat/
kldstat_make:
	(cd $(kldstat_SRCDIR) && \
		$(CRUNCHMAKE) $(BUILDOPTS) $(kldstat_OPTS) depend &&\
		$(CRUNCHMAKE) $(BUILDOPTS) $(kldstat_OPTS) $(kldstat_OBJS))
kldstat_clean:
	(cd $(kldstat_SRCDIR) && $(CRUNCHMAKE) $(BUILDOPTS) clean cleandepend)

kldstat_stub.c:
	echo "int _crunched_kldstat_stub(int argc, char **argv, char **envp){return main(argc,argv,envp);}" >kldstat_stub.c
kldstat.lo: kldstat_stub.o $(kldstat_OBJPATHS)
	$(CC) -nostdlib -Wl,-dc -r -o kldstat.lo kldstat_stub.o $(kldstat_OBJPATHS)
	crunchide -k _crunched_kldstat_stub kldstat.lo

# -------- kldunload

kldunload_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/rescue/rescue//usr/home/freebsd/omega/src/sbin/kldunload
kldunload_OBJPATHS= $(kldunload_OBJDIR)/kldunload.o
kldunload_SRCDIR=/usr/home/freebsd/omega/src/rescue/rescue/../../sbin/kldunload
kldunload_REALSRCDIR=/usr/home/freebsd/omega/src/sbin/kldunload
kldunload_OBJS= kldunload.o
kldunload_OPTS+= DIRPRFX=rescue/rescue/kldunload/
kldunload_make:
	(cd $(kldunload_SRCDIR) && \
		$(CRUNCHMAKE) $(BUILDOPTS) $(kldunload_OPTS) depend &&\
		$(CRUNCHMAKE) $(BUILDOPTS) $(kldunload_OPTS) $(kldunload_OBJS))
kldunload_clean:
	(cd $(kldunload_SRCDIR) && $(CRUNCHMAKE) $(BUILDOPTS) clean cleandepend)

kldunload_stub.c:
	echo "int _crunched_kldunload_stub(int argc, char **argv, char **envp){return main(argc,argv,envp);}" >kldunload_stub.c
kldunload.lo: kldunload_stub.o $(kldunload_OBJPATHS)
	$(CC) -nostdlib -Wl,-dc -r -o kldunload.lo kldunload_stub.o $(kldunload_OBJPATHS)
	crunchide -k _crunched_kldunload_stub kldunload.lo

# -------- ldconfig

ldconfig_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/rescue/rescue//usr/home/freebsd/omega/src/sbin/ldconfig
ldconfig_OBJPATHS= $(ldconfig_OBJDIR)/elfhints.o $(ldconfig_OBJDIR)/ldconfig.o $(ldconfig_OBJDIR)/shlib.o $(ldconfig_OBJDIR)/support.o
ldconfig_SRCDIR=/usr/home/freebsd/omega/src/rescue/rescue/../../sbin/ldconfig
ldconfig_REALSRCDIR=/usr/home/freebsd/omega/src/sbin/ldconfig
ldconfig_OBJS= elfhints.o ldconfig.o shlib.o support.o
ldconfig_OPTS+= DIRPRFX=rescue/rescue/ldconfig/
ldconfig_make:
	(cd $(ldconfig_SRCDIR) && \
		$(CRUNCHMAKE) $(BUILDOPTS) $(ldconfig_OPTS) depend &&\
		$(CRUNCHMAKE) $(BUILDOPTS) $(ldconfig_OPTS) $(ldconfig_OBJS))
ldconfig_clean:
	(cd $(ldconfig_SRCDIR) && $(CRUNCHMAKE) $(BUILDOPTS) clean cleandepend)

ldconfig_stub.c:
	echo "int _crunched_ldconfig_stub(int argc, char **argv, char **envp){return main(argc,argv,envp);}" >ldconfig_stub.c
ldconfig.lo: ldconfig_stub.o $(ldconfig_OBJPATHS)
	$(CC) -nostdlib -Wl,-dc -r -o ldconfig.lo ldconfig_stub.o $(ldconfig_OBJPATHS)
	crunchide -k _crunched_ldconfig_stub ldconfig.lo

# -------- md5

md5_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/rescue/rescue//usr/home/freebsd/omega/src/sbin/md5
md5_OBJPATHS= $(md5_OBJDIR)/md5.o
md5_SRCDIR=/usr/home/freebsd/omega/src/rescue/rescue/../../sbin/md5
md5_REALSRCDIR=/usr/home/freebsd/omega/src/sbin/md5
md5_OBJS= md5.o
md5_OPTS+= DIRPRFX=rescue/rescue/md5/
md5_make:
	(cd $(md5_SRCDIR) && \
		$(CRUNCHMAKE) $(BUILDOPTS) $(md5_OPTS) depend &&\
		$(CRUNCHMAKE) $(BUILDOPTS) $(md5_OPTS) $(md5_OBJS))
md5_clean:
	(cd $(md5_SRCDIR) && $(CRUNCHMAKE) $(BUILDOPTS) clean cleandepend)

md5_stub.c:
	echo "int _crunched_md5_stub(int argc, char **argv, char **envp){return main(argc,argv,envp);}" >md5_stub.c
md5.lo: md5_stub.o $(md5_OBJPATHS)
	$(CC) -nostdlib -Wl,-dc -r -o md5.lo md5_stub.o $(md5_OBJPATHS)
	crunchide -k _crunched_md5_stub md5.lo

# -------- mdconfig

mdconfig_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/rescue/rescue//usr/home/freebsd/omega/src/sbin/mdconfig
mdconfig_OBJPATHS= $(mdconfig_OBJDIR)/mdconfig.o
mdconfig_SRCDIR=/usr/home/freebsd/omega/src/rescue/rescue/../../sbin/mdconfig
mdconfig_REALSRCDIR=/usr/home/freebsd/omega/src/sbin/mdconfig
mdconfig_OBJS= mdconfig.o
mdconfig_OPTS+= DIRPRFX=rescue/rescue/mdconfig/
mdconfig_make:
	(cd $(mdconfig_SRCDIR) && \
		$(CRUNCHMAKE) $(BUILDOPTS) $(mdconfig_OPTS) depend &&\
		$(CRUNCHMAKE) $(BUILDOPTS) $(mdconfig_OPTS) $(mdconfig_OBJS))
mdconfig_clean:
	(cd $(mdconfig_SRCDIR) && $(CRUNCHMAKE) $(BUILDOPTS) clean cleandepend)

mdconfig_stub.c:
	echo "int _crunched_mdconfig_stub(int argc, char **argv, char **envp){return main(argc,argv,envp);}" >mdconfig_stub.c
mdconfig.lo: mdconfig_stub.o $(mdconfig_OBJPATHS)
	$(CC) -nostdlib -Wl,-dc -r -o mdconfig.lo mdconfig_stub.o $(mdconfig_OBJPATHS)
	crunchide -k _crunched_mdconfig_stub mdconfig.lo

# -------- mdmfs

mdmfs_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/rescue/rescue//usr/home/freebsd/omega/src/sbin/mdmfs
mdmfs_OBJPATHS= $(mdmfs_OBJDIR)/mdmfs.o
mdmfs_SRCDIR=/usr/home/freebsd/omega/src/rescue/rescue/../../sbin/mdmfs
mdmfs_REALSRCDIR=/usr/home/freebsd/omega/src/sbin/mdmfs
mdmfs_OBJS= mdmfs.o
mdmfs_OPTS+= DIRPRFX=rescue/rescue/mdmfs/
mdmfs_make:
	(cd $(mdmfs_SRCDIR) && \
		$(CRUNCHMAKE) $(BUILDOPTS) $(mdmfs_OPTS) depend &&\
		$(CRUNCHMAKE) $(BUILDOPTS) $(mdmfs_OPTS) $(mdmfs_OBJS))
mdmfs_clean:
	(cd $(mdmfs_SRCDIR) && $(CRUNCHMAKE) $(BUILDOPTS) clean cleandepend)

mdmfs_stub.c:
	echo "int _crunched_mdmfs_stub(int argc, char **argv, char **envp){return main(argc,argv,envp);}" >mdmfs_stub.c
mdmfs.lo: mdmfs_stub.o $(mdmfs_OBJPATHS)
	$(CC) -nostdlib -Wl,-dc -r -o mdmfs.lo mdmfs_stub.o $(mdmfs_OBJPATHS)
	crunchide -k _crunched_mdmfs_stub mdmfs.lo

# -------- mknod

mknod_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/rescue/rescue//usr/home/freebsd/omega/src/sbin/mknod
mknod_OBJPATHS= $(mknod_OBJDIR)/mknod.o
mknod_SRCDIR=/usr/home/freebsd/omega/src/rescue/rescue/../../sbin/mknod
mknod_REALSRCDIR=/usr/home/freebsd/omega/src/sbin/mknod
mknod_OBJS= mknod.o
mknod_OPTS+= DIRPRFX=rescue/rescue/mknod/
mknod_make:
	(cd $(mknod_SRCDIR) && \
		$(CRUNCHMAKE) $(BUILDOPTS) $(mknod_OPTS) depend &&\
		$(CRUNCHMAKE) $(BUILDOPTS) $(mknod_OPTS) $(mknod_OBJS))
mknod_clean:
	(cd $(mknod_SRCDIR) && $(CRUNCHMAKE) $(BUILDOPTS) clean cleandepend)

mknod_stub.c:
	echo "int _crunched_mknod_stub(int argc, char **argv, char **envp){return main(argc,argv,envp);}" >mknod_stub.c
mknod.lo: mknod_stub.o $(mknod_OBJPATHS)
	$(CC) -nostdlib -Wl,-dc -r -o mknod.lo mknod_stub.o $(mknod_OBJPATHS)
	crunchide -k _crunched_mknod_stub mknod.lo

# -------- mount

mount_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/rescue/rescue//usr/home/freebsd/omega/src/sbin/mount
mount_OBJPATHS= $(mount_OBJDIR)/mount.o $(mount_OBJDIR)/mount_fs.o $(mount_OBJDIR)/getmntopts.o $(mount_OBJDIR)/vfslist.o
mount_SRCDIR=/usr/home/freebsd/omega/src/rescue/rescue/../../sbin/mount
mount_REALSRCDIR=/usr/home/freebsd/omega/src/sbin/mount
mount_OBJS= mount.o mount_fs.o getmntopts.o vfslist.o
mount_OPTS+= DIRPRFX=rescue/rescue/mount/
mount_make:
	(cd $(mount_SRCDIR) && \
		$(CRUNCHMAKE) $(BUILDOPTS) $(mount_OPTS) depend &&\
		$(CRUNCHMAKE) $(BUILDOPTS) $(mount_OPTS) $(mount_OBJS))
mount_clean:
	(cd $(mount_SRCDIR) && $(CRUNCHMAKE) $(BUILDOPTS) clean cleandepend)

mount_stub.c:
	echo "int _crunched_mount_stub(int argc, char **argv, char **envp){return main(argc,argv,envp);}" >mount_stub.c
mount.lo: mount_stub.o $(mount_OBJPATHS)
	$(CC) -nostdlib -Wl,-dc -r -o mount.lo mount_stub.o $(mount_OBJPATHS)
	crunchide -k _crunched_mount_stub mount.lo

# -------- mount_cd9660

mount_cd9660_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/rescue/rescue//usr/home/freebsd/omega/src/sbin/mount_cd9660
mount_cd9660_OBJPATHS= $(mount_cd9660_OBJDIR)/mount_cd9660.o $(mount_cd9660_OBJDIR)/getmntopts.o
mount_cd9660_SRCDIR=/usr/home/freebsd/omega/src/rescue/rescue/../../sbin/mount_cd9660
mount_cd9660_REALSRCDIR=/usr/home/freebsd/omega/src/sbin/mount_cd9660
mount_cd9660_OBJS= mount_cd9660.o getmntopts.o
mount_cd9660_OPTS+= DIRPRFX=rescue/rescue/mount_cd9660/
mount_cd9660_make:
	(cd $(mount_cd9660_SRCDIR) && \
		$(CRUNCHMAKE) $(BUILDOPTS) $(mount_cd9660_OPTS) depend &&\
		$(CRUNCHMAKE) $(BUILDOPTS) $(mount_cd9660_OPTS) $(mount_cd9660_OBJS))
mount_cd9660_clean:
	(cd $(mount_cd9660_SRCDIR) && $(CRUNCHMAKE) $(BUILDOPTS) clean cleandepend)

mount_cd9660_stub.c:
	echo "int _crunched_mount_cd9660_stub(int argc, char **argv, char **envp){return main(argc,argv,envp);}" >mount_cd9660_stub.c
mount_cd9660.lo: mount_cd9660_stub.o $(mount_cd9660_OBJPATHS)
	$(CC) -nostdlib -Wl,-dc -r -o mount_cd9660.lo mount_cd9660_stub.o $(mount_cd9660_OBJPATHS)
	crunchide -k _crunched_mount_cd9660_stub mount_cd9660.lo

# -------- mount_msdosfs

mount_msdosfs_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/rescue/rescue//usr/home/freebsd/omega/src/sbin/mount_msdosfs
mount_msdosfs_OBJPATHS= $(mount_msdosfs_OBJDIR)/mount_msdosfs.o $(mount_msdosfs_OBJDIR)/getmntopts.o
mount_msdosfs_SRCDIR=/usr/home/freebsd/omega/src/rescue/rescue/../../sbin/mount_msdosfs
mount_msdosfs_REALSRCDIR=/usr/home/freebsd/omega/src/sbin/mount_msdosfs
mount_msdosfs_OBJS= mount_msdosfs.o getmntopts.o
mount_msdosfs_OPTS+= DIRPRFX=rescue/rescue/mount_msdosfs/
mount_msdosfs_make:
	(cd $(mount_msdosfs_SRCDIR) && \
		$(CRUNCHMAKE) $(BUILDOPTS) $(mount_msdosfs_OPTS) depend &&\
		$(CRUNCHMAKE) $(BUILDOPTS) $(mount_msdosfs_OPTS) $(mount_msdosfs_OBJS))
mount_msdosfs_clean:
	(cd $(mount_msdosfs_SRCDIR) && $(CRUNCHMAKE) $(BUILDOPTS) clean cleandepend)

mount_msdosfs_stub.c:
	echo "int _crunched_mount_msdosfs_stub(int argc, char **argv, char **envp){return main(argc,argv,envp);}" >mount_msdosfs_stub.c
mount_msdosfs.lo: mount_msdosfs_stub.o $(mount_msdosfs_OBJPATHS)
	$(CC) -nostdlib -Wl,-dc -r -o mount_msdosfs.lo mount_msdosfs_stub.o $(mount_msdosfs_OBJPATHS)
	crunchide -k _crunched_mount_msdosfs_stub mount_msdosfs.lo

# -------- mount_nfs

mount_nfs_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/rescue/rescue//usr/home/freebsd/omega/src/sbin/mount_nfs
mount_nfs_OBJPATHS= $(mount_nfs_OBJDIR)/mount_nfs.o $(mount_nfs_OBJDIR)/getmntopts.o $(mount_nfs_OBJDIR)/mounttab.o
mount_nfs_SRCDIR=/usr/home/freebsd/omega/src/rescue/rescue/../../sbin/mount_nfs
mount_nfs_REALSRCDIR=/usr/home/freebsd/omega/src/sbin/mount_nfs
mount_nfs_OBJS= mount_nfs.o getmntopts.o mounttab.o
mount_nfs_OPTS+= DIRPRFX=rescue/rescue/mount_nfs/
mount_nfs_make:
	(cd $(mount_nfs_SRCDIR) && \
		$(CRUNCHMAKE) $(BUILDOPTS) $(mount_nfs_OPTS) depend &&\
		$(CRUNCHMAKE) $(BUILDOPTS) $(mount_nfs_OPTS) $(mount_nfs_OBJS))
mount_nfs_clean:
	(cd $(mount_nfs_SRCDIR) && $(CRUNCHMAKE) $(BUILDOPTS) clean cleandepend)

mount_nfs_stub.c:
	echo "int _crunched_mount_nfs_stub(int argc, char **argv, char **envp){return main(argc,argv,envp);}" >mount_nfs_stub.c
mount_nfs.lo: mount_nfs_stub.o $(mount_nfs_OBJPATHS)
	$(CC) -nostdlib -Wl,-dc -r -o mount_nfs.lo mount_nfs_stub.o $(mount_nfs_OBJPATHS)
	crunchide -k _crunched_mount_nfs_stub mount_nfs.lo

# -------- mount_nullfs

mount_nullfs_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/rescue/rescue//usr/home/freebsd/omega/src/sbin/mount_nullfs
mount_nullfs_OBJPATHS= $(mount_nullfs_OBJDIR)/mount_nullfs.o $(mount_nullfs_OBJDIR)/getmntopts.o
mount_nullfs_SRCDIR=/usr/home/freebsd/omega/src/rescue/rescue/../../sbin/mount_nullfs
mount_nullfs_REALSRCDIR=/usr/home/freebsd/omega/src/sbin/mount_nullfs
mount_nullfs_OBJS= mount_nullfs.o getmntopts.o
mount_nullfs_OPTS+= DIRPRFX=rescue/rescue/mount_nullfs/
mount_nullfs_make:
	(cd $(mount_nullfs_SRCDIR) && \
		$(CRUNCHMAKE) $(BUILDOPTS) $(mount_nullfs_OPTS) depend &&\
		$(CRUNCHMAKE) $(BUILDOPTS) $(mount_nullfs_OPTS) $(mount_nullfs_OBJS))
mount_nullfs_clean:
	(cd $(mount_nullfs_SRCDIR) && $(CRUNCHMAKE) $(BUILDOPTS) clean cleandepend)

mount_nullfs_stub.c:
	echo "int _crunched_mount_nullfs_stub(int argc, char **argv, char **envp){return main(argc,argv,envp);}" >mount_nullfs_stub.c
mount_nullfs.lo: mount_nullfs_stub.o $(mount_nullfs_OBJPATHS)
	$(CC) -nostdlib -Wl,-dc -r -o mount_nullfs.lo mount_nullfs_stub.o $(mount_nullfs_OBJPATHS)
	crunchide -k _crunched_mount_nullfs_stub mount_nullfs.lo

# -------- mount_udf

mount_udf_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/rescue/rescue//usr/home/freebsd/omega/src/sbin/mount_udf
mount_udf_OBJPATHS= $(mount_udf_OBJDIR)/mount_udf.o $(mount_udf_OBJDIR)/getmntopts.o
mount_udf_SRCDIR=/usr/home/freebsd/omega/src/rescue/rescue/../../sbin/mount_udf
mount_udf_REALSRCDIR=/usr/home/freebsd/omega/src/sbin/mount_udf
mount_udf_OBJS= mount_udf.o getmntopts.o
mount_udf_OPTS+= DIRPRFX=rescue/rescue/mount_udf/
mount_udf_make:
	(cd $(mount_udf_SRCDIR) && \
		$(CRUNCHMAKE) $(BUILDOPTS) $(mount_udf_OPTS) depend &&\
		$(CRUNCHMAKE) $(BUILDOPTS) $(mount_udf_OPTS) $(mount_udf_OBJS))
mount_udf_clean:
	(cd $(mount_udf_SRCDIR) && $(CRUNCHMAKE) $(BUILDOPTS) clean cleandepend)

mount_udf_stub.c:
	echo "int _crunched_mount_udf_stub(int argc, char **argv, char **envp){return main(argc,argv,envp);}" >mount_udf_stub.c
mount_udf.lo: mount_udf_stub.o $(mount_udf_OBJPATHS)
	$(CC) -nostdlib -Wl,-dc -r -o mount_udf.lo mount_udf_stub.o $(mount_udf_OBJPATHS)
	crunchide -k _crunched_mount_udf_stub mount_udf.lo

# -------- mount_unionfs

mount_unionfs_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/rescue/rescue//usr/home/freebsd/omega/src/sbin/mount_unionfs
mount_unionfs_OBJPATHS= $(mount_unionfs_OBJDIR)/mount_unionfs.o $(mount_unionfs_OBJDIR)/getmntopts.o
mount_unionfs_SRCDIR=/usr/home/freebsd/omega/src/rescue/rescue/../../sbin/mount_unionfs
mount_unionfs_REALSRCDIR=/usr/home/freebsd/omega/src/sbin/mount_unionfs
mount_unionfs_OBJS= mount_unionfs.o getmntopts.o
mount_unionfs_OPTS+= DIRPRFX=rescue/rescue/mount_unionfs/
mount_unionfs_make:
	(cd $(mount_unionfs_SRCDIR) && \
		$(CRUNCHMAKE) $(BUILDOPTS) $(mount_unionfs_OPTS) depend &&\
		$(CRUNCHMAKE) $(BUILDOPTS) $(mount_unionfs_OPTS) $(mount_unionfs_OBJS))
mount_unionfs_clean:
	(cd $(mount_unionfs_SRCDIR) && $(CRUNCHMAKE) $(BUILDOPTS) clean cleandepend)

mount_unionfs_stub.c:
	echo "int _crunched_mount_unionfs_stub(int argc, char **argv, char **envp){return main(argc,argv,envp);}" >mount_unionfs_stub.c
mount_unionfs.lo: mount_unionfs_stub.o $(mount_unionfs_OBJPATHS)
	$(CC) -nostdlib -Wl,-dc -r -o mount_unionfs.lo mount_unionfs_stub.o $(mount_unionfs_OBJPATHS)
	crunchide -k _crunched_mount_unionfs_stub mount_unionfs.lo

# -------- newfs

newfs_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/rescue/rescue//usr/home/freebsd/omega/src/sbin/newfs
newfs_OBJPATHS= $(newfs_OBJDIR)/newfs.o $(newfs_OBJDIR)/mkfs.o $(newfs_OBJDIR)/geom_bsd_enc.o
newfs_SRCDIR=/usr/home/freebsd/omega/src/rescue/rescue/../../sbin/newfs
newfs_REALSRCDIR=/usr/home/freebsd/omega/src/sbin/newfs
newfs_OBJS= newfs.o mkfs.o geom_bsd_enc.o
newfs_OPTS+= DIRPRFX=rescue/rescue/newfs/
newfs_make:
	(cd $(newfs_SRCDIR) && \
		$(CRUNCHMAKE) $(BUILDOPTS) $(newfs_OPTS) depend &&\
		$(CRUNCHMAKE) $(BUILDOPTS) $(newfs_OPTS) $(newfs_OBJS))
newfs_clean:
	(cd $(newfs_SRCDIR) && $(CRUNCHMAKE) $(BUILDOPTS) clean cleandepend)

newfs_stub.c:
	echo "int _crunched_newfs_stub(int argc, char **argv, char **envp){return main(argc,argv,envp);}" >newfs_stub.c
newfs.lo: newfs_stub.o $(newfs_OBJPATHS)
	$(CC) -nostdlib -Wl,-dc -r -o newfs.lo newfs_stub.o $(newfs_OBJPATHS)
	crunchide -k _crunched_newfs_stub newfs.lo

# -------- newfs_msdos

newfs_msdos_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/rescue/rescue//usr/home/freebsd/omega/src/sbin/newfs_msdos
newfs_msdos_OBJPATHS= $(newfs_msdos_OBJDIR)/newfs_msdos.o $(newfs_msdos_OBJDIR)/mkfs_msdos.o
newfs_msdos_SRCDIR=/usr/home/freebsd/omega/src/rescue/rescue/../../sbin/newfs_msdos
newfs_msdos_REALSRCDIR=/usr/home/freebsd/omega/src/sbin/newfs_msdos
newfs_msdos_OBJS= newfs_msdos.o mkfs_msdos.o
newfs_msdos_OPTS+= DIRPRFX=rescue/rescue/newfs_msdos/
newfs_msdos_make:
	(cd $(newfs_msdos_SRCDIR) && \
		$(CRUNCHMAKE) $(BUILDOPTS) $(newfs_msdos_OPTS) depend &&\
		$(CRUNCHMAKE) $(BUILDOPTS) $(newfs_msdos_OPTS) $(newfs_msdos_OBJS))
newfs_msdos_clean:
	(cd $(newfs_msdos_SRCDIR) && $(CRUNCHMAKE) $(BUILDOPTS) clean cleandepend)

newfs_msdos_stub.c:
	echo "int _crunched_newfs_msdos_stub(int argc, char **argv, char **envp){return main(argc,argv,envp);}" >newfs_msdos_stub.c
newfs_msdos.lo: newfs_msdos_stub.o $(newfs_msdos_OBJPATHS)
	$(CC) -nostdlib -Wl,-dc -r -o newfs_msdos.lo newfs_msdos_stub.o $(newfs_msdos_OBJPATHS)
	crunchide -k _crunched_newfs_msdos_stub newfs_msdos.lo

# -------- nos-tun

nos_tun_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/rescue/rescue//usr/home/freebsd/omega/src/sbin/nos-tun
nos_tun_OBJPATHS= $(nos_tun_OBJDIR)/nos-tun.o
nos_tun_SRCDIR=/usr/home/freebsd/omega/src/rescue/rescue/../../sbin/nos-tun
nos_tun_REALSRCDIR=/usr/home/freebsd/omega/src/sbin/nos-tun
nos_tun_OBJS= nos-tun.o
nos_tun_OPTS+= DIRPRFX=rescue/rescue/nos-tun/
nos_tun_make:
	(cd $(nos_tun_SRCDIR) && \
		$(CRUNCHMAKE) $(BUILDOPTS) $(nos_tun_OPTS) depend &&\
		$(CRUNCHMAKE) $(BUILDOPTS) $(nos_tun_OPTS) $(nos_tun_OBJS))
nos_tun_clean:
	(cd $(nos_tun_SRCDIR) && $(CRUNCHMAKE) $(BUILDOPTS) clean cleandepend)

nos-tun_stub.c:
	echo "int _crunched_nos_tun_stub(int argc, char **argv, char **envp){return main(argc,argv,envp);}" >nos-tun_stub.c
nos-tun.lo: nos-tun_stub.o $(nos_tun_OBJPATHS)
	$(CC) -nostdlib -Wl,-dc -r -o nos-tun.lo nos-tun_stub.o $(nos_tun_OBJPATHS)
	crunchide -k _crunched_nos_tun_stub nos-tun.lo

# -------- ping

ping_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/rescue/rescue//usr/home/freebsd/omega/src/sbin/ping
ping_OBJPATHS= $(ping_OBJDIR)/ping.o
ping_SRCDIR=/usr/home/freebsd/omega/src/rescue/rescue/../../sbin/ping
ping_REALSRCDIR=/usr/home/freebsd/omega/src/sbin/ping
ping_OBJS= ping.o
ping_OPTS+= DIRPRFX=rescue/rescue/ping/
ping_make:
	(cd $(ping_SRCDIR) && \
		$(CRUNCHMAKE) $(BUILDOPTS) $(ping_OPTS) depend &&\
		$(CRUNCHMAKE) $(BUILDOPTS) $(ping_OPTS) $(ping_OBJS))
ping_clean:
	(cd $(ping_SRCDIR) && $(CRUNCHMAKE) $(BUILDOPTS) clean cleandepend)

ping_stub.c:
	echo "int _crunched_ping_stub(int argc, char **argv, char **envp){return main(argc,argv,envp);}" >ping_stub.c
ping.lo: ping_stub.o $(ping_OBJPATHS)
	$(CC) -nostdlib -Wl,-dc -r -o ping.lo ping_stub.o $(ping_OBJPATHS)
	crunchide -k _crunched_ping_stub ping.lo

# -------- reboot

reboot_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/rescue/rescue//usr/home/freebsd/omega/src/sbin/reboot
reboot_OBJPATHS= $(reboot_OBJDIR)/reboot.o
reboot_SRCDIR=/usr/home/freebsd/omega/src/rescue/rescue/../../sbin/reboot
reboot_REALSRCDIR=/usr/home/freebsd/omega/src/sbin/reboot
reboot_OBJS= reboot.o
reboot_OPTS+= DIRPRFX=rescue/rescue/reboot/
reboot_make:
	(cd $(reboot_SRCDIR) && \
		$(CRUNCHMAKE) $(BUILDOPTS) $(reboot_OPTS) depend &&\
		$(CRUNCHMAKE) $(BUILDOPTS) $(reboot_OPTS) $(reboot_OBJS))
reboot_clean:
	(cd $(reboot_SRCDIR) && $(CRUNCHMAKE) $(BUILDOPTS) clean cleandepend)

reboot_stub.c:
	echo "int _crunched_reboot_stub(int argc, char **argv, char **envp){return main(argc,argv,envp);}" >reboot_stub.c
reboot.lo: reboot_stub.o $(reboot_OBJPATHS)
	$(CC) -nostdlib -Wl,-dc -r -o reboot.lo reboot_stub.o $(reboot_OBJPATHS)
	crunchide -k _crunched_reboot_stub reboot.lo

# -------- restore

restore_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/rescue/rescue//usr/home/freebsd/omega/src/sbin/restore
restore_OBJPATHS= $(restore_OBJDIR)/main.o $(restore_OBJDIR)/interactive.o $(restore_OBJDIR)/restore.o $(restore_OBJDIR)/dirs.o $(restore_OBJDIR)/symtab.o $(restore_OBJDIR)/tape.o $(restore_OBJDIR)/utilities.o $(restore_OBJDIR)/dumprmt.o
restore_SRCDIR=/usr/home/freebsd/omega/src/rescue/rescue/../../sbin/restore
restore_REALSRCDIR=/usr/home/freebsd/omega/src/sbin/restore
restore_OBJS= main.o interactive.o restore.o dirs.o symtab.o tape.o utilities.o dumprmt.o
restore_OPTS+= DIRPRFX=rescue/rescue/restore/
restore_make:
	(cd $(restore_SRCDIR) && \
		$(CRUNCHMAKE) $(BUILDOPTS) $(restore_OPTS) depend &&\
		$(CRUNCHMAKE) $(BUILDOPTS) $(restore_OPTS) $(restore_OBJS))
restore_clean:
	(cd $(restore_SRCDIR) && $(CRUNCHMAKE) $(BUILDOPTS) clean cleandepend)

restore_stub.c:
	echo "int _crunched_restore_stub(int argc, char **argv, char **envp){return main(argc,argv,envp);}" >restore_stub.c
restore.lo: restore_stub.o $(restore_OBJPATHS)
	$(CC) -nostdlib -Wl,-dc -r -o restore.lo restore_stub.o $(restore_OBJPATHS)
	crunchide -k _crunched_restore_stub restore.lo

# -------- rcorder

rcorder_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/rescue/rescue//usr/home/freebsd/omega/src/sbin/rcorder
rcorder_OBJPATHS= $(rcorder_OBJDIR)/ealloc.o $(rcorder_OBJDIR)/hash.o $(rcorder_OBJDIR)/rcorder.o
rcorder_SRCDIR=/usr/home/freebsd/omega/src/rescue/rescue/../../sbin/rcorder
rcorder_REALSRCDIR=/usr/home/freebsd/omega/src/sbin/rcorder
rcorder_OBJS= ealloc.o hash.o rcorder.o
rcorder_OPTS+= DIRPRFX=rescue/rescue/rcorder/
rcorder_make:
	(cd $(rcorder_SRCDIR) && \
		$(CRUNCHMAKE) $(BUILDOPTS) $(rcorder_OPTS) depend &&\
		$(CRUNCHMAKE) $(BUILDOPTS) $(rcorder_OPTS) $(rcorder_OBJS))
rcorder_clean:
	(cd $(rcorder_SRCDIR) && $(CRUNCHMAKE) $(BUILDOPTS) clean cleandepend)

rcorder_stub.c:
	echo "int _crunched_rcorder_stub(int argc, char **argv, char **envp){return main(argc,argv,envp);}" >rcorder_stub.c
rcorder.lo: rcorder_stub.o $(rcorder_OBJPATHS)
	$(CC) -nostdlib -Wl,-dc -r -o rcorder.lo rcorder_stub.o $(rcorder_OBJPATHS)
	crunchide -k _crunched_rcorder_stub rcorder.lo

# -------- route

route_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/rescue/rescue//usr/home/freebsd/omega/src/sbin/route
route_OBJPATHS= $(route_OBJDIR)/route.o
route_SRCDIR=/usr/home/freebsd/omega/src/rescue/rescue/../../sbin/route
route_REALSRCDIR=/usr/home/freebsd/omega/src/sbin/route
route_OBJS= route.o
route_OPTS+= DIRPRFX=rescue/rescue/route/
route_make:
	(cd $(route_SRCDIR) && \
		$(CRUNCHMAKE) $(BUILDOPTS) $(route_OPTS) depend &&\
		$(CRUNCHMAKE) $(BUILDOPTS) $(route_OPTS) $(route_OBJS))
route_clean:
	(cd $(route_SRCDIR) && $(CRUNCHMAKE) $(BUILDOPTS) clean cleandepend)

route_stub.c:
	echo "int _crunched_route_stub(int argc, char **argv, char **envp){return main(argc,argv,envp);}" >route_stub.c
route.lo: route_stub.o $(route_OBJPATHS)
	$(CC) -nostdlib -Wl,-dc -r -o route.lo route_stub.o $(route_OBJPATHS)
	crunchide -k _crunched_route_stub route.lo

# -------- routed

routed_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/rescue/rescue//usr/home/freebsd/omega/src/sbin/routed
routed_OBJPATHS= $(routed_OBJDIR)/if.o $(routed_OBJDIR)/input.o $(routed_OBJDIR)/main.o $(routed_OBJDIR)/output.o $(routed_OBJDIR)/parms.o $(routed_OBJDIR)/radix.o $(routed_OBJDIR)/rdisc.o $(routed_OBJDIR)/table.o $(routed_OBJDIR)/trace.o
routed_SRCDIR=/usr/home/freebsd/omega/src/rescue/rescue/../../sbin/routed
routed_REALSRCDIR=/usr/home/freebsd/omega/src/sbin/routed
routed_OBJS= if.o input.o main.o output.o parms.o radix.o rdisc.o table.o trace.o
routed_OPTS+= DIRPRFX=rescue/rescue/routed/
routed_make:
	(cd $(routed_SRCDIR) && \
		$(CRUNCHMAKE) $(BUILDOPTS) $(routed_OPTS) depend &&\
		$(CRUNCHMAKE) $(BUILDOPTS) $(routed_OPTS) $(routed_OBJS))
routed_clean:
	(cd $(routed_SRCDIR) && $(CRUNCHMAKE) $(BUILDOPTS) clean cleandepend)

routed_stub.c:
	echo "int _crunched_routed_stub(int argc, char **argv, char **envp){return main(argc,argv,envp);}" >routed_stub.c
routed.lo: routed_stub.o $(routed_OBJPATHS)
	$(CC) -nostdlib -Wl,-dc -r -o routed.lo routed_stub.o $(routed_OBJPATHS)
	crunchide -k _crunched_routed_stub routed.lo

# -------- rtquery

rtquery_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/rescue/rescue//usr/home/freebsd/omega/src/sbin/routed/rtquery
rtquery_OBJPATHS= $(rtquery_OBJDIR)/rtquery.o
rtquery_SRCDIR=/usr/home/freebsd/omega/src/rescue/rescue/../../sbin/routed/rtquery
rtquery_REALSRCDIR=/usr/home/freebsd/omega/src/sbin/routed/rtquery
rtquery_OBJS= rtquery.o
rtquery_OPTS+= DIRPRFX=rescue/rescue/rtquery/
rtquery_make:
	(cd $(rtquery_SRCDIR) && \
		$(CRUNCHMAKE) $(BUILDOPTS) $(rtquery_OPTS) depend &&\
		$(CRUNCHMAKE) $(BUILDOPTS) $(rtquery_OPTS) $(rtquery_OBJS))
rtquery_clean:
	(cd $(rtquery_SRCDIR) && $(CRUNCHMAKE) $(BUILDOPTS) clean cleandepend)

rtquery_stub.c:
	echo "int _crunched_rtquery_stub(int argc, char **argv, char **envp){return main(argc,argv,envp);}" >rtquery_stub.c
rtquery.lo: rtquery_stub.o $(rtquery_OBJPATHS)
	$(CC) -nostdlib -Wl,-dc -r -o rtquery.lo rtquery_stub.o $(rtquery_OBJPATHS)
	crunchide -k _crunched_rtquery_stub rtquery.lo

# -------- rtsol

rtsol_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/rescue/rescue//usr/home/freebsd/omega/src/sbin/rtsol
rtsol_OBJPATHS= $(rtsol_OBJDIR)/rtsold.o $(rtsol_OBJDIR)/rtsol.o $(rtsol_OBJDIR)/if.o $(rtsol_OBJDIR)/probe.o $(rtsol_OBJDIR)/dump.o $(rtsol_OBJDIR)/rtsock.o
rtsol_SRCDIR=/usr/home/freebsd/omega/src/rescue/rescue/../../sbin/rtsol
rtsol_REALSRCDIR=/usr/home/freebsd/omega/src/sbin/rtsol
rtsol_OBJS= rtsold.o rtsol.o if.o probe.o dump.o rtsock.o
rtsol_OPTS+= DIRPRFX=rescue/rescue/rtsol/
rtsol_make:
	(cd $(rtsol_SRCDIR) && \
		$(CRUNCHMAKE) $(BUILDOPTS) $(rtsol_OPTS) depend &&\
		$(CRUNCHMAKE) $(BUILDOPTS) $(rtsol_OPTS) $(rtsol_OBJS))
rtsol_clean:
	(cd $(rtsol_SRCDIR) && $(CRUNCHMAKE) $(BUILDOPTS) clean cleandepend)

rtsol_stub.c:
	echo "int _crunched_rtsol_stub(int argc, char **argv, char **envp){return main(argc,argv,envp);}" >rtsol_stub.c
rtsol.lo: rtsol_stub.o $(rtsol_OBJPATHS)
	$(CC) -nostdlib -Wl,-dc -r -o rtsol.lo rtsol_stub.o $(rtsol_OBJPATHS)
	crunchide -k _crunched_rtsol_stub rtsol.lo

# -------- savecore

savecore_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/rescue/rescue//usr/home/freebsd/omega/src/sbin/savecore
savecore_OBJPATHS= $(savecore_OBJDIR)/savecore.o
savecore_SRCDIR=/usr/home/freebsd/omega/src/rescue/rescue/../../sbin/savecore
savecore_REALSRCDIR=/usr/home/freebsd/omega/src/sbin/savecore
savecore_OBJS= savecore.o
savecore_OPTS+= DIRPRFX=rescue/rescue/savecore/
savecore_make:
	(cd $(savecore_SRCDIR) && \
		$(CRUNCHMAKE) $(BUILDOPTS) $(savecore_OPTS) depend &&\
		$(CRUNCHMAKE) $(BUILDOPTS) $(savecore_OPTS) $(savecore_OBJS))
savecore_clean:
	(cd $(savecore_SRCDIR) && $(CRUNCHMAKE) $(BUILDOPTS) clean cleandepend)

savecore_stub.c:
	echo "int _crunched_savecore_stub(int argc, char **argv, char **envp){return main(argc,argv,envp);}" >savecore_stub.c
savecore.lo: savecore_stub.o $(savecore_OBJPATHS)
	$(CC) -nostdlib -Wl,-dc -r -o savecore.lo savecore_stub.o $(savecore_OBJPATHS)
	crunchide -k _crunched_savecore_stub savecore.lo

# -------- spppcontrol

spppcontrol_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/rescue/rescue//usr/home/freebsd/omega/src/sbin/spppcontrol
spppcontrol_OBJPATHS= $(spppcontrol_OBJDIR)/spppcontrol.o
spppcontrol_SRCDIR=/usr/home/freebsd/omega/src/rescue/rescue/../../sbin/spppcontrol
spppcontrol_REALSRCDIR=/usr/home/freebsd/omega/src/sbin/spppcontrol
spppcontrol_OBJS= spppcontrol.o
spppcontrol_OPTS+= DIRPRFX=rescue/rescue/spppcontrol/
spppcontrol_make:
	(cd $(spppcontrol_SRCDIR) && \
		$(CRUNCHMAKE) $(BUILDOPTS) $(spppcontrol_OPTS) depend &&\
		$(CRUNCHMAKE) $(BUILDOPTS) $(spppcontrol_OPTS) $(spppcontrol_OBJS))
spppcontrol_clean:
	(cd $(spppcontrol_SRCDIR) && $(CRUNCHMAKE) $(BUILDOPTS) clean cleandepend)

spppcontrol_stub.c:
	echo "int _crunched_spppcontrol_stub(int argc, char **argv, char **envp){return main(argc,argv,envp);}" >spppcontrol_stub.c
spppcontrol.lo: spppcontrol_stub.o $(spppcontrol_OBJPATHS)
	$(CC) -nostdlib -Wl,-dc -r -o spppcontrol.lo spppcontrol_stub.o $(spppcontrol_OBJPATHS)
	crunchide -k _crunched_spppcontrol_stub spppcontrol.lo

# -------- swapon

swapon_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/rescue/rescue//usr/home/freebsd/omega/src/sbin/swapon
swapon_OBJPATHS= $(swapon_OBJDIR)/swapon.o
swapon_SRCDIR=/usr/home/freebsd/omega/src/rescue/rescue/../../sbin/swapon
swapon_REALSRCDIR=/usr/home/freebsd/omega/src/sbin/swapon
swapon_OBJS= swapon.o
swapon_OPTS+= DIRPRFX=rescue/rescue/swapon/
swapon_make:
	(cd $(swapon_SRCDIR) && \
		$(CRUNCHMAKE) $(BUILDOPTS) $(swapon_OPTS) depend &&\
		$(CRUNCHMAKE) $(BUILDOPTS) $(swapon_OPTS) $(swapon_OBJS))
swapon_clean:
	(cd $(swapon_SRCDIR) && $(CRUNCHMAKE) $(BUILDOPTS) clean cleandepend)

swapon_stub.c:
	echo "int _crunched_swapon_stub(int argc, char **argv, char **envp){return main(argc,argv,envp);}" >swapon_stub.c
swapon.lo: swapon_stub.o $(swapon_OBJPATHS)
	$(CC) -nostdlib -Wl,-dc -r -o swapon.lo swapon_stub.o $(swapon_OBJPATHS)
	crunchide -k _crunched_swapon_stub swapon.lo

# -------- sysctl

sysctl_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/rescue/rescue//usr/home/freebsd/omega/src/sbin/sysctl
sysctl_OBJPATHS= $(sysctl_OBJDIR)/sysctl.o
sysctl_SRCDIR=/usr/home/freebsd/omega/src/rescue/rescue/../../sbin/sysctl
sysctl_REALSRCDIR=/usr/home/freebsd/omega/src/sbin/sysctl
sysctl_OBJS= sysctl.o
sysctl_OPTS+= DIRPRFX=rescue/rescue/sysctl/
sysctl_make:
	(cd $(sysctl_SRCDIR) && \
		$(CRUNCHMAKE) $(BUILDOPTS) $(sysctl_OPTS) depend &&\
		$(CRUNCHMAKE) $(BUILDOPTS) $(sysctl_OPTS) $(sysctl_OBJS))
sysctl_clean:
	(cd $(sysctl_SRCDIR) && $(CRUNCHMAKE) $(BUILDOPTS) clean cleandepend)

sysctl_stub.c:
	echo "int _crunched_sysctl_stub(int argc, char **argv, char **envp){return main(argc,argv,envp);}" >sysctl_stub.c
sysctl.lo: sysctl_stub.o $(sysctl_OBJPATHS)
	$(CC) -nostdlib -Wl,-dc -r -o sysctl.lo sysctl_stub.o $(sysctl_OBJPATHS)
	crunchide -k _crunched_sysctl_stub sysctl.lo

# -------- tunefs

tunefs_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/rescue/rescue//usr/home/freebsd/omega/src/sbin/tunefs
tunefs_OBJPATHS= $(tunefs_OBJDIR)/tunefs.o
tunefs_SRCDIR=/usr/home/freebsd/omega/src/rescue/rescue/../../sbin/tunefs
tunefs_REALSRCDIR=/usr/home/freebsd/omega/src/sbin/tunefs
tunefs_OBJS= tunefs.o
tunefs_OPTS+= DIRPRFX=rescue/rescue/tunefs/
tunefs_make:
	(cd $(tunefs_SRCDIR) && \
		$(CRUNCHMAKE) $(BUILDOPTS) $(tunefs_OPTS) depend &&\
		$(CRUNCHMAKE) $(BUILDOPTS) $(tunefs_OPTS) $(tunefs_OBJS))
tunefs_clean:
	(cd $(tunefs_SRCDIR) && $(CRUNCHMAKE) $(BUILDOPTS) clean cleandepend)

tunefs_stub.c:
	echo "int _crunched_tunefs_stub(int argc, char **argv, char **envp){return main(argc,argv,envp);}" >tunefs_stub.c
tunefs.lo: tunefs_stub.o $(tunefs_OBJPATHS)
	$(CC) -nostdlib -Wl,-dc -r -o tunefs.lo tunefs_stub.o $(tunefs_OBJPATHS)
	crunchide -k _crunched_tunefs_stub tunefs.lo

# -------- umount

umount_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/rescue/rescue//usr/home/freebsd/omega/src/sbin/umount
umount_OBJPATHS= $(umount_OBJDIR)/umount.o $(umount_OBJDIR)/vfslist.o $(umount_OBJDIR)/mounttab.o
umount_SRCDIR=/usr/home/freebsd/omega/src/rescue/rescue/../../sbin/umount
umount_REALSRCDIR=/usr/home/freebsd/omega/src/sbin/umount
umount_OBJS= umount.o vfslist.o mounttab.o
umount_OPTS+= DIRPRFX=rescue/rescue/umount/
umount_make:
	(cd $(umount_SRCDIR) && \
		$(CRUNCHMAKE) $(BUILDOPTS) $(umount_OPTS) depend &&\
		$(CRUNCHMAKE) $(BUILDOPTS) $(umount_OPTS) $(umount_OBJS))
umount_clean:
	(cd $(umount_SRCDIR) && $(CRUNCHMAKE) $(BUILDOPTS) clean cleandepend)

umount_stub.c:
	echo "int _crunched_umount_stub(int argc, char **argv, char **envp){return main(argc,argv,envp);}" >umount_stub.c
umount.lo: umount_stub.o $(umount_OBJPATHS)
	$(CC) -nostdlib -Wl,-dc -r -o umount.lo umount_stub.o $(umount_OBJPATHS)
	crunchide -k _crunched_umount_stub umount.lo

# -------- ping6

ping6_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/rescue/rescue//usr/home/freebsd/omega/src/sbin/ping6
ping6_OBJPATHS= $(ping6_OBJDIR)/ping6.o
ping6_SRCDIR=/usr/home/freebsd/omega/src/rescue/rescue/../../sbin/ping6
ping6_REALSRCDIR=/usr/home/freebsd/omega/src/sbin/ping6
ping6_OBJS= ping6.o
ping6_OPTS+= DIRPRFX=rescue/rescue/ping6/
ping6_make:
	(cd $(ping6_SRCDIR) && \
		$(CRUNCHMAKE) $(BUILDOPTS) $(ping6_OPTS) depend &&\
		$(CRUNCHMAKE) $(BUILDOPTS) $(ping6_OPTS) $(ping6_OBJS))
ping6_clean:
	(cd $(ping6_SRCDIR) && $(CRUNCHMAKE) $(BUILDOPTS) clean cleandepend)

ping6_stub.c:
	echo "int _crunched_ping6_stub(int argc, char **argv, char **envp){return main(argc,argv,envp);}" >ping6_stub.c
ping6.lo: ping6_stub.o $(ping6_OBJPATHS)
	$(CC) -nostdlib -Wl,-dc -r -o ping6.lo ping6_stub.o $(ping6_OBJPATHS)
	crunchide -k _crunched_ping6_stub ping6.lo

# -------- ipf

ipf_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/rescue/rescue//usr/home/freebsd/omega/src/sbin/ipf/ipf
ipf_OBJPATHS= $(ipf_OBJDIR)/ipf.o $(ipf_OBJDIR)/ipfcomp.o $(ipf_OBJDIR)/ipf_y.o $(ipf_OBJDIR)/ipf_l.o $(ipf_OBJDIR)/bpf_filter.o $(ipf_OBJDIR)/addicmp.o $(ipf_OBJDIR)/addipopt.o $(ipf_OBJDIR)/alist_free.o $(ipf_OBJDIR)/alist_new.o $(ipf_OBJDIR)/allocmbt.o $(ipf_OBJDIR)/assigndefined.o $(ipf_OBJDIR)/bcopywrap.o $(ipf_OBJDIR)/binprint.o $(ipf_OBJDIR)/buildopts.o $(ipf_OBJDIR)/checkrev.o $(ipf_OBJDIR)/connecttcp.o $(ipf_OBJDIR)/count4bits.o $(ipf_OBJDIR)/count6bits.o $(ipf_OBJDIR)/debug.o $(ipf_OBJDIR)/dupmbt.o $(ipf_OBJDIR)/facpri.o $(ipf_OBJDIR)/familyname.o $(ipf_OBJDIR)/fill6bits.o $(ipf_OBJDIR)/findword.o $(ipf_OBJDIR)/flags.o $(ipf_OBJDIR)/freembt.o $(ipf_OBJDIR)/ftov.o $(ipf_OBJDIR)/genmask.o $(ipf_OBJDIR)/gethost.o $(ipf_OBJDIR)/getifname.o $(ipf_OBJDIR)/geticmptype.o $(ipf_OBJDIR)/getnattype.o $(ipf_OBJDIR)/getport.o $(ipf_OBJDIR)/getportproto.o $(ipf_OBJDIR)/getproto.o $(ipf_OBJDIR)/getsumd.o $(ipf_OBJDIR)/hostname.o $(ipf_OBJDIR)/icmpcode.o $(ipf_OBJDIR)/icmptypename.o $(ipf_OBJDIR)/icmptypes.o $(ipf_OBJDIR)/initparse.o $(ipf_OBJDIR)/interror.o $(ipf_OBJDIR)/ionames.o $(ipf_OBJDIR)/ipf_dotuning.o $(ipf_OBJDIR)/ipf_perror.o $(ipf_OBJDIR)/ipft_hx.o $(ipf_OBJDIR)/ipft_pc.o $(ipf_OBJDIR)/ipft_tx.o $(ipf_OBJDIR)/ipoptsec.o $(ipf_OBJDIR)/kmem.o $(ipf_OBJDIR)/kmemcpywrap.o $(ipf_OBJDIR)/kvatoname.o $(ipf_OBJDIR)/load_dstlist.o $(ipf_OBJDIR)/load_dstlistnode.o $(ipf_OBJDIR)/load_file.o $(ipf_OBJDIR)/load_hash.o $(ipf_OBJDIR)/load_hashnode.o $(ipf_OBJDIR)/load_http.o $(ipf_OBJDIR)/load_pool.o $(ipf_OBJDIR)/load_poolnode.o $(ipf_OBJDIR)/load_url.o $(ipf_OBJDIR)/mb_hexdump.o $(ipf_OBJDIR)/msgdsize.o $(ipf_OBJDIR)/mutex_emul.o $(ipf_OBJDIR)/nametokva.o $(ipf_OBJDIR)/nat_setgroupmap.o $(ipf_OBJDIR)/ntomask.o $(ipf_OBJDIR)/optname.o $(ipf_OBJDIR)/optprint.o $(ipf_OBJDIR)/optprintv6.o $(ipf_OBJDIR)/optvalue.o $(ipf_OBJDIR)/parsefields.o $(ipf_OBJDIR)/parseipfexpr.o $(ipf_OBJDIR)/parsewhoisline.o $(ipf_OBJDIR)/poolio.o $(ipf_OBJDIR)/portname.o $(ipf_OBJDIR)/prependmbt.o $(ipf_OBJDIR)/print_toif.o $(ipf_OBJDIR)/printactiveaddr.o $(ipf_OBJDIR)/printactivenat.o $(ipf_OBJDIR)/printaddr.o $(ipf_OBJDIR)/printaps.o $(ipf_OBJDIR)/printbuf.o $(ipf_OBJDIR)/printdstl_live.o $(ipf_OBJDIR)/printdstlist.o $(ipf_OBJDIR)/printdstlistdata.o $(ipf_OBJDIR)/printdstlistnode.o $(ipf_OBJDIR)/printdstlistpolicy.o $(ipf_OBJDIR)/printfieldhdr.o $(ipf_OBJDIR)/printfr.o $(ipf_OBJDIR)/printfraginfo.o $(ipf_OBJDIR)/printhash.o $(ipf_OBJDIR)/printhash_live.o $(ipf_OBJDIR)/printhashdata.o $(ipf_OBJDIR)/printhashnode.o $(ipf_OBJDIR)/printhost.o $(ipf_OBJDIR)/printhostmap.o $(ipf_OBJDIR)/printhostmask.o $(ipf_OBJDIR)/printifname.o $(ipf_OBJDIR)/printip.o $(ipf_OBJDIR)/printipfexpr.o $(ipf_OBJDIR)/printiphdr.o $(ipf_OBJDIR)/printlog.o $(ipf_OBJDIR)/printlookup.o $(ipf_OBJDIR)/printmask.o $(ipf_OBJDIR)/printnat.o $(ipf_OBJDIR)/printnataddr.o $(ipf_OBJDIR)/printnatfield.o $(ipf_OBJDIR)/printnatside.o $(ipf_OBJDIR)/printpacket.o $(ipf_OBJDIR)/printpacket6.o $(ipf_OBJDIR)/printpool.o $(ipf_OBJDIR)/printpool_live.o $(ipf_OBJDIR)/printpooldata.o $(ipf_OBJDIR)/printpoolfield.o $(ipf_OBJDIR)/printpoolnode.o $(ipf_OBJDIR)/printportcmp.o $(ipf_OBJDIR)/printproto.o $(ipf_OBJDIR)/printsbuf.o $(ipf_OBJDIR)/printstate.o $(ipf_OBJDIR)/printstatefields.o $(ipf_OBJDIR)/printtcpflags.o $(ipf_OBJDIR)/printtqtable.o $(ipf_OBJDIR)/printtunable.o $(ipf_OBJDIR)/printunit.o $(ipf_OBJDIR)/remove_hash.o $(ipf_OBJDIR)/remove_hashnode.o $(ipf_OBJDIR)/remove_pool.o $(ipf_OBJDIR)/remove_poolnode.o $(ipf_OBJDIR)/resetlexer.o $(ipf_OBJDIR)/rwlock_emul.o $(ipf_OBJDIR)/save_execute.o $(ipf_OBJDIR)/save_file.o $(ipf_OBJDIR)/save_nothing.o $(ipf_OBJDIR)/save_syslog.o $(ipf_OBJDIR)/save_v1trap.o $(ipf_OBJDIR)/save_v2trap.o $(ipf_OBJDIR)/vtof.o $(ipf_OBJDIR)/tcp_flags.o $(ipf_OBJDIR)/tcpflags.o $(ipf_OBJDIR)/tcpoptnames.o $(ipf_OBJDIR)/v6ionames.o $(ipf_OBJDIR)/v6optvalue.o $(ipf_OBJDIR)/var.o $(ipf_OBJDIR)/verbose.o
ipf_SRCDIR=/usr/home/freebsd/omega/src/rescue/rescue/../../sbin/ipf/ipf
ipf_REALSRCDIR=/usr/home/freebsd/omega/src/sbin/ipf/ipf
ipf_OBJS= ipf.o ipfcomp.o ipf_y.o ipf_l.o bpf_filter.o addicmp.o addipopt.o alist_free.o alist_new.o allocmbt.o assigndefined.o bcopywrap.o binprint.o buildopts.o checkrev.o connecttcp.o count4bits.o count6bits.o debug.o dupmbt.o facpri.o familyname.o fill6bits.o findword.o flags.o freembt.o ftov.o genmask.o gethost.o getifname.o geticmptype.o getnattype.o getport.o getportproto.o getproto.o getsumd.o hostname.o icmpcode.o icmptypename.o icmptypes.o initparse.o interror.o ionames.o ipf_dotuning.o ipf_perror.o ipft_hx.o ipft_pc.o ipft_tx.o ipoptsec.o kmem.o kmemcpywrap.o kvatoname.o load_dstlist.o load_dstlistnode.o load_file.o load_hash.o load_hashnode.o load_http.o load_pool.o load_poolnode.o load_url.o mb_hexdump.o msgdsize.o mutex_emul.o nametokva.o nat_setgroupmap.o ntomask.o optname.o optprint.o optprintv6.o optvalue.o parsefields.o parseipfexpr.o parsewhoisline.o poolio.o portname.o prependmbt.o print_toif.o printactiveaddr.o printactivenat.o printaddr.o printaps.o printbuf.o printdstl_live.o printdstlist.o printdstlistdata.o printdstlistnode.o printdstlistpolicy.o printfieldhdr.o printfr.o printfraginfo.o printhash.o printhash_live.o printhashdata.o printhashnode.o printhost.o printhostmap.o printhostmask.o printifname.o printip.o printipfexpr.o printiphdr.o printlog.o printlookup.o printmask.o printnat.o printnataddr.o printnatfield.o printnatside.o printpacket.o printpacket6.o printpool.o printpool_live.o printpooldata.o printpoolfield.o printpoolnode.o printportcmp.o printproto.o printsbuf.o printstate.o printstatefields.o printtcpflags.o printtqtable.o printtunable.o printunit.o remove_hash.o remove_hashnode.o remove_pool.o remove_poolnode.o resetlexer.o rwlock_emul.o save_execute.o save_file.o save_nothing.o save_syslog.o save_v1trap.o save_v2trap.o vtof.o tcp_flags.o tcpflags.o tcpoptnames.o v6ionames.o v6optvalue.o var.o verbose.o
ipf_OPTS+= DIRPRFX=rescue/rescue/ipf/
ipf_make:
	(cd $(ipf_SRCDIR) && \
		$(CRUNCHMAKE) $(BUILDOPTS) $(ipf_OPTS) depend &&\
		$(CRUNCHMAKE) $(BUILDOPTS) $(ipf_OPTS) $(ipf_OBJS))
ipf_clean:
	(cd $(ipf_SRCDIR) && $(CRUNCHMAKE) $(BUILDOPTS) clean cleandepend)

ipf_stub.c:
	echo "int _crunched_ipf_stub(int argc, char **argv, char **envp){return main(argc,argv,envp);}" >ipf_stub.c
ipf.lo: ipf_stub.o $(ipf_OBJPATHS)
	$(CC) -nostdlib -Wl,-dc -r -o ipf.lo ipf_stub.o $(ipf_OBJPATHS)
	crunchide -k _crunched_ipf_stub ipf.lo

# -------- zfs

zfs_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/rescue/rescue//usr/home/freebsd/omega/src/cddl/sbin/zfs
zfs_OBJPATHS= $(zfs_OBJDIR)/zfs_main.o $(zfs_OBJDIR)/zfs_iter.o
zfs_SRCDIR=/usr/home/freebsd/omega/src/rescue/rescue/../../cddl/sbin/zfs
zfs_REALSRCDIR=/usr/home/freebsd/omega/src/cddl/sbin/zfs
zfs_OBJS= zfs_main.o zfs_iter.o
zfs_OPTS+= DIRPRFX=rescue/rescue/zfs/
zfs_make:
	(cd $(zfs_SRCDIR) && \
		$(CRUNCHMAKE) $(BUILDOPTS) $(zfs_OPTS) depend &&\
		$(CRUNCHMAKE) $(BUILDOPTS) $(zfs_OPTS) $(zfs_OBJS))
zfs_clean:
	(cd $(zfs_SRCDIR) && $(CRUNCHMAKE) $(BUILDOPTS) clean cleandepend)

zfs_stub.c:
	echo "int _crunched_zfs_stub(int argc, char **argv, char **envp){return main(argc,argv,envp);}" >zfs_stub.c
zfs.lo: zfs_stub.o $(zfs_OBJPATHS)
	$(CC) -nostdlib -Wl,-dc -r -o zfs.lo zfs_stub.o $(zfs_OBJPATHS)
	crunchide -k _crunched_zfs_stub zfs.lo

# -------- zpool

zpool_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/rescue/rescue//usr/home/freebsd/omega/src/cddl/sbin/zpool
zpool_OBJPATHS= $(zpool_OBJDIR)/zpool_main.o $(zpool_OBJDIR)/zpool_vdev.o $(zpool_OBJDIR)/zpool_iter.o $(zpool_OBJDIR)/zpool_util.o $(zpool_OBJDIR)/zfs_comutil.o $(zpool_OBJDIR)/timestamp.o
zpool_SRCDIR=/usr/home/freebsd/omega/src/rescue/rescue/../../cddl/sbin/zpool
zpool_REALSRCDIR=/usr/home/freebsd/omega/src/cddl/sbin/zpool
zpool_OBJS= zpool_main.o zpool_vdev.o zpool_iter.o zpool_util.o zfs_comutil.o timestamp.o
zpool_OPTS+= DIRPRFX=rescue/rescue/zpool/
zpool_make:
	(cd $(zpool_SRCDIR) && \
		$(CRUNCHMAKE) $(BUILDOPTS) $(zpool_OPTS) depend &&\
		$(CRUNCHMAKE) $(BUILDOPTS) $(zpool_OPTS) $(zpool_OBJS))
zpool_clean:
	(cd $(zpool_SRCDIR) && $(CRUNCHMAKE) $(BUILDOPTS) clean cleandepend)

zpool_stub.c:
	echo "int _crunched_zpool_stub(int argc, char **argv, char **envp){return main(argc,argv,envp);}" >zpool_stub.c
zpool.lo: zpool_stub.o $(zpool_OBJPATHS)
	$(CC) -nostdlib -Wl,-dc -r -o zpool.lo zpool_stub.o $(zpool_OBJPATHS)
	crunchide -k _crunched_zpool_stub zpool.lo

# -------- dhclient

dhclient_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/rescue/rescue//usr/home/freebsd/omega/src/sbin/dhclient
dhclient_OBJPATHS= $(dhclient_OBJDIR)/dhclient.o $(dhclient_OBJDIR)/clparse.o $(dhclient_OBJDIR)/alloc.o $(dhclient_OBJDIR)/dispatch.o $(dhclient_OBJDIR)/hash.o $(dhclient_OBJDIR)/bpf.o $(dhclient_OBJDIR)/options.o $(dhclient_OBJDIR)/tree.o $(dhclient_OBJDIR)/conflex.o $(dhclient_OBJDIR)/errwarn.o $(dhclient_OBJDIR)/inet.o $(dhclient_OBJDIR)/packet.o $(dhclient_OBJDIR)/convert.o $(dhclient_OBJDIR)/tables.o $(dhclient_OBJDIR)/parse.o $(dhclient_OBJDIR)/privsep.o
dhclient_SRCDIR=/usr/home/freebsd/omega/src/rescue/rescue/../../sbin/dhclient
dhclient_REALSRCDIR=/usr/home/freebsd/omega/src/sbin/dhclient
dhclient_OBJS= dhclient.o clparse.o alloc.o dispatch.o hash.o bpf.o options.o tree.o conflex.o errwarn.o inet.o packet.o convert.o tables.o parse.o privsep.o
dhclient_OPTS+= DIRPRFX=rescue/rescue/dhclient/ -DRELEASE_CRUNCH -Dlint
dhclient_make:
	(cd $(dhclient_SRCDIR) && \
		$(CRUNCHMAKE) $(BUILDOPTS) $(dhclient_OPTS) depend &&\
		$(CRUNCHMAKE) $(BUILDOPTS) $(dhclient_OPTS) $(dhclient_OBJS))
dhclient_clean:
	(cd $(dhclient_SRCDIR) && $(CRUNCHMAKE) $(BUILDOPTS) clean cleandepend)

dhclient_stub.c:
	echo "int _crunched_dhclient_stub(int argc, char **argv, char **envp){return main(argc,argv,envp);}" >dhclient_stub.c
dhclient.lo: dhclient_stub.o $(dhclient_OBJPATHS)
	$(CC) -nostdlib -Wl,-dc -r -o dhclient.lo dhclient_stub.o $(dhclient_OBJPATHS)
	crunchide -k _crunched_dhclient_stub dhclient.lo

# -------- head

head_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/rescue/rescue//usr/home/freebsd/omega/src/usr.bin/head
head_OBJPATHS= $(head_OBJDIR)/head.o
head_SRCDIR=/usr/home/freebsd/omega/src/rescue/rescue/../../usr.bin/head
head_REALSRCDIR=/usr/home/freebsd/omega/src/usr.bin/head
head_OBJS= head.o
head_OPTS+= DIRPRFX=rescue/rescue/head/
head_make:
	(cd $(head_SRCDIR) && \
		$(CRUNCHMAKE) $(BUILDOPTS) $(head_OPTS) depend &&\
		$(CRUNCHMAKE) $(BUILDOPTS) $(head_OPTS) $(head_OBJS))
head_clean:
	(cd $(head_SRCDIR) && $(CRUNCHMAKE) $(BUILDOPTS) clean cleandepend)

head_stub.c:
	echo "int _crunched_head_stub(int argc, char **argv, char **envp){return main(argc,argv,envp);}" >head_stub.c
head.lo: head_stub.o $(head_OBJPATHS)
	$(CC) -nostdlib -Wl,-dc -r -o head.lo head_stub.o $(head_OBJPATHS)
	crunchide -k _crunched_head_stub head.lo

# -------- mt

mt_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/rescue/rescue//usr/home/freebsd/omega/src/usr.bin/mt
mt_OBJPATHS= $(mt_OBJDIR)/mt.o
mt_SRCDIR=/usr/home/freebsd/omega/src/rescue/rescue/../../usr.bin/mt
mt_REALSRCDIR=/usr/home/freebsd/omega/src/usr.bin/mt
mt_OBJS= mt.o
mt_OPTS+= DIRPRFX=rescue/rescue/mt/
mt_make:
	(cd $(mt_SRCDIR) && \
		$(CRUNCHMAKE) $(BUILDOPTS) $(mt_OPTS) depend &&\
		$(CRUNCHMAKE) $(BUILDOPTS) $(mt_OPTS) $(mt_OBJS))
mt_clean:
	(cd $(mt_SRCDIR) && $(CRUNCHMAKE) $(BUILDOPTS) clean cleandepend)

mt_stub.c:
	echo "int _crunched_mt_stub(int argc, char **argv, char **envp){return main(argc,argv,envp);}" >mt_stub.c
mt.lo: mt_stub.o $(mt_OBJPATHS)
	$(CC) -nostdlib -Wl,-dc -r -o mt.lo mt_stub.o $(mt_OBJPATHS)
	crunchide -k _crunched_mt_stub mt.lo

# -------- nc

nc_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/rescue/rescue//usr/home/freebsd/omega/src/usr.bin/nc
nc_OBJPATHS= $(nc_OBJDIR)/netcat.o $(nc_OBJDIR)/atomicio.o $(nc_OBJDIR)/socks.o
nc_SRCDIR=/usr/home/freebsd/omega/src/rescue/rescue/../../usr.bin/nc
nc_REALSRCDIR=/usr/home/freebsd/omega/src/usr.bin/nc
nc_OBJS= netcat.o atomicio.o socks.o
nc_OPTS+= DIRPRFX=rescue/rescue/nc/
nc_make:
	(cd $(nc_SRCDIR) && \
		$(CRUNCHMAKE) $(BUILDOPTS) $(nc_OPTS) depend &&\
		$(CRUNCHMAKE) $(BUILDOPTS) $(nc_OPTS) $(nc_OBJS))
nc_clean:
	(cd $(nc_SRCDIR) && $(CRUNCHMAKE) $(BUILDOPTS) clean cleandepend)

nc_stub.c:
	echo "int _crunched_nc_stub(int argc, char **argv, char **envp){return main(argc,argv,envp);}" >nc_stub.c
nc.lo: nc_stub.o $(nc_OBJPATHS)
	$(CC) -nostdlib -Wl,-dc -r -o nc.lo nc_stub.o $(nc_OBJPATHS)
	crunchide -k _crunched_nc_stub nc.lo

# -------- sed

sed_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/rescue/rescue//usr/home/freebsd/omega/src/usr.bin/sed
sed_OBJPATHS= $(sed_OBJDIR)/compile.o $(sed_OBJDIR)/main.o $(sed_OBJDIR)/misc.o $(sed_OBJDIR)/process.o
sed_SRCDIR=/usr/home/freebsd/omega/src/rescue/rescue/../../usr.bin/sed
sed_REALSRCDIR=/usr/home/freebsd/omega/src/usr.bin/sed
sed_OBJS= compile.o main.o misc.o process.o
sed_OPTS+= DIRPRFX=rescue/rescue/sed/
sed_make:
	(cd $(sed_SRCDIR) && \
		$(CRUNCHMAKE) $(BUILDOPTS) $(sed_OPTS) depend &&\
		$(CRUNCHMAKE) $(BUILDOPTS) $(sed_OPTS) $(sed_OBJS))
sed_clean:
	(cd $(sed_SRCDIR) && $(CRUNCHMAKE) $(BUILDOPTS) clean cleandepend)

sed_stub.c:
	echo "int _crunched_sed_stub(int argc, char **argv, char **envp){return main(argc,argv,envp);}" >sed_stub.c
sed.lo: sed_stub.o $(sed_OBJPATHS)
	$(CC) -nostdlib -Wl,-dc -r -o sed.lo sed_stub.o $(sed_OBJPATHS)
	crunchide -k _crunched_sed_stub sed.lo

# -------- tail

tail_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/rescue/rescue//usr/home/freebsd/omega/src/usr.bin/tail
tail_OBJPATHS= $(tail_OBJDIR)/forward.o $(tail_OBJDIR)/misc.o $(tail_OBJDIR)/read.o $(tail_OBJDIR)/reverse.o $(tail_OBJDIR)/tail.o
tail_SRCDIR=/usr/home/freebsd/omega/src/rescue/rescue/../../usr.bin/tail
tail_REALSRCDIR=/usr/home/freebsd/omega/src/usr.bin/tail
tail_OBJS= forward.o misc.o read.o reverse.o tail.o
tail_OPTS+= DIRPRFX=rescue/rescue/tail/
tail_make:
	(cd $(tail_SRCDIR) && \
		$(CRUNCHMAKE) $(BUILDOPTS) $(tail_OPTS) depend &&\
		$(CRUNCHMAKE) $(BUILDOPTS) $(tail_OPTS) $(tail_OBJS))
tail_clean:
	(cd $(tail_SRCDIR) && $(CRUNCHMAKE) $(BUILDOPTS) clean cleandepend)

tail_stub.c:
	echo "int _crunched_tail_stub(int argc, char **argv, char **envp){return main(argc,argv,envp);}" >tail_stub.c
tail.lo: tail_stub.o $(tail_OBJPATHS)
	$(CC) -nostdlib -Wl,-dc -r -o tail.lo tail_stub.o $(tail_OBJPATHS)
	crunchide -k _crunched_tail_stub tail.lo

# -------- tee

tee_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/rescue/rescue//usr/home/freebsd/omega/src/usr.bin/tee
tee_OBJPATHS= $(tee_OBJDIR)/tee.o
tee_SRCDIR=/usr/home/freebsd/omega/src/rescue/rescue/../../usr.bin/tee
tee_REALSRCDIR=/usr/home/freebsd/omega/src/usr.bin/tee
tee_OBJS= tee.o
tee_OPTS+= DIRPRFX=rescue/rescue/tee/
tee_make:
	(cd $(tee_SRCDIR) && \
		$(CRUNCHMAKE) $(BUILDOPTS) $(tee_OPTS) depend &&\
		$(CRUNCHMAKE) $(BUILDOPTS) $(tee_OPTS) $(tee_OBJS))
tee_clean:
	(cd $(tee_SRCDIR) && $(CRUNCHMAKE) $(BUILDOPTS) clean cleandepend)

tee_stub.c:
	echo "int _crunched_tee_stub(int argc, char **argv, char **envp){return main(argc,argv,envp);}" >tee_stub.c
tee.lo: tee_stub.o $(tee_OBJPATHS)
	$(CC) -nostdlib -Wl,-dc -r -o tee.lo tee_stub.o $(tee_OBJPATHS)
	crunchide -k _crunched_tee_stub tee.lo

# -------- gzip

gzip_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/rescue/rescue//usr/home/freebsd/omega/src/usr.bin/gzip
gzip_OBJPATHS= $(gzip_OBJDIR)/gzip.o
gzip_SRCDIR=/usr/home/freebsd/omega/src/rescue/rescue/../../usr.bin/gzip
gzip_REALSRCDIR=/usr/home/freebsd/omega/src/usr.bin/gzip
gzip_OBJS= gzip.o
gzip_OPTS+= DIRPRFX=rescue/rescue/gzip/
gzip_make:
	(cd $(gzip_SRCDIR) && \
		$(CRUNCHMAKE) $(BUILDOPTS) $(gzip_OPTS) depend &&\
		$(CRUNCHMAKE) $(BUILDOPTS) $(gzip_OPTS) $(gzip_OBJS))
gzip_clean:
	(cd $(gzip_SRCDIR) && $(CRUNCHMAKE) $(BUILDOPTS) clean cleandepend)

gzip_stub.c:
	echo "int _crunched_gzip_stub(int argc, char **argv, char **envp){return main(argc,argv,envp);}" >gzip_stub.c
gzip.lo: gzip_stub.o $(gzip_OBJPATHS)
	$(CC) -nostdlib -Wl,-dc -r -o gzip.lo gzip_stub.o $(gzip_OBJPATHS)
	crunchide -k _crunched_gzip_stub gzip.lo

# -------- bzip2

bzip2_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/rescue/rescue//usr/home/freebsd/omega/src/usr.bin/bzip2
bzip2_OBJPATHS= $(bzip2_OBJDIR)/bzip2.o
bzip2_SRCDIR=/usr/home/freebsd/omega/src/rescue/rescue/../../usr.bin/bzip2
bzip2_REALSRCDIR=/usr/home/freebsd/omega/src/usr.bin/bzip2
bzip2_OBJS= bzip2.o
bzip2_OPTS+= DIRPRFX=rescue/rescue/bzip2/
bzip2_make:
	(cd $(bzip2_SRCDIR) && \
		$(CRUNCHMAKE) $(BUILDOPTS) $(bzip2_OPTS) depend &&\
		$(CRUNCHMAKE) $(BUILDOPTS) $(bzip2_OPTS) $(bzip2_OBJS))
bzip2_clean:
	(cd $(bzip2_SRCDIR) && $(CRUNCHMAKE) $(BUILDOPTS) clean cleandepend)

bzip2_stub.c:
	echo "int _crunched_bzip2_stub(int argc, char **argv, char **envp){return main(argc,argv,envp);}" >bzip2_stub.c
bzip2.lo: bzip2_stub.o $(bzip2_OBJPATHS)
	$(CC) -nostdlib -Wl,-dc -r -o bzip2.lo bzip2_stub.o $(bzip2_OBJPATHS)
	crunchide -k _crunched_bzip2_stub bzip2.lo

# -------- less

less_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/rescue/rescue//usr/home/freebsd/omega/src/usr.bin/less
less_OBJPATHS= $(less_OBJDIR)/main.o $(less_OBJDIR)/screen.o $(less_OBJDIR)/brac.o $(less_OBJDIR)/ch.o $(less_OBJDIR)/charset.o $(less_OBJDIR)/cmdbuf.o $(less_OBJDIR)/command.o $(less_OBJDIR)/cvt.o $(less_OBJDIR)/decode.o $(less_OBJDIR)/edit.o $(less_OBJDIR)/filename.o $(less_OBJDIR)/forwback.o $(less_OBJDIR)/help.o $(less_OBJDIR)/ifile.o $(less_OBJDIR)/input.o $(less_OBJDIR)/jump.o $(less_OBJDIR)/line.o $(less_OBJDIR)/linenum.o $(less_OBJDIR)/lsystem.o $(less_OBJDIR)/mark.o $(less_OBJDIR)/optfunc.o $(less_OBJDIR)/option.o $(less_OBJDIR)/opttbl.o $(less_OBJDIR)/os.o $(less_OBJDIR)/output.o $(less_OBJDIR)/pattern.o $(less_OBJDIR)/position.o $(less_OBJDIR)/prompt.o $(less_OBJDIR)/search.o $(less_OBJDIR)/signal.o $(less_OBJDIR)/tags.o $(less_OBJDIR)/ttyin.o $(less_OBJDIR)/version.o
less_SRCDIR=/usr/home/freebsd/omega/src/rescue/rescue/../../usr.bin/less
less_REALSRCDIR=/usr/home/freebsd/omega/src/usr.bin/less
less_OBJS= main.o screen.o brac.o ch.o charset.o cmdbuf.o command.o cvt.o decode.o edit.o filename.o forwback.o help.o ifile.o input.o jump.o line.o linenum.o lsystem.o mark.o optfunc.o option.o opttbl.o os.o output.o pattern.o position.o prompt.o search.o signal.o tags.o ttyin.o version.o
less_OPTS+= DIRPRFX=rescue/rescue/less/
less_make:
	(cd $(less_SRCDIR) && \
		$(CRUNCHMAKE) $(BUILDOPTS) $(less_OPTS) depend &&\
		$(CRUNCHMAKE) $(BUILDOPTS) $(less_OPTS) $(less_OBJS))
less_clean:
	(cd $(less_SRCDIR) && $(CRUNCHMAKE) $(BUILDOPTS) clean cleandepend)

less_stub.c:
	echo "int _crunched_less_stub(int argc, char **argv, char **envp){return main(argc,argv,envp);}" >less_stub.c
less.lo: less_stub.o $(less_OBJPATHS)
	$(CC) -nostdlib -Wl,-dc -r -o less.lo less_stub.o $(less_OBJPATHS)
	crunchide -k _crunched_less_stub less.lo

# -------- xz

xz_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/rescue/rescue//usr/home/freebsd/omega/src/usr.bin/xz
xz_OBJPATHS= $(xz_OBJDIR)/args.o $(xz_OBJDIR)/coder.o $(xz_OBJDIR)/file_io.o $(xz_OBJDIR)/hardware.o $(xz_OBJDIR)/list.o $(xz_OBJDIR)/main.o $(xz_OBJDIR)/message.o $(xz_OBJDIR)/mytime.o $(xz_OBJDIR)/options.o $(xz_OBJDIR)/signals.o $(xz_OBJDIR)/suffix.o $(xz_OBJDIR)/util.o $(xz_OBJDIR)/tuklib_open_stdxxx.o $(xz_OBJDIR)/tuklib_progname.o $(xz_OBJDIR)/tuklib_exit.o $(xz_OBJDIR)/tuklib_cpucores.o $(xz_OBJDIR)/tuklib_mbstr_width.o $(xz_OBJDIR)/tuklib_mbstr_fw.o
xz_SRCDIR=/usr/home/freebsd/omega/src/rescue/rescue/../../usr.bin/xz
xz_REALSRCDIR=/usr/home/freebsd/omega/src/usr.bin/xz
xz_OBJS= args.o coder.o file_io.o hardware.o list.o main.o message.o mytime.o options.o signals.o suffix.o util.o tuklib_open_stdxxx.o tuklib_progname.o tuklib_exit.o tuklib_cpucores.o tuklib_mbstr_width.o tuklib_mbstr_fw.o
xz_OPTS+= DIRPRFX=rescue/rescue/xz/
xz_make:
	(cd $(xz_SRCDIR) && \
		$(CRUNCHMAKE) $(BUILDOPTS) $(xz_OPTS) depend &&\
		$(CRUNCHMAKE) $(BUILDOPTS) $(xz_OPTS) $(xz_OBJS))
xz_clean:
	(cd $(xz_SRCDIR) && $(CRUNCHMAKE) $(BUILDOPTS) clean cleandepend)

xz_stub.c:
	echo "int _crunched_xz_stub(int argc, char **argv, char **envp){return main(argc,argv,envp);}" >xz_stub.c
xz.lo: xz_stub.o $(xz_OBJPATHS)
	$(CC) -nostdlib -Wl,-dc -r -o xz.lo xz_stub.o $(xz_OBJPATHS)
	crunchide -k _crunched_xz_stub xz.lo

# -------- tar

tar_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/rescue/rescue//usr/home/freebsd/omega/src/usr.bin/tar
tar_OBJPATHS= $(tar_OBJDIR)/bsdtar.o $(tar_OBJDIR)/cmdline.o $(tar_OBJDIR)/creation_set.o $(tar_OBJDIR)/read.o $(tar_OBJDIR)/subst.o $(tar_OBJDIR)/util.o $(tar_OBJDIR)/write.o $(tar_OBJDIR)/err.o $(tar_OBJDIR)/line_reader.o
tar_SRCDIR=/usr/home/freebsd/omega/src/rescue/rescue/../../usr.bin/tar
tar_REALSRCDIR=/usr/home/freebsd/omega/src/usr.bin/tar
tar_OBJS= bsdtar.o cmdline.o creation_set.o read.o subst.o util.o write.o err.o line_reader.o
tar_OPTS+= DIRPRFX=rescue/rescue/tar/
tar_make:
	(cd $(tar_SRCDIR) && \
		$(CRUNCHMAKE) $(BUILDOPTS) $(tar_OPTS) depend &&\
		$(CRUNCHMAKE) $(BUILDOPTS) $(tar_OPTS) $(tar_OBJS))
tar_clean:
	(cd $(tar_SRCDIR) && $(CRUNCHMAKE) $(BUILDOPTS) clean cleandepend)

tar_stub.c:
	echo "int _crunched_tar_stub(int argc, char **argv, char **envp){return main(argc,argv,envp);}" >tar_stub.c
tar.lo: tar_stub.o $(tar_OBJPATHS)
	$(CC) -nostdlib -Wl,-dc -r -o tar.lo tar_stub.o $(tar_OBJPATHS)
	crunchide -k _crunched_tar_stub tar.lo

# -------- vi

vi_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/rescue/rescue//usr/home/freebsd/omega/src/usr.bin/vi
vi_OBJPATHS= $(vi_OBJDIR)/cl_funcs.o $(vi_OBJDIR)/cl_main.o $(vi_OBJDIR)/cl_read.o $(vi_OBJDIR)/cl_screen.o $(vi_OBJDIR)/cl_term.o $(vi_OBJDIR)/conv.o $(vi_OBJDIR)/cut.o $(vi_OBJDIR)/delete.o $(vi_OBJDIR)/encoding.o $(vi_OBJDIR)/exf.o $(vi_OBJDIR)/key.o $(vi_OBJDIR)/line.o $(vi_OBJDIR)/log.o $(vi_OBJDIR)/main.o $(vi_OBJDIR)/mark.o $(vi_OBJDIR)/msg.o $(vi_OBJDIR)/options.o $(vi_OBJDIR)/options_f.o $(vi_OBJDIR)/put.o $(vi_OBJDIR)/recover.o $(vi_OBJDIR)/screen.o $(vi_OBJDIR)/search.o $(vi_OBJDIR)/seq.o $(vi_OBJDIR)/util.o $(vi_OBJDIR)/ex.o $(vi_OBJDIR)/ex_abbrev.o $(vi_OBJDIR)/ex_append.o $(vi_OBJDIR)/ex_args.o $(vi_OBJDIR)/ex_argv.o $(vi_OBJDIR)/ex_at.o $(vi_OBJDIR)/ex_bang.o $(vi_OBJDIR)/ex_cd.o $(vi_OBJDIR)/ex_cmd.o $(vi_OBJDIR)/ex_cscope.o $(vi_OBJDIR)/ex_delete.o $(vi_OBJDIR)/ex_display.o $(vi_OBJDIR)/ex_edit.o $(vi_OBJDIR)/ex_equal.o $(vi_OBJDIR)/ex_file.o $(vi_OBJDIR)/ex_filter.o $(vi_OBJDIR)/ex_global.o $(vi_OBJDIR)/ex_init.o $(vi_OBJDIR)/ex_join.o $(vi_OBJDIR)/ex_map.o $(vi_OBJDIR)/ex_mark.o $(vi_OBJDIR)/ex_mkexrc.o $(vi_OBJDIR)/ex_move.o $(vi_OBJDIR)/ex_open.o $(vi_OBJDIR)/ex_preserve.o $(vi_OBJDIR)/ex_print.o $(vi_OBJDIR)/ex_put.o $(vi_OBJDIR)/ex_quit.o $(vi_OBJDIR)/ex_read.o $(vi_OBJDIR)/ex_screen.o $(vi_OBJDIR)/ex_script.o $(vi_OBJDIR)/ex_set.o $(vi_OBJDIR)/ex_shell.o $(vi_OBJDIR)/ex_shift.o $(vi_OBJDIR)/ex_source.o $(vi_OBJDIR)/ex_stop.o $(vi_OBJDIR)/ex_subst.o $(vi_OBJDIR)/ex_tag.o $(vi_OBJDIR)/ex_txt.o $(vi_OBJDIR)/ex_undo.o $(vi_OBJDIR)/ex_usage.o $(vi_OBJDIR)/ex_util.o $(vi_OBJDIR)/ex_version.o $(vi_OBJDIR)/ex_visual.o $(vi_OBJDIR)/ex_write.o $(vi_OBJDIR)/ex_yank.o $(vi_OBJDIR)/ex_z.o $(vi_OBJDIR)/getc.o $(vi_OBJDIR)/v_at.o $(vi_OBJDIR)/v_ch.o $(vi_OBJDIR)/v_cmd.o $(vi_OBJDIR)/v_delete.o $(vi_OBJDIR)/v_ex.o $(vi_OBJDIR)/v_increment.o $(vi_OBJDIR)/v_init.o $(vi_OBJDIR)/v_itxt.o $(vi_OBJDIR)/v_left.o $(vi_OBJDIR)/v_mark.o $(vi_OBJDIR)/v_match.o $(vi_OBJDIR)/v_paragraph.o $(vi_OBJDIR)/v_put.o $(vi_OBJDIR)/v_redraw.o $(vi_OBJDIR)/v_replace.o $(vi_OBJDIR)/v_right.o $(vi_OBJDIR)/v_screen.o $(vi_OBJDIR)/v_scroll.o $(vi_OBJDIR)/v_search.o $(vi_OBJDIR)/v_section.o $(vi_OBJDIR)/v_sentence.o $(vi_OBJDIR)/v_status.o $(vi_OBJDIR)/v_txt.o $(vi_OBJDIR)/v_ulcase.o $(vi_OBJDIR)/v_undo.o $(vi_OBJDIR)/v_util.o $(vi_OBJDIR)/v_word.o $(vi_OBJDIR)/v_xchar.o $(vi_OBJDIR)/v_yank.o $(vi_OBJDIR)/v_z.o $(vi_OBJDIR)/v_zexit.o $(vi_OBJDIR)/vi.o $(vi_OBJDIR)/vs_line.o $(vi_OBJDIR)/vs_msg.o $(vi_OBJDIR)/vs_refresh.o $(vi_OBJDIR)/vs_relative.o $(vi_OBJDIR)/vs_smap.o $(vi_OBJDIR)/vs_split.o $(vi_OBJDIR)/regcomp.o $(vi_OBJDIR)/regerror.o $(vi_OBJDIR)/regexec.o $(vi_OBJDIR)/regfree.o
vi_SRCDIR=/usr/home/freebsd/omega/src/rescue/rescue/../../usr.bin/vi
vi_REALSRCDIR=/usr/home/freebsd/omega/src/usr.bin/vi
vi_OBJS= cl_funcs.o cl_main.o cl_read.o cl_screen.o cl_term.o conv.o cut.o delete.o encoding.o exf.o key.o line.o log.o main.o mark.o msg.o options.o options_f.o put.o recover.o screen.o search.o seq.o util.o ex.o ex_abbrev.o ex_append.o ex_args.o ex_argv.o ex_at.o ex_bang.o ex_cd.o ex_cmd.o ex_cscope.o ex_delete.o ex_display.o ex_edit.o ex_equal.o ex_file.o ex_filter.o ex_global.o ex_init.o ex_join.o ex_map.o ex_mark.o ex_mkexrc.o ex_move.o ex_open.o ex_preserve.o ex_print.o ex_put.o ex_quit.o ex_read.o ex_screen.o ex_script.o ex_set.o ex_shell.o ex_shift.o ex_source.o ex_stop.o ex_subst.o ex_tag.o ex_txt.o ex_undo.o ex_usage.o ex_util.o ex_version.o ex_visual.o ex_write.o ex_yank.o ex_z.o getc.o v_at.o v_ch.o v_cmd.o v_delete.o v_ex.o v_increment.o v_init.o v_itxt.o v_left.o v_mark.o v_match.o v_paragraph.o v_put.o v_redraw.o v_replace.o v_right.o v_screen.o v_scroll.o v_search.o v_section.o v_sentence.o v_status.o v_txt.o v_ulcase.o v_undo.o v_util.o v_word.o v_xchar.o v_yank.o v_z.o v_zexit.o vi.o vs_line.o vs_msg.o vs_refresh.o vs_relative.o vs_smap.o vs_split.o regcomp.o regerror.o regexec.o regfree.o
vi_OPTS+= DIRPRFX=rescue/rescue/vi/
vi_make:
	(cd $(vi_SRCDIR) && \
		$(CRUNCHMAKE) $(BUILDOPTS) $(vi_OPTS) depend &&\
		$(CRUNCHMAKE) $(BUILDOPTS) $(vi_OPTS) $(vi_OBJS))
vi_clean:
	(cd $(vi_SRCDIR) && $(CRUNCHMAKE) $(BUILDOPTS) clean cleandepend)

vi_stub.c:
	echo "int _crunched_vi_stub(int argc, char **argv, char **envp){return main(argc,argv,envp);}" >vi_stub.c
vi.lo: vi_stub.o $(vi_OBJPATHS)
	$(CC) -nostdlib -Wl,-dc -r -o vi.lo vi_stub.o $(vi_OBJPATHS)
	crunchide -k _crunched_vi_stub vi.lo

# -------- id

id_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/rescue/rescue//usr/home/freebsd/omega/src/usr.bin/id
id_OBJPATHS= $(id_OBJDIR)/id.o
id_SRCDIR=/usr/home/freebsd/omega/src/rescue/rescue/../../usr.bin/id
id_REALSRCDIR=/usr/home/freebsd/omega/src/usr.bin/id
id_OBJS= id.o
id_OPTS+= DIRPRFX=rescue/rescue/id/
id_make:
	(cd $(id_SRCDIR) && \
		$(CRUNCHMAKE) $(BUILDOPTS) $(id_OPTS) depend &&\
		$(CRUNCHMAKE) $(BUILDOPTS) $(id_OPTS) $(id_OBJS))
id_clean:
	(cd $(id_SRCDIR) && $(CRUNCHMAKE) $(BUILDOPTS) clean cleandepend)

id_stub.c:
	echo "int _crunched_id_stub(int argc, char **argv, char **envp){return main(argc,argv,envp);}" >id_stub.c
id.lo: id_stub.o $(id_OBJPATHS)
	$(CC) -nostdlib -Wl,-dc -r -o id.lo id_stub.o $(id_OBJPATHS)
	crunchide -k _crunched_id_stub id.lo

# -------- iscsictl

iscsictl_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/rescue/rescue//usr/home/freebsd/omega/src/usr.bin/iscsictl
iscsictl_OBJPATHS= $(iscsictl_OBJDIR)/iscsictl.o $(iscsictl_OBJDIR)/periphs.o $(iscsictl_OBJDIR)/parse.o $(iscsictl_OBJDIR)/token.o
iscsictl_SRCDIR=/usr/home/freebsd/omega/src/rescue/rescue/../../usr.bin/iscsictl
iscsictl_REALSRCDIR=/usr/home/freebsd/omega/src/usr.bin/iscsictl
iscsictl_OBJS= iscsictl.o periphs.o parse.o token.o
iscsictl_OPTS+= DIRPRFX=rescue/rescue/iscsictl/
iscsictl_make:
	(cd $(iscsictl_SRCDIR) && \
		$(CRUNCHMAKE) $(BUILDOPTS) $(iscsictl_OPTS) depend &&\
		$(CRUNCHMAKE) $(BUILDOPTS) $(iscsictl_OPTS) $(iscsictl_OBJS))
iscsictl_clean:
	(cd $(iscsictl_SRCDIR) && $(CRUNCHMAKE) $(BUILDOPTS) clean cleandepend)

iscsictl_stub.c:
	echo "int _crunched_iscsictl_stub(int argc, char **argv, char **envp){return main(argc,argv,envp);}" >iscsictl_stub.c
iscsictl.lo: iscsictl_stub.o $(iscsictl_OBJPATHS)
	$(CC) -nostdlib -Wl,-dc -r -o iscsictl.lo iscsictl_stub.o $(iscsictl_OBJPATHS)
	crunchide -k _crunched_iscsictl_stub iscsictl.lo

# -------- zdb

zdb_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/rescue/rescue//usr/home/freebsd/omega/src/cddl/usr.sbin/zdb
zdb_OBJPATHS= $(zdb_OBJDIR)/zdb.o $(zdb_OBJDIR)/zdb_il.o
zdb_SRCDIR=/usr/home/freebsd/omega/src/rescue/rescue/../../cddl/usr.sbin/zdb
zdb_REALSRCDIR=/usr/home/freebsd/omega/src/cddl/usr.sbin/zdb
zdb_OBJS= zdb.o zdb_il.o
zdb_OPTS+= DIRPRFX=rescue/rescue/zdb/
zdb_make:
	(cd $(zdb_SRCDIR) && \
		$(CRUNCHMAKE) $(BUILDOPTS) $(zdb_OPTS) depend &&\
		$(CRUNCHMAKE) $(BUILDOPTS) $(zdb_OPTS) $(zdb_OBJS))
zdb_clean:
	(cd $(zdb_SRCDIR) && $(CRUNCHMAKE) $(BUILDOPTS) clean cleandepend)

zdb_stub.c:
	echo "int _crunched_zdb_stub(int argc, char **argv, char **envp){return main(argc,argv,envp);}" >zdb_stub.c
zdb.lo: zdb_stub.o $(zdb_OBJPATHS)
	$(CC) -nostdlib -Wl,-dc -r -o zdb.lo zdb_stub.o $(zdb_OBJPATHS)
	crunchide -k _crunched_zdb_stub zdb.lo

# -------- chroot

chroot_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/rescue/rescue//usr/home/freebsd/omega/src/usr.sbin/chroot
chroot_OBJPATHS= $(chroot_OBJDIR)/chroot.o
chroot_SRCDIR=/usr/home/freebsd/omega/src/rescue/rescue/../../usr.sbin/chroot
chroot_REALSRCDIR=/usr/home/freebsd/omega/src/usr.sbin/chroot
chroot_OBJS= chroot.o
chroot_OPTS+= DIRPRFX=rescue/rescue/chroot/
chroot_make:
	(cd $(chroot_SRCDIR) && \
		$(CRUNCHMAKE) $(BUILDOPTS) $(chroot_OPTS) depend &&\
		$(CRUNCHMAKE) $(BUILDOPTS) $(chroot_OPTS) $(chroot_OBJS))
chroot_clean:
	(cd $(chroot_SRCDIR) && $(CRUNCHMAKE) $(BUILDOPTS) clean cleandepend)

chroot_stub.c:
	echo "int _crunched_chroot_stub(int argc, char **argv, char **envp){return main(argc,argv,envp);}" >chroot_stub.c
chroot.lo: chroot_stub.o $(chroot_OBJPATHS)
	$(CC) -nostdlib -Wl,-dc -r -o chroot.lo chroot_stub.o $(chroot_OBJPATHS)
	crunchide -k _crunched_chroot_stub chroot.lo

# -------- chown

chown_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/rescue/rescue//usr/home/freebsd/omega/src/usr.sbin/chown
chown_OBJPATHS= $(chown_OBJDIR)/chown.o
chown_SRCDIR=/usr/home/freebsd/omega/src/rescue/rescue/../../usr.sbin/chown
chown_REALSRCDIR=/usr/home/freebsd/omega/src/usr.sbin/chown
chown_OBJS= chown.o
chown_OPTS+= DIRPRFX=rescue/rescue/chown/
chown_make:
	(cd $(chown_SRCDIR) && \
		$(CRUNCHMAKE) $(BUILDOPTS) $(chown_OPTS) depend &&\
		$(CRUNCHMAKE) $(BUILDOPTS) $(chown_OPTS) $(chown_OBJS))
chown_clean:
	(cd $(chown_SRCDIR) && $(CRUNCHMAKE) $(BUILDOPTS) clean cleandepend)

chown_stub.c:
	echo "int _crunched_chown_stub(int argc, char **argv, char **envp){return main(argc,argv,envp);}" >chown_stub.c
chown.lo: chown_stub.o $(chown_OBJPATHS)
	$(CC) -nostdlib -Wl,-dc -r -o chown.lo chown_stub.o $(chown_OBJPATHS)
	crunchide -k _crunched_chown_stub chown.lo

# -------- iscsid

iscsid_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/rescue/rescue//usr/home/freebsd/omega/src/usr.sbin/iscsid
iscsid_OBJPATHS= $(iscsid_OBJDIR)/chap.o $(iscsid_OBJDIR)/discovery.o $(iscsid_OBJDIR)/iscsid.o $(iscsid_OBJDIR)/keys.o $(iscsid_OBJDIR)/log.o $(iscsid_OBJDIR)/login.o $(iscsid_OBJDIR)/pdu.o
iscsid_SRCDIR=/usr/home/freebsd/omega/src/rescue/rescue/../../usr.sbin/iscsid
iscsid_REALSRCDIR=/usr/home/freebsd/omega/src/usr.sbin/iscsid
iscsid_OBJS= chap.o discovery.o iscsid.o keys.o log.o login.o pdu.o
iscsid_OPTS+= DIRPRFX=rescue/rescue/iscsid/
iscsid_make:
	(cd $(iscsid_SRCDIR) && \
		$(CRUNCHMAKE) $(BUILDOPTS) $(iscsid_OPTS) depend &&\
		$(CRUNCHMAKE) $(BUILDOPTS) $(iscsid_OPTS) $(iscsid_OBJS))
iscsid_clean:
	(cd $(iscsid_SRCDIR) && $(CRUNCHMAKE) $(BUILDOPTS) clean cleandepend)

iscsid_stub.c:
	echo "int _crunched_iscsid_stub(int argc, char **argv, char **envp){return main(argc,argv,envp);}" >iscsid_stub.c
iscsid.lo: iscsid_stub.o $(iscsid_OBJPATHS)
	$(CC) -nostdlib -Wl,-dc -r -o iscsid.lo iscsid_stub.o $(iscsid_OBJPATHS)
	crunchide -k _crunched_iscsid_stub iscsid.lo

# ========
