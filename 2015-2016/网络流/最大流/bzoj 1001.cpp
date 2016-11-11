#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <string.h>
using namespace std;

const int MAXN=100100;//���������ֵ
const int MAXM=880010;//���������ֵ
const int INF=0x3f3f3f3f;

struct Node
{
    int from,to,next;
    int cap;
}edge[MAXM];
int tol;
int head[MAXN];
int dep[MAXN];
int gap[MAXN];//gap[x]=y :˵������������dep[i]==x�ĸ���Ϊy
//n���ܵĵ�ĸ���������Դ��ͻ��

void init()
{
    tol=0;
    memset(head,-1,sizeof(head));
}

void addedge(int u,int v,int w)
{
    edge[tol].from=u;
    edge[tol].to=v;
    edge[tol].cap=w;
    edge[tol].next=head[u];
    head[u]=tol++;

    edge[tol].from=v;
    edge[tol].to=u;
    edge[tol].cap=w;
    edge[tol].next=head[v];
    head[v]=tol++;

}

void BFS(int start,int end)
{
    memset(dep,-1,sizeof(dep));
    memset(gap,0,sizeof(gap));
    gap[0]=1;
    int que[MAXN];
    int front,rear;
    front=rear=0;
    dep[end]=0;
    que[rear++]=end;
    while(front!=rear)
    {
        int u=que[front++];
        if(front==MAXN)front=0;
        for(int i=head[u];i!=-1;i=edge[i].next)
        {
            int v=edge[i].to;
            if(dep[v]!=-1)continue;
            que[rear++]=v;
            if(rear==MAXN)rear=0;
            dep[v]=dep[u]+1;
            ++gap[dep[v]];
        }
    }
}
int n;
int SAP(int start,int end)
{
    int res=0;
    BFS(start,end);
    int cur[MAXN];
    int S[MAXN];
    int top=0;
    memcpy(cur,head,sizeof(head));
    int u=start;
    int i;
    //cout<<n<<endl;
    while(dep[start]<n)
    {
        //cout<<"asdf";
        if(u==end)
        {
            int temp=INF;
            int inser;
            for(i=0;i<top;i++)
               if(temp>edge[S[i]].cap)
               {
                   temp=edge[S[i]].cap;
                   inser=i;
               }
            for(i=0;i<top;i++)
            {
                edge[S[i]].cap-=temp;
                edge[S[i]^1].cap+=temp;
            }
            res+=temp;
            top=inser;
            u=edge[S[top]].from;
        }
        if(u!=end&&gap[dep[u]-1]==0)//���ֶϲ㣬������·
          break;
        for(i=cur[u];i!=-1;i=edge[i].next)
           if(edge[i].cap!=0&&dep[u]==dep[edge[i].to]+1)
             break;
        if(i!=-1)
        {
            cur[u]=i;
            S[top++]=i;
            u=edge[i].to;
        }
        else
        {
            int min=n;
            for(i=head[u];i!=-1;i=edge[i].next)
            {
                if(edge[i].cap==0)continue;
                if(min>dep[edge[i].to])
                {
                    min=dep[edge[i].to];
                    cur[u]=i;
                }
            }
            --gap[dep[u]];
            dep[u]=min+1;
            ++gap[dep[u]];
            if(u!=start)u=edge[S[--top]].from;
        }
    }
    return res;
}
int m;
int main(){
    cin>>n>>m;
    if(n==1||m==1){
        if(n==1) swap(n,m);
        int ans=INF;
        for(int i=1;i<=n;i++){
            int v;
            cin>>v;
            ans=(v,ans);
        }
        if(ans!=INF)
            cout<<ans;
        else cout<<0;
        return 0;
    }
    init();
    for(int i=1;i<=n;i++){
        for(int j=1;j<m;j++){
            int v;
            scanf("%d",&v);
            int num=(i-1)*m+j;
            addedge(num,num+1,v);
            //cout<<num<<" "<<num+1<<" "<<v<<endl;
        }
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<=m;j++){
            int v;
            scanf("%d",&v);
            int num=(i-1)*m+j;
            addedge(num,num+m,v);
            //cout<<num<<" "<<num+m<<" "<<v<<endl;
        }
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            int v;
            scanf("%d",&v);
            int num=(i-1)*m+j;
            addedge(num,num+m+1,v);
            //cout<<num<<" "<<num+m+1<<" "<<v<<endl;
        }
    }
    n=n*m;
    //cout<<n<<endl;
    cout<<SAP(1,n)<<endl;
    return 0;
}

