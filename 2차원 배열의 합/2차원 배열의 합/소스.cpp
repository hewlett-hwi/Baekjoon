#include <iostream>
using namespace std;

int n, m, k;
int ary[301][301];

int main()
{
	std::ios::sync_with_stdio(false);
	freopen("input.txt", "r", stdin);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= m; j++)
		cin >> ary[i][j];

	cin >> k; // �� ��

	// k����ŭ ��µ�
	for (int i = 0; i < k; i++) {
		int y1, x1, y2, x2;
		cin >> y1 >> x1;
		cin >> y2 >> x2;

		int sum = 0;
		for (int a = y1; a <= y2; a++)
		for (int b = x1; b <= x2; b++)
			sum += ary[a][b];
		cout << sum << endl;
	}

	return 0;
}
