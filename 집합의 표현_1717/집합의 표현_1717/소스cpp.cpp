#include <stdio.h>

int n, m;
int ary[1000001];

inline int find(int target)
{
	if (ary[target] == target)
		return target;
	return ary[target] = find(ary[target]);
}

int main()
{
	freopen("Text.txt", "r", stdin);

	scanf("%d %d", &n, &m);
	for (int i = 0; i <= n; i++)
		ary[i] = i;

	for (int i = 0; i < m; i++)
	{
		int cmd, a, b;
		scanf("%d %d %d", &cmd, &a, &b);

		if (cmd == 0) {
			int aParent = find(a);
			int bParent = find(b);
			if (aParent != bParent)
				ary[aParent] = bParent;
		}
		else {
			if (find(a) == find(b))
				printf("YES\n");
			else
				printf("NO\n");
		}
	}
	return 0;
}
