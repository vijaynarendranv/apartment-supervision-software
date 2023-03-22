#ifndef PERSON_H
#define PERSON_H

struct Person
{
    char name[60];
    int age;
    char aadhar_number[20];
    char ph_no[10];
    Person();
    void display();
};

class Person_class
{
    char dirname[60];
    Person heap[100];
public:
    Person_class(char* dirname);
    void sign_up();
    char* entryMenu();
};
#endif // PERSON_H
