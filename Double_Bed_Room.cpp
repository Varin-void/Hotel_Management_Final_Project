#pragma once
#include <iostream>
#include "Room_Class.cpp"
using namespace std;

class Double_Bed_Room:public Room
{
private:
	Room room;
public:
	Double_Bed_Room() :room(0, 0, "", "") {};
	Double_Bed_Room(int id, int floor, string status, string bed_type) :room(id, floor, status, bed_type) {};
	~Double_Bed_Room(){};

	void input() {
		Room::input_info();		
	}

	void output() {
		Room::output_info();
	}
};
