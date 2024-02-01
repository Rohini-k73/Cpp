#pragma once
class Book {
    int id;
    char name[30];
    double price;
    double rating;
    char author[20];

public:
    Book();
    Book(int, const char*, double, const char*, double);
    void setId(int id);
    void setName(const char*);
    void setAuthor(const char*);
    void setPrice(double);
    void setRating(double);
    int getId();
    const char* getName();
    double getPrice();
    const char* getAuthor();
    double getRating();
    void display();
};


