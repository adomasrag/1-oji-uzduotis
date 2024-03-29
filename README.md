# 1-oji-uzduotis V1.0

## Programos aprašymas:
   Programa skirta apskaičiuoti studentų galutinius balus pagal įvestus duomenis.
   
   Galutinis balas = 0.4 * namų darbų vidurkis/mediana + 0.6 egzamino pažymys.
   
   Paleidus programą, vartotojui leidžiama pasirinkti, ką jis norės atlikti su programa.
   
   Toliau jam leidžiama pasirinkti, kaip bus skaičiuojamas pažymys už visus namų darbus - pagal vidurkį ar medianą.
   
   Galimi studento duomenys:
   - Studento vardas,
   - Studento pavardė,
   - Studento namų darbų pažymiai (vartotojas jų gali įvesti kiek tik nori, pažymiai gali būti generuojami atsitiktinai),
   - Studento egzamino pažymys (galima įvesti arba generuoti atsitiktinai),
   
   Vartotojui nusprendus, kokiu būdu jis norės, kad programa veiktų, programa ekrane  atvaizduoja išveda nurodytus galimus studento duomenis ir pasrinktinai galutinį balą..

# Naudojimosi instrukcija

Paleidus programą:
- Vartotojui leidžiama pasirinkti, kaip jis norėtų, kad programa veiktų (duomenis pačiam įvesti, duomenis generuoti, nuskaityti iš failo).
- Pasirinkus Rankinį įvedimą:
   - Leidžiama pačiam mechaniškai įvesti studentų duomenis.
- Pasirinkus Atsitiktinį įvedimą:
   - Leidžiama įvesti studento vardą, pavardę, studentų skaičių ir namų darbų skaičių, pažymiai generuojami atsitiktinai.
- Pasirinkus Nuskaitymą iš failo:
   - Leidžiama įvesti failo pavadinimą, nuo kurio yra nuskaitomi duomenys ir išsaugomi struktūroje programoje.
- Pasirinkus Generavimą failų:
   - Sugeneruojami penki skirtingų dydžių failai, jie surikiuojami į dvi grupes ir sukuriami failai toms grupėms išvesti. Programa atlieka veikimo spartos analizę.

Taip pat, pasirinkus vieną iš trijų pirmų pasirinkimų, leidžiama vartotojui pasirinkti, ar jis norės išvedimo metu pateikti galutinį balą apskaičiuota su mediana ar su vidurkiu.


Galimos versijos:

# V0.1

## Programos aprašymas:
   ### Programa realizuota 2 būdais:
   1. ***V0.1 - array.***
      Studentų įvedimui ir studento namų darbų įvedimui naudoja dinaminškai reguliuojamus masyvus.
      
   2. ***V0.1 - vector.***
      Studentų įvedimui ir studento namų darbų įvedimui naudoja vektorius. Taip pat naudojami vektorių metodai tokie kaip size() ir t.t.
   
   Programų funkcionalumas toks pats.
   
# V0.2

## Programos aprašymas (pakeitimai nuo V0.1):
   - Tobulinama tik su vektoriais padaryta programa.
   - Patobulintas programos veikimas (pritaikyti geresni vektorių naudojimo metodai, pakeistas duomenų išvedimas, kad vizualiai atrodytų taip, kaip nurodyta reikalavimuose)
   - Vartotojas gali pasirinkti, jog duomenys būtų skaitomi iš failo. Vartotojas turi įvesti norimo nuskaityti failo pavadinimą. Failo duomenys talpinami į vektoriaus struktūros 'Studentas' atitinkamą dalį.
   - Rezultatai išvedami į ekraną. Šioje versijoje studentai yra rūšiuojami pagal pavardę. 

# V0.3

## Programos aprašymas (pakeitimai nuo V0.2):
- Pridėtas Exception Handling, kuris išveda "Klaida", kuomet įvesti duomenys neatitinka reikalavimų skirtų būtent tiems kintamiesiems (pvz.: pažymiai negali būti string ar char tipo).
- Programa išskaidyta į skirtingus *.h ir *.cpp tipo failus.

# V0.4

## Programos aprašymas (pakeitimai nuo V0.3):
**Sukurtas failų generatorius:**
  - Vartotojui pridėtas pasirinkimas failams generuoti. Sukuriami 5 atsitiktiniai studentų tekstiniai failai - turinys 1000, 10000, 100000, 1000000, 10000000 studentų.

