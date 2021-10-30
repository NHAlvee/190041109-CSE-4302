#include <bits/stdc++.h>

using namespace std;

class Default
{
public:
    int count = 0;
    string *arr;
    Default()
    {
        arr = new string[60];
    }
    void show()
    {
        for (int i = 0; i < count; i++)
        {
            cout << arr[i] << endl;
        }
        cout << "#############" << endl;
    }
    void add(string s)
    {
        arr[count++] = s;
    }
    void edit(int n, string x)
    {
        arr[n] = x;
    }
};
class manual_copy
{
public:
    int count = 0;
    string *arr;
    manual_copy()
    {
        arr = new string[60];
    }
    //new user defined copy constructor
    manual_copy(manual_copy &ob1)
    {
        count = ob1.count;
        arr = new string[60];
        for (int i = 0; i < count; i++)
        {
            arr[i] = ob1.arr[i];
        }
    }
    void operator=(manual_copy &ob1)
    {
        //arr = ob1.arr; 
        count = ob1.count;
        for (int i = 0; i < count; i++)
        {
            arr[i] = ob1.arr[i];
        }
    }
    void show()
    {
        for (int i = 0; i < count; i++)
        {
            cout << arr[i] << endl;
        }
        cout << "#############" << endl;
    }
    void add(string s)
    {
        arr[count++] = s;
    }
    void edit(int n, string x)
    {
        arr[n] = x;
    }
};

class employee
{
private:
    string name;
    employee &operator=(employee &obj)
    {
        name = obj.name;
        return *this;
    }
    employee(employee &obj)
    {
        name = obj.name;
    }

public:
    employee() {}
    employee(string s) : name(s) {}
};
int main()
{
   /* Default ob1;
    ob1.add("oop");
    ob1.add("is");
    ob1.add("cool");
    Default ob2 = ob1;
    ob1.show();
    ob2.show();
    ob1.edit(0, "ds");
    ob1.show();
    ob2.show();*/

    manual_copy obj1,obj3;
    obj1.add("oop");
    obj1.add("is");
    obj1.add("cool");
    manual_copy obj2 = obj1;
    obj1.show();
    obj2.show();
    obj1.edit(0, "ds");
    obj1.show();
    obj2.show();
    
    obj3=obj1;
    obj1.edit(0, "math");
    obj1.show();
    obj3.show();

    employee emp1("Alvee"),emp2;
    /// emp1=emp2;
   /// employee emp2=emp1;
}
