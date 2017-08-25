#include <stdio.h>
#include <iostream>
using namespace std;

int n, m;
int ary[1000001];

int allChange(int target, int tobe)
{
	int ret = 0;
	for (int i = 1; i <= n; i++) 
	{
		if (ary[i] == target) {
			ary[i] = tobe;
			ret++;
		}

	}
	return ret;
}

int main()
{
	std::ios::sync_with_stdio(false);
	freopen("Text.txt", "r", stdin);

	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		ary[i] = i;

	for (int i = 0; i < m; i++)
	{
		int cmd, a, b;
		scanf("%d %d %d", &cmd, &a, &b);

		switch (cmd)
		{
			case 0:
				if (a < b) {
					ary[b] = a;
					allChange(b, a);
				}
				else {
					ary[a] = b;
					allChange(a, b);
				}

				break;
			case 1:
				if (ary[a] == ary[b])
					printf("YES\n");
				else
					printf("NO\n");
				break;
		}
	}

	return 0;
}
