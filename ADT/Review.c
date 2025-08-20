#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef struct{
    int arr[MAX];
    int count;
} LIST;

void initList(LIST *L);
void insertFirst(LIST *L, int data);
void insertLast(LIST *L, int data);
void deleteFirst(LIST *L);
void deleteLast(LIST *L);
void displayList(LIST L);

int main(){
    LIST myList;
    initList(&myList);

    insertFirst(&myList, 21);
    insertFirst(&myList, 7);
    displayList(myList);

    insertLast(&myList, 55);
    insertLast(&myList, 9);
    displayList(myList);

    deleteFirst(&myList);
    displayList(myList);

    insertLast(&myList, 22);
    displayList(myList);

    deleteLast(&myList);
    displayList(myList);

    deleteLast(&myList);
    deleteLast(&myList);
    deleteLast(&myList);
    displayList(myList);

    return 0;
}

void initList(LIST *L){
    L->count = 0;
}

void insertFirst(LIST *L, int data){
    int x;

    if(L->count != MAX){
        for(x = L->count; x > 0; x--){
            L->arr[x] = L->arr[x - 1];
        }
        L->arr[x] = data;
        L->count++;
    }
}

void insertLast(LIST *L, int data){
    if(L->count != MAX){
        L->arr[L->count] = data;
        L->count++;
    }
}

void deleteFirst(LIST *L){
    int x;
    if(L->count > 0){
        for(x = 0; x < L->count - 1; x++){
            L->arr[x] = L->arr[x + 1];
        }
        L->count--;
    }
}

void deleteLast(LIST *L){
    if(L->count > 0){
        L->count--;
    }
}

void displayList(LIST L){
    int x;

    for(x = 0; x < L.count; x++){
        printf("%d\n", L.arr[x]);
    }
    printf("\n");
}