/*
 * This file is produced automatically.
 * Do not modify anything in here by hand.
 *
 * Created from source file
 *   /usr/home/freebsd/omega/src/sys/dev/fb/fb_if.m
 * with
 *   makeobjops.awk
 *
 * See the source file for legal information
 */


#ifndef _fb_if_h_
#define _fb_if_h_

/** @brief Unique descriptor for the FB_PIN_MAX() method */
extern struct kobjop_desc fb_pin_max_desc;
/** @brief A function implementing the FB_PIN_MAX() method */
typedef int fb_pin_max_t(device_t dev, int *npins);

static __inline int FB_PIN_MAX(device_t dev, int *npins)
{
	kobjop_t _m;
	KOBJOPLOOKUP(((kobj_t)dev)->ops,fb_pin_max);
	return ((fb_pin_max_t *) _m)(dev, npins);
}

/** @brief Unique descriptor for the FB_GETINFO() method */
extern struct kobjop_desc fb_getinfo_desc;
/** @brief A function implementing the FB_GETINFO() method */
typedef struct fb_info * fb_getinfo_t(device_t dev);

static __inline struct fb_info * FB_GETINFO(device_t dev)
{
	kobjop_t _m;
	KOBJOPLOOKUP(((kobj_t)dev)->ops,fb_getinfo);
	return ((fb_getinfo_t *) _m)(dev);
}

#endif /* _fb_if_h_ */
