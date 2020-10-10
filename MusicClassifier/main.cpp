#include"IntOfChose.h"
#include"file_classify.h"
using namespace std;

void displayFunction();

int main()
{
	file_classify executor;
	enum FuntionOption { CANCEL = 0, ADDCOS, SORTSONGS, SHOWFLODER };
	bool Cancel = false;
	while (!Cancel)
	{
		displayFunction();
		Choose inputInteger;// get admin selection by class of Choose
		int FuntionSelection = inputInteger.excute(0, 4);

		switch (FuntionSelection)// decide how to proceed based on admin's menu selection
		{
		case ADDCOS:  // add the new object of capsule toys
			executor.create_SongClass();
			break;
		case SORTSONGS:// add the new level of capsule toys
			executor.Sorting_Songs();
			break;
		case SHOWFLODER:
			executor.getCOS().showData();
			break;
		case CANCEL: // exit debug mode
			Cancel = true;
			break;
		default:	// user did not enter an integer from 0-3
			cout << "\nIncorrect choice!" << endl;
			break;
		}//end switch
	}//end 
	return 0;
}

void displayFunction()
{
	cout << "\n< 1 > - Add Artist" << endl;
	cout << "< 2 > - Start classify" << endl;
	cout << "< 3 > - Check Artist folder" << endl;
	cout << "< 0 > - Exit \n" << endl;
}
