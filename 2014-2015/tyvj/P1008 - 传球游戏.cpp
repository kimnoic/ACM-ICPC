#include<iostream>
#include<memory.h>
using namespace std;
int find(int n,int note)
{
    if(note==-1)
    return (n-1);
    else if(note==n)
    return 0;
    else
    return note;
}
int main()
{
    int dt[31][30],m,n;
    cin>>n>>m;
    memset(dt,0,sizeof(dt));
    dt[0][0]=1;
    for(int i=1;i<=m;i++)
    for(int j=0;j<n;j++)
    dt[i][j]=dt[i-1][find(n,j-1)]+dt[i-1][find(n,j+1)];
    cout<<dt[m][0]<<endl;
    return 0;
}
