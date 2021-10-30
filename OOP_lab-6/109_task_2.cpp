#include<bits/stdc++.h>

using namespace std;
class FLOAT{
private:
   float x;
public:
   FLOAT(): x(0)
   {

   }
   FLOAT(float ix): x(ix)
   {

   }
   FLOAT operator +(FLOAT f)
   {
       return FLOAT(x+f.x);
   }
   FLOAT operator -(FLOAT f)
   {
       return FLOAT(x-f.x);
   }
   FLOAT operator *(FLOAT f)
   {
       return FLOAT(x*f.x);
   }
   FLOAT operator /(FLOAT f)
   {
       if(f.x==0)
       {
           cout<<"Invalid"<<endl;
           return FLOAT(x);
       }
       return FLOAT(x/f.x);
   }
   operator int() const
   {
       return (int)x;
   }
   void display () const
   {
       cout<<"data: "<<x<<endl;
   }
   ~FLOAT()
   {
       cout<<"destructor"<<endl;
   }
};
int main()
{
    FLOAT f1(6.2), f2(9.8), f3(0), f4;
    f1.display();
    f2.display();
    f3.display();
    f4 = f1 + f2;
    f4.display();
    f4 = f1 - f3;
    f4.display();
    f4 = f1 * f2;
    f4.display();
    f4 = f2 / f3;
    f4.display();
    int i = f1;
    cout << "Int: " << i << endl; 
    return 0;
}