#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;
const int N = 2000010;
char a[N],b[N],c[N];
int n,m;
int next[N],exa[N],exb[N];
int dis(int now,int sz){
    return min(now,sz-now-1);
}
void getnext(char *s){
    int len=strlen(s),cur=0;
    next[0]=len;
    while(cur<len && s[cur]==s[cur+1]) cur++;
    next[1]=cur;
    cur=1;
    for(int k=2;k<len;k++){
        int p=cur+next[cur]-1,L=next[k-cur];
        if(k+L-1>=p){
            int j=(p-k+1)>0?(p-k+1):0;
            while(k+j<len&&s[k+j]==s[j]) j++;
            next[k]=j;
            cur=k;
        }
        else {
            next[k]=L;
        }
    }
}
void exkmp(char *s1,char *s2,int *ex){
    getnext(s2);
    int l1=strlen(s1),l2=strlen(s2),cur=0;
    while(cur<min(l1,l2)&&s1[cur]==s2[cur]) cur++;
    ex[0]=cur;cur=0;
    for(int k=1;k<l1;k++){
        int p=cur+ex[cur]-1,L=next[k-cur];
        if(k+L-1>=p){
            int j=(p-k+1)>0?(p-k+1):0;
            while(k+j<l1&&j<l2&&s1[k+j]==s2[j])j++;
            ex[k]=j;
            cur=k;
        }
        else ex[k]=L;
    }
    reverse(a,a+2*n);
    reverse(c,c+m);
}
int minp(char *s){
    int i=0,j=1,k=0,t,len=strlen(s);
    while(i<len&&j<len&&k<len){
        t=s[(i+k)%len]-s[(j+k)%len];
        if(t==0)k++;
        else{
            if(t>0)i+=k+1;
            else j+=k+1;
            if(i==j)j++;
            k=0;
        }
    }
    return min(i,j);
}
int main(){
    scanf("%d%d",&n,&m);
    scanf("%s%s",a,b);
//    cin>>a>>b;
    int start=minp(b);
    for(int i=0,j=start;i<m;i++,j=(j+1)%m) c[i]=b[j];c[m]=0;
    for(int i=n;i<2*n;i++) a[i]=a[i-n];a[2*n]=0;
    exkmp(a,c,exa);
    exkmp(a,c,exb);
    reverse(exb,exb+n*2);
    int ans=-1;
    for(int i=0;i<n;i++)
        if(exa[i]==m||exa[i]+exb[i+m-1]==m-1){
            if(ans==-1) ans=i;
            else if(dis(i,n)<dis(ans,n)) ans=i;
        }
    cout<<c<<endl;
    for(int i=0,j=ans;i<n;i++,j=(j+1)%n) putchar(a[j]);
    puts("");
    return 0;
}
