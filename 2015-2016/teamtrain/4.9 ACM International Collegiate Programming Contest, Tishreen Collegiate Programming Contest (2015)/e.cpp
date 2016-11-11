#include <bits/stdc++.h>
using namespace std;
int a[20];
int res[20];
int c[10];
map<long long,bool>mp;
int main(){
    int n,T;
    cin>>T;
    int cnt=0;
    int _case=0;
    while(T--){
        n=10;
        long long sum=0;
        mp.clear();
        for(int i=1;i<=n;i++){
            cin>>a[i];
            sum+=a[i];
            mp[a[i]]=true;
        }
        sum/=4;
        bool f=false;
        for(int i=2;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for(int k=j+1;k<=n;k++){
                    if(2*a[1]+a[i]+a[j]+a[k]==2*sum){
                        long long ans=(sum-a[1]);
                        cnt=0;
                        res[++cnt]=(ans-a[i]);
                        res[++cnt]=(ans-a[j]);
                        res[++cnt]=(ans-a[k]);
                        int p=0;
                        for(int l=2;l<=n;l++){
                            if(l!=i&&l!=j&&l!=k){
                                c[++p]=a[l];
                            }
                        }
                        sort(c+1,c+7);
                        int minn=min(res[1],res[2]);
                        minn=min(minn,res[3]);
                        res[4]=(c[1]-minn);
                        int maxx=max(res[1],res[2]);
                        maxx=max(maxx,res[3]);
                        res[5]=(c[6]-maxx);
                        bool flag=true;

                        for(int u=1;u<=5;u++){
                            for(int v=u+1;v<=5;v++){
                                if(!mp[res[u]+res[v]]){
                                    flag=false;
                                    break;
                                }
                            }
                            if(!flag){
                                break;
                            }
                        }
                        if(flag){
                            sort(res+1,res+6);
                            cout<<"Case "<<++_case<<":";
                            for(int u=1;u<=5;u++){
                                cout<<" "<<res[u];
                            }
                            cout<<endl;
                            f=true;
                            break;
                        }

                    }
                }
                if(f){
                    break;
                }
            }
            if(f) break;
        }
    }
    return 0;
}
