/**
 * @Author: YangGuang
 * @Date:   2017-12-10T20:55:47+08:00
 * @Email:  guang334419520@126.com
 * @Filename: shell.c
 * @Last modified by:   YangGuang
 * @Last modified time: 2017-12-10T21:08:23+08:00
 */


#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

#define MAXLINE 128
void err_sys(const char* msg_err) {
  printf("%s\n", msg_err);
  exit(254);
}

int main(int argc, char const *argv[]) {

  char buf[MAXLINE];
  pid_t childpid;
  int status;

  printf("%%<");


  while (fgets(buf, MAXLINE, stdin)) {
    if(buf[strlen(buf) - 1] == '\n') {
      buf[strlen(buf) - 1] = 0;
    }

    if( (childpid = fork()) == 0) {
      execlp(buf, buf, (char*)0);

      exit(127);
    }

    if(waitpid(childpid, &status, 0) < 0)
      err_sys("waitpid error");

    printf("%%<");
  }

  return 0;
}
