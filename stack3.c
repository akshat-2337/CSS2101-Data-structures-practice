//implementation of stack using LL.
//self

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node{
    int data;
    struct node*next;
};

struct node *head =  NULL; //default initialisation

void push(int val){
    struct node * newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data=val;
    newnode->next=head;
    head=newnode;
    printf("Push succesfull \n");
}

void pop(){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp=head;
    head=head->next;
    printf("Popped data  : %d \n",temp->data);
    free(temp);
}

void peek(){
    if(head==NULL){
        printf("Stack is empty \n");
    }
    else{
        printf("Top element = %d", head->data);
    }
}

void display(){
    struct node *temp = head;
    printf("Stack : \n");
    while(temp!=NULL){
        printf(" %d",temp->data);
        temp=temp->next;
    }
    free(temp);
}

void isempty(){
    if(head==NULL){
        printf("\n Stack is empty");
    }
    else{
        printf("\n Stack is not empty");
    }
}

int main() {
    int choice, val;

    while(1) {
        printf("\n\n--- STACK USING LINKED LIST ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Check Empty\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                push(val);
                break;

            case 2:
                if(head == NULL)
                    printf("Stack is empty. Cannot pop.\n");
                else
                    pop();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                isempty();
                break;

            case 6:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}
