#ifndef __PHIL_DATA__
#define __PHIL_DATA__

#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

#define PHILOSOPHERS 5
#define THINKING 0
#define EATING 1
#define HUNGRY 2

// Chopsticks are shared resource
pthread_mutex_t chopsticks[PHILOSOPHERS];
int chopstick_condition[PHILOSOPHERS];

int philosopher_condition[PHILOSOPHERS];
int philosopher_index[PHILOSOPHERS];

/**
 * Initializes synchronization primitives.
 */
void printPhilosophers(void);

#endif
