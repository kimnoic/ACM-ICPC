#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,d,h;
    cin>>n>>h>>d;
    if(n==2&&h==1&&d==1){
        cout<<"1 2";
        return 0;
    }
    if(2*d<h || (max(d,h))>=n || d>h ||(h==d&&h==1&&n>2)){
        cout<<"-1";
        return 0;
    }
    if(d==h){
        for(int i=1;i<=d;i++){
            printf("%d %d\n",i,i+1);
        }
        for(int i=d+2;i<=n;i++){
            printf("2 %d\n",i);
        }
        return 0;
    }
    for(int i=1;i<=d;i++){
        printf("%d %d\n",i,i+1);
    }
    printf("%d %d\n",1,d+2);
    for(int i=d+2;i<=h;i++){
        printf("%d %d\n",i,i+1);
    }
    for(int i=h+2;i<=n;i++){
        printf("%d %d\n",1,i);
    }
    return 0;
}
