#include <bits/stdc++.h>
using namespace std;
int n;
struct pt{
    int a,b;
}p[233];
bool cmp(pt a,pt b){
    return a.a<b.a;
}
int main(){
    cin>>n;
    int sum=0;
    for(int i=1;i<=n;i++) {
        cin>>p[i].a;
        p[i].b=i;

    }
    sort(p+1,p+n+1,cmp);
    for(int i=1;i<=n/2;i++){
        cout<<p[i].b<<" "<<p[n-i+1].b<<endl;
    }
    return 0;
}
