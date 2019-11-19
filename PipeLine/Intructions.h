#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

class Instructions {
private:
	typedef struct {
		string command;
		int pc;
	}entoli;

	typedef struct {
		string label;
		int pc;
	}etiketa;

public:
	vector<entoli>commands;
	vector<etiketa>labels;
	Instructions() {
		cout << "Class Instructions has been created" << endl;
	}

	void import(string code) {
		size_t found;
		entoli tempentoli;
		etiketa tempetiketa;
		found = code.find(':');
		if (found != code.npos) {
			//einai label
			code.erase(found);
			tempetiketa.label = code;
			tempetiketa.pc = (commands.size() * 4);
			labels.push_back(tempetiketa);
		}
		else {
			//den einai label
			tempentoli.command = code;
			tempentoli.pc = (commands.size() * 4);
			commands.push_back(tempentoli);
		}
	}

	void printall() {
		int i;
		for (i = 0; i < commands.size(); i++) {
			cout << "Command " << i + 1 << ": " << commands[i].command << "  PC: " << hex << commands[i].pc << endl;
		}
		for (i = 0; i < labels.size(); i++) {
			cout << "Label " << i + 1 << ": " << labels[i].label << "  PC: " << hex << labels[i].pc << endl;
		}
	}
};
