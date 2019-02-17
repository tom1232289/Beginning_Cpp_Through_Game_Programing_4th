// Word Jumble
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

int main()
{
	// 1.创造单词、单词提示的多维数组
	enum fields
	{
		WORD,
		HINT,
		NUM_FIELDS
	};
	const int NUM_WORDS = 5;
	const string WORDS[NUM_WORDS][NUM_FIELDS] =
	{
		{"wall","Do you feel you're banging your head against something?"},
		{"glasses","These might help you see the answer."},
		{"labored","Going slowly, is it?"},
		{"persistent","Keep at it."},
		{"jumble","It's what the game is all about."}
	};

	// 2.欢迎界面
	cout << "\t\t\tWelcome to Word Jumble!" << endl << endl;
	cout << "Unscramble the letters to make a word." << endl;

	// 3.进入游戏主循环
	while (true) {		
		bool bHinted = false;
		string sContinue;
		// 4.随机选择一个单词
		srand(static_cast<unsigned int>(time(0)));
		int choice = (rand() % NUM_WORDS);
		string theWord = WORDS[choice][WORD];
		string theHint = WORDS[choice][HINT];
		double scores = theWord.size() * 10;

		// 5.单词乱序
		string jumble = theWord;
		int length = jumble.size();
		for (int i = 0; i < length; ++i) {
			int index1 = (rand() % length);
			int index2 = (rand() % length);
			char temp = jumble[index1];
			jumble[index1] = jumble[index2];
			jumble[index2] = temp;
		}

		// 6.开始猜
		cout << "Enter 'hint' for a hint." << endl;
		cout << "Enter 'quit' to quit the game." << endl << endl;
		cout << "The jumble is: " << jumble << endl;
		cout << "Your guess: " << endl;
		string guess;
		cin >> guess;

		// 7.若猜错则循环
		while (guess != theWord) {
			if (guess == "quit")
				break;
			if (guess == "hint") {
				cout << theHint << endl;
				if (!bHinted) {
					scores = scores / 2;
					bHinted = true;
				}
				cout << "Your guess: " << endl;
				cin >> guess;
			}
			else {
				cout << "Sorry, That's not it." << endl;
				scores -= 10;
				cout << "Your guess: " << endl;
				cin >> guess;
			}
		}
		if (guess == "quit")
			break;

		cout << "That's it! You guessed it!" << endl;
		if (scores < 0)
			scores = 0;
		cout << "Your scores is: " << scores << endl;
		cout << "Continue?(y/n)" << endl;
		cin >> sContinue;
		if (sContinue == "n")
			break;
	}
	cout << "Thanks for playing." << endl;

	system("pause");
	return 0;
}