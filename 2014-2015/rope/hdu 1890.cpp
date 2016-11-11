#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <ext/rope>
using namespace std;
using namespace __gnu_cxx;
#define Max 100010
int val[Max],n,pos[Max];

rope<int>q;
int main(){
    while(~scanf("%d"),&n){
        for(int i=1;i<=n;i++){
            scanf("%d",&val[i]);
            pos[i]=i;
        }
    }
    return 0;
}
