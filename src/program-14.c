// program 14
//
// implementation of Binary Search Tree data structure

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

	if (data < node->data) {
		node->left = Delete(node->left, data);
	} else if (data > node->data) {
		node->right = Delete(node->right, data);
	} else {
		if (node->left == NULL || node->right == NULL) {
			tnode *tmp = (node->left == NULL) ? node->right : node->left;
			free(node);
			return tmp;
		}

		tnode *tmp = node->right;
		while (tmp->left != NULL) tmp = tmp->left;
		node->data = tmp->data;
		node->right = Delete(node->right, tmp->data);
	}

	return node;
}

tnode *Search(tnode *node, int data) {
	if (node == NULL) return NULL;
	if (data == node->data) return node;

	if (data < node->data) {
		return Search(node->left, data);
	} else {
		return Search(node->right, data);
	}
}

void In(tnode *node) {
	if (node == NULL) return;

	In(node->left);
	printf("%d ", node->data);
	In(node->right);
}

int main() {
	root = Insert(root, 50);
	root = Insert(root, 30);
	root = Insert(root, 60);
	root = Insert(root, 71);
	root = Insert(root, 70);

	printf("Inorder: ");
	In(root);
	putchar('\n');

	printf("Searching for 60: %s\n", (Search(root, 60) ? "Found" : "Not Found"));
	printf("Deleting 60\n");
	root = Delete(root, 60);
	printf("Searching for 60: %s\n", (Search(root, 60) ? "Found" : "Not Found"));

	return 0;
}