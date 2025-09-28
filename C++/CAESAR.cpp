#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// Hàm mã hóa Caesar
string encryptCaesar(const string &text, int key) {
    string result;
    result.reserve(text.size()); // tối ưu cấp phát bộ nhớ

    for (char c : text) {
        if (isupper(c)) {
            result.push_back(char((c - 'A' + key) % 26 + 'A'));
        } else if (islower(c)) {
            result.push_back(char((c - 'a' + key) % 26 + 'a'));
        } else {
            result.push_back(c); // giữ nguyên ký tự khác chữ
        }
    }
    return result;
}

// Hàm giải mã Caesar
string decryptCaesar(const string &text, int key) {
    string result;
    result.reserve(text.size());

    for (char c : text) {
        if (isupper(c)) {
            result.push_back(char((c - 'A' - key + 26) % 26 + 'A'));
        } else if (islower(c)) {
            result.push_back(char((c - 'a' - key + 26) % 26 + 'a'));
        } else {
            result.push_back(c);
        }
    }
    return result;
}

int main() {
    string plaintext, ciphertext;
    int key;

    cout << "Nhap ban ro: ";
    getline(cin, plaintext);

    cout << "Nhap khoa k (so buoc dich chuyen): ";
    cin >> key;
    cin.ignore();

    ciphertext = encryptCaesar(plaintext, key);
    cout << "==> Ban ma: " << ciphertext << endl;

    cout << "\nNhap ban ma de giai ma: ";
    getline(cin, ciphertext);

    cout << "Nhap khoa k de giai ma: ";
    cin >> key;

    string decrypted = decryptCaesar(ciphertext, key);
    cout << "==> Ban ro sau giai ma: " << decrypted << endl;

    return 0;
}
