#include<iostream>
#include <random>


using namespace std;

int main() {
	bool onoff = true;
	char letter = randomletter();
	while (onoff == true) {
		cout << letter;
		onoff = false;
	}
}

char randomletter() {
	int n = rand % 29;
	assert(n >= 1 && n <= 29);
	return "abcdefghijklmnopqrstuvwxyzåäö"[n - 1];
}