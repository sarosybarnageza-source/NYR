# Úszóegyesületi Nyilvántartó Rendszer (NYR)

Ez a szoftver a Budapesti Műszaki és Gazdaságtudományi Egyetem (BME VIK) **A programozás alapjai 2** című tárgyának keretében készült nagy házi feladatként.

## A projekt célja

A program egy uszodai bérlet- és jegykezelő rendszer, amely egy úszóegyesület napi adminisztrációs terheinek digitalizálására született. Célja a papíralapú és táblázatkezelőben vezetett adatok kiváltása, a hibalehetőségek (elfelejtett befizetések, lejárt bérletek) minimalizálása és automatizált statisztikák készítése.

## A program működése

A rendszer egy központi konzolos vagy grafikus felületen keresztül vezérelhető, ahol a felhasználó az alábbi alapvető folyamatokat végezheti el:

### 1. Tagok és edzők kezelése
* **Regisztráció:** Új gyermekek rögzítése a rendszerben (név, születési dátum, szülői adatok, versenyzői státusz megadásával). A rendszer minden taghoz egyedi azonosítót (ID) rendel.
* **Keresés és szűrés:** A tagok listája azonosító vagy név alapján is szűrhető és megtekinthető.
* **Törlés és visszaállítás:** A rendszer támogatja a "soft delete" funkciót, így a törölt tagok adatai nem vesznek el azonnal, szükség esetén visszaállíthatók.

### 2. Bérlet- és jegykezelés
* **Bérletvásárlás:** A tagok különböző típusú bérleteket (4, 8, 12 alkalmas, korlátlan vagy próba) vásárolhatnak.
* **Alkalmak kezelése:** Edzésre való belépéskor a rendszer ellenőrzi a bérlet érvényességét, és automatikusan levon egy alkalmat.
* **Kedvezmények:** A rendszer automatikusan számolja a versenyzői árakat és a beállítható testvérkedvezményeket.

### 3. Pénztár és tranzakciók
* **Befizetések rögzítése:** Minden bérlet- vagy jegyvásárláshoz pénzügyi tranzakció kapcsolódik (készpénz, átutalás vagy egyéb fizetési mód).
* **Előzmények:** A befizetések visszakereshetők, így a gyermekek pénzügyi egyenlege és fizetési előzményei bármikor ellenőrizhetők.

### 4. Adattárolás és statisztika
* **Adatmentés:** A program képes az összes adat (gyermekek, edzők, jelenlétek, befizetések) külső fájlba történő mentésére és onnan való betöltésére.
* **Statisztika:** Az adminisztrátorok jelentéseket készíthetnek a bevételekről és az edzések látogatottságáról egy adott időszakra vonatkozóan.

## Technikai specifikációk (Szigorítások)

A projekt megfelel a tárgy szigorú akadémiai követelményeinek:
* **STL-mentesség:** A rendszer nem használhat standard tárolókat (pl. `std::vector`, `std::list`). Helyette egy saját fejlesztésű, sablon alapú `Tarolo<T>` osztály kezeli a dinamikus memóriát.
* **Manuális memóriakezelés:** A rendszer precíz destruktorokkal és másoló mechanizmusokkal rendelkezik a memóriaszivárgások teljes körű elkerülése érdekében.
* **Dátumkezelés:** Saját fejlesztésű `Date` osztály biztosítja az időpontok platformfüggetlen kezelését és összehasonlítását.

## Fejlesztési ütemterv
* **Várható befejezés:** 2026. május 26.
* **Implementáció:** C++ (OOP alapokon).
* **Státusz:** Tervezés és specifikáció kész.

## Telepítés és futtatás

A projekt lefordításához egy C++11 (vagy újabb) szabványt támogató fordítóra van szükség.

```bash
# Fordítás Makefile segítségével
make

# Futtatás
./nyr