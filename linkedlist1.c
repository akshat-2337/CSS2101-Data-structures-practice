#include<stdio.h>
#include<stdlib.h>

int main(){

    struct Node   //Node's structure
    {
        int data;  //data of node
        struct Node* next;  //address of next node
    };

    struct Node *head, *newnode, *tail; //creating 2 nodes a header node and a new node.
    
    head  =  (struct Node *) malloc (sizeof(struct Node));
    newnode  =  (struct Node *) malloc (sizeof(struct Node));
    tail = (struct Node *) malloc(sizeof(struct Node));

    head->next = newnode;
    head->data = 23;

    newnode->data=37;
    newnode->next=tail;

    tail->data=0;
    tail->next=NULL;

    
    //traversal of linked list

    struct Node *temp; //creating a temporary node to traverse the linked list (points at the head node)
    temp=head;
    
    while(temp!=NULL){  //temp is a pointer so it knows when it reaches the end of the linked list..

        printf(" %d \n", temp->data);
        temp=temp->next;
    }

    free(head);
    free(newnode);
    free(tail);
    
}