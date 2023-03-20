## Structure
Pada sesi ini anda diminta untuk menyelesaikan sebuah persoalan yang akan melatih imajinasi serta kemampuan anda dalam mendefinisikan, menggunakan, dan memanipulasi structure. Lebih lanjut, anda juga akan memanfaatkan structure dalam pola array.

### Task 01: Dictionary (score: 100pts; file : t04_01.c)
Ucok mengalami kesulitan dalam mempelajari Bahasa Inggris. Kelemahan Ucok yang paling menghambat adalah dalam perbendaharaan kosa kata (vocabulary). Ucok mendapati salah satu solusi yang dapat diambil untuk membantunya memperbanyak kosa kata dalam Bahasa Inggris adalah dengan menggunakan kamus (dictionary).

Ucok selanjutnya ingin berinovasi untuk mengembangkan sebuah solusi yang di masa mendatang dapat juga digunakan oleh teman-temannya. Sebagai awal mula pengembangan, Ucok menginginkan dua fungsionalitas dasar pada kamus yang akan dikembangkannya, yaitu:
1. mencatat kosa kata dalam Bahasa Inggris dan artinya dalam Bahasa Indonesia; dan
2. mencari arti dari suatu kata dalam Bahasa Inggris.

Ucok selanjutnya merancang serangkaian perintah untuk melakukan fungsionalitas di atas. Perintah akan dimasukan dalam bentuk sebaris input dan diikuti dengan satu atau lebih input lainnya. Solusi akan terus-menerus membaca perintah dari pengguna hingga diperintahkan untuk berhenti. Berikut adalah daftar perintah yang akan diproses oleh solusi:
- Baris perintah ```register``` digunakan untuk menambahkan sebuah informasi kosa kata baru. Baris perintah ini akan diikuti oleh tiga buah masukan lainnya yang merepresentasikan ```kata``` dalam Bahasa Inggris, dan ```arti kata``` dalam Bahasa Indonesia.
- Baris perintah ```find``` digunakan untuk mencari arti atau makna dari sebuah kata dalam Bahasa Inggris. Baris perintah ini akan diikuti oleh satu baris masukan lagi berupa ```kata``` yang akan dicari arti atau maknanya. Solusi kemudian akan mencari kecocokan ```kata``` tersebut dan menampilkannya dalam satu baris keluaran.
- Baris perintah ```---``` digunakan untuk mengakhiri solusi.

Dalam upayanya mengembangkan solusi yang efektif dan elegan, Ucok akan menggunakan structure dan enumeration. Ucok akan mengerjakan proyek ini dengan sahabatnya, Butet.

### Solution Design
Ucok dan Butet akan menyimpan ```kata``` dan ```arti kata``` dalam sebuah structure.

### Limitations
Sebagai permulaan, diasumsikan bahwa kamus hanya akan menyimpan paling banyak 5 kata. Jika jumlah kata telah tercapai, maka kamus akan mengabaikan perintah untuk menambahkan (```register```) kata baru dengan tidak menyimpan kata baru tersebut. Maksimum panjang dari sebuah kata adalah 20, dan panjang teks untuk arti dari kata adalah 80.

### Input
Solusi akan secara terus-menerus membaca satu baris perintah yang dimasukan oleh pengguna. Solusi kemudian bereaksi sesuai dengan perintah yang dimasukan. Solusi hanya akan berhenti jika diperintahkan. Terdapat tiga buah perintah, yaitu:
- Baris perintah ```register``` digunakan untuk menambahkan sebuah informasi kosa kata baru. Baris perintah ini akan diikuti oleh tiga buah masukan lainnya yang merepresentasikan ```kata``` dalam Bahasa Inggris, dan ```arti kata``` dalam Bahasa Indonesia.
- Baris perintah ```find``` digunakan untuk mencari arti atau makna dari sebuah kata dalam Bahasa Inggris. Baris perintah ini akan diikuti oleh satu baris masukan lagi berupa ```kata``` yang akan dicari arti atau maknanya.
- Baris perintah ```---``` digunakan untuk mengakhiri solusi.

```
<register
<kata>
<arti kata>|find
<kata>|--->

```

### Output
Solusi hanya akan memberikan satu baris keluaran, yaitu pada saat melakukan pencarian ```kata```. Pada saat melaksanakan perintah lainnya, solusi tidak memberikan keluaran apapun. Jika ```kata``` yang dicari TIDAK ditemukan, maka solusi tidak akan memberikan keluaran apapun. Satu baris keluaran terdiri atas tiga segmen, yaitu ```kata``` dalam Bahasa Inggris, dan ```arti kata``` yang diseparasi dengan simbol ```#```.

```
<kata>#<arti kata>
```

### Example 1
Input:
```
register
ski
ski
find
ski
register
skin
kulit
find
ski
find
skin
---

```

Output:
```
ski#ski
ski#ski
skin#kulit

```

### Example 2
Input:
```
find
bag
register
bag
tas
find
bag
---

```

Output:
```
bag#tas

```

### Example 3
Input:
```
---

```

Output:
```
```

## Submission
1. t04_01.c
2. changelog.txt

## How to submit?
Please see https://youtu.be/g0BQ195-aWo