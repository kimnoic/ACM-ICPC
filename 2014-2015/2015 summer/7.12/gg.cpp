#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
using namespace std;

struct node
{
    int h,m,s,no,flag;
} a[20005];

int abs(int a)
{
    if(a<0)
        return -a;
    return a;
}

int cmp(node a,node b)
{
    if(a.h!=b.h)
        return a.h<b.h;
    if(a.m!=b.m)
        return a.m<b.m;
    return a.s<b.s;
}

int work(int i,int j)
{
    int t1 = a[i].h*3600+a[i].m*60+a[i].s;
    int t2 = a[j].h*3600+a[j].m*60+a[j].s;
    return t1-t2;
}

int cmp2(node a,node b)
{
    return a.no<b.no;
}

int main()
{
    int t,n,k,tem;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++)
        {
            scanf("%d:%d:%d",&a[i].h,&a[i].m,&a[i].s);
            a[i].no = i;
            a[i].flag = 0;
        }
        sort(a+1,a+1+n,cmp);
        a[1].flag = 1;
        tem = 1;
        int cnt = 1;
        for(int i = 2; i<=n; i++)
        {
            if(abs(work(i,tem))>=k)
            {
                a[i].flag = 1;
                tem = i;
                cnt++;
            }
        }
        sort(a+1,a+1+n,cmp2);
        int ff = 0;
        printf("%d\n",cnt);
        for(int i = 1; i<=n; i++)
        {
            if(a[i].flag)
            {
                if(ff)
                    printf(" %d",i);
                else
                    printf("%d",i);
                ff = 1;
            }
        }
        cout<<endl;
    }

    return 0;
}
