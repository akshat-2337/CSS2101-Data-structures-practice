#include<stdio.h>
#include<stdlib.h>

struct node{
    int coef;
    int expon;
    struct node* next;
};

struct node* createnode(int coef, int expon){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));

    newnode->coef = coef;
    newnode->expon = expon;
    newnode->next = NULL;

    return newnode;
}

void insertend(struct node** head, int coef, int expon){

    struct node* tmp = createnode(coef, expon);

    if(*head == NULL){
        *head = tmp;
    }
    else{
        struct node* ptr = *head;

        while(ptr->next != NULL){
            ptr = ptr->next;
        }

        ptr->next = tmp;
    }
}

void display(struct node* head){

    struct node* ptr = head;

    while(ptr != NULL){
        printf("%dx^%d", ptr->coef, ptr->expon);

        if(ptr->next != NULL)
            printf(" + ");

        ptr = ptr->next;
    }

    printf("\n");
}

struct node* add(struct node* p1, struct node* p2){

    struct node* result = NULL;

    while(p1 != NULL && p2 != NULL){

        if(p1->expon > p2->expon){
            insertend(&result, p1->coef, p1->expon);
            p1 = p1->next;
        }

        else if(p1->expon < p2->expon){
            insertend(&result, p2->coef, p2->expon);
            p2 = p2->next;
        }

        else{
            int sum = p1->coef + p2->coef;

            if(sum != 0){
                insertend(&result, sum, p1->expon);
            }

            p1 = p1->next;
            p2 = p2->next;
        }
    }

    while(p1 != NULL){
        insertend(&result, p1->coef, p1->expon);
        p1 = p1->next;
    }

    while(p2 != NULL){
        insertend(&result, p2->coef, p2->expon);
        p2 = p2->next;
    }

    return result;
}

int main(){

    struct node* p1 = NULL;
    struct node* p2 = NULL;
    struct node* result = NULL;

    int n1, n2;
    int coef, expon;

    printf("Enter number of terms in first polynomial: ");
    scanf("%d", &n1);

    printf("Enter terms in descending order of exponent:\n");

    for(int i = 0; i < n1; i++){
        scanf("%d %d", &coef, &expon);
        insertend(&p1, coef, expon);
    }

    printf("Enter number of terms in second polynomial: ");
    scanf("%d", &n2);

    printf("Enter terms in descending order of exponent:\n");

    for(int i = 0; i < n2; i++){
        scanf("%d %d", &coef, &expon);
        insertend(&p2, coef, expon);
    }

    printf("\nFirst polynomial: ");
    display(p1);

    printf("Second polynomial: ");
    display(p2);

    result = add(p1, p2);

    printf("Result: ");
    display(result);

    return 0;
}