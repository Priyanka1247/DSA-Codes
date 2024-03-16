#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100


struct Queue {
    int items[MAX_SIZE];
    int front, rear;
};


void initializeQueue(struct Queue *queue) {
    queue->front = -1;
    queue->rear = -1;
}


int isEmpty(struct Queue *queue) {
    return (queue->front == -1);
}


int isFull(struct Queue *queue) {
    return ((queue->rear + 1) % MAX_SIZE == queue->front);
}


void enqueue(struct Queue *queue, int value) {
    if (isFull(queue)) {
        printf("Queue overflow. Cannot enqueue element.\n");
        return;
    }
    if (isEmpty(queue)) {
        queue->front = 0;
    }
    queue->rear = (queue->rear + 1) % MAX_SIZE;
    queue->items[queue->rear] = value;
}


int dequeue(struct Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue underflow. Cannot dequeue element.\n");
        return -1;
    }
    int dequeuedItem = queue->items[queue->front];
    if (queue->front == queue->rear) {

        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % MAX_SIZE;
    }
    return dequeuedItem;
}


void display(struct Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    int i = queue->front;
    while (i != queue->rear) {
        printf("%d ", queue->items[i]);
        i = (i + 1) % MAX_SIZE;
    }
    printf("%d\n", queue->items[i]);
}

int main() {

    struct Queue queue;
    initializeQueue(&queue);


    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);


    display(&queue);


    printf("Dequeued element: %d\n", dequeue(&queue));


    display(&queue);

    return 0;
}
