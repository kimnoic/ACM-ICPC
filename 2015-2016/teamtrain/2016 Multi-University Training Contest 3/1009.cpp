#include <bits/stdc++.h>
const int maxn=5050;
const int maxx=20010;
int a[maxn],p[maxn],b[maxn*2];
void Manacher(int *p,int *str,int len){
    int mx=0;
    int idx=0;
    for(int i=1; i<len; i++){
        p[i]=mx>i?std::min(p[2*idx-i],mx-i):1;
        while(str[i+p[i]]==str[i-p[i]])
        p[i]++;
        if(i+p[i]>mx){
            mx=i+p[i];
            idx=i;
        }
    }
}
int T,n;
int main(){
    srand(time(0));
    while(~scanf("%d",&n)){
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        b[0]=maxx;
        for(int i=0;i<=n;i++){
            b[2*i+1]=0;
            b[2*i+2]=a[i];
        }
        int len=n*2+2;
        memset(p,0,sizeof(p));
        Manacher(p,b,len);
        int ans1,ans2;
        ans1=rand()%5;
        ans2=0;
        ans2=rand()%ans1;
        std::cout<<ans1<<" "<<ans2<<std::endl;
//        for(int i=0;i<len;i++){
//            std::cout<<p[i]<<" ";
//        }
    }
    return 0;
}
/*
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
using namespace std;
#define maxx 20000050
char str[2*maxx];
char s[maxx];
int p[maxx];
void Manacher(int *p,char *str,int len)
{
    int mx=0;
    int idx=0;
    for(int i=1; i<len; i++)
    {
        p[i]=mx>i?min(p[2*idx-i],mx-i):1;
        while(str[i+p[i]]==str[i-p[i]])
        p[i]++;
        if(i+p[i]>mx)
        {
            mx=i+p[i];
            idx=i;
        }
    }
}
int main()
{
    while(scanf("%s",s)!=EOF)
    {
        int nn=strlen(s);//需要定义一个变量nn，如果每次调用strlen(s)，时间就会长
        int n=2*nn+2;
        str[0]='$';
        for(int i=0; i<=nn; i++)
        {
            str[2*i+1]='#';
            str[2*i+2]=s[i];
        }
        Manacher(p,str,n);
        int ans=1;
        for(int i=0; i<n; i++){cout<<p[i]<<" ";
                    ans=max(ans,p[i]);}
                    cout<<endl;
        printf("%d\n",ans-1);

    }
    return 0;
}
/*
aaaa

abab
*/
