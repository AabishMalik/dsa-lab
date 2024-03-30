// program 6
// Basic operation of enqueqe and dequeqe in a queue
//

#include <stdio.h>

#define MAX 128
int queue[MAX];
int front = -1;
int rear = -1;

void enqueue(int data)
{
		if (rear == MAX - 1) {
				printf("Queue is full\n");
				return;
		}
		queue[++rear] = data;
}

int dequeue()
{
		if (front == rear) {
				printf("Queue is empty\n");
				return -1;
		}
		return queue[++front];
}

int isEmpty()
{
		return front == rear;
}

void display()
{
		for (int i = front + 1; i <= rear; i++) { printf("%d ", queue[i]); }
		printf("\n");
}

void stdin_flush()
{
		int c;
		while ((c = getchar()) != '\n' && c != EOF)
				;
}

int main()
{
		while (1) {
				char op;
				printf("Available operations:\n");
				printf("1. Enqueue\n");
				printf("2. Dequeue\n");
				printf("3. Display\n");
				printf("4. Exit\n");

				printf("Enter operation: ");
				scanf(" %c", &op);

				if (op == '1') {
						int data;
						printf("Enter data: ");
						scanf("%d", &data);
						enqueue(data);
				} else if (op == '2') {
						int data = dequeue();
						if (data != -1) { printf("Dequeued data: %d\n", data); }
				} else if (op == '3') {
						display();
				} else if (op == '4') {
						break;
				}
				stdin_flush();
				printf("Press enter to continue\n");
				getchar();
		}
}
