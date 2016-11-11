#include <bits/stdc++.h>
using namespace std;
#define Max 200010
long long a[Max];
long long minn;
int n;
int main(){
    cin>>n;
    cin>>a[1];
    minn=a[1];
    for(int i=2;i<=n;i++){
        scanf("%I64d",&a[i]);
        minn=min(minn,a[i]);

    }
    int cnt=0;
    int maxx=0;
    int f1=0,flag=0;
    for(int i=1;i<=n;i++){
        a[i]-=minn;
        if(a[i]) {
            cnt++;
            if(flag==0){
                f1++;
            }
        }
        else {
            flag=1;
            maxx=max(maxx,cnt);
            cnt=0;
        }
    }
    maxx=max(maxx,f1+cnt);
    cout<<minn*n+maxx;

    return 0;
}
