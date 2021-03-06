#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

struct Node
{
    int data;
    struct Node *lchild;
    struct Node *rchild;
};

struct Queue
{
    int size;
    int front;
    int rear;
    struct Node **Q;
};

void create(struct Queue *q, int size)
{
    q->size = size;
    q->front = q->rear = 0;
    q->Q = (struct Node **)malloc(q->size*sizeof(struct Node *));
}

void enqueue(struct Queue *q, struct Node *x)
{
    if((q->rear+1)%q->size == q->front)
        printf("queue is full\n");
    else{
        // insertion is done at rear end
        q->rear = (q->rear+1)%q->size;
        q->Q[q->rear] = x;
    }
}

struct Node* dequeue(struct Queue *q)
{
    struct Node *x = NULL;
    if(q->front == q->rear)
        printf("queue is empty\n");
    else{
        q->front = (q->front+1)%q->size;
        x = q->Q[q->front];
    }
    return x;
}

int isEmpty(struct Queue q)
{
    return q.front==q.rear;
}

#endif // QUEUE_H_INCLUDED
