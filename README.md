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

<img width="1741" height="767" alt="image" src="https://github.com/user-attachments/assets/43ac6e42-bf7d-478e-b079-3624223b8fe7" />


- HTML/

<img width="966" height="486" alt="image" src="https://github.com/user-attachments/assets/fc086f2a-be7b-42d9-a89f-9448a251280b" />

<img width="864" height="466" alt="image" src="https://github.com/user-attachments/assets/f8550018-1697-4e78-8075-ee114b8232fb" />


2. Phương pháp Affine:
a) Tên gọi:

Affine cipher (mã Affine)

b) Thuật toán mã hoá, thuật toán giải mã:

- Mã hoá: C = (a.P + b ) mod 26 với điều kiện gcd(a,26) =1(để có nghịch đảo modulo 26)

- Giải mã : P =a^(-1).(C-b) mod 26
a^(-1) là nghịch đảo modulo 26 (số x sao cho a.x=1 mod 26)

Trong đó: 

- a,b là khoá. Đk: gcd(a,26)=1 (để tồn tại nhịch đảo)
- a^(-1): nghịch đảo modular của a.

c) Không gian khoá:
Với bảng chữ cái 26 ký tự, khoá Affine là cặp ( a,b) sao cho:

- a thuộc tập các số nguyên tố cùng nhau với 26 (tức gcd(a,26)=1
- b là số nguyên trong [0,25]
- số lựa chọn  bằng 𝜑(26)=12. Các giá trị hợp lệ của a: 1, 3, 5, 7, 9, 11, 15, 17, 19, 21, 23, 25.
- b có 26 khả năng (0..25).
- Tổng không gian khoá = 12x26=312 khoá

d) Cách phá mã (không cần khoá):

- Brute-force (thử tất cả khóa): duyệt tất cả 312 cặp (𝑎,𝑏) giải mã với mỗi cặp rồi kiểm tra kết quả.
- Known-plaintext attack (biết một vài cặp bản rõ–bản mã)

e) Cài đặt thuật toán mã hoá và giải mã bằng code C++ và bằng html+css+javascript
-C++:

<img width="406" height="536" alt="image" src="https://github.com/user-attachments/assets/b567062c-b0e9-4e82-80bb-a89586a3b4ca" />

- HTML

  
<img width="845" height="766" alt="image" src="https://github.com/user-attachments/assets/d3a0a555-acc2-4a08-aafd-7ef77f22adf9" />


<img width="877" height="775" alt="image" src="https://github.com/user-attachments/assets/884b1430-1226-4f16-92c3-8985d6227b21" />

3. Hoán vị

a) Tên gọi

Thường gọi: Permutation cipher, Transposition cipher

b) Thuật toán mã hoá, thuật toán giải mã

Mã hoá (Columnar Transposition):

- Lấy keyLength = độ dài khóa (k).

- Viết bản rõ ngang hàng vào ma trận có k cột, điền theo hàng trái→phải, khi hết hàng tạo hàng mới. Nếu cuối cùng thiếu ô thì pad (thường là 'X' hoặc '_').

- Đọc ra bản mã bằng cách lấy các cột theo thứ tự của chỉ số khóa đã sắp (tức cột có chữ cái khóa nhỏ nhất trước, v.v.), đọc từ trên xuống dưới. Nối các cột theo thứ tự này → ciphertext.

Giải mã:

- Biết k và thứ tự cột (từ khóa).

- Tính số hàng: rows = ceil(len(cipher)/k). Nếu len không chia hết, một vài cột ngắn hơn 1 ô (chi tiết cần tính cẩn thận). Cách phổ biến: tính số ô đầy trong mỗi cột dựa trên len(cipher) % k.

- Phân chia ciphertext thành k cột theo thứ tự sắp (mỗi cột có chiều dài tương ứng).

- Đọc ma trận theo hàng trái→phải, nối lại để lấy plaintext; loại bỏ padding nếu cần.

c) Không gian khóa

- Nếu khóa được biểu diễn là một phép hoán vị của k cột, số khóa = k! (k giai thừa).

- Nếu dùng khóa là từ (chuỗi ký tự), các ký tự trùng nhau làm giảm số lượng perm do đối xứng.

--> Kết luận: không gian khóa tăng rất nhanh với k. Nhưng trong thực tế ngôn ngữ và chiều dài khóa thường nhỏ nên bị phá được.

d) Cách phá mã (mà không cần khoá)

- Brute-force (thử mọi hoán vị)

Thử tất cả k! hoán vị (k nhỏ ≤ 8–9 khả thi). Mỗi lời giả (plaintext) chấm điểm bằng n-gram / frequency scoring để chọn kết quả hợp lý.

- Known-plaintext / crib attack

Nếu biết (hoặc đoán) một mẩu bản rõ (crib), ta có thể “trượt” crib qua ciphertext, kiểm tra tính tương thích vị trí — rất mạnh cho transposition.

- Anagram / column-length heuristics

Kiểm tra các cột có cấu trúc từ/cụm từ khả dĩ (ví dụ cột tạo ra nhiều nguyên âm/ngắn từ) — dựa vào tính chất bảng chữ cái.

- Statistical scoring (n-gram)

Với mỗi hoán vị thử được, ghép lại plaintext giả, tính điểm bằng unigrams/bigrams/trigrams; chọn lời có điểm cao nhất.

- Kết hợp với substitution

Nếu ciphertext là transposition cộng substitution (ví dụ: substitution trước rồi transposition), phải kết hợp với phân tích tần suất và các phương pháp giải mã hỗn hợp.

- Tối ưu hóa tìm kiếm

Dùng heuristics (hill-climbing, simulated annealing) để tìm hoán vị tốt nhất theo điểm n-gram; rất hiệu quả với khóa dài hơn.

e) Cài đặt thuật toán mã hoá và giải mã bằng code C++ và bằng html+css+javascript
