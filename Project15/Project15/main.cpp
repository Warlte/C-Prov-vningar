#include<iostream>
#include<vector>
#include<random>
#include<array>
#include<chrono>
#include<thread>

using namespace std;
vector<int> asignnumber(int diff);
void compare(vector<int> facit, vector<int> svar);

int main() {
	int diff = 2;
	bool onoff = true;
	vector<int> numbers = asignnumber(diff);
	vector<int> inputnumbers;
	vector<int> inarr;

	cout << "hallo" << numbers[0] << numbers[1];

	while (onoff == true) {
		cout << "Level " << diff << ": " << diff << " stycken unika tal mellan 0-20" << endl;
		cout << "tryck enter för att starta" << endl;
		cin;
		cout << "memorera följande nummer : ";
		for (int i = 0; i < diff;i++) {
			cout << numbers[i] << " ";
		}
		cout << endl;

		for (int i = 0; i < 5; i++) {
			cout << 5 - i << "...";
			this_thread::sleep_for(std::chrono::milliseconds(1000));
		}

		for (int i = 0; i < 20; i++) {
			cout << endl;
		}

		int temp;
		for (int i = 0; i < numbers.size(); i++) {
			cin >> temp;
			inputnumbers.push_back(temp);
		}
		compare(numbers, inputnumbers);
		onoff = false;
	}

}

vector<int> asignnumber(int diff) {
	vector<int> returna;

	while (diff > 0) {
		int temprandint = rand() % 21;

		bool found = false;

		for (int num : returna) {
			if (temprandint == num) {
				found = true;
				break;
			}
		}

		if (!found) {
			returna.push_back(temprandint);
			diff--;
		}
	}
	return returna;
}

void compare(vector<int> facit, vector<int> svar) {
	int correctanswer = 0;
	for (int i = 0; i < facit.size(); i++) {
		for (int j = 0; j < svar.size(); j++) {
			if (facit[j] == svar[i]) {
				correctanswer++;
				break;
			}
		}
	}
	if (correctanswer == facit.size()) {
		cout << "du hadde alla rätt";
	}
	else {
		cout << "du hadde " << correctanswer << " utav " << facit.size() << " rätt";
	}
}