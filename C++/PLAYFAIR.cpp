#include <bits/stdc++.h>
using namespace std;

// Chuẩn hóa chuỗi: in hoa, bỏ J, loại ký tự không phải chữ
string chuanHoa(const string &s) {
    string r; 
    for (char c : s) 
        if (isalpha(c)) r += (toupper(c) == 'J' ? 'I' : toupper(c));
    return r;
}

// Tạo bảng 5x5 từ khóa
vector<vector<char>> taoBangKhoa(const string &k) {
    string used = chuanHoa(k), alpha = "ABCDEFGHIKLMNOPQRSTUVWXYZ";
    for (char c : alpha) if (used.find(c) == string::npos) used += c;
    vector<vector<char>> m(5, vector<char>(5));
    for (int i = 0; i < 25; i++) m[i/5][i%5] = used[i];
    return m;
}

// Tìm vị trí ký tự trong bảng
pair<int,int> pos(const vector<vector<char>> &m, char c) {
    for (int i = 0; i < 5; i++) 
        for (int j = 0; j < 5; j++) 
            if (m[i][j] == c) return make_pair(i,j);
    return make_pair(-1,-1);
}

// Tạo cặp ký tự (digraphs)
string taoCap(const string &s) {
    string str = chuanHoa(s), r;
    for (size_t i = 0; i < str.size(); i++) {
        char a = str[i], b = (i+1 < str.size() ? str[i+1] : 'X');
        if (a == b) { r += a; r += 'X'; }
        else { r += a; r += b; i++; }
    }
    if (r.size() % 2) r += 'X';
    return r;
}

// Hàm mã hóa/giải mã
string playfair(const string &txt, const string &k, string mode) {
    vector<vector<char>> m = taoBangKhoa(k);
    string str = (mode == "enc" ? taoCap(txt) : chuanHoa(txt)), r;
    int sh = (mode == "enc" ? 1 : 4);

    for (size_t i = 0; i < str.size(); i += 2) {
        pair<int,int> p1 = pos(m, str[i]);
        pair<int,int> p2 = pos(m, str[i+1]);
        int r1 = p1.first, c1 = p1.second;
        int r2 = p2.first, c2 = p2.second;

        if (r1 == r2) { 
            r += m[r1][(c1+sh)%5]; r += m[r2][(c2+sh)%5]; 
        } else if (c1 == c2) { 
            r += m[(r1+sh)%5][c1]; r += m[(r2+sh)%5][c2]; 
        } else { 
            r += m[r1][c2]; r += m[r2][c1]; 
        }
    }

    if (mode == "dec") {
        string clean;
        for (size_t i = 0; i < r.size(); i++)
            if (!(i > 0 && i < r.size()-1 && r[i]=='X' && r[i-1]==r[i+1])) 
                clean += r[i];
        if (!clean.empty() && clean.back()=='X') clean.pop_back();
        return clean;
    }
    return r;
}

int main() {
    while (true) {
        cout << "\n--- PLAYFAIR ---\n1. Ma hoa\n2. Giai ma\n3. Thoat\nChon: ";
        int c; cin >> c; cin.ignore();
        if (c == 3) break;
        string t, k; 
        cout << "Nhap van ban: "; getline(cin, t);
        cout << "Nhap khoa: "; getline(cin, k);
        if (c == 1) cout << "Ban ma: " << playfair(t, k, "enc") << "\n";
        else if (c == 2) cout << "Ban giai ma: " << playfair(t, k, "dec") << "\n";
        else cout << "Lua chon khong hop le.\n";
    }
    return 0;
}
