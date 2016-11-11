#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>

using namespace std;
#define Max 33

int f[Max][Max];

int cal(int x,int k,int c){
    vector<int >q;
    int t=x;
    while(t){
        q.push_back(t%c);
        t/=c;
    }
    int cnt=0,ans=0;
    for(int i=q.size()-1;i>=0;i--){
        if(q[i]==1){
            ans+=f[i][k-cnt];
            cnt++;
            if(cnt==k) break;
        }
        else if(q[i]>1){
            ans+=f[i+1][k-cnt];
            break;
        }
    }
    if(cnt==k) ans++;
    return ans;
}
int x,y;
int k,b;
int main(){
    f[0][0]=1;
    for(int i=1;i<33;i++){
        f[i][0]=f[i-1][0];
        for(int j=1;j<=i;j++)
            f[i][j]=f[i-1][j-1]+f[i-1][j];
    }
    cin>>x>>y>>k>>b;
    cout<<cal(y,k,b)-cal(x-1,k,b);
    return 0;
}
