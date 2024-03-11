//Creator : Mohamed Ahmed Hamed
//ID : 20231131
//Version : 4.0
//Cipher type : Route Cipher



#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

void route_cipher_encryption();
void route_cipher_decryption();

int main()
{
    char choice;
    cout << "Welcome to Route Cipher encryption/decryption. Enter 'e' for encryption or 'd' for decryption: ";
    cin >> choice;
    cin.ignore();

    if (choice == 'e' || choice == 'E')
        route_cipher_encryption();
    else if (choice == 'd' || choice == 'D')
        route_cipher_decryption();
    else
        cout << "Invalid choice." << endl;

    return 0;
}

void route_cipher_encryption() {
    int Secret_key;
    string Message, Modif_Mess;

    // Taking inputs
    cout << "Enter your secret key: ";
    cin >> Secret_key;
    cin.ignore(); // to clear the input buffer
    cout << "Enter the message you want to encrypt: ";
    getline(cin, Message);

    Modif_Mess.resize(Message.length()); // Resize Modif_Mess to have the same length as Message

    // Copy only alphabetic characters from Message to Modif_Mess
    int j = 0;
    for (int i = 0; i < Message.length(); i++)
    {
        if (isalpha(Message[i]))
            Modif_Mess[j++] = toupper(Message[i]);
    }

    // Resize Modif_Mess to fit only alphabetic characters
    Modif_Mess.resize(j);

    // Create a 2D vector to store the message for encryption
    vector<vector<char>> matrix;

    // Fill the matrix with the message characters row by row
    int col = ceil((double)Modif_Mess.size() / Secret_key);
    matrix.resize(col, vector<char>(Secret_key, 'X'));

    // Fill the matrix with the message characters
    j = 0;
    for (int i = 0; i < col; ++i) {
        for (int k = 0; k < Secret_key && j < Modif_Mess.size(); ++k) {
            matrix[i][k] = Modif_Mess[j++];
        }
    }

    // Display the matrix before encryption
    cout << "Matrix before encryption:" << endl;
    for (const auto& row : matrix) {
        for (char c : row) {
            cout << c << " ";
        }
        cout << endl;
    }

    // Collect the encrypted message in a counterclockwise spiral path starting from the bottom left corner and going upwards
    cout << "Encrypted message: ";
    int i_encryption = col - 1, j_encryption = 0;
    while (i_encryption >= 0 && j_encryption < Secret_key) {
        if (matrix[i_encryption][j_encryption] != 'X') {
            cout << matrix[i_encryption][j_encryption];
        }
        if (i_encryption % 2 == 0) {
            // If on even row, move up
            --i_encryption;
        }
        else {
            // If on odd row, move down
            ++i_encryption;
        }
        if (i_encryption < 0 || i_encryption >= col) {
            // If reached the boundary, move to the next column
            ++j_encryption;
            if (j_encryption < Secret_key) {
                // Adjust row index based on column direction
                if (i_encryption % 2 == 0) {
                    i_encryption = col - 1;
                }
                else {
                    i_encryption = 0;
                }
            }
        }
    }
    cout << endl;
}

void route_cipher_decryption() {
    string Encrypted_Message;
    int Secret_key;

    cout << "Enter the encrypted message: ";
    getline(cin, Encrypted_Message);
    cout << "Enter your secret key: ";
    cin >> Secret_key;

    // Calculate number of rows needed
    int numRows = ceil((double)Encrypted_Message.size() / Secret_key);

    // Create a 2D vector to store the encrypted message
    vector<vector<char>> matrix(numRows, vector<char>(Secret_key, 'X'));

    // Fill the matrix with the encrypted message characters in a counterclockwise spiral path
    int index = 0;
    int i_decryption = 0, j_decryption = Secret_key - 1;
    while (i_decryption < numRows && j_decryption >= 0 && index < Encrypted_Message.size()) {
        if (Encrypted_Message[index] != ' ') {
            matrix[i_decryption][j_decryption] = Encrypted_Message[index++];
        }
        if (i_decryption % 2 == 0) {
            // If on even row, move down
            ++i_decryption;
        }
        else {
            // If on odd row, move up
            --i_decryption;
        }
        if (i_decryption < 0 || i_decryption >= numRows) {
            // If reached the boundary, move to the next column
            --j_decryption;
            if (j_decryption >= 0) {
                // Adjust row index based on column direction
                if (i_decryption % 2 == 0) {
                    i_decryption = 0;
                }
                else {
                    i_decryption = numRows - 1;
                }
            }
        }
    }

    // Display the matrix before decryption
    cout << "Matrix before decryption:" << endl;
    for (const auto& row : matrix) {
        for (char c : row) {
            cout << c << " ";
        }
        cout << endl;
    }

    // Print the decrypted message row by row
    cout << "Decrypted message: ";
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < Secret_key; ++j) {
            if (matrix[i][j] != 'X') {
                cout << matrix[i][j];
            }
        }
    }
    cout << endl;
}



