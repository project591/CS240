#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define maximum length of lines */
#define MAXTEXT 10000
//#define MAXWORD 100

struct Node
{
    char* word;
    struct Node* next;
    struct Node* prev;
    struct Node* first;
    struct Node* last;
};

void addNewNodeToTheEnd(char* newWord, struct Node** head_address)
{
    // Create and allocate new node
    struct Node* new_node = malloc(sizeof(struct Node));
    // Create a pointer to point to the head
    struct Node* head = *head_address;

    // Create the data
    new_node->word = malloc(strlen(newWord) + 1);
    strcpy(new_node->word, newWord);
    new_node->next = NULL;
    new_node->prev = NULL;
    new_node->first = head; // Will be pointing to the first node
    new_node->last = new_node; // Will be pointing to the last node

    // If the value at head is NULL, new node becomes the head
    if (head == NULL)
    {
        *head_address = new_node;
        new_node->first = new_node;
    }
    // Otherwise, traverse head until the end, then append the new node
    else
    {
        while (head->next != NULL)
        {
            head->last = new_node;
            head = head->next;
        }

        head->last = new_node; // Why is this code repeating?
        new_node->prev = head;
        head->next = new_node;
    }
}

void printList(struct Node* head)
{
    while (head != NULL)
    {
        // If end of linked list, print without ","
        if (head->next == NULL)
        {
            printf("%s", head->word);
        }
        else
        {
            printf("%s,", head->word);
        }

        head = head->next; // This is to continue printing the linked list.
    }
}

void printFromBack(struct Node* head)
{
    while (head->next != NULL)
    {
        head = head->next;
    }

    while (head != NULL)
    {
        if (head->prev == NULL)
            printf("%s", head->word);
        else
            printf("%s,", head->word);

        head = head->prev;
    }
}

int findDuplicates(char* newWord, struct Node* head)
{
    while (head != NULL)
    {
        if (strcmp(newWord, head->word) == 0)
            return 1;

        head = head->next;
    }
    return 0;
}

// There is a better way to write this code. 
void deleteNode(int x, struct Node** head_address)
{
    struct Node* curr = *head_address;
    struct Node* head = *head_address;

    // Find node position
    for (int i = 1; i < x; i++)
    {
        if (curr->next != NULL)
        {
            curr = curr->next;
        }
        else
        {
            return;
        }
    }

    // If node to be deleted is at beginning
    if (*head_address == curr)
    {
        // Set head to next address
        *head_address = curr->next;

        // Set the prev of next node to current node's prev if it exists
        // Edge case for deleting last node in list
        if (curr->next != NULL)
            curr->next->prev = curr->prev;

        // Set all first pointer to point to the next node
        while (head->next != NULL)
        {
            head = head->next;
            head->first = curr->next;
        }
    }
    // If node to be deleted is at end
    else if (curr->next == NULL)
    {
        curr->prev->next = NULL;

        // Set all last pointer to point to the 2nd last node
        while (head->next != NULL)
        {
            head->last = curr->prev;
            head = head->next;
        }
        head->last = curr->prev;
    }
    // If node to be deleted is at middle
    else
    {
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
    }

    free(curr);
}

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    struct Node* list = NULL;
    int a, b, c;
    char line[MAXTEXT];
    char* str;

    // Get string input and positions to be deleted
    // scanf("%[^\n]s", line);

    fgets(line, MAXTEXT, stdin);
    scanf("%d %d %d", &a, &b, &c);

    // Split the string by whitespace add new node to the linkedlist
    str = strtok(line, " ");
    while (str != NULL)
    {
        if (findDuplicates(str, list) != 1)
            addNewNodeToTheEnd(str, &list);
        str = strtok(NULL, " ");
    }

    // Sort the positions to be deleted to be ascending value
    int pos[] = { a, b, c };

    if (pos[0] > pos[1])
        swap(&pos[0], &pos[1]);

    if (pos[0] > pos[2])
        swap(&pos[0], &pos[2]);

    if (pos[1] > pos[2])
        swap(&pos[1], &pos[2]);

    // Perform node deletion
    if (list != NULL)
    {
        for (int i = 0; i < 3; i++)
        {
            deleteNode(pos[i] - i, &list);
        }
    }

    // Print the linked list
    printList(list);

    return 0;
}