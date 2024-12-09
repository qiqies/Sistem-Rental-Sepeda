#include "Owner.h"
#include <iostream>
const int MAX_OWN = 20;


Owner totall[MAX_OWN];
int Owner::cont = 0;


Owner::Owner(std::string nameown, std::string emailown, int own)
    : _nameown(nameown), _emailown(emailown), ownerID(own) {}


void Owner::newowner(std::string nameown, std::string emailown, int own) {
    if(cont >= 20) {
        std::cout << "Maaf, jumlah owner sudah penuh\n";
        return;
    }
    totall[cont] =  Owner(nameown, emailown, own);
    cont++;
}

bool Owner::regowe() const {
    if(cont == 0) {
        std::cout << "Tidak ada owner\n";
        return false;
    }
    return true;
}

