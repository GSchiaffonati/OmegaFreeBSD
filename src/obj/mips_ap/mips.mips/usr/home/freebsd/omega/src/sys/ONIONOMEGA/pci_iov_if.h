/*
 * This file is produced automatically.
 * Do not modify anything in here by hand.
 *
 * Created from source file
 *   /usr/home/freebsd/omega/src/sys/dev/pci/pci_iov_if.m
 * with
 *   makeobjops.awk
 *
 * See the source file for legal information
 */


#ifndef _pci_iov_if_h_
#define _pci_iov_if_h_


struct nvlist;

/** @brief Unique descriptor for the PCI_IOV_INIT() method */
extern struct kobjop_desc pci_iov_init_desc;
/** @brief A function implementing the PCI_IOV_INIT() method */
typedef int pci_iov_init_t(device_t dev, uint16_t num_vfs,
                           const struct nvlist *config);

static __inline int PCI_IOV_INIT(device_t dev, uint16_t num_vfs,
                                 const struct nvlist *config)
{
	kobjop_t _m;
	KOBJOPLOOKUP(((kobj_t)dev)->ops,pci_iov_init);
	return ((pci_iov_init_t *) _m)(dev, num_vfs, config);
}

/** @brief Unique descriptor for the PCI_IOV_UNINIT() method */
extern struct kobjop_desc pci_iov_uninit_desc;
/** @brief A function implementing the PCI_IOV_UNINIT() method */
typedef void pci_iov_uninit_t(device_t dev);

static __inline void PCI_IOV_UNINIT(device_t dev)
{
	kobjop_t _m;
	KOBJOPLOOKUP(((kobj_t)dev)->ops,pci_iov_uninit);
	((pci_iov_uninit_t *) _m)(dev);
}

/** @brief Unique descriptor for the PCI_IOV_ADD_VF() method */
extern struct kobjop_desc pci_iov_add_vf_desc;
/** @brief A function implementing the PCI_IOV_ADD_VF() method */
typedef int pci_iov_add_vf_t(device_t dev, uint16_t vfnum,
                             const struct nvlist *config);

static __inline int PCI_IOV_ADD_VF(device_t dev, uint16_t vfnum,
                                   const struct nvlist *config)
{
	kobjop_t _m;
	KOBJOPLOOKUP(((kobj_t)dev)->ops,pci_iov_add_vf);
	return ((pci_iov_add_vf_t *) _m)(dev, vfnum, config);
}

#endif /* _pci_iov_if_h_ */
