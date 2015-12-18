# bsdbox.mk - generated from bsdbox.conf by crunchgen 0.2

LD?= ld
STRIPBIN?= strip
# NOTE: Some LIBS declarations below overridden by LIBS_SO
LIBS+= -lkvm -lmemstat -lnetgraph -lcrypt -ledit -ll -ltermcapw -lalias -lcam -lcursesw -ldevstat -lipsec -lgeom -lbsdxml -ljail -lkiconv -lmd -lsbuf -lufs -lbz2 -lm -lncursesw -lncurses -lelf -larchive -lz -llzma -lssl -lcrypto -lwrap -lpcap
LIBS_SO+= -lc -lutil -lcrypt -lxo -lgpio -lpam -lbsm -l80211
CRUNCHMAKE=$(MAKE)
BUILDOPTS+= -DRESCUE
CRUNCHED_OBJS= ls.lo cat.lo dd.lo df.lo cp.lo hostname.lo kill.lo mkdir.lo sleep.lo ps.lo ln.lo rm.lo kenv.lo mv.lo expr.lo sh.lo dmesg.lo sysctl.lo init.lo reboot.lo mount.lo umount.lo route.lo ping.lo ifconfig.lo kldload.lo kldunload.lo kldstat.lo mdmfs.lo mdconfig.lo newfs.lo true.lo false.lo hexdump.lo tail.lo nc.lo w.lo head.lo uname.lo tset.lo vmstat.lo cpio.lo tput.lo passwd.lo gzip.lo netstat.lo cap_mkdb.lo gpioctl.lo chown.lo arp.lo inetd.lo wlandebug.lo tcpdump.lo hostapd.lo hostapd_cli.lo pwd_mkdb.lo getty.lo
SUBMAKE_TARGETS= ls_make cat_make dd_make df_make cp_make hostname_make kill_make mkdir_make sleep_make ps_make ln_make rm_make kenv_make mv_make expr_make sh_make dmesg_make sysctl_make init_make reboot_make mount_make umount_make route_make ping_make ifconfig_make kldload_make kldunload_make kldstat_make mdmfs_make mdconfig_make newfs_make true_make false_make hexdump_make tail_make nc_make w_make head_make uname_make tset_make vmstat_make cpio_make tput_make passwd_make gzip_make netstat_make cap_mkdb_make gpioctl_make chown_make arp_make inetd_make wlandebug_make tcpdump_make hostapd_make hostapd_cli_make pwd_mkdb_make getty_make
SUBCLEAN_TARGETS= ls_clean cat_clean dd_clean df_clean cp_clean hostname_clean kill_clean mkdir_clean sleep_clean ps_clean ln_clean rm_clean kenv_clean mv_clean expr_clean sh_clean dmesg_clean sysctl_clean init_clean reboot_clean mount_clean umount_clean route_clean ping_clean ifconfig_clean kldload_clean kldunload_clean kldstat_clean mdmfs_clean mdconfig_clean newfs_clean true_clean false_clean hexdump_clean tail_clean nc_clean w_clean head_clean uname_clean tset_clean vmstat_clean cpio_clean tput_clean passwd_clean gzip_clean netstat_clean cap_mkdb_clean gpioctl_clean chown_clean arp_clean inetd_clean wlandebug_clean tcpdump_clean hostapd_clean hostapd_cli_clean pwd_mkdb_clean getty_clean

all: objs exe
objs: $(SUBMAKE_TARGETS)
exe: bsdbox
bsdbox: bsdbox.o $(CRUNCHED_OBJS) $(SUBMAKE_TARGETS)
.if defined(LIBS_SO) && !empty(LIBS_SO)
	$(CC) -o bsdbox bsdbox.o $(CRUNCHED_OBJS) \
		-Xlinker -Bstatic $(LIBS) \
		-Xlinker -Bdynamic $(LIBS_SO)
.else
	$(CC) -static -o bsdbox bsdbox.o $(CRUNCHED_OBJS) $(LIBS)
.endif
	$(STRIPBIN) bsdbox
realclean: clean subclean
clean:
	rm -f bsdbox *.lo *.o *_stub.c
subclean: $(SUBCLEAN_TARGETS)

# -------- ls

ls_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/tools/bsdbox//usr/home/freebsd/omega/src/bin/ls
ls_OBJPATHS= $(ls_OBJDIR)/cmp.o $(ls_OBJDIR)/ls.o $(ls_OBJDIR)/print.o $(ls_OBJDIR)/util.o
ls_SRCDIR=/usr/home/freebsd/omega/src/tools/bsdbox/../../bin/ls
ls_REALSRCDIR=/usr/home/freebsd/omega/src/bin/ls
ls_OBJS= cmp.o ls.o print.o util.o
ls_OPTS+= DIRPRFX=tools/bsdbox/ls/
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

# -------- cat

cat_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/tools/bsdbox//usr/home/freebsd/omega/src/bin/cat
cat_OBJPATHS= $(cat_OBJDIR)/cat.o
cat_SRCDIR=/usr/home/freebsd/omega/src/tools/bsdbox/../../bin/cat
cat_REALSRCDIR=/usr/home/freebsd/omega/src/bin/cat
cat_OBJS= cat.o
cat_OPTS+= DIRPRFX=tools/bsdbox/cat/
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

# -------- dd

dd_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/tools/bsdbox//usr/home/freebsd/omega/src/bin/dd
dd_OBJPATHS= $(dd_OBJDIR)/args.o $(dd_OBJDIR)/conv.o $(dd_OBJDIR)/conv_tab.o $(dd_OBJDIR)/dd.o $(dd_OBJDIR)/misc.o $(dd_OBJDIR)/position.o
dd_SRCDIR=/usr/home/freebsd/omega/src/tools/bsdbox/../../bin/dd
dd_REALSRCDIR=/usr/home/freebsd/omega/src/bin/dd
dd_OBJS= args.o conv.o conv_tab.o dd.o misc.o position.o
dd_OPTS+= DIRPRFX=tools/bsdbox/dd/
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

df_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/tools/bsdbox//usr/home/freebsd/omega/src/bin/df
df_OBJPATHS= $(df_OBJDIR)/df.o $(df_OBJDIR)/vfslist.o
df_SRCDIR=/usr/home/freebsd/omega/src/tools/bsdbox/../../bin/df
df_REALSRCDIR=/usr/home/freebsd/omega/src/bin/df
df_OBJS= df.o vfslist.o
df_OPTS+= DIRPRFX=tools/bsdbox/df/
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

# -------- cp

cp_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/tools/bsdbox//usr/home/freebsd/omega/src/bin/cp
cp_OBJPATHS= $(cp_OBJDIR)/cp.o $(cp_OBJDIR)/utils.o
cp_SRCDIR=/usr/home/freebsd/omega/src/tools/bsdbox/../../bin/cp
cp_REALSRCDIR=/usr/home/freebsd/omega/src/bin/cp
cp_OBJS= cp.o utils.o
cp_OPTS+= DIRPRFX=tools/bsdbox/cp/
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

# -------- hostname

hostname_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/tools/bsdbox//usr/home/freebsd/omega/src/bin/hostname
hostname_OBJPATHS= $(hostname_OBJDIR)/hostname.o
hostname_SRCDIR=/usr/home/freebsd/omega/src/tools/bsdbox/../../bin/hostname
hostname_REALSRCDIR=/usr/home/freebsd/omega/src/bin/hostname
hostname_OBJS= hostname.o
hostname_OPTS+= DIRPRFX=tools/bsdbox/hostname/
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

# -------- kill

kill_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/tools/bsdbox//usr/home/freebsd/omega/src/bin/kill
kill_OBJPATHS= $(kill_OBJDIR)/kill.o
kill_SRCDIR=/usr/home/freebsd/omega/src/tools/bsdbox/../../bin/kill
kill_REALSRCDIR=/usr/home/freebsd/omega/src/bin/kill
kill_OBJS= kill.o
kill_OPTS+= DIRPRFX=tools/bsdbox/kill/
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

# -------- mkdir

mkdir_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/tools/bsdbox//usr/home/freebsd/omega/src/bin/mkdir
mkdir_OBJPATHS= $(mkdir_OBJDIR)/mkdir.o
mkdir_SRCDIR=/usr/home/freebsd/omega/src/tools/bsdbox/../../bin/mkdir
mkdir_REALSRCDIR=/usr/home/freebsd/omega/src/bin/mkdir
mkdir_OBJS= mkdir.o
mkdir_OPTS+= DIRPRFX=tools/bsdbox/mkdir/
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

