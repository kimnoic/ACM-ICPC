#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <queue>
#include <stack>
#include <vector>
#include <set>
#include <map>
using namespace std;
#define Max 2000100
int val[Max];
int n,k;
int bfs(){
    queue<int>q;
    val[n]=1;
    while(!q.empty()) {q.pop();}
    q.push(n);
    while(1){
        int res=q.front();
        if(res==k) return val[res];
        if(res>Max-1||res<0) continue;
        q.pop();
        if(res-1>=0&&!val[res-1]){
            val[res-1]=val[res]+1;q.push(res-1);
        }
        if(res+1<Max&&!val[res+1]){
            val[res+1]=val[res]+1;q.push(res+1);
        }
        if((2*res<Max)&&!val[2*res]){
            val[2*res]=val[res]+1;
            q.push(res*2);
        }
    }
}
int main(){
    cin>>n>>k;
    memset(val,0,sizeof(val));
    cout<<bfs()-1;
    return 0;
}
