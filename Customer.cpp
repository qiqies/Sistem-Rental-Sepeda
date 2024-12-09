#include "Customer.h"
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;

const int MAX_CUST = 20;

Customer total[MAX_CUST];
int cnt = 0;
bool emp = 0;

//constructor
Customer::Customer(string name, string email, int phoneNumber, int Nik)
		: _name(name), _email(email), _phoneNumber(phoneNumber), _NIK(Nik){}
		
// buat ngeluarin yang udah ke save 
void Customer::print() const
{
    cout << "Name: " << _name << "\nEmail: " << _email << "\nPhoneNumber: " << _phoneNumber << "\n";
}

void Customer::newcust(const Customer &c){
	if(cnt > MAX_CUST){
		cout<<"Maaf, jumlah pelanggan sudah penuh\n";
		return;
	}
	total[cnt] = c;
	cnt++;
	emp = true;
}


