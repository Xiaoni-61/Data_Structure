#include <iostream>
#include <stdio.h>

using namespace std;
const int N = 1000010;

int n;
int q[N], temp[N];

void merge_sort(int q[], int low, int high)
{
    if (low >= high)
        return;
    int mid = (low + high) >> 1;
    merge_sort(q, low, mid);
    merge_sort(q, mid + 1, high);
    int k = 0, i = low, j = mid + 1;
    while (i <= mid && j <= high)
    {
        if (q[i] <= q[j])
            temp[k++] = q[i++];
        else
            temp[k++] = q[j++];
    }
    while (i <= mid)
        temp[k++] = q[i++];
    while (j <= high)
        temp[k++] = q[j++];
    for (i = low, j = 0; i <= high; i++, j++)
        q[i] = temp[j];
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &q[i]);
    }
    merge_sort(q, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", q[i]);
    }
}