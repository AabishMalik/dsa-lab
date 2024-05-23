// program 10
//
// implementation of a stack using linked list

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node *next;
} node_t;

node_t *head;

void Push(int data) {
	node_t *node = (node_t *)malloc(sizeof(node_t));
	node->data = data;
	node->next = head;
	head = node;
	printf("Pushed: %d\n", data);
}

void Pop() {
	if (head == NULL)
		printf("Stack is Empty!!\n");
	else {
		node_t *tmp = head;
		head = head->next;
		printf("Popped: %d\n", tmp->data);
		free(tmp);
	}
}

void Search(int data) {
	int f = 0;
	node_t *tmp = head;
	while (tmp != NULL) {
		if (tmp->data == data) {
			f = 1;
			break;
		}
		tmp = tmp->next;
	}
	if (f)
		printf("%d is not in stack\n", data);
	else
		printf("%d found in stack", data);
}

void Display() {
	node_t *tmp = head;
	while (tmp != NULL) {
		printf("%d%s", tmp->data, (tmp->next == NULL) ? "\n" : "->");
		tmp = tmp->next;
	}
}

int main() {
	Push(10);
	Push(14);
	Push(11);
	Push(13);
	Pop();
	Pop();
	Pop();
	Display();

	return 0;
}