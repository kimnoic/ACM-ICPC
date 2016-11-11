#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <queue>
#include <vector>
#include <stack>
#include <set>
#include <map>
using namespace std;
#define Max 1010
int n;
char s[Max];
int sum1,sum2,res,ans;
int main(){
    cin>>n;
    while(n--){
        sum1=0;
        sum2=0;
        res=0;
        ans=0;
        scanf("%s",s);
        int len=strlen(s);
        for(int i=0;i<len;i++){
            if(s[i]=='*') sum1++;
            else sum2++;
        }
        if(sum1==0){
            cout<<"0"<<endl;
            continue;
        }
        else if(sum2==0){
            cout<<sum1+1<<endl;
            continue;
        }
        //cout<<"asdf"<<endl;
        int cnt=sum1-sum2+1;
        cnt=max(cnt,0);
        ans=cnt;
        sum1=0,sum2=cnt;
        for(int i=0;i<len;i++){
            if(s[i]=='*'){
                sum1++;
            }
            else {
                sum2++;
            }
            if(sum1+1>sum2){
                sum1--;
                sum2++;
                ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
