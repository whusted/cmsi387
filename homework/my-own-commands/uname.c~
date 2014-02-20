/**
 * This program demonstrates invocation of the kill
 * system call (37) using the syscall function.
 */
#include <sys/types.h> 
#include <sys/utsname.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>

#include <stdio.h>

int main(int argc, char *argv[]) {
  
  int id = atoi(argv[1]);
  int result = syscall(37, id);

  // A result of -1 means that something went wrong.
  if (result == -1) {
    char *errorMessage = "Oops something went wrong\n";
    syscall(4, 2, errorMessage, strlen(errorMessage));
  }
}
