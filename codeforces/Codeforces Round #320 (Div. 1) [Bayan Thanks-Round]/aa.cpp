#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
using namespace std;
int yy=0;
int main()
{
    double x1,x2;
    int k1,k2,a,b;
    cin>>a>>b;
    double l=a-b;
    double r=a+b;
    if(l>=0){
        x1=b;
        yy++;
        k1=floor((double)l/2/b);
        if(k1==0 && l!=0)
            x1=-1;
        if(k1!=0)
            x1=(double)l/2/k1;
    }
    else
    {
        x1=-1;
    }
    if(r<0||a<b)
        x2=-1;
    else
    {
        x2=b;
        yy++;
        k2=floor((double)r/2/b)-1;
        if(k2<0)
            x2=-1;
        else
            x2=(double)r/2/(k2+1);
    }
    if(x1<=0)
    {
        if(x2>0)
            printf("%.11lf\n",x2);
        else
            cout<<"-1"<<endl;

        yy++;
    }
    else
    {
        if(x2>0)
            printf("%.11lf\n",min(x1,x2));
        else
            printf("%.11lf\n",x1);
    }
    return 0;
}
