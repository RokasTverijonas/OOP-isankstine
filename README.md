# Objektinio programavimo egzamino (išankstinė) užduotis

## Aprašymas

Programa nuskaito tekstinį failą ir skaičiuoja kiek kartų žodžiai pasikartoja tekste.

## Funkcionalumas

- Skaičiuoja kiek kartų žodžiai pasikartoja tekste
- Sukuria cross-reference tipo lentelę, kurioje nurodoma kuriose eilutėse žodis pasikartojo
- Randa URL adresus tekste
- Išveda rezultatus į skirtingus failus

## Naudojimosi instrukcija

1. Nusiklonuokite repozitoriją
   
   ```
   git clone https://github.com/RokasTverijonas/OOP-isankstine.git
   ```
2. Į failą "tekstas.txt" įklijuokite savo tekstą

3. Įsidiekite CMake

4. Projekto kompiliavimas su CMake
   
   ```
   cd OOP-isankstine
   mkdir build
   cd build
   cmake ..
   cmake --build .
   ```
5. Paleiskite programą
   
   ```
   cd build/debug
   ./programa
   ```
6. Raskite rezultatų failus build/debug direktorijoje

## Reikalavimai

- CMake 3.10
- C++ 20