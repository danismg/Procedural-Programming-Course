#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>

sem_t room;
sem_t chopstick[10];
void * philosopher(void *);
void eat(int);
int main(){
	int i,a[10];
	pthread_t tid[5];
	sem_init(&room,0,10);
	for(i=0;i<10;i++)
		sem_init(&chopstick[i],0,3);
	for(i=0;i<10;i++){
		a[i]=i;
		pthread_create(&tid[i],NULL,philosopher,(void *)&a[i]);
	}
	for(i=0;i<10;i++)
		pthread_join(tid[i],NULL);
}
void * philosopher(void * num){
	int phil=*(int *)num;
	sem_wait(&room);
	printf("\nPhilosopher %d confirmation on room",phil);
	sem_wait(&chopstick[phil]);
	sem_wait(&chopstick[(phil+1)%5]);
	eat(phil);
	sleep(2);
	printf("\nPhilosopher %d finished eating",phil);
	sem_post(&chopstick[(phil+1)%5]);
	sem_post(&chopstick[phil]);
	sem_post(&room);
}
void eat(int phil){
	printf("\nPhilosopher %d is eating",phil);
}