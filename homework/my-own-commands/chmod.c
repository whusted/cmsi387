/**
 * This program demonstrates invocation of the chmod
 * system call (15 in 32-bit Linux) using the syscall function.  Some
 * of its output is then displayed.
 */
#include <linux/kernel.h>
#include <linux/types.h>
#include <linux/unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

#include <stdio.h>

int main(int argc, char *argv[]) {
  //Accepts either 777 for full permissions or 444 for read only.
  //All calls should have all 3 numbers as arguments.
  int errorCheck;
  if (argc < 3) {
  	errorCheck = -1;
  }

  int input = atoi(argv[2]);
  
  // Read only
  if (input == 444) {
      errorCheck = 0;
      syscall(15, argv[1], S_IRUSR | S_IRGRP | S_IROTH);
  } else if (input == 777) {
      errorCheck = 0;
      syscall(15, argv[1], S_IRUSR | S_IWUSR | S_IXUSR | S_IRGRP | S_IWGRP | S_IXGRP | S_IROTH | S_IWOTH | S_IXOTH);
      
  } else {
      errorCheck = -1;
  }

  if (errorCheck == -1) {
      printf("%s", "Please input a file followed by 444 or 777\n");
      return -1;
  } else {
      return 0;
  }
}
