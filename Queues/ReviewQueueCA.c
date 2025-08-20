#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef struct{
    int elem[MAX];
    int front;
    int rear;
} CQUEUE;

void initQueue(CQUEUE *CQ);
void displayQueue(CQUEUE CQ);
void enQueue(CQUEUE *CQ, int data);
void deQueue(CQUEUE *CQ, int data);

int main(){
    CQUEUE Q;
    initQueue(&Q);

    enQueue(&Q, 10);
    enQueue(&Q, 20);
    enQueue(&Q, 30);
    displayQueue(Q);

    enQueue(&Q, 12);
    displayQueue(Q);

    deQueue(&Q, 12);
    deQueue(&Q, 10);
    displayQueue(Q);

    return 0;
}

void initQueue(CQUEUE *CQ){
    CQ->front = 1;
    CQ->rear = 0;
}

void enQueue(CQUEUE *CQ, int data){
    if((CQ->rear + 2) % MAX != CQ->front){
        CQ->rear = (CQ->rear + 1) % MAX;
        CQ->elem[CQ->rear] = data;
    }
}

void deQueue(CQUEUE *CQ, int data){
    if((CQ->rear + 1) % MAX != CQ->front){
        CQ->front = (CQ->front + 1) % MAX;
    }
}

void displayQueue(CQUEUE CQ){
    int x;

    for(x = CQ.front; x != (CQ.rear + 1) % MAX; x = (x + 1) % MAX){
        printf("%d ", CQ.elem[x]);
    }
    printf("\n\n");
}