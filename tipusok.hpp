#ifndef TYPES_HPP
#define TYPES_HPP

#ifdef MEMTRACE
 #include "memtrace_gtest/memtrace.h"
 #include "memtrace_gtest/gtest_lite.h"
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