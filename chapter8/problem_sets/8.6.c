/**
 * @Author: YangGuang <sunshine>
 * @Date:   2018-04-10T14:59:01+08:00
 * @Email:  guang334419520@126.com
 * @Filename: 8.6.c
 * @Last modified by:   sunshine
 * @Last modified time: 2018-04-10T15:04:06+08:00
 */

#include <unistd.h>
#include <stdlib.h>
#include "../../my_error.h"

#ifdef SOLARIS
#define PSCMD "ps -a -o pid,ppid,s,tty,comm"
#else
#define PSCMD "ps -o pid,ppid,state,tty,command"
#endif

int
main(void)
{
  pid_t pid;

  if ( (pid = fork()) < 0)
    err_sys("fork error");
  else if (pid == 0)
    exit(0);

/*
  if (waitpid(pid, NULL, 0) < 0)
    err_sys("waitpid error");
    */
  sleep(4);

  system(PSCMD);
  exit(0);
}
