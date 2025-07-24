# 📞 LinkBook – A C++ Phone Book Manager with Doubly Linked List

> A modular, interactive command-line phone book manager built in **C++**, using a **doubly linked list** and **vector** to manage contact records efficiently.  
> Developed as part of a Data Structures and Algorithms course project.

---

## 📁 Project Structure

phone-book/
├── include/
│ └── contactList.h # Header file containing class and method declarations
├── src/
│ ├── contactList.cpp # Implementation of contactList methods
│ └── main.cpp # Main menu and program logic
├── README.md # Documentation


---

## ✨ Features

- ➕ **Add Contact** – Create a new contact with name, phone number, and notes
- 📋 **Display All Contacts** – View full contact list
- 🧾 **Display Names or Numbers Only** – Focused view by field
- 🔍 **Search Contact** – Find by name or phone number
- 📝 **Edit Contact** – Update name, number, or notes
- ❌ **Delete Contact(s)** – Delete by name, number, or clear all
- 📊 **Sort Contacts** – By name or by number using selection sort
- 📱 **Simulate Calls** – Output a mock call to selected contact
- 🧠 **Doubly Linked List** – Efficient traversal and operations
- 📦 **Vector** – Helps resolve duplicates during search/edit

---

## 💻 Technologies Used

| Component           | Description                                      |
|--------------------|--------------------------------------------------|
| **Language**        | C++                                              |
| **Data Structures** | Doubly Linked List, Vector                       |
| **Libraries**       | `<iostream>`, `<vector>`, `<string>`             |
| **Build Tool**      | `g++` or any standard C++ compiler               |
| **Environment**     | Linux, Windows, macOS (with a C++ compiler)      |

---

## ⚙️ Installation & Build

### 🔁 Step 1: Clone the repository

git clone https://github.com/your-username/phone-book.git
cd phone-book

### 🧱 Step 2: Compile the code
    g++ src/*.cpp -Iinclude -o phone_book

### ▶️ Step 3: Run the application
    ./phone_book

🧪 Sample Menu
    --- Phone Book Menu ---
    1. Add New Contact
    2. Display All Contacts
    3. Display All Names
    4. Display All Phone Numbers
    5. Delete All Contacts
    6. Delete Contact By Name
    7. Delete Contact By Phone Number
    8. Search Contact By Name
    9. Search Contact By Phone Number
    10. Edit Contact Name
    11. Edit Contact Phone Number
    12. Edit Contact Notes
    13. Sort Contacts By Name
    14. Sort Contacts By Phone Number
    15. Make Calls
    16. Exit

🚀 Future Enhancements
    💾 File I/O support to save and load contacts

    🖥️ GUI version using Qt or SFML

    🔐 Input validation for phone number format

    ⚡ Switch from Selection Sort to Merge Sort for efficiency

🤝 Contributing
Pull requests are welcome!

# Fork this repo
# Create your feature branch
git checkout -b feature/your-feature

# Commit your changes
git commit -m "Add new feature"

# Push to your fork
git push origin feature/your-feature

# Open a pull request 🎉
📄 License
This project is licensed under the MIT License.

👨‍💻 Author
Mahad Kamran
📧 Email: mahadkamran003@gmail.com