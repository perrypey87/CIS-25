#include <iostream>
using namespace std;

int main() {
    // Fixed: Changed to proper variable declaration syntax with commas
    float n1, n2, n3;
    
    cout << "Enter three numbers: ";
    // Fixed: Changed input operator from '>' to '>>'
    cin >> n1 >> n2 >> n3;
    
    // Fixed: Changed '=' to '==' for comparison (not assignment)
    // This checks if n1 equals n2 AND n1 is greater than or equal to n3
    if (n1 == n2 && n1 >= n3) {
        cout << "Largest number: " << n1;
    }
    
    // Fixed: Changed '=' to '==' for comparison
    // Properly nested: This else if checks if n2 equals n1 AND n2 is >= n3
    else if (n2 == n1 && n2 >= n3) {
        // Fixed: Output should be n1, not n2, since n1 == n2
        cout << "Largest number: " << n1;
    }
    
    // Fixed: Properly nested else if statement
    // This checks if n3 is greater than or equal to both n1 and n2
    else if (n3 >= n1 && n3 >= n2) {
        // Fixed: Changed output from n2 to n3
        cout << "Largest number: " << n3;
    }
    
    // Added: Missing closing brace for else block
    
    return 0;
}
