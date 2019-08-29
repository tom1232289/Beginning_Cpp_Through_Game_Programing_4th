/*
α���룺
����һ���յ�Tic-Tac-Toe������
��ʾ��Ϸ��˵��
����˭����
��ʾ����
while��û���˻�ʤ ���� ����ƽ�֣�
	if ����������
		ȡ������Ҫ�ߵ�λ��
		��������
	else
		����AIҪ�ߵ�λ��
		��������
	��ʾ����
	ת������
ף�ػ�ʤ�� ���� ����ƽ��
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// ��ʾ��Ϸ����ָ��
void instructions();

// ѯ���ǻ�񡣽���һ��������Ϊ����������'y'��'n'
char askYesNo(string question);

// ѯ��һ����Χ�ڵ����֡�����һ�����⡢һ����Χ���޺�һ����Χ������Ϊ����������low��high֮������֡�
int askNumber(string question, int high, int low = 0);

// ȷ����ҵ����ӣ�����'X'��'O'
char humanPiece();

// ����������ӵ�Ӧ�����ӡ�����'X'��'O'������'X'��'O'
char opponent(char piece);

// ����Ļ����ʾ���̡�����������Ϊ����
void displayBoard(const vector<char> &board);

// ȷ����Ϸ��ʤ�ߡ�����������Ϊ����������'X'��'O'��'T'����ʾ���壩��'N'����ʾ��û����һ��ʤ����
char winner(const vector<char> &board);

// ȷ��һ����ĺϷ��ԡ�����һ��������һ������Ϊ����������true��false
bool isLegel(const vector<char> &board, int move);

// ��ȡ������ҵ�һ���塣����һ��������������ҵ�������Ϊ������������ҵ�һ����
int humanMove(const vector<char> &board, char human);

// ����������һ���塣����һ��������������������Ϊ���������ؼ������һ����
// ����˼·��
// ��1��������������ĳһ�����ܻ�ʤ����ѡ����һ���塣
// ��2������������������������һ�����ʤ���������ֹ����
// ��3��������ʣ�µĿշ�����ѡ�����ŵ�һ���������ŵķ��������ģ����ŵ����ĸ����䣬�������ʣ�µķ���
int computerMove(vector<char> board, char computer);

// ��ϲ��ʤ���������塣����ʤ�������������������������ҵ�������Ϊ����
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
	// ���п��ܵĻ�ʤ��ʽ
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
	// ���3��Ŀ�귽���Ƿ���ͬ����ֵ�����գ�������У�����ʤ����
	for (int row = 0; row < TOTAL_ROWS; ++row) {
		if (board[WINNING_ROWS[row][0]] != EMPTY && board[WINNING_ROWS[row][0]] == board[WINNING_ROWS[row][1]] && board[WINNING_ROWS[row][1]] == board[WINNING_ROWS[row][2]]) {
			return board[WINNING_ROWS[row][0]];
		}
	}
	// û����һ�ʤ������ǲ���ƽ�֣�û��ʣ��Ŀո��ӣ�
	if (count(board.begin(), board.end(), EMPTY) == 0)
		return TIE;
	// û����һ�ʤҲ����ƽ�֣�����Ϸ��ʱû��ʤ��
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
	// ��1��������������ĳһ�����ܻ�ʤ����ѡ����һ���塣
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
	// ��2������������������������һ�����ʤ���������ֹ����
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
	// ��3��������ʣ�µĿշ�����ѡ�����ŵ�һ���������ŵķ��������ģ����ŵ����ĸ����䣬�������ʣ�µķ���
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
