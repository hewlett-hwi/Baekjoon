#include <iostream>
using namespace std;

int d[10001];

int main()
{
	std::ios::sync_with_stdio(false);
	freopen("Text.txt", "r", stdin);

	int N, X;
	cin >> N >> X;

	for (int i = 0; i < N; i++)
	{
		cin >> d[i];
	}

	for (int i = 0; i < N; i++)
	{
		if (d[i] < X)
		{
			cout << d[i] << " ";
		}
	}

	return 0;
}
