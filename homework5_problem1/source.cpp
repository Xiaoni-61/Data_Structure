#include<iostream>
#include <stdio.h>
using namespace std;

void swap(int *k, int low, int high)
{
	int temp;
	temp = k[low];
	k[low] = k[high];
	k[high] = temp;
}
int Partition(int *k, int low, int high)
{
	int point;
	point = k[low];
	while (low < high)
	{
		while (low < high &&k[high] >= point)
		{
			high--;
		}
		swap(k, low, high);
		while (low < high &&k[low] <= point)
		{
			low++;
		}
		swap(k, low, high);
	}
	return low;
}
void Qsort(int *k, int low, int high)
{
	int point;
	if (low < high)
	{
		point = Partition(k, low, high);
		Qsort(k, low, point - 1);
		Qsort(k, point + 1, high);
	}
}
void QuickSort(int *k, int n)
{
	Qsort(k, 0, n - 1);
}
int main()
{
	int n;
	cin >> n;
	int *a = new int[n];
	int i;
	for (i = 0; i < n; i++) {
		cin >> a[i];
	}
	QuickSort(a, n);

	for (i = 0; i < (n-1); i++)
	{
		cout << a[i] << " ";
	}

	cout << a[n-1];
	
	//system("pause");
	return 0;
}
