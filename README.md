#Custom Stack in C++

A generic stack implementation using a singly linked list.

## Features
- Template-based design
- Deep copy support (Rule of Three)
- Dynamic memeory management
- Exception-safe pop and peek
- STL-like interface

## Motivation
Built to understand how std::stack works internally and to practice memeory ownership and copy semantics in C++.

## Usage
Include stack.cpp and use like a normal stack

```cpp
#include "stack.cpp"
#include <iostream>

int main() {
    Stack<int> st;
    st.push(5);
    st.push(6);

    std::cout << st.peek(); // prints 6
    st.pop();
    std::cout << st.peek(); // prints 5
}
