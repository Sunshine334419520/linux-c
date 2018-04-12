/**
 * @Author: YangGuang <sunshine>
 * @Date:   2018-04-11T14:42:01+08:00
 * @Email:  guang334419520@126.com
 * @Filename: 10-5.c
 * @Last modified by:   sunshine
 * @Last modified time: 2018-04-12T17:21:41+08:00
 */

#include "../my_error.h"
#include <unistd.h>
#include <setjmp.h>
#include <signal.h>

static jmp_buf env_alrm;

static void
sig_alrm(int signo)
{
  longjmp(env_alrm, 1);
}

unsigned int sleep(unsigned int seconds){
  if (signal(SIGALRM,sig_alrm) == SIG_ERR)
    return seconds;
  if (setjmp(env_alrm) == 0) {
    alarm(seconds);
    pause();
  }
  return alarm(0);
}
