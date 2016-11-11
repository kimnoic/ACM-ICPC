#include <iostream>
#include <string.h>
using namespace std;

#define Max 100003

int father[Max],tree[Max];
int u[Max];
int sum=0;
void build (int a)
{
    for(int i=1;i<=a;i++)
    {
        father[i]=i;
        tree[i]=1;
    }
}

int path(int a)
{
    if(a!=father[a])
    {
        father[a]=path(father[a]);
    }
    return father[a];
}

int ans;

void together(int a,int b)
{
    if(u[a]!=1) {sum++;u[a]=1;}
    if(u[b]!=1) {sum++;u[b]=1;}
    a=path(a);b=path(b);
    if(a==b) {ans=1; return ;}
    else if(tree[a]>=tree[b])
    {
        father[b]=a;
        tree[a]+=tree[b];
    }
    else
    {
        father[a]=b;
        tree[b]+=tree[a];
    }
}
int main()
{
    int n,m;
    while (cin>>n>>m&&(n!=-1||m!=-1))
    {
        sum=0;
        memset(u,0,sizeof(u));
        if(n==0&&m==0) {cout<<"Yes"<<endl;}
        else {
        build(Max);
        int a,b;
        ans=0;
        together(n,m);
        while (cin>>a>>b&&(a!=0||b!=0))
        {
            if(father[a]==father[b]) ans=1;
            together(a,b);
        }
        if(sum!=tree[father[n]]) ans=1;
        if(ans==1) cout<<"No"<<endl;
        else cout<<"Yes"<<endl;}
    }
    return 0;
}
