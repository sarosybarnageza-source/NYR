#ifndef BERLET_HPP
#define BERLET_HPP

#include "tipusok.hpp"

class Berlet {
private:
        /**
         * @brief A bérlet típusa és alkalomkorlátja.
         * @details A bérletek lehetnek:
         * - "4 alkalmas": osszesAlkalom += 4
         * - "8 alkalmas": osszesAlkalom += 8
         * - "12 alkalmas": osszesAlkalom += 12
         * - "korlatlan": osszesAlkalom = -1 (korlátlan alkalom)
         * - "proba": osszesAlkalom = 1 (egy alkalom, próba bérlet)
         */
        BerletTipus tipus;
        // Az összes alkalom száma, -1 korlátlan alkalom esetén
        int osszesAlkalom;
        // A már felhasznált alkalmak száma
        int felhasznalt;

public:
        //* Konstruktor

        /**
         * @brief Konstruktor a bérlet inicializálásához.
         * @param t A bérlet típusa, alapértelmezetten BerletTipus::Nincs.
         * @param ossz Az összes alkalom száma, alapértelmezetten 0 (nincs alkalom). Korlátlan alkalom esetén -1.
         */
        Berlet(BerletTipus t = BerletTipus::Nincs, int ossz = 0) : tipus(t), osszesAlkalom(ossz), felhasznalt(0) {}

        //* Geterek

        /**
         * @brief Visszaadja a bérlet összes alkalom számát.
         * @return int 
         */
        int getOsszesAlkalom() const { return osszesAlkalom; }

        /**
         * @brief Visszaadja a bérlet már felhasznált alkalmak számát.
         * @return int 
         */
        int getFelhasznalt() const { return felhasznalt; }

        /**
         * @brief Visszaadja a bérlet típusát.
         * @return std::string 
         */
        BerletTipus getTipus() const { return tipus; }

        /**
         * @brief Visszaadja a bérlet hátralévő alkalmainak számát.
         * @return int -1, ha korlátlan alkalom, egyébként a hátralévő alkalmak száma.
         */
        int getHatralevo() const { 
                return (osszesAlkalom == -1) ? -1 : (osszesAlkalom - felhasznalt); 
        }

        //* Seterek

        /**
         * @brief Beállítja a bérlet típusát.
         * @param ujTipus Az új bérlet típus.
         */
        void setTipus(BerletTipus ujTipus) { tipus = ujTipus; }

        /**
         * @brief Beállítja a bérlet összes alkalom számát.
         * @param ujOsszesAlkalom Az új összes alkalom szám.
         */
        void setOsszesAlkalom(int ujOsszesAlkalom) { osszesAlkalom = ujOsszesAlkalom; }

        /**
         * @brief Beállítja a bérlet már felhasznált alkalmak számát.
         * @param ujFelhasznalt Az új már felhasznált alkalmak száma.
         */
        void setFelhasznalt(int ujFelhasznalt) { felhasznalt = ujFelhasznalt; }

        //* Egyéb metódusok

        /**
         * @brief Ellenőrzi, hogy a bérlet használható-e még.
         * @return true, ha korlátlan VAGY van még alkalma.
         */
        bool vanMegAlkalom() const {
                if (osszesAlkalom == -1) return true;
                return felhasznalt < osszesAlkalom;
        }

        /**
         * @brief Egy alkalom levonása (felhasznált növelése).
         */
        void alkalomLevonas() {
                if (vanMegAlkalom()) felhasznalt++;
        }

        /**
         * @brief Növeli a bérlet alkalmainak számát, és szükség esetén módosítja a típusát.
         * @details Ha a hozzáadott alkalmak száma 4, 8 vagy 12, akkor a típus is módosul ennek megfelelően.
         * Ha a hozzáadott alkalmak száma nulla vagy negatív, akkor nem történik változás.
         * Ha a bérlet jelenleg korlátlan (-1), akkor a hozzáadott alkalmak száma lesz az új összes alkalom, és a felhasznált alkalmak száma 0 lesz.
         * @param n A hozzáadandó alkalmak száma.
         */
        void hozzaadAlkalom(int n);

        //* Operátorok

        /**
         * @brief Növeli a bérlet alkalmainak számát a megadott értékkel, és szükség esetén módosítja a típusát.
         * @param n A hozzáadandó alkalmak száma.
         * @return A módosított bérlet referencia értéke.
         */
        Berlet& operator+=(int n);

};

#endif