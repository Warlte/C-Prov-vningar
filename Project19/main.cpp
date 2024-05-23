#include<iostream>
#include<vector>
#include<C:\Users\malte\source\repos\Project19\Project19\header.h>
#include<string>
#include<cmath>


void closestscolor(int r, int g, int b);
std::vector<color> colors;

int main() {
	colors.push_back(color(192, 192, 192, "silver"));
	colors.push_back(color(0, 0, 0, "black"));
	colors.push_back(color(128, 128, 0, "olive"));
	colors.push_back(color(154, 205, 0, "Yellow green"));
	colors.push_back(color(255, 222, 173, "Navajo white"));
	colors.push_back(color(176, 224, 230, "Powder blue"));

	bool onoff = true;

	int red;
	int green;
	int blue;

	std::cout << "ange en önskad färg(R,G,B)" << std::endl;
	std::cin >> red;
	std::cin >> green;
	std::cin >> blue;
	closestscolor(red, green, blue);
}

void closestscolor(int r, int g, int b) {
	int colordiff = 10000000000;
	int colorpos = 0;
	for (int i = 0; i < colors.size(); i++) {
		int tempcolors = std::sqrt(r - (colors[i].getred()) ^ 2 + (g - colors[i].getgreen()) ^ 2 + (b - colors[i].getblue()) ^ 2);
		if (tempcolors < 0) {
			tempcolors = tempcolors * -1;
		}
		std::cout << tempcolors << std::endl;
		if (colordiff > tempcolors) {
			colordiff = tempcolors;
			colorpos = i;
		}
	}
	std::cout << "närmaste färgen är " << colors[colorpos].getred() << "," << colors[colorpos].getgreen() << "," << colors[colorpos].getblue() << "," << colors[colorpos].getname() << std::endl;
}