#include <bits/stdc++.h>
using namespace std;
#define maxx 100

void heapify(int *arr, int i, int n)
{
	int smallest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < n && arr[left] < arr[smallest])
		smallest = left;

	if (right < n && arr[right] < arr[smallest])
		smallest = right;

	if (smallest != i)
	{
		swap(arr[i], arr[smallest]);
		heapify(arr, smallest, n);
	}
}

void insert(int *arr, int &n, int key)
{
	n = n + 1;
	arr[n - 1] = key;
	int i = n - 1;
	while (i != 0 && arr[(i - 1) / 2] > arr[i])
	{
		swap(arr[i], arr[(i - 1) / 2]);
		i = (i - 1) / 2;
	}
}

void printHeap(int *arr, int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}

int main()
{
	int arr[maxx] = {10, 5, 3, 2, 4};
	int n = 5;

	int key = 1;
	insert(arr, n, key);

	printHeap(arr, n);

	return 0;
}
