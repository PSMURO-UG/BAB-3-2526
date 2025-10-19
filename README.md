
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
    ![Kode Program](https://github.com/ElectroBoi/BAB-3-2526/tree/main)
## [Perc. 3] Mode WallFollower menggunakan Sensor HCSR04 / HCSR05
## [Perc. 4] Mode LineFollower menggunakan Sensor Inframerah dan IC I2c PCF8574T
## [Perc. Mandiri 1] Mengganti Mode dengan Button
## [Perc. Mandiri 2 (Bonus)] Kontrol Bluetooth dengan deteksi tembok
