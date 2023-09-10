#include <iostream>

using namespace std;

struct Complex
{
    int real;
    int imaginary;

    Complex()
    {
        real = 0;
        imaginary = 0;
    }
    Complex(int real, int imaginary)
    {
        this->real = real;
        this->imaginary = imaginary;
    }

    // Overload the bitwise AND operator (&)
    Complex operator&(const Complex &other)
    {
        Complex result;
        result.real = this->real & other.real;
        result.imaginary = this->imaginary & other.imaginary;
        return result;
    }

    // Overload the bitwise OR operator (|)
    Complex operator|(const Complex &other)
    {
        Complex result;
        result.real = this->real | other.real;
        result.imaginary = this->imaginary | other.imaginary;
        return result;
    }

    // Overload the bitwise XOR operator (^)
    Complex operator^(const Complex &other)
    {
        Complex result;
        result.real = this->real ^ other.real;
        result.imaginary = this->imaginary ^ other.imaginary;
        return result;
    }

    // Display function
    void display()
    {
        cout << "Complex number: " << real << " + " << imaginary << "i" << endl;
    }
};

int main()
{
    Complex cmp1(5, 9);
    Complex cmp2(3, 6);
    Complex result;

    // Bitwise AND operation
    result = cmp1 & cmp2;
    cout << "Bitwise AND result: ";
    result.display();

    // Bitwise OR operation
    result = cmp1 | cmp2;
    cout << "Bitwise OR result: ";
    result.display();

    // Bitwise XOR operation
    result = cmp1 ^ cmp2;
    cout << "Bitwise XOR result: ";
    result.display();

    return 0;
}
