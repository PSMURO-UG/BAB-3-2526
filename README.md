
![Logo](https://github.com/ElectroBoi/BAB-3-2526/blob/main/images/Banner.png)
# Robot AiO (All in One) BAB III Praktikum Robotika

Robot berjenis wheeled robot dengan dua roda untuk mengontrol gerakan, dan satu roda *idler* (roda tanpa penggerak) pada bagian depan robot, yang dilengkapi dengan rangkaian PCB untuk integrasi dengan modul Bluetooth, sensor ultrasonik, dan sensor inframerah.

## Skematik Robot dan Koneksi Pin pada Arduino Nano
![Skematik](https://via.placeholder.com/468x300?text=App+Screenshot+Here)
- Light/dark mode toggle
- Live previews
- Fullscreen mode
- Cross platform


| **Nama Modul**|**Pin pada Modul**| **Pin pada Arduno Nano**|
| :-------- | :------- | :------------------------- |
| `api_key` | `string` | `string`|
| `api_key` | `string` | `string`|
| `api_key` | `string` | `string`|

## [Perc. 1] Rangakai Komponen pada Robot
**[*Top View*]**
![Penempatan Komponen Atas](https://github.com/ElectroBoi/BAB-3-2526/blob/main/images/look%20top.png)
**[*Back View*]**
![Penempatan Komponen Belakang](https://github.com/ElectroBoi/BAB-3-2526/blob/main/images/lookback.png)

**Langkah Kerja :**

    1. Pasangkan mikrokontroler menghadap atas dengan PCB
    2. Pasangkan Modul HC05 menghadap atas dengan PCB
    3. Pasangkan Sensor HCSR04 atau HCSR05 menghadap keluar dengan PCB
## [Perc. 2] Integrasi Kontrol Menggunakan Bluetooth (HC05)

**Langkah Kerja :**

    1. Pastikan Modul Bluetooth terpasang dengan benar
    2. Hubungkan mikrokontroler dengan komputer menggunakan kabel Micro USB
    3. Buka aplikasi Arduino IDE
    4. Ketikan program dibawah ini (Pastikan Program yang dituliskan Benar)
    
 **<** **[Kode Program BT](https://github.com/ElectroBoi/BAB-3-2526/blob/main/Program/Bluetooth.ino)** **>**
 **<** **[Aplikasi BT](https://drive.google.com/file/d/139XglMQmpKbAmF9NAKJcPuc5kbBICK5A/view)** **>**

    5. Download Aplikasi Bluetooth Controller MIT
    6. Menyalakan Bluetooth pada setting Smartphone
    7. Buka Aplikasi Bluetooth Controller MIT
    8. Tekan Tombol “Speech Language”, lalu pilih salah satu bahasa (id) Indonesia atau(en) English
    9. Tekan Tombol “Connect”, lalu Cari dan pilih Modul Bluetooth yang tersambung
    dengan Robot
    10. Tekan Tombol Dpad untuk mengontrol Robot atau tekan tombol mic untuk beri
    perintah gerakan pada robot AiO!

## [Perc. 3] Mode WallFollower menggunakan Sensor HCSR04 / HCSR05

**Langkah Kerja :**

    1. Pastikan Modul UltraSonik Terpasang dengan benar
    2. Hubungkan mikrokontroler dengan komputer menggunakan kabel Micro USB
    3. Buka aplikasi Arduino IDE
    4. Ketikan program dibawah ini (Pastikan Program yang dituliskan Benar)
    
 **<** **[Kode Program WF](https://github.com/ElectroBoi/BAB-3-2526/blob/main/Program/WF.ino)** **>**

****
    5. Upload Program pada Arduino Nano
    6. Masukan Baterai pada Robot AiO
    7. Masukan Robot pada arena WallFlower
    8. Nyalakan Switch pada robot AiO dan saksikan robot melewati rintangan!
## [Perc. 4] Mode LineFollower menggunakan Sensor Inframerah dan IC I2c PCF8574T

**Langkah Kerja :**

    1. Pastikan Sensor Inframerah dapat mendeteksi jalur hitam pada arena, 
       bila belum terdeteksi sensor dapat di kalibrasi dengan memutar Varistor 
       (Komponen kotak biru) pada robot
    2. Hubungkan mikrokontroler dengan komputer menggunakan kabel Micro USB
    3. Buka aplikasi Arduino IDE
    4. Ketikan program dibawah ini (Pastikan Program yang dituliskan Benar)

 **<** **[Kode Program LF](https://github.com/ElectroBoi/BAB-3-2526/blob/main/Program/LineFollower.ino)** **>**

***
    5. Upload Program pada Arduino Nano
    6. Masukan Baterai pada Robot AiO
    7. Masukan Robot pada arena LineFollower
    8. Nyalakan Switch pada robot AiO dan saksikan robot melewati rintangan!
    
## [Perc. Mandiri 1] Mengganti Mode dengan Button

Buatlah program untuk mengganti mode operasi robot antara Bluetooth Controller, Line Follower,
dan Wall Follower menggunakan tombol yang terdapat pada pin A6. Setiap mode harus memiliki
indikator LED dengan pola kedip yang berbeda!
(contoh: mode Bluetooth kedip 1 detik, mode Line Follower kedip ½ detik)

**<** **[Contoh Kode Program PM1](https://github.com/ElectroBoi/BAB-3-2526/blob/main/Program/contohPM2.ino)** **>**
## [Perc. Mandiri 2 (Bonus)] Kontrol Bluetooth dengan deteksi tembok

Buatlah program untuk kontrol robot menggunakan Bluetooth Controller yang dilengkapi dengan
sistem deteksi dinding. Apabila terdapat dinding di depan robot, robot akan berhenti secara
otomatis!

**<** **[Contoh Kode Program PM2](https://github.com/ElectroBoi/BAB-3-2526/tree/main)** **>**
