#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>
#include "Room_Class.cpp"
#include "Standard_Room.cpp"
#include "Double_Bed_Room.cpp"
#include "RoomDAO.cpp"

using namespace std;

class Hotel_Room :public RoomDAO {

private:
    string name;
    Room* rooms[100];
    int count = 0;

public:

    Hotel_Room() :name("unknown") {
        Room *room1 = new Room(1, 1, "available","single");
        add_room(room1);
    };
    Hotel_Room(string name) :name(name) {};
    ~Hotel_Room() {};

    void add_room(Room* room)  {
        rooms[count] = new Room();
        rooms[count] = room;
        count++;
    }

    void edit_room(int room_id, int choice) {
        int id, floor;
        string type;
        string status;

        int found = find_room_by_id(room_id);
        if (found != -1) {
            if (choice == 1)
            {
                cout << "[-] Enter new room id: ";
                cin >> id;
                rooms[found]->set_id(id);
                cout << "\nEdit successfully!!!\n";
            }
            else if (choice == 2)
            {
                cout << "[-] Enter new room floor: ";
                cin >> floor;
                rooms[found]->set_floor(floor);
                cout << "\nEdit successfully!!!\n";
            }
            else if (choice == 3)
            {
                cout << "[-] Enter new room status: ";
                cin >> status;
                rooms[found]->set_status(status);
                cout << "\nEdit successfully!!!\n";
            }
            else
            {
                cout << "Invalid option!!!";
            }
           
        }
        else {
            cout << "[-] Room Not found" << endl;
        }
    }

    void delete_room_by_id(int id) {
        int found = find_room_by_id(id);
        if (found != -1) {
            for (int i = found; i < count; i++) {
                rooms[i] = rooms[i + 1];
            }
            count--;
            cout << "[-] Room has been remove" << endl;
        }
        else {
            cout << "[-] Room Not found" << endl;
        }
    }

    void view_all_room() {
        cout << "Room No " << setw(20) << "  " << "Room Floor" << setw(20) << " " << "Status" << setw(30) << "Bed type" << endl;
        for (int i = 0; i < count; i++) {
            cout << rooms[i]->get_id() << setw(30) << "  " << rooms[i]->get_floor() << setw(25) << " " << rooms[i]->get_status() << setw(25) << rooms[i]->get_bed_type() << endl;               
        }
    }

    Room* get_room_by_id(int id) {
        Room* room = nullptr;
        for (int i = 0; i < count; i++) {
            if (rooms[i]->get_id() == id) {
                return rooms[i];
            }
        }
        return room;
    }

    int find_room_by_id(int id) {
        for (int i = 0; i < count; i++) {
            if (rooms[i]->get_id() == id) {
                return i;
            }
        }
        return -1;
    }

    void sort_room_by_id() {
        for (int i = 0; i < count; i++) {
            for (int j = 0; j < count - i - 1; j++) {
                if (rooms[j]->get_id() > rooms[j + 1]->get_id()) {
                    Room* temp = rooms[j];
                    rooms[j] = rooms[j + 1];
                    rooms[j + 1] = temp;
                }
            }
        }
    }
    
};