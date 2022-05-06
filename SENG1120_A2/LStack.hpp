// Implementation of Lstack.h goes here
#include "LStack.h"

// Author: Johanne Montano
// Course: SENG1120
// Student Number: c3336019

// Constructor
template <typename T>
LStack<T>::LStack()
{
    // Initialise LL
    LL = LinkedList<T>();
}

// Destructor
template <typename T>
LStack<T>::~LStack() {}

// Add element on top of the stack
template <typename T>
void LStack<T>::push(T item)
{
    LL.add_to_head(item);
}

// Pop top most element and return deleted object's data
template <typename T>
T LStack<T>::pop()
{
    T data;
    if (LL.size() != 0)
    {
        data = LL.get_from_head();
        LL.remove_from_head();
    }
    return data;
}

// Peek value of top most element
template <typename T>
T &LStack<T>::peek()
{
    T &val = LL.get_from_head();
    if (LL.size() != 0)
    {
        val = LL.get_from_head();
    }
    return val;
}

// Check if stack is empty or not
template <typename T>
bool LStack<T>::is_empty()
{
    if (LL.size() == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}