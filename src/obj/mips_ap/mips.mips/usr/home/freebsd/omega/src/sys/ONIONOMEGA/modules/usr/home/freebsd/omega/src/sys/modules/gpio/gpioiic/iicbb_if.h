/*
 * This file is produced automatically.
 * Do not modify anything in here by hand.
 *
 * Created from source file
 *   /usr/home/freebsd/omega/src/sys/dev/iicbus/iicbb_if.m
 * with
 *   makeobjops.awk
 *
 * See the source file for legal information
 */


#ifndef _iicbb_if_h_
#define _iicbb_if_h_

/** @brief Unique descriptor for the IICBB_CALLBACK() method */
extern struct kobjop_desc iicbb_callback_desc;
/** @brief A function implementing the IICBB_CALLBACK() method */
typedef int iicbb_callback_t(device_t dev, int index, caddr_t data);

static __inline int IICBB_CALLBACK(device_t dev, int index, caddr_t data)
{
	kobjop_t _m;
	KOBJOPLOOKUP(((kobj_t)dev)->ops,iicbb_callback);
	return ((iicbb_callback_t *) _m)(dev, index, data);
}

/** @brief Unique descriptor for the IICBB_PRE_XFER() method */
extern struct kobjop_desc iicbb_pre_xfer_desc;
/** @brief A function implementing the IICBB_PRE_XFER() method */
typedef int iicbb_pre_xfer_t(device_t dev);

static __inline int IICBB_PRE_XFER(device_t dev)
{
	kobjop_t _m;
	KOBJOPLOOKUP(((kobj_t)dev)->ops,iicbb_pre_xfer);
	return ((iicbb_pre_xfer_t *) _m)(dev);
}

/** @brief Unique descriptor for the IICBB_POST_XFER() method */
extern struct kobjop_desc iicbb_post_xfer_desc;
/** @brief A function implementing the IICBB_POST_XFER() method */
typedef void iicbb_post_xfer_t(device_t dev);

static __inline void IICBB_POST_XFER(device_t dev)
{
	kobjop_t _m;
	KOBJOPLOOKUP(((kobj_t)dev)->ops,iicbb_post_xfer);
	((iicbb_post_xfer_t *) _m)(dev);
}

/** @brief Unique descriptor for the IICBB_SETSDA() method */
extern struct kobjop_desc iicbb_setsda_desc;
/** @brief A function implementing the IICBB_SETSDA() method */
typedef void iicbb_setsda_t(device_t dev, int val);

static __inline void IICBB_SETSDA(device_t dev, int val)
{
	kobjop_t _m;
	KOBJOPLOOKUP(((kobj_t)dev)->ops,iicbb_setsda);
	((iicbb_setsda_t *) _m)(dev, val);
}

/** @brief Unique descriptor for the IICBB_SETSCL() method */
extern struct kobjop_desc iicbb_setscl_desc;
/** @brief A function implementing the IICBB_SETSCL() method */
typedef void iicbb_setscl_t(device_t dev, int val);

static __inline void IICBB_SETSCL(device_t dev, int val)
{
	kobjop_t _m;
	KOBJOPLOOKUP(((kobj_t)dev)->ops,iicbb_setscl);
	((iicbb_setscl_t *) _m)(dev, val);
}

/** @brief Unique descriptor for the IICBB_GETSDA() method */
extern struct kobjop_desc iicbb_getsda_desc;
/** @brief A function implementing the IICBB_GETSDA() method */
typedef int iicbb_getsda_t(device_t dev);

static __inline int IICBB_GETSDA(device_t dev)
{
	kobjop_t _m;
	KOBJOPLOOKUP(((kobj_t)dev)->ops,iicbb_getsda);
	return ((iicbb_getsda_t *) _m)(dev);
}

/** @brief Unique descriptor for the IICBB_GETSCL() method */
extern struct kobjop_desc iicbb_getscl_desc;
/** @brief A function implementing the IICBB_GETSCL() method */
typedef int iicbb_getscl_t(device_t dev);

static __inline int IICBB_GETSCL(device_t dev)
{
	kobjop_t _m;
	KOBJOPLOOKUP(((kobj_t)dev)->ops,iicbb_getscl);
	return ((iicbb_getscl_t *) _m)(dev);
}

/** @brief Unique descriptor for the IICBB_RESET() method */
extern struct kobjop_desc iicbb_reset_desc;
/** @brief A function implementing the IICBB_RESET() method */
typedef int iicbb_reset_t(device_t dev, u_char speed, u_char addr,
                          u_char *oldaddr);

static __inline int IICBB_RESET(device_t dev, u_char speed, u_char addr,
                                u_char *oldaddr)
{
	kobjop_t _m;
	KOBJOPLOOKUP(((kobj_t)dev)->ops,iicbb_reset);
	return ((iicbb_reset_t *) _m)(dev, speed, addr, oldaddr);
}

#endif /* _iicbb_if_h_ */
