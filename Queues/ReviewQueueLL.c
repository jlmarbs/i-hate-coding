#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX 5

typedef struct node{
    int data;
    struct node *link;
} *LQueue;

typedef struct{
    LQueue front;
    LQueue rear;
} Queue;

void initQueue(Queue *Q);
void enQueue(Queue *Q, int data);
void deQueue(Queue *Q);
void displayQueue(Queue Q);

int main(){

    return 0;
}

void initQueue(Queue *Q){
    Q->front = NULL;
    Q->rear = NULL;
}

void enQueue(Queue *Q, int data){
    LQueue newNode = (LQueue)malloc(sizeof(struct node));
    if(newNode != NULL){
        newNode->data = data;
        newNode->link = NULL;

        if(Q->front == NULL){
            Q->front = newNode;
        }
    }
}

void deQueue(Queue *Q){
    if(Q->front != NULL){
        LQueue temp;
        temp = Q->front;
        Q->front = Q->front->link;
        free(temp);
    }
}

void displayQueue(Queue Q){
    LQueue trav;

    for(trav = Q.front; trav != NULL; trav = trav->link){
        printf("%d ", trav->data);
    }
    printf("\n\n");
}