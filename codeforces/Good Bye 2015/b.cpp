#include <bits/stdc++.h>
using namespace std;
long long a,b;
#define Max 1010
int aa[Max],bb[Max];
int cal(long long a){
    if(a/2==0) return 1;
    else return cal(a/2)+1;
}
int main(){
    cin>>a>>b;
    int lena=cal(a);
    int lenb=cal(b);
    //cout<<lena<<" "<<lenb<<endl;
    int ka=0,kb=0;
    int tb=0;
    for(int i=lena;i>=1;i--){
        aa[i]=a%2;
        if(!aa[i]) ka++;
        a/=2;
    }
    for(int i=lenb;i>=1;i--){
        bb[i]=b%2;
        if(!bb[i]) {kb++;tb=i;}
        b/=2;
    }
    if(lenb==lena){
        if(kb>=2){
            cout<<0;
            return 0;
        }
        unsigned long long cnt=0;
        int cntb=0;
        int flag=0;
        for(int i=1;i<=lena;i++){
            if(!flag){
                if(!aa[i]){
                cnt++;
                if(!bb[i]) break;
                flag=1;
                }
            }
            if(flag){
                cnt++;
            }
            if(tb){
                if(i==tb) break;
            }
        }
        cout<<cnt;
    }
    else{
        unsigned long long cnt=0;
        if(!kb){
            cnt+=(lenb-1);
        }
        else if(kb==1){
            cnt+=(lenb-tb+1);
        }
        for(int i=lena+1;i<lenb;i++){
            cnt+=i-1;
        }
        //cout<<cnt<<endl;
        int flag=0;
        for(int i=1;i<=lena;i++){
            if(!flag){
                if(!aa[i]){
                    cnt++;
                    flag=1;
                }
            }
            else cnt++;
        }
        cout<<cnt;
    }
    return 0;
}
