#include <iostream>
using namespace std;

int N = 0;
int fact(int n);

int main()
{
	std::ios::sync_with_stdio(false);
	cin >> N; // �׽�Ʈ���̽� ����

	cout << fact(N) << endl;

	return 0;
}

int fact(int n)
{
	if (n == 0)
		return 1;
	else if (n == 1)
		return 1;
	return n * fact(n - 1);
}