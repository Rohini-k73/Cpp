#include "book.h"
#include <fstream>
#include <iostream>
#include "Linklist.h"
#include "linklist.cpp"
#include "node.cpp"
using namespace std;

int main() {
    int choice = 0;
    char control;
    Linklist<Book>lt; //manage linked list of book obj
    
    //reading data
    ifstream in("text.bin", ios::binary);
	if(in.is_open()){
		Book b;
		while(in.read(reinterpret_cast<char*>(&b), sizeof(b))){
			lt.insertEnd(b);
		}
		in.close();
	}
	else{
		cout<<"File opening for reading is fail!";
	}
    cout << "-----------Welcome to Book Library------------";
    do {
        cout << "\n\tPress 1. Insert Books(at Position)";
        cout << "\n\tPress 2. Display all books";
        cout << "\n\tPress 3. Delete Book(from Position)";
        cout << "\n\tPress 4. Edit Book(Update))";
        cout << "\n\tPress 5. Search a book";
//        cout << "\n\tPress 6. Top 3 books(in Price or Rating)";
        cout << "\n\tPress 6. Show a book with Max Price/Rating";

        cout << "\nEnter your choice : ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int id;
                char name[30];
                double price;
                double rating;
                char author[20];
                int pos;

                cout << "\nEnter Book id : ";
                cin >> id;
                cout << "\nEnter Book name : ";
                fflush(stdin);
                gets(name);
                cout << "\nEnter Book Author : ";
                gets(author);
                cout << "\nEnter Book price : ";
                cin >> price;
                cout << "\nEnter Book Ratings : ";
                cin >> rating;
                cout << "\nEnter Position : ";
                cin >> pos;

                Book b(id, name, price, author, rating);
                lt.insertPos(b, pos);
    
            } break;

            case 2: {
           
                    lt.display();
               
            } break;

            case 3: {
                int pos;
                cout << "\nEnter the position : ";
                cin >> pos;
                lt.deletePos(pos);
              
            } break;
			
		    case 4: {
                int id;
                cout << "\nEnter the id : ";
                cin >> id;
                lt.editBookById(id);
               
            } break;
			
			case 5: {
			    int searchChoice;
			    cout << "\n\t1. Search by ID.. ";
			    cout << "\n\t2. Search by Name..";
			    cout << "\nEnter your search choice: ";
			    cin >> searchChoice;
			
			    if (searchChoice == 1) {
			        int id;
			        cout << "\nEnter the Book ID to search: ";
			        cin >> id;
			        lt.searchById(id);
			    } else if (searchChoice == 2) {
			        char name[30];
			        cout << "\nEnter the Book Name to search: ";
				fflush(stdin);
				gets(name);
			        lt.searchByName(name);
			    } else {
			        cout << "Invalid search choice";
			    }
			} break;

		
		case 7:{
//		    int topChoice;
//		    cout << "\n\t1. Top 3 by Price";
//		    cout << "\n\t2. Top 3 by Rating";
//		    cout << "\nEnter your choice for top 3: ";
//		    cin >> topChoice;
//		
//		    if (topChoice == 1 || topChoice == 2) {
//		        lt.top3(topChoice);
//		    } else {
//		        cout << "Invalid choice for top 3";
//		    }
		} break;
		
		case 6: {
		    int maxChoice;
		    cout << "\n\t1. Max by Price";
		    cout << "\n\t2. Max by Rating";
		    cout << "\nEnter your choice for max: ";
		    cin >> maxChoice;
		
		    if (maxChoice == 1 || maxChoice == 2) {
		        lt.max(maxChoice);
		    } else {
		        cout << "Invalid choice for max";
		    }
		} break;

            default: {
                cout << "Invalid choice";
                break;
            }
        }
        cout << "\nDo you want to continue ('y' for yes and 'n' for no): ";
        cin >> control;
    } while (control == 'y' || control == 'Y');

    cout << "\n<-------------Thank you------------->\n";
    
    
    //write
    ofstream out("text.bin", ios::binary);
	if(out.is_open()){
		Node<Book>* temp = lt.getStart(); //iterate throught linkedlist
		while(temp!=NULL){
			Book b = temp->getData();
			out.write(reinterpret_cast<char*>(&b), sizeof(b));
			temp = temp->getNext();
		}
		out.close();
	}
	else{
		cout<<"File opening for writing is fail!\n";
	}

    return 0;
}

