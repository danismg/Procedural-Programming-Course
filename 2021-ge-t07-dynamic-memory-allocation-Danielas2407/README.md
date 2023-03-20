## Dynamic Memory Allocation
Tugas kali ini adalah kelanjutan dari tugas terstruktur sebelumnya dengan menyertakan konsep dynamic memory allocation.

### Academic
Simulator hasil karya Ucok dan Butet kaya akan fitur. Meski demikian, simulator yang sudah dikembangkan belum sempurna, pengembangan masih diperlukan. Ada dua kekurangan mendasar dari simulator. Yang pertama adalah belum terwujudnya interaksi dinamis antara simulator dan penggunanya, masih statis. Yang kedua, adalah ketidakmampuan simulator untuk beradaptasi pada kebutuhan ruang penyimpanan yang dinamis. Untuk dapat dipergunakan, simulator harus secara manual diset ukuran ruang data yang akan dioperasikannya melalui additional command line argument.

Menyadari kedua keterbatasan tersebut sangat krusial bagi pengembangan selanjutnya, Ucok dan Butet kemudian berkomitmen untuk secara berhahap melanjutkan pengembangan. Pada tahap ini, Ucok dan Butet akan mengembangkan tujuh buah fitur:
1. Menstruktur simulator agar secara dinamis berinteraksi dengan pengguna. Interaksi dikemas dalam bentuk baris-baris instruksi yang setiap instruksinya kemudian akan ditindaklanjuti oleh simulator. Fitur ini akan tercapai setahap demi setahap dengan menyelesaikan keenam fitur lainnya.
2. Secara dinamis melakukan penambahan mahasiswa (```student```) ke dalam simulator.
3. Secara dinamis melakukan penambahan mata kuliah (```course```) ke dalam simulator.
4. Fitur untuk menampilkan semua data ```student``` yang tersimpan.
5. Fitur untuk menampilkan semua data ```course``` yang tersimpan.
6. Fitur untuk melakukan pencarian data ```student``` berdasarkan ```id```-nya.
7. Fitur untuk melakukan pencarian data ```course``` berdasarkan ```code```-nya.

Selanjutnya, setelah mendaftarkan kebutuhan fitur yang akan dikembangkan, Ucok dan Butet kemudian merancang skema perintah yang akan dipakai untuk berinteraksi dengan simulator. Setiap perintah dituliskan dalam satu baris masukan ke standard input. Sebaris perintah terdiri atas paling sedikit satu segmen masukan. Sebuah segmen dapat dipisahkan dengan segmen lainnya dengan memperhatikan hash sign (```#```). Simulator akan secara terus menerus membaca perintah dari standard input dan hanya akan menghentikan eksekusi jika diberi triple dash sign (```---```). Berikut adalah rincian format perintah untuk setiap fitur.

#### 1. Penambahan data ```student``` (file: ```t07_01.c```)
Fitur ini ditandai dengan perintah ```create-student``` pada segmen pertama dan diikuti oleh empat segmen data lainnya, yaitu ```id```, ```name```, ```year```, dan ```study-program```. Format perintah yang digunakan adalah sebagai berikut. 
```
create-student#id#name#year#study-program
```
Untuk menambahkan sebuah data baru, fitur ini akan memanfaatkan fungsi ```create_student()``` yang telah dikembangkan beberapa waktu lalu. Perlu diingat bahwa ruang penyimpanan harus mencukupi, fit dengan jumlah data yang disimpan dan tidak berlebih.

Fitur ini tidak memberikan keluaran apapun ke standard output.

#### 2. Menampilkan semua data ```student``` (file: ```t07_01.c```)
Fitur ini ditandai dengan perintah ```print-students``` tanpa segmen tambahan. Format perintah yang digunakan adalah sebagai berikut. 
```
print-students
```
Silakan untuk melengkapi fungsi ```print_students()``` dengan menyertakan ```students``` yang akan ditampilkan beserta ```sentinel``` variabel-nya. Secara iteratif, untuk menampilkan sebuah ```course```, fungsi ini akan memanfaatkan fungsi ```print_student()```.

