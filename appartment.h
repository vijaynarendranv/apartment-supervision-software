#ifndef APPARTMENT_H
#define APPARTMENT_H
#include <iostream>
#include <cstdio>
#include <cstring>
#include <sys/stat.h>
#include <sys/types.h>

class Appartment
{
    char filename[100];
public:
    Appartment();
    void createdirectory(char* filename);
    void addentry(char* filename);
    void removefile(char* filename);
    char* entryMenu();
    void use_appartment(char* apt);

};

#endif // APPARTMENT_H
