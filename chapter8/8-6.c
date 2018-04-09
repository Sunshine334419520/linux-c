/**
 * @Author: YangGuang <sunshine>
 * @Date:   2018-04-09T15:28:23+08:00
 * @Email:  guang334419520@126.com
 * @Filename: 8-6.c
 * @Last modified by:   sunshine
 * @Last modified time: 2018-04-09T15:33:04+08:00
 */
#include "../my_error.h"
#include "8-5.c"

int main(int argc, char const *argv[]) {
  pid_t pid;
  int status;

  if ( (pid = fork()) < 0)
    err_sys("fork error");
  else if (pid == 0)
    exit(7);

  if (wait(&status) != pid)
    err_sys("wait error");
  pr_exit(status);

  if ( (pid = fork()) < 0)
    err_sys("fork error");
  else if (pid == 0)
    abort();

  if (wait(&status) != pid)
    err_sys("wait error");
  pr_exit(status);

  if ( (pid = fork()) < 0)
    err_sys("fork error");
  else if (pid == 0)
    status /= 0;

  if (wait(&status) != pid)
    err_sys("wait error");
  pr_exit(status);
  return 0;
}
