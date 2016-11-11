#include <bits/stdc++.h>
using namespace std;
#define Si(a) scanf("%d",&a)
#define Sd(a) scanf("%lf",&a)
#define inf 1e30
struct p{
    double x,y,la,lb,lt;
}bot[100010];

double solve(double ax,double ay,double bx,double by){
    return sqrt((ax-bx)*(ax-bx)+(ay-by)*(ay-by));
}
int main(){
    double ax,ay,bx,by,tx,ty;
    int i,n;
    scanf("%lf%lf%lf%lf%lf%lf",&ax,&ay,&bx,&by,&tx,&ty);
    Si(n);
    for(i=1;i<=n;i++){
        Sd(bot[i].x),Sd(bot[i].y);
        bot[i].lt=solve(bot[i].x,bot[i].y,tx,ty);
        bot[i].la=solve(bot[i].x,bot[i].y,ax,ay);
        bot[i].lb=solve(bot[i].x,bot[i].y,bx,by);
    }
    int mai=0,mbi=0;
    double ma=-inf,mb=-inf;
    double sum1=0,sum2=0,sum3=0,sum4=0;
    for(i=1;i<=n;i++){
        if(bot[i].lt-bot[i].la>ma){
            ma=bot[i].lt-bot[i].la;
            mai=i;
        }
    }
    for(i=1;i<=n;i++){
        if(i==mai)continue;
        if(bot[i].lt-bot[i].lb>mb){
            mb=bot[i].lt-bot[i].lb;
            mbi=i;
        }
    }
    sum1=bot[mai].la+bot[mai].lt+bot[mbi].lb+bot[mbi].lt;
    for(i=1;i<=n;i++){
        if(i==mai||i==mbi)continue;
        sum1+=bot[i].lt*2;
    }

    ma=-inf;mb=-inf;mai=0;mbi=0;
    for(i=1;i<=n;i++){
        if(bot[i].lt-bot[i].lb>mb){
            mb=bot[i].lt-bot[i].lb;
            mbi=i;
        }
    }
    for(i=1;i<=n;i++){
        if(i==mbi)continue;
        if(bot[i].lt-bot[i].la>ma){
            ma=bot[i].lt-bot[i].la;
            mai=i;
        }
    }
    sum2=bot[mai].la+bot[mai].lt+bot[mbi].lb+bot[mbi].lt;
    for(i=1;i<=n;i++){
        if(i==mai||i==mbi)continue;
        sum2+=bot[i].lt*2;
    }

    ma=-inf;mb=-inf;mai=0;mbi=0;
    for(i=1;i<=n;i++){
        if(bot[i].lt-bot[i].la>ma){
            ma=bot[i].lt-bot[i].la;
            mai=i;
        }
    }
    sum3=bot[mai].la+bot[mai].lt;
    for(i=1;i<=n;i++){
        if(i==mai)continue;
        sum3+=bot[i].lt*2;
    }

    ma=-inf;mb=-inf;mai=0;mbi=0;
    for(i=1;i<=n;i++){
        if(bot[i].lt-bot[i].lb>mb){
            mb=bot[i].lt-bot[i].lb;
            mbi=i;
        }
    }
    sum4=bot[mbi].lb+bot[mbi].lt;
    for(i=1;i<=n;i++){
        if(i==mbi)continue;
        sum4+=bot[i].lt*2;
    }

    printf("%.12lf\n",min(min(sum1,sum2),min(sum3,sum4)));
    return 0;
}
