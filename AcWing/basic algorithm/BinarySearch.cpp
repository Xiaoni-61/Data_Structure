/*AcWing 789题
若开始时使l=mid 则在之前求mid时需要mid=r+l+1>>1
若开始时使r=mid 则在之前求mid时需要mid=r+l>>1*/

#include <iostream>

using namespace std;

int n;
const int N = 100000;
int q[N];

int main()
{
    int p, num;
    scanf("%d%d", &n, &num);
    for (int i = 0; i < n; i++)
        scanf("%d", &q[i]);
    while (num--)
    {
        scanf("%d", &p);
        int l = 0, r = n - 1;
        while (l < r)
        {
            int mid = r + l >> 1;
            if (q[mid] >= p)
                r = mid;
            else
                l = mid + 1;
        }
        if (q[r] != p)
            cout << "-1 -1" << endl;
        else
        {
            cout << l << " ";
            int l = 0, r = n - 1;
            while (l < r)
            {
                int mid = r + l + 1 >> 1;
                if (q[mid] <= p)
                    l = mid;
                else
                    r = mid - 1;
            }
            cout << l << endl;
        }
    }

    return 0;
}


