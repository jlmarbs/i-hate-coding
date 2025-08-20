#include <stdio.h>
#include <stdlib.h>
#define MAX 5 

typedef int SET[MAX];

SET *Union(SET A, SET B);
SET *Intersection(SET A, SET B);
SET *Difference(SET A, SET B);
void initSet(SET *A);
void insert(SET *A, int ndx);
void display(SET A);
void delete(SET *A, int ndx);
void populateA(SET *A);
void populateB(SET *B);
int isMember(SET A, int ndx);

int main(){

    SET A;
    SET B;
    
    initSet(&A);
    initSet(&B);
    populateA(&A);
    populateB(&B);
    display(A);
    display(B);

    SET *C = Difference(A, B);
    display(*C);
    printf("Is a Member?: %d", isMember(*C, 3));
    free(C);

    return 0;
}

SET *Union(SET A, SET B){
    SET *C = (SET*)malloc(sizeof(SET));

    if(C != NULL){
        int x;
        for(x = 0; x < MAX; x++){
            (*C)[x] = A[x] | B[x];
        }
    }
    return C;
}

SET *Intersection(SET A, SET B){
    SET *C = (SET*)malloc(sizeof(SET));

    if(C != NULL){
        int x;
        for(x = 0; x < MAX; x++){
            (*C)[x] = A[x] & B[x];
        }
    }
    return C;
}

SET *Difference(SET A, SET B){
    SET *C = (SET*)malloc(sizeof(SET));

    if(C != NULL){
        int x;
        for(x = 0; x < MAX; x++){
            (*C)[x] = A[x] &~ B[x];
        }
    }
    return C;
}

void initSet(SET *A){
    int x;
    for(x = 0; x < MAX; x++){
        (*A)[x] = 0;
    }
}

void insert(SET *A, int ndx){
    if(ndx < MAX && ndx >= 0){
        (*A)[ndx] = 1;
    }
}

void display(SET A){
    int x;
    printf("\n");
    for(x = 0; x < MAX; x++){
        printf("%d ", A[x]);
    }
    printf("\n");
}

void delete(SET *A, int ndx){
    if(ndx < MAX && ndx >= 0){
        (*A)[ndx] = 0;
    }
}

void populateA(SET *A){
    insert(A, 3);
    insert(A, 4);
    insert(A, 1);
}

void populateB(SET *B){
    insert(B, 2);
    insert(B, 4);
    insert(B, 0);
}

int isMember(SET A, int ndx){
    return A[ndx] == 1 ? 1 : 0;
}