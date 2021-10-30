#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Lab
{
private:
    string labName;
    int capacity;

public:
    Lab() : labName(""), capacity(0)
    {
    }
    Lab(string labName, int capacity) : labName(labName), capacity(capacity)
    {
    }
    string getLabName()
    {
        return labName;
    }
    int getCapacity()
    {
        return capacity;
    }
    void setLabName(string iname)
    {
        labName = iname;
    }
    void setCapacity(int icapacity)
    {
        capacity = icapacity;
    }
    void display() const
    {
        cout << "Lab " << labName << " " << capacity << " Capacity" << endl;
    }
};

class Lecturer_Room
{
private:
    string roomName;
    int roomNo;
    int capacity;

public:
    Lecturer_Room() : roomName(""), roomNo(0), capacity(0)
    {
    }
    Lecturer_Room(string roomName, int roomNo, int capacity) : roomName(roomName), roomNo(roomNo), capacity(capacity)
    {
    }

    string getRoomName()
    {
        return roomName;
    }
    int getCapacity()
    {
        return capacity;
    }
    void setRoomName(string irname)
    {
        roomName = irname;
    }
    void setCapacity(int icapacity)
    {
        capacity = icapacity;
    }
    void setRoomNo(int ir_no)
    {
        roomNo = ir_no;
    }
    int getRoomNo()
    {
        return roomNo;
    }
    void display() const
    {
        cout << roomName << " " << roomNo << " " << capacity << " Capacity" << endl;
    }
};

class N28Building
{
private:
    vector<Lab> Labs;
    vector<Lecturer_Room> Lecturer_Rooms;

public:
    N28Building()
    {
        cout << "Welcome to N28 Building" << endl;
    }
    void showAllLabs() const
    {
        cout << "Show all labs:" << endl;
        for (int i = 0; i < Labs.size(); i++)
            Labs[i].display();
        cout << endl;
    }
    void showAllLecturerRooms() const
    {
        cout << "Show all lecturer rooms:" << endl;
        for (int i = 0; i < Lecturer_Rooms.size(); i++)
            Lecturer_Rooms[i].display();
        cout << endl;
    }

    void addLab(string labName, int capacity)
    {
        Labs.push_back(Lab(labName, capacity));
    }

    void addLecturerRoom(string roomName, int roomNo, int capacity)
    {
        Lecturer_Rooms.push_back(Lecturer_Room(roomName, roomNo, capacity));
    }
};

int main()
{
    N28Building building;
    building.addLab("CSE", 100);
    building.addLab("MPE", 100);
    building.addLab("EEE", 100);
    building.addLecturerRoom("Hafiz", 101, 150);
    building.addLecturerRoom("Shafie", 102, 150);
    building.addLecturerRoom("Rahim", 103, 150);
    building.showAllLabs();
    building.showAllLecturerRooms();
}