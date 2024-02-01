#pragma once
#include<iostream>
#include"book.h"
using namespace std;

template <class T>
class Node {
    T data; // each node contains a Book object 
    Node* next; 

public:	
    Node(T&);
    T& getData();
    Node* getNext();
    void setData(T&);
    void setNext(Node*);    
};
