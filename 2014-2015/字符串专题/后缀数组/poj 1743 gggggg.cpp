#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int nMax = 200001;

int  num[nMax];
int sa[nMax], rank[nMax], height[nMax];
int wa[nMax], wb[nMax], wv[nMax], wd[nMax];

int cmp(int *r, int a, int b, int l){
    return r[a] == r[b] && r[a+l] == r[b+l];
}

void da(int *r, int n, int m){          //  倍增算法 r为待匹配数组  n为总长度 m为字符范围
    int i, j, p, *x = wa, *y = wb, *t;
    for(i = 0; i < m; i ++) wd[i] = 0;
    for(i = 0; i < n; i ++) wd[x[i]=r[i]] ++;
    for(i = 1; i < m; i ++) wd[i] += wd[i-1];
    for(i = n-1; i >= 0; i --) sa[-- wd[x[i]]] = i;
    for(j = 1, p = 1; p < n; j *= 2, m = p){
        for(p = 0, i = n-j; i < n; i ++) y[p ++] = i;
        for(i = 0; i < n; i ++) if(sa[i] >= j) y[p ++] = sa[i] - j;
        for(i = 0; i < n; i ++) wv[i] = x[y[i]];
        for(i = 0; i < m; i ++) wd[i] = 0;
        for(i = 0; i < n; i ++) wd[wv[i]] ++;
        for(i = 1; i < m; i ++) wd[i] += wd[i-1];
        for(i = n-1; i >= 0; i --) sa[-- wd[wv[i]]] = y[i];
        for(t = x, x = y, y = t, p = 1, x[sa[0]] = 0, i = 1; i < n; i ++){
            x[sa[i]] = cmp(y, sa[i-1], sa[i], j) ? p - 1: p ++;
        }
    }
}

void calHeight(int *r, int n){           //  求height数组。
    int i, j, k = 0;
    for(i = 1; i <= n; i ++) rank[sa[i]] = i;
    for(i = 0; i < n; height[rank[i ++]] = k){
        for(k ? k -- : 0, j = sa[rank[i]-1]; r[i+k] == r[j+k]; k ++);
    }
}

int loc[nMax],m;
char str[nMax],res[nMax];
bool vis[1004];
int abs(int a){if(a>0)return a;return -a;}

bool check(int mid,int len){
    int i,j;
   // cout<<"mid"<<mid<<endl;
    for(i=2;i<=len;i++){
        if(height[i]<mid)continue;
        for(j=i-1;j>=2;j--){
     //       cout<<i<<' '<<j<<endl;
            if(abs(sa[i]-sa[j])>=mid){
                return 1;
            }
            if(height[j]<mid)break;
        }
    }
    return 0;
}

int main(){
    int n,k,i,j,a,b,sp,ans;
    while(scanf("%d",&n)&&n){
        n--;
        ans=0;
        for(i=0;i<=n;i++){
            scanf("%d",&num[i]);
        }
        if(n<10){
            printf("0\n");
            continue;
        }
        for(i=0;i<n;i++){
            num[i]=num[i+1]-num[i]+90;
        }
        num[n]=0;
        da(num,n+1,200);
        calHeight(num,n);
        int left=3,right=n,mid;//开始二分
        while(right>=left){
            mid=(right+left)/2;
   //         cout<<"fuck"<<mid<<endl;
            if(check(mid,n)){         //判断长度为mid的串是否是所有字符串的公共子串
                left=mid+1;
                ans=mid;
            }
            else{
                right=mid-1;
            }
        }
        if(ans<4){
            printf("0\n");
        }
        else{
            printf("%d\n",ans+1);
        }
    }
}
    return 0;
}
