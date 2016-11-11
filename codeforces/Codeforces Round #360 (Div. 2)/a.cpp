#include <bits/stdc++.h>
using namespace std;
char t[233];
int main(){
    int n,d;
    cin>>n>>d;
    int sum=0,res=0;
    for(int i=1;i<=d;i++){
        cin>>t;
        int len=strlen(t);
        int flag=1;
        for(int j=0;j<len;j++){
            if(t[j]=='0'){
                flag=0;
                break ;
            }

        }
        if(!flag)
            sum++;
        else {
            sum=0;
        }
        res=max(res,sum);
    }
    cout<<res;
    return 0;
}