# -------- sleep

sleep_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/tools/bsdbox//usr/home/freebsd/omega/src/bin/sleep
sleep_OBJPATHS= $(sleep_OBJDIR)/sleep.o
sleep_SRCDIR=/usr/home/freebsd/omega/src/tools/bsdbox/../../bin/sleep
sleep_REALSRCDIR=/usr/home/freebsd/omega/src/bin/sleep
sleep_OBJS= sleep.o
sleep_OPTS+= DIRPRFX=tools/bsdbox/sleep/
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

# -------- ps

ps_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/tools/bsdbox//usr/home/freebsd/omega/src/bin/ps
ps_OBJPATHS= $(ps_OBJDIR)/fmt.o $(ps_OBJDIR)/keyword.o $(ps_OBJDIR)/nlist.o $(ps_OBJDIR)/print.o $(ps_OBJDIR)/ps.o
ps_SRCDIR=/usr/home/freebsd/omega/src/tools/bsdbox/../../bin/ps
ps_REALSRCDIR=/usr/home/freebsd/omega/src/bin/ps
ps_OBJS= fmt.o keyword.o nlist.o print.o ps.o
ps_OPTS+= DIRPRFX=tools/bsdbox/ps/
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

# -------- ln

ln_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/tools/bsdbox//usr/home/freebsd/omega/src/bin/ln
ln_OBJPATHS= $(ln_OBJDIR)/ln.o
ln_SRCDIR=/usr/home/freebsd/omega/src/tools/bsdbox/../../bin/ln
ln_REALSRCDIR=/usr/home/freebsd/omega/src/bin/ln
ln_OBJS= ln.o
ln_OPTS+= DIRPRFX=tools/bsdbox/ln/
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

# -------- rm

rm_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/tools/bsdbox//usr/home/freebsd/omega/src/bin/rm
rm_OBJPATHS= $(rm_OBJDIR)/rm.o
rm_SRCDIR=/usr/home/freebsd/omega/src/tools/bsdbox/../../bin/rm
rm_REALSRCDIR=/usr/home/freebsd/omega/src/bin/rm
rm_OBJS= rm.o
rm_OPTS+= DIRPRFX=tools/bsdbox/rm/
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

# -------- kenv

kenv_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/tools/bsdbox//usr/home/freebsd/omega/src/bin/kenv
kenv_OBJPATHS= $(kenv_OBJDIR)/kenv.o
kenv_SRCDIR=/usr/home/freebsd/omega/src/tools/bsdbox/../../bin/kenv
kenv_REALSRCDIR=/usr/home/freebsd/omega/src/bin/kenv
kenv_OBJS= kenv.o
kenv_OPTS+= DIRPRFX=tools/bsdbox/kenv/
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

# -------- mv

mv_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/tools/bsdbox//usr/home/freebsd/omega/src/bin/mv
mv_OBJPATHS= $(mv_OBJDIR)/mv.o
mv_SRCDIR=/usr/home/freebsd/omega/src/tools/bsdbox/../../bin/mv
mv_REALSRCDIR=/usr/home/freebsd/omega/src/bin/mv
mv_OBJS= mv.o
mv_OPTS+= DIRPRFX=tools/bsdbox/mv/
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

# -------- expr

expr_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/tools/bsdbox//usr/home/freebsd/omega/src/bin/expr
expr_OBJPATHS= $(expr_OBJDIR)/expr.o
expr_SRCDIR=/usr/home/freebsd/omega/src/tools/bsdbox/../../bin/expr
expr_REALSRCDIR=/usr/home/freebsd/omega/src/bin/expr
expr_OBJS= expr.o
expr_OPTS+= DIRPRFX=tools/bsdbox/expr/
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

# -------- sh

sh_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/tools/bsdbox//usr/home/freebsd/omega/src/bin/sh
sh_OBJPATHS= $(sh_OBJDIR)/alias.o $(sh_OBJDIR)/arith_yacc.o $(sh_OBJDIR)/arith_yylex.o $(sh_OBJDIR)/cd.o $(sh_OBJDIR)/echo.o $(sh_OBJDIR)/error.o $(sh_OBJDIR)/eval.o $(sh_OBJDIR)/exec.o $(sh_OBJDIR)/expand.o $(sh_OBJDIR)/histedit.o $(sh_OBJDIR)/input.o $(sh_OBJDIR)/jobs.o $(sh_OBJDIR)/kill.o $(sh_OBJDIR)/mail.o $(sh_OBJDIR)/main.o $(sh_OBJDIR)/memalloc.o $(sh_OBJDIR)/miscbltin.o $(sh_OBJDIR)/mystring.o $(sh_OBJDIR)/options.o $(sh_OBJDIR)/output.o $(sh_OBJDIR)/parser.o $(sh_OBJDIR)/printf.o $(sh_OBJDIR)/redir.o $(sh_OBJDIR)/show.o $(sh_OBJDIR)/test.o $(sh_OBJDIR)/trap.o $(sh_OBJDIR)/var.o $(sh_OBJDIR)/builtins.o $(sh_OBJDIR)/nodes.o $(sh_OBJDIR)/syntax.o
sh_SRCDIR=/usr/home/freebsd/omega/src/tools/bsdbox/../../bin/sh
sh_REALSRCDIR=/usr/home/freebsd/omega/src/bin/sh
sh_OBJS= alias.o arith_yacc.o arith_yylex.o cd.o echo.o error.o eval.o exec.o expand.o histedit.o input.o jobs.o kill.o mail.o main.o memalloc.o miscbltin.o mystring.o options.o output.o parser.o printf.o redir.o show.o test.o trap.o var.o builtins.o nodes.o syntax.o
sh_OPTS+= DIRPRFX=tools/bsdbox/sh/
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

# -------- dmesg

dmesg_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/tools/bsdbox//usr/home/freebsd/omega/src/sbin/dmesg
dmesg_OBJPATHS= $(dmesg_OBJDIR)/dmesg.o
dmesg_SRCDIR=/usr/home/freebsd/omega/src/tools/bsdbox/../../sbin/dmesg
dmesg_REALSRCDIR=/usr/home/freebsd/omega/src/sbin/dmesg
dmesg_OBJS= dmesg.o
dmesg_OPTS+= DIRPRFX=tools/bsdbox/dmesg/
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

# -------- sysctl

sysctl_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/tools/bsdbox//usr/home/freebsd/omega/src/sbin/sysctl
sysctl_OBJPATHS= $(sysctl_OBJDIR)/sysctl.o
sysctl_SRCDIR=/usr/home/freebsd/omega/src/tools/bsdbox/../../sbin/sysctl
sysctl_REALSRCDIR=/usr/home/freebsd/omega/src/sbin/sysctl
sysctl_OBJS= sysctl.o
sysctl_OPTS+= DIRPRFX=tools/bsdbox/sysctl/
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

# -------- init

init_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/tools/bsdbox//usr/home/freebsd/omega/src/sbin/init
init_OBJPATHS= $(init_OBJDIR)/init.o $(init_OBJDIR)/getmntopts.o
init_SRCDIR=/usr/home/freebsd/omega/src/tools/bsdbox/../../sbin/init
init_REALSRCDIR=/usr/home/freebsd/omega/src/sbin/init
init_OBJS= init.o getmntopts.o
init_OPTS+= DIRPRFX=tools/bsdbox/init/
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

# -------- reboot

reboot_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/tools/bsdbox//usr/home/freebsd/omega/src/sbin/reboot
reboot_OBJPATHS= $(reboot_OBJDIR)/reboot.o
reboot_SRCDIR=/usr/home/freebsd/omega/src/tools/bsdbox/../../sbin/reboot
reboot_REALSRCDIR=/usr/home/freebsd/omega/src/sbin/reboot
reboot_OBJS= reboot.o
reboot_OPTS+= DIRPRFX=tools/bsdbox/reboot/
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

# -------- mount

