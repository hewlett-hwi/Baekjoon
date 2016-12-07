#include <iostream>
using namespace std;
#define MAX(a, b) ( (a>b) ? a : b )

int d[10000];
int c[10000];

int main()
{
	int test_case;
	int n;

	std::ios::sync_with_stdio(false);
	freopen("input2.txt", "r", stdin);
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> d[i];
	}

	c[1] = d[1];
	c[2] = MAX(c[1] + d[1], c[0] + d[2]);
	c[3] = MAX(MAX(c[2] + d[1], c[1] + d[2]), c[0] + d[3]);


	for (int i = 4; i <= n; i++)
	{
		int max = 0;
		for (int j = 1; j <= i; j++)
		{
			if (max <= c[i - j] + d[j])
				max = c[i - j] + d[j];
		}
		c[i] = max;
	}

	cout << c[n] << endl;

	return 0;
}