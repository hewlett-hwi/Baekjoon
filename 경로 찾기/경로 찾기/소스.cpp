#include <iostream>
using namespace std;

int N = 0;
int MAP[101][101];

int main()
{
	std::ios::sync_with_stdio(false);
	freopen("Text.txt", "r", stdin);

	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> MAP[i][j];
		}
	}


	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (MAP[i][j] == 1)
			{
				bfs(i, j);
			}
		}
	}

	return 0;
}

int bfs(int i, int j)
{

}