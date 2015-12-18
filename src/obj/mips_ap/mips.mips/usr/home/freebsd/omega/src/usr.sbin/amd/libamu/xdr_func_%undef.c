/*
 * Copyright (c) 1997-2006 Erez Zadok
 * Copyright (c) 1990 Jan-Simon Pendry
 * Copyright (c) 1990 Imperial College of Science, Technology & Medicine
 * Copyright (c) 1990 The Regents of the University of California.
 * All rights reserved.
 *
 * This code is derived from software contributed to Berkeley by
 * Jan-Simon Pendry at Imperial College, London.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgment:
 *      This product includes software developed by the University of
 *      California, Berkeley and its contributors.
 * 4. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 *
 * File: am-utils/libamu/xdr_func.c
 *
 */

/*
 * Complete list of all possible xdr functions which may be needed.
 */
#ifdef HAVE_CONFIG_H
# include <config.h>
#endif /* HAVE_CONFIG_H */
#include <am_defs.h>
#include <amu.h>

#ifdef __RPCSVC_MOUNT_H__
# error IRIX6 should not include rpcsvc/mount.h
#endif /* __RPCSVC_MOUNT_H__ */

/*
 * MACROS:
 */
#ifdef HAVE_FS_AUTOFS
# ifndef AUTOFS_MAXCOMPONENTLEN
#  define AUTOFS_MAXCOMPONENTLEN 255
# endif /* not AUTOFS_MAXCOMPONENTLEN */
# ifndef AUTOFS_MAXOPTSLEN
#  define AUTOFS_MAXOPTSLEN 255
# endif /* not AUTOFS_MAXOPTSLEN */
# ifndef AUTOFS_MAXPATHLEN
#  define AUTOFS_MAXPATHLEN 1024
# endif /* not AUTOFS_MAXPATHLEN */
#endif /* HAVE_FS_AUTOFS */

/* forward definitions, are they needed? */
extern bool_t xdr_exportnode(XDR *xdrs, exportnode *objp);
extern bool_t xdr_groupnode(XDR *xdrs, groupnode *objp);
extern bool_t xdr_name(XDR *xdrs, name *objp);


















































































/*
 * NFS V3 XDR FUNCTIONS:
 */
#ifdef HAVE_FS_NFS3
bool_t
xdr_am_fhandle3(XDR *xdrs, am_fhandle3 *objp)
{
  if (amuDebug(D_XDRTRACE))
    plog(XLOG_DEBUG, "xdr_am_fhandle3:");

  if (!xdr_bytes(xdrs,
		 (char **) &objp->fhandle3_val,
		 (u_int *) &objp->fhandle3_len,
		 AM_FHSIZE3))
    return (FALSE);
  return (TRUE);
}


bool_t
xdr_am_mountstat3(XDR *xdrs, am_mountstat3 *objp)
{
  enum_t local_obj = *objp;

  if (amuDebug(D_XDRTRACE))
    plog(XLOG_DEBUG, "xdr_am_mountstat3:");

  if (!xdr_enum(xdrs, &local_obj))
    return (FALSE);
  return (TRUE);
}


bool_t
xdr_am_mountres3_ok(XDR *xdrs, am_mountres3_ok *objp)
{
  if (amuDebug(D_XDRTRACE))
    plog(XLOG_DEBUG, "xdr_am_mountres3_ok:");

  if (!xdr_am_fhandle3(xdrs, &objp->fhandle))
    return (FALSE);
  if (!xdr_array(xdrs,
		 (char **) ((voidp) &objp->auth_flavors.auth_flavors_val),
		 (u_int *) &objp->auth_flavors.auth_flavors_len,
		 ~0,
		 sizeof(int),
		 (XDRPROC_T_TYPE) xdr_int))
    return (FALSE);
  return (TRUE);
}


bool_t
xdr_am_mountres3(XDR *xdrs, am_mountres3 *objp)
{
  if (amuDebug(D_XDRTRACE))
    plog(XLOG_DEBUG, "xdr_am_mountres3:");

  if (!xdr_am_mountstat3(xdrs, &objp->fhs_status))
    return (FALSE);

  if (objp->fhs_status == AM_MNT3_OK) {
    if (!xdr_am_mountres3_ok(xdrs, &objp->mountres3_u.mountinfo))
      return (FALSE);
  }
  return (TRUE);
}


