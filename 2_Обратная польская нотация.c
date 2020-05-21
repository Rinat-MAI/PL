#include <stdio.h>
#include <string.h>
#define SIZE 128

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
	char buf[SIZE];
	int answer = 0;
	printf("Enter an expression: ");
	scanf("%s", buf);
	for(int i = 0; i < strlen(buf); i++){
		if(buf[i] > '0' && buf[i] < '9'){
			push(&opn, buf[i] - '0');
			printf("%d\n", buf[i] - '0');
		}
		else{
			switch(buf[i]){
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
	}
	return printf("Obtained value: %d\n", answer);
}