**Studentai rikiuojami į dvi grupes (toliau išvedami į atskirus failus):**
  - Galutinis balas pagal vidurkį < 5 - „Vargsiukai“
  - Galutinis balas pagal vidurkį >= 5 - „Kietiakiai“

**Atlikta programos veikimo spartos analizė:**
  - Atsitiktinio failo sugeneravimo laikas;
  - Duomenų nuskaitymo iš failo laikas;
  - Studentų rikiavimo į dvi grupes laikas;
  - Surūšiuotų studentų išvedimo į du naujus failus laikas;
  - Atsitiktinio failo testavimo laikas.

|Failo dydis ->                                           |1000  |10000  |100000  |1000000  |10000000|
|---|---|---|---|---|---|
|Atsitiktinio failo sugeneravimo laikas                   | 0.014 | 0.032 | 0.339 | 2.317 | 20.977 | 
|Duomenų nuskaitymo iš failo laikas                       | 0.012 | 0.055 | 0.761 | 4.394 | 38.222 | 
|Studentų rikiavimo į dvi grupes laikas         | 0.003 | 0.009 | 0.085 | 0.652 | 5.462 | 
|Surūšiuotų studentų išvedimo į du naujus failus laikas                              | 0.022 | 0.113 | 0.900 | 9.089 | 70.472 | 
|Atsitiktinio failo testavimo laikas       | 0.192 | 0.215 | 2.113 | 16.597 | 136.190 | 

Laikas duotas sekundėmis. Laikas suapvalintas iki trijų skaičių po kablelio.

# V0.5

## Programos aprašymas (pakeitimai nuo V0.4):

- Programa parašyta su trijų tipų konteineriais, su std::vector, std::list ir std::deque.
- Tikrinama, su kurio tipo konteineriais programa veiks sparčiausiai.

|| Kont. tipas | 1 000  | 10 000 | 100 000 | 1 000 000 | 10 000 000 |
| --- | --- | --- | --- | --- | --- | --- |
| Nuskaitymas|Vector|0.004|0.032|0.31|3.16|31.10|
||List|0.003|0.051|0.331|3.731|24.838|
||Deque|0.005|0.050|0.471|3.851|34.296|
| Rūšiavimas|Vector|0.000|0.001|0.01|0.12|1.12|
||List|0.000|0.001|0.02|0.52|9.11|
||Deque|0.003|0.032|0.505|5.631|69.831|
| Skirstymas|Vector|0.000|0.002|0.02|0.26|3.08|
||List|0.000|0.002|0.03|0.26|2.85|
||Deque|0.000|0.007|0.077|0.488|5.840|

Laikas duotas sekundėmis. Laikas buvo apvalinamas iki trijų skaičių po kablelio.

## Testavimo sistemos parametrai:
CPU: Intel(R) Core(TM) i5-7200U CPU @ 2.50GHz (2 branduoliai (4 loginiai))

RAM: 8 GB

SSD: 256 GB MICRON 1100 MTFDDAV256TBN


# V1.0

## Programos aprašymas (pakeitimai nuo V0.5):

 - Optimizuota studentų rūšiavimo (dalijimo) į dvi kategorijas ("vargsiuku" ir "kietiakiu") realizaciją: t.y. visiems trims konteinerių tipams (vector, list ir deque) išmatuota veikimo sparta priklausomai nuo studentų dalijimo į dvi kategorijas strategijos:

 - 1 strategija: Bendro studentai konteinerio (vector, list ir deque tipų)
skaidymas (rūšiavimas) į du naujus to paties tipo konteinerius:

 - 2 strategija: Bendro studentų konteinerio (vector, list ir deque) skaidymas (rūšiavimas)
panaudojant tik vieną naują konteinerį: "vargsiukai".

Gauti rezultatai:

| Kont. tipas | Strategija | 1 000  | 10 000 | 100 000 | 1 000 000 | 10 000 000 |
|--- | --- | --- | --- | --- | --- | --- |
|Vector|1 str.|0.000|0.005|0.074|0.512|5.375|
||2 str.|0.000|0.010|0.070|0.707|7.916|
|List|1 str.|0.001|0.008|0.079|0.666|8.400|
||2 str.|0.001|0.009|0.104|0.819|9.312|
|Deque|1 str.|0.000|0.005|0.055|0.416|4.751|
||2 str.|0.000|0.010|0.077|0.768|10.472|

Laikas duotas sekundėmis. Laikas buvo apvalinamas iki trijų skaičių po kablelio.
