#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#define Max 233
using namespace std;
int fa[Max],n,vis[Max];
void init()
{
    for(int i=1;i<=100;i++) fa[i]=i;
    memset(vis,0,sizeof(vis));
}
int find(int a)
{
    if(a!=fa[a]) return fa[a]=find(fa[a]);
    else return a;
}
void Union(int a,int b)
{
    int f1=find(a);int f2=find(b);
    fa[f1]=f2;
}
int main()
{
    int a,b;
    int flag=0;
    int _case=0;
    while(cin>>a>>b)
    {
        flag=0;
        init();
        if(a==-1&&b==-1) break;if(a==0&&b==0){cout<<"Case "<<++_case<<" is a tree."<<endl;continue;}
        if(find(a)==find(b)) flag=1;
        Union(a,b);
        vis[a]=1;vis[b]=1;
        while(cin>>a>>b)
        {
            vis[a]=1;vis[b]=1;
            if(a==0&&b==0) break;
            if(find(a)==find(b)) flag=1;
            else Union(a,b);
        }
        int pos;
        for(int i=1;i<=100;i++)
        {
            if(vis[i]) {pos=i;break;}
        }
        for(int i=1;i<=100;i++)
        {
            if(vis[i])
            {
                if(find(pos)!=find(i))
                {
                    flag=1;
                    break;
                }
            }
        }
        if(!flag) cout<<"Case "<<++_case<<" is a tree."<<endl;
        else cout<<"Case "<<++_case<<" is not a tree."<<endl;
    }
    return 0;
}
