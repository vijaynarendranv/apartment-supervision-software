#ifndef ROOMGRAPH_H
#define ROOMGRAPH_H

#include <unordered_map>
#include <vector>

void roomgraph_func();

struct Room
{
    int rno;
    int bedrooms;
    int halls;
    int kitchens;
    char owner[60];
    Room();
    void get_data();
    void print_data();

};
struct adj_list_node
{
    Room head;
    std::vector<adj_list_node*> adj_list;
};
class RoomGraph
{
    adj_list_node graph[30];
    int size;
public:
    RoomGraph()
    {
        size = 0;
    }
    void insertRoom(Room a);
    void add_edge(int rno1, int rno2);
    void bfstraversal();
    void bfstraversal2();
    adj_list_node* bfssearch(int rno);
    void modify(int,char*);
    void displayfloor(int,char* dirname);
    void reset()
    {
        size = 0;
    }
    void print_to_file(char* filename);

};
#endif // ROOMGRAPH_H
