#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <vector>
using namespace std;
#define Max 10010
int nnext[Max];

void preKMP(int x[],int m){
    int i,j;
    memset(nnext,0,sizeof(nnext));
    j=nnext[0]=-1;
    i=0;
    while(i<m){
        while(-1!=j && x[i]!=x[j])j=nnext[j];
        if(x[++i]==x[++j])nnext[i]=nnext[j];
        else nnext[i]=j;
    }
}
int a[Max],b[1000010];
int T,n,m;
int main(){
    cin>>T;
    while(T--){
        cin>>n>>m;
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        for(int i=0;i<m;i++){
            scanf("%d",&b[i]);
        }
        preKMP(b,m);
        int i=0,j=0;
        int flag=1;
        while(i<n){
            while(j!=-1&&a[i]!=b[j]) j=nnext[j];
            i++;j++;
            if(j>=m){
                cout<<j<<endl;
                flag=0;
                break;
            }
        }
        if(flag)
        cout<<-1<<endl;
    }
    return 0;
}
