# C++ Linked Stack

A **template-based stack implementation** in C++ using a singly linked list (STL-style).

This project implements a stack container with basic stack operations, designed to help understand **memeory management**, **deep copying**, and **Rule of Three** in C++.

## Features
- Generic template-based stack (works with any data type)
- Implements Rule of Three:
  - Copy constructor
  - Copy assignment operator
  - Destructor
- Dynamic memeory management using linked list
- Exception-safe `peek()` and `pop()` operations
- STL-like interface: `push`, `peek`, `pop`, `empty`

## Motivation
I built this project to understand how `std::stack` works internally and to practice managing memory in C++ safely. It also helps reinforce concepts like deep vs shallow copy, exception handling, and linked list manipulation.

## Usage
Include the source file (`stack.cpp`) and use it like a normal stack:

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
