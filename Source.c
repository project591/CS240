#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {

	int key;
	struct TreeNode* parent;
	struct TreeNode* left;
	struct TreeNode* right;
};

struct TreeNode* addNode(int key, struct TreeNode* root) {

	if (root == NULL) {
		
		struct TreeNode* newnode;
		newnode = malloc(sizeof(struct TreeNode));
		newnode->key = key;
		newnode->parent = NULL;
		newnode->left = NULL;
		newnode->right = NULL;

		return newnode;
	}

	if (key < root->key) {
		// compare with value at root of tree
		// less than 
		struct TreeNode* leftNode = addNode(key, root->left);
		root->left = leftNode;
		leftNode->parent = root;
	}
	else if(key > root->key) {
		struct TreeNode* rightNode = addNode(key, root->right);
		root->right = rightNode;
		rightNode ->parent = root;
	}
	return root;
}

void printBST(struct TreeNode* root)
{
	if (root != NULL)
	{
		printBST(root->left);
		printf("Node: %d, ", root->key);
		if (root->parent == NULL)
			printf("Parent: NULL\n");
		else
			printf("Parent: %d\n", root->parent->key);
		printBST(root->right);
	}
}

int main() {

	struct TreeNode* pointer = NULL;
	int n = 0;

	while (1)
	{
		if (n == -1) break;

		if(scanf("%d", &n) == -1) break;

		if( n != -1) 
		pointer = addNode(n, pointer);
	}

	/*addNode(12,&pointer);
	addNode(50, &pointer);
	addNode(5, &pointer);
	addNode(10, &pointer);
	addNode(9, &pointer);
	addNode(20, &pointer);
	addNode(7, &pointer);
	addNode(6, &pointer);
	*/
	printBST(pointer);

	return 0;
}
