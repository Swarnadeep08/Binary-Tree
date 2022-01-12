#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

struct Stack
{
    int size;
    int top;
    struct Node **A;
};

void createStk(struct Stack *st, int size)
{
    st->size = size;
    st->top = -1;
    st->A = (struct Node **)malloc(st->size*sizeof(struct Node *));
}

void push(struct Stack *st, struct Node *x)
{
    if(st->top==st->size-1){
        printf("Stack Overflow\n");
    }
    else{
        st->top++;
        st->A[st->top] = x;
    }
}

struct Node* pop(struct Stack *st)
{
    if(st->top==-1){
        printf("Stack Underflow\n");
        return NULL;
    }
    else{
        struct Node* x = st->A[st->top];
        st->top--;
        return x;
    }
}

int isFullStk(struct Stack st)
{
    return st.top==st.size-1;
}

int isEmptyStk(struct Stack st)
{
    return st.top==-1;
}

#endif // STACK_H_INCLUDED
