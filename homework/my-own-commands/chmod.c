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

// For convenience, we just use the stdio functions to display
// the output for this one.
#include <stdio.h>

int main(int argc, char *argv[]) {
  // We keep the hardcoded system call numbers to illustrate
  // that they are still just that: numbers.
  syscall(15, argv[1], S_IRUSR | S_IRGRP | S_IROTH);
}
