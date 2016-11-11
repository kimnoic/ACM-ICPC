#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define DEBUG(x) cout<< #x << ':' << x << endl
#define FOR(i,s,t) for(int i = (s);i <= (t);i++)
#define FORD(i,s,t) for(int i = (s);i >= (t);i--)
#define REP(i,n) FOR(i,0,n-1)
#define REPD(i,n) FORD(i,n-1,0)
#define PII pair<int,int>
#define PB push_back
#define MP make_pair
#define ft first
#define sd second
#define lowbit(x) (x&(-x))
#define INF (1<<30)

const int maxn = 1e5+10;
char s[maxn];
int sa[maxn],t1[maxn],t2[maxn],c[maxn];
int rnk[maxn],height[maxn];

void getHeight(int n){
    int k = 0;
    for(int i=1;i<=n;i++)rnk[sa[i]] = i;
    for(int i=0;i<n;i++){
        if(k)k--;
        int j = sa[rnk[i]-1];
        while(s[i+k]==s[j+k])k++;
        height[rnk[i]] = k;
    }
}
bool cmp(int *r,int a,int b,int l){
    return (r[a]==r[b] && r[a+l]==r[b+l]);
}
void build_sa(int m,int n){
    int i,*x=t1,*y=t2,k,p;
    for( i=0;i<m;i++)c[i] = 0;
    for( i=0;i<n;i++)c[x[i] = s[i]]++;
    for( i=1;i<m;i++)c[i] += c[i-1];
    for( i=n-1;i>=0;i--)sa[-- c[x[i]]] = i;
    for(k=1,p=0;p<n;m=p,k<<=1){
        p = 0;
        for(i=n-k;i<n;i++)y[p++] = i;
        for(i=0;i<n;i++)if(sa[i]>=k)y[p++] = sa[i]-k;
        for(i=0;i<m;i++)c[i] = 0;
        for(i=0;i<n;i++)c[x[y[i]]]++;
        for(i=1;i<m;i++)c[i] += c[i-1];
        for(i=n-1;i>=0;i--)sa[--c[x[y[i]]]] = y[i];
        swap(x,y);
        p = 1; x[sa[0]] = 0;
        for(i=1;i<n;i++)
            x[sa[i]] = cmp(y,sa[i-1],sa[i],k)?p-1:p++;
    }
    getHeight(n-1);
}
int sum[maxn];
char temp;
void init(int n){
    memset(sum,0,sizeof(sum));
    if(s[0]==temp) sum[0]=1;
    for(int i=1;i<n;i++){
        sum[i]=sum[i-1];
        if(s[i]==temp) sum[i]++;
    }
}
long long solve(int n){
    long long ans;
    int p=sa[1];
    if(p==0&&sum[p]){
        ans=(long long)(n-sa[1]);
    }
    else if(p==0){
        int id=upper_bound(sum+p,sum+n,0)-sum;
        if(id!=n)
        ans=(long long)n-id;else ans=0;
    }
    else {
        int id=upper_bound(sum+p,sum+n,sum[p-1])-sum;
        if(id!=n)
        ans=(long long)n-id;
        else ans=0;
    }
    for(int i=2;i<=n;i++){
        p=sa[i];
        if(p==0){
            if(sum[p]==1){
                ans+=n-sa[i]-height[i];
            }
            else {
                int id=upper_bound(sum+p,sum+n,0)-sum;
                int h=height[i];
                if(id!=n)
                ans+=(long long)n-max(h+sa[i],id);
            }
        }
        else if(sum[p]>sum[p-1]){
            ans +=(long long) n-sa[i]-height[i];
        }
        else {
            int id=upper_bound(sum+p,sum+n,sum[p-1])-sum;
            int h=height[i];
            if(id!=n)
            ans+=(long long)n-max(h+sa[i],id);
        }
    }
    return ans;
}
int main(){
    int T;
    cin>>T;
    int _case=0;
    while(T--){
        cin>>temp;
        scanf("%s",s);
        int n = strlen(s);
        build_sa(255,n+1);
        init(n);
        printf("Case #%d: ",++_case);
        cout<<solve(n)<<endl;
    }
    return 0;
}
