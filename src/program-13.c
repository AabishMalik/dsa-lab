// program 13
//
// implementation of Tree data structure

#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
	int data;
	struct TreeNode *left;
	struct TreeNode *right;
} tnode;

tnode *root = NULL;

tnode *Create(int data) {
	tnode *node = malloc(sizeof(tnode));
	node->data = data;
	node->left = node->right = NULL;
	return node;
}

tnode *Insert(tnode *node, int data) {
	if (node == NULL) return Create(data);

	if (data < node->data) {
		node->left = Insert(node->left, data);
	} else {
		node->right = Insert(node->right, data);
	}
	return node;
}

tnode *Delete(tnode *node, int data) {
	if (node == NULL) return NULL;

	if (node->data == data) {
		free(node);
		return NULL;
	}
	node->left = Delete(node->left, data);
	node->right = Delete(node->right, data);

	return node;
}

tnode *Search(tnode *node, int data) {
	if (node == NULL) return NULL;

	tnode *left = Search(node->left, data);
	tnode *right = Search(node->left, data);

	if (left != NULL) return left;
	return right;
}

void Pre(tnode *node) {
	if (node == NULL) return;

	printf("%d ", node->data);
	Pre(node->left);
	Pre(node->right);
}
void In(tnode *node) {
	if (node == NULL) return;

	In(node->left);
	printf("%d ", node->data);
	In(node->right);
}

void Post(tnode *node) {
	if (node == NULL) return;

	Post(node->left);
	Post(node->right);
	printf("%d ", node->data);
}

int main() {
	root = Insert(root, 10);
	root = Insert(root, 20);
	root = Insert(root, 25);
	root = Insert(root, 30);
	printf("\nPreorder: ");
	Pre(root);

	printf("\nPostoder: ");
	Post(root);

	root = Delete(root, 30);
	root = Delete(root, 20);

	printf("\nInorder: ");
	In(root);

	return 0;
}