/* XXX obnoxious prerequisites. */
#define COMPAT_43
#define COMPAT_43TTY
#include <sys/param.h>
#include <sys/devicestat.h>
#include <sys/disklabel.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <sys/tty.h>
#include <bsm/audit.h>
#include <net/ethernet.h>
#include <net/if.h>
#ifdef PF
#include <net/pfvar.h>
#include <net/if_pfsync.h>
#endif
#include <net/route.h>
#include <netinet/in.h>
#include <netinet/ip_mroute.h>
#include <netinet6/in6_var.h>
#include <netinet6/nd6.h>
#include <netinet6/ip6_mroute.h>
#include <stdio.h>
#include <cam/cam.h>
#include <stddef.h>
#include <stdint.h>

#include <cam/cam_compat.h>
#include <cam/scsi/scsi_enc.h>
#include <cam/scsi/scsi_pass.h>
#include <cam/scsi/scsi_sg.h>
#include <cam/scsi/scsi_targetio.h>
#include <crypto/cryptodev.h>
#include <dev/acpica/acpiio.h>
#include <dev/bktr/ioctl_bt848.h>
#include <dev/bktr/ioctl_meteor.h>
#include <dev/ciss/cissio.h>
#include <dev/filemon/filemon.h>
#include <dev/firewire/firewire.h>
#include <dev/iicbus/iic.h>
#include <dev/io/iodev.h>
#include <dev/lmc/if_lmc.h>
#include <dev/mfi/mfi_ioctl.h>
#include <dev/nvme/nvme.h>
#include <dev/ofw/openfirmio.h>
#include <dev/ofw/openpromio.h>
#include <dev/pbio/pbioio.h>
#include <dev/ppbus/lptio.h>
#include <dev/ppbus/ppi.h>
#include <dev/smbus/smb.h>
#include <dev/speaker/speaker.h>
#include <dev/usb/ufm_ioctl.h>
#include <dev/usb/uftdiio.h>
#include <dev/usb/uled_ioctl.h>
#include <dev/usb/usb_ioctl.h>
#include <dev/wi/if_wavelan_ieee.h>
#include <fs/cuse/cuse_ioctl.h>
#include <fs/devfs/devfs.h>
#include <fs/nandfs/nandfs_fs.h>
#include <geom/gate/g_gate.h>
#include <geom/geom_ctl.h>
#include <net/altq/altq.h>
#include <net/altq/altq_cbq.h>
#include <net/altq/altq_cdnr.h>
#include <net/altq/altq_hfsc.h>
#include <net/altq/altq_priq.h>
#include <net/altq/altq_red.h>
#include <net/altq/altq_rio.h>
#include <net/bpf.h>
#include <net/if_atm.h>
#include <net/if_gif.h>
#include <net/if_gre.h>
#include <net/if_lagg.h>
#include <net/if_tap.h>
#include <net/if_tun.h>
#include <net/netmap.h>
#include <net80211/ieee80211_ioctl.h>
#include <netgraph/ng_message.h>
#include <netinet/ip_carp.h>
#include <netinet/ip_fil.h>
#include <netinet/ip_lookup.h>
#include <netinet/ip_nat.h>
#include <netinet/ip_proxy.h>
#include <netinet/ip_scan.h>
#include <netinet/ip_state.h>
#include <netinet6/in6_var.h>
#include <netsmb/smb_dev.h>
#include <rpc/des.h>
#include <security/audit/audit_ioctl.h>
#include <sys/aac_ioctl.h>
#include <sys/agpio.h>
#include <sys/ata.h>
#include <sys/bus.h>
#include <sys/cdio.h>
#include <sys/cdrio.h>
#include <sys/cfictl.h>
#include <sys/chio.h>
#include <sys/consio.h>
#include <sys/cpuctl.h>
#include <sys/dataacq.h>
#include <sys/digiio.h>
#include <sys/dvdio.h>
#include <sys/fbio.h>
#include <sys/fdcio.h>
#include <sys/filio.h>
#include <sys/gpio.h>
#include <sys/ioctl_compat.h>
#include <sys/iov.h>
#include <sys/ipmi.h>
#include <sys/joystick.h>
#include <sys/kbio.h>
#include <sys/ksyms.h>
#include <sys/mdioctl.h>
#include <sys/memrange.h>
#include <sys/mouse.h>
#include <sys/mpt_ioctl.h>
#include <sys/mtio.h>
#include <sys/pciio.h>
#include <sys/pioctl.h>
#include <sys/ptio.h>
#include <sys/snoop.h>
#include <sys/sockio.h>
#include <sys/soundcard.h>
#include <sys/tiio.h>
#include <sys/timepps.h>
#include <sys/ttycom.h>
#include <sys/watchdog.h>
#include <ufs/ffs/fs.h>
#include <sys/diskmbr.h>


void ioctlname(unsigned long val, int decimal);

