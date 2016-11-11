#include <bits/stdc++.h>
using namespace std;
int n;
long long x,y;
#define Max 100010
struct pt{
    long long x,y,s;
}p[Max];
bool cmp(pt a,pt b){
    if(a.x==b.x){
        return a.y>b.y;
    }
    else return a.x<b.x;
}
bool judge(pt a,pt b,pt c){
    if((b.y-a.y)*(c.x-b.x)!=(c.y-b.y)*(b.x-a.x)) return true;
    else return false;
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        p[i].s=i;
        cin>>p[i].x>>p[i].y;
    }
    sort(p+1,p+n+1,cmp);
    for(int i=1;i<n-1;i++){
        if(judge(p[i],p[i+1],p[i+2])){
            cout<<p[i].s<<" "<<p[i+1].s<<" "<<p[i+2].s;
            break;
        }
    }
    return 0;
}
