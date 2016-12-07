#include <iostream>
using namespace std;

#define R 0
#define G 1
#define B 2

#define MIN(a, b) ( ((a) > (b)) ? (b) : (a) )

int main()
{
	std::ios::sync_with_stdio(false);
	freopen("input2.txt", "r", stdin);

	int n = 0; // 집의 수
	int input[1001][3];
	int cache[1001][3]; // i번째 집에서 r g b 를 골랐을때 최소값 저장
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> input[i][R]; cin >> input[i][G]; cin >> input[i][B];
		//cout << input[i][R]; cout << input[i][G]; cout << input[i][B];
		//cout << endl;
	}

	// 첫번쨰 집은 미리 채워놓음
	cache[1][R] = input[1][R]; cache[1][G] = input[1][G]; cache[1][B] = input[1][B];

	for (int i = 2; i <= n; i++) {
		cache[i][R] = MIN(cache[i - 1][G], cache[i - 1][B]) + input[i][R];
		cache[i][G] = MIN(cache[i - 1][R], cache[i - 1][B]) + input[i][G];
		cache[i][B] = MIN(cache[i - 1][R], cache[i - 1][G]) + input[i][B];
		//cout << input[i][R] << " " << input[i][G] << " " << input[i][B] << endl;
		//cout << cache[i][R] << " " << cache[i][G] << " " << cache[i][B] << endl;
	}

	int ANSWER = 0;
	ANSWER = (cache[n][R] > cache[n][G]) ? cache[n][G] : cache[n][R];
	ANSWER = (ANSWER > cache[n][B]) ? cache[n][B] : ANSWER;

	cout << ANSWER << endl;

	return 0;
}
