#include "RoomGraph.h"
#include <cstring>
#include <deque>
#include "person.h"
#include <algorithm>
#include <iostream>
#include <fstream>

#define RESET   "\033[0m"
#define GREEN   "\033[32m"
using namespace std;

Room::Room()
{
        rno = 0;
        bedrooms = 2;
        halls = 1;
        kitchens = 1;
        strcpy(owner," ");

}

void Room::get_data()
{
    cout << "Enter the room number:";
    cin >> rno;
    cout << "Enter the number of bhk";
    cin>> bedrooms >> halls >> kitchens;
    fflush(stdin);
    cout << "Enter owner name:";
    cin.getline(owner,60);

}

void Room::print_data()
{
    cout << "Room no:" << rno << endl;
    cout << "Bedrooms:" << bedrooms << endl;
    cout << "Halls:" << halls << endl;
    cout << "Kitchens:" << kitchens << endl;
    if(strcmp(owner," ")!=0)
    cout << "Owner:" << owner << endl;
    else
       cout << "Owner:" << "None" << endl;
}

void RoomGraph::insertRoom(Room a)
{
    graph[size].head = a;
    size++;
}

void RoomGraph::add_edge(int rno1, int rno2)
{
    int index1 = -1;
    int index2 = -1;
    for(int i=0; i < size; i++)
        if(rno1 == graph[i].head.rno)
            index1 = i;

    for(int i=0; i < size; i++)
        if(rno2 == graph[i].head.rno)
            index2 = i;

    if(index1 == -1 || index2 == -1) {
        cout << "Room is not yet added.";
        return;
    }

    graph[index1].adj_list.push_back(&graph[index2]);

    graph[index2].adj_list.push_back(&graph[index1]);

}

void RoomGraph::bfstraversal()
{
    if(size == 0)
    {
        cout << "Graph is empty" <<endl;
        return;
    }
    vector<adj_list_node*> visited;
    deque<adj_list_node*> q;
    q.push_back(&graph[0]);
    visited.push_back(&graph[0]);

    while(!q.empty())
    {
        adj_list_node* poppedelement = q.front();
        q.pop_front();
        for(auto &i: poppedelement->adj_list)
        {
            if(std::find(visited.begin(),visited.end(),i)==visited.end()) {

                visited.push_back(i);
                q.push_back(i);
            }

        }
    }
    cout << endl;
    for(auto &i: visited)
        i->head.print_data();
}
void RoomGraph::bfstraversal2()
{
    if(size == 0)
    {
        cout << "Graph is empty" <<endl;
        return;
    }
    vector<adj_list_node*> visited;
    deque<adj_list_node*> q;
    q.push_back(&graph[0]);
    visited.push_back(&graph[0]);

    while(!q.empty())
    {
        adj_list_node* poppedelement = q.front();
        q.pop_front();
        for(auto &i: poppedelement->adj_list)
        {
            if(std::find(visited.begin(),visited.end(),i)==visited.end()) {

                visited.push_back(i);
                q.push_back(i);
            }

        }
    }
    cout << endl;
    for(auto &i: visited)
        if(strcmp(i->head.owner," ")==0)
        cout << i->head.rno<<" ";
        else
            cout << GREEN << i->head.rno << RESET << " ";
}

