#include<bits/stdc++.h>
using namespace std;
struct self
{
    double x,y;
    int bh;
}s[5];
int m;
double x,y;

const double eps = 1e-6;

double sqr(double i)
{
    return i*i;
}

double f(int a,int b,int c)
{
    double d1,d2,d3;
    d1=sqrt(sqr(s[a].x-s[b].x)+sqr(s[a].y-s[b].y));
    d2=sqrt(sqr(s[a].x-s[c].x)+sqr(s[a].y-s[c].y));
    d3=sqrt(sqr(s[b].x-s[c].x)+sqr(s[b].y-s[c].y));
    double p=(d1+d2+d3)/2;
    return sqrt(p*(p-d1)*(p-d2)*(p-d3));
}

int init()
{
    if(fabs(f(1,2,3)-f(1,2,4)-f(1,3,4)-f(2,3,4))<=eps)
        return 1;
    return 0;
}

int bs(int a,int b)
{
    if(fabs(f(a,b,4))<eps)
        return 1;
    return 0;
}

int main()
{
    scanf("%d",&m);
    for(int i=1;i<=3;i++)
    {
        scanf("%lf%lf",&s[i].x,&s[i].y);
        s[i].bh=i;
    }
    for(int i=4;i<=m;i++)
    {
        scanf("%lf%lf",&x,&y);
        s[4].x=x;
        s[4].y=y;
        if(init())
        {
            if(bs(1,2))
            {
                s[1].x=x;
                s[1].y=y;
                s[1].bh=i;
            }
            else
                if(bs(2,3))
                {
                    s[2].x=x;
                    s[2].y=y;
                    s[2].bh=i;
                }
                else
                {
                    s[3].x=x;
                    s[3].y=y;
                    s[3].bh=i;
                }
        }
    }
    cout<<s[1].bh<<" "<<s[2].bh<<" "<<s[3].bh<<endl;
    return 0;
}
