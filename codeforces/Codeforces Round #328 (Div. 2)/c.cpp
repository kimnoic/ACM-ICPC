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
#define lson l,m,rt*2
#define rson m+1,r,rt*2+1
long long m,x,y,res,g,lim,a,b,c;
double tt;
int main(){
    scanf("%I64d %I64d %I64d",&m,&x,&y);
    if(x<=y){

    }
    else
        swap(x,y);
    a=x-1;
    res=min(m,a);
    g=__gcd(x,y);
    tt=x;
    tt*=(double)y;
    tt/=g;
    if(tt>m)
        c=0;
    else{
        lim=(long long)x/g*y;
        c=m/lim;
        if(c!=0)
            res=c*(a+1);
        if(m%lim!=0){
            long long temp=(long long)lim*c;
            res+=min(a,(m-temp));
        }
    }
    if(res!=0){
        g=__gcd(res,m);
        printf("%I64d/%I64d\n",res/g,m/g);
    }
    else cout<<res<<"/"<<m<<endl;
    return 0;
}
