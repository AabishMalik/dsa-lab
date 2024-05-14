// program 9
//
// Basic implementation of a circular linked list


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
		head = tail = node;
		tail->next = head;
	} else if (idx == 0) {
		node->next = head;
		head = node;
		tail->next = head;
	} else if (idx >= length) {
		tail->next = node;
		tail = node;
		tail->next = head;
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

void Search(int data) {
	node_t *current = head;
	int idx = 0;
	while (current != NULL) {
		if (current->data == data) {
			printf("Found %d at index %d\n", data, idx);
			return;
		}
		current = current->next;
		idx++;
		if (current == head) {
			break;
		}
	}
	printf("%d not found\n", data);
}

void Display() {
	node_t *current = head;
	while (current != NULL) {
		printf("%d%s", current->data, (current->next != head) ? "->" : "\n");
		current = current->next;
		if (current == head) {
			break;
		}
	}
}

void Delete(size_t idx) {
	if (length == 0) return;
	node_t *current = head;
	if (idx == 0) {
		head = head->next;
		tail->next = head;
	} else {
		for (size_t i = 0; i < idx - 1; i++) {
			current = current->next;
		}
		node_t *temp = current->next;
		current->next = temp->next;
		free(temp);
	}
	length--;
}


int main() {
	Insert(0, 1);
	Insert(1, 2);
	Insert(2, 4);
	Insert(3, 7);
	Display();
	Search(2);
	Delete(5);
	Display();
	Search(2);
	return 0;
}