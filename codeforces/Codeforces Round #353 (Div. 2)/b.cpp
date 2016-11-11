#include <bits/stdc++.h>
using namespace std;
long long a,b,c,d,n;
int main(){
    cin>>n>>a>>b>>c>>d;
    long long maxx=max(max(a+b,a+c),max(b+d,c+d));
    long long minn=min(min(a+b,a+c),min(b+d,c+d));
    long long t=maxx-minn;
    cout<<max((long long)0,(n)*(n-((maxx-minn))));
    return 0;
}
