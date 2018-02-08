#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>


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

item create(char x,int y,char z){
item curr;
curr.type = x;
curr.amount = y;
curr.unit = z;
return curr;
}

void display(){
printf("first=%d, \nlast=%d\n",first,last);
}

int main(){
item i1,i2;
i1 = create(1,4,3);
i2 = create(5,1,8);
item *p1 = &i1;
item *p2 = &i2;
printf("Produce 1st time:\n");
produce(p1);
display();
printf("Produce 2nd time:\n");
produce(p2);
display();
printf("Consume 1st time:\n");
consume();
display();

}


