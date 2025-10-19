# Robot AiO (All in One)
### BAB III Praktikum Robotika

<div align="center">

![Banner](https://github.com/ElectroBoi/BAB-3-2526/blob/main/images/Banner.png)

[![Arduino](https://img.shields.io/badge/Arduino-Nano-00979D?style=for-the-badge&logo=arduino&logoColor=white)](https://www.arduino.cc/)
[![HC-05](https://img.shields.io/badge/Bluetooth-HC--05-blue?style=for-the-badge)](https://components101.com/wireless/hc-05-bluetooth-module)
[![HC-SR04](https://img.shields.io/badge/Ultrasonic-HC--SR04%2F05-orange?style=for-the-badge)](https://www.handsontec.com/dataspecs/HC-SR04-Ultrasonic.pdf)

</div>

---

## 📋 Deskripsi Proyek

Robot **AiO (All in One)** adalah wheeled robot dengan sistem penggerak dua roda dan satu roda *idler* (tanpa penggerak) pada bagian depan. Robot ini dilengkapi dengan PCB terintegrasi untuk mendukung berbagai modul seperti:

- Bluetooth (HC-05) untuk kontrol jarak jauh
- Sensor Ultrasonik (HC-SR04/05) untuk deteksi rintangan
- Sensor Inframerah untuk line following

---

## 🔌 Konfigurasi Pin Arduino Nano

### Skematik Robot

![Skematik](https://github.com/ElectroBoi/BAB-3-2526/blob/main/images/Schematic.png)

### Pin Connections Table

| **Modul** | **Pin Modul** | **Pin Arduino Nano** |
|:----------|:--------------|:---------------------|
| **L298N Motor Driver** | ENA | `D5` |
| | IN1 | `D3` |
| | IN2 | `D4` |
| | IN3 | `D2` |
| | IN4 | `D7` |
| | ENB | `D6` |
| **Ultrasonik Depan** | ECHO | `D10` |
| | TRIG | `D11` |
| **Ultrasonik Kiri** | ECHO | `D9` |
| | TRIG | `D8` |
| **Ultrasonik Kanan** | ECHO | `D13` |
| | TRIG | `D12` |
| **Bluetooth HC-05** | TX | `D15` |
| | RX | `D16` |

---

## 🛠️ Percobaan & Panduan

### [Percobaan 1] Perakitan Komponen Robot

<table>
<tr>
<td width="50%">

**Top View**

![Top View](https://github.com/ElectroBoi/BAB-3-2526/blob/main/images/look%20top.png)

</td>
<td width="50%">

**Back View**

![Back View](https://github.com/ElectroBoi/BAB-3-2526/blob/main/images/lookback.png)

</td>
</tr>
</table>

#### Langkah Perakitan:

1. Pasang mikrokontroler menghadap ke atas pada PCB
2. Pasang modul HC-05 menghadap ke atas pada PCB
3. Pasang sensor HC-SR04/05 menghadap keluar pada PCB
4. Check penempatan setiap modul (verifikasi pada asisten terlebih dahulu sebelum robot dinyalakan!)

---

### [Percobaan 2] Kontrol Bluetooth dengan HC-05

Kendalikan robot secara nirkabel menggunakan smartphone Anda.

#### Langkah Kerja:

1. Pastikan modul Bluetooth terpasang dengan benar
2. Hubungkan mikrokontroler ke komputer via kabel Micro USB
3. Buka Arduino IDE
4. Upload program kontrol Bluetooth
5. Download dan install aplikasi **Bluetooth Controller MIT**
6. Aktifkan Bluetooth di smartphone
7. Buka aplikasi Bluetooth Controller MIT
8. Tekan **"Speech Language"** dan pilih bahasa **(id) Indonesia** atau **(en) English**
9. Tekan **"Connect"** dan pilih modul Bluetooth robot
10. Gunakan **D-pad** untuk kontrol manual atau **tombol mic** untuk perintah suara

#### Download Resources:

<div align="center">

[![Kode Program](https://img.shields.io/badge/Kode_Program_BT-Download-blue?style=for-the-badge)](https://github.com/ElectroBoi/BAB-3-2526/blob/main/Program/Bluetooth.ino)
[![Aplikasi BT](https://img.shields.io/badge/Aplikasi_BT-Download-green?style=for-the-badge)](https://drive.google.com/file/d/139XglMQmpKbAmF9NAKJcPuc5kbBICK5A/view)

</div>

---

### [Percobaan 3] Mode Wall Follower

Robot akan mengikuti dinding menggunakan sensor ultrasonik.

#### Langkah Kerja:

1. Pastikan modul ultrasonik terpasang dengan benar
2. Hubungkan mikrokontroler ke komputer via kabel Micro USB
3. Buka Arduino IDE
4. Upload program Wall Follower
5. Upload program ke Arduino Nano
6. Pasang baterai pada robot
7. Letakkan robot di arena Wall Follower
8. Nyalakan switch dan lihat robot beraksi

#### Download Resources:

<div align="center">

[![Kode Program WF](https://img.shields.io/badge/Kode_Program_WF-Download-orange?style=for-the-badge)](https://github.com/ElectroBoi/BAB-3-2526/blob/main/Program/WF.ino)

</div>

---

### [Percobaan 4] Mode Line Follower

Robot akan mengikuti garis hitam menggunakan sensor inframerah.

#### Langkah Kerja:

1. **Kalibrasi sensor**: Pastikan sensor IR dapat mendeteksi jalur hitam. Jika belum terdeteksi, putar **varistor** (komponen kotak biru) pada robot
2. Hubungkan mikrokontroler ke komputer via kabel Micro USB
3. Buka Arduino IDE
4. Upload program Line Follower
5. Upload program ke Arduino Nano
6. Pasang baterai pada robot
7. Letakkan robot di arena Line Follower
8. Nyalakan switch dan lihat robot mengikuti garis

#### Download Resources:

<div align="center">

[![Kode Program LF](https://img.shields.io/badge/Kode_Program_LF-Download-red?style=for-the-badge)](https://github.com/ElectroBoi/BAB-3-2526/blob/main/Program/LineFollower.ino)

</div>

---

## 🎯 Percobaan Mandiri

### [Mandiri 1] Mode Switching dengan Button

**Tantangan:** Buat program untuk mengganti mode operasi robot menggunakan tombol pada **pin A6**.

**Mode yang tersedia:**
- Bluetooth Controller
- Line Follower
- Wall Follower

**Requirement:** Setiap mode harus memiliki **indikator LED** dengan pola kedip berbeda.

> **Contoh pola kedip:**
> - Bluetooth: LED kedip 1 detik
> - Line Follower: LED kedip ½ detik
> - Wall Follower: LED kedip ¼ detik

<div align="center">

[![Contoh PM1](https://img.shields.io/badge/Contoh_Kode_PM1-View-purple?style=for-the-badge)](https://github.com/ElectroBoi/BAB-3-2526/blob/main/Program/ContohPM1.ino)

</div>

---

### [Mandiri 2] Bluetooth + Wall Detection (BONUS)

**Tantangan:** Buat program kontrol Bluetooth dengan **sistem deteksi dinding otomatis**.

**Fitur yang diharapkan:**
- Kontrol robot via Bluetooth seperti biasa
- Robot **berhenti otomatis** jika mendeteksi dinding di depan
- Kombinasi kontrol manual dengan safety system

<div align="center">

[![Contoh PM2](https://img.shields.io/badge/Contoh_Kode_PM2-View-gold?style=for-the-badge)](https://github.com/ElectroBoi/BAB-3-2526/blob/main/Program/contohPM2.ino)

</div>

---

## 🛠️ Komponen yang Digunakan

| Komponen | Deskripsi |
|----------|-----------|
| Arduino Nano | Mikrokontroler utama |
| L298N Motor Driver | Pengendali motor DC |
| HC-05 | Modul Bluetooth |
| HC-SR04/05 (3x) | Sensor ultrasonik |
| Sensor IR + PCF8574T | Sensor inframerah dengan I2C expander |
| Baterai | Power supply untuk robot |
| Switch | On/Off robot |
| Custom PCB | Board integrasi semua komponen |

---

## 📚 Resources & Links

- [Repository Lengkap](https://github.com/ElectroBoi/BAB-3-2526)
- [Folder Program](https://github.com/ElectroBoi/BAB-3-2526/tree/main/Program)
- [Folder Images](https://github.com/ElectroBoi/BAB-3-2526/tree/main/images)

---

## 📄 Lisensi

Project ini dibuat untuk keperluan **praktikum robotika**. Silakan gunakan dan modifikasi sesuai kebutuhan pembelajaran.

---

<div align="center">

**Pusat Studi. Multimedia dan Robotika**


</div>
