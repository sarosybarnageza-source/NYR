#include "../include/berlet.hpp"

void Berlet::hozzaadAlkalom(int n) {
        if (n <= 0) return;

        if (osszesAlkalom == -1) {
                osszesAlkalom = n;
                felhasznalt = 0; //Hogy ne legyen ellentmondás a korlátlan és a konkrét alkalmak között.
        } else {
                osszesAlkalom += n;
        }

        switch (n) {
                case 4:  tipus = BerletTipus::Alkalom4;  break;
                case 8:  tipus = BerletTipus::Alkalom8;  break;
                case 12: tipus = BerletTipus::Alkalom12; break;
                default: break; 
        }
}

Berlet& Berlet::operator+=(int n) {
        hozzaadAlkalom(n);
        return *this;
}