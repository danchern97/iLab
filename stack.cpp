#include <iostream>
#include <cstdlib>

typedef int stack_type;

class CStack {
private:

    int size_d;
    int pointer;
    stack_type* date_d;

    void isfull() {
        if(pointer >= size_d) {
            resize_d();
        }
    }

    int isempty() {
        if(pointer < 0) {
            return 1;
        } else {
            return 0;
        }
    }

    void resize_d() {
        size_d += 100;
        date_d = (stack_type*) realloc(date_d, size_d*sizeof(stack_type));
    }

public:

    CStack() {
        size_d = 10;
        pointer = -1;
        date_d = (stack_type*) calloc(size_d, sizeof(stack_type));
    }

    CStack(int x) {
        size_d = x;
        pointer = -1;
        date_d = (stack_type*) calloc(size_d, sizeof(stack_type));
    }

    ~CStack() {
        size_d = 0;
        pointer = 0;
        free(date_d);
    }

    void push(stack_type t) {
        isfull();
        pointer++;
        date_d[pointer] = t;
    }

    stack_type pop() {
        if(!isempty()) {
            stack_type t = date_d[pointer];
            date_d[pointer] = (stack_type) NULL;
            pointer --;
            return t;
        } else {
            std::cout « "Error: stack is empty" « std::endl;
            return (stack_type) NULL;
        }
    }

    void dump() {
        int i = pointer;
        while(i >= 0) {
            std::cout « date_d[i] « std::endl;
            i--;
        }
    }

};
