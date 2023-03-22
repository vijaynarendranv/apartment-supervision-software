#ifndef BLOCK_H
#define BLOCK_H
#include "RoomGraph.h"
class Block
{
    char dirname[20];
    char currentname[60];

public:
    /*Block(char* dirname);
    void insertfloors(int a);
    void print_to_file();
    void load_from_file();
    void displayblock();
    int hashcode(int rno);
    void createblock();
    void deleteblock();
    void useblock();*/
    Block(char* dirname);
    void addentry(char* filename);
    void createdirectory(char* filename);
    char* entryMenu();
    void use_block(char* blk);
    void removefile(char* filename);
};

class Hashmap
{
    RoomGraph rg[10];
public:
    Hashmap();
    void display();
    int hashcode(int rno);
    void writetofile(char* blk);
    void modify(char* dirname);
    void reset();
    void loadfromfile(char*blk);
    void searchanddisplay(int rno,char* dirname);
};
#endif // BLOCK_H
