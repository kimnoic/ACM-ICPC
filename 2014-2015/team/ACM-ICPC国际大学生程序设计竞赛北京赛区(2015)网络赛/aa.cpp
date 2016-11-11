#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <queue>
#include <stack>
#include <vector>
#include <set>
#include <map>
using namespace std;
int T,m,n;
struct pt{
    double x,y;
}p[233];
double dis[233];
int main(){
    cin>>T;
    while(T--){
        int maxx=9999999;
        cin>>m>>n;
        for(int i=1;i<=m;i++){
            scanf(" %lf %lf",&p[i].x,&p[i].y);
        }
        for(int i=1;i<=m;i++){
            int top=0;
            for(int j=1;j<=m;j++){
                if(j==i) continue;
                else{
                    double d=(p[j].x-p[i].x)*(p[j].x-p[i].x)+(p[j].y-p[i].y)*(p[j].y-p[i].y);
                    dis[++top]=d;
                }
            }
            if(n==0&&m!=0) continue;
            sort(dis+1,dis+top+1);
            if(top<n-1) continue;
            if(top>=n){
                int x2=sqrt(dis[n-1]);
                if(sqrt(dis[n])<=x2+1) continue;
            }
            int res=sqrt(dis[n-1])+1;
            maxx=min(maxx,res);
        }
        if(maxx==9999999) cout<<"-1"<<endl;
        else cout<<maxx<<endl;
    }
    return 0;
}
