#include <stdio.h>
#include <assert.h>

struct Node {
    double data;
    struct Node *next;
};

typedef struct Node Node;

struct Stack {
    Node *root;
};

typedef struct Stack Stack;

Stack create();
void del(Stack* s);
int push(Stack* s, double x);
double pop(Stack* s);
int isEmpty(Stack* s);
void dump(Stack* s);
