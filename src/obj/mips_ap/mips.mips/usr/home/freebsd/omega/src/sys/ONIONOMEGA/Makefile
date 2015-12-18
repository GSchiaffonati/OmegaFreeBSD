KERN_IDENT=ONIONOMEGA
MACHINE=mips
MACHINE_ARCH=mips
MODULES_OVERRIDE=gpio ar71xx if_gif if_vlan if_gre if_bridge bridgestp usb wlan wlan_xauth wlan_acl wlan_wep wlan_tkip wlan_ccmp wlan_rssadapt wlan_amrr hwpmc ipfw
DEBUG=-g
KERNLOADADDR=0x80050000
S=/usr/home/freebsd/omega/src/sys
# Makefile.mips
# $FreeBSD$
#
# Makefile for FreeBSD
#
# This makefile is constructed from a machine description:
#	config machineid
# Most changes should be made in the machine description
#	/sys/mips/conf/``machineid''
# after which you should do
#	 config machineid
# Generic makefile changes should be made in
#	/sys/conf/Makefile.mips
# after which config should be rerun for all machines.
#

# Which version of config(8) is required.

STD8X16FONT?=	iso

.if !defined(S)
.if exists(./@/.)
S=	./@
.else
S=	../../..
.endif
.endif
.include "$S/conf/kern.pre.mk"

INCLUDES+= -I$S/contrib/libfdt

LDSCRIPT_NAME?=ldscript.$M
SYSTEM_LD:= ${SYSTEM_LD:$S/conf/${LDSCRIPT_NAME}=${LDSCRIPT_NAME}}
SYSTEM_DEP:= ${SYSTEM_DEP:$S/conf/${LDSCRIPT_NAME}=${LDSCRIPT_NAME}}

KERNLOADADDR?=0x80001000
# This obscure value is defined by CFE for WR160N
# To be changed later
TRAMPLOADADDR?=0x807963c0

# We default to the MIPS32 ISA, if none specified in the
# kernel configuration file.
ARCH_FLAGS?=-march=mips32
EXTRA_FLAGS=-fno-pic -mno-abicalls -G0 -DKERNLOADADDR=${KERNLOADADDR}

HACK_EXTRA_FLAGS=-shared

# We add the -fno-pic flag to kernels because otherwise performance
# is extremely poor, as well as -mno-abicalls to force no ABI usage.
CFLAGS+=${EXTRA_FLAGS} $(ARCH_FLAGS)
HACK_EXTRA_FLAGS+=${EXTRA_FLAGS} $(ARCH_FLAGS)
TRAMP_ARCH_FLAGS?=$(ARCH_FLAGS)
TRAMP_EXTRA_FLAGS=${EXTRA_FLAGS} ${TRAMP_ARCH_FLAGS}
.if ${MACHINE_ARCH:Mmips64*} != ""
TRAMP_ELFSIZE=64
.else
TRAMP_ELFSIZE=32
.endif

ASM_CFLAGS+=${CFLAGS} -D_LOCORE -DLOCORE

.if !defined(WITHOUT_KERNEL_TRAMPOLINE)
KERNEL_EXTRA=trampoline
trampoline: ${KERNEL_KO}.tramp.bin
${KERNEL_KO}.tramp.bin: ${KERNEL_KO} $S/$M/$M/elf_trampoline.c \
	$S/$M/$M/inckern.S 
	${OBJCOPY} --strip-symbol '$$d' --strip-symbol '$$a' \
		-g --strip-symbol '$$t' ${FULLKERNEL} ${KERNEL_KO}.tmp
	sed -e s/${KERNLOADADDR}/${TRAMPLOADADDR}/ -e s/" + SIZEOF_HEADERS"// \
		 ${LDSCRIPT_NAME} > ${LDSCRIPT_NAME}.tramp.noheader
	${CC} -O -nostdlib -I. -I$S ${TRAMP_EXTRA_FLAGS} ${TRAMP_LDFLAGS} -Xlinker \
		-T -Xlinker ${LDSCRIPT_NAME}.tramp.noheader \
		-DKERNNAME="\"${KERNEL_KO}.tmp\"" -DELFSIZE=${TRAMP_ELFSIZE} \
		$S/$M/$M/elf_trampoline.c $S/$M/$M/inckern.S \
		-o ${KERNEL_KO}.tramp.elf
	${OBJCOPY} -S -O binary ${KERNEL_KO}.tramp.elf \
		${KERNEL_KO}.tramp.bin
.endif

BEFORE_DEPEND=miidevs.h pccarddevs.h usbdevs.h \
	usbdevs_data.h 

OBJS=cam.o cam_compat.o cam_periph.o cam_queue.o cam_sim.o cam_xpt.o \
	ata_all.o ata_xpt.o ata_pmp.o scsi_xpt.o scsi_all.o ata_da.o \
	scsi_da.o smp_all.o dnvlist.o nvlist.o nvpair.o \
	rijndael-alg-fst.o rijndael-api-fst.o rijndael-api.o sha2.o \
	sha256c.o siphash.o siphash_test.o db_access.o db_break.o \
	db_capture.o db_command.o db_examine.o db_expr.o db_input.o \
	db_lex.o db_main.o db_output.o db_print.o db_ps.o db_run.o \
	db_script.o db_sym.o db_thread.o db_textdump.o db_variables.o \
	db_watch.o db_write_cmd.o if_ath_ahb.o if_ath.o if_ath_alq.o \
	if_ath_beacon.o if_ath_btcoex.o if_ath_debug.o if_ath_descdma.o \
	if_ath_keycache.o if_ath_ioctl.o if_ath_led.o if_ath_lna_div.o \
	if_ath_tx.o if_ath_tx_edma.o if_ath_tx_ht.o if_ath_tdma.o \
	if_ath_sysctl.o if_ath_rx.o if_ath_rx_edma.o if_ath_spectral.o \
	ah_osdep.o ah.o ah_regdomain.o ar9300_ani.o ar9300_attach.o \
	ar9300_beacon.o ar9300_eeprom.o ar9300_freebsd.o ar9300_gpio.o \
	ar9300_interrupts.o ar9300_keycache.o ar9300_mci.o ar9300_misc.o \
	ar9300_paprd.o ar9300_phy.o ar9300_power.o ar9300_radar.o \
	ar9300_radio.o ar9300_recv.o ar9300_recv_ds.o ar9300_reset.o \
	ar9300_stub.o ar9300_stub_funcs.o ar9300_spectral.o \
	ar9300_timer.o ar9300_xmit.o ar9300_xmit_ds.o sample.o \
	dfs_null.o eisa_if.o arswitch.o arswitch_reg.o arswitch_phy.o \
	arswitch_8216.o arswitch_8226.o arswitch_8316.o arswitch_8327.o \
	arswitch_7240.o arswitch_9340.o arswitch_vlans.o etherswitch.o \
	etherswitch_if.o mdio_if.o mdio.o miiproxy.o fb_if.o mx25l.o \
	gpiobus.o gpioc.o gpioled.o gpio_if.o gpiobus_if.o led.o md.o \
	memdev.o memutil.o mii.o mii_physubr.o miibus_if.o ukphy.o \
	ukphy_subr.o mmcbr_if.o mmcbus_if.o null.o card_if.o power_if.o \
	pci_if.o pci_iov_if.o pcib_if.o pcib_support.o random_infra.o \
	random_harvestq.o randomdev.o fortuna.o hash.o spibus.o \
	spibus_if.o uart_core.o uart_dev_ns8250.o uart_if.o uart_subr.o \
	uart_tty.o ehci.o usb_controller.o umass.o usb_busdma.o \
	usb_core.o usb_debug.o usb_dev.o usb_device.o usb_dynamic.o \
	usb_error.o usb_generic.o usb_handle_request.o usb_hid.o \
	usb_hub.o usb_if.o usb_lookup.o usb_mbuf.o usb_msctest.o \
	usb_parse.o usb_pf.o usb_process.o usb_request.o usb_transfer.o \
	usb_util.o usb_quirk.o watchdog.o dead_vnops.o devfs_devs.o \
	devfs_dir.o devfs_rule.o devfs_vfsops.o devfs_vnops.o \
	fifo_vnops.o pseudofs.o pseudofs_fileno.o pseudofs_vncache.o \
	pseudofs_vnops.o geom_bsd_enc.o geom_ctl.o geom_dev.o \
	geom_disk.o geom_dump.o geom_event.o geom_io.o geom_kern.o \
	geom_map.o geom_slice.o geom_subr.o geom_vfs.o g_part.o \
	g_part_if.o g_part_bsd.o g_part_mbr.o g_uncompress.o xz_malloc.o \
	xz_crc32.o xz_dec_bcj.o xz_dec_lzma2.o xz_dec_stream.o isa_if.o \
	bus_if.o clock_if.o cpufreq_if.o device_if.o imgact_elf.o \
	imgact_shell.o init_main.o init_sysent.o ksched.o kern_acct.o \
	kern_alq.o kern_clock.o kern_condvar.o kern_conf.o kern_cons.o \
	kern_cpu.o kern_cpuset.o kern_context.o kern_descrip.o \
	kern_dump.o kern_environment.o kern_et.o kern_event.o \
	kern_exec.o kern_exit.o kern_fail.o kern_ffclock.o kern_fork.o \
	kern_hhook.o kern_idle.o kern_intr.o kern_jail.o kern_khelp.o \
	kern_kthread.o kern_ktrace.o kern_linker.o kern_lock.o \
	kern_lockf.o kern_loginclass.o kern_malloc.o kern_mbuf.o \
	kern_mib.o kern_module.o kern_mtxpool.o kern_mutex.o \
	kern_ntptime.o kern_numa.o kern_osd.o kern_physio.o kern_pmc.o \
	kern_priv.o kern_proc.o kern_procctl.o kern_prot.o kern_racct.o \
	kern_rangelock.o kern_rctl.o kern_resource.o kern_rmlock.o \
	kern_rwlock.o kern_sema.o kern_sharedpage.o kern_shutdown.o \
	kern_sig.o kern_switch.o kern_sx.o kern_synch.o kern_syscalls.o \
	kern_sysctl.o kern_tc.o kern_thr.o kern_thread.o kern_time.o \
	kern_timeout.o kern_umtx.o kern_uuid.o kern_xxx.o link_elf.o \
	linker_if.o md5c.o p1003_1b.o posix4_mib.o sched_4bsd.o \
	serdev_if.o stack_protector.o subr_autoconf.o subr_blist.o \
	subr_bus.o subr_bus_dma.o subr_bufring.o subr_capability.o \
	subr_clock.o subr_counter.o subr_devstat.o subr_disk.o \
	subr_eventhandler.o subr_fattime.o subr_hash.o subr_hints.o \
	subr_kdb.o subr_kobj.o subr_lock.o subr_log.o subr_module.o \
	subr_msgbuf.o subr_param.o subr_pcpu.o subr_pctrie.o \
	subr_power.o subr_prf.o subr_prof.o subr_rman.o subr_rtc.o \
	subr_sbuf.o subr_scanf.o subr_sglist.o subr_sleepqueue.o \
	subr_smp.o subr_stack.o subr_taskqueue.o subr_trap.o \
	subr_turnstile.o subr_uio.o subr_unit.o subr_vmem.o \
	sys_capability.o sys_generic.o sys_pipe.o sys_procdesc.o \
	sys_process.o sys_socket.o syscalls.o sysv_ipc.o tty.o \
	tty_info.o tty_inq.o tty_outq.o tty_pts.o tty_tty.o \
	tty_ttydisc.o uipc_accf.o uipc_debug.o uipc_domain.o uipc_mbuf.o \
	uipc_mbuf2.o uipc_mbufhash.o uipc_shm.o uipc_sockbuf.o \
	uipc_socket.o uipc_syscalls.o uipc_usrreq.o vfs_acl.o vfs_bio.o \
	vfs_cache.o vfs_cluster.o vfs_default.o vfs_export.o \
	vfs_extattr.o vfs_hash.o vfs_init.o vfs_lookup.o vfs_mount.o \
	vfs_mountroot.o vfs_subr.o vfs_syscalls.o vfs_vnops.o \
	arc4random.o asprintf.o bcd.o bsearch.o crc32.o explicit_bzero.o \
	fnmatch.o inet_aton.o inet_ntoa.o inet_ntop.o inet_pton.o \
	jenkins_hash.o murmur3_32.o memcchr.o memchr.o memcmp.o qsort.o \
	qsort_r.o random.o scanc.o strcasecmp.o strcat.o strchr.o \
	strcmp.o strcpy.o strcspn.o strdup.o strndup.o strlcat.o \
	strlcpy.o strlen.o strncmp.o strncpy.o strnlen.o strrchr.o \
	strsep.o strspn.o strstr.o strtol.o strtoq.o strtoul.o strtouq.o \
	strvalid.o timingsafe_bcmp.o zlib.o bpf.o bpf_buffer.o \
	bpf_filter.o bpf_zerocopy.o bridgestp.o if.o if_bridge.o \
	if_clone.o if_dead.o if_debug.o if_ethersubr.o if_loop.o \
	if_llatbl.o if_media.o if_mib.o netisr.o pfil.o radix.o \
	radix_mpath.o raw_cb.o raw_usrreq.o route.o rtsock.o ieee80211.o \
	ieee80211_action.o ieee80211_ageq.o ieee80211_adhoc.o \
	ieee80211_amrr.o ieee80211_crypto.o ieee80211_crypto_ccmp.o \
	ieee80211_crypto_none.o ieee80211_crypto_tkip.o \
	ieee80211_crypto_wep.o ieee80211_ddb.o ieee80211_dfs.o \
	ieee80211_freebsd.o ieee80211_hostap.o ieee80211_ht.o \
	ieee80211_hwmp.o ieee80211_input.o ieee80211_ioctl.o \
	ieee80211_mesh.o ieee80211_monitor.o ieee80211_node.o \
	ieee80211_output.o ieee80211_phy.o ieee80211_power.o \
	ieee80211_proto.o ieee80211_radiotap.o ieee80211_ratectl.o \
	ieee80211_ratectl_none.o ieee80211_regdomain.o ieee80211_scan.o \
	ieee80211_scan_sta.o ieee80211_sta.o ieee80211_superg.o \
	ieee80211_scan_sw.o ieee80211_tdma.o ieee80211_wds.o \
	ieee80211_xauth.o ieee80211_alq.o if_ether.o igmp.o in.o \
	in_debug.o in_kdtrace.o in_fib.o ip_id.o in_mcast.o in_pcb.o \
	in_proto.o in_rmx.o ip_ecn.o ip_encap.o ip_fastfwd.o ip_icmp.o \
	ip_input.o ip_options.o ip_output.o ip_reass.o raw_ip.o cc.o \
	cc_newreno.o tcp_hostcache.o tcp_input.o tcp_lro.o tcp_output.o \
	tcp_reass.o tcp_sack.o tcp_subr.o tcp_syncache.o tcp_timer.o \
	tcp_timewait.o tcp_usrreq.o udp_usrreq.o audit_syscalls.o \
	mac_syscalls.o ffs_alloc.o ffs_balloc.o ffs_inode.o \
	ffs_snapshot.o ffs_softdep.o ffs_subr.o ffs_tables.o \
	ffs_vfsops.o ffs_vnops.o ffs_suspend.o ufs_acl.o ufs_bmap.o \
	ufs_dirhash.o ufs_extattr.o ufs_inode.o ufs_lookup.o ufs_quota.o \
	ufs_vfsops.o ufs_vnops.o default_pager.o device_pager.o \
	phys_pager.o sg_pager.o swap_pager.o uma_core.o uma_dbg.o \
	vm_fault.o vm_glue.o vm_init.o vm_kern.o vm_map.o vm_meter.o \
	vm_mmap.o vm_object.o vm_page.o vm_pageout.o vm_pager.o \
	vm_phys.o vm_radix.o vm_reserv.o vm_domain.o vm_unix.o \
	vm_zeroidle.o vnode_pager.o autoconf.o bus_space_generic.o \
	busdma_machdep.o cache.o cache_mipsNN.o cpu.o db_disasm.o \
	db_interface.o db_trace.o dump_machdep.o elf_machdep.o \
	exception.o fp.o gdb_machdep.o in_cksum.o libkern_machdep.o \
	machdep.o mem.o minidump_machdep.o nexus.o pm_machdep.o pmap.o \
	ptrace_machdep.o sc_machdep.o stack_machdep.o stdatomic.o \
	support.o bcopy.o swtch.o sys_machdep.o tlb.o trap.o \
	uio_machdep.o uma_machdep.o vm_machdep.o kern_clocksource.o \
	link_elf_obj.o subr_busdma_bufalloc.o subr_dummy_vdso_tc.o \
	subr_sfbuf.o ffsl.o ffsll.o fls.o flsl.o flsll.o memmove.o \
	cmpdi2.o ucmpdi2.o ashldi3.o ashrdi3.o apb.o ar71xx_gpio.o \
	ar71xx_machdep.o ar71xx_ehci.o ar71xx_spi.o ar71xx_macaddr.o \
	ar71xx_wdog.o if_arge.o uart_bus_ar933x.o uart_cpu_ar933x.o \
	uart_dev_ar933x.o ar71xx_bus_space_reversed.o intr_machdep.o \
	tick.o ar71xx_setup.o ar71xx_chip.o ar724x_chip.o ar91xx_chip.o \
	ar933x_chip.o ar934x_chip.o qca953x_chip.o qca955x_chip.o 

