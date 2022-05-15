// Implementation of Lstack.h goes here
#include "LStack.h"

// Author: Johanne Montano
// Course: SENG1120
// Student Number: c3336019

// Constructor
template <typename T>
LStack<T>::LStack()
{
    // Initialise size so we don't get a segfault somewhere but the linkedList member should be initialised after this
    size = 0;
}

// Destructor - empty
template <typename T>
LStack<T>::~LStack() {}

// Add element on top of the stack
template <typename T>
void LStack<T>::push(T item)
{
    // Increment size and use add_to_head from LL
    size++;
    LL.add_to_head(item);
}

// Danger for the functions below - peeking or popping an empty list with code written this way will lead to a segfault
// Must take care when using these functions
// Always check if stack is empty before peeking or popping anything!
// This is why we keep track of the stack's state using the size variable and the length method so
// we can do some checks

// Pop top most element and return deleted object's data
template <typename T>
T LStack<T>::pop()
{
    // If size is not 0 decrement it then return the data
    if (size > 0)
    {
        size--;
    }
    return LL.remove_from_head();
}

// Peek value of top most element
template <typename T>
T &LStack<T>::peek()
{
    return LL.get_from_head();
}

// Check if stack is empty or not
template <typename T>
bool LStack<T>::is_empty() const
{
    return LL.size() == 0;
}

// Return no of elements inside the stack
template <typename T>
int LStack<T>::length() const
{
    return size;
}
