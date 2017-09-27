#include <stdio.h>
#include <iostream>
using namespace std;

#define MAX (1000001)
char str1[MAX];
char str2[MAX];

int main()
{
	std::ios::sync_with_stdio(false);
	freopen("Text.txt", "r", stdin);

	cin >> str1 >> str2;
	cout << str2 << str2 << endl;

	return 0;
}
