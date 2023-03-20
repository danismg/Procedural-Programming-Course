## Academic Simulation
Tugas kali ini adalah kelanjutan dari tugas terstruktur sebelumnya dengan tujuan menyelesaikan studi kasus Academic Simulator.

### Academic Simulator
Hampir selesai pengembangan Academic Simulator karya Ucok dan Butet. Dari fitur-fitur yang telah dikembangkan, tersisa satu area penting yang belum diakomodir, rencana studi. Dengan motivasi tinggi dan tidak ingin membuang waktu, Ucok dan Butet pun mulai memikirkan perilaku simulator yang diharapkan.

Terlebih dahulu Butet mendaftarkan fitur rencana studi yang akan dikembangkan pada periode ini. Hal esensial yang perlu dipertahankan adalah perilaku dinamis dan interaktivitas dengan pengguna melalui perintah-perintah pada command line. Berikut adalah daftar fitur yang akan dikembangkan:
1. Secara dinamis melakukan penambahan rencana studi (```enrollment```) ke dalam simulator.
2. Fitur untuk menampilkan semua data ```enrollment``` yang tersimpan, dimulai dari yang lebih dahulu didaftarkan.
3. Fitur untuk mengeset nilai (```grade```) dari suatu ```enrollment``` berdasarkan ```course-code```, ```student-id```, ```year```, dan ```semester```-nya.
4. Fitur untuk menampilkan data ```student``` lengkap dengan ```gpa```-nya.

Selanjutnya, setelah mendaftarkan kebutuhan fitur yang akan dikembangkan, Ucok dan Butet kemudian merancang skema perintah yang akan dipakai untuk berinteraksi dengan simulator. Setiap perintah dituliskan dalam satu baris masukan ke standard input. Sebaris perintah terdiri atas paling sedikit satu segmen masukan. Sebuah segmen dapat dipisahkan dengan segmen lainnya dengan memperhatikan hash sign (```#```). Simulator akan secara terus menerus membaca perintah dari standard input dan hanya akan menghentikan eksekusi jika diberi triple dash signs (```---```). Berikut adalah rincian format perintah untuk setiap fitur.

#### 1. Penambahan data ```enrollment``` (file: ```t08_01.c```)
Fitur ini ditandai dengan perintah ```create-enrollment``` pada segmen pertama dan diikuti oleh empat segmen data lainnya, yaitu ```course-code```, ```student-id```, ```year```, dan ```semester```. Format perintah yang digunakan adalah sebagai berikut. 
```
create-enrollment#course-code#student-id#year#semester
```
Untuk menambahkan sebuah data baru, fitur ini akan memanfaatkan fungsi ```create_enrollment()``` yang telah dikembangkan beberapa waktu lalu. Perlu diingat bahwa ruang penyimpanan harus mencukupi, fit dengan jumlah data yang disimpan dan tidak berlebih.

Fitur ini tidak memberikan keluaran apapun ke standard output.

#### 2. Menampilkan semua data ```enrollment``` (file: ```t08_01.c```)
Fitur ini ditandai dengan perintah ```print-enrollments``` tanpa segmen tambahan. Format perintah yang digunakan adalah sebagai berikut. 
```
print-enrollments
```
Fitur ini memanfaatkan fungsi ```print_enrollments()``` dan ```print_enrollment()```.

Fitur ini akan mencetak seluruh data ```enrollment``` yang tersimpan ke standard output, mulai dari yang lebih awal disimpan.

#### 3. Menge-set nilai (```grade```) dari sebuah ```enrollment``` (file: ```t08_02.c```)
Fitur ini ditandai dengan perintah ```set-enrollment-grade``` dan diikuti oleh lima segmen data lainnya, yaitu ```course-code```, ```student-id```, ```year```, ```semester```, dan ```grade```-nya. Format perintah yang digunakan adalah sebagai berikut.
```
set-enrollment-grade#course-code#student-id#year#semester#grade
```
Fitur ini akan memanfaatkan fungsi ```set_enrollment_grade()``` yang telah dikembangkan beberapa waktu lalu.

Fitur ini tidak memberikan keluaran apapun ke standard output.

#### 4. Mengkalkulasi ```gpa``` (file: ```t08_03.c```)
Perhitungan ```gpa``` telah dilakukan beberapa waktu lalu dengan memanfaatkan fungsi ```calculate_gpa()```. Tugas anda adalah memastikan bahwa setiap kali ```print_student()``` dipanggil, maka gpa yang ditampilkan representatif terhadap ```enrollment```.

#### Note
1. Tidak diperbolehkan untuk memodifikasi berkas ```academic.h```.
2. Tidak diperbolehkan untuk mendefinisikan structure, enumeration, maupun fungsi selain entry point pada berkas ```08_XX.c```.
3. Silakan mendefinisikan structure, enumeration, atau fungsi tambahan pada berkas ```custom.h``` dan ```custom.c```.

