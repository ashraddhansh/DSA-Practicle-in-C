#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the stack
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to check if the stack is empty
int isEmpty(struct Node* top) {
    return top == NULL;
}

// Function to push an element onto the stack
void push(struct Node** top, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *top;
    *top = newNode;
    printf("Pushed: %d\n", data);
}

// Function to pop an element from the stack
void pop(struct Node** top) {
    if (isEmpty(*top)) {
        printf("Stack Underflow! No elements to pop.\n");
    } else {
        struct Node* temp = *top;
        *top = (*top)->next;
        printf("Popped: %d\n", temp->data);
        free(temp);
    }
}

// Function to peek at the top element of the stack
void peek(struct Node* top) {
    if (isEmpty(top)) {
        printf("Stack is empty.\n");
    } else {
        printf("Top element: %d\n", top->data);
    }
}

// Function to display all elements in the stack
void display(struct Node* top) {
    if (isEmpty(top)) {
        printf("Stack is empty.\n");
    } else {
        struct Node* temp = top;
        printf("Stack elements: ");
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    struct Node* stack = NULL;
    int choice, value;

    while (1) {
        // Display menu for the user
        printf("\nStack Operations:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");

        // Read user's choice
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Push continuously
                printf("Enter value to push (-1 to stop): ");
                while (1) {
                    scanf("%d", &value);
                    if (value == -1) {
                        break;
                    }
                    push(&stack, value);
                    printf("Enter next value to push (-1 to stop): ");
                }
                break;

            case 2: // Pop
                pop(&stack);
                break;

            case 3: // Peek
                peek(stack);
                break;

            case 4: // Display
                display(stack);
                break;

            case 5: // Exit
                printf("Exiting program.\n");
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
