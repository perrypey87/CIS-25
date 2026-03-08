#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

// Class representing a Netflix show
// Each object stores a single row from the CSV file
class NetflixShow {
public:
    string type;         // "Movie" or "TV Show"
    string title;        // Name of the show
    string director;     // Director(s), may be empty
    string country;      // Country of production, may be empty
    string date_added;   // Date added to Netflix, may be empty
    string release_year; // Year of release
};

// Function to parse a CSV line correctly handling quoted fields and commas
vector<string> parseCSVLine(const string& line) {
    vector<string> fields; // Stores all extracted fields
    string field;          // Temporary variable for current field
    bool inQuotes = false; // True if inside quotes

    for (size_t i = 0; i < line.size(); i++) {
        char c = line[i];

        if (c == '"') {
            // Toggle inQuotes flag when encountering a quote
            inQuotes = !inQuotes;
        }
        else if (c == ',' && !inQuotes) {
            // Comma outside quotes marks end of field
            fields.push_back(field);
            field.clear();
        }
        else {
            // Regular character, append to current field
            field += c;
        }
    }

    // Add the last field after the last comma
    fields.push_back(field);

    return fields;
}

int main() {
    ifstream file("netflix_titles.csv"); // CSV file must be in the same folder
    if (!file) {
        cout << "Error opening file." << endl;
        return 1; // Exit if file cannot be opened
    }

    vector<NetflixShow> shows; // Vector to store NetflixShow objects
    string line;

    // Skip the header row (first line)
    getline(file, line);

    while (getline(file, line)) {
        // Parse the line into fields
        vector<string> fields = parseCSVLine(line);

        // Check if we have enough columns; fill missing fields with empty strings
        while (fields.size() < 7) fields.push_back("");

        // Map CSV columns to our class fields
        // CSV column order: show_id, type, title, director, cast, country, date_added, release_year, ...
        NetflixShow show;
        show.type = fields[1];
        show.title = fields[2];
        show.director = fields[3];
        show.country = fields[5];      // Skip cast column
        show.date_added = fields[6];
        show.release_year = fields[7];

        shows.push_back(show);

        // Stop after reading first 10 rows
        if (shows.size() >= 10)
            break;
    }

    // Display the first 10 shows
    cout << "Netflix Dataset\n----------------------\n";
    for (NetflixShow s : shows) {
        cout << "Type: " << (s.type.empty() ? "N/A" : s.type) << endl;
        cout << "Title: " << (s.title.empty() ? "N/A" : s.title) << endl;
        cout << "Director: " << (s.director.empty() ? "N/A" : s.director) << endl;
        cout << "Country: " << (s.country.empty() ? "N/A" : s.country) << endl;
        cout << "Date Added: " << (s.date_added.empty() ? "N/A" : s.date_added) << endl;
        cout << "Release Year: " << (s.release_year.empty() ? "N/A" : s.release_year) << endl;
        cout << "----------------------\n";
    }

    file.close();
    return 0;
}
