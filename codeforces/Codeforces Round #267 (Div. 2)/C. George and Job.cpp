#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
long long f[5010][5010],s[5010],a[5010];
int main()
{
    int k,m,n;
    cin>>n>>m>>k;
    memset(s,0,sizeof(s));
    memset(f,0,sizeof(f));
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        s[i]=s[i-1]+a[i];
    }
    for (int i=1;i<=n;i++)
     for (int j=1;j<=k;j++)
    {
       if (i-m>=0)
       f[i][j]=max(f[i-m][j-1]+s[i]-s[i-m],f[i-1][j]);
    }
    cout << f[n][k]<<endl;
    return 0;
}
