#include <iostream>
#include "menu_functions.h"

using namespace std;

int main() {
    int option;
    
    cout << "========================================\n";
    cout << "  C++ Menu Program with Functions\n";
    cout << "========================================\n";
    
    do {
        showMenu();
        cin >> option;
        
        switch(option) {
            case 1:
                addNumbers();
                break;
            case 2:
                displayMessage();
                break;
            case 3:
                calculateSquare();
                break;
            case 4:
                cout << "\nThank you for using the program!\n";
                cout << "Goodbye!\n";
                break;
            default:
                cout << "\nInvalid option! Please choose 1-4.\n";
        }
        
    } while (option != 4);
    
    return 0;
}
