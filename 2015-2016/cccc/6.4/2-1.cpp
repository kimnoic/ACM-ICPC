#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <queue>
#include <stack>
#include <vector>
#include <set>
#include <map>
using namespace std;
const int maxn = 10010;
struct pt{
    int val;
    int k;
    int id;
}p[maxn];
bool cmp(pt a,pt b){
    if(a.val==b.val){
        if(a.k==b.k){
            return a.id<b.id;
        }
        else return a.k>b.k;
    }
    else return a.val>b.val;
}
int n;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        p[i].id=i;
        int k;
        cin>>k;
        int a,b;
        double sum=0;
        for(int j=1;j<=k;j++){
            cin>>a>>b;
            p[a].k++;
            p[a].val+=b;
            sum+=b;
        }
        p[i].val-=sum;
    }
    sort(p+1,p+n+1,cmp);
    for(int i=1;i<=n;i++){
        cout<<p[i].id<<" ";
        printf("%.2f\n",(double)p[i].val/100.0);
    }
    return 0;
}
