#define LENGTH 64
/* sha512hl.c * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <phk@FreeBSD.org> wrote this file.  As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return.   Poul-Henning Kamp
 * ----------------------------------------------------------------------------
 */

#include <sys/cdefs.h>
__FBSDID("$FreeBSD$");

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

#include "sha512.h"

char *
SHA512_End(SHA512_CTX *ctx, char *buf)
{
	int i;
	unsigned char digest[LENGTH];
	static const char hex[]="0123456789abcdef";

	if (!buf)
		buf = malloc(2*LENGTH + 1);
	if (!buf)
		return 0;
	SHA512_Final(digest, ctx);
	for (i = 0; i < LENGTH; i++) {
		buf[i+i] = hex[digest[i] >> 4];
		buf[i+i+1] = hex[digest[i] & 0x0f];
	}
	buf[i+i] = '\0';
	return buf;
}

char *
SHA512_File(const char *filename, char *buf)
{
	return (SHA512_FileChunk(filename, buf, 0, 0));
}

char *
SHA512_FileChunk(const char *filename, char *buf, off_t ofs, off_t len)
{
	unsigned char buffer[16*1024];
	SHA512_CTX ctx;
	struct stat stbuf;
	int f, i, e;
	off_t n;

	SHA512_Init(&ctx);
	f = open(filename, O_RDONLY);
	if (f < 0)
		return 0;
	if (fstat(f, &stbuf) < 0)
		return 0;
	if (ofs > stbuf.st_size)
		ofs = stbuf.st_size;
	if ((len == 0) || (len > stbuf.st_size - ofs))
		len = stbuf.st_size - ofs;
	if (lseek(f, ofs, SEEK_SET) < 0)
		return 0;
	n = len;
	i = 0;
	while (n > 0) {
		if (n > sizeof(buffer))
			i = read(f, buffer, sizeof(buffer));
		else
			i = read(f, buffer, n);
		if (i <= 0) 
			break;
		SHA512_Update(&ctx, buffer, i);
		n -= i;
	} 
	e = errno;
	close(f);
	errno = e;
	if (i < 0)
		return 0;
	return (SHA512_End(&ctx, buf));
}

char *
SHA512_Data (const void *data, unsigned int len, char *buf)
{
	SHA512_CTX ctx;

	SHA512_Init(&ctx);
	SHA512_Update(&ctx,data,len);
	return (SHA512_End(&ctx, buf));
}

#ifdef WEAK_REFS
/* When building libmd, provide weak references. Note: this is not
   activated in the context of compiling these sources for internal
   use in libcrypt.
 */
#undef SHA512_End
__weak_reference(_libmd_SHA512_End, SHA512_End);
#undef SHA512_File
__weak_reference(_libmd_SHA512_File, SHA512_File);
#undef SHA512_FileChunk
__weak_reference(_libmd_SHA512_FileChunk, SHA512_FileChunk);
#undef SHA512_Data
__weak_reference(_libmd_SHA512_Data, SHA512_Data);
#endif
