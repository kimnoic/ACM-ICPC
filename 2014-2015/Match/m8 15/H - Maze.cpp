#include <iostream>
using namespace std;
char table[501][501];
int x[250001];
int y[250001];
int n,m,k;
int aa,bb;
int sum;
int table2[501][501]={};
int ii=1;
int jj=1;
void dfs(int a,int b)
{
    cout<<a<<"   "<<b<<endl;
    if(a>=1&&a<=n&&b>=1&&b<=m&&table[a][b]=='.'&&table2[a][b]==0)
        {
            cout<<a<<" "<<b<<endl;
            x[ii]=a;
            x[jj]=b;
            ii++;jj++;
            sum--;
            table2[a][b]=1;
            if(sum!=0) dfs(a-1,b);
            if(sum!=0) dfs(a,b-1);
            if(sum!=0) dfs(a+1,b);
            if(sum!=0) dfs(a,b+1);
        }
}
int main()
{
    cin>>n>>m>>k;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>table[i][j];
            if(table[i][j]=='.') {ans++;aa=i;bb=j;}
        }
    }
    sum=ans-k;
    int s=sum;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(table[i][j]=='.') table[i][j]='X';
        }
    }
    dfs(aa,bb);
    cout<<s;
    for(int i=1;i<=s;i++) cout<<x[i]<<" "<<y[i]<<endl;
    for(int i=1;i<=s;i++)
    {
        table[x[i]][y[i]]='.';
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cout<<table[i][j];
        }
        cout<<endl;
    }
    return 0;
}
