#include "admin.h"
#include "appartment.h"
#include "RoomGraph.h"

using namespace std;

void admin()
{
    int exit = 0,ch;
    Appartment a;
    do
    {
        system("cls");
        cout << "ADMIN" << endl << endl;
        cout << "Menu" << endl;
        cout << "1.Create appartment" << endl;
        cout << "2.Use appartment" << endl;
        cout << "3.Delete appartment" << endl;
        cout << "4.Exit" << endl;
        cout << "Enter your choice:";
        cin>> ch;
        switch(ch)
        {
        case 1:
            {
                char s[100];
                cout << "Enter the name of the appartment:";
                cin >> s;
                a.addentry(s);
            }
        case 2:{
            char s[20];
            char *h = a.entryMenu();
            strcpy(s,h);
            delete h;
            if(strcmp(s," ")==0)
                break;
            a.use_appartment(s);
            break;
        }
        case 3:
            {
                char s[20];
                char *h = a.entryMenu();
                strcpy(s,h);
                delete h;
                if(strcmp(s," ")==0)
                    break;
                a.removefile(s);
            }
        break;
        case 4: exit =1;
        break;
        }
        cout << endl;
        system("pause");
    }while(exit == 0);
}
