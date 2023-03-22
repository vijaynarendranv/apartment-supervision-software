#include "appartment.h"
#include "blocks.h"
#include "person.h"
#include <fstream>

using namespace std;

bool check_file_present(char* a)
{
    ifstream f(a,ios::in|ios::binary);
    if(!f)
    {
        f.close();
        return false;
    }
    f.close();
    return true;
}

Appartment::Appartment()
{
    char some[100];
    strcpy(some,"apt_details");
    strcat(some,".aprt");
    if(!check_file_present(some))
    {
        ofstream f(some,ios::out);
        f.close();
    }

}
void Appartment::addentry(char* filename)
{
    if(!check_file_present("apt_details.aprt"))
    {
        cout << "\nFile is not present.";
        return;
    }
    createdirectory(filename);
    ofstream f("apt_details.aprt",ios::out|ios::app);

    f<<filename<<endl;
    f.close();
}

void Appartment::createdirectory(char* filename)
{
    if (mkdir(filename) == -1)
        cerr << "\nError :  " << strerror(errno) << endl;

    else
        cout << "\nDirectory created";
}

char* Appartment::entryMenu()
{
    char **s = new char*[10];
    for(int i=0; i < 10; i++)
        s[i] = new char[60];
    int n=0;
    if(!check_file_present("apt_details.aprt"))
    {
        cout << "\nFile is not present.";
        return " ";
    }
    else
    {
        ifstream rf("apt_details.aprt");
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
        cout << "Appartments" << endl << endl;
        cout << "Menu" << endl;
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
        else if(ch == n+1)
        {
            char *ns = new char[10];
            strcpy(ns," ");
            return ns;
        }
    }while(exit == 0);
    char *ns = new char[10];
    strcpy(ns," ");
    return ns;
}

void Appartment::removefile(char* filename)
{
    if (rmdir(filename) == -1)
        cerr << "\nError :  " << strerror(errno) << endl;

    else
        cout << "\nDirectory deleted.";
    ifstream rf("apt_details.aprt",ios::in);
    ofstream wf("temp.aprt",ios::out);
    char w[50];
    while(true)
    {
        rf.getline(w,50);
        if(!rf)
            break;
        if(strcmp(filename,w)!=0)
        wf << w << endl;
    }
    rf.close();
    wf.close();
    remove("apt_details.aprt");
    rename("temp.aprt","apt_details.aprt");
}
void Appartment::use_appartment(char* apt)
{
    int exit = 0,ch;
    Block b(apt);
    do
    {
        system("cls");
        cout << "APPARTMENT" << apt << endl << endl;
        cout << "Menu" << endl;
        cout << "1.Create Block" << endl;
        cout << "2.Use Block" << endl;
        cout << "3.Delete Block" << endl;
        cout << "4.Register person" << endl;
        cout << "5.Exit" << endl;
        cout << "Enter your choice:";
        cin>> ch;
        switch(ch)
        {
        case 1:
            {
                char s[100];
                cout << "Enter the name of the block:";
                cin >> s;
                b.addentry(s);
            }
        case 2:{
            char s[20];
            char *h = b.entryMenu();
            strcpy(s,h);
            delete h;
            if(strcmp(s," ")==0)
                break;
            b.use_block(s);
        }
            break;
        case 3:
            {
                char s[20];
                char *h = b.entryMenu();
                strcpy(s,h);
                delete h;
                if(strcmp(s," ")==0)
                    break;
                cout << "hello";
                b.removefile(s);
            }
        break;
        case 4: {
            char some[100];
            strcpy(some,apt);
            strcat(some,"/");
            Person_class p(some);
            p.sign_up();
        }
        break;
        case 5: {
            exit = 1;
        }
        }
        cout << endl;
        system("pause");
    }while(exit == 0);
}



