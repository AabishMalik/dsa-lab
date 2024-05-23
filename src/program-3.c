// Program 3
// Program to check if brackets in an expression are balanced or not

#include <stdio.h>
#include <string.h>

int main() {
	char BUFFER[128], STK[128];
	printf("Enter expression: ");
	scanf("\n%[^\n]127s", BUFFER);
	int len = strlen(BUFFER);
	int top = -1;
	char is_valid = 1;

	for (int i = 0; i < len && is_valid; i++) {
		switch (BUFFER[i]) {
		case '(':
		case '{':
		case '[': STK[++top] = BUFFER[i]; break;
		case ')':
			if (STK[top] == '(') {
				top--;
			} else
				is_valid = 0;
			break;
		case ']':
			if (STK[top] == '[') {
				top--;
			} else
				is_valid = 0;
			break;
		case '}':
			if (STK[top] == '{') {
				top--;
			} else
				is_valid = 0;
			break;
		default: break;
		}
	}

	if (is_valid)
		printf("Valid expression\n");
	else
		printf("Invalid expression\n");
}
