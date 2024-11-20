#include <stdio.h>
#include <stdlib.h>

// Define Node structure
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

// Function to check if the queue is empty
int isEmpty(struct Node* front) {
    return (front == NULL);
}

// Enqueue operation
void enqueue(struct Node** front, struct Node** rear, int data) {
    struct Node* newNode = createNode(data);
    if (isEmpty(*front)) {
        *front = *rear = newNode;
    } else {
        (*rear)->next = newNode;
        *rear = newNode;
    }
    printf("Enqueued: %d\n", data);
}

// Dequeue operation
void dequeue(struct Node** front) {
    if (isEmpty(*front)) {
        printf("Queue Underflow! The queue is empty.\n");
        return;
    }
    struct Node* temp = *front;
    *front = (*front)->next;
    printf("Dequeued: %d\n", temp->data);
    free(temp);
}

// Peek operation (view front element without removing it)
void peek(struct Node* front) {
    if (isEmpty(front)) {
        printf("Queue is empty.\n");
    } else {
        printf("Front element: %d\n", front->data);
    }
}

// Display operation
void display(struct Node* front) {
    if (isEmpty(front)) {
        printf("Queue is empty.\n");
        return;
    }
    struct Node* temp = front;
    printf("Queue: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* front = NULL;
    struct Node* rear = NULL;
    int choice, data;

    while (1) {
        // Display menu to user
        printf("\nQueue Operations Menu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Enqueue operation (Continuous input until -1 is entered)
                while (1) {
                    printf("Enter value to enqueue (Enter -1 to stop): ");
                    scanf("%d", &data);
                    if (data == -1) {
                        break; // Exit loop when -1 is entered
                    }
                    enqueue(&front, &rear, data);
                }
                break;

            case 2:
                // Dequeue operation
                dequeue(&front);
                break;

            case 3:
                // Peek operation
                peek(front);
                break;

            case 4:
                // Display the queue
                display(front);
                break;

            case 5:
                // Exit
                printf("Exiting the program.\n");
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
