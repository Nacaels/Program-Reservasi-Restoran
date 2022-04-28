#include<iostream>
using namespace std;

// prototye prosedur
void tambah();
void lihat();
void ubah();
void hapus();
void exit();

// deklarasi struct data reservasi dengan isi variabel nomor antrian, nomor meja, jumlah tamu, dan jam reservasi
struct data{
	int nomor;
	int meja;
	int tamu;
	float time;
};

// deklarasi variabel global
int pilihan, jumlahData, pilihanUbah, dataUbah, ubahNomor, ubahMeja, ubahTamu, dataHapus, i, j;
string tanyaUlang, tanggal;
float ubahTime;

// deklarasi array struct dengan jumlah 10 data
data dt[10];

int main(){
    // berfungsi untuk meng-clear layar output, agar output program tidak menumpuk dan terlihat rapi
	system("cls");
	cout << " == PROGRAM PENDATAAN RESERVASI MEJA DI RESTORAN ==" << endl;
	cout << endl;
	cout << " =========== MENU ===========" << endl;
	cout << " [1] Tambah data reservasi" << endl;
	cout << " [2] Lihat data reservasi" << endl;
	cout << " [3] Ubah data reservasi" << endl;
	cout << " [4] Hapus data reservasi" << endl;
	cout << " [5] Exit" << endl;
	cout << " Masukkan pilihan anda : "; cin >> pilihan;
	
	if (pilihan == 1){
		// jika user memilih menu 1 maka akan masuk ke opsi menambah data
		system("cls");
		cout << "\t======== TAMBAH DATA RESERVASI ========" << endl;
		//cout << endl;
		cout << "=======================================================" << endl;
		cout << " !!! DALAM 1 HARI HANYA TERSEDIA 10 SLOT RESERVASI !!!" << endl;
		cout << "=======================================================" << endl;
		cout << endl;
		cout << " Tanggal reservasi : "; cin >> tanggal;
		cout << "===================================" << endl;
		cout << " Masukkan Jumlah Data : "; cin >> jumlahData;
		
		tambah();
        // memanggil prosedur tambah array struct untuk melakukan inputan data
		while (j < 1){
			// melakukan perulangan untuk menanyakan user apakah ingin menambah data lagi atau tidak
			cout << " Ingin menambah data lagi?" << endl;
			cout << " [y]Ya/[t]Tidak : "; cin >> tanyaUlang;
			
			if (tanyaUlang == "y"){
				// jika user memilihh ya maka akan berlanjut lagi
				continue;
                // continue kurang lebih sama seperti break, break mengakhiri perulangan sedangkan continue melanjutkan perulangan
			} else {
				// jika user memilih tidak maka akan keluar dari perulangan dan kembali ke fungsi main
				main();
			}
		break;  // menggunakan break agar tidak terjadi perulangan terus-menerus
		}
		
	} else if (pilihan == 2){
		// jika user memilih menu 2 maka akan masuk ke opsi melihat data
		lihat();
		cout << endl;
		system("pause");
        // untuk memberikan jeda agar output program tidak langsung ke step selanjutnya, sampai user memasukkan sembarang inputan
		main();
		
	} else if (pilihan == 3){
		// jika user memilih menu 3 maka akan masuk ke opsi mengubah data
		ubah();
		
	} else if (pilihan == 4){
		// jika user memilih menu 4 maka akan masuk ke opsi menghapus data
		hapus();
		
	} else if (pilihan == 5){
		// jika user memilih menu 5 maka akan masuk ke opsi exit/keluar dari program
		exit();
		
	} else {
        system("cls");
		// jika user memilih menu selain menu 1, 2, 3, 4, dan 5 maka akan masuk ke opsi else yang akan menampilkan output sebegai berikut dan kembali ke fungsi main
		cout << endl;
		cout << "===========================================" << endl;
		cout << "\tPILIHAN ANDA TIDAK TERSEDIA" << endl;
		cout << "===========================================" << endl;
		system("pause");
		main();
	}
}

void tambah(){
	system("cls");
    cout << "=======================================================" << endl;
	cout <<  "\tTanggal Reservasi : " << tanggal << endl;
    // menampilkan tanggal reservasi yang sudah diinputkan sebelumnya
    cout << "=======================================================" << endl;
	cout << endl;
	
	for (i=0; i < jumlahData; i++){
        // untuk menambahkan data secara berulang-ulang, sehingga data yang dimasukkan sesuai dengan sebanyak data yang user inginkan
		cout << " Data ke " << i+1 /*agar var i yang ditampilkan dimulai dari angka 1*/ << endl;
		cout << " Masukkan nomor antrian  : "; cin >> dt[i].nomor;
        // memasukkan inputan nomor antrian kedalam array struct nomor
		cout << " Masukkan nomor meja     : "; cin >> dt[i].meja;
        // memasukkan inputan nomor meja kedalam array struct meja
		cout << " Masukkan jumlah tamu    : "; cin >> dt[i].tamu;
        // memasukkan inputan jumlah tamu kedalam array struct tamu
		cout << " Masukkan jam reservasi  : "; cin >> dt[i].time;
        // memasukkan inputan jam reservasi kedalam array struct time
		cout << endl;
	}
}

