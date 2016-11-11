#include <stdio.h>
#include <math.h>
const double pi = acos(-1.0);
int main()
{
    int t;
    double x1,x2,x3,y1,y2,y3,l,at;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
        at = atan2(y2-y1,x2-x1);
        l = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
        x3 = x1+l*cos(at+pi/3.0);
        y3 = y1+l*sin(at+pi/3.0);
        printf("(%.2lf,%.2lf)\n",x3,y3);
    }

    return 0;
}
