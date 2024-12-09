#include "Customer.h"
#include "Reservation.h"
#include "Bike.h"
#include "Owner.h"
#include "Admin.h"
//#include "Payment.h"
#include "Bike.cpp"
#include "Customer.cpp"
#include "Owner.cpp"
#include "Admin.cpp"
//#include "Payment.cpp"
#include <iostream>
#include <string>
#include <windows.h>
#include <sstream>
#include <cstdlib>  
#include <ctime> 
#include <fstream>

using namespace std;
static int save=0, sw, jam=0;
Bike myBike;

void Reservation::who_are_you(){
	int ang;
	setColor(23);
	cout<<"=========== RENTAL SEPEDA LISTRIK ============"<<endl<<endl;
	setColor(7);
	do{
	cout<<"Masuk sebagai :\n"<<"1. Owner\n"<<"2. Customer\n"<<"3. Admin\n"<<"4. Keluar\n"<<"Masukkan Angka : ";
	cin>>ang;
	system("cls");
	switch (ang){
            case 1:
                owe();
                break;
            case 2:
                cust();
                break;
            case 3:
                adm();
                break;
            default:
                cout<<"Keluar dari Program\n";
                break;
        }
        break;
    } while (ang >= 1 && ang <= 3);
    
}

void Reservation::adm(){
	string nama, email;
	int adminid;
	ofstream myFile;
	myFile.open("Adm.txt");
	cout<<"Masukkan data diri Anda\n";
	cout<<"Nama     : "; cin>>nama;
	cout<<"Admain ID : "; 
	cin>>adminid;
	cout<<"Email    : "; 
	cin>>email;
	
	if(email.find("@gmail.com")==-1){
		cout<<"Email yang Anda Masukkan Tidak Valid!\n";
		adm();
	}
	
	int msk;
	myFile << "Nama = " <<  nama << "\nAdmin ID = " << adminid << "\nEmail = " << email;
	Admin Admin(nama, email, adminid);
	myFile.close();
	cout<<"Registrasi Berhasil\n";
	system("cls");
	cout<<"Menambah Sepeda : \n"<<"(Masukan 1 = Ya, 0 = Tidak)\n";
	cin>>msk;
	system("cls");
	if(msk==0){
		cout<<"Kembali ke Menu Utama\n";
	}
	else{
		Admin.databike();
	}
	who_are_you();
}


void Reservation::owe(){
	ofstream own;
	own.open("Owner.txt");
	string nama;
	int id_own;
	string email;
	cout<<"Masukkan data diri Anda\n";
	cout<<"Nama     : ";
	cin>>nama;
	cout<<"Owner ID : "; 
	cin>>id_own;
	cout<<"Email    : ";
	cin>>email;
	
	if(email.find("@gmail.com")==-1){
		cout<<"Email yang Anda Masukkan Tidak Valid!\n";
		owe();
	}
	
	own << "Nama = "<<nama<<"\nOwner ID = "<<id_own<<"\nEmail = "<<email<<endl;
	own.close();
	 
	system("cls");
	cout<<"Sedang Memproses...\n";
	Sleep(1000);
	Owner::newowner(nama, email, id_own);
	system("cls");
	int no;
	cout<<"Registrasi Berhasil\n";
	Sleep(3000);
	system("cls");
	setColor(23);
	cout<<"======== Menu Utama ========\n";
	setColor(7);
	cout<<"1. Laporan Pemesanan"<<endl;
	cout<<"2. Halaman Utama"<<endl;
	cout<<"Masukkan Nomor = "; cin>>no;
	if(no == 1){
		if(Bike::res==0){
			cout<<"Reservasi Tidak Ditemukan!\n\n";
			who_are_you();
		}
		else{
			string palupi;
			ifstream cingtah;
			cingtah.open("Rent.txt");
			getline(cingtah, palupi);
			cout<<palupi<<endl;
			getline(cingtah, palupi);
			cout<<palupi<<endl;
			getline(cingtah, palupi);
			cout<<palupi<<endl<<endl;
			cingtah.close();
			who_are_you();
		}
	}
	Sleep(1000);
	system("cls");
	who_are_you();
}


