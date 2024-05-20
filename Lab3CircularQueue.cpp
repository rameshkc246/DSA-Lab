#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Define the circular queue structure
struct CircularQueue {
    int items[MAX_SIZE];
    int front, rear;
};

// Function to initialize the circular queue
void initialize(struct CircularQueue *queue) {
    queue->front = -1;
    queue->rear = -1;
}

// Function to check if the circular queue is empty
int isEmpty(struct CircularQueue *queue) {
    return queue->front == -1;
}

// Function to check if the circular queue is full
int isFull(struct CircularQueue *queue) {
    return (queue->front == 0 && queue->rear == MAX_SIZE - 1) || (queue->front == queue->rear + 1);
}

// Function to enqueue (insert) an element into the circular queue
void enqueue(struct CircularQueue *queue, int item) {
    if (isFull(queue)) {
        printf("Queue is full. Cannot enqueue.\n");
    } else {
        if (isEmpty(queue)) {
            queue->front = 0;
        }
        queue->rear = (queue->rear + 1) % MAX_SIZE;
        queue->items[queue->rear] = item;
        printf("%d enqueued into the circular queue.\n", item);
    }
}

// Function to dequeue (remove) an element from the circular queue
int dequeue(struct CircularQueue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1; // Return a sentinel value to indicate failure
    } else {
        int item = queue->items[queue->front];
        if (queue->front == queue->rear) {
            queue->front = -1;
            queue->rear = -1;
        } else {
            queue->front = (queue->front + 1) % MAX_SIZE;
        }
        return item;
    }
}

// Function to display the elements of the circular queue
void display(struct CircularQueue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements:\n");
        int i = queue->front;
        do {
            printf("%d\n", queue->items[i]);
            i = (i + 1) % MAX_SIZE;
        } while (i != (queue->rear + 1) % MAX_SIZE);
    }
}

int main() {
    struct CircularQueue queue;
    initialize(&queue);
    int choice, item;

    while (1) {
        printf("\nCircular Queue Menu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Quit\n");

        printf("Enter your choice (1/2/3/4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to enqueue: ");
                scanf("%d", &item);
                enqueue(&queue, item);
                break;
            case 2:
                item = dequeue(&queue);
                if (item != -1) {
                    printf("Dequeued element: %d\n", item);
                }
                break;
            case 3:
                display(&queue);
                break;
            case 4:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

