#include <iostream>

using namespace std;

int a[501][501]={};
int table[501][501]={};
int n,m,k;
int ans;
int nx[]={0,-1,1,0,0};
int ny[]={0,0,0,1,-1};
char c[1000];

void d(int x,int y)
{
    if(ans==0)return;    ans--;
    table[y][x]=2;
    for(int i=1;i<=4;i++)
       {
        if(table[y+ny[i]][x+nx[i]]==1)
            {
                d(x+nx[i],y+ny[i]);
        }
       }
}

int main()
{
    int x,y;
    cin>>n>>m>>k;
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        cin>>c;
        for(int j=0;j<m;j++)
            if(c[j]=='.')
            {
                table[i][j+1]=1;
                x=j+1;
                y=i;
                a[i][j+1]=1;
                sum++;
            }
    };
    ans=sum-k;
    d(x,y);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
            {
                if(table[i][j]==1)cout<<"X";
                if(table[i][j]==2)cout<<".";
                if(table[i][j]==0)cout<<"#";}
        cout<<endl;
    }
    return 0;
}
