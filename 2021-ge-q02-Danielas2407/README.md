## Academic Simulation: The Final Showdown
Dari perspektif fungsionalitas, Academic Simulator garapan Ucok dan Butet, sahabat selamanya. Dengan penuh sukacita mereka menunjukkan maha karya tersebut pada sang Dosen Pemrograman yang menginisiasi pengembangan simulator. Ucok berpendapat bahwa simulator sudah sempurna dan dapat dirilis sehingga bisa digunakan khalayak.

Setelah beberapa waktu menganalisis, sang Dosen menolak lantaran menemukan adanya kemungkinan redundansi (duplikasi) data. Sang Dosen memberikan contoh masukkan sebagai berikut:
```
create-student#12S20999#Wiro Sableng#2020#Information Systems
create-student#12S20998#Jaka Sembung#2020#Information Systems
print-students
create-student#12S19888#Milkyman#2019#Informatika
create-student#12S20998#Jaka Sembung#2020#Information Systems
print-students
create-student#12S19887#Petrik Starfish#2019#Informatika
print-students
---

```
Solusi saat ini belum mampu mendeteksi adanya data berulang, misal untuk mahasiswa dengan ```id``` ```12S20998``` atas nama ```Jaka Sembung```. Menurut sang Dosen hal ini dapat memicu inkonsistensi. Kemudian, Ucok dan Butet disarankan untuk turut memeriksa persoalan serupa pada dua entitas lainnya, ```course``` dan ```enrollment```.

Dalam rangka memberi arahan, sang Dosen mengambil secarik kertas dan menjabarkan pentingnya menjaga keunikan data pada suatu kumpulan entitas. Penjaminan keunikan ditentukan oleh satu atau lebih kombinasi nilai, yang pada domain ilmu basis data disebut dengan ```primary key```. Melihat Ucok dan Butet geleng-geleng dan saling menatap, sang Dosen pun paham bahwa mereka berdua tidak mengerti apa yang ia maksud. Sang Dosen kemudian meneruskan dengan contoh, untuk entitas ```student```, nilai dari atribut ```id``` adalah nilai penentu keunikan. Artinya, seorang mahasiswa dapat dibedakan dari mahasiswa lainnya jika memiliki ```id``` yang berbeda. Dua orang mahasiswa dengan ```id``` berbeda bisa saja memiliki ```nama```, ```tahun masuk```, dan berada pada ```prodi``` yang sama. Ucok dan Butet pulai mengangguk pendek.

Sang Dosen melanjutkan, untuk entitas ```course```, atribut unik yang harus dijaga adalah ```code```. Untuk entitas ```enrollment``` agak sedikit berbeda karena tidak ditemukan satupun atribut yang mampu digunakan untuk menjamin keunikan sebuah ```enrollment```. Untuk menjaga keunikan, entitas enrollment harus menggunakan kombinasi beberapa atribut sekaligus, konsep ini disebut "composite key". Jika diamati, sebuah enrollment harus menggunakan kombinasi ```student-id```, ```course-code```, ```year```, dan ```semester``` bersamaan. Artinya duplikasi data ditentukan dari keempat atribut tersebut. Saran sang Dosen, proses pendaftaran harus dibatalkan ketika diketahui ditemukan redundansi data.

Melanjutkan analisisnya, sang Dosen juga menyampaikan satu temuan lainnya. Berikut adalah contoh masukan yang diberikan.
```
create-student#12S20999#Wiro Sableng#2020#Information Systems
create-student#12S20998#Jaka Sembung#2020#Information Systems
print-students
create-student#12S19888#Milkyman#2019#Informatika
create-student#12S20998#Jaka Sembung#2020#Information Systems
print-students
create-student#12S19887#Petrik Starfish#2019#Informatika
print-students
create-course#12S1102#Visual Programming#2#D
create-course#TIS1101#Digital Innovation#2#D
print-courses
create-course#10S1002#Procedural Programming#2#C
create-course#TIS1101#Digital Innovation#2#D
create-course#12S1102#Visual Programming#2#D
print-courses
create-enrollment#12S1102#12S20999#2020-2021#odd
create-enrollment#12S1102#12S20999#2020-2021#even
create-enrollment#12S1102#12S20998#2020-2021#odd
create-enrollment#TIS1101#12S20999#2020-2021#odd
create-enrollment#TIS1101#12S20998#2020-2021#odd
print-enrollments
create-enrollment#10S1999#12S20999#2020-2021#even
print-enrollments
create-enrollment#TIS1101#12S19800#2020-2021#even
create-enrollment#TIS1101#12S19887#2020-2021#even
print-enrollments
---

```
Persoalan dari kasus di atas terdapat kesalahan pada saat mendaftarkan ```enrollment``` dengan ```course-code``` ```10S1999```. ```Course``` tersebut tidak pernah terdaftar sebelumnya pada simulator. Ucok dan Butet harus memproteksi simulator mereka agar membatalkan proses pendaftaran jika salah satu dari ```student``` dan ```course``` tidak ditemukan pada simulator.

Setelah paham betul tentang tantangan tersebut, Ucok dan Butet pun langsung menyusun langkah-langkah perbaikan. Berikut penjabarannya:
1. Mengembangkan mekanisme pemeriksaan redundansi data pada entitas ```student``` berdasarkan ```id```-nya (```q02_01.c```).
2. Mengembangkan mekanisme pemeriksaan redundansi data pada entitas ```course``` berdasarkan ```code```-nya (```q02_02.c```).
3. Mengembangkan mekanisme pemeriksaan redundansi data pada entitas ```enrollment``` berdasarkan kombinasi ```student-id```, ```course-code```, ```year```, dan ```semester``` (```q02_03.c```).
4. Mengembangkan mekanisme pemeriksaan eksistensi data ```course``` dan ```student``` pada saat mendaftarkan sebuah ```enrollment``` (```q02_04.c```).
Simulator harus membatalkan proses untuk setiap kegagalan pemenuhan syarat pemeriksaan di atas dan melanjutkan ke baris perintah berikutnya hingga ditemukan triple dash signs ```(---```).

### Note
Anda tidak diizinkan untuk memodifikasi berkas ```academic.h```. Bila diperlukan, ada dapat mendefinisikan structure, enumeration, atau fungsi lain yang dirasa perlu pada ```custom.h``` dan ```custom.c```.

## Submission
1. academic.c
2. q02_0*.c
3. changelog.txt

## How to submit?
Please see https://youtu.be/g0BQ195-aWo