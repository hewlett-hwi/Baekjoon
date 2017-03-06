#include <iostream>
using namespace std;

#define MAX_M 500000

int M;    // # of element in array
int N;    // # of numbers to search
int arr[MAX_M];

void quickSort(int first, int last);
void binarySearch(int* arr, int low, int high, int target);



int main(void)
{
	std::ios::sync_with_stdio(false);
	//freopen("Text.txt", "r", stdin);
	int targetValue;

	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}

	quickSort(0, N - 1);

	scanf("%d", &M);

	for (int i = 0; i < M; i++)
	{
		scanf("%d", &targetValue);
		binarySearch(arr, 0, N- 1, targetValue);
	}
	printf("\n");

	return 0;
}

void binarySearch(int* arr, int low, int high, int target)
{
	int mid;
	if (low > high)
	{
		printf("0 ");
		return;
	}

	mid = (low + high) / 2;

	if (target < arr[mid])
	{
		binarySearch(arr, low, mid - 1, target);
	}
	else if (arr[mid] < target)
	{
		binarySearch(arr, mid + 1, high, target);
	}
	else
	{
		//printf("%d ", mid);
		printf("1 ");
		return;
	}
}

void quickSort(int first, int last)
{
	int pivot;
	int i;
	int j;
	int temp;

	if (first < last)
	{
		pivot = first;
		i = first;
		j = last;

		while (i < j)
		{
			while (arr[i] <= arr[pivot] && i < last)
			{
				i++;
			}
			while (arr[j] > arr[pivot])
			{
				j--;
			}
			if (i < j)
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}

		temp = arr[pivot];
		arr[pivot] = arr[j];
		arr[j] = temp;

		quickSort(first, j - 1);
		quickSort(j + 1, last);
	}
}