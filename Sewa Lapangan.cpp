#include <iostream>
#include <fstream>
#include <cstdlib> 

using namespace std;

void inputData(string &nama, string &hari, int &lama_sewa, string &booking) {
    cout << "Masukkan nama            : ";
    cin >> nama;
    cout << "Masukkan hari            : ";
    cin >> hari;
    cout << "Masukkan lama waktu sewa (hanya angka)): " ;
    cin >> lama_sewa  ;
    cout << "Masukkan jam waktu main  : ";
    cin >> booking;
}

void simpanData(string nama, string hari, int lama_sewa, string booking, int total_bayar) {
    ofstream file("data_pemesanan.txt" , ios::app); // Membuka file untuk menambahkan data 
    if (file.is_open()) {
        file << "Nama           : " << nama << endl;
        file << "Hari           : " << hari << endl;
        file << "Jam waktu main : " << booking << endl;
        file << "Lama booking   : " << lama_sewa << " jam" << endl;
        file << "Total bayar    : " << total_bayar << endl;
        file << "=================" << endl;
        file.close();
    } else {
        cout << "Gagal membuka file untuk penyimpanan data." << endl;
    }
}

int main() {
    string nama, hari, booking;
    int pil, lama_sewa;
    char ulang;
    int harga[5] = {100000, 150000, 80000, 100000, 150000};

    do {
    cout << "SELAMAT DATANG DI TEMPAT OLAHRAGA TERBESAR" << endl;
    cout << "=========================================" << endl;
    cout << "====== PENYEWAAN LAPANGAN OLAHRAGA ======" << endl;
    cout << "=========================================" << endl;

    cout << endl;
    ulang:
    cout << "Silahkan memilih lapangan yang akan disewa" << endl;
    cout << "=========================================" << endl;
    cout << "| 1. BASKET       100.000/jam           |" << endl;
    cout << "| 2. FUTSAL       150.000/jam           |" << endl;
    cout << "| 3. BADMINTON    80.000 /jam           |" << endl;
    cout << "| 4. VOLI         100.000/jam           |" << endl;
    cout << "| 5. TENNIS       150.000/jam           |" << endl;
    cout << "| 6. TIDAK JADI BOOKING/KELUAR PROGRAM  |" << endl;
    cout << "=========================================" << endl;

    cout << endl;
    cout << "Masukkan pilihan sesuai nomor: ";
    cin >> pil;

    system("cls");

    if (pil >= 1 && pil <= 5) {
        cout << "=================================" << endl;
        cout << "Anda akan menyewa lapangan ";
        switch (pil) {
            case 1:
                cout << "basket" << endl;
                break;
            case 2:
                cout << "futsal" << endl;
                break;
            case 3:
                cout << "badminton" << endl;
                break;
            case 4:
                cout << "voli" << endl;
                break;
            case 5:
                cout << "tenis" << endl;
                break;
        }
        cout << "=================================" << endl;
        cout << "Harga " << harga[pil - 1] << "/jam" << endl;

        cout << "Silahkan masukkan data diri anda" << endl;
        inputData(nama, hari, lama_sewa, booking);
        system ("cls");
        cout << "=================" << endl;
        cout << "Data diri anda  " << endl;
        cout << "=================" << endl;
        cout << "Nama           : " << nama << endl;
        cout << "Hari           : " << hari << endl;
        cout << "Jam waktu main : " << booking << endl;
        cout << "Lama booking   : " << lama_sewa << " jam" << endl;

        int total_bayar = lama_sewa * harga[pil - 1];
        int no_uang;
        cout << "=================================" << endl;
        cout << "| Silahkan melakukan pembayaran |" << endl;
        cout << "=================================" << endl;
        cout << "Total bayar : " << total_bayar << endl;
        cout << "=================================" << endl;
        cout << "nominal uang anda : "; cin >> no_uang;
        cout <<endl;
        cout << "kembalian : "<<no_uang - total_bayar <<endl;
        cout << "=========================================="<<endl;
        cout << "terima kasih , JUNJUNG TINGGI SPORTIVITAS"<<endl;

        // Menyimpan data pemesanan ke dalam file
        simpanData(nama, hari, lama_sewa, booking, total_bayar);
    } else if (pil == 6) {
        return 0;
    } else {
        cout << endl;
        cout << "=======================" << endl;
        cout << "| Pilihan tidak valid |" << endl;
        cout << "=======================" << endl;
        goto ulang;
    }
	cout << "Apakah anda ingin mengulang (y/t): ";cin >> ulang; 
	system("cls");
	}while (ulang != 'y'||'Y');
	
    return 0;
}

