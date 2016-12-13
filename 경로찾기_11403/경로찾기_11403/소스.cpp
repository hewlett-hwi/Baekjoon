#include <iostream>
using namespace std;

int N = 0;
int MAP[101][101];
bool VISIT[101][101];

int dfs(int i, int j);
void init();

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
				init();
				dfs(i, j);
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << MAP[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}

int dfs(int i, int j)
{
	if (VISIT[i][j] == true)
		return 0;
	// 가서 바꾸도록 여기서 처리...
	VISIT[i][j] = true;
	MAP[i][j] = 1;
	for (int a = 1; a <= N; a++)
	{
		if (MAP[j][a] == 1)
		{
			// 여기서 처리하지말고
			dfs(i, a);
		}
	}
	return 0;
}

void init()
{
	for (int i = 1; i <= N; i++)
	for (int j = 1; j <= N; j++)
		VISIT[i][j] = false;
}