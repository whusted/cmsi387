#include "phil-data.h"

#include <pthread.h>
#include <semaphore.h>

void printPhilosophers() {
  // loop through and print condition of each phil
  for (int i = 0; i < PHILOSOPHERS; i++) {
    if (philosopher_condition[i] == HUNGRY) {
      printf("%s", "HUNGRY  ");
    } else if (philosopher_condition[i] == THINKING) {
      printf("%s", "THINKING  ");
    } else if (philosopher_condition[i] == EATING) {
      printf("%s", "EATING  ");
    }
  }
  printf("\n");
}
