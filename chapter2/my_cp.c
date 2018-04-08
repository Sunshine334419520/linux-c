#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
int main(int argc, char * argv[])
{
    char buf[10000];
    char *p = buf; 
    FILE* fin = fopen(argv[1],"r");
    FILE* fout = fopen(argv[2], "w");
    /*
    while((*p = fgetc(fin) != EOF)) {
       if(*p == '\0') 
           continue;

       p++;
    }

    fwrite(buf,sizeof(char), strlen(buf), fout);

    fclose(fin);
    fclose(fout);
    */

    *p = 'a';
    p++;
    *p = '2';

    printf("%s",buf);

}

