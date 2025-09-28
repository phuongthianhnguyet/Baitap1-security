#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// Hàm sinh thứ tự cột từ khóa (dựa theo sắp xếp chữ cái của khóa)
vector<int> keyOrder(const string &key) {
    int k = key.size();
    vector<pair<char, int>> v;
    for (int i = 0; i < k; i++) {
        v.push_back({key[i], i});
    }
    stable_sort(v.begin(), v.end(), [](auto &a, auto &b) {
        return a.first < b.first;
    });

    vector<int> order(k);
    for (int i = 0; i < k; i++) {
        order[i] = v[i].second;
    }
    return order;
}

// Hàm mã hóa (Columnar Transposition)
string permutationEncrypt(const string &plain, const string &key, char padChar = 'X') {
    int k = key.size();
    int rows = (plain.size() + k - 1) / k; // làm tròn lên
    int total = rows * k;

    string work = plain;
    if ((int)work.size() < total) work.append(total - work.size(), padChar);

    // Tạo ma trận
    vector<string> matrix(rows, string(k, padChar));
    int idx = 0;
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < k; c++) {
            matrix[r][c] = work[idx++];
        }
    }

    // Sắp xếp cột theo khóa
    vector<int> order = keyOrder(key);

    // Đọc cột theo thứ tự đã sắp
    string cipher;
    for (int pos = 0; pos < k; pos++) {
        int col = order[pos];
        for (int r = 0; r < rows; r++) {
            cipher.push_back(matrix[r][col]);
        }
    }
    return cipher;
}

// Hàm giải mã
string permutationDecrypt(const string &cipher, const string &key, char padChar = 'X') {
    int k = key.size();
    int L = cipher.size();
    int rows = (L + k - 1) / k;
    int total = rows * k;

    string work = cipher;
    if ((int)work.size() < total) work.append(total - work.size(), padChar);

    vector<int> order = keyOrder(key);

    // Mỗi cột có 'rows' ký tự
    vector<string> cols(k, string(rows, padChar));

    int idx = 0;
    for (int pos = 0; pos < k; pos++) {
        int col = order[pos];
        for (int r = 0; r < rows; r++) {
            cols[col][r] = work[idx++];
        }
    }

    // Đọc hàng
    string plain;
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < k; c++) {
            plain.push_back(cols[c][r]);
        }
    }

    // Xoá ký tự pad cuối (nếu có)
    while (!plain.empty() && plain.back() == padChar) {
        plain.pop_back();
    }

    return plain;
}

// -------------------------
// Chương trình chính
// -------------------------
int main() {
    string ban_ro, ban_ma, ban_ma_nhap, key;

    cout << "=== PHUONG PHAP MA HOA HOAN VI (Permutation Cipher) ===\n";

    // Mã hóa
    cout << "\n--- MA HOA ---\n";
    cout << "Nhap ban ro: ";
    getline(cin, ban_ro);
    cout << "Nhap khoa (mot tu bat ky): ";
    getline(cin, key);

    ban_ma = permutationEncrypt(ban_ro, key);
    cout << "Ban ma: " << ban_ma << "\n";

    // Giải mã
    cout << "\n--- GIAI MA ---\n";
    cout << "Nhap ban ma: ";
    getline(cin, ban_ma_nhap);
    cout << "Nhap lai khoa (phai trung voi luc ma hoa): ";
    getline(cin, key);

    string giai_ma = permutationDecrypt(ban_ma_nhap, key);
    cout << "Ban ro sau giai ma: " << giai_ma << "\n";

    return 0;
}
