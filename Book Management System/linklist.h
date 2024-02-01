#pragma once
#include <fstream>
#include "Node.h"
#include <iostream>
//using namespace std;

template <class T>
class Linklist {
    Node<T>* start;

public:
    Linklist();
    Node<T>* getStart();
    void insertPos(T &, int);
    void deletePos(int);
    void insertEnd(T&);
    void editBookById(int);
    void display();
    ~Linklist();
    int searchById(int );
    int searchByName(const char*);
//    void top3(int);
    void max(int );
};