CFILES=$S/cam/cam.c $S/cam/cam_compat.c $S/cam/cam_periph.c \
	$S/cam/cam_queue.c $S/cam/cam_sim.c $S/cam/cam_xpt.c \
	$S/cam/ata/ata_all.c $S/cam/ata/ata_xpt.c $S/cam/ata/ata_pmp.c \
	$S/cam/scsi/scsi_xpt.c $S/cam/scsi/scsi_all.c \
	$S/cam/ata/ata_da.c $S/cam/scsi/scsi_da.c $S/cam/scsi/smp_all.c \
	$S/contrib/libnv/dnvlist.c $S/contrib/libnv/nvlist.c \
	$S/contrib/libnv/nvpair.c $S/crypto/rijndael/rijndael-alg-fst.c \
	$S/crypto/rijndael/rijndael-api-fst.c \
	$S/crypto/rijndael/rijndael-api.c $S/crypto/sha2/sha2.c \
	$S/crypto/sha2/sha256c.c $S/crypto/siphash/siphash.c \
	$S/crypto/siphash/siphash_test.c $S/ddb/db_access.c \
	$S/ddb/db_break.c $S/ddb/db_capture.c $S/ddb/db_command.c \
	$S/ddb/db_examine.c $S/ddb/db_expr.c $S/ddb/db_input.c \
	$S/ddb/db_lex.c $S/ddb/db_main.c $S/ddb/db_output.c \
	$S/ddb/db_print.c $S/ddb/db_ps.c $S/ddb/db_run.c \
	$S/ddb/db_script.c $S/ddb/db_sym.c $S/ddb/db_thread.c \
	$S/ddb/db_textdump.c $S/ddb/db_variables.c $S/ddb/db_watch.c \
	$S/ddb/db_write_cmd.c $S/dev/ath/if_ath_ahb.c \
	$S/dev/ath/if_ath.c $S/dev/ath/if_ath_alq.c \
	$S/dev/ath/if_ath_beacon.c $S/dev/ath/if_ath_btcoex.c \
	$S/dev/ath/if_ath_debug.c $S/dev/ath/if_ath_descdma.c \
	$S/dev/ath/if_ath_keycache.c $S/dev/ath/if_ath_ioctl.c \
	$S/dev/ath/if_ath_led.c $S/dev/ath/if_ath_lna_div.c \
	$S/dev/ath/if_ath_tx.c $S/dev/ath/if_ath_tx_edma.c \
	$S/dev/ath/if_ath_tx_ht.c $S/dev/ath/if_ath_tdma.c \
	$S/dev/ath/if_ath_sysctl.c $S/dev/ath/if_ath_rx.c \
	$S/dev/ath/if_ath_rx_edma.c $S/dev/ath/if_ath_spectral.c \
	$S/dev/ath/ah_osdep.c $S/dev/ath/ath_hal/ah.c \
	$S/dev/ath/ath_hal/ah_regdomain.c \
	$S/contrib/dev/ath/ath_hal/ar9300/ar9300_ani.c \
	$S/contrib/dev/ath/ath_hal/ar9300/ar9300_attach.c \
	$S/contrib/dev/ath/ath_hal/ar9300/ar9300_beacon.c \
	$S/contrib/dev/ath/ath_hal/ar9300/ar9300_eeprom.c \
	$S/contrib/dev/ath/ath_hal/ar9300/ar9300_freebsd.c \
	$S/contrib/dev/ath/ath_hal/ar9300/ar9300_gpio.c \
	$S/contrib/dev/ath/ath_hal/ar9300/ar9300_interrupts.c \
	$S/contrib/dev/ath/ath_hal/ar9300/ar9300_keycache.c \
	$S/contrib/dev/ath/ath_hal/ar9300/ar9300_mci.c \
	$S/contrib/dev/ath/ath_hal/ar9300/ar9300_misc.c \
	$S/contrib/dev/ath/ath_hal/ar9300/ar9300_paprd.c \
	$S/contrib/dev/ath/ath_hal/ar9300/ar9300_phy.c \
	$S/contrib/dev/ath/ath_hal/ar9300/ar9300_power.c \
	$S/contrib/dev/ath/ath_hal/ar9300/ar9300_radar.c \
	$S/contrib/dev/ath/ath_hal/ar9300/ar9300_radio.c \
	$S/contrib/dev/ath/ath_hal/ar9300/ar9300_recv.c \
	$S/contrib/dev/ath/ath_hal/ar9300/ar9300_recv_ds.c \
	$S/contrib/dev/ath/ath_hal/ar9300/ar9300_reset.c \
	$S/contrib/dev/ath/ath_hal/ar9300/ar9300_stub.c \
	$S/contrib/dev/ath/ath_hal/ar9300/ar9300_stub_funcs.c \
	$S/contrib/dev/ath/ath_hal/ar9300/ar9300_spectral.c \
	$S/contrib/dev/ath/ath_hal/ar9300/ar9300_timer.c \
	$S/contrib/dev/ath/ath_hal/ar9300/ar9300_xmit.c \
	$S/contrib/dev/ath/ath_hal/ar9300/ar9300_xmit_ds.c \
	$S/dev/ath/ath_rate/sample/sample.c \
	$S/dev/ath/ath_dfs/null/dfs_null.c \
	$S/dev/etherswitch/arswitch/arswitch.c \
	$S/dev/etherswitch/arswitch/arswitch_reg.c \
	$S/dev/etherswitch/arswitch/arswitch_phy.c \
	$S/dev/etherswitch/arswitch/arswitch_8216.c \
	$S/dev/etherswitch/arswitch/arswitch_8226.c \
	$S/dev/etherswitch/arswitch/arswitch_8316.c \
	$S/dev/etherswitch/arswitch/arswitch_8327.c \
	$S/dev/etherswitch/arswitch/arswitch_7240.c \
	$S/dev/etherswitch/arswitch/arswitch_9340.c \
	$S/dev/etherswitch/arswitch/arswitch_vlans.c \
	$S/dev/etherswitch/etherswitch.c $S/dev/etherswitch/mdio.c \
	$S/dev/etherswitch/miiproxy.c $S/dev/flash/mx25l.c \
	$S/dev/gpio/gpiobus.c $S/dev/gpio/gpioc.c $S/dev/gpio/gpioled.c \
	$S/dev/led/led.c $S/dev/md/md.c $S/dev/mem/memdev.c \
	$S/dev/mem/memutil.c $S/dev/mii/mii.c $S/dev/mii/mii_physubr.c \
	$S/dev/mii/ukphy.c $S/dev/mii/ukphy_subr.c $S/dev/null/null.c \
	$S/dev/pci/pcib_support.c $S/dev/random/random_infra.c \
	$S/dev/random/random_harvestq.c $S/dev/random/randomdev.c \
	$S/dev/random/fortuna.c $S/dev/random/hash.c \
	$S/dev/spibus/spibus.c $S/dev/uart/uart_core.c \
	$S/dev/uart/uart_dev_ns8250.c $S/dev/uart/uart_subr.c \
	$S/dev/uart/uart_tty.c $S/dev/usb/controller/ehci.c \
	$S/dev/usb/controller/usb_controller.c \
	$S/dev/usb/storage/umass.c $S/dev/usb/usb_busdma.c \
	$S/dev/usb/usb_core.c $S/dev/usb/usb_debug.c \
	$S/dev/usb/usb_dev.c $S/dev/usb/usb_device.c \
	$S/dev/usb/usb_dynamic.c $S/dev/usb/usb_error.c \
	$S/dev/usb/usb_generic.c $S/dev/usb/usb_handle_request.c \
	$S/dev/usb/usb_hid.c $S/dev/usb/usb_hub.c \
	$S/dev/usb/usb_lookup.c $S/dev/usb/usb_mbuf.c \
	$S/dev/usb/usb_msctest.c $S/dev/usb/usb_parse.c \
	$S/dev/usb/usb_pf.c $S/dev/usb/usb_process.c \
	$S/dev/usb/usb_request.c $S/dev/usb/usb_transfer.c \
	$S/dev/usb/usb_util.c $S/dev/usb/quirk/usb_quirk.c \
	$S/dev/watchdog/watchdog.c $S/fs/deadfs/dead_vnops.c \
	$S/fs/devfs/devfs_devs.c $S/fs/devfs/devfs_dir.c \
	$S/fs/devfs/devfs_rule.c $S/fs/devfs/devfs_vfsops.c \
	$S/fs/devfs/devfs_vnops.c $S/fs/fifofs/fifo_vnops.c \
	$S/fs/pseudofs/pseudofs.c $S/fs/pseudofs/pseudofs_fileno.c \
	$S/fs/pseudofs/pseudofs_vncache.c \
	$S/fs/pseudofs/pseudofs_vnops.c $S/geom/geom_bsd_enc.c \
	$S/geom/geom_ctl.c $S/geom/geom_dev.c $S/geom/geom_disk.c \
	$S/geom/geom_dump.c $S/geom/geom_event.c $S/geom/geom_io.c \
	$S/geom/geom_kern.c $S/geom/geom_map.c $S/geom/geom_slice.c \
	$S/geom/geom_subr.c $S/geom/geom_vfs.c $S/geom/part/g_part.c \
	$S/geom/part/g_part_bsd.c $S/geom/part/g_part_mbr.c \
	$S/geom/uncompress/g_uncompress.c \
	$S/contrib/xz-embedded/freebsd/xz_malloc.c \
	$S/contrib/xz-embedded/linux/lib/xz/xz_crc32.c \
	$S/contrib/xz-embedded/linux/lib/xz/xz_dec_bcj.c \
	$S/contrib/xz-embedded/linux/lib/xz/xz_dec_lzma2.c \
	$S/contrib/xz-embedded/linux/lib/xz/xz_dec_stream.c \
	$S/kern/imgact_elf.c $S/kern/imgact_shell.c $S/kern/init_main.c \
	$S/kern/init_sysent.c $S/kern/ksched.c $S/kern/kern_acct.c \
	$S/kern/kern_alq.c $S/kern/kern_clock.c $S/kern/kern_condvar.c \
	$S/kern/kern_conf.c $S/kern/kern_cons.c $S/kern/kern_cpu.c \
	$S/kern/kern_cpuset.c $S/kern/kern_context.c \
	$S/kern/kern_descrip.c $S/kern/kern_dump.c \
	$S/kern/kern_environment.c $S/kern/kern_et.c \
	$S/kern/kern_event.c $S/kern/kern_exec.c $S/kern/kern_exit.c \
	$S/kern/kern_fail.c $S/kern/kern_ffclock.c $S/kern/kern_fork.c \
	$S/kern/kern_hhook.c $S/kern/kern_idle.c $S/kern/kern_intr.c \
	$S/kern/kern_jail.c $S/kern/kern_khelp.c $S/kern/kern_kthread.c \
	$S/kern/kern_ktrace.c $S/kern/kern_linker.c $S/kern/kern_lock.c \
	$S/kern/kern_lockf.c $S/kern/kern_loginclass.c \
	$S/kern/kern_malloc.c $S/kern/kern_mbuf.c $S/kern/kern_mib.c \
	$S/kern/kern_module.c $S/kern/kern_mtxpool.c \
	$S/kern/kern_mutex.c $S/kern/kern_ntptime.c $S/kern/kern_numa.c \
	$S/kern/kern_osd.c $S/kern/kern_physio.c $S/kern/kern_pmc.c \
	$S/kern/kern_priv.c $S/kern/kern_proc.c $S/kern/kern_procctl.c \
	$S/kern/kern_prot.c $S/kern/kern_racct.c \
	$S/kern/kern_rangelock.c $S/kern/kern_rctl.c \
	$S/kern/kern_resource.c $S/kern/kern_rmlock.c \
	$S/kern/kern_rwlock.c $S/kern/kern_sema.c \
	$S/kern/kern_sharedpage.c $S/kern/kern_shutdown.c \
	$S/kern/kern_sig.c $S/kern/kern_switch.c $S/kern/kern_sx.c \
	$S/kern/kern_synch.c $S/kern/kern_syscalls.c \
	$S/kern/kern_sysctl.c $S/kern/kern_tc.c $S/kern/kern_thr.c \
	$S/kern/kern_thread.c $S/kern/kern_time.c $S/kern/kern_timeout.c \
	$S/kern/kern_umtx.c $S/kern/kern_uuid.c $S/kern/kern_xxx.c \
	$S/kern/link_elf.c $S/kern/md5c.c $S/kern/p1003_1b.c \
	$S/kern/posix4_mib.c $S/kern/sched_4bsd.c \
	$S/kern/stack_protector.c $S/kern/subr_autoconf.c \
	$S/kern/subr_blist.c $S/kern/subr_bus.c $S/kern/subr_bus_dma.c \
	$S/kern/subr_bufring.c $S/kern/subr_capability.c \
	$S/kern/subr_clock.c $S/kern/subr_counter.c \
	$S/kern/subr_devstat.c $S/kern/subr_disk.c \
	$S/kern/subr_eventhandler.c $S/kern/subr_fattime.c \
	$S/kern/subr_hash.c $S/kern/subr_hints.c $S/kern/subr_kdb.c \
	$S/kern/subr_kobj.c $S/kern/subr_lock.c $S/kern/subr_log.c \
	$S/kern/subr_module.c $S/kern/subr_msgbuf.c $S/kern/subr_param.c \
	$S/kern/subr_pcpu.c $S/kern/subr_pctrie.c $S/kern/subr_power.c \
	$S/kern/subr_prf.c $S/kern/subr_prof.c $S/kern/subr_rman.c \
	$S/kern/subr_rtc.c $S/kern/subr_sbuf.c $S/kern/subr_scanf.c \
	$S/kern/subr_sglist.c $S/kern/subr_sleepqueue.c \
	$S/kern/subr_smp.c $S/kern/subr_stack.c $S/kern/subr_taskqueue.c \
	$S/kern/subr_trap.c $S/kern/subr_turnstile.c $S/kern/subr_uio.c \
	$S/kern/subr_unit.c $S/kern/subr_vmem.c $S/kern/sys_capability.c \
	$S/kern/sys_generic.c $S/kern/sys_pipe.c $S/kern/sys_procdesc.c \
	$S/kern/sys_process.c $S/kern/sys_socket.c $S/kern/syscalls.c \
	$S/kern/sysv_ipc.c $S/kern/tty.c $S/kern/tty_info.c \
	$S/kern/tty_inq.c $S/kern/tty_outq.c $S/kern/tty_pts.c \
	$S/kern/tty_tty.c $S/kern/tty_ttydisc.c $S/kern/uipc_accf.c \
	$S/kern/uipc_debug.c $S/kern/uipc_domain.c $S/kern/uipc_mbuf.c \
	$S/kern/uipc_mbuf2.c $S/kern/uipc_mbufhash.c $S/kern/uipc_shm.c \
	$S/kern/uipc_sockbuf.c $S/kern/uipc_socket.c \
	$S/kern/uipc_syscalls.c $S/kern/uipc_usrreq.c $S/kern/vfs_acl.c \
	$S/kern/vfs_bio.c $S/kern/vfs_cache.c $S/kern/vfs_cluster.c \
	$S/kern/vfs_default.c $S/kern/vfs_export.c $S/kern/vfs_extattr.c \
	$S/kern/vfs_hash.c $S/kern/vfs_init.c $S/kern/vfs_lookup.c \
	$S/kern/vfs_mount.c $S/kern/vfs_mountroot.c $S/kern/vfs_subr.c \
	$S/kern/vfs_syscalls.c $S/kern/vfs_vnops.c \
	$S/libkern/arc4random.c $S/libkern/asprintf.c $S/libkern/bcd.c \
	$S/libkern/bsearch.c $S/libkern/crc32.c \
	$S/libkern/explicit_bzero.c $S/libkern/fnmatch.c \
	$S/libkern/inet_aton.c $S/libkern/inet_ntoa.c \
	$S/libkern/inet_ntop.c $S/libkern/inet_pton.c \
	$S/libkern/jenkins_hash.c $S/libkern/murmur3_32.c \
	$S/libkern/memcchr.c $S/libkern/memchr.c $S/libkern/memcmp.c \
	$S/libkern/qsort.c $S/libkern/qsort_r.c $S/libkern/random.c \
	$S/libkern/scanc.c $S/libkern/strcasecmp.c $S/libkern/strcat.c \
	$S/libkern/strchr.c $S/libkern/strcmp.c $S/libkern/strcpy.c \
	$S/libkern/strcspn.c $S/libkern/strdup.c $S/libkern/strndup.c \
	$S/libkern/strlcat.c $S/libkern/strlcpy.c $S/libkern/strlen.c \
	$S/libkern/strncmp.c $S/libkern/strncpy.c $S/libkern/strnlen.c \
	$S/libkern/strrchr.c $S/libkern/strsep.c $S/libkern/strspn.c \
	$S/libkern/strstr.c $S/libkern/strtol.c $S/libkern/strtoq.c \
	$S/libkern/strtoul.c $S/libkern/strtouq.c $S/libkern/strvalid.c \
	$S/libkern/timingsafe_bcmp.c $S/libkern/zlib.c $S/net/bpf.c \
	$S/net/bpf_buffer.c $S/net/bpf_filter.c $S/net/bpf_zerocopy.c \
	$S/net/bridgestp.c $S/net/if.c $S/net/if_bridge.c \
	$S/net/if_clone.c $S/net/if_dead.c $S/net/if_debug.c \
	$S/net/if_ethersubr.c $S/net/if_loop.c $S/net/if_llatbl.c \
	$S/net/if_media.c $S/net/if_mib.c $S/net/netisr.c $S/net/pfil.c \
	$S/net/radix.c $S/net/radix_mpath.c $S/net/raw_cb.c \
	$S/net/raw_usrreq.c $S/net/route.c $S/net/rtsock.c \
	$S/net80211/ieee80211.c $S/net80211/ieee80211_action.c \
	$S/net80211/ieee80211_ageq.c $S/net80211/ieee80211_adhoc.c \
	$S/net80211/ieee80211_amrr.c $S/net80211/ieee80211_crypto.c \
	$S/net80211/ieee80211_crypto_ccmp.c \
	$S/net80211/ieee80211_crypto_none.c \
	$S/net80211/ieee80211_crypto_tkip.c \
	$S/net80211/ieee80211_crypto_wep.c $S/net80211/ieee80211_ddb.c \
	$S/net80211/ieee80211_dfs.c $S/net80211/ieee80211_freebsd.c \
	$S/net80211/ieee80211_hostap.c $S/net80211/ieee80211_ht.c \
	$S/net80211/ieee80211_hwmp.c $S/net80211/ieee80211_input.c \
	$S/net80211/ieee80211_ioctl.c $S/net80211/ieee80211_mesh.c \
	$S/net80211/ieee80211_monitor.c $S/net80211/ieee80211_node.c \
	$S/net80211/ieee80211_output.c $S/net80211/ieee80211_phy.c \
	$S/net80211/ieee80211_power.c $S/net80211/ieee80211_proto.c \
	$S/net80211/ieee80211_radiotap.c $S/net80211/ieee80211_ratectl.c \
	$S/net80211/ieee80211_ratectl_none.c \
	$S/net80211/ieee80211_regdomain.c $S/net80211/ieee80211_scan.c \
	$S/net80211/ieee80211_scan_sta.c $S/net80211/ieee80211_sta.c \
	$S/net80211/ieee80211_superg.c $S/net80211/ieee80211_scan_sw.c \
	$S/net80211/ieee80211_tdma.c $S/net80211/ieee80211_wds.c \
	$S/net80211/ieee80211_xauth.c $S/net80211/ieee80211_alq.c \
	$S/netinet/if_ether.c $S/netinet/igmp.c $S/netinet/in.c \
	$S/netinet/in_debug.c $S/netinet/in_kdtrace.c \
	$S/netinet/in_fib.c $S/netinet/ip_id.c $S/netinet/in_mcast.c \
	$S/netinet/in_pcb.c $S/netinet/in_proto.c $S/netinet/in_rmx.c \
	$S/netinet/ip_ecn.c $S/netinet/ip_encap.c \
	$S/netinet/ip_fastfwd.c $S/netinet/ip_icmp.c \
	$S/netinet/ip_input.c $S/netinet/ip_options.c \
	$S/netinet/ip_output.c $S/netinet/ip_reass.c $S/netinet/raw_ip.c \
	$S/netinet/cc/cc.c $S/netinet/cc/cc_newreno.c \
	$S/netinet/tcp_hostcache.c $S/netinet/tcp_input.c \
	$S/netinet/tcp_lro.c $S/netinet/tcp_output.c \
	$S/netinet/tcp_reass.c $S/netinet/tcp_sack.c \
	$S/netinet/tcp_subr.c $S/netinet/tcp_syncache.c \
	$S/netinet/tcp_timer.c $S/netinet/tcp_timewait.c \
	$S/netinet/tcp_usrreq.c $S/netinet/udp_usrreq.c \
	$S/security/audit/audit_syscalls.c \
	$S/security/mac/mac_syscalls.c $S/ufs/ffs/ffs_alloc.c \
	$S/ufs/ffs/ffs_balloc.c $S/ufs/ffs/ffs_inode.c \
	$S/ufs/ffs/ffs_snapshot.c $S/ufs/ffs/ffs_softdep.c \
	$S/ufs/ffs/ffs_subr.c $S/ufs/ffs/ffs_tables.c \
	$S/ufs/ffs/ffs_vfsops.c $S/ufs/ffs/ffs_vnops.c \
	$S/ufs/ffs/ffs_suspend.c $S/ufs/ufs/ufs_acl.c \
	$S/ufs/ufs/ufs_bmap.c $S/ufs/ufs/ufs_dirhash.c \
	$S/ufs/ufs/ufs_extattr.c $S/ufs/ufs/ufs_inode.c \
	$S/ufs/ufs/ufs_lookup.c $S/ufs/ufs/ufs_quota.c \
	$S/ufs/ufs/ufs_vfsops.c $S/ufs/ufs/ufs_vnops.c \
	$S/vm/default_pager.c $S/vm/device_pager.c $S/vm/phys_pager.c \
	$S/vm/sg_pager.c $S/vm/swap_pager.c $S/vm/uma_core.c \
	$S/vm/uma_dbg.c $S/vm/vm_fault.c $S/vm/vm_glue.c $S/vm/vm_init.c \
	$S/vm/vm_kern.c $S/vm/vm_map.c $S/vm/vm_meter.c $S/vm/vm_mmap.c \
	$S/vm/vm_object.c $S/vm/vm_page.c $S/vm/vm_pageout.c \
	$S/vm/vm_pager.c $S/vm/vm_phys.c $S/vm/vm_radix.c \
	$S/vm/vm_reserv.c $S/vm/vm_domain.c $S/vm/vm_unix.c \
	$S/vm/vm_zeroidle.c $S/vm/vnode_pager.c $S/mips/mips/autoconf.c \
	$S/mips/mips/bus_space_generic.c $S/mips/mips/busdma_machdep.c \
	$S/mips/mips/cache.c $S/mips/mips/cache_mipsNN.c \
	$S/mips/mips/cpu.c $S/mips/mips/db_disasm.c \
	$S/mips/mips/db_interface.c $S/mips/mips/db_trace.c \
	$S/mips/mips/dump_machdep.c $S/mips/mips/elf_machdep.c \
	$S/mips/mips/gdb_machdep.c $S/mips/mips/in_cksum.c \
	$S/mips/mips/libkern_machdep.c $S/mips/mips/machdep.c \
	$S/mips/mips/mem.c $S/mips/mips/minidump_machdep.c \
	$S/mips/mips/nexus.c $S/mips/mips/pm_machdep.c \
	$S/mips/mips/pmap.c $S/mips/mips/ptrace_machdep.c \
	$S/mips/mips/sc_machdep.c $S/mips/mips/stack_machdep.c \
	$S/mips/mips/stdatomic.c $S/mips/mips/sys_machdep.c \
	$S/mips/mips/tlb.c $S/mips/mips/trap.c \
	$S/mips/mips/uio_machdep.c $S/mips/mips/uma_machdep.c \
	$S/mips/mips/vm_machdep.c $S/kern/kern_clocksource.c \
	$S/kern/link_elf_obj.c $S/kern/subr_busdma_bufalloc.c \
	$S/kern/subr_dummy_vdso_tc.c $S/kern/subr_sfbuf.c \
	$S/libkern/ffsl.c $S/libkern/ffsll.c $S/libkern/fls.c \
	$S/libkern/flsl.c $S/libkern/flsll.c $S/libkern/memmove.c \
	$S/libkern/cmpdi2.c $S/libkern/ucmpdi2.c $S/libkern/ashldi3.c \
	$S/libkern/ashrdi3.c $S/mips/atheros/apb.c \
	$S/mips/atheros/ar71xx_gpio.c $S/mips/atheros/ar71xx_machdep.c \
	$S/mips/atheros/ar71xx_ehci.c $S/mips/atheros/ar71xx_spi.c \
	$S/mips/atheros/ar71xx_macaddr.c $S/mips/atheros/ar71xx_wdog.c \
	$S/mips/atheros/if_arge.c $S/mips/atheros/uart_bus_ar933x.c \
	$S/mips/atheros/uart_cpu_ar933x.c \
	$S/mips/atheros/uart_dev_ar933x.c \
	$S/mips/atheros/ar71xx_bus_space_reversed.c \
	$S/mips/mips/intr_machdep.c $S/mips/mips/tick.c \
	$S/mips/atheros/ar71xx_setup.c $S/mips/atheros/ar71xx_chip.c \
	$S/mips/atheros/ar724x_chip.c $S/mips/atheros/ar91xx_chip.c \
	$S/mips/atheros/ar933x_chip.c $S/mips/atheros/ar934x_chip.c \
	$S/mips/atheros/qca953x_chip.c $S/mips/atheros/qca955x_chip.c 

