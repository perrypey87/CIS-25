#include <iostream>
using namespace std;

int main() {
    int choice;
    
    cout << "===== SIMPLE MENU =====" << endl;
    cout << "1. Option A" << endl;
    cout << "2. Option B" << endl;
    cout << "3. Option C" << endl;
    cout << "======================" << endl;
    cout << "Enter your choice (1-3): ";
    cin >> choice;
    
    if (choice == 1) {
        cout << "You selected Option A" << endl;
    } else if (choice == 2) {
        cout << "You selected Option B" << endl;
    } else if (choice == 3) {
        cout << "You selected Option C" << endl;
    } else {
        cout << "Invalid choice! Please select 1, 2, or 3." << endl;
    }
    
    return 0;
}
