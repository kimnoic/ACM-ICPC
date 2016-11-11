#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <set>
#include <map>
using namespace std;
struct pt{
    double x,y;
}p[40][40];
double xx,yy;
void cal(pt a,pt b,pt c,pt d){
    xx=a.x;
    yy=a.y;
    double k=((a.x-c.x)*(c.y-d.y)-(a.y-c.y)*(c.x-d.x))/((a.x-b.x)*(c.y-d.y)-(a.y-b.y)*(c.x-d.x));
    xx+=(b.x-a.x)*k;
    yy+=(b.y-a.y)*k;
}
double cross(pt a,pt b,pt c)
{
    return (a.x-c.x)*(b.y-c.y)-(b.x-c.x)*(a.y-c.y);
}
double res,temp;
int n;
int main(){
    while(cin>>n){
        if(n==0) break;
        res=0;
        memset(p,0,sizeof(p));
        for(int i=1;i<=n;i++){
            cin>>p[i][0].x;
            p[i][0].y=0;
        }
        for(int i=1;i<=n;i++){
            cin>>p[i][n+1].x;
            p[i][n+1].y=1;
        }
        for(int i=1;i<=n;i++){
            cin>>p[0][i].y;
            p[0][i].x=0;
        }
        for(int i=1;i<=n;i++){
            cin>>p[n+1][i].y;
            p[n+1][i].x=1;
        }
        p[0][0].x=0;p[0][0].y=0;
        p[0][n+1].x=0;p[0][n+1].y=1;
        p[n+1][0].x=1;p[n+1][0].y=0;
        p[n+1][n+1].x=1;p[n+1][n+1].y=1;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cal(p[i][0],p[i][n+1],p[0][j],p[n+1][j]);
                p[i][j].x=xx;
                p[i][j].y=yy;
            }
        }
        /*for(int i=0;i<=n+1;i++){
            for(int j=0;j<=n+1;j++){
                cout<<p[i][j].x<<" "<<p[i][j].y<<endl;
            }
        }*/
        for(int i=1;i<=n+1;i++){
            for(int j=1;j<=n+1;j++){
                temp=fabs(cross(p[i][j],p[i-1][j],p[i][j-1]));
                temp+=fabs(cross(p[i-1][j-1],p[i-1][j],p[i][j-1]));
                temp/=2;
                res=max(res,temp);
            }
        }
        printf("%.6lf\n",res);
    }
    return 0;
}
