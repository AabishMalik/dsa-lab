// program 7
//
// Basic implementation of a singly linked list

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node *next;
} node_t;

typedef struct List {
	node_t *head;
	node_t *tail;
	size_t length;
} list_t;

list_t *ListCreate() {
	list_t *list = (list_t *)malloc(sizeof(list_t));
	list->head = NULL;
	list->tail = NULL;
	list->length = 0;
	return list;
}

void ListInsert(list_t *list, size_t idx, int data) {
	node_t *node = (node_t *)malloc(sizeof(node_t));
	node->data = data;
	node->next = NULL;
	if (idx == 0) {
		node->next = list->head;
		list->head = node;
		list->tail = node;
	} else if (idx > list->length) {
		list->tail->next = node;
		list->tail = node;
	} else {
		node_t *current = list->head;
		for (int i = 0; i < idx - 1; i++) {
			current = current->next;
		}
		node->next = current->next;
		current->next = node;
	}
	list->length++;
}

void ListDisplay(list_t *list) {
	node_t *current = list->head;
	while (current != NULL) {
		printf("%d%s", current->data, (current->next != NULL) ? "->" : "\n");
		current = current->next;
	}
}

int ListSearch(list_t *list, int data) {
	node_t *current = list->head;
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

void ListDelete(list_t *list, size_t idx) {
	node_t *current = list->head;
	if (idx == 0) {
		list->head = current->next;
		free(current);
	} else {
		for (int i = 0; i < idx - 1; i++) {
			current = current->next;
		}
		node_t *temp = current->next;
		current->next = temp->next;
		free(temp);
	}
	list->length--;
}

int main() {
	list_t *list = ListCreate();
	ListInsert(list, 0, 10);
	ListInsert(list, 1, 20);
	ListInsert(list, 2, 30);
	ListInsert(list, 3, 40);
	ListInsert(list, 4, 50);
	ListDisplay(list);
	printf("Index of 30: %d\n", ListSearch(list, 30));
	ListDelete(list, 2);
	printf("After deleting index 2\n");
	ListDisplay(list);

	return 0;
}
