Berikut adalah rangkaian komponen dari servocontrol.cpp:

![rangkaian](https://i.imgur.com/fAeoM45.png)

Cara kerja perangkat:
1. Sensor ultrasonik akan memancarkan sinyal dan menangkap kembali sinyal yang terpantul sehingga sensor tersebut akan mendeteksi sesuatu pada jarak tertentu
2. Ketika hasil bacaan sensor dibawah 10cm, maka servo tidak akan berputar
3. ketika hasil bacaan sensor diatas 10cm, maka servo akan berputar sesuai dengan besar bacaan sensor
4. Setiap hasil bacaan sensor merupakan kelipatan 2cm, servo akan berputar sebesar 10 derajat
