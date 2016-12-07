#include <iostream>
#define MAX(A, B) (A > B) ? A : B
using namespace std;
int n;
int in[52];
int dp[52][500002];

void init() {
	for (int i = 0; i < 52; i++) {
		for (int j = 0; j < 500002; j++) {
			dp[i][j] = -2;  //초기화
		}
	}
}

int process(int index, int leftTop, int rightTop) {
	int t = leftTop - rightTop + 250000;

	if (index > n) return -1; //불가능한 경우..
	if (leftTop > 250000 || rightTop > 250000) return -1;

	if (dp[index][t] != -2) { //방문했던 곳인 경우
		return dp[index][t];
	}

	dp[index][t] = -1;
	if (t == 250000 && leftTop != 0) dp[index][t] = 0;

	int f = process(index + 1, leftTop + in[index], rightTop);
	int s = process(index + 1, leftTop, rightTop + in[index]);
	int z = process(index + 1, leftTop, rightTop);

	if (f != -1) {
		dp[index][t] = MAX(dp[index][t], f + in[index]);
	}

	if (s != -1) {
		dp[index][t] = MAX(dp[index][t], s);
	}

	if (z != -1) {
		dp[index][t] = MAX(dp[index][t], z);
	}

	return dp[index][t]; // 높이차이가 t일때, (앞으로 같아질수있다면) 왼쪽에 쌓을 탑 높이, 왼쪽탑만 쭉 더해서 리턴.
}

int main() {
	std::ios::sync_with_stdio(false);
	freopen("input2.txt", "r", stdin);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> in[i];
	}
	init();
	cout << process(0, 0, 0) << endl;
}




/*
6
3
2 3 5
3
10 9 2
2
11 11
9
14 3 20 15 15 14 24 23 15
50
14 5 29 43 34 17 21 17 10 21 6 35 9 3 20 18 47 42 1 27 13 8 8 18 13 36 25 3 48 4 36 19 34 1 10 2 4 35 3 24 43 13 24 8 28 31 1 49 6 16
40
5010 1234 12 34 50000 1234 55000 52000 23 100 5010 1234 12 34 50000 1234 55000 52000 23 100 5010 1234 12 34 50000 1234 55000 52000 23 100 5010 1234 12 34 50000 1234 55000 52000 23 100


5
-1
11
64
491
329294
*/