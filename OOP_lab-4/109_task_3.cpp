#include<bits/stdc++.h>

using namespace std;
class ZooAnimal{
private:
    char nameOfAnimal[20];
    int birthyear;
    int cageNumber;
    float weight;
    int height;
public:
    ZooAnimal():birthyear(2021),cageNumber(0),weight(0.0),height(0)
    {
        strcpy(nameOfAnimal,"");
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
        weight = iw;
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
        return weight;
    }
    int get_height()
    {
        return height;
    }
    int get_age()
    {
        return 2021-birthyear;
    }
    void getInformation()
    {

        cout << "Name of Animal: " << nameOfAnimal << endl;
        cout<< "Birthyear: " << birthyear << endl;
        cout<< "Cage Number: " << cageNumber << endl;
        cout<< "Weight: " << weight << endl;
        cout << "Height: " << height << endl;
    }
};
int main()
{
    ZooAnimal animal1,animal2;
    animal1.getInformation();
    cout<<animal1.get_age()<<endl;
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
    return 0;
}