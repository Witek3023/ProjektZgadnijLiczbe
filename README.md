# ProjektZgadnijLiczbe
Stworzyć grę "Zgadnij liczbę" w języku C++ uruchamianą w wierszu poleceń zgodnie z
poniższymi wymaganiami.
Projekt gra ma składać się z:
- minimum jednego pliku .cpp,
- readme.md z instrukcją do gry (uruchomienie, sterowanie, możliwości),

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
- [ ] ekran wyników podzielony na poziomy trudności, które możemy przełączać
- [ ] tryb zakładu, o który zapyta gra po wybraniu poziomu trudności - jeśli tak, to gracz
podaje maksymalną liczbę prób w następnej rozgrywce
- [x] (poprawie)stwórz prymitywny "interfejs graficzny"
- [x] zapis i wczytywanie wyników do pliku (nice to have)
- [ ] animacje
- [ ] try catch przy kazdym wyborze
- [ ] brak top 5 w wyborze switch jesli nie ma top 5
- [ ] while w kazdym menu
- [ ] nowy typ w result bool czy tryb zakladu