bool_t
xdr_am_diropargs3(XDR *xdrs, am_diropargs3 *objp)
{
  if (amuDebug(D_XDRTRACE))
    plog(XLOG_DEBUG, "xdr_am_diropargs3:");

  if (!xdr_am_nfs_fh3(xdrs, &objp->dir))
    return (FALSE);
  if (!xdr_am_filename3(xdrs, &objp->name))
    return (FALSE);
  return (TRUE);
}


bool_t
xdr_am_filename3(XDR *xdrs, am_filename3 *objp)
{
  if (amuDebug(D_XDRTRACE))
    plog(XLOG_DEBUG, "xdr_am_filename3:");

  if (!xdr_string(xdrs, objp, ~0))
    return (FALSE);
  return (TRUE);
}


bool_t
xdr_am_LOOKUP3args(XDR *xdrs, am_LOOKUP3args *objp)
{
  if (amuDebug(D_XDRTRACE))
    plog(XLOG_DEBUG, "xdr_am_LOOKUP3args:");

  if (!xdr_am_diropargs3(xdrs, &objp->what))
    return (FALSE);
  return (TRUE);
}


bool_t
xdr_am_LOOKUP3res(XDR *xdrs, am_LOOKUP3res *objp)
{
  if (amuDebug(D_XDRTRACE))
    plog(XLOG_DEBUG, "xdr_am_LOOKUP3res:");

  if (!xdr_am_nfsstat3(xdrs, &objp->status))
    return (FALSE);
  switch (objp->status) {
  case AM_NFS3_OK:
    if (!xdr_am_LOOKUP3resok(xdrs, &objp->res_u.ok))
      return (FALSE);
    break;
  default:
    if (!xdr_am_LOOKUP3resfail(xdrs, &objp->res_u.fail))
      return (FALSE);
    break;
  }
  return (TRUE);
}


bool_t
xdr_am_LOOKUP3resfail(XDR *xdrs, am_LOOKUP3resfail *objp)
{
  if (amuDebug(D_XDRTRACE))
    plog(XLOG_DEBUG, "xdr_am_LOOKUP3resfail:");

  /*
   * Don't xdr post_op_attr: amd doesn't need them, but they require many
   * additional xdr functions.
   */
#if 0
  if (!xdr_post_op_attr(xdrs, &objp->dir_attributes))
    return (FALSE);
#endif
  return (TRUE);
}


bool_t
xdr_am_LOOKUP3resok(XDR *xdrs, am_LOOKUP3resok *objp)
{
  if (amuDebug(D_XDRTRACE))
    plog(XLOG_DEBUG, "xdr_am_LOOKUP3resok:");

  if (!xdr_am_nfs_fh3(xdrs, &objp->object))
    return (FALSE);
  /*
   * Don't xdr post_op_attr: amd doesn't need them, but they require many
   * additional xdr functions.
   */
#if 0
  if (!xdr_post_op_attr(xdrs, &objp->obj_attributes))
    return (FALSE);
  if (!xdr_post_op_attr(xdrs, &objp->dir_attributes))
    return (FALSE);
#endif
  return (TRUE);
}


bool_t
xdr_am_nfs_fh3(XDR *xdrs, am_nfs_fh3 *objp)
{
  if (amuDebug(D_XDRTRACE))
    plog(XLOG_DEBUG, "xdr_am_nfs_fh3:");

  if (!xdr_u_int(xdrs, &objp->am_fh3_length))
    return (FALSE);
  if (objp->am_fh3_length > AM_FHSIZE3)
    return (FALSE);
  if (!xdr_opaque(xdrs, objp->am_fh3_data, objp->am_fh3_length))
    return (FALSE);
  return (TRUE);
}


bool_t
xdr_am_nfsstat3(XDR *xdrs, am_nfsstat3 *objp)
{
  if (amuDebug(D_XDRTRACE))
    plog(XLOG_DEBUG, "xdr_am_nfsstat3:");

  if (!xdr_enum(xdrs, (enum_t *)objp))
    return (FALSE);
  return (TRUE);
}
#endif /* not HAVE_FS_NFS3 */
