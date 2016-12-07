#include <iostream>
using namespace std;

int M, N;
int c[21][301][3]; // dp용 0 이전 index, 1 최대 값, 2 현재 기업 투자액
int d[21][301]; // 입력값
int output[21]; // 기업별 투자금액 저장

int main()
{
	std::ios::sync_with_stdio(false);
	freopen("Text.txt", "r", stdin);

	cin >> M >> N;

	for (int i = 1; i <= M; i++)
	{
		int unit = 0;
		cin >> unit;
		for (int j = 1; j <= N; j++) {
			cin >> d[j][unit];
		}
	}

	for (int i = 1; i <= M; i++) // 첫번째 기업 cache 초기화
	{
		c[1][i][1] = d[1][i];
		c[1][i][2] = i;
	}


	for (int i = 2; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			for (int k = 0; k <= j; k++)
			{
				int subsum = c[i - 1][k][1] + d[i][j - k];
				if (subsum >= c[i][j][1]) {
					c[i][j][1] = subsum;
					c[i][j][0] = k;
					c[i][j][2] = j - k;
				}

			}
		}
	}

	//for (int i = 1; i <= N; i++) {
	//  for (int j = 1; j <= M; j++) {
	//      cout << c[i][j][2] << " ";
	//  }
	//  cout << endl;
	//}

	// 기업별 금액 계산
	output[N] = M - c[N][M][0]; // 마지막 기업 투자 금액

	int preindex = c[N][M][0];
	for (int i = N - 1; i >= 1; i--) {
		output[i] = c[i][preindex][2];
		preindex = c[i][preindex][0];

	}

	// 최대수익 출력
	cout << c[N][M][1] << endl;

	// 기업별 금액 출력
	for (int i = 1; i <= N; i++) {
		cout << output[i];
		if (i != N) cout << " ";
		else cout << endl;
	}

	return 0;
}