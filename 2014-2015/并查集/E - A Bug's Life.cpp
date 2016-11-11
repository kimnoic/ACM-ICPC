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
    int k=0;
    int u=t;
    while (t--)
    {
        k++;
        int flag=0;
        scanf("%d%d",&n,&in);
        build(n);
        for(int i=1;i<=in;i++)
        {
            scanf("%d%d",&t1,&t2);
            if(flag) continue;
            if(path(t1)==path(t2)) flag=1;
            else
            {
                if(sex[t1]!=0)
                {
                    Union(sex[t1],t2);
                }
                else sex[t1]=t2;
                if(sex[t2]!=0)
                {
                    Union(sex[t2],t1);
                }
                else sex[t2]=t1;
            }
        }
        printf("Scenario #%d:\n",k);
        if(flag)
            printf("Suspicious bugs found!");
        else printf("No suspicious bugs found!");
        if(k!=t) printf("\n\n");
    }
    return 0;
}
