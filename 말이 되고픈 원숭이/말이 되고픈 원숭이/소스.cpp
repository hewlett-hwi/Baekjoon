#include <iostream>
using namespace std;
#define MIN(a, b) ( (a > b) ? b : a)
#define MAX_N 10000
#define INF 987654321

struct Data {
	int y, x , k;
};

int K;
int X, Y;
int map[210][210];
int c[210][210][31]; // k별로 최소값

int front;
int rear;
Data queue[MAX_N];

void queueInit(void);
int queueIsEmpty(void);
int queueIsFull(void);
int queueIsFull(void);
int queueEnqueue(Data q);
int queueDequeue(Data *q);

void run(int y, int x, int k);


int dir[12][2] = {
	{ 0, -1 }, { -1, 0 }, { 0, 1 }, { 1, 0 },
	{ -2, -1 }, { -1, -2 }, { 1, -2 }, { 2, -1 },
	{ -2, 1 }, { -1, 2 }, { 1, 2 }, { 2, 1 }
};

void init() {
	for (int i = 0; i < 210; i++)
	for (int j = 0; j < 210; j++)
	for (int k = 0; k < 31; k++)
		c[i][j][k] = INF;

	queueInit();
}



int main()
{
	std::ios::sync_with_stdio(false);
	freopen("Text.txt", "r", stdin);

	cin >> K;
	cin >> X >> Y;

	for (int i = 1; i <= Y; i++) {
		for (int j = 1; j <= X; j++)
			cin >> map[i][j];
	}

	init();

	c[1][1][K] = 0;

	Data q = { 1, 1, K };
	queueEnqueue(q);

	while (!queueIsEmpty())
	{
		Data q;
		if (queueDequeue(&q) == 1)
		{
			//cout << q[0] << q[1] << q[2]  << " : " << c[q[0]][q[1]][q[2]] << endl;
			run(q.y, q.x, q.k);
		}
	}

	int ANSWER = INF;
	for (int i = 0; i < 31; i++) {
		//cout << i << " : "<< c[Y][X][i] << endl;
		ANSWER = MIN(ANSWER, c[Y][X][i]);
	}

	if (ANSWER == INF)
		ANSWER = -1;
	cout << ANSWER << endl;

	return 0;
}

void run(int y, int x, int k)
{
	int nextY, nextX;
	int count = c[y][x][k];

	for (int i = 0; i < 12; i++)
	{
		nextY = y + dir[i][0];
		nextX = x + dir[i][1];

		if (nextX <1 || nextY <1 || nextX > X || nextY > Y) // 밖으로 나가는것들
			continue;
		if (map[nextY][nextX] != 0) // 장애물
			continue;

		if (i < 4) // 일반 턴 
		{
			if (c[nextY][nextX][k] >= count + 1)
			{
				c[nextY][nextX][k] = count + 1;
				// 큐에 넣음
				Data q = { nextY, nextX, k };
				queueEnqueue(q);
			}
		}
		else // 말 턴
		{
			if (k > 0) {
				if (c[nextY][nextX][k - 1] >= count + 1)
				{
					c[nextY][nextX][k - 1] = count + 1;
					// 큐에 넣음
					Data q = { nextY, nextX, k - 1 };
					queueEnqueue(q);
				}
			}
		} // else end

	}
}

void queueInit(void)
{
	front = 0;
	rear = 0;
}

int queueIsEmpty(void)
{
	return (front == rear);
}

int queueIsFull(void)
{
	if ((front + 1) % MAX_N == rear)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int queueEnqueue(Data q)
{
	if (queueIsFull())
	{
		//printf("queue is full!");
		return 0;
	}
	queue[front].y = q.y;
	queue[front].x = q.x;
	queue[front].k = q.k;

	front++;
	if (front == MAX_N)
	{
		front = 0;
	}

	return 1;
}

int queueDequeue(Data *q)
{
	if (queueIsEmpty())
	{
		//printf("queue is empty!");
		return 0;
	}
	q->y = queue[rear].y;
	q->x = queue[rear].x;
	q->k = queue[rear].k;


	rear++;
	if (rear == MAX_N)
	{
		rear = 0;
	}
	return 1;
}