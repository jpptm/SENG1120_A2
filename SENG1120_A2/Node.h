// Author: Johanne Montano
// Course: SENG1120
// Student Number: c3336019
#ifndef NODE_H
#define NODE_H

#include <cstdlib>

// This class will serve as data containers for our linked list
template <class T>
class Node
{
public:
    // Initialising constructor
    Node();

    // Initialise empty destructor
    ~Node();

    // Initialise getters and setters
    void set_next(Node<T> *next_);
    void set_previous(Node<T> *previous_);
    void set_data(T &node_data_);

    const Node<T> *get_next() const;
    Node<T> *get_next();
    const Node<T> *get_previous() const;
    Node<T> *get_previous();
    T &get_data();

    // Declare private member variables
private:
    Node *next;
    Node *previous;
    T node_data;
};
#endif // NODE_H
