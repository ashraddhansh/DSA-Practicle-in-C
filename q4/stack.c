#include <stdio.h>
#include <stdlib.h>

#define MAX 10  // Define the maximum size of the stack

// Structure to represent a stack
struct Stack {
    int arr[MAX];
    int top;
};

// Function to initialize the stack
void initStack(struct Stack* stack) {
    stack->top = -1;  // Stack is empty initially
}

// Function to check if the stack is full
int isFull(struct Stack* stack) {
    return stack->top == MAX - 1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to push an element onto the stack
void push(struct Stack* stack) {
    int value;
    while (1) {
        if (isFull(stack)) {
            printf("Stack overflow! Unable to push more elements.\n");
            return;  // Exit the loop if the stack is full
        }

        printf("Enter value to push (or -1 to stop pushing): ");
        scanf("%d", &value);
        if (value == -1) {
            return;  // Exit the loop if user inputs -1
        }

        stack->arr[++stack->top] = value;  // Increment top and insert element
        printf("%d pushed to stack\n", value);
    }
}

// Function to pop an element from the stack
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow! Unable to pop\n");
        return -1;  // Indicating stack is empty
    } else {
        return stack->arr[stack->top--];  // Return the element and decrement top
    }
}

// Function to get the top element of the stack without popping
int peek(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return -1;  // Indicating stack is empty
    } else {
        return stack->arr[stack->top];  // Return the top element
    }
}

// Function to display the stack
void display(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements: ");
        for (int i = 0; i <= stack->top; i++) {
            printf("%d ", stack->arr[i]);
        }
        printf("\n");
    }
}

// Main function to test stack operations
int main() {
    struct Stack stack;
    initStack(&stack);  // Initialize the stack

    int choice, value;

    while (1) {
        printf("\nStack Operations:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push(&stack);  // Push elements until user decides to stop
                break;
            case 2:
                value = pop(&stack);
                if (value != -1) {
                    printf("Popped element: %d\n", value);
                }
                break;
            case 3:
                value = peek(&stack);
                if (value != -1) {
                    printf("Top element is: %d\n", value);
                }
                break;
            case 4:
                display(&stack);
                break;
            case 5:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
