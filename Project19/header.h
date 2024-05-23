#pragma once

#include<string>

class color {
public:
	color(int r, int g, int b, std::string cname);
	int getred();
	int getgreen();
	int getblue();
	std::string getname();
private:
	int red;
	int green;
	int blue;
	std::string name;
};
