/*
 * This file is produced automatically.
 * Do not modify anything in here by hand.
 *
 * Created from source file
 *   /usr/home/freebsd/omega/src/sys/dev/etherswitch/mdio_if.m
 * with
 *   makeobjops.awk
 *
 * See the source file for legal information
 */


#ifndef _mdio_if_h_
#define _mdio_if_h_

/** @brief Unique descriptor for the MDIO_READREG() method */
extern struct kobjop_desc mdio_readreg_desc;
/** @brief A function implementing the MDIO_READREG() method */
typedef int mdio_readreg_t(device_t dev, int phy, int reg);

static __inline int MDIO_READREG(device_t dev, int phy, int reg)
{
	kobjop_t _m;
	KOBJOPLOOKUP(((kobj_t)dev)->ops,mdio_readreg);
	return ((mdio_readreg_t *) _m)(dev, phy, reg);
}

/** @brief Unique descriptor for the MDIO_WRITEREG() method */
extern struct kobjop_desc mdio_writereg_desc;
/** @brief A function implementing the MDIO_WRITEREG() method */
typedef int mdio_writereg_t(device_t dev, int phy, int reg, int val);

static __inline int MDIO_WRITEREG(device_t dev, int phy, int reg, int val)
{
	kobjop_t _m;
	KOBJOPLOOKUP(((kobj_t)dev)->ops,mdio_writereg);
	return ((mdio_writereg_t *) _m)(dev, phy, reg, val);
}

#endif /* _mdio_if_h_ */
