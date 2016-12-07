#include <iostream>
using namespace std;
#define MIN(x, y) ( (x>y) ? y : x )

int n = 0;
int cache[1000001];

int main()
{
	cin >> n;
	// cache[1]은 0으로 셋팅
	for (int i = 2; i <= n; i++) {
		cache[i] = cache[i - 1] + 1;

		if (i % 2 == 0) {
			cache[i] = MIN(cache[i / 2], cache[i - 1]) + 1;
		}
		if (i % 3 == 0) {
			cache[i] = MIN(cache[i / 3], cache[i - 1]) + 1;
		}
	}

	cout << cache[n] << endl;

	return 0;
}

