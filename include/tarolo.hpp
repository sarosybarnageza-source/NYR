#ifndef TAROLO_HPP
#define TAROLO_HPP

#include <cstddef>

#ifdef MEMTRACE
 #include "../lib/memtrace_gtest/memtrace.h"
 #include "../lib/memtrace_gtest/gtest_lite.h"
#endif

template <typename Tipus>
class Tarolo{
private:
        Tipus* adat;
        size_t meret;
        size_t kapacitas;

        /**
         * @brief Ha szükséges, növeli a tároló kapacitását, hogy több elemet tudjon tárolni.
         */
        void nyujt();
public:
        //*Konstruktorok, destruktor, másoló konstruktor
        
        /**
         * @brief A Tarolo osztály konstruktora, amely inicializálja a tároló adatait, méretét és kapacitását.
         * Az adat pointert nullptr-re állítja, a méretet és kapacitást pedig 0-ra inicializálja.
         */
        Tarolo() : adat(nullptr), meret(0), kapacitas(0) {};

        /**
         * @brief A Tarolo osztály konstruktora, amely inicializálja a tároló adatait egy adott kezdeti kapacitással.
         * @param kezdoKapacitas a tároló kezdeti kapacitása, amely meghatározza, hogy hány elemet tud tárolni anélkül, hogy új memóriát kellene foglalnia.
         */
        Tarolo(size_t kezdoKapacitas) : adat(new Tipus[kezdoKapacitas]), meret(0), kapacitas(kezdoKapacitas) {};

        /**
         * @brief A Tarolo osztály konstruktora, amely inicializálja a tároló adatait egy adott kezdeti adatokkal.
         * @param kezdoAdatok egy pointer a kezdeti adatokra, amelyeket a tárolóba másolni kell
         * @param darab a kezdeti adatok száma, amely meghatározza, hogy hány elemet tud tárolni
         */
        Tarolo(const Tipus* kezdoAdatok, size_t darab)
                : adat(new Tipus[darab]), meret(darab), kapacitas(darab) {
                for (size_t i = 0; i < darab; ++i) {
                        adat[i] = kezdoAdatok[i];
                }
        };

        /**
         * @brief A Tarolo osztály másoló konstruktora, amely létrehoz egy új Tarolo objektumot egy meglévő Tarolo objektum alapján.
         * Ez a konstruktor mély másolást hajt végre, azaz új memóriaterületet foglal a másolt adatok számára.
         * @param masik a másolandó Tarolo objektum
         */
        Tarolo(const Tarolo& masik)
                : adat(new Tipus[masik.kapacitas]), meret(masik.meret), kapacitas(masik.kapacitas) {
                for (size_t i = 0; i < masik.meret; ++i) {
                        adat[i] = masik.adat[i];
                }
        };

        /**
         * @brief A Tarolo osztály destruktora, amely felszabadítja a tároló által lefoglalt memóriát.
         * Ez biztosítja, hogy ne legyen memória szivárgás a Tarolo objektumok használata során.
         */
        ~Tarolo() {
                delete[] adat;
        };

        //* Operatorok

        /**
         * @brief A Tarolo osztály másoló értékadó operátora, amely egy meglévő Tarolo objektum értékeit egy másik Tarolo objektumba másolja.
         * Ez az operátor mély másolást hajt végre, azaz új memóriaterületet foglal a másolt adatok számára.
         * @param masik a másolandó Tarolo objektum
         * @return Egy referencia a módosított Tarolo objektumra
         */
        Tarolo& operator=(const Tarolo& masik);

        /**
         * @brief [] operátor, amely lehetővé teszi az elemek elérését index alapján.
         * @warning az operátor nem végez határellenőrzést, ezért a hívónak biztosítania kell, hogy az index érvényes legyen.
         * @param index az elem indexe
         * @return A megadott indexű elem referenciája
         */
        Tipus& operator[](size_t index) { return adat[index]; };

        /**
         * @brief [] operátor, amely lehetővé teszi az elemek elérését index alapján, konstans objektumok esetén.
         * @warning az operátor nem végez határellenőrzést, ezért a hívónak biztosítania kell, hogy az index érvényes legyen.
         * @param index az elem indexe
         * @return A megadott indexű elem konstans referenciája
         */
        const Tipus& operator[](size_t index) const { return adat[index]; };

        //*Getters
        /**
         * @brief Lekérdezi a tároló aktuális méretét, azaz hány elemet tartalmaz.
         * @return A tároló aktuális mérete.
         */
        size_t getMeret() const { return meret; };

        /**
         * @brief Lekérdezi a tároló aktuális kapacitását, azaz hány elemet tud tárolni anélkül, hogy új memóriát kellene foglalnia.
         * @return A tároló aktuális kapacitása.
         */
        size_t getKapacitas() const { return kapacitas; };

        //*Egyéb metódusok

        /**
         * @brief Hozzáad egy új elemet a tárolóhoz. Ha a tároló eléri a kapacitását, automatikusan megnöveli a kapacitást.
         * @param ujElem az új elem, amelyet hozzá kell adni a tárolóhoz
         */
        void hozzaad(const Tipus& ujElem);

        
};

#endif //TAROLO_HPP