#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

char stack[MAX];
int top = -1;

void push(char ch) {
    if(top == MAX-1) {
        printf("Stack full\n");
    }
    else {
        stack[++top] = ch;
    }
}

char pop() {
    return stack[top--];
}

int main() {

    char par[100];

    printf("Enter parenthesis to validate: ");
    scanf("%s", par);

    int len = strlen(par);
    int flag = 1;

    for(int i = 0; i < len; i++) {

        char ch = par[i];

        if(ch == '(' || ch == '{' || ch == '[') {
            push(ch);
        }
        else {

            if(top == -1) {
                flag = 0;
                break;
            }

            char z = pop();

            if(!((z == '{' && ch == '}') ||
                 (z == '(' && ch == ')') ||
                 (z == '[' && ch == ']'))) {

                flag = 0;
                break;
            }
        }
    }

    if(flag == 1 && top == -1) {
        printf("VALID PARENTHESIS!");
    }
    else {
        printf("INVALID PARENTHESIS");
    }

    return 0;
}