#include <iostream>
#include <fstream>
#include <map>
#include <string>
using namespace std;

typedef map<string, string> MyMap;
typedef MyMap::iterator Iter;

int main() {
	MyMap m;

	ifstream amount("File.txt");
	string line;
	int n = 0;
	while (getline(amount, line)) { n++; }

	string* mas = new string[n]; int i = 0;
	ifstream dict("File.txt");
	do {
		string str;
		getline(dict, str);
		cout << str << endl;
		m.insert(MyMap::value_type(str, str));
		mas[i] = str; i++;
	} while (!dict.eof());
	cout << endl;

	int counter = 0, copier = 1, a = 1;
	for (int k = 0; k < i; k++) {
		for (int j = 0; j < i; j++) {
			if (mas[k] == mas[j]) {
				counter++;
			}
			if (counter > a && mas[k] == mas[j]) {
				copier++;
				a++;
			}
			if (j == i - 1 && counter > 1) {
				ofstream out("File.txt", ios::app);
				cout << mas[k] << " = " << copier << " copy" << endl;
				out << "\n";
				out << mas[k] << " = " << copier << " copy" << endl;
				out.close();
			}
		}
		a = 0;
		copier = 0;
		counter = 0;
	}
	cout << endl;

	for (Iter it = m.begin(); it != m.end(); it++) {
		cout << it->first << " - " << it->second << endl;
	}
}
