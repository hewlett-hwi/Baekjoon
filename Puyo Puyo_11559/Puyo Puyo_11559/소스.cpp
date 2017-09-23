#include <stdio.h>
#include <iostream>
using namespace std;

char map[12][6];
int dy[4] = { 0, -1, 0, 1 };
int dx[4] = { -1, 0, 1, 0 };
int visited[12][6]; // 0:초기 1:대기 2:방문완료 4:터질것

void printMap() {
	for (int y = 0; y < 12; y++) {
		for (int x = 0; x < 6; x++)
			cout << map[y][x];
		cout << endl;
	}
	cout << endl;
}

void changeVisitedStatus(int from, int to) {
	for (int y = 0; y < 12; y++) {
		for (int x = 0; x < 6; x++) {
			if (visited[y][x] == from)
				visited[y][x] = to;
		}
	}
}

void changeVisitedStatusZero() {
	for (int y = 0; y < 12; y++) {
		for (int x = 0; x < 6; x++) {
			visited[y][x] = 0;
		}
	}
}

int fire() {
	int ret = 0;
	for (int y = 0; y < 12; y++) {
		for (int x = 0; x < 6; x++) {
			if (visited[y][x] == 4)
			{
				map[y][x] = '.';
				ret++;
			}

		}
	}

	return ret;
}

void land() {
	for (int j = 0; j < 6; j++)
	{
		for (int i = 11; i >= 0; i--)
		{
			if (map[i][j] != '.')
			{
				int k = i;
				while (k <= 11)
				{
					if (map[k + 1][j] == '.')
					{
						char tmp = map[k][j];
						map[k][j] = '.';
						map[k + 1][j] = tmp;
						k = k + 1;
					}
					else
						break;
				}

			}
		}
	}
}

int dfs(int y, int x, char target) {
	int ret = 1;

	if (y < 0 || x < 0 || y >= 12 || x >= 6)
		return 0;
	if (map[y][x] != target || visited[y][x] != 0)
		return 0;

	visited[y][x] = 1;

	for (int i = 0; i < 4; i++) {
		ret = ret + dfs(y + dy[i], x + dx[i], target);
	}

	return ret;
}


int doDfs() {
	int answer = 0;
	bool isFire = false;
	while (1)
	{
		printMap();

		for (int y = 0; y < 12; y++) {
			for (int x = 0; x < 6; x++) {
				if (visited[y][x] == false && map[y][x] != '.')
				{
					int ret = dfs(y, x, map[y][x]);
					if (ret >= 4)
						changeVisitedStatus(1, 4), isFire = true;
					else
						changeVisitedStatus(1, 2);
				}
			}
		}

		fire();
		land();


		if (isFire == true)
			answer++, isFire = false;
		else
			break;

		// visited 초기화
		changeVisitedStatusZero();

	} // while end
	return answer;
}


int main()
{
	std::ios::sync_with_stdio(false);
	freopen("Text.txt", "r", stdin);

	for (int y = 0; y < 12; y++) {
		for (int x = 0; x < 6; x++)
			cin >> map[y][x];
	}

	cout << doDfs() << endl;

	//printMap();

	return 0;
}