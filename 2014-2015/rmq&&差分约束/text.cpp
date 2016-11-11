#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>

using namespace std;

const int N=50010;
const int INF=0x3f3f3f3f;

int num[N],dpmin[N][20],dpmax[N][20];
int n,q;

void create_Dpmin(){
    int i,j;
    for(i=1;i<=n;i++)
        dpmin[i][0]=num[i];
    int sum=log((double)(n+1))/log(2.0);
    for(j=1;j<=sum;j++)
        for(i=1;i+(1<<j)-1<=n;i++)
            dpmin[i][j]=min(dpmin[i][j-1],dpmin[i+(1<<(j-1))][j-1]);
}

void create_Dpmax(){
    int i,j;
    for(i=1;i<=n;i++)
        dpmax[i][0]=num[i];
    int sum=log((double)(n+1))/log(2.0);//cout<<" sun is "<<sum<<endl;
    for(j=1;j<=sum;j++)
        for(i=1;i+(1<<j)-1<=n;i++)
            dpmax[i][j]=max(dpmax[i][j-1],dpmax[i+(1<<(j-1))][j-1]);
}

int getmax(int l,int r){
    int k=(int)(log((double)(r-l+1))/log(2.0));//cout<<"this is"<<k<<endl;
    return max(dpmax[l][k],dpmax[r-(1<<k)+1][k]);
}

int getmin(int l,int r){
    int k=(int)(log((double)(r-l+1))/log(2.0));//cout<<k<<endl;
    return min(dpmin[l][k],dpmin[r-(1<<k)+1][k]);
}

int main(){

    //freopen("input.txt","r",stdin);

    while(~scanf("%d%d",&n,&q)){
        for(int i=1;i<=n;i++)
            scanf("%d",&num[i]);
        create_Dpmin();
        create_Dpmax();
        int l,r;
        while(q--){
            scanf("%d%d",&l,&r);
            printf("%d\n",getmax(l,r)-getmin(l,r));
        }
    }
    return 0;
}
