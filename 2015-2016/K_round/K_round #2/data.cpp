#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("data.txt","w",stdout);
    srand((unsigned)(time(NULL)));
    int n=rand()%233;
    for(int i=1;i<=n;i++){
        cout<<(char)('a'+rand()%26);
    }
    return 0;
}
