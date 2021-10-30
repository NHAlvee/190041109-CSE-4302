#include <bits/stdc++.h>

using namespace std;
class Coordinate
{
private:
    float x, y;

public:
    Coordinate() : x(0), y(0)
    {
    }
    Coordinate(float ix, float iy) : x(ix), y(iy)
    {
    }
    ~Coordinate()
    {
        cout << "destructor" << endl;
    }
    float getDistance(Coordinate c)
    {
        float temp = sqrt(((x - c.x) * (x - c.x)) + ((y - c.y) * (y - c.y)));
        return temp;
    }
    float getDistance()
    {
        float temp = sqrt((x * x) + (y * y));
        return temp;
    }
    void move_x(float val)
    {
        x += val;
    }
    void move_y(float val)
    {
        y += val;
    }
    void move(float val)
    {
        move_x(val);
        move_y(val);
    }
    int operator==(Coordinate c)
    {
        if (getDistance() == c.getDistance())
            return 1;
        else
            return 0;
    }
    int operator!=(Coordinate c)
    {
        if (getDistance() != c.getDistance())
            return 1;
        else
            return 0;
    }
    int operator>(Coordinate c)
    {
        if (getDistance() > c.getDistance())
            return 1;
        else
            return 0;
    }
    int operator<(Coordinate c)
    {
        if (getDistance() < c.getDistance())
            return 1;
        else
            return 0;
    }
    int operator>=(Coordinate c)
    {
        if (getDistance() >= c.getDistance())
            return 1;
        else
            return 0;
    }
    int operator<=(Coordinate c)
    {
        if (getDistance() <= c.getDistance())
            return 1;
        else
            return 0;
    }
    Coordinate operator++(int)
    {
        x++;
        y++;
        return Coordinate(x, y);
    }
    Coordinate operator++()
    {
        x++;
        y++;
        return Coordinate(x, y);
    }
    Coordinate operator--(int)
    {
        x--;
        y--;
        return Coordinate(x, y);
    }
     Coordinate operator--()
    {
        x--;
        y--;
        return Coordinate(x, y);
    }
    void display() const
    {
        cout << "Abscissa: " << x << endl;
        cout << "Ordinate: " << y << endl;
    }
};
int main()
{
    Coordinate c1(5, 8.5), c2(4, 7.5);
    cout << "Distance from origin: " << c1.getDistance() << endl;
    cout << "Distance from another object: " << c1.getDistance(c2) << endl;
    c1.move(5);
    c1++;
    ++c1;
    --c2;
    c2--;
    c1.display();
    c2.display();
    if (c1 == c2)
        cout << "equal" << endl;
    else
        cout << "not equal" << endl;
    return 0;
}