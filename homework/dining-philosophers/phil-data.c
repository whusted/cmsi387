#include "phil-data.h"

#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

// JD: You call this in multiple threads, and not from within any
//     criical section.  This may result in occasional "interleaved"
//     output if more than 1 thread happens to be doing this within
//     a very short amount of time.
void printPhilosophers() {
  // loop through and print condition of each phil
  // JD: This is nice and straightforward, but can be a level richer,
  //     I think, if you also display chopstick state between the
  //     5 philosophers.
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
        printf("*** CRITICAL SECTION VIOLATION; TERMINATING ***\n");
        exit(1);
    }
  chopstick_condition[chopstick] += 1;

}

void dropChopstick(int chopstick) {
  pthread_mutex_unlock(&chopsticks[chopstick]);
  chopstick_condition[chopstick] -= 1;
  // JD: ^^^Do your state change *before* you unlock---that way you
  //     are guaranteed to "own" the chopstick.  And, like in
  //     pickUpChopstick, you can do another sanity check before
  //     marking the chopstick as being down: said chopstick must
  //     still be held by you right before you put it down.
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
