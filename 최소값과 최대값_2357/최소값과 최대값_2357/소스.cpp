#include <iostream>
using namespace std;

int d[100001];

int main()
{
	int N, M;
	std::ios::sync_with_stdio(false);
	freopen("Text.txt", "r", stdin);

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		cin >> d[i];
	}

	for (int i = 1; i <= M; i++) {
		int a, b;
		int MIN, MAX;
		cin >> a >> b;

		if (d[a] <= d[a + 1]) {
			MIN = d[a]; MAX = d[a + 1];
		}
		else {
			MIN = d[a + 1]; MAX = d[a];
		}

		for (int j = a + 2; j <= b; j++) {
			if (d[j] <= MIN)
				MIN = d[j];
			else if (d[j] >= MAX)
				MAX = d[j];
		}

		cout << MIN << " " << MAX << endl;
	}


	return 0;
}
