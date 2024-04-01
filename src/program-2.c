// Program 2
// Basic imprementation of a stack

#include <stdio.h>
#include <stdlib.h>

int *stack = NULL;
static size_t size = 0;

#define is_empty() (size == 0 || stack == NULL)

void create() {
		printf("Enter Starting stack size: ");
		scanf("\n%lu", &size);
		stack = malloc(sizeof(int) * size);
		for (size_t i = 0; i < size; i++) {
				printf("Element [%lu]: ", i);
				scanf("\n%d", &stack[i]);
		}
}

void push(int val) {
		if (stack == NULL) {
				printf("Stack not initialized...");
				return;
		}
		size++;
		stack = realloc(stack, sizeof(int) * size);
		stack[size - 1] = val;
}

int pop() {
		if (is_empty()) { return 0; }
		int ret = stack[size - 1];
		size--;
		stack = realloc(stack, sizeof(int) * size);
		return ret;
}

int peek() {
		if (is_empty()) { return 0; }
		return stack[size - 1];
}

void show() {
		if (is_empty()) {
				printf("Stack not initialized...\n");
		} else {
				for (size_t i = size - 1; i > 0; i--)
						printf("%-5s %d\n", i == size - 1 ? ">" : " ", stack[i]);

				printf("%-5s %d\n", 0 == size - 1 ? ">" : " ", stack[0]);
		}
}

void flush_stdin() {
		int c;
		while ((c = getchar()) != '\n' && c != EOF)
				;
}

int main() {
		int v;
		create();
		printf("Enter value to push: ");
		scanf("\n%d", &v);
		push(v);
		printf("Peeked: %d\n", peek());
		printf("Popped: %d\n", pop());
		show();
}
