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
int computerMove(const vector<char> &board, char computer);

// 恭喜获胜或宣布和棋。接受胜出方、计算机的棋子与人类玩家的棋子作为参数
void announceWinner(char winner, char computer, char human);










int main()
{

}