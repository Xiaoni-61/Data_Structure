#include<iostream>
#include <stdio.h>
using namespace std;


void merge(int array[], int temparray[], int left, int right, int middle) {
	//归并过程，将数组暂存入临时数组
	for (int i = left; i <= right; i++) { temparray[i] = array[i]; }
	//左右边子序列的起始位置
	int index1 = left; int index2 = middle + 1;
	int i = left; 	//从左开始归并
	while (index1 <= middle && index2 <= right) {
		if (temparray[index1] <= temparray[index2]) {
			array[i++] = temparray[index1++];
		}
		else {
			array[i++] = temparray[index2++];
		}
	}
	//处理剩余记录
	while (index1 <= middle) { array[i++] = temparray[index1++]; }
	while (index2 <= right) { array[i++] = temparray[index2++]; }
}



void mergeSort(int array[], int temparray[], int left, int right) {
	//如果序列中只有0或1个记录，不必排序
	if (left < right) {
		//从中间划分为两个子序列
		int middle = (left + right) / 2;
		//对左边一半进行递归
		mergeSort(array, temparray, left, middle);
		//对右边一半进行递归
		mergeSort(array, temparray, middle + 1, right);
		// 进行归并	
		merge(array, temparray, left, right, middle);
	}
}


int main()
{
	int n;
	cin >> n;
	int *a = new int[n];
	int *b = new int[n];
	int i;
	for (i = 0; i < n; i++) {
		cin >> a[i];
	}
	mergeSort(a,b,0, n-1);

	for (i = 0; i < (n - 1); i++)
	{
		cout << a[i] << " ";
	}

	cout << a[n - 1];

	//system("pause");
	return 0;
}
