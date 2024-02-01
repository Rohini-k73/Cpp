#include <fstream>
#include "Linklist.h"
#include<string.h>
#include "book.h"
#include<iostream>
using namespace std;

//////////////////////////////////////
//constructor
template <class T>
Linklist<T>::Linklist() {
    start = NULL;
}
//////////////////////////////////////
template<class T>
Node<T>* Linklist<T>::getStart(){
	return start;
}

/////////////////////////////////////
template <class T>
void Linklist<T>::insertPos(T &data, int pos){
    Node<T>* temp = new Node<T>(data);
    if (start == NULL) {
        start = temp;
        return;
    }
    //insert at the beggining
    if (pos == 1) {
        temp->setNext(start);
        start = temp;
        return;
    }
    Node<T>* p = start;
    int i = 1;
    while (i != pos - 1 && p->getNext() != NULL) {
        p = p->getNext();
        i++;
    }
    //attach node first
    temp->setNext(p->getNext());
    p->setNext(temp);
}
////////////////////////////////
template<class T>
void Linklist<T>::insertEnd(T& data){
	Node<T>* temp = new Node<T>(data);
	if(start==NULL){
		start = temp;
	}
	else{
		Node<T>* p = start;
		while(p->getNext()!=NULL){
			p = p->getNext();
		}
		p->setNext(temp);
	}
}
//delete
//////////////////////////////////
template <class T>
void Linklist<T>::deletePos(int pos) {
    if (start == NULL) {
        cout << "\nNo nodes to delete";
        return;
    }

    // Declare 'p' here
    Node<T>* p = start;

    // Delete the first node
    if (pos == 1) {
        start = start->getNext();
        cout << "\nBook at position 1 is deleted ";
        delete p;
        return;
    }

    int i = 1;
    while (i < pos - 1 && p->getNext() != NULL) {
        i++;
        p = p->getNext();
    }
	
	//check valid position
    if (i == pos - 1) {
        Node<T>* q = p->getNext();
        p->setNext(q->getNext());
        cout << "\nBook at position " << pos << " is deleted";
        delete q;
    } else {
        cout << "\nInvalid position";
    }
}
//////////////////////////////////
template <class T>
void Linklist<T>::editBookById(int id) {
    if (start == NULL) {
        cout << "\nNo Books to edit";
        return;
    }

    Node<T>* p = start;
    while (p != NULL) {
        if (p->getData().getId() == id) {

            char ans;
            cout << "Do you wish to change book name(y/n): ";
            cin >> ans;

            if (ans == 'y' || ans == 'Y') {
                cout << "Enter the new book name: ";
                char name[20];
                cin >> name;
                p->getData().setName(name);
            }

            cout << "Do you wish to change Price(y/n): ";
            cin >> ans;

            if (ans == 'y' || ans == 'Y') {
                cout << "Enter the new Price: ";
                double price;
                cin >> price;
                p->getData().setPrice(price);
            }

            cout << "Do you wish to change Rating(y/n): ";
            cin >> ans;

            if (ans == 'y' || ans == 'Y') {
                cout << "Enter the new Rating: ";
                double rating;
                cin >> rating;
                p->getData().setRating(rating);
            }

            // Break out of the loop after editing the book
            break;
        }
        p = p->getNext();
    }
}

//////////////////////////////////
template <class T>
void Linklist<T>::display(){
    if (start == NULL) {
        cout << "No Books to display." << endl;
    } else {
        Node<T>* p = start;
        while (p != NULL) {
        	
        	//p->getData will return book obj
            p->getData().display();
            p = p->getNext();
        }
        cout << endl;
    }
}
/////////////////////////////////
template <class T>
Linklist<T>::~Linklist(){
	Node<T> *p;
	while(start!=NULL){
		p=start;
		start = start->getNext();
		delete p;
	}
}
/////////////////////////////////
// Search by id
template <class T>
int Linklist<T>::searchById(int id) {
	  Node<T>* p = start;
    int position = 0;
    while (p != NULL) {
        if (p->getData().getId() == id) {
            cout << "Found" << endl;
            p->getData().display();
            return position;
        }
        p = p->getNext();
        position++;
    }

    cout << "Book with ID " << id << " not found." << endl;
    return -1;
}

///////////////////////////////////
// Search by name
template <class T>
int Linklist<T>::searchByName(const char* name) {
	  Node<T>* p = start;
    int position = 0;

    while (p != NULL) {
        if (strcasecmp(p->getData().getName(), name) == 0) {
            cout << "Found" << endl;
            p->getData().display();
            return position;
        }
        p = p->getNext();
        position++;
    }

    cout << "Book with name '" << name << "' not found." << endl;
    return -1;
}
/////////////////////////////
// Function to find and display the maximum book based on either price or rating
template <class T>
void Linklist<T>::max(int choice) {
    if (start == NULL) {
        cout << "No Books to display" << endl;
        return;
    }

    double maxValue = 0;
    Node<T>* p = start;
    Node<T>* maxNode = NULL;

    while (p != NULL) {
        double value;
        if (choice == 1) {
            value = p->getData().getPrice();
        } else if (choice == 2) {
            value = p->getData().getRating();
        } else {
            cout << "Invalid choice for max function." << endl;
            return;
        }

        if (value > maxValue) {
            maxValue = value;
            maxNode = p;
        }

        p = p->getNext();
    }

    cout << "\nMaximum book is:-" << endl;
    if (maxNode != NULL) {
        maxNode->getData().display();
    }
}
// Function to find and display the top 3 books based on either price or rating
//template <class T>
//void Linklist<T>::top3(int choice) {
//    if (start == NULL) {
//        cout << "No nodes to display" << endl;
//        return;
//    }
//
//    double max1 = 0, max2 = 0, max3 = 0;
//    Node<T>* p = start;
//    Node<T>* maxNode1 = NULL;
//    Node<T>* maxNode2 = NULL;
//    Node<T>* maxNode3 = NULL;
//
//    while (p != NULL) {
//        double value;
//        if (choice == 1) {
//            value = p->getData().getPrice();
//        } else if (choice == 2) {
//            value = p->getData().getRating();
//        } else {
//            cout << "Invalid choice for top3 function." << endl;
//            return;
//        }
//
//        if (value > max1) {
//            max3 = max2;
//            max2 = max1;
//            max1 = value;
//
//            maxNode3 = maxNode2;
//            maxNode2 = maxNode1;
//            maxNode1 = p;
//        } else if (value > max2 && value != max1) {
//            max2 = value;
//            maxNode2 = p;
//        } else if (value > max3 && value != max2) {
//            max3 = value;
//            maxNode3 = p;
//        }
//
//        p = p->getNext();
//    }
//
//    cout << "\nTop 3 books are:-" << endl;
//    if (maxNode1 != NULL) {
//        maxNode1->getData().display();
//    }
//    if (maxNode2 != NULL) {
//        maxNode2->getData().display();
//    }
//    if (maxNode3 != NULL) {
//        maxNode3->getData().display();
//    }
//}

/////////////////////////////////////



