/**
 * @Author: YangGuang <sunshine>
 * @Date:   2018-04-09T15:21:14+08:00
 * @Email:  guang334419520@126.com
 * @Filename: 8-5.cc
 * @Last modified by:   sunshine
 * @Last modified time: 2018-04-09T15:27:53+08:00
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

void
pr_exit(int status)
{
  if (WIFEXITED(status))
    printf("normal termination, exit status = %d\n",
           WEXITSTATUS(status));
  else if (WIFSIGNALED(status))
    printf("abnormal termination, signal number = %d%s\n",
            WTERMSIG(status),
#ifdef WCOREDUMP
            WCOREDUMP(status) ? " (core file generated)" : "");
#else
            "");
#endif
  else if (WIFSTOPPED(status))
    printf("child stopped, signal number = %d\n",
            WSTOPSIG(status));
}
