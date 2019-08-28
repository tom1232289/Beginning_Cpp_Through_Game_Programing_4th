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
int computerMove(const vector<char> &board, char computer);

// ��ϲ��ʤ���������塣����ʤ�������������������������ҵ�������Ϊ����
void announceWinner(char winner, char computer, char human);










int main()
{

}