/*
 * This file is produced automatically.
 * Do not modify anything in here by hand.
 *
 * Created from source file
 *   /usr/home/freebsd/omega/src/sys/dev/etherswitch/etherswitch_if.m
 * with
 *   makeobjops.awk
 *
 * See the source file for legal information
 */


#ifndef _etherswitch_if_h_
#define _etherswitch_if_h_

/** @brief Unique descriptor for the ETHERSWITCH_GETINFO() method */
extern struct kobjop_desc etherswitch_getinfo_desc;
/** @brief A function implementing the ETHERSWITCH_GETINFO() method */
typedef etherswitch_info_t* etherswitch_getinfo_t(device_t dev);

static __inline etherswitch_info_t* ETHERSWITCH_GETINFO(device_t dev)
{
	kobjop_t _m;
	KOBJOPLOOKUP(((kobj_t)dev)->ops,etherswitch_getinfo);
	return ((etherswitch_getinfo_t *) _m)(dev);
}

/** @brief Unique descriptor for the ETHERSWITCH_LOCK() method */
extern struct kobjop_desc etherswitch_lock_desc;
/** @brief A function implementing the ETHERSWITCH_LOCK() method */
typedef void etherswitch_lock_t(device_t dev);

static __inline void ETHERSWITCH_LOCK(device_t dev)
{
	kobjop_t _m;
	KOBJOPLOOKUP(((kobj_t)dev)->ops,etherswitch_lock);
	((etherswitch_lock_t *) _m)(dev);
}

/** @brief Unique descriptor for the ETHERSWITCH_UNLOCK() method */
extern struct kobjop_desc etherswitch_unlock_desc;
/** @brief A function implementing the ETHERSWITCH_UNLOCK() method */
typedef void etherswitch_unlock_t(device_t dev);

static __inline void ETHERSWITCH_UNLOCK(device_t dev)
{
	kobjop_t _m;
	KOBJOPLOOKUP(((kobj_t)dev)->ops,etherswitch_unlock);
	((etherswitch_unlock_t *) _m)(dev);
}

/** @brief Unique descriptor for the ETHERSWITCH_READREG() method */
extern struct kobjop_desc etherswitch_readreg_desc;
/** @brief A function implementing the ETHERSWITCH_READREG() method */
typedef int etherswitch_readreg_t(device_t dev, int reg);

static __inline int ETHERSWITCH_READREG(device_t dev, int reg)
{
	kobjop_t _m;
	KOBJOPLOOKUP(((kobj_t)dev)->ops,etherswitch_readreg);
	return ((etherswitch_readreg_t *) _m)(dev, reg);
}

/** @brief Unique descriptor for the ETHERSWITCH_WRITEREG() method */
extern struct kobjop_desc etherswitch_writereg_desc;
/** @brief A function implementing the ETHERSWITCH_WRITEREG() method */
typedef int etherswitch_writereg_t(device_t dev, int reg, int value);

static __inline int ETHERSWITCH_WRITEREG(device_t dev, int reg, int value)
{
	kobjop_t _m;
	KOBJOPLOOKUP(((kobj_t)dev)->ops,etherswitch_writereg);
	return ((etherswitch_writereg_t *) _m)(dev, reg, value);
}

/** @brief Unique descriptor for the ETHERSWITCH_READPHYREG() method */
extern struct kobjop_desc etherswitch_readphyreg_desc;
/** @brief A function implementing the ETHERSWITCH_READPHYREG() method */
typedef int etherswitch_readphyreg_t(device_t dev, int phy, int reg);

static __inline int ETHERSWITCH_READPHYREG(device_t dev, int phy, int reg)
{
	kobjop_t _m;
	KOBJOPLOOKUP(((kobj_t)dev)->ops,etherswitch_readphyreg);
	return ((etherswitch_readphyreg_t *) _m)(dev, phy, reg);
}

/** @brief Unique descriptor for the ETHERSWITCH_WRITEPHYREG() method */
extern struct kobjop_desc etherswitch_writephyreg_desc;
/** @brief A function implementing the ETHERSWITCH_WRITEPHYREG() method */
typedef int etherswitch_writephyreg_t(device_t dev, int phy, int reg,
                                      int value);

