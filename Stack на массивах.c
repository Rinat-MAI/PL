#include <stdio.h>
#define SIZE 20

struct stack{
	int mas[SIZE];
	int cnt;
};
void stack_init(struct stack *st){
	st->cnt = 0;
}
void push(struct stack *st, int val){
	if(st->cnt < SIZE){
		st->mas[st->cnt] = val;
		st->cnt++;
	}
	else{
		printf("Стек переполнен\n");
	}
}
int pop(struct stack *st){
	if(st->cnt > 0){
		st->cnt--;
		return st->mas[st->cnt];
	}
	else{
		printf("Пустой стек\n");
	}
}

int main(){
	struct stack gg;
	stack_init(&gg);
	push(&gg, 7);
	push(&gg, 8);
	printf("%d", pop(&gg));
	printf("%d", pop(&gg));
}
