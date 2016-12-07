#include <iostream>
using namespace std;

int T = 0;

int ZeroOneCount[2];
int cache[41][3];

int fibonacci(int n);

int main()
{
	std::ios::sync_with_stdio(false);
	freopen("input2.txt", "r", stdin);
	cin >> T; // 테스트케이스 개수


	//실제알고리즘 구현
	for (int i = 0; i < T; i++)
	{
		int n = 0; //input
		ZeroOneCount[0] = 0;
		ZeroOneCount[1] = 0;

		for (int i = 0; i < 41; i++) {
			cache[i][0] = -1;
			cache[i][1] = -1;
			cache[i][2] = -1;
		}
			


		cin >> n;

		fibonacci(n);

		//cout << ZeroOneCount[0] << " " << ZeroOneCount[1] << endl;
		cout << cache[n][1] << " " << cache[n][2] << endl;
	}



	return 0;
}

int fibonacci(int n) {
	if (n == 0) {
		//printf("0");
		ZeroOneCount[0]++;
		cache[n][1] = 1;
		cache[n][2] = 0;
		return 0;
	}
	else if (n == 1) {
		//printf("1");
		ZeroOneCount[1]++;
		cache[n][1] = 0;
		cache[n][2] = 1;
		return 1;
	}
	else {
		if (cache[n][0] != -1)
			return cache[n][0];
		else // -1 인 경우
		{
			int output = fibonacci(n - 1) + fibonacci(n - 2);
			cache[n][1] = cache[n - 2][1] + cache[n - 1][1];
			cache[n][2] = cache[n - 2][2] + cache[n - 1][2];
			cache[n][0] = output;
			return output;
		}
	}
}