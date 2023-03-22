#include <iostream>
#include "admin.h"
#include "user.h"

using namespace std;

int main()
{
    int exit = 0, ch;

    do
    {
        system("cls");
        cout << "Appartment Management" << endl << endl;
        cout << "Menu" << endl;
        cout << "1. Admin" << endl;
        cout << "2. User" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice:";
        cin >> ch;

        switch(ch)
        {
            case 1: admin();
            break;
            case 2: user();
            break;
            case 3: exit = 1;
            break;
            default:
                cout << "\nInvalid choice!";
            break;
        }
        cout << endl;
        system("pause");
    }while(exit == 0);
    return 0;
}
