#include<stdio.h>
#include<string.h>
#include<math.h>
#include <iostream>
using namespace std;
const double esp=1e-9;
double r1,r2;
double f(double x)//横截面的面积计算
{
return 4*sqrt(r1*r1-x*x)*sqrt(r2*r2-x*x);
}
double simpson(double a,double b)
{
return (b-a)*(f(a)+4*f((a+b)/2)+f(b))/6.0;
}
double caclulate(double a,double b,int cnt)//这里使计算积分，可是目前还是不大懂为什么这样做？？？
{
double sum=simpson(a,b),mid=(a+b)/2.;
double t=simpson(a,mid)+simpson(mid,b);
if((fabs(t-sum)<esp)&& cnt>3) return sum;
return caclulate(a,mid,cnt+1)+caclulate(mid,b,cnt+1);
}
int main()
{int T;
 double r,ans;
   	scanf("%lf%lf",&r1,&r2);
   	if(r1-r2>esp)//这里的比较大小与精度有关
   	r=r2;
   	else
   	r=r1;
   	ans=2.0*caclulate(0,r,0);
   	printf("%.4lf\n",ans);
    return 0;
}
