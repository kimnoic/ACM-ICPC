#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <queue>
#include <vector>
#include <stack>
#include <set>
#include <map>
using namespace std;
#define rson l,m,rt*2
#define lson m+1,r,rt*2+1
#define Max 333
struct pt{
    int x,y;
}p[Max];
bool cmp(pt a,pt b){
    if(a.y==b.y) return a.x<b.x;
    else return a.y<b.y;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>p[i].x>>p[i].y;
        }int flag=0;
        if(n==4){
            sort(p+1,p+n+1,cmp);
            flag=1;

            int x1=p[1].x-p[2].x;
            int y1=p[1].y-p[2].y;
            int x2=p[1].x-p[3].x;
            int y2=p[1].y-p[3].y;
           //cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
            if(abs(x1)!=abs(y2)||abs(y1)!=abs(x2)) flag=0;
            x1=p[4].x-p[2].x;
            y1=p[4].y-p[2].y;
            x2=p[4].x-p[3].x;
            y2=p[4].y-p[3].y;
            if(abs(x1)!=abs(y2)||abs(y1)!=abs(x2)) flag=0;
        }
        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
