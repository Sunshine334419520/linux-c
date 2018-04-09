/**
 * @Author: YangGuang <sunshine>
 * @Date:   2018-04-09T15:36:58+08:00
 * @Email:  guang334419520@126.com
 * @Filename: 8-8.c
 * @Last modified by:   sunshine
 * @Last modified time: 2018-04-09T15:47:05+08:00
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include "../my_error.h"

int main(int argc, char const *argv[]) {
  pid_t pid;
  if ( (pid = fork()) < 0)
    err_sys("fork error");
  else if (pid == 0) {
    if ( (pid = fork()) < 0)
      err_sys("fork error");
    else if (pid > 0) {
      // parent
      exit(0);
    }
    // second child;
    sleep(2);
    printf("second child, parent pid = %ld\n", (long)getppid());
    exit(0);
  }

  if (waitpid(pid, NULL, 0) != pid)
    err_sys("waitpid error");
  return 0;
}
