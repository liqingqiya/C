/* Our own header. Tabs are set for 4 spaces, not 8 */

#ifndef __unpipc_h
#define __unpipc_h

#include "config.h" /* configuration options for current os */

#include <sys/types.h>
#include <sys/time.h>
#include <time.h>
#include <errno.h>
#include <fcntl.h>
#include <limits.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/wait.h>

#ifdef HAVE_MQUEUE_H
#include <mqueue.h>
#endif

#ifdef HAVE_SEMAPHORE_H
#include <semaphore.h>

#ifndef SEM_FAILED
#define SEM_FAILED ((sem_t *)(-1))
#endif

#endif

#ifdef HAVE_SYS_MMAN_H
#include <sys/mman.h>
#endif

#ifndef MAP_FAILED
#define MAP_FAILED ((void *)(-1))
#endif

#ifdef HAVE_SYS_MSG_H
#include <sys/ipc.h>
#endif

#ifdef HAVE_SYS_SEM_H
#include <sys/msg.h>
#endif

#ifdef HAVE_SYS_SEM_H
#ifdef __bsdi__
#undef HAVE_SYS_SEM_H
#else
#include <sys/sem.h>
#endif

#ifndef HAVE_SEMUN_UNION
union semun {
    int               val;
    struct semid_ds   *buf;
    unsigned short    *array;
};
#endif
#endif /* HAVE_SYS_SEM_H */

#ifdef HAVE_SYS_SHM_H
#include <sys/shm.h>
#endif

#ifdef HAVE_POLL_H
#include <poll.h>
#endif

#ifdef HAVE_STROPTS_H
#include <stropts.h>
#endif

#ifdef HAVE_STRINGS_H
#include <stropts.h>
#endif

#ifdef HAVE_STRINGS_H
#include <strings.h>
#endif


/*Next three headers are normally needed for socket/file ioctl's:
 * <sys/ioctl.h>, <sys/fillio.h>, and <sys/sockio.h>
 */
#ifdef HAVE_SYS_IOCTL_H
#include <sys/ioctl.h>
#endif

#ifdef HAVE_SYS_FILIO_H
#include <sys/filio.h>
#endif

#ifdef HAVE_PTHREAD_H
#include <pthread.h>
#endif

#ifdef HAVE_DOOR_H
#include <door.h>
#endif

#ifdef HAVE_RPC_RPC_H
#ifdef _PSX4_NSPACE_H_TS
#undef SUCCESS
#endif
#include <rpc/rpc.h>
#endif

/* Define bzero() as a macro if it's not in standard C library. */
#ifndef HAVE_BZERO
#define bzero(ptr, n)  memset(ptr, 0, n)
#endif

/* Posix.1g
 * 
 * */

#ifndef INFTIM
#define INFTIM (-1)
#ifdef HAVE_POOL_H
#define INFTIM_UNPH
#endif
#endif

/* Miscellaneous constants */
#ifndef PATH_MAX
#define PATH_MAX 1024
#endif

#define MAX_PATH 1024
#define MAXLINE  4096
#define BUFFSIZE 8192

#define FILE_MODE   (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)
#define DIR_MODE    (FILE_MODE | S_IXUSR | S_IXOTH)
#define SVMSG_MODE  (MSG_R | MSG_W | MSG_R>>3 | MSG_R>>6)
#define SVSEM_MODE  (SEM_R | SEM_W | SEM_R>>3 | SEM_R>>6)
#define SVSHM_MODE  (SHM_R | SHM_W | SHM_R>>3 | SHM_R>>6)

typedef void Sigfunc(int);

#ifdef HAVE_SIGINFO_T_STRUCT
typedef void Sigfunc_rt(int , siginfo_t *, void *);
#endif

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

#ifndef HAVE_TIMESPEC_STRUCT
struct timespec {
    time_t tv_sec;
    long tv_nsec;
};
#endif

/*
 *
 * */
#ifdef __bsdi__
#define va_mode_t int
#else
#define va_mode_t mode_t
#endif

#define read_lock(fd, offset, whence, len) \
    lock_reg(fd, F_SETLK, F_RDLCK, offset, whence, len)
#define readw_lock(fd, offset , whence, len) \
    lock_reg(fd, F_SETLKW, F_RDLCK, offset, whence, len)
#define write_lock(fd, offset, whence, len) \
    lock_reg(fd, F_SETLK, F_WRLCK, offset, whence, len)
#define writew_lock(fd, offset, whence, len) \
    lock_reg(fd, F_SETLKW, F_WRLCK, offset, whence, len)
#define un_lock(fd, offset, whence, len) \
    lock_reg(fd, F_SETLK, F_UNLCK, offset, whence, len)
#define is_read_lockable(fd, offset, whence, len) \
    lock_test(fd, F_RDLCK, offset, whence, len)
#define is_write_lockable(fd, offset, whence, len) \
    lock_test(fd, F_WRLCK, offset, whence, len)





#endif /* __unpipc_h */
