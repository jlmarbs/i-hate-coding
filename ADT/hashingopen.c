#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct node{
    struct node *link;
    int data;
} *LIST;

typedef LIST Dictionary[MAX];

void initDict(Dictionary D);
int hash(int elem);
void insert(Dictionary D, int elem);
void delete(Dictionary D, int elem);
void display(Dictionary D);


int main(){
    Dictionary D;
    initDict(D);

    insert(D, 10);
    insert(D, 43);
    insert(D, 54);
    insert(D, 32);
    insert(D, 22);
    display(D);

    delete(D, 22);
    display(D);

    return 0;
}

void initDict(Dictionary D){
    int x;

    for(x = 0; x < MAX; x++){
        D[x] = NULL;
    }
}

int hash(int elem){
    return elem % MAX;
}

void insert(Dictionary D, int elem){
    int index = hash(elem);
    LIST *trav;
    
    for(trav = &D[index]; *trav != NULL && (*trav)->data < elem; trav = &(*trav)->link){}

    if(*trav == NULL || (*trav)->data != elem){
        LIST newNode = (LIST)malloc(sizeof(struct node));

        if(newNode != NULL){
            newNode->data = elem;
            newNode->link = *trav;
            *trav = newNode;
        }
    }
}

void delete(Dictionary D, int elem){
    int index = hash(elem);
    LIST *trav;

    for(trav = &D[index]; *trav != NULL && (*trav)->data != elem; trav = &(*trav)->link){}
    if(*trav != NULL){
        LIST temp;
        temp = *trav;
        *trav = temp->link;
        free(temp);
    }
}

void display(Dictionary D){
    int x;

    for(x = 0; x < MAX; x++){
        printf("Index %d: ", x);
        LIST trav;
        for(trav = D[x]; trav != NULL; trav = trav->link){
            printf("--> %d ", trav->data);
        }
        printf("\n");
    }
    printf("\n");
}