SFILES=$S/mips/mips/exception.S $S/mips/mips/fp.S $S/mips/mips/locore.S \
	$S/mips/mips/support.S $S/mips/mips/bcopy.S $S/mips/mips/swtch.S 

MFILES=$S/dev/eisa/eisa_if.m $S/dev/etherswitch/etherswitch_if.m \
	$S/dev/etherswitch/mdio_if.m $S/dev/fb/fb_if.m \
	$S/dev/gpio/gpio_if.m $S/dev/gpio/gpiobus_if.m \
	$S/dev/mii/miibus_if.m $S/dev/mmc/mmcbr_if.m \
	$S/dev/mmc/mmcbus_if.m $S/dev/pccard/card_if.m \
	$S/dev/pccard/power_if.m $S/dev/pci/pci_if.m \
	$S/dev/pci/pci_iov_if.m $S/dev/pci/pcib_if.m \
	$S/dev/spibus/spibus_if.m $S/dev/uart/uart_if.m \
	$S/dev/usb/usb_if.m $S/geom/part/g_part_if.m $S/isa/isa_if.m \
	$S/kern/bus_if.m $S/kern/clock_if.m $S/kern/cpufreq_if.m \
	$S/kern/device_if.m $S/kern/linker_if.m $S/kern/serdev_if.m 

CLEAN=miidevs.h pccarddevs.h usbdevs.h usbdevs_data.h 

CLEAN+=	${LDSCRIPT_NAME} ${LDSCRIPT_NAME}.tramp.noheader \
	${KERNEL_KO}.tramp.elf ${KERNEL_KO}.tramp.bin

${LDSCRIPT_NAME}: $S/conf/${LDSCRIPT_NAME}
	sed s/KERNLOADADDR/${KERNLOADADDR}/g $S/conf/${LDSCRIPT_NAME} \
		> ${LDSCRIPT_NAME}
miidevs.h: $S/tools/miidevs2h.awk $S/dev/mii/miidevs
	${AWK} -f $S/tools/miidevs2h.awk $S/dev/mii/miidevs

pccarddevs.h: $S/tools/pccarddevs2h.awk $S/dev/pccard/pccarddevs
	${AWK} -f $S/tools/pccarddevs2h.awk $S/dev/pccard/pccarddevs

usbdevs.h: $S/tools/usbdevs2h.awk $S/dev/usb/usbdevs
	${AWK} -f $S/tools/usbdevs2h.awk $S/dev/usb/usbdevs -h

usbdevs_data.h: $S/tools/usbdevs2h.awk $S/dev/usb/usbdevs
	${AWK} -f $S/tools/usbdevs2h.awk $S/dev/usb/usbdevs -d

cam.ln: $S/cam/cam.c
	${NORMAL_LINT}

cam.o: $S/cam/cam.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

cam_compat.ln: $S/cam/cam_compat.c
	${NORMAL_LINT}

cam_compat.o: $S/cam/cam_compat.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

cam_periph.ln: $S/cam/cam_periph.c
	${NORMAL_LINT}

cam_periph.o: $S/cam/cam_periph.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

cam_queue.ln: $S/cam/cam_queue.c
	${NORMAL_LINT}

cam_queue.o: $S/cam/cam_queue.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

cam_sim.ln: $S/cam/cam_sim.c
	${NORMAL_LINT}

cam_sim.o: $S/cam/cam_sim.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

cam_xpt.ln: $S/cam/cam_xpt.c
	${NORMAL_LINT}

cam_xpt.o: $S/cam/cam_xpt.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

ata_all.ln: $S/cam/ata/ata_all.c
	${NORMAL_LINT}

ata_all.o: $S/cam/ata/ata_all.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

ata_xpt.ln: $S/cam/ata/ata_xpt.c
	${NORMAL_LINT}

ata_xpt.o: $S/cam/ata/ata_xpt.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

ata_pmp.ln: $S/cam/ata/ata_pmp.c
	${NORMAL_LINT}

ata_pmp.o: $S/cam/ata/ata_pmp.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

scsi_xpt.ln: $S/cam/scsi/scsi_xpt.c
	${NORMAL_LINT}

scsi_xpt.o: $S/cam/scsi/scsi_xpt.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

scsi_all.ln: $S/cam/scsi/scsi_all.c
	${NORMAL_LINT}

scsi_all.o: $S/cam/scsi/scsi_all.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

ata_da.ln: $S/cam/ata/ata_da.c
	${NORMAL_LINT}

ata_da.o: $S/cam/ata/ata_da.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

scsi_da.ln: $S/cam/scsi/scsi_da.c
	${NORMAL_LINT}

scsi_da.o: $S/cam/scsi/scsi_da.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

smp_all.ln: $S/cam/scsi/smp_all.c
	${NORMAL_LINT}

smp_all.o: $S/cam/scsi/smp_all.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

dnvlist.ln: $S/contrib/libnv/dnvlist.c
	${NORMAL_LINT}

dnvlist.o: $S/contrib/libnv/dnvlist.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

nvlist.ln: $S/contrib/libnv/nvlist.c
	${NORMAL_LINT}

nvlist.o: $S/contrib/libnv/nvlist.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

nvpair.ln: $S/contrib/libnv/nvpair.c
	${NORMAL_LINT}

nvpair.o: $S/contrib/libnv/nvpair.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

rijndael-alg-fst.ln: $S/crypto/rijndael/rijndael-alg-fst.c
	${NORMAL_LINT}

rijndael-alg-fst.o: $S/crypto/rijndael/rijndael-alg-fst.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

rijndael-api-fst.ln: $S/crypto/rijndael/rijndael-api-fst.c
	${NORMAL_LINT}

rijndael-api-fst.o: $S/crypto/rijndael/rijndael-api-fst.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

rijndael-api.ln: $S/crypto/rijndael/rijndael-api.c
	${NORMAL_LINT}

rijndael-api.o: $S/crypto/rijndael/rijndael-api.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

sha2.ln: $S/crypto/sha2/sha2.c
	${NORMAL_LINT}

sha2.o: $S/crypto/sha2/sha2.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

sha256c.ln: $S/crypto/sha2/sha256c.c
	${NORMAL_LINT}

sha256c.o: $S/crypto/sha2/sha256c.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

siphash.ln: $S/crypto/siphash/siphash.c
	${NORMAL_LINT}

siphash.o: $S/crypto/siphash/siphash.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

siphash_test.ln: $S/crypto/siphash/siphash_test.c
	${NORMAL_LINT}

siphash_test.o: $S/crypto/siphash/siphash_test.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

db_access.ln: $S/ddb/db_access.c
	${NORMAL_LINT}

db_access.o: $S/ddb/db_access.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

db_break.ln: $S/ddb/db_break.c
	${NORMAL_LINT}

db_break.o: $S/ddb/db_break.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

db_capture.ln: $S/ddb/db_capture.c
	${NORMAL_LINT}

db_capture.o: $S/ddb/db_capture.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

db_command.ln: $S/ddb/db_command.c
	${NORMAL_LINT}

db_command.o: $S/ddb/db_command.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

db_examine.ln: $S/ddb/db_examine.c
	${NORMAL_LINT}

db_examine.o: $S/ddb/db_examine.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

db_expr.ln: $S/ddb/db_expr.c
	${NORMAL_LINT}

db_expr.o: $S/ddb/db_expr.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

db_input.ln: $S/ddb/db_input.c
	${NORMAL_LINT}

db_input.o: $S/ddb/db_input.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

db_lex.ln: $S/ddb/db_lex.c
	${NORMAL_LINT}

db_lex.o: $S/ddb/db_lex.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

db_main.ln: $S/ddb/db_main.c
	${NORMAL_LINT}

db_main.o: $S/ddb/db_main.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

db_output.ln: $S/ddb/db_output.c
	${NORMAL_LINT}

db_output.o: $S/ddb/db_output.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

db_print.ln: $S/ddb/db_print.c
	${NORMAL_LINT}

db_print.o: $S/ddb/db_print.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

db_ps.ln: $S/ddb/db_ps.c
	${NORMAL_LINT}

db_ps.o: $S/ddb/db_ps.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

db_run.ln: $S/ddb/db_run.c
	${NORMAL_LINT}

db_run.o: $S/ddb/db_run.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

db_script.ln: $S/ddb/db_script.c
	${NORMAL_LINT}

db_script.o: $S/ddb/db_script.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

db_sym.ln: $S/ddb/db_sym.c
	${NORMAL_LINT}

db_sym.o: $S/ddb/db_sym.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

db_thread.ln: $S/ddb/db_thread.c
	${NORMAL_LINT}

db_thread.o: $S/ddb/db_thread.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

db_textdump.ln: $S/ddb/db_textdump.c
	${NORMAL_LINT}

db_textdump.o: $S/ddb/db_textdump.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

db_variables.ln: $S/ddb/db_variables.c
	${NORMAL_LINT}

db_variables.o: $S/ddb/db_variables.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

db_watch.ln: $S/ddb/db_watch.c
	${NORMAL_LINT}

db_watch.o: $S/ddb/db_watch.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

db_write_cmd.ln: $S/ddb/db_write_cmd.c
	${NORMAL_LINT}

db_write_cmd.o: $S/ddb/db_write_cmd.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

if_ath_ahb.ln: $S/dev/ath/if_ath_ahb.c
	${NORMAL_LINT}

if_ath_ahb.o: $S/dev/ath/if_ath_ahb.c
	${NORMAL_C} -I$S/dev/ath
	${NORMAL_CTFCONVERT}

if_ath.ln: $S/dev/ath/if_ath.c
	${NORMAL_LINT}

if_ath.o: $S/dev/ath/if_ath.c
	${NORMAL_C} -I$S/dev/ath
	${NORMAL_CTFCONVERT}

if_ath_alq.ln: $S/dev/ath/if_ath_alq.c
	${NORMAL_LINT}

if_ath_alq.o: $S/dev/ath/if_ath_alq.c
	${NORMAL_C} -I$S/dev/ath
	${NORMAL_CTFCONVERT}

if_ath_beacon.ln: $S/dev/ath/if_ath_beacon.c
	${NORMAL_LINT}

if_ath_beacon.o: $S/dev/ath/if_ath_beacon.c
	${NORMAL_C} -I$S/dev/ath
	${NORMAL_CTFCONVERT}

if_ath_btcoex.ln: $S/dev/ath/if_ath_btcoex.c
	${NORMAL_LINT}

if_ath_btcoex.o: $S/dev/ath/if_ath_btcoex.c
	${NORMAL_C} -I$S/dev/ath
	${NORMAL_CTFCONVERT}

if_ath_debug.ln: $S/dev/ath/if_ath_debug.c
	${NORMAL_LINT}

if_ath_debug.o: $S/dev/ath/if_ath_debug.c
	${NORMAL_C} -I$S/dev/ath
	${NORMAL_CTFCONVERT}

if_ath_descdma.ln: $S/dev/ath/if_ath_descdma.c
	${NORMAL_LINT}

if_ath_descdma.o: $S/dev/ath/if_ath_descdma.c
	${NORMAL_C} -I$S/dev/ath
	${NORMAL_CTFCONVERT}

if_ath_keycache.ln: $S/dev/ath/if_ath_keycache.c
	${NORMAL_LINT}

if_ath_keycache.o: $S/dev/ath/if_ath_keycache.c
	${NORMAL_C} -I$S/dev/ath
	${NORMAL_CTFCONVERT}

if_ath_ioctl.ln: $S/dev/ath/if_ath_ioctl.c
	${NORMAL_LINT}

if_ath_ioctl.o: $S/dev/ath/if_ath_ioctl.c
	${NORMAL_C} -I$S/dev/ath
	${NORMAL_CTFCONVERT}

if_ath_led.ln: $S/dev/ath/if_ath_led.c
	${NORMAL_LINT}

if_ath_led.o: $S/dev/ath/if_ath_led.c
	${NORMAL_C} -I$S/dev/ath
	${NORMAL_CTFCONVERT}

if_ath_lna_div.ln: $S/dev/ath/if_ath_lna_div.c
	${NORMAL_LINT}

if_ath_lna_div.o: $S/dev/ath/if_ath_lna_div.c
	${NORMAL_C} -I$S/dev/ath
	${NORMAL_CTFCONVERT}

if_ath_tx.ln: $S/dev/ath/if_ath_tx.c
	${NORMAL_LINT}

if_ath_tx.o: $S/dev/ath/if_ath_tx.c
	${NORMAL_C} -I$S/dev/ath
	${NORMAL_CTFCONVERT}

if_ath_tx_edma.ln: $S/dev/ath/if_ath_tx_edma.c
	${NORMAL_LINT}

if_ath_tx_edma.o: $S/dev/ath/if_ath_tx_edma.c
	${NORMAL_C} -I$S/dev/ath
	${NORMAL_CTFCONVERT}

if_ath_tx_ht.ln: $S/dev/ath/if_ath_tx_ht.c
	${NORMAL_LINT}

if_ath_tx_ht.o: $S/dev/ath/if_ath_tx_ht.c
	${NORMAL_C} -I$S/dev/ath
	${NORMAL_CTFCONVERT}

if_ath_tdma.ln: $S/dev/ath/if_ath_tdma.c
	${NORMAL_LINT}

if_ath_tdma.o: $S/dev/ath/if_ath_tdma.c
	${NORMAL_C} -I$S/dev/ath
	${NORMAL_CTFCONVERT}

if_ath_sysctl.ln: $S/dev/ath/if_ath_sysctl.c
	${NORMAL_LINT}

if_ath_sysctl.o: $S/dev/ath/if_ath_sysctl.c
	${NORMAL_C} -I$S/dev/ath
	${NORMAL_CTFCONVERT}

if_ath_rx.ln: $S/dev/ath/if_ath_rx.c
	${NORMAL_LINT}

if_ath_rx.o: $S/dev/ath/if_ath_rx.c
	${NORMAL_C} -I$S/dev/ath
	${NORMAL_CTFCONVERT}

if_ath_rx_edma.ln: $S/dev/ath/if_ath_rx_edma.c
	${NORMAL_LINT}

if_ath_rx_edma.o: $S/dev/ath/if_ath_rx_edma.c
	${NORMAL_C} -I$S/dev/ath
	${NORMAL_CTFCONVERT}

if_ath_spectral.ln: $S/dev/ath/if_ath_spectral.c
	${NORMAL_LINT}

if_ath_spectral.o: $S/dev/ath/if_ath_spectral.c
	${NORMAL_C} -I$S/dev/ath
	${NORMAL_CTFCONVERT}

ah_osdep.ln: $S/dev/ath/ah_osdep.c
	${NORMAL_LINT}

ah_osdep.o: $S/dev/ath/ah_osdep.c
	${NORMAL_C} -I$S/dev/ath
	${NORMAL_CTFCONVERT}

ah.ln: $S/dev/ath/ath_hal/ah.c
	${NORMAL_LINT}

ah.o: $S/dev/ath/ath_hal/ah.c
	${NORMAL_C} -I$S/dev/ath
	${NORMAL_CTFCONVERT}

ah_regdomain.ln: $S/dev/ath/ath_hal/ah_regdomain.c
	${NORMAL_LINT}

ah_regdomain.o: $S/dev/ath/ath_hal/ah_regdomain.c
	${NORMAL_C} ${NO_WSHIFT_COUNT_NEGATIVE} ${NO_WSHIFT_COUNT_OVERFLOW} -I$S/dev/ath
	${NORMAL_CTFCONVERT}

ar9300_ani.ln: $S/contrib/dev/ath/ath_hal/ar9300/ar9300_ani.c
	${NORMAL_LINT}

ar9300_ani.o: $S/contrib/dev/ath/ath_hal/ar9300/ar9300_ani.c
	${NORMAL_C} -I$S/dev/ath -I$S/dev/ath/ath_hal -I$S/contrib/dev/ath/ath_hal
	${NORMAL_CTFCONVERT}

ar9300_attach.ln: $S/contrib/dev/ath/ath_hal/ar9300/ar9300_attach.c
	${NORMAL_LINT}

ar9300_attach.o: $S/contrib/dev/ath/ath_hal/ar9300/ar9300_attach.c
	${NORMAL_C} -I$S/dev/ath -I$S/dev/ath/ath_hal -I$S/contrib/dev/ath/ath_hal
	${NORMAL_CTFCONVERT}