mount_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/tools/bsdbox//usr/home/freebsd/omega/src/sbin/mount
mount_OBJPATHS= $(mount_OBJDIR)/mount.o $(mount_OBJDIR)/mount_fs.o $(mount_OBJDIR)/getmntopts.o $(mount_OBJDIR)/vfslist.o
mount_SRCDIR=/usr/home/freebsd/omega/src/tools/bsdbox/../../sbin/mount
mount_REALSRCDIR=/usr/home/freebsd/omega/src/sbin/mount
mount_OBJS= mount.o mount_fs.o getmntopts.o vfslist.o
mount_OPTS+= DIRPRFX=tools/bsdbox/mount/
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

# -------- umount

umount_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/tools/bsdbox//usr/home/freebsd/omega/src/sbin/umount
umount_OBJPATHS= $(umount_OBJDIR)/umount.o $(umount_OBJDIR)/vfslist.o $(umount_OBJDIR)/mounttab.o
umount_SRCDIR=/usr/home/freebsd/omega/src/tools/bsdbox/../../sbin/umount
umount_REALSRCDIR=/usr/home/freebsd/omega/src/sbin/umount
umount_OBJS= umount.o vfslist.o mounttab.o
umount_OPTS+= DIRPRFX=tools/bsdbox/umount/
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

# -------- route

route_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/tools/bsdbox//usr/home/freebsd/omega/src/sbin/route
route_OBJPATHS= $(route_OBJDIR)/route.o
route_SRCDIR=/usr/home/freebsd/omega/src/tools/bsdbox/../../sbin/route
route_REALSRCDIR=/usr/home/freebsd/omega/src/sbin/route
route_OBJS= route.o
route_OPTS+= DIRPRFX=tools/bsdbox/route/
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

# -------- ping

ping_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/tools/bsdbox//usr/home/freebsd/omega/src/sbin/ping
ping_OBJPATHS= $(ping_OBJDIR)/ping.o
ping_SRCDIR=/usr/home/freebsd/omega/src/tools/bsdbox/../../sbin/ping
ping_REALSRCDIR=/usr/home/freebsd/omega/src/sbin/ping
ping_OBJS= ping.o
ping_OPTS+= DIRPRFX=tools/bsdbox/ping/
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

# -------- ifconfig

ifconfig_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/tools/bsdbox//usr/home/freebsd/omega/src/sbin/ifconfig
ifconfig_OBJPATHS= $(ifconfig_OBJDIR)/ifconfig.o $(ifconfig_OBJDIR)/af_link.o $(ifconfig_OBJDIR)/af_inet.o $(ifconfig_OBJDIR)/af_inet6.o $(ifconfig_OBJDIR)/af_nd6.o $(ifconfig_OBJDIR)/ifclone.o $(ifconfig_OBJDIR)/ifmac.o $(ifconfig_OBJDIR)/ifmedia.o $(ifconfig_OBJDIR)/iffib.o $(ifconfig_OBJDIR)/ifvlan.o $(ifconfig_OBJDIR)/ifvxlan.o $(ifconfig_OBJDIR)/ifgre.o $(ifconfig_OBJDIR)/ifgif.o $(ifconfig_OBJDIR)/sfp.o $(ifconfig_OBJDIR)/ifieee80211.o $(ifconfig_OBJDIR)/carp.o $(ifconfig_OBJDIR)/ifgroup.o $(ifconfig_OBJDIR)/ifpfsync.o $(ifconfig_OBJDIR)/ifbridge.o $(ifconfig_OBJDIR)/iflagg.o
ifconfig_SRCDIR=/usr/home/freebsd/omega/src/tools/bsdbox/../../sbin/ifconfig
ifconfig_REALSRCDIR=/usr/home/freebsd/omega/src/sbin/ifconfig
ifconfig_OBJS= ifconfig.o af_link.o af_inet.o af_inet6.o af_nd6.o ifclone.o ifmac.o ifmedia.o iffib.o ifvlan.o ifvxlan.o ifgre.o ifgif.o sfp.o ifieee80211.o carp.o ifgroup.o ifpfsync.o ifbridge.o iflagg.o
ifconfig_OPTS+= DIRPRFX=tools/bsdbox/ifconfig/
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

# -------- kldload

kldload_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/tools/bsdbox//usr/home/freebsd/omega/src/sbin/kldload
kldload_OBJPATHS= $(kldload_OBJDIR)/kldload.o
kldload_SRCDIR=/usr/home/freebsd/omega/src/tools/bsdbox/../../sbin/kldload
kldload_REALSRCDIR=/usr/home/freebsd/omega/src/sbin/kldload
kldload_OBJS= kldload.o
kldload_OPTS+= DIRPRFX=tools/bsdbox/kldload/
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

# -------- kldunload

kldunload_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/tools/bsdbox//usr/home/freebsd/omega/src/sbin/kldunload
kldunload_OBJPATHS= $(kldunload_OBJDIR)/kldunload.o
kldunload_SRCDIR=/usr/home/freebsd/omega/src/tools/bsdbox/../../sbin/kldunload
kldunload_REALSRCDIR=/usr/home/freebsd/omega/src/sbin/kldunload
kldunload_OBJS= kldunload.o
kldunload_OPTS+= DIRPRFX=tools/bsdbox/kldunload/
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

# -------- kldstat

kldstat_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/tools/bsdbox//usr/home/freebsd/omega/src/sbin/kldstat
kldstat_OBJPATHS= $(kldstat_OBJDIR)/kldstat.o
kldstat_SRCDIR=/usr/home/freebsd/omega/src/tools/bsdbox/../../sbin/kldstat
kldstat_REALSRCDIR=/usr/home/freebsd/omega/src/sbin/kldstat
kldstat_OBJS= kldstat.o
kldstat_OPTS+= DIRPRFX=tools/bsdbox/kldstat/
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

# -------- mdmfs

mdmfs_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/tools/bsdbox//usr/home/freebsd/omega/src/sbin/mdmfs
mdmfs_OBJPATHS= $(mdmfs_OBJDIR)/mdmfs.o
mdmfs_SRCDIR=/usr/home/freebsd/omega/src/tools/bsdbox/../../sbin/mdmfs
mdmfs_REALSRCDIR=/usr/home/freebsd/omega/src/sbin/mdmfs
mdmfs_OBJS= mdmfs.o
mdmfs_OPTS+= DIRPRFX=tools/bsdbox/mdmfs/
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

# -------- mdconfig

mdconfig_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/tools/bsdbox//usr/home/freebsd/omega/src/sbin/mdconfig
mdconfig_OBJPATHS= $(mdconfig_OBJDIR)/mdconfig.o
mdconfig_SRCDIR=/usr/home/freebsd/omega/src/tools/bsdbox/../../sbin/mdconfig
mdconfig_REALSRCDIR=/usr/home/freebsd/omega/src/sbin/mdconfig
mdconfig_OBJS= mdconfig.o
mdconfig_OPTS+= DIRPRFX=tools/bsdbox/mdconfig/
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

# -------- newfs

newfs_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/tools/bsdbox//usr/home/freebsd/omega/src/sbin/newfs
newfs_OBJPATHS= $(newfs_OBJDIR)/newfs.o $(newfs_OBJDIR)/mkfs.o $(newfs_OBJDIR)/geom_bsd_enc.o
newfs_SRCDIR=/usr/home/freebsd/omega/src/tools/bsdbox/../../sbin/newfs
newfs_REALSRCDIR=/usr/home/freebsd/omega/src/sbin/newfs
newfs_OBJS= newfs.o mkfs.o geom_bsd_enc.o
newfs_OPTS+= DIRPRFX=tools/bsdbox/newfs/
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

# -------- true

true_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/tools/bsdbox//usr/home/freebsd/omega/src/usr.bin/true
true_OBJPATHS= $(true_OBJDIR)/true.o
true_SRCDIR=/usr/home/freebsd/omega/src/tools/bsdbox/../../usr.bin/true
true_REALSRCDIR=/usr/home/freebsd/omega/src/usr.bin/true
true_OBJS= true.o
true_OPTS+= DIRPRFX=tools/bsdbox/true/
true_make:
	(cd $(true_SRCDIR) && \
		$(CRUNCHMAKE) $(BUILDOPTS) $(true_OPTS) depend &&\
		$(CRUNCHMAKE) $(BUILDOPTS) $(true_OPTS) $(true_OBJS))
true_clean:
	(cd $(true_SRCDIR) && $(CRUNCHMAKE) $(BUILDOPTS) clean cleandepend)

