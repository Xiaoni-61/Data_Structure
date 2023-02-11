#include<iostream>

typedef long long LL;

using namespace std;

const int N = 100010;
int q[N],temp[N];

LL mergesort(int l,int r)
{
    if(l>=r) return 0;
    int mid = l+r>>1;
    
    LL res = mergesort(l,mid)+mergesort(mid+1,r);
    
    int i,j;
    int k=0;
    for(i=l,j=mid+1;i<=mid&&j<=r;){
        if(q[i]<=q[j]) temp[k++]=q[i++];
        else{
            temp[k++]=q[j++];
            res+=mid-i+1;
        }
    }
    while(i<=mid)temp[k++]=q[i++];
    while(j<=r)temp[k++]=q[j++];
    
    for(i=l,j=0;i<=r;i++,j++)
        q[i]=temp[j];
        
    return res;
}

int main()
{
    int n;
    scanf("%d",&n);
    
    for(int i=0;i<n;i++){
        scanf("%d",&q[i]);
    }
    cout<<mergesort(0,n-1)<<endl;
    return 0;
}