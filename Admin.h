#ifndef _ADMIN_H
#define _ADMIN_H
#include <string>

class Admin{
	public:
		Admin(std::string namemin = "", std::string emailmin = "", int admin = 0);
	
		void databike();
		
	private:
		std::string _namemin;
		std::string _emailmin;
		int _admin;
};
#endif
