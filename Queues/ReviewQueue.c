#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 5

typedef struct {
    int items[MAX];
    int front;
    int rear;
} Queue;

void initQueue(Queue *Q);
int isFull(Queue Q);
int isEmpty(Queue Q);
void enqueue(Queue *Q, int elem);
void dequeue(Queue *Q);
int front(Queue Q);
void display(Queue *Q);

int main(){
    Queue test;
    initQueue(&test);

    enqueue(&test, 10);
    enqueue(&test, 20);
    enqueue(&test, 30);
    enqueue(&test, 40);
    display(&test);

    return 0;
}

void initQueue(Queue *Q){
    Q->front = 1;
    Q->rear = 0;
}

int isFull(Queue Q){
    return (Q.front == (Q.rear + 2) % MAX);
}

int isEmpty(Queue Q){
    return (Q.front == (Q.rear + 1) % MAX);
}

void enqueue(Queue *Q, int elem){
    if(!isFull(*Q)){
        Q->rear = (Q->rear + 1) % MAX;
        Q->items[Q->rear] = elem;
    }
}

void dequeue(Queue *Q){
    if(!isEmpty(*Q)){
        Q->front = (Q->front + 1) % MAX;
    }
}

int front(Queue Q){
    if(!isEmpty(Q)){
        return Q.items[Q.front];
    }
}

void display(Queue *Q){
    Queue temp;
    initQueue(&temp);

    while(!isEmpty(*Q)){
        dequeue(Q);
        enqueue(&temp, front(*Q));
    }

    while(!isEmpty(temp)){
        printf("%d ", front(*Q));
        dequeue(&temp);
        enqueue(Q, front(temp));
    }
}