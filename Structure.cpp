//
// Created by barto on 29.03.17.
//

#include "Structure.h"

// public

void Structure::test(string nameOfStructure) {
	nameOfStructure = nameOfStructure.substr(4, nameOfStructure.size() - 8);
	char opt = 0;
	Counter counter;
	int nOE[4] = {50, 1000, 10000, 20000};
	int r[3] = {100, RAND_MAX / 2, RAND_MAX};
	int numberOfTests;
	double sumOfResults;
	int index;
	int res;

	do {
		cout << "- TESTY -" << endl;
		cout << "1. Dodawanie na poczatku" << endl;
		cout << "2. Dodawanie w srodku" << endl;
		cout << "3. Dodawanie na koncu" << endl;
		cout << "4. Usuwanie na poczatku" << endl;
		cout << "5. Usuwanie w srodku" << endl;
		cout << "6. Usuwanie na koncu" << endl;
		cout << "7. Wyszukiwanie" << endl;
		cout << "0. Powrot" << endl;
		cout << "Podaj opcje:";
		cin >> opt;
		cout << endl;

		switch (opt) {
			case '1':
				cout << endl << "Podaj ilosc testow: ";
				cin >> numberOfTests;
				for (int i = 0; i < sizeof(nOE) / sizeof(int); i++) {
					for (int j = 0; j < sizeof(r) / sizeof(int); j++) {
						int numberOfElements = nOE[i];
						int range = r[j];

						string path = "..\\wyniki\\";
						path += to_string(time(0));
						path += "-" + nameOfStructure + "-dodawanie-poczatek-n" + to_string(numberOfElements) + "-r" +
								to_string(range) + ".txt";

						fstream file(path, fstream::out);
						srand(time(NULL));

						if (!file.is_open()) {
							cout << "Wyniki sie nie zapisza!!!" << endl;
						}

						file.setf(ios::fixed);

						sumOfResults = 0;

						for (int k = 0; k < numberOfTests; k++) {
							generate(numberOfElements, range);

							int value = rand() % range;
							counter.startCounter();
							add(value, 0);
							double result = counter.getCounter();
							sumOfResults += result;
							cout << result << endl;
							file << result << endl;
							removePosition(0);

							clear();
						}

						sumOfResults /= numberOfTests;

						cout << "Srednia: " << sumOfResults << endl;
						file << "Srednia: " << sumOfResults << endl;

						file.close();
					}
				}
				break;

			case '2':
				cout << endl << "Podaj ilosc testow: ";
				cin >> numberOfTests;
				for (int i = 0; i < sizeof(nOE) / sizeof(int); i++) {
					cout << "Ilosc elementow: " << nOE[i] << "; Podaj index: ";
					cin >> index;
					for (int j = 0; j < sizeof(r) / sizeof(int); j++) {
						int numberOfElements = nOE[i];
						int range = r[j];

						string path = "..\\wyniki\\";

						path += to_string(time(0));
						path += "-" + nameOfStructure + "-dodawanie-wlasnyIndex-n" + to_string(numberOfElements) +
								"-r" + to_string(range) + ".txt";

						fstream file(path, fstream::out);
						srand(time(NULL));

						if (!file.is_open()) {
							cout << "Wyniki sie nie zapisza!!!" << endl;
						}

						file.setf(ios::fixed);

						sumOfResults = 0;

						for (int k = 0; k < numberOfTests; k++) {
							generate(numberOfElements, range);

							int value = rand() % range;
							counter.startCounter();
							add(value, index);
							double result = counter.getCounter();
							sumOfResults += result;
							cout << result << endl;
							file << result << endl;
							removePosition(index);

							clear();
						}

						sumOfResults /= numberOfTests;

						cout << "Srednia: " << sumOfResults << endl;
						file << "Srednia: " << sumOfResults << endl;

						file.close();
					}
				}
				break;

			case '3':
				cout << endl << "Podaj ilosc testow: ";
				cin >> numberOfTests;
				for (int i = 0; i < sizeof(nOE) / sizeof(int); i++) {
					for (int j = 0; j < sizeof(r) / sizeof(int); j++) {
						int numberOfElements = nOE[i];
						int range = r[j];

						string path = "..\\wyniki\\";

						path += to_string(time(0));
						path += "-" + nameOfStructure + "-dodawanie-koniec-n" + to_string(numberOfElements) + "-r" +
								to_string(range) + ".txt";

						fstream file(path, fstream::out);
						srand(time(NULL));

						if (!file.is_open()) {
							cout << "Wyniki sie nie zapisza!!!" << endl;
						}

						file.setf(ios::fixed);

						sumOfResults = 0;

						for (int k = 0; k < numberOfTests; k++) {
							generate(numberOfElements, range);

							int value = rand() % range;
							counter.startCounter();
							add(value, size);
							double result = counter.getCounter();
							sumOfResults += result;
							cout << result << endl;
							file << result << endl;
							removePosition(size - 1);

							clear();
						}

						sumOfResults /= numberOfTests;

						cout << "Srednia: " << sumOfResults << endl;
						file << "Srednia: " << sumOfResults << endl;

						file.close();
					}
				}
				break;

			case '4':
				cout << endl << "Podaj ilosc testow: ";
				cin >> numberOfTests;
				for (int i = 0; i < sizeof(nOE) / sizeof(int); i++) {
					for (int j = 0; j < sizeof(r) / sizeof(int); j++) {
						int numberOfElements = nOE[i];
						int range = r[j];

						string path = "..\\wyniki\\";

						path += to_string(time(0));
						path += "-" + nameOfStructure + "-usuwanie-poczatek-n" + to_string(numberOfElements) + "-r" +
								to_string(range) + ".txt";

						fstream file(path, fstream::out);
						srand(time(NULL));

						if (!file.is_open()) {
							cout << "Wyniki sie nie zapisza!!!" << endl;
						}

						file.setf(ios::fixed);

						sumOfResults = 0;

						for (int k = 0; k < numberOfTests; k++) {
							generate(numberOfElements, range);

							int value = rand() % range;
							add(value, 0);
							counter.startCounter();
							removePosition(0);
							double result = counter.getCounter();
							sumOfResults += result;
							cout << result << endl;
							file << result << endl;

							clear();
						}

						sumOfResults /= numberOfTests;

						cout << "Srednia: " << sumOfResults << endl;
						file << "Srednia: " << sumOfResults << endl;

						file.close();
					}
				}
				break;

			case '5':
				cout << endl << "Podaj ilosc testow: ";
				cin >> numberOfTests;
				for (int i = 0; i < sizeof(nOE) / sizeof(int); i++) {
					cout << "Ilosc elementow: " << nOE[i] << "; Podaj index: ";
					cin >> index;
					for (int j = 0; j < sizeof(r) / sizeof(int); j++) {
						int numberOfElements = nOE[i];
						int range = r[j];

						string path = "..\\wyniki\\";

						path += to_string(time(0));
						path += "-" + nameOfStructure + "-usuwanie-wlasnyIndex-n" + to_string(numberOfElements) + "-r" +
								to_string(range) + ".txt";

						fstream file(path, fstream::out);
						srand(time(NULL));

						if (!file.is_open()) {
							cout << "Wyniki sie nie zapisza!!!" << endl;
						}

						file.setf(ios::fixed);

						sumOfResults = 0;

						for (int k = 0; k < numberOfTests; k++) {
							generate(numberOfElements, range);

							int value = rand() % range;
							add(value, index);
							counter.startCounter();
							removePosition(index);
							double result = counter.getCounter();
							sumOfResults += result;
							cout << result << endl;
							file << result << endl;

							clear();
						}

						sumOfResults /= numberOfTests;

						cout << "Srednia: " << sumOfResults << endl;
						file << "Srednia: " << sumOfResults << endl;

						file.close();
					}
				}
				break;

			case '6':
				cout << endl << "Podaj ilosc testow: ";
				cin >> numberOfTests;
				for (int i = 0; i < sizeof(nOE) / sizeof(int); i++) {
					for (int j = 0; j < sizeof(r) / sizeof(int); j++) {
						int numberOfElements = nOE[i];
						int range = r[j];

						string path = "..\\wyniki\\";

						path += to_string(time(0));
						path += "-" + nameOfStructure + "-usuwanie-koniec-n" + to_string(numberOfElements) + "-r" +
								to_string(range) + ".txt";

						fstream file(path, fstream::out);
						srand(time(NULL));

						if (!file.is_open()) {
							cout << "Wyniki sie nie zapisza!!!" << endl;
						}

						file.setf(ios::fixed);

						sumOfResults = 0;

						for (int k = 0; k < numberOfTests; k++) {
							generate(numberOfElements, range);

							int value = rand() % range;
							add(value, size);
							counter.startCounter();
							removePosition(size - 1);
							double result = counter.getCounter();
							sumOfResults += result;
							cout << result << endl;
							file << result << endl;

							clear();
						}

						sumOfResults /= numberOfTests;

						cout << "Srednia: " << sumOfResults << endl;
						file << "Srednia: " << sumOfResults << endl;

						file.close();
					}
				}
				break;

			case '7':
				cout << endl << "Podaj ilosc testow: ";
				cin >> numberOfTests;
				for (int i = 0; i < sizeof(nOE) / sizeof(int); i++) {
					for (int j = 0; j < sizeof(r) / sizeof(int); j++) {
						int numberOfElements = nOE[i];
						int range = r[j];

						string path = "..\\wyniki\\";

						path += to_string(time(0));
						path += "-" + nameOfStructure + "-wyszukiwanie-n" + to_string(numberOfElements) + "-r" +
								to_string(range) + ".txt";

						fstream file(path, fstream::out);
						srand(time(NULL));

						if (!file.is_open()) {
							cout << "Wyniki sie nie zapisza!!!" << endl;
						}

						file.setf(ios::fixed);

						sumOfResults = 0;

						generate(numberOfElements, range);
						print();

						for (int k = 0; k < numberOfTests; k++) {
							int value = rand() % range;
							cout << "Wyszukiwanie: " << value << endl;
							counter.startCounter();
							res = lookFor(value, false);
							double result = counter.getCounter();
							sumOfResults += result;
							cout << "Wynik: " << res << endl;
							cout << "Czas: " << result << endl;
							file << result << endl;
						}

						clear();

						sumOfResults /= numberOfTests;

						cout << "Srednia: " << sumOfResults << endl;
						file << "Srednia: " << sumOfResults << endl;

						file.close();
					}
				}
				break;

			case '0':
				break;

			default:
				cout << "Nie ma takiej opcji, wybierz jeszcze raz." << endl;
				break;
		}

	} while (opt != '0');
}

// protected

vector<int> Structure::loadRawDataFrom(string path) {
	vector<int> returnIntVector = vector<int>();
	vector<string> values = vector<string>();

	fstream file(path, ios::in);

	if (!file.is_open())
		return returnIntVector;

	string amountOfNumbersS = "";
	getline(file, amountOfNumbersS);
	int amountOfNumbers = stoi(amountOfNumbersS);

	for (int i = 0; i < amountOfNumbers; i++) {
		string temp = "";
		getline(file, temp);
		values.push_back(temp);
	}

	if (values.empty())
		return returnIntVector;

	for (int i = 0; i < values.size(); i++) {
		returnIntVector.push_back(stoi(values[i]));
	}

	return returnIntVector;
}
