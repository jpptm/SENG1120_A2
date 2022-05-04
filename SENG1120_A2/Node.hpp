// Implementation
#include "Node.h"

// Author: Johanne Montano
// Course: SENG1120
// Student Number: c3336019

// This class will be used as data holders for a linked list

// Constructors
template <typename T>
Node<T>::Node()
{
    next = NULL;
    previous = NULL;
}

// Empty destructor
template <typename T>
Node<T>::~Node() {}

// Setters
template <typename T>
void Node<T>::set_next(Node *next_)
{
    next = next_;
}

template <typename T>
void Node<T>::set_previous(Node *previous_)
{
    previous = previous_;
}

template <typename T>
void Node<T>::set_data(const T &node_data_)
{
    node_data = node_data_;
}

// Getters - use const when we can and non const when we must alter the state of the object
template <typename T>
Node<T> *Node<T>::get_next()
{
    return next;
}

template <typename T>
Node<T> *Node<T>::get_previous()
{
    return previous;
}

template <typename T>
T &Node<T>::get_data()
{
    return node_data;
}