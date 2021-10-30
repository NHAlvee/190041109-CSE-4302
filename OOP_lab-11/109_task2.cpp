#include <fstream> //for file-stream functions
#include <iostream>
#include <typeinfo> //for typeid()
using namespace std;
#include <process.h> //for exit()
const int MAX = 50;
enum p_type
{
    tcricket,
    tfootball
};
class player
{
protected:
    char player_name[50];
    char player_country[50];
    int age;
    static int player_no;
    static player *arrap[];

public:
    virtual void player_info()
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
    virtual p_type get_type(); //get type
    static void add();         //add an player
    static void display();     //display all players
    static void read();        //read from disk file
    static void write();       //write to disk file
};
int player::player_no;
player *player::arrap[MAX];
class cricketer : public player
{
private:
    char player_role[50];
    int runs;
    int wickets;

public:
    void player_info()
    {
        player::player_info();
        cout << "player role: " << player_role << endl;
        cout << "runs: " << runs << endl;
        cout << "wickets: " << wickets << endl;
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
};
class footballer : public player
{
private:
    char playing_position[50];
    int goals;
    int assists;

public:
    void player_info()
    {
        player::player_info();
        cout << "playing position: " << playing_position << endl;
        cout << "goals: " << goals << endl;
        cout << "assists: " << assists << endl;
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
};
void player::add()
{
    char ch;
    cout << "c to add a cricketer\n"
            "f to add a footballer\n";
    cin >> ch;
    switch (ch)
    { //create specified player type
    case 'c':
        arrap[player_no] = new cricketer;
        break;
    case 'f':
        arrap[player_no] = new footballer;
        break;
    default:
        cout << "\nUnknown player type\n";
        return;
    }
    arrap[player_no++]->set_player_info(); //get player data from user
}
void player::display()
{
    for (int j = 0; j < player_no; j++)
    {
        cout << (j + 1);              //display number
        switch (arrap[j]->get_type()) //display type
        {
        case tcricket:
            cout << ".Type: cricketer"<<endl;
            break;
        case tfootball:
            cout << ".Type: footballer"<<endl;
            break;
        default:
            cout << ".Unknown type"<<endl;
        }
        arrap[j]->player_info(); //display player data
        cout << endl;
    }
}
//typeid returns unique id for each class
p_type player::get_type()
{
    if (typeid(*this) == typeid(cricketer))
        return tcricket;
    else if (typeid(*this) == typeid(footballer))
        return tfootball;
    else
    {
        cerr << "\nBad player type";
        exit(1);
    }
    return tcricket;
}
void player::write()
{
    int size;
    cout << "Writing " << player_no << " player.\n";
    ofstream ouf; //open ofstream in binary
    p_type ptype; //type of each player object
    ouf.open("PLAY.DAT", ios::trunc | ios::binary);
    if (!ouf)
    {
        cout << "\nCan't open file\n";
        return;
    }
    for (int j = 0; j < player_no; j++) //for every player object
    {                                   //get its type
        ptype = arrap[j]->get_type();
        //write type to file
        ouf.write((char *)&ptype, sizeof(ptype));
        switch (ptype) //find its size
        {
        case tcricket:
            size = sizeof(cricketer);
            break;
        case tfootball:
            size = sizeof(footballer);
            break;
        } //write player object to file
        ouf.write((char *)(arrap[j]), size);
        if (!ouf)
        {
            cout << "\nCan't write to file\n";
            return;
        }
    }
}
void player::read()
{
    int size;     //size of player object
    p_type ptype; //type of player
    ifstream inf; //open ifstream in binary
    inf.open("PLAY.DAT", ios::binary);
    if (!inf)
    {
        cout << "\nCan't open file\n";
        return;
    }
    player_no = 0; //no players in memory yet
    while (true)
    { //read type of next player
        inf.read((char *)&ptype, sizeof(ptype));
        if (inf.eof()) //quit loop on eofr
            break;
        if (!inf) //error reading type
        {
            cout << "\nCan't read type from file\n";
            return;
        }
        switch (ptype)
        {              //make new player
        case tcricket: //of correct type
            arrap[player_no] = new cricketer;
            size = sizeof(cricketer);
            break;
        case tfootball:
            arrap[player_no] = new footballer;
            size = sizeof(footballer);
            break;
        default:
            cout << "\nUnknown type in file\n";
            return;
        } //read data from file into it
        inf.read((char *)arrap[player_no], size);
        if (!inf) //error but not eof
        {
            cout << "\nCan't read data from file\n";
            return;
        }
        player_no++; //count player
    }                //end while
    cout << "Reading " << player_no << " players\n";
}
int main()
{
    char ch;
    while (true)
    {
        cout << "'a'--add data for an player"
                "\n' d'--display data for all players"
                "\n' w'--write all player data to file"
                "\n' r'--read all player data from file"
                "\n' x'--exit"
                "\nEnter selection: ";
        cin >> ch;
        switch (ch)
        {
        case 'a': //add an player to list
            player::add();
            break;
        case 'd': //display all players
            player::display();
            break;
        case 'w': //write players to file
            player::write();
            break;
        case 'r': //read all players from file
            player::read();
            break;
        case 'x':
            exit(0); //exit program
        default:
            cout << "\nUnknown command";
        } //end switch
    }     //end while
    return 0;
} //end main()