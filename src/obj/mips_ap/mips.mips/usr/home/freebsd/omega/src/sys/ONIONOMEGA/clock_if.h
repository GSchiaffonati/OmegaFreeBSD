/*
 * This file is produced automatically.
 * Do not modify anything in here by hand.
 *
 * Created from source file
 *   /usr/home/freebsd/omega/src/sys/kern/clock_if.m
 * with
 *   makeobjops.awk
 *
 * See the source file for legal information
 */


#ifndef _clock_if_h_
#define _clock_if_h_

/** @brief Unique descriptor for the CLOCK_GETTIME() method */
extern struct kobjop_desc clock_gettime_desc;
/** @brief A function implementing the CLOCK_GETTIME() method */
typedef int clock_gettime_t(device_t dev, struct timespec *ts);

static __inline int CLOCK_GETTIME(device_t dev, struct timespec *ts)
{
	kobjop_t _m;
	KOBJOPLOOKUP(((kobj_t)dev)->ops,clock_gettime);
	return ((clock_gettime_t *) _m)(dev, ts);
}

/** @brief Unique descriptor for the CLOCK_SETTIME() method */
extern struct kobjop_desc clock_settime_desc;
/** @brief A function implementing the CLOCK_SETTIME() method */
typedef int clock_settime_t(device_t dev, struct timespec *ts);

static __inline int CLOCK_SETTIME(device_t dev, struct timespec *ts)
{
	kobjop_t _m;
	KOBJOPLOOKUP(((kobj_t)dev)->ops,clock_settime);
	return ((clock_settime_t *) _m)(dev, ts);
}

#endif /* _clock_if_h_ */
