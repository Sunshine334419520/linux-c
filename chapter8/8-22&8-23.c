/**
 * @Author: YangGuang <sunshine>
 * @Date:   2018-04-10T11:57:11+08:00
 * @Email:  guang334419520@126.com
 * @Filename: 8-22&8-23.c
 * @Last modified by:   sunshine
 * @Last modified time: 2018-04-10T12:06:47+08:00
 */

#include <sys/wait.h>
#include <errno.h>
#include <unistd.h>
#include "../my_error.h"
#include "8-5.c"


int
system(const char* cmdstring)
{
  pid_t pid;
  int status;

  if (cmdstring == NULL)
    return 1;

  if ( (pid = fork()) < 0)
    status = -1;
  else if (pid == 0) {
    execl("/bin/sh", "sh", "-c", cmdstring, (char*)0);
    _exit(127);
  }
  else {
    while (waitpid(pid, &status, 0) < 0) {
      if (errno != EINTR) {
        status = -1;
        break;
      }
    }
  }
  return status;
}

int main(int argc, char const *argv[]) {
  int status;

  if ( (status = system("date")) < 0)
    err_sys("system() error");

  pr_exit(status);

  if ( (status = system("nosuchcommadn")) < 0)
    err_sys("system error");
  pr_exit(status);

  if ( (status = system("who; exit 44")) < 0)
    err_sys("system error");
  pr_exit(status);
  return 0;
}
