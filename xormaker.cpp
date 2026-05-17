#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;


string xorProcess(string data, char key) {
    for (int i = 0; i < data.size(); i++) {
        data[i] ^= key;
    }
    return data;
}

int main() {
    int choice;
    cout << "--- XOR TOOL BY HACKER ---" << endl;
    cout << "1. Encrypt (IP/String to Hex)" << endl;
    cout << "2. Decrypt (Hex + Key to Original)" << endl;
    cout << "Select Option: ";
    cin >> choice;
    cin.ignore();  // for cleaning buffer 

    if (choice == 1) {
        // --- ENCRYPTION LOGIC ---
        string data;
        char key;
        cout << "\nEnter String (e.g. Any script ): ";
        getline(cin, data);
        cout << "Enter Secret Key (Symbol): ";
        cin >> key;

        cout << "\n[+] Encrypted Hex Code (Copy this into your Malware):" << endl;
        for (unsigned char c : data) {
            printf("\\x%02x", c ^ key);
        }
        cout << endl;

    } else if (choice == 2) {
        // --- DECRYPTION LOGIC ---
        string hexInput;
        char key;
        cout << "\nEnter Hex Code (Format: \\x7a\\x63...): ";
        getline(cin, hexInput);
        cout << "Enter Secret Key: ";
        cin >> key;

       
        string original = "";
        for (int i = 0; i < hexInput.length(); i++) {
            if (hexInput[i] == '\\' && hexInput[i+1] == 'x') {
                string part = hexInput.substr(i + 2, 2);
                char ch = (char)stoul(part, nullptr, 16);
                original += (ch ^ key); 
                i += 3;
            }
        }
        cout << "\n[!] Decrypted Original Data: " << original << endl;

    } else {
        cout << "Error: try again properly" << endl;
    }

    return 0;
}

