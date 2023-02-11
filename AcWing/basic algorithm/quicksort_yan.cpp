#include <iostream>

using namespace std;

const int N = 100010;

int q[N];


void quicksort(int q[], int low, int high)
{
    if (low>=high)return;
    int i=low-1;
    int j=high+1;
    int x=q[low+high>>1];
    while(i<j ){
        do i++ ; while (q[i]<x);
        do j-- ; while (q[j]>x);
        if(i<j) swap(q[i],q[j]);
    }
    quicksort(q,low,j);
    quicksort(q,j+1,high);
}



int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &q[i]);
    }
    quicksort(q, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", q[i]);
    }

}
