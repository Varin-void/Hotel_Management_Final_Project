#include <iostream>
#include "RunApp.cpp"
#include "UserManager.cpp"
#include "User.cpp"
using namespace std;

int main() 
{
    Application app;
    UserManager userManager;
    string username;
    string password;

    do {
        system("cls");
        cout << "===========Login===========" << endl;
        cout << "Enter username: ";
        cin >> username;
        cout << "Password: ";
        cin >> password;
        User* user = userManager.authenticateUser(username, password);
        if (user != nullptr) {
            if (user->getType() == "ADMIN") {
                cout << "\n\nLogin Success!!!!\n";
                system("pause");
                system("cls");
                app.user();
            }
            else if (user->getType() == "NORMAL") {
                cout << "\n\nLogin Success!!!!\n";
                system("pause");
                system("cls");
                app.run();
            }
        }
        else {
            cout << "Invalid user" << endl;
        }
    } while (true);

}