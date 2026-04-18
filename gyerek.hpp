#ifndef GYEREK_HPP
#define GYEREK_HPP

#include <string>
#include <vector>
#include "date.hpp"
#include "berlet.hpp"
#include "jelenlet.hpp"
#include "befizetes.hpp"

class Gyerek {
private:
        //Azonosító, rendszer fogja osztani, egyedi módon azonosítja a gyereket a rendszerben
        int id;
        //Teljes név (vezetéknév + keresztnév)
        std::string nev;
        //Születési dátum
        Date szuletesiDatum;
        //Szülő neve
        std::string szuloNev;
        //Szülő telefonszáma
        std::string szuloTelefonszam;
        //Versenyző-e a gyerek
        bool versenyzo;
        //Használt-e már próba bérletet, ha már valaha volt edzésen, akkor true
        bool hasznaltProba;
        // Ez a mező jelzi, hogy a gyerek törölt-e (true) vagy sem (false)
        bool torolt; 

        /**
         * @brief A gyerekhez tartozó bérlet adatai.
         * Ez a mező tárolja a gyerek aktuális bérletét, amely meghatározza, hogy hány alkalommal vehet részt edzéseken.
         * A bérlet típusa és alkalomkorlátja alapján a rendszer nyomon követi, hogy a gyerek hány alkalommal vett részt edzéseken,
         * és hogy van-e még lehetősége edzésen részt venni a bérlet alapján.
         */
        Berlet berlet;
        /**
         * @brief A gyerek jelenléti adatai.
         * @details Ez a mező egy vektort tartalmaz, amelyben a gyerek minden jelenléte szerepel,
         * beleértve a jelenlét dátumát és a fizetési állapotot. 
         */
        std::vector<Jelenlet> jelenletek;
        /**
         * @brief A múltbeli befizetések adatai,
         * @details amelyek tartalmazzák a befizetés dátumát, összegét, fizetési módját és egy opcionális megjegyzést.
         * *Pointereket tárolunk, mert az eredeti objektum a Rendszerben lakik.
         */
        std::vector<Befizetes*> befizetesek;

public:
        //*Konstruktor

        /**
         * @brief A Gyerek osztály konstruktora, amely inicializálja a gyerek adatait,
         * beleértve az azonosítót, nevet, születési dátumot, szülő nevét és telefonszámát,
         * valamint a versenyzői státuszt.
         * @param i azonosító, amely egyedi módon azonosítja a gyereket a rendszerben
         * @param n a gyerek teljes neve (vezetéknév + keresztnév) 
         * @param szuletesiD a gyerek születési dátuma
         * @param szuloN a gyerek szülőjének neve
         * @param szuloT a gyerek szülőjének telefonszáma
         * @param vers a gyerek versenyzői státusza, alapértelmezetten false (nem versenyző)
         */
        Gyerek(int i, const std::string& n, const Date& szuletesiD, const std::string& szuloN, const std::string& szuloT, bool vers = false) 
                : id(i), nev(n), szuletesiDatum(szuletesiD), szuloNev(szuloN), szuloTelefonszam(szuloT), versenyzo(vers), hasznaltProba(false), berlet(BerletTipus::Nincs, 0), torolt(false) {};
        
        //*Getters

        /**
         * @brief Lekérdezi a gyerek azonosítóját.
         * @return A gyerek azonosítója.
         */
        int getId() const { return id; };

        /**
         * @brief Lekérdezi a gyerek nevét.
         * @return A gyerek teljes neve (vezetéknév + keresztnév).
         */
        std::string getNev() const { return nev; };

        /**
         * @brief Lekérdezi a gyerek születési dátumát.
         * @return A gyerek születési dátuma.
         */
        Date getSzuletesiDatum() const { return szuletesiDatum; };

        /**
         * @brief Lekérdezi a gyerek szülőjének nevét.
         * @return A gyerek szülőjének neve.
         */
        std::string getSzuloNev() const { return szuloNev; };

        /**
         * @brief Lekérdezi a gyerek szülőjének telefonszámát.
         * @return A gyerek szülőjének telefonszáma.
         */
        std::string getSzuloTelefonszam() const { return szuloTelefonszam; };

        /**
         * @brief Lekérdezi, hogy a gyerek versenyző-e.
         * @return true, ha a gyerek versenyző, false egyébként.
         */
        bool isVersenyzo() const { return versenyzo; };

        /**
         * @brief Lekérdezi, hogy a gyerek használt-e már próba bérletet.
         * @return true, ha a gyerek már használt próba bérletet, false egyébként.
         */
        bool hasznaltProbaBerlet() const { return hasznaltProba; };

        /**
         * @brief Lekérdezi a gyerek aktuális bérletét.
         * @return A gyerek aktuális bérlete, amely meghatározza, hogy hány alkalommal vehet részt edzéseken.
         */
        Berlet& getBerlet() { return berlet; };

        /**
         * @brief Lekérdezi, hogy a gyerek törölt-e.
         * @return true, ha a gyerek törölt, false egyébként.
         */
        bool isTorolt() const { return torolt; };

        //*Setters

        /**
         * @brief Beállítja a gyerek törölt státuszát.
         * @param t true, ha a gyereket törölni szeretnénk, false egyébként.
         */
        void setTorolt(bool t) { torolt = t; }

        //*Metódusok

        /**
         * @brief Hozzáad egy jelenletet a gyerek jelenleteihez.
         * @param j A hozzáadandó jelenlet.
         */
        void jelenletHozzaad(const Jelenlet& j);
        
        /**
         * @brief Hozzáad egy befizetést a gyerek befizetéseihez.
         * @param b A hozzáadandó befizetés.
         */
        void befizetesHozzaad(Befizetes* b);

};

#endif