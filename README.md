## Baitap1-security
AN TOÀN VÀ BẢO MẬT THÔNG TIN
# Tìm hiểu các phươngg pháp mã hoá cổ điển
1. Caesar
2. Affine
3. Hoán vị
4. Vigenère
5. Playfair

# Với mỗi phương pháp, hãy tìm hiểu:
a) Tên gọi

b) Thuật toán mã hoá, thuật toán giải mã

c) Không gian khóa

d) Cách phá mã (mà không cần khoá)

e) Cài đặt thuật toán mã hoá và giải mã bằng code C++ và bằng html+css+javascript
# BÀI LÀM:
1. Phương pháp Caesar:

a) Tên gọi:
Mã Caesar cipher (shift cipher)

b) Thuật toán mã hoá, thuật toán giải mã
- Mã hoá:
  (Ký tự P --> số p 0...25): C = (P + k)mod 26
  
- Giải mã:
   P = (C - k)mod 26
  
P: ký tự bản rõ (plaintext, dạng số 0-25)

C: ký tự bản mã (ciphertext)

k: khoá (số bước dịch chuyển)

c) Không gian khoá:
k ∈ {0, 1, 2,...,25}--> 26 khả năng

d) Cách phá mã (không cần khoá):

- Brute-force: thử toàn bộ giá trị (26 giá trị k)
  
- Phân tích tần suất / chi-squared cho văn bản dài.

- Crib / từ điển scoring.

e) Cài đặt thuật toán mã hoá và giải mã bằng code C++ và bằng html+css+javascript
-C++:

<img width="1334" height="639" alt="image" src="https://github.com/user-attachments/assets/aadf7f4c-924c-4d34-922d-928d82bb79b6" />

- HTML/

2. Phương pháp Affine:
a) Tên gọi:

Affine cipher (Mật mã Affine)

b) Thuật toán mã hoá, thuật toán giải mã:

- Mã hoá: C = (a.P + b ) mod 26 với điều kiện gcd(a,26) =1(để có nghịch đảo modulo 26)
- Giải mã : P =a^(-1).(C-b) mod 26
a^(-1) là nghịch đảo
  a^(-1): nghịch đảo modular của a.

c) Không gian khoá:

d) Cách phá mã (không cần khoá):
