#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
#include <vector>
#include <stack>
#include <set>
#include <map>
using namespace std;
#define Max 1000100
int vis[Max];
int main(){
    int n=990528;
    for(int i=1;;i++){
        if((i*(i+1)/2)>n) break;
        vis[i*(i+1)/2]++;
    }

    for(int i=1;;i++){
        if(i*(2*i-1)>n) break;
        vis[i*(2*i-1)]++;
    }
    for(int i=1;;i++){
        if(i>n) break;
        if(i%400==0) vis[i]++;
        else if(i%4==0&&i%100!=0) vis[i]++;
    }
    for(int i=2016;;i++){
        if(i>n) break;
        if(vis[i]==3)
        cout<<i<<endl;
    }
    return 0;
}
