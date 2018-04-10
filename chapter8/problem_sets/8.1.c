/**
 * @Author: YangGuang <sunshine>
 * @Date:   2018-04-10T14:46:20+08:00
 * @Email:  guang334419520@126.com
 * @Filename: 8.1.c
 * @Last modified by:   sunshine
 * @Last modified time: 2018-04-10T15:09:38+08:00
 */

#include "../../my_error.h"
#include <unistd.h>
#include <stdlib.h>

int globvar = 6;

int main(int argc, char const *argv[]) {
  int var;
  pid_t pid;

  var = 88;
  printf("before vfork\n");
  if ( (pid = vfork()) < 0)
    err_sys("fork error");
  else if (pid == 0) {
    globvar++;
    var++;
    fclose(stdout);
    exit(0);
  }

  int i;
  char buf[10];
  i = printf("pid = %ld, glob = %d, var = %d\n", (long)getpid(), globvar, var);
  snprintf(buf, 10, "%d\n", i);
  write(STDOUT_FILENO, buf, strlen(buf));

  return 0;
}
