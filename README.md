🚀 PARSING EKSPRESI ARITMATIKA🚀  
--------------------------------------
📌 Program Ini Dibuat Untuk Proyek Mata Kuliah Struktur Data dan Algoritma.  
🎯 Tujuannya Untuk Mengonversi Ekspresi Aritmatika Antara Infix, Postfix, dan Prefix.
---
✨ Fitur Program  
Program ini bisa melakukan konversi ekspresi aritmatika berikut:  
✅ Infix ➝ Postfix  
✅ Infix ➝ Prefix  
✅ Postfix ➝ Infix  
✅ Prefix ➝ Infix  
✅ Prefix ➝ Postfix  
✅ Postfix ➝ Prefix  
___
📝Contoh Input & Output:

1️⃣ Infix ➝ Postfix  
Input: (A+B)\*C  
Output: AB+C\*  

2️⃣ Infix ➝ Prefix  
Input: (A+B)*C  
Output: *+ABC  

3️⃣ Postfix ➝ Infix  
Input: AB+C*  
Output: (A+B)*C  

4️⃣ Prefix ➝ Infix  
Input: *+ABC  
Output: (A+B)*C  

5️⃣ Prefix ➝ Postfix  
Input: \*+ABC  
Output: AB+C\*  

6️⃣ Postfix ➝ Prefix  
Input: AB+C*  
Output: *+ABC  
___
> ⚠️ Peringatan: Pastikan input sesuai format di bawah ini agar tidak terjadi error.

1️⃣ Gunakan Format Ekspresi yang Benar  
Pastikan ekspresi hanya terdiri dari huruf (A-Z, a-z) atau angka (0-9) sebagai operand.  
Operator yang didukung: +, -, *, /.  
  
Gunakan tanda kurung hanya untuk infix, misalnya:  
✅ Benar: (A+B)\*C  
❌ Salah: A+(B*\C (Kurung tidak seimbang)  
  
2️⃣ Jangan Memasukkan Ekspresi Kosong  
Jika input kosong, program tidak dapat memproses ekspresi dan akan mengembalikan error.  
  
3️⃣ Ekspresi Harus Valid Secara Sintaks  
Pastikan ekspresi tidak memiliki operator yang berurutan atau tidak ada operand di antara operator.  
Contoh yang salah:  
❌ "A++B" (Operator ganda tidak valid)  
❌ "AB+" dalam infix (ini hanya valid untuk postfix)  
  
4️⃣ Hindari Karakter yang Tidak Didukung  
Program hanya mendukung karakter berikut:  
Operand: A-Z, a-z, 0-9  
Operator: +, -, *, /  
Kurung dalam Infix: (, )  
Jangan masukkan karakter lain seperti ^, %, [ ], @, atau simbol lainnya.  
  
5️⃣ Perhatikan Prioritas Operator dalam Infix  
Jika ingin hasil yang sesuai, pastikan ekspresi infix ditulis dengan benar.  
Misalnya:  
✅ Benar: (A+B)\*C  
❌ Salah: A+B\*C) (Kurung tidak seimbang)  

6️⃣ Program Tidak Menangani Pembagian dengan Nol  
Meskipun program hanya melakukan konversi dan tidak melakukan perhitungan langsung, hindari ekspresi seperti A/0, karena dalam perhitungan nyata ini tidak valid.  
___
> ⚠️ Kekurangan Kode Program ini yaitu (Kalau sudah diperbaiki, akan dihapus):  
1. Program menggunakan stack berbasis array dengan size 100, tak bisa lebih.  
2. Stack menerima pointer ke string, yang artinya mumeeeeet beeeet, akan banyak kesulitan di trouble shooting.  
3. Bagaimana jika pengguna memasukkan selain dari abjad? (!isalnum), ya error lah brook, wong kodenya aja ga tau 😂  
4. Banyak variabel yang perlu diinisialisasi ukurannya per fungsi, yang mana kalau kita pakai ukuran MAX akan boros memori, jadi kita pakailah malloc yang suuuper ribeeet.  
5. Banyak perulangan yang sama di tiap fungsi yang sebenarnya bisa disederhanakan.  
6. // kita rehat sejenak.  