ar9300_beacon.ln: $S/contrib/dev/ath/ath_hal/ar9300/ar9300_beacon.c
	${NORMAL_LINT}

ar9300_beacon.o: $S/contrib/dev/ath/ath_hal/ar9300/ar9300_beacon.c
	${NORMAL_C} -I$S/dev/ath -I$S/dev/ath/ath_hal -I$S/contrib/dev/ath/ath_hal
	${NORMAL_CTFCONVERT}

ar9300_eeprom.ln: $S/contrib/dev/ath/ath_hal/ar9300/ar9300_eeprom.c
	${NORMAL_LINT}

ar9300_eeprom.o: $S/contrib/dev/ath/ath_hal/ar9300/ar9300_eeprom.c
	${NORMAL_C} -I$S/dev/ath -I$S/dev/ath/ath_hal -I$S/contrib/dev/ath/ath_hal ${NO_WCONSTANT_CONVERSION}
	${NORMAL_CTFCONVERT}

ar9300_freebsd.ln: $S/contrib/dev/ath/ath_hal/ar9300/ar9300_freebsd.c
	${NORMAL_LINT}

ar9300_freebsd.o: $S/contrib/dev/ath/ath_hal/ar9300/ar9300_freebsd.c
	${NORMAL_C} -I$S/dev/ath -I$S/dev/ath/ath_hal -I$S/contrib/dev/ath/ath_hal
	${NORMAL_CTFCONVERT}

ar9300_gpio.ln: $S/contrib/dev/ath/ath_hal/ar9300/ar9300_gpio.c
	${NORMAL_LINT}

ar9300_gpio.o: $S/contrib/dev/ath/ath_hal/ar9300/ar9300_gpio.c
	${NORMAL_C} -I$S/dev/ath -I$S/dev/ath/ath_hal -I$S/contrib/dev/ath/ath_hal
	${NORMAL_CTFCONVERT}

ar9300_interrupts.ln: $S/contrib/dev/ath/ath_hal/ar9300/ar9300_interrupts.c
	${NORMAL_LINT}

ar9300_interrupts.o: $S/contrib/dev/ath/ath_hal/ar9300/ar9300_interrupts.c
	${NORMAL_C} -I$S/dev/ath -I$S/dev/ath/ath_hal -I$S/contrib/dev/ath/ath_hal
	${NORMAL_CTFCONVERT}

ar9300_keycache.ln: $S/contrib/dev/ath/ath_hal/ar9300/ar9300_keycache.c
	${NORMAL_LINT}

ar9300_keycache.o: $S/contrib/dev/ath/ath_hal/ar9300/ar9300_keycache.c
	${NORMAL_C} -I$S/dev/ath -I$S/dev/ath/ath_hal -I$S/contrib/dev/ath/ath_hal
	${NORMAL_CTFCONVERT}

ar9300_mci.ln: $S/contrib/dev/ath/ath_hal/ar9300/ar9300_mci.c
	${NORMAL_LINT}

ar9300_mci.o: $S/contrib/dev/ath/ath_hal/ar9300/ar9300_mci.c
	${NORMAL_C} -I$S/dev/ath -I$S/dev/ath/ath_hal -I$S/contrib/dev/ath/ath_hal
	${NORMAL_CTFCONVERT}

ar9300_misc.ln: $S/contrib/dev/ath/ath_hal/ar9300/ar9300_misc.c
	${NORMAL_LINT}

ar9300_misc.o: $S/contrib/dev/ath/ath_hal/ar9300/ar9300_misc.c
	${NORMAL_C} -I$S/dev/ath -I$S/dev/ath/ath_hal -I$S/contrib/dev/ath/ath_hal
	${NORMAL_CTFCONVERT}

ar9300_paprd.ln: $S/contrib/dev/ath/ath_hal/ar9300/ar9300_paprd.c
	${NORMAL_LINT}

ar9300_paprd.o: $S/contrib/dev/ath/ath_hal/ar9300/ar9300_paprd.c
	${NORMAL_C} -I$S/dev/ath -I$S/dev/ath/ath_hal -I$S/contrib/dev/ath/ath_hal
	${NORMAL_CTFCONVERT}

ar9300_phy.ln: $S/contrib/dev/ath/ath_hal/ar9300/ar9300_phy.c
	${NORMAL_LINT}

ar9300_phy.o: $S/contrib/dev/ath/ath_hal/ar9300/ar9300_phy.c
	${NORMAL_C} -I$S/dev/ath -I$S/dev/ath/ath_hal -I$S/contrib/dev/ath/ath_hal
	${NORMAL_CTFCONVERT}

ar9300_power.ln: $S/contrib/dev/ath/ath_hal/ar9300/ar9300_power.c
	${NORMAL_LINT}

ar9300_power.o: $S/contrib/dev/ath/ath_hal/ar9300/ar9300_power.c
	${NORMAL_C} -I$S/dev/ath -I$S/dev/ath/ath_hal -I$S/contrib/dev/ath/ath_hal
	${NORMAL_CTFCONVERT}

ar9300_radar.ln: $S/contrib/dev/ath/ath_hal/ar9300/ar9300_radar.c
	${NORMAL_LINT}

ar9300_radar.o: $S/contrib/dev/ath/ath_hal/ar9300/ar9300_radar.c
	${NORMAL_C} -I$S/dev/ath -I$S/dev/ath/ath_hal -I$S/contrib/dev/ath/ath_hal
	${NORMAL_CTFCONVERT}

ar9300_radio.ln: $S/contrib/dev/ath/ath_hal/ar9300/ar9300_radio.c
	${NORMAL_LINT}

ar9300_radio.o: $S/contrib/dev/ath/ath_hal/ar9300/ar9300_radio.c
	${NORMAL_C} -I$S/dev/ath -I$S/dev/ath/ath_hal -I$S/contrib/dev/ath/ath_hal
	${NORMAL_CTFCONVERT}

ar9300_recv.ln: $S/contrib/dev/ath/ath_hal/ar9300/ar9300_recv.c
	${NORMAL_LINT}

ar9300_recv.o: $S/contrib/dev/ath/ath_hal/ar9300/ar9300_recv.c
	${NORMAL_C} -I$S/dev/ath -I$S/dev/ath/ath_hal -I$S/contrib/dev/ath/ath_hal
	${NORMAL_CTFCONVERT}

ar9300_recv_ds.ln: $S/contrib/dev/ath/ath_hal/ar9300/ar9300_recv_ds.c
	${NORMAL_LINT}

ar9300_recv_ds.o: $S/contrib/dev/ath/ath_hal/ar9300/ar9300_recv_ds.c
	${NORMAL_C} -I$S/dev/ath -I$S/dev/ath/ath_hal -I$S/contrib/dev/ath/ath_hal
	${NORMAL_CTFCONVERT}

ar9300_reset.ln: $S/contrib/dev/ath/ath_hal/ar9300/ar9300_reset.c
	${NORMAL_LINT}

ar9300_reset.o: $S/contrib/dev/ath/ath_hal/ar9300/ar9300_reset.c
	${NORMAL_C} -I$S/dev/ath -I$S/dev/ath/ath_hal -I$S/contrib/dev/ath/ath_hal ${NO_WSOMETIMES_UNINITIALIZED} -Wno-unused-function
	${NORMAL_CTFCONVERT}

ar9300_stub.ln: $S/contrib/dev/ath/ath_hal/ar9300/ar9300_stub.c
	${NORMAL_LINT}

ar9300_stub.o: $S/contrib/dev/ath/ath_hal/ar9300/ar9300_stub.c
	${NORMAL_C} -I$S/dev/ath -I$S/dev/ath/ath_hal -I$S/contrib/dev/ath/ath_hal
	${NORMAL_CTFCONVERT}

ar9300_stub_funcs.ln: $S/contrib/dev/ath/ath_hal/ar9300/ar9300_stub_funcs.c
	${NORMAL_LINT}

ar9300_stub_funcs.o: $S/contrib/dev/ath/ath_hal/ar9300/ar9300_stub_funcs.c
	${NORMAL_C} -I$S/dev/ath -I$S/dev/ath/ath_hal -I$S/contrib/dev/ath/ath_hal
	${NORMAL_CTFCONVERT}

ar9300_spectral.ln: $S/contrib/dev/ath/ath_hal/ar9300/ar9300_spectral.c
	${NORMAL_LINT}

ar9300_spectral.o: $S/contrib/dev/ath/ath_hal/ar9300/ar9300_spectral.c
	${NORMAL_C} -I$S/dev/ath -I$S/dev/ath/ath_hal -I$S/contrib/dev/ath/ath_hal
	${NORMAL_CTFCONVERT}

ar9300_timer.ln: $S/contrib/dev/ath/ath_hal/ar9300/ar9300_timer.c
	${NORMAL_LINT}

ar9300_timer.o: $S/contrib/dev/ath/ath_hal/ar9300/ar9300_timer.c
	${NORMAL_C} -I$S/dev/ath -I$S/dev/ath/ath_hal -I$S/contrib/dev/ath/ath_hal
	${NORMAL_CTFCONVERT}

ar9300_xmit.ln: $S/contrib/dev/ath/ath_hal/ar9300/ar9300_xmit.c
	${NORMAL_LINT}

ar9300_xmit.o: $S/contrib/dev/ath/ath_hal/ar9300/ar9300_xmit.c
	${NORMAL_C} -I$S/dev/ath -I$S/dev/ath/ath_hal -I$S/contrib/dev/ath/ath_hal
	${NORMAL_CTFCONVERT}

ar9300_xmit_ds.ln: $S/contrib/dev/ath/ath_hal/ar9300/ar9300_xmit_ds.c
	${NORMAL_LINT}

ar9300_xmit_ds.o: $S/contrib/dev/ath/ath_hal/ar9300/ar9300_xmit_ds.c
	${NORMAL_C} -I$S/dev/ath -I$S/dev/ath/ath_hal -I$S/contrib/dev/ath/ath_hal
	${NORMAL_CTFCONVERT}

sample.ln: $S/dev/ath/ath_rate/sample/sample.c
	${NORMAL_LINT}

sample.o: $S/dev/ath/ath_rate/sample/sample.c
	${NORMAL_C} -I$S/dev/ath
	${NORMAL_CTFCONVERT}

dfs_null.ln: $S/dev/ath/ath_dfs/null/dfs_null.c
	${NORMAL_LINT}

dfs_null.o: $S/dev/ath/ath_dfs/null/dfs_null.c
	${NORMAL_C} -I$S/dev/ath
	${NORMAL_CTFCONVERT}

eisa_if.ln: $S/dev/eisa/eisa_if.m
	${NORMAL_LINT}

eisa_if.o: $S/dev/eisa/eisa_if.m
	${NORMAL_M}
	${NORMAL_CTFCONVERT}

arswitch.ln: $S/dev/etherswitch/arswitch/arswitch.c
	${NORMAL_LINT}

arswitch.o: $S/dev/etherswitch/arswitch/arswitch.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

arswitch_reg.ln: $S/dev/etherswitch/arswitch/arswitch_reg.c
	${NORMAL_LINT}

arswitch_reg.o: $S/dev/etherswitch/arswitch/arswitch_reg.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

arswitch_phy.ln: $S/dev/etherswitch/arswitch/arswitch_phy.c
	${NORMAL_LINT}

arswitch_phy.o: $S/dev/etherswitch/arswitch/arswitch_phy.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

arswitch_8216.ln: $S/dev/etherswitch/arswitch/arswitch_8216.c
	${NORMAL_LINT}

arswitch_8216.o: $S/dev/etherswitch/arswitch/arswitch_8216.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

arswitch_8226.ln: $S/dev/etherswitch/arswitch/arswitch_8226.c
	${NORMAL_LINT}

arswitch_8226.o: $S/dev/etherswitch/arswitch/arswitch_8226.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

arswitch_8316.ln: $S/dev/etherswitch/arswitch/arswitch_8316.c
	${NORMAL_LINT}

arswitch_8316.o: $S/dev/etherswitch/arswitch/arswitch_8316.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

arswitch_8327.ln: $S/dev/etherswitch/arswitch/arswitch_8327.c
	${NORMAL_LINT}

arswitch_8327.o: $S/dev/etherswitch/arswitch/arswitch_8327.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

arswitch_7240.ln: $S/dev/etherswitch/arswitch/arswitch_7240.c
	${NORMAL_LINT}

arswitch_7240.o: $S/dev/etherswitch/arswitch/arswitch_7240.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

arswitch_9340.ln: $S/dev/etherswitch/arswitch/arswitch_9340.c
	${NORMAL_LINT}

arswitch_9340.o: $S/dev/etherswitch/arswitch/arswitch_9340.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

arswitch_vlans.ln: $S/dev/etherswitch/arswitch/arswitch_vlans.c
	${NORMAL_LINT}

arswitch_vlans.o: $S/dev/etherswitch/arswitch/arswitch_vlans.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

etherswitch.ln: $S/dev/etherswitch/etherswitch.c
	${NORMAL_LINT}

etherswitch.o: $S/dev/etherswitch/etherswitch.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

etherswitch_if.ln: $S/dev/etherswitch/etherswitch_if.m
	${NORMAL_LINT}

etherswitch_if.o: $S/dev/etherswitch/etherswitch_if.m
	${NORMAL_M}
	${NORMAL_CTFCONVERT}

mdio_if.ln: $S/dev/etherswitch/mdio_if.m
	${NORMAL_LINT}

mdio_if.o: $S/dev/etherswitch/mdio_if.m
	${NORMAL_M}
	${NORMAL_CTFCONVERT}

mdio.ln: $S/dev/etherswitch/mdio.c
	${NORMAL_LINT}

mdio.o: $S/dev/etherswitch/mdio.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

miiproxy.ln: $S/dev/etherswitch/miiproxy.c
	${NORMAL_LINT}

miiproxy.o: $S/dev/etherswitch/miiproxy.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

fb_if.ln: $S/dev/fb/fb_if.m
	${NORMAL_LINT}

fb_if.o: $S/dev/fb/fb_if.m
	${NORMAL_M}
	${NORMAL_CTFCONVERT}

mx25l.ln: $S/dev/flash/mx25l.c
	${NORMAL_LINT}

mx25l.o: $S/dev/flash/mx25l.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

gpiobus.ln: $S/dev/gpio/gpiobus.c gpiobus_if.h
	${NORMAL_LINT}

gpiobus.o: $S/dev/gpio/gpiobus.c gpiobus_if.h
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

gpioc.ln: $S/dev/gpio/gpioc.c gpio_if.h
	${NORMAL_LINT}

gpioc.o: $S/dev/gpio/gpioc.c gpio_if.h
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

gpioled.ln: $S/dev/gpio/gpioled.c
	${NORMAL_LINT}

gpioled.o: $S/dev/gpio/gpioled.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

gpio_if.ln: $S/dev/gpio/gpio_if.m
	${NORMAL_LINT}

gpio_if.o: $S/dev/gpio/gpio_if.m
	${NORMAL_M}
	${NORMAL_CTFCONVERT}

gpiobus_if.ln: $S/dev/gpio/gpiobus_if.m
	${NORMAL_LINT}

gpiobus_if.o: $S/dev/gpio/gpiobus_if.m
	${NORMAL_M}
	${NORMAL_CTFCONVERT}

led.ln: $S/dev/led/led.c
	${NORMAL_LINT}

led.o: $S/dev/led/led.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

md.ln: $S/dev/md/md.c
	${NORMAL_LINT}

md.o: $S/dev/md/md.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

memdev.ln: $S/dev/mem/memdev.c
	${NORMAL_LINT}

memdev.o: $S/dev/mem/memdev.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

memutil.ln: $S/dev/mem/memutil.c
	${NORMAL_LINT}

memutil.o: $S/dev/mem/memutil.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

mii.ln: $S/dev/mii/mii.c
	${NORMAL_LINT}

mii.o: $S/dev/mii/mii.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

mii_physubr.ln: $S/dev/mii/mii_physubr.c
	${NORMAL_LINT}

mii_physubr.o: $S/dev/mii/mii_physubr.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

miibus_if.ln: $S/dev/mii/miibus_if.m
	${NORMAL_LINT}

miibus_if.o: $S/dev/mii/miibus_if.m
	${NORMAL_M}
	${NORMAL_CTFCONVERT}

ukphy.ln: $S/dev/mii/ukphy.c
	${NORMAL_LINT}

ukphy.o: $S/dev/mii/ukphy.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

ukphy_subr.ln: $S/dev/mii/ukphy_subr.c
	${NORMAL_LINT}

ukphy_subr.o: $S/dev/mii/ukphy_subr.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

mmcbr_if.ln: $S/dev/mmc/mmcbr_if.m
	${NORMAL_LINT}

mmcbr_if.o: $S/dev/mmc/mmcbr_if.m
	${NORMAL_M}
	${NORMAL_CTFCONVERT}

mmcbus_if.ln: $S/dev/mmc/mmcbus_if.m
	${NORMAL_LINT}

mmcbus_if.o: $S/dev/mmc/mmcbus_if.m
	${NORMAL_M}
	${NORMAL_CTFCONVERT}

null.ln: $S/dev/null/null.c
	${NORMAL_LINT}

null.o: $S/dev/null/null.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

card_if.ln: $S/dev/pccard/card_if.m
	${NORMAL_LINT}

card_if.o: $S/dev/pccard/card_if.m
	${NORMAL_M}
	${NORMAL_CTFCONVERT}

power_if.ln: $S/dev/pccard/power_if.m
	${NORMAL_LINT}

power_if.o: $S/dev/pccard/power_if.m
	${NORMAL_M}
	${NORMAL_CTFCONVERT}

pci_if.ln: $S/dev/pci/pci_if.m
	${NORMAL_LINT}

pci_if.o: $S/dev/pci/pci_if.m
	${NORMAL_M}
	${NORMAL_CTFCONVERT}

pci_iov_if.ln: $S/dev/pci/pci_iov_if.m
	${NORMAL_LINT}

pci_iov_if.o: $S/dev/pci/pci_iov_if.m
	${NORMAL_M}
	${NORMAL_CTFCONVERT}

pcib_if.ln: $S/dev/pci/pcib_if.m
	${NORMAL_LINT}

pcib_if.o: $S/dev/pci/pcib_if.m
	${NORMAL_M}
	${NORMAL_CTFCONVERT}

pcib_support.ln: $S/dev/pci/pcib_support.c
	${NORMAL_LINT}

pcib_support.o: $S/dev/pci/pcib_support.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

random_infra.ln: $S/dev/random/random_infra.c
	${NORMAL_LINT}

random_infra.o: $S/dev/random/random_infra.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

random_harvestq.ln: $S/dev/random/random_harvestq.c
	${NORMAL_LINT}

random_harvestq.o: $S/dev/random/random_harvestq.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

randomdev.ln: $S/dev/random/randomdev.c
	${NORMAL_LINT}

randomdev.o: $S/dev/random/randomdev.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

fortuna.ln: $S/dev/random/fortuna.c
	${NORMAL_LINT}

fortuna.o: $S/dev/random/fortuna.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

hash.ln: $S/dev/random/hash.c
	${NORMAL_LINT}

hash.o: $S/dev/random/hash.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

spibus.ln: $S/dev/spibus/spibus.c spibus_if.h
	${NORMAL_LINT}

spibus.o: $S/dev/spibus/spibus.c spibus_if.h
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

spibus_if.ln: $S/dev/spibus/spibus_if.m
	${NORMAL_LINT}

spibus_if.o: $S/dev/spibus/spibus_if.m
	${NORMAL_M}
	${NORMAL_CTFCONVERT}

uart_core.ln: $S/dev/uart/uart_core.c
	${NORMAL_LINT}

uart_core.o: $S/dev/uart/uart_core.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

uart_dev_ns8250.ln: $S/dev/uart/uart_dev_ns8250.c
	${NORMAL_LINT}

