#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Patient {
    int id;
    string name;
    int age;
    string gender;
    string diagnosis;
};

int binarySearch(Patient* patients, int size, int searchID) {
    int left = 0;
    int right = size - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (patients[mid].id == searchID) return mid;
        else if (patients[mid].id < searchID) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

void sortByID(Patient* patients, int count) {
    for (int i = 1; i < count; i++) {
        Patient key = patients[i];
        int j = i - 1;
        while (j >= 0 && patients[j].id > key.id) {
            patients[j + 1] = patients[j];
            j--;
        }
        patients[j + 1] = key;
    }
}

// Clear bad cin state
void clearInput() {
    cin.clear();
    cin.ignore(1000, '\n');
}

int loadPatients(Patient* patients, int maxSize) {
    ifstream inFile("patients.txt");
    if (!inFile) return 0;
    int count = 0;
    while (count < maxSize &&
           inFile >> patients[count].id
                  >> patients[count].name
                  >> patients[count].age
                  >> patients[count].gender
                  >> patients[count].diagnosis) {
        count++;
    }
    inFile.close();
    return count;
}

void savePatients(Patient* patients, int count) {
    ofstream outFile("patients.txt");
    if (!outFile) {
        cout << "Error: Could not open patients.txt for writing.\n";
        return;
    }
    for (int i = 0; i < count; i++) {
        outFile << patients[i].id       << " "
                << patients[i].name     << " "
                << patients[i].age      << " "
                << patients[i].gender   << " "
                << patients[i].diagnosis << "\n";
    }
    outFile.close();
    cout << "Patients saved to patients.txt.\n";
}

void addPatient(Patient* patients, int& count, int maxSize) {
    if (count >= maxSize) {
        cout << "Patient list is full.\n";
        return;
    }
    Patient p;
    cout << "Enter Patient ID: ";
    while (!(cin >> p.id)) { cout << "Enter a numeric ID: "; clearInput(); }
    cout << "Enter Name: ";
    cin >> p.name;
    cout << "Enter Age: ";
    while (!(cin >> p.age)) { cout << "Enter a numeric age: "; clearInput(); }
    cout << "Enter Gender: ";
    cin >> p.gender;
    cout << "Enter Diagnosis: ";
    cin >> p.diagnosis;
    patients[count++] = p;
    sortByID(patients, count);
    cout << "Patient added successfully.\n";
}

void displayPatients(Patient* patients, int count) {
    if (count == 0) { cout << "No patient records found.\n"; return; }
    cout << "\nPatient Records\n---------------\n";
    for (int i = 0; i < count; i++) {
        cout << "ID: "        << patients[i].id        << "\n"
             << "Name: "      << patients[i].name      << "\n"
             << "Age: "       << patients[i].age       << "\n"
             << "Gender: "    << patients[i].gender    << "\n"
             << "Diagnosis: " << patients[i].diagnosis << "\n"
             << "---------------\n";
    }
}

void searchPatient(Patient* patients, int count) {
    int searchID;
    cout << "Enter patient ID to search: ";
    while (!(cin >> searchID)) { cout << "Enter a numeric ID: "; clearInput(); }
    int index = binarySearch(patients, count, searchID);
    if (index != -1) {
        cout << "Patient Found\n"
             << "Name: "      << patients[index].name      << "\n"
             << "Age: "       << patients[index].age       << "\n"
             << "Diagnosis: " << patients[index].diagnosis << "\n";
    } else {
        cout << "Patient not found.\n";
    }
}

void updatePatient(Patient* patients, int count) {
    int updateID;
    cout << "Enter patient ID to update: ";
    while (!(cin >> updateID)) { cout << "Enter a numeric ID: "; clearInput(); }
    int index = binarySearch(patients, count, updateID);
    if (index != -1) {
        cout << "Enter new diagnosis: ";
        cin >> patients[index].diagnosis;
        cout << "Patient record updated successfully.\n";
    } else {
        cout << "Patient not found.\n";
    }
}

int main() {
    const int MAX_SIZE = 100;
    Patient* patients = new Patient[MAX_SIZE];
    int count = 0;

    count = loadPatients(patients, MAX_SIZE);
    if (count > 0) {
        cout << "Loaded " << count << " patient(s) from patients.txt.\n";
        sortByID(patients, count);
    }

    int choice = 0;
    do {
        cout << "\nHospital Patient System\n\n"
             << "1. Add Patient\n"
             << "2. Display Patients\n"
             << "3. Search Patient\n"
             << "4. Update Patient\n"
             << "5. Save Patients\n"
             << "6. Exit\n\n"
             << "Enter choice: ";

        if (!(cin >> choice)) {
            clearInput();
            cout << "Invalid choice. Please enter 1-6.\n";
            continue;
        }

        switch (choice) {
            case 1: addPatient(patients, count, MAX_SIZE); break;
            case 2: displayPatients(patients, count);      break;
            case 3: searchPatient(patients, count);        break;
            case 4: updatePatient(patients, count);        break;
            case 5: savePatients(patients, count);         break;
            case 6:
                savePatients(patients, count);
                cout << "Good Bye!\n";
                break;
            default:
                cout << "Invalid choice. Please enter 1-6.\n";
        }
    } while (choice != 6);

    delete[] patients;
    patients = nullptr;
    return 0;
}
