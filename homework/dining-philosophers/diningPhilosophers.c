#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>

#define PHILOSOPHERS 5
#define THINKING 0
#define EATING 1

void pickUpChopstick() {


}

void dropChopstick() {

}

int main(int argc, char const *argv[]) {

	// Chopsticks are shared resource
	pthread_mutex_t chopsticks[PHILOSOPHERS];

    // Philosophers are the threads
	pthread_t philosophers[PHILOSOPHERS];
	int philosopher_condition[PHILOSOPHERS];

	return 0;
}