uart_dev_ns8250.o: $S/dev/uart/uart_dev_ns8250.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

uart_if.ln: $S/dev/uart/uart_if.m
	${NORMAL_LINT}

uart_if.o: $S/dev/uart/uart_if.m
	${NORMAL_M}
	${NORMAL_CTFCONVERT}

uart_subr.ln: $S/dev/uart/uart_subr.c
	${NORMAL_LINT}

uart_subr.o: $S/dev/uart/uart_subr.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

uart_tty.ln: $S/dev/uart/uart_tty.c
	${NORMAL_LINT}

uart_tty.o: $S/dev/uart/uart_tty.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

ehci.ln: $S/dev/usb/controller/ehci.c
	${NORMAL_LINT}

ehci.o: $S/dev/usb/controller/ehci.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

usb_controller.ln: $S/dev/usb/controller/usb_controller.c
	${NORMAL_LINT}

usb_controller.o: $S/dev/usb/controller/usb_controller.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

umass.ln: $S/dev/usb/storage/umass.c
	${NORMAL_LINT}

umass.o: $S/dev/usb/storage/umass.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

usb_busdma.ln: $S/dev/usb/usb_busdma.c
	${NORMAL_LINT}

usb_busdma.o: $S/dev/usb/usb_busdma.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

usb_core.ln: $S/dev/usb/usb_core.c
	${NORMAL_LINT}

usb_core.o: $S/dev/usb/usb_core.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

usb_debug.ln: $S/dev/usb/usb_debug.c
	${NORMAL_LINT}

usb_debug.o: $S/dev/usb/usb_debug.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

usb_dev.ln: $S/dev/usb/usb_dev.c
	${NORMAL_LINT}

usb_dev.o: $S/dev/usb/usb_dev.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

usb_device.ln: $S/dev/usb/usb_device.c
	${NORMAL_LINT}

usb_device.o: $S/dev/usb/usb_device.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

usb_dynamic.ln: $S/dev/usb/usb_dynamic.c
	${NORMAL_LINT}

usb_dynamic.o: $S/dev/usb/usb_dynamic.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

usb_error.ln: $S/dev/usb/usb_error.c
	${NORMAL_LINT}

usb_error.o: $S/dev/usb/usb_error.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

usb_generic.ln: $S/dev/usb/usb_generic.c
	${NORMAL_LINT}

usb_generic.o: $S/dev/usb/usb_generic.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

usb_handle_request.ln: $S/dev/usb/usb_handle_request.c
	${NORMAL_LINT}

usb_handle_request.o: $S/dev/usb/usb_handle_request.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

usb_hid.ln: $S/dev/usb/usb_hid.c
	${NORMAL_LINT}

usb_hid.o: $S/dev/usb/usb_hid.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

usb_hub.ln: $S/dev/usb/usb_hub.c
	${NORMAL_LINT}

usb_hub.o: $S/dev/usb/usb_hub.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

usb_if.ln: $S/dev/usb/usb_if.m
	${NORMAL_LINT}

usb_if.o: $S/dev/usb/usb_if.m
	${NORMAL_M}
	${NORMAL_CTFCONVERT}

usb_lookup.ln: $S/dev/usb/usb_lookup.c
	${NORMAL_LINT}

usb_lookup.o: $S/dev/usb/usb_lookup.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

usb_mbuf.ln: $S/dev/usb/usb_mbuf.c
	${NORMAL_LINT}

usb_mbuf.o: $S/dev/usb/usb_mbuf.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

usb_msctest.ln: $S/dev/usb/usb_msctest.c
	${NORMAL_LINT}

usb_msctest.o: $S/dev/usb/usb_msctest.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

usb_parse.ln: $S/dev/usb/usb_parse.c
	${NORMAL_LINT}

usb_parse.o: $S/dev/usb/usb_parse.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

usb_pf.ln: $S/dev/usb/usb_pf.c
	${NORMAL_LINT}

usb_pf.o: $S/dev/usb/usb_pf.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

usb_process.ln: $S/dev/usb/usb_process.c
	${NORMAL_LINT}

usb_process.o: $S/dev/usb/usb_process.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

usb_request.ln: $S/dev/usb/usb_request.c
	${NORMAL_LINT}

usb_request.o: $S/dev/usb/usb_request.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

usb_transfer.ln: $S/dev/usb/usb_transfer.c
	${NORMAL_LINT}

usb_transfer.o: $S/dev/usb/usb_transfer.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

usb_util.ln: $S/dev/usb/usb_util.c
	${NORMAL_LINT}

usb_util.o: $S/dev/usb/usb_util.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

usb_quirk.ln: $S/dev/usb/quirk/usb_quirk.c
	${NORMAL_LINT}

usb_quirk.o: $S/dev/usb/quirk/usb_quirk.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

watchdog.ln: $S/dev/watchdog/watchdog.c
	${NORMAL_LINT}

watchdog.o: $S/dev/watchdog/watchdog.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

dead_vnops.ln: $S/fs/deadfs/dead_vnops.c
	${NORMAL_LINT}

dead_vnops.o: $S/fs/deadfs/dead_vnops.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

devfs_devs.ln: $S/fs/devfs/devfs_devs.c
	${NORMAL_LINT}

devfs_devs.o: $S/fs/devfs/devfs_devs.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

devfs_dir.ln: $S/fs/devfs/devfs_dir.c
	${NORMAL_LINT}

devfs_dir.o: $S/fs/devfs/devfs_dir.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

devfs_rule.ln: $S/fs/devfs/devfs_rule.c
	${NORMAL_LINT}

devfs_rule.o: $S/fs/devfs/devfs_rule.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

devfs_vfsops.ln: $S/fs/devfs/devfs_vfsops.c
	${NORMAL_LINT}

devfs_vfsops.o: $S/fs/devfs/devfs_vfsops.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

devfs_vnops.ln: $S/fs/devfs/devfs_vnops.c
	${NORMAL_LINT}

devfs_vnops.o: $S/fs/devfs/devfs_vnops.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

fifo_vnops.ln: $S/fs/fifofs/fifo_vnops.c
	${NORMAL_LINT}

fifo_vnops.o: $S/fs/fifofs/fifo_vnops.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

pseudofs.ln: $S/fs/pseudofs/pseudofs.c
	${NORMAL_LINT}

pseudofs.o: $S/fs/pseudofs/pseudofs.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

pseudofs_fileno.ln: $S/fs/pseudofs/pseudofs_fileno.c
	${NORMAL_LINT}

pseudofs_fileno.o: $S/fs/pseudofs/pseudofs_fileno.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

pseudofs_vncache.ln: $S/fs/pseudofs/pseudofs_vncache.c
	${NORMAL_LINT}

pseudofs_vncache.o: $S/fs/pseudofs/pseudofs_vncache.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

pseudofs_vnops.ln: $S/fs/pseudofs/pseudofs_vnops.c
	${NORMAL_LINT}

pseudofs_vnops.o: $S/fs/pseudofs/pseudofs_vnops.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

geom_bsd_enc.ln: $S/geom/geom_bsd_enc.c
	${NORMAL_LINT}

geom_bsd_enc.o: $S/geom/geom_bsd_enc.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

geom_ctl.ln: $S/geom/geom_ctl.c
	${NORMAL_LINT}

geom_ctl.o: $S/geom/geom_ctl.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

geom_dev.ln: $S/geom/geom_dev.c
	${NORMAL_LINT}

geom_dev.o: $S/geom/geom_dev.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

geom_disk.ln: $S/geom/geom_disk.c
	${NORMAL_LINT}

geom_disk.o: $S/geom/geom_disk.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

geom_dump.ln: $S/geom/geom_dump.c
	${NORMAL_LINT}

geom_dump.o: $S/geom/geom_dump.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

geom_event.ln: $S/geom/geom_event.c
	${NORMAL_LINT}

geom_event.o: $S/geom/geom_event.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

geom_io.ln: $S/geom/geom_io.c
	${NORMAL_LINT}

geom_io.o: $S/geom/geom_io.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

geom_kern.ln: $S/geom/geom_kern.c
	${NORMAL_LINT}

geom_kern.o: $S/geom/geom_kern.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

geom_map.ln: $S/geom/geom_map.c
	${NORMAL_LINT}

geom_map.o: $S/geom/geom_map.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

geom_slice.ln: $S/geom/geom_slice.c
	${NORMAL_LINT}

geom_slice.o: $S/geom/geom_slice.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

geom_subr.ln: $S/geom/geom_subr.c
	${NORMAL_LINT}

geom_subr.o: $S/geom/geom_subr.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

geom_vfs.ln: $S/geom/geom_vfs.c
	${NORMAL_LINT}

geom_vfs.o: $S/geom/geom_vfs.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

g_part.ln: $S/geom/part/g_part.c
	${NORMAL_LINT}

g_part.o: $S/geom/part/g_part.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

g_part_if.ln: $S/geom/part/g_part_if.m
	${NORMAL_LINT}

g_part_if.o: $S/geom/part/g_part_if.m
	${NORMAL_M}
	${NORMAL_CTFCONVERT}

g_part_bsd.ln: $S/geom/part/g_part_bsd.c
	${NORMAL_LINT}

g_part_bsd.o: $S/geom/part/g_part_bsd.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

g_part_mbr.ln: $S/geom/part/g_part_mbr.c
	${NORMAL_LINT}

g_part_mbr.o: $S/geom/part/g_part_mbr.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

g_uncompress.ln: $S/geom/uncompress/g_uncompress.c
	${NORMAL_LINT}

g_uncompress.o: $S/geom/uncompress/g_uncompress.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

xz_malloc.ln: $S/contrib/xz-embedded/freebsd/xz_malloc.c
	${NORMAL_LINT}

xz_malloc.o: $S/contrib/xz-embedded/freebsd/xz_malloc.c
	${NORMAL_C} -I$S/contrib/xz-embedded/freebsd/ -I$S/contrib/xz-embedded/linux/lib/xz/ -I$S/contrib/xz-embedded/linux/include/linux/
	${NORMAL_CTFCONVERT}

xz_crc32.ln: $S/contrib/xz-embedded/linux/lib/xz/xz_crc32.c
	${NORMAL_LINT}

xz_crc32.o: $S/contrib/xz-embedded/linux/lib/xz/xz_crc32.c
	${NORMAL_C} -I$S/contrib/xz-embedded/freebsd/ -I$S/contrib/xz-embedded/linux/lib/xz/ -I$S/contrib/xz-embedded/linux/include/linux/
	${NORMAL_CTFCONVERT}

xz_dec_bcj.ln: $S/contrib/xz-embedded/linux/lib/xz/xz_dec_bcj.c
	${NORMAL_LINT}

xz_dec_bcj.o: $S/contrib/xz-embedded/linux/lib/xz/xz_dec_bcj.c
	${NORMAL_C} -I$S/contrib/xz-embedded/freebsd/ -I$S/contrib/xz-embedded/linux/lib/xz/ -I$S/contrib/xz-embedded/linux/include/linux/
	${NORMAL_CTFCONVERT}

xz_dec_lzma2.ln: $S/contrib/xz-embedded/linux/lib/xz/xz_dec_lzma2.c
	${NORMAL_LINT}

xz_dec_lzma2.o: $S/contrib/xz-embedded/linux/lib/xz/xz_dec_lzma2.c
	${NORMAL_C} -I$S/contrib/xz-embedded/freebsd/ -I$S/contrib/xz-embedded/linux/lib/xz/ -I$S/contrib/xz-embedded/linux/include/linux/
	${NORMAL_CTFCONVERT}

xz_dec_stream.ln: $S/contrib/xz-embedded/linux/lib/xz/xz_dec_stream.c
	${NORMAL_LINT}

xz_dec_stream.o: $S/contrib/xz-embedded/linux/lib/xz/xz_dec_stream.c
	${NORMAL_C} -I$S/contrib/xz-embedded/freebsd/ -I$S/contrib/xz-embedded/linux/lib/xz/ -I$S/contrib/xz-embedded/linux/include/linux/
	${NORMAL_CTFCONVERT}

isa_if.ln: $S/isa/isa_if.m
	${NORMAL_LINT}

isa_if.o: $S/isa/isa_if.m
	${NORMAL_M}
	${NORMAL_CTFCONVERT}

bus_if.ln: $S/kern/bus_if.m
	${NORMAL_LINT}

bus_if.o: $S/kern/bus_if.m
	${NORMAL_M}
	${NORMAL_CTFCONVERT}

clock_if.ln: $S/kern/clock_if.m
	${NORMAL_LINT}

clock_if.o: $S/kern/clock_if.m
	${NORMAL_M}
	${NORMAL_CTFCONVERT}

cpufreq_if.ln: $S/kern/cpufreq_if.m
	${NORMAL_LINT}

cpufreq_if.o: $S/kern/cpufreq_if.m
	${NORMAL_M}
	${NORMAL_CTFCONVERT}

device_if.ln: $S/kern/device_if.m
	${NORMAL_LINT}

device_if.o: $S/kern/device_if.m
	${NORMAL_M}
	${NORMAL_CTFCONVERT}

imgact_elf.ln: $S/kern/imgact_elf.c
	${NORMAL_LINT}

imgact_elf.o: $S/kern/imgact_elf.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

imgact_shell.ln: $S/kern/imgact_shell.c
	${NORMAL_LINT}

imgact_shell.o: $S/kern/imgact_shell.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

init_main.ln: $S/kern/init_main.c
	${NORMAL_LINT}

init_main.o: $S/kern/init_main.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

init_sysent.ln: $S/kern/init_sysent.c
	${NORMAL_LINT}

init_sysent.o: $S/kern/init_sysent.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

ksched.ln: $S/kern/ksched.c
	${NORMAL_LINT}

ksched.o: $S/kern/ksched.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

kern_acct.ln: $S/kern/kern_acct.c
	${NORMAL_LINT}

kern_acct.o: $S/kern/kern_acct.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

kern_alq.ln: $S/kern/kern_alq.c
	${NORMAL_LINT}

kern_alq.o: $S/kern/kern_alq.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

kern_clock.ln: $S/kern/kern_clock.c
	${NORMAL_LINT}

kern_clock.o: $S/kern/kern_clock.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

kern_condvar.ln: $S/kern/kern_condvar.c
	${NORMAL_LINT}

kern_condvar.o: $S/kern/kern_condvar.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

kern_conf.ln: $S/kern/kern_conf.c
	${NORMAL_LINT}

kern_conf.o: $S/kern/kern_conf.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

kern_cons.ln: $S/kern/kern_cons.c
	${NORMAL_LINT}

kern_cons.o: $S/kern/kern_cons.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

kern_cpu.ln: $S/kern/kern_cpu.c
	${NORMAL_LINT}

kern_cpu.o: $S/kern/kern_cpu.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

kern_cpuset.ln: $S/kern/kern_cpuset.c
	${NORMAL_LINT}

kern_cpuset.o: $S/kern/kern_cpuset.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

kern_context.ln: $S/kern/kern_context.c
	${NORMAL_LINT}

kern_context.o: $S/kern/kern_context.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

kern_descrip.ln: $S/kern/kern_descrip.c
	${NORMAL_LINT}

kern_descrip.o: $S/kern/kern_descrip.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

kern_dump.ln: $S/kern/kern_dump.c
	${NORMAL_LINT}

kern_dump.o: $S/kern/kern_dump.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

kern_environment.ln: $S/kern/kern_environment.c
	${NORMAL_LINT}

kern_environment.o: $S/kern/kern_environment.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

kern_et.ln: $S/kern/kern_et.c
	${NORMAL_LINT}

kern_et.o: $S/kern/kern_et.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

kern_event.ln: $S/kern/kern_event.c
	${NORMAL_LINT}

kern_event.o: $S/kern/kern_event.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

kern_exec.ln: $S/kern/kern_exec.c
	${NORMAL_LINT}

kern_exec.o: $S/kern/kern_exec.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

kern_exit.ln: $S/kern/kern_exit.c
	${NORMAL_LINT}

kern_exit.o: $S/kern/kern_exit.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

kern_fail.ln: $S/kern/kern_fail.c
	${NORMAL_LINT}

kern_fail.o: $S/kern/kern_fail.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

kern_ffclock.ln: $S/kern/kern_ffclock.c
	${NORMAL_LINT}

kern_ffclock.o: $S/kern/kern_ffclock.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

kern_fork.ln: $S/kern/kern_fork.c
	${NORMAL_LINT}

kern_fork.o: $S/kern/kern_fork.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

kern_hhook.ln: $S/kern/kern_hhook.c
	${NORMAL_LINT}

kern_hhook.o: $S/kern/kern_hhook.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

kern_idle.ln: $S/kern/kern_idle.c
	${NORMAL_LINT}

kern_idle.o: $S/kern/kern_idle.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

kern_intr.ln: $S/kern/kern_intr.c
	${NORMAL_LINT}

kern_intr.o: $S/kern/kern_intr.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

kern_jail.ln: $S/kern/kern_jail.c
	${NORMAL_LINT}

kern_jail.o: $S/kern/kern_jail.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

kern_khelp.ln: $S/kern/kern_khelp.c
	${NORMAL_LINT}

kern_khelp.o: $S/kern/kern_khelp.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

kern_kthread.ln: $S/kern/kern_kthread.c
	${NORMAL_LINT}

kern_kthread.o: $S/kern/kern_kthread.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

kern_ktrace.ln: $S/kern/kern_ktrace.c
	${NORMAL_LINT}

kern_ktrace.o: $S/kern/kern_ktrace.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

kern_linker.ln: $S/kern/kern_linker.c
	${NORMAL_LINT}

kern_linker.o: $S/kern/kern_linker.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

kern_lock.ln: $S/kern/kern_lock.c
	${NORMAL_LINT}

kern_lock.o: $S/kern/kern_lock.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

kern_lockf.ln: $S/kern/kern_lockf.c
	${NORMAL_LINT}

kern_lockf.o: $S/kern/kern_lockf.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

kern_loginclass.ln: $S/kern/kern_loginclass.c
	${NORMAL_LINT}

kern_loginclass.o: $S/kern/kern_loginclass.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

kern_malloc.ln: $S/kern/kern_malloc.c
	${NORMAL_LINT}

kern_malloc.o: $S/kern/kern_malloc.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

kern_mbuf.ln: $S/kern/kern_mbuf.c
	${NORMAL_LINT}

kern_mbuf.o: $S/kern/kern_mbuf.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

kern_mib.ln: $S/kern/kern_mib.c
	${NORMAL_LINT}

kern_mib.o: $S/kern/kern_mib.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

kern_module.ln: $S/kern/kern_module.c
	${NORMAL_LINT}

kern_module.o: $S/kern/kern_module.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

kern_mtxpool.ln: $S/kern/kern_mtxpool.c
	${NORMAL_LINT}

kern_mtxpool.o: $S/kern/kern_mtxpool.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

kern_mutex.ln: $S/kern/kern_mutex.c
	${NORMAL_LINT}

kern_mutex.o: $S/kern/kern_mutex.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

kern_ntptime.ln: $S/kern/kern_ntptime.c
	${NORMAL_LINT}

kern_ntptime.o: $S/kern/kern_ntptime.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

kern_numa.ln: $S/kern/kern_numa.c
	${NORMAL_LINT}

kern_numa.o: $S/kern/kern_numa.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

kern_osd.ln: $S/kern/kern_osd.c
	${NORMAL_LINT}

kern_osd.o: $S/kern/kern_osd.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

kern_physio.ln: $S/kern/kern_physio.c
	${NORMAL_LINT}

kern_physio.o: $S/kern/kern_physio.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

kern_pmc.ln: $S/kern/kern_pmc.c
	${NORMAL_LINT}

kern_pmc.o: $S/kern/kern_pmc.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

kern_priv.ln: $S/kern/kern_priv.c
	${NORMAL_LINT}

kern_priv.o: $S/kern/kern_priv.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

