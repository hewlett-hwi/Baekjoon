#include <iostream>
using namespace std;
#define MAX(A, B) ( (A>B) ? (A) : (B) )

int N, M;
int d[1001][1001];
int c[1001][1001];
int c_row[1001][2];

int main()
{
	// �ʱ�ȭ.. �� �������� �����ָ�, 0���� ������� 0�� MAX�� ��Ƽ� �ȵ�
	for (int i = 0; i < 1001; i++) {
		c_row[i][0] = c_row[i][1] = -987654321;
	}

	std::ios::sync_with_stdio(false);
	freopen("Text.txt", "r", stdin);

	cin >> N >> M;
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= M; x++) {
			cin >> d[y][x];
		}
	}

	c[1][1] = d[1][1];

	for (int x = 2; x <= M; x++) {
		c[1][x] = c[1][x - 1] + d[1][x];
	}

	for (int y = 2; y <= N; y++)
	{
		for (int x = 1; x <= M; x++)
		{
			c_row[x][0] = MAX(c[y - 1][x], c_row[x - 1][0]) + d[y][x];
		}
		for (int x = M; x >= 1; x--)
		{
			c_row[x][1] = MAX(c[y - 1][x], c_row[x + 1][1]) + d[y][x];
		}

		for (int x = 1; x <= M; x++)
		{
			c[y][x] = MAX(c_row[x][0], c_row[x][1]);
		}

	}

	//for (int y = 1; y <= N; y++) {
	//  for (int x = 1; x <= M; x++) {
	//      cout << c[y][x]<<" ";
	//  }
	//  cout << endl;
	//}


	cout << c[N][M] << endl;

	return 0;
}