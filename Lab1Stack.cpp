#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Define the stack structure
struct Stack {
    int items[MAX_SIZE];
    int top;
};

// Function to initialize the stack
void initialize(struct Stack *stack) {
    stack->top = -1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack *stack) {
    return stack->top == -1;
}

// Function to check if the stack is full
int isFull(struct Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}

// Function to push an element onto the stack
void push(struct Stack *stack, int item) {
    if (isFull(stack)) {
        printf("Stack is full. Cannot push.\n");
    } else {
        stack->items[++stack->top] = item;
        printf("%d pushed onto the stack.\n", item);
    }
}

// Function to pop an element from the stack
int pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty. Cannot pop.\n");
        return -1; // Return a sentinel value to indicate failure
    } else {
        int item = stack->items[stack->top--];
        return item;
    }
}

// Function to peek at the top element of the stack
int peek(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        return -1; // Return a sentinel value to indicate failure
    } else {
        return stack->items[stack->top];
    }
}

// Function to display the elements of the stack
void display(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack elements:\n");
        for (int i = 0; i <= stack->top; i++) {
            printf("%d\n", stack->items[i]);
        }
    }
}

int main() {
    struct Stack stack;
    initialize(&stack);
    int choice, item;

    while (1) {
        printf("\nStack Menu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Quit\n");

        printf("Enter your choice (1/2/3/4/5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to push: ");
                scanf("%d", &item);
                push(&stack, item);
                break;
            case 2:
                item = pop(&stack);
                if (item != -1) {
                    printf("Popped element: %d\n", item);
                }
                break;
            case 3:
                item = peek(&stack);
                if (item != -1) {
                    printf("Top element: %d\n", item);
                }
                break;
            case 4:
                display(&stack);
                break;
            case 5:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

