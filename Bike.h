#ifndef _BIKE_H
#define _BIKE_H
#include <iostream>
#include <vector>
#include <string>

class Bike{
	
	public:
		
    	Bike(std::string model1 = "", int bike = 0, bool available = false, int price = 0);
    	
		void print() const;
		
		void newBike();
		
		void showBike();
		
		void choiceBike(int sw);
		
		void cash();
		
		void Res();
		
		void Money(int sw, int jam);
		
		void check(int sw, int jam);
		
		void success();
		
		int getPrice() const{
		return _price;
		};
		
		friend std::ostream& operator<<(std::ostream& os, const Bike& b);
		
		static std::vector<Bike> vec; 
    	static int cnto; 
		static int sw;
		static int jam;
		static int date;
		static int month;
		static int year;
		static int res;
//		static std::vector<float> p;	
	private:
		std::string _mdl;
		int _bike;
		bool _available;
		int _price;
		float rizz;	
		
};
#endif	
