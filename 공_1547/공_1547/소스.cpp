#include <iostream>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	freopen("Text.txt", "r", stdin);

	int N = 0;
	cin >> N;

	int inBall = 1;

	for (int i = 0; i < N; i++)
	{
		int left, right;
		cin >> left >> right;

		if (inBall == left)
			inBall = right;
		else if (inBall == right)
			inBall = left;
		
	}

	cout << inBall << endl;

	return 0;
}