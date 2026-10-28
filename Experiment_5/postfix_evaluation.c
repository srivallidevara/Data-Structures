#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow!\n");
        exit(1);
    }

    stack[++top] = value;
}

int pop() {
    if (top == -1) {
        printf("Invalid Postfix Expression!\n");
        exit(1);
    }

    return stack[top--];
}

int evaluatePostfix(char postfix[]) {
    int i, a, b, result;
    char symbol;

    for (i = 0; postfix[i] != '\0'; i++) {
        symbol = postfix[i];

        if (symbol == ' ' || symbol == '\t') {
            continue;
        }

        if (isdigit((unsigned char)symbol)) {
            push(symbol - '0');
        }
        else {
            b = pop();
            a = pop();

            switch (symbol) {
                case '+':
                    result = a + b;
                    break;

                case '-':
                    result = a - b;
                    break;

                case '*':
                    result = a * b;
                    break;

                case '/':
                    if (b == 0) {
                        printf("Division