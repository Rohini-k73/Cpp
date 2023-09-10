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

    // Arithmatic operator overloading
    //  for addition
    Complex operator+(int a)
    {
        Complex ans;
        ans.setReal(this->getReal() + a);
        ans.setImaginary(this->getImaginary() + a);
        return ans;
    }
    Complex operator+(Complex c)
    {
        Complex ans;
        ans.setReal(this->real + c.getReal());
        ans.setImaginary(this->imaginary + c.getImaginary());
        return ans;
    }

    // for substraction
    Complex operator-(int a)
    {
        Complex ans;
        ans.setReal(this->getReal() - a);
        ans.setImaginary(this->getImaginary() - a);
        return ans;
    }
    Complex operator-(Complex c)
    {
        Complex ans;
        ans.setReal(this->real - c.getReal());
        ans.setImaginary(this->imaginary - c.getImaginary());
        return ans;
    }

    // for multiplication
    Complex operator*(int a)
    {
        Complex ans;
        ans.setReal(this->getReal() * a);
        ans.setImaginary(this->getImaginary() * a);
        return ans;
    }
    Complex operator*(Complex c)
    {
        Complex ans;
        ans.setReal(this->real * c.getReal());
        ans.setImaginary(this->imaginary * c.getImaginary());
        return ans;
    }

    // for Division
    Complex operator/(int a)
    {
        Complex ans;
        ans.setReal(this->getReal() / a);
        ans.setImaginary(this->getImaginary() / a);
        return ans;
    }
    Complex operator/(Complex c)
    {
        Complex ans;
        ans.setReal(this->real / c.getReal());
        ans.setImaginary(this->imaginary / c.getImaginary());
        return ans;
    }

    void display()
    {
        cout << "complex number is: " << real << " + " << imaginary << "i\n";
    }
};

Complex operator+(int a, Complex c)
{
    Complex ans;
    ans.setReal(a + c.getReal());
    ans.setImaginary(a + c.getImaginary());
    return ans;
}
Complex operator-(int a, Complex c)
{
    Complex ans;
    ans.setReal(c.getReal() - a);
    ans.setImaginary(c.getImaginary() - a);
    return ans;
}
Complex operator*(int a, Complex c)
{
    Complex ans;
    ans.setReal(c.getReal() * a);
    ans.setImaginary(c.getImaginary() * a);
    return ans;
}
Complex operator/(int a, Complex c)
{
    Complex ans;
    ans.setReal(c.getReal() / a);
    ans.setImaginary(c.getImaginary() / a);
    return ans;
}

int main()
{
    Complex cmp1(5, 9);
    Complex cmp2(5, 9);
    Complex cmp3;

    cout << "\nAdding:\n";
    cmp3 = cmp1 + 10; // adding one integer
    cmp3.display();
    cmp3 = cmp1 + cmp2; // adding two complex object/variables;
    cmp3.display();
    cmp3 = 10 + cmp2; // adding one integer and one complex object/variables;
    cmp3.display();

    cout << "\nSubracting:\n";
    cmp3 = cmp1 - 10;
    cmp3.display();
    cmp3 = cmp1 - cmp2;
    cmp3.display();
    cmp3 = 10 - cmp2;
    cmp3.display();

    cout << "\nMultiplication:\n";
    cmp3 = cmp1 * 10;
    cmp3.display();
    cmp3 = cmp1 * cmp2;
    cmp3.display();
    cmp3 = 10 * cmp2;
    cmp3.display();

    cout << "\nDivision:\n";
    cmp3 = cmp1 / 10;
    cmp3.display();
    cmp3 = cmp1 / cmp2;
    cmp3.display();
    cmp3 = 10 / cmp2;
    cmp3.display();

    return 0;
};
