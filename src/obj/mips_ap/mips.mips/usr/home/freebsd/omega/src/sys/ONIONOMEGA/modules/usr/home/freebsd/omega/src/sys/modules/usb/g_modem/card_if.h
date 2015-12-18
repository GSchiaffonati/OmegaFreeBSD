/*
 * This file is produced automatically.
 * Do not modify anything in here by hand.
 *
 * Created from source file
 *   /usr/home/freebsd/omega/src/sys/dev/pccard/card_if.m
 * with
 *   makeobjops.awk
 *
 * See the source file for legal information
 */


#ifndef _card_if_h_
#define _card_if_h_

/** @brief Unique descriptor for the CARD_SET_RES_FLAGS() method */
extern struct kobjop_desc card_set_res_flags_desc;
/** @brief A function implementing the CARD_SET_RES_FLAGS() method */
typedef int card_set_res_flags_t(device_t dev, device_t child, int restype,
                                 int rid, u_long value);

static __inline int CARD_SET_RES_FLAGS(device_t dev, device_t child,
                                       int restype, int rid, u_long value)
{
	kobjop_t _m;
	KOBJOPLOOKUP(((kobj_t)dev)->ops,card_set_res_flags);
	return ((card_set_res_flags_t *) _m)(dev, child, restype, rid, value);
}

/** @brief Unique descriptor for the CARD_GET_RES_FLAGS() method */
extern struct kobjop_desc card_get_res_flags_desc;
/** @brief A function implementing the CARD_GET_RES_FLAGS() method */
typedef int card_get_res_flags_t(device_t dev, device_t child, int restype,
                                 int rid, u_long *value);

static __inline int CARD_GET_RES_FLAGS(device_t dev, device_t child,
                                       int restype, int rid, u_long *value)
{
	kobjop_t _m;
	KOBJOPLOOKUP(((kobj_t)dev)->ops,card_get_res_flags);
	return ((card_get_res_flags_t *) _m)(dev, child, restype, rid, value);
}

/** @brief Unique descriptor for the CARD_SET_MEMORY_OFFSET() method */
extern struct kobjop_desc card_set_memory_offset_desc;
/** @brief A function implementing the CARD_SET_MEMORY_OFFSET() method */
typedef int card_set_memory_offset_t(device_t dev, device_t child, int rid,
                                     uint32_t cardaddr, uint32_t *deltap);

static __inline int CARD_SET_MEMORY_OFFSET(device_t dev, device_t child,
                                           int rid, uint32_t cardaddr,
                                           uint32_t *deltap)
{
	kobjop_t _m;
	KOBJOPLOOKUP(((kobj_t)dev)->ops,card_set_memory_offset);
	return ((card_set_memory_offset_t *) _m)(dev, child, rid, cardaddr, deltap);
}

/** @brief Unique descriptor for the CARD_GET_MEMORY_OFFSET() method */
extern struct kobjop_desc card_get_memory_offset_desc;
/** @brief A function implementing the CARD_GET_MEMORY_OFFSET() method */
typedef int card_get_memory_offset_t(device_t dev, device_t child, int rid,
                                     uint32_t *offset);

static __inline int CARD_GET_MEMORY_OFFSET(device_t dev, device_t child,
                                           int rid, uint32_t *offset)
{
	kobjop_t _m;
	KOBJOPLOOKUP(((kobj_t)dev)->ops,card_get_memory_offset);
	return ((card_get_memory_offset_t *) _m)(dev, child, rid, offset);
}

/** @brief Unique descriptor for the CARD_ATTACH_CARD() method */
extern struct kobjop_desc card_attach_card_desc;
/** @brief A function implementing the CARD_ATTACH_CARD() method */
typedef int card_attach_card_t(device_t dev);

static __inline int CARD_ATTACH_CARD(device_t dev)
{
	kobjop_t _m;
	KOBJOPLOOKUP(((kobj_t)dev)->ops,card_attach_card);
	return ((card_attach_card_t *) _m)(dev);
}

/** @brief Unique descriptor for the CARD_DETACH_CARD() method */
extern struct kobjop_desc card_detach_card_desc;
/** @brief A function implementing the CARD_DETACH_CARD() method */
typedef int card_detach_card_t(device_t dev);

