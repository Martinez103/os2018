#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define BUFFER_SIZE 10

typedef struct{
char type;
int amount;
char unit;
} item;
item buffer[BUFFER_SIZE];


int first=0;
int last=0;


void produce(item *i){
	while ((first + 1) % BUFFER_SIZE == last) {
		
	}
	memcpy(&buffer[first], i, sizeof(item));
	first = (first + 1) % BUFFER_SIZE;
}

item *consume() {
	item *i = malloc(sizeof(item));
	while (first == last) {
		
	}
	memcpy(i, &buffer[last], sizeof(item));
	last = (last + 1) % BUFFER_SIZE;
	return i;
}

item *create(char x,int y,char z){
item *curr = malloc(sizeof(item));
curr->type = x;
curr->amount = y;
curr->unit = z;
return curr;
}

void display(item *i){
if(i=NULL)
  return;
else
printf("%d %d %d",i->type,i->amount,i->unit);
}

void *thread_create(void *param){
     item *i1,*i2,*i3;
i1 = create(0,4,3);
i2 = create(1,5,3);
i3 = create(7,3,4);
produce(i1);
produce(i2);
produce(i3);
}

void *thread_consume(void *param){
display(consume());
display(consume());
}


int main(){
pthread_t tid1,tid2;

pthread_create(&tid1,NULL,thread_create,NULL);
pthread_create(&tid2,NULL,thread_consume,NULL);


pthread_join(tid1,NULL);
pthread_join(tid2,NULL);
return 0;
}














