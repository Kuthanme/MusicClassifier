#ifndef COSDATABASE
#define COSDATABASE

#include"class_of_song.h"

class COSdatabase
{
public:
	COSdatabase();
	~COSdatabase();

	class_of_song getFile(unsigned int i)const;
	vector< class_of_song > getdata()const;
	
	int find_ClassOfSong(string &rCS);  // search class of song
	bool duplicateCS(class_of_song &rCS);
	void save_FileImmediately();
	void showData();  // show the data
	void PushBack(class_of_song &newClass);
	void erase(int i);

protected:
	void loadFromCOS_File();
	void saveToCOS_File();
	vector< class_of_song > COSdata;
};

COSdatabase::COSdatabase()
{
	loadFromCOS_File();
}

COSdatabase::~COSdatabase()
{
	saveToCOS_File();
}

class_of_song COSdatabase::getFile(unsigned int i)const
{
	return COSdata[i];
}

vector< class_of_song > COSdatabase::getdata()const
{
	return COSdata;
}

 // search class of song
int COSdatabase::find_ClassOfSong(string &rCS) 
{
	for (unsigned int i = 0; i < COSdata.size(); ++i)
	{
		if (COSdata[i].getName() == rCS)
			return i;//return position in vector 
	}
	return -1;// if no data be found return minus number
}

// check if have same level
bool COSdatabase::duplicateCS(class_of_song &rCS)
{
	for (unsigned i = 0; i < COSdata.size(); i++)
	{
		if (rCS.getName()== COSdata[i].getName())
			return true;
	}
	return false;
}

void COSdatabase::showData()
{
	cout << endl << "Folder of Artist:\n"
		<<"--------------------------------\n";

	for (unsigned int i = 0; i < COSdata.size(); ++i)
		cout << COSdata[i].getName() << endl;

	cout << "--------------------------------\n";
}

void COSdatabase::save_FileImmediately()
{
	saveToCOS_File();
}

void COSdatabase::PushBack(class_of_song &newClass)
{
	COSdata.push_back(newClass);
}

void COSdatabase::erase(int i)
{
	vector< class_of_song >::iterator iter = COSdata.begin();
	COSdata.erase(iter + i);
}

//load level data
void COSdatabase::loadFromCOS_File()
{
	class_of_song COS_inload;	//contain data from file
	fstream  COS_load("COS.dat", ios::in | ios::binary);	//file which has the info of Class Of Song
	if (!COS_load)
	{
		COS_load.close();
		cout << "File COS.dat could not be opened!" << endl;
		ofstream inFile("COS.dat", ios::out | ios::binary);
		inFile.close();
		COS_load.open("COS.dat", ios::in | ios::binary);
		system("pause");
	}
	COS_load.seekg(0, ios::beg);
	COS_load.read(reinterpret_cast<char*>(&COS_inload), sizeof(class_of_song));
	while (!COS_load.eof())
	{
		COSdata.push_back(COS_inload);
		COS_load.read(reinterpret_cast<char*>(&COS_inload), sizeof(class_of_song));
	}
	COS_load.close();
}

//save level data
void COSdatabase::saveToCOS_File()
{
	fstream COS_write("COS.dat", ios::out | ios::binary);
	if (!COS_write)
	{
		COS_write.close();
		cout << "File COS.dat could not be opened." << endl;
		ofstream inFile("COS.dat", ios::out | ios::binary);
		inFile.close();
		COS_write.open("COS.dat", ios::in | ios::binary);
		system("pause");
	}
	COS_write.seekp(0, ios::beg);
	for (unsigned i = 0; i < COSdata.size(); i++)
	{
		COS_write.write(reinterpret_cast<char*>(&COSdata[i]), sizeof(class_of_song));
	}
	COS_write.close();
}

#endif
