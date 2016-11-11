#include <bits/stdc++.h>
using namespace std;
#define Max 33
int c[Max][Max];
void init(){
    c[0][0]=1;
    for(int i=1;i<Max;i++){
        c[i][0]=c[i-1][0];
        for(int j=1;j<=i;j++){
            c[i][j]=c[i-1][j]+c[i-1][j-1];
        }
    }
}
int cal(int x,int k){
    int cnt=0,ans=0;
    for(int i=31;i>0;i--){
        if(x&(1<<i)){
            cnt++;
            if(cnt>k) break;
            x^=(1<<i);
        }
        if((1<<(i-1))<=x)
            ans+=c[i-1][k-cnt];
    }
    if(cnt+x==k) ++ans;
    return ans;
}
int search(int l,int r,int k){
    int index = 1, cnt = 0;
    for(int i=1;i<=Max;i++){
        cnt=cal(r,i)-cal(l-1,i);
        if(k<=cnt) {
            index = i;
            break;
        }
        k-=cnt;
    }
    int mid, ll = l;
    while(l<r){
        mid=l+(r-l)/2;
        cnt=cal(mid,index)-cal(ll-1,index);
        if(cnt<k) l = mid+1;
        else r=mid;
    }
    return l;
}
int x,y,k,t;

int main(){
    cin>>t;
    init();
    while(t--){
        cin>>x>>y>>k;
        if(x>=0){
            if(k==0){
            cout<<0<<endl;
            continue;
        }
        if(x==0){
            k-=1;
            x+=1;
        }
        cout<<search(x, y, k)<<endl;
        }
        else{
            if(k==0){
                cout<<0<<endl;
                continue;
            }
            if(y==0) {
                k -= 1;
                y -= 1;
            }
            x&=~(1<<31);
            y&=~(1<<31);
            cout<<((1<<31)|search(x, y, k))<<endl;
        }
    }
    return 0;
}
