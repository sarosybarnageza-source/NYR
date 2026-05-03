# Úszóegyesületi Nyilvántartó Rendszer (NYR)

Ez a szoftver a Budapesti Műszaki és Gazdaságtudományi Egyetem (BME VIK) **A programozás alapjai 2** című tárgyának keretében készül nagy házi feladatként.

## A projekt célja

A program egy uszodai bérlet- és jegykezelő rendszer, amely egy úszóegyesület napi adminisztrációs terheinek digitalizálására született. Célja a papíralapú és táblázatkezelőben vezetett adatok kiváltása, a hibalehetőségek (elfelejtett befizetések, lejárt bérletek) minimalizálása és statisztikák készítése.

## Technikai specifikációk (NHF szigorítások)
A projekt megfelel a tárgy szigorú követelményeinek:
- **STL-mentesség:** A rendszer nem használhat standard tárolókat (pl. `std::vector`, `std::list`). Helyette egy saját fejlesztésű, sablon alapú `Tarolo<T>` osztály kezeli a dinamikus memóriát.
- **Heterogén kollekciók:** A tranzakciók (befizetések) kezelése heterogén módon, bázisosztály pointerek tárolásával valósul meg, támogatva a különböző fizetési módokat.
- **Manuális memóriakezelés:** A rendszer implementálja a szükséges destruktorokat és másoló mechanizmusokat a memóriaszivárgás elkerülése érdekében[cite: 22].
- **Dátumkezelés:** Saját `Date` osztály az időpontok platformfüggetlen kezelésére.

## Főbb funkciók
- **Gyerekek nyilvántartása:** ID-alapú kereshető lista, részletes adatlapok (születési idő, szülői adatok, versenyzői státusz).
- **Bérletkezelés:** Rugalmas bérletkonstrukciók, automatikus alkalomszám-levonás és testvérkedvezmény kezelése.
- **Pénztár és tranzakciók:** Készpénzes és átutalásos befizetések rögzítése, előzmények visszakeresése.
- **Statisztika:** Napi bevételek és edzői csoportokra lebontott aktivitási jelentések.
- **Adatbiztonság:** TXT alapú adattárolás az `NYRdata` mappában, automatikus mentési lehetőséggel.

## Projektstruktúra
- `Rendszer`: A központi vezérlő (Controller), amely összefogja a tárolókat és a konfigurációt.
- `Gyerek`: A sportolók adatait és saját jelenléti/befizetési listáit kezelő osztály.
- `Tarolo`: Saját generikus, dinamikus tömb implementáció.
- `Berlet`: Az alkalmakat és típusokat kezelő üzleti logika.
- `Edzo`: Az edzők alapadatait tároló osztály.

## Fejlesztési ütemterv

- **Várható befejezés:** 2026. május 26.
- **Implementáció:** C++ (OOP alapokon).
- **Státusz:** Tervezés és specifikáció kész.

## Speciális szabályok a rendszerben

- **Soft Delete:** A törölt adatok nem vesznek el azonnal, 30 napig visszaállíthatóak az admin felületen.
- **Bérlet kiegészítés:** Új bérlet vásárlásakor a megmaradt alkalmak hozzáadódnak az új bérlethez.
- **Próba bérlet:** Egy gyerek csak egyszer vehet igénybe próba bérletet, melynek ára később beszámítható egy rendes bérlet vásárlásába.
