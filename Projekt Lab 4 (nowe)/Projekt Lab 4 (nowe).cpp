
#include <iostream>
#include <stdlib.h> // cls do czyszczenia ekranu
#include <cstdlib> // Potrzebne do rand() i srand()
#include <ctime>   // Potrzebne do time()

int DataCounter = 0;//wskazuje na pierwszy pusty elemt tablicy
double pamiec[100]; // przechowuje temperatury: stare i nowe

char jednostka[100]; //przechowywanie jednostki temp podanej i obliczonej

#include "headerFile.h" //cudzysłów!!
using namespace std;



int main() {
    int numerprogramu;
    int entitytoRemove;
    int toModificate;
    int randomData;

    
    for (int i = 0;; i++) { 
        
        system("cls"); // czyszczenie ekranu

        if (DataCounter > 100) { // ostrzeżenie o zapełnieniu pamięci
            cout << "Zapelniono pamiec: przeliczenia nie będą już zapisywane. " << endl;
        }

        cout << "Ktory program chcesz uruchomic ?" << endl;
        program();
        cin >> numerprogramu;

        if (numerprogramu == 7) {
            cout << "Koniec programu" << endl;
            return 0;
        }

        switch (numerprogramu) {
        case 1: {
            float fahr, celsius;
            cout << "Podaj wartosc Fahr: ";
            cin >> fahr;

            int wynik = check(fahr, 'F');
            if (wynik == -999) {
                cout << "Podano zly przedzial temperatury" << endl;
            }
            else {
                celsius = FtoC(fahr);
                cout << fahr << " Fahr to " << celsius << " Celsius " << endl;
            }
            pamiec[DataCounter] = fahr; //przechowywanie temp podanej
            jednostka[DataCounter] = 'F';
            DataCounter++;
            pamiec[DataCounter] = celsius; // przechowywanie temp obliczonej
            jednostka[DataCounter] = 'C'; 
            DataCounter++;
            break;
        }
        case 2: {
            float fahr, kelvin;
            cout << "Podaj wartosc Fahr: ";
            cin >> fahr;

            int wynik = check(fahr, 'F');
            if (wynik == -999) {
                cout << "Podano zly zakres temperatury" << endl;
            }
            else {
                kelvin = FtoK(fahr);
                cout << fahr << " Fahr to " << kelvin << " Kelvin " << endl;
            }
            pamiec[DataCounter] = fahr;
            jednostka[DataCounter] = 'F';
            DataCounter++;
            pamiec[DataCounter] = kelvin;
            jednostka[DataCounter] = 'K';
            DataCounter++;
            break;
        }
        case 3: {
            float celsius, fahr;
            cout << "Podaj wartosc Celsius: ";
            cin >> celsius;

            int wynik = check(celsius, 'C');
            if (wynik == -999) {
                cout << "Podano zly zakres temperatury" << endl;
            }
            else {
                fahr = CtoF(celsius);
                cout << celsius << " Celsius to " << fahr << " Fahr " << endl;
            }
            pamiec[DataCounter] = celsius;
            jednostka[DataCounter] = 'C';
            DataCounter++;
            pamiec[DataCounter] = fahr;
            jednostka[DataCounter] = 'F';
            DataCounter++;
            break;
        }
        case 4: {
            float celsius, kelvin;
            cout << "Podaj wartosc Celsius: ";
            cin >> celsius;

            int wynik = check(celsius, 'C');
            if (wynik == -999) {
                cout << "Podano zly zakres temperatury" << endl;
            }
            else {
                kelvin = CtoK(celsius);
                cout << celsius << " Celsius to " << kelvin << " Kelvina " << endl;
            }
            pamiec[DataCounter] = celsius;
            jednostka[DataCounter] = 'C';
            DataCounter++;
            pamiec[DataCounter] = kelvin;
            jednostka[DataCounter] = 'K';
            DataCounter++;
            break;
        }
        case 5: {
            float kelvin, celsius;
            cout << "Podaj wartosc Kelvin: ";
            cin >> kelvin;

            int wynik = check(kelvin, 'K');
            if (wynik == -999) {
                cout << "Podano zly zakres temperatury" << endl;
            }
            else {
                celsius = KtoC(kelvin);
                cout << kelvin << " Kelvin to " << celsius << " Celsius " << endl;
            }
            pamiec[DataCounter] = kelvin;
            jednostka[DataCounter] = 'K';
            DataCounter++;
            pamiec[DataCounter] = celsius;
            jednostka[DataCounter] = 'C';
            DataCounter++;
            break;
        }
        case 6: {
            float kelvin, fahr;
            cout << "Podaj wartosc Kelvin: ";
            cin >> kelvin;

            int wynik = check(kelvin, 'K');
            if (wynik == -999) {
                cout << "Podano zly zakres temperatury" << endl;
            }
            else {
                fahr = KtoF(kelvin);
                cout << kelvin << " Kelvin to " << fahr << " Fahr " << endl;
            }
            pamiec[DataCounter] = kelvin;
            jednostka[DataCounter] = 'K';
            DataCounter++;
            pamiec[DataCounter] = fahr;
            jednostka[DataCounter] = 'F';
            DataCounter++;
            break;
        }
        case 8: {
            cout << "Wybierz ktora historie chcesz zobaczyc: " << endl;
            wersjahistorii();
            int wersja;
            cin >> wersja;

            if (DataCounter != 0) {
                switch (wersja) {
                case 1: {
                    for (int i = 0; i < DataCounter; i += 2) {
                        if (jednostka[i] == 'C') {
                            cout << pamiec[i] << jednostka[i] << '\t';
                            cout << pamiec[i + 1] << jednostka[i + 1] << endl;
                        }
                    }
                    cout << endl;
                    break;
                }
                case 2: {
                    for (int i = 0; i < DataCounter; i += 2) {
                        if (jednostka[i] == 'F') {
                            cout << pamiec[i] << jednostka[i] << '\t';
                            cout << pamiec[i + 1] << jednostka[i + 1] << endl;
                        }
                    }
                    cout << endl;
                    break;
                }
                case 3: {
                    for (int i = 0; i < DataCounter; i += 2) {
                        if (jednostka[i] == 'K') {
                            cout << pamiec[i] << jednostka[i] << '\t';
                            cout << pamiec[i + 1] << jednostka[i + 1] << endl;
                        }
                    }
                    cout << endl;
                    break;
                }
                case 4: {
                    for (int i = 0; i < DataCounter; i += 2) {
                        cout << pamiec[i] << jednostka[i] << '\t';
                        cout << pamiec[i + 1] << jednostka[i + 1] << endl;
                    }
                    cout << endl;
                    break;
                }
                }
            }
            else {
                cout << "Historia nie istnieje. " << endl;

            }
            break;
        }
        case 9: { //czyscimy ekran i wyswietlanie calej historii
            system("cls");

            for (int i = 0; i < DataCounter; i += 2) {
                cout << ((i/2)+1) << "." << '\t' << pamiec[i] << jednostka[i] << '\t';
                cout << pamiec[i + 1] << jednostka[i + 1] << endl;
            }
            cout << endl;
            cout << "Ktora linie chcesz usunac? " << endl;
            cin >> entitytoRemove;

            if (entitytoRemove >= DataCounter) {
                cout << "Taki element nie istnieje. " << endl;
            }
            else {
                for (int i = entitytoRemove * 2 - 2; i <= DataCounter - 1; i++) {
                    pamiec[i] = pamiec[i + 2];
                }
                DataCounter -= 2;
                }
            break;
        }
        case 10: {
            for (int i = 0; i < DataCounter; i += 2) {
                cout << ((i / 2) + 1) << "." << '\t' << pamiec[i] << jednostka[i] << '\t';
                cout << pamiec[i + 1] << jednostka[i + 1] << endl;
            }
            cout << endl;
            cout << "Ktora linie chcesz zmodyfikowac? ";
            cin >> toModificate;
            modyfikacja(toModificate);
            break;
              }

        case 11: {
            string odp;
            cout << "Ile losowych temperatur przeliczyc? ";
            cin >> randomData;

            if ((DataCounter + randomData * 2) < 100) {
                losowanie(randomData);
            }
            else {
                cout << "Czy wygenerowac tylko tyle losowek ile zostalo miejsca?" << endl;
                cin >> odp;
                if (odp == "tak") {
                    randomData = ((100 - DataCounter) / 2);
                    losowanie(randomData);
                }
                if (odp == "nie") {
                    break;
                }
            }
            wyswietlanie();
            break;
        }
        default:
            cout << "Podano zly numer programu" << endl;
        }
        cout << "Podano juz: " << (DataCounter + 1)/2 << " temperatur. " << endl;
        cout << "------------------------------------------" << endl;
        cout << "Aby przejsc dalej, wcisnij enter: ";
        cin.ignore();
        cin.get();
    }

    return 0;
}