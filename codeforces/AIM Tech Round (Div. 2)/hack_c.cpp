#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int >v;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    sort(v.rbegin(),v.rend());
    long long int ans =0;
    set<int>S;
    for(int i=0;i<v.size();i++){
        int num=v[i];
        while(1){
            if(num==0){
                break;
            }
            if(S.find(num)==S.end()){
                break;
            }
            num--;
        }
        ans+=num;
        S.insert(num);
    }
    cout<<ans;
    return 0;
}
