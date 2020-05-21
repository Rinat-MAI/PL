#include <stdio.h>
#include <stdlib.h>
 
struct node{ 
	int key;
	struct node *next;
};

// Создание списка
struct node *create_node(int value){ 
	struct node *p;
	p = malloc(sizeof(*p));
	if(p != NULL){
		p->key = value;
		p->next = NULL;
	}
	return p;
}

// Функция добавление элемента в список
struct node *node_add(int value, struct node *node){ 
	struct node *newnode = create_node(value);
	if(node != NULL){
		newnode->next = node;
		return newnode;
	}
	return node;
}

// Функция поиска и удаления элемента
struct node *node_search(struct node *node, int value){ 
	struct node *p, *prev = NULL;
	for(p = node; p != NULL; p = p->next){
		if(p->key == value){
			if(prev == NULL){
				node = p->next;
			}
			else{
				prev->next = p->next;
			}
			free(p);
			return node;
		}
		prev = p;
	}
	return NULL;
}

// Функция подсчета длины списка
int node_length(struct node *node){
	if(node == NULL){
		return printf("Пустой список\n");
	}
	struct node *p;
	int count;
	for(p = node; p->next != NULL; p = p->next){
		count++;
	}
	free(p);
	return count++;
}

// Функция печати списка
void node_print(struct node *node){
	if(node == NULL){
		printf("Пустой список\n");
	}
	else{
		struct node *p = node;
		do{
			printf("%d\n", p->key);
			p = p->next;
		}
		while(p->next != NULL);
	free(p);
	}
}
int main(){
	
}
