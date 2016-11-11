#include <bits/stdc++.h>
const double eps=1e-7;
double a,v1,v2,x,y,t,s;
int main(){
    //double q=3.0/25.0;
    printf("%.20f\n",q);
    while(~scanf("%lf%lf%lf",&a,&v1,&v2)){
        if(v2>=v1){
            printf("Infinity\n");
        }
        else {
            x=0,y=a;
            while(y>0){
                t+=eps;
                double an=x/y;
                double sum=sqrt(x*x+y*y);
                double tx=x/sum;
                double ty=y/sum;
                x-=tx*v1*eps;x+=v2*eps;
                y-=ty*v1*eps;
            }
            printf("%.10f\n",t);
        }
    }
    return 0;
}
