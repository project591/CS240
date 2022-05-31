//FINAL1 DIOS
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct STUDENT {
    char* name; // store name of student
    int age;
};

struct STUDENT_NODE {
    struct STUDENT std;
    struct STUDENT_NODE* next;
};

struct STUDENT_NODE* createLinkedList(struct STUDENT a[], int n) {
    // create a linked list copying from an array of n students
    // return the linked list created

    if (n == 0) return NULL; // return a NULL pointer if there is no student

    struct STUDENT_NODE* first_node;
    first_node = malloc(sizeof(struct STUDENT_NODE));
    first_node->next = NULL;
    first_node->std = a[0]; // first student


    struct STUDENT_NODE* last_node; // always address of (currently) last node in the list
    last_node = first_node;

    for (int i = 1; i <= n - 1; i++) {
        // create a new node store student a[i]
        // extend the list to add this node
        struct STUDENT_NODE* new_node;
        new_node = malloc(sizeof(struct STUDENT_NODE));
        new_node->std = a[i];
        new_node->next = NULL;

        last_node->next = new_node;
        last_node = new_node;
    }
    return first_node;

}

void printStudent(struct STUDENT x) {
    // print all info of student x
    printf("Student name: %s, age: %d", x.name, x.age);
}
void printLinkedList(struct STUDENT_NODE* list) {
    while (list != NULL) {
        printStudent(list->std); // print the student at the current node
        list = list->next;
        if (list != NULL) printf("\n");
    }
}

struct STUDENT_NODE* removeLastNode(struct STUDENT_NODE* list) {
    // remove last node from list and return new list
    // complete this function ...
    // ...
    struct STUDENT_NODE* holdList = list;
    struct STUDENT_NODE* temp = NULL;
    if (list->next == NULL)
    {
        free(list);
        list = NULL;
    }
    else
    {
        while (holdList->next != NULL)
        {
            temp = holdList;
            holdList = holdList->next;
        }
        free(temp->next);
        temp->next = NULL;
    }
    return list;
}

int main() {
    struct STUDENT students[100];
    int n = 0;
    char name[100];

    while (1) {
        int age;
        if (scanf("%s %d", name, &age) == EOF) break;
        students[n].name = malloc(strlen(name) + 1);
        strcpy(students[n].name, name);
        students[n].age = age;
        n++;
        if (n == 100) break;
    }

    struct STUDENT_NODE* list = createLinkedList(students, n);
    list = removeLastNode(list);
    printLinkedList(list);

    return 0;
}


