#include<iostream>

// 快排的思想一边递归 寻找第k大的数

using namespace std;

const int N= 100010;
int q[N];
int n,k; 

int quicksort(int q[],int l,int r,int k)
{
    if(l==r)return q[l];
    
    int i=l-1,j=r+1;
    int x=q[l];
    
    while(i<j){
        while(q[++i]<x);
        while(q[--j]>x);
        if(i<j){
            int temp=q[i];
            q[i]=q[j];
            q[j]=temp;
        }
    }
    int length=j-l+1;
    if(length>=k) return quicksort(q, l, j, k);
    else return quicksort(q, j+1, r, k-length);
    
    
}

int main()
{
    cin >> n >> k; 
    for (int i=0;i<n;i++){
        scanf("%d",&q[i]);
    }
    printf("%d",quicksort(q,0,n-1,k));
    return 0;
}