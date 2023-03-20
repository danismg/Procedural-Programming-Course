## Indirection
Tugas kali ini adalah kelanjutan dari tugas terstruktur sebelumnya dengan penekanan pada aspek indirection.

### Academic
Minggu lalu, Butet dan Ucok telah mengembangkan sebuah simulator untuk mensimulasikan entitas-entitas pada lingkup dunia akademik. Simulator tersebut masih sederhana dan memiliki banyak ruang pengembangan. Butet dan Ucok mengidentifikasi setidaknya ada empat fungsionalitas yang dapat dikembangkan. 
1. Fitur yang pertama adalah penyimpanan informasi GPA (Grade Point Average) atau yang biasa disebut IPK (Indeks Prestasi Kumulatif) atau IPS (Indeks Prestasi Semester) untuk konteks periode yang lebih pendek.
2. Fitur untuk menampilkan sekumpulan enrollment yang dikemas dalam sebuah array. Fitur ini bermanfaat untuk memudahkan manajemen data.
3. Fitur kedua adalah pemberian nilai terhadap suatu enrollment atau rencana studi.
4. Fitur untuk menghitung GPA.

Kemarin sore, Butet dan Ucok yang kurang kerjaan ini, menemui dosen pemrograman yang minggu lalu menugaskan mereka mengembangkan simulator. Mereka menyampaikan ide mereka untuk melanjutkan pengembangan dengan menambahkan keempat fitur. Ide mereka diterima dan mereka diizinkan untuk merealisasikan ide tersebut.

Dalam merealisasikan idenya, Butet dan Ucok lebih banyak berpikir dan berdiskusi daripada langsung menulis kode. Mereka merencanakan pendekatan yang akan digunakan. Butet ingin mempertahankan konsep dan desain yang telah ada pada simulator dan lebih memilih untuk bekerja dengan mengikuti pola yang sama. Dengan demikian tidak akan merusak apa yang sudah ada.

Setelah beberapa saat melakukan brainstorming, Butet dan Ucok kemudian menyepakati:
1. Untuk meletakkan ```GPA``` sebagai bagian dari entitas ```student``` dengan tipe data ```float```. Selain itu, ```GPA``` akan selalu direpresentasikan dalam dua digit presisi. Oleh sebab itu, implementasi fungsi ```print_student``` perlu disesuaikan.
2. Untuk memudahkan manajemen data, enrollment akan disimpan dalam array. Sebagai batasan, array akan di-set fixed-size, 10 elemen. Di masa mendatang, ukuran ini dapat dibuat dinamis.
3. Untuk menampilkan enrollment yang tersimpan pada array, akan dikembangkan sebuah fungsi baru ```print_assignments``` yang perilakunya sangat mirip dengan ```print_assingment```. Perbedaannya terletak pada tipe masukan.
4. Untuk mengeset grade dari suatu enrollment akan dikembangkan sebuah fungsi baru, ```set_enrollment_grade```. Nilai diberikan pada sebuah enrollment dengan ```course``` dan ```student``` yang relevan. Jika terdapat lebih dari satu enrollment yang relevan, maka grade akan diberikan pada enrollment yang paling akhir dimasukan.
5. Untuk menghitung GPA akan dikembangkan sebuah fungsi baru, ```calculate_gpa```. Pada saat menghitung GPA, hanya memperhitungkan enrollment yang relevan saja.

### Solution Design
Semua entitas telah didefinisikan pada berkas ```academic.h```. Entitas ```course```, ```student```, dan ```enrollment``` didefinisikan dalam bentuk structures, sementara opsi nilai (```grade```) dan ```semester``` didefinisikan dalam bentuk enumerations. Pada ```academic.h``` juga telah dituliskan spesifikasi dari fungsi-fungsi yang harus dikembangkan untuk menyelesaikan tugas ini. Atribut baru, ```gpa``` pada struktur ```student``` dan berbagai function prototypes yang diperlukan telah didefinisikan pada ```academic.h```. 

Dengan mengikuti pendekatan pada pekerjaan sebelumnya, maka hanya diperbolehkan untuk mengubah berkas ```academic.c``` saja. Pada berkas tersebut berisi implementasi dari spesifikasi. Implementasi yang dikerjakan Butet harus merujuk pada spesifikasi.

### Output Formats
1. Terjadi perubahan pada format keluaran untuk ```print_student``` dengan tambahan nilai ```gpa``` pada segmen akhir (lihat contoh cases).
2. Untuk ```print_enrollements``` pada dasarnya sama dengan ```print_enrollement``` dengan jumlah baris keluaran sesuai dengan banyak elemen pada array yang diberikan sebagai parameter.

### Compilation
Proses kompilasi harus menyertakan program dan ```academic.c``` yang berisi implementasi dari spesifikasi. Berikut ini adalah contoh perintah untuk mengkompilasi ```t06_01.c```.
```
> gcc t06_01.c academic.c -o t06_01
```
Dari kompilasi akan dihasilkan sebuah berkas executable ```t06_01```.

### Case 1 (t06_01.c, 20 points)
Berikut adalah keluaran yang diharapkan.
```
12S1102|Visual Programming|2|D
10S1002|Procedural Programming|2|D
12S20999|Wiro Sableng|2020|Information Systems|0.00

```
### Case 2 (t06_02.c, 20 points)
Berikut adalah keluaran yang diharapkan.
```
12S1102|Visual Programming|2|D
10S1002|Procedural Programming|2|D
12S20999|Wiro Sableng|2020|Information Systems|0.00
12S1102|12S20999|None|0.00
10S1002|12S20999|None|0.00

```
### Case 3 (t06_03.c, 20 points)
Berikut adalah keluaran yang diharapkan.
```
12S1102|Visual Programming|2|D
10S1002|Procedural Programming|2|D
12S20999|Wiro Sableng|2020|Information Systems|0.00
12S1102|12S20999|None|0.00
10S1002|12S20999|None|0.00
12S1102|12S20999|A|8.00
10S1002|12S20999|AB|7.00

```
### Case 4 (t06_04.c, 20 points)
Berikut adalah keluaran yang diharapkan.
```
12S1102|Visual Programming|2|D
10S1002|Procedural Programming|2|D
12S20999|Wiro Sableng|2020|Information Systems|0.00
12S1102|12S20999|None|0.00
10S1002|12S20999|None|0.00
12S1102|12S20999|A|8.00
10S1002|12S20999|AB|7.00
12S20999|Wiro Sableng|2020|Information Systems|3.75

```

## Submission
1. academic.c
2. changelog.txt

## How to submit?
Please see https://youtu.be/g0BQ195-aWo