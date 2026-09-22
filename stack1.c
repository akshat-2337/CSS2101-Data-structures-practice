#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 5

int stack[MAX];
int top = -1;

void push(int item){
    if(top == MAX - 1){
        printf("Stack full \n");
    } else {
        stack[++top] = item;
    }
}

void pop(){
    if(top == -1){
        printf("Stack empty\n");
    } else {
        printf("Popped: %d\n", stack[top]);
        --top;
    }
}

void peek(){
    if(top == -1){
        printf("Stack empty\n");
    } else {
        printf("Top element: %d\n", stack[top]);
    }
}

void isempty(){
    if(top == -1){
        printf("Stack is empty\n");
    } else {
        printf("Stack is not empty\n");
    }
}

void display(){
    if(top == -1) {
        printf("Stack empty\n");
        return;
    }
    printf("Stack elements: ");
    for(int i = top; i >= 0; i--){
        printf("%d ", stack[i]);
    }
    printf("\n");
}

void input(){
    printf("Enter %d items for stack:\n", MAX);
    for(int i = 0; i < MAX; i++){
        int x;
        scanf("%d", &x);
        push(x);
    }
}

int main(){
    int choice;
    
    while(true){
        printf("\n--- STACK MENU ---\n");
        printf("1. Enter stack\n");
        printf("2. PUSH\n");
        printf("3. POP\n");
        printf("4. PEEK\n");
        printf("5. DISPLAY\n");
        printf("6. STATUS\n");
        printf("7. EXIT\n");
        printf("Enter your choice: ");
        
        if (scanf("%d", &choice) != 1) break;

        if(choice == 1){
            input();
        } else if(choice == 2){
            int y;
            printf("Enter value to push: ");
            scanf("%d", &y);
            push(y);
        } else if(choice == 3){
            pop();
        } else if(choice == 4){
            peek();
        } else if(choice == 5){
            display();
        } else if(choice == 6){
            isempty();
        } else if(choice == 7){
            printf("Exiting program...\n");
            break;
        } else {
            printf("Invalid choice! Try again.\n");
        }
    }
    
    return 0;
}