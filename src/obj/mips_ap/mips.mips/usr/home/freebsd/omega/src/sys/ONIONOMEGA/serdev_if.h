/*
 * This file is produced automatically.
 * Do not modify anything in here by hand.
 *
 * Created from source file
 *   /usr/home/freebsd/omega/src/sys/kern/serdev_if.m
 * with
 *   makeobjops.awk
 *
 * See the source file for legal information
 */


#ifndef _serdev_if_h_
#define _serdev_if_h_

/** @brief Unique descriptor for the SERDEV_IHAND() method */
extern struct kobjop_desc serdev_ihand_desc;
/** @brief A function implementing the SERDEV_IHAND() method */
typedef serdev_intr_t* serdev_ihand_t(device_t dev, int ipend);

static __inline serdev_intr_t* SERDEV_IHAND(device_t dev, int ipend)
{
	kobjop_t _m;
	KOBJOPLOOKUP(((kobj_t)dev)->ops,serdev_ihand);
	return ((serdev_ihand_t *) _m)(dev, ipend);
}

/** @brief Unique descriptor for the SERDEV_IPEND() method */
extern struct kobjop_desc serdev_ipend_desc;
/** @brief A function implementing the SERDEV_IPEND() method */
typedef int serdev_ipend_t(device_t dev);

static __inline int SERDEV_IPEND(device_t dev)
{
	kobjop_t _m;
	KOBJOPLOOKUP(((kobj_t)dev)->ops,serdev_ipend);
	return ((serdev_ipend_t *) _m)(dev);
}

/** @brief Unique descriptor for the SERDEV_SYSDEV() method */
extern struct kobjop_desc serdev_sysdev_desc;
/** @brief A function implementing the SERDEV_SYSDEV() method */
typedef int serdev_sysdev_t(device_t dev);

static __inline int SERDEV_SYSDEV(device_t dev)
{
	kobjop_t _m;
	KOBJOPLOOKUP(((kobj_t)dev)->ops,serdev_sysdev);
	return ((serdev_sysdev_t *) _m)(dev);
}

#endif /* _serdev_if_h_ */
