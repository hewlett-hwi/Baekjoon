#include <iostream>
using namespace std;
#define MAX 51

int TC;
int M, N, K;
int answer = 1;
int map[MAX][MAX] = {0, };
int visited[MAX][MAX] = { 0, };

int dir[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} };

void showMap() {
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			cout << map[y][x];
		}
		cout << endl;
	}
	cout << endl;
}

void init() {
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			map[y][x] = 0;
			visited[y][x] = 0;
		}
	}

	answer = 1;
}

void dfs(int y, int x) {
	if (y < 0 || x < 0 || y >= N || x >= M)
		return;
	if (map[y][x] != 1 || visited[y][x])
		return;

	visited[y][x] = 1;
	map[y][x] = answer;

	for (int i = 0; i < 4; i++) {
		int newY = y + dir[i][0];
		int newX = x + dir[i][1];

		dfs(newY, newX);
	}
}

void doDfs() {
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			if (map[y][x] == 1) {
				answer++;
				dfs(y, x);
			}
		}
	}
}

int main()
{
	freopen("Text.txt", "r", stdin);
	
	cin >> TC;
	while (TC--) {
		init();
		cin >> M >> N >> K;

		for (int i = 0; i < K; i++) {
			int y, x;
			cin >> x >> y;
			map[y][x] = 1;
		}

		doDfs();
		//showMap();
		cout << answer - 1 << endl;
	}

	return 0;
}
