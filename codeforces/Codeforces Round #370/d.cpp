#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return a<b;
}
int f[10]={0,1,2,3,1,2};
int main(){
    sort(f,f+6,cmp);
    for(int i=0;i<6;i++)
        cout<<f[i]<<endl;
    return 0;
}
