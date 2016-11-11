#include <bits/stdc++.h>
using namespace std;
struct pt{
    long long m,s;
}p[100010];
int n;
long long d;
bool cmp(pt a,pt b){
    return a.m<b.m;
}
int main(){
    cin>>n>>d;
    for(int i=1;i<=n;i++){
        cin>>p[i].m>>p[i].s;
    }
    sort(p+1,p+n+1,cmp);
    long long tmp=p[1].s;
    long long res=tmp;
    int last=0;
    last=1;
    for(int i=2;i<=n;i++){
        if(p[i].m-p[last].m<d){
            tmp+=p[i].s;
            res=max(res,tmp);
        }
        else {
            while(p[i].m-p[last].m>=d&&last<=i){
                tmp-=p[last].s;
                last++;
            }
            tmp+=p[i].s;
            res=max(res,tmp);
        }
    }
    cout<<res;
    return 0;
}
