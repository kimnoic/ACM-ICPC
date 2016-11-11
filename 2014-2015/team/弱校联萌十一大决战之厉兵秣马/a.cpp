#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <queue>
#include <stack>
#include <vector>
#include <set>
#include <map>
using namespace std;
#define Max 110
struct pt{
    double x,y;
}p1[Max],p2[Max];
int vis1[Max],vis2[Max];
int n;
int cross(double x1,double x2,double y1,double y2){
    return x1*y2-x2*y1;
}
int xx(pt s,pt t){
    return (s.x*t.y+s.y*t.x);
}
const double eps=1e-8;
int sgn(double x){
    if (fabs(x)<eps) return 0;
    if (x<0) return -1;
    return 1;
}
pt A1,A2,B1,B2;
int kua(){
    pt A1B1,B2B1,A2A1,B2A1;
    A1B1.x=A1.x-B1.x;  A1B1.y=A1.y-B1.y;
    B2B1.x=B2.x-B1.x;  B2B1.y=B2.y-B1.y;
    A2A1.x=A2.x-A1.x;  A2A1.y=A2.y-A1.y;
    B2A1.x=B2.x-A1.x;  B2A1.y=B2.y-A1.y;
    if(xx(A1B1,B2B1)*xx(B2B1,A2A1)>=0){
        return 1;
        A1B1.y=-A1B1.y;A1B1.x=-A1B1.x;
        if(xx(A1B1,A2A1)*xx(A2A1,B2A1)>=0)
            {return 1;}
        else
            return 0;
    }
    else
        return 0;
}
int main(){

    A1.x=-42,A1.y=58,A2.x=-68,A2.y=60;
    B1.x=44,B1.y=86,B2.x=-47,B2.y=-44;
    //cout<<kua()<<endl;
    cin>>n;
    memset(vis1,0,sizeof(vis1));
    memset(vis2,0,sizeof(vis2));
    for(int i=1;i<=n;i++){
        scanf("%lf%lf",&p1[i].x,&p1[i].y);
    }
    for(int i=1;i<=n;i++){
        scanf("%lf%lf",&p2[i].x,&p2[i].y);
    }
    int cnt=n;
    int pre=n+1;
    while(cnt&&pre!=cnt){
        pre=cnt;
        int flag=0;
        for(int i=1;i<=n;i++){
            //cout<<"i    "<<i<<endl;
            if(vis1[i]==0){
                for(int j=1;j<=n;j++){
                    if(vis2[j]) continue;
                    vis1[i]=j;
                    vis2[j]=i;
                    int flag=0;
                    A1=p1[i],A2=p2[j];
                    for(int k=1;k<=n;k++){
                        if(!vis1[k]){
                            B1=p1[k];
                            for(int u=1;u<=n;u++){
                                if(!vis2[u]){
                                    B2=p2[u];
                                    if( min(A1.x,A2.x) <= max(B1.x,B2.x) &&
                                    min(B1.x,B2.x) <= max(A1.x,A2.x) &&
                                    min(A1.y,A2.y) <= max(B1.y,B2.y) &&
                                    min(B1.y,B2.y) <= max(A1.y,A2.y)   ){
                                        if(!kua()){
                                            //cout<<A1.x<<" "<<A1.y<<" "<<A2.x<<" "<<A2.y<<endl;
                                            //cout<<endl;
                                            //cout<<B1.x<<" "<<B1.y<<" "<<B2.x<<" "<<B2.y<<endl;
                                            //cout<<i<<" "<<j<<" "<<k<<" "<<u<<endl;
                                            flag=1;
                                            break;
                                        }
                                    }
                                }
                            }
                            if(flag) break;
                        }
                    }
                    if(!flag){
                        cnt--;
                        break;
                    }
                    else {
                        vis1[i]=0;
                        vis2[j]=0;
                    }
                }
                //cout<<endl;


            }
        }
    }
for(int i=1;i<=n;i++) cout<<vis1[i]<<endl;
    return 0;
}