true_stub.c:
	echo "int _crunched_true_stub(int argc, char **argv, char **envp){return main(argc,argv,envp);}" >true_stub.c
true.lo: true_stub.o $(true_OBJPATHS)
	$(CC) -nostdlib -Wl,-dc -r -o true.lo true_stub.o $(true_OBJPATHS)
	crunchide -k _crunched_true_stub true.lo

# -------- false

false_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/tools/bsdbox//usr/home/freebsd/omega/src/usr.bin/false
false_OBJPATHS= $(false_OBJDIR)/false.o
false_SRCDIR=/usr/home/freebsd/omega/src/tools/bsdbox/../../usr.bin/false
false_REALSRCDIR=/usr/home/freebsd/omega/src/usr.bin/false
false_OBJS= false.o
false_OPTS+= DIRPRFX=tools/bsdbox/false/
false_make:
	(cd $(false_SRCDIR) && \
		$(CRUNCHMAKE) $(BUILDOPTS) $(false_OPTS) depend &&\
		$(CRUNCHMAKE) $(BUILDOPTS) $(false_OPTS) $(false_OBJS))
false_clean:
	(cd $(false_SRCDIR) && $(CRUNCHMAKE) $(BUILDOPTS) clean cleandepend)

false_stub.c:
	echo "int _crunched_false_stub(int argc, char **argv, char **envp){return main(argc,argv,envp);}" >false_stub.c
false.lo: false_stub.o $(false_OBJPATHS)
	$(CC) -nostdlib -Wl,-dc -r -o false.lo false_stub.o $(false_OBJPATHS)
	crunchide -k _crunched_false_stub false.lo

# -------- hexdump

hexdump_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/tools/bsdbox//usr/home/freebsd/omega/src/usr.bin/hexdump
hexdump_OBJPATHS= $(hexdump_OBJDIR)/conv.o $(hexdump_OBJDIR)/display.o $(hexdump_OBJDIR)/hexdump.o $(hexdump_OBJDIR)/hexsyntax.o $(hexdump_OBJDIR)/odsyntax.o $(hexdump_OBJDIR)/parse.o
hexdump_SRCDIR=/usr/home/freebsd/omega/src/tools/bsdbox/../../usr.bin/hexdump
hexdump_REALSRCDIR=/usr/home/freebsd/omega/src/usr.bin/hexdump
hexdump_OBJS= conv.o display.o hexdump.o hexsyntax.o odsyntax.o parse.o
hexdump_OPTS+= DIRPRFX=tools/bsdbox/hexdump/
hexdump_make:
	(cd $(hexdump_SRCDIR) && \
		$(CRUNCHMAKE) $(BUILDOPTS) $(hexdump_OPTS) depend &&\
		$(CRUNCHMAKE) $(BUILDOPTS) $(hexdump_OPTS) $(hexdump_OBJS))
hexdump_clean:
	(cd $(hexdump_SRCDIR) && $(CRUNCHMAKE) $(BUILDOPTS) clean cleandepend)

hexdump_stub.c:
	echo "int _crunched_hexdump_stub(int argc, char **argv, char **envp){return main(argc,argv,envp);}" >hexdump_stub.c
hexdump.lo: hexdump_stub.o $(hexdump_OBJPATHS)
	$(CC) -nostdlib -Wl,-dc -r -o hexdump.lo hexdump_stub.o $(hexdump_OBJPATHS)
	crunchide -k _crunched_hexdump_stub hexdump.lo

# -------- tail

tail_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/tools/bsdbox//usr/home/freebsd/omega/src/usr.bin/tail
tail_OBJPATHS= $(tail_OBJDIR)/forward.o $(tail_OBJDIR)/misc.o $(tail_OBJDIR)/read.o $(tail_OBJDIR)/reverse.o $(tail_OBJDIR)/tail.o
tail_SRCDIR=/usr/home/freebsd/omega/src/tools/bsdbox/../../usr.bin/tail
tail_REALSRCDIR=/usr/home/freebsd/omega/src/usr.bin/tail
tail_OBJS= forward.o misc.o read.o reverse.o tail.o
tail_OPTS+= DIRPRFX=tools/bsdbox/tail/
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

# -------- nc

nc_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/tools/bsdbox//usr/home/freebsd/omega/src/usr.bin/nc
nc_OBJPATHS= $(nc_OBJDIR)/netcat.o $(nc_OBJDIR)/atomicio.o $(nc_OBJDIR)/socks.o
nc_SRCDIR=/usr/home/freebsd/omega/src/tools/bsdbox/../../usr.bin/nc
nc_REALSRCDIR=/usr/home/freebsd/omega/src/usr.bin/nc
nc_OBJS= netcat.o atomicio.o socks.o
nc_OPTS+= DIRPRFX=tools/bsdbox/nc/
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

# -------- w

w_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/tools/bsdbox//usr/home/freebsd/omega/src/usr.bin/w
w_OBJPATHS= $(w_OBJDIR)/fmt.o $(w_OBJDIR)/pr_time.o $(w_OBJDIR)/proc_compare.o $(w_OBJDIR)/w.o
w_SRCDIR=/usr/home/freebsd/omega/src/tools/bsdbox/../../usr.bin/w
w_REALSRCDIR=/usr/home/freebsd/omega/src/usr.bin/w
w_OBJS= fmt.o pr_time.o proc_compare.o w.o
w_OPTS+= DIRPRFX=tools/bsdbox/w/
w_make:
	(cd $(w_SRCDIR) && \
		$(CRUNCHMAKE) $(BUILDOPTS) $(w_OPTS) depend &&\
		$(CRUNCHMAKE) $(BUILDOPTS) $(w_OPTS) $(w_OBJS))
w_clean:
	(cd $(w_SRCDIR) && $(CRUNCHMAKE) $(BUILDOPTS) clean cleandepend)

w_stub.c:
	echo "int _crunched_w_stub(int argc, char **argv, char **envp){return main(argc,argv,envp);}" >w_stub.c
w.lo: w_stub.o $(w_OBJPATHS)
	$(CC) -nostdlib -Wl,-dc -r -o w.lo w_stub.o $(w_OBJPATHS)
	crunchide -k _crunched_w_stub w.lo

# -------- head

head_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/tools/bsdbox//usr/home/freebsd/omega/src/usr.bin/head
head_OBJPATHS= $(head_OBJDIR)/head.o
head_SRCDIR=/usr/home/freebsd/omega/src/tools/bsdbox/../../usr.bin/head
head_REALSRCDIR=/usr/home/freebsd/omega/src/usr.bin/head
head_OBJS= head.o
head_OPTS+= DIRPRFX=tools/bsdbox/head/
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

# -------- uname

uname_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/tools/bsdbox//usr/home/freebsd/omega/src/usr.bin/uname
uname_OBJPATHS= $(uname_OBJDIR)/uname.o
uname_SRCDIR=/usr/home/freebsd/omega/src/tools/bsdbox/../../usr.bin/uname
uname_REALSRCDIR=/usr/home/freebsd/omega/src/usr.bin/uname
uname_OBJS= uname.o
uname_OPTS+= DIRPRFX=tools/bsdbox/uname/
uname_make:
	(cd $(uname_SRCDIR) && \
		$(CRUNCHMAKE) $(BUILDOPTS) $(uname_OPTS) depend &&\
		$(CRUNCHMAKE) $(BUILDOPTS) $(uname_OPTS) $(uname_OBJS))
uname_clean:
	(cd $(uname_SRCDIR) && $(CRUNCHMAKE) $(BUILDOPTS) clean cleandepend)

uname_stub.c:
	echo "int _crunched_uname_stub(int argc, char **argv, char **envp){return main(argc,argv,envp);}" >uname_stub.c
uname.lo: uname_stub.o $(uname_OBJPATHS)
	$(CC) -nostdlib -Wl,-dc -r -o uname.lo uname_stub.o $(uname_OBJPATHS)
	crunchide -k _crunched_uname_stub uname.lo

# -------- tset

