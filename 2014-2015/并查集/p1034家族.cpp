#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

#define Max 2001
int n,in,t1,t2;
int bug[Max];
int father[Max];
int sex[Max];

void build(int a)
{
    for(int i=1;i<=a;i++)
    {
        father[i]=i;
        sex[i]=0;
        bug[i]=0;
    }
}

int path(int a)
{
    if(a!=father[a])
        father[a]=path(father[a]);
    return father[a];
}

void Union(int a,int b)
{
    a=path(a);b=path(b);
    if(a==b) return ;
    if(bug[a]>bug[b])
        father[b]=a;
    else
    {
        if(bug[a]==bug[b]) bug[b]++;
        father[a]=b;
    }
}

int main()
{
    int t;
    cin>>t;
    int n,m;
    cin>>n>>m;
    build(t);
    for(int i=1;i<=n;i++)
    {
        cin>>t1>>t2;
        Union(bug[t1],bug[t2]);
    }
    for(int i=1;i<=m;i++)
    {
        cin>>t1>>t2;
        if(father[t1]==father[t2]) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}
