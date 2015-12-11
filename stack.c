Stack create(){
    Stack s;
    s.root = NULL;
    return s;
}

int push(Stack* s, double x) {
    //assert(x);
    Node* t  = (Node*)calloc(1, sizeof(Node));
    t->data = x;
    if(isEmpty(s)) {
        t->next = NULL;
    } else {
        t->next = s->root;
    }
    s->root = t;
    return (!isEmpty(s));
}

int isEmpty(Stack* s) {
    return (s->root == NULL);
}

double pop(Stack* s) {
    printf("pop\n");
    assert(!isEmpty(s));
    double rt = s->root->data;
    s->root = s->root->next;
    return rt;

}

void dump(Stack* s) {
    if(isEmpty(s)) {
        printf("Dump error: stack is empty\n");
    } else {
        Node *t = s->root;
        while(t != NULL) {
            printf("%.2f ",  t->data);
            t = t->next;
        }
    }
}

void del(Stack* s){
    Node* pointer = s->root;
    Node* pointer_next;
    while(pointer_next != NULL){
        pointer_next = pointer->next;
        free(&(pointer->data));
        free(&(pointer->next));
        pointer = pointer_next;
    }
}
