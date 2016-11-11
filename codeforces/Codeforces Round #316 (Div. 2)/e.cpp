#include <bits/stdc++.h>

using namespace std;
const int MAX=505;
const int MOD=1e9+7;
char s[MAX][MAX];
int f[MAX][MAX]={0};
int f_[MAX][MAX];
int i,j,m,n,k,dis;
struct point{
    int x,y;
};
point next_1(point a)
{
    if (a.y==1&&a.x<n)
        a.x++;
    else
        a.y++;
    return a;
}
point next_2(point a)
{
    if (a.x==n&&a.y>1)
        a.y--;
    else
        a.x--;
    return a;
}
point nex(point a)
{
    a.x--;
    a.y++;
    return a;
}
int main()
{
    cin>>n>>m;
    int ans=0;
    getchar();
    for (i=1;i<=n;i++)
    {
        for (j=1;j<=m;j++)
            scanf("%c",&s[i][j]);
        getchar();
    }
    point a,b,p1,p2;
    a.x=a.y=1;
    b.x=n;b.y=m;
    int max_=(m+n)/2;
    if (s[1][1]==s[n][m])
        f[1][n]=1;
    else
        f[1][n]=0;
    if (m+n<=3)
    {
        cout<<f[1][n]<<endl;
        return 0;
    }
    for (dis=2;dis<=max_;dis++)
    {
        a=next_1(a);
        b=next_2(b);
        for (i=1;i<=500;i++)
            for (j=1;j<=500;j++)
            {
                f_[i][j]=f[i][j];
                f[i][j]=0;
            }
        for (p1=a;p1.y<=m&&p1.x>=1;p1=nex(p1))
        {
            for (p2=b;p2.y<=m&&p2.x>=1;p2=nex(p2))
                if (s[p1.x][p1.y]==s[p2.x][p2.y])
                {
                    f[p1.x][p2.x]=((f_[p1.x-1][p2.x]+f_[p1.x-1][p2.x+1])%MOD+(f_[p1.x][p2.x]+f_[p1.x][p2.x+1])%MOD)%MOD;
                    if (((p1.x==p2.x)&&(abs(p1.y-p2.y)<=1))||((p1.y==p2.y)&&(abs(p1.x-p2.x)<=1)))
                        ans=(ans+f[p1.x][p2.x])%MOD;
                }
        }
    }
    cout<<ans<<endl;
    return 0;
}
