/*
 * This file is produced automatically.
 * Do not modify anything in here by hand.
 *
 * Created from source file
 *   /usr/home/freebsd/omega/src/sys/dev/uart/uart_if.m
 * with
 *   makeobjops.awk
 *
 * See the source file for legal information
 */


#ifndef _uart_if_h_
#define _uart_if_h_

/** @brief Unique descriptor for the UART_ATTACH() method */
extern struct kobjop_desc uart_attach_desc;
/** @brief A function implementing the UART_ATTACH() method */
typedef int uart_attach_t(struct uart_softc *this);

static __inline int UART_ATTACH(struct uart_softc *this)
{
	kobjop_t _m;
	KOBJOPLOOKUP(((kobj_t)this)->ops,uart_attach);
	return ((uart_attach_t *) _m)(this);
}

/** @brief Unique descriptor for the UART_DETACH() method */
extern struct kobjop_desc uart_detach_desc;
/** @brief A function implementing the UART_DETACH() method */
typedef int uart_detach_t(struct uart_softc *this);

static __inline int UART_DETACH(struct uart_softc *this)
{
	kobjop_t _m;
	KOBJOPLOOKUP(((kobj_t)this)->ops,uart_detach);
	return ((uart_detach_t *) _m)(this);
}

/** @brief Unique descriptor for the UART_FLUSH() method */
extern struct kobjop_desc uart_flush_desc;
/** @brief A function implementing the UART_FLUSH() method */
typedef int uart_flush_t(struct uart_softc *this, int what);

static __inline int UART_FLUSH(struct uart_softc *this, int what)
{
	kobjop_t _m;
	KOBJOPLOOKUP(((kobj_t)this)->ops,uart_flush);
	return ((uart_flush_t *) _m)(this, what);
}

/** @brief Unique descriptor for the UART_GETSIG() method */
extern struct kobjop_desc uart_getsig_desc;
/** @brief A function implementing the UART_GETSIG() method */
typedef int uart_getsig_t(struct uart_softc *this);

static __inline int UART_GETSIG(struct uart_softc *this)
{
	kobjop_t _m;
	KOBJOPLOOKUP(((kobj_t)this)->ops,uart_getsig);
	return ((uart_getsig_t *) _m)(this);
}

/** @brief Unique descriptor for the UART_IOCTL() method */
extern struct kobjop_desc uart_ioctl_desc;
/** @brief A function implementing the UART_IOCTL() method */
typedef int uart_ioctl_t(struct uart_softc *this, int request, intptr_t data);

static __inline int UART_IOCTL(struct uart_softc *this, int request,
                               intptr_t data)
{
	kobjop_t _m;
	KOBJOPLOOKUP(((kobj_t)this)->ops,uart_ioctl);
	return ((uart_ioctl_t *) _m)(this, request, data);
}

/** @brief Unique descriptor for the UART_IPEND() method */
extern struct kobjop_desc uart_ipend_desc;
/** @brief A function implementing the UART_IPEND() method */
typedef int uart_ipend_t(struct uart_softc *this);

static __inline int UART_IPEND(struct uart_softc *this)
{
	kobjop_t _m;
	KOBJOPLOOKUP(((kobj_t)this)->ops,uart_ipend);
	return ((uart_ipend_t *) _m)(this);
}

/** @brief Unique descriptor for the UART_PARAM() method */
extern struct kobjop_desc uart_param_desc;
/** @brief A function implementing the UART_PARAM() method */
typedef int uart_param_t(struct uart_softc *this, int baudrate, int databits,
                         int stopbits, int parity);

static __inline int UART_PARAM(struct uart_softc *this, int baudrate,
                               int databits, int stopbits, int parity)
{
	kobjop_t _m;
	KOBJOPLOOKUP(((kobj_t)this)->ops,uart_param);
	return ((uart_param_t *) _m)(this, baudrate, databits, stopbits, parity);
}

/** @brief Unique descriptor for the UART_PROBE() method */
extern struct kobjop_desc uart_probe_desc;
/** @brief A function implementing the UART_PROBE() method */
typedef int uart_probe_t(struct uart_softc *this);

static __inline int UART_PROBE(struct uart_softc *this)
{
	kobjop_t _m;
	KOBJOPLOOKUP(((kobj_t)this)->ops,uart_probe);
	return ((uart_probe_t *) _m)(this);
}

/** @brief Unique descriptor for the UART_RECEIVE() method */
extern struct kobjop_desc uart_receive_desc;
/** @brief A function implementing the UART_RECEIVE() method */
typedef int uart_receive_t(struct uart_softc *this);

static __inline int UART_RECEIVE(struct uart_softc *this)
{
	kobjop_t _m;
	KOBJOPLOOKUP(((kobj_t)this)->ops,uart_receive);
	return ((uart_receive_t *) _m)(this);
}

/** @brief Unique descriptor for the UART_SETSIG() method */
extern struct kobjop_desc uart_setsig_desc;
/** @brief A function implementing the UART_SETSIG() method */
typedef int uart_setsig_t(struct uart_softc *this, int sig);

static __inline int UART_SETSIG(struct uart_softc *this, int sig)
{
	kobjop_t _m;
	KOBJOPLOOKUP(((kobj_t)this)->ops,uart_setsig);
	return ((uart_setsig_t *) _m)(this, sig);
}

/** @brief Unique descriptor for the UART_TRANSMIT() method */
extern struct kobjop_desc uart_transmit_desc;
/** @brief A function implementing the UART_TRANSMIT() method */
typedef int uart_transmit_t(struct uart_softc *this);

static __inline int UART_TRANSMIT(struct uart_softc *this)
{
	kobjop_t _m;
	KOBJOPLOOKUP(((kobj_t)this)->ops,uart_transmit);
	return ((uart_transmit_t *) _m)(this);
}

/** @brief Unique descriptor for the UART_GRAB() method */
extern struct kobjop_desc uart_grab_desc;
/** @brief A function implementing the UART_GRAB() method */
typedef void uart_grab_t(struct uart_softc *this);

static __inline void UART_GRAB(struct uart_softc *this)
{
	kobjop_t _m;
	KOBJOPLOOKUP(((kobj_t)this)->ops,uart_grab);
	((uart_grab_t *) _m)(this);
}

/** @brief Unique descriptor for the UART_UNGRAB() method */
extern struct kobjop_desc uart_ungrab_desc;
/** @brief A function implementing the UART_UNGRAB() method */
typedef void uart_ungrab_t(struct uart_softc *this);

static __inline void UART_UNGRAB(struct uart_softc *this)
{
	kobjop_t _m;
	KOBJOPLOOKUP(((kobj_t)this)->ops,uart_ungrab);
	((uart_ungrab_t *) _m)(this);
}

#endif /* _uart_if_h_ */
