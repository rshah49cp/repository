#include "safe_ops.h"

/* adapted from my previous CSC 357 course */

#ifdef ALLOC_LIB

void* safe_realloc(void *line, size_t size) {
    void *ptr = NULL;
    if (!(ptr = realloc(line, size))) {
        free(line); /* clear any old memory */
        perror("realloc error");
        exit(EXIT_FAILURE); /* end program */
    }
    return ptr;
}

void* safe_malloc(size_t size) {
    void* ptr = malloc(size);
    if (ptr == NULL) {
        perror("malloc error");
        exit(EXIT_FAILURE);
    }
    return ptr;
}

void* safe_calloc(size_t elements, size_t size) {
    void* ptr = calloc(elements, size);
    if (ptr == NULL) {
        perror("calloc error");
        exit(EXIT_FAILURE);
    }
    return ptr;
}

void* safe_memset(void *addr, int value, size_t size){
    void* ptr = memset(addr, value, size);
    if (ptr == NULL) {
        perror("memset error");
        exit(EXIT_FAILURE);
    }
    return ptr;
}

#endif

#ifdef FILE_IO_LIB
FILE* safe_fopen(char* filename, char* access){
    FILE *file = fopen(filename, access);
    if (file == NULL) {
        perror("Error opening the file");
    }
    return file;
}

int safe_open(char *pathname, int flags){
    int fd = open(pathname, flags);
    if (fd == -1){
        char errormsg[100];
        sprintf(errormsg, "open without mode failed: %s\n", pathname);
        perror(errormsg);
        exit(-1);
    }
    return fd;
}
 
int safe_open_mode(char *pathname, int flags, mode_t mode){
    int fd = open(pathname, flags, mode);
    if (fd == -1){
        char errormsg[100];
        sprintf(errormsg, "open with mode failed: %s\n", pathname);
        perror(errormsg);
        exit(-1);
    }
    return fd;
}

void safe_close(int fd){
    if (close(fd)){
        perror("fd close failed\n");
        exit(EXIT_FAILURE);
    }
}

ssize_t safe_read(int fd, void *buf, size_t count){
    ssize_t bytes = read(fd, buf, count);
    if (bytes < 0){
        perror("fd read failed\n");
        exit(EXIT_FAILURE);
    }
    return bytes;
}

ssize_t safe_write(int fd, const void *buf, size_t count){
    ssize_t bytes = write(fd, buf, count);
    if (bytes < 0){
        perror("fd write failed\n");
        exit(EXIT_FAILURE);
    }
    return bytes;
}

#endif

#ifdef DIR_LIB

DIR *safe_opendir(const char *dirname) {
    DIR *dir = opendir(dirname);

    if (dir == NULL) {
        perror("opendir");
        exit(EXIT_FAILURE);
    }

    return dir;
}

struct dirent *safe_readdir(DIR *dir) {
    struct dirent *entry = readdir(dir);

    if (entry == NULL) {
        perror("readdir");
        exit(EXIT_FAILURE);
    }

    return entry;
}

void safe_mkdir(const char *dirname, mode_t permissions) {
    if (mkdir(dirname, permissions) == 0) {
		
        printf("Directory '%s' created successfully.\n", dirname);
		
    } else {
        perror("mkdir");
        exit(EXIT_FAILURE);
    }
}

#endif

#ifdef OTHER_LIB

int safe_lstat(const char *path, struct stat *buf){
	int safe = lstat(path, buf);
	if (safe != 0){
		perror(path);
        exit(EXIT_FAILURE);
	}
}

int safe_creat(const char *filename, mode_t permissions) {
    int file_desc = creat(filename, permissions);
    if (file_desc != -1) {
		/*
 *         printf("File '%s' created successfully.\n", filename);
 *         		*/
        return file_desc;
    } else {
        perror("creat");
		free(filename);
        exit(EXIT_FAILURE);
    }
}

int safe_socket(int domain, int type, int protocol){
	/* return type is a file descriptor */
	int socket_fd = socket(domain, type, protocol);
	if (socket_fd == -1) {
		perror("Error creating socket");
		exit(EXIT_FAILURE);
	}
	return socket_fd;
}

#endif