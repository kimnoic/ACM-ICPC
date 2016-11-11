#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
using namespace std;
int f[20][20];
vector <int > q;

int ddp(int len,int d,bool flag_1,bool flag_2){
    if(len==-1){
        if(flag_1) return d!=0;
        else return 1;
    }
    if(!flag_1&&!flag_2&&f[len][d]!=-1){
        return f[len][d];
    }
    int ed=9;
    int ans=0;
    if(flag_2) ed=q[len];
    //cout<<ed<<endl;
    for(int i=0;i<=ed;i++){
        if(flag_1){
            ans+=ddp(len-1,i,flag_1&&i==0,flag_2&&i==ed);
        }
        else if(abs(i-d)>=2){
            ans+=ddp(len-1,i,false,i==ed&&flag_2);
        }
    }

    if(!flag_1&&!flag_2){
        f[len][d]=ans;
    }
    return ans;
}

int cal(int x){
    if(x==0) return 0;
    q.clear();
    while(x){
        q.push_back(x%10);
        x/=10;
    }
    int len=q.size()-1;
    memset(f,-1,sizeof(f));
    return ddp(len,0,true,true);//
}
int a,b;

int main(){
    cin>>a>>b;
    cout<<cal(b)-cal(a-1);
    return 0;
}
