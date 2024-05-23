#include<iostream>
#include<C:\Users\malte\source\repos\Project18\Project18\ordlista.h>
#include<vector>
#include<fstream>
#include<string>

using namespace std;
vector<string> splitString(string str, char splitter);
void readFile(string file);

int main() {
	string myfile;
	bool onoff = true;
	while (onoff == true) {
		cout << "Please write the name of the file you want to analyze: ";
		cin >> myfile;
		if (myfile == "exit") {
			onoff = false;
		}
		else {
			readFile(myfile);
		}
		
	}
}

void readFile(string file) {
	string line = "";
	vector<string> temp;
	int test = 0;
	int eng_words = 0;
	int swe_words = 0;
	ifstream in(file);
	if (!in.fail()) {
		if (in.is_open()) {
			while (getline(in, line)) {
				if (line != "") {
					temp = splitString(line, ' ');

					for (int i = 0; i < temp.size(); i++) {
						for (int j = 0; j < ORD_ENG_ANTAL;j++) {
							if (temp[i] == ord_eng[j]) {
								eng_words++;
							}
						}
						for (int g = 0; g < ORD_SVE_ANTAL; g++) {
							if (temp[i] == ord_sve[g]) {
								swe_words++;
							}
						}
					}

				}
			}
		}
	}
	if (eng_words == 0 && swe_words == 0) {
		cout << "3" << endl;
		cout << eng_words << " " << swe_words << endl;
		cout << "sorry i cant tell if its english or swedish" << endl;
	}
	else if (eng_words == 0) {
		if(swe_words <= 5){
			cout << "2" << endl;
			cout << eng_words << " " << swe_words << endl;
			cout << "sorry i cant tell if its english or swedish" << endl;
		}
		else if(swe_words > 5) {
			cout << eng_words << " " << swe_words << endl;
			cout << "the text is in swedish" << endl;
		}
	}
	else if (swe_words == 0) {
		if (eng_words <= 5) {
			cout << "4" << endl;
			cout << eng_words << " " << swe_words << endl;
			cout << "sorry i cant tell if its english or swedish" << endl;
		}
		else if (eng_words > 5) {
			cout << eng_words << " " << swe_words << endl;
			cout << "the text is in english" << endl;
		}
	}
	/*
	else if ((swe_words % eng_words) < 2) {
		cout << "1" << endl;
		cout << swe_words % eng_words;
		cout << eng_words << " " << swe_words << endl;
		cout << "sorry i cant tell if its english or swedish" << endl;
	}*/
	else if (eng_words > swe_words) {
		cout << eng_words << " " << swe_words << endl;
		cout << "the text is in english" << endl;
	}
	else {
		cout << eng_words << " " << swe_words << endl;
		cout << "the text is in swedish" << endl;
	}
}

vector<string> splitString(string str, char splitter) {
		vector<string> result;
		string current = "";

		for (int i = 0; i < str.size(); i++) {
			if (str[i] == splitter) {
				if (current != "") {
					result.push_back(current);
					current = "";
				}
				continue;
			}
			current += str[i];
		}
		if (current.size() != 0) {
			result.push_back(current);
		}
		return result;
}