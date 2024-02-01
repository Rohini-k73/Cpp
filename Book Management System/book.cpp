#include "book.h"
#include <iostream>
#include <string.h>
#include <iomanip>

using namespace std;

Book::Book() {
    this->id = 0;
    strcpy(this->name, "not given");
    this->price = 0.0;
    strcpy(this->author, "not given");
    this->rating = 0.0; 
}

Book::Book(int id, const char* name, double price, const char* author, double rating) {
    this->id = id;
    strcpy(this->name, name);
    this->price = price;
    strcpy(this->author, author);
    this->rating = rating;
}

void Book::setId(int id) {
    this->id = id;
}

void Book::setName(const char* name) {
    strcpy(this->name, name);
}

void Book::setPrice(double price) {
    this->price = price;
}

void Book::setAuthor(const char* author) {
    strcpy(this->author, author);
}

void Book::setRating(double rating) {
    this->rating = rating;
}

int Book::getId() {
    return id;
}

const char* Book::getName() {
    return name;
}

double Book::getPrice() {
    return price;
}

const char* Book::getAuthor() {
    return author;
}

double Book::getRating() {
    return rating;
}


void Book::display() {
//    cout << "Id: " << this->id << endl;
//    cout << "Name: " << this->name << endl;
//    cout << "Price: " << this->price << endl;
//    cout << "Author: " << this->author << endl;
//    cout << "Rating: " << this->rating << endl;

	cout << "+----------------------------------------------------------------+" << endl;
    cout << "|    Book id    : "  << this->id << endl;
    cout << "|----------------------------------------------------------------|" << endl;
    cout << "|    Book Name  : "  << this->name  << endl;
    cout << "|----------------------------------------------------------------|" << endl;
    cout << "|    Author Name: " << this->author<< endl;
    cout << "|----------------------------------------------------------------|" << endl;
    cout << "|    Price      : "  << fixed << setprecision(2) << this->price  << endl;
    cout << "|----------------------------------------------------------------|" << endl;
    cout << "|    Rating       : "  << fixed << setprecision(2) << this->rating<< endl;
    cout << "+----------------------------------------------------------------+" << endl;
   
}

