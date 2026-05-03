#ifndef DATE_HPP
#define DATE_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <ctime>

#ifdef MEMTRACE
 #include "memtrace_gtest/memtrace.h"
 #include "memtrace_gtest/gtest_lite.h"
#endif


class Date {
private:
        // Egyszerű dátum osztály, amely év, hónap és nap mezőket tartalmaz
        int ev, ho, nap;
public:
        //* Konstruktor

        /**
         * @brief A Date osztály alapértelmezett konstruktora, amely a mai nap dátumát állítja be.
         */
        Date() {
                std::time_t t = std::time(nullptr);
                std::tm* now = std::localtime(&t);
                ev = now->tm_year + 1900;
                ho = now->tm_mon + 1;
                nap = now->tm_mday;
        };

        /**
         * @brief Konstruktor konkrét dátum megadásához.
         * @param e az év
         * @param h a hónap
         * @param n a nap
         */
        Date(int e, int h, int n) : ev(e), ho(h), nap(n) {};

        /**
         * @brief Másoló konstruktor a Date osztályhoz.
         */
        Date(const Date& other) : ev(other.ev), ho(other.ho), nap(other.nap) {};

        /**
         * @brief Stringből konstruktor a Date osztályhoz, amely "YYYY-MM-DD" formátumú stringet vár.
         * @param dateStr a dátum stringként "YYYY-MM-DD" formátumban
         */
        Date(const std::string& dateStr);

        //* Operátorok

        /**
         * @brief Összehasonlító operátor a dátumok rendezéséhez és összehasonlításához.
         * @param other a másik dátum, amellyel összehasonlítjuk ezt a dátumot
         * @return true, ha ez a dátum kisebb, mint a másik
         * @return false, ha ez a dátum nagyobb vagy egyenlő a másikkal
         */
        bool operator<(const Date& other) const;

        /**
         * @brief Nagyobb operátor a dátumok rendezéséhez és összehasonlításához.
         * @param other a másik dátum, amellyel összehasonlítjuk ezt a dátumot
         * @return true, ha ez a dátum nagyobb, mint a másik
         * @return false, ha ez a dátum kisebb vagy egyenlő a másikkal
         */
        bool operator>(const Date& other) const;

        /**
         * @brief Egyenlőség operátor a dátumok összehasonlításához.
         * @param other a másik dátum, amellyel összehasonlítjuk ezt a dátumot
         * @return true, ha ez a dátum megegyezik a másikkal
         * @return false, ha ez a dátum nem egyezik meg a másikkal
         */
        bool operator==(const Date& other) const {
                return (ev == other.ev && ho == other.ho && nap == other.nap);
        };

        //* Metodusok

        /**
         * @brief Beállítja dátumot a mai napra
         */
        void setToToday();

        /**
         * @brief Dátum stringgé alakítása "YYYY-MM-DD" formátumban.
         * @return A dátum stringként.
         */
        std::string toString() const;
};

#endif