#include <iostream>
#include "menu_functions.h"

using namespace std;

// Display the menu
void showMenu() {
    cout << "\n========== MENU ==========\n";
    cout << "1. Add Two Numbers\n";
    cout << "2. Display Message\n";
    cout << "3. Calculate Square\n";
    cout << "4. Exit\n";
    cout << "==========================\n";
    cout << "Enter your choice: ";
}

// Function to add two numbers
void addNumbers() {
    int num1, num2;
    cout << "\nEnter first number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;
    cout << "Sum: " << (num1 + num2) << endl;
}

// Function to display a message
void displayMessage() {
    cout << "\nWelcome to C++ Programming!" << endl;
    cout << "Functions make code reusable and organized." << endl;
}

// Function to calculate square of a number
void calculateSquare() {
    int number;
    cout << "\nEnter a number: ";
    cin >> number;
    cout << "Square of " << number << " is: " << (number * number) << endl;
}
