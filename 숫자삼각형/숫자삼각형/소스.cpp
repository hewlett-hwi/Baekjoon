#include <iostream>
using namespace std;
#define MAX(A, B) ( (A>B) ? (A) : (B) )

int n = 0;
int d[501][501];
int c[501][501];

int main()
{
	std::ios::sync_with_stdio(false);
	freopen("input2.txt", "r", stdin);
	cin >> n; // 테스트케이스 개수

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			cin >> d[i][j];
		}
	}


	c[1][1] = d[1][1];
	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			c[i][j] = MAX(c[i - 1][j - 1], c[i - 1][j]) + d[i][j];
		}
	}

	int ANSWER = 0;
	for (int i = 1; i <= n; i++) {
		if (ANSWER <= c[n][i])
			ANSWER = c[n][i];
	}

	cout << ANSWER << endl;

	return 0;
}
