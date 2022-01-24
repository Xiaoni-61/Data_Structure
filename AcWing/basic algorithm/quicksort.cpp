
#include <iostream>

const int N = 1e6 + 10;
int n;
int q[N];
void quicksort(int q[], int low, int high)
{
    if (low >= high)
        return;

    int temp = q[low];
    int i = low;
    int j = high;
    while (i < j)
    {
        while (i < j && q[j] >= temp)
            j--;
        q[i] = q[j];
        while (i < j && q[i] <= temp)
            i++;
        q[j] = q[i];
    }
    q[i] = temp;
    quicksort(q, low, i - 1);
    quicksort(q, i + 1, high);
}
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &q[i]);
    }
    quicksort(q, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        printf("%d", q[i]);
    }
}