void lihat(){
	system("cls");
	cout << "\t======== LIST DATA RESERVASI ========" << endl;
    cout << "=======================================================" << endl;
	cout << "\tTanggal reservasi : " << tanggal << endl;
    // menampilkan tanggal reservasi yang sudah diinputkan sebelumnya
	cout << "=======================================================" << endl;
	
	for (i=0; i < jumlahData; i++){
        // untuk menampilkan data secara berulang-ulang, sehingga data yang ditampilkan sesuai dengan banyaknya data yang ada
		cout << endl;
		cout << "=========================" << endl;
		cout << "\tData ke " << i+1 << endl;
		cout << "=========================" << endl;
		cout << " Nomor Antrian  : " << dt[i].nomor << endl;
        // menampilkan nomor antrian dengan memanggil array struct nomor
		cout << " Nomor meja     : " << dt[i].meja << endl;
        // menampilkan nomor meja dengan memanggil array struct meja
		cout << " Jumlah tamu    : " << dt[i].tamu << endl;
        // menampilkan jumlah tamu dengan memanggil array struct tamu
		cout << " Jam reservasi  : " << dt[i].time << endl;
        // menampilkan jam reservasi dengan memanggil array struct time
	}
}

void ubah(){
	system("cls");
	cout << " ==== MENGUBAH DATA RESERVASI ====" << endl;
	cout << endl;
	lihat();
    // menampilkan list data reservasi yang sudah diinputkan agar memudahkan user memilih data yang ingin diubah
	cout << endl;
	cout << "==============================================" << endl;
	cout << " Masukkan nomor data yang ingin diubah : "; cin >> dataUbah;
    // menginputkan nomor data yang ingin dihapus
	cout << "==============================================" << endl;
	cout << endl;
	
	// menginpukan nomor antrian, nomor meja, jumah tamu, dan jam reservasi baru
	cout << " Masukkan nomor antrian baru  : "; cin >> ubahNomor; 
    // menyimpan nomor antrian yang baru kedalam variabel ubahNomor
	dt[dataUbah-1].nomor = ubahNomor;
    // lalu memasukkan kembali nilai ubahNomor kedalam array struct nomor pada index yang user pilih sebelumnya
	
	cout << " Masukkan nomor meja baru     : "; cin >> ubahMeja;
    // menyimpan nomor meja yang baru kedalam variabel ubahMeja
	dt[dataUbah-1].meja = ubahMeja;
    // lalu memasukkan kembali nilai ubahMeja kedalam array struct meja pada index yang user pilih sebelumnya
	
	cout << " Masukkan jumlah tamu baru    : "; cin >> ubahTamu;
    // menyimpan jumlah tamu yang baru kedalam variabel ubahTamu
	dt[dataUbah-1].tamu = ubahTamu;
    // lalu memasukkan kembali nilai ubahTamu kedalam array struct tamu pada index yang user pilih sebelumnya
	
	cout << " Masukkan jam reservasi baru  : "; cin >> ubahTime;
    // menyimpan jam reservasi yang baru kedalam variabel ubahTime
	dt[dataUbah-1].time = ubahTime;
    // lalu memasukkan kembali nilai ubahTime kedalam array struct time pada index yang user pilih sebelumnya
	cout << endl;
	cout << "============================" << endl;
	
	// melakukan perulangan untuk menanyakan user apakah ingin mengubah data lagi atau tidak
	while (j < 1) {
		cout << " ingin mengubah data lagi?" << endl;
		cout << " [y]Ya/[t]Tidak : "; cin >> tanyaUlang;
		
		if (tanyaUlang == "y"){
			continue;
		} else {
			main();
		}
	break;
	}
}

void hapus(){
	system("cls");
	cout << " ==== MENGHAPUS DATA RESERVASI ====" << endl;
	cout << endl;
	lihat();
	// menampilkan list data reservasi yang sudah diinputkan agar memudahkan user memilih data yang ingin dihapus
	cout << endl;
	cout << " Masukkan nomor antrian yang ingin dihapus : "; cin >> dataHapus;
	// menginputkan nomor antrian yang ingin dihapus
	cout << "============================================" << endl;
	
	// perulangan untuk mencari nomor antrian pada array struct nomor
	for (i=0; i < jumlahData; i++){
		if (dt[i].nomor == dataHapus){
			dt[i] = dt[i+1];
			// jika ketemu maka data ke i akan dihapus dan diganti dengan data setelah index yang dihapus
			jumlahData--;
			// jumlah data akan berkurang 1 karena data telah berhasil dihapus
		}
	}
	
	system("cls");
	cout << "=======================" << endl;
	cout << " Data berhasil dihapus" << endl;
	// menampilakn output berikut untuk memberi tahu user jika data berhasil dihapus
	cout << "=======================" << endl;
	system("pause");
	
	lihat();
	cout << endl;
	cout << "============================" << endl;
	
	// melakukan perulangan untuk menanyakan user apakah ingin menghapus data lagi atau tidak
	while (j < 1){
		cout << " ingin menghapus data lagi?" << endl;
		cout << " [y]Ya/[t]Tidak : "; cin >> tanyaUlang;
			
			if (tanyaUlang == "y"){
				continue;
			} else {
				main();
			}
		break;
	}
}

void exit(){
	system("cls");
	cout << endl;
	cout << "======================================================" << endl;
	cout << "\tTERIMA KASIH TELAH MENGGUNAKAN PROGRAM" << endl;
	cout << "======================================================" << endl;
}
