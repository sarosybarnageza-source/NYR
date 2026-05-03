#ifndef EDZO_HPP
#define EDZO_HPP

#include <string>

#ifdef MEMTRACE
 #include "memtrace_gtest/memtrace.h"
 #include "memtrace_gtest/gtest_lite.h"
#endif

class Edzo {
private:
        // Edző neve
        std::string nev;
public:
        //* Konstruktor

        /**
         * @brief Az Edzo osztály konstruktora, amely inicializálja az edző nevét.
         * @param nev 
         */
        Edzo(const std::string& nev = "") : nev(nev) {};
        
        //* Getters

        /**
         * @brief Lekérdezi az edző nevét.
         * @return Az edző neve stringként.
         */
        std::string getNev() const { return nev; }

        //* Setters

        /**
         * @brief Beállítja az edző nevét.
         * @param ujNev Az új név, amelyre az edző nevét módosítani szeretnénk.
         */
        void setNev(const std::string& ujNev) { nev = ujNev; };
};

#endif