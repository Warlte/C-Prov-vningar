#include<iostream>
#include<random>
#include<windows.h>
#include<C:\Users\malte\source\repos\Project17\Project17\ordlista.h>


using namespace std;
char randomletter(int n);
void setWesternEuropeanCodePage();
void alfabetchecker(char letter);

int main() {
	setWesternEuropeanCodePage();
	bool onoff = true;
	int number = rand() % 29;
	char letter = randomletter(number);
	char test;
	int counter = 1;
	while (onoff == true) {
		cout << "runda " << counter << ". gissa en bokstav(siffran 0 för att ge upp)):" << endl;
		cin >> test;

		if (test == '0') {
			onoff = false;
		}
		
		if (letter == test) {
			cout << "rätt bokstav.";
			onoff = false;
		}

		if (counter >= 15) {
			cout << "ledtråd bokstaven är nummer " << number;
		}
		else if (counter == 10) {
			alfabetchecker(letter);
		}
		else if (counter == 5) {
			if (letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u') {
				cout << "letter is a vowel." << endl;
			}
			else {
				cout << "letter is a consonant." << endl;
			}
		}

		counter++;
	}
}

char randomletter(int n) {
	return "abcdefghijklmnopqrstuvwxyzåäö"[n - 1];
}

void alfabetchecker(char letter) {
	if (letter <= 'm') {
		cout << "letter is in the first half of the alphabet." << endl;
	}
	else {
		cout << "letter is in the second half of the alfabet." << endl;
	}
}

void setWesternEuropeanCodePage() {
	SetConsoleOutputCP(1252);
	SetConsoleCP(1252);
}