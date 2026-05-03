#ifndef BEFIZETES_HPP
#define BEFIZETES_HPP

#include <string>
#include "date.hpp"
#include "tipusok.hpp"

#ifdef MEMTRACE
 #include "memtrace.h"
 #include "gtest_lite.h"
#endif

class Befizetes {
private:
        // A befizetés dátuma (év, hónap, nap)
        Date date;
        // A befizetés összege forintban
        int osszeg;
        //Fizetési mód (pl. "készpénz", "átutalás")
        FizetesiMod mod;
        // Opcionális megjegyzés a befizetéshez
        std::string megjegyzes;
        // Ez a mező jelzi, hogy a befizetés törölt-e (true) vagy sem (false)
        bool torolt;
public:
        //* Konstruktor

        /**
         * @brief Konstruktor a Befizetes osztályhoz, amely megköveteli a dátumot, összeget és fizetési módot.
         * @param d a befizetés dátuma
         * @param o a befizetés összege forintban
         * @param m a fizetési mód
         * @param meg egy opcionális megjegyzés a befizetéshez
         * @param t a befizetés törölt-e (true) vagy sem (false)
         */
        Befizetes(const Date& d, int o, FizetesiMod m, const std::string& meg = "", bool t = false) : date(d), osszeg(o), mod(m), megjegyzes(meg), torolt(t) {};

        //* Getterek

        /**
         * @brief Getter a befizetés dátumához.
         * @return A befizetés dátuma.
         */
        Date getDate() const { return date; };

        /**
         * @brief Getter a befizetés összegéhez.
         * @return A befizetés összege forintban.
         */
        int getOsszeg() const { return osszeg; };

        /**
         * @brief Getter a befizetés fizetési módjához.
         * @return A befizetés fizetési módja (pl. "készpénz", "átutalás").
         */
        FizetesiMod getMod() const { return mod; };

        /**
         * @brief Getter a befizetés megjegyzéséhez.
         * @return A befizetés megjegyzése.
         */
        std::string getMegjegyzes() const { return megjegyzes; };

        /**
         * @brief Getter a befizetés törölt állapotához.
         * @return true, ha a befizetés törölt, false egyébként.
         */
        bool isTorolt() const { return torolt; };

        //* Setterek

        /**
         * @brief Setter a befizetés dátumához.
         * @param d a befizetés dátuma.
         */
        void setDate(const Date& d) { date = d; };

        /**
         * @brief Setter a befizetés összegéhez.
         * @param o a befizetés összege forintban.
         */
        void setOsszeg(int o) { osszeg = o; };

        /**
         * @brief Setter a befizetés fizetési módjához.
         * @param m a fizetési mód (pl. "készpénz", "átutalás").
         */
        void setMod(FizetesiMod m) { mod = m; };

        /**
         * @brief Setter a befizetés megjegyzéséhez.
         * @param meg a befizetés megjegyzése.
         */
        void setMegjegyzes(const std::string& meg) { megjegyzes = meg; };

        /**
         * @brief Befizetés törlése, vagy visszaállítása a törölt állapotból.
         * @param t true, ha a befizetés törölt, false egyébként.
         */
        void setTorolt(bool t) { torolt = t; };
};

#endif