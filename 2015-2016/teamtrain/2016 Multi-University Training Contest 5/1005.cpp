#include <bits/stdc++.h>
const int maxn=2e6+100;
const int mod=1000000007;
char str[maxn],s[maxn];
int p[maxn];
int n;
int v[maxn];
struct tree{
    int l,r;
    int sum,add;
}tree[maxn>>2];
#define LL long long
void pushup(LL x)
{
  LL tmp=2*x;
  tree[x].sum=tree[tmp].sum+tree[tmp+1].sum;
}


void pushdown(LL x)
{
  LL tmp=2*x;
  tree[tmp].add+=tree[x].add;
  tree[tmp+1].add+=tree[x].add;
  tree[tmp].sum+=tree[x].add*(tree[tmp].r-tree[tmp].l+1);
  tree[tmp+1].sum+=tree[x].add*(tree[tmp+1].r-tree[tmp+1].l+1);
  tree[x].add=0;
}

void build(int l,int r,int x)
{
  tree[x].l=l;
  tree[x].r=r;
  tree[x].add=0;
  if(l==r)
  {
    tree[x].sum=0;
    return ;
  }
  int tmp=x<<1;
  int mid=(l+r)>>1;
  build(l,mid,tmp);
  build(mid+1,r,tmp+1);
  pushup(x);	 //����ڽ����Ĺ����и�sum��ֵ���ǵú���Ҫpushup
}

void update(LL l,LL r,LL c,LL x)
{
  if(r<tree[x].l||l>tree[x].r)
    return ;
  if(l<=tree[x].l&&r>=tree[x].r)
  {
    tree[x].add+=c;
    tree[x].sum+=c*(tree[x].r-tree[x].l+1);
    return ;
  }
  if(tree[x].add)
    pushdown(x);
  LL tmp=x<<1;
  update(l,r,c,tmp);	//  !!!
  update(l,r,c,tmp+1);
  pushup(x);
}
int res;
void query(LL l,LL r,LL x)
{
  if(r<tree[x].l||l>tree[x].r)		 //Ҫ���µ����䲻�ڸ�������
    return ;
  if(l<=tree[x].l&&r>=tree[x].r)	  //Ҫ������������˸�����
  {
    res+=tree[x].sum;
    return ;
  }
  if(tree[x].add)
    pushdown(x);
  LL tmp=x<<1;
  LL mid=(tree[x].l+tree[x].r)>>1;
  if(r<=mid)
    query(l,r,tmp);
  else if(l>mid)
    query(l,r,tmp+1);
  else
  {
    query(l,mid,tmp);
    query(mid+1,r,tmp+1);
  }
//	pushup(x);
}
void init(){
    int i, j, k;
    str[0] = '$';
    str[1] = '#';
    for(i=0; i<n; i++)
    {
        str[i*2+2] = s[i];
        str[i*2+3] = '#';
    }
    n = n*2+2;
    s[n] = 0;
}
void kp(){
    int i;
    int mx = 0;
    int id;
    for(i=n; str[i]!=0; i++)
        str[i] = 0;
    for(i=1; i<n; i++)
    {
        if( mx > i )
            p[i] = std::min( p[2*id-i], p[id]+id-i );
        else
            p[i] = 1;
        for(; str[i+p[i]] == str[i-p[i]]; p[i]++)
            ;
        if( p[i] + i > mx )
        {
            mx = p[i] + i;
            id = i;
        }
    }
}
long long cal(long long x){
    return x*(x-1)/2%mod;
}
long long ans;
int main(){
    while(~scanf("%s",s)){
        n=strlen(s);
        build(1,n,1);
        init();
        kp();
        ans=0;
        memset(v,0,sizeof(v));
        for(int i=2;i<=n;i++){
//            std::cout<<p[i]<<std::endl;
            if(i%2==0){
                if(p[i]>2){
//                    std::cout<<i/2-p[i]/2+1<<" "<<i/2+p[i]/2-1<<std::endl;
                    update(i/2-p[i]/2,i/2+p[i]/2,1,1);
                }
            }
            else {
                if(p[i]>1){
//                    std::cout<<i/2-p[i]/2+1<<" "<<i/2+p[i]/2<<std::endl;
                    update(i/2-p[i]/2+1,i/2+p[i]/2,1,1);
                }
            }
        }
        for(int i=1;i<n/2;i++){
            res=0;
            query(i,i,1);
//            std::cout<<i<<" "<<res<<std::endl;
            ans+=cal((long long)(res));
        }
        ans%=mod;
        std::cout<<ans<<std::endl;
    }
    return 0;
}
