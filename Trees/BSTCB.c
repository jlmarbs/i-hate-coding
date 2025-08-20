#include <stdio.h>
#define MAX 10

typedef struct{
    int data;
    int left;
    int right;
} NodeType;

typedef struct{
    NodeType node[MAX];
    int avail;
} VHeap;
    
typedef int BST;

void initVHeap(VHeap *VH);
void initBST(BST *T);
int allocSpace(VHeap *VH);
void deallocSpace(VHeap *VH, int ndx);
void insertMem(BST *T, VHeap *VH, int elem);
int deleteMin(BST *T, VHeap *VH);
int deleteMax(BST *T, VHeap *VH);
void deleteMem(BST *T, VHeap *VH, int elem);
void preorder(BST T, VHeap VH);
void postorder(BST T, VHeap VH);
void inorder(BST T, VHeap VH);
void display(BST T, VHeap VH);
int isMember(BST T, VHeap VH, int elem);

int main(){
    VHeap VTree;
    BST Tree;
    initVHeap(&VTree);
    initBST(&Tree);

    insertMem(&Tree, &VTree, 15);
    insertMem(&Tree, &VTree, 11);
    insertMem(&Tree, &VTree, 18);
    insertMem(&Tree, &VTree, 7);
    insertMem(&Tree, &VTree, 22);
    insertMem(&Tree, &VTree, 19);
    insertMem(&Tree, &VTree, 13);
    display(Tree, VTree);

    deleteMem(&Tree, &VTree, 9);
    display(Tree, VTree);

    return 0;
}

void initVHeap(VHeap *VH){
    int x;
    VH->avail = 0;

    for(x = 0; x < MAX - 1; x++){
        VH->node[x].left = x + 1;
        VH->node[x].right = -1;
    }
    VH->node[x].left = -1;
    VH->node[x].right = -1;
}

void initBST(BST *T){
    (*T) = -1;
}

int allocSpace(VHeap *VH){
    int retVal = VH->avail;

    if(retVal != -1){
        VH->avail = VH->node[retVal].left;
    }
    return retVal;
}

void deallocSpace(VHeap *VH, int ndx){
    if(ndx >= 0 && ndx < MAX){
        VH->node[ndx].left = VH->avail;
        VH->avail = ndx;
    }
}

void insertMem(BST *T, VHeap *VH, int elem){
    BST *trav;

    for(trav = T; *trav != -1 && VH->node[*trav].data != elem;){
        trav = (VH->node[*trav].data > elem) ? &VH->node[*trav].left : &VH->node[*trav].right;
    }

    if(*trav == -1){
        int newNode = allocSpace(VH);
        if(newNode != -1){
            VH->node[newNode].data = elem;
            VH->node[newNode].left = -1;
            VH->node[newNode].right = -1;
            *trav = newNode;
        }
    }
}

int deleteMin(BST *T, VHeap *VH){
    BST temp, *trav;
    int num;

    for(trav = T; *trav != -1 && VH->node[*trav].left != -1; trav = &VH->node[*trav].left){}

    if(*trav != -1){
        temp = *trav;
        num = VH->node[temp].data;
        *trav = VH->node[temp].right;
        deallocSpace(VH, temp);
    }
    return num;
}

int deleteMax(BST *T, VHeap *VH){
    BST temp, *trav;
    int num;

    for(trav = T; *trav != -1 && VH->node[*trav].right != -1; trav = &VH->node[*trav].right){}

    if(*trav != -1){
        temp = *trav;
        num = VH->node[temp].data;
        *trav = VH->node[temp].left;
        deallocSpace(VH, temp);
    }
    return num;
}

void deleteMem(BST *T, VHeap *VH, int elem){
    BST temp, *trav;

    for(trav = T; *trav != -1 && VH->node[*trav].data != elem;){
        trav = (VH->node[*trav].data > elem) ? &VH->node[*trav].left : &VH->node[*trav].right;
    }

    if(*trav != -1){
        temp = *trav;
        if(VH->node[temp].left == -1 || VH->node[temp].right == -1){
            *trav = (VH->node[temp].left != -1) ? VH->node[temp].left : VH->node[temp].right;
        } else{
            VH->node[temp].data = deleteMin(&VH->node[temp].right, VH);
        }
    }
}

void preorder(BST T, VHeap VH){
    if(T != -1){
        printf("%d ", VH.node[T].data);
        preorder(VH.node[T].left, VH);
        preorder(VH.node[T].right, VH);
    }
}

void postorder(BST T, VHeap VH){
    if(T != -1){
        postorder(VH.node[T].left, VH);
        postorder(VH.node[T].right, VH);
        printf("%d ", VH.node[T].data);
    }
}

void inorder(BST T, VHeap VH){
    if(T != -1){
        inorder(VH.node[T].left, VH);
        printf("%d ", VH.node[T].data);
        inorder(VH.node[T].right, VH);
    }
}

void display(BST T, VHeap VH){
    printf("PREORDER: ");
    preorder(T, VH);
    printf("\n");
    printf("POSTORDER: ");
    postorder(T, VH);
    printf("\n");
    printf("INORDER: ");
    inorder(T, VH);
    printf("\n\n");
}

int isMember(BST T, VHeap VH, int elem){
    BST trav;

    for(trav = T; trav != -1 && VH.node[trav].data != elem;){
        trav = (VH.node[trav].data > elem) ? VH.node[trav].left : VH.node[trav].right;
    }
    return (trav != -1) ? 1 : 0;
}