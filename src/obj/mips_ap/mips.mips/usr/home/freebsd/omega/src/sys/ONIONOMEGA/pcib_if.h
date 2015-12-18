/*
 * This file is produced automatically.
 * Do not modify anything in here by hand.
 *
 * Created from source file
 *   /usr/home/freebsd/omega/src/sys/dev/pci/pcib_if.m
 * with
 *   makeobjops.awk
 *
 * See the source file for legal information
 */


#ifndef _pcib_if_h_
#define _pcib_if_h_

/** @brief Unique descriptor for the PCIB_MAXSLOTS() method */
extern struct kobjop_desc pcib_maxslots_desc;
/** @brief A function implementing the PCIB_MAXSLOTS() method */
typedef int pcib_maxslots_t(device_t dev);

static __inline int PCIB_MAXSLOTS(device_t dev)
{
	kobjop_t _m;
	KOBJOPLOOKUP(((kobj_t)dev)->ops,pcib_maxslots);
	return ((pcib_maxslots_t *) _m)(dev);
}

/** @brief Unique descriptor for the PCIB_MAXFUNCS() method */
extern struct kobjop_desc pcib_maxfuncs_desc;
/** @brief A function implementing the PCIB_MAXFUNCS() method */
typedef int pcib_maxfuncs_t(device_t dev);

static __inline int PCIB_MAXFUNCS(device_t dev)
{
	kobjop_t _m;
	KOBJOPLOOKUP(((kobj_t)dev)->ops,pcib_maxfuncs);
	return ((pcib_maxfuncs_t *) _m)(dev);
}

/** @brief Unique descriptor for the PCIB_READ_CONFIG() method */
extern struct kobjop_desc pcib_read_config_desc;
/** @brief A function implementing the PCIB_READ_CONFIG() method */
typedef u_int32_t pcib_read_config_t(device_t dev, u_int bus, u_int slot,
                                     u_int func, u_int reg, int width);

static __inline u_int32_t PCIB_READ_CONFIG(device_t dev, u_int bus, u_int slot,
                                           u_int func, u_int reg, int width)
{
	kobjop_t _m;
	KOBJOPLOOKUP(((kobj_t)dev)->ops,pcib_read_config);
	return ((pcib_read_config_t *) _m)(dev, bus, slot, func, reg, width);
}

/** @brief Unique descriptor for the PCIB_WRITE_CONFIG() method */
extern struct kobjop_desc pcib_write_config_desc;
/** @brief A function implementing the PCIB_WRITE_CONFIG() method */
typedef void pcib_write_config_t(device_t dev, u_int bus, u_int slot,
                                 u_int func, u_int reg, u_int32_t value,
                                 int width);

static __inline void PCIB_WRITE_CONFIG(device_t dev, u_int bus, u_int slot,
                                       u_int func, u_int reg, u_int32_t value,
                                       int width)
{
	kobjop_t _m;
	KOBJOPLOOKUP(((kobj_t)dev)->ops,pcib_write_config);
	((pcib_write_config_t *) _m)(dev, bus, slot, func, reg, value, width);
}

/** @brief Unique descriptor for the PCIB_ROUTE_INTERRUPT() method */
extern struct kobjop_desc pcib_route_interrupt_desc;
/** @brief A function implementing the PCIB_ROUTE_INTERRUPT() method */
typedef int pcib_route_interrupt_t(device_t pcib, device_t dev, int pin);

static __inline int PCIB_ROUTE_INTERRUPT(device_t pcib, device_t dev, int pin)
{
	kobjop_t _m;
	KOBJOPLOOKUP(((kobj_t)pcib)->ops,pcib_route_interrupt);
	return ((pcib_route_interrupt_t *) _m)(pcib, dev, pin);
}

/** @brief Unique descriptor for the PCIB_ALLOC_MSI() method */
extern struct kobjop_desc pcib_alloc_msi_desc;
/** @brief A function implementing the PCIB_ALLOC_MSI() method */
typedef int pcib_alloc_msi_t(device_t pcib, device_t dev, int count,
                             int maxcount, int *irqs);

static __inline int PCIB_ALLOC_MSI(device_t pcib, device_t dev, int count,
                                   int maxcount, int *irqs)
{
	kobjop_t _m;
	KOBJOPLOOKUP(((kobj_t)pcib)->ops,pcib_alloc_msi);
	return ((pcib_alloc_msi_t *) _m)(pcib, dev, count, maxcount, irqs);
}

/** @brief Unique descriptor for the PCIB_RELEASE_MSI() method */
extern struct kobjop_desc pcib_release_msi_desc;
/** @brief A function implementing the PCIB_RELEASE_MSI() method */
typedef int pcib_release_msi_t(device_t pcib, device_t dev, int count,
                               int *irqs);

static __inline int PCIB_RELEASE_MSI(device_t pcib, device_t dev, int count,
                                     int *irqs)
{
	kobjop_t _m;
	KOBJOPLOOKUP(((kobj_t)pcib)->ops,pcib_release_msi);
	return ((pcib_release_msi_t *) _m)(pcib, dev, count, irqs);
}

