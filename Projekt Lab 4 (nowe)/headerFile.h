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
    cout << "----------------------------------" << endl;
    cout << "8 - pokaz historie" << endl;
    cout << "9 - usun historie" << endl;
    cout << "10 - zmodyfikuj historie" << endl;
    cout << "11 - losowe wypelnianie historii" << endl;
    cout << "----------------------------------" << endl;
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

void modyfikacja(int toModificate) {
    int Temp = 0, c;
    char Jednostkadozamiany; //pierwotna jednostka
    char Jednostka;//jednostka zmieniona

    //pytamay o nowa temp
    cin.ignore(); //zeby gatchar nie odczytywal poprzednich cinów
    cout << "Podaj nowa wartosc temperatury do przeliczenia (np. 10F): ";
    while ((c = getchar()) != EOF) {
        if (c>='0' && c<='9') {
            c = c - '0'; // z kodu ASCII chce otrzymaæ liczbê
            Temp = c + Temp;
            Temp = Temp * 10;
        }
        else if(c == 'F' || c == 'C' || c == 'K') {
            Jednostkadozamiany = c;
            break;
        }
       
    }
    Temp = Temp / 10;
    pamiec[toModificate * 2 - 2] = Temp;
    jednostka[toModificate * 2 - 2] = Jednostkadozamiany;

    //pytamy na jaka temp przeliczyc
    int d;
    cout << "Podaj na jaka jednostke chcesz zamienic ta temperature(C/F/K): ";
    cin >> Jednostka;
   
    while ((d = getchar()) != EOF) {
        if (Jednostka == 'F') {
            if (Jednostkadozamiany == 'C') {
                pamiec[toModificate * 2 - 1] = CtoF(Temp);
                jednostka[toModificate * 2 - 1] = Jednostka;
            }
            else if (Jednostkadozamiany == 'K') {
                pamiec[toModificate * 2 - 1] = KtoF(Temp);
                jednostka[toModificate * 2 - 1] = Jednostka;
            }
            else {
                cout << "Podano zla jednostke. " << endl;
            }

        }
        else if (Jednostka == 'C') {
            if (Jednostkadozamiany == 'K') {
                pamiec[toModificate * 2 - 1] = KtoC(Temp);
                jednostka[toModificate * 2 - 1] = Jednostka;
            }
            else if (Jednostkadozamiany == 'F') {
                pamiec[toModificate * 2 - 1] = FtoC(Temp);
                jednostka[toModificate * 2 - 1] = Jednostka;
            }
            else {
                cout << "Podano zla jednostke. " << endl;
            }

        }
        else if (Jednostka == 'K') {
            if (Jednostkadozamiany == 'C') {
                pamiec[toModificate * 2 - 1] = CtoK(Temp);
                jednostka[toModificate * 2 - 1] = Jednostka;
            }
            else if (Jednostkadozamiany == 'F') {
                pamiec[toModificate * 2 - 1] = FtoK(Temp);
                jednostka[toModificate * 2 - 1] = Jednostka;
            }
            else {
                cout << "Podano zla jednostke. " << endl;
            }

        }
        else {
            cout << "Podano zla jednostke." << endl;
        }
        
        cout << pamiec[toModificate * 2 - 2];
        cout << jednostka[toModificate * 2 - 2]<< '\t';
        cout << pamiec[toModificate * 2 - 1];
        cout << jednostka[toModificate * 2 - 1]<< '\t'<< endl;
        break;
    }
}

void losowanie(int randomData) {
    srand(time(NULL));
    for (int i = DataCounter; i < (DataCounter + randomData * 2); i+=2) {

        char jednostkaCKF[] = { 'C', 'F', 'K' };
        int indeks = rand() % 3;
        char wylosowana = jednostkaCKF[indeks];

        if (wylosowana == 'C') {
            jednostka[i] = 'C';
            int min = -273;
            int max = 727;
            pamiec[i] = min + rand() % (max-min+1);

            char jednostkaKF[] = { 'F', 'K' };
            int indeksKF = rand() % 2;
            char wylosowanaKF = jednostkaKF[indeksKF];

            if (wylosowanaKF == 'K') {
                jednostka[i + 1] = 'K';
                pamiec[i + 1] = CtoK(pamiec[i]);
            }
            if (wylosowanaKF == 'F') {
                jednostka[i + 1] = 'F';
                pamiec[i + 1] = CtoF(pamiec[i]);
            }
       }
        if (wylosowana == 'K') {
            jednostka[i] = 'K';
            int min = 0;
            int max = 1000;
            pamiec[i] = min + rand() % (max - min + 1);

            char jednostkaCF[] = { 'C', 'F' };
            int indeksCF = rand() % 2;
            char wylosowanaCF = jednostkaCF[indeksCF];

            if (wylosowanaCF == 'C') {
                jednostka[i + 1] = 'C';
                pamiec[i + 1] = KtoC(pamiec[i]);
            }
            if (wylosowanaCF == 'F') {
                jednostka[i + 1] = 'F';
                pamiec[i + 1] = KtoF(pamiec[i]);
            }
        }
        if (wylosowana == 'F') {
            jednostka[i] = 'F';
            int min = 0;
            int max = 1000;
            pamiec[i] = min + rand() % (max - min + 1);

            char jednostkaKC[] = { 'C', 'K' };
            int indeksKC = rand() % 2;
            char wylosowanaKC = jednostkaKC[indeksKC];

            if (wylosowanaKC == 'K') {
                jednostka[i + 1] = 'K';
                pamiec[i + 1] = FtoK(pamiec[i]);
            }
            if (wylosowanaKC == 'C') {
                jednostka[i + 1] = 'C';
                pamiec[i + 1] = FtoC(pamiec[i]);
            }
        }
        
    }
    DataCounter = DataCounter + randomData * 2;
}
void wyswietlanie() {
    for (int i = 0; i < DataCounter; i+=2) {
        cout << (i / 2 + 1) << '\t' << pamiec[i] << jednostka[i];
        cout << '\t' << pamiec[i + 1] << jednostka[i + 1] << endl;
    }
}