void Reservation::cust(){
	ofstream love;
	love.open("Customer.txt");
	string nama="", email="", pn="", nik="";
	long long phoneNumber, Nik;
	cout<<"Masukkan data diri Anda";
	cout<<"\nNama          : "; 
	cin>>nama;
    cout << "NIK           : "; 
    cin >>Nik; 
    stringstream ss;
    ss << Nik;          
    nik = ss.str();
    if(nik.length()!=16){
		cout<<"NIK yang Anda Masukkan Tidak Valid\n";
		cust();
	}
	cout<<"Nomor Telepon : ";
	cin>>phoneNumber;
	stringstream pp;
    pp << phoneNumber;  
    pn = pp.str();
	if(pn.length()!=12){
	cout<<"Nomor Telepon Terdiri dari 12 Digit!\n";
	cust();
    }
	cout<<"Email         : "; 
	cin>>email;
	if(email.find("@gmail.com")==-1){
		cout<<"Email yang Anda Masukkan Tidak Valid\n";
		cust();
	}
	love << "Nama = "<<nama<<"\nNIK = "<<Nik<<"\nNomor Telepon = "<<phoneNumber<<endl;
	love.close();
	Customer Customer(nama, email, phoneNumber, Nik);
	cout<<"Registrasi Berhasil\n";
	Sleep(3000);
	system("cls");

	int pilihan;
	setColor(23);
	cout<<"===== MENU UTAMA ====\n";
	setColor(7);
	cout<<"1. Katalog Sepeda\n";
	cout<<"2. Reservasi\n";
	cout<<"3. Pembayaran\n\n";
	cout<<"Masukkan nomor : "; cin>>pilihan;
	
	if(pilihan == 1){
		system("cls");
		catalogBike();
		
	}
	if(pilihan == 2){
		system("cls");
		reservation();
		
	}
	else if(pilihan == 3){
		system("cls");
		pay();
		
	}
	else if(pilihan == 4){
		system("cls");
		who_are_you();
		
	}
	else{
		system("cls");
		cout<<"Masukan Tidak Sesuai!\n";
		cout<<"Kembali ke Halaman Utama\n";
		
		who_are_you();
	}
}


void Reservation::reservation(){
	myBike.Res();
	int pilihan;
	setColor(23);
	cout<<"===== MENU UTAMA ====\n";
	setColor(7);
	cout<<"1. Katalog Sepeda\n";
	cout<<"2. Reservasi\n";
	cout<<"3. Pembayaran\n";
	cout<<"4. Halaman Utama\n\n";
	cout<<"Masukkan nomor : "; cin>>pilihan;
	
	if(pilihan == 1){
		system("cls");
		catalogBike();
	}
	else if(pilihan == 2){
		system("cls");
		reservation();
	}
	else if(pilihan == 3){
		system("cls");
		pay();
	}
	else if(pilihan == 4){
		system("cls");
		who_are_you();	
	}
	else{
		system("cls");
		cout<<"Masukan Tidak Sesuai!\n";
		cout<<"Kembali ke Halaman Utama\n";
		who_are_you();
	}
}

void Reservation::catalogBike(){
	myBike.showBike();
	int pilihan;
	setColor(23);
	cout<<"===== MENU UTAMA ====\n";
	setColor(7);
	cout<<"1. Katalog Sepeda\n";
	cout<<"2. Reservasi\n";
	cout<<"3. Pembayaran\n";
	cout<<"4. Halaman Utama\n\n";
	cout<<"Masukkan nomor : "; cin>>pilihan;
	
	if(pilihan == 1){system("cls");
		catalogBike();
		
	}
	else if(pilihan == 2){
		system("cls");
		reservation();
		
	}
	else if(pilihan == 3){
		system("cls");
		pay();
		
	}
	else if(pilihan == 4){
		system("cls");
		who_are_you();
	
	}
	else{
		system("cls");
		cout<<"Masukan Tidak Sesuai!\n";
		cout<<"Kembali ke Halaman Utama\n";
		who_are_you();
	}
}

void Reservation::pay(){
	setColor(23);
    cout<<"==== PEMBAYARAN ====\n\n";
    setColor(7);
	cout<<"KETENTUAN :\n";
	cout<<"1. Pembayaran dilakukan selambat-lambatnya 1 hari sebelum tanggal sewa\n";
	cout<<"2. Apabila telah membayar, tidak dapat mengajukan pembatalan\n";
	cout<<"3. Segala kerusakan yang terjadi pada sepeda menjadi tanggung jawab penyewa\n";
	cout<<"4. Apabila penyewa telat dalam mengembalikan sepeda, akan dikenakan pembayaran tambahan\n";
	
	std::srand(std::time(0));
    int rn = std::rand() % 1000000;
    save=rn;
    cout<<"Kode Pembayaran : "<<rn<<endl;
	bool next;
	cout<<endl<<"Apakah ingin melanjutkan pembayaran?\n"<<"Ketik 1 = Ya atau 0 = Tidak\n";
	cout<<"Masukkan angka  : "; cin>>next;
	
	if(next){
		int cd, byr=0;
		cout<<"Masukkan Kode Pembayaran : "; cin>>cd;
		myBike.cash();
		if(cd==save){
			cout<<endl;
			cout<<"Masukkan Kode Pembayaran : "; cin>>byr;
			Sleep(1000);
			cout<<"Proses Verifikasi...";
			Sleep(3000);
			cout<<"\nPembayaran Berhasil!\n";
			cout<<"Kembali ke Halaman Utama";
			Sleep(1000);
			system("cls");
			who_are_you();
			myBike.success();
		}
		else{
			cout<<"Kode yang kamu masukkan tidak valid!\n";
			pay();
		}
	}
	 else{
		cout<<"Kembali ke Menu Utama\n";
		who_are_you();
	}
}




