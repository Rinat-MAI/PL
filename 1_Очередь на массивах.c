#include <stdio.h>
#define SIZE 20

struct queue{
	int mas[SIZE];
	int cnt;
};
void queue_init(struct queue *q){
	q->cnt = 0;
}
void queue(struct queue *q, int value){
	if(q->cnt < SIZE){
		q->mas[q->cnt] = value;
		q->cnt++;
	}
	else{
		printf("Стек переполнен\n");
	}
}
int dequeue(struct queue *q){
	int value;
	if(q != NULL){
		value = q->mas[0];
		for(int i = 0; i != q->cnt - 1; i++){
			q->mas[i] = q->mas[i + 1];
		}
		q->cnt--;
		return value;
	}
	else{
		return printf("Invalid queue\n");
	}
}

int main(){
	struct queue *p;
	queue_init(p);
	queue(p, 2);
	queue(p, 3);
	printf("%d\n", dequeue(p));
	printf("%d\n", dequeue(p));
	return 0;
}
