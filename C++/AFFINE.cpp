#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// -------------------------
// Hàm tiện ích
// -------------------------

// Ước chung lớn nhất (gcd)
int ucln(int a, int b) {
    return (b == 0) ? a : ucln(b, a % b);
}

// Nghịch đảo modular của a theo mod m
int modInverse(int a, int m) {
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1) return x;
    }
    return 1; // Trả về 1 nếu không tìm được
}

// -------------------------
// Hàm mã hóa & giải mã Affine
// -------------------------

// Mã hóa: E(x) = (a*x + b) mod 26
string affineEncrypt(const string &text, int a, int b) {
    string result = "";
    for (char c : text) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            result += char(((a * (c - base) + b) % 26) + base);
        } else {
            result += c;
        }
    }
    return result;
}

// Giải mã: D(y) = a^(-1) * (y - b) mod 26
string affineDecrypt(const string &text, int a, int b) {
    string result = "";
    int a_inv = modInverse(a, 26);
    for (char c : text) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            result += char((a_inv * ((c - base - b + 26)) % 26) + base);
        } else {
            result += c;
        }
    }
    return result;
}

// -------------------------
// Chương trình chính
// -------------------------

int main() {
    cout << "=== THUAT TOAN MA HOA AFFINE ===\n";

    int choice;
    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Ma hoa\n";
        cout << "2. Giai ma\n";
        cout << "0. Thoat\n";
        cout << "Lua chon cua ban: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            string ban_ro;
            int a, b;
            cout << "\nNhap ban ro: ";
            getline(cin, ban_ro);
            cout << "Nhap khoa a (nguyen to cung 26): ";
            cin >> a;
            cout << "Nhap khoa b: ";
            cin >> b;
            cin.ignore();

            if (ucln(a, 26) != 1) {
                cout << "Khoa a khong hop le! Phai nguyen to cung 26.\n";
            } else {
                string ban_ma = affineEncrypt(ban_ro, a, b);
                cout << "Ban ma: " << ban_ma << "\n";
            }

        } else if (choice == 2) {
            string ban_ma;
            int a, b;
            cout << "\nNhap ban ma: ";
            getline(cin, ban_ma);
            cout << "Nhap khoa a: ";
            cin >> a;
            cout << "Nhap khoa b: ";
            cin >> b;
            cin.ignore();

            string ban_ro = affineDecrypt(ban_ma, a, b);
            cout << "Ban ro sau giai ma: " << ban_ro << "\n";
        }

    } while (choice != 0);

    cout << "Chuong trinh ket thuc.\n";
    return 0;
}
