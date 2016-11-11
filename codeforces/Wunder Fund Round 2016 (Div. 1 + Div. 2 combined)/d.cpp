#include <bits/stdc++.h>
using namespace std;
long long n,x,y;
#define Max 200010
struct pt{
    int x,y;
}p[Max];
vector<int>q[Max];
int main(){
    cin>>n>>x>>y;
    for(int i=1;i<=n;i++){
        cin>>p[i].x>>p[i].y;
    }
    if(y<=x){
        cout<<(n-1)*y;
        return 0;
    }

    return 0;
}
