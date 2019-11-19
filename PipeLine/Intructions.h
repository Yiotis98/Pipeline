#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

class Instructions {
public:
	typedef struct {
		string command;
		int pc;
	}entoli;

	typedef struct {
		string label;
		int pc;
	}etiketa;

	vector<entoli>commands;
	vector<etiketa>labels;
	Instructions() {
		cout << "Class Instructions has been created" << endl;
	}
	void import(string code);
	void printall();
	
};

class RegisterFile {
public:
	int r0, at, v0, v1, a0, a1, a2, a3;
	int t0, t1, t2, t3, t4, t5, t6, t7, t8, t9;
	int s0, s1, s2, s3, s4, s5, s6, s7;
	int k0, k1, fp, ra,zero,gp,sp;
	RegisterFile() {
		gp = 0x10008000;
		sp = 0x7ffffffc;
		zero = 0;
		r0 = 0; at = 0; v0 = 0; v1 = 0; a0 = 0; a1 = 0; a2 = 0; a3 = 0;
		t0 = 0; t1 = 0; t2 = 0; t3 = 0; t4 = 0; t5 = 0; t6 = 0; t7 = 0; t8 = 0; t9 = 0;
		s0 = 0; s1 = 0; s2 = 0; s3 = 0; s4 = 0; s5 = 0; s6 = 0; s7 = 0;
		k0 = 0; k1 = 0; fp = 0; ra = 0;
		cout << "Class RegisterFile has been created" << endl;
	}
	void StoreReg(string reg,int value);
	int ReadReg(string reg);
};

class Memmory {
public:
	typedef struct {
		int address;
		int value;
	}mem;
	vector<mem>memmory;
	Memmory() {
		cout << "Class Memmory has been created" << endl;
	}
	void SortMem();
	void StoreMem(int address, int value);
	int ReadMem(int address);
	void PrintMem();
};
