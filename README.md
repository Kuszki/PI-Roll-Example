[![QMake](https://github.com/Kuszki/PI-Roll-Example/actions/workflows/qmake.yml/badge.svg)](https://github.com/Kuszki/PI-Roll-Example/actions/workflows/qmake.yml)

# PI-Roll-Example
Przykładowy projekt Qt - symulacja rzutu kostką

Projekt stanowi demonstracje tworzenia interfejsu przy użyciu biblioteki
Qt z wykorzystaniem okna dialogowego i podstawowych kontrolek. Dodatkowo
została zaprezentowana koncepcja sygnałów i slotów demonstrując różne
sposoby łączenia zdarzeń. Program został skomentowany w stylu Doxygen.

## Budowanie
- Skonfigurować narzędzia `qmake`, `git` oraz dowolny kompilator `C++`
- Sklonować repozytorium: `git clone https://github.com/Kuszki/PI-Roll-Example`
- Utworzyć katalog budowania: `mkdir build-PI-Roll-Example`
- Przejść do katalogu budowania: `cd build-PI-Roll-Example`
- Uruchomić qmake: `qmake ../PI-Roll-Example`
- Zbudować projekt: `make` lub `nmake`
- Uruchomić program: `./PI-Roll-Example`
