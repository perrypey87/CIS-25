#include <iostream>
using namespace std;

struct Patient {
    int id;
    string name;
    int age;
};

int main() {
    // 1. Regular Patient variable
    Patient patient1;

    // 2. Assign values using the regular variable
    patient1.id = 101;
    patient1.name = "John";
    patient1.age = 40;

    // 3. Create a pointer that stores the address of the patient
    Patient* p = &patient1;

    // 4. Display data using the pointer
    cout << "ID: " << p->id << endl;
    cout << "Name: " << p->name << endl;
    cout << "Age: " << p->age << endl;

    return 0;
}
