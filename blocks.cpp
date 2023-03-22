#include "blocks.h"

#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <sys/stat.h>
#include <sys/types.h>
#include <cstdlib>

using namespace std;

bool check_file_present(char* a);

Block::Block(char* dirname)
{
    char some[100];
    strcpy(some,dirname);
    strcpy(currentname,some);
    strcat(currentname,"/");
    strcat(some,"/block_details");

    strcat(some,".blk");

    if(!check_file_present(some))
    {
        ofstream f(some,ios::out);
        f.close();
    }

}
void Block::addentry(char* filename)
{
    char some[100];
    strcpy(some,currentname);
    strcat(some,"/block_details.blk");

    if(!check_file_present(some))
    {
        cout << "\nFile is not present.";
        return;
    }
    strcpy(some," ");
    strcpy(some,currentname);
    strcat(some,filename);
    cout << "The file name is " << some;
    createdirectory(some);
    strcpy(some," ");
    strcpy(some,currentname);
    strcat(some,"block_details.blk");
    cout << "The file name is " << some;
    ofstream f(some,ios::out|ios::app);

    f<<filename<<endl;
    f.close();
}

void Block::createdirectory(char* filename)
{

    if (mkdir(filename) == -1)
        cerr << "\nError :  " << strerror(errno) << endl;

    else
        cout << "\nDirectory created";
}

char* Block::entryMenu()
{
    char **s = new char*[10];
    for(int i=0; i < 10; i++)
        s[i] = new char[60];
    int n=0;
    char some[100];
    strcpy(some,currentname);
    strcat(some,"/block_details.blk");
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
        cout << "Block" << endl << endl;
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

void Block::removefile(char* filename)
{
    char some[100];
    strcpy(some,currentname);
    strcat(some,filename);
    cout << "\nThe directory is " << some;
    if (rmdir(some) == -1)
        cerr << "\nError :  " << strerror(errno) << endl;

    else
        cout << "\nDirectory deleted.";
    strcpy(some,currentname);
    strcat(some,"/block_details.blk");
    ifstream rf(some,ios::in);
    ofstream wf("temp.aprt",ios::out);
    char w[50];
    while(true)
    {
        rf.getline(w,50);
        if(!rf)
            break;
        if(strcmp(filename,w)!=0)
        wf << w<<endl;
    }
    rf.close();
    wf.close();
    remove(some);
    rename("temp.aprt",some);
}

Hashmap::Hashmap()
{
    Room r;
    for(int i=0; i < 10; i++)
    {
        for(int j=0; j < 10; j++)
        {
            r.rno = j+10*i;
            rg[i].insertRoom(r);
            if(r.rno%10 !=0)
                rg[i].add_edge(r.rno,r.rno-1);
            if(r.rno%10 == 9)
                rg[i].add_edge(r.rno,10*i);
        }
    }
}
int Hashmap::hashcode(int rno)
{
    return rno/10;
}
void Hashmap::display()
{
    cout <<"\nTraversal\n";
    for(int i=0; i < 10; i++)
    {
        rg[i].bfstraversal2();
        cout << endl;
    }
}
void Hashmap::modify(char* dirname)
{
    int rno;
    cout << "Enter the room number to modify:";
    cin>> rno;
    fflush(stdin);
    rg[hashcode(rno)].modify(rno,dirname);
}
void Hashmap::writetofile(char*blk)
{
    char some[100];
    for(int i=0; i < 10; i++)
    {
        strcpy(some,blk);
        strcat(some,"/");
        strcat(some,"floor");
        char numbstr[10];
        itoa(i,numbstr,10);
        strcat(some,numbstr);
        strcat(some,".dat");
        cout << "\nThe file name is: " << some << endl;
        rg[i].print_to_file(some);
    }
}
void Hashmap::loadfromfile(char*blk)
{
    char some[100];
    Room r;
    for(int i=0; i < 10; i++)
    {
        strcpy(some,blk);
        strcat(some,"/");
        strcat(some,"floor");
        char numbstr[10];
        itoa(i,numbstr,10);
        strcat(some,numbstr);
        strcat(some,".dat");
        cout << "\nThe file name is: " << some << endl;
        ifstream f(some,ios::in);

            for(int j=0; j < 10; j++)
            {
                f.read((char*)&r,sizeof(r));
                rg[i].insertRoom(r);
                rg[i].bfstraversal();
                if(r.rno%10 !=0)
                    rg[i].add_edge(r.rno,r.rno-1);
                if(r.rno%10 == 9)
                    rg[i].add_edge(r.rno,10*i);
            }
        f.close();
    }
    system("pause");
}
void Hashmap::reset()
{
    for(int i=0; i < 10; i++)
        rg[i].reset();
}
void Hashmap::searchanddisplay(int rno,char* dirname)
{
    rg[hashcode(rno)].displayfloor(rno,dirname);
}
void Block::use_block(char* blk)
{
    int exit = 0,ch;
    char some[100];
    strcpy(some,currentname);
    strcat(some,blk);
    Hashmap h;
    h.reset();
    h.loadfromfile(some);
    do
    {
        system("cls");
        cout << "Block " << blk << endl << endl;
        cout << "Menu" << endl;
        cout << "1.Display rooms" << endl;
        cout << "2.Change owner" << endl;
        cout << "3.Save file" << endl;
        cout << "4.Exit" << endl;
        cout << "Enter your choice:";
        cin>> ch;
        switch(ch)
        {
        case 1:
            {
                h.display();
            }
            break;
        case 2:{
            h.modify(currentname);
        }
            break;
         case 3:{
            h.writetofile(some);
        }
            break;
        case 4:
            exit = 1;
        break;
        }
        cout << endl;
        system("pause");
    }while(exit == 0);
}
