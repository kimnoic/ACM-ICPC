#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
#include <cmath>
#include <vector>
#include <map>
#include <cmath>
#include <queue>
#include <set>
#include <time.h>
#include <algorithm>
using namespace std;
int pp[1001];
int ppt[1001];
int gcd(int x,int y)
{
    return !y?x:gcd(y,x%y);
}

int main()
{
    int N,M,Y;
    int i,j;
    int dd,tt;
    while(scanf("%d %d %d",&N,&M,&Y)==3)
    {
        for(i=0;i<N;i++)
        {
            scanf("%d",&pp[i]);
        }
        dd = gcd(M,Y);
        tt = Y / dd;
        for(i=0;i<N;i++)
        {
            pp[i] *= (M/dd);
        }
        int s;
        int sum=0;

        for(i=0;i<N;i++)
        {
            s = pp[i]%tt;
            if(s<=(tt/2))
            {
                ppt[i] = pp[i] - s;
                sum -= s;
            }
            else
            {
                ppt[i] = pp[i] + (tt - s);
                sum += (tt-s);
            }
        }
        sum = sum / tt;
        bool flag = 1;
        int st = tt/2+1;
        while(sum>0 && flag)
        {
            for(i=0;i<N;i++)
            {
                if(pp[i]%tt==st)
                {
                    ppt[i] -= tt;
                    sum -= 1;
                    if(!sum)
                    {
                        flag = 0;
                        break;
                    }
                }
            }
            st += 1;
        }
        st = tt/2;
        flag = 1;
        while(sum<0 && flag)
        {
            for(i=0;i<N;i++)
            {
                if(pp[i]%tt==st)
                {
                    ppt[i] += tt;
                    sum += 1;
                    if(!sum)
                    {
                        flag = 0;
                        break;
                    }
                }
            }
            st -= 1;
        }
        for(i=0;i<N;i++)
        {
            printf("%d%c",ppt[i]/tt,i==(N-1)?'\n':' ');
        }
    }
    return 0;
}
