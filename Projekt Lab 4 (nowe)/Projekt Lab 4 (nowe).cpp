
#include <iostream>
#include <stdlib.h> // cls do czyszczenia ekranu
using namespace std;

float KtoF(float kelvin) {
    float wynik = (((kelvin - 273.15) * 9.0 / 5.0) + 32);
    return wynik;
}

float KtoC(float kelvin) {
    float wynik = (kelvin - 273.15);
    return wynik;
}

float CtoK(float celsius) {
    float wynik = (celsius + 273.15);
    return wynik;
}
 
float CtoF(float celsius) {
    float wynik = (celsius * 9.0 / 5.0) + 32.0;
    return wynik;
}

float FtoK(float fahr) {
    float wynik = (5.0 / 9.0) * (fahr + 459.67);
    return wynik;
}

float FtoC(float fahr) {
    float wynik = (5.0 / 9.0) * (fahr - 32.0);
    return wynik;
}

void program() {
    cout << "Wybierz program: " << endl;
    cout << "1 - przelicz Fahr -> Celsius" << endl;
    cout << "2 - przelicz Fahr -> Kelwin" << endl;
    cout << "3 - przelicz Celsius -> Fahr" << endl;
    cout << "4 - przelicz Celsius -> Kelwin" << endl;
    cout << "5 - przelicz Kelwin -> Celsius" << endl;
    cout << "6 - przelicz Kelwin -> Fahr" << endl;
    cout << "7 - zakoncz dzialanie programu" << endl;
}

int check(float temp, char stopnie) {
    switch (stopnie) {
    case 'F':
        if (temp < -459.67) return -999;
        else return temp;
    case 'C':
        if (temp < -273.15) return -999;
        else return temp;
    case 'K':
        if (temp < 0) return -999;
        else return temp;
    default:
        return -999;
    }
}

int main() {
    int numerprogramu;

    for (int i = 0;; i++) { // tak jak w Twoim oryginalnym kodzie
        system("cls");

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
            break;
        }
        default:
            cout << "Podano zly numer programu" << endl;
        }
        cout << "Aby przejsc dalej, podaj wcisnij enter: ";
        cin.ignore();
        cin.get();
    }

    return 0;
}