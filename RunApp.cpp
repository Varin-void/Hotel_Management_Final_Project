#include <iostream>
#include <fstream>
#include "Hotel_Room.cpp"
#include "Room_Class.cpp"
#include "Standard_Room.cpp"
#include "Double_Bed_Room.cpp"
#include "UserManager.cpp"
#include "User.cpp"

using namespace std;

enum Menu {
    ADD_ROOM = 1, SEARCH_ROOM, VIEW_ALL_ROOM, DELETE_ROOM, EDIT_ROOM, SORT_ROOM, EXIT_APP
};
enum Room_Type{
    STANDARD_ROOM = 1, DOUBLE_BED_ROOM
};
enum Choice{
    YES = 1, NO
};

class Application {
private:

public:
    void user() {
        char ch;
        int num = 0;
        int op = 0;
        char confirm;
        UserManager userManager;
        do
        {
            system("cls");
            cout << "==================================================" << endl;
            cout << "\tAdmin Menu" << endl;
            cout << "1. Add New User" << endl;
            cout << "2. View All User" << endl;
            cout << "3. Edit User" << endl;
            cout << "4. Delete User" << endl;
            cout << "0. Exit" << endl;
            cout << "Please Choose Option 0 - 4 :  ";
            cin >> ch;
            switch (ch)
            {
            case '1': {
                system("cls");
                
                User user;
                user.inputUser();
                userManager.addUser(user);
                
                cout << "The user has been Created!!!" << endl;
                system("pause");
                break;
            }
            case '2':
                system("cls");
                
                userManager.viewUser();

                system("pause");
                break;
            case '3': {
                system("cls");
                
                string username;
                cout << "Enter username:";
                cin >> username;
                userManager.editUser(username);
                cout << "The user has been edited successfully!!!" << endl;

                system("pause");
                break;
            }
            case '4': {
                system("cls");
                
                do
                {
                    string username;
                    cout << "Enter username you want to delete:";
                    cin >> username;

                    cout << "You Sure u want to delete? (y/n) :";
                    cin >> confirm;

                    if (confirm == 'y')
                    {
                        userManager.deleteUser(username);
                        cout << "The user has been deleted!!!" << endl;
                        system("pause");
                        break;
                    } 
                    
                } while (confirm != 'y' || confirm != 'Y');
                break;
            }
            default:
                cout << "\a";
            }
            
        } while (ch != '0');
    }

    void run() {
        int option;
        int choice = 1;
        int count = 0;
        int id;
        int search = 0;
        int choice_room;
        int confirm =0;
        char question;

        Hotel_Room hotel;
        Room* room = nullptr;
        Single_Bed_Room* standard_room = nullptr;
        Double_Bed_Room* double_room= nullptr;

        do
        {
            system("cls");

            show_menu();

            int choice = get_command();

            switch (choice)
            {
            
            case ADD_ROOM:
                do
                {
                    system("cls");
                    
                    cout << "[-] Room Types" << endl;
                    cout << "\t1. Standard Room" << endl;
                    cout << "\t2. Double Bed Room" << endl;
                    cout << "Please enter your option: ";
                    cin >> option;

                    switch (option)
                    {

                    case STANDARD_ROOM:
                        standard_room = new Single_Bed_Room();
                        standard_room->input();
                        hotel.add_room(standard_room);
                        count++;
                        cout << "\n[-] Room has been added!!!\n";
                        
                        break;

                    case DOUBLE_BED_ROOM:
                        double_room = new Double_Bed_Room();
                        double_room->input();
                        hotel.add_room(double_room);
                        count++;
                        cout << "\n[-] Room has been added!!!\n";
                        
                        break;
                    default:
                        cout << "\n[-] Invalid Input!!!\n";
                        break;
                    }
                    
                    cout << "Do you want to continue ( Y or N ) ??? : ";
                    cin >> question;
                    
                } while (question != 'n');

                break;

            case SEARCH_ROOM:
                system("cls");
                
                cout << "[-] Enter Room ID you want to find: ";
                cin >> id;
                search = hotel.find_room_by_id(id);
                if (search == -1)
                {    
                    cout << "[!!!] Room Not Found [!!!]";
                    system("pause");
                }
                else
                {
                    cout << "[-] Result of search : " << endl;
                    hotel.get_room_by_id(id)->output_info();
                    system("pause");
                }
                break;

            case VIEW_ALL_ROOM:
                system("cls");
                
                cout << "[-] All Rooms Info: " << endl;
                hotel.view_all_room();
                cout << endl;
                system("pause");
                break;

            case DELETE_ROOM:
                system("cls");
                
                cout << "[-] Enter Room ID you want to Delete: ";
                cin >> id;
                search = hotel.find_room_by_id(id);
                if (search == -1)
                {
                    cout << "[!!!] Room Not Found [!!!]";
                }
                else
                {
                    cout << "[-] This is the Room you want to delete : " << endl;
                    hotel.get_room_by_id(id)->output_info();
                    cout << "\n[!!!] Please comfirm if u want to delete or not  (1 = Yes or 2 = No) [!!!] : ";
                    cin >> confirm;
                    switch (confirm)
                    {
                    case YES:
                        hotel.delete_room_by_id(id);
                        system("cls");
                        
                        cout << "The Room have been deleted Here is your new Rooms Detail : \n\n";
                        hotel.view_all_room();
                        system("pause");
                        break;
                    case NO:

                        break;
                    }
                }
                break;

            case EDIT_ROOM:
                system("cls");

                cout << "[-] Enter The room you want to Edit : ";
                cin >> id;
                choice_rooms();
                cout << "choose your option : ";
                cin >> choice_room;

                hotel.edit_room(id, choice_room);  

                system("pause");
                break;

            case SORT_ROOM:
                system("cls");

                cout << "[-] Result After sorting from Lower to higher Room ID :" << endl;
                hotel.sort_room_by_id();
                cout << "\nRooms Have Been Sorted!!!" << endl;
                hotel.view_all_room();
                system("pause");
                break;

            case EXIT_APP:
                cout << "Exit program" << endl;
                exit(0);

                break;

            default:
                cout << "Invalid Option!!!";
                break;
            }
        } while (choice != 7);
    }

    void show_menu() {
        system("cls");
        cout << "\n\t======================== Room Management Menu ========================";
        cout << "\n\n\t\t[01] Add Room";
        cout << "\n\n\t\t[02] Search Room";
        cout << "\n\n\t\t[03] View All Room";
        cout << "\n\n\t\t[04] Delete Specific Room";
        cout << "\n\n\t\t[05] Edit Room Information";
        cout << "\n\n\t\t[06] Sort Room";
        cout << "\n\n\t\t[07] EXIT";
        cout << "\n\n\t======================================================================";
        cout << "\n\n\t\t[--] Select Your Option (1-7) \n\n\n";
    }

    void choice_rooms() {
        cout << "\n[1] Edit room ID.";
        cout << "\n[2] Edit room FLoor.";
        cout << "\n[3] Edit room Status.";
        cout << "\n[4] Edit room type.";
        cout << endl;
    }

    int get_command() {
        int choice;
        cout << "Please enter your choice: ";
        cin >> choice;
        while (!is_legal(choice)) {
            cout << "Invalid choice, please enter again(1-7)" << endl;
            show_menu();
            cin >> choice;
        }
        return choice;
    }

    bool is_legal(int c) {
        return ((c == 1) || (c == 2) || (c == 3) || (c == 4) || ((c == 5) || (c == 6) || (c) == 7));
    }
};