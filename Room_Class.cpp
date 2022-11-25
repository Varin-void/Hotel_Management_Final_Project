#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Room
{
private:
	int room_id;
	int room_floor;
	string room_status;
	string bed_type;

public:
	Room() :room_id(0), room_floor(0), room_status(""),bed_type("") {};
	Room(int id, int floor, string status,string bed_type) : room_id(id), room_floor(floor), room_status(status),bed_type(bed_type) {};
	~Room(){};

	void set_id(int id) {
		if (id < 0)
		{
			throw "Invalid input";
		}
		else
		{
			this->room_id = id;
		}	
	}
	int get_id() {
		return room_id;
	}

	void set_floor(int floor) {
		this->room_floor = floor;
	}
	int get_floor(){
		return room_floor;
	}

	void set_status(string status) {
		this->room_status = status;
	}
	string get_status() {
		return room_status;
	}

	void set_bed_type(string bed_type) {
		this->bed_type = bed_type;
	}
	string get_bed_type() {
		return bed_type;
	}

	virtual void input_info() {
		try
		{
			cout << "[-] Enter Room ID : ";
			cin >> room_id;
			set_id(room_id);

			cout << "[-] Enter Room Floor : ";
			cin >> room_floor;

			cout << "[-] Enter Room Status : ";
			cin >> room_status;

			cout << "[-] Enter Room Type: ";
			cin >> bed_type;
		}
		catch (char* s)
		{
			cout << s;
		}
	}

	virtual void output_info() {
		cout << "[-] Room ID : " << room_id << endl;
		cout << "[-] Room Floor : " << room_floor << endl;
		cout << "[-] Room Status : " << room_status << endl;
		cout << "[-] Bed Type : " << bed_type << endl;
	}

};
