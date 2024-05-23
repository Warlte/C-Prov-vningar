#pragma once
#include<vector>

class Salong {

public:
	Salong(int totplatser, int radstolar);
	bool bokaPlats(int pos1);
	bool avbokaPlats(int pos1);
	int getAntalPlatser();
	int getLedigaPlatser();
	void skrivutStolar();
private:
	int totalaPlatser;
	int bokadePlatser = 0;
	int radMangd;
	std::vector<int> platser;
	//std::vector< std::vector< int > > a;
};
