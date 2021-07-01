#include <bits/stdc++.h>

using namespace std;
class Product
{
private:
    string name;
    double discountPercent, unitPrice;

public:
    Product() : unitPrice(10), discountPercent(0.5)
    {
    }
    void assignName(string product_name)
    {
        name = product_name;
        return;
    }
    void setPrice(double product_price)
    {
        if (product_price < 0)
            cout << "Price has to be non-negative" << endl;
        else
            unitPrice = product_price;
        return;
    }
    void setDiscPercent(double percent)
    {
        if (percent >= 0 && percent <= 10)
            discountPercent = percent;
        else
            cout<<"discount percent needs to be within 0-10%";
        return;
    }
    double getSellingPrice(int nos)
    {
        double result;
        result=(unitPrice - (unitPrice * (discountPercent/100))) * nos;
        return result;
    }
    void display()
    {
        cout << name << " has a unit price BDT " << unitPrice << ". Current discount " << discountPercent << "%." << endl;
        return;
    }
};
int main()
{
    Product product1,product2;
    product1.assignName("Drinko");
    product2.assignName("Pizza");
    product1.setPrice(30);
    product2.setPrice(300);
    product1.setDiscPercent(5.5);
    product2.setDiscPercent(7.25);
    product1.display();
    product2.display();
    cout<<"Discount Price of product 1: "<<product1.getSellingPrice(1)<<endl;
    cout<<"Discount Price of product 2: "<<product2.getSellingPrice(1)<<endl;
    return 0;
}