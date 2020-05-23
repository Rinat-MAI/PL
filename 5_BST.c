#include <stdio.h>
#include <stdlib.h>

struct bstree{
	int key;
	int value;
	struct bstree *left;
	struct bstree *right;
};

// Создание элемента
struct bstree *bstree_create(int key, int value){
	struct bstree *node;
	node = malloc(sizeof(*node));
	if(node != NULL){
		node->key = key;
		node->value = value;
		node->left = NULL;
		node->right = NULL;
	}
	return node;
}


// Функция поиска элемента
struct bstree *bstree_search(struct bstree *tree, int key){
	while(tree != NULL){
		if(tree->key == key){
			return tree;
		}
		else if(key < tree->key){
			tree = tree->left;
		}
		else{
			tree = tree->right;
		}
	}
	return tree;
}

// Функция добавления элемента
void bstree_add(struct bstree *tree, int key, int value){
	struct bstree *parent, *node;
	if(tree == NULL){
		return;
	}
	while(tree != NULL){
		parent = tree;
		if(key < tree->key){
			tree = tree->left;
		}
		else if(key > tree->key){
			tree = tree->right;
		}
		else{
			return;
		}
	}
	node = bstree_create(key, value);
	if(key < parent->key){
		parent->left = node;
	}
	else{
		parent->right = node;
	}
}

//Функция нахождения минимального элемента
struct bstree *bstree_min(struct bstree *tree){
	if(tree == NULL){
		return NULL;
	}
	while(tree->left != NULL){
		tree = tree->left;
		return tree; 
	}
}

// Функция удаления эелемента
void bstree_delete(struct bstree *tree, int key){
	if(tree == NULL){
		return;
	}
	else{
		struct bstree *parent;
		parent = tree;
		while(tree->key != key){
			parent = tree;
			if(key < tree->key){
				tree = tree->left;
			}
			else{
				tree = tree->right;
			}
		}
		if(tree->left == NULL && tree->right == NULL){ // 1 случай (у удалаяемого узла нет ветвей)
			free(tree);
		}
		else if(tree->left != NULL && tree->right != NULL){ // 3 случай (у удаляемого узла есть две ветви)
			struct bstree *parent2 = tree->right;
			while(parent2->left->left != NULL){
				parent2 = parent2->left;
			}
			struct bstree *min = parent->left;
			if(parent2->left->right != NULL){
				parent->left = parent->left->right;
				parent2->left->left = parent->left->left;
			}
			parent2->left = min;
			parent->left = min;
			parent2->right = min->right;
			free(min);

		}
		else{ // 2 случай (у удаляемого узла есть одна ветвь)
			if(parent->left == tree){
				if(tree->left != NULL){
					parent->left = tree->left;
				}
				else{
					parent->left = tree->right;
				}
			}
			else{
				if(tree->left != NULL){
					parent->right = tree->left;
				}
				else{
					parent->right = tree->right;
				}
			}
			free(tree);
		}
	}	
}

int main(){

}
