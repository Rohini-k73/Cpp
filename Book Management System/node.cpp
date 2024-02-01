#include "Node.h"
template <class T>
Node<T>::Node(T &d) {
    data = d;
    next = NULL;	
}

//getter
template <class T>
T& Node<T>::getData() {
    return data;
}

template <class T>
Node<T>* Node<T>::getNext() {
    return next;
}

//setter
template <class T>
void Node<T>::setData(T &d) {
    data = d;
}

template <class T>
void Node<T>::setNext(Node<T>* nt) {
    next = nt;
}

