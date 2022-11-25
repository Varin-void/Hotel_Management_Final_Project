#pragma once

#include <iostream>
#include "Room_Class.cpp"
#include <vector>
#include <fstream>

using namespace std;

class RoomDAO {
public:
	
    virtual void add_room(Room* room) = 0;

    virtual void edit_room(int room_id, int choice) = 0;      

    virtual void delete_room_by_id(int id) = 0;

    virtual void view_all_room() = 0;

    virtual Room* get_room_by_id(int id) = 0;

    virtual int find_room_by_id(int id) = 0;

    virtual void sort_room_by_id() = 0;


};


