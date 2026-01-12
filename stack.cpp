#include <iostream>
using namespace std;
#define STACK_IS_EMPTY 1

template <typename dataType>
struct node
{
    dataType data;
    node *next;
};

template <typename dataType>
class stack
{
private:
    node<dataType> *top;

public:
    stack();
    stack(const stack &s);
    void push(dataType);
    dataType peek() const;
    void pop();
    bool empty() const;
    stack &operator=(const stack &s);
    ~stack();
};

template <typename dataType>
stack<dataType>::stack() : top(nullptr) {}

template <typename dataType>
void stack<dataType>::push(dataType data)
{
    node<dataType> *newNode = new node<dataType>;
    newNode->data = data;
    newNode->next = top;
    top = newNode;
}

template <typename dataType>
dataType stack<dataType>::peek() const
{
    if (!empty())
        return top->data;
    throw STACK_IS_EMPTY;
}

template <typename dataType>
void stack<dataType>::pop()
{
    if (!empty())
    {
        node<dataType> *toDel = top;
        top = top->next;
        delete toDel;
    }
    else
        throw STACK_IS_EMPTY;
}

template <typename dataType>
bool stack<dataType>::empty() const
{
    return top == nullptr;
}

template <typename dataType>
stack<dataType>::~stack()
{
    while (!empty())
        pop();
}

template <typename dataType>
stack<dataType> &stack<dataType>::operator=(const stack<dataType> &s)
{
    if(this == &s)
        return *this;

    while(!empty())
        pop();

    node<dataType> *temp = s.top;
    node<dataType> *tail = nullptr;

    while (temp)
    {
        node<dataType>* newNode = new node<dataType>;
        newNode->data = temp->data;
        newNode->next = nullptr;
        if (top == nullptr)
            top = newNode;
        else
            tail->next = newNode;

        temp = temp->next;
        tail = newNode;
    }
    return *this;
}

template <typename dataType>
stack<dataType>::stack(const stack<dataType> &s)
{
    node<dataType> *temp, *tail = nullptr;
    this->top = nullptr;
    temp = s.top;
    while (temp)
    {
        node<dataType>* newNode = new node<dataType>;
        newNode->data = temp->data;
        newNode->next = nullptr;
        if (this->top == nullptr)
            this->top = newNode;
        else
            tail->next = newNode;
        temp = temp->next;
        tail = newNode;
    }
}

int main()
{
    stack<int> st;
    st.push(5);
    st.push(6);
    
    stack<int> temp = st;
    cout<<temp.peek();
    temp.pop();
    temp.pop();
    // temp.pop();
    return 0;
}