kern_proc.ln: $S/kern/kern_proc.c
	${NORMAL_LINT}

kern_proc.o: $S/kern/kern_proc.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

kern_procctl.ln: $S/kern/kern_procctl.c
	${NORMAL_LINT}

kern_procctl.o: $S/kern/kern_procctl.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

kern_prot.ln: $S/kern/kern_prot.c
	${NORMAL_LINT}

kern_prot.o: $S/kern/kern_prot.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

kern_racct.ln: $S/kern/kern_racct.c
	${NORMAL_LINT}

kern_racct.o: $S/kern/kern_racct.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

kern_rangelock.ln: $S/kern/kern_rangelock.c
	${NORMAL_LINT}

kern_rangelock.o: $S/kern/kern_rangelock.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

kern_rctl.ln: $S/kern/kern_rctl.c
	${NORMAL_LINT}

kern_rctl.o: $S/kern/kern_rctl.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

kern_resource.ln: $S/kern/kern_resource.c
	${NORMAL_LINT}

kern_resource.o: $S/kern/kern_resource.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

kern_rmlock.ln: $S/kern/kern_rmlock.c
	${NORMAL_LINT}

kern_rmlock.o: $S/kern/kern_rmlock.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

kern_rwlock.ln: $S/kern/kern_rwlock.c
	${NORMAL_LINT}

kern_rwlock.o: $S/kern/kern_rwlock.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

kern_sema.ln: $S/kern/kern_sema.c
	${NORMAL_LINT}

kern_sema.o: $S/kern/kern_sema.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

kern_sharedpage.ln: $S/kern/kern_sharedpage.c
	${NORMAL_LINT}

kern_sharedpage.o: $S/kern/kern_sharedpage.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

kern_shutdown.ln: $S/kern/kern_shutdown.c
	${NORMAL_LINT}

kern_shutdown.o: $S/kern/kern_shutdown.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

kern_sig.ln: $S/kern/kern_sig.c
	${NORMAL_LINT}

kern_sig.o: $S/kern/kern_sig.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

kern_switch.ln: $S/kern/kern_switch.c
	${NORMAL_LINT}

kern_switch.o: $S/kern/kern_switch.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

kern_sx.ln: $S/kern/kern_sx.c
	${NORMAL_LINT}

kern_sx.o: $S/kern/kern_sx.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

kern_synch.ln: $S/kern/kern_synch.c
	${NORMAL_LINT}

kern_synch.o: $S/kern/kern_synch.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

kern_syscalls.ln: $S/kern/kern_syscalls.c
	${NORMAL_LINT}

kern_syscalls.o: $S/kern/kern_syscalls.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

kern_sysctl.ln: $S/kern/kern_sysctl.c
	${NORMAL_LINT}

kern_sysctl.o: $S/kern/kern_sysctl.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

kern_tc.ln: $S/kern/kern_tc.c
	${NORMAL_LINT}

kern_tc.o: $S/kern/kern_tc.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

kern_thr.ln: $S/kern/kern_thr.c
	${NORMAL_LINT}

kern_thr.o: $S/kern/kern_thr.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

kern_thread.ln: $S/kern/kern_thread.c
	${NORMAL_LINT}

kern_thread.o: $S/kern/kern_thread.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

kern_time.ln: $S/kern/kern_time.c
	${NORMAL_LINT}

kern_time.o: $S/kern/kern_time.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

kern_timeout.ln: $S/kern/kern_timeout.c
	${NORMAL_LINT}

kern_timeout.o: $S/kern/kern_timeout.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

kern_umtx.ln: $S/kern/kern_umtx.c
	${NORMAL_LINT}

kern_umtx.o: $S/kern/kern_umtx.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

kern_uuid.ln: $S/kern/kern_uuid.c
	${NORMAL_LINT}

kern_uuid.o: $S/kern/kern_uuid.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

kern_xxx.ln: $S/kern/kern_xxx.c
	${NORMAL_LINT}

kern_xxx.o: $S/kern/kern_xxx.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

link_elf.ln: $S/kern/link_elf.c
	${NORMAL_LINT}

link_elf.o: $S/kern/link_elf.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

linker_if.ln: $S/kern/linker_if.m
	${NORMAL_LINT}

linker_if.o: $S/kern/linker_if.m
	${NORMAL_M}
	${NORMAL_CTFCONVERT}

md5c.ln: $S/kern/md5c.c
	${NORMAL_LINT}

md5c.o: $S/kern/md5c.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

p1003_1b.ln: $S/kern/p1003_1b.c
	${NORMAL_LINT}

p1003_1b.o: $S/kern/p1003_1b.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

posix4_mib.ln: $S/kern/posix4_mib.c
	${NORMAL_LINT}

posix4_mib.o: $S/kern/posix4_mib.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

sched_4bsd.ln: $S/kern/sched_4bsd.c
	${NORMAL_LINT}

sched_4bsd.o: $S/kern/sched_4bsd.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

serdev_if.ln: $S/kern/serdev_if.m
	${NORMAL_LINT}

serdev_if.o: $S/kern/serdev_if.m
	${NORMAL_M}
	${NORMAL_CTFCONVERT}

stack_protector.ln: $S/kern/stack_protector.c
	${NORMAL_LINT}

stack_protector.o: $S/kern/stack_protector.c
	${NORMAL_C:N-fstack-protector*}
	${NORMAL_CTFCONVERT}

subr_autoconf.ln: $S/kern/subr_autoconf.c
	${NORMAL_LINT}

subr_autoconf.o: $S/kern/subr_autoconf.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

subr_blist.ln: $S/kern/subr_blist.c
	${NORMAL_LINT}

subr_blist.o: $S/kern/subr_blist.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

subr_bus.ln: $S/kern/subr_bus.c
	${NORMAL_LINT}

subr_bus.o: $S/kern/subr_bus.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

subr_bus_dma.ln: $S/kern/subr_bus_dma.c
	${NORMAL_LINT}

subr_bus_dma.o: $S/kern/subr_bus_dma.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

subr_bufring.ln: $S/kern/subr_bufring.c
	${NORMAL_LINT}

subr_bufring.o: $S/kern/subr_bufring.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

subr_capability.ln: $S/kern/subr_capability.c
	${NORMAL_LINT}

subr_capability.o: $S/kern/subr_capability.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

subr_clock.ln: $S/kern/subr_clock.c
	${NORMAL_LINT}

subr_clock.o: $S/kern/subr_clock.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

subr_counter.ln: $S/kern/subr_counter.c
	${NORMAL_LINT}

subr_counter.o: $S/kern/subr_counter.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

subr_devstat.ln: $S/kern/subr_devstat.c
	${NORMAL_LINT}

subr_devstat.o: $S/kern/subr_devstat.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

subr_disk.ln: $S/kern/subr_disk.c
	${NORMAL_LINT}

subr_disk.o: $S/kern/subr_disk.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

subr_eventhandler.ln: $S/kern/subr_eventhandler.c
	${NORMAL_LINT}

subr_eventhandler.o: $S/kern/subr_eventhandler.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

subr_fattime.ln: $S/kern/subr_fattime.c
	${NORMAL_LINT}

subr_fattime.o: $S/kern/subr_fattime.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

subr_hash.ln: $S/kern/subr_hash.c
	${NORMAL_LINT}

subr_hash.o: $S/kern/subr_hash.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

subr_hints.ln: $S/kern/subr_hints.c
	${NORMAL_LINT}

subr_hints.o: $S/kern/subr_hints.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

subr_kdb.ln: $S/kern/subr_kdb.c
	${NORMAL_LINT}

subr_kdb.o: $S/kern/subr_kdb.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

subr_kobj.ln: $S/kern/subr_kobj.c
	${NORMAL_LINT}

subr_kobj.o: $S/kern/subr_kobj.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

subr_lock.ln: $S/kern/subr_lock.c
	${NORMAL_LINT}

subr_lock.o: $S/kern/subr_lock.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

subr_log.ln: $S/kern/subr_log.c
	${NORMAL_LINT}

subr_log.o: $S/kern/subr_log.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

subr_module.ln: $S/kern/subr_module.c
	${NORMAL_LINT}

subr_module.o: $S/kern/subr_module.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

subr_msgbuf.ln: $S/kern/subr_msgbuf.c
	${NORMAL_LINT}

subr_msgbuf.o: $S/kern/subr_msgbuf.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

subr_param.ln: $S/kern/subr_param.c
	${NORMAL_LINT}

subr_param.o: $S/kern/subr_param.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

subr_pcpu.ln: $S/kern/subr_pcpu.c
	${NORMAL_LINT}

subr_pcpu.o: $S/kern/subr_pcpu.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

subr_pctrie.ln: $S/kern/subr_pctrie.c
	${NORMAL_LINT}

subr_pctrie.o: $S/kern/subr_pctrie.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

subr_power.ln: $S/kern/subr_power.c
	${NORMAL_LINT}

subr_power.o: $S/kern/subr_power.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

subr_prf.ln: $S/kern/subr_prf.c
	${NORMAL_LINT}

subr_prf.o: $S/kern/subr_prf.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

subr_prof.ln: $S/kern/subr_prof.c
	${NORMAL_LINT}

subr_prof.o: $S/kern/subr_prof.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

subr_rman.ln: $S/kern/subr_rman.c
	${NORMAL_LINT}

subr_rman.o: $S/kern/subr_rman.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

subr_rtc.ln: $S/kern/subr_rtc.c
	${NORMAL_LINT}

subr_rtc.o: $S/kern/subr_rtc.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

subr_sbuf.ln: $S/kern/subr_sbuf.c
	${NORMAL_LINT}

subr_sbuf.o: $S/kern/subr_sbuf.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

subr_scanf.ln: $S/kern/subr_scanf.c
	${NORMAL_LINT}

subr_scanf.o: $S/kern/subr_scanf.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

subr_sglist.ln: $S/kern/subr_sglist.c
	${NORMAL_LINT}

subr_sglist.o: $S/kern/subr_sglist.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

subr_sleepqueue.ln: $S/kern/subr_sleepqueue.c
	${NORMAL_LINT}

subr_sleepqueue.o: $S/kern/subr_sleepqueue.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

subr_smp.ln: $S/kern/subr_smp.c
	${NORMAL_LINT}

subr_smp.o: $S/kern/subr_smp.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

subr_stack.ln: $S/kern/subr_stack.c
	${NORMAL_LINT}

subr_stack.o: $S/kern/subr_stack.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

subr_taskqueue.ln: $S/kern/subr_taskqueue.c
	${NORMAL_LINT}

subr_taskqueue.o: $S/kern/subr_taskqueue.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

subr_trap.ln: $S/kern/subr_trap.c
	${NORMAL_LINT}

subr_trap.o: $S/kern/subr_trap.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

subr_turnstile.ln: $S/kern/subr_turnstile.c
	${NORMAL_LINT}

subr_turnstile.o: $S/kern/subr_turnstile.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

subr_uio.ln: $S/kern/subr_uio.c
	${NORMAL_LINT}

subr_uio.o: $S/kern/subr_uio.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

subr_unit.ln: $S/kern/subr_unit.c
	${NORMAL_LINT}

subr_unit.o: $S/kern/subr_unit.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

subr_vmem.ln: $S/kern/subr_vmem.c
	${NORMAL_LINT}

subr_vmem.o: $S/kern/subr_vmem.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

sys_capability.ln: $S/kern/sys_capability.c
	${NORMAL_LINT}

sys_capability.o: $S/kern/sys_capability.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

sys_generic.ln: $S/kern/sys_generic.c
	${NORMAL_LINT}

sys_generic.o: $S/kern/sys_generic.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

sys_pipe.ln: $S/kern/sys_pipe.c
	${NORMAL_LINT}

sys_pipe.o: $S/kern/sys_pipe.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

sys_procdesc.ln: $S/kern/sys_procdesc.c
	${NORMAL_LINT}

sys_procdesc.o: $S/kern/sys_procdesc.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

sys_process.ln: $S/kern/sys_process.c
	${NORMAL_LINT}

sys_process.o: $S/kern/sys_process.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

sys_socket.ln: $S/kern/sys_socket.c
	${NORMAL_LINT}

sys_socket.o: $S/kern/sys_socket.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

syscalls.ln: $S/kern/syscalls.c
	${NORMAL_LINT}

syscalls.o: $S/kern/syscalls.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

sysv_ipc.ln: $S/kern/sysv_ipc.c
	${NORMAL_LINT}

sysv_ipc.o: $S/kern/sysv_ipc.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

tty.ln: $S/kern/tty.c
	${NORMAL_LINT}

tty.o: $S/kern/tty.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

tty_info.ln: $S/kern/tty_info.c
	${NORMAL_LINT}

tty_info.o: $S/kern/tty_info.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

tty_inq.ln: $S/kern/tty_inq.c
	${NORMAL_LINT}

tty_inq.o: $S/kern/tty_inq.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

tty_outq.ln: $S/kern/tty_outq.c
	${NORMAL_LINT}

tty_outq.o: $S/kern/tty_outq.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

tty_pts.ln: $S/kern/tty_pts.c
	${NORMAL_LINT}

tty_pts.o: $S/kern/tty_pts.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

tty_tty.ln: $S/kern/tty_tty.c
	${NORMAL_LINT}

tty_tty.o: $S/kern/tty_tty.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

tty_ttydisc.ln: $S/kern/tty_ttydisc.c
	${NORMAL_LINT}

tty_ttydisc.o: $S/kern/tty_ttydisc.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

uipc_accf.ln: $S/kern/uipc_accf.c
	${NORMAL_LINT}

uipc_accf.o: $S/kern/uipc_accf.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

uipc_debug.ln: $S/kern/uipc_debug.c
	${NORMAL_LINT}

uipc_debug.o: $S/kern/uipc_debug.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

uipc_domain.ln: $S/kern/uipc_domain.c
	${NORMAL_LINT}

uipc_domain.o: $S/kern/uipc_domain.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

uipc_mbuf.ln: $S/kern/uipc_mbuf.c
	${NORMAL_LINT}

uipc_mbuf.o: $S/kern/uipc_mbuf.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

uipc_mbuf2.ln: $S/kern/uipc_mbuf2.c
	${NORMAL_LINT}

uipc_mbuf2.o: $S/kern/uipc_mbuf2.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

uipc_mbufhash.ln: $S/kern/uipc_mbufhash.c
	${NORMAL_LINT}

uipc_mbufhash.o: $S/kern/uipc_mbufhash.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

uipc_shm.ln: $S/kern/uipc_shm.c
	${NORMAL_LINT}

uipc_shm.o: $S/kern/uipc_shm.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

uipc_sockbuf.ln: $S/kern/uipc_sockbuf.c
	${NORMAL_LINT}

uipc_sockbuf.o: $S/kern/uipc_sockbuf.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

uipc_socket.ln: $S/kern/uipc_socket.c
	${NORMAL_LINT}

uipc_socket.o: $S/kern/uipc_socket.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

uipc_syscalls.ln: $S/kern/uipc_syscalls.c
	${NORMAL_LINT}

uipc_syscalls.o: $S/kern/uipc_syscalls.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

uipc_usrreq.ln: $S/kern/uipc_usrreq.c
	${NORMAL_LINT}

uipc_usrreq.o: $S/kern/uipc_usrreq.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

vfs_acl.ln: $S/kern/vfs_acl.c
	${NORMAL_LINT}

vfs_acl.o: $S/kern/vfs_acl.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

vfs_bio.ln: $S/kern/vfs_bio.c
	${NORMAL_LINT}

vfs_bio.o: $S/kern/vfs_bio.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

vfs_cache.ln: $S/kern/vfs_cache.c
	${NORMAL_LINT}

vfs_cache.o: $S/kern/vfs_cache.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

vfs_cluster.ln: $S/kern/vfs_cluster.c
	${NORMAL_LINT}

vfs_cluster.o: $S/kern/vfs_cluster.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

vfs_default.ln: $S/kern/vfs_default.c
	${NORMAL_LINT}

vfs_default.o: $S/kern/vfs_default.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

vfs_export.ln: $S/kern/vfs_export.c
	${NORMAL_LINT}

vfs_export.o: $S/kern/vfs_export.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

vfs_extattr.ln: $S/kern/vfs_extattr.c
	${NORMAL_LINT}

vfs_extattr.o: $S/kern/vfs_extattr.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

vfs_hash.ln: $S/kern/vfs_hash.c
	${NORMAL_LINT}

vfs_hash.o: $S/kern/vfs_hash.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

vfs_init.ln: $S/kern/vfs_init.c
	${NORMAL_LINT}

vfs_init.o: $S/kern/vfs_init.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

vfs_lookup.ln: $S/kern/vfs_lookup.c
	${NORMAL_LINT}

vfs_lookup.o: $S/kern/vfs_lookup.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

vfs_mount.ln: $S/kern/vfs_mount.c
	${NORMAL_LINT}

vfs_mount.o: $S/kern/vfs_mount.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

vfs_mountroot.ln: $S/kern/vfs_mountroot.c
	${NORMAL_LINT}

vfs_mountroot.o: $S/kern/vfs_mountroot.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

vfs_subr.ln: $S/kern/vfs_subr.c
	${NORMAL_LINT}

vfs_subr.o: $S/kern/vfs_subr.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

vfs_syscalls.ln: $S/kern/vfs_syscalls.c
	${NORMAL_LINT}

vfs_syscalls.o: $S/kern/vfs_syscalls.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

vfs_vnops.ln: $S/kern/vfs_vnops.c
	${NORMAL_LINT}

vfs_vnops.o: $S/kern/vfs_vnops.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

arc4random.ln: $S/libkern/arc4random.c
	${NORMAL_LINT}

arc4random.o: $S/libkern/arc4random.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

asprintf.ln: $S/libkern/asprintf.c
	${NORMAL_LINT}

asprintf.o: $S/libkern/asprintf.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

bcd.ln: $S/libkern/bcd.c
	${NORMAL_LINT}

bcd.o: $S/libkern/bcd.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

bsearch.ln: $S/libkern/bsearch.c
	${NORMAL_LINT}

bsearch.o: $S/libkern/bsearch.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

crc32.ln: $S/libkern/crc32.c
	${NORMAL_LINT}

crc32.o: $S/libkern/crc32.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

explicit_bzero.ln: $S/libkern/explicit_bzero.c
	${NORMAL_LINT}

explicit_bzero.o: $S/libkern/explicit_bzero.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

fnmatch.ln: $S/libkern/fnmatch.c
	${NORMAL_LINT}

fnmatch.o: $S/libkern/fnmatch.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

inet_aton.ln: $S/libkern/inet_aton.c
	${NORMAL_LINT}

inet_aton.o: $S/libkern/inet_aton.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

inet_ntoa.ln: $S/libkern/inet_ntoa.c
	${NORMAL_LINT}

inet_ntoa.o: $S/libkern/inet_ntoa.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

inet_ntop.ln: $S/libkern/inet_ntop.c
	${NORMAL_LINT}

inet_ntop.o: $S/libkern/inet_ntop.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

inet_pton.ln: $S/libkern/inet_pton.c
	${NORMAL_LINT}

inet_pton.o: $S/libkern/inet_pton.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

jenkins_hash.ln: $S/libkern/jenkins_hash.c
	${NORMAL_LINT}

jenkins_hash.o: $S/libkern/jenkins_hash.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

murmur3_32.ln: $S/libkern/murmur3_32.c
	${NORMAL_LINT}

murmur3_32.o: $S/libkern/murmur3_32.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

memcchr.ln: $S/libkern/memcchr.c
	${NORMAL_LINT}

memcchr.o: $S/libkern/memcchr.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

memchr.ln: $S/libkern/memchr.c
	${NORMAL_LINT}

memchr.o: $S/libkern/memchr.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

memcmp.ln: $S/libkern/memcmp.c
	${NORMAL_LINT}

