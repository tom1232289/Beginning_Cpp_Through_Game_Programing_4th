// Guess My Number
// The classic number guessing game
 
// 生成low到up(low < up)之间的随机正整数
// uiResult = (rand() % (up - low + 1)) + low;

// 生成low到up之间的随机实数
// fResult = low + (up - low) * rand() / (RAND_MAX + 1);

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	srand((unsigned)time(NULL));   //seed random number generator
	const int MAXNUM = 100;
	int guessNumber = rand() % MAXNUM + 1;  // random number between 1 and 100
	int tries = 0;
	char cInput = NULL;
	bool bContinue = true;
	int up = 100, low = 0;

	cout << "\tWelcome to Guess My Number\n\n";
	cout << "please think about a number between 1 to 100" << endl << endl;

	while (bContinue) {
		cout << "Is it " << guessNumber << "?" << endl;
		cout << "y/h/l" << endl;
		cin >> cInput;
		if (cInput == 'y' || cInput == 'Y') 
			bContinue = false;
		else {
			++tries;
			if (cInput == 'h' || cInput == 'H') {
				up = guessNumber - 1;
				if (up == low) {
					cout << "The secret number is " << low << endl;
					break;
				}
				guessNumber = (rand() % (up - low + 1)) + low;
			}
			else if (cInput == 'l' || cInput == 'L') {
				low = guessNumber + 1;
				if (up == low) {
					cout << "The secret number is " << low << endl;
					break;
				}
				guessNumber = (rand() % (up - low + 1)) + low;
			}
		}
	}
	cout << "Tried " << tries << " times." << endl;
	system("pause");
	return 0;
}
