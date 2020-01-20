#include "Intructions.h"

using namespace std;

void main() {
	ifstream fi;
	string str;
	size_t found;
	Instructions program;
	fi.open("input.txt", ios::in);
	if (!fi.is_open()) {
		cout << "Error with opening the file" << endl;
	}
	while (!fi.eof()) {
		getline(fi, str);
		found = str.find('#');
		if (found != str.npos) {
			str.erase(found);
		}
		found = str.find('.');
		if (found != str.npos) {
			str.erase(found);
		}
		found = str.find('\t');
		while (found != str.npos) {
			str.erase(found, 1);
			found = str.find('\t');
		}
		found = str.find(' ');
		while (found != str.npos) {
			str.erase(found, 1);
			found = str.find(' ');
		}
		if (!str.empty()) {
			program.import(str);
		}
	}
	program.printall();
}