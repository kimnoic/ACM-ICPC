#include <bits/stdc++.h>
using namespace std;
int p;int k;
void change(){
    if(p==1) p=2;
    else if(p==2) p=1;
    else p=k;
}
int main(){
    int n;
    cin>>n;
    int sum=0;
    p=0;
    for(int i=1;i<=n;i++){
        cin>>k;
        if(k==0){
            sum++;
            p=0;
        }
        else {
            if(p==0){
                p=k;
                continue;
            }
            if(p==3){
                p=k;
                continue;
            }
            else if(p==2){
                if(k==2){
                    sum++;
                    p=0;
                }
                else p=1;
            }
            else {
                if(k==1){
                    sum++;
                    p=0;
                }
                else p=2;
            }
        }

    }
    cout<<sum;
    return 0;
}
