#include<iostream>

using namespace std;
	
void swap(int arr[], int a, int b);
void sort(int array[], int n);
void adjustHeap(int array[], int i, int length);

void sort(int array[],int n) {
		
	for (int i = n / 2 - 1; i >= 0; i--) {
		adjustHeap(array, i, n);			//建堆
	}

	
	// 开始排序逻辑
	for (int j = n - 1; j > 0; j--) {
		
		swap(array, 0, j);
		
		adjustHeap(array, 0, j);
	}
}

	
void adjustHeap(int array[], int i, int length) {
		
	int temp = array[i];
		
	for (int k = 2 * i + 1; k < length; k = 2 * k + 1) {
		
		if (k + 1 < length && array[k] < array[k + 1]) {
			k++;
		}

		if (array[k] > temp) {
			swap(array, i, k);
			
			i = k;
			
		}
		else {
			break;
		}
	}
}

	
void swap(int arr[], int a, int b) {
	int temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}


int main() {
	int n;
	cin >> n;
	int* array = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> array[i];
	}
		// 接下来就是排序的主体逻辑
	sort(array,n);
	for (int i = n-1; i > 0; i--) {
		cout << array[i] << " ";
	}
	cout << array[0];
	cout << endl;
	//system("pause");
}
