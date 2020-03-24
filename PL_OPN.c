#include <stdio.h>
#include <stdlib.h>
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
	struct stack opn;
	stack_init(&opn);
	char* val = (char*)malloc(10);
	int answer = 0;
	scanf("%s", &val);
	printf("%lu\n", sizeof(val));
	for(int i = 0; i < sizeof(val); i++){
		if(val[i] > '0' && val[i] < '9'){
			push(&opn, val[i]);
		}
		else if(opn.cnt > 1){
			switch(val[i]){
				case '*':
				answer = pop(&opn) * pop(&opn);
				push(&opn, answer);
				break;
				case '/':
				answer = pop(&opn) / pop(&opn);
				push(&opn, answer);
				break;
				case '+':
				answer = pop(&opn) + pop(&opn);
				push(&opn, answer);
				break;
				case '-':
				answer = pop(&opn) - pop(&opn);
				push(&opn, answer);
				break;
			}
		}
		else{
			return printf("Invalid value\n");
		}
	}
	printf("Obtained value: %d\n", answer);
	// push(&gg, 7);
	// push(&gg, 8);
	// printf("%d", pop(&gg));
	// printf("%d", pop(&gg));
}