static __inline int ETHERSWITCH_WRITEPHYREG(device_t dev, int phy, int reg,
                                            int value)
{
	kobjop_t _m;
	KOBJOPLOOKUP(((kobj_t)dev)->ops,etherswitch_writephyreg);
	return ((etherswitch_writephyreg_t *) _m)(dev, phy, reg, value);
}

/** @brief Unique descriptor for the ETHERSWITCH_GETPORT() method */
extern struct kobjop_desc etherswitch_getport_desc;
/** @brief A function implementing the ETHERSWITCH_GETPORT() method */
typedef int etherswitch_getport_t(device_t dev, etherswitch_port_t *vg);

static __inline int ETHERSWITCH_GETPORT(device_t dev, etherswitch_port_t *vg)
{
	kobjop_t _m;
	KOBJOPLOOKUP(((kobj_t)dev)->ops,etherswitch_getport);
	return ((etherswitch_getport_t *) _m)(dev, vg);
}

/** @brief Unique descriptor for the ETHERSWITCH_SETPORT() method */
extern struct kobjop_desc etherswitch_setport_desc;
/** @brief A function implementing the ETHERSWITCH_SETPORT() method */
typedef int etherswitch_setport_t(device_t dev, etherswitch_port_t *vg);

static __inline int ETHERSWITCH_SETPORT(device_t dev, etherswitch_port_t *vg)
{
	kobjop_t _m;
	KOBJOPLOOKUP(((kobj_t)dev)->ops,etherswitch_setport);
	return ((etherswitch_setport_t *) _m)(dev, vg);
}

/** @brief Unique descriptor for the ETHERSWITCH_GETVGROUP() method */
extern struct kobjop_desc etherswitch_getvgroup_desc;
/** @brief A function implementing the ETHERSWITCH_GETVGROUP() method */
typedef int etherswitch_getvgroup_t(device_t dev, etherswitch_vlangroup_t *vg);

static __inline int ETHERSWITCH_GETVGROUP(device_t dev,
                                          etherswitch_vlangroup_t *vg)
{
	kobjop_t _m;
	KOBJOPLOOKUP(((kobj_t)dev)->ops,etherswitch_getvgroup);
	return ((etherswitch_getvgroup_t *) _m)(dev, vg);
}

/** @brief Unique descriptor for the ETHERSWITCH_SETVGROUP() method */
extern struct kobjop_desc etherswitch_setvgroup_desc;
/** @brief A function implementing the ETHERSWITCH_SETVGROUP() method */
typedef int etherswitch_setvgroup_t(device_t dev, etherswitch_vlangroup_t *vg);

static __inline int ETHERSWITCH_SETVGROUP(device_t dev,
                                          etherswitch_vlangroup_t *vg)
{
	kobjop_t _m;
	KOBJOPLOOKUP(((kobj_t)dev)->ops,etherswitch_setvgroup);
	return ((etherswitch_setvgroup_t *) _m)(dev, vg);
}

/** @brief Unique descriptor for the ETHERSWITCH_GETCONF() method */
extern struct kobjop_desc etherswitch_getconf_desc;
/** @brief A function implementing the ETHERSWITCH_GETCONF() method */
typedef int etherswitch_getconf_t(device_t dev, etherswitch_conf_t *conf);

static __inline int ETHERSWITCH_GETCONF(device_t dev, etherswitch_conf_t *conf)
{
	kobjop_t _m;
	KOBJOPLOOKUP(((kobj_t)dev)->ops,etherswitch_getconf);
	return ((etherswitch_getconf_t *) _m)(dev, conf);
}

/** @brief Unique descriptor for the ETHERSWITCH_SETCONF() method */
extern struct kobjop_desc etherswitch_setconf_desc;
/** @brief A function implementing the ETHERSWITCH_SETCONF() method */
typedef int etherswitch_setconf_t(device_t dev, etherswitch_conf_t *conf);

static __inline int ETHERSWITCH_SETCONF(device_t dev, etherswitch_conf_t *conf)
{
	kobjop_t _m;
	KOBJOPLOOKUP(((kobj_t)dev)->ops,etherswitch_setconf);
	return ((etherswitch_setconf_t *) _m)(dev, conf);
}

#endif /* _etherswitch_if_h_ */
