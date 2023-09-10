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

    // Logical AND operator (considering non-zero as true)
    bool operator&&(const Complex &other) const
    {
        return (this->real && other.real) && (this->imaginary && other.imaginary);
    }

    // Logical OR operator (considering non-zero as true)
    bool operator||(const Complex &other) const
    {
        return (this->real || other.real) || (this->imaginary || other.imaginary);
    }

    // Logical NOT operator (considering non-zero as true)
    bool operator!() const
    {
        return !(this->real || this->imaginary);
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
    Complex cmp2(0, 0);

    // Logical AND operation
    bool logicalAnd = cmp1 && cmp2;
    cout << "Logical AND: " << (logicalAnd ? "True" : "False") << endl;

    // Logical OR operation
    bool logicalOr = cmp1 || cmp2;
    cout << "Logical OR: " << (logicalOr ? "True" : "False") << endl;

    // Logical NOT operation
    bool logicalNot = !cmp1;
    cout << "Logical NOT: " << (logicalNot ? "True" : "False") << endl;

    return 0;
}
