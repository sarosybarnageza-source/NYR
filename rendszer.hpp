#ifndef RENDSZER_HPP
#define RENDSZER_HPP

#include "config.hpp"
#include "edzo.hpp"
#include "gyerek.hpp"
#include "befizetes.hpp"

#ifdef MEMTRACE
 #include "memtrace_gtest/memtrace.h"
 #include "memtrace_gtest/gtest_lite.h"
#endif

class Rendszer {
private:
        //Globális árak és jelszó
        Config configuration;
        //Gyerekek tárolója érték szerint
        Tarolo<Gyerek> gyerekek;
        //Befizetések tárolása érték szerint
        Tarolo<Befizetes> befizetesek;
        //Edzők tárolása érték szerint
        Tarolo<Edzo> edzok;
public:
        //*Konstruktor és Destruktor

        /**
         * @brief Rendszer konstruktora
         */
        Rendszer();

        /**
         * @brief Rendszer destruktora
         * @todo Készítsen automatikus mentést
         */
        ~Rendszer();

        //* Gyerek kezelés

        /**
         * @brief Hozzáad egy gyereket a tarolóhoz
         * @param gy 
         */
        void gyerekHozzaad(const Gyerek& gy) { gyerekek.hozzaad(gy); }

        /**
         * @brief Visszaadja a megfelelő gyerek pointerét
         * @param id A Gyerek-et meghatározó ID
         * @return Gyerek* Megfelelő Gyerek-re mutató pointer
         */
        Gyerek* keresGyerek(size_t id);

        /**
         * @brief Visszaadja a megfelelő gyerek pointerét
         * @details kereséshez elegendő egy név részlet
         * @param nev név részlet (ékezet nem számít)
         * @return Gyerek*  Megfelelő Gyerek-re mutató pointer
         */
        Gyerek* keresGyerek(const std::string& nev);

        //* Pénztár modul

        /**
         * @brief Új befizetés rögzítése a rendszerben és a gyereknél.
         * @param gyerekID A gyerek azonosítója, aki fizet.
         * @param b Dinamikusan foglalt (new) befizetés objektum. A Rendszer veszi át a tulajdonjogot.
         */
        void befizetesRogzit(size_t gyerekID, Befizetes* b);

        //*Edzők kezelése

        /**
         * @brief Új edző hozzáadása
         * @param e hozzáaadandó edző
         */
        void edzoHozzaad(const Edzo& e) {
                edzok.hozzaad(e);
        }

        /**
         * @brief Edző eltávolítása
         * @param e eltávolítandó edző
         */
        void edzo(const Edzo& e) {
                //TODO tarolóból eltávolítás
        }

        //*Mentés és betöltés

        /**
         * @brief Összes adat jelenlegi állapotát menti
         * @param fajlnev kimeneti fájl útvonala 
         */
        void ment(const std::string& fajlnev);

        /**
         * @brief Adatok betöltése
         * @param fajlnev bemeneti fájl útvonal
         */
        void betolt(const std::string& fajlnev);

        //* Getterek

        /**
         * @brief Visszaadja a jelenle használt tárolót, amiben a gyereket tároljuk
         * @return Tarolo<Gyerek>& Gyerekek tárolója
         */
        Tarolo<Gyerek>& getGyerekek() {
                return gyerekek;
        }

        /**
         * @brief Visszaadja az edzők tárolóját
         * @return Tarolo<Edzo>& edzők tárolója
         */
        Tarolo<Edzo>& getEdzok() {
                return edzok;
        }

        /**
         * @brief Visszaadja a jelenlegi beállításokat
         * @return Config& jelenleg használt beállítások
         */
        Config& getConfig() {
                return configuration;
        }

};

#endif