#include <iostream>
#include <stdio.h>
using namespace std;

int N;
int c[1001] = {1, };

void makeSosu()
{
	for (int i = 2; i <= 1000; i++)
	{
		if (c[i] == true)
		{
			int cal = 1;
			while (1)
			{
				cal++;
				int result = i * cal;
				if (result > 1000)
					break;
				c[result] = false;
			}
		}
	}
}

int isSosu(int num)
{
	if (c[num] == 1)
		return 1;
	else
		return 0;
}

int main(int argc, char** argv)
{
	for (int i = 0; i < 1001; i++)
		c[i] = 1;
	c[0] = c[1] = 0;
	makeSosu();

	//freopen("Text.txt", "r", stdin);
	std::ios::sync_with_stdio(false);
	cin >> N;

	int answer = 0;

	for (int i = 0; i < N; i++)
	{
		int input;
		cin >> input;
		if (isSosu(input))
			answer++;
	}
	cout << answer << endl;

	return 0;
}