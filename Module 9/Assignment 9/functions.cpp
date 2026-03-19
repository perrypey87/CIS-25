#include "User.h"
#include <iomanip>
#include <algorithm>
#include <cctype>

// ── Helpers ────────────────────────────────────────────────────────────────
static void printLine() {
    cout << "-------------------------------------------" << endl;
}

static void printInventoryTable(vector<Item>& inventory) {
    if (inventory.empty()) {
        cout << "  (No items in inventory)" << endl;
        return;
    }
    cout << left << setw(20) << "Item"
         << setw(12) << "Quantity"
         << setw(10) << "Price" << endl;
    printLine();
    for (auto& item : inventory) {
        cout << left << setw(20) << item.name
             << setw(12) << item.quantity
             << "$" << fixed << setprecision(2) << item.price << endl;
    }
}

static string toLower(string s) {
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    return s;
}

// Flush leftover newline/garbage from cin after every numeric read
static void flushCin() {
    cin.clear();
    cin.ignore(10000, '\n');
}

// ── User (Base) ────────────────────────────────────────────────────────────
User::User(string name, string r) : username(name), role(r) {}

string User::getUsername() { return username; }
string User::getRole()     { return role; }

void User::accessLevel() {
    cout << "General Access" << endl;
}

void User::showMenu(vector<Item>& inventory) {
    cout << "No menu available." << endl;
}

// ── Employee ───────────────────────────────────────────────────────────────
Employee::Employee(string name) : User(name, "Employee") {}

void Employee::accessLevel() {
    cout << "Employee Access: View inventory, Search inventory" << endl;
}

void Employee::viewInventory(vector<Item>& inventory) {
    cout << "\n  === Inventory ===" << endl;
    printInventoryTable(inventory);
}

void Employee::searchInventory(vector<Item>& inventory) {
    cout << "  Enter item name to search: ";
    string query; cin >> query;
    bool found = false;
    cout << endl;
    for (auto& item : inventory) {
        if (toLower(item.name).find(toLower(query)) != string::npos) {
            cout << "  Found: " << item.name
                 << " | Qty: " << item.quantity
                 << " | Price: $" << fixed << setprecision(2) << item.price << endl;
            found = true;
        }
    }
    if (!found) cout << "  No items found matching \"" << query << "\"." << endl;
}

void Employee::showMenu(vector<Item>& inventory) {
    int choice = 0;
    do {
        cout << "\n  === Employee Menu ===" << endl;
        cout << "  1. View Inventory" << endl;
        cout << "  2. Search Inventory" << endl;
        cout << "  0. Logout" << endl;
        cout << "  Choice: ";
        cin >> choice; flushCin();
        cout << endl;
        if      (choice == 1) viewInventory(inventory);
        else if (choice == 2) searchInventory(inventory);
        else if (choice != 0) cout << "  Invalid choice." << endl;
    } while (choice != 0);
}

// ── Manager ────────────────────────────────────────────────────────────────
Manager::Manager(string name) : User(name, "Manager") {}

void Manager::accessLevel() {
    cout << "Manager Access: View inventory, Search inventory, Update items" << endl;
}

void Manager::viewInventory(vector<Item>& inventory) {
    cout << "\n  === Inventory ===" << endl;
    printInventoryTable(inventory);
}

void Manager::searchInventory(vector<Item>& inventory) {
    cout << "  Enter item name to search: ";
    string query; cin >> query;
    bool found = false;
    cout << endl;
    for (auto& item : inventory) {
        if (toLower(item.name).find(toLower(query)) != string::npos) {
            cout << "  Found: " << item.name
                 << " | Qty: " << item.quantity
                 << " | Price: $" << fixed << setprecision(2) << item.price << endl;
            found = true;
        }
    }
    if (!found) cout << "  No items found matching \"" << query << "\"." << endl;
}

void Manager::updateItem(vector<Item>& inventory) {
    if (inventory.empty()) { cout << "  Inventory is empty." << endl; return; }
    viewInventory(inventory);
    cout << "\n  Enter item name to update: ";
    string name; cin >> name;
    for (auto& item : inventory) {
        if (toLower(item.name) == toLower(name)) {
            cout << "  New quantity (" << item.quantity << "): ";
            cin >> item.quantity; flushCin();
            cout << "  New price ($" << item.price << "): ";
            cin >> item.price; flushCin();
            cout << "  Item updated successfully." << endl;
            return;
        }
    }
    cout << "  Item \"" << name << "\" not found." << endl;
}

