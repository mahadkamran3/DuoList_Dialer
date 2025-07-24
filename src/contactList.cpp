#include "../include/contactList.h"
using namespace std;

contactList::contactList() { p = NULL; }

void contactList::insert(string num, string name, string notes) {
    contact *t = new contact();
    t->contactName = name;
    t->phoneNum = num;
    t->notes = notes.empty() ? "No notes available!" : notes;

    if (p == NULL) {
        t->nextContact = t->prevContact = NULL;
        p = t;
    } else {
        t->nextContact = p;
        t->prevContact = NULL;
        p->prevContact = t;
        p = t;
    }

    contact *q = t->nextContact;
    while (q != NULL) {
        if (t->phoneNum == q->phoneNum || t->contactName == q->contactName) {
            cout << "Contact already exists!" << endl;
            delete t;
            return;
        }
        q = q->nextContact;
    }

    cout << "Contact added successfully!" << endl;
    sortByName();
}

void contactList::display() {
    contact *q = p;
    if (!q) { cout << "No contacts available.\n"; return; }
    while (q != NULL) {
        cout << "Name: " << q->contactName << "\nPhone: " << q->phoneNum << "\nNotes: " << q->notes << "\n\n";
        q = q->nextContact;
    }
}

void contactList::displayName() {
    contact *q = p;
    if (!q) { cout << "No contacts found!\n"; return; }
    while (q != NULL) {
        cout << "Name: " << q->contactName << endl;
        q = q->nextContact;
    }
}

void contactList::displayPhoneNumbers() {
    contact *q = p;
    if (!q) { cout << "No contacts found!\n"; return; }
    while (q != NULL) {
        cout << "Phone: " << q->phoneNum << endl;
        q = q->nextContact;
    }
}

void contactList::deleteAll() {
    while (p != NULL) {
        contact *q = p;
        p = p->nextContact;
        delete q;
    }
    cout << "All contacts deleted.\n";
}

void contactList::deleteByName(string name) {
    vector<contact*> matches;
    contact *q = p;
    while (q) {
        if (q->contactName == name)
            matches.push_back(q);
        q = q->nextContact;
    }

    if (matches.empty()) {
        cout << "No contact found with name: " << name << endl;
        return;
    }

    cout << "Enter phone number to delete: ";
    string phone;
    cin >> phone;

    for (contact* c : matches) {
        if (c->phoneNum == phone) {
            if (c->prevContact) c->prevContact->nextContact = c->nextContact;
            if (c->nextContact) c->nextContact->prevContact = c->prevContact;
            if (c == p) p = c->nextContact;
            delete c;
            cout << "Contact deleted.\n";
            return;
        }
    }

    cout << "Phone number not found under this name.\n";
}

void contactList::deleteByPhoneNumber(string num) {
    contact *q = p;
    while (q) {
        if (q->phoneNum == num) {
            if (q->prevContact) q->prevContact->nextContact = q->nextContact;
            if (q->nextContact) q->nextContact->prevContact = q->prevContact;
            if (q == p) p = q->nextContact;
            delete q;
            cout << "Contact deleted.\n";
            return;
        }
        q = q->nextContact;
    }
    cout << "Contact not found.\n";
}

void contactList::searchByName(string name) {
    contact *q = p;
    bool found = false;
    while (q) {
        if (q->contactName == name) {
            cout << "Name: " << q->contactName << "\nPhone: " << q->phoneNum << "\nNotes: " << q->notes << "\n";
            found = true;
        }
        q = q->nextContact;
    }
    if (!found) cout << "No contact found with name: " << name << endl;
}

void contactList::searchByPhoneNumber(string num) {
    contact *q = p;
    while (q) {
        if (q->phoneNum == num) {
            cout << "Name: " << q->contactName << "\nPhone: " << q->phoneNum << "\nNotes: " << q->notes << "\n";
            return;
        }
        q = q->nextContact;
    }
    cout << "No contact found with phone number: " << num << endl;
}

void contactList::editName(string name) {
    string phone;
    cout << "Enter phone number of the contact to update name: ";
    cin >> phone;

    contact *q = p;
    while (q) {
        if (q->phoneNum == phone) {
            cout << "Enter new name: ";
            cin.ignore(); getline(cin, q->contactName);
            cout << "Updated successfully.\n";
            return;
        }
        q = q->nextContact;
    }
    cout << "Contact not found.\n";
}

void contactList::editPhoneNumber(string oldNum) {
    contact *q = p;
    while (q) {
        if (q->phoneNum == oldNum) {
            cout << "Enter new number: ";
            cin >> q->phoneNum;
            cout << "Updated successfully.\n";
            return;
        }
        q = q->nextContact;
    }
    cout << "Contact not found.\n";
}

void contactList::editNotes(string num) {
    contact *q = p;
    while (q) {
        if (q->phoneNum == num) {
            cout << "Enter new notes: ";
            cin.ignore(); getline(cin, q->notes);
            cout << "Updated successfully.\n";
            return;
        }
        q = q->nextContact;
    }
    cout << "Contact not found.\n";
}

void contactList::sortByName() {
    for (contact *i = p; i != NULL; i = i->nextContact) {
        for (contact *j = i->nextContact; j != NULL; j = j->nextContact) {
            if (i->contactName > j->contactName) {
                swap(i->contactName, j->contactName);
                swap(i->phoneNum, j->phoneNum);
                swap(i->notes, j->notes);
            }
        }
    }
}

void contactList::sortByPhoneNumber() {
    for (contact *i = p; i != NULL; i = i->nextContact) {
        for (contact *j = i->nextContact; j != NULL; j = j->nextContact) {
            if (i->phoneNum > j->phoneNum) {
                swap(i->contactName, j->contactName);
                swap(i->phoneNum, j->phoneNum);
                swap(i->notes, j->notes);
            }
        }
    }
}

void contactList::makeCalls(string num) {
    contact *q = p;
    while (q) {
        if (q->phoneNum == num) {
            cout << "📞 Calling " << q->contactName << " at " << q->phoneNum << "...\n";
            cout << "🔕 Line busy. Try again later.\n";
            return;
        }
        q = q->nextContact;
    }
    cout << "Contact not found.\n";
}
