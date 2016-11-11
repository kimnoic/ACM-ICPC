#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
using namespace std;
#define Max 10010
double abss(double a){
    if(a<0) return -a;
    else return a;
}
double max(double a,double b){
    if(a>b) return a;
    else return b;
}
struct pt{
    int t,x;
}p[Max];
bool cmp(pt a,pt b){
    return a.t<b.t;
}
int T;
int main(){
    cin>>T;
    int _case=0;
    while(T--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            scanf("%d%d",&p[i].t,&p[i].x);
        }
        sort(p+1,p+n+1,cmp);
        double ans=abss(p[2].x-p[1].x)/(p[2].t-p[1].t);
        for(int i=3;i<=n;i++){
            ans=max(ans,abss(p[i].x-p[i-1].x)/(p[i].t-p[i-1].t));
        }
        printf("Case #%d: %.2lf\n",++_case,ans);
    }
    return 0;
}
