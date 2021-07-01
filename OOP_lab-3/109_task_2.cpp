#include <bits/stdc++.h>

using namespace std;
class RationalNumber
{
private:
    int numerator;
    int denominator;

public:
    void assign(int a, int b)
    {
        if (b == 0)
        {
            cout << "invalid denominator" << endl;
            return;
        }
        numerator = a;
        denominator = b;
    }
    double convert()
    {
        double result;
        result = (double)numerator / denominator;
        return result;
    }
    void invert()
    {
        if (numerator == 0)
        {
            cout << "invalid input" << endl;
            return;
        }
        swap(denominator, numerator);
    }
    void print()
    {
        cout << "The Rational Number is " << numerator << "/" << denominator << endl;
    }
};
int main()
{
    RationalNumber rational_number;
    rational_number.assign(15, 2);
    rational_number.print();
    cout << "After convertion :" << rational_number.convert() << endl;
    rational_number.invert();
    rational_number.print();

    return 0;
}