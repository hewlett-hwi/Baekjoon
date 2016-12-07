#include <iostream>
using namespace std;

long long cache[100][2];

int main()
{
	long long n = 0;

	cin >> n;

	// √ ±‚»≠
	for (long long i = 0; i < 100; i++) {
		cache[i][0] = 0;
		cache[i][1] = 0;
	}
	cache[1][0] = 0;
	cache[1][1] = 1;

	for (long long i = 2; i <= n; i++) {
		cache[i][0] = cache[i - 1][0] + cache[i - 1][1];
		cache[i][1] = cache[i - 1][0];
	}

	cout << cache[n][0] + cache[n][1] << endl;

	return 0;
}