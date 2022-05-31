//FINAL EXAM DIOS
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TreeNode {
	char* key;
	struct TreeNode* left;
	struct TreeNode* right;
};

void addNode(char* key, struct TreeNode** address_of_tree) {

	struct TreeNode* newnode;
	newnode = *address_of_tree;

	if (newnode == NULL) {
		newnode = malloc(sizeof(struct TreeNode));
		newnode->key = malloc(sizeof(struct TreeNode));
		strcpy(newnode->key, key);
		newnode->left = NULL;
		newnode->right = NULL;

		*address_of_tree = newnode;

		return;
	}

	if (strcmp(key, newnode->key) < 0) {
		// compare with value at root of tree
		// less than 
		addNode(key, &(newnode->left));
		//newnode->left = leftNode;
		//leftNode->parent = newnode;
	}
	else if (strcmp(key, newnode->key) > 0) {
		addNode(key, &(newnode->right));
		//newnode->right = rightNode;
		//rightNode->parent = newnode;
	}
}

void printBST(struct TreeNode* root)
{
	if (root != NULL)
	{
		printBST(root->left);
		printf("%s\n", root->key);
		printBST(root->right);
	}
}

int main() {

	struct TreeNode* pointer = NULL;
	int n = 0;

	while (1)
	{
		char words[1000];
		if (scanf("%s", words) == EOF) break;

		addNode(words, &pointer);

		n++;

		if (n == 100) break;
	}

	printBST(pointer);
	return 0;
}