tset_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/tools/bsdbox//usr/home/freebsd/omega/src/usr.bin/tset
tset_OBJPATHS= $(tset_OBJDIR)/map.o $(tset_OBJDIR)/misc.o $(tset_OBJDIR)/set.o $(tset_OBJDIR)/term.o $(tset_OBJDIR)/tset.o $(tset_OBJDIR)/wrterm.o
tset_SRCDIR=/usr/home/freebsd/omega/src/tools/bsdbox/../../usr.bin/tset
tset_REALSRCDIR=/usr/home/freebsd/omega/src/usr.bin/tset
tset_OBJS= map.o misc.o set.o term.o tset.o wrterm.o
tset_OPTS+= DIRPRFX=tools/bsdbox/tset/
tset_make:
	(cd $(tset_SRCDIR) && \
		$(CRUNCHMAKE) $(BUILDOPTS) $(tset_OPTS) depend &&\
		$(CRUNCHMAKE) $(BUILDOPTS) $(tset_OPTS) $(tset_OBJS))
tset_clean:
	(cd $(tset_SRCDIR) && $(CRUNCHMAKE) $(BUILDOPTS) clean cleandepend)

tset_stub.c:
	echo "int _crunched_tset_stub(int argc, char **argv, char **envp){return main(argc,argv,envp);}" >tset_stub.c
tset.lo: tset_stub.o $(tset_OBJPATHS)
	$(CC) -nostdlib -Wl,-dc -r -o tset.lo tset_stub.o $(tset_OBJPATHS)
	crunchide -k _crunched_tset_stub tset.lo

# -------- vmstat

vmstat_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/tools/bsdbox//usr/home/freebsd/omega/src/usr.bin/vmstat
vmstat_OBJPATHS= $(vmstat_OBJDIR)/vmstat.o
vmstat_SRCDIR=/usr/home/freebsd/omega/src/tools/bsdbox/../../usr.bin/vmstat
vmstat_REALSRCDIR=/usr/home/freebsd/omega/src/usr.bin/vmstat
vmstat_OBJS= vmstat.o
vmstat_OPTS+= DIRPRFX=tools/bsdbox/vmstat/
vmstat_make:
	(cd $(vmstat_SRCDIR) && \
		$(CRUNCHMAKE) $(BUILDOPTS) $(vmstat_OPTS) depend &&\
		$(CRUNCHMAKE) $(BUILDOPTS) $(vmstat_OPTS) $(vmstat_OBJS))
vmstat_clean:
	(cd $(vmstat_SRCDIR) && $(CRUNCHMAKE) $(BUILDOPTS) clean cleandepend)

vmstat_stub.c:
	echo "int _crunched_vmstat_stub(int argc, char **argv, char **envp){return main(argc,argv,envp);}" >vmstat_stub.c
vmstat.lo: vmstat_stub.o $(vmstat_OBJPATHS)
	$(CC) -nostdlib -Wl,-dc -r -o vmstat.lo vmstat_stub.o $(vmstat_OBJPATHS)
	crunchide -k _crunched_vmstat_stub vmstat.lo

# -------- cpio

cpio_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/tools/bsdbox//usr/home/freebsd/omega/src/usr.bin/cpio
cpio_OBJPATHS= $(cpio_OBJDIR)/cpio.o $(cpio_OBJDIR)/cmdline.o $(cpio_OBJDIR)/err.o $(cpio_OBJDIR)/line_reader.o
cpio_SRCDIR=/usr/home/freebsd/omega/src/tools/bsdbox/../../usr.bin/cpio
cpio_REALSRCDIR=/usr/home/freebsd/omega/src/usr.bin/cpio
cpio_OBJS= cpio.o cmdline.o err.o line_reader.o
cpio_OPTS+= DIRPRFX=tools/bsdbox/cpio/
cpio_make:
	(cd $(cpio_SRCDIR) && \
		$(CRUNCHMAKE) $(BUILDOPTS) $(cpio_OPTS) depend &&\
		$(CRUNCHMAKE) $(BUILDOPTS) $(cpio_OPTS) $(cpio_OBJS))
cpio_clean:
	(cd $(cpio_SRCDIR) && $(CRUNCHMAKE) $(BUILDOPTS) clean cleandepend)

cpio_stub.c:
	echo "int _crunched_cpio_stub(int argc, char **argv, char **envp){return main(argc,argv,envp);}" >cpio_stub.c
cpio.lo: cpio_stub.o $(cpio_OBJPATHS)
	$(CC) -nostdlib -Wl,-dc -r -o cpio.lo cpio_stub.o $(cpio_OBJPATHS)
	crunchide -k _crunched_cpio_stub cpio.lo

# -------- tput

tput_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/tools/bsdbox//usr/home/freebsd/omega/src/usr.bin/tput
tput_OBJPATHS= $(tput_OBJDIR)/tput.o
tput_SRCDIR=/usr/home/freebsd/omega/src/tools/bsdbox/../../usr.bin/tput
tput_REALSRCDIR=/usr/home/freebsd/omega/src/usr.bin/tput
tput_OBJS= tput.o
tput_OPTS+= DIRPRFX=tools/bsdbox/tput/
tput_make:
	(cd $(tput_SRCDIR) && \
		$(CRUNCHMAKE) $(BUILDOPTS) $(tput_OPTS) depend &&\
		$(CRUNCHMAKE) $(BUILDOPTS) $(tput_OPTS) $(tput_OBJS))
tput_clean:
	(cd $(tput_SRCDIR) && $(CRUNCHMAKE) $(BUILDOPTS) clean cleandepend)

tput_stub.c:
	echo "int _crunched_tput_stub(int argc, char **argv, char **envp){return main(argc,argv,envp);}" >tput_stub.c
tput.lo: tput_stub.o $(tput_OBJPATHS)
	$(CC) -nostdlib -Wl,-dc -r -o tput.lo tput_stub.o $(tput_OBJPATHS)
	crunchide -k _crunched_tput_stub tput.lo

# -------- passwd

passwd_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/tools/bsdbox//usr/home/freebsd/omega/src/usr.bin/passwd
passwd_OBJPATHS= $(passwd_OBJDIR)/passwd.o
passwd_SRCDIR=/usr/home/freebsd/omega/src/tools/bsdbox/../../usr.bin/passwd
passwd_REALSRCDIR=/usr/home/freebsd/omega/src/usr.bin/passwd
passwd_OBJS= passwd.o
passwd_OPTS+= DIRPRFX=tools/bsdbox/passwd/
passwd_make:
	(cd $(passwd_SRCDIR) && \
		$(CRUNCHMAKE) $(BUILDOPTS) $(passwd_OPTS) depend &&\
		$(CRUNCHMAKE) $(BUILDOPTS) $(passwd_OPTS) $(passwd_OBJS))
passwd_clean:
	(cd $(passwd_SRCDIR) && $(CRUNCHMAKE) $(BUILDOPTS) clean cleandepend)

passwd_stub.c:
	echo "int _crunched_passwd_stub(int argc, char **argv, char **envp){return main(argc,argv,envp);}" >passwd_stub.c
passwd.lo: passwd_stub.o $(passwd_OBJPATHS)
	$(CC) -nostdlib -Wl,-dc -r -o passwd.lo passwd_stub.o $(passwd_OBJPATHS)
	crunchide -k _crunched_passwd_stub passwd.lo

# -------- gzip

gzip_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/tools/bsdbox//usr/home/freebsd/omega/src/usr.bin/gzip
gzip_OBJPATHS= $(gzip_OBJDIR)/gzip.o
gzip_SRCDIR=/usr/home/freebsd/omega/src/tools/bsdbox/../../usr.bin/gzip
gzip_REALSRCDIR=/usr/home/freebsd/omega/src/usr.bin/gzip
gzip_OBJS= gzip.o
gzip_OPTS+= DIRPRFX=tools/bsdbox/gzip/
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

# -------- netstat

