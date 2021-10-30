#include <bits/stdc++.h>

using namespace std;

class player
{
protected:
    string player_name;
    string player_country;
    int age;

public:
    player() : player_name(""), player_country(""), age(0)
    {
    }
    player(string name, string c_name, int _age) : player_name(name), player_country(c_name), age(_age)
    {
    }
    void player_info()
    {
        cout << "Player name: " << player_name << endl;
        cout << "Country: " << player_country << endl;
        cout << "Age: " << age << endl;
    }
    virtual void set_player_info()
    {
        cout << "Enter name: ";
        cin >> player_name;
        cout << "Enter country: ";
        cin >> player_country;
        cout << "Enter age: ";
        cin >> age;
    }
    virtual void show_player_info() = 0;
};

class cricketer : public player
{
private:
    string player_role;
    int runs;
    int wickets;

public:
    cricketer()
    {
    }
    cricketer(string name, string c_name, int _age, string _role, int _runs, int _wickets) : player(name, c_name, _age), player_role(_role), runs(_runs), wickets(_wickets)
    {
    }
    void set_player_info()
    {
        player::set_player_info();
        cout << "Enter player role: ";
        cin >> player_role;
        cout << "Enter runs scored: ";
        cin >> runs;
        cout << "Enter wickets taken: ";
        cin >> wickets;
    }
    void show_player_info()
    {
        cout << "Cricketer info:-" << endl;
        player::player_info();
        cout << "Playing role: " << player_role << endl;
        cout << "Total runs: " << runs << endl;
        cout << "Total wickets: " << wickets << endl;
    }
};
class footballer : public player
{
private:
    string playing_position;
    int goals;
    int assists;

public:
    footballer()
    {
    }
    footballer(string name, string c_name, int _age, string _pos, int _goals, int _assists) : player(name, c_name, _age), playing_position(_pos), goals(_goals), assists(_assists)
    {
    }
    void set_player_info()
    {
        player::set_player_info();
        cout << "Enter playing position: ";
        cin >> playing_position;
        cout << "Enter goals scored: ";

        cin >> goals;
        cout << "Enter assists: ";
        cin >> assists;
    }
    void show_player_info()
    {
        cout << "Footballer info:-" << endl;
        player::player_info();
        cout << "Playing position: " << playing_position << endl;
        cout << "Total goals: " << goals << endl;
        cout << "Total assists: " << assists << endl;
    }
};
class stadium
{
protected:
    string stadium_name;

public:
    stadium() : stadium_name("")
    {
    }
    stadium(string _name) : stadium_name(_name)
    {
    }
    virtual void set_name()
    {
        cout << "Enter stadium name: ";
        cin >> stadium_name;
    }
};
class cricket_stadium : public stadium
{
private:
    int capacity;

public:
    cricket_stadium()
    {
    }
    cricket_stadium(string _name, int _capacity) : stadium(_name), capacity(_capacity)
    {
    }
    void set_name()
    {
        stadium::set_name();
        cout << "Enter total capacity: ";
        cin >> capacity;
    }
    void show_info()
    {
        cout << "Stadium name: " << stadium_name << endl;
        cout << "Total capacity: " << capacity << endl;
    }
};
int main()
{
    stadium stadium1;
    ///player player1;
    player *players[2];
    ///players[0]= new cricketer("Shanto","Bangladesh",21,"All rounder",100,500);
    players[0] = new cricketer();
    players[1] = new footballer("alvee", "Bangladesh", 20, "CF", 50, 100);
    players[0]->show_player_info();
    players[1]->show_player_info();
    players[0]->set_player_info();
    players[0]->show_player_info();
}