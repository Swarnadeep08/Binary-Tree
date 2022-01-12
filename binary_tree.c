// implementation of binary tree using linked list

#include<stdio.h>
#include<stdlib.h>
#include "queue.h"
#include "stack.h"

// root is a global pointer
struct Node *root = NULL;

void TreeCreate()
{
    struct Node *p, *t;
    int x;
    struct Queue q;
    create(&q, 100);

    printf("enter the root value : ");
    scanf("%d", &x);
    root = (struct Node *)malloc(sizeof(struct Node));
    root->data = x;
    root->lchild = root->rchild = NULL;
    // store the address of the root node in the queue
    enqueue(&q, root);

    while(!isEmpty(q)){
        p = dequeue(&q);
        // entering left child
        printf("enter the left child of %d : ", p->data);
        scanf("%d", &x);
        if(x!=-1){
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            // store the address of the left child in queue
            enqueue(&q, p->lchild);
        }
        printf("enter the right child of %d : ", p->data);
        scanf("%d", &x);
        if(x!=-1){
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            // store the address of the left child in queue
            enqueue(&q, p->rchild);
        }
    }
    free(q.Q);
}

void preOrder(struct Node *p)
{
    if(p!=NULL)
    {
        printf("%d ", p->data);
        preOrder(p->lchild);
        preOrder(p->rchild);
    }
}

void inOrder(struct Node *p)
{
    if(p!=NULL)
    {
        inOrder(p->lchild);
        printf("%d ", p->data);
        inOrder(p->rchild);
    }
}

void postOrder(struct Node *p)
{
    if(p!=NULL)
    {
        postOrder(p->lchild);
        postOrder(p->rchild);
        printf("%d ", p->data);
    }
}

int count(struct Node *p)
{
    int x,y;
    if(p!=NULL){
        x = count(p->lchild);
        y = count(p->rchild);
        return x+y+1;
    }
    return 0;
}

int countLeaf(struct Node *p)
{
    if(p==NULL)
        return 0;
    if(p->lchild==NULL && p->rchild==NULL){
        return 1;
    }
    return countLeaf(p->lchild) + countLeaf(p->rchild);
}

int countStrict(struct Node *p)
{
    int x,y;
    if(p!=NULL){
        x = countStrict(p->lchild);
        y = countStrict(p->rchild);
        if(p->lchild!=NULL && p->rchild!=NULL)
            return x+y+1;
        else
            return x+y;
    }
    return 0;
}

int countInternal(struct Node *p)
{
    int x,y;
    if(p!=NULL){
        x = countInternal(p->lchild);
        y = countInternal(p->rchild);
        // this statement can also be written as p->lchid!=NULL XOR p->rchild!=NULL
        if((p->lchild!=NULL && p->rchild==NULL) || (p->lchild==NULL && p->rchild!=NULL))
            return x+y+1;
        else
            return x+y;
    }
    return 0;
}

int height(struct Node *p)
{
    int x,y;
    if(p!=NULL){
        x = height(p->lchild);
        y = height(p->rchild);
        if(x>y)
            return x+1;
        else
            return y+1;
    }
    return 0;
}

int sum(struct Node *p)
{
    int x,y;
    if(p!=NULL){
        x = sum(p->lchild);
        y = sum(p->rchild);
        return x+y+p->data;
    }
    return 0;
}

void levelOrder(struct Node *p)
{
    struct Queue q;
    create(&q, 100);

    // root's data is displayed and address stored in queue
    printf("%d ", p->data);
    enqueue(&q, p);

    while(!isEmpty(q)){
        p = dequeue(&q);
        if(p->lchild!=NULL){
            printf("%d ", p->lchild->data);
            enqueue(&q, p->lchild);
        }
        if(p->rchild!=NULL){
            printf("%d ", p->rchild->data);
            enqueue(&q, p->rchild);
        }
    }
    free(q.Q);
}

// iterative approach
void iter_inorder(struct Node *p)
{
    struct Stack st;
    createStk(&st, 100);

    while(p!=NULL || !isEmptyStk(st)){
        if(p!=NULL){
            push(&st, p);
            p = p->lchild;
        }
        else{
            p = pop(&st);
            printf("%d ", p->data);
            p = p->rchild;
        }
    }
    free(st.A);
}

// iterative approach
void iter_preorder(struct Node *p)
{
    struct Stack st;
    createStk(&st, 100);

    while(p!=NULL || !isEmptyStk(st)){
        if(p!=NULL){
            printf("%d ", p->data);
            push(&st, p);
            p = p->lchild;
        }
        else{
            p = pop(&st);
            p = p->rchild;
        }
    }
    free(st.A);
}

int main()
{
    TreeCreate();
    printf("\nlevel-order traversal : ");
    levelOrder(root);
    printf("\nno. of leaf nodes %d",countLeaf(root));
    printf("\nno. of degree two nodes %d",countStrict(root));
    printf("\nno. of degree one nodes %d",countInternal(root));

    return 0;
}
