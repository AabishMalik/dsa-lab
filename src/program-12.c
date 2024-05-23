// program 12
//
// implementation of a priority queue using linked list

#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
	int data;
	int priority;
	struct Node *next;
} node_t;

node_t *head = NULL, *tail = NULL;

void Enqueue(int data, int priority) {
	node_t *node = malloc(sizeof(node_t));
	if (node == NULL) return;

	node->data = data;
	node->priority = priority;
	node->next = NULL;

	if (head == NULL) {
		head = tail = node;
	} else {
		tail->next = node;
		tail = node;
	}
	printf("Enqueued : (%d, %d)\n", data, priority);
}

void Dequeue() {
	node_t *tmp = head;
	node_t *ret = head;
	node_t *prev = NULL;

	while (tmp->next != NULL) {
		if (tmp->next->priority > ret->priority) {
			prev = tmp;
			ret = tmp->next;
		}
		tmp = tmp->next;
	}
	if (prev == NULL) {
		head = head->next;
	} else {
		prev->next = ret->next;
	}

	printf("Dequeued: (%d, %d)\n", ret->data, ret->priority);
	free(ret);
}

void Search(int data) {
	node_t *tmp = head;
	while (tmp != NULL) {
		if (tmp->data == data) {
			printf("%d found in queue\n", data);
			return;
		}
		tmp = tmp->next;
	}
	printf("%d not found in quque\n", data);
}

void Display() {
	node_t *tmp = head;
	if (tmp == NULL) {
		printf("Queue is empty\n");
		return;
	}

	while (tmp != NULL) {
		printf("(%d, %d) ", tmp->data, tmp->priority);
		tmp = tmp->next;
	}
	putchar('\n');
}

int main() {
	Enqueue(10, 0);
	Enqueue(20, 1);
	Enqueue(30, 3);
	Enqueue(40, 2);

	Dequeue();
	Dequeue();
	Dequeue();
	Search(10);
	Display();
}