#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
long long a[1001];
int main()
{
    int t;
    cin>>t;
    char k;
    a[0]=-1;
    for(int i=1;i<=t;i++)
    {
        int j=1;
        while(cin>>a[j]>>k&&k!='\n') j++;
        for(int k=1;k<=j+1;k++)
        {
            for(int u=k;u<=j+1;u++)
            {
                if(a[u]<a[k])
                {
                    int t=a[u];
                    a[u]=a[k];
                    a[k]=t;
                }
            }
        }
        for(int i=k;k<=j+1;k++)
        {
            if(a[k]!=a[k-1]) cout<<a[k]<<" ";
        }
        cout<<endl;
    }
    return 0;
}




                if(i==a&&j==b&&abs(1-table[i][j][0])<1e-7)
                    continue;
