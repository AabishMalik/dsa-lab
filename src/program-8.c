// program 8
//
// Basic implementation of a doubly linked list

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node *next;
	struct Node *prev;
} node_t;

node_t *head = NULL;
node_t *tail = NULL;
size_t length = 0;

void Insert(size_t idx, int data){
	node_t *node = (node_t *)malloc(sizeof(node_t));
	node->data = data;
	node->next = node->prev = NULL;

	if(length == 0){
		head = tail = node;
	}else if(idx == 0){
		node->next = head;
		head->prev = node;
		head = node;
	}else{
		node_t *current = head;
		for(size_t i=0; i<idx-1 && current->next != NULL; i++){
			current = current->next;
		}
		node->next = current->next;
		node->prev = current;
		current->next = node;
		if(node->next == NULL) tail = node;
		else{
			node->next->prev = node;
		}
	}
	length++;
}

void Search(int data){
	node_t *current = head;
	int idx = 0;
	while(current != NULL){
		if(current->data == data){
			printf("Found %d at index %d\n", data, idx);
			return;
		}
		current = current->next;
		idx++;
	}
	printf("%d not found\n", data);
}

void Display(){
	node_t *current = head;
	while(current != NULL){
		printf("%d%s", current->data, (current->next != NULL) ? "<->" : "\n");
		current = current->next;
	}
}

void Delete(size_t idx){
	if(length == 0) return;
	node_t *current = head;
	if(idx == 0){
		head = head->next;
		head->prev = NULL;
	}else if (idx == length-1){
		tail = tail->prev;
		tail->next = NULL;
	}else if(idx >= length){
		printf("Index out of bounds\n");
		return;
	}else{
		for(size_t i = 0; i<idx; i++){
			current = current->next;
		}
		if(current != NULL){
			current->prev->next = current->next;
			current->next->prev = current->prev;
		}
	}
	free(current);
	length--;
}

int main(){
	Insert(0, 1); Insert(1, 9); Insert(3, 10); Insert(1, 5);
	Display();
	Search(5);
	Search(11);
	Delete(1);
	Display();
	return 0;
}