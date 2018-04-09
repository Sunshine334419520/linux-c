/**
 * @Author: YangGuang <sunshine>
 * @Date:   2018-04-09T14:53:46+08:00
 * @Email:  guang334419520@126.com
 * @Filename: 8-1.c
 * @Last modified by:   sunshine
 * @Last modified time: 2018-04-09T15:16:09+08:00
 */

#include <stdio.h>
#include "../my_error.h"
#include <unistd.h>

volatile int globvar = 6;
char buf[] = "a wirte to stdout\n";

int main(int argc, char const *argv[]) {
  volatile int var;
  pid_t pid;

  var = 88;
  if (write(STDOUT_FILENO, buf, sizeof(buf) - 1) != (sizeof(buf) - 1))
    err_sys("write error");
  printf("before fork\n");

  if ( (pid = fork()) < 0)
    err_sys("fork error");
  else if (pid == 0) {
    globvar++;
    var++;
  }
  else
    sleep(2);

  globvar++;
  printf("pid = %ld, glob = %d, var = %d\n", (long)getpid(), globvar, var);
  return 0;
}
