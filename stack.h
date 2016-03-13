typedef int stack_type;

class CStack {
private:

    int size_d;
    int pointer;
    stack_type* date_d;

    void isfull();

    int isempty();

    void resize_d();

public:

    CStack();

    CStack(int x);

    ~CStack();

    void push(stack_type t);

    stack_type pop();

    void dump();
};
