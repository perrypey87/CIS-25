#include <iostream>
#include <string>
using namespace std;

// Base class
class User {
protected:
    string username;

public:
    User(string name) : username(name) {}

    virtual void accessLevel() {
        cout << "User: " << username << " | Access: General Access" << endl;
    }

    virtual ~User() {}
};

// Derived class: Employee
class Employee : public User {
public:
    Employee(string name) : User(name) {}

    void accessLevel() override {
        cout << "User: " << username << " | Role: Employee | Permissions: View inventory" << endl;
    }
};

// Derived class: Manager
class Manager : public User {
public:
    Manager(string name) : User(name) {}

    void accessLevel() override {
        cout << "User: " << username << " | Role: Manager | Permissions: View and update inventory" << endl;
    }
};

// Derived class: Admin
class Admin : public User {
public:
    Admin(string name) : User(name) {}

    void accessLevel() override {
        cout << "User: " << username << " | Role: Admin | Permissions: Full access: add, update, delete inventory" << endl;
    }
}
