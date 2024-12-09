#ifndef _OWNER_H
#define _OWNER_H
#include <string>
#include <iostream>


class Owner {
public:
    Owner(std::string nameown = "", std::string emailown = "", int own = 0);

    void newowner(const Owner &o);
    bool regowe() const;
	
	static void newowner(std::string nameown, std::string emailown, int own);
	
	static int cont;

private:
    std::string _nameown;
    std::string _emailown;
    int ownerID;
};

#endif 

