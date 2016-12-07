#include <iostream>
using namespace std;
#define MIN(a, b) ( (a>b) ? (b) : (a) )

int n, m;
int d[1001][1001];
int c[1001][1001];
int ANSWER = 0;

int main()
{
	std::ios::sync_with_stdio(false);
	freopen("Text.txt", "r", stdin);

	cin >> n >> m;
	for (int y = 1; y <= n; y++) {
		for (int x = 1; x <= m; x++) {
			char temp;
			cin >> temp;
			d[y][x] = temp - '0';
		}
	}

	//for (int y = 1; y <= n; y++) {
	//	for (int x = 1; x <= m; x++) {
	//		cout << d[y][x] << " ";
	//	}
	//	cout << endl;
	//}

	for (int y = 1; y <= n; y++) {
		for (int x = 1; x <= m; x++) {
			if (d[y][x] == 1) {
				int min = MIN(MIN(c[y - 1][x], c[y][x - 1]), c[y - 1][x - 1]) + 1;
				c[y][x] = min;
				if (min >= ANSWER) ANSWER = min;
			}
		}
	}

	cout << ANSWER * ANSWER << endl;

	return 0;
}
