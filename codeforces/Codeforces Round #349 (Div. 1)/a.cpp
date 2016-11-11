#include <bits/stdc++.h>
using namespace std;
string s;
const int maxn=1e4+5;
int vis[maxn];
set<string>st;
set<string>::iterator it;
int main(){
    cin>>s;
    int len=s.size();
    vis[len]=1;
    for(int i=len-1;i>4;i--){
        if(vis[i+2]!=0&&(vis[i+2]!=2||s.substr(i,2)!=s.substr(i+2,2))){
            st.insert(s.substr(i,2));
            vis[i]+=2;
        }
        if(vis[i+3]){
            if(vis[i+3]!=3||s.substr(i,3)!=s.substr(i+3,3)){
                st.insert(s.substr(i,3));
                vis[i]+=3;
            }
        }
    }
    cout<<st.size()<<endl;
    for(it=st.begin();it!=st.end();it++){
        cout<<*it<<endl;
    }
    return 0;
}
/*
gvtgnjyfvnuhagulgmjlqzpvxsygmikofsnvkuplnkxeibnicygpvfvtebppadpdnrxjodxdhxqceaulbfxogwrigstsjudhkgwkhseuwngbppisuzvhzzxxbaggfngmevksbrntpprxvcczlalutdzhwmzbalkqmykmodacjrmwhwugyhwlrbnqxsznldmaxpndwmovcolowxhj
*/
