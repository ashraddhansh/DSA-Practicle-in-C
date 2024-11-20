#include <stdio.h>
#include <stdlib.h>

// Define a node structure for the linked list
struct Node {
    int data;
    struct Node* next;
};

// Define a circular queue structure
struct CircularQueue {
    struct Node* front;
    struct Node* rear;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to initialize the circular queue
void initQueue(struct CircularQueue* queue) {
    queue->front = queue->rear = NULL;
}

// Function to check if the queue is empty
int isEmpty(struct CircularQueue* queue) {
    return queue->front == NULL;
}

// Function to enqueue an element into the circular queue
void enqueue(struct CircularQueue* queue, int data) {
    struct Node* newNode = createNode(data);
    if (isEmpty(queue)) {
        queue->front = queue->rear = newNode;
        newNode->next = queue->front; // Circular link
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
        queue->rear->next = queue->front; // Circular link
    }
    printf("Enqueued: %d\n", data);
}

// Function to dequeue an element from the circular queue
void dequeue(struct CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Queue Underflow: Queue is empty\n");
        return;
    }

    struct Node* temp = queue->front;
    if (queue->front == queue->rear) {
        queue->front = queue->rear = NULL;
    } else {
        queue->front = queue->front->next;
        queue->rear->next = queue->front;
    }

    printf("Dequeued: %d\n", temp->data);
    free(temp);
}

// Function to peek the front element of the queue
void peek(struct CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
    } else {
        printf("Front element: %d\n", queue->front->data);
    }
}

// Function to check if the queue is empty
int size(struct CircularQueue* queue) {
    if (isEmpty(queue)) {
        return 0;
    }

    int count = 0;
    struct Node* temp = queue->front;
    do {
        count++;
        temp = temp->next;
    } while (temp != queue->front);
    return count;
}

// Function to display the elements of the circular queue
void display(struct CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return;
    }

    struct Node* temp = queue->front;
    printf("Queue elements: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != queue->front);
    printf("\n");
}

// Main function to drive the circular queue operations
int main() {
    struct CircularQueue queue;
    initQueue(&queue);
    
    int choice, data;
    
    while (1) {
        printf("\nCircular Queue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Size\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue (-1 to stop): ");
                while (1) {
                    scanf("%d", &data);
                    if (data == -1) {
                        break;
                    }
                    enqueue(&queue, data);
                }
                break;
            
            case 2:
                dequeue(&queue);
                break;

            case 3:
                peek(&queue);
                break;

            case 4:
                display(&queue);
                break;
            
            case 5:
                printf("Queue size: %d\n", size(&queue));
                break;

            case 6:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}
