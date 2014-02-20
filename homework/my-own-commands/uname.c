/**
 * This program demonstrates invocation of the mkdir
 * system call (39) using the syscall function.
 */
#include <sys/types.h> 
#include <sys/utsname.h>
#include <unistd.h>
#include <string.h>

#include <stdio.h>

int main(int argc, char *argv[]) {
  
  struct utsname buf;
  int result = syscall(122, &buf);
  printf("%s\n", buf.sysname);

  // A result of -1 means that something went wrong.
  if (result == -1) {
    char *errorMessage = "Oops something went wrong\n";
    syscall(4, 2, errorMessage, strlen(errorMessage));
  }
}
