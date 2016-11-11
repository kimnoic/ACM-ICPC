#include <set>
#include <cstdio>
#include <iostream>
#include <map>

using namespace std;
#define Max 100100
set <int> f;
map <int ,int> l,r;
int n;
set<int>::iterator it;

int t;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>t;
        if(i==1){
            f.insert(t);
        }
        else {
            it=f.lower_bound(t);
            if(it==f.end()) r[*--it]=t;
            else {
                if(!l[*it]) l[*it]=t;
                else r[*--it]=t;
            }
            cout<<*it<<" ";
            f.insert(t);
        }
    }
    return 0;
}

