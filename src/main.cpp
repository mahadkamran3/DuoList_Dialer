#include "../include/contactList.h"
using namespace std;

int main() {
    contactList cl;
    int choice;
    string name, phoneNumber, notes;

    while (true) {
        cout << "\n--- Phone Book Menu ---\n";
        cout << "1. Add New Contact\n2. Display All Contacts\n3. Display All Names\n4. Display All Phone Numbers\n";
        cout << "5. Delete All Contacts\n6. Delete Contact By Name\n7. Delete Contact By Phone Number\n";
        cout << "8. Search Contact By Name\n9. Search Contact By Phone Number\n";
        cout << "10. Edit Contact Name\n11. Edit Contact Phone Number\n12. Edit Contact Notes\n";
        cout << "13. Sort Contacts By Name\n14. Sort Contacts By Phone Number\n15. Make Calls\n16. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cin.ignore();
                cout << "Enter Name: "; getline(cin, name);
                cout << "Enter Phone Number: "; cin >> phoneNumber;
                cin.ignore();
                cout << "Enter Notes: "; getline(cin, notes);
                cl.insert(phoneNumber, name, notes);
                break;
            case 2: cl.display(); break;
            case 3: cl.displayName(); break;
            case 4: cl.displayPhoneNumbers(); break;
            case 5: cl.deleteAll(); break;
            case 6: cout << "Name to Delete: "; cin >> name; cl.deleteByName(name); break;
            case 7: cout << "Phone to Delete: "; cin >> phoneNumber; cl.deleteByPhoneNumber(phoneNumber); break;
            case 8: cout << "Name to Search: "; cin >> name; cl.searchByName(name); break;
            case 9: cout << "Phone to Search: "; cin >> phoneNumber; cl.searchByPhoneNumber(phoneNumber); break;
            case 10: cout << "Edit Name for (Enter existing name): "; cin >> name; cl.editName(name); break;
            case 11: cout << "Edit Phone for: "; cin >> phoneNumber; cl.editPhoneNumber(phoneNumber); break;
            case 12: cout << "Edit Notes for: "; cin >> phoneNumber; cl.editNotes(phoneNumber); break;
            case 13: cl.sortByName(); break;
            case 14: cl.sortByPhoneNumber(); break;
            case 15: cout << "Call Phone: "; cin >> phoneNumber; cl.makeCalls(phoneNumber); break;
            case 16: cout << "Goodbye!\n"; return 0;
            default: cout << "Invalid option!\n";
        }
    }
}