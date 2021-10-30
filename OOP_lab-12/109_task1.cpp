#include <bits/stdc++.h>

using namespace std;
const int MAX = 50;
template <class Type>
class my_stack
{
private:
    Type stk[MAX];
    int top;

public:
    ///class Full{};
    ///class Empty {};
    my_stack() : top(-1)
    {
    }
    void push(Type inp)
    {
        top++;
        stk[top] = inp;
    }
    Type pop()
    {
        Type temp;
        temp=stk[top];
        stk[top--]=-999;
        return temp;

    }
    Type peek()
    {
        return stk[0];
    }
};
int main()
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
    return 0;
}