static __inline int CARD_DETACH_CARD(device_t dev)
{
	kobjop_t _m;
	KOBJOPLOOKUP(((kobj_t)dev)->ops,card_detach_card);
	return ((card_detach_card_t *) _m)(dev);
}

/** @brief Unique descriptor for the CARD_DO_PRODUCT_LOOKUP() method */
extern struct kobjop_desc card_do_product_lookup_desc;
/** @brief A function implementing the CARD_DO_PRODUCT_LOOKUP() method */
typedef const struct pccard_product * card_do_product_lookup_t(device_t bus,
                                                               device_t dev,
                                                               const struct pccard_product *tab, size_t ent_size, pccard_product_match_fn matchfn);

static __inline const struct pccard_product * CARD_DO_PRODUCT_LOOKUP(device_t bus, device_t dev, const struct pccard_product *tab, size_t ent_size, pccard_product_match_fn matchfn)
{
	kobjop_t _m;
	KOBJOPLOOKUP(((kobj_t)bus)->ops,card_do_product_lookup);
	return ((card_do_product_lookup_t *) _m)(bus, dev, tab, ent_size, matchfn);
}

/** @brief Unique descriptor for the CARD_CIS_SCAN() method */
extern struct kobjop_desc card_cis_scan_desc;
/** @brief A function implementing the CARD_CIS_SCAN() method */
typedef int card_cis_scan_t(device_t bus, device_t dev, pccard_scan_t fnp,
                            void *argp);

static __inline int CARD_CIS_SCAN(device_t bus, device_t dev, pccard_scan_t fnp,
                                  void *argp)
{
	kobjop_t _m;
	KOBJOPLOOKUP(((kobj_t)bus)->ops,card_cis_scan);
	return ((card_cis_scan_t *) _m)(bus, dev, fnp, argp);
}

/** @brief Unique descriptor for the CARD_ATTR_READ() method */
extern struct kobjop_desc card_attr_read_desc;
/** @brief A function implementing the CARD_ATTR_READ() method */
typedef int card_attr_read_t(device_t bus, device_t dev, uint32_t offset,
                             uint8_t *val);

static __inline int CARD_ATTR_READ(device_t bus, device_t dev, uint32_t offset,
                                   uint8_t *val)
{
	kobjop_t _m;
	KOBJOPLOOKUP(((kobj_t)bus)->ops,card_attr_read);
	return ((card_attr_read_t *) _m)(bus, dev, offset, val);
}

/** @brief Unique descriptor for the CARD_ATTR_WRITE() method */
extern struct kobjop_desc card_attr_write_desc;
/** @brief A function implementing the CARD_ATTR_WRITE() method */
typedef int card_attr_write_t(device_t bus, device_t dev, uint32_t offset,
                              uint8_t val);

static __inline int CARD_ATTR_WRITE(device_t bus, device_t dev, uint32_t offset,
                                    uint8_t val)
{
	kobjop_t _m;
	KOBJOPLOOKUP(((kobj_t)bus)->ops,card_attr_write);
	return ((card_attr_write_t *) _m)(bus, dev, offset, val);
}

/** @brief Unique descriptor for the CARD_CCR_READ() method */
extern struct kobjop_desc card_ccr_read_desc;
/** @brief A function implementing the CARD_CCR_READ() method */
typedef int card_ccr_read_t(device_t bus, device_t dev, uint32_t offset,
                            uint8_t *val);

static __inline int CARD_CCR_READ(device_t bus, device_t dev, uint32_t offset,
                                  uint8_t *val)
{
	kobjop_t _m;
	KOBJOPLOOKUP(((kobj_t)bus)->ops,card_ccr_read);
	return ((card_ccr_read_t *) _m)(bus, dev, offset, val);
}

/** @brief Unique descriptor for the CARD_CCR_WRITE() method */
extern struct kobjop_desc card_ccr_write_desc;
/** @brief A function implementing the CARD_CCR_WRITE() method */
typedef int card_ccr_write_t(device_t bus, device_t dev, uint32_t offset,
                             uint8_t val);

static __inline int CARD_CCR_WRITE(device_t bus, device_t dev, uint32_t offset,
                                   uint8_t val)
{
	kobjop_t _m;
	KOBJOPLOOKUP(((kobj_t)bus)->ops,card_ccr_write);
	return ((card_ccr_write_t *) _m)(bus, dev, offset, val);
}

#endif /* _card_if_h_ */