Fitur ini akan mencetak seluruh data ```student``` yang tersimpan ke standard output.

#### 3. Penambahan data ```course``` (file: ```t07_02.c```)
Fitur ini ditandai dengan perintah ```create-course``` pada segmen pertama dan diikuti oleh empat segmen data lainnya, yaitu ```code```, ```name```, ```credit```, dan ```passing-grade```. Format perintah yang digunakan adalah sebagai berikut. 
```
create-course#code#name#credit#passing-grade
```
Untuk menambahkan sebuah data baru, fitur ini akan memanfaatkan fungsi ```create_course()``` yang telah dikembangkan beberapa waktu lalu. Perlu diingat bahwa ruang penyimpanan harus mencukupi, fit dengan jumlah data yang disimpan dan tidak berlebih.

Fitur ini tidak memberikan keluaran apapun ke standard output.

#### 4. Menampilkan semua data ```course``` (file: ```t07_02.c```)
Fitur ini ditandai dengan perintah ```print-courses``` tanpa segmen tambahan. Format perintah yang digunakan adalah sebagai berikut. 
```
print-courses
```
Silakan untuk melengkapi fungsi ```print_courses()``` dengan menyertakan ```courses``` yang akan ditampilkan beserta ```sentinel``` variabel-nya. Secara iteratif, untuk menampilkan sebuah ```course```, fungsi ini memanfaatkan fungsi ```print_course()```.

Fitur ini akan mencetak seluruh data ```course``` yang tersimpan ke standard output.

#### 5. Mencari data ```student``` berdasarkan ```id```-nya (file: ```t07_03.c```)
Fitur ini ditandai dengan perintah ```find-student-by-id``` dan diikuti oleh satu segmen lainnya yang berisi ```id``` dari student yang dicari. Format perintah yang digunakan adalah sebagai berikut. 
```
find-student-by-id#id
```
Silakan untuk melengkapi fungsi ```find_student_by_id()``` dengan menyertakan ```students``` yang akan ditampilkan, ```sentinel``` variabel, dan ```id``` yang akan digunakan sebagai basis pencarian. Gunakan ```strcmp()``` untuk memeriksa kesesuaian ```id```.

Jika ditemukan, fungsi akan memanggil ```print_student()```, jika tidak menemukan data yang sesuai maka tidak ada keluaran yang diberikan.

#### 6. Mencari data ```course``` berdasarkan ```code```-nya (file: ```t07_04.c```)
Fitur ini ditandai dengan perintah ```find-course-by-code``` dan diikuti oleh satu segmen lainnya yang berisi ```id``` dari course yang dicari. Format perintah yang digunakan adalah sebagai berikut. 
```
find-course-by-code#code
```
Silakan untuk melengkapi fungsi ```find_course_by_code()``` dengan menyertakan ```course``` yang akan ditampilkan, ```sentinel``` variabel, dan ```code``` yang akan digunakan sebagai basis pencarian. Gunakan ```strcmp()``` untuk memeriksa kesesuaian ```code```.

Jika ditemukan, fungsi akan memanggil ```print_course()```, jika tidak menemukan data yang sesuai maka tidak ada keluaran yang diberikan.

