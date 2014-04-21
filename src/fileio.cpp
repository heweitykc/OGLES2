#include <iostream>
#include <fstream>
#include "fileio.h"
using namespace std;

void Loader::load(const char *fname)
{
	ifstream file(fname,ios::in|ios::binary);
	if (file.is_open()){
		file.seekg (0, ios::end);
		int size = file.tellg();
		cout << "file size=" << size << endl;
		buff = new char[size+1];
		file.seekg (0, ios::beg);
		file.read (buff, size);
		buff[size] = '\0';
		file.close();
	}
	else 
		cout << "Unable to open file" << fname <<endl;
}

char* Loader::getbuff()
{
	return buff;
}

void Loader::clear()
{
	if(buff == NULL) return;
	delete[] buff;
	buff = NULL;
}

Loader::Loader()
{
	buff = NULL;
}

Loader::~Loader()
{
	clear();
}