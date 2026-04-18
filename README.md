# Úszóegyesületi Nyilvántartó Rendszer (NYR)

Ez a szoftver a Budapesti Műszaki és Gazdaságtudományi Egyetem (BME VIK) **A programozás alapjai 2** című tárgyának keretében készül nagy házi feladatként.

## A projekt célja

A program egy uszodai bérlet- és jegykezelő rendszer, amely egy úszóegyesület napi adminisztrációs terheinek digitalizálására született. Célja a papíralapú és táblázatkezelőben vezetett adatok kiváltása, a hibalehetőségek (elfelejtett befizetések, lejárt bérletek) minimalizálása és statisztikák készítése.

## Főbb funkciók

A rendszer nyolc fő modulra tagolódik a könnyű kezelhetőség érdekében:

- **Gyerekek nyilvántartása:** ID-alapú kereshető lista, csoportok szerinti bontás és részletes adatlapok.
- **Pénztár és bérletkezelés:** Jegy- és bérletvásárlás rögzítése, automatikus alkalomszám-levonás és testvérkedvezmény kezelése.
- **Tranzakciók és korrekciók:** Befizetési előzmények visszakeresése, dátumszűrés és bérletadatok kézi módosítása.
- **Statisztika és jelentés:** Napi bevételek összesítése és edzői csoportokra lebontott aktivitási statisztikák készítése.
- **Adminisztráció:** Jelszóval védett felület az árak módosítására, az edzők listájának kezelésére és az adatok karbantartására.
- **Adatbiztonság:** Automatikus mentés 5 percenként, manuális biztonsági mentés (időbélyeggel) és importálási lehetőség.

## Technikai részletek

- **Platformfüggetlen:** Elsősorban Linux környezetre tervezve.
- **Adattárolás:** Az adatok JSON formátumban tárolódnak egy dedikált adatmappában (`NYRdata`).
- **Objektumorientált felépítés:** A rendszer osztályokba szervezett (`Gyerek`, `Berlet`, `Befizetes`, `Edzo`, `Config`), melyeket egy központi `Rendszer` osztály fog össze.
- **Kimenetek:** A képernyős táblázatok mellett lehetőség van az adatok tagolt, emberi olvasásra alkalmas TXT fájlba történő exportálására is.

## Fejlesztési ütemterv

- **Várható befejezés:** 2026. május 26.
- **Implementáció:** C++ (OOP alapokon).
- **Státusz:** Tervezés és specifikáció kész.

## Speciális szabályok a rendszerben

- **Soft Delete:** A törölt adatok nem vesznek el azonnal, 30 napig visszaállíthatóak az admin felületen.
- **Bérlet kiegészítés:** Új bérlet vásárlásakor a megmaradt alkalmak hozzáadódnak az új bérlethez.
- **Próba bérlet:** Egy gyerek csak egyszer vehet igénybe próba bérletet, melynek ára később beszámítható egy rendes bérlet vásárlásába.
