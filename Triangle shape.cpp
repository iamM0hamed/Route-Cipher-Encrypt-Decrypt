#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int lines = (n + 1) / 2;
    int spaces = lines - 1;

    for (int i = 0; i < lines; i++) {
        // Print leading spaces
        for (int j = 0; j < spaces; j++) {
            cout << " ";
        }

        // Print '*' characters
        if (i == 0 || i == lines - 1) {
            // For first and last line, print all '*'
            for (int k = 0; k < n - 2 * spaces; k++) {
                cout << "*";
            }
        }
        else {
            // For other lines, print '*' at edges and spaces in between
            cout << "*";
            for (int k = 0; k < n - 2 * (spaces + 1); k++) {
                cout << " ";
            }
            cout << "*";
        }

        // Move to next line
        cout << endl;

        // Decrease spaces for the next line
        spaces--;
    }

    return 0;
}