### Case studies
#### Case 1 (t07_01.c, 20 points)
Berikut adalah contoh masukan yang diberikan.
```
create-student#12S20999#Wiro Sableng#2020#Information Systems
print-students
create-student#12S20998#Jaka Sembung#2020#Information Systems
print-students
---

```
Berikut adalah keluaran yang diharapkan.
```
12S20999|Wiro Sableng|2020|Information Systems|0.00
12S20999|Wiro Sableng|2020|Information Systems|0.00
12S20998|Jaka Sembung|2020|Information Systems|0.00

```
#### Case 2 (t07_02.c, 20 points)
Berikut adalah contoh masukan yang diberikan.
```
create-student#12S20999#Wiro Sableng#2020#Information Systems
print-students
create-student#12S20998#Jaka Sembung#2020#Information Systems
print-students
create-course#12S1102#Visual Programming#2#D
print-courses
create-course#10S1002#Procedural Programming#2#C
print-courses
print-students
print-courses
---

```
Berikut adalah keluaran yang diharapkan.
```
12S20999|Wiro Sableng|2020|Information Systems|0.00
12S20999|Wiro Sableng|2020|Information Systems|0.00
12S20998|Jaka Sembung|2020|Information Systems|0.00
12S1102|Visual Programming|2|D
12S1102|Visual Programming|2|D
10S1002|Procedural Programming|2|C
12S20999|Wiro Sableng|2020|Information Systems|0.00
12S20998|Jaka Sembung|2020|Information Systems|0.00
12S1102|Visual Programming|2|D
10S1002|Procedural Programming|2|C

```
#### Case 3 (t07_03.c, 20 points)
Berikut adalah contoh masukan yang diberikan.
```
create-student#12S20999#Wiro Sableng#2020#Information Systems
print-students
create-student#12S20998#Jaka Sembung#2020#Information Systems
print-students
create-course#12S1102#Visual Programming#2#D
print-courses
create-course#10S1002#Procedural Programming#2#C
print-courses
print-students
find-student-by-id#12S20998
print-courses
find-student-by-id#12S20999
---

```
Berikut adalah keluaran yang diharapkan.
```
12S20999|Wiro Sableng|2020|Information Systems|0.00
12S20999|Wiro Sableng|2020|Information Systems|0.00
12S20998|Jaka Sembung|2020|Information Systems|0.00
12S1102|Visual Programming|2|D
12S1102|Visual Programming|2|D
10S1002|Procedural Programming|2|C
12S20999|Wiro Sableng|2020|Information Systems|0.00
12S20998|Jaka Sembung|2020|Information Systems|0.00
12S20998|Jaka Sembung|2020|Information Systems|0.00
12S1102|Visual Programming|2|D
10S1002|Procedural Programming|2|C
12S20999|Wiro Sableng|2020|Information Systems|0.00

```
#### Case 4 (t07_04.c, 20 points)
Berikut adalah contoh masukan yang diberikan.
```
create-student#12S20999#Wiro Sableng#2020#Information Systems
print-students
create-student#12S20998#Jaka Sembung#2020#Information Systems
print-students
create-course#12S1102#Visual Programming#2#D
print-courses
create-course#10S1002#Procedural Programming#2#C
print-courses
print-students
find-student-by-id#12S20998
print-courses
find-student-by-id#12S20990
find-course-by-code#10S1002
find-course-by-code#10S1000
find-student-by-id#12S20999
find-course-by-code#12S1102
---

```
Berikut adalah keluaran yang diharapkan.
```
12S20999|Wiro Sableng|2020|Information Systems|0.00
12S20999|Wiro Sableng|2020|Information Systems|0.00
12S20998|Jaka Sembung|2020|Information Systems|0.00
12S1102|Visual Programming|2|D
12S1102|Visual Programming|2|D
10S1002|Procedural Programming|2|C
12S20999|Wiro Sableng|2020|Information Systems|0.00
12S20998|Jaka Sembung|2020|Information Systems|0.00
12S20998|Jaka Sembung|2020|Information Systems|0.00
12S1102|Visual Programming|2|D
10S1002|Procedural Programming|2|C
10S1002|Procedural Programming|2|C
12S20999|Wiro Sableng|2020|Information Systems|0.00
12S1102|Visual Programming|2|D

```

## Submission
1. academic.c
2. t07_01.c
3. t07_02.c
4. t07_03.c
5. t07_04.c
6. changelog.txt

## How to submit?
Please see https://youtu.be/g0BQ195-aWo