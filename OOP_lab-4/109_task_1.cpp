#include <bits/stdc++.h>

using namespace std;
class calculator
{
private:
    int value;

public:
    calculator() : value(0)
    {
    }
    calculator(int ival)
    {
        value = ival;
    }
    int getvalue()
    {
        return value;
    }
    void setvalue(int iv)
    {
        value=iv;
    }
    void add(int ival)
    {
        value += ival;
    }
    void subtract(int ival)
    {
        value -= ival;
    }
    void multiply(int ival)
    {
        value *= ival;
    }
    void division(int ival)
    {
        if (ival == 0)
        {
            cout << "Error: divoded by 0 is undefined" << endl;
            return;
        }
        value /= ival;
    }
    void clear()
    {
        value = 0;
    }
    void display() const
    {
        cout << "Calculator display: " << value << endl;
    }
    ~calculator()
    {
        cout << "calculator object is destroyed" << endl;
    }
};
int main()
{
    calculator calc(0);
    calc.add(10);
    calc.display();
    calc.add(7);
    calc.display();
    calc.multiply(31);
    calc.display();
    calc.subtract(42);
    calc.display();
    calc.division(7);
    calc.display();
    calc.division(0);
    calc.display();
    calc.add(3);
    calc.display();
    calc.subtract(1);
    calc.display();
    calc.clear();
    calc.display();
    
    return 0;
}