#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int x) {
    if (top < MAX - 1) {
        stack[++top] = x;
    }
}

int pop() {
    if (top >= 0) {
        return stack[top--];
    }
    return 0; // Return zero or handle stack underflow
}

int main() {
    char ip[100];

    printf("Enter prefix expression: ");
    if (scanf("%99s", ip) != 1) return 1;

    for (int i = strlen(ip) - 1; i >= 0; i--) {

        if (ip[i] >= '0' && ip[i] <= '9') {
            int x = ip[i] - '0';
            push(x);
        }
        else if (ip[i] == '+') {
            int a = pop();
            int b = pop();
            push(a + b);
        }
        else if (ip[i] == '-') {
            int a = pop();
            int b = pop();
            push(a - b);
        }
        else if (ip[i] == '*') {
            int a = pop();
            int b = pop();
            push(a * b);
        }
        else if (ip[i] == '/') {
            int a = pop();
            int b = pop();
            push(b != 0 ? a / b : 0); // Avoid division by zero
        }
        else if (ip[i] == '^') {
            int a = pop();
            int b = pop();
            push((int)pow(a, b));
        }
    }

    printf("Final result = %d\n", pop());

    return 0;
}