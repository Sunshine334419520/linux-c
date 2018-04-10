/**
 * @Author: YangGuang <sunshine>
 * @Date:   2018-04-10T11:29:58+08:00
 * @Email:  guang334419520@126.com
 * @Filename: 8-16&2-17.c
 * @Last modified by:   sunshine
 * @Last modified time: 2018-04-10T11:54:58+08:00
 */

#include "../my_error.h"
#include <unistd.h>
#include <sys/wait.h>

char *env_init[] = { "USER=unknown", "PATH=/tmp", NULL};

int main(int argc, char const *argv[]) {
  pid_t pid;
  if ( (pid = fork()) < 0)
    err_sys("fork error");
  else if (pid == 0) {

    if (execle("./echoall",
                "echoall","my argv1", "MY ARGV2", (char*)0, env_init ) < 0)
      err_sys("execle error");

    exit(0);
  }

  if (waitpid(pid, NULL, 0) < 0)
    err_sys("waitpid error");

  if ( (pid = fork()) < 0) {
    err_sys("fork error");
  } else if (pid == 0) {
    if (execlp("echoall", "echoall", "only 1 arg", (char*)0) < 0)
      err_sys("execlp error");
  }
  return 0;
}
