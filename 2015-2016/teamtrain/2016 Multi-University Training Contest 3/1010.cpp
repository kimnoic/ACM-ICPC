#include <bits/stdc++.h>
const double eps=1e-5;
double a,v1,v2,x,y,t,s;
int w[2][2]={2,3,4,1};
int main(){
    //while(~scanf("%lf%lf%lf",&a,&v1,&v2)){
    freopen("in.txt","w",stdout);
    for(a=0;a<=100;a+=1)
    for(v1=0;v1<=100;v1+=1){
        for(v2=0;v2<=v1-4;v2+=1){
                t=0;
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
                printf("%.5f,",t);
        }
        for(v2=v1+1;v2<=100;v2+=1){
            if(v2>=v1){
                printf("0,");
            }
        }
    }
    return 0;
}
