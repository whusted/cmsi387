#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>

#define PHILOSOPHERS 5
#define THINKING 0
#define EATING 1
#define HUNGRY 2

void pickUpChopstick() {
  //lock mutex

}

void dropChopstick() {
  //unlock mutex
}

void eat() {
  // pick up chopsticks one at a time
  // set current philosopher condtion to eating 
  // philosopher_condition[] = EATING;
  // eat for random time
  randomWait(10);
}

void think() {
  // think for random time
  randomWait(10);
  // philosopher condition should change to hungry... meaning a 3rd function is needed
}

void finishedEating() {
  // should be called when philosopher condition is eating
  // philosopher condition should change to thinking
}

// From bounded buffer
int randomWait(int bound) {
  int wait = rand() % bound;
  sleep(wait);
  return wait;
}

int main(int argc, char const *argv[]) {

	// Chopsticks are shared resource
  pthread_mutex_t chopsticks[PHILOSOPHERS];
	int chopstick_condition[PHILOSOPHERS];

    // Philosophers are the threads
	pthread_t philosophers[PHILOSOPHERS];
	int philosopher_condition[PHILOSOPHERS];

	// Now make them eat and think until the end of time
	//while (1) {
      //print the states of the philosophers
      //printPhilosophers();

      // if (philosopher_condition[current] == THINKING) {
      //   think();
      // } else if (philosopher_condition[current] == EATING) {
      //   eat();
      // } else if (philosopher_condition[current] == HUNGRY) {
      //   //be hungry? not sure what to call this function
      // }



	//}

	return 0;
}