### Case studies
#### Case 1 (t08_01.c, 40 points)
Berikut adalah contoh masukan yang diberikan.
```
create-student#12S20999#Wiro Sableng#2020#Information Systems
create-student#12S20998#Jaka Sembung#2020#Information Systems
print-students
create-course#12S1102#Visual Programming#2#D
create-course#TIS1101#Digital Innovation#2#D
print-courses
create-enrollment#12S1102#12S20999#2020-2021#odd
create-enrollment#12S1102#12S20998#2020-2021#odd
create-enrollment#TIS1101#12S20999#2020-2021#odd
create-enrollment#TIS1101#12S20998#2020-2021#odd
print-enrollments
---

```
Berikut adalah keluaran yang diharapkan.
```
12S20999|Wiro Sableng|2020|Information Systems|0.00
12S20998|Jaka Sembung|2020|Information Systems|0.00
12S1102|Visual Programming|2|D
TIS1101|Digital Innovation|2|D
12S1102|12S20999|None|0.00
12S1102|12S20998|None|0.00
TIS1101|12S20999|None|0.00
TIS1101|12S20998|None|0.00

```
#### Case 2 (t08_03.c, 20 points)
Berikut adalah contoh masukan yang diberikan.
```
create-student#12S20999#Wiro Sableng#2020#Information Systems
create-student#12S20998#Jaka Sembung#2020#Information Systems
print-students
create-course#12S1102#Visual Programming#2#D
create-course#TIS1101#Digital Innovation#2#D
print-courses
create-enrollment#12S1102#12S20999#2020-2021#odd
create-enrollment#12S1102#12S20998#2020-2021#odd
create-enrollment#TIS1101#12S20999#2020-2021#odd
create-enrollment#TIS1101#12S20998#2020-2021#odd
print-enrollments
set-enrollment-grade#12S1102#12S20999#2020-2021#odd#A
set-enrollment-grade#12S1102#12S20998#2020-2021#odd#A
set-enrollment-grade#TIS1101#12S20999#2020-2021#odd#AB
set-enrollment-grade#TIS1101#12S20998#2020-2021#odd#B
print-enrollments
---

```
Berikut adalah keluaran yang diharapkan.
```
12S20999|Wiro Sableng|2020|Information Systems|0.00
12S20998|Jaka Sembung|2020|Information Systems|0.00
12S1102|Visual Programming|2|D
TIS1101|Digital Innovation|2|D
12S1102|12S20999|None|0.00
12S1102|12S20998|None|0.00
TIS1101|12S20999|None|0.00
TIS1101|12S20998|None|0.00
12S1102|12S20999|A|8.00
12S1102|12S20998|A|8.00
TIS1101|12S20999|AB|7.00
TIS1101|12S20998|B|6.00

```
#### Case 3 (t08_03.c, 20 points)
Berikut adalah contoh masukan yang diberikan.
```
create-student#12S20999#Wiro Sableng#2020#Information Systems
create-student#12S20998#Jaka Sembung#2020#Information Systems
print-students
create-course#12S1102#Visual Programming#2#D
create-course#TIS1101#Digital Innovation#2#D
print-courses
create-enrollment#12S1102#12S20999#2020-2021#odd
create-enrollment#12S1102#12S20998#2020-2021#odd
create-enrollment#TIS1101#12S20999#2020-2021#odd
create-enrollment#TIS1101#12S20998#2020-2021#odd
print-enrollments
print-students
set-enrollment-grade#12S1102#12S20999#2020-2021#odd#A
set-enrollment-grade#12S1102#12S20998#2020-2021#odd#A
set-enrollment-grade#TIS1101#12S20999#2020-2021#odd#AB
set-enrollment-grade#TIS1101#12S20998#2020-2021#odd#B
print-enrollments
print-students
---

```
Berikut adalah keluaran yang diharapkan.
```
12S20999|Wiro Sableng|2020|Information Systems|0.00
12S20998|Jaka Sembung|2020|Information Systems|0.00
12S1102|Visual Programming|2|D
TIS1101|Digital Innovation|2|D
12S1102|12S20999|None|0.00
12S1102|12S20998|None|0.00
TIS1101|12S20999|None|0.00
TIS1101|12S20998|None|0.00
12S20999|Wiro Sableng|2020|Information Systems|0.00
12S20998|Jaka Sembung|2020|Information Systems|0.00
12S1102|12S20999|A|8.00
12S1102|12S20998|A|8.00
TIS1101|12S20999|AB|7.00
TIS1101|12S20998|B|6.00
12S20999|Wiro Sableng|2020|Information Systems|2.88
12S20998|Jaka Sembung|2020|Information Systems|3.63

```

## Submission
1. academic.c
2. t08_01.c
3. t08_02.c
4. t08_03.c
5. changelog.txt

## How to submit?
Please see https://youtu.be/g0BQ195-aWo