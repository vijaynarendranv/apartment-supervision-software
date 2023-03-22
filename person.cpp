#include "person.h"
#include <iostream>
#include <cstring>
#include <fstream>

bool check_file_present(char* a);

using namespace std;

Person::Person()
{
    strcpy(name,"");
    strcpy(aadhar_number,"");
    strcpy(ph_no,"");
    age = 0;
}
void Person::display()
{
    cout << "\nName:" << name;
    cout << "\nAge:" << age;
    cout << "\nAadhar:" << aadhar_number;
    cout << "\nPhone number:" << ph_no;
    cout << endl;
}

Person_class::Person_class(char* dirname)
{
    strcpy(this->dirname,dirname);
}

void Person_class::sign_up()
{
    Person p;
    cout << "\t\t SIGN UP FORM\n\n";
    cout << "Enter your name:";
    fflush(stdin);
    cin.getline(p.name,60);
    cout <<"Enter your age:";
    cin >> p.age;
    fflush(stdin);
    cout << "Enter your aadhar number:";
    cin >> p.aadhar_number;
    fflush(stdin);
    cout << "Enter your phone number:";
    cin >> p.ph_no;
    char some[100];
    strcpy(some,dirname);
    strcat(some,p.name);
    strcat(some,".dat");
    ifstream f(some,ios::in);
    if(f)
    {
        cout << "Sorry the name already exists.\n";
        f.close();
        return;
    }
    else
    {
        f.close();
        ofstream f2(some,ios::out);
        f2.write((char*)&p,sizeof(p));
        f2.close();
        strcpy(some,dirname);
        strcat(some,"persons.txt");
        ofstream f3(some,ios::out|ios::app);
        f3 << p.name << endl;
        f3.close();
    }
}
char* Person_class::entryMenu()
{
    char **s = new char*[10];
    for(int i=0; i < 10; i++)
        s[i] = new char[60];
    int n=0;
    char some[100];
    strcpy(some,dirname);
    strcat(some,"persons.txt");
    if(!check_file_present(some))
    {
        cout << "\nFile is not present.";
        return " ";
    }
    else
    {
        ifstream rf(some);
       while(true)
        {
            rf.getline(s[n],50);
            if(!rf)
                break;
            n++;
        }
        rf.close();
    }
    int exit = 0,ch;
    do
    {
        system("cls");
        cout << "Persons" << endl << endl;
        cout << "Menu" << endl;
        cout << "0. Remove owner" << endl;
        for(int i=0; i < n; i++)
        {
            cout << i+1 << "." <<s[i]<<endl;
        }
        cout << n+1 <<".Exit" << endl;
        cout << "Enter your choice:";
        cin>> ch;
        fflush(stdin);
        if(ch >=1 && ch <= n)
         {
             return s[ch-1];
         }
        else if(ch == 0)
        {
            char *ns = new char[10];
            strcpy(ns," ");
            return ns;
        }
        else if(ch == n+1)
            return NULL;
    }while(exit == 0);
    return NULL;
}
