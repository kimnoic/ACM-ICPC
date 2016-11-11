#include <bits/stdc++.h>
using namespace std;
int n,m;
long long mp[2333][2333];
long long re[2333];
int main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
            cin>>mp[i][j];
    }
    int p;
    for(int i=0;i<m;i++)
    {
        long long max=0;p=0;
        for(int j=1;j<=n;j++)
        {
            if(mp[i][j]>max)
            {
                max=mp[i][j];
                p=j;
            }
        }
        re[p]++;
    }
    long long  max=0;
    for(int i=0;i<m;i++)
    {
        if(re[i]>max)
        {
            max=re[i];
            p=i;
        }
    }
    cout<<p+1;
    return 0;
}