void RoomGraph::print_to_file(char* filename)
{
    ofstream f(filename,ios::out|ios::trunc);
    for(int i=0; i < size; i++)
        f.write((char*)&graph[i].head,sizeof(graph[i].head));
    f.close();
}
adj_list_node* RoomGraph::bfssearch(int rno)
{
    if(size == 0)
    {
        cout << "Graph is empty" <<endl;
        return NULL;
    }
    vector<adj_list_node*> visited;
    deque<adj_list_node*> q;
    q.push_back(&graph[0]);
    visited.push_back(&graph[0]);

    while(!q.empty())
    {
        adj_list_node* poppedelement = q.front();
        q.pop_front();
        for(auto &i: poppedelement->adj_list)
        {
            if(std::find(visited.begin(),visited.end(),i)==visited.end()) {

                visited.push_back(i);
                q.push_back(i);
            }

        }
    }
    cout << endl;
    for(auto &i: visited)
        if(i->head.rno == rno)
            return i;
    return NULL;
}
void RoomGraph::modify(int rno,char*dirname)
{
    adj_list_node* n = bfssearch(rno);
    if(n== NULL)
    {
        cout << "No room number found.";
        return;
    }
    Person_class p(dirname);
    char* s= p.entryMenu();
    if(s == NULL)
    {
        return;
    }
    strcpy(n->head.owner,s);
    delete s;
}
void RoomGraph::displayfloor(int rno,char* dirname)
{
    system("cls");
    adj_list_node* n = bfssearch(rno);
    if(n== NULL)
    {
        cout << "No room number found.";
        return;
    }
    cout << "Floor number:" << rno%10 << "\n\n";
    cout << "\t\t\t";
    if(graph[0].head.rno == rno)
    {
        cout << GREEN << "||" << RESET;
    }
    else
        cout << "||";
    cout << "\n\n";
     cout << "\t\t";
    if(graph[9].head.rno == rno)
    {
        cout << GREEN << "||" << RESET;
    }
    else
        cout << "||";
         cout << "\t\t";
    if(graph[1].head.rno == rno)
    {
        cout << GREEN << "||" << RESET;
    }
    else
        cout << "||";
    cout << "\n\n";
     cout << "\t\t";
    if(graph[8].head.rno == rno)
    {
        cout << GREEN << "||" << RESET;
    }
    else
        cout << "||";
         cout << "\t\t";
    if(graph[2].head.rno == rno)
    {
        cout << GREEN << "||" << RESET;
    }
    else
        cout << "||";
    cout << "\n\n";
     cout << "\t\t";
    if(graph[7].head.rno == rno)
    {
        cout << GREEN << "||" << RESET;
    }
    else
        cout << "||";
         cout << "\t\t";
    if(graph[3].head.rno == rno)
    {
        cout << GREEN << "||" << RESET;
    }
    else
        cout << "||";
    cout << "\n\n";
     cout << "\t\t";
    if(graph[6].head.rno == rno)
    {
        cout << GREEN << "||" << RESET;
    }
    else
        cout << "||";
         cout << "\t\t";
    if(graph[4].head.rno == rno)
    {
        cout << GREEN << "||" << RESET;
    }
    else
        cout << "||";
    cout << "\n\n";
    cout << "\t\t\t";
    if(graph[5].head.rno == rno)
    {
        cout << GREEN << "||" << RESET;
    }
    else
        cout << "||";
    cout << "\n\n";

    cout << "Room Details:\n";
    n->head.print_data();

    cout << endl;
    char some[100];
    strcpy(some,dirname);
    strcat(some,n->head.owner);
    strcat(some,".dat");
    ifstream f(some,ios::in);
    Person p;
    f.read((char*)&p,sizeof(p));
    p.display();


}
void roomgraph_func()
{
    RoomGraph g;
    int exit = 0,ch;
    do
    {
        system("cls");
        cout << "Room graph" << endl << endl;
        cout << "Menu" << endl;
        cout << "1.Insert room" << endl;
        cout << "2. Insert edge" << endl;
        cout << "3.Display" << endl;
        cout << "4.Exit" << endl;
        cout << "Enter your choice:";
        cin>> ch;
        switch(ch)
        {
        case 1:
            {
               Room r;
               r.get_data();
               g.insertRoom(r);
            }
        break;
        case 2:
            {
                cout << "Enter first room number:";
                int a;
                cin >> a;
                cout << "Enter second room number:";
                int b;
                cin >> b;
                g.add_edge(a,b);
            }
            break;
        case 3:
            {
                cout <<"\nBFS traversal\n";
                g.bfstraversal();
            }
        break;
        case 4: exit =1;
        break;
        }
        cout << endl;
        system("pause");
    }while(exit == 0);
}