netstat_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/tools/bsdbox//usr/home/freebsd/omega/src/usr.bin/netstat
netstat_OBJPATHS= $(netstat_OBJDIR)/if.o $(netstat_OBJDIR)/inet.o $(netstat_OBJDIR)/main.o $(netstat_OBJDIR)/mbuf.o $(netstat_OBJDIR)/mroute.o $(netstat_OBJDIR)/netisr.o $(netstat_OBJDIR)/nl_symbols.o $(netstat_OBJDIR)/route.o $(netstat_OBJDIR)/unix.o $(netstat_OBJDIR)/mroute6.o $(netstat_OBJDIR)/ipsec.o $(netstat_OBJDIR)/bpf.o $(netstat_OBJDIR)/pfkey.o $(netstat_OBJDIR)/sctp.o $(netstat_OBJDIR)/flowtable.o $(netstat_OBJDIR)/inet6.o $(netstat_OBJDIR)/netgraph.o
netstat_SRCDIR=/usr/home/freebsd/omega/src/tools/bsdbox/../../usr.bin/netstat
netstat_REALSRCDIR=/usr/home/freebsd/omega/src/usr.bin/netstat
netstat_OBJS= if.o inet.o main.o mbuf.o mroute.o netisr.o nl_symbols.o route.o unix.o mroute6.o ipsec.o bpf.o pfkey.o sctp.o flowtable.o inet6.o netgraph.o
netstat_OPTS+= DIRPRFX=tools/bsdbox/netstat/
netstat_make:
	(cd $(netstat_SRCDIR) && \
		$(CRUNCHMAKE) $(BUILDOPTS) $(netstat_OPTS) depend &&\
		$(CRUNCHMAKE) $(BUILDOPTS) $(netstat_OPTS) $(netstat_OBJS))
netstat_clean:
	(cd $(netstat_SRCDIR) && $(CRUNCHMAKE) $(BUILDOPTS) clean cleandepend)

netstat_stub.c:
	echo "int _crunched_netstat_stub(int argc, char **argv, char **envp){return main(argc,argv,envp);}" >netstat_stub.c
netstat.lo: netstat_stub.o $(netstat_OBJPATHS)
	$(CC) -nostdlib -Wl,-dc -r -o netstat.lo netstat_stub.o $(netstat_OBJPATHS)
	crunchide -k _crunched_netstat_stub netstat.lo

# -------- cap_mkdb

cap_mkdb_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/tools/bsdbox//usr/home/freebsd/omega/src/usr.bin/cap_mkdb
cap_mkdb_OBJPATHS= $(cap_mkdb_OBJDIR)/cap_mkdb.o
cap_mkdb_SRCDIR=/usr/home/freebsd/omega/src/tools/bsdbox/../../usr.bin/cap_mkdb
cap_mkdb_REALSRCDIR=/usr/home/freebsd/omega/src/usr.bin/cap_mkdb
cap_mkdb_OBJS= cap_mkdb.o
cap_mkdb_OPTS+= DIRPRFX=tools/bsdbox/cap_mkdb/
cap_mkdb_make:
	(cd $(cap_mkdb_SRCDIR) && \
		$(CRUNCHMAKE) $(BUILDOPTS) $(cap_mkdb_OPTS) depend &&\
		$(CRUNCHMAKE) $(BUILDOPTS) $(cap_mkdb_OPTS) $(cap_mkdb_OBJS))
cap_mkdb_clean:
	(cd $(cap_mkdb_SRCDIR) && $(CRUNCHMAKE) $(BUILDOPTS) clean cleandepend)

cap_mkdb_stub.c:
	echo "int _crunched_cap_mkdb_stub(int argc, char **argv, char **envp){return main(argc,argv,envp);}" >cap_mkdb_stub.c
cap_mkdb.lo: cap_mkdb_stub.o $(cap_mkdb_OBJPATHS)
	$(CC) -nostdlib -Wl,-dc -r -o cap_mkdb.lo cap_mkdb_stub.o $(cap_mkdb_OBJPATHS)
	crunchide -k _crunched_cap_mkdb_stub cap_mkdb.lo

# -------- gpioctl

gpioctl_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/tools/bsdbox//usr/home/freebsd/omega/src/usr.sbin/gpioctl
gpioctl_OBJPATHS= $(gpioctl_OBJDIR)/gpioctl.o
gpioctl_SRCDIR=/usr/home/freebsd/omega/src/tools/bsdbox/../../usr.sbin/gpioctl
gpioctl_REALSRCDIR=/usr/home/freebsd/omega/src/usr.sbin/gpioctl
gpioctl_OBJS= gpioctl.o
gpioctl_OPTS+= DIRPRFX=tools/bsdbox/gpioctl/
gpioctl_make:
	(cd $(gpioctl_SRCDIR) && \
		$(CRUNCHMAKE) $(BUILDOPTS) $(gpioctl_OPTS) depend &&\
		$(CRUNCHMAKE) $(BUILDOPTS) $(gpioctl_OPTS) $(gpioctl_OBJS))
gpioctl_clean:
	(cd $(gpioctl_SRCDIR) && $(CRUNCHMAKE) $(BUILDOPTS) clean cleandepend)

gpioctl_stub.c:
	echo "int _crunched_gpioctl_stub(int argc, char **argv, char **envp){return main(argc,argv,envp);}" >gpioctl_stub.c
gpioctl.lo: gpioctl_stub.o $(gpioctl_OBJPATHS)
	$(CC) -nostdlib -Wl,-dc -r -o gpioctl.lo gpioctl_stub.o $(gpioctl_OBJPATHS)
	crunchide -k _crunched_gpioctl_stub gpioctl.lo

# -------- chown

chown_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/tools/bsdbox//usr/home/freebsd/omega/src/usr.sbin/chown
chown_OBJPATHS= $(chown_OBJDIR)/chown.o
chown_SRCDIR=/usr/home/freebsd/omega/src/tools/bsdbox/../../usr.sbin/chown
chown_REALSRCDIR=/usr/home/freebsd/omega/src/usr.sbin/chown
chown_OBJS= chown.o
chown_OPTS+= DIRPRFX=tools/bsdbox/chown/
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

# -------- arp

arp_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/tools/bsdbox//usr/home/freebsd/omega/src/usr.sbin/arp
arp_OBJPATHS= $(arp_OBJDIR)/arp.o
arp_SRCDIR=/usr/home/freebsd/omega/src/tools/bsdbox/../../usr.sbin/arp
arp_REALSRCDIR=/usr/home/freebsd/omega/src/usr.sbin/arp
arp_OBJS= arp.o
arp_OPTS+= DIRPRFX=tools/bsdbox/arp/
arp_make:
	(cd $(arp_SRCDIR) && \
		$(CRUNCHMAKE) $(BUILDOPTS) $(arp_OPTS) depend &&\
		$(CRUNCHMAKE) $(BUILDOPTS) $(arp_OPTS) $(arp_OBJS))
arp_clean:
	(cd $(arp_SRCDIR) && $(CRUNCHMAKE) $(BUILDOPTS) clean cleandepend)

arp_stub.c:
	echo "int _crunched_arp_stub(int argc, char **argv, char **envp){return main(argc,argv,envp);}" >arp_stub.c
arp.lo: arp_stub.o $(arp_OBJPATHS)
	$(CC) -nostdlib -Wl,-dc -r -o arp.lo arp_stub.o $(arp_OBJPATHS)
	crunchide -k _crunched_arp_stub arp.lo

# -------- inetd

inetd_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/tools/bsdbox//usr/home/freebsd/omega/src/usr.sbin/inetd
inetd_OBJPATHS= $(inetd_OBJDIR)/inetd.o $(inetd_OBJDIR)/builtins.o
inetd_SRCDIR=/usr/home/freebsd/omega/src/tools/bsdbox/../../usr.sbin/inetd
inetd_REALSRCDIR=/usr/home/freebsd/omega/src/usr.sbin/inetd
inetd_OBJS= inetd.o builtins.o
inetd_OPTS+= DIRPRFX=tools/bsdbox/inetd/
inetd_make:
	(cd $(inetd_SRCDIR) && \
		$(CRUNCHMAKE) $(BUILDOPTS) $(inetd_OPTS) depend &&\
		$(CRUNCHMAKE) $(BUILDOPTS) $(inetd_OPTS) $(inetd_OBJS))
inetd_clean:
	(cd $(inetd_SRCDIR) && $(CRUNCHMAKE) $(BUILDOPTS) clean cleandepend)

inetd_stub.c:
	echo "int _crunched_inetd_stub(int argc, char **argv, char **envp){return main(argc,argv,envp);}" >inetd_stub.c
inetd.lo: inetd_stub.o $(inetd_OBJPATHS)
	$(CC) -nostdlib -Wl,-dc -r -o inetd.lo inetd_stub.o $(inetd_OBJPATHS)
	crunchide -k _crunched_inetd_stub inetd.lo

# -------- wlandebug

