//Problem Statement:
//Detect whether a given singly linked list contains a cycle using Floyd’s cycle-finding algorithm.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node* next;
};

bool hasCycle(struct Node *head) {
    struct Node *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return true;
    }
    return false;
}

int main() {
    // Create list: 1->2->3->4->5 with a cycle: 5->3
    struct Node* head = malloc(sizeof(struct Node));
    head->data = 1;
    head->next = malloc(sizeof(struct Node));
    head->next->data = 2;
    head->next->next = malloc(sizeof(struct Node));
    head->next->next->data = 3;
    head->next->next->next = malloc(sizeof(struct Node));
    head->next->next->next->data = 4;
    head->next->next->next->next = malloc(sizeof(struct Node));
    head->next->next->next->next->data = 5;
    head->next->next->next->next->next = head->next->next; // Creating cycle

    if (hasCycle(head))
        printf("Cycle detected\n");
    else
        printf("No cycle\n");

    return 0;
}

//Expected Output:

//Cycle detected

