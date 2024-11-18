#include <stdio.h>
#include <stdlib.h>

#define MAX 5  

struct Queue {
    int arr[MAX];
    int front, rear;
};


void initQueue(struct Queue* q) {
    q->front = -1;
    q->rear = -1;
}

int isEmpty(struct Queue* q) {
    return (q->front == -1);
}

int isFull(struct Queue* q) {
    return (q->rear == MAX - 1);
}

void insert(struct Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue Overflow! Cannot insert %d.\n", value);
    } else {
        if (q->front == -1) {
            q->front = 0;  // 
        }
        q->rear++;
        q->arr[q->rear] = value;
        printf("%d inserted into the queue.\n", value);
    }
}


void delete(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue Underflow! Cannot delete element.\n");
    } else {
        int deletedValue = q->arr[q->front];
        printf("%d deleted from the queue.\n", deletedValue);
        if (q->front == q->rear) {
            // Only one element in the queue
            q->front = q->rear = -1;
        } else {
            q->front++;
        }
    }
}


void display(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
    } else {
        printf("Queue elements are: ");
        for (int i = q->front; i <= q->rear; i++) {
            printf("%d ", q->arr[i]);
        }
        printf("\n");
    }
}

int main() {
    struct Queue q;
    int choice, value;

    initQueue(&q);  

    while (1) {
        printf("\nQueue Operations Menu:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                insert(&q, value);
                break;
            case 2:
                delete(&q);
                break;
            case 3:
                display(&q);
                break;
            case 4:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
