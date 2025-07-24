#ifndef CONTACTLIST_H
#define CONTACTLIST_H

#include <iostream>
#include <string>
#include <vector>

class contactList {
    struct contact {
        std::string phoneNum;
        std::string contactName;
        std::string notes;
        contact* nextContact;
        contact* prevContact;
    } *p;

public:
    contactList();
    void insert(std::string, std::string, std::string);
    void display();
    void displayName();
    void displayPhoneNumbers();
    void deleteAll();
    void deleteByName(std::string);
    void deleteByPhoneNumber(std::string);
    void searchByName(std::string);
    void searchByPhoneNumber(std::string);
    void editName(std::string);
    void editPhoneNumber(std::string);
    void editNotes(std::string);
    void sortByName();
    void sortByPhoneNumber();
    void makeCalls(std::string);
};

#endif
