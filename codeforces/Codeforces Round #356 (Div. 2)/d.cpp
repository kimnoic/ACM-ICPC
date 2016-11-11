#include <bits/stdc++.h>
using namespace std;
long long th(long long x){
    return x*x*x;
}
long long cct=0;
long long cal(long long x){
    long long ans=pow(x,1.0/3.0);
    ans+=5;
    int r=0;
    while(x){
        if(x>=th(ans)){
            x-=th(ans);
            r++;
            cct++;
        }
        else
            ans--;
    }
    return r ;
}
long long tmp,sum,cnt,n;
vector<long long>v;
int main(){
    cin>>n;
    tmp=1;sum=0;cnt=0;
    while(1){
        while(th(tmp)>=(th(tmp+1)-sum)){
            tmp++;
            cct++;
            if(tmp>1e5)
                break;
        }
        if(sum+th(tmp)>n)
            break;
        v.push_back(tmp);
        cnt++;
        sum+=th(tmp);

    }
    int len=v.size();
    long long k=1;
    for(int i=len-1;i>=0;i--){
        long long temp=sum-th(v[i]);
        long long ll=v[i],rr=100001;
        k++;
        while(ll<rr){
            long long mid=ll+rr+1>>1LL;
            if(!(cal(temp+th(mid))==cnt&&temp+th(mid)<=n)){
                rr=mid-1;
            }
            else
                ll=mid;
            v[i]=ll;
        }
        sum=temp+th(v[i]);
    }
    if(k)
        cout<<cnt<<" "<<sum<<endl;
    return 0;
}
