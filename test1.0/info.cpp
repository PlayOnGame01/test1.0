#include <iostream>
#include <fstream>
#include <map>
#include <string>
using namespace std;

typedef map<string, string> MyMap;
typedef MyMap::iterator Iter;

int main() {
	MyMap s;

	ifstream file("File.txt");
	string line;
	int e = 0;
	while (getline(file, line)) { e++; }

	string* al = new string[e]; int i = 0;
	ifstream dict("File.txt");
	do {
		string str;
		getline(dict, str);
		cout << str << endl;
		s.insert(MyMap::value_type(str, str));
		al[i] = str; i++;
	} while (!dict.eof());
	cout << endl;

	int count = 0, count = 1, a = 1;
	for (int k = 0; k < i; k++) {
		for (int j = 0; j < i; j++) {
			if (al[k] == al[j]) {
				count++;
			}
			if (count > a && al[k] == al[j]) {
				count++;
				a++;
			}
			if (j == i - 1 && count > 1) {
				ofstream out("File.txt", ios::app);
				cout << al[k] << " = " << count << " copy" << endl;
				out << "\n";
				out << al[k] << " = " << count << " copy" << endl;
				out.close();
			}
		}
		a = 0;
		count = 0;
		count = 0;
	}
	cout << endl;

	for (Iter it = s.begin(); it != s.end(); it++) {
		cout << it->first << " - " << it->second << endl;
	}
}
