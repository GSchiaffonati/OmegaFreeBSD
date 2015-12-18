/*
 * This file is produced automatically.
 * Do not modify anything in here by hand.
 *
 * Created from source file
 *   /usr/home/freebsd/omega/src/sys/dev/spibus/spibus_if.m
 * with
 *   makeobjops.awk
 *
 * See the source file for legal information
 */


#ifndef _spibus_if_h_
#define _spibus_if_h_

/** @brief Unique descriptor for the SPIBUS_TRANSFER() method */
extern struct kobjop_desc spibus_transfer_desc;
/** @brief A function implementing the SPIBUS_TRANSFER() method */
typedef int spibus_transfer_t(device_t dev, device_t child,
                              struct spi_command *cmd);

static __inline int SPIBUS_TRANSFER(device_t dev, device_t child,
                                    struct spi_command *cmd)
{
	kobjop_t _m;
	KOBJOPLOOKUP(((kobj_t)dev)->ops,spibus_transfer);
	return ((spibus_transfer_t *) _m)(dev, child, cmd);
}

#endif /* _spibus_if_h_ */
