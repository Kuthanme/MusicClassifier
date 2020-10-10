#ifndef FILE_CLASSIFY
#define FILE_CLASSIFY
#include <sys/types.h>
#include <errno.h>
#include <algorithm>
#include <windows.h>
#include"COSdatabase.h"

class file_classify
{
public:
	file_classify();
	~file_classify();
	COSdatabase getCOS();
	void create_folder(string &FolderName);
	void create_SongClass();
	void Sorting_Songs();
	
private:
	void getMp3Files();

	COSdatabase COS;
	class_of_song newClass;
	string dir = string("D:/Downloads");	//folder path (Absolute position or relative)
	vector<string> files = vector<string>();
	vector<string> mp3_files;
};

file_classify::file_classify()
{
	getMp3Files();
}

file_classify::~file_classify()
{}

COSdatabase file_classify::getCOS()
{
	return COS;
}

#include "dirent.h"
void file_classify::getMp3Files()
{
	DIR *dp;//創立資料夾指標
	struct dirent *dirp;
	if ((dp = opendir(dir.c_str())) == NULL)
	{
		cout << "Error(" << errno << ") opening " << dir << endl;
		return;
	}
	while ((dirp = readdir(dp)) != NULL)
	{//如果dirent指標非空
		files.push_back(string(dirp->d_name));//將資料夾和檔案名放入vector
	}
	closedir(dp);//關閉資料夾指標

	int pos = 0;
	for (int i = 0; i < files.size(); ++i)
	{// put .mp3 files into another vector
		if ((pos = files[i].find(".mp3")) != -1)
		{
			mp3_files.push_back(files[i]);
		}
	}
}

#include <direct.h>
#include <stdlib.h>
#include <stdio.h>
void file_classify::create_folder(string &rFolderName)
{
	string tempFolder_dir = "D:\\Downloads\\" + rFolderName;
	const char* newFolder_dir = tempFolder_dir.c_str();

	if (_mkdir(newFolder_dir) == 0)
	{
		cout <<"-------------------------------\n"
			<< "Folder'" << rFolderName << "'created\n"
			<<"-------------------------------\n";
		//system("dir");
		//if (_rmdir(newFolder_dir) == 0)
		//	cout << "資料夾'" << rFolderName << "'移除成功\n";

		//else
		//	cout << "資料夾'" << rFolderName << "'無法移除\n";
	}
	else
		cout <<"-------------------------------\n"
		<< "Folder'" << rFolderName << "'connot be created or exist\n"
		<<"-------------------------------\n";
}

void file_classify::create_SongClass()
{
	char newname[30];
	cout << "Input Artist: ";
	cin.ignore();
	cin.get(newname, 30, '\n');
	newClass.setName(newname);
	if (COS.duplicateCS(newClass))
	{//if system has same class of song, return
		cout << "You have same folder! \n" << endl;
		return;
	}
	COS.PushBack(newClass);
	COS.save_FileImmediately();
	cout << "Successful!!" << endl;
}
void file_classify::Sorting_Songs()
{
	for (int i = 0; i < COS.getdata().size(); ++i)
	{// first loop: create folder by Class Of Song(COS) data
		string FolderName = COS.getFile(i).getName();
		create_folder(FolderName);

		int _pos = 0;
		for (int i = 0; i < mp3_files.size(); i++)
		{// second loop: move the same class .mp3 file to the folder
			if ((_pos = mp3_files[i].find(FolderName)) != -1)
			{
				// source path of folder
				string temp_FolderPath = "D:\\Downloads\\" + mp3_files[i];
				LPCSTR FolderPath = temp_FolderPath.c_str();

				// destination path of folder
				string temp_Dst_FolderPath = "D:\\Downloads\\" + FolderName + "\\" + mp3_files[i];
				LPCSTR Dst_FolderPath = temp_Dst_FolderPath.c_str();

				MoveFile(FolderPath, Dst_FolderPath);// move file 
			}
		}
	}
	cout << "Music classified!" << endl;
}

#endif