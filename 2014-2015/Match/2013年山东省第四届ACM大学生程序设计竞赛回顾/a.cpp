#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <set>
#include <queue>
#include <map>
#include <stack>
#include <vector>
#include <stdlib.h>
#include <math.h>
using namespace std;
int _case;
double x1,x2,x3,y,y2,y3;
#define pi acos(-1)
int main()
{
	cin>>_case;
	while(_case--)
	{
		cin>>x1>>y>>x2>>y2;
		double a=atan2((y2-y),(x2-x1));
		double l=sqrt((y2-y)*(y2-y)+(x2-x1)*(x2-x1));
		x3=x1+l*cos(a+pi/3);
		y3=y+l*sin(a+pi/3);
		printf("(%.2lf,%.2lf)\n",x3,y3);
	}
	return 0;
}
