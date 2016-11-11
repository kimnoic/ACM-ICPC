#include <bits/stdc++.h>
using namespace std;
const int maxn = 20010;
int n,q,l,r,k;
long long res[maxn];
int a[maxn];
struct pt{
    int l,r;
    int id;
}p[maxn];
bool cmp1(pt a,pt b){
    if(a.l/k!=b.l/k) return a.l/k<b.l/k;
    else return a.r<b.r;
}
vector<int> divi[maxn];
int f[maxn];
void getdivisor(){
    for(int i=1;i<maxn;i++){
        for(int j=i;j<maxn;j+=i){
            divi[j].push_back(i);
        }
    }
}
void getf(){
    for(int i=1;i<maxn;i++){
        int t=i;
        for(int j=0;j<divi[i].size();j++){
            t-=f[divi[i][j]];
        }
        f[i]=t;
    }
}
int cnt[maxn];
long long del(int a){
    long long ret=0;
    for(int i=0;i<divi[a].size();i++){
        int y=divi[a][i];
        ret+=1LL*f[y]*(--cnt[y]);
    }
    return ret;
}
long long Insert(int a){
    long long ret=0;
    for(int i=0;i<divi[a].size();i++){
        int y=divi[a][i];
        ret+=1LL*f[y]*(cnt[y]++);
    }
    return ret;
}
bool cmp2(pt a,pt b){
    return a.id<b.id;
}
int main(){
    getdivisor();
    getf();
    int _case=0;
    int T;
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        cin>>q;
        for(int i=1;i<=q;i++){
            cin>>p[i].l>>p[i].r;
            p[i].id=i;
        }
        k=sqrt(n);
        long long ress=0;
        sort(p+1,p+q+1,cmp1);l=0,r=0;
        memset(cnt,0,sizeof(cnt));
        for(int i=1;i<=q;i++){
            //cout<<i<<endl;
            int ll=p[i].l,rr=p[i].r;
            while(l<ll){
                ress-=del(a[l]);
                l++;
            }
            while(l>ll){
                l--;
                ress+=Insert(a[l]);

            }
            while(r<rr){
                r++;
                ress+=Insert(a[r]);

            }
            while(r>rr){
                ress-=del(a[r]);
                r--;
            }
            res[p[i].id]=ress;
        }
        //sort(p+1,p+q+1,cmp2);
        cout<<"Case #"<<++_case<<":"<<endl;
        for(int i=1;i<=q;i++) cout<<res[i]<<endl;
    }
    return 0;
}
