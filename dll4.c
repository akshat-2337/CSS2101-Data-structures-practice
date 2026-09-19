#include<stdio.h>
#include<stdlib.h>

int main(){
    struct node {
        int data;
        struct node* prev;
        struct node* next;
    };

    // 1. Allocate memory for ALL nodes
    struct node *head = (struct node*)malloc(sizeof(struct node));
    struct node *mid  = (struct node*)malloc(sizeof(struct node));
    struct node *mid2 = (struct node*)malloc(sizeof(struct node));
    struct node *mid3 = (struct node*)malloc(sizeof(struct node));
    struct node *tail = (struct node*)malloc(sizeof(struct node));

    head->data=10; head->prev=NULL; head->next=mid;
    mid->data=20;  mid->prev=head;  mid->next=mid2;
    mid2->data=23; mid2->prev=mid;  mid2->next=mid3;
    mid3->data=25; mid3->prev=mid2; mid3->next=tail;
    tail->data=30; tail->prev=mid3; tail->next=NULL;

    // Create new node
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = 7;

    printf("Enter insertion position (e.g., 3): ");
    int x;
    scanf("%d", &x);

    // Traversal to find the position
    struct node *ptr = head;
    struct node *tmp = NULL;

    for(int i = 1; i < x; i++){
        tmp = ptr;
        ptr = ptr->next;
    }

    // 2. Correct Insertion Logic (Insert between tmp and ptr)
    tmp->next = newnode;
    newnode->prev = tmp;
    newnode->next = ptr;
    ptr->prev = newnode;

    // Print list
    struct node *ptr2 = head;
    while(ptr2 != NULL){
        printf("%d ", ptr2->data);
        ptr2 = ptr2->next;
    }
    printf("\n");

    return 0;
}