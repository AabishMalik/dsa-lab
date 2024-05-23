// program 7
//
// Basic implementation of a singly linked list

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node *next;
} node_t;

node_t *head = NULL, *tail = NULL;
size_t length = 0;

void Insert(size_t idx, int data) {
	node_t *node = (node_t *)malloc(sizeof(node_t));
	node->data = data;
	node->next = NULL;

	if (length == 0) {
		head = node;
		tail = node;

	} else if (idx == 0) {
		node->next = head;
		head = node;

	} else if (idx >= length) {
		tail->next = node;
		tail = node;
	} else {
		node_t *current = head;
		for (size_t i = 0; i < idx - 1; i++) {
			current = current->next;
		}
		node->next = current->next;
		current->next = node;
	}
	length++;
}

void Display() {
	node_t *current = head;
	while (current != NULL) {
		printf("%d%s", current->data, (current->next != NULL) ? "->" : "\n");
		current = current->next;
	}
}

int Search(int data) {
	node_t *current = head;
	int idx = 0;
	while (current != NULL) {
		if (current->data == data) {
			return idx;
		}
		current = current->next;
		idx++;
	}
	return -1;
}

void Delete(size_t idx) {
	node_t *current = head;
	if (idx == 0) {
		head = current->next;
		free(current);
		length--;
	} else {
		for (size_t i = 0; i < idx - 1 && current != NULL; i++) {
			current = current->next;
		}
		if (current != NULL) {
			node_t *temp = current->next;
			current->next = temp->next;
			free(temp);
			length--;
		}
	}
}

int main() {
	Insert(0, 1);
	Insert(1, 2);
	Insert(2, 3);
	Insert(0, 4);
	Display();
	printf("Index of 3: %d\n", Search(3));
	Delete(1);
	printf("After deleting index 1\n");
	Display();

	return 0;
}
