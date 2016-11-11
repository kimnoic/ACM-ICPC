#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <time.h>
using namespace std;
int T,E,n;
#define Max 233
#define N 233333
int a[Max],b[Max],dp[N];
priority_queue<int,vector<int>,greater<int> >q;
int main(){
    cin>>T;
    while(T--){
        cin>>n;
    while(!q.empty()) q.pop();
        for(int i=1;i<=n;i++){
            int x;
            cin>>x;
            q.push(x);
        }
        cin>>E;
        int sum=0;
        for (int i=1;i<n;i++){
            int fir=q.top();
            q.pop();
            int sec=q.top();
            q.pop();
            if(fir>sec) swap(fir,sec);
            a[i]=fir;b[i]=sec;
            E-=a[i];sum+=b[i]-a[i];
            q.push(fir+sec);
        }
        if(E<0||E>sum){
            cout<<"No"<<endl;
            continue;
        }
        memset(dp,0,sizeof(dp+E+1));
        dp[0]=1;
        for(int i=1;i<n;i++){
            int d=b[i]-a[i];
            for(int j=E;j>=d;j--){
                if (dp[j-d]){
                    dp[j]=1;
                }
            }
        }
        if(dp[E]){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
    }
    return 0;
}
