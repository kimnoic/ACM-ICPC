#include<cstdio>
#include<cstring>
int n,m;
char a[1000010],b[10010];
int p[11111];
void getp(){
    p[1]=0;
    int i,j=0;
    for(i=2;i<=m;i++){
        while(j>0&&b[j+1]!=b[i]) j=p[j];
        if(b[j+1]==b[i]) j+=1;
        p[i]=j;
    }
}
int kmp()
{
    int i,j=0,cnt=0;
    for(i=1;i<=n;i++){
        while(j>0&&b[j+1]!=a[i]) j=p[j];
        if(b[j+1]==a[i]) j+=1;
        if(j==m){
             cnt++;
            j=p[j];

        }
    }
    return cnt;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s%s",b+1,a+1);
        m=strlen(b+1);
        n=strlen(a+1);
        getp();
        printf("%d\n",kmp());
    }
}
