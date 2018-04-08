#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

char buf1[] = "abcdefghij";
char buf2[] = "ABCDEFGHIJ";

#define FILE_MODE (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH)

int main(void)
{
    int fd;

    if( (fd = creat("file.hole", FILE_MODE)) < 0)
        exit(1);

    if(write(fd, buf1, 10) != 10)
        exit(1);

    if(lseek(fd, 16384, SEEK_SET) == -1)
        exit(1);

    if(write(fd, buf2, 10) != 10)
        exit(1);
    exit(0);
}