wlandebug_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/tools/bsdbox//usr/home/freebsd/omega/src/usr.sbin/wlandebug
wlandebug_OBJPATHS= $(wlandebug_OBJDIR)/wlandebug.o
wlandebug_SRCDIR=/usr/home/freebsd/omega/src/tools/bsdbox/../../usr.sbin/wlandebug
wlandebug_REALSRCDIR=/usr/home/freebsd/omega/src/usr.sbin/wlandebug
wlandebug_OBJS= wlandebug.o
wlandebug_OPTS+= DIRPRFX=tools/bsdbox/wlandebug/
wlandebug_make:
	(cd $(wlandebug_SRCDIR) && \
		$(CRUNCHMAKE) $(BUILDOPTS) $(wlandebug_OPTS) depend &&\
		$(CRUNCHMAKE) $(BUILDOPTS) $(wlandebug_OPTS) $(wlandebug_OBJS))
wlandebug_clean:
	(cd $(wlandebug_SRCDIR) && $(CRUNCHMAKE) $(BUILDOPTS) clean cleandepend)

wlandebug_stub.c:
	echo "int _crunched_wlandebug_stub(int argc, char **argv, char **envp){return main(argc,argv,envp);}" >wlandebug_stub.c
wlandebug.lo: wlandebug_stub.o $(wlandebug_OBJPATHS)
	$(CC) -nostdlib -Wl,-dc -r -o wlandebug.lo wlandebug_stub.o $(wlandebug_OBJPATHS)
	crunchide -k _crunched_wlandebug_stub wlandebug.lo

# -------- tcpdump

tcpdump_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/tools/bsdbox//usr/home/freebsd/omega/src/usr.sbin/tcpdump
tcpdump_OBJPATHS=
tcpdump_make:
	@echo "** cannot make objs for tcpdump"

tcpdump_stub.c:
	echo "int _crunched_tcpdump_stub(int argc, char **argv, char **envp){return main(argc,argv,envp);}" >tcpdump_stub.c
tcpdump.lo: tcpdump_stub.o $(tcpdump_OBJPATHS)
	$(CC) -nostdlib -Wl,-dc -r -o tcpdump.lo tcpdump_stub.o $(tcpdump_OBJPATHS)
	crunchide -k _crunched_tcpdump_stub tcpdump.lo

# -------- hostapd

hostapd_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/tools/bsdbox//usr/home/freebsd/omega/src/usr.sbin/wpa/hostapd
hostapd_OBJPATHS= $(hostapd_OBJDIR)/accounting.o $(hostapd_OBJDIR)/aes-omac1.o $(hostapd_OBJDIR)/ap_config.o $(hostapd_OBJDIR)/ap_drv_ops.o $(hostapd_OBJDIR)/ap_mlme.o $(hostapd_OBJDIR)/authsrv.o $(hostapd_OBJDIR)/base64.o $(hostapd_OBJDIR)/beacon.o $(hostapd_OBJDIR)/bss_load.o $(hostapd_OBJDIR)/chap.o $(hostapd_OBJDIR)/common.o $(hostapd_OBJDIR)/config_file.o $(hostapd_OBJDIR)/ctrl_iface.o $(hostapd_OBJDIR)/ctrl_iface_ap.o $(hostapd_OBJDIR)/driver_common.o $(hostapd_OBJDIR)/l2_packet_freebsd.o $(hostapd_OBJDIR)/driver_bsd.o $(hostapd_OBJDIR)/drivers.o $(hostapd_OBJDIR)/drv_callbacks.o $(hostapd_OBJDIR)/eap_common.o $(hostapd_OBJDIR)/eap_peap_common.o $(hostapd_OBJDIR)/eap_register.o $(hostapd_OBJDIR)/eap_server.o $(hostapd_OBJDIR)/eap_server_methods.o $(hostapd_OBJDIR)/eap_user_db.o $(hostapd_OBJDIR)/eapol_auth_dump.o $(hostapd_OBJDIR)/eapol_auth_sm.o $(hostapd_OBJDIR)/eloop.o $(hostapd_OBJDIR)/gas.o $(hostapd_OBJDIR)/gas_serv.o $(hostapd_OBJDIR)/hostapd.o $(hostapd_OBJDIR)/hs20.o $(hostapd_OBJDIR)/http_client.o $(hostapd_OBJDIR)/http_server.o $(hostapd_OBJDIR)/httpread.o $(hostapd_OBJDIR)/hw_features_common.o $(hostapd_OBJDIR)/ieee802_11_auth.o $(hostapd_OBJDIR)/ieee802_11_common.o $(hostapd_OBJDIR)/ieee802_11_shared.o $(hostapd_OBJDIR)/ieee802_1x.o $(hostapd_OBJDIR)/ip_addr.o $(hostapd_OBJDIR)/main.o $(hostapd_OBJDIR)/ms_funcs.o $(hostapd_OBJDIR)/os_unix.o $(hostapd_OBJDIR)/peerkey_auth.o $(hostapd_OBJDIR)/pmksa_cache_auth.o $(hostapd_OBJDIR)/preauth_auth.o $(hostapd_OBJDIR)/radius.o $(hostapd_OBJDIR)/radius_client.o $(hostapd_OBJDIR)/radius_das.o $(hostapd_OBJDIR)/sta_info.o $(hostapd_OBJDIR)/tkip_countermeasures.o $(hostapd_OBJDIR)/upnp_xml.o $(hostapd_OBJDIR)/utils.o $(hostapd_OBJDIR)/uuid.o $(hostapd_OBJDIR)/vlan_init.o $(hostapd_OBJDIR)/wpa_auth.o $(hostapd_OBJDIR)/wpa_auth_glue.o $(hostapd_OBJDIR)/wpa_auth_ie.o $(hostapd_OBJDIR)/wpa_common.o $(hostapd_OBJDIR)/wpa_debug.o $(hostapd_OBJDIR)/wpabuf.o $(hostapd_OBJDIR)/wps.o $(hostapd_OBJDIR)/wps_attr_build.o $(hostapd_OBJDIR)/wps_attr_parse.o $(hostapd_OBJDIR)/wps_attr_process.o $(hostapd_OBJDIR)/wps_common.o $(hostapd_OBJDIR)/wps_dev_attr.o $(hostapd_OBJDIR)/wps_enrollee.o $(hostapd_OBJDIR)/wps_hostapd.o $(hostapd_OBJDIR)/wps_registrar.o $(hostapd_OBJDIR)/wps_upnp.o $(hostapd_OBJDIR)/wps_upnp_ap.o $(hostapd_OBJDIR)/wps_upnp_event.o $(hostapd_OBJDIR)/wps_upnp_ssdp.o $(hostapd_OBJDIR)/wps_upnp_web.o $(hostapd_OBJDIR)/eap_server_gtc.o $(hostapd_OBJDIR)/eap_server_identity.o $(hostapd_OBJDIR)/eap_server_md5.o $(hostapd_OBJDIR)/eap_server_mschapv2.o $(hostapd_OBJDIR)/eap_server_peap.o $(hostapd_OBJDIR)/eap_server_tls.o $(hostapd_OBJDIR)/eap_server_tls_common.o $(hostapd_OBJDIR)/eap_server_ttls.o $(hostapd_OBJDIR)/eap_server_wsc.o $(hostapd_OBJDIR)/eap_wsc_common.o $(hostapd_OBJDIR)/eap_sim_common.o $(hostapd_OBJDIR)/eap_sim_db.o $(hostapd_OBJDIR)/crypto_openssl.o $(hostapd_OBJDIR)/random.o $(hostapd_OBJDIR)/sha1-prf.o $(hostapd_OBJDIR)/sha256-prf.o $(hostapd_OBJDIR)/sha256-tlsprf.o $(hostapd_OBJDIR)/tls_openssl.o $(hostapd_OBJDIR)/fips_prf_openssl.o $(hostapd_OBJDIR)/sha1-tlsprf.o
hostapd_SRCDIR=/usr/home/freebsd/omega/src/tools/bsdbox/../../usr.sbin/wpa/hostapd
hostapd_REALSRCDIR=/usr/home/freebsd/omega/src/usr.sbin/wpa/hostapd
hostapd_OBJS= accounting.o aes-omac1.o ap_config.o ap_drv_ops.o ap_mlme.o authsrv.o base64.o beacon.o bss_load.o chap.o common.o config_file.o ctrl_iface.o ctrl_iface_ap.o driver_common.o l2_packet_freebsd.o driver_bsd.o drivers.o drv_callbacks.o eap_common.o eap_peap_common.o eap_register.o eap_server.o eap_server_methods.o eap_user_db.o eapol_auth_dump.o eapol_auth_sm.o eloop.o gas.o gas_serv.o hostapd.o hs20.o http_client.o http_server.o httpread.o hw_features_common.o ieee802_11_auth.o ieee802_11_common.o ieee802_11_shared.o ieee802_1x.o ip_addr.o main.o ms_funcs.o os_unix.o peerkey_auth.o pmksa_cache_auth.o preauth_auth.o radius.o radius_client.o radius_das.o sta_info.o tkip_countermeasures.o upnp_xml.o utils.o uuid.o vlan_init.o wpa_auth.o wpa_auth_glue.o wpa_auth_ie.o wpa_common.o wpa_debug.o wpabuf.o wps.o wps_attr_build.o wps_attr_parse.o wps_attr_process.o wps_common.o wps_dev_attr.o wps_enrollee.o wps_hostapd.o wps_registrar.o wps_upnp.o wps_upnp_ap.o wps_upnp_event.o wps_upnp_ssdp.o wps_upnp_web.o eap_server_gtc.o eap_server_identity.o eap_server_md5.o eap_server_mschapv2.o eap_server_peap.o eap_server_tls.o eap_server_tls_common.o eap_server_ttls.o eap_server_wsc.o eap_wsc_common.o eap_sim_common.o eap_sim_db.o crypto_openssl.o random.o sha1-prf.o sha256-prf.o sha256-tlsprf.o tls_openssl.o fips_prf_openssl.o sha1-tlsprf.o
hostapd_OPTS+= DIRPRFX=tools/bsdbox/hostapd/
hostapd_make:
	(cd $(hostapd_SRCDIR) && \
		$(CRUNCHMAKE) $(BUILDOPTS) $(hostapd_OPTS) depend &&\
		$(CRUNCHMAKE) $(BUILDOPTS) $(hostapd_OPTS) $(hostapd_OBJS))
