#ifndef JELENLET_HPP
#define JELENLET_HPP

#include <string>
#include "date.hpp"

#ifdef MEMTRACE
 #include "memtrace_gtest/memtrace.h"
 #include "memtrace_gtest/gtest_lite.h"
#endif

class Jelenlet {
private:
        // Jelenlét dátuma Formátum: "YYYY-MM-DD"
        Date datum;
        // Fizetési állapot: true, ha fizetett, false egyébként
        bool fizetett;

public:
        //* Konstruktor

        /**
         * @brief A Jelenlet osztály konstruktora. Alapértelmezés szerint a jelenlét dátuma a mai nap, és a fizetési állapot false (nem fizetett).
         * @param d A jelenlét dátuma.
         * @param f A fizetési állapot.
         */
        Jelenlet(const Date& d = Date(), bool f = false) : datum(d), fizetett(f) {};

        //*Getters

        /**
         * @brief Lekérdezi a jelenlét dátumát.
         * @return A jelenlét dátuma stringként.
         */
        Date getDatum() const { return datum; };

        /**
         * @brief Lekérdezi a fizetési állapotot.
         * @return true, ha fizetett, false egyébként.
         */
        bool getFizetett() const { return fizetett; };

        //*Setters

        /**
         * @brief Beállítja a jelenlét dátumát.
         * @param ujDatum Az új dátum, amelyre a jelenlét dátumát módosítani szeretnénk.
         */
        void setDatum(const Date& ujDatum) { datum = ujDatum; };

        /**
         * @brief Beállítja a fizetési állapotot.
         * @param fizetesiAllapot Az új fizetési állapot, amelyre a jelenlét fizetési állapotát módosítani szeretnénk.
         */
        void setFizetett(bool fizetesiAllapot) { fizetett = fizetesiAllapot; };
};

#endif