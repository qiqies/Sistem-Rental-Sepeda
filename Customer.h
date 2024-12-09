#ifndef _CUSTOMER_H
#define _CUSTOMER_H
#include <string>

class Customer{
	public:
		Customer (std::string name = "", std::string email = "", int phoneNumber = 0, int Nik = 0);
		
		void print() const;
		
		void newcust(const Customer &c);
		
	private:
   		std::string _name;  
    	std::string _email;       
    	int _phoneNumber;
    	int _NIK;
};

#endif 
