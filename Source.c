//FINAL EXAM
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {

	char* key;
	struct TreeNode* parent;
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
		newnode->parent = NULL;
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
		printf("Node: %s, ", root->key);
		if (root->parent == NULL)
			printf("Parent: NULL\n");
		else
			printf("Parent: %s\n", root->parent->key);
		printBST(root->right);
	}
}

int main() {

	struct TreeNode* pointer = NULL;

	while (1)
	{
		char words[1000];
		if (scanf("%s", words) == EOF) break;

		addNode(words, &pointer);
	}

	printBST(pointer);
	return 0;
}
