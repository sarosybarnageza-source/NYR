#ifndef CONFIG_HPP
#define CONFIG_HPP

#include <string>
#include "tipusok.hpp"

#ifdef MEMTRACE
 #include "memtrace_gtest/memtrace.h"
 #include "memtrace_gtest/gtest_lite.h"
#endif


class Config {
private:
        // Belépő árak
        int normalAr;
        int versenyzoAr;

        // Testvér kedvezmény
        int testverKedvezmeny;

        // Különböző bérlet típusok árai
        int ar4Alkalom;
        int ar8Alkalom;
        int ar12Alkalom;
        int arKorlatlan;
        int arProba;

        // Admin jelszó
        std::string adminJelszo;

public:
        //* Konstruktor

        /**
         * @brief A Config osztály konstruktora, amely lehetővé teszi a belépő árak, testvér kedvezmény, bérlet árak és az admin jelszó egyéni értékekkel történő inicializálását.
         * @details Ragaszkodik az előre meghatározott értékekhez, de lehetőséget ad arra, hogy a program igényei szerint módosítsuk azokat a konstruktor paramétereinek segítségével.
         * Az árak és a jelszó értékei a következők:
         * - normalAr: 1300 Ft (alapértelmezett)
         * - versenyzoAr: 1000 Ft (alapértelmezett)
         * - testverKedvezmeny: 1000 Ft (alapértelmezett)
         * - ar4Alkalom: 17000 Ft (alapértelmezett)
         * - ar8Alkalom: 28000 Ft (alapértelmezett)
         * - ar12Alkalom: 42000 Ft (alapértelmezett)
         * - arKorlatlan: 0 Ft (alapértelmezett)
         * - arProba: 5000 Ft (alapértelmezett)
         * - adminJelszo: "nagyhazi" (alapértelmezett)
         */
        Config(int normalAr=1300, int versenyzoAr=1000, int testverKedvezmeny=1000, int ar4Alkalom=17000, int ar8Alkalom=28000, int ar12Alkalom=42000, int arKorlatlan=0, int arProba=5000, const std::string& adminJelszo="nagyhazi") 
            : normalAr(normalAr), versenyzoAr(versenyzoAr), testverKedvezmeny(testverKedvezmeny), ar4Alkalom(ar4Alkalom), ar8Alkalom(ar8Alkalom), ar12Alkalom(ar12Alkalom), arKorlatlan(arKorlatlan), arProba(arProba), adminJelszo(adminJelszo) {};
        
        //*Getters

        /**
         * @brief Lekérdezi a normál belépő árát.
         * @return A normál belépő ára egész számként.
         */
        int getNormalAr() const { return normalAr; };

        /**
         * @brief Lekérdezi a versenyző belépő árát.
         * @return A versenyző belépő ára egész számként.
         */
        int getVersenyzoAr() const { return versenyzoAr; };

        /**
         * @brief Lekérdezi a testvér kedvezményt.
         * @return A testvér kedvezmény értéke egész számként.
         */
        int getTestverKedvezmeny() const { return testverKedvezmeny; };
        
        /**
         * @brief Lekérdezi a bérlet árát a megadott típus alapján.
         * @param tipus A bérlet típusa.
         * @return A bérlet ára egész számként. Ha a típus nem létezik, -1-et ad vissza.
         */
        int getBerletAr(BerletTipus tipus) const {
                switch (tipus) {
                        case BerletTipus::Alkalom4:   return ar4Alkalom;
                        case BerletTipus::Alkalom8:   return ar8Alkalom;
                        case BerletTipus::Alkalom12:  return ar12Alkalom;
                        case BerletTipus::Korlatlan:  return arKorlatlan;
                        case BerletTipus::Proba:      return arProba;
                        default:                      return 0;
    }
        }
        
        /**
         * @brief Lekérdezi a bérlet alkalom számát a megadott típus alapján.
         * @param tipus A bérlet típusa.
         * @return A bérlet alkalom száma egész számként, ha korlátozott, vagy -1, ha korlátlan. Ha a típus nem létezik, 0-t ad vissza.
         */
        int getBerletAlkalom(BerletTipus tipus) const {
                switch (tipus) {
                        case BerletTipus::Alkalom4:   return 4;
                        case BerletTipus::Alkalom8:   return 8;
                        case BerletTipus::Alkalom12:  return 12;
                        case BerletTipus::Korlatlan:  return -1;
                        case BerletTipus::Proba:      return 1;
                        default:                      return 0;
                }
        }

        /**
         * @brief Ellenőrzi az admin jelszót.
         * @param tipp A beírt jelszó.
         * @return true, ha a jelszó helyes, false egyébként.
         */
        bool jelszoEllenorzes(const std::string& tipp) const;

        //* Setters

        /**
         * @brief Beállítja a normál belépő árát.
         * @param ujNormalAr Az új normál belépő ár.
         */
        void setNormalAr(int ujNormalAr) { normalAr = ujNormalAr; };

        /**
         * @brief Beállítja a versenyző belépő árát.
         * @param ujVersenyzoAr Az új versenyző belépő ár.
         */
        void setVersenyzoAr(int ujVersenyzoAr) { versenyzoAr = ujVersenyzoAr; };

        /**
         * @brief Beállítja a testvér kedvezményt.
         * @param ujTestverKedvezmeny Az új testvér kedvezmény.
         */
        void setTestverKedvezmeny(int ujTestverKedvezmeny) { testverKedvezmeny = ujTestverKedvezmeny; };

        /**
         * @brief Beállítja a 4 alkalom bérlet árát.
         * @param ujAr4Alkalom Az új 4 alkalom bérlet ár.
         */
        void setAr4Alkalom(int ujAr4Alkalom) { ar4Alkalom = ujAr4Alkalom; };

        /**
         * @brief Beállítja az 8 alkalom bérlet árát.
         * @param ujAr8Alkalom Az új 8 alkalom bérlet ár.
         */
        void setAr8Alkalom(int ujAr8Alkalom) { ar8Alkalom = ujAr8Alkalom; };

        /**
         * @brief Beállítja a 12 alkalom bérlet árát.
         * @param ujAr12Alkalom Az új 12 alkalom bérlet ár.
         */
        void setAr12Alkalom(int ujAr12Alkalom) { ar12Alkalom = ujAr12Alkalom; };

        /**
         * @brief Beállítja a korlátlan bérlet árát.
         * @param ujArKorlatlan Az új korlátlan bérlet ár.
         */
        void setArKorlatlan(int ujArKorlatlan) { arKorlatlan = ujArKorlatlan; };

        /**
         * @brief Beállítja a próbaidő bérlet árát.
         * @param ujArProba Az új próbaidő bérlet ár.
         */
        void setArProba(int ujArProba) { arProba = ujArProba; };

        /**
         * @brief Beállítja az admin jelszót.
         * @param ujAdminJelszo Az új admin jelszó.
         */
        void setAdminJelszo(const std::string& ujAdminJelszo) { adminJelszo = ujAdminJelszo; };

};

#endif