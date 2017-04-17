#include <iostream>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	freopen("Text.txt", "r", stdin);

	int sum = 0;
	int answer = 0;
	for (int i = 0; i < 4; i++)
	{
		int in, out = 0;
		cin >> out >> in;

		
		sum = sum  + (-out + in);
		if (answer <= sum)
			answer = sum;
	}

	cout << answer << endl;

	return 0;
}