#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <queue>
#include <vector>
#include <stack>
#include <set>
#include <map>
using namespace std;
#define Max 100010
struct pt{
    int val,p;
}p[Max];
bool cmp(pt a,pt b){
    return a.val<b.val;
}
int segment[Max*4];
int val[Max];
void build(int k,int left,int right){
    if(left==right){
        segment[k]=1;
        return ;
    }
    else {
        int mid=(left+right)/2;
        build(k*2,left,mid);
        build(k*2+1,mid+1,right);
        segment[k]=segment[k*2]+segment[k*2+1];
    }
}
void cal(int k,int left,int right,int pos,int v){
    if(left==right){
        val[left]=v;
        segment[k]=0;
        return ;
    }
    int mid=(left+right)/2;
    if(pos<=segment[k*2]){
        cal(k*2,left,mid,pos,v);
    }
    else {
        cal(k*2+1,mid+1,right,pos-segment[k*2],v);
    }segment[k]=segment[k*2]+segment[k*2+1];

}
int main(){
    int T;
    cin>>T;
    int _case=0;
    while(T--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            scanf("%d%d",&p[i].val,&p[i].p);
        }
        printf("Case #%d: ",++_case);
        sort(p+1,p+n+1,cmp);
        build(1,1,n);
        int flag=0;
        for(int i=1;i<=n;i++){
            //cout<<n<<" "<<i<<" "<<p[i].p<<endl;
            int temp=n-i-p[i].p;
            //cout<<temp<<endl;
            if(temp<0){
                flag=1;
                break;
            }
            else {
                if(p[i].p>temp){
                    p[i].p=temp;
                }
                cal(1,1,n,p[i].p+1,p[i].val);
            }
        }
        if(flag){
            printf("impossible\n");
        }
        else {
            printf("%d",val[1]);
            for(int i=2;i<=n;i++){
                printf(" %d",val[i]);
            }
            printf("\n");
        }
    }
    return 0;
}
