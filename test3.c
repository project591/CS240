#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct NODE {
	char* word; 
	struct node* next;  
};

// Using recursive function to print the linked list. 
void reversePrint(struct NODE* head_value)
{
	if (head_value == NULL)
		return;

	reversePrint(head_value->next);
	
	if (head_value->next != NULL)
		printf(",%s", head_value->word); // If there is a value then you should put comma behind it. Opposite of first part
	else
		printf("%s", head_value->word); //If there is no next value, just simply print the word. 

	head_value= head_value->next;	
}

int main() {

	struct NODE* list = NULL;
	struct NODE* first_node = NULL;

	//This is where I fill the Linked List
	while (1)
	{
		char* letters;
		letters = malloc(sizeof(char*) * 10000);

		if (scanf("%s", letters) == EOF) break;

		struct NODE* node;
		node = malloc(sizeof(struct NODE));

		node->word = letters;
		node->next = NULL;

		if (list == NULL) {

			list = node;
			first_node = node;

		}
		else {
			list->next = node;
			list = node;
		}
	}

	struct NODE* pt;
	pt = first_node;
	int position = 0;

	// Solution to the second part of the exam. 
	reversePrint(pt);

	// Solution to first part of the test
	/*while (1){
		if (pt != NULL) {
			position++;
			// This is the solution!
			if (pt->next != NULL)
				printf("%s,", pt->word);
			else
				printf("%s", pt->word);
			
			pt = pt->next;
		}
		else
			break;
 }*/
	return 0;
}

