#include<iostream>
#include<string>
#include<fstream>
#include<vector>

using namespace std;

vector<string> deutsch;
vector<string> swedish;

void addFromFile(string file);
vector<string> splitString(string str, char splitter);

int main(){
	bool onoff = true;
	addFromFile("glosor.txt");
	cout << "read " << swedish.size() << " thingys from file." <<endl;

	string temp2;
	int count = 0;
	while (onoff == true) {
		int temp = rand() % deutsch.size();
		cout << " please write " << swedish[temp] << " in german: ";
		cin >> temp2;
		if (temp2 == deutsch[temp]) {
			cout << "Correct" << endl;
			count++;
		}
		else {
			cout << "Incorrect" << endl;
			count = 0;
		}
		if (count == 5) {
			onoff = false;
		}
	}


}

void playglossor() {

}

void addFromFile(string file) {
	string line = "";
	vector<string> temp;
	//int test = 0;
	ifstream in(file);
	if (!in.fail()) {
		if (in.is_open()) {
			while (getline(in, line)) {
				if (line != "") {

					temp = splitString(line, ',');

					swedish.push_back(temp[0]);
					deutsch.push_back(temp[1]);
				}
			}
		}
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