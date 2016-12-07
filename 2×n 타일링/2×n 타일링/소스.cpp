#include <iostream>
using namespace std;

int n = 0;
long long c[1001];

int main()
{
	std::ios::sync_with_stdio(false);
	freopen("Text.txt", "r", stdin);
	cin >> n; 

	c[1] = 1; c[2] = 2;

	for (int i = 3; i <= n; i++)
		c[i] = ( c[i - 2] + c[i - 1] ) % 10007;

	cout << c[n] << endl;

	return 0;
}
