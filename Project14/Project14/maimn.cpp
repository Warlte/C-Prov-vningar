#include <iostream>
using namespace std;


int main() {
	int arr[100];
	arr[99] = 3;
	arr[100] = 4;
	arr[101] = 5;

	cout << arr[100] << " " << arr[101];
}
