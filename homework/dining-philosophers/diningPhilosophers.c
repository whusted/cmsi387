#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>

#define PHILOSOPHERS 5
#define THINKING 0
#define EATING 1
#define HUNGRY 2

// Chopsticks are shared resource
pthread_mutex_t chopsticks[PHILOSOPHERS];
int chopstick_condition[PHILOSOPHERS];

int philosopher_condition[PHILOSOPHERS];

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
  // philosopher condition should change to hungry... meaning a 3rd function is needed
}

void finishedEating() {
  // should be called when philosopher condition is eating
  // drop chopsticks individually

  // philosopher condition should change to thinking
}

// From bounded buffer
int randomWait(int bound) {
  int wait = rand() % bound;
  sleep(wait);
  return wait;
}

int main(int argc, char const *argv[]) {

    // Philosophers are the threads
	pthread_t philosophers[PHILOSOPHERS];

	// Now make them eat and think until the end of time
	//while (1) {
    //print the states of the philosophers
    //printPhilosophers();

    // if (philosopher_condition[current] == THINKING) {
    //   think();
    // } else if (philosopher_condition[current] == EATING) {
    //   eat();
    // } else if (philosopher_condition[current] == HUNGRY) {
    //   finishedEating()
    // }



	//}

	return 0;
}