#include<iostream>
#include <stdio.h>
using namespace std;


void merge(int array[], int temparray[], int left, int right, int middle) {
	//�鲢���̣��������ݴ�����ʱ����
	for (int i = left; i <= right; i++) { temparray[i] = array[i]; }
	//���ұ������е���ʼλ��
	int index1 = left; int index2 = middle + 1;
	int i = left; 	//����ʼ�鲢
	while (index1 <= middle && index2 <= right) {
		if (temparray[index1] <= temparray[index2]) {
			array[i++] = temparray[index1++];
		}
		else {
			array[i++] = temparray[index2++];
		}
	}
	//����ʣ���¼
	while (index1 <= middle) { array[i++] = temparray[index1++]; }
	while (index2 <= right) { array[i++] = temparray[index2++]; }
}



void mergeSort(int array[], int temparray[], int left, int right) {
	//���������ֻ��0��1����¼����������
	if (left < right) {
		//���м仮��Ϊ����������
		int middle = (left + right) / 2;
		//�����һ����еݹ�
		mergeSort(array, temparray, left, middle);
		//���ұ�һ����еݹ�
		mergeSort(array, temparray, middle + 1, right);
		// ���й鲢	
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
