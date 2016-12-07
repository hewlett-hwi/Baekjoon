#include <iostream>
using namespace std;

int Y, X;
int d[501][501];
int c[501][501];

int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };

int go(int y, int x);

int main()
{
	std::ios::sync_with_stdio(false);
	freopen("Text.txt", "r", stdin);

	cin >> Y >> X;

	for (int i = 1; i <= Y; i++) {
		for (int j = 1; j <= X; j++) {
			cin >> d[i][j];
		}
	}

	cout << go(1, 1) << endl;

	//for (int i = 1; i <= Y; i++) {
	//	for (int j = 1; j <= X; j++) {
	//		cout << c[i][j] << " ";
	//	}
	//	cout << endl;
	//}
	

	return 0;
}

int go(int y, int x )
{
	int height = d[y][x];
	if (y == Y && x == X)
		return 1;
	if (y == Y + 1 || x == X + 1 || y == 0 || x == 0)
		return 0;

	if (c[y][x] != 0)
		return c[y][x];
	// 미로찾기 재귀함수에선 안에 for문 안에 재귀하는게 핵심
	for (int i = 0; i < 4; i++) {
		int yNew = y + dy[i];
		int xNew = x + dx[i];

		if (d[yNew][xNew] < height)
			c[y][x] = c[y][x] + go(yNew, xNew);
	}

	return c[y][x];
}