void Manager::showMenu(vector<Item>& inventory) {
    int choice = 0;
    do {
        cout << "\n  === Manager Menu ===" << endl;
        cout << "  1. View Inventory" << endl;
        cout << "  2. Search Inventory" << endl;
        cout << "  3. Update Item" << endl;
        cout << "  0. Logout" << endl;
        cout << "  Choice: ";
        cin >> choice; flushCin();
        cout << endl;
        if      (choice == 1) viewInventory(inventory);
        else if (choice == 2) searchInventory(inventory);
        else if (choice == 3) updateItem(inventory);
        else if (choice != 0) cout << "  Invalid choice." << endl;
    } while (choice != 0);
}

// ── Admin ──────────────────────────────────────────────────────────────────
Admin::Admin(string name) : User(name, "Admin") {}

void Admin::accessLevel() {
    cout << "Admin Access: Full access — add, update, delete inventory" << endl;
}

void Admin::viewInventory(vector<Item>& inventory) {
    cout << "\n  === Inventory ===" << endl;
    printInventoryTable(inventory);
}

void Admin::searchInventory(vector<Item>& inventory) {
    cout << "  Enter item name to search: ";
    string query; cin >> query;
    bool found = false;
    cout << endl;
    for (auto& item : inventory) {
        if (toLower(item.name).find(toLower(query)) != string::npos) {
            cout << "  Found: " << item.name
                 << " | Qty: " << item.quantity
                 << " | Price: $" << fixed << setprecision(2) << item.price << endl;
            found = true;
        }
    }
    if (!found) cout << "  No items found matching \"" << query << "\"." << endl;
}

void Admin::addItem(vector<Item>& inventory) {
    Item newItem;
    cout << "  Item name: ";    cin >> newItem.name;  flushCin();
    cout << "  Quantity: ";     cin >> newItem.quantity; flushCin();
    cout << "  Price: $";       cin >> newItem.price; flushCin();
    inventory.push_back(newItem);
    cout << "  \"" << newItem.name << "\" added to inventory." << endl;
}

void Admin::updateItem(vector<Item>& inventory) {
    if (inventory.empty()) { cout << "  Inventory is empty." << endl; return; }
    viewInventory(inventory);
    cout << "\n  Enter item name to update: ";
    string name; cin >> name;
    for (auto& item : inventory) {
        if (toLower(item.name) == toLower(name)) {
            cout << "  New quantity (" << item.quantity << "): ";
            cin >> item.quantity; flushCin();
            cout << "  New price ($" << item.price << "): ";
            cin >> item.price; flushCin();
            cout << "  Item updated successfully." << endl;
            return;
        }
    }
    cout << "  Item \"" << name << "\" not found." << endl;
}

void Admin::deleteItem(vector<Item>& inventory) {
    if (inventory.empty()) { cout << "  Inventory is empty." << endl; return; }
    viewInventory(inventory);
    cout << "\n  Enter item name to delete: ";
    string name; cin >> name;
    for (auto it = inventory.begin(); it != inventory.end(); ++it) {
        if (toLower(it->name) == toLower(name)) {
            cout << "  \"" << it->name << "\" removed from inventory." << endl;
            inventory.erase(it);
            return;
        }
    }
    cout << "  Item \"" << name << "\" not found." << endl;
}

void Admin::showMenu(vector<Item>& inventory) {
    int choice = 0;
    do {
        cout << "\n  === Admin Menu ===" << endl;
        cout << "  1. View Inventory" << endl;
        cout << "  2. Search Inventory" << endl;
        cout << "  3. Add Item" << endl;
        cout << "  4. Update Item" << endl;
        cout << "  5. Delete Item" << endl;
        cout << "  0. Logout" << endl;
        cout << "  Choice: ";
        cin >> choice; flushCin();
        cout << endl;
        if      (choice == 1) viewInventory(inventory);
        else if (choice == 2) searchInventory(inventory);
        else if (choice == 3) addItem(inventory);
        else if (choice == 4) updateItem(inventory);
        else if (choice == 5) deleteItem(inventory);
        else if (choice != 0) cout << "  Invalid choice." << endl;
    } while (choice != 0);
}
