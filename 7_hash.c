#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_MUL 31
#define HASH_SIZE 128

struct student{
	char fn[256];
	char sn[256];
 	char gender;
 	float h;
	float w;
	int gr;
	float as;
 };

struct listnode{
	char *key;
	struct student st;
	struct listnode *next;
};

struct listnode* hashTab[HASH_SIZE];

unsigned int hash(char *s){
	unsigned int h = 0;
	char *p;
	for (p = s; *p != '\0'; p++){
		h = h * HASH_MUL + (unsigned int)*p;
	}
	return h % HASH_SIZE;
}

void hashtab_init(struct listnode **hashtab){
	int i;
	for(i = 0; i < HASH_SIZE; i++){
		hashtab[i] = NULL;
	}
}

void hashtab_add(struct listnode **hashtab, char *key, struct student *student){
	struct listnode *node;
	node = malloc(sizeof(*node));
	unsigned int index = hash(key);
	if(node != NULL){
		for(int i = 0; i < 256; i++){
			node->st.fn[i] = student->fn[i];
			node->st.sn[i] = student->sn[i];
		}
		node->st.gender = student->gender;
		node->st.h = student->h;
		node->st.w = student->w;
		node->st.gr = student->gr;
		node->st.as = student->as;
		hashtab[index] = node;
	}
}

struct listnode *hashtab_lookup(struct listnode **hashtab, char *key){
	int index;
	struct listnode *node;
	index = hash(key);
	for(node = hashtab[index]; node != NULL; node = node->next){
		if(strcmp(node->key, key) == 0){
			return node;
		}
	}
	return NULL;
}

void hashtab_del(struct listnode **hashtab, char *key){
	unsigned int index;
	struct listnode *node, *prev;
	index = hash(key);
	node = hashtab[index];
	for(node; node != NULL; node = node->next){
		if(strcmp(node->key, key) == 0){
			if(prev == NULL){
				hashtab[index] = node->next;
			}
			else{
				prev->next = node->next;
			}
			free(node);
			return;
		}
		prev = node;
	}
}

//Функция печати структуры student
void student_printf(struct student *student){
	if(student != NULL){
		for(int i = 0; i < 256 && student->fn[i] != '\0'; i++){
			printf("%c", student->fn[i]);
		}
		printf("\n");
		for(int i = 0; i < 256 && student->sn[i] != '\0;'; i++){
			printf("%c", student->sn[i]);
		}
		printf("\n");
		printf("%c\n", student->gender);
		printf("%f\n", student->h);
		printf("%f\n", student->w);
		printf("%d\n", student->gr);
		printf("%f\n", student->as);
	}
	return;
}

void hashtab_printf(struct listnode **hashtab){
	for(int i = 0; i < HASH_SIZE; i++){
		if(hashtab[i] != NULL){
			printf("Ячейка №%d:", i);
			struct listnode *node;
			node = hashtab[i];
			while(hashtab[i] != NULL){
				student_printf(&node->st);
				printf("\n");
				node = node->next;
			}
		}
	}
	return;
}


int main(){

}
