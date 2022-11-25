#pragma once
#include <iostream>
#include "User.cpp"
#include <fstream>
#include <iomanip>

class UserManager {
private:
	User users[100];
	int count = 0;
public:
	UserManager() {
		User user1("admin", "123", "ADMIN");
		User user2("rin", "123", "NORMAL");
		users[count++] = user1;
		users[count++] = user2;
	}
	void addUser(User user) {
		users[count] = user;
		count++;
	}
	void writeUserToFile(User user) {
		ofstream outFile;
		outFile.open("user.dat", ios::binary | ios::app);
		outFile.write((char*)(&user), sizeof(user));
		outFile.close();
	}
	void readUserFromFile() {
		User user;
		bool flag = false;
		ifstream inFile;
		inFile.open("user.dat", ios::binary);
		if (!inFile)
		{
			cout << "File could not be open !! Press any Key...";
			return;
		}
		cout << "\nUSER DETAILS\n";

		while (inFile.read((char*)(&user), sizeof(user)))
		{
			user.outputUser();
			flag = true;
		}
		inFile.close();
		if (flag == false) {
			cout << "\n\nUser does not exist";
		}
	}
	void viewUser() {
		cout << "UserName " << setw(20) << "  " << "User Type" << endl;
		for (int i = 0; i < count; i++) {
			cout <<endl <<"[+]" << users[i].getUsername() << setw(20) << "  " << users[i].getType() << endl;
		}
		
	}
	int findUserByName(string name) {
		for (int i = 0; i < count; i++) {
			if (users[i].getUsername() == name) {
				return i;
			}
		}
		return -1;
	}
	User* getUserByName(string name) {
		User* user = nullptr;
		for (int i = 0; i < count; i++) {
			if (users[i].getUsername() == name) {
				return &users[i];
			}
		}
		return user;
	}
	void editUser(string name) {
		string role;
		int found = findUserByName(name);
		if (found != -1) {
			cout << "Enter new role: ";
			cin >> role;
			users[found].setType(role);
			cout << "User has been edited" << endl;
		}
		else {
			cout << "Not found" << endl;
		}
	}

	void deleteUser(string name) {
		int found = findUserByName(name);
		if (found != -1) {
			for (int i = found; i < count; i++) {
				users[i] = users[i + 1];
			}
			count--;
			cout << "User has been deleted" << endl;
		}
		else {
			cout << "Not found" << endl;
		}
	}
	User* authenticateUser(string username, string password) {
		User* user = nullptr;
		for (int i = 0; i < count; i++) {
			if (users[i].getUsername() == username && users[i].getPassword() == password) {
				return &users[i];
			}
		}
		return user;
	}
};