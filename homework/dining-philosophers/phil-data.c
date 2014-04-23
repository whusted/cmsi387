#include "phil-data.h"

#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

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

void pickUpChopstick(int chopstick) {
  pthread_mutex_lock(&chopsticks[chopstick]);
  // Check if current chopstick is already picked up
  if (chopstick_condition[chopstick] < 0) {
        printf("*** CRITICAL SECTION VIOLATION ***\n");
        exit(1);
    }
  chopstick_condition[chopstick] += 1;

}

void dropChopstick(int chopstick) {
  pthread_mutex_unlock(&chopsticks[chopstick]);
  chopstick_condition[chopstick] -= 1;
}

// From bounded buffer
int randomWait(int bound) {
  int wait = rand() % bound;
  sleep(wait);
  return wait;
}

void eat(int philosopher) {
  pickUpChopstick(philosopher);
  pickUpChopstick((philosopher + 1) % PHILOSOPHERS);
  
  philosopher_condition[philosopher] = EATING;
  randomWait(10);
}

void think(int philosopher) {
  randomWait(10);
  philosopher_condition[philosopher] = HUNGRY;
}

void finishedEating(int philosopher) {
  dropChopstick(philosopher);
  dropChopstick((philosopher + 1) % PHILOSOPHERS);
  philosopher_condition[philosopher] = THINKING;
}
