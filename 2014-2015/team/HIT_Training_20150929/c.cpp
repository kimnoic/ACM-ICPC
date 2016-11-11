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
int n;
int a,b,c;
map<long long ,int>q;
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>b>>c;
        double r=a+b+c;
        double res=(r-a)*(r-b)*(r-c)/r;
        long long now=(long long)(res*1e6+0.5);
        if(!q[res]){
            q[res]=1;
            //cout<<res<<endl;
        }
        else q[res]++;
    }
    int maxx=0;

    map<long long,int>::iterator it;
    for(it=q.begin();it!=q.end();++it){
        if(it->second>maxx){
            maxx=it->second;
            //cout<<it->second<<endl;
        }
    }
    cout<<maxx;
    return 0;
}
