#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100


struct Stack {
    int items[MAX_SIZE];
    int top;
};


void initializeStack(struct Stack *stack) {
    stack->top = -1;
}


int isEmpty(struct Stack *stack) {
    return (stack->top == -1);
}


int isFull(struct Stack *stack) {
    return (stack->top == MAX_SIZE - 1);
}


void push(struct Stack *stack, int value) {
    if (isFull(stack)) {
        printf("Stack overflow. Cannot push element.\n");
        return;
    }
    stack->items[++stack->top] = value;
}


int pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow. Cannot pop element.\n");
        return -1;
    }
    return stack->items[stack->top--];
}


void display(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = stack->top; i >= 0; i--) {
        printf("%d ", stack->items[i]);
    }
    printf("\n");
}


int peek(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        return -1;
    }
    return stack->items[stack->top];
}

int main() {

    struct Stack stack;
    initializeStack(&stack);


    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);


    display(&stack);


    printf("Top element of the stack: %d\n", peek(&stack));


    printf("Popped element: %d\n", pop(&stack));


    display(&stack);

    return 0;
}
