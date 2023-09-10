using namespace std;
#include <iostream>
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

    void setReal(int a)
    {
        this->real = a;
    }
    void setImaginary(int b)
    {
        this->imaginary = b;
    }

    int getReal()
    {
        return real;
    }
    int getImaginary()
    {
        return imaginary;
    }

    // relational operators overloading
    int operator>(Complex c)
    {
        if (this->getReal() > c.getReal())
            return 1;
        else
            return 0;
    }
    int operator<(Complex c)
    {
        if (this->getReal() < c.getReal())
            return 1;
        else
            return 0;
    }
    int operator>=(Complex c)
    {
        if (this->getReal() >= c.getReal())
            return 1;
        else
            return 0;
    }
    int operator<=(Complex c)
    {
        if (this->getReal() <= c.getReal())
            return 1;
        else
            return 0;
    }
    int operator==(Complex c)
    {
        if ((this->getReal() == c.getReal()) && (this->getImaginary() == c.getImaginary()))
            return 1;
        else
            return 0;
    }
    int operator!=(Complex c)
    {
        if ((this->getReal() != c.getReal()) || (this->getImaginary() != c.getImaginary()))
            return 1;
        else
            return 0;
    }
    void display()
    {
        cout << "complex number is: " << real << " + " << imaginary << "i\n";
    }
};

int main()
{
    Complex cmp1(5, 9);
    Complex cmp2(5, 9);
    Complex cmp3;

    if (cmp1 > cmp2)
    {
        cout << "cmp1 is greater\n";
    }
    else
    {
        cout << "cmp2 is greater\n";
    }

    if (cmp1 < cmp2)
    {
        cout << "cmp1 is less\n";
    }
    else
    {
        cout << "cmp2 is less\n";
    }

    if (cmp1 >= cmp2)
    {
        cout << "cmp1 is greater or both are equal\n";
    }
    else
    {
        cout << "cmp2 is greater or both are equal\n";
    }

    if (cmp1 <= cmp2)
    {
        cout << "cmp1 is less or both are equal\n";
    }
    else
    {
        cout << "cmp2 is less or both are equal\n";
    }

    if (cmp1 == cmp2)
    {
        cout << "both are equal\n";
    }
    else
    {
        cout << "both are not equal\n";
    }

    if (cmp1 != cmp2)
    {
        cout << "both are not equal\n";
    }
    else
    {
        cout << "both are equal\n";
    }
    return 0;
}