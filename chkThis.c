#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>


int main(int argc, char** argv) {

  if (argc==2) {
    char attr_path[50];
    int pid;
    sscanf(argv[1], "%d", &pid);
    sprintf(attr_path,"/proc/%d/exe", pid);
    char* link_path = realpath(attr_path, NULL);
    int thisErrno = errno;

    printf("attr_path=%s\n", attr_path);
    printf("link_path=%s\n", link_path);
    printf("errno=%s (%d)\n", strerror(thisErrno), thisErrno);

    free(link_path);

    char full_path[PATH_MAX];
    link_path = realpath(attr_path, full_path);
    thisErrno = errno;
    printf("link_path=%s\n", link_path);
    printf("full_path=%s\n", full_path);
    printf("errno=%s (%d)\n", strerror(thisErrno), thisErrno);

//    free(link_path);

  } else {
    printf("usage: %s pid\n", argv[0]);
  }
}

