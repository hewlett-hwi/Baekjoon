#include <iostream>
using namespace std;

int N, K;

typedef struct struct_country
{
	int gold;
	int silver;
	int bronze;
}Country;

Country country[1001];

int main()
{
	std::ios::sync_with_stdio(false);
	freopen("Text.txt", "r", stdin);

	cin >> N >> K;

	for (int i = 0; i < N; i++)
	{
		int num = 0;
		int gold = 0;
		int silver = 0;
		int bronze = 0;

		cin >> num >> gold >> silver >> bronze;
		country[num].gold = gold;
		country[num].silver = silver;
		country[num].bronze = bronze;
	}

	int answer = 1;
	for (int i = 1; i <= N; i++)
	{
		if (country[K].gold < country[i].gold) answer++;
		else if (country[K].gold == country[i].gold && country[K].silver < country[i].silver)    answer++;
		else if (country[K].gold == country[i].gold && country[K].silver == country[i].silver && country[K].bronze < country[i].bronze)    answer++;
		else continue;
	}

	cout << answer << endl;

	return 0;
}