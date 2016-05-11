#include <iostream>

using namespace std;

#define DISPLAY(X) for(int _i=0; _i<X; _i++) cout<<'*'; cout<<endl;

typedef int T;

class Stack{
    private:
        size_t size;
        int top;
        T *stack;
    public:
        Stack(size_t sz);
        Stack(const Stack &s);
        void operator=(const Stack &s);
        ~Stack();

        bool isfull() const;
        bool isempty() const;
        void display() const;

        void push(int);
        int pop();
        int max() const;
};

Stack::Stack(size_t sz):size(sz), top(-1), stack(new T[sz])
{
    cout<<"Created a new stack @ "<<this<<endl;
}

Stack::Stack(const Stack &s):size(s.size), top(s.top), stack(new T[s.size])
{
    int i;
    cout<<"copy constructor overloaded and created new object @ "<<this<<endl;

    // copy each element form original stack to this new one
    for(i=0; i <= s.top; ++i)
        stack[i] = s.stack[i];
}

void Stack::operator=(const Stack &ref)
{
    int i;
    cout<<"Assignement operator overloaded"<<endl;
    if(this == &ref) {
        cout<<"Self Assignment"<<endl;
        return;
    }

    top = ref.top;
    size = ref.size;
    delete []stack;
    stack = NULL;

    stack = new T[ref.size];
    for(i=0; i<ref.size; i++)
        stack[i] = ref.stack[i];
}

Stack::~Stack()
{
    cout<<"Destructor invoked for : "<<this<<endl;
    delete []stack;
}

void Stack::display()const
{
    int i;

    if(isempty()) {
        cout<<"Stack empty, Nothing to display"<<endl;
        return;
    }

    cout<<"Stack elements are : ";
    for(i=0; i <= top; i++)
        cout << stack[i] << " ";
    cout<<endl;
}

bool Stack::isfull() const
{
    return (top+1 == size ? 1 : 0);
}

bool Stack::isempty() const
{
    return (top == -1 ? 1 : 0);
}

void Stack::push(int element)
{
    if(isfull()) {
        cout<<"Stack is full, Can't insert"<<endl;
        return;
    }
    stack[++top] = element;
}

int Stack::pop()
{
    if(isempty()) {
        cout<<"Stack empty, nothing to delete"<<endl;
        return -1;
    }
    return stack[top--];
}

int Stack::max() const
{
    return size;
}

int main()
{
    Stack s(5);
    Stack s1 = s;
    int i;

    s1.display();
    s.display();

    for(i=0; i<s.max(); i++)
        s.push(i + 76);

    s.display();
    s1.display();

    Stack s2(7);
    s2 = s;

    s.display();
    s1.display();
    s2.display();

    DISPLAY(10);
    typedef void (Stack::*spush) (int) ;
    spush sp = &Stack::push;
    s2.pop();
    (s2.*sp)(765);
    s2.display();
    DISPLAY(10);

    return 0;
}