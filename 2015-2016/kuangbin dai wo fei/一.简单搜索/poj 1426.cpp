#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <queue>
#include <vector>
#include <stack>
#include <set>
#include <map>

using namespace std;


#define LL long long
void bfs(int x){
    queue<LL>q;
    while(!q.empty()){
        q.pop();
    }
    q.push(1);
    while(!q.empty()){
        long long k=q.front();
        q.pop();
        if(k%x==0){
            cout<<k<<endl;
            return ;
        }
        q.push(k*10);
        q.push(k*10+1);
    }
}
int main(){
    int n;
    while(cin>>n){
        if(n==0) break;
        bfs(n);
    }
    return 0;
}
