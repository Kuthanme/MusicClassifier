#ifndef CLASS_OF_SONG
#define CLASS_OF_SONG

#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
using namespace std;
using std::string;

class class_of_song	// define each name of class
{
public:
	void setName(string rName);
	string getName()const;
	
private:
	char name[30];
};

void class_of_song::setName(string rName)
{
	strcpy_s(name, rName.c_str());
}

string class_of_song::getName()const
{
	string buffer(name);
	return buffer;
}

#endif


