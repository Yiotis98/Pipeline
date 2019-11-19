#include "Intructions.h"

void Instructions::import(string code) {
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

void Instructions::printall() {
	int i;
	for (i = 0; i < commands.size(); i++) {
		cout << "Command " << i + 1 << ": " << commands[i].command << "  PC: " << hex << commands[i].pc << endl;
	}
	for (i = 0; i < labels.size(); i++) {
		cout << "Label " << i + 1 << ": " << labels[i].label << "  PC: " << hex << labels[i].pc << endl;
	}
}

int RegisterFile::ReadReg(string reg) {
	if (reg.compare("r0")) {
		return r0;
	}
	else if (reg.compare("at")) {
		return at;
	}
	else if (reg.compare("v0")) {
		return v0;
	}
	else if (reg.compare("v1")) {
		return v1;
	}
	else if (reg.compare("a0")) {
		return a0;
	}else if (reg.compare("a1")) {
		return a1;
	}
	else if (reg.compare("a2")) {
		return a2;
	}
	else if (reg.compare("a3")) {
		return a3;
	}
	else if (reg.compare("t0")) {
		return t0;
	}
	else if (reg.compare("t1")) {
		return t1;
	}
	else if (reg.compare("t2")) {
		return t2;
	}
	else if (reg.compare("t3")) {
		return t3;
	}
	else if (reg.compare("t4")) {
		return t4;
	}
	else if (reg.compare("t5")) {
		return t5;
	}
	else if (reg.compare("t6")) {
		return t6;
	}
	else if (reg.compare("t7")) {
		return t7;
	}
	else if (reg.compare("t8")) {
		return t8;
	}
	else if (reg.compare("t9")) {
		return t9;
	}
	else if (reg.compare("s0")) {
		return s0;
	}
	else if (reg.compare("s1")) {
		return s1;
	}
	else if (reg.compare("s2")) {
		return s2;
	}
	else if (reg.compare("s3")) {
		return s3;
	}
	else if (reg.compare("s4")) {
		return s4;
	}
	else if (reg.compare("s5")) {
		return s5;
	}
	else if (reg.compare("s6")) {
		return s6;
	}
	else if (reg.compare("s7")) {
		return s7;
	}
	else if (reg.compare("k0")) {
		return k0;
	}
	else if (reg.compare("k1")) {
		return k1;
	}
	else if (reg.compare("gp")) {
		return gp;
	}
	else if (reg.compare("sp")) {
		return sp;
	}
	else if (reg.compare("fp")) {
		return fp;
	}
	else if (reg.compare("ra")) {
		return ra;
	}
	else if (reg.compare("zero")) {
		return zero;
	}
	else {
		cout << "Error with register file"<<endl;
	}
}

void RegisterFile::StoreReg(string reg, int value) {
	if (reg.compare("r0")) {
		r0 = value;
	}
	else if (reg.compare("at")) {
		at = value;
	}
	else if (reg.compare("v0")) {
		v0 = value;
	}
	else if (reg.compare("v1")) {
		v1 = value;
	}
	else if (reg.compare("a0")) {
		a0 = value;
	}
	else if (reg.compare("a1")) {
		a1 = value;
	}
	else if (reg.compare("a2")) {
		a2 = value;
	}
	else if (reg.compare("a3")) {
		a3 = value;
	}
	else if (reg.compare("t0")) {
		t0 = value;
	}
	else if (reg.compare("t1")) {
		t1 = value;
	}
	else if (reg.compare("t2")) {
		t2 = value;
	}
	else if (reg.compare("t3")) {
		t3 = value;
	}
	else if (reg.compare("t4")) {
		t4 = value;
	}
	else if (reg.compare("t5")) {
		t5 = value;
	}
	else if (reg.compare("t6")) {
		t6 = value;
	}
	else if (reg.compare("t7")) {
		t7 = value;
	}
	else if (reg.compare("t8")) {
		t8 = value;
	}
	else if (reg.compare("t9")) {
		t9 = value;
	}
	else if (reg.compare("s0")) {
		s0 = value;
	}
	else if (reg.compare("s1")) {
		s1 = value;
	}
	else if (reg.compare("s2")) {
		s2 = value;
	}
	else if (reg.compare("s3")) {
		s3 = value;
	}
	else if (reg.compare("s4")) {
		s4 = value;
	}
	else if (reg.compare("s5")) {
		s5 = value;
	}
	else if (reg.compare("s6")) {
		s6 = value;
	}
	else if (reg.compare("s7")) {
		s7 = value;
	}
	else if (reg.compare("k0")) {
		k0 = value;
	}
	else if (reg.compare("k1")) {
		k1 = value;
	}
	else if (reg.compare("gp")) {
		gp = value;
	}
	else if (reg.compare("sp")) {
		s0 = value;
	}
	else if (reg.compare("fp")) {
		fp = value;
	}
	else if (reg.compare("ra")) {
		ra = value;
	}
	else if (reg.compare("zero")) {
		zero = value;
	}
	else {
		cout << "Error with register file" << endl;
	}
}

void Memmory::SortMem() {
	int i, j, temp;
	for (i = 0; i < memmory.size(); i++) {
		for (j = 0; j < memmory.size(); j++) {
			if (memmory[j].address > memmory[i].address) {
				swap(memmory[i], memmory[j]);
			}
		}
	}
}

int Memmory::ReadMem(int address) {
	int i;
	for (i = 0; i < memmory.size(); i++) {
		if (memmory[i].address == address) {
			return memmory[i].value;
		}
	}
	cout << "Error with reading memmory"<<endl;
}

void Memmory::StoreMem(int address, int value) {
	int i;
	mem tempmem;
	for (i = 0; i < memmory.size(); i++) {
		if (memmory[i].address == address) {
			break;
		}
	}
	if (i < memmory.size()) {
		memmory[i].value = value;
	}
	else {
		tempmem.address = address;
		tempmem.value = value;
		memmory.push_back(tempmem);
	}
	SortMem();
}

void Memmory::PrintMem() {
	int i;
	cout << "MEMMORY" << endl;
	for (i = 0; i < memmory.size(); i++) {
		cout << "Address: " << hex << memmory[i].address << " Value: " << hex << memmory[i].value << endl;
	}
}