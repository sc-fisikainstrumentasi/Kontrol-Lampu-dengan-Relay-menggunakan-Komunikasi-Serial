
/*SC-FISIKA INSTRMENTASI UIN SUKA
 Note : 
 a. Perhatikan Setiap penjelasan progam
 b. penjelasan progam diawali dengan tanda "//"
 c. penjelasan progam bukan bagian dari skecth progam yang akan di jalankan

 PROYEK : Komunikasi Serial Arduino Menyalaan Lampu dengan Relay
 
*/

int Relay = 13; //memberikan variable pada pin 13 dengan nama Relay


//fungsi void setup untuk mendelarasikan pin pada arduino & menjalankan progam sekali
void setup()
{
    pinMode(Relay, OUTPUT);//mendelarasikan Relay sebagai OUTPUT
    Serial.begin(9600); //untuk menentukan kecepatan pengiriman dan penerimaan data melalui port serial(9600 bit per detik (bps))

}


//fungsi void loop untuk menjalankan progam berulangkali
void loop() 
{
  if (Serial.available())//Untuk mengecek apakah data sudah ada di buffer penerima
    {
      if (Serial.parseInt() == 1)//membuat code dalam bentuk angka 1 untuk menyalaan lampu
        {
          digitalWrite(Relay, HIGH);//Memberi Relay tegangan Max (5 Volt)
          Serial.println("Command completed Lampu turned ON"); //mengirim data string tersebut ke Serial Monitor
        }

      else if (Serial.parseInt()== 2)//membuat code dalam bentuk angka 2 untuk Mematikan Lampu
        {
          digitalWrite(Relay, LOW);//Memberi Relay tegangan Min (0 Volt)
          Serial.println("Command completed Lampu turned OFF");//mengirim data string tersebut ke Serial Monitor

        }
    }

}

/*
Fungsi-Fungsi Komuniasi Serial ARDUINO

if (Serial) : Untuk mengecek apakah Port sudah siap
Serial.available() : Untuk mengecek apakah data sudah ada di buffer penerima
Serial.begin() : untuk mengeset kecepatan transmisi data
Serial.end() : Untuk menon-aktifkan pin rx dan tx sbg fungsi serial dan kembali sbg pin I/O
Serial.find() : mencari string dlm buffer data
Serial.findUntil(): mencari buffer data sampai data dgn panjang/terminator nya yg diberikan ditemukan
Serial.flush(): menunggu data terkirim semua
Serial.parseFloat(): mengambil data float pertama dari data di buffer serial.
Serial.parseInt(): mengambil data integer pertama dari data di buffer serial.
Serial.peek(): mengambil data berikutnya di bufer penerima
Serial.print() : mengirim data ASCII
Serial.println() : mengirimdata ASCII + CR,LF (kode enter)
Serial.read(): membaca data yg diterima
Serial.readBytes(): membaca data byte yg diterima
Serial.readBytesUntil()
Serial.setTimeout(): mengeset batas maksimum waktu  tunggu(timeout)  transmisi data.
Serial.write() : mengirim data byte (numerik)
Serial.serialEvent(): fungsi ini akan dipanggil jika data datang/diterima.berlaku spt interupsi serial.

*/
