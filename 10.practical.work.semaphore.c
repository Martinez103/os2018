#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <stdbool.h>
#include <semaphore.h>

#define BUFFER_SIZE 10
///////// SEMAPHORE /////////
sem_t s;

typedef struct{
int type;
int amount;
int unit;
} item;
item buffer[BUFFER_SIZE];

int first=0;
int last=0;

void produce(item *i){
	sem_wait(&s);
	while ((first + 1) % BUFFER_SIZE == last) {
		
	}
	memcpy(&buffer[first], i, sizeof(item));
	first = (first + 1) % BUFFER_SIZE;
	sem_post(&s);
}

item *consume() {
	sem_wait(&s);
	item *i = malloc(sizeof(item));
	while (first == last) {
		
	}
	memcpy(i, &buffer[last], sizeof(item));
	last = (last + 1) % BUFFER_SIZE;
	sem_post(&s);
	return i;
}

void display(item *x){
	printf("%d %d %d\n",x->type,x->amount,x->unit);
}

item create_item(int x,int y,int z){
	item curr;
	curr.type = x;
	curr.amount = y;
	curr.unit = z;
	return curr;
}

void *thread_producer(void *param){
	item i1,i2,i3;
	i1 = create_item(1,3,4);
	i2 = create_item(5,7,6);
	i3 = create_item(3,1,1);
	item *p1,*p2,*p3;		
	p1 = &i1;	
	p2 = &i2;
	p3 = &i3;	
	produce(p1);
	produce(p2);
	produce(p3);
}

void *thread_consumer(void *param){
	display(consume());
	display(consume());	
}


int main(){
	sem_init(&s,0,1);
	pthread_t tid1,tid2;
	pthread_create(&tid1,NULL,thread_producer,NULL);
	pthread_create(&tid2,NULL,thread_consumer,NULL);

	pthread_join(tid1,NULL);
	pthread_join(tid2,NULL);
	return 0;
}


