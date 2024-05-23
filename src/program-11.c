// program 11
//
// implementation of a queue using linked list

#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
	int data;
	struct Node *next;
} node_t;

node_t *head = NULL, *tail = NULL;

void Enqueue(int data) {
	node_t *node = malloc(sizeof(node_t));
	node->data = data;
	node->next = NULL;

	if (head == NULL) {
		head = tail = node;
	} else {
		tail->next = node;
		tail = node;
	}

	printf("Enqueued: %d\n", data);
}

void Dequeue() {
	if (head == NULL) {
		printf("Queue is empty\n");
		return;
	}
	node_t *tmp = head;
	head = head->next;

	printf("Dequeued: %d\n", tmp->data);
	free(tmp);
}

void Search(int data) {
	node_t *tmp = head;
	while (tmp != NULL) {
		if (tmp->data == data) {
			printf("%d found in queue\n", data);
			return;
		}
	}
	printf("%d not found in queue\n", data);
}

void Display() {
	node_t *tmp = head;
	if (tmp == NULL) {
		printf("Queue is empty\n");
	} else
		while (tmp != NULL) {
			printf("%d ", tmp->data);
			tmp = tmp->next;
		}
	putchar('\n');
}

int main() {
	Enqueue(10);
	Enqueue(20);
	Enqueue(30);
	Enqueue(40);
	Dequeue();
	Dequeue();
	Dequeue();
	Search(40);
	Dequeue();
	Display();
}