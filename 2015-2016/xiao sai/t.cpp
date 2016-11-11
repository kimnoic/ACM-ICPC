#include <bits/stdc++.h>
using namespace std;

int main(){
    srand( (unsigned)time( NULL ) );
    //freopen("in.txt","w",stdout);
    int n=rand()%6+3;
    for(int i=1;i<=n;i++){
        cout<<(char)('a'+rand()%26);
    }
    return 0;
    return 0;
}
