#include "user.h"
#include <iostream>
#include "appartment.h"
#include "blocks.h"
#include "person.h"

using namespace std;

void user()
{
    Appartment a;
    char s[20];
    char person_location[30];
    char file_location[30];
    char *h;
    start:
    h = a.entryMenu();
    strcpy(s,h);
    delete h;
    if(strcmp(s," ")==0)
        return;
    strcpy(person_location,s);
    strcat(person_location,"/");
    Block b(s);
    h = b.entryMenu();
    strcpy(s,h);
    delete h;
    if(strcmp(s," ")==0)
        goto start;
    Hashmap ha;
    strcpy(file_location,person_location);
    strcat(file_location,s);
    ha.reset();
    ha.loadfromfile(file_location);
    int rno;
    cout << "Enter the room number:";
    cin >> rno;
    if(rno >=100)
    {
        cout << "\nInvalid";
        return;
    }
    ha.searchanddisplay(rno,person_location);
    cout << endl;

}
