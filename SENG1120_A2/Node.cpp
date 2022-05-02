#include "Node.h"

// Author: Johanne Montano
// Course: SENG1120
// Student Number: c3336019

// this class will be used as data holders for a linked list

// constructors
template <typename T>
Node<T>::Node()
{
    next = NULL;
    previous = NULL;
}

// empty destructor
template <typename T>
Node<T>::~Node() {}

// setters
template <typename T>
void Node<T>::set_next(Node<T> *next_)
{
    next = next_;
}

template <typename T>
void Node<T>::set_previous(Node<T> *previous_)
{
    previous = previous_;
}

template <typename T>
void Node<T>::set_data(T &node_data_)
{
    node_data = node_data_;
}

// getters - use const when we can and non const when we must alter the state of the object
template <typename T>
const Node<T> *Node<T>::get_next() const
{
    return next;
}

template <typename T>
const Node<T> *Node<T>::get_previous() const
{
    return previous;
}

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

template class Node<int>;