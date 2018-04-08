/**
 * @Author: sunshine
 * @Date:   2017-12-10T16:43:47+08:00
 * @Email:  guang334419520@126.com
 * @Filename: myls.c
 * @Last modified by:   sunshine
 * @Last modified time: 2017-12-10T17:00:26+08:00
 */

#include <dirent.h>
#include <stdio.h>


int main(int argc, char *argv[]) {
  DIR* dp;
  struct dirent* dirp;

  if(argc != 2)
    return -1;
  if( (dp = opendir(argv[1])) == NULL)
    return -1;
  while ( (dirp = readdir(dp)) != NULL) {
    printf("%s\n", dirp->d_name);
  }

  closedir(dp);
  return 0;
}
