/*
#include<iostream>
#include<C:\Users\malte\source\repos\salong bokning\salong bokning\header.h>
#include<vector>

using namespace std;

int main() {
	
	std::vector< std::vector< int > > a;
	a.push_back(vector<int>());
	a.push_back(vector<int>());
	a[0].push_back(5);
	a[1].push_back(6);
	cout << a[0][0] << " " << a[1][0];
	

	

	a =Salong(30, 5);
	b =Salong(25, 5);
	c =Salong(60, 10);
	d.Salong(80, 10);
	e =Salong(120, 12);

	bool onoff = true;
	int inp1;
	char inp2;
	int inp3;


	while (onoff = true) {
		cout << "Salong 1: " << a.getLedigaPlatser() << " lediga platser av " << a.getAntalPlatser() << " totalt" << endl;
		cout << "Salong 2: " << b.getLedigaPlatser() << " lediga platser av " << b.getAntalPlatser() << " totalt" << endl;
		cout << "Salong 3: " << c.getLedigaPlatser() << " lediga platser av " << c.getAntalPlatser() << " totalt" << endl;
		cout << "Salong 4: " << d.getLedigaPlatser() << " lediga platser av " << d.getAntalPlatser() << " totalt" << endl;
		cout << "Salong 5: " << e.getLedigaPlatser() << " lediga platser av " << e.getAntalPlatser() << " totalt" << endl;
		cout << ""
	}

}
*/

// biografbokning.cpp
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <Windows.h>

#include "C:\Users\malte\source\repos\salong bokning\salong bokning\header.h"

using namespace std;

// Anropa denna för att enkelt kunna få åäö rätt utskriva
void setWesternEuropeanCodePage() {
    SetConsoleOutputCP(1252);
    SetConsoleCP(1252);
}

vector<Salong> salonger;

void init()
{
    // Konstruera och lägg till 5 salonger med olika antal platser och
    // antal stolar per rad
    salonger.push_back(Salong(30, 5));
    salonger.push_back(Salong(25, 5));
    salonger.push_back(Salong(60, 10));
    salonger.push_back(Salong(80, 10));
    salonger.push_back(Salong(120, 20));
    salonger.push_back(Salong(130, 20));
}

void bokaSalong(int salongnr)
{
    while (true) {
        int n = salongnr - 1;
        cout << "--- Salong " << salongnr << " ---" << endl;
        salonger[n].skrivutStolar();

        cout << endl << "Boka (b), avboka (a) eller tillbaks (x)? ";
        string kommando;
        cin >> kommando;

        if (kommando == "x")
            break;

        if (kommando == "a" || kommando == "b") {
            cout << "Vilken plats? ";
            int stolnr;
            cin >> stolnr;
            if (kommando == "b") {
                salonger[n].bokaPlats(stolnr);
                cout << "Bokade plats: " << stolnr << endl << endl;
            }
            else {
                salonger[n].avbokaPlats(stolnr);
                cout << "Avbokade plats: " << stolnr << endl << endl;
            }
        }
    }
}

int main()
{
    setWesternEuropeanCodePage();
    init();

    while (true) {
        cout << endl << "========== Biografbokning v1.0 =========" << endl;
        for (unsigned int i = 0; i < salonger.size(); i++) {
            int antalplatser = salonger[i].getAntalPlatser();
            int ledigaplatser = salonger[i].getLedigaPlatser();
            cout << "  Salong " << i + 1 << ": " << ledigaplatser << " lediga platser av "
                << antalplatser << " totalt" << endl;
        }
        cout << "Vilken salong (1-" << salonger.size() << ")? ";
        int salong;
        cin >> salong;
        cout << endl;
        bokaSalong(salong);
    }
}
