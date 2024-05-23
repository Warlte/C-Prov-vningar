#include<C:\Users\malte\source\repos\Project19\Project19\header.h>
#include<string>;

color::color(int r, int g, int b, std::string cname) {
	red = r;
	green = g;
	blue = b;
	name = cname;
}

int color::getred() {
	return red;
}

int color::getgreen() {
	return green;
}

int color::getblue() {
	return blue;
}

std::string color::getname() {
	return name;
}