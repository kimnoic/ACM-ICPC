#include <bits/stdc++.h>
using namespace std;
int n;
char t[233];
int v[233];
int main(){
    cin>>n;
    cin>>t;
    for(int i=0;i<n;i++){
        int temp=t[i]-'0';
        v[temp]++;
    }
    if(v[0]&&(v[1]||v[2],v[3])){
        cout<<"YES";
        return 0;
    }
    int sum=0;
    if(v[1]) sum++;
    if(v[3]) sum++;
    if(v[7]) sum++;
    if(v[9]) sum++;
    if(sum>=3||(v[1]&&v[9])||(v[3]&&v[7])){
        cout<<"YES";
        return 0;
    }
    if(v[2]&&v[7]&&v[9]){
        cout<<"YES";
        return 0;
    }
    else if(v[4]&&v[3]&&v[9]){
        cout<<"YES";
        return 0;
    }
    else if(v[6]&&v[1]&&v[7]){
        cout<<"YES";
        return 0;
    }
    else if(v[8]&&v[1]&&v[3]){
        cout<<"YES";
        return 0;
    }
    else if(v[7]&&v[2]&&v[6]){
        cout<<"YES";
        return 0;
    }
    else if(v[9]&&v[2]&&v[4]){
        cout<<"YES";
        return 0;
    }
    else if(v[3]&&v[4]&&v[8]){
        cout<<"YES";
        return 0;
    }
    else if(v[1]&&v[6]&&v[8]){
        cout<<"YES";
        return 0;
    }
    cout<<"NO";
    return 0;
}
