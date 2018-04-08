#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    if(argc !=2 ) {
        printf("usage: a.out <pathname>\n");
        exit(0);
    }

    if(access(argv[1], R_OK) < 0) 
    {
        printf("access error for %s\n", argv[1]);
        exit(0);
    }
    else 
        printf("read access OK\n");

    if(open(argv[1], O_RDONLY) < 0) 
    {
        printf("access error for %s", argv[1]);
        exit(0);
    }
    else
        printf("ope for reading OK\n");
    return EXIT_SUCCESS;
}
