#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* head = NULL;

struct node* createnode(int val){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));

    newnode->data = val;
    newnode->next = NULL;

    return newnode;
}

void insertend(int val){
    struct node* tmp = createnode(val);

    if(head == NULL){
        head = tmp;
    }
    else{
        struct node* ptr = head;

        while(ptr->next != NULL){
            ptr = ptr->next;
        }

        ptr->next = tmp;
    }
}

void display(){
    struct node* ptr = head;

    while(ptr != NULL){
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }

    printf("\n");
}

struct node* reverse(){
    struct node* prev = NULL;
    struct node* curr = head;
    struct node* next;

    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

int main(){

    insertend(10);
    insertend(20);
    insertend(30);
    insertend(40);

    printf("Original list: ");
    display();

    reverse();

    printf("Reversed list: ");
    display();

    return 0;
}