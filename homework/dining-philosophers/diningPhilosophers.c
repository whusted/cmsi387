#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

#include "phil-data.h"

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
  // JD: Ack, TAAAAAAB in the line below!
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
  // While loop in run prevents us from ever getting here
  for (int i = 0; i < PHILOSOPHERS; i++) {
    pthread_join(philosophers[i], NULL);
  }
 
  // Will also not get here
  // JD: Here too!  AIEEEYEEEYEEEIEEEE!
	return 0;
}