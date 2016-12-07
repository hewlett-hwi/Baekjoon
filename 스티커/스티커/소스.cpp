#include <iostream>
using namespace std;
#define MAX(a, b) ( (a>b) ? (a) : (b) )

int T = 0;
int d[100001][2];
int c[100001][2];

int main()
{
	std::ios::sync_with_stdio(false);
	freopen("input2.txt", "r", stdin);
	cin >> T; // 테스트케이스 개수

	//실제알고리즘 구현
	for (int k = 0; k < T; k++)
	{
		int n = 0; cin >> n;

		for (int j = 1; j <= n; j++)
			cin >> d[j][0];
		for (int j = 1; j <= n; j++)
			cin >> d[j][1];

		c[1][0] = d[1][0];
		c[1][1] = d[1][1];
		c[2][0] = d[1][1] + d[2][0];
		c[2][1] = d[1][0] + d[2][1];
		
		for (int i = 3; i <= n; i++)
		{
			c[i][0] = MAX(c[i-2][1], MAX(c[i - 2][0], c[i - 1][1])) + d[i][0];
			c[i][1] = MAX(c[i-2][0], MAX(c[i - 2][1], c[i - 1][0])) + d[i][1];
		}

		cout << MAX( MAX(c[n-1][0], c[n-1][1]), MAX(c[n][0], c[n][1]) )<< endl;

		// 초기화 필요
	}
	return 0;
}
