#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// ── Inventory Item ─────────────────────────────────────────────────────────
struct Item {
    string name;
    int    quantity;
    double price;
};

// ── Base Class: User ───────────────────────────────────────────────────────
class User {
protected:
    string username;
    string role;
public:
    User(string name, string r);
    string getUsername();
    string getRole();
    virtual void accessLevel();
    virtual void showMenu(vector<Item>& inventory);
    virtual ~User() {}
};

// ── Employee ───────────────────────────────────────────────────────────────
class Employee : public User {
public:
    Employee(string name);
    void accessLevel() override;
    void showMenu(vector<Item>& inventory) override;
private:
    void viewInventory(vector<Item>& inventory);
    void searchInventory(vector<Item>& inventory);
};

// ── Manager ────────────────────────────────────────────────────────────────
class Manager : public User {
public:
    Manager(string name);
    void accessLevel() override;
    void showMenu(vector<Item>& inventory) override;
private:
    void viewInventory(vector<Item>& inventory);
    void searchInventory(vector<Item>& inventory);
    void updateItem(vector<Item>& inventory);
};

// ── Admin ──────────────────────────────────────────────────────────────────
class Admin : public User {
public:
    Admin(string name);
    void accessLevel() override;
    void showMenu(vector<Item>& inventory) override;
private:
    void viewInventory(vector<Item>& inventory);
    void searchInventory(vector<Item>& inventory);
    void addItem(vector<Item>& inventory);
    void updateItem(vector<Item>& inventory);
    void deleteItem(vector<Item>& inventory);
};

#endif
