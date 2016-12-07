/*
#include <iostream>
using namespace std;
#define MAX(A, B) ( (A>B) ? (A) : (B) )

int n = 0;
int d[301];
int c[301][3];

int main()
{
	std::ios::sync_with_stdio(false);
	freopen("input2.txt", "r", stdin);
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> d[i];

	c[1][1] = d[1];
	c[1][2] = d[1];
	c[2][1] = d[2];
	c[2][2] = d[1] + d[2];

	for (int i = 3; i <= n; i++)
	{
		c[i][1] = MAX(c[i - 2][1], c[i - 2][2]) + d[i];
		c[i][2] = c[i - 1][1] + d[i];
		//cout << c[i][1] << " " << c[i][2] << endl;
	}


	cout << MAX(c[n][1], c[n][2]) << endl;

	return 0;
}

*/

#include <iostream>
using namespace std;
#define MAX(A, B) ( (A>B) ? (A) : (B) )

int n = 0;
int d[301];
int c[301];

int main()
{
	std::ios::sync_with_stdio(false);
	freopen("input2.txt", "r", stdin);
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> d[i];

	c[1] = d[1];
	c[2] = d[1] + d[2];

	for (int i = 3; i <= n; i++)
	{
		c[i] = MAX(c[i - 3] + d[i - 1] + d[i], c[i - 2] + d[i]);
		//cout << c[i] << endl;
	}


	cout << c[n] << endl;

	return 0;
}
