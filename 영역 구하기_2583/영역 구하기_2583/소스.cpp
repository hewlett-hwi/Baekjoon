#include <stdio.h>
#include <iostream>
using namespace std;

#define MAX 101
#define USED 999
#define VISITED 777
int map[MAX][MAX];
int m, n, k;
int answer[1000];
int answerCount = 0;

int dy[4] = { 0, -1, 0, 1 };
int dx[4] = { -1, 0, 1, 0 };

int fill(int y1, int x1, int y2, int x2) {
	int ret = 0;

	for (int y = y1; y >= y2; y--) {
		for (int x = x1; x <= x2; x++) {
			map[y][x] = USED;
			ret++;
		}
	}
	return ret;
}

void printMap() {
	for (int y = 0; y < m; y++) {
		for (int x = 0; x < n; x++) {
			cout << map[y][x];
		}
		cout << endl;
	}
}

int dfs(int y, int x) {
	int ret = 1;
	if (y < 0 || x < 0 || y >= m || x >= n)
		return 0;
	if (map[y][x] != 0)
		return 0;
	
	map[y][x] = VISITED;

	for (int i = 0; i < 4; i++) {
		ret = ret + dfs(y + dy[i], x + dx[i]);
	}

	return ret;
}

void bubbleSort() {
	for (int i = 0; i < answerCount; i++) {
		for (int j = 0; j < answerCount - i -1; j++) {
			if (answer[j] > answer[j + 1]) {
				int temp = answer[j];
				answer[j] = answer[j+1];
				answer[j + 1] = temp;
			}
		}
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	freopen("Text.txt", "r", stdin);

	cin >> m >> n >> k;

	for (int i = 0; i < k; i++) {
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		y1 = m - y1 - 1;
		y2 = m - y2; x2 = x2 - 1;

		fill(y1, x1, y2, x2);
	}


	for (int y = 0; y < m; y++) {
		for (int x = 0; x < n; x++) {
			if (map[y][x] == 0) {
				//dfs
				int ret =dfs(y, x);
				answer[answerCount++] = ret;
			}
		}
	}

	//printMap();
	bubbleSort();

	cout << answerCount << endl;

	for (int i = 0; i < answerCount; i++) {
		cout << answer[i] <<" ";
	}

	return 0;
}
