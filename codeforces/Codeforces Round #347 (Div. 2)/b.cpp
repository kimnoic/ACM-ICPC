#include <bits/stdc++.h>
using namespace std;
int a[2333];
int b,c,n;
char t;
int main(){
    int cnt=0;
    b=0;
    c=0;
    while(cin>>t&&t!='='){
        if(t=='?') continue;
        else if(t=='+'){
            a[++cnt]=1;
            b++;
        }
        else a[++cnt]=-1,c++;

    }
    cin>>n;
    if(((b+1)*n-c)<n||((b+1)-c*n)>n)
        {
        cout<<"Impossible";
        return 0;
    }
    cout<<"Possible"<<endl;

    int sum=n+c;
    int k=sum/(b+1);
    int l=sum%(b+1);
    if(l){
        cout<<k+1;
        l--;
    }
    else cout<<k;
    for(int i=1;i<=cnt;i++){
        if(a[i]==-1){
            cout<<" - 1";
        }
        else{
            cout<<" + ";
            if(l){
                cout<<k+1;
                l--;
            }
            else cout<<k;
        }
    }
    cout<<" = "<<n;
    return 0;
}