hostapd_clean:
	(cd $(hostapd_SRCDIR) && $(CRUNCHMAKE) $(BUILDOPTS) clean cleandepend)

hostapd_stub.c:
	echo "int _crunched_hostapd_stub(int argc, char **argv, char **envp){return main(argc,argv,envp);}" >hostapd_stub.c
hostapd.lo: hostapd_stub.o $(hostapd_OBJPATHS)
	$(CC) -nostdlib -Wl,-dc -r -o hostapd.lo hostapd_stub.o $(hostapd_OBJPATHS)
	crunchide -k _crunched_hostapd_stub hostapd.lo

# -------- hostapd_cli

hostapd_cli_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/tools/bsdbox//usr/home/freebsd/omega/src/usr.sbin/wpa/hostapd_cli
hostapd_cli_OBJPATHS= $(hostapd_cli_OBJDIR)/common.o $(hostapd_cli_OBJDIR)/edit.o $(hostapd_cli_OBJDIR)/eloop.o $(hostapd_cli_OBJDIR)/hostapd_cli.o $(hostapd_cli_OBJDIR)/os_unix.o $(hostapd_cli_OBJDIR)/wpa_ctrl.o $(hostapd_cli_OBJDIR)/wpa_debug.o
hostapd_cli_SRCDIR=/usr/home/freebsd/omega/src/tools/bsdbox/../../usr.sbin/wpa/hostapd_cli
hostapd_cli_REALSRCDIR=/usr/home/freebsd/omega/src/usr.sbin/wpa/hostapd_cli
hostapd_cli_OBJS= common.o edit.o eloop.o hostapd_cli.o os_unix.o wpa_ctrl.o wpa_debug.o
hostapd_cli_OPTS+= DIRPRFX=tools/bsdbox/hostapd_cli/
hostapd_cli_make:
	(cd $(hostapd_cli_SRCDIR) && \
		$(CRUNCHMAKE) $(BUILDOPTS) $(hostapd_cli_OPTS) depend &&\
		$(CRUNCHMAKE) $(BUILDOPTS) $(hostapd_cli_OPTS) $(hostapd_cli_OBJS))
hostapd_cli_clean:
	(cd $(hostapd_cli_SRCDIR) && $(CRUNCHMAKE) $(BUILDOPTS) clean cleandepend)

hostapd_cli_stub.c:
	echo "int _crunched_hostapd_cli_stub(int argc, char **argv, char **envp){return main(argc,argv,envp);}" >hostapd_cli_stub.c
hostapd_cli.lo: hostapd_cli_stub.o $(hostapd_cli_OBJPATHS)
	$(CC) -nostdlib -Wl,-dc -r -o hostapd_cli.lo hostapd_cli_stub.o $(hostapd_cli_OBJPATHS)
	crunchide -k _crunched_hostapd_cli_stub hostapd_cli.lo

# -------- pwd_mkdb

pwd_mkdb_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/tools/bsdbox//usr/home/freebsd/omega/src/usr.sbin/pwd_mkdb
pwd_mkdb_OBJPATHS= $(pwd_mkdb_OBJDIR)/pw_scan.o $(pwd_mkdb_OBJDIR)/pwd_mkdb.o
pwd_mkdb_SRCDIR=/usr/home/freebsd/omega/src/tools/bsdbox/../../usr.sbin/pwd_mkdb
pwd_mkdb_REALSRCDIR=/usr/home/freebsd/omega/src/usr.sbin/pwd_mkdb
pwd_mkdb_OBJS= pw_scan.o pwd_mkdb.o
pwd_mkdb_OPTS+= DIRPRFX=tools/bsdbox/pwd_mkdb/
pwd_mkdb_make:
	(cd $(pwd_mkdb_SRCDIR) && \
		$(CRUNCHMAKE) $(BUILDOPTS) $(pwd_mkdb_OPTS) depend &&\
		$(CRUNCHMAKE) $(BUILDOPTS) $(pwd_mkdb_OPTS) $(pwd_mkdb_OBJS))
pwd_mkdb_clean:
	(cd $(pwd_mkdb_SRCDIR) && $(CRUNCHMAKE) $(BUILDOPTS) clean cleandepend)

pwd_mkdb_stub.c:
	echo "int _crunched_pwd_mkdb_stub(int argc, char **argv, char **envp){return main(argc,argv,envp);}" >pwd_mkdb_stub.c
pwd_mkdb.lo: pwd_mkdb_stub.o $(pwd_mkdb_OBJPATHS)
	$(CC) -nostdlib -Wl,-dc -r -o pwd_mkdb.lo pwd_mkdb_stub.o $(pwd_mkdb_OBJPATHS)
	crunchide -k _crunched_pwd_mkdb_stub pwd_mkdb.lo

# -------- getty

getty_OBJDIR=/home/freebsd/omega/src/../obj/mips_ap//mips.mips/usr/home/freebsd/omega/src/tools/bsdbox//usr/home/freebsd/omega/src/libexec/getty
getty_OBJPATHS= $(getty_OBJDIR)/main.o $(getty_OBJDIR)/init.o $(getty_OBJDIR)/subr.o $(getty_OBJDIR)/chat.o
getty_SRCDIR=/usr/home/freebsd/omega/src/tools/bsdbox/../../libexec/getty
getty_REALSRCDIR=/usr/home/freebsd/omega/src/libexec/getty
getty_OBJS= main.o init.o subr.o chat.o
getty_OPTS+= DIRPRFX=tools/bsdbox/getty/
getty_make:
	(cd $(getty_SRCDIR) && \
		$(CRUNCHMAKE) $(BUILDOPTS) $(getty_OPTS) depend &&\
		$(CRUNCHMAKE) $(BUILDOPTS) $(getty_OPTS) $(getty_OBJS))
getty_clean:
	(cd $(getty_SRCDIR) && $(CRUNCHMAKE) $(BUILDOPTS) clean cleandepend)

getty_stub.c:
	echo "int _crunched_getty_stub(int argc, char **argv, char **envp){return main(argc,argv,envp);}" >getty_stub.c
getty.lo: getty_stub.o $(getty_OBJPATHS)
	$(CC) -nostdlib -Wl,-dc -r -o getty.lo getty_stub.o $(getty_OBJPATHS)
	crunchide -k _crunched_getty_stub getty.lo

# ========
