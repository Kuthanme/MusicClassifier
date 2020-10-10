#ifndef INTOFCHOSE
#define INTOFCHOSE
#include <limits> 
#include <iostream>
using namespace std;
class Choose // use the function of this class to get user selection
{
public:
	int excute(int begin, int end);
	int input_censor();
};
int Choose::excute(int begin, int end)
{// input an integer in the range [ begin, end ]
	int choose;
	do
	{
		cin >> choose;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits< int >::max(), '\n');
			cout << "請輸入數字! :";
		}
		else if (begin <= choose && choose <= end)
			return choose;
		else cout << "超出範圍! :";
	} while (true);
}
int Choose::input_censor()
{// check user's input 
	int choose;
	do
	{
		cin >> choose;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits< int >::max(), '\n');
			cout << "請輸入數字! :";
		}
		else return choose;
			
	} while (true);
}
#endif 
/* A_A  Let's defraud all consumer by Disposable Games!!!!!! / 咱們來用免洗遊戲坑錢吧!!!!!!  A_A */ 