#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <queue>
#include <stack>
#include <vector>
#include <set>
#include <map>

using namespace std;
const int inf = 0x3f3f3f3f;

int t;
int f[1<<17][17];
int g[17][17];
int m,n,x,y,w;

void pe(int i)
{
    int g[111];
    int num=0;
    while(i)
    {
        num++;
        g[num]=i%2;
        i/=2;
    }
    for(int i=1;i<=num;i++)cout<<g[i];
}

int work(int zt,int lastp)
{
    if(f[zt][lastp]!=-1)
        return f[zt][lastp];
    //cout<<"work[";pe(zt);cout<<"]["<<lastp<<"]"<<endl;
    f[zt][lastp]=inf;
    for(int i=0;i<m;i++)
    {
        int pos=m-i;        //city number
        //cout<<"  i="<<i<<" pos="<<pos<<endl;
        if((zt & (1<<i))&&pos!=lastp)
        {
            //cout<<" update"<<endl;
            f[zt][lastp]=min(f[zt][lastp],work(zt-(1<<i),pos)+g[pos][lastp]);
            f[zt][lastp]=min(f[zt][lastp],work(zt,pos)+g[pos][lastp]);
        }
    }
   // cout<<"work[";pe(zt);cout<<"]["<<lastp<<"]="<<f[zt][lastp]<<endl;
    return f[zt][lastp];
}

int main()
{
    scanf("%d",&t);
    while(t--)
    {
        cin>>m>>n;
        //scanf("%d%d",&m,&n);
        memset(g,0x3f,sizeof(g));
        for(int i=1;i<=m;i++)
            g[i][i]=0;
        memset(f,-1,sizeof(f));
        f[1<<(m-1)][1]=0;

        for(int i=1;i<=n;i++)
        {
            scanf("%d%d%d",&x,&y,&w);
            g[x][y]=min(w,g[x][y]);
            g[y][x]=g[x][y];
        }
        int ans=inf;
        for(int i=1;i<=m;i++)
            ans=min(ans,work((1<<m)-1,i)+g[i][1]);
        cout<<ans<<endl;
        //printf("%d\n",ans);
    }
    return 0;
}
/*
1
9
10
1 2 1
2 3 2
3 4 3
4 5 4
5 6 5
6 7 6
7 1 7
1 9 9
9 8 8
2 8 1

*/
