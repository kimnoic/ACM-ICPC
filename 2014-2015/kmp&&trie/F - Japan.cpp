#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string.h>
#define Max 1000001
#define MAX 1001
using namespace std;
long long  c[MAX],sum;
int W,E,k,t,number;

int lowbit(int a)
{
    return a&-a;
}

struct node
{
    int e,w;
} spa[Max];

bool cmp(node a, node b)
{
    if(a.e == b.e) return a.w < b.w;
    else return a.e <b.e;
}

int query(int a)
{
    int number=0;
    while(a <= 1001)
    {
        number+=c[a];
        a+=lowbit(a);
    }
    return number;
}
void add(int a)
{
    while(a>0)
    {
        c[a]++;a-=lowbit(a);
    }
}

int main()
{
    scanf("%d",&t);
    int ans=1;
    while(t--)
    {
        scanf("%d%d%d",&W,&E,&k);
        memset(c,0,sizeof(c));
        for(int i=0; i<k; i++)
        {
            scanf("%d%d",&spa[i].e,&spa[i].w);
        }
        sort(spa,spa+k,cmp);
        sum=0;
        for(int i=0; i<k; i++)
        {
            sum=sum+query(spa[i].w+1);
            add(spa[i].w);
        }
        printf("Test case %d: %lld",ans,sum);
        cout<<endl;
        ans++;
    }
    return 0;
}
