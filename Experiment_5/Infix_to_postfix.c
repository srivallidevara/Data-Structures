#include <stdio.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char symbol) {
    if (top < MAX - 1) {
        stack[++top] = symbol;
    }
}

char pop() {
    if (top == -1) {
        return '\0';
    }

    return stack[top--];
}

char peek() {
    if (top == -1) {
        return '\0';
    }

    return stack[top];
}

int precedence(char symbol) {
    switch (symbol) {
        case '^':
            return 3;

        case '*':
        case '/':
        case '%':
            return 2;

        case '+':
        case '-':
            return 1;

        default:
            return 0;
    }
}

int isOperator(char symbol) {
    return symbol == '+' || symbol == '-' ||
           symbol == '*' || symbol == '/' ||
           symbol == '%' || symbol == '^';
}

void infixToPostfix(char infix[]) {
    char postfix[MAX];
    int i = 0, j = 0;
    char symbol;

    top = -1;

    while (infix[i] != '\0') {
        symbol = infix[i];

        if (symbol == ' ' || symbol == '\t') {
            i++;
            continue;
        }

        if (isalnum((unsigned char)symbol)) {
            postfix[j++] = symbol;
        }
        else if (symbol == '(') {
            push(symbol);
        }
        else if (symbol == ')') {
            while (top != -1 && peek() != '(') {
                postfix[j++] = pop();
            }

            if (top == -1) {
                printf("Invalid expression!\n");
                return;
            }

            pop();
        }
        else if (isOperator(symbol)) {
            while (top != -1 && peek() != '(' &&
                  (precedence(peek()) > precedence(symbol) ||
                  (precedence(peek()) == precedence(symbol)
                   && symbol != '^'))) {
                postfix[j++] = pop();
            }

            push(symbol);
        }
        else {
            printf("Invalid character: %c\n", symbol);
            return;
        }

        i++;
    }

    while (top != -1) {
        if (peek() == '(') {
            printf("Invalid expression!\n");
            return;
        }

        postfix[j++] = pop();
    }

    postfix[j] = '\0';

    printf("Infix Expression   : %s\n", infix);
    printf("Postfix Expression : %s\n", postfix);
}

int main() {
    char infix[MAX];

    printf("Enter an infix expression: ");
    if (fgets(infix, sizeof(infix), stdin) == NULL) {
        return 1;
    }

    infixToPostfix(infix);

    return 0;
}