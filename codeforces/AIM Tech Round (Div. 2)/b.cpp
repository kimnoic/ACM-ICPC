#include<bits/stdc++.h>
using namespace std;
#define Max 30

long long s[Max];long long sum=0;
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>s[i];
    sort(s+1,s+n+1);
    int cnt=1;
    for(int i=1;i<=n;i++)
        if(s[i]==s[i-1]){
            cnt++;
            for(int j=i-1;j>=1;j--)
                if(s[i]==s[j])
                    s[i]--;
            sort(s+1,s+i+1);
            cnt++;
        }

    for(int i=1;i<=n;i++)
        if(s[i]>0)
            sum+=s[i];
    if(cnt)
    cout<<sum;
    return 0;
}