/** @brief Unique descriptor for the PCIB_ALLOC_MSIX() method */
extern struct kobjop_desc pcib_alloc_msix_desc;
/** @brief A function implementing the PCIB_ALLOC_MSIX() method */
typedef int pcib_alloc_msix_t(device_t pcib, device_t dev, int *irq);

static __inline int PCIB_ALLOC_MSIX(device_t pcib, device_t dev, int *irq)
{
	kobjop_t _m;
	KOBJOPLOOKUP(((kobj_t)pcib)->ops,pcib_alloc_msix);
	return ((pcib_alloc_msix_t *) _m)(pcib, dev, irq);
}

/** @brief Unique descriptor for the PCIB_RELEASE_MSIX() method */
extern struct kobjop_desc pcib_release_msix_desc;
/** @brief A function implementing the PCIB_RELEASE_MSIX() method */
typedef int pcib_release_msix_t(device_t pcib, device_t dev, int irq);

static __inline int PCIB_RELEASE_MSIX(device_t pcib, device_t dev, int irq)
{
	kobjop_t _m;
	KOBJOPLOOKUP(((kobj_t)pcib)->ops,pcib_release_msix);
	return ((pcib_release_msix_t *) _m)(pcib, dev, irq);
}

/** @brief Unique descriptor for the PCIB_MAP_MSI() method */
extern struct kobjop_desc pcib_map_msi_desc;
/** @brief A function implementing the PCIB_MAP_MSI() method */
typedef int pcib_map_msi_t(device_t pcib, device_t dev, int irq, uint64_t *addr,
                           uint32_t *data);

static __inline int PCIB_MAP_MSI(device_t pcib, device_t dev, int irq,
                                 uint64_t *addr, uint32_t *data)
{
	kobjop_t _m;
	KOBJOPLOOKUP(((kobj_t)pcib)->ops,pcib_map_msi);
	return ((pcib_map_msi_t *) _m)(pcib, dev, irq, addr, data);
}

/** @brief Unique descriptor for the PCIB_POWER_FOR_SLEEP() method */
extern struct kobjop_desc pcib_power_for_sleep_desc;
/** @brief A function implementing the PCIB_POWER_FOR_SLEEP() method */
typedef int pcib_power_for_sleep_t(device_t pcib, device_t dev, int *pstate);

static __inline int PCIB_POWER_FOR_SLEEP(device_t pcib, device_t dev,
                                         int *pstate)
{
	kobjop_t _m;
	KOBJOPLOOKUP(((kobj_t)pcib)->ops,pcib_power_for_sleep);
	return ((pcib_power_for_sleep_t *) _m)(pcib, dev, pstate);
}

/** @brief Unique descriptor for the PCIB_GET_RID() method */
extern struct kobjop_desc pcib_get_rid_desc;
/** @brief A function implementing the PCIB_GET_RID() method */
typedef uint16_t pcib_get_rid_t(device_t pcib, device_t dev);

static __inline uint16_t PCIB_GET_RID(device_t pcib, device_t dev)
{
	kobjop_t _m;
	KOBJOPLOOKUP(((kobj_t)pcib)->ops,pcib_get_rid);
	return ((pcib_get_rid_t *) _m)(pcib, dev);
}

/** @brief Unique descriptor for the PCIB_TRY_ENABLE_ARI() method */
extern struct kobjop_desc pcib_try_enable_ari_desc;
/** @brief A function implementing the PCIB_TRY_ENABLE_ARI() method */
typedef int pcib_try_enable_ari_t(device_t pcib, device_t dev);

static __inline int PCIB_TRY_ENABLE_ARI(device_t pcib, device_t dev)
{
	kobjop_t _m;
	KOBJOPLOOKUP(((kobj_t)pcib)->ops,pcib_try_enable_ari);
	return ((pcib_try_enable_ari_t *) _m)(pcib, dev);
}

/** @brief Unique descriptor for the PCIB_ARI_ENABLED() method */
extern struct kobjop_desc pcib_ari_enabled_desc;
/** @brief A function implementing the PCIB_ARI_ENABLED() method */
typedef int pcib_ari_enabled_t(device_t pcib);

static __inline int PCIB_ARI_ENABLED(device_t pcib)
{
	kobjop_t _m;
	KOBJOPLOOKUP(((kobj_t)pcib)->ops,pcib_ari_enabled);
	return ((pcib_ari_enabled_t *) _m)(pcib);
}

/** @brief Unique descriptor for the PCIB_DECODE_RID() method */
extern struct kobjop_desc pcib_decode_rid_desc;
/** @brief A function implementing the PCIB_DECODE_RID() method */
typedef void pcib_decode_rid_t(device_t pcib, uint16_t rid, int *bus, int *slot,
                               int *func);

static __inline void PCIB_DECODE_RID(device_t pcib, uint16_t rid, int *bus,
                                     int *slot, int *func)
{
	kobjop_t _m;
	KOBJOPLOOKUP(((kobj_t)pcib)->ops,pcib_decode_rid);
	((pcib_decode_rid_t *) _m)(pcib, rid, bus, slot, func);
}

#endif /* _pcib_if_h_ */
