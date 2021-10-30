#include <iostream>
#include <string>
using namespace std;

enum class Material
{
    Wood,
    Board,
    Steel,
    foam
};
class Furniture
{
protected:
    double price;
    double discount;
    Material madeof;
    string product_name;

public:
    Furniture(double p, double d, Material m, string p_name) : price(0), discount(0), madeof(Material::Wood), product_name("")
    {
        setPrice(p);
        setDiscount(d);
        setMadeof(m);
        setName(p_name);
    }
    void setPrice(double val)
    {
        if (val > 0)
            price = val;
    }
    void setDiscount(double val)
    {
        if (val <= price)
            discount = val;
    }
    void setMadeof(Material val)
    {
        madeof = val;
    }
    void setName(string p_name)
    {
        product_name = p_name;
    }
    void setDiscountPercentage(double perc)
    {
        discount = price * perc / 100;
    }
    double getDiscount()
    {
        return discount;
    }
    double getPrice()
    {
        return price;
    }
    string getMadeof()
    {
        if (madeof == Material::Wood)
            return string("Wood");
        else if (madeof == Material::Board)
            return string("Board");
        else if (madeof == Material::Steel)
            return string("Steel");
        else
            return string("");
    }
    virtual void productDetails() = 0;
};

enum class BedSize
{
    Single,
    SemiDouble,
    Double
};

class Bed : public Furniture
{
    BedSize Bedsize;

public:
    Bed(double ip, double id, Material im, BedSize s, string ipn) : Furniture(ip, id, im, ipn), Bedsize(s)
    {
    }
    void productDetails()
    {

        cout << "Name: " << product_name << endl;
        cout << "Regular Price: " << price << endl;
        cout << "Discounted Price: " << price - discount << endl;
        cout << "Material: " << getMadeof() << endl;
        //Furniture::productDetails();
        cout << "Bed Size: ";
        if (Bedsize == BedSize::Double)
            cout << "Double";
        else if (Bedsize == BedSize::SemiDouble)
            cout << "SemiDouble";
        else if (Bedsize == BedSize::Single)
            cout << "Single";
        else
            cout << "";
        cout << endl;
    }
};
enum class SofaSize
{
    One,
    Two,
    Three,
    Four,
    Five
};
class Sofa : public Furniture
{
    SofaSize Sofasize;

public:
    Sofa(double ip, double id, Material im, SofaSize s, string ipn) : Furniture(ip, id, im, ipn), Sofasize(s)
    {
    }
    void productDetails()
    {
        cout << "Name: " << product_name << endl;
        cout << "Regular Price: " << price << endl;
        cout << "Discounted Price: " << price - discount << endl;
        cout << "Material: " << getMadeof() << endl;
        //Furniture::productDetails();
        cout << "Sofa Size: ";
        if (Sofasize == SofaSize::One)
            cout << "One";
        else if (Sofasize == SofaSize::Two)
            cout << "Two";
        else if (Sofasize == SofaSize::Three)
            cout << "Three";
        else if (Sofasize == SofaSize::Four)
            cout << "Four";
        else if (Sofasize == SofaSize::Five)
            cout << "Five";
        else
            cout << "";
        cout << endl;
    }
    ~Sofa()
    {
    }
};
enum class AlmirahSize
{
    Two,
    Three,
    Four
};
class Almirah : public Furniture
{
    AlmirahSize Almirahsize;

public:
    Almirah(double ip, double id, Material im, AlmirahSize s, string ipn) : Furniture(ip, id, im, ipn), Almirahsize(s) {}
    void productDetails()
    {
        cout << "Name: " << product_name << endl;
        cout << "Regular Price: " << price << endl;
        cout << "Discounted Price: " << price - discount << endl;
        cout << "Material: " << getMadeof() << endl;
        //Furniture::productDetails();
        cout << "Almirah Size: ";
        if (Almirahsize == AlmirahSize::Two)
            cout << "Two";
        else if (Almirahsize == AlmirahSize::Four)
            cout << "Four";
        else if (Almirahsize == AlmirahSize::Three)
            cout << "Three";
        else
            cout << "";
        cout << endl;
    }
};

/**task 4
sort_furniture_discount will sort the array in descending order based on their discount price.
You may need to add some member functions
**/
void order(Furniture **a, Furniture **b)
{
    if ((*a)->getPrice() - (*a)->getDiscount() < (*b)->getPrice() - (*b)->getDiscount())
    {
        Furniture *temp = *a;
        *a = *b;
        *b = temp;
    }
}

void sort_furniture_discount(Furniture *furnitures[], int n)
{
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            order(furnitures + i, furnitures + j);
        }
    }
}

int main()
{
    Furniture *f_list[100];

    /**
        task 1
        So that following lines can be executed without error
    */
    f_list[0] = new Bed(10000, 123, Material::Wood, BedSize::Single, "x");
    f_list[1] = new Sofa(11000, 234, Material::Steel, SofaSize::Five, "y");
    f_list[2] = new Almirah(13000, 345, Material::Wood, AlmirahSize::Two, "z");
    f_list[3] = new Bed(10090, 123, Material::Wood, BedSize::Single, "c");

    /**task 1 ends here*/

    /**
        task 2
        So that following lines can be executed without error

        task 3 (Modify productDetails)
    */
    f_list[2]->setDiscountPercentage(30);
    for (int i = 0; i < 4; i++)
    {
        f_list[i]->productDetails();
        cout << "####################" << endl;
    }

    /**task 2 ends here*/
    /**task 3 ends here*/

    /**task 4
    So that following lines can be executed without error
    */
    sort_furniture_discount(f_list, 4);
    cout << ".........................." << endl;
    cout << "########After Sort########" << endl;
    for (int i = 0; i < 4; i++)
    {
        f_list[i]->productDetails();
        cout << "####################" << endl;
    }
    for (int i = 0; i < 4; i++)
    {
        delete f_list[i];
    }
    /**task 4 ends here*/
}
