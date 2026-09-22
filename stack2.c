// stack implementation using LL

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node *top = NULL; // initializing top pointer to NULL

void push(int val){
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    if(!newNode){
        printf("Stack Overflow \n");
    }
    else{
        newNode->data = val;
        newNode->next = top;
        top = newNode;
        printf("Pushed to stack \n");
    }
}

void pop(){
    if(top == NULL){
        printf("Stack Underflow \n");
    }
    else{
        struct node *temp = top; // Direct pointer assignment without extra malloc
        printf("Popped data = %d\n", temp->data);
        top = top->next;
        free(temp);
    }
}

void peek(){
    if(top == NULL){
        printf("Stack is empty \n");
    }
    else{
        printf("The top element is = %d\n", top->data);
    }
}

void isempty(){
    if(top == NULL){
        printf("Stack is empty\n");
    }
    else{
        printf("Stack is not empty\n");
    }
}

void display(){
    struct node *temp = top;
    if(temp == NULL){
        printf("Stack is empty \n");
    }
    else{
        while(temp != NULL){ // Fixed uppercase NULL
            printf(" %d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    int choice, value;

    while (1) {
        printf("\n1. Push\n2. Pop\n3. Peek\n4. isEmpty\n5. Display\n6. Exit\n");
        printf("Enter your choice: ");
        
        if (scanf("%d", &choice) != 1) {
            break;
        }

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;

            case 2:
                pop();
                break;

            case 3:
                peek();
                break;

            case 4:
                isempty();
                break;

            case 5:
                display();
                break;

            case 6:
                printf("Exiting program...\n");
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }

    return 0;
}