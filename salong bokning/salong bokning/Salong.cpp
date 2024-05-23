#include<C:\Users\malte\source\repos\salong bokning\salong bokning\header.h>
#include<iostream>
#include<vector>

Salong::Salong(int totplatser, int radstolar) {
	totalaPlatser = totplatser;
	radMangd = radstolar;
	for (int i = 0; i < totplatser; i++) {
		platser.push_back(0);
	}
	
	
	
	/*
	int rest = totplatser % radstolar;
	int frfrtot = totplatser - rest;
	int counter = 0;
	int counter2frfr = 0;

	while (counter != frfrtot) {
		a.push_back(std::vector<int>());
		for (int i = 0; i < radstolar; i++) {
			a[counter2frfr].push_back(0);
			
			counter++;
		}
		counter2frfr++;
	}
	if (rest != 0) {
		a.push_back(std::vector<int>());
		for (int i = 0; i < rest; i++) {
			a[counter2frfr].push_back(0);
		}
	}
	*/
	
}
bool Salong::bokaPlats(int pos1) {
	//std::cout << bokadePlatser << std::endl;
	if (platser[pos1-1] == 1 || pos1 - 1 > platser.size()) {
		std::cout << "redan bokad" << std::endl;
		return false;
	}
	else {
		bokadePlatser++;
		platser[pos1-1] = 1;
		return true;
	}
}
bool Salong::avbokaPlats(int pos1) {
	//std::cout << bokadePlatser << std::endl;
	if (platser[pos1-1] == 0 || pos1 - 1 > platser.size()) {
		std::cout << "Platsen är inte bokad" << std::endl;
		return false;
	}
	else {
		bokadePlatser--;
		platser[pos1-1] = 0;
		return true;
	}
}
int Salong::getAntalPlatser() {
	//std::cout << totalaPlatser << std::endl;
	return totalaPlatser;
}
int Salong::getLedigaPlatser() {
	//std::cout << bokadePlatser << " " << totalaPlatser << " " << totalaPlatser - bokadePlatser << std::endl;
	return totalaPlatser - bokadePlatser;
}
void Salong::skrivutStolar() {

	int rest = totalaPlatser % radMangd;
	int frfrtot = totalaPlatser - rest;
	int counter = 0;
	int counter2frfr = 0;

	while (counter != frfrtot) {
		for (int i = 0; i < radMangd; i++) {
			if (platser[counter] == 0) {
				std::cout << counter + 1 << " ";
			}
			else {
				std::cout << "-- ";
			}

			counter++;
		}
	std::cout << "\n";
	}

	if (rest != 0) {
		for (int i = 0; i < rest; i++) {
			if (platser[counter] == 0) {
				std::cout << counter + 1 << " ";
			}
			else {
				std::cout << "-- ";
			}
			counter++;
		}
	}
}