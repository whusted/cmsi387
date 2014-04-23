#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

#include "phil-data.h"

void pickUpChopstick(int chopstick) {
  //lock mutex
  pthread_mutex_lock(&chopsticks[chopstick]);
  // Check if current chopstick is already picked up
  // Bump current chopstick state by 1
  chopstick_condition[chopstick] += 1;

}

void dropChopstick(int chopstick) {
  //unlock mutex
  pthread_mutex_unlock(&chopsticks[chopstick]);
  chopstick_condition[chopstick] -= 1;
}

void eat(int philosopher) {
  pickUpChopstick(philosopher);
  pickUpChopstick((philosopher + 1) % PHILOSOPHERS);
  
  // set current philosopher condtion to eating
  philosopher_condition[philosopher] = EATING;
  // eat for random time
  randomWait(10);
}

void think(int philosopher) {
  // think for random time
  randomWait(10);
  philosopher_condition[philosopher] = HUNGRY;
}

void finishedEating(int philosopher) {
  // drop chopsticks individually
  dropChopstick(philosopher);
  dropChopstick((philosopher + 1) % PHILOSOPHERS);
  // philosopher condition should change to thinking
  philosopher_condition[philosopher] = THINKING;
}

// From bounded buffer
int randomWait(int bound) {
  int wait = rand() % bound;
  sleep(wait);
  return wait;
}

void* run(void* philosopher) {
  int current = *(int*) philosopher;
  // Now make them eat and think until the end of time
  while (1) {
    //print the conditions of the philosophers
    printPhilosophers();

    if (philosopher_condition[current] == THINKING) {
      think(current);
    } else if (philosopher_condition[current] == HUNGRY) {
      eat(current);
    } else if (philosopher_condition[current] == EATING) {
      finishedEating(current);
    }
  }
}

int main() {

  // Philosophers are the threads
	pthread_t philosophers[PHILOSOPHERS];

  // Loop through philosopher indexes, initialize to thinking
  for (int i = 0; i < PHILOSOPHERS; i++) {
    philosopher_condition[i] = THINKING;
    philosopher_index[i] = i;
    chopstick_condition[i] = 0;
    pthread_mutex_init(&chopsticks[i], NULL);
    // Call run in new thread
    pthread_create(&philosophers[i], NULL, run, &philosopher_index[i]);
  }
  // While (1) prevents us from ever getting here
  for (int i = 0; i < PHILOSOPHERS; i++) {
    pthread_join(philosophers[i], NULL);
  }
 
  // Will also not get here
	return 0;
}