#include <iostream>
#define  N 1001
typedef long long LL;
const LL inf=100000000000000LL;
using namespace std;
int n,m;
long long  table[N][N];
long long dire[N][N][4];


long long max(long long a,long long b)
{
    if(a>b) return a;
    else return b;
}
int main()
{
    cin>>n>>m;
	for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++) cin>>table[i][j];
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
            dire[i][j][0]=table[i][j]+max(dire[i-1][j][0],dire[i][j-1][0]);
    for(int i=n;i>=1;i--)
    for(int j=m;j>=1;j--)
			dire[i][j][1]=table[i][j]+max(dire[i+1][j][1],dire[i][j+1][1]);
    for(int i=n;i>=1;i--)
    for(int j=1;j<=m;j++)
			dire[i][j][2]=table[i][j]+max(dire[i+1][j][2],dire[i][j-1][2]);
    for(int i=1;i<=n;i++)
    for(int j=m;j>=1;j--)
			dire[i][j][3]=table[i][j]+max(dire[i-1][j][3],dire[i][j+1][3]);
    for(int k=0;k<4;k++)
	{
    for(int i=0;i<=n+1;i++)
			dire[i][0][k]=dire[i][m+1][k]=-inf;
    for(int j=0;j<=m+1;j++)
			dire[0][j][k]=dire[n+1][j][k]=-inf;
	}

long long ans=0,t;
for(int i=1;i<=n;i++)
for(int j=1;j<=m;j++)
    {
        t=dire[i-1][j][0]+dire[i+1][j][1]+dire[i][j-1][2]+dire[i][j+1][3];
        ans=max(ans,t);
        t=dire[i][j-1][0]+dire[i][j+1][1]+dire[i+1][j][2]+dire[i-1][j][3];
        ans=max(ans,t);
    }
	cout<<ans<<endl;
    return 0;
}

