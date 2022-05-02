// Author: Johanne Montano
// Course: SENG1120
// Student Number: c3336019
#ifndef NODE_H
#define NODE_H

#include <cstdlib>

// this class will serve as data containers for our linked list
template <class T>
class Node
{
public:
    // initialising constructor
    Node();

    // initialise empty destructor
    ~Node();

    // initialise getters and setters
    void set_next(Node<T> *next_);
    void set_previous(Node<T> *previous_);
    void set_data(T &node_data_);

    const Node<T> *get_next() const;
    Node<T> *get_next();
    const Node<T> *get_previous() const;
    Node<T> *get_previous();
    T &get_data();

    // declare private member variables
private:
    Node *next;
    Node *previous;
    T node_data;
};
#endif // NODE_H
