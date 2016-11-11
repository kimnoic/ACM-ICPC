#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
int l[50005],r[50005],s[50005],w[50005];
long long c[50005][4]={0};
int main(int argc, const char * argv[])
{

    int i,j,m,n,k,T,a,b;
    long long ans=0;
    cin >>T;
    c[0][0]=1;
    c[1][0]=1;
    c[1][1]=1;
    for (i=2;i<=50000;i++)
    {
        c[i][0]=1;
        for (j=1;j<=3&&j<=i;j++)
            c[i][j]=c[i-1][j]+c[i-1][j-1];
    }
    while (T--)
    {
        cin>>n>>m;
        memset(l,0,sizeof(l));
        memset(r,0,sizeof(r));

        for (i=1;i<=n;i++) scanf("%d",&w[i]);
        for (i=1;i<=m;i++)
        {
            scanf("%d%d",&a,&b);
            l[a]++;
            r[b]++;
        }
        int cnt=0;
        for (i=1;i<=n;i++)
        {
            cnt+=l[i];
            cnt-=r[i-1];
            ans+=c[cnt][3]*w[i];
        }
        long long p=c[m][3];
        if (p>=3)
        {
            ans/=__gcd(ans,p);
            p/=__gcd(ans,p);
        }
        if (p==1) cout<<ans<<endl;else
            if (p==0) cout<<0<<endl;else
        cout<<ans<<"/"<<p<<endl;
    }
    return 0;
}
