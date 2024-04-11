#include<iostream>
#include<random>

using namespace std;

int const arraySize = 20;
int randArray[arraySize];

int rollDice();
void displayRun(int values[], int size);
bool hasRun(int values[], int size);

int main() {
	srand(time(0));

	for (int i = 0; i < arraySize; i++) {
		randArray[i] = rollDice();
	}

	displayRun(randArray, arraySize);
	if (hasRun(randArray, arraySize)) {
		cout << endl << "Has Run";
	}
	else {
		cout << endl << "Doesnt have run";
	}
	return 0;
}

int rollDice() {
	return rand() % 6 + 1;
}

void displayRun(int values[], int size) {
	int placeHolder = values[0];
	bool runContinued = false;
	for (int i = 1; i < size + 1; i++) {
		if (runContinued) {
			if (values[i] == placeHolder) {
				cout << placeHolder;
			}
			else {
				cout << placeHolder << ")";
				runContinued = false;
			}
		}
		else {
			if (values[i] == placeHolder) {
				cout << "(" << placeHolder;
				runContinued = true;
			}
			else {
				cout << placeHolder;
			}
		}
		placeHolder = values[i];
		cout << " ";
	}
}
bool hasRun(int values[], int size) {
	int placeHolder = values[0];
	for (int i = 1; i < size + 1; i++) {
			if (values[i] == placeHolder) {
				return true;
			}
		placeHolder = values[i];
	}
	return false;
}