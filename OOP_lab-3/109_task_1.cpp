#include <bits/stdc++.h>

using namespace std;
class Counter
{
private:
    int count;
    int count_increament;

public:
    Counter() : count(0), count_increament(0)
    {
    }
    void setIncrementStep(int step_val)
    {
        count_increament = step_val;
    }
    int getCount()
    {
        return count;
    }
    void increment()
    {
        count += count_increament;
    }
    void resetCount()
    {
        count = 0;
    }
};
int main()
{
    Counter get_count;
    get_count.setIncrementStep(5);
    get_count.increment();
    cout << get_count.getCount() << endl;
    get_count.resetCount();
    cout << get_count.getCount() << endl;
    get_count.setIncrementStep(3);
    get_count.increment();
    cout << get_count.getCount() << endl;

    return 0;
}