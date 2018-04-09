/**
 * @Author: YangGuang <sunshine>
 * @Date:   2018-04-09T16:38:00+08:00
 * @Email:  guang334419520@126.com
 * @Filename: 8-12.c
 * @Last modified by:   sunshine
 * @Last modified time: 2018-04-09T16:42:24+08:00
 */

#include "../my_error.h"
#include <unistd.h>

static void charatatime(char*);

int main(int argc, char const *argv[]) {
  pid_t pid;

  if ( (pid = fork()) < 0)
    err_sys("error fork");
  else if (pid == 0) {
    charatatime("output from child\n");
  }
  else
    charatatime("output from parent\n");


  return 0;
}

static void
charatatime(char* str)
{
  char* ptr;
  int c;
  setbuf(stdout, NULL);
  for (ptr = str; (c = *ptr++) != 0;)
    putc(c, stdout);
}