memcmp.o: $S/libkern/memcmp.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

qsort.ln: $S/libkern/qsort.c
	${NORMAL_LINT}

qsort.o: $S/libkern/qsort.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

qsort_r.ln: $S/libkern/qsort_r.c
	${NORMAL_LINT}

qsort_r.o: $S/libkern/qsort_r.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

random.ln: $S/libkern/random.c
	${NORMAL_LINT}

random.o: $S/libkern/random.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

scanc.ln: $S/libkern/scanc.c
	${NORMAL_LINT}

scanc.o: $S/libkern/scanc.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

strcasecmp.ln: $S/libkern/strcasecmp.c
	${NORMAL_LINT}

strcasecmp.o: $S/libkern/strcasecmp.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

strcat.ln: $S/libkern/strcat.c
	${NORMAL_LINT}

strcat.o: $S/libkern/strcat.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

strchr.ln: $S/libkern/strchr.c
	${NORMAL_LINT}

strchr.o: $S/libkern/strchr.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

strcmp.ln: $S/libkern/strcmp.c
	${NORMAL_LINT}

strcmp.o: $S/libkern/strcmp.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

strcpy.ln: $S/libkern/strcpy.c
	${NORMAL_LINT}

strcpy.o: $S/libkern/strcpy.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

strcspn.ln: $S/libkern/strcspn.c
	${NORMAL_LINT}

strcspn.o: $S/libkern/strcspn.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

strdup.ln: $S/libkern/strdup.c
	${NORMAL_LINT}

strdup.o: $S/libkern/strdup.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

strndup.ln: $S/libkern/strndup.c
	${NORMAL_LINT}

strndup.o: $S/libkern/strndup.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

strlcat.ln: $S/libkern/strlcat.c
	${NORMAL_LINT}

strlcat.o: $S/libkern/strlcat.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

strlcpy.ln: $S/libkern/strlcpy.c
	${NORMAL_LINT}

strlcpy.o: $S/libkern/strlcpy.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

strlen.ln: $S/libkern/strlen.c
	${NORMAL_LINT}

strlen.o: $S/libkern/strlen.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

strncmp.ln: $S/libkern/strncmp.c
	${NORMAL_LINT}

strncmp.o: $S/libkern/strncmp.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

strncpy.ln: $S/libkern/strncpy.c
	${NORMAL_LINT}

strncpy.o: $S/libkern/strncpy.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

strnlen.ln: $S/libkern/strnlen.c
	${NORMAL_LINT}

strnlen.o: $S/libkern/strnlen.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

strrchr.ln: $S/libkern/strrchr.c
	${NORMAL_LINT}

strrchr.o: $S/libkern/strrchr.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

strsep.ln: $S/libkern/strsep.c
	${NORMAL_LINT}

strsep.o: $S/libkern/strsep.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

strspn.ln: $S/libkern/strspn.c
	${NORMAL_LINT}

strspn.o: $S/libkern/strspn.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

strstr.ln: $S/libkern/strstr.c
	${NORMAL_LINT}

strstr.o: $S/libkern/strstr.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

strtol.ln: $S/libkern/strtol.c
	${NORMAL_LINT}

strtol.o: $S/libkern/strtol.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

strtoq.ln: $S/libkern/strtoq.c
	${NORMAL_LINT}

strtoq.o: $S/libkern/strtoq.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

strtoul.ln: $S/libkern/strtoul.c
	${NORMAL_LINT}

strtoul.o: $S/libkern/strtoul.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

strtouq.ln: $S/libkern/strtouq.c
	${NORMAL_LINT}

strtouq.o: $S/libkern/strtouq.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

strvalid.ln: $S/libkern/strvalid.c
	${NORMAL_LINT}

strvalid.o: $S/libkern/strvalid.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

timingsafe_bcmp.ln: $S/libkern/timingsafe_bcmp.c
	${NORMAL_LINT}

timingsafe_bcmp.o: $S/libkern/timingsafe_bcmp.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

zlib.ln: $S/libkern/zlib.c
	${NORMAL_LINT}

zlib.o: $S/libkern/zlib.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

bpf.ln: $S/net/bpf.c
	${NORMAL_LINT}

bpf.o: $S/net/bpf.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

bpf_buffer.ln: $S/net/bpf_buffer.c
	${NORMAL_LINT}

bpf_buffer.o: $S/net/bpf_buffer.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

bpf_filter.ln: $S/net/bpf_filter.c
	${NORMAL_LINT}

bpf_filter.o: $S/net/bpf_filter.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

bpf_zerocopy.ln: $S/net/bpf_zerocopy.c
	${NORMAL_LINT}

bpf_zerocopy.o: $S/net/bpf_zerocopy.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

bridgestp.ln: $S/net/bridgestp.c
	${NORMAL_LINT}

bridgestp.o: $S/net/bridgestp.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

if.ln: $S/net/if.c
	${NORMAL_LINT}

if.o: $S/net/if.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

if_bridge.ln: $S/net/if_bridge.c
	${NORMAL_LINT}

if_bridge.o: $S/net/if_bridge.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

if_clone.ln: $S/net/if_clone.c
	${NORMAL_LINT}

if_clone.o: $S/net/if_clone.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

if_dead.ln: $S/net/if_dead.c
	${NORMAL_LINT}

if_dead.o: $S/net/if_dead.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

if_debug.ln: $S/net/if_debug.c
	${NORMAL_LINT}

if_debug.o: $S/net/if_debug.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

if_ethersubr.ln: $S/net/if_ethersubr.c
	${NORMAL_LINT}

if_ethersubr.o: $S/net/if_ethersubr.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

if_loop.ln: $S/net/if_loop.c
	${NORMAL_LINT}

if_loop.o: $S/net/if_loop.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

if_llatbl.ln: $S/net/if_llatbl.c
	${NORMAL_LINT}

if_llatbl.o: $S/net/if_llatbl.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

if_media.ln: $S/net/if_media.c
	${NORMAL_LINT}

if_media.o: $S/net/if_media.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

if_mib.ln: $S/net/if_mib.c
	${NORMAL_LINT}

if_mib.o: $S/net/if_mib.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

netisr.ln: $S/net/netisr.c
	${NORMAL_LINT}

netisr.o: $S/net/netisr.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

pfil.ln: $S/net/pfil.c
	${NORMAL_LINT}

pfil.o: $S/net/pfil.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

radix.ln: $S/net/radix.c
	${NORMAL_LINT}

radix.o: $S/net/radix.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

radix_mpath.ln: $S/net/radix_mpath.c
	${NORMAL_LINT}

radix_mpath.o: $S/net/radix_mpath.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

raw_cb.ln: $S/net/raw_cb.c
	${NORMAL_LINT}

raw_cb.o: $S/net/raw_cb.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

raw_usrreq.ln: $S/net/raw_usrreq.c
	${NORMAL_LINT}

raw_usrreq.o: $S/net/raw_usrreq.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

route.ln: $S/net/route.c
	${NORMAL_LINT}

route.o: $S/net/route.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

rtsock.ln: $S/net/rtsock.c
	${NORMAL_LINT}

rtsock.o: $S/net/rtsock.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

ieee80211.ln: $S/net80211/ieee80211.c
	${NORMAL_LINT}

ieee80211.o: $S/net80211/ieee80211.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

ieee80211_action.ln: $S/net80211/ieee80211_action.c
	${NORMAL_LINT}

ieee80211_action.o: $S/net80211/ieee80211_action.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

ieee80211_ageq.ln: $S/net80211/ieee80211_ageq.c
	${NORMAL_LINT}

ieee80211_ageq.o: $S/net80211/ieee80211_ageq.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

ieee80211_adhoc.ln: $S/net80211/ieee80211_adhoc.c
	${NORMAL_LINT}

ieee80211_adhoc.o: $S/net80211/ieee80211_adhoc.c
	${NORMAL_C} -Wno-unused-function
	${NORMAL_CTFCONVERT}

ieee80211_amrr.ln: $S/net80211/ieee80211_amrr.c
	${NORMAL_LINT}

ieee80211_amrr.o: $S/net80211/ieee80211_amrr.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

ieee80211_crypto.ln: $S/net80211/ieee80211_crypto.c
	${NORMAL_LINT}

ieee80211_crypto.o: $S/net80211/ieee80211_crypto.c
	${NORMAL_C} -Wno-unused-function
	${NORMAL_CTFCONVERT}

ieee80211_crypto_ccmp.ln: $S/net80211/ieee80211_crypto_ccmp.c
	${NORMAL_LINT}

ieee80211_crypto_ccmp.o: $S/net80211/ieee80211_crypto_ccmp.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

ieee80211_crypto_none.ln: $S/net80211/ieee80211_crypto_none.c
	${NORMAL_LINT}

ieee80211_crypto_none.o: $S/net80211/ieee80211_crypto_none.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

ieee80211_crypto_tkip.ln: $S/net80211/ieee80211_crypto_tkip.c
	${NORMAL_LINT}

ieee80211_crypto_tkip.o: $S/net80211/ieee80211_crypto_tkip.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

ieee80211_crypto_wep.ln: $S/net80211/ieee80211_crypto_wep.c
	${NORMAL_LINT}

ieee80211_crypto_wep.o: $S/net80211/ieee80211_crypto_wep.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

ieee80211_ddb.ln: $S/net80211/ieee80211_ddb.c
	${NORMAL_LINT}

ieee80211_ddb.o: $S/net80211/ieee80211_ddb.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

ieee80211_dfs.ln: $S/net80211/ieee80211_dfs.c
	${NORMAL_LINT}

ieee80211_dfs.o: $S/net80211/ieee80211_dfs.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

ieee80211_freebsd.ln: $S/net80211/ieee80211_freebsd.c
	${NORMAL_LINT}

ieee80211_freebsd.o: $S/net80211/ieee80211_freebsd.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

ieee80211_hostap.ln: $S/net80211/ieee80211_hostap.c
	${NORMAL_LINT}

ieee80211_hostap.o: $S/net80211/ieee80211_hostap.c
	${NORMAL_C} -Wno-unused-function
	${NORMAL_CTFCONVERT}

ieee80211_ht.ln: $S/net80211/ieee80211_ht.c
	${NORMAL_LINT}

ieee80211_ht.o: $S/net80211/ieee80211_ht.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

ieee80211_hwmp.ln: $S/net80211/ieee80211_hwmp.c
	${NORMAL_LINT}

ieee80211_hwmp.o: $S/net80211/ieee80211_hwmp.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

ieee80211_input.ln: $S/net80211/ieee80211_input.c
	${NORMAL_LINT}

ieee80211_input.o: $S/net80211/ieee80211_input.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

ieee80211_ioctl.ln: $S/net80211/ieee80211_ioctl.c
	${NORMAL_LINT}

ieee80211_ioctl.o: $S/net80211/ieee80211_ioctl.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

ieee80211_mesh.ln: $S/net80211/ieee80211_mesh.c
	${NORMAL_LINT}

ieee80211_mesh.o: $S/net80211/ieee80211_mesh.c
	${NORMAL_C} -Wno-unused-function
	${NORMAL_CTFCONVERT}

ieee80211_monitor.ln: $S/net80211/ieee80211_monitor.c
	${NORMAL_LINT}

ieee80211_monitor.o: $S/net80211/ieee80211_monitor.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

ieee80211_node.ln: $S/net80211/ieee80211_node.c
	${NORMAL_LINT}

ieee80211_node.o: $S/net80211/ieee80211_node.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

ieee80211_output.ln: $S/net80211/ieee80211_output.c
	${NORMAL_LINT}

ieee80211_output.o: $S/net80211/ieee80211_output.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

ieee80211_phy.ln: $S/net80211/ieee80211_phy.c
	${NORMAL_LINT}

ieee80211_phy.o: $S/net80211/ieee80211_phy.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

ieee80211_power.ln: $S/net80211/ieee80211_power.c
	${NORMAL_LINT}

ieee80211_power.o: $S/net80211/ieee80211_power.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

ieee80211_proto.ln: $S/net80211/ieee80211_proto.c
	${NORMAL_LINT}

ieee80211_proto.o: $S/net80211/ieee80211_proto.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

ieee80211_radiotap.ln: $S/net80211/ieee80211_radiotap.c
	${NORMAL_LINT}

ieee80211_radiotap.o: $S/net80211/ieee80211_radiotap.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

ieee80211_ratectl.ln: $S/net80211/ieee80211_ratectl.c
	${NORMAL_LINT}

ieee80211_ratectl.o: $S/net80211/ieee80211_ratectl.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

ieee80211_ratectl_none.ln: $S/net80211/ieee80211_ratectl_none.c
	${NORMAL_LINT}

ieee80211_ratectl_none.o: $S/net80211/ieee80211_ratectl_none.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

ieee80211_regdomain.ln: $S/net80211/ieee80211_regdomain.c
	${NORMAL_LINT}

ieee80211_regdomain.o: $S/net80211/ieee80211_regdomain.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

ieee80211_scan.ln: $S/net80211/ieee80211_scan.c
	${NORMAL_LINT}

ieee80211_scan.o: $S/net80211/ieee80211_scan.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

ieee80211_scan_sta.ln: $S/net80211/ieee80211_scan_sta.c
	${NORMAL_LINT}

ieee80211_scan_sta.o: $S/net80211/ieee80211_scan_sta.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

ieee80211_sta.ln: $S/net80211/ieee80211_sta.c
	${NORMAL_LINT}

ieee80211_sta.o: $S/net80211/ieee80211_sta.c
	${NORMAL_C} -Wno-unused-function
	${NORMAL_CTFCONVERT}

ieee80211_superg.ln: $S/net80211/ieee80211_superg.c
	${NORMAL_LINT}

ieee80211_superg.o: $S/net80211/ieee80211_superg.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

ieee80211_scan_sw.ln: $S/net80211/ieee80211_scan_sw.c
	${NORMAL_LINT}

ieee80211_scan_sw.o: $S/net80211/ieee80211_scan_sw.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

ieee80211_tdma.ln: $S/net80211/ieee80211_tdma.c
	${NORMAL_LINT}

ieee80211_tdma.o: $S/net80211/ieee80211_tdma.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

ieee80211_wds.ln: $S/net80211/ieee80211_wds.c
	${NORMAL_LINT}

ieee80211_wds.o: $S/net80211/ieee80211_wds.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

ieee80211_xauth.ln: $S/net80211/ieee80211_xauth.c
	${NORMAL_LINT}

ieee80211_xauth.o: $S/net80211/ieee80211_xauth.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

ieee80211_alq.ln: $S/net80211/ieee80211_alq.c
	${NORMAL_LINT}

ieee80211_alq.o: $S/net80211/ieee80211_alq.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

if_ether.ln: $S/netinet/if_ether.c
	${NORMAL_LINT}

if_ether.o: $S/netinet/if_ether.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

igmp.ln: $S/netinet/igmp.c
	${NORMAL_LINT}

igmp.o: $S/netinet/igmp.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

in.ln: $S/netinet/in.c
	${NORMAL_LINT}

in.o: $S/netinet/in.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

in_debug.ln: $S/netinet/in_debug.c
	${NORMAL_LINT}

in_debug.o: $S/netinet/in_debug.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

in_kdtrace.ln: $S/netinet/in_kdtrace.c
	${NORMAL_LINT}

in_kdtrace.o: $S/netinet/in_kdtrace.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

in_fib.ln: $S/netinet/in_fib.c
	${NORMAL_LINT}

in_fib.o: $S/netinet/in_fib.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

ip_id.ln: $S/netinet/ip_id.c
	${NORMAL_LINT}

ip_id.o: $S/netinet/ip_id.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

in_mcast.ln: $S/netinet/in_mcast.c
	${NORMAL_LINT}

in_mcast.o: $S/netinet/in_mcast.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

in_pcb.ln: $S/netinet/in_pcb.c
	${NORMAL_LINT}

in_pcb.o: $S/netinet/in_pcb.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

in_proto.ln: $S/netinet/in_proto.c
	${NORMAL_LINT}

in_proto.o: $S/netinet/in_proto.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

in_rmx.ln: $S/netinet/in_rmx.c
	${NORMAL_LINT}

in_rmx.o: $S/netinet/in_rmx.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

ip_ecn.ln: $S/netinet/ip_ecn.c
	${NORMAL_LINT}

ip_ecn.o: $S/netinet/ip_ecn.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

ip_encap.ln: $S/netinet/ip_encap.c
	${NORMAL_LINT}

ip_encap.o: $S/netinet/ip_encap.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

ip_fastfwd.ln: $S/netinet/ip_fastfwd.c
	${NORMAL_LINT}

ip_fastfwd.o: $S/netinet/ip_fastfwd.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

ip_icmp.ln: $S/netinet/ip_icmp.c
	${NORMAL_LINT}

ip_icmp.o: $S/netinet/ip_icmp.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

ip_input.ln: $S/netinet/ip_input.c
	${NORMAL_LINT}

ip_input.o: $S/netinet/ip_input.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

ip_options.ln: $S/netinet/ip_options.c
	${NORMAL_LINT}

ip_options.o: $S/netinet/ip_options.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

ip_output.ln: $S/netinet/ip_output.c
	${NORMAL_LINT}

ip_output.o: $S/netinet/ip_output.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

ip_reass.ln: $S/netinet/ip_reass.c
	${NORMAL_LINT}

ip_reass.o: $S/netinet/ip_reass.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

raw_ip.ln: $S/netinet/raw_ip.c
	${NORMAL_LINT}

raw_ip.o: $S/netinet/raw_ip.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

cc.ln: $S/netinet/cc/cc.c
	${NORMAL_LINT}

cc.o: $S/netinet/cc/cc.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

cc_newreno.ln: $S/netinet/cc/cc_newreno.c
	${NORMAL_LINT}

cc_newreno.o: $S/netinet/cc/cc_newreno.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

tcp_hostcache.ln: $S/netinet/tcp_hostcache.c
	${NORMAL_LINT}

tcp_hostcache.o: $S/netinet/tcp_hostcache.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

tcp_input.ln: $S/netinet/tcp_input.c
	${NORMAL_LINT}

tcp_input.o: $S/netinet/tcp_input.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

tcp_lro.ln: $S/netinet/tcp_lro.c
	${NORMAL_LINT}

tcp_lro.o: $S/netinet/tcp_lro.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

tcp_output.ln: $S/netinet/tcp_output.c
	${NORMAL_LINT}

tcp_output.o: $S/netinet/tcp_output.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

tcp_reass.ln: $S/netinet/tcp_reass.c
	${NORMAL_LINT}

tcp_reass.o: $S/netinet/tcp_reass.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

tcp_sack.ln: $S/netinet/tcp_sack.c
	${NORMAL_LINT}

tcp_sack.o: $S/netinet/tcp_sack.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

tcp_subr.ln: $S/netinet/tcp_subr.c
	${NORMAL_LINT}

tcp_subr.o: $S/netinet/tcp_subr.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

tcp_syncache.ln: $S/netinet/tcp_syncache.c
	${NORMAL_LINT}

tcp_syncache.o: $S/netinet/tcp_syncache.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

tcp_timer.ln: $S/netinet/tcp_timer.c
	${NORMAL_LINT}

tcp_timer.o: $S/netinet/tcp_timer.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

tcp_timewait.ln: $S/netinet/tcp_timewait.c
	${NORMAL_LINT}

tcp_timewait.o: $S/netinet/tcp_timewait.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

tcp_usrreq.ln: $S/netinet/tcp_usrreq.c
	${NORMAL_LINT}

tcp_usrreq.o: $S/netinet/tcp_usrreq.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

udp_usrreq.ln: $S/netinet/udp_usrreq.c
	${NORMAL_LINT}

udp_usrreq.o: $S/netinet/udp_usrreq.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

audit_syscalls.ln: $S/security/audit/audit_syscalls.c
	${NORMAL_LINT}

audit_syscalls.o: $S/security/audit/audit_syscalls.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

