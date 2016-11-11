#include <bits/stdc++.h>
using namespace std;
int n;
const int maxn=100010;
map<string,int>mp,mpp;
map<int,string>h1,h2;
struct pt{
    int p,sum;
}edge;
vector<pt>tr[maxn],trr[maxn];
map<pair<string,string>,int>f1,f2;
pair<string,string>p;
int deg1[maxn],deg2[maxn];
string s1,s2;
void init(int u){

}
void dfs(int u,int v){

}
int main(){
    cin>>n;
    int top1=0,top2=0;
    int a,b;
    memset(deg1,0,sizeof(deg1));
    memset(deg2,0,sizeof(deg2));
    for(int i=1;i<n;i++){
        cin>>s1>>s2;
        p=make_pair(s1,s2);
        if(f1[p]) continue;
        if(!mp[s1]){
            mp[s1]=++top1;
            a=top1;
            h1[a]=s1;
        }
        else a=mp[s1];
        if(!mp[s2]){
            mp[s2]=++top1;
            b=top1;
            h1[b]=s2;
        }
        else b=mp[s2];
        tr[a].p.push_back(b);
        tr[b].p.push_back(a);


        deg1[a]++;
        deg1[b]++;
        f1[p]=1;
    }
    int st1,st2;
    for(int i=1;i<=n;i++){
        if(deg1[i]==1){
            st1=i;
        }
        break;
    }
    for(int i=1;i<n;i++){
        cin>>s1>>s2;
        p=make_pair(s1,s2);
        if(f2[p]) continue;
        if(!mpp[s1]){
            mpp[s1]=++top2;
            a=top2;
            h2[a]=s1;
        }
        else a=mpp[s1];
        if(!mpp[s2]){
            mpp[s2]=++top2;
            b=top2;
            h2[b]=s2;
        }
        else b=mpp[s2];
        trr[a].p.push_back(b);
        trr[b].p.push_back(a);
        deg2[a]++;
        deg2[b]++;
        f2[p]=1;
    }
    for(int i=1;i<=n;i++){
        if(deg2[i]==1) {
            st2=i;
            break;
        }
    }
    dfs(st1,st2);
    return 0;
}
/*
string str1, str2;

string min_pre(string str){
      vector<string> box;
      string ret = "";
      int equal = 0, st = 0;
      for(int i = 0; i < str.size(); i++){
           if(str[i] == '0') equal++;
           else equal--;
           if(equal == 0){
                if(i - 1 > st + 1){
                    box.push_back("0" + min_pre(str.substr(st + 1,i - 1 - st)) + "1");
                }else box.push_back("01");
                st = i + 1;
           }
      }
      sort(box.begin(), box.end());
      for(int i = 0; i < box.size(); i++) ret += box[i];
      return ret;
}

int main(){
      //freopen("poj 1635.in","r",stdin);
      int ca;
      scanf("%d", &ca);
      while(cin >> str1 >> str2){
           if(min_pre(str1) == min_pre(str2)) printf("same\n");
           else printf("different\n");
      }
}
*/
