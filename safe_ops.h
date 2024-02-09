#ifndef SAFE_OPS
#define SAFE_OPS

#include "include_all.h"

/* included functions */

#define ALLOC_LIB
#define FILE_IO_LIB

/************************/

/* excluded functions 

#define DIR_LIB
#define OTHER_LIB

*/
#ifdef ALLOC_LIB

void* safe_realloc(void *line, size_t size);
void* safe_malloc(size_t size);
void* safe_calloc(size_t elements, size_t size);
void* safe_memset(void *addr, int value, size_t size);

#endif

#ifdef FILE_IO_LIB

FILE* safe_fopen(char* filename, char* access);
int safe_open(char *pathname, int flags);
int safe_open_mode(char *pathname, int flags, mode_t mode);
void safe_close(int fd);
ssize_t safe_read(int fd, void *buf, size_t count);
ssize_t safe_write(int fd, const void *buf, size_t count);

#endif

#ifdef DIR_LIB

DIR *safe_opendir(const char *dirname);
struct dirent *safe_readdir(DIR *dir);
void safe_mkdir(const char *dirname, mode_t permissions);

#endif

#ifdef OTHER_LIB

int safe_lstat(const char *path, struct stat *buf);
int safe_creat(const char *filename, mode_t permissions);
int safe_socket(int domain, int type, int protocol);

#endif

#endif