#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;

// Chuyển key thành vector shift (0..25), bỏ ký tự không phải chữ
vector<int> keyShifts(const string &key) {
    vector<int> shifts;
    for (char ch : key) {
        if (isalpha(static_cast<unsigned char>(ch))) {
            char up = toupper(static_cast<unsigned char>(ch));
            shifts.push_back(up - 'A');
        }
    }
    return shifts;
}

// Mã hóa Vigenere: giữ nguyên case và ký tự khác chữ
string vigenereEncrypt(const string &plain, const vector<int> &shifts) {
    if (shifts.empty()) return "[Loi] Key khong hop le (khong co chu cai).";
    string out;
    out.reserve(plain.size());
    int k = shifts.size();
    int pos = 0;
    for (char ch : plain) {
        if (isalpha(static_cast<unsigned char>(ch))) {
            bool isUpper = isupper(static_cast<unsigned char>(ch));
            char base = isUpper ? 'A' : 'a';
            int p = ch - base;
            int c = (p + shifts[pos % k]) % 26;
            out.push_back(static_cast<char>(c + base));
            pos++;
        } else {
            out.push_back(ch);
        }
    }
    return out;
}

// Giải mã Vigenere
string vigenereDecrypt(const string &cipher, const vector<int> &shifts) {
    if (shifts.empty()) return "[Loi] Key khong hop le (khong co chu cai).";
    string out;
    out.reserve(cipher.size());
    int k = shifts.size();
    int pos = 0;
    for (char ch : cipher) {
        if (isalpha(static_cast<unsigned char>(ch))) {
            bool isUpper = isupper(static_cast<unsigned char>(ch));
            char base = isUpper ? 'A' : 'a';
            int y = ch - base;
            int p = (y - shifts[pos % k] + 26) % 26;
            out.push_back(static_cast<char>(p + base));
            pos++;
        } else {
            out.push_back(ch);
        }
    }
    return out;
}

int main() {
    cout << "=== VIGENERE CIPHER ===\n";
    int choice;
    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Ma hoa\n2. Giai ma\n0. Thoat\nChon: ";
        if (!(cin >> choice)) return 0;
        cin.ignore(); // bỏ '\n'
        if (choice == 1) {
            string plain, key;
            cout << "\nNhap ban ro: ";
            getline(cin, plain);
            cout << "Nhap khoa (cchuoi ki tu, chi chu se duoc dung): ";
            getline(cin, key);
            vector<int> shifts = keyShifts(key);
            string cipher = vigenereEncrypt(plain, shifts);
            cout << "Ban ma: " << cipher << "\n";
        } else if (choice == 2) {
            string cipher, key;
            cout << "\nNhap ban ma: ";
            getline(cin, cipher);
            cout << "Nhap khoa (chuoi ki tu, chi chu se duoc dung): ";
            getline(cin, key);
            vector<int> shifts = keyShifts(key);
            string plain = vigenereDecrypt(cipher, shifts);
            cout << "Ban ro: " << plain << "\n";
        }
    } while (choice != 0);
    cout << "Thoat chuong trinh.\n";
    return 0;
}
