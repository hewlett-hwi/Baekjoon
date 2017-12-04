#include <iostream>
using namespace std;

int dir[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} };

#define MAX 25
char map[MAX][MAX];
char visited[MAX][MAX] = {'0', };
int N;

int answer = 1;
int answerArray[1000] = {0, };

void showMap();
void quickSort(int first, int last);

int dfs(int y, int x, int type) {
	int ret = 1;

	if (y >= N || x >= N || y < 0 || x < 0)
		return 0;
	if (map[y][x] != '1' || visited[y][x]=='1')
		return 0;

	visited[y][x] = '1';

	for (int i = 0; i < 4; i++) {
		int ny = y + dir[i][0];
		int nx = x + dir[i][1];

		ret = ret + dfs(ny, nx, type);
	}

	map[y][x] = type + '0';

	return ret;
}

int main()
{
	freopen("Text.txt", "r", stdin);

	cin >> N;

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			char data;	cin >> data;	map[y][x] = data;
		}
	}


	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			if (map[y][x] == '1') {
				answer++;
				answerArray[answer-2] = dfs(y, x, answer);
			}
		}
	}
	
	//showMap();
	quickSort(0, answer - 2);

	cout << answer - 1 << endl;
	for (int i = 0; i < answer - 1; i++)
		cout << answerArray[i] << endl;

	return 0;
}

void showMap() {
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cout << map[y][x];
		}
		cout << endl;
	}

}

void quickSort(int first, int last){	int pivot;	int i;	int j;	int temp;	if (first < last)	{		pivot = first;		i = first;		j = last;
		while (i < j)		{			while (answerArray[i] <= answerArray[pivot] && i < last)			{				i++;			}			while (answerArray[j] > answerArray[pivot])			{				j--;			}			if (i < j)			{				temp = answerArray[i];				answerArray[i] = answerArray[j];				answerArray[j] = temp;			}		}
		temp = answerArray[pivot];		answerArray[pivot] = answerArray[j];		answerArray[j] = temp;
		quickSort(first, j - 1);		quickSort(j + 1, last);	}}
