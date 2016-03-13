#include <iostream>
#include <cstdlib>
#include "stack.h"
#include <assert.h>

void CStack::isfull() {
    if(pointer >= size_d) {
        resize_d();
    }
}

int CStack::isempty() {
    if(pointer < 0) {
        return 1;
    } else {
        return 0;
    }
}

void CStack::resize_d() {
    size_d += 100;
    date_d = (stack_type*) realloc(date_d, size_d*sizeof(stack_type));
    assert(date_d);
}

CStack::CStack() {
    size_d = 10;
    pointer = -1;
    date_d = (stack_type*) calloc(size_d, sizeof(stack_type));
    assert(date_d);
}

CStack::CStack(int x) {
    size_d = x;
    pointer = -1;
    date_d = (stack_type*) calloc(size_d, sizeof(stack_type));
    assert(date_d);
}

CStack::~CStack() {
    size_d = 0;
    pointer = 0;
    free(date_d);
}


void CStack::push(stack_type t) {
    isfull();
    pointer++;
    date_d[pointer] = t;
}

stack_type CStack::pop() {
    assert((!isempty()));
    stack_type t = date_d[pointer];
    date_d[pointer] = (stack_type) NULL;
    pointer --;
    return t;
}

void CStack::dump() {
    if(isempty()) {
        std::cout << "Stack is empty" << std::endl;
    } else {
        int i = pointer;
        while(i >= 0) {
            std::cout << date_d[i] << std::endl;
            i--;

        }
    }
}

int main() {
    return 0;
}
