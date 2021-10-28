#ifndef _SYSCALLS_H_
#define _SYSCALLS_H_

#include <unistd.h>

// ssize_t write(int fd, const void *buf, size_t count);
int sys_write(int fd, const void * buffer, size_t count);

//    ssize_t read(int fd, void *buf, size_t count);
ssize_t sys_read(int fd, void * buffer, size_t count);


int sys_time();


#endif