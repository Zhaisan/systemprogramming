#include<stdlib.h>
#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<sys/stat.h>
#include<unistd.h>
 
int main(int argc, char *argv[]) {
 
    int source, dest, n;
    char buf;
    int filesize;
    int i;
 
    if (argc != 3) {
        fprintf(stderr, "usage %s <source> <dest>", argv[0]);
        exit(-1);
    }
    if ((source = open(argv[1], 0400)) < 0) { 
        fprintf(stderr, "can't open source");
        exit(-1);
    }
    if ((dest = creat(argv[2], 0700)) < 0) { 
        fprintf(stderr, "can't create dest");
        exit(-1);
    }
 
    filesize = lseek(source, (off_t) 0, SEEK_END); 
    for (i = filesize - 1; i >= 0; i--) { 
        lseek(source, (off_t) i, SEEK_SET);
 
        n = read(source, &buf, 1);
 
        if (n != 1) {
            fprintf(stderr, "can't read 1 byte");
            exit(-1);
        }
 
        n = write(dest, &buf, 1);
        if (n != 1) {
            fprintf(stderr, "can't write 1 byte");
            exit(-1);
        }
 
    }
    close(source);
    close(dest);
    return 0;
}