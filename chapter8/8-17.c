/**
 * @Author: YangGuang <sunshine>
 * @Date:   2018-04-10T11:39:42+08:00
 * @Email:  guang334419520@126.com
 * @Filename: 8-17.c
 * @Last modified by:   sunshine
 * @Last modified time: 2018-04-10T11:45:36+08:00
 */

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[]) {
  int i;
  char **ptr;
  extern char **environ;

  for (i = 0; i < argc; i++)
    printf("argv[%d] : %s\n", i, argv[i]);

  for (ptr = environ; *ptr != 0; ptr++)
    printf("%s\n", *ptr);
  return 0;
}
