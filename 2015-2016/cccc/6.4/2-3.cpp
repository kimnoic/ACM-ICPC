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
const int maxn = 33;
int a[maxn];
int b[maxn],c[maxn],d[maxn],e[maxn];
void dd(int l,int r,int rt,int k){
    if(l>r) return ;
    if(l==r) {
        d[rt]=b[k];
        return ;
    }
    d[rt]=b[k];
    int p=c[b[k]];
    int w;
    int z=e[a[l]];
    for(int i=l;i<=p-1;i++){
        if(e[a[i]]<z) z=e[a[i]];
    }
    dd(l,p-1,rt*2,z);
    z=e[a[p+1]];
    for(int i=p+1;i<=r;i++){
        if(e[a[i]]<z) z=e[a[i]];
    }
    dd(p+1,r,rt*2+1,z);
}
int n;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
        c[a[i]]=i;
    }
    for(int i=1;i<=n;i++) {
        cin>>b[i];
        e[b[i]]=i;
    }
    dd(1,n,1,1);
    for(int i=1;i<=n;i++) cout<<d[i]<<endl;
    return 0;
}
/*
7
1 2 3 4 5 6 7
4 1 3 2 6 5 7
*/
