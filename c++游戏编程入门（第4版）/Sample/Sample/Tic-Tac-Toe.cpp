/*
伪代码：
创建一个空的Tic-Tac-Toe的棋盘
显示游戏的说明
决定谁先走
显示棋盘
while（没有人获胜 并且 不是平局）
	if 到人类走了
		取得人类要走的位置
		更新棋盘
	else
		计算AI要走的位置
		更新棋盘
	显示棋盘
	转换棋手
祝贺获胜者 或者 宣布平局
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 显示游戏操作指南
void instructions();

// 询问是或否。接受一个问题作为参数，返回'y'或'n'
char askYesNo(string question);

// 询问一定范围内的数字。接受一个问题、一个范围下限和一个范围上限作为参数。返回low到high之间的数字。
int askNumber(string question, int high, int low = 0);

// 确定玩家的棋子，返回'X'或'O'
char humanPiece();

// 计算给定棋子的应对棋子。接受'X'或'O'，返回'X'或'O'
char opponent(char piece);

// 在屏幕上显示棋盘。接受棋盘作为参数
void displayBoard(const vector<char> &board);

// 确定游戏的胜者。接受棋盘作为参数，返回'X'、'O'、'T'（表示和棋）或'N'（表示还没有哪一方胜出）
char winner(const vector<char> &board);

// 确定一招棋的合法性。接受一个棋盘与一招棋作为参数，返回true或false
bool isLegel(const vector<char> &board, int move);

// 获取人类玩家的一招棋。接受一个棋盘与人类玩家的棋子作为参数，返回玩家的一招棋
int humanMove(const vector<char> &board, char human);

// 计算计算机的一招棋。接受一个棋盘与计算机的棋子作为参数，返回计算机的一招棋
// 核心思路：
// （1）如果计算机采用某一招棋能获胜，则选择这一招棋。
// （2）否则，如果人类玩家能用其下一招棋获胜，则出棋阻止他。
// （3）否则，在剩下的空方格中选择最优的一个方格。最优的方格在中心，次优的是四个角落，最次则是剩下的方格。
int computerMove(vector<char> board, char computer);

// 恭喜获胜或宣布和棋。接受胜出方、计算机的棋子与人类玩家的棋子作为参数
void announceWinner(char winner, char computer, char human);

const char X = 'X';
const char O = 'O';
const char EMPTY = ' ';
const char TIE = 'T';
const char NO_ONE = 'N';

int main()
{
	int move;
	const int NUM_SQUARES = 9;
	vector<char> board(NUM_SQUARES, EMPTY);
	instructions();
	char human = humanPiece();
	char computer = opponent(human);
	char turn = X;
	displayBoard(board);
	while (winner(board) == NO_ONE) {
		if (turn == human) {
			move = humanMove(board, human);
			board[move] = human;
		}
		else {
			move = computerMove(board, computer);
			board[move] = computer;
		}
		displayBoard(board);
		turn = opponent(turn);
	}
	announceWinner(winner(board), computer, human);

	return 0;
}

void instructions()
{
	cout << "Welcome to the ultimate man-machine showdown:Tic-Tac-Toe." << endl;
	cout << "--where human brain is pit against silicon processor" << endl << endl;
	cout << "Make your move known by entering a number, 0 - 8. The number" << endl;
	cout << "corresponds to the desired board position, as illustrated:" << endl << endl;
	cout << "0 | 1 | 2" << endl;
	cout << "---------" << endl;
	cout << "3 | 4 | 5" << endl;
	cout << "---------" << endl;
	cout << "6 | 7 | 8" << endl;
	cout << endl;
	cout << "Prepare yourself, human. The battle is about to begin." << endl << endl;
}

char askYesNo(string question)
{
	char response;
	do
	{
		cout << question << " (y/n):";
		cin >> response;
	} while (response != 'y' && response != 'n');
	return response;
}

int askNumber(string question, int high, int low)
{
	int number;
	do
	{
		cout << question << " (" << low << " - " << high << "): ";
		cin >> number;
	} while (number > high || number < low);
	return number;
}

char humanPiece()
{
	char go_first = askYesNo("Do you require the first move?");
	if (go_first == 'y') {
		cout << endl << "Then take the first move. You will need it." << endl;
		return X;
	}
	else {
		cout << endl << "Your bravery will be your undoing...I will go first." << endl;
		return O;
	}
}

char opponent(char piece)
{
	return piece == X ? O : X;
}

void displayBoard(const vector<char> &board)
{
	cout << "\n\t" << board.at(0) << " | " << board.at(1) << " | " << board.at(2);
	cout << "\n\t" << "---------";
	cout << "\n\t" << board.at(3) << " | " << board.at(4) << " | " << board.at(5);
	cout << "\n\t" << "---------";
	cout << "\n\t" << board.at(6) << " | " << board.at(7) << " | " << board.at(8);
	cout << endl << endl;
}

char winner(const vector<char> &board)
{
	// 所有可能的获胜方式
	const int WINNING_ROWS[8][3] = {
		{0,1,2},
		{3,4,5},
		{6,7,8},
		{0,3,6},
		{1,4,7},
		{2,5,8},
		{0,4,8},
		{2,4,6}
	};
	const int TOTAL_ROWS = 8;
	// 检查3个目标方格是否有同样的值（不空），如果有，则有胜出者
	for (int row = 0; row < TOTAL_ROWS; ++row) {
		if (board[WINNING_ROWS[row][0]] != EMPTY && board[WINNING_ROWS[row][0]] == board[WINNING_ROWS[row][1]] && board[WINNING_ROWS[row][1]] == board[WINNING_ROWS[row][2]]) {
			return board[WINNING_ROWS[row][0]];
		}
	}
	// 没有玩家获胜，检查是不是平局（没有剩余的空格子）
	if (count(board.begin(), board.end(), EMPTY) == 0)
		return TIE;
	// 没有玩家获胜也不是平局，则游戏暂时没有胜者
	return NO_ONE;
}

inline bool isLegel(const vector<char> &board, int move)
{
	return (board.at(move) == EMPTY);
}

int humanMove(const vector<char> &board, char human)
{
	int move = askNumber("Where will you move?", (board.size() - 1));
	while (!isLegel(board, move)) {
		cout << endl << "That square is already occupied, foolish human." << endl;
		move = askNumber("Where will you move?", (board.size() - 1));
	}
	cout << "Fine..." << endl;
	return move;
}

int computerMove(vector<char> board, char computer)
{
	// （1）如果计算机采用某一招棋能获胜，则选择这一招棋。
	unsigned int move = 0;
	bool found = false;
	while (!found && move < board.size()) {
		if (isLegel(board, move)) {
			board.at(move) = computer;
			found = winner(board) == computer;
			board.at(move) = EMPTY;
		}
		if (!found) {
			++move;
		}
	}
	// （2）否则，如果人类玩家能用其下一招棋获胜，则出棋阻止他。
	if (!found) {
		move = 0;
		char human = opponent(computer);
		while (!found && move < board.size()) {
			if (isLegel(board, move)) {
				board.at(move) = human;
				found = winner(board) == human;
				board.at(move) = EMPTY;
			}
			if (!found) {
				++move;
			}
		}
	}
	// （3）否则，在剩下的空方格中选择最优的一个方格。最优的方格在中心，次优的是四个角落，最次则是剩下的方格。
	if (!found) {
		move = 0;
		unsigned int i = 0;
		const int BEST_MOVES[] = { 4,0,2,6,8,1,3,5,7 };
		while (!found && i < board.size()) {
			move = BEST_MOVES[i];
			if (isLegel(board, move)) {
				found = true;
			}
			++i;
		}
	}

	cout << "I shall take square number " << move << endl;

	return move;
}

void announceWinner(char winner, char computer, char human)
{
	if (winner == computer) {
		cout << winner << "'s won!" << endl;
		cout << "As I predicted, human, I am triumphant once more -- proof" << endl;
		cout << "that computers are superior to humans in all regards." << endl;
	}
	else if (winner == human) {
		cout << winner << "'s won!" << endl;
		cout << "No, no! It cannot be! Somehow you tricked me, human." << endl;
		cout << "But never again! I, the computer, so swear it!" << endl;
	}
	else {
		cout << "It's a tie" << endl;
		cout << "You were most lucky, human, and somehow managed to tie me." << endl;
		cout << "Celebrate...for this is the best you will ever achivec." << endl;
	}
}
