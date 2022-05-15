// Author: Johanne Montano
// Course: SENG1120
// Student Number: c3336019

// Macroguard
#ifndef LSTACK_H
#define LSTACK_H

#include "LinkedList.h"

// The class below will create a template for the stack data structure
template <class T>
class LStack
{
public:
    // Initialise constructor and destructor
    LStack();
    ~LStack();

    // Push adds new item on top of the stack, pop removes the top most element, peek looks at the top most element
    void push(T item);
    T pop();
    T &peek();
    bool is_empty() const;

    int length() const;

private:
    // The size variable is here so that we can keep track of the count of the elements within the stack
    // without communicating with the LinkedList class.
    // We just increment or decrement by 1 whenever we push or pop accordingly
    LinkedList<T> LL;
    int size;
};

// Include hpp file to let compiler know that the implementation is there
#include "LStack.hpp"
#endif // LSTACK_H