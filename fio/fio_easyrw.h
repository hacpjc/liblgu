#ifndef FIO_FIO_EASYRW_H_
#define FIO_FIO_EASYRW_H_

#include <stdlib.h>
#include <stdint.h>

typedef enum
{
	FIO_EASYRW_ERRNUM_OK = 0,
	FIO_EASYRW_ERRNUM_INVAL,   //!< Invalid input argument
	FIO_EASYRW_ERRNUM_OPEN,    //!< Cannot open file
	FIO_EASYRW_ERRNUM_NOMEM,   //!< Cannot alloc memory
	FIO_EASYRW_ERRNUM_IO,      //!< IO exception
	FIO_EASYRW_RRRNUM_OVERSZ,  //!< Over pre-defiend limit.
	FIO_EASYRW_ERRNUM_MISC
} fio_easyrw_errnum_t;

/**
 * Read smaller regular files into one buf.
 */
struct fio_easyrw
{
	const char *path;

	unsigned int nofollow : 1; //!< 1: Do not follow link.
	uint64_t limit; //!< Max file size to read. Avoid reading un-expected large file. (0: unlimited)

	void *out;
	unsigned int out_len;
	unsigned int out_max;

	int fd;
};

#define FIO_EASYRW_INITIALIZER(_path, _limit, _nofollow) \
	{ .path = (_path), .limit = (_limit), .no_follow = !!(_nofollow), .out = NULL, .out_len = 0, out_max = 0, .fd = -1 }

void fio_easyrw_init(struct fio_easyrw *erw,
	const char *path, const uint64_t limit, const unsigned int nofollow);
void fio_easyrw_exit(struct fio_easyrw *erw);

void *fio_easyrw_get_out(struct fio_easyrw *erw);
unsigned int fio_easyrw_get_out_len(struct fio_easyrw *erw);


fio_easyrw_errnum_t fio_easyrw_read_simple(struct fio_easyrw *erw);

typedef int (* fio_easyrw_read_func_t)(struct fio_easyrw *erw, void *priv);
fio_easyrw_errnum_t fio_easyrw_read(struct fio_easyrw *erw, fio_easyrw_read_func_t func, void *priv);

#endif