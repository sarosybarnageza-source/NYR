#ifndef TIPUSOK_HPP
#define TIPUSOK_HPP

#ifdef MEMTRACE
 #include "../lib/memtrace_gtest/memtrace.h"
 #include "../lib/memtrace_gtest/gtest_lite.h"
#endif

enum class BerletTipus {
    Nincs,
    Alkalom4,
    Alkalom8,
    Alkalom12,
    Korlatlan,
    Proba
};

enum class FizetesiMod {
    Keszpenz,
    Atutalas,
    Egyeb
};

#endif