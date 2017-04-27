#include <stdio.h>
using namespace std;
#define MAX 400001

int rmq_min[MAX];
int rmq_max[MAX];
int d[100001];
int N, M;

inline int min(int a, int b)
{
	return (a > b) ? b : a;
}

inline int max(int a, int b)
{
	return (a > b) ? a : b;
}

// node가 담당하는 범위가 left ~ right
// node: 세그먼트 트리 노드 번호 
int init_rmq_min(int left, int right, int node) 

{
	if (left == right)
		return rmq_min[node] = d[left];
	int mid = (left + right) / 2;
	int leftMin = init_rmq_min(left, mid, node * 2);
	int rightMin = init_rmq_min(mid + 1, right, node * 2 + 1);

	return rmq_min[node] = min(leftMin, rightMin);
}

int init_rmq_max(int left, int right, int node)

{
	if (left == right)
		return rmq_max[node] = d[left];
	int mid = (left + right) / 2;
	int leftMax = init_rmq_max(left, mid, node * 2);
	int rightMax = init_rmq_max(mid + 1, right, node * 2 + 1);

	return rmq_max[node] = max(leftMax, rightMax);
}

int query_rmq_min(int left, int right, int node_left, int node_right, int node)
{
	if (left > node_right || right < node_left)
		return 1000000009;
	
	if (left <= node_left && node_right <= right)
		return rmq_min[node];

	int mid = (node_left + node_right) / 2;
	int leftMin = query_rmq_min(left, right, node_left, mid, node * 2);
	int rightMin = query_rmq_min(left, right, mid + 1, node_right, node * 2 + 1);

	return min(leftMin, rightMin);
}

int query_rmq_max(int left, int right, int node_left, int node_right, int node)
{
	if (left > node_right || right < node_left)
		return -1000000009;

	if (left <= node_left && node_right <= right)
		return rmq_max[node];

	int mid = (node_left + node_right) / 2;
	int leftMax = query_rmq_max(left, right, node_left, mid, node * 2);
	int rightMax = query_rmq_max(left, right, mid + 1, node_right, node * 2 + 1);

	return max(leftMax, rightMax);
}

int main(int argc, char** argv)
{
	freopen("Text.txt", "r", stdin);

	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++)
		scanf("%d", &d[i]);
		

	init_rmq_min(0, N - 1, 1);
	init_rmq_max(0, N - 1, 1);

	for (int i = 0; i < M; i++)
	{
		int queryLeft, queryRight;
		scanf("%d %d", &queryLeft, &queryRight);
		queryLeft--; queryRight--;

		//cout << query_rmq_min(queryLeft, queryRight, 0, N - 1, 1) << " " << query_rmq_max(queryLeft, queryRight, 0, N - 1, 1) << endl;
		
		printf("%d ", query_rmq_min(queryLeft, queryRight, 0, N - 1, 1));
		printf("%d\n", query_rmq_max(queryLeft, queryRight, 0, N - 1, 1));
	}


	return 0; // 정상종료시 반드시 0을 리턴해야 합니다.
}