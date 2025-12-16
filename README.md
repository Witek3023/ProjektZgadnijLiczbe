
# ProjektZgadnijLiczbe - Gra "Zgadnij Liczbę"

Gra oferuje:
- ✅ 3 poziomy trudności
- ✅ System zapisów wyników
- ✅ Interaktywny TOP 5 z podziałem na poziomy
- ✅ Tryb zakładu dla dodatkowych wyzwań
- ✅ Kolorowy interfejs
- ✅ Losowe komunikaty
- ✅ Pełna obsługa błędów
- ✅ Animacje i efekty specjalne

**Miłej zabawy!**

## HOW TO

Gra "Zgadnij liczbę" napisana w języku C++ z interfejsem tekstowym. Celem gry jest odgadnięcie wylosowanej liczby w jak najmniejszej ilości prób.

## Instalacja i uruchomienie
Kompilacja lub pobranie gotowych plików [tutaj](https://github.com/Witek3023/ProjektZgadnijLiczbe/releases)

### 1. Klonowanie repozytorium
```bash
git clone https://github.com/Witek3023/ProjektZgadnijLiczbe.git
cd ProjektZgadnijLiczbe
```

### 2. Kompilacja
```bash
# Kompilacja wszystkich plików źródłowych
g++ src/*.cpp -o game
```

### 3. Uruchomienie
```bash
./game
```

## Jak grać

### Menu główne
Po uruchomieniu gry zobaczysz menu główne:
```
 ########################################
 #         GRA ZGADNIJ LICZBE           #
 ########################################
 #                                      #
 #       [1] Rozpocznij nowa gre        #
 #          [2] Sprawdz TOP 5           #
 #             [0] Wyjscie              #
 #                                      #
 ########################################
Twoj wybor:
```

### Rozpoczęcie gry
1. Wybierz opcję `1` z menu głównego
2. Wybierz poziom trudności:
   - **1. Łatwy**: zakres 1-50,
   - **2. Średni**: zakres 1-100,
   - **3. Trudny**: zakres 1-250,

3. **Opcjonalnie**: Wybierz tryb zakładu (podaj maksymalną liczbę prób)

4. Zaczyna się gra - zgaduj liczbę!

### Zasady gry
- Program wylosuje liczbę z wybranego zakresu,
- W każdej turze podaj swoją propozycję,
- Program podpowie czy liczba jest **za mała** czy **za duża**,
- Celem jest odgadnięcie liczby w jak najmniejszej ilości prób,
- Po sukcesie podaj swoje imię - wynik zostanie zapisany!,

## System wyników (TOP 5)

### Dostęp do wyników
- Opcja `2` w menu głównym (widoczna tylko gdy są zapisane wyniki),
- Wyniki są automatycznie wczytywane przy starcie gry,
- Wyniki są automatycznie zapisywane przy wyjściu z gry,
- Aby załadować przykładowe wyniki zmień nazwe pliku wyniki.bak na wyniki.txt,

### Przeglądanie wyników
- Wyniki są podzielone na poziomy trudności
- Wyświetlane są najlepsze wyniki (najmniej prób)
- Maksymalnie 5 wyników na poziom

### Sterowanie w TOP 5
- **A**: Poprzedni poziom trudności
- **D**: Następny poziom trudności
- **Enter**: Powrót do menu głównego

## Funkcje specjalne

### Tryb zakładu
- Po wybraniu poziomu trudności gra zapyta o tryb zakładu
- Jeśli wybierzesz "tak", podajesz maksymalną liczbę prób
- Jeśli przekroczysz limit - przegrywasz!

### Losowe komunikaty
Gra używa różnych komunikatów zamiast powtarzania tych samych:
- "Za mało!" / "Za dużo!"
- "Spróbuj większą liczbę!" / "Spróbuj mniejszą liczbę!"
- I inne wariacje...

### Kolorowy interfejs
- Menu główne ma kolorowe tło dla lepszej czytelności
- Wyniki są wyróżnione kolorami

### Easter Egg
- W menu głównym wybierz opcję `3` dla niespodzianki! 🎉

<details>
<summary>TODO</summary>

Stworzyć grę "Zgadnij liczbę" w języku C++ uruchamianą w wierszu poleceń zgodnie z
poniższymi wymaganiami.
Projekt gra ma składać się z:
- [x] minimum jednego pliku .cpp,
- [ ] readme.md z instrukcją do gry (uruchomienie, sterowanie, możliwości),

### Wymagania:

- [x] ekran powitalny skąd możemy a) rozpocząć nową grę b) sprawdzić aktualne TOP5 (tylko
gdy już jakieś są!)
- [x] na ekranie wyników wyświetlamy TOP5 najlepszych, gdzie będziemy widzieć nazwę
użytkownika, ilość prób, oraz poziom trudności. Z ekranu wyników możemy wrócić do
ekranu powitalnego.
- [x] przed rozpoczęciem gry należy wybrać jeden z poziomów trudności np. łatwy (1-50),
średni (1-100), trudny (1-250)
- [x] podczas gry na ekranie zawsze wyświetla się aktualny numer próby
- [x] w przypadku braku podania prawidłowej liczby, na ekranie dostaniemy komunikat czy
liczba jest za mała czy za duża i zostanie uruchomiona kolejna próba
- [x] w przypadku trafienia prawidłowej liczby dostaniemy komunikat o podanie swojego
imienia.
Po wpisaniu imienia zostaniemy przekierowani do ekranu powitalnego

### Dodatkowo:

- [x] losowe komunikaty zamiast jednego stałego, gdy nie trafimy liczby
- [x] ekran wyników podzielony na poziomy trudności, które możemy przełączać
- [x] tryb zakładu, o który zapyta gra po wybraniu poziomu trudności - jeśli tak, to gracz
podaje maksymalną liczbę prób w następnej rozgrywce
- [x] (poprawie)stwórz prymitywny "interfejs graficzny"
- [x] zapis i wczytywanie wyników do pliku (nice to have)
- [x] animacje
- [x] try-catch przy każdym wyborze     
- [x] brak top 5 w wyborze switch jesli nie ma top 5
- [x] while w kazdym menu
- [x] nowy typ w result bool czy tryb zakladu
- [x] tryb zakladu, error enter liczba prob
</details>
