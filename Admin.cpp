#include "Admin.h"
#include "Bike.h"
#include <string>
#include <sstream>
//using namespace std;

Admin::Admin(std::string namemin, std::string emailmin, int admin): _namemin(namemin), _emailmin(emailmin), _admin(admin){}
		
// buat ngeluarin yang udah ke save 

void Admin::databike(){
	Bike bikes;
	bikes.newBike();
}
