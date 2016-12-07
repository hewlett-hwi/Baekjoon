#include <iostream>
using namespace std;
#define MAX(A, B) ( (A>B) ? (A) : (B) )

int N, M;
int d[1001][1001];
int c[1001][1001];

int main()
{
	std::ios::sync_with_stdio(false);
	freopen("Text.txt", "r", stdin);

	cin >> N >> M;
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= M; x++) {
			cin >> d[y][x];
		}
	}

	c[1][1] = d[1][1];
	for (int y = 2; y <= N; y++) {
		c[y][1] = c[y - 1][1] + d[y][1];
	}
	for (int x = 2; x <= M; x++) {
		c[1][x] = c[1][x - 1] + d[1][x];
	}

	for (int y = 2; y <= N; y++)
	{
		for (int x = 2; x <= M; x++)
		{
			c[y][x] = MAX(MAX(c[y - 1][x], c[y][x - 1]), c[y - 1][x - 1]) + d[y][x];
		}
	}

	//for (int y = 1; y <= N; y++) {
	//	for (int x = 1; x <= M; x++) {
	//		cout << c[y][x]<<" ";
	//	}
	//	cout << endl;
	//}


	cout << c[N][M] << endl;

	return 0;
}
