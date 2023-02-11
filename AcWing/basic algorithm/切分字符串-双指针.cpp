#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    char str[1010];

    gets(str);
//    cin.getline[str,1010]

    int n=strlen(str);

    int i,j;

    for(i=0; i<n; i++){
        j=i;

        while(j < n&&str[j] != ' ')j++;

        for(int k=i;k<j;k++)cout<<str[k];
        cout<<endl;

        i=j;

    }
    return 0;
}