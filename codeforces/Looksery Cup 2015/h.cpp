#include <iostream>
#include <stdio.h>
#define N 233
#include <math.h>
using namespace std;
int main()
{
	double a,b,c,d;
	cin>>a>>b>>c>>d;
	double x1,x2,res=1<<30;
    for(double aa=-1;aa<=1;aa+=2)
		for(double bb=-1;bb<=1;bb+=2)
			for(double cc=-1;cc<=1;cc+=2)
				for(double dd=-1;dd<=1;dd+=2)
	{
		double t=aa*dd-bb*cc;
		if(t!=0)
		{
			int y;
			if((-aa*d-dd*a+bb*c+cc*b)*(-aa*d-dd*a+bb*c+cc*b)-4*(a*d-b*c)*t<0) continue;
			x1=((-aa*d-dd*a+bb*c+cc*b)+sqrt((-aa*d-dd*a+bb*c+cc*b)*(-aa*d-dd*a+bb*c+cc*b)-4*(a*d-b*c)*t))/(2*t);
			if(x1<0) x1=-x1;
			res=min(res,x1);
			x1=((-aa*d-dd*a+bb*c+cc*b)-sqrt((-aa*d-dd*a+bb*c+cc*b)*(-aa*d-dd*a+bb*c+cc*b)-4*(a*d-b*c)*t))/(2*t);
			if(x1<0) x1=-x1;
			res=min(res,x1);
		}
		else
		{
			int x;
			if((-aa*d-dd*a+bb*c+cc*b)==0) continue;
			x1=(a*d-b*c)/(aa*d+dd*a-bb*c-cc*b);
			if(x1<0) x1=-x1;
			res=min(res,x1);
		}
	}
    printf("%.10lf",res);
	return 0;
}