mac_syscalls.ln: $S/security/mac/mac_syscalls.c
	${NORMAL_LINT}

mac_syscalls.o: $S/security/mac/mac_syscalls.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

ffs_alloc.ln: $S/ufs/ffs/ffs_alloc.c
	${NORMAL_LINT}

ffs_alloc.o: $S/ufs/ffs/ffs_alloc.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

ffs_balloc.ln: $S/ufs/ffs/ffs_balloc.c
	${NORMAL_LINT}

ffs_balloc.o: $S/ufs/ffs/ffs_balloc.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

ffs_inode.ln: $S/ufs/ffs/ffs_inode.c
	${NORMAL_LINT}

ffs_inode.o: $S/ufs/ffs/ffs_inode.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

ffs_snapshot.ln: $S/ufs/ffs/ffs_snapshot.c
	${NORMAL_LINT}

ffs_snapshot.o: $S/ufs/ffs/ffs_snapshot.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

ffs_softdep.ln: $S/ufs/ffs/ffs_softdep.c
	${NORMAL_LINT}

ffs_softdep.o: $S/ufs/ffs/ffs_softdep.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

ffs_subr.ln: $S/ufs/ffs/ffs_subr.c
	${NORMAL_LINT}

ffs_subr.o: $S/ufs/ffs/ffs_subr.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

ffs_tables.ln: $S/ufs/ffs/ffs_tables.c
	${NORMAL_LINT}

ffs_tables.o: $S/ufs/ffs/ffs_tables.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

ffs_vfsops.ln: $S/ufs/ffs/ffs_vfsops.c
	${NORMAL_LINT}

ffs_vfsops.o: $S/ufs/ffs/ffs_vfsops.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

ffs_vnops.ln: $S/ufs/ffs/ffs_vnops.c
	${NORMAL_LINT}

ffs_vnops.o: $S/ufs/ffs/ffs_vnops.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

ffs_suspend.ln: $S/ufs/ffs/ffs_suspend.c
	${NORMAL_LINT}

ffs_suspend.o: $S/ufs/ffs/ffs_suspend.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

ufs_acl.ln: $S/ufs/ufs/ufs_acl.c
	${NORMAL_LINT}

ufs_acl.o: $S/ufs/ufs/ufs_acl.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

ufs_bmap.ln: $S/ufs/ufs/ufs_bmap.c
	${NORMAL_LINT}

ufs_bmap.o: $S/ufs/ufs/ufs_bmap.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

ufs_dirhash.ln: $S/ufs/ufs/ufs_dirhash.c
	${NORMAL_LINT}

ufs_dirhash.o: $S/ufs/ufs/ufs_dirhash.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

ufs_extattr.ln: $S/ufs/ufs/ufs_extattr.c
	${NORMAL_LINT}

ufs_extattr.o: $S/ufs/ufs/ufs_extattr.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

ufs_inode.ln: $S/ufs/ufs/ufs_inode.c
	${NORMAL_LINT}

ufs_inode.o: $S/ufs/ufs/ufs_inode.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

ufs_lookup.ln: $S/ufs/ufs/ufs_lookup.c
	${NORMAL_LINT}

ufs_lookup.o: $S/ufs/ufs/ufs_lookup.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

ufs_quota.ln: $S/ufs/ufs/ufs_quota.c
	${NORMAL_LINT}

ufs_quota.o: $S/ufs/ufs/ufs_quota.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

ufs_vfsops.ln: $S/ufs/ufs/ufs_vfsops.c
	${NORMAL_LINT}

ufs_vfsops.o: $S/ufs/ufs/ufs_vfsops.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

ufs_vnops.ln: $S/ufs/ufs/ufs_vnops.c
	${NORMAL_LINT}

ufs_vnops.o: $S/ufs/ufs/ufs_vnops.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

default_pager.ln: $S/vm/default_pager.c
	${NORMAL_LINT}

default_pager.o: $S/vm/default_pager.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

device_pager.ln: $S/vm/device_pager.c
	${NORMAL_LINT}

device_pager.o: $S/vm/device_pager.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

phys_pager.ln: $S/vm/phys_pager.c
	${NORMAL_LINT}

phys_pager.o: $S/vm/phys_pager.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

sg_pager.ln: $S/vm/sg_pager.c
	${NORMAL_LINT}

sg_pager.o: $S/vm/sg_pager.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

swap_pager.ln: $S/vm/swap_pager.c
	${NORMAL_LINT}

swap_pager.o: $S/vm/swap_pager.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

uma_core.ln: $S/vm/uma_core.c
	${NORMAL_LINT}

uma_core.o: $S/vm/uma_core.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

uma_dbg.ln: $S/vm/uma_dbg.c
	${NORMAL_LINT}

uma_dbg.o: $S/vm/uma_dbg.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

vm_fault.ln: $S/vm/vm_fault.c
	${NORMAL_LINT}

vm_fault.o: $S/vm/vm_fault.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

vm_glue.ln: $S/vm/vm_glue.c
	${NORMAL_LINT}

vm_glue.o: $S/vm/vm_glue.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

vm_init.ln: $S/vm/vm_init.c
	${NORMAL_LINT}

vm_init.o: $S/vm/vm_init.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

vm_kern.ln: $S/vm/vm_kern.c
	${NORMAL_LINT}

vm_kern.o: $S/vm/vm_kern.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

vm_map.ln: $S/vm/vm_map.c
	${NORMAL_LINT}

vm_map.o: $S/vm/vm_map.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

vm_meter.ln: $S/vm/vm_meter.c
	${NORMAL_LINT}

vm_meter.o: $S/vm/vm_meter.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

vm_mmap.ln: $S/vm/vm_mmap.c
	${NORMAL_LINT}

vm_mmap.o: $S/vm/vm_mmap.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

vm_object.ln: $S/vm/vm_object.c
	${NORMAL_LINT}

vm_object.o: $S/vm/vm_object.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

vm_page.ln: $S/vm/vm_page.c
	${NORMAL_LINT}

vm_page.o: $S/vm/vm_page.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

vm_pageout.ln: $S/vm/vm_pageout.c
	${NORMAL_LINT}

vm_pageout.o: $S/vm/vm_pageout.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

vm_pager.ln: $S/vm/vm_pager.c
	${NORMAL_LINT}

vm_pager.o: $S/vm/vm_pager.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

vm_phys.ln: $S/vm/vm_phys.c
	${NORMAL_LINT}

vm_phys.o: $S/vm/vm_phys.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

vm_radix.ln: $S/vm/vm_radix.c
	${NORMAL_LINT}

vm_radix.o: $S/vm/vm_radix.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

vm_reserv.ln: $S/vm/vm_reserv.c
	${NORMAL_LINT}

vm_reserv.o: $S/vm/vm_reserv.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

vm_domain.ln: $S/vm/vm_domain.c
	${NORMAL_LINT}

vm_domain.o: $S/vm/vm_domain.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

vm_unix.ln: $S/vm/vm_unix.c
	${NORMAL_LINT}

vm_unix.o: $S/vm/vm_unix.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

vm_zeroidle.ln: $S/vm/vm_zeroidle.c
	${NORMAL_LINT}

vm_zeroidle.o: $S/vm/vm_zeroidle.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

vnode_pager.ln: $S/vm/vnode_pager.c
	${NORMAL_LINT}

vnode_pager.o: $S/vm/vnode_pager.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

autoconf.ln: $S/mips/mips/autoconf.c
	${NORMAL_LINT}

autoconf.o: $S/mips/mips/autoconf.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

bus_space_generic.ln: $S/mips/mips/bus_space_generic.c
	${NORMAL_LINT}

bus_space_generic.o: $S/mips/mips/bus_space_generic.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

busdma_machdep.ln: $S/mips/mips/busdma_machdep.c
	${NORMAL_LINT}

busdma_machdep.o: $S/mips/mips/busdma_machdep.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

cache.ln: $S/mips/mips/cache.c
	${NORMAL_LINT}

cache.o: $S/mips/mips/cache.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

cache_mipsNN.ln: $S/mips/mips/cache_mipsNN.c
	${NORMAL_LINT}

cache_mipsNN.o: $S/mips/mips/cache_mipsNN.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

cpu.ln: $S/mips/mips/cpu.c
	${NORMAL_LINT}

cpu.o: $S/mips/mips/cpu.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

db_disasm.ln: $S/mips/mips/db_disasm.c
	${NORMAL_LINT}

db_disasm.o: $S/mips/mips/db_disasm.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

db_interface.ln: $S/mips/mips/db_interface.c
	${NORMAL_LINT}

db_interface.o: $S/mips/mips/db_interface.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

db_trace.ln: $S/mips/mips/db_trace.c
	${NORMAL_LINT}

db_trace.o: $S/mips/mips/db_trace.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

dump_machdep.ln: $S/mips/mips/dump_machdep.c
	${NORMAL_LINT}

dump_machdep.o: $S/mips/mips/dump_machdep.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

elf_machdep.ln: $S/mips/mips/elf_machdep.c
	${NORMAL_LINT}

elf_machdep.o: $S/mips/mips/elf_machdep.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

exception.ln: $S/mips/mips/exception.S
	${NORMAL_LINT}

exception.o: $S/mips/mips/exception.S
	${NORMAL_S}
	${NORMAL_CTFCONVERT}

fp.ln: $S/mips/mips/fp.S
	${NORMAL_LINT}

fp.o: $S/mips/mips/fp.S
	${NORMAL_S}
	${NORMAL_CTFCONVERT}

gdb_machdep.ln: $S/mips/mips/gdb_machdep.c
	${NORMAL_LINT}

gdb_machdep.o: $S/mips/mips/gdb_machdep.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

in_cksum.ln: $S/mips/mips/in_cksum.c
	${NORMAL_LINT}

in_cksum.o: $S/mips/mips/in_cksum.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

libkern_machdep.ln: $S/mips/mips/libkern_machdep.c
	${NORMAL_LINT}

libkern_machdep.o: $S/mips/mips/libkern_machdep.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

locore.ln: $S/mips/mips/locore.S
	${NORMAL_LINT}

locore.o: $S/mips/mips/locore.S
	${NORMAL_S}

machdep.ln: $S/mips/mips/machdep.c
	${NORMAL_LINT}

machdep.o: $S/mips/mips/machdep.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

mem.ln: $S/mips/mips/mem.c
	${NORMAL_LINT}

mem.o: $S/mips/mips/mem.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

minidump_machdep.ln: $S/mips/mips/minidump_machdep.c
	${NORMAL_LINT}

minidump_machdep.o: $S/mips/mips/minidump_machdep.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

nexus.ln: $S/mips/mips/nexus.c
	${NORMAL_LINT}

nexus.o: $S/mips/mips/nexus.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

pm_machdep.ln: $S/mips/mips/pm_machdep.c
	${NORMAL_LINT}

pm_machdep.o: $S/mips/mips/pm_machdep.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

pmap.ln: $S/mips/mips/pmap.c
	${NORMAL_LINT}

pmap.o: $S/mips/mips/pmap.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

ptrace_machdep.ln: $S/mips/mips/ptrace_machdep.c
	${NORMAL_LINT}

ptrace_machdep.o: $S/mips/mips/ptrace_machdep.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

sc_machdep.ln: $S/mips/mips/sc_machdep.c
	${NORMAL_LINT}

sc_machdep.o: $S/mips/mips/sc_machdep.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

stack_machdep.ln: $S/mips/mips/stack_machdep.c
	${NORMAL_LINT}

stack_machdep.o: $S/mips/mips/stack_machdep.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

stdatomic.ln: $S/mips/mips/stdatomic.c
	${NORMAL_LINT}

stdatomic.o: $S/mips/mips/stdatomic.c
	${NORMAL_C:N-Wmissing-prototypes}
	${NORMAL_CTFCONVERT}

support.ln: $S/mips/mips/support.S
	${NORMAL_LINT}

support.o: $S/mips/mips/support.S
	${NORMAL_S}
	${NORMAL_CTFCONVERT}

bcopy.ln: $S/mips/mips/bcopy.S
	${NORMAL_LINT}

bcopy.o: $S/mips/mips/bcopy.S
	${NORMAL_S}
	${NORMAL_CTFCONVERT}

swtch.ln: $S/mips/mips/swtch.S
	${NORMAL_LINT}

swtch.o: $S/mips/mips/swtch.S
	${NORMAL_S}
	${NORMAL_CTFCONVERT}

sys_machdep.ln: $S/mips/mips/sys_machdep.c
	${NORMAL_LINT}

sys_machdep.o: $S/mips/mips/sys_machdep.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

tlb.ln: $S/mips/mips/tlb.c
	${NORMAL_LINT}

tlb.o: $S/mips/mips/tlb.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

trap.ln: $S/mips/mips/trap.c
	${NORMAL_LINT}

trap.o: $S/mips/mips/trap.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

uio_machdep.ln: $S/mips/mips/uio_machdep.c
	${NORMAL_LINT}

uio_machdep.o: $S/mips/mips/uio_machdep.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

uma_machdep.ln: $S/mips/mips/uma_machdep.c
	${NORMAL_LINT}

uma_machdep.o: $S/mips/mips/uma_machdep.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

vm_machdep.ln: $S/mips/mips/vm_machdep.c
	${NORMAL_LINT}

vm_machdep.o: $S/mips/mips/vm_machdep.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

kern_clocksource.ln: $S/kern/kern_clocksource.c
	${NORMAL_LINT}

kern_clocksource.o: $S/kern/kern_clocksource.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

link_elf_obj.ln: $S/kern/link_elf_obj.c
	${NORMAL_LINT}

link_elf_obj.o: $S/kern/link_elf_obj.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

subr_busdma_bufalloc.ln: $S/kern/subr_busdma_bufalloc.c
	${NORMAL_LINT}

subr_busdma_bufalloc.o: $S/kern/subr_busdma_bufalloc.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

subr_dummy_vdso_tc.ln: $S/kern/subr_dummy_vdso_tc.c
	${NORMAL_LINT}

subr_dummy_vdso_tc.o: $S/kern/subr_dummy_vdso_tc.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

subr_sfbuf.ln: $S/kern/subr_sfbuf.c
	${NORMAL_LINT}

subr_sfbuf.o: $S/kern/subr_sfbuf.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

ffsl.ln: $S/libkern/ffsl.c
	${NORMAL_LINT}

ffsl.o: $S/libkern/ffsl.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

ffsll.ln: $S/libkern/ffsll.c
	${NORMAL_LINT}

ffsll.o: $S/libkern/ffsll.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

fls.ln: $S/libkern/fls.c
	${NORMAL_LINT}

fls.o: $S/libkern/fls.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

flsl.ln: $S/libkern/flsl.c
	${NORMAL_LINT}

flsl.o: $S/libkern/flsl.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

flsll.ln: $S/libkern/flsll.c
	${NORMAL_LINT}

flsll.o: $S/libkern/flsll.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

memmove.ln: $S/libkern/memmove.c
	${NORMAL_LINT}

memmove.o: $S/libkern/memmove.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

cmpdi2.ln: $S/libkern/cmpdi2.c
	${NORMAL_LINT}

cmpdi2.o: $S/libkern/cmpdi2.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

ucmpdi2.ln: $S/libkern/ucmpdi2.c
	${NORMAL_LINT}

ucmpdi2.o: $S/libkern/ucmpdi2.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

ashldi3.ln: $S/libkern/ashldi3.c
	${NORMAL_LINT}

ashldi3.o: $S/libkern/ashldi3.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

ashrdi3.ln: $S/libkern/ashrdi3.c
	${NORMAL_LINT}

ashrdi3.o: $S/libkern/ashrdi3.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

apb.ln: $S/mips/atheros/apb.c
	${NORMAL_LINT}

apb.o: $S/mips/atheros/apb.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

ar71xx_gpio.ln: $S/mips/atheros/ar71xx_gpio.c
	${NORMAL_LINT}

ar71xx_gpio.o: $S/mips/atheros/ar71xx_gpio.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

ar71xx_machdep.ln: $S/mips/atheros/ar71xx_machdep.c
	${NORMAL_LINT}

ar71xx_machdep.o: $S/mips/atheros/ar71xx_machdep.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

ar71xx_ehci.ln: $S/mips/atheros/ar71xx_ehci.c
	${NORMAL_LINT}

ar71xx_ehci.o: $S/mips/atheros/ar71xx_ehci.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

ar71xx_spi.ln: $S/mips/atheros/ar71xx_spi.c
	${NORMAL_LINT}

ar71xx_spi.o: $S/mips/atheros/ar71xx_spi.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

ar71xx_macaddr.ln: $S/mips/atheros/ar71xx_macaddr.c
	${NORMAL_LINT}

ar71xx_macaddr.o: $S/mips/atheros/ar71xx_macaddr.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

ar71xx_wdog.ln: $S/mips/atheros/ar71xx_wdog.c
	${NORMAL_LINT}

ar71xx_wdog.o: $S/mips/atheros/ar71xx_wdog.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

if_arge.ln: $S/mips/atheros/if_arge.c
	${NORMAL_LINT}

if_arge.o: $S/mips/atheros/if_arge.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

uart_bus_ar933x.ln: $S/mips/atheros/uart_bus_ar933x.c
	${NORMAL_LINT}

uart_bus_ar933x.o: $S/mips/atheros/uart_bus_ar933x.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

uart_cpu_ar933x.ln: $S/mips/atheros/uart_cpu_ar933x.c
	${NORMAL_LINT}

uart_cpu_ar933x.o: $S/mips/atheros/uart_cpu_ar933x.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

uart_dev_ar933x.ln: $S/mips/atheros/uart_dev_ar933x.c
	${NORMAL_LINT}

uart_dev_ar933x.o: $S/mips/atheros/uart_dev_ar933x.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

ar71xx_bus_space_reversed.ln: $S/mips/atheros/ar71xx_bus_space_reversed.c
	${NORMAL_LINT}

ar71xx_bus_space_reversed.o: $S/mips/atheros/ar71xx_bus_space_reversed.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

intr_machdep.ln: $S/mips/mips/intr_machdep.c
	${NORMAL_LINT}

intr_machdep.o: $S/mips/mips/intr_machdep.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

tick.ln: $S/mips/mips/tick.c
	${NORMAL_LINT}

tick.o: $S/mips/mips/tick.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

ar71xx_setup.ln: $S/mips/atheros/ar71xx_setup.c
	${NORMAL_LINT}

ar71xx_setup.o: $S/mips/atheros/ar71xx_setup.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

ar71xx_chip.ln: $S/mips/atheros/ar71xx_chip.c
	${NORMAL_LINT}

ar71xx_chip.o: $S/mips/atheros/ar71xx_chip.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

ar724x_chip.ln: $S/mips/atheros/ar724x_chip.c
	${NORMAL_LINT}

ar724x_chip.o: $S/mips/atheros/ar724x_chip.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

ar91xx_chip.ln: $S/mips/atheros/ar91xx_chip.c
	${NORMAL_LINT}

ar91xx_chip.o: $S/mips/atheros/ar91xx_chip.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

ar933x_chip.ln: $S/mips/atheros/ar933x_chip.c
	${NORMAL_LINT}

ar933x_chip.o: $S/mips/atheros/ar933x_chip.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

ar934x_chip.ln: $S/mips/atheros/ar934x_chip.c
	${NORMAL_LINT}

ar934x_chip.o: $S/mips/atheros/ar934x_chip.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

qca953x_chip.ln: $S/mips/atheros/qca953x_chip.c
	${NORMAL_LINT}

qca953x_chip.o: $S/mips/atheros/qca953x_chip.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}

qca955x_chip.ln: $S/mips/atheros/qca955x_chip.c
	${NORMAL_LINT}

qca955x_chip.o: $S/mips/atheros/qca955x_chip.c
	${NORMAL_C}
	${NORMAL_CTFCONVERT}


.include "$S/conf/kern.post.mk"
