#include <bits/stdc++.h>
using namespace std;
int T;
long long n;
vector<int>q;
long long f[23][2];
const int N = 30;
long long z[N] = {1};
long long dp(int len,bool flag_1,bool flag_2){
    if(len==0) return 0;
    if(!flag_1&&f[len][1]!=-1) return f[len][flag_1];
    long long cnt=0;
    int ed=flag_2?q[len]:9;
    for(int i=0;i<=ed;i++){
        if(flag_1&&i==9){
            cnt += flag_2 ? n % z[len-1] + 1 : z[len-1];
        }
        else {
            cnt += dp(len - 1, i == 4, flag_2 && q[len] == i);
        }
    }
    return flag_2 ? cnt : f[len][flag_1] = cnt;
}
long long cal(long long x){
    q.clear();
    if(x==0) return 0;
    while(x){
        q.push_back(x%10);
        x/=10;
    }
    memset(f,-1,sizeof(f));
    return dp(q.size()-1,false,true);
}
int main(){
    cin>>T;
    while(T--){
        cin>>n;
        cout<<cal(n)<<endl;
    }
    return 0;
}
