#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str;
	string * pStr = &str;
	string ** pStr2 = &pStr;
	size_t size = (*pStr2)->size();
	cout << size << endl;

	return 0;
}