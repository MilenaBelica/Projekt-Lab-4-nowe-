#pragma once
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
    cout << "8 - pokaz historie" << endl;
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

void wersjahistorii(){
    cout << "1 - Tylko C na K/F" << endl;
    cout << "2 - Tylko F na C/K" << endl;
    cout << "3 - Tylko K na C/F" << endl;
    cout << "4 - Cala Historia" << endl;
}
