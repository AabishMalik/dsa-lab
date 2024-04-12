// program 7
//
// Basic implementation of a singly linked list

#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node *next;
};

typedef struct Node node_t;

node_t *ListCreate(size_t size) {
	if (size == 0) return NULL;

	node_t *node = (node_t *)malloc(sizeof(node_t));
	node_t *curr = node;

	for (size_t i = 0; i < size - 1; i++) {
		curr->next = (node_t *)malloc(sizeof(node_t));
		curr = curr->next;
	}
	return node;
}

void ListDisplay(node_t *head) {
	if (head == NULL) return;

	node_t *curr = head;
	while (curr != NULL) {
		printf("%d%s", curr->data, (curr->next == NULL) ? "\n" : "->");
		curr = curr->next;
	}
}

void ListInsert(node_t *head, size_t index, int data) {
	if (head == NULL || index < 0) return;

	node_t *node = (node_t *)malloc(sizeof(node_t));
	node->data = data;

	node_t *curr = head;
	if (index == 0) {
		node->next = head;
		head = node;
	} else {
		for (size_t i = 0; curr != NULL; i++) {
			if (i == index - 1) {
				node->next = curr->next;
				curr->next = node;
				return;
			}
			curr = curr->next;
		}
	}
	free(node);
}

int ListSearch(node_t *head, int val) {
	if (head == NULL) return -1;

	int idx = -1;
	node_t *curr = head;
	for (int i = 0; curr != NULL; i++) {
		if (val == curr->data) {
			idx = i;
			break;
		}
		curr = curr->next;
	}
	return idx;
}

void ListDelete(node_t *head, size_t index) {
	if (head == NULL) {
		printf("List is empty\n");
		return;
	}
	node_t *curr = head;

	if (index == 0) {
		head = head->next;
		free(curr);
		return;
	}

	for (size_t i = 0; curr != NULL; i++) {
		if (i == index - 1) {
			node_t *temp = curr->next;
			curr->next = temp->next;
			free(temp);
			break;
		}
		curr = curr->next;
	}
}

int main() {
	node_t *head = ListCreate(1);
	head->data = 10;
	ListInsert(head, 1, 20);
	ListInsert(head, 2, 30);
	ListInsert(head, 3, 40);
	ListInsert(head, 4, 50);
	ListDisplay(head);
	printf("Index of 30: %d\n", ListSearch(head, 30));
	ListDelete(head, 2);
	printf("After deleting index 2\n");
	ListDisplay(head);

	return 0;
}
