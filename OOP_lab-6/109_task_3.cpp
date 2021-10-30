#include <bits/stdc++.h>

using namespace std;
class ZooAnimal
{
private:
    char nameOfAnimal[20];
    int birthyear;
    int cageNumber;
    float weightData;
    int height;

public:
    ZooAnimal() : birthyear(2021), cageNumber(0), weightData(0.0), height(0)
    {
        strcpy(nameOfAnimal, "");
    }
    void set_name(char *iname)
    {
        strcpy(nameOfAnimal, iname);
    }
    void set_birthyear(int ibirth)
    {
        birthyear = ibirth;
    }
    void set_cageNo(int icage)
    {
        cageNumber = icage;
    }
    void set_weight(float iw)
    {
        weightData = iw;
    }
    void set_height(int ih)
    {
        height = ih;
    }
    char *get_name()
    {
        return nameOfAnimal;
    }
    int get_birthyear()
    {
        return birthyear;
    }
    int get_cagenumber()
    {
        return cageNumber;
    }
    float get_weight()
    {
        return weightData;
    }
    int get_height()
    {
        return height;
    }
    int get_age()
    {
        return 2021 - birthyear;
    }
    void getInformation()
    {

        cout << "Name of Animal: " << nameOfAnimal << endl;
        cout << "Birthyear: " << birthyear << endl;
        cout << "Cage Number: " << cageNumber << endl;
        cout << "Weight: " << weightData << endl;
        cout << "Height: " << height << endl;
    }
    int operator==(int data)
    {
        if (weightData == data)
            return 1;
        else
            return 0;
    }
    void operator --(int n)
    {
        height -= n;
    }
};
int main()
{
    ZooAnimal animal1, animal2;
    animal1.getInformation();
    cout << animal1.get_age() << endl;
    animal2.set_birthyear(2030);
    animal2.set_cageNo(120);
    animal2.set_height(5);
    animal2.set_name("Lion");
    animal2.set_weight(1000);
    animal2.get_birthyear();
    animal2.get_cagenumber();
    animal2.get_height();
    animal2.get_name();
    animal2.get_weight();
    animal2.getInformation();
    if (animal2 == 1000)
        cout << "weight matches" << endl;
    else
        cout << "weight doesn't match" << endl;
    animal2.operator --(2);
    animal2.getInformation();
    cout<<(1000.0==1000)<<endl;
    return 0;
}