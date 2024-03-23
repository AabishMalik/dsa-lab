// Program 4
// Evaluating Different types of expressions

#include <stdio.h>
#include <string.h>

int operand[128], top1 = -1, operator[128], top2 = -1;

int precedence(char op)
{
		if (op == '+' || op == '-') return 1;
		if (op == '*' || op == '/') return 2;
		return 0;
}

void process()
{
		int y = operand[top1--];
		int x = operand[top1--];
		int op = operator[top2--];

		if (op == '+') {
				operand[++top1] = x + y;
		} else if (op == '-') {
				operand[++top1] = x - y;
		} else if (op == '*') {
				operand[++top1] = x * y;
		} else if (op == '/') {
				operand[++top1] = x / y;
		}
		if (op == '(') {
				top1 += 2;
				top2 += 1;
		}
}

int evaluateInfixExpression(char *exp)
{
		for (int i = 0; exp[i] != '\0'; i++) {
				while (exp[i] == ' ') i++;
				char token = exp[i];

				if (token >= '0' && token <= '9') {
						int v = 0;
						while (exp[i] >= '0' && exp[i] <= '9') {
								v = (v * 10) + (exp[i] - '0');
								i++;
						}
						operand[++top1] = v;
						i--;

				} else if (token == '(') {
						operator[++top2] = token;

				} else if (token == ')') {
						while (operator[top2] != '(') { process(); }
						top2--;

				} else if (token == '/' || token == '*' || token == '+' || token == '-') {
						if (top2 == -1)
								operator[++top2] = token;
						else {
								while (precedence(token) <= precedence(operator[top2]) &&
									   top2 != -1) {
										process();
								}
								operator[++top2] = token;
						}
				}
		}
		while (top2 >= 0) { process(); }

		if (top1 == 0 && top2 == -1) {
				return operand[top1--];
		} else {
				printf("Invalid Expression\n");
				return 0;
		}
}

int evaluatePostFixExpression(char *exp)
{
		for (int i = 0; exp[i] != '\0'; i++) {
				int token = exp[i];
				if (token >= '0' && token <= '9') {
						operand[++top1] = token - '0';
				} else if (token == '+' || token == '-' || token == '*' || token == '/') {
						int z = 0;
						int y = operand[top1--];
						int x = operand[top1--];

						if (token == '+') z = x + y;
						if (token == '-') z = x - y;
						if (token == '*') z = x * y;
						if (token == '/') z = x / y;
						operand[++top1] = z;
				}
		}

		return operand[top1--];
}

int evaluatePrefixExpression(char *exp)
{
		for (int i = strlen(exp) - 1; i >= 0; i--) {
				int token = exp[i];
				if (token >= '0' && token <= '9') {
						operand[++top1] = token - '0';
				} else if (token == '+' || token == '-' || token == '*' || token == '/') {
						int z = 0;
						int x = operand[top1--];
						int y = operand[top1--];

						if (token == '+') z = x + y;
						if (token == '-') z = x - y;
						if (token == '*') z = x * y;
						if (token == '/') z = x / y;
						operand[++top1] = z;
				}
		}

		return operand[top1--];
}

int main()
{
		char *infix = "9*(4-1)";
		char *prefix = "*-941";
		char *postfix = "419-*";
		printf("Solved Infix %s :%d\n", infix, evaluateInfixExpression("9*(4-1)"));
		printf("Solved Postfix %s :%d\n", postfix, evaluatePostFixExpression("41-9*"));
		printf("Solved Prefix %s :%d\n", prefix, evaluatePrefixExpression("*9-41"));
}
