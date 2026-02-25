#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

class Item {
public:
    string name;
    double price;
    int quantity;

    double getTotalPrice() {
        return price * quantity;
    }
};

void addItem() {
    Item item;

    cout << "Enter item name: ";
    cin >> item.name;
    cout << "Enter item price: ";
    cin >> item.price;
    cout << "Enter item quantity: ";
    cin >> item.quantity;

    ofstream out("cart.txt", ios::app);
    if (out.is_open()) {
        out << item.name << " " << item.price << " " << item.quantity << endl;
        out.close();
        cout << "Item added to cart." << endl;
    } else {
        cout << "Unable to open file for writing." << endl;
    }
}

void viewCheckout() {
    ifstream in("cart.txt");
    if (!in.is_open()) {
        cout << "No items in cart." << endl;
        return;
    }

    cout << "\n===== CHECKOUT =====" << endl;
    cout << fixed << setprecision(2);

    double grandTotal = 0.0;
    string name;
    double price;
    int quantity;

    while (in >> name >> price >> quantity) {
        Item item;
        item.name = name;
        item.price = price;
        item.quantity = quantity;
        double total = item.getTotalPrice();
        grandTotal += total;
        cout << name << " - $" << price << " x " << quantity << " = $" << total << endl;
    }
    in.close();

    cout << "--------------------" << endl;
    cout << "Total: $" << grandTotal << endl;
}

int main() {
    int choice;

    do {
        cout << "\n====== SHOPPING CART MENU ======" << endl;
        cout << "1. Add item to cart" << endl;
        cout << "2. View checkout" << endl;
        cout << "3. Exit" << endl;
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addItem();
                break;
            case 2:
                viewCheckout();
                break;
            case 3:
                cout << "Thank you for shopping!" << endl;
                break;
            default:
                cout << "Invalid option. Please try again." << endl;
        }
    } while (choice != 3);

    return 0;
}

