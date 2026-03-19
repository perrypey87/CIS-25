#include "User.h"
#include <map>
#include <memory>

// ── Predefined Users (username -> role) ───────────────────────────────────
map<string, string> userDatabase = {
    {"david",   "Employee"},
    {"perry",   "Manager"},
    {"admin",   "Admin"}
};

static void flushCin() {
    cin.clear();
    cin.ignore(10000, '\n');
}

// ── Login ──────────────────────────────────────────────────────────────────
User* login() {
    string username;
    cout << "  Enter username: ";
    cin >> username; flushCin();

    auto it = userDatabase.find(username);
    if (it == userDatabase.end()) {
        cout << "  User not found." << endl;
        return nullptr;
    }

    string role = it->second;
    cout << "  Welcome, " << username << "! Role: " << role << endl;

    if (role == "Employee") return new Employee(username);
    if (role == "Manager")  return new Manager(username);
    if (role == "Admin")    return new Admin(username);
    return nullptr;
}

int main() {
    // ── Starting inventory ─────────────────────────────────────────────────
    vector<Item> inventory = {
        {"Laptop",     15, 999.99},
        {"Mouse",      50, 29.99},
        {"Keyboard",   30, 49.99},
        {"Monitor",    10, 299.99},
        {"USB Hub",    25, 19.99}
    };

    int choice = 0;
    do {
        cout << "\n===========================================" << endl;
        cout << "     Role-Based Inventory System" << endl;
        cout << "===========================================" << endl;
        cout << "  1. Login" << endl;
        cout << "  0. Exit" << endl;
        cout << "  Choice: ";
        cin >> choice; flushCin();
        cout << endl;

        if (choice == 1) {
            User* user = login();
            if (user != nullptr) {
                cout << "  Access Level: ";
                user->accessLevel();
                user->showMenu(inventory);
                cout << "  Logged out." << endl;
                delete user;
            }
        } else if (choice != 0) {
            cout << "  Invalid choice." << endl;
        }

    } while (choice != 0);

    cout << "\n  Goodbye!" << endl;
    return 0;
}
