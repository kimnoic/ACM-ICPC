#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5+10;
int a[maxn],n,k;
long long sum=0;
int main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    sort(a+1,a+n+1);
    int ll = sum/n;
    int rr = (sum+n-1)/n;
    int l = 0,r=ll,ans1=0;
    while(l<=r){
        int m = (l+r)>>1;
        long long ne = 0;
        for(int i= 1;i<=n;i++)
            if(a[i]<=m)
                ne+=m-a[i];
        if (ne <= k)
            ans1=m,l=m+1;
        else
            r=m-1;
    }
    l = rr,r=1e9;
    int ansr = 0;
    while(l<=r){
        int m = (l+r)>>1;
        long long ne = 0;
        for (int i = 1;i<=n;i++)
            if (a[i]>m)
                ne+=a[i]-m;
        if (ne <= k)
            ansr = m,r=m-1;
        else
            l=m+1;
    }
    printf("%d\n",ansr-ans1);
    return 0;
}
