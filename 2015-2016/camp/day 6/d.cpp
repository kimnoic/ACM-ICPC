#include <bits/stdc++.h>
using namespace std;
#define Max 100010
#define INF 0x3fffffff
int f[Max],n,cnt;
struct pt{
    int a,b;
}p[Max];
bool cmp(pt a,pt b){
    if(a.a!=b.a)
    return a.a>b.a;
    else return a.b>b.b;
}
long long sum=0;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        f[i]=INF;
    }
    for(int i=1;i<=n;i++){
        cin>>p[i].a;
    }
    for(int i=1;i<=n;i++){
        cin>>p[i].b;
    }
    cnt=0;
    sort(p+1,p+n+1,cmp);
    for(int i=2;i<=n;i++){

        if(!(i%2)){
            f[++cnt]=p[i].b;
            int k=cnt;
            while(k!=1){
                if(f[k]<f[k/2]){
                    swap(f[k],f[k/2]);
                    k/=2;
                }
                else {
                    break;
                }
            }
        }
        else {
            if(p[i].b>f[1]){
                f[1]=p[i].b;
                int k=1;
                while(f[k]>min(f[k*2],f[k*2+1])){
                    if(f[k*2+1]==INF){
                        swap(f[k],f[k*2]);
                        break;
                    }
                    else if(f[k*2]<f[k*2+1]){
                        swap(f[k],f[k*2]);
                        k*=2;
                    }
                    else {
                        swap(f[k],f[k*2+1]);
                        k*=2;
                        k++;
                    }
                }
            }
        }
    }
    for(int i=1;i<=cnt;i++) sum+=(long long)f[i];
    cout<<sum;
    return 0;
}
/*
5
1 2 3 4 5
2 3 4 5 6
*/
