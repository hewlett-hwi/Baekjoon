#include <iostream>
using namespace std;

int n = 0;
int c[100001][3];

int main()
{
	std::ios::sync_with_stdio(false);
	freopen("Text.txt", "r", stdin);
	cin >> n;

	c[1][0] = c[1][1] = c[1][2] = 1;
	for (int i = 2; i <= n; i++)
	{
		c[i][0] =  (c[i - 1][0] + c[i - 1][1] + c[i - 1][1]) % 9901;
		c[i][1] = (c[i - 1][0] + c[i - 1][2]) % 9901;
		c[i][2] = (c[i - 1][0] + c[i - 1][1]) % 9901;
	}

	cout << (c[n][0] + c[n][1] + c[n][2])%9901  << endl;



	return 0;
}
