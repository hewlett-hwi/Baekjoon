#include <stdio.h>
#define MIN(A, B) ( (A>B) ? B : A)

int N, M;
int d[100000];
int c[400000];

int initTree(int left, int right, int node);
int queryTree(int nodeL, int nodeR, int node, int QuestionL, int QuestionR);

int main()
{
	freopen("Text.txt", "r", stdin);
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++)
		scanf("%d", &d[i]);

	initTree(0, N - 1, 1);

	for (int i = 0; i < M; i++)
	{
		int q1, q2;
		scanf("%d %d", &q1, &q2);
		printf("%d\n", queryTree(0, N - 1, 1, q1 - 1, q2 - 1));
	}

}

int initTree(int left, int right, int node)
{
	if (left == right)
		return c[node] = d[left];

	int leftMin = initTree(left, (left + right) / 2, node * 2);
	int rightMin = initTree((left + right) / 2 + 1, right, node * 2 + 1);

	return c[node] = MIN(leftMin, rightMin);
}

int queryTree(int nodeL, int nodeR, int node, int QuestionL, int QuestionR)
{
	if (QuestionR < nodeL || nodeR < QuestionL)
		return 1000000000;
	if (QuestionL <= nodeL && nodeR <= QuestionR)
		return c[node];

	int leftMin = queryTree(nodeL, (nodeL + nodeR) / 2, node * 2, QuestionL, QuestionR);
	int rightMin = queryTree((nodeL + nodeR) / 2 + 1, nodeR, node * 2 + 1, QuestionL, QuestionR);

	return MIN(leftMin, rightMin);
}
