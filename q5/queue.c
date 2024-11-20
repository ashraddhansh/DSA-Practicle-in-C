#include <stdio.h>
#include <stdlib.h>

#define MAX 5 // Define the maximum size of the queue

// Queue structure with front, rear, and the array to store elements
int queue[MAX];
int front = -1, rear = -1;

// Function to check if the queue is full
int isFull() {
    return (rear == MAX - 1);
}

// Function to check if the queue is empty
int isEmpty() {
    return (front == -1 || front > rear);
}

// Function to add an element to the queue (Enqueue operation)
void enqueue(int value) {
    if (isFull()) {
        printf("Queue Overflow! Cannot enqueue %d\n", value);
    } else {
        if (front == -1) { // If queue is empty, set front to 0
            front = 0;
        }
        rear++;
        queue[rear] = value; // Insert element at rear
        printf("Enqueued: %d\n", value);
    }
}

// Function to remove an element from the queue (Dequeue operation)
void dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow! No elements to dequeue.\n");
    } else {
        printf("Dequeued: %d\n", queue[front]);
        front++; // Increment front to remove the element
    }
}

// Function to peek at the front element of the queue
void peek() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
    } else {
        printf("Front element: %d\n", queue[front]);
    }
}

// Function to display all elements in the queue
void display() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, value;

    while (1) {
        // Display menu for the user
        printf("\nQueue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");

        // Read user's choice
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Enqueue (Push)
                do {
                    printf("Enter value to enqueue (or -1 to stop): ");
                    scanf("%d", &value);
                    if (value != -1) {
                        enqueue(value);
                    }
                } while (value != -1);
                break;

            case 2: // Dequeue
                dequeue();
                break;

            case 3: // Peek
                peek();
                break;

            case 4: // Display
                display();
                break;

            case 5: // Exit
                printf("Exiting program.\n");
                exit(0);
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
