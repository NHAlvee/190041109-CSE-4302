#include <bits/stdc++.h>

using namespace std;
const int MAX = 3;
template <class Type>
class my_stack
{
private:
    Type stk[MAX];
    int top;

public:
    class Full
    {
    };
    class Empty
    {
    };
    my_stack() : top(-1)
    {
    }
    void push(Type inp)
    {
        if (top == MAX - 1)
            throw Full();
        else
        {
            top++;
            stk[top] = inp;
        }
    }
    Type pop()
    {
        if (top == -1)
            throw Empty();
        else
        {
            Type temp;
            temp = stk[top];
            stk[top--] = -999;
            return temp;
        }
    }
    Type peek()
    {
        return stk[0];
    }
};
int main()
{
    try
    {
        my_stack<int> s1;
        s1.push(100);
        s1.push(200);
        s1.push(300);
        cout << "First element inserted: " << s1.peek() << endl;
        cout << "elements: " << endl;
        cout << "1. " << s1.pop() << endl;
        cout << "2. " << s1.pop() << endl;
        cout << "3. " << s1.pop() << endl;
    }
    catch (my_stack<int>::Full)
    {
        cout << "Exception: my_stack Full" << endl;
    }
    catch (my_stack<int>::Empty)
    {
        cout << "Exception: my_stack Empty" << endl;
    }
    return 0;
}