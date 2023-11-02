# PID-Kontrol-ID
Ini adalah library PID Kontrol yang dirancang untuk platform Arduino. Library ini memungkinkan Anda untuk mengimplementasikan kontrol PID (Proporsional-Integral-Derivative) dalam proyek Arduino Anda dengan mudah dengan function ber-bahasa indonesia.

## Daftar Isi

- [Fitur Utama](#fitur-utama)
- [Instalasi](#instalasi)
- [Penggunaan](#penggunaan)
- [Dokumentasi](#dokumentasi)
- [Kontribusi](#kontribusi)
- [Lisensi](#lisensi)

## Fitur Utama

- Mendukung kontrol PID dengan konstanta Kp, Ki, dan Kd yang dapat disesuaikan.
- Pengaturan rentang masukan dan keluaran.
- Kemampuan untuk mengatur setpoint kontrol.
- Mendukung waktu sampel untuk integral dan derivatif.
- Kontrol output dalam rentang yang ditentukan.

## Instalasi

Anda dapat menginstal library ini melalui Arduino Library Manager atau secara manual dengan mengunduh dan menyalinnya ke folder Arduino Library Anda.

### Instalasi melalui Arduino Library Manager

1. Buka Arduino IDE.
2. Pergi ke "Sketch" -> "Include Library" -> "Manage Libraries..."
3. Di dalam kotak "Library Manager," cari "PID Kontrol" dan pilih versi terbaru.
4. Klik "Install" untuk menginstal library.

### Instalasi Manual

1. Unduh repository ini.
2. Ekstrak berkas ZIP jika diperlukan.
3. Salin folder `PID_Kontrol` ke dalam folder `libraries` di direktori Arduino Anda.
4. Restart Arduino IDE jika sudah terbuka.

## Penggunaan

Impor library pada kode Anda:

`#include <PID_Kontrol.h>`

Inisialisasi objek PID_Kontrol:

`PID_Kontrol pid(Kp, Ki, Kd, SetPoint, InMin, InMax, OutMin, OutMax);`

Gunakan metode PID Kontrol untuk mengatur parameter dan perhitungan kontrol.

## Dokumentasi

`PID_Kontrol`

`PID_Kontrol(double Kp, double Ki, double Kd, double SetPoint, int InMin, int InMax, int OutMin, int OutMax)`
Membuat objek PID_Kontrol dengan parameter pengaturan awal.

`void mulai()`
Memulai kontrol PID.

`void setRange(int InMin, int InMax, int OutMin, int OutMax)`
Mengatur rentang masukan dan keluaran.

`void setSetPoints(double SetPoint)`
Mengatur setpoint kontrol.

`void setKonstanta(double Kp, double Kd, double Ki)`
Mengatur konstanta Kp, Kd, dan Ki.

`void setError(double Error)`
Mengatur nilai error.

`void setSampling(double Ti, double Td)`
Mengatur waktu sampel Ti dan Td.

`double kalkulasi(double Feedback)`
Menghitung keluaran kontrol berdasarkan umpan balik.

`double getOutput()`
Mengembalikan nilai keluaran saat ini.

`void reset()`
Mereset kontrol PID.

Contoh Penggunaan

Berikut adalah contoh penggunaan library ini:

```
#include <PID_Kontrol.h>

PID_Kontrol pid(1.0, 0.1, 0.01, 50, 0, 100, 0, 255);

void setup() {
  pid.mulai();
}

void loop() {
  double feedback = readSensorValue();
  double output = pid.kalkulasi(feedback);
  setMotorSpeed(output);
}

```
