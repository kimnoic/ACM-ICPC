#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <queue>
#include <vector>
#include <stack>
#include <map>
#include <set>
using namespace std;
#define Max 233
int mp[Max][Max];
int n;
struct pt{
    int x,y;
}p[33];
bool check(int i,int j,int k){
    int minx=min(p[i].x,p[j].x);
    int maxx=max(p[i].x,p[j].x);
    int miny=min(p[i].y,p[j].y);
    int maxy=max(p[i].y,p[j].y);
    if(p[k].x>=minx&&p[k].x<=maxx&&p[k].y<=maxy&&p[k].y>=miny) return false;
    return true;
}
bool judge(int i,int j,int k){
    int minx=min(p[i].x,p[j].x);
    int maxx=max(p[i].x,p[j].x);
    int miny=min(p[i].y,p[j].y);
    int maxy=max(p[i].y,p[j].y);
    if(p[k].x<maxx&&p[k].x>minx&&p[k].y<maxy&&p[k].y>miny) return true;
    else return false;
}
int vis[Max];
int res;
int main(){
    while(cin>>n){
        if(n==0) break;
        memset(mp,0,sizeof(mp));
        memset(vis,0,sizeof(vis));
        res=0;
        for(int i=1;i<=n;i++){
            scanf("%d %d",&p[i].x,&p[i].y);
            mp[p[i].x][p[i].y]=i;
        }
        for(int i=1;i<=n;i++){
            //cout<<"i "<<i<<endl;
            vis[i]=1;
            for(int j=1;j<=n;j++){
                if(!vis[j]){
                    //cout<<"j "<<j<<endl;
                    if(p[i].x==p[j].x||p[i].y==p[j].y) continue;
                    vis[j]=1;
                    int tx=p[i].x-p[j].x;
                    int ty=p[i].y-p[j].y;
                    if(mp[p[i].x][p[i].y-ty]&&mp[p[i].x-tx][p[i].y]){
                        int k1=mp[p[i].x][p[i].y-ty];
                        int k2=mp[p[i].x-tx][p[i].y];
                        vis[k1]=1;
                        vis[k2]=1;
                        for(int k=1;k<=n;k++){
                            if(!vis[k]){
                                //cout<<"k "<<k<<endl;
                                vis[k]=1;
                                for(int y=1;y<=n;y++){
                                    if((!vis[y])&&p[y].x!=p[k].x&&p[k].y!=p[y].y){
                                        vis[y]=1;
                                        //cout<<"k "<<k<<endl;
                                        tx=p[k].x-p[y].x;
                                        ty=p[k].y-p[y].y;
                                        if(mp[p[k].x][p[k].y-ty]&&mp[p[k].x-tx][p[k].y]){
                                            int k3=mp[p[k].x][p[k].y-ty];
                                            int k4=mp[p[k].x-tx][p[k].y];
                                            if((!vis[k3])&&(!vis[k4])){
                                                if(check(i,j,k)&&check(i,j,y)&&check(i,j,k3)&&check(i,j,k4)&&check(y,k,i)&&check(y,k,j)&&check(y,k,k1)&&check(y,k,k2)){
                                                    int sum=abs((p[i].x-p[j].x)*(p[i].y-p[j].y));
                                                    sum+=abs((p[k].x-p[y].x)*(p[k].y-p[y].y));
                                                    res=max(res,sum);
                                                    //cout<<res<<endl;
                                                }
                                                else if((judge(i,j,k)&&judge(i,j,y))||(judge(y,k,i)&&judge(y,k,j))){
                                                    int sum=abs((p[i].x-p[j].x)*(p[i].y-p[j].y));
                                                    sum=max(sum,abs((p[k].x-p[y].x)*(p[k].y-p[y].y)));
                                                    res=max(res,sum);
                                                }
                                            }
                                        }
                                        vis[y]=0;
                                    }
                                }
                                vis[k]=0;
                            }
                        }
                        vis[k1]=0;
                        vis[k2]=0;
                    }
                    vis[j]=0;
                }
            }
            vis[i]=0;
        }
        if(res==0) cout<<"imp"<<endl;
        else cout<<res<<endl;
    }
    return 0;
}
