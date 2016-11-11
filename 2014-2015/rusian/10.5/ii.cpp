#include<stdio.h>
#include<math.h>
#define pi 3.1415926
int main()
{
    int D,V;
    double k,d;
    while(scanf("%d%d",&D,&V)&&D&&V)
    {
       k=D*D*D-6*V/pi;
       d=pow(k,1.0/3.0);
       printf("%.3lf\n",d);
    }
    return 0;
}
