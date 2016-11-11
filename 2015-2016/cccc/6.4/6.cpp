#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <queue>
#include <stack>
#include <vector>
#include <set>
#include <map>
using namespace std;
int n,a;
int suma,sumb;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a;
        if(a%2==0) suma++;
        else sumb++;
    }
    cout<<sumb<<" "<<suma;
    return 0;
}