void
ioctlname(unsigned long val, int decimal)
{
	const char *str = NULL;

	if (val == IOCATARAIDREBUILD)
		str = "IOCATARAIDREBUILD";
	else if (val == SNDCTL_DSP_GETRECVOL)
		str = "SNDCTL_DSP_GETRECVOL";
	else if (val == DVDIOCREPORTKEY)
		str = "DVDIOCREPORTKEY";
	else if (val == SNDCTL_MIDI_PRETIME)
		str = "SNDCTL_MIDI_PRETIME";
	else if (val == SNDCTL_PMGR_ACCESS)
		str = "SNDCTL_PMGR_ACCESS";
	else if (val == RADIO_GETFREQ)
		str = "RADIO_GETFREQ";
	else if (val == DIGIIO_GETALTPIN)
		str = "DIGIIO_GETALTPIN";
	else if (val == CIOCFSESSION)
		str = "CIOCFSESSION";
	else if (val == METEORGVIDEO)
		str = "METEORGVIDEO";
	else if (val == SIOCGPRIVATE_0)
		str = "SIOCGPRIVATE_0";
	else if (val == SIOCGPRIVATE_1)
		str = "SIOCGPRIVATE_1";
	else if (val == TIOCSPGRP)
		str = "TIOCSPGRP";
	else if (val == SIOCSTGET)
		str = "SIOCSTGET";
	else if (val == SNDCTL_DSP_GET_RECSRC_NAMES)
		str = "SNDCTL_DSP_GET_RECSRC_NAMES";
	else if (val == METEORGFMT)
		str = "METEORGFMT";
	else if (val == NIOCREGIF)
		str = "NIOCREGIF";
	else if (val == PIOCCONT)
		str = "PIOCCONT";
	else if (val == SIOCSPFXFLUSH_IN6)
		str = "SIOCSPFXFLUSH_IN6";
	else if (val == CDNR_IF_ATTACH)
		str = "CDNR_IF_ATTACH";
	else if (val == CDIOCGETVOL)
		str = "CDIOCGETVOL";
	else if (val == SIOCGIFPSRCADDR)
		str = "SIOCGIFPSRCADDR";
	else if (val == VMIO_SIOCNETIF)
		str = "VMIO_SIOCNETIF";
	else if (val == SIOCGIFADDR)
		str = "SIOCGIFADDR";
	else if (val == FSACTL_SET_VAR)
		str = "FSACTL_SET_VAR";
	else if (val == SNDCTL_SEQ_RESETSAMPLES)
		str = "SNDCTL_SEQ_RESETSAMPLES";
	else if (val == TIOCSBRK)
		str = "TIOCSBRK";
	else if (val == KDGKBTYPE)
		str = "KDGKBTYPE";
	else if (val == SG_SET_FORCE_PACK_ID)
		str = "SG_SET_FORCE_PACK_ID";
	else if (val == SNDCTL_DSP_SETFRAGMENT)
		str = "SNDCTL_DSP_SETFRAGMENT";
	else if (val == TUNSDEBUG)
		str = "TUNSDEBUG";
	else if (val == SNDCTL_TMR_SELECT)
		str = "SNDCTL_TMR_SELECT";
	else if (val == SIOCGIFDESCR)
		str = "SIOCGIFDESCR";
	else if (val == SNDCTL_TMR_START)
		str = "SNDCTL_TMR_START";
	else if (val == CDIOCPITCH)
		str = "CDIOCPITCH";
	else if (val == SIOCSTGSZ)
		str = "SIOCSTGSZ";
	else if (val == CDRIOCWRITESPEED)
		str = "CDRIOCWRITESPEED";
	else if (val == MPTIO_READ_CFG_PAGE)
		str = "MPTIO_READ_CFG_PAGE";
	else if (val == ENCIOC_GETELMSTAT)
		str = "ENCIOC_GETELMSTAT";
	else if (val == SNDCTL_COPR_RCVMSG)
		str = "SNDCTL_COPR_RCVMSG";
	else if (val == SW_VGA_M80x25)
		str = "SW_VGA_M80x25";
	else if (val == BIOCGHDRCMPLT)
		str = "BIOCGHDRCMPLT";
	else if (val == SW_VGA_M80x30)
		str = "SW_VGA_M80x30";
	else if (val == CDIOCALLOW)
		str = "CDIOCALLOW";
	else if (val == SW_VGA_M80x50)
		str = "SW_VGA_M80x50";
	else if (val == WDIOCPATPAT)
		str = "WDIOCPATPAT";
	else if (val == SNDCTL_TMR_SOURCE)
		str = "SNDCTL_TMR_SOURCE";
	else if (val == SW_VGA_M80x60)
		str = "SW_VGA_M80x60";
	else if (val == TIOCSETD)
		str = "TIOCSETD";
	else if (val == MOUSE_GETLEVEL)
		str = "MOUSE_GETLEVEL";
	else if (val == METEORGCONT)
		str = "METEORGCONT";
	else if (val == CONS_GETTERM)
		str = "CONS_GETTERM";
	else if (val == IOCATAREINIT)
		str = "IOCATAREINIT";
	else if (val == FW_SRSTREAM)
		str = "FW_SRSTREAM";
	else if (val == FBIOPUTCMAPI)
		str = "FBIOPUTCMAPI";
	else if (val == SIOCSIFBRDADDR)
		str = "SIOCSIFBRDADDR";
	else if (val == NANDFS_IOCTL_GET_CPINFO)
		str = "NANDFS_IOCTL_GET_CPINFO";
	else if (val == PIO_DEADKEYMAP)
		str = "PIO_DEADKEYMAP";
	else if (val == TIOCEXCL)
		str = "TIOCEXCL";
	else if (val == SNDCTL_DSP_SET_CHNORDER)
		str = "SNDCTL_DSP_SET_CHNORDER";
	else if (val == SNDCTL_DSP_SETBLKSIZE)
		str = "SNDCTL_DSP_SETBLKSIZE";
	else if (val == KBADDKBD)
		str = "KBADDKBD";
	else if (val == NIOCRXSYNC)
		str = "NIOCRXSYNC";
	else if (val == IOCATADEVICES)
		str = "IOCATADEVICES";
	else if (val == TIOCLSET)
		str = "TIOCLSET";
	else if (val == AIOGFMT)
		str = "AIOGFMT";
	else if (val == SNDCTL_SEQ_NRSYNTHS)
		str = "SNDCTL_SEQ_NRSYNTHS";
	else if (val == USB_GET_ALTINTERFACE)
		str = "USB_GET_ALTINTERFACE";
	else if (val == SIOCADIFR)
		str = "SIOCADIFR";
	else if (val == BIOCSETF)
		str = "BIOCSETF";
	else if (val == SOUND_PCM_READ_BITS)
		str = "SOUND_PCM_READ_BITS";
	else if (val == CDNR_ADD_FILTER)
		str = "CDNR_ADD_FILTER";
	else if (val == BIOCGBLEN)
		str = "BIOCGBLEN";
	else if (val == SW_BG320)
		str = "SW_BG320";
	else if (val == CCISS_SETINTINFO)
		str = "CCISS_SETINTINFO";
	else if (val == FD_STYPE)
		str = "FD_STYPE";
	else if (val == SNDCTL_DSP_MAPINBUF)
		str = "SNDCTL_DSP_MAPINBUF";
	else if (val == CONS_SETCURSORSHAPE)
		str = "CONS_SETCURSORSHAPE";
	else if (val == KIOCGADDR)
		str = "KIOCGADDR";
	else if (val == TIOCGDRAINWAIT)
		str = "TIOCGDRAINWAIT";
	else if (val == CDRIOCSENDCUE)
		str = "CDRIOCSENDCUE";
	else if (val == TIOCMGDTRWAIT)
		str = "TIOCMGDTRWAIT";
	else if (val == SIOCGTUNFIB)
		str = "SIOCGTUNFIB";
	else if (val == SNDCTL_SEQ_GETOUTCOUNT)
		str = "SNDCTL_SEQ_GETOUTCOUNT";
	else if (val == OFIOCGETNEXT)
		str = "OFIOCGETNEXT";
	else if (val == USB_FS_OPEN)
		str = "USB_FS_OPEN";
	else if (val == SIOCSETLG)
		str = "SIOCSETLG";
	else if (val == TVTUNER_GETFREQ)
		str = "TVTUNER_GETFREQ";
	else if (val == FSACTL_DOWNLOAD)
		str = "FSACTL_DOWNLOAD";
	else if (val == SIOCSIFINFO_FLAGS)
		str = "SIOCSIFINFO_FLAGS";
	else if (val == METEORCAPFRM)
		str = "METEORCAPFRM";
	else if (val == SNDCTL_DSP_SETDUPLEX)
		str = "SNDCTL_DSP_SETDUPLEX";
	else if (val == METEORGVWS)
		str = "METEORGVWS";
	else if (val == SNDCTL_MIX_NREXT)
		str = "SNDCTL_MIX_NREXT";
	else if (val == FW_GDEVLST)
		str = "FW_GDEVLST";
	else if (val == IOCATAREQUEST)
		str = "IOCATAREQUEST";
	else if (val == AUDITPIPE_SET_PRESELECT_FLAGS)
		str = "AUDITPIPE_SET_PRESELECT_FLAGS";
	else if (val == USB_GET_RX_BUFFER_SIZE)
		str = "USB_GET_RX_BUFFER_SIZE";
	else if (val == METEORSCSAT)
		str = "METEORSCSAT";
	else if (val == BT848_GHUE)
		str = "BT848_GHUE";
	else if (val == VMIO_SIOCBRIDGE)
		str = "VMIO_SIOCBRIDGE";
	else if (val == SNDCTL_DSP_SETFMT)
		str = "SNDCTL_DSP_SETFMT";
	else if (val == AIOSTOP)
		str = "AIOSTOP";
	else if (val == SIOCGETVIFCNT)
		str = "SIOCGETVIFCNT";
	else if (val == AIONWRITE)
		str = "AIONWRITE";
	else if (val == FSACTL_SEND_RAW_SRB)
		str = "FSACTL_SEND_RAW_SRB";
	else if (val == SNDCTL_DSP_SYNC)
		str = "SNDCTL_DSP_SYNC";
	else if (val == ENCIOC_SETSTRING)
		str = "ENCIOC_SETSTRING";
	else if (val == SNDCTL_DSP_CURRENT_IPTR)
		str = "SNDCTL_DSP_CURRENT_IPTR";
	else if (val == CONS_SAVERMODE)
		str = "CONS_SAVERMODE";
	else if (val == AIOSSIZE)
		str = "AIOSSIZE";
	else if (val == SW_ENH_B80x25)
		str = "SW_ENH_B80x25";
	else if (val == TARGIOCDISABLE)
		str = "TARGIOCDISABLE";
	else if (val == METEORSFMT)
		str = "METEORSFMT";
	else if (val == UFSSUSPEND)
		str = "UFSSUSPEND";
	else if (val == AGPIOC_SETUP)
		str = "AGPIOC_SETUP";
	else if (val == KBRELKBD)
		str = "KBRELKBD";
	else if (val == GPIOGET)
		str = "GPIOGET";
	else if (val == CDRIOCFLUSH)
		str = "CDRIOCFLUSH";
	else if (val == SW_ENH_B80x43)
		str = "SW_ENH_B80x43";
	else if (val == SMB_RECVB)
		str = "SMB_RECVB";
	else if (val == TIIOCGETTRACE)
		str = "TIIOCGETTRACE";
	else if (val == METEORSFPS)
		str = "METEORSFPS";
	else if (val == FIONSPACE)
		str = "FIONSPACE";
	else if (val == SNDCTL_DSP_GET_CHNORDER)
		str = "SNDCTL_DSP_GET_CHNORDER";
	else if (val == CONS_FINDMODE)
		str = "CONS_FINDMODE";
	else if (val == AUDITPIPE_SET_PRESELECT_NAFLAGS)
		str = "AUDITPIPE_SET_PRESELECT_NAFLAGS";
	else if (val == TIOCCDTR)
		str = "TIOCCDTR";
	else if (val == GIO_KEYMAP)
		str = "GIO_KEYMAP";
	else if (val == BT848_SCBARS)
		str = "BT848_SCBARS";
	else if (val == IPMICTL_RECEIVE_MSG_TRUNC)
		str = "IPMICTL_RECEIVE_MSG_TRUNC";
	else if (val == BIOCFLUSH)
		str = "BIOCFLUSH";
	else if (val == TVTUNER_SETCHNL)
		str = "TVTUNER_SETCHNL";
	else if (val == AUDITPIPE_GET_QLIMIT)
		str = "AUDITPIPE_GET_QLIMIT";
	else if (val == ALT_ATTACH)
		str = "ALT_ATTACH";
	else if (val == BT848_GCONT)
		str = "BT848_GCONT";
	else if (val == VT_GETMODE)
		str = "VT_GETMODE";
	else if (val == TUNGIFHEAD)
		str = "TUNGIFHEAD";
	else if (val == SIOCSNDFLUSH_IN6)
		str = "SIOCSNDFLUSH_IN6";
	else if (val == UFTDIIOC_ERASE_EEPROM)
		str = "UFTDIIOC_ERASE_EEPROM";
	else if (val == CFIOCGOEMPR)
		str = "CFIOCGOEMPR";
	else if (val == SNDCTL_COPR_RDATA)
		str = "SNDCTL_COPR_RDATA";
	else if (val == SIOCGLAGG)
		str = "SIOCGLAGG";
	else if (val == AUDITPIPE_SET_PRESELECT_MODE)
		str = "AUDITPIPE_SET_PRESELECT_MODE";
	else if (val == ACPIIO_BATT_GET_UNITS)
		str = "ACPIIO_BATT_GET_UNITS";
	else if (val == CDIOCSETSTEREO)
		str = "CDIOCSETSTEREO";
	else if (val == AD_SUPPORTED_GAINS)
		str = "AD_SUPPORTED_GAINS";
	else if (val == SG_SET_KEEP_ORPHAN)
		str = "SG_SET_KEEP_ORPHAN";
	else if (val == MTIOCRDHPOS)
		str = "MTIOCRDHPOS";
	else if (val == TIOCNXCL)
		str = "TIOCNXCL";
	else if (val == CDIOCSETSTERIO)
		str = "CDIOCSETSTERIO";
	else if (val == SNDCTL_DSP_SKIP)
		str = "SNDCTL_DSP_SKIP";
	else if (val == USB_GET_RX_INTERFACE_DESC)
		str = "USB_GET_RX_INTERFACE_DESC";
	else if (val == SW_VGA_C80x25)
		str = "SW_VGA_C80x25";
	else if (val == AIOSFMT)
		str = "AIOSFMT";
	else if (val == MOUSE_SETVARS)
		str = "MOUSE_SETVARS";
	else if (val == MEMRANGE_SET)
		str = "MEMRANGE_SET";
	else if (val == SNDCTL_TMR_METRONOME)
		str = "SNDCTL_TMR_METRONOME";
	else if (val == USB_GET_RX_ENDPOINT_DESC)
		str = "USB_GET_RX_ENDPOINT_DESC";
	else if (val == UFTDIIOC_RESET_IO)
		str = "UFTDIIOC_RESET_IO";
	else if (val == BT848_MSP_WRITE)
		str = "BT848_MSP_WRITE";
	else if (val == SIOCGIFAFLAG_IN6)
		str = "SIOCGIFAFLAG_IN6";
	else if (val == GIO_FONT8x8)
		str = "GIO_FONT8x8";
	else if (val == TIOCMSET)
		str = "TIOCMSET";
	else if (val == SIOCAIFGROUP)
		str = "SIOCAIFGROUP";
	else if (val == FSACTL_SENDFIB)
		str = "FSACTL_SENDFIB";
	else if (val == USB_GET_DEV_PORT_PATH)
		str = "USB_GET_DEV_PORT_PATH";
	else if (val == CAMIOGET)
		str = "CAMIOGET";
	else if (val == NVME_PASSTHROUGH_CMD)
		str = "NVME_PASSTHROUGH_CMD";
	else if (val == BT848_GCAPAREA)
		str = "BT848_GCAPAREA";
	else if (val == UFTDIIOC_RESET_RX)
		str = "UFTDIIOC_RESET_RX";
	else if (val == SIOCSIFMETRIC)
		str = "SIOCSIFMETRIC";
	else if (val == NANDFS_IOCTL_GET_SUSTAT)
		str = "NANDFS_IOCTL_GET_SUSTAT";
	else if (val == UFTDIIOC_RESET_TX)
		str = "UFTDIIOC_RESET_TX";
	else if (val == TIOCDRAIN)
		str = "TIOCDRAIN";
	else if (val == SIOCPROXY)
		str = "SIOCPROXY";
	else if (val == SIOCSLAGGPORT)
		str = "SIOCSLAGGPORT";
	else if (val == CDIOCRESUME)
		str = "CDIOCRESUME";
	else if (val == BT848_SCSAT)
		str = "BT848_SCSAT";
	else if (val == BIOCIMMEDIATE)
		str = "BIOCIMMEDIATE";
	else if (val == SG_GET_TRANSFORM)
		str = "SG_GET_TRANSFORM";
	else if (val == PBIO_SETOPACE)
		str = "PBIO_SETOPACE";
	else if (val == SIOCGTQTAB)
		str = "SIOCGTQTAB";
	else if (val == CRIOGET)
		str = "CRIOGET";
	else if (val == SW_VESA_FULL_1280)
		str = "SW_VESA_FULL_1280";
	else if (val == VMIO_SIOCSLADRF)
		str = "VMIO_SIOCSLADRF";
	else if (val == CDNR_ADD_TBM)
		str = "CDNR_ADD_TBM";
	else if (val == CDNR_ADD_TCM)
		str = "CDNR_ADD_TCM";
	else if (val == CAMIOCOMMAND)
		str = "CAMIOCOMMAND";
	else if (val == CFIOCGFACTORYPR)
		str = "CFIOCGFACTORYPR";
	else if (val == SG_SCSI_RESET)
		str = "SG_SCSI_RESET";
	else if (val == FBIOGATTR)
		str = "FBIOGATTR";
	else if (val == FSACTL_ZERO_FIBTIMES)
		str = "FSACTL_ZERO_FIBTIMES";
	else if (val == VMIO_SIOCPORT)
		str = "VMIO_SIOCPORT";
	else if (val == SIOCGDRVSPEC)
		str = "SIOCGDRVSPEC";
	else if (val == SIOCGIFDSTADDR_IN6)
		str = "SIOCGIFDSTADDR_IN6";
	else if (val == KDGETREPEAT)
		str = "KDGETREPEAT";
	else if (val == SIOCSETFF)
		str = "SIOCSETFF";
	else if (val == SIOCGIFPHYS)
		str = "SIOCGIFPHYS";
	else if (val == SMB_BREAD)
		str = "SMB_BREAD";
	else if (val == GIO_COLOR)
		str = "GIO_COLOR";
	else if (val == TIOCGETA)
		str = "TIOCGETA";
	else if (val == TIOCGETC)
		str = "TIOCGETC";
	else if (val == TIOCGETP)
		str = "TIOCGETP";
	else if (val == SW_ENH_B40x25)
		str = "SW_ENH_B40x25";
	else if (val == SIOCSIFINFO_IN6)
		str = "SIOCSIFINFO_IN6";
	else if (val == NVME_IO_TEST)
		str = "NVME_IO_TEST";
	else if (val == METEORGHUE)
		str = "METEORGHUE";
	else if (val == SNDCTL_SEQ_PERCMODE)
		str = "SNDCTL_SEQ_PERCMODE";
	else if (val == FBIO_SETLINEWIDTH)
		str = "FBIO_SETLINEWIDTH";
	else if (val == MDIOCRESIZE)
		str = "MDIOCRESIZE";
	else if (val == CDNR_ADD_TSW)
		str = "CDNR_ADD_TSW";
	else if (val == SNDCTL_DSP_SETTRIGGER)
		str = "SNDCTL_DSP_SETTRIGGER";
	else if (val == TVTUNER_SETAFC)
		str = "TVTUNER_SETAFC";
	else if (val == USB_GET_REPORT_DESC)
		str = "USB_GET_REPORT_DESC";
	else if (val == BIOCSETWF)
		str = "BIOCSETWF";
	else if (val == KDSKBSTATE)
		str = "KDSKBSTATE";
	else if (val == SIOCADDMULTI)
		str = "SIOCADDMULTI";
	else if (val == CDNR_GETSTATS)
		str = "CDNR_GETSTATS";
	else if (val == CONS_CURRENTADP)
		str = "CONS_CURRENTADP";
	else if (val == SW_B80x25)
		str = "SW_B80x25";
	else if (val == SIOCSIFMAC)
		str = "SIOCSIFMAC";
	else if (val == SNPSTTY)
		str = "SNPSTTY";
	else if (val == SOUND_PCM_READ_CHANNELS)
		str = "SOUND_PCM_READ_CHANNELS";
	else if (val == ULED_GET_COLOR)
		str = "ULED_GET_COLOR";
	else if (val == ENCIOC_GETELMDESC)
		str = "ENCIOC_GETELMDESC";
	else if (val == AUDITPIPE_GET_PRESELECT_MODE)
		str = "AUDITPIPE_GET_PRESELECT_MODE";
	else if (val == SIOCGIFDSTADDR)
		str = "SIOCGIFDSTADDR";
	else if (val == FBIOGCURPOS)
		str = "FBIOGCURPOS";
	else if (val == TIOCSTAT)
		str = "TIOCSTAT";
	else if (val == AGPIOC_ACQUIRE)
		str = "AGPIOC_ACQUIRE";
	else if (val == USB_DEVICEINFO)
		str = "USB_DEVICEINFO";
	else if (val == SW_PC98_EGC640x400)
		str = "SW_PC98_EGC640x400";
	else if (val == PPIGDATA)
		str = "PPIGDATA";
	else if (val == FW_SBINDADDR)
		str = "FW_SBINDADDR";
	else if (val == TUNSIFHEAD)
		str = "TUNSIFHEAD";
	else if (val == IOCATAATTACH)
		str = "IOCATAATTACH";
	else if (val == BT848GFMT)
		str = "BT848GFMT";
	else if (val == FBIOGETCMAP)
		str = "FBIOGETCMAP";
	else if (val == METEORGCSAT)
		str = "METEORGCSAT";
	else if (val == METEORSVWS)
		str = "METEORSVWS";
	else if (val == FWOHCI_WRREG)
		str = "FWOHCI_WRREG";
	else if (val == FBIOGVIDEO)
		str = "FBIOGVIDEO";
	else if (val == I2CWRITE)
		str = "I2CWRITE";
	else if (val == SIOCSIFMTU)
		str = "SIOCSIFMTU";
	else if (val == SIOCIPFGETNEXT)
		str = "SIOCIPFGETNEXT";
	else if (val == BIOCGETZMAX)
		str = "BIOCGETZMAX";
	else if (val == CDNR_DISABLE)
		str = "CDNR_DISABLE";
	else if (val == PPIGSTATUS)
		str = "PPIGSTATUS";
	else if (val == DEV_DETACH)
		str = "DEV_DETACH";
	else if (val == TIOCGWINSZ)
		str = "TIOCGWINSZ";
	else if (val == CDIOCCAPABILITY)
		str = "CDIOCCAPABILITY";
	else if (val == SG_NEXT_CMD_LEN)
		str = "SG_NEXT_CMD_LEN";
	else if (val == KDGKBMODE)
		str = "KDGKBMODE";
	else if (val == SNDCTL_DSP_SET_RECSRC)
		str = "SNDCTL_DSP_SET_RECSRC";
	else if (val == USB_DISCOVER)
		str = "USB_DISCOVER";
	else if (val == USB_IFACE_DRIVER_ACTIVE)
		str = "USB_IFACE_DRIVER_ACTIVE";
	else if (val == FIONCLEX)
		str = "FIONCLEX";
	else if (val == CUSE_IOCTL_DESTROY_DEV)
		str = "CUSE_IOCTL_DESTROY_DEV";
	else if (val == SNDCTL_DSP_GETODELAY)
		str = "SNDCTL_DSP_GETODELAY";
	else if (val == TUNSIFMODE)
		str = "TUNSIFMODE";
	else if (val == CDIOCCLOSE)
		str = "CDIOCCLOSE";
	else if (val == SW_ENH_CG640)
		str = "SW_ENH_CG640";
	else if (val == DEVFSIO_RADD)
		str = "DEVFSIO_RADD";
	else if (val == SNDCTL_DSP_HALT)
		str = "SNDCTL_DSP_HALT";
	else if (val == GPIOMAXPIN)
		str = "GPIOMAXPIN";
	else if (val == CDIOCSETMUTE)
		str = "CDIOCSETMUTE";
	else if (val == CIOCGSESSION2)
		str = "CIOCGSESSION2";
	else if (val == SNDCTL_DSP_SETPLAYVOL)
		str = "SNDCTL_DSP_SETPLAYVOL";
	else if (val == FSACTL_MINIPORT_REV_CHECK)
		str = "FSACTL_MINIPORT_REV_CHECK";
	else if (val == SNDCTL_DSP_HALT_INPUT)
		str = "SNDCTL_DSP_HALT_INPUT";
	else if (val == GIO_VFONT)
		str = "GIO_VFONT";
	else if (val == OFIOCGETPROPLEN)
		str = "OFIOCGETPROPLEN";
	else if (val == SIOCGIFXMEDIA)
		str = "SIOCGIFXMEDIA";
	else if (val == FW_CBINDADDR)
		str = "FW_CBINDADDR";
	else if (val == AUDITPIPE_SET_QLIMIT)
		str = "AUDITPIPE_SET_QLIMIT";
	else if (val == SIOCGIFGMEMB)
		str = "SIOCGIFGMEMB";
	else if (val == CONS_GETVERS)
		str = "CONS_GETVERS";
	else if (val == SIOCLOOKUPSTATW)
		str = "SIOCLOOKUPSTATW";
	else if (val == SIOCIPFSET)
		str = "SIOCIPFSET";
	else if (val == SNDCTL_DSP_GETOPEAKS)
		str = "SNDCTL_DSP_GETOPEAKS";
	else if (val == VT_LOCKSWITCH)
		str = "VT_LOCKSWITCH";
	else if (val == USB_GET_POWER_USAGE)
		str = "USB_GET_POWER_USAGE";
	else if (val == FW_SSTBUF)
		str = "FW_SSTBUF";
	else if (val == SW_VESA_32K_640)
		str = "SW_VESA_32K_640";
	else if (val == USB_GET_RX_FRAME_SIZE)
		str = "USB_GET_RX_FRAME_SIZE";
	else if (val == TIOCLGET)
		str = "TIOCLGET";
	else if (val == SIOCRMSCA)
		str = "SIOCRMSCA";
	else if (val == CDIOCREADSUBCHANNEL_SYSSPACE)
		str = "CDIOCREADSUBCHANNEL_SYSSPACE";
	else if (val == TIOCSETA)
		str = "TIOCSETA";
	else if (val == TIOCSETN)
		str = "TIOCSETN";
	else if (val == TIOCSETP)
		str = "TIOCSETP";
	else if (val == OPROMNXTPROP)
		str = "OPROMNXTPROP";
	else if (val == PBIO_SETDIFF)
		str = "PBIO_SETDIFF";
	else if (val == NVME_BIO_TEST)
		str = "NVME_BIO_TEST";
	else if (val == PPS_IOC_FETCH_FFCOUNTER)
		str = "PPS_IOC_FETCH_FFCOUNTER";
	else if (val == METEORSHUE)
		str = "METEORSHUE";
	else if (val == SNDCTL_PMGR_IFACE)
		str = "SNDCTL_PMGR_IFACE";
	else if (val == BT848_GLNOTCH)
		str = "BT848_GLNOTCH";
	else if (val == BT848_I2CWR)
		str = "BT848_I2CWR";
	else if (val == METEORSHWS)
		str = "METEORSHWS";
	else if (val == G_GATE_CMD_DONE)
		str = "G_GATE_CMD_DONE";
	else if (val == BT848_GAUDIO)
		str = "BT848_GAUDIO";
	else if (val == MIOSPASSTHRU)
		str = "MIOSPASSTHRU";
	else if (val == UFTDIIOC_SET_ERROR_CHAR)
		str = "UFTDIIOC_SET_ERROR_CHAR";
	else if (val == MTIOCERRSTAT)
		str = "MTIOCERRSTAT";
	else if (val == GPIOTOGGLE)
		str = "GPIOTOGGLE";
	else if (val == SW_VESA_64K_640)
		str = "SW_VESA_64K_640";
	else if (val == SNDCTL_DSP_SETRECVOL)
		str = "SNDCTL_DSP_SETRECVOL";
	else if (val == SNDCTL_SEQ_RESET)
		str = "SNDCTL_SEQ_RESET";
	else if (val == CONS_MODEINFO)
		str = "CONS_MODEINFO";
	else if (val == VMIO_SIOCSIFFLAGS)
		str = "VMIO_SIOCSIFFLAGS";
	else if (val == METEORGFPS)
		str = "METEORGFPS";
	else if (val == SMBIOC_SETFLAGS)
		str = "SMBIOC_SETFLAGS";
	else if (val == SW_B40x25)
		str = "SW_B40x25";
	else if (val == FSACTL_CLOSE_ADAPTER_CONFIG)
		str = "FSACTL_CLOSE_ADAPTER_CONFIG";
	else if (val == FILEMON_SET_PID)
		str = "FILEMON_SET_PID";
	else if (val == SG_SET_TRANSFORM)
		str = "SG_SET_TRANSFORM";
	else if (val == SIOCINAFR)
		str = "SIOCINAFR";
	else if (val == FW_GDEUI64)
		str = "FW_GDEUI64";
	else if (val == SNDCTL_DSP_GETIPTR)
		str = "SNDCTL_DSP_GETIPTR";
	else if (val == FM_SET_FREQ)
		str = "FM_SET_FREQ";
	else if (val == PPS_IOC_GETPARAMS)
		str = "PPS_IOC_GETPARAMS";
	else if (val == CDRIOCINITWRITER)
		str = "CDRIOCINITWRITER";
	else if (val == PBIO_SETIPACE)
		str = "PBIO_SETIPACE";
	else if (val == VT_WAITACTIVE)
		str = "VT_WAITACTIVE";
	else if (val == WDIOC_GETPRETIMEOUT)
		str = "WDIOC_GETPRETIMEOUT";
	else if (val == CUSE_IOCTL_GET_COMMAND)
		str = "CUSE_IOCTL_GET_COMMAND";
	else if (val == SNDCTL_DSP_LOW_WATER)
		str = "SNDCTL_DSP_LOW_WATER";
	else if (val == CDIOCSETPATCH)
		str = "CDIOCSETPATCH";
	else if (val == PIO_FONT8x14)
		str = "PIO_FONT8x14";
	else if (val == PIO_FONT8x16)
		str = "PIO_FONT8x16";
	else if (val == DIGIIO_SETALTPIN)
		str = "DIGIIO_SETALTPIN";
	else if (val == CIOCKEY2)
		str = "CIOCKEY2";
	else if (val == AD_NCHANS_GET)
		str = "AD_NCHANS_GET";
	else if (val == BT848SFMT)
		str = "BT848SFMT";
	else if (val == SW_TEXT_132x25)
		str = "SW_TEXT_132x25";
	else if (val == TIIOCGETPARAMS)
		str = "TIIOCGETPARAMS";
	else if (val == SW_BG640)
		str = "SW_BG640";
	else if (val == SW_TEXT_132x30)
		str = "SW_TEXT_132x30";
	else if (val == SW_TEXT_132x43)
		str = "SW_TEXT_132x43";
	else if (val == MIOGPASSTHRU)
		str = "MIOGPASSTHRU";
	else if (val == SW_TEXT_132x50)
		str = "SW_TEXT_132x50";
	else if (val == SW_TEXT_132x60)
		str = "SW_TEXT_132x60";
	else if (val == USB_RELEASE_INTERFACE)
		str = "USB_RELEASE_INTERFACE";
	else if (val == GREGKEY)
		str = "GREGKEY";
	else if (val == SIOCGNBRINFO_IN6)
		str = "SIOCGNBRINFO_IN6";
	else if (val == FIOASYNC)
		str = "FIOASYNC";
	else if (val == PPS_IOC_KCBIND)
		str = "PPS_IOC_KCBIND";
	else if (val == SIOCSIFPHYADDR_IN6)
		str = "SIOCSIFPHYADDR_IN6";
	else if (val == CUSE_IOCTL_ALLOC_UNIT_BY_ID)
		str = "CUSE_IOCTL_ALLOC_UNIT_BY_ID";
	else if (val == USB_SET_TX_TIMEOUT)
		str = "USB_SET_TX_TIMEOUT";
	else if (val == IOCATARAIDADDSPARE)
		str = "IOCATARAIDADDSPARE";
	else if (val == FSACTL_NULL_IO_TEST)
		str = "FSACTL_NULL_IO_TEST";
	else if (val == FD_GTYPE)
		str = "FD_GTYPE";
	else if (val == MTIOCEEOT)
		str = "MTIOCEEOT";
	else if (val == IPMICTL_GET_MY_ADDRESS_CMD)
		str = "IPMICTL_GET_MY_ADDRESS_CMD";
	else if (val == CHIOGPICKER)
		str = "CHIOGPICKER";
	else if (val == I2CRSTCARD)
		str = "I2CRSTCARD";
	else if (val == SPKRTONE)
		str = "SPKRTONE";
	else if (val == GPIOSETNAME)
		str = "GPIOSETNAME";
	else if (val == FD_FORM)
		str = "FD_FORM";
	else if (val == GIO_FONT8x14)
		str = "GIO_FONT8x14";
	else if (val == GIO_FONT8x16)
		str = "GIO_FONT8x16";
	else if (val == BT848_MSP_READ)
		str = "BT848_MSP_READ";
	else if (val == TVTUNER_SETTYPE)
		str = "TVTUNER_SETTYPE";
	else if (val == SIOCGETFF)
		str = "SIOCGETFF";
	else if (val == SIOCGETFS)
		str = "SIOCGETFS";
	else if (val == ACPIIO_BATT_GET_BIF)
		str = "ACPIIO_BATT_GET_BIF";
	else if (val == SIOCDIFADDR_IN6)
		str = "SIOCDIFADDR_IN6";
	else if (val == TUNSLMODE)
		str = "TUNSLMODE";
	else if (val == CDIOCEJECT)
		str = "CDIOCEJECT";
	else if (val == ALT_READ_TG_REG)
		str = "ALT_READ_TG_REG";
	else if (val == SW_VGA_C80x30)
		str = "SW_VGA_C80x30";
	else if (val == NANDFS_IOCTL_SYNC)
		str = "NANDFS_IOCTL_SYNC";
	else if (val == SIOCGETLG)
		str = "SIOCGETLG";
	else if (val == MOUSE_GETMODE)
		str = "MOUSE_GETMODE";
	else if (val == SW_VGA_C80x50)
		str = "SW_VGA_C80x50";
	else if (val == WDIOC_SETPRETIMEOUT)
		str = "WDIOC_SETPRETIMEOUT";
	else if (val == SW_VGA_C80x60)
		str = "SW_VGA_C80x60";
	else if (val == SIOCSVH)
		str = "SIOCSVH";
	else if (val == MTIOCPARAMSET)
		str = "MTIOCPARAMSET";
	else if (val == I2CRDWR)
		str = "I2CRDWR";
	else if (val == SW_MCAMODE)
		str = "SW_MCAMODE";
	else if (val == MTIOCGETEOTMODEL)
		str = "MTIOCGETEOTMODEL";
	else if (val == USB_DEV_QUIRK_GET)
		str = "USB_DEV_QUIRK_GET";
	else if (val == ACPIIO_BATT_GET_BST)
		str = "ACPIIO_BATT_GET_BST";
	else if (val == KDSETRAD)
		str = "KDSETRAD";
	else if (val == SIOCSIFNAME)
		str = "SIOCSIFNAME";
	else if (val == SNDCTL_SEQ_NRMIDIS)
		str = "SNDCTL_SEQ_NRMIDIS";
	else if (val == SIOCGNATL)
		str = "SIOCGNATL";
	else if (val == SIOCGNATS)
		str = "SIOCGNATS";
	else if (val == METEORSVIDEO)
		str = "METEORSVIDEO";
	else if (val == SG_SET_DEBUG)
		str = "SG_SET_DEBUG";
	else if (val == BIOCROTZBUF)
		str = "BIOCROTZBUF";
	else if (val == MEMRANGE_GET)
		str = "MEMRANGE_GET";
	else if (val == FBIO_ADPINFO)
		str = "FBIO_ADPINFO";
	else if (val == AIOGSIZE)
		str = "AIOGSIZE";
	else if (val == SMB_SENDB)
		str = "SMB_SENDB";
	else if (val == AD_NGAINS_GET)
		str = "AD_NGAINS_GET";
	else if (val == FIODTYPE)
		str = "FIODTYPE";
	else if (val == SIOCGETSGCNT_IN6)
		str = "SIOCGETSGCNT_IN6";
	else if (val == BT848_SHUE)
		str = "BT848_SHUE";
	else if (val == SNDCTL_DSP_SYNCGROUP)
		str = "SNDCTL_DSP_SYNCGROUP";
	else if (val == PCIOCGETBAR)
		str = "PCIOCGETBAR";
	else if (val == IOCATARAIDCREATE)
		str = "IOCATARAIDCREATE";
	else if (val == ULED_SET_COLOR)
		str = "ULED_SET_COLOR";
	else if (val == SNDCTL_CARDINFO)
		str = "SNDCTL_CARDINFO";
	else if (val == CPUCTL_WRMSR)
		str = "CPUCTL_WRMSR";
	else if (val == TUNGIFINFO)
		str = "TUNGIFINFO";
	else if (val == SG_SET_FORCE_LOW_DMA)
		str = "SG_SET_FORCE_LOW_DMA";
	else if (val == KIOCGSIZE)
		str = "KIOCGSIZE";
	else if (val == BIOCSETBUFMODE)
		str = "BIOCSETBUFMODE";
	else if (val == TIOCSDRAINWAIT)
		str = "TIOCSDRAINWAIT";
	else if (val == SIOCAIFADDR)
		str = "SIOCAIFADDR";
	else if (val == SW_VESA_CG800x600)
		str = "SW_VESA_CG800x600";
	else if (val == CCISS_GETBUSTYPES)
		str = "CCISS_GETBUSTYPES";
	else if (val == USB_SET_PORT_ENABLE)
		str = "USB_SET_PORT_ENABLE";
	else if (val == SIOCSIFFLAGS)
		str = "SIOCSIFFLAGS";
	else if (val == MTIOCIEOT)
		str = "MTIOCIEOT";
	else if (val == SIOCGLOWAT)
		str = "SIOCGLOWAT";
	else if (val == SIOCATMCLOSEVCC)
		str = "SIOCATMCLOSEVCC";
	else if (val == SIOCGIFMEDIA)
		str = "SIOCGIFMEDIA";
	else if (val == ACPIIO_REQSLPSTATE)
		str = "ACPIIO_REQSLPSTATE";
	else if (val == BT848_SCAPAREA)
		str = "BT848_SCAPAREA";
	else if (val == SNDCTL_TMR_STOP)
		str = "SNDCTL_TMR_STOP";
	else if (val == SNDCTL_SEQ_CTRLRATE)
		str = "SNDCTL_SEQ_CTRLRATE";
	else if (val == AUDITPIPE_GET_QLIMIT_MAX)
		str = "AUDITPIPE_GET_QLIMIT_MAX";
	else if (val == SNDCTL_SEQ_OUTOFBAND)
		str = "SNDCTL_SEQ_OUTOFBAND";
	else if (val == CUSE_IOCTL_CREATE_DEV)
		str = "CUSE_IOCTL_CREATE_DEV";
	else if (val == AACIO_STATS)
		str = "AACIO_STATS";
	else if (val == CCISS_SETNODENAME)
		str = "CCISS_SETNODENAME";
	else if (val == JOY_GETTIMEOUT)
		str = "JOY_GETTIMEOUT";
	else if (val == METEORSCHCV)
		str = "METEORSCHCV";
	else if (val == NANDFS_IOCTL_MAKE_SNAP)
		str = "NANDFS_IOCTL_MAKE_SNAP";
	else if (val == SNDCTL_COPR_WCODE)
		str = "SNDCTL_COPR_WCODE";
	else if (val == SW_VESA_CG1024x768)
		str = "SW_VESA_CG1024x768";
	else if (val == SW_EGAMONOAPA)
		str = "SW_EGAMONOAPA";
	else if (val == SNDCTL_SEQ_GETTIME)
		str = "SNDCTL_SEQ_GETTIME";
	else if (val == CDNR_MOD_TCM)
		str = "CDNR_MOD_TCM";
	else if (val == CPUCTL_CPUID_COUNT)
		str = "CPUCTL_CPUID_COUNT";
	else if (val == OTIOCGETD)
		str = "OTIOCGETD";
	else if (val == USB_GET_DEVICE_DESC)
		str = "USB_GET_DEVICE_DESC";
	else if (val == MFIIO_QUERY_DISK)
		str = "MFIIO_QUERY_DISK";
	else if (val == CHIOSETVOLTAG)
		str = "CHIOSETVOLTAG";
	else if (val == METEORGACTPIXFMT)
		str = "METEORGACTPIXFMT";
	else if (val == G_GATE_CMD_CREATE)
		str = "G_GATE_CMD_CREATE";
	else if (val == USB_DO_REQUEST)
		str = "USB_DO_REQUEST";
	else if (val == BT848_SVSAT)
		str = "BT848_SVSAT";
	else if (val == SIOCGIFPDSTADDR)
		str = "SIOCGIFPDSTADDR";
	else if (val == SMBIOC_OPENSHARE)
		str = "SMBIOC_OPENSHARE";
	else if (val == ALT_WRITE_TG_REG)
		str = "ALT_WRITE_TG_REG";
	else if (val == FIOSEEKDATA)
		str = "FIOSEEKDATA";
	else if (val == PIOCGFL)
		str = "PIOCGFL";
	else if (val == USB_SET_RX_BUFFER_SIZE)
		str = "USB_SET_RX_BUFFER_SIZE";
	else if (val == SIOCIFCREATE2)
		str = "SIOCIFCREATE2";
	else if (val == GRESKEY)
		str = "GRESKEY";
	else if (val == GETFKEY)
		str = "GETFKEY";
	else if (val == SW_VGA_MODEX)
		str = "SW_VGA_MODEX";
	else if (val == CAMIOQUEUE)
		str = "CAMIOQUEUE";
	else if (val == NANDFS_IOCTL_GET_CPSTAT)
		str = "NANDFS_IOCTL_GET_CPSTAT";
	else if (val == GPIOSETCONFIG)
		str = "GPIOSETCONFIG";
	else if (val == CDIOREADTOCHEADER)
		str = "CDIOREADTOCHEADER";
	else if (val == I2CREAD)
		str = "I2CREAD";
	else if (val == MDIOCDETACH)
		str = "MDIOCDETACH";
	else if (val == NIOCCONFIG)
		str = "NIOCCONFIG";
	else if (val == ENCIOC_SETENCSTAT)
		str = "ENCIOC_SETENCSTAT";
	else if (val == AUDITPIPE_GET_QLEN)
		str = "AUDITPIPE_GET_QLEN";
	else if (val == TIOCGETD)
		str = "TIOCGETD";
	else if (val == UFTDIIOC_GET_LATENCY)
		str = "UFTDIIOC_GET_LATENCY";
	else if (val == FBIO_SETDISPSTART)
		str = "FBIO_SETDISPSTART";
	else if (val == PPS_IOC_GETCAP)
		str = "PPS_IOC_GETCAP";
	else if (val == PPS_IOC_FETCH)
		str = "PPS_IOC_FETCH";
	else if (val == IPMICTL_SET_GETS_EVENTS_CMD)
		str = "IPMICTL_SET_GETS_EVENTS_CMD";
	else if (val == USB_GET_IFACE_DRIVER)
		str = "USB_GET_IFACE_DRIVER";
	else if (val == KDMKTONE)
		str = "KDMKTONE";
	else if (val == FSACTL_GET_NEXT_ADAPTER_FIB)
		str = "FSACTL_GET_NEXT_ADAPTER_FIB";
	else if (val == SIOCSTLCK)
		str = "SIOCSTLCK";
	else if (val == USB_FS_START)
		str = "USB_FS_START";
	else if (val == SNDCTL_AUDIOINFO)
		str = "SNDCTL_AUDIOINFO";
	else if (val == SNDCTL_DSP_SPEED)
		str = "SNDCTL_DSP_SPEED";
	else if (val == FD_CLRERR)
		str = "FD_CLRERR";
	else if (val == CONS_SETWINORG)
		str = "CONS_SETWINORG";
	else if (val == SW_ENH_C80x25)
		str = "SW_ENH_C80x25";
	else if (val == BT848SCLIP)
		str = "BT848SCLIP";
	else if (val == SW_ENH_C80x43)
		str = "SW_ENH_C80x43";
	else if (val == SW_VGA_C40x25)
		str = "SW_VGA_C40x25";
	else if (val == USB_CLAIM_INTERFACE)
		str = "USB_CLAIM_INTERFACE";
	else if (val == METEORSCOUNT)
		str = "METEORSCOUNT";
	else if (val == SW_VESA_32K_320)
		str = "SW_VESA_32K_320";
	else if (val == CDNR_ADD_ELEM)
		str = "CDNR_ADD_ELEM";
	else if (val == SNDCTL_DSP_SUBDIVIDE)
		str = "SNDCTL_DSP_SUBDIVIDE";
	else if (val == MTIOCPARAMGET)
		str = "MTIOCPARAMGET";
	else if (val == SG_GET_ACCESS_COUNT)
		str = "SG_GET_ACCESS_COUNT";
	else if (val == AUDITPIPE_GET_PRESELECT_AUID)
		str = "AUDITPIPE_GET_PRESELECT_AUID";
	else if (val == USB_SET_TX_FORCE_SHORT)
		str = "USB_SET_TX_FORCE_SHORT";
	else if (val == BT848_SAUDIO)
		str = "BT848_SAUDIO";
	else if (val == CCISS_GETDRIVERVER)
		str = "CCISS_GETDRIVERVER";
	else if (val == BIOCSRSIG)
		str = "BIOCSRSIG";
	else if (val == SNDCTL_SEQ_PANIC)
		str = "SNDCTL_SEQ_PANIC";
	else if (val == SIOCIFGCLONERS)
		str = "SIOCIFGCLONERS";
	else if (val == PCIOCWRITE)
		str = "PCIOCWRITE";
	else if (val == SNDCTL_COPR_RESET)
		str = "SNDCTL_COPR_RESET";
	else if (val == BIOCGETIF)
		str = "BIOCGETIF";
	else if (val == SNDCTL_MIX_NRMIX)
		str = "SNDCTL_MIX_NRMIX";
	else if (val == AD_MICRO_PERIOD_SET)
		str = "AD_MICRO_PERIOD_SET";
	else if (val == FBIO_GETDISPSTART)
		str = "FBIO_GETDISPSTART";
	else if (val == IODEV_PIO)
		str = "IODEV_PIO";
	else if (val == CDIOCSETRIGHT)
		str = "CDIOCSETRIGHT";
	else if (val == DIGIIO_DEBUG)
		str = "DIGIIO_DEBUG";
	else if (val == SNDCTL_COPR_HALT)
		str = "SNDCTL_COPR_HALT";
	else if (val == CDIOCPLAYMSF)
		str = "CDIOCPLAYMSF";
	else if (val == SIOCSWAPA)
		str = "SIOCSWAPA";
	else if (val == NANDFS_IOCTL_CHANGE_CPMODE)
		str = "NANDFS_IOCTL_CHANGE_CPMODE";
	else if (val == SIOCGSCST)
		str = "SIOCGSCST";
	else if (val == AUDITPIPE_GET_PRESELECT_FLAGS)
		str = "AUDITPIPE_GET_PRESELECT_FLAGS";
	else if (val == CIOCFINDDEV)
		str = "CIOCFINDDEV";
	else if (val == KDSETREPEAT)
		str = "KDSETREPEAT";
	else if (val == SIOCGLAGGOPTS)
		str = "SIOCGLAGGOPTS";
	else if (val == SIOCGIFFLAGS)
		str = "SIOCGIFFLAGS";
	else if (val == SIOCGSCOPE6DEF)
		str = "SIOCGSCOPE6DEF";
	else if (val == SNDCTL_DSP_BIND_CHANNEL)
		str = "SNDCTL_DSP_BIND_CHANNEL";
	else if (val == SNDCTL_DSP_SYNCSTART)
		str = "SNDCTL_DSP_SYNCSTART";
	else if (val == SIOCGSCOPE6)
		str = "SIOCGSCOPE6";
	else if (val == SIOCADNAT)
		str = "SIOCADNAT";
	else if (val == FBIOGCURSOR)
		str = "FBIOGCURSOR";
	else if (val == TIOCUCNTL)
		str = "TIOCUCNTL";
	else if (val == AUDITPIPE_FLUSH_PRESELECT_AUID)
		str = "AUDITPIPE_FLUSH_PRESELECT_AUID";
	else if (val == FD_GSTAT)
		str = "FD_GSTAT";
	else if (val == TAPGDEBUG)
		str = "TAPGDEBUG";
	else if (val == METEORSSIGNAL)
		str = "METEORSSIGNAL";
	else if (val == MOUSE_READSTATE)
		str = "MOUSE_READSTATE";
	else if (val == RADIO_SETMODE)
		str = "RADIO_SETMODE";
	else if (val == CDIOCPAUSE)
		str = "CDIOCPAUSE";
	else if (val == CFIOCSOEMPR)
		str = "CFIOCSOEMPR";
	else if (val == SIOCIPFGET)
		str = "SIOCIPFGET";
	else if (val == AUDITPIPE_DELETE_PRESELECT_AUID)
		str = "AUDITPIPE_DELETE_PRESELECT_AUID";
	else if (val == FIODGNAME)
		str = "FIODGNAME";
	else if (val == FW_GRSTREAM)
		str = "FW_GRSTREAM";
	else if (val == USB_FS_INIT)
		str = "USB_FS_INIT";
	else if (val == UFTDIIOC_GET_HWREV)
		str = "UFTDIIOC_GET_HWREV";
	else if (val == SNDCTL_MIDIINFO)
		str = "SNDCTL_MIDIINFO";
	else if (val == OTIOCSETD)
		str = "OTIOCSETD";
	else if (val == TIIOCSETPARAMS)
		str = "TIIOCSETPARAMS";
	else if (val == SNDCTL_MIX_READ)
		str = "SNDCTL_MIX_READ";
	else if (val == USB_SET_CONFIG)
		str = "USB_SET_CONFIG";
	else if (val == SIOCDELST)
		str = "SIOCDELST";
	else if (val == BT848_GCSAT)
		str = "BT848_GCSAT";
	else if (val == BT848_WEEPROM)
		str = "BT848_WEEPROM";
	else if (val == SIOCSRTRFLUSH_IN6)
		str = "SIOCSRTRFLUSH_IN6";
	else if (val == CDIOCCLRDEBUG)
		str = "CDIOCCLRDEBUG";
	else if (val == MDIOCLIST)
		str = "MDIOCLIST";
	else if (val == SNDCTL_DSP_GETOSPACE)
		str = "SNDCTL_DSP_GETOSPACE";
	else if (val == SIOCGIFFIB)
		str = "SIOCGIFFIB";
	else if (val == SG_GET_RESERVED_SIZE)
		str = "SG_GET_RESERVED_SIZE";
	else if (val == OPROMGETPROP)
		str = "OPROMGETPROP";
	else if (val == SW_VESA_FULL_320)
		str = "SW_VESA_FULL_320";
	else if (val == SIOCFRSYN)
		str = "SIOCFRSYN";
	else if (val == DEV_SUSPEND)
		str = "DEV_SUSPEND";
	else if (val == CFIOCQRY)
		str = "CFIOCQRY";
	else if (val == WDIOC_SETTIMEOUT)
		str = "WDIOC_SETTIMEOUT";
	else if (val == SW_VESA_64K_1024)
		str = "SW_VESA_64K_1024";
	else if (val == SMB_OLD_BREAD)
		str = "SMB_OLD_BREAD";
	else if (val == USB_IFACE_DRIVER_DETACH)
		str = "USB_IFACE_DRIVER_DETACH";
	else if (val == AIOSYNC)
		str = "AIOSYNC";
	else if (val == SG_SET_COMMAND_Q)
		str = "SG_SET_COMMAND_Q";
	else if (val == MFIIO_PASSTHRU)
		str = "MFIIO_PASSTHRU";
	else if (val == SIOCIFCREATE)
		str = "SIOCIFCREATE";
	else if (val == CDRIOCREADFORMATCAPS)
		str = "CDRIOCREADFORMATCAPS";
	else if (val == SIOCLOOKUPDELTABLE)
		str = "SIOCLOOKUPDELTABLE";
	else if (val == AGPIOC_ALLOCATE)
		str = "AGPIOC_ALLOCATE";
	else if (val == METEORSBRIG)
		str = "METEORSBRIG";
	else if (val == MPTIO_RAID_ACTION)
		str = "MPTIO_RAID_ACTION";
	else if (val == USB_SET_PORT_DISABLE)
		str = "USB_SET_PORT_DISABLE";
	else if (val == SW_ENH_C40x25)
		str = "SW_ENH_C40x25";
	else if (val == NGIOCGINFO)
		str = "NGIOCGINFO";
	else if (val == BIOCVERSION)
		str = "BIOCVERSION";
	else if (val == CDIOREADTOCENTRY)
		str = "CDIOREADTOCENTRY";
	else if (val == SNDCTL_DSP_GETERROR)
		str = "SNDCTL_DSP_GETERROR";
	else if (val == USB_GET_TX_ENDPOINT_DESC)
		str = "USB_GET_TX_ENDPOINT_DESC";
	else if (val == TIOCSTOP)
		str = "TIOCSTOP";
	else if (val == SIOCGI2C)
		str = "SIOCGI2C";
	else if (val == CCISS_PASSTHRU)
		str = "CCISS_PASSTHRU";
	else if (val == SW_VESA_1280x1024)
		str = "SW_VESA_1280x1024";
	else if (val == SMBIOC_WRITE)
		str = "SMBIOC_WRITE";
	else if (val == SIOCFRENB)
		str = "SIOCFRENB";
	else if (val == WDIOC_SETSOFTTIMEOUTACT)
		str = "WDIOC_SETSOFTTIMEOUTACT";
	else if (val == VMIO_SIOCSKEEP)
		str = "VMIO_SIOCSKEEP";
	else if (val == FSACTL_AIF_THREAD)
		str = "FSACTL_AIF_THREAD";
	else if (val == FSACTL_OPEN_GET_ADAPTER_FIB)
		str = "FSACTL_OPEN_GET_ADAPTER_FIB";
	else if (val == SIOCGETSGCNT)
		str = "SIOCGETSGCNT";
	else if (val == SNDCTL_MIX_WRITE)
		str = "SNDCTL_MIX_WRITE";
	else if (val == GEOM_CTL)
		str = "GEOM_CTL";
	else if (val == SW_C80x25)
		str = "SW_C80x25";
	else if (val == GREGADDRD)
		str = "GREGADDRD";
	else if (val == GREGADDRS)
		str = "GREGADDRS";
	else if (val == FSACTL_OPENCLS_COMM_PERF_DATA)
		str = "FSACTL_OPENCLS_COMM_PERF_DATA";
	else if (val == TIOCPKT)
		str = "TIOCPKT";
	else if (val == SIOCATMGETVCCS)
		str = "SIOCATMGETVCCS";
	else if (val == AGPIOC_INFO)
		str = "AGPIOC_INFO";
	else if (val == TIOCSDTR)
		str = "TIOCSDTR";
	else if (val == MTIOCRBLIM)
		str = "MTIOCRBLIM";
	else if (val == GIO_SCRNMAP)
		str = "GIO_SCRNMAP";
	else if (val == SNDCTL_DSP_CURRENT_OPTR)
		str = "SNDCTL_DSP_CURRENT_OPTR";
	else if (val == SIOCPURGENAT)
		str = "SIOCPURGENAT";
	else if (val == CDIOREADTOCENTRYS)
		str = "CDIOREADTOCENTRYS";
	else if (val == USB_GET_POWER_MODE)
		str = "USB_GET_POWER_MODE";
	else if (val == MOUSE_READDATA)
		str = "MOUSE_READDATA";
	else if (val == SIOCSIFDESCR)
		str = "SIOCSIFDESCR";
	else if (val == MTIOCGET)
		str = "MTIOCGET";
	else if (val == GIFSOPTS)
		str = "GIFSOPTS";
	else if (val == SG_GET_KEEP_ORPHAN)
		str = "SG_GET_KEEP_ORPHAN";
	else if (val == PPIGECR)
		str = "PPIGECR";
	else if (val == CUSE_IOCTL_FREE_UNIT_BY_ID)
		str = "CUSE_IOCTL_FREE_UNIT_BY_ID";
	else if (val == IPMICTL_SEND_COMMAND)
		str = "IPMICTL_SEND_COMMAND";
	else if (val == MTIOCSETEOTMODEL)
		str = "MTIOCSETEOTMODEL";
	else if (val == CONS_GETCURSORSHAPE)
		str = "CONS_GETCURSORSHAPE";
	else if (val == DEVFSIO_SUSE)
		str = "DEVFSIO_SUSE";
	else if (val == SIOCSLAGGHASH)
		str = "SIOCSLAGGHASH";
	else if (val == IPMICTL_GET_MY_LUN_CMD)
		str = "IPMICTL_GET_MY_LUN_CMD";
	else if (val == GPIOGETCONFIG)
		str = "GPIOGETCONFIG";
	else if (val == USB_DEV_QUIRK_REMOVE)
		str = "USB_DEV_QUIRK_REMOVE";
	else if (val == USB_REQUEST)
		str = "USB_REQUEST";
	else if (val == ENCIOC_GETELMMAP)
		str = "ENCIOC_GETELMMAP";
	else if (val == CCISS_GETINTINFO)
		str = "CCISS_GETINTINFO";
	else if (val == SIOCSIFPHYADDR)
		str = "SIOCSIFPHYADDR";
	else if (val == SIOCGVH)
		str = "SIOCGVH";
	else if (val == SW_VESA_64K_320)
		str = "SW_VESA_64K_320";
	else if (val == SIOCIFDESTROY)
		str = "SIOCIFDESTROY";
	else if (val == TIOCMBIC)
		str = "TIOCMBIC";
	else if (val == SIOCSIFGENERIC)
		str = "SIOCSIFGENERIC";
	else if (val == PIOCSFL)
		str = "PIOCSFL";
	else if (val == RADIO_SETFREQ)
		str = "RADIO_SETFREQ";
	else if (val == FSACTL_FORCE_DELETE_DISK)
		str = "FSACTL_FORCE_DELETE_DISK";
	else if (val == SW_VESA_C80x60)
		str = "SW_VESA_C80x60";
	else if (val == TIOCTIMESTAMP)
		str = "TIOCTIMESTAMP";
	else if (val == BIOCGTSTAMP)
		str = "BIOCGTSTAMP";
	else if (val == SNDCTL_GETLABEL)
		str = "SNDCTL_GETLABEL";
	else if (val == TIOCHPCL)
		str = "TIOCHPCL";
	else if (val == CPUCTL_UPDATE)
		str = "CPUCTL_UPDATE";
	else if (val == FBIOSVIDEO)
		str = "FBIOSVIDEO";
	else if (val == SNDCTL_DSP_GETFMTS)
		str = "SNDCTL_DSP_GETFMTS";
	else if (val == CFIOCGPLR)
		str = "CFIOCGPLR";
	else if (val == SIOCLOOKUPADDNODEW)
		str = "SIOCLOOKUPADDNODEW";
	else if (val == MOUSE_SETLEVEL)
		str = "MOUSE_SETLEVEL";
	else if (val == CDIOCREADSUBCHANNEL)
		str = "CDIOCREADSUBCHANNEL";
	else if (val == SIOCSIFADDR)
		str = "SIOCSIFADDR";
	else if (val == TIOCSWINSZ)
		str = "TIOCSWINSZ";
	else if (val == SIOCSIFCAP)
		str = "SIOCSIFCAP";
	else if (val == DIOCSMBR)
		str = "DIOCSMBR";
	else if (val == DEV_DISABLE)
		str = "DEV_DISABLE";
	else if (val == BT848_SBRIG)
		str = "BT848_SBRIG";
	else if (val == IOV_CONFIG)
		str = "IOV_CONFIG";
	else if (val == FBIOGETCMAPI)
		str = "FBIOGETCMAPI";
	else if (val == BT848_GPIO_GET_DATA)
		str = "BT848_GPIO_GET_DATA";
	else if (val == SIOCIPFITER)
		str = "SIOCIPFITER";
	else if (val == IPMICTL_SET_MY_ADDRESS_CMD)
		str = "IPMICTL_SET_MY_ADDRESS_CMD";
	else if (val == TIOCMBIS)
		str = "TIOCMBIS";
	else if (val == CUSE_IOCTL_FREE_UNIT)
		str = "CUSE_IOCTL_FREE_UNIT";
	else if (val == FD_SOPTS)
		str = "FD_SOPTS";
	else if (val == AUDITPIPE_GET_TRUNCATES)
		str = "AUDITPIPE_GET_TRUNCATES";
	else if (val == SNDCTL_TMR_CONTINUE)
		str = "SNDCTL_TMR_CONTINUE";
	else if (val == IOCATAGSPINDOWN)
		str = "IOCATAGSPINDOWN";
	else if (val == TAPGIFINFO)
		str = "TAPGIFINFO";
	else if (val == TIOCNOTTY)
		str = "TIOCNOTTY";
	else if (val == SIOCGIFCAP)
		str = "SIOCGIFCAP";
	else if (val == PIO_FONT8x8)
		str = "PIO_FONT8x8";
	else if (val == CDNR_ENABLE)
		str = "CDNR_ENABLE";
	else if (val == USB_GET_TX_INTERFACE_DESC)
		str = "USB_GET_TX_INTERFACE_DESC";
	else if (val == FSACTL_GET_PCI_INFO)
		str = "FSACTL_GET_PCI_INFO";
	else if (val == SIOCADSCA)
		str = "SIOCADSCA";
	else if (val == SW_ENH_MONOAPA2)
		str = "SW_ENH_MONOAPA2";
	else if (val == SIOCADAFR)
		str = "SIOCADAFR";
	else if (val == SMBIOC_OPENSESSION)
		str = "SMBIOC_OPENSESSION";
	else if (val == OFIOCSET)
		str = "OFIOCSET";
	else if (val == SIOCGIFSTAT_IN6)
		str = "SIOCGIFSTAT_IN6";
	else if (val == PCIOCREAD)
		str = "PCIOCREAD";
	else if (val == CDNR_TCM_STATS)
		str = "CDNR_TCM_STATS";
	else if (val == CDIOCSETLEFT)
		str = "CDIOCSETLEFT";
	else if (val == CONS_SETTERM)
		str = "CONS_SETTERM";
	else if (val == METEORGETGEO)
		str = "METEORGETGEO";
	else if (val == UFTDIIOC_SET_LATENCY)
		str = "UFTDIIOC_SET_LATENCY";
	else if (val == KDENABIO)
		str = "KDENABIO";
	else if (val == SNDCTL_ENGINEINFO)
		str = "SNDCTL_ENGINEINFO";
	else if (val == SW_VGA_M90x25)
		str = "SW_VGA_M90x25";
	else if (val == SW_VGA_M90x30)
		str = "SW_VGA_M90x30";
	else if (val == SW_VGA_M90x43)
		str = "SW_VGA_M90x43";
	else if (val == TIOCMSDTRWAIT)
		str = "TIOCMSDTRWAIT";
	else if (val == SIOCGIFNETMASK_IN6)
		str = "SIOCGIFNETMASK_IN6";
	else if (val == SW_TEXT_80x25)
		str = "SW_TEXT_80x25";
	else if (val == SW_VGA_M90x50)
		str = "SW_VGA_M90x50";
	else if (val == WDIOC_SETSOFT)
		str = "WDIOC_SETSOFT";
	else if (val == SW_TEXT_80x30)
		str = "SW_TEXT_80x30";
	else if (val == USB_DEVICEENUMERATE)
		str = "USB_DEVICEENUMERATE";
	else if (val == FW_GSTBUF)
		str = "FW_GSTBUF";
	else if (val == SW_VGA_M90x60)
		str = "SW_VGA_M90x60";
	else if (val == SNDCTL_MIXERINFO)
		str = "SNDCTL_MIXERINFO";
	else if (val == SW_TEXT_80x43)
		str = "SW_TEXT_80x43";
	else if (val == SW_TEXT_80x50)
		str = "SW_TEXT_80x50";
	else if (val == SNDCTL_SEQ_THRESHOLD)
		str = "SNDCTL_SEQ_THRESHOLD";
	else if (val == SW_TEXT_80x60)
		str = "SW_TEXT_80x60";
	else if (val == SW_C40x25)
		str = "SW_C40x25";
	else if (val == USB_GET_PLUGTIME)
		str = "USB_GET_PLUGTIME";
	else if (val == SIOCGIFCONF)
		str = "SIOCGIFCONF";
	else if (val == AIOGMIX)
		str = "AIOGMIX";
	else if (val == ENCIOC_GETENCNAME)
		str = "ENCIOC_GETENCNAME";
	else if (val == SNDCTL_GETSONG)
		str = "SNDCTL_GETSONG";
	else if (val == SIOCLOOKUPDELNODE)
		str = "SIOCLOOKUPDELNODE";
	else if (val == FWOHCI_RDREG)
		str = "FWOHCI_RDREG";
	else if (val == SG_IO)
		str = "SG_IO";
	else if (val == ENCIOC_GETTEXT)
		str = "ENCIOC_GETTEXT";
	else if (val == SW_VESA_CG640x400)
		str = "SW_VESA_CG640x400";
	else if (val == OSIOCAIFADDR)
		str = "OSIOCAIFADDR";
	else if (val == SIOCSIFNETMASK)
		str = "SIOCSIFNETMASK";
	else if (val == PIO_KEYMAP)
		str = "PIO_KEYMAP";
	else if (val == SIOCSTUNFIB)
		str = "SIOCSTUNFIB";
	else if (val == METEORGINPUT)
		str = "METEORGINPUT";
	else if (val == SIOCGIFADDR_IN6)
		str = "SIOCGIFADDR_IN6";
	else if (val == USB_SETDEBUG)
		str = "USB_SETDEBUG";
	else if (val == PIO_KEYMAPENT)
		str = "PIO_KEYMAPENT";
	else if (val == CPUCTL_MSRSBIT)
		str = "CPUCTL_MSRSBIT";
	else if (val == FIOGETLBA)
		str = "FIOGETLBA";
	else if (val == SNDCTL_SYSINFO)
		str = "SNDCTL_SYSINFO";
	else if (val == SW_CG320)
		str = "SW_CG320";
	else if (val == GRESOPTS)
		str = "GRESOPTS";
	else if (val == FSACTL_CLOSE_GET_ADAPTER_FIB)
		str = "FSACTL_CLOSE_GET_ADAPTER_FIB";
	else if (val == PPS_IOC_DESTROY)
		str = "PPS_IOC_DESTROY";
	else if (val == SW_VESA_CG640x480)
		str = "SW_VESA_CG640x480";
	else if (val == TIIOCSETTRACE)
		str = "TIIOCSETTRACE";
	else if (val == TVTUNER_SETFREQ)
		str = "TVTUNER_SETFREQ";
	else if (val == JOY_SET_Y_OFFSET)
		str = "JOY_SET_Y_OFFSET";
	else if (val == SW_CG640_E)
		str = "SW_CG640_E";
	else if (val == SIOCAADDRCTL_POLICY)
		str = "SIOCAADDRCTL_POLICY";
	else if (val == SIOCRMIFR)
		str = "SIOCRMIFR";
	else if (val == DEV_SET_DRIVER)
		str = "DEV_SET_DRIVER";
	else if (val == SG_GET_TIMEOUT)
		str = "SG_GET_TIMEOUT";
	else if (val == METEORGCHCV)
		str = "METEORGCHCV";
	else if (val == KIOCSOUND)
		str = "KIOCSOUND";
	else if (val == BT848_REEPROM)
		str = "BT848_REEPROM";
	else if (val == SIOCSIFVNET)
		str = "SIOCSIFVNET";
	else if (val == CONS_MOUSECTL)
		str = "CONS_MOUSECTL";
	else if (val == SNDCTL_AUDIOINFO_EX)
		str = "SNDCTL_AUDIOINFO_EX";
	else if (val == NIOCGINFO)
		str = "NIOCGINFO";
	else if (val == METEORCAPTUR)
		str = "METEORCAPTUR";
	else if (val == FSACTL_QUERY_ADAPTER_CONFIG)
		str = "FSACTL_QUERY_ADAPTER_CONFIG";
	else if (val == AD_MICRO_PERIOD_GET)
		str = "AD_MICRO_PERIOD_GET";
	else if (val == CDNR_TBM_STATS)
		str = "CDNR_TBM_STATS";
	else if (val == AUDITPIPE_GET_INSERTS)
		str = "AUDITPIPE_GET_INSERTS";
	else if (val == SW_PC98_PEGC640x400)
		str = "SW_PC98_PEGC640x400";
	else if (val == PPS_IOC_CREATE)
		str = "PPS_IOC_CREATE";
	else if (val == BT848_GVSAT)
		str = "BT848_GVSAT";
	else if (val == SIOCSIFALIFETIME_IN6)
		str = "SIOCSIFALIFETIME_IN6";
	else if (val == SG_GET_REQUEST_TABLE)
		str = "SG_GET_REQUEST_TABLE";
	else if (val == FIONREAD)
		str = "FIONREAD";
	else if (val == SOUND_PCM_WRITE_FILTER)
		str = "SOUND_PCM_WRITE_FILTER";
	else if (val == SW_VESA_64K_1280)
		str = "SW_VESA_64K_1280";
	else if (val == TAPGIFNAME)
		str = "TAPGIFNAME";
	else if (val == SIOCZRLST)
		str = "SIOCZRLST";
	else if (val == SG_SET_RESERVED_SIZE)
		str = "SG_SET_RESERVED_SIZE";
	else if (val == WDIOC_GETTIMEOUT)
		str = "WDIOC_GETTIMEOUT";
	else if (val == FILEMON_SET_FD)
		str = "FILEMON_SET_FD";
	else if (val == CDIOCRESET)
		str = "CDIOCRESET";
	else if (val == USB_DEVICESTATS)
		str = "USB_DEVICESTATS";
	else if (val == SMB_TRANS)
		str = "SMB_TRANS";
	else if (val == VMIO_SIOCSETMACADDR)
		str = "VMIO_SIOCSETMACADDR";
	else if (val == METEORGCOUNT)
		str = "METEORGCOUNT";
	else if (val == SW_VGA12)
		str = "SW_VGA12";
	else if (val == VT_SETMODE)
		str = "VT_SETMODE";
	else if (val == JOY_GET_Y_OFFSET)
		str = "JOY_GET_Y_OFFSET";
	else if (val == G_GATE_CMD_CANCEL)
		str = "G_GATE_CMD_CANCEL";
	else if (val == CPUCTL_CPUID)
		str = "CPUCTL_CPUID";
	else if (val == CCISS_GETHEARTBEAT)
		str = "CCISS_GETHEARTBEAT";
	else if (val == SNPGTTY)
		str = "SNPGTTY";
	else if (val == USB_SET_REPORT)
		str = "USB_SET_REPORT";
	else if (val == SW_EGAMONO80x25)
		str = "SW_EGAMONO80x25";
	else if (val == SW_PC98_PEGC640x480)
		str = "SW_PC98_PEGC640x480";
	else if (val == G_GATE_CMD_MODIFY)
		str = "G_GATE_CMD_MODIFY";
	else if (val == USB_GET_TX_FRAME_SIZE)
		str = "USB_GET_TX_FRAME_SIZE";
	else if (val == OPROMCHILD)
		str = "OPROMCHILD";
	else if (val == BIOCGDIRECTION)
		str = "BIOCGDIRECTION";
	else if (val == BT848GCLIP)
		str = "BT848GCLIP";
	else if (val == PPISEPPA)
		str = "PPISEPPA";
	else if (val == PPISEPPD)
		str = "PPISEPPD";
	else if (val == FW_ASYREQ)
		str = "FW_ASYREQ";
	else if (val == FWOHCI_WRPHYREG)
		str = "FWOHCI_WRPHYREG";
	else if (val == SIOCGLAGGFLAGS)
		str = "SIOCGLAGGFLAGS";
	else if (val == FSACTL_GET_FIBTIMES)
		str = "FSACTL_GET_FIBTIMES";
	else if (val == CHIOGPARAMS)
		str = "CHIOGPARAMS";
	else if (val == SG_GET_LOW_DMA)
		str = "SG_GET_LOW_DMA";
	else if (val == BT848_SIGNATURE)
		str = "BT848_SIGNATURE";
	else if (val == JOY_SET_X_OFFSET)
		str = "JOY_SET_X_OFFSET";
	else if (val == SIOCGENITER)
		str = "SIOCGENITER";
	else if (val == MOUSE_SYN_GETHWINFO)
		str = "MOUSE_SYN_GETHWINFO";
	else if (val == TIOCMGET)
		str = "TIOCMGET";
	else if (val == DIGIIO_MODEL)
		str = "DIGIIO_MODEL";
	else if (val == USB_FS_CLEAR_STALL_SYNC)
		str = "USB_FS_CLEAR_STALL_SYNC";
	else if (val == ENCIOC_GETENCSTAT)
		str = "ENCIOC_GETENCSTAT";
	else if (val == USB_SET_TEMPLATE)
		str = "USB_SET_TEMPLATE";
	else if (val == SIOCSLAGGDELPORT)
		str = "SIOCSLAGGDELPORT";
	else if (val == TIOCCBRK)
		str = "TIOCCBRK";
	else if (val == NIOCTXSYNC)
		str = "NIOCTXSYNC";
	else if (val == FM_GET_STAT)
		str = "FM_GET_STAT";
	else if (val == BIOCLOCK)
		str = "BIOCLOCK";
	else if (val == FWOHCI_RDPHYREG)
		str = "FWOHCI_RDPHYREG";
	else if (val == MOUSE_GETHWINFO)
		str = "MOUSE_GETHWINFO";
	else if (val == CDRIOCNEXTWRITEABLEADDR)
		str = "CDRIOCNEXTWRITEABLEADDR";
	else if (val == MTIOCRDSPOS)
		str = "MTIOCRDSPOS";
	else if (val == FW_STSTREAM)
		str = "FW_STSTREAM";
	else if (val == MPTIO_WRITE_CFG_PAGE)
		str = "MPTIO_WRITE_CFG_PAGE";
	else if (val == SNDCTL_MIX_EXTINFO)
		str = "SNDCTL_MIX_EXTINFO";
	else if (val == UFTDIIOC_GET_BITMODE)
		str = "UFTDIIOC_GET_BITMODE";
	else if (val == OCHIOGSTATUS)
		str = "OCHIOGSTATUS";
	else if (val == USB_SET_POWER_MODE)
		str = "USB_SET_POWER_MODE";
	else if (val == SIOCDELMULTI)
		str = "SIOCDELMULTI";
	else if (val == AUDITPIPE_FLUSH)
		str = "AUDITPIPE_FLUSH";
	else if (val == DEV_ATTACH)
		str = "DEV_ATTACH";
	else if (val == IOCATASMODE)
		str = "IOCATASMODE";
	else if (val == SNDCTL_DSP_STEREO)
		str = "SNDCTL_DSP_STEREO";
	else if (val == SIOCSDRVSPEC)
		str = "SIOCSDRVSPEC";
	else if (val == SIOCSGIFPREFIX_IN6)
		str = "SIOCSGIFPREFIX_IN6";
	else if (val == AD_GAINS_SET)
		str = "AD_GAINS_SET";
	else if (val == MTIOCSLOCATE)
		str = "MTIOCSLOCATE";
	else if (val == IOCATARAIDSTATUS)
		str = "IOCATARAIDSTATUS";
	else if (val == CPUCTL_MSRCBIT)
		str = "CPUCTL_MSRCBIT";
	else if (val == SIOCSLOWAT)
		str = "SIOCSLOWAT";
	else if (val == METEORGBT254)
		str = "METEORGBT254";
	else if (val == USB_SET_RX_SHORT_XFER)
		str = "USB_SET_RX_SHORT_XFER";
	else if (val == CDRIOCFIXATE)
		str = "CDRIOCFIXATE";
	else if (val == CONS_SCRSHOT)
		str = "CONS_SCRSHOT";
	else if (val == KDRASTER)
		str = "KDRASTER";
	else if (val == ENCIOC_SETELMSTAT)
		str = "ENCIOC_SETELMSTAT";
	else if (val == CDNR_IF_DETACH)
		str = "CDNR_IF_DETACH";
	else if (val == FBIO_ADAPTER)
		str = "FBIO_ADAPTER";
	else if (val == SMBIOC_REQUEST)
		str = "SMBIOC_REQUEST";
	else if (val == ACPIIO_SETSLPSTATE)
		str = "ACPIIO_SETSLPSTATE";
	else if (val == CIOCCRYPTAEAD)
		str = "CIOCCRYPTAEAD";
	else if (val == JOY_GET_X_OFFSET)
		str = "JOY_GET_X_OFFSET";
	else if (val == SNDCTL_DSP_GET_RECSRC)
		str = "SNDCTL_DSP_GET_RECSRC";
	else if (val == USB_SET_RX_STALL_FLAG)
		str = "USB_SET_RX_STALL_FLAG";
	else if (val == SIOCSTAT1)
		str = "SIOCSTAT1";
	else if (val == SIOCSTAT2)
		str = "SIOCSTAT2";
	else if (val == OSIOCAIFADDR_IN6)
		str = "OSIOCAIFADDR_IN6";
	else if (val == USB_GET_TEMPLATE)
		str = "USB_GET_TEMPLATE";
	else if (val == WDIOC_GETTIMELEFT)
		str = "WDIOC_GETTIMELEFT";
	else if (val == SIOCSLAGGOPTS)
		str = "SIOCSLAGGOPTS";
	else if (val == CDIOCSETDEBUG)
		str = "CDIOCSETDEBUG";
	else if (val == SW_VESA_FULL_640)
		str = "SW_VESA_FULL_640";
	else if (val == SIOCGIFPDSTADDR_IN6)
		str = "SIOCGIFPDSTADDR_IN6";
	else if (val == FSACTL_DELETE_DISK)
		str = "FSACTL_DELETE_DISK";
	else if (val == FW_IBUSRST)
		str = "FW_IBUSRST";
	else if (val == SIOCSIFPHYS)
		str = "SIOCSIFPHYS";
	else if (val == SNDCTL_DSP_GETPLAYVOL)
		str = "SNDCTL_DSP_GETPLAYVOL";
	else if (val == SW_VGA_CG320)
		str = "SW_VGA_CG320";
	else if (val == G_GATE_CMD_START)
		str = "G_GATE_CMD_START";
	else if (val == SMB_WRITEB)
		str = "SMB_WRITEB";
	else if (val == SMB_WRITEW)
		str = "SMB_WRITEW";
	else if (val == TIOCPTMASTER)
		str = "TIOCPTMASTER";
	else if (val == DVDIOCREADSTRUCTURE)
		str = "DVDIOCREADSTRUCTURE";
	else if (val == PTIOCSETTIMEOUT)
		str = "PTIOCSETTIMEOUT";
	else if (val == TVTUNER_GETCHNL)
		str = "TVTUNER_GETCHNL";
	else if (val == MTIOCEXTGET)
		str = "MTIOCEXTGET";
	else if (val == TIOCGSID)
		str = "TIOCGSID";
	else if (val == AIOSMIX)
		str = "AIOSMIX";
	else if (val == DEVFSIO_RAPPLY)
		str = "DEVFSIO_RAPPLY";
	else if (val == CDIOCPREVENT)
		str = "CDIOCPREVENT";
	else if (val == CONS_SETKBD)
		str = "CONS_SETKBD";
	else if (val == ACPIIO_ACAD_GET_STATUS)
		str = "ACPIIO_ACAD_GET_STATUS";
	else if (val == FBIO_SETMODE)
		str = "FBIO_SETMODE";
	else if (val == CDNR_MOD_TBM)
		str = "CDNR_MOD_TBM";
	else if (val == SNDCTL_DSP_POST)
		str = "SNDCTL_DSP_POST";
	else if (val == USB_FS_UNINIT)
		str = "USB_FS_UNINIT";
	else if (val == PIO_VFONT)
		str = "PIO_VFONT";
	else if (val == DEVFSIO_SGETNEXT)
		str = "DEVFSIO_SGETNEXT";
	else if (val == USB_QUIRK_NAME_GET)
		str = "USB_QUIRK_NAME_GET";
	else if (val == TIOCGLTC)
		str = "TIOCGLTC";
	else if (val == PPISFIFO)
		str = "PPISFIFO";
	else if (val == FBIO_GETLINEWIDTH)
		str = "FBIO_GETLINEWIDTH";
	else if (val == BT848_SBTSC)
		str = "BT848_SBTSC";
	else if (val == CIOCCRYPT)
		str = "CIOCCRYPT";
	else if (val == CUSE_IOCTL_GET_SIG)
		str = "CUSE_IOCTL_GET_SIG";
	else if (val == CONS_RELKBD)
		str = "CONS_RELKBD";
	else if (val == MFI_SET_AEN)
		str = "MFI_SET_AEN";
	else if (val == USB_GET_TX_BUFFER_SIZE)
		str = "USB_GET_TX_BUFFER_SIZE";
	else if (val == VT_RELDISP)
		str = "VT_RELDISP";
	else if (val == IOCATAGPARM)
		str = "IOCATAGPARM";
	else if (val == CONS_GSAVER)
		str = "CONS_GSAVER";
	else if (val == SIOCSTPUT)
		str = "SIOCSTPUT";
	else if (val == BT848_SCONT)
		str = "BT848_SCONT";
	else if (val == FIOSEEKHOLE)
		str = "FIOSEEKHOLE";
	else if (val == G_GATE_CMD_DESTROY)
		str = "G_GATE_CMD_DESTROY";
	else if (val == METEORGBRIG)
		str = "METEORGBRIG";
	else if (val == SW_VGA11)
		str = "SW_VGA11";
	else if (val == SW_VGA13)
		str = "SW_VGA13";
	else if (val == CCISS_GETPCIINFO)
		str = "CCISS_GETPCIINFO";
	else if (val == AGPIOC_BIND)
		str = "AGPIOC_BIND";
	else if (val == MOUSE_GETVARS)
		str = "MOUSE_GETVARS";
	else if (val == CDNR_MOD_TSW)
		str = "CDNR_MOD_TSW";
	else if (val == NANDFS_IOCTL_GET_FSINFO)
		str = "NANDFS_IOCTL_GET_FSINFO";
	else if (val == FBIOSCURPOS)
		str = "FBIOSCURPOS";
	else if (val == SIOCIPFDELTOK)
		str = "SIOCIPFDELTOK";
	else if (val == OTIOCCONS)
		str = "OTIOCCONS";
	else if (val == TIOCSIG)
		str = "TIOCSIG";
	else if (val == PPISECR)
		str = "PPISECR";
	else if (val == KDSBORDER)
		str = "KDSBORDER";
	else if (val == SNDCTL_DSP_SILENCE)
		str = "SNDCTL_DSP_SILENCE";
	else if (val == DUMPDMA)
		str = "DUMPDMA";
	else if (val == BIOCFEEDBACK)
		str = "BIOCFEEDBACK";
	else if (val == MPTIO_READ_CFG_HEADER)
		str = "MPTIO_READ_CFG_HEADER";
	else if (val == SG_GET_PACK_ID)
		str = "SG_GET_PACK_ID";
	else if (val == CUSE_IOCTL_READ_DATA)
		str = "CUSE_IOCTL_READ_DATA";
	else if (val == CONS_BLANKTIME)
		str = "CONS_BLANKTIME";
	else if (val == TIOCSTI)
		str = "TIOCSTI";
	else if (val == USB_SET_GPIO)
		str = "USB_SET_GPIO";
	else if (val == PPISSTATUS)
		str = "PPISSTATUS";
	else if (val == CDIOCSTART)
		str = "CDIOCSTART";
	else if (val == MPTIO_READ_EXT_CFG_HEADER)
		str = "MPTIO_READ_EXT_CFG_HEADER";
	else if (val == SIOCSPGRP)
		str = "SIOCSPGRP";
	else if (val == KDSKBMODE)
		str = "KDSKBMODE";
	else if (val == SNDCTL_DSP_COOKEDMODE)
		str = "SNDCTL_DSP_COOKEDMODE";
	else if (val == TARGIOCENABLE)
		str = "TARGIOCENABLE";
	else if (val == SIOCGIFALIFETIME_IN6)
		str = "SIOCGIFALIFETIME_IN6";
	else if (val == IPMICTL_SET_MY_LUN_CMD)
		str = "IPMICTL_SET_MY_LUN_CMD";
	else if (val == SW_CG640x350)
		str = "SW_CG640x350";
	else if (val == PPISCTRL)
		str = "PPISCTRL";
	else if (val == GIFGOPTS)
		str = "GIFGOPTS";
	else if (val == TIOCCONS)
		str = "TIOCCONS";
	else if (val == AGPIOC_RELEASE)
		str = "AGPIOC_RELEASE";
	else if (val == GREGPROTO)
		str = "GREGPROTO";
	else if (val == DEVFSIO_RGETNEXT)
		str = "DEVFSIO_RGETNEXT";
	else if (val == BIOCGRTIMEOUT)
		str = "BIOCGRTIMEOUT";
	else if (val == CHIOPOSITION)
		str = "CHIOPOSITION";
	else if (val == TAPSDEBUG)
		str = "TAPSDEBUG";
	else if (val == FBIOGTYPE)
		str = "FBIOGTYPE";
	else if (val == BIOCGSTATS)
		str = "BIOCGSTATS";
	else if (val == SNDCTL_SYNTH_INFO)
		str = "SNDCTL_SYNTH_INFO";
	else if (val == SIOCCIFPREFIX_IN6)
		str = "SIOCCIFPREFIX_IN6";
	else if (val == BT848SCBUF)
		str = "BT848SCBUF";
	else if (val == CPUCTL_RDMSR)
		str = "CPUCTL_RDMSR";
	else if (val == DEV_ENABLE)
		str = "DEV_ENABLE";
	else if (val == SPKRTUNE)
		str = "SPKRTUNE";
	else if (val == USB_GET_CONFIG_DESC)
		str = "USB_GET_CONFIG_DESC";
	else if (val == TIOCSETAF)
		str = "TIOCSETAF";
	else if (val == CCISS_GETNODENAME)
		str = "CCISS_GETNODENAME";
	else if (val == PBIO_GETOPACE)
		str = "PBIO_GETOPACE";
	else if (val == SIOCGIFINDEX)
		str = "SIOCGIFINDEX";
	else if (val == OFIOCGETCHILD)
		str = "OFIOCGETCHILD";
	else if (val == KDSETMODE)
		str = "KDSETMODE";
	else if (val == FBIO_GETPALETTE)
		str = "FBIO_GETPALETTE";
	else if (val == USB_GET_REPORT)
		str = "USB_GET_REPORT";
	else if (val == SMB_QUICK_READ)
		str = "SMB_QUICK_READ";
	else if (val == DEVFSIO_RDEL)
		str = "DEVFSIO_RDEL";
	else if (val == SIOCSIFLLADDR)
		str = "SIOCSIFLLADDR";
	else if (val == SIOCSIFADDR_IN6)
		str = "SIOCSIFADDR_IN6";
	else if (val == SW_VESA_C132x25)
		str = "SW_VESA_C132x25";
	else if (val == SW_VESA_C132x43)
		str = "SW_VESA_C132x43";
	else if (val == SW_VESA_C132x50)
		str = "SW_VESA_C132x50";
	else if (val == SW_VESA_C132x60)
		str = "SW_VESA_C132x60";
	else if (val == DVDIOCSENDKEY)
		str = "DVDIOCSENDKEY";
	else if (val == SIOCSIFFIB)
		str = "SIOCSIFFIB";
	else if (val == TIOCEXT)
		str = "TIOCEXT";
	else if (val == SW_VESA_32K_800)
		str = "SW_VESA_32K_800";
	else if (val == SNDCTL_DSP_GETTRIGGER)
		str = "SNDCTL_DSP_GETTRIGGER";
	else if (val == SNDCTL_SEQ_TESTMIDI)
		str = "SNDCTL_SEQ_TESTMIDI";
	else if (val == SNDCTL_MIDI_MPUMODE)
		str = "SNDCTL_MIDI_MPUMODE";
	else if (val == TIOCOUTQ)
		str = "TIOCOUTQ";
	else if (val == TIOCSLTC)
		str = "TIOCSLTC";
	else if (val == SG_SET_TIMEOUT)
		str = "SG_SET_TIMEOUT";
	else if (val == BT848_CCBARS)
		str = "BT848_CCBARS";
	else if (val == NANDFS_IOCTL_DELETE_CP)
		str = "NANDFS_IOCTL_DELETE_CP";
	else if (val == AUDITPIPE_GET_DROPS)
		str = "AUDITPIPE_GET_DROPS";
	else if (val == BT848_SLNOTCH)
		str = "BT848_SLNOTCH";
	else if (val == CONS_CLRHIST)
		str = "CONS_CLRHIST";
	else if (val == BT848_GBRIG)
		str = "BT848_GBRIG";
	else if (val == BIOCSETIF)
		str = "BIOCSETIF";
	else if (val == USB_FS_STOP)
		str = "USB_FS_STOP";
	else if (val == SIOCS80211)
		str = "SIOCS80211";
	else if (val == CONS_HISTORY)
		str = "CONS_HISTORY";
	else if (val == IOV_DELETE)
		str = "IOV_DELETE";
	else if (val == MFIIO_STATS)
		str = "MFIIO_STATS";
	else if (val == SMB_READW)
		str = "SMB_READW";
	else if (val == SIOCSPRISM2DEBUG)
		str = "SIOCSPRISM2DEBUG";
	else if (val == OFIOCFINDDEVICE)
		str = "OFIOCFINDDEVICE";
	else if (val == FD_GOPTS)
		str = "FD_GOPTS";
	else if (val == SNDCTL_MIX_ENUMINFO)
		str = "SNDCTL_MIX_ENUMINFO";
	else if (val == KDGKBSTATE)
		str = "KDGKBSTATE";
	else if (val == CDRIOCINITTRACK)
		str = "CDRIOCINITTRACK";
	else if (val == FW_SDEUI64)
		str = "FW_SDEUI64";
	else if (val == FBIO_FINDMODE)
		str = "FBIO_FINDMODE";
	else if (val == UFTDIIOC_WRITE_EEPROM)
		str = "UFTDIIOC_WRITE_EEPROM";
	else if (val == MDIOCQUERY)
		str = "MDIOCQUERY";
	else if (val == TIOCGPTN)
		str = "TIOCGPTN";
	else if (val == METEORSTS)
		str = "METEORSTS";
	else if (val == FM_START)
		str = "FM_START";
	else if (val == USB_SET_CM_OVER_DATA)
		str = "USB_SET_CM_OVER_DATA";
	else if (val == OFIOCGETOPTNODE)
		str = "OFIOCGETOPTNODE";
	else if (val == SIOCGETMIFCNT_IN6)
		str = "SIOCGETMIFCNT_IN6";
	else if (val == USB_SET_ALTINTERFACE)
		str = "USB_SET_ALTINTERFACE";
	else if (val == NANDFS_IOCTL_DELETE_SNAP)
		str = "NANDFS_IOCTL_DELETE_SNAP";
	else if (val == CONS_ADPINFO)
		str = "CONS_ADPINFO";
	else if (val == SNDCTL_DSP_HALT_OUTPUT)
		str = "SNDCTL_DSP_HALT_OUTPUT";
	else if (val == BT848_MSP_RESET)
		str = "BT848_MSP_RESET";
	else if (val == BIOCGETBUFMODE)
		str = "BIOCGETBUFMODE";
	else if (val == MPTIO_READ_EXT_CFG_PAGE)
		str = "MPTIO_READ_EXT_CFG_PAGE";
	else if (val == GIO_ATTR)
		str = "GIO_ATTR";
	else if (val == DEVFSIO_RAPPLYID)
		str = "DEVFSIO_RAPPLYID";
	else if (val == BIOCSDIRECTION)
		str = "BIOCSDIRECTION";
	else if (val == PTIOCGETTIMEOUT)
		str = "PTIOCGETTIMEOUT";
	else if (val == TUNGDEBUG)
		str = "TUNGDEBUG";
	else if (val == SIOCSIFDSTADDR)
		str = "SIOCSIFDSTADDR";
	else if (val == PIOCBIC)
		str = "PIOCBIC";
	else if (val == METEORSTATUS)
		str = "METEORSTATUS";
	else if (val == CONS_IO)
		str = "CONS_IO";
	else if (val == FSACTL_PROBE_CONTAINERS)
		str = "FSACTL_PROBE_CONTAINERS";
	else if (val == CDIOCPLAYBLOCKS)
		str = "CDIOCPLAYBLOCKS";
	else if (val == USB_GET_FULL_DESC)
		str = "USB_GET_FULL_DESC";
	else if (val == BT848_GPIO_SET_EN)
		str = "BT848_GPIO_SET_EN";
	else if (val == KDGETLED)
		str = "KDGETLED";
	else if (val == SW_VESA_CG1280x1024)
		str = "SW_VESA_CG1280x1024";
	else if (val == SIOCGIFMETRIC)
		str = "SIOCGIFMETRIC";
	else if (val == GRESADDRD)
		str = "GRESADDRD";
	else if (val == GRESADDRS)
		str = "GRESADDRS";
	else if (val == OSS_GETVERSION)
		str = "OSS_GETVERSION";
	else if (val == MFI_CMD)
		str = "MFI_CMD";
	else if (val == FBIOVERTICAL)
		str = "FBIOVERTICAL";
	else if (val == AUDITPIPE_SET_PRESELECT_AUID)
		str = "AUDITPIPE_SET_PRESELECT_AUID";
	else if (val == FBIO_BLANK)
		str = "FBIO_BLANK";
	else if (val == SIOCGPRISM2DEBUG)
		str = "SIOCGPRISM2DEBUG";
	else if (val == MDIOCATTACH)
		str = "MDIOCATTACH";
	else if (val == SNDCTL_TMR_TEMPO)
		str = "SNDCTL_TMR_TEMPO";
	else if (val == UFTDIIOC_READ_EEPROM)
		str = "UFTDIIOC_READ_EEPROM";
	else if (val == CHIOSPICKER)
		str = "CHIOSPICKER";
	else if (val == FM_STOP)
		str = "FM_STOP";
	else if (val == SIOCAIFPREFIX_IN6)
		str = "SIOCAIFPREFIX_IN6";
	else if (val == SW_CG640x480)
		str = "SW_CG640x480";
	else if (val == BT848_SUSAT)
		str = "BT848_SUSAT";
	else if (val == MTIOCSETLIST)
		str = "MTIOCSETLIST";
	else if (val == SW_VESA_64K_800)
		str = "SW_VESA_64K_800";
	else if (val == PCIOCATTACHED)
		str = "PCIOCATTACHED";
	else if (val == SW_VESA_FULL_800)
		str = "SW_VESA_FULL_800";
	else if (val == CDNR_DEL_FILTER)
		str = "CDNR_DEL_FILTER";
	else if (val == FBIO_GETWINORG)
		str = "FBIO_GETWINORG";
	else if (val == GREGOPTS)
		str = "GREGOPTS";
	else if (val == FIONBIO)
		str = "FIONBIO";
	else if (val == NVME_RESET_CONTROLLER)
		str = "NVME_RESET_CONTROLLER";
	else if (val == USB_SET_IMMED)
		str = "USB_SET_IMMED";
	else if (val == PBIO_GETDIFF)
		str = "PBIO_GETDIFF";
	else if (val == MOUSE_SETMODE)
		str = "MOUSE_SETMODE";
	else if (val == FIONWRITE)
		str = "FIONWRITE";
	else if (val == SOUND_PCM_WRITE_CHANNELS)
		str = "SOUND_PCM_WRITE_CHANNELS";
	else if (val == GIO_DEADKEYMAP)
		str = "GIO_DEADKEYMAP";
	else if (val == FIOGETOWN)
		str = "FIOGETOWN";
	else if (val == UFTDIIOC_SET_BITMODE)
		str = "UFTDIIOC_SET_BITMODE";
	else if (val == CUSE_IOCTL_FREE_MEMORY)
		str = "CUSE_IOCTL_FREE_MEMORY";
	else if (val == ACPIIO_BATT_GET_BATTINFO)
		str = "ACPIIO_BATT_GET_BATTINFO";
	else if (val == KDDISABIO)
		str = "KDDISABIO";
	else if (val == CDRIOCFORMAT)
		str = "CDRIOCFORMAT";
	else if (val == SNDCTL_SEQ_SYNC)
		str = "SNDCTL_SEQ_SYNC";
	else if (val == PIOCWAIT)
		str = "PIOCWAIT";
	else if (val == CIOCKEY)
		str = "CIOCKEY";
	else if (val == SW_VGA_C90x25)
		str = "SW_VGA_C90x25";
	else if (val == SIOCIPFFB)
		str = "SIOCIPFFB";
	else if (val == SW_VGA_C90x43)
		str = "SW_VGA_C90x43";
	else if (val == SW_VGA_C90x50)
		str = "SW_VGA_C90x50";
	else if (val == FSACTL_GET_COMM_PERF_DATA)
		str = "FSACTL_GET_COMM_PERF_DATA";
	else if (val == KDGKBINFO)
		str = "KDGKBINFO";
	else if (val == PCIOCLISTVPD)
		str = "PCIOCLISTVPD";
	else if (val == CDIOCSETVOL)
		str = "CDIOCSETVOL";
	else if (val == TUNSIFINFO)
		str = "TUNSIFINFO";
	else if (val == AD_GAINS_GET)
		str = "AD_GAINS_GET";
	else if (val == SG_GET_NUM_WAITING)
		str = "SG_GET_NUM_WAITING";
	else if (val == SOUND_MIXER_INFO)
		str = "SOUND_MIXER_INFO";
	else if (val == BIOCGDLTLIST)
		str = "BIOCGDLTLIST";
	else if (val == CDRIOCBLANK)
		str = "CDRIOCBLANK";
	else if (val == NANDFS_IOCTL_GET_VINFO)
		str = "NANDFS_IOCTL_GET_VINFO";
	else if (val == USB_GET_GPIO)
		str = "USB_GET_GPIO";
	else if (val == SNDCTL_SETNAME)
		str = "SNDCTL_SETNAME";
	else if (val == IOCATADETACH)
		str = "IOCATADETACH";
	else if (val == BIOCPROMISC)
		str = "BIOCPROMISC";
	else if (val == CDIOCPLAYTRACKS)
		str = "CDIOCPLAYTRACKS";
	else if (val == SW_PC98_80x25)
		str = "SW_PC98_80x25";
	else if (val == CDIOCSETMONO)
		str = "CDIOCSETMONO";
	else if (val == CONS_CURRENT)
		str = "CONS_CURRENT";
	else if (val == FW_GTPMAP)
		str = "FW_GTPMAP";
	else if (val == CDRIOCSETBLOCKSIZE)
		str = "CDRIOCSETBLOCKSIZE";
	else if (val == SMBIOC_T2RQ)
		str = "SMBIOC_T2RQ";
	else if (val == SNDCTL_TMR_TIMEBASE)
		str = "SNDCTL_TMR_TIMEBASE";
	else if (val == CDNR_DEL_ELEM)
		str = "CDNR_DEL_ELEM";
	else if (val == SNDCTL_DSP_GETISPACE)
		str = "SNDCTL_DSP_GETISPACE";
	else if (val == SIOCGIFGROUP)
		str = "SIOCGIFGROUP";
	else if (val == SIOCINIFR)
		str = "SIOCINIFR";
	else if (val == SMB_PCALL)
		str = "SMB_PCALL";
	else if (val == SIOCGIFSTAT_ICMP6)
		str = "SIOCGIFSTAT_ICMP6";
	else if (val == METEORSETGEO)
		str = "METEORSETGEO";
	else if (val == PPIGEPPA)
		str = "PPIGEPPA";
	else if (val == PPIGEPPD)
		str = "PPIGEPPD";
	else if (val == ENCIOC_GETENCID)
		str = "ENCIOC_GETENCID";
	else if (val == SIOCGIFPREFIX_IN6)
		str = "SIOCGIFPREFIX_IN6";
	else if (val == FM_GET_FREQ)
		str = "FM_GET_FREQ";
	else if (val == PCIOCGETCONF)
		str = "PCIOCGETCONF";
	else if (val == PBIO_GETIPACE)
		str = "PBIO_GETIPACE";
	else if (val == PIO_VFONT_DEFAULT)
		str = "PIO_VFONT_DEFAULT";
	else if (val == SNDCTL_DSP_GETCHANNELMASK)
		str = "SNDCTL_DSP_GETCHANNELMASK";
	else if (val == DIGIIO_IDENT)
		str = "DIGIIO_IDENT";
	else if (val == CDRIOCREADSPEED)
		str = "CDRIOCREADSPEED";
	else if (val == DIGIIO_RING)
		str = "DIGIIO_RING";
	else if (val == SNDCTL_DSP_GET_PLAYTGT)
		str = "SNDCTL_DSP_GET_PLAYTGT";
	else if (val == CHIOEXCHANGE)
		str = "CHIOEXCHANGE";
	else if (val == SIOCATMOPENVCC)
		str = "SIOCATMOPENVCC";
	else if (val == FBIO_ADPTYPE)
		str = "FBIO_ADPTYPE";
	else if (val == SETFKEY)
		str = "SETFKEY";
	else if (val == SIOCDADDRCTL_POLICY)
		str = "SIOCDADDRCTL_POLICY";
	else if (val == CIOCASYMFEAT)
		str = "CIOCASYMFEAT";
	else if (val == SW_VESA_32K_1024)
		str = "SW_VESA_32K_1024";
	else if (val == SW_BG640x480)
		str = "SW_BG640x480";
	else if (val == TVTUNER_GETTYPE)
		str = "TVTUNER_GETTYPE";
	else if (val == OPROMNEXT)
		str = "OPROMNEXT";
	else if (val == USB_READ_DIR)
		str = "USB_READ_DIR";
	else if (val == BT848_GPIO_SET_DATA)
		str = "BT848_GPIO_SET_DATA";
	else if (val == METEORSCONT)
		str = "METEORSCONT";
	else if (val == SIOCFUNCL)
		str = "SIOCFUNCL";
	else if (val == SIOCGTABL)
		str = "SIOCGTABL";
	else if (val == BT848_GSTATUS)
		str = "BT848_GSTATUS";
	else if (val == VMIO_SIOCSIFBR)
		str = "VMIO_SIOCSIFBR";
	else if (val == SIOCGIFBRDADDR)
		str = "SIOCGIFBRDADDR";
	else if (val == FSACTL_QUERY_DISK)
		str = "FSACTL_QUERY_DISK";
	else if (val == CDRIOCGETBLOCKSIZE)
		str = "CDRIOCGETBLOCKSIZE";
	else if (val == FSACTL_GET_VAR)
		str = "FSACTL_GET_VAR";
	else if (val == AUDITPIPE_GET_READS)
		str = "AUDITPIPE_GET_READS";
	else if (val == IOCATAGMODE)
		str = "IOCATAGMODE";
	else if (val == METEORSINPUT)
		str = "METEORSINPUT";
	else if (val == CHIOIELEM)
		str = "CHIOIELEM";
	else if (val == TIOCGPGRP)
		str = "TIOCGPGRP";
	else if (val == SNDCTL_DSP_GET_PLAYTGT_NAMES)
		str = "SNDCTL_DSP_GET_PLAYTGT_NAMES";
	else if (val == SIOCAUTHR)
		str = "SIOCAUTHR";
	else if (val == SIOCAUTHW)
		str = "SIOCAUTHW";
	else if (val == PIO_SCRNMAP)
		str = "PIO_SCRNMAP";
	else if (val == LPT_IRQ)
		str = "LPT_IRQ";
	else if (val == ACPIIO_ACKSLPSTATE)
		str = "ACPIIO_ACKSLPSTATE";
	else if (val == DEV_RESUME)
		str = "DEV_RESUME";
	else if (val == SNDCTL_MIDI_MPUCMD)
		str = "SNDCTL_MIDI_MPUCMD";
	else if (val == CONS_BELLTYPE)
		str = "CONS_BELLTYPE";
	else if (val == CUSE_IOCTL_ALLOC_UNIT)
		str = "CUSE_IOCTL_ALLOC_UNIT";
	else if (val == CONS_GETINFO)
		str = "CONS_GETINFO";
	else if (val == SW_VGA_CG640)
		str = "SW_VGA_CG640";
	else if (val == IPMICTL_RECEIVE_MSG)
		str = "IPMICTL_RECEIVE_MSG";
	else if (val == WDIOC_SETPRETIMEOUTACT)
		str = "WDIOC_SETPRETIMEOUTACT";
	else if (val == BIOCSBLEN)
		str = "BIOCSBLEN";
	else if (val == CUSE_IOCTL_WRITE_DATA)
		str = "CUSE_IOCTL_WRITE_DATA";
	else if (val == CCISS_REVALIDVOLS)
		str = "CCISS_REVALIDVOLS";
	else if (val == METEORGHWS)
		str = "METEORGHWS";
	else if (val == TIOCSCTTY)
		str = "TIOCSCTTY";
	else if (val == BIOCSHDRCMPLT)
		str = "BIOCSHDRCMPLT";
	else if (val == TIOCSTART)
		str = "TIOCSTART";
	else if (val == UFTDIIOC_SET_EVENT_CHAR)
		str = "UFTDIIOC_SET_EVENT_CHAR";
	else if (val == SW_VGA_C90x30)
		str = "SW_VGA_C90x30";
	else if (val == SMB_BWRITE)
		str = "SMB_BWRITE";
	else if (val == USB_SET_RX_TIMEOUT)
		str = "USB_SET_RX_TIMEOUT";
	else if (val == SIOCSIFMEDIA)
		str = "SIOCSIFMEDIA";
	else if (val == TIOCSETC)
		str = "TIOCSETC";
	else if (val == USB_GET_CM_OVER_DATA)
		str = "USB_GET_CM_OVER_DATA";
	else if (val == FBIOGXINFO)
		str = "FBIOGXINFO";
	else if (val == SIOCIPFINTERROR)
		str = "SIOCIPFINTERROR";
	else if (val == SNDCTL_MIDI_INFO)
		str = "SNDCTL_MIDI_INFO";
	else if (val == ALT_WRITE_TG_MEM)
		str = "ALT_WRITE_TG_MEM";
	else if (val == ENCIOC_INIT)
		str = "ENCIOC_INIT";
	else if (val == SIOCDIFPREFIX_IN6)
		str = "SIOCDIFPREFIX_IN6";
	else if (val == ENCIOC_GETSTRING)
		str = "ENCIOC_GETSTRING";
	else if (val == VT_GETINDEX)
		str = "VT_GETINDEX";
	else if (val == NGIOCSETNAME)
		str = "NGIOCSETNAME";
	else if (val == FBIO_GETMODE)
		str = "FBIO_GETMODE";
	else if (val == CHIOGSTATUS)
		str = "CHIOGSTATUS";
	else if (val == FW_GCROM)
		str = "FW_GCROM";
	else if (val == SIOCSDEFIFACE_IN6)
		str = "SIOCSDEFIFACE_IN6";
	else if (val == SIOCGHIWAT)
		str = "SIOCGHIWAT";
	else if (val == SNDCTL_DSP_MAPOUTBUF)
		str = "SNDCTL_DSP_MAPOUTBUF";
	else if (val == CUSE_IOCTL_SELWAKEUP)
		str = "CUSE_IOCTL_SELWAKEUP";
	else if (val == SNDCTL_FM_4OP_ENABLE)
		str = "SNDCTL_FM_4OP_ENABLE";
	else if (val == SG_GET_SCSI_ID)
		str = "SG_GET_SCSI_ID";
	else if (val == SIOCATMARK)
		str = "SIOCATMARK";
	else if (val == SIOCSSCOPE6)
		str = "SIOCSSCOPE6";
	else if (val == FBIOSCURSOR)
		str = "FBIOSCURSOR";
	else if (val == SIOCG80211STATS)
		str = "SIOCG80211STATS";
	else if (val == UFSRESUME)
		str = "UFSRESUME";
	else if (val == CONS_SAVERSTART)
		str = "CONS_SAVERSTART";
	else if (val == SW_VGA_C90x60)
		str = "SW_VGA_C90x60";
	else if (val == USB_SET_TX_BUFFER_SIZE)
		str = "USB_SET_TX_BUFFER_SIZE";
	else if (val == SIOCATMGVCCS)
		str = "SIOCATMGVCCS";
	else if (val == SIOCG80211)
		str = "SIOCG80211";
	else if (val == SMBIOC_LOOKUP)
		str = "SMBIOC_LOOKUP";
	else if (val == SG_GET_COMMAND_Q)
		str = "SG_GET_COMMAND_Q";
	else if (val == CONS_GET)
		str = "CONS_GET";
	else if (val == SW_VESA_800x600)
		str = "SW_VESA_800x600";
	else if (val == SNDCTL_SEQ_GETINCOUNT)
		str = "SNDCTL_SEQ_GETINCOUNT";
	else if (val == METEORGSUPPIXFMT)
		str = "METEORGSUPPIXFMT";
	else if (val == BIOCSETFNR)
		str = "BIOCSETFNR";
	else if (val == CONS_CURSORTYPE)
		str = "CONS_CURSORTYPE";
	else if (val == SNDCTL_SYNTH_MEMAVL)
		str = "SNDCTL_SYNTH_MEMAVL";
	else if (val == SG_GET_VERSION_NUM)
		str = "SG_GET_VERSION_NUM";
	else if (val == TVTUNER_GETAFC)
		str = "TVTUNER_GETAFC";
	else if (val == SIOCMATCHFLUSH)
		str = "SIOCMATCHFLUSH";
	else if (val == USB_FS_OPEN_STREAM)
		str = "USB_FS_OPEN_STREAM";
	else if (val == CONS_IDLE)
		str = "CONS_IDLE";
	else if (val == MOUSE_GETSTATUS)
		str = "MOUSE_GETSTATUS";
	else if (val == SIOCIPFFL)
		str = "SIOCIPFFL";
	else if (val == SIOCSIFRVNET)
		str = "SIOCSIFRVNET";
	else if (val == SW_PC98_80x30)
		str = "SW_PC98_80x30";
	else if (val == PIOCSTATUS)
		str = "PIOCSTATUS";
	else if (val == DIGIIO_REINIT)
		str = "DIGIIO_REINIT";
	else if (val == SIOCRMNAT)
		str = "SIOCRMNAT";
	else if (val == SG_EMULATED_HOST)
		str = "SG_EMULATED_HOST";
	else if (val == IOCATARAIDDELETE)
		str = "IOCATARAIDDELETE";
	else if (val == SIOCGIFMAC)
		str = "SIOCGIFMAC";
	else if (val == USB_DEV_QUIRK_ADD)
		str = "USB_DEV_QUIRK_ADD";
	else if (val == CUSE_IOCTL_SYNC_COMMAND)
		str = "CUSE_IOCTL_SYNC_COMMAND";
	else if (val == FSACTL_OPEN_ADAPTER_CONFIG)
		str = "FSACTL_OPEN_ADAPTER_CONFIG";
	else if (val == USB_GET_CONFIG)
		str = "USB_GET_CONFIG";
	else if (val == TIOCLBIC)
		str = "TIOCLBIC";
	else if (val == TIOCLBIS)
		str = "TIOCLBIS";
	else if (val == FBIOMONINFO)
		str = "FBIOMONINFO";
	else if (val == SIOCFRZST)
		str = "SIOCFRZST";
	else if (val == SIOCSLAGG)
		str = "SIOCSLAGG";
	else if (val == MTIOCHLOCATE)
		str = "MTIOCHLOCATE";
	else if (val == SNDCTL_DSP_GETCAPS)
		str = "SNDCTL_DSP_GETCAPS";
	else if (val == FIOSETOWN)
		str = "FIOSETOWN";
	else if (val == USB_FS_CLOSE)
		str = "USB_FS_CLOSE";
	else if (val == SIOCLOOKUPSTAT)
		str = "SIOCLOOKUPSTAT";
	else if (val == CDRIOCGETPROGRESS)
		str = "CDRIOCGETPROGRESS";
	else if (val == I2CSTART)
		str = "I2CSTART";
	else if (val == SNDCTL_DSP_SETSYNCRO)
		str = "SNDCTL_DSP_SETSYNCRO";
	else if (val == PPIGCTRL)
		str = "PPIGCTRL";
	else if (val == SMBIOC_READ)
		str = "SMBIOC_READ";
	else if (val == AUDITPIPE_GET_QLIMIT_MIN)
		str = "AUDITPIPE_GET_QLIMIT_MIN";
	else if (val == SNDCTL_DSP_POLICY)
		str = "SNDCTL_DSP_POLICY";
	else if (val == SIOCDIFPHYADDR)
		str = "SIOCDIFPHYADDR";
	else if (val == GIO_KEYMAPENT)
		str = "GIO_KEYMAPENT";
	else if (val == REMOTE_GETKEY)
		str = "REMOTE_GETKEY";
	else if (val == METEORSBT254)
		str = "METEORSBT254";
	else if (val == PPIGFIFO)
		str = "PPIGFIFO";
	else if (val == METEORGTS)
		str = "METEORGTS";
	else if (val == SOUND_PCM_READ_FILTER)
		str = "SOUND_PCM_READ_FILTER";
	else if (val == SIOCDIFADDR)
		str = "SIOCDIFADDR";
	else if (val == SIOCIPFL6)
		str = "SIOCIPFL6";
	else if (val == SNDCTL_FM_LOAD_INSTR)
		str = "SNDCTL_FM_LOAD_INSTR";
	else if (val == CUSE_IOCTL_SET_PFH)
		str = "CUSE_IOCTL_SET_PFH";
	else if (val == SIOCGIFMTU)
		str = "SIOCGIFMTU";
	else if (val == AIOGCAP)
		str = "AIOGCAP";
	else if (val == BIOCGDLT)
		str = "BIOCGDLT";
	else if (val == DEVFSIO_SAPPLY)
		str = "DEVFSIO_SAPPLY";
	else if (val == VT_ACTIVATE)
		str = "VT_ACTIVATE";
	else if (val == SIOCGLAGGPORT)
		str = "SIOCGLAGGPORT";
	else if (val == BT848GCBUF)
		str = "BT848GCBUF";
	else if (val == SIOCSIFPREFIX_IN6)
		str = "SIOCSIFPREFIX_IN6";
	else if (val == SG_GET_SG_TABLESIZE)
		str = "SG_GET_SG_TABLESIZE";
	else if (val == GPIOSET)
		str = "GPIOSET";
	else if (val == JOY_SETTIMEOUT)
		str = "JOY_SETTIMEOUT";
	else if (val == MTIOCEXTLOCATE)
		str = "MTIOCEXTLOCATE";
	else if (val == SW_VESA_1024x768)
		str = "SW_VESA_1024x768";
	else if (val == SIOCSHIWAT)
		str = "SIOCSHIWAT";
	else if (val == SIOCLOOKUPDELNODEW)
		str = "SIOCLOOKUPDELNODEW";
	else if (val == BIOCSRTIMEOUT)
		str = "BIOCSRTIMEOUT";
	else if (val == SIOCLOOKUPFLUSH)
		str = "SIOCLOOKUPFLUSH";
	else if (val == IOCATAGMAXCHANNEL)
		str = "IOCATAGMAXCHANNEL";
	else if (val == SW_CG320_D)
		str = "SW_CG320_D";
	else if (val == METEORSACTPIXFMT)
		str = "METEORSACTPIXFMT";
	else if (val == USB_GET_STRING_DESC)
		str = "USB_GET_STRING_DESC";
	else if (val == USB_FS_COMPLETE)
		str = "USB_FS_COMPLETE";
	else if (val == SNDCTL_COPR_RCODE)
		str = "SNDCTL_COPR_RCODE";
	else if (val == CHIOMOVE)
		str = "CHIOMOVE";
	else if (val == VT_OPENQRY)
		str = "VT_OPENQRY";
	else if (val == FW_GTSTREAM)
		str = "FW_GTSTREAM";
	else if (val == CCISS_GETFIRMVER)
		str = "CCISS_GETFIRMVER";
	else if (val == METEORGSIGNAL)
		str = "METEORGSIGNAL";
	else if (val == CDIOCSTOP)
		str = "CDIOCSTOP";
	else if (val == AGPIOC_UNBIND)
		str = "AGPIOC_UNBIND";
	else if (val == IOV_GET_SCHEMA)
		str = "IOV_GET_SCHEMA";
	else if (val == RADIO_GETMODE)
		str = "RADIO_GETMODE";
	else if (val == CFIOCSPLR)
		str = "CFIOCSPLR";
	else if (val == FBIOSATTR)
		str = "FBIOSATTR";
	else if (val == AGPIOC_CHIPSET_FLUSH)
		str = "AGPIOC_CHIPSET_FLUSH";
	else if (val == FBIOPUTCMAP)
		str = "FBIOPUTCMAP";
	else if (val == AUDITPIPE_GET_MAXAUDITDATA)
		str = "AUDITPIPE_GET_MAXAUDITDATA";
	else if (val == SIOCGDEFIFACE_IN6)
		str = "SIOCGDEFIFACE_IN6";
	else if (val == IOCATASSPINDOWN)
		str = "IOCATASSPINDOWN";
	else if (val == VT_GETACTIVE)
		str = "VT_GETACTIVE";
	else if (val == SOUND_PCM_READ_RATE)
		str = "SOUND_PCM_READ_RATE";
	else if (val == BIOCSETZBUF)
		str = "BIOCSETZBUF";
	else if (val == SMB_READB)
		str = "SMB_READB";
	else if (val == SNDCTL_SETLABEL)
		str = "SNDCTL_SETLABEL";
	else if (val == FSACTL_SEND_LARGE_FIB)
		str = "FSACTL_SEND_LARGE_FIB";
	else if (val == SIOCGPGRP)
		str = "SIOCGPGRP";
	else if (val == CONS_SSAVER)
		str = "CONS_SSAVER";
	else if (val == SMB_QUICK_WRITE)
		str = "SMB_QUICK_WRITE";
	else if (val == CAMGETPASSTHRU)
		str = "CAMGETPASSTHRU";
	else if (val == SNDCTL_DSP_GETIPEAKS)
		str = "SNDCTL_DSP_GETIPEAKS";
	else if (val == TVTUNER_GETCHNLSET)
		str = "TVTUNER_GETCHNLSET";
	else if (val == FSACTL_GET_FEATURES)
		str = "FSACTL_GET_FEATURES";
	else if (val == SNDCTL_DSP_GETBLKSIZE)
		str = "SNDCTL_DSP_GETBLKSIZE";
	else if (val == I2CSADDR)
		str = "I2CSADDR";
	else if (val == TIOCFLUSH)
		str = "TIOCFLUSH";
	else if (val == ALT_READ_TG_MEM)
		str = "ALT_READ_TG_MEM";
	else if (val == SIOCGIFPSRCADDR_IN6)
		str = "SIOCGIFPSRCADDR_IN6";
	else if (val == SIOCGIFNETMASK)
		str = "SIOCGIFNETMASK";
	else if (val == FBIO_MODEINFO)
		str = "FBIO_MODEINFO";
	else if (val == SIOCAIFADDR_IN6)
		str = "SIOCAIFADDR_IN6";
	else if (val == BIOCSTSTAMP)
		str = "BIOCSTSTAMP";
	else if (val == USB_GET_REPORT_ID)
		str = "USB_GET_REPORT_ID";
	else if (val == OFIOCGET)
		str = "OFIOCGET";
	else if (val == SW_VESA_32K_1280)
		str = "SW_VESA_32K_1280";
	else if (val == FIOCLEX)
		str = "FIOCLEX";
	else if (val == TVTUNER_GETSTATUS)
		str = "TVTUNER_GETSTATUS";
	else if (val == FBIO_SETPALETTE)
		str = "FBIO_SETPALETTE";
	else if (val == ENCIOC_GETELMDEVNAMES)
		str = "ENCIOC_GETELMDEVNAMES";
	else if (val == TARGIOCDEBUG)
		str = "TARGIOCDEBUG";
	else if (val == TIIOCGETSTATS)
		str = "TIIOCGETSTATS";
	else if (val == MTIOCTOP)
		str = "MTIOCTOP";
	else if (val == CIOCGSESSION)
		str = "CIOCGSESSION";
	else if (val == FBIOGCURMAX)
		str = "FBIOGCURMAX";
	else if (val == SIOCGIFSTATUS)
		str = "SIOCGIFSTATUS";
	else if (val == BIOCGRSIG)
		str = "BIOCGRSIG";
	else if (val == USB_SET_TX_STALL_FLAG)
		str = "USB_SET_TX_STALL_FLAG";
	else if (val == BT848_GUSAT)
		str = "BT848_GUSAT";
	else if (val == PPISDATA)
		str = "PPISDATA";
	else if (val == CCISS_GETQSTATS)
		str = "CCISS_GETQSTATS";
	else if (val == SNDCTL_COPR_SENDMSG)
		str = "SNDCTL_COPR_SENDMSG";
	else if (val == TUNSIFPID)
		str = "TUNSIFPID";
	else if (val == NANDFS_IOCTL_GET_BDESCS)
		str = "NANDFS_IOCTL_GET_BDESCS";
	else if (val == TAPSIFINFO)
		str = "TAPSIFINFO";
	else if (val == SNDCTL_DSP_SET_PLAYTGT)
		str = "SNDCTL_DSP_SET_PLAYTGT";
	else if (val == KDSETLED)
		str = "KDSETLED";
	else if (val == AUDITPIPE_GET_PRESELECT_NAFLAGS)
		str = "AUDITPIPE_GET_PRESELECT_NAFLAGS";
	else if (val == GRESPROTO)
		str = "GRESPROTO";
	else if (val == I2CSTOP)
		str = "I2CSTOP";
	else if (val == PPS_IOC_SETPARAMS)
		str = "PPS_IOC_SETPARAMS";
	else if (val == IPMICTL_UNREGISTER_FOR_CMD)
		str = "IPMICTL_UNREGISTER_FOR_CMD";
	else if (val == SNDCTL_COPR_RUN)
		str = "SNDCTL_COPR_RUN";
	else if (val == SNDCTL_COPR_WDATA)
		str = "SNDCTL_COPR_WDATA";
	else if (val == SIOCLOOKUPADDNODE)
		str = "SIOCLOOKUPADDNODE";
	else if (val == SNDCTL_SETSONG)
		str = "SNDCTL_SETSONG";
	else if (val == KDGETMODE)
		str = "KDGETMODE";
	else if (val == BIOCSDLT)
		str = "BIOCSDLT";
	else if (val == SIOCGIFGENERIC)
		str = "SIOCGIFGENERIC";
	else if (val == SNDCTL_COPR_LOAD)
		str = "SNDCTL_COPR_LOAD";
	else if (val == I2CRPTSTART)
		str = "I2CRPTSTART";
	else if (val == ENCIOC_GETNELM)
		str = "ENCIOC_GETNELM";
	else if (val == BT848_GPIO_GET_EN)
		str = "BT848_GPIO_GET_EN";
	else if (val == USB_GET_DEVICEINFO)
		str = "USB_GET_DEVICEINFO";
	else if (val == FSACTL_SIM_IO_TEST)
		str = "FSACTL_SIM_IO_TEST";
	else if (val == FBIO_SETWINORG)
		str = "FBIO_SETWINORG";
	else if (val == NANDFS_IOCTL_GET_SUINFO)
		str = "NANDFS_IOCTL_GET_SUINFO";
	else if (val == IPMICTL_REGISTER_FOR_CMD)
		str = "IPMICTL_REGISTER_FOR_CMD";
	else if (val == FD_GDTYPE)
		str = "FD_GDTYPE";
	else if (val == SIOCDIFGROUP)
		str = "SIOCDIFGROUP";
	else if (val == SNDCTL_DSP_GETOPTR)
		str = "SNDCTL_DSP_GETOPTR";
	else if (val == CUSE_IOCTL_ALLOC_MEMORY)
		str = "CUSE_IOCTL_ALLOC_MEMORY";
	else if (val == OFIOCNEXTPROP)
		str = "OFIOCNEXTPROP";
	else if (val == SIOCGIFINFO_IN6)
		str = "SIOCGIFINFO_IN6";
	else if (val == TIOCSETAW)
		str = "TIOCSETAW";
	else if (val == SIOCRMAFR)
		str = "SIOCRMAFR";
	else if (val == SIOCLOOKUPADDTABLE)
		str = "SIOCLOOKUPADDTABLE";
	else if (val == AGPIOC_DEALLOCATE)
		str = "AGPIOC_DEALLOCATE";
	else if (val == SNDCTL_DSP_NONBLOCK)
		str = "SNDCTL_DSP_NONBLOCK";
	else if (val == PIOCBIS)
		str = "PIOCBIS";
	else if (val == SW_VESA_FULL_1024)
		str = "SW_VESA_FULL_1024";
	else if (val == FD_READID)
		str = "FD_READID";
	else if (val == SIOCLOOKUPITER)
		str = "SIOCLOOKUPITER";

	if (str != NULL)
		printf("%s", str);
	else if (decimal)
		printf("%lu", val);
	else
		printf("%#lx", val);
}
