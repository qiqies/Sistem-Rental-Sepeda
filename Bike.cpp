#include "Bike.h"
#include <iostream>
#include<fstream>
#include <vector>
#include <string>
#include <windows.h> 
using namespace std;

Bike::Bike(std::string model1, int bike, bool available, int price)
    : _mdl(model1), _bike(bike), _available(available), _price(price) {}

int Bike::cnto = 0;
std::vector<Bike> Bike::vec;
int Bike::sw = 0;
int Bike::jam = 0;
int Bike::date = 0;
int Bike::month = 0;
int Bike::year =  0;
int Bike::res = 0;
std::vector<float> p;

void setColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

void Bike::newBike() {
	ofstream outputFile("bike.txt");
	
	if(!outputFile.is_open()){
		cerr << "Gagal Membuka File!" << endl;
		return;
	}
    if (cnto >= 20) {
        cout << "Jumlah Sepeda Sudah Penuh\n";
        return;
    }

    int bike;
    string model;
    bool available;
    int price;

    cout << "Masukkan Data Sepeda:\n";
    cout << "Nomor ID       : ";
    cin >> bike;
    cout << "Model          : ";
    cin >> model;
    cout << "Ketersediaan (1 untuk Tersedia, 0 untuk Tidak): ";
    cin >> available;
    cout << "Harga/Jam      : ";
    cin >> price;
    outputFile << "Nomor ID = "<<bike<<"\nModel = "<<model<<"\nKetersediaan = "<<available<<"\nHarga/Jam = "<<price;
 	outputFile.close();
 	
    vec.push_back(Bike(model, bike, available, price));
    cnto++;
	
//	outputFile << model <<"\t"<<bike<<"\t"<<available<<"\t"<<price<<"\n";
	
    system("cls");
    cout<<"Proses Verifikasi...";
    Sleep(1000); 
    system("cls");
    cout << "Data Berhasil Dimasukkan!\n\n";
}

void Bike::Res() {
//	cout<<"sw+1 = "<<sw+1<<" cnto = "<<cnto<<endl;
	int pol;
    if (cnto == 0) {
        cout << "Tidak ada sepeda yang tersedia untuk disewa.\n";
        return;
    }
	setColor(23);
    cout << "==== RESERVASI SEPEDA ====\n\n";
    setColor(7);
    cout << "Masukkan angka sepeda: ";
    cin >> sw;
    if (sw+1 < 0 || sw > cnto) {
        cout << "Pilihan tidak valid!\n";
        return;
    }
    cout << "Masukkan Tahun : \n";
    cin >> year;
    cout<<"Masukkan Bulan <angka>: \n";
    cin>> month;
    cout<<"Masukkan Tanggal : \n";
    cin>>date;
    
    if(year%4!=0&&month==2&&date>28){
    	cout<<"Tidak ada tanggal "<<date<<" Pada Bulan "<<month<<endl;
    	Res();
	}
	else if(month<=7&&month%2==0&&(date>30||date<1)){
		cout<<"Tidak ada tanggal "<<date<<" Pada Bulan "<<month<<endl;
    	Res();
	}
    else if(month<=7&&month%2==1&&(date>31||date<1)){
		cout<<"Tidak ada tanggal "<<date<<" Pada Bulan "<<month<<endl;
    	Res();
	}
	else if(month>7&&month%2==1&&(date>30||date<1)){
		cout<<"Tidak ada tanggal "<<date<<" Pada Bulan "<<month<<endl;
    	Res();
	}
	else if(month>7&&month%2==0&&(date>31||date<1)){
		cout<<"Tidak ada tanggal "<<date<<" Pada Bulan "<<month<<endl;
    	Res();
	}
    cout << "Masukkan Durasi Sewa dalam Jam: ";
    cin >> jam;
	
	
	res++;
    system("cls");
}

void Bike::success(){
	ofstream tuku;
	tuku.open("Rent.txt");
	tuku << "Nomor Sepeda = " <<sw << "\nTanggal/Bulan/Tahun = "<<date<<"/"<<month<<"/"<<year<<"\nDurasi Sewa = "<<jam;
	tuku.close();
}

void Bike::cash() {
	
//	cout<<"sw+1 = "<<sw+1<<" cnto = "<<cnto<<endl;
    if (sw+1 < 0 || sw > cnto) {
        cout << "Pilihan sepeda tidak valid!\n";
        return;
    }
    
    cout<<"Akses vector = "<<vec[sw-1]._price<<" Jam = "<<jam<<endl;

    cout << "Berikut Rincian Sepeda yang Akan Anda Sewa:\n";
    cout << vec[sw-1] << endl;
    cout << "\nNominal Harga yang Harus Anda Bayarkan: ";
    cout << vec[sw-1]._price * jam << endl;
}

void Bike::showBike() {
	system("cls");
    if (cnto == 0) {
        cout << "Sepeda Tidak Tersedia\n";
        return;
    }
	setColor(23);
    cout << "==== Daftar Sepeda ====\n";
    setColor(7);
    for (int i = 0; i < cnto; ++i) {
        cout << "Sepeda ke-" << i + 1 << " : \n" << vec[i] << endl;
    }
}

std::ostream& operator<<(std::ostream& os, const Bike& b) {
    os << "Model        : " << b._mdl << "\n";
    os << "ID           : " << b._bike << "\n";
    os << "Ketersediaan : " << (b._available ? "Tersedia" : "Tidak Tersedia") << "\n";
    os << "Harga        : " << b._price << "\n";
    return os;
}

