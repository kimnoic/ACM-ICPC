void EKMP(char s[],char t[],int next[],int extend[]){
    int i,j,p,L;
    int lens=strlen(s);
    int lent=strlen(t);
    next[0]=lent;
    j=0;
    while(j+1<lent && t[j]==t[j+1])j++;
    next[1]=j;

    int a=1;
    for(i=2;i<lent;i++){
        p=next[a]+a-1;
        L=next[i-a];
        if(i+L<p+1)next[i]=L;
        else{
            j=max(0,p-i+1);
            while(i+j<lent && t[i+j]==t[j])j++;
            next[i]=j;
            a=i;
        }
    }

    j=0;
    while(j<lens && j<lent && s[j]==t[j])j++;
    extend[0]=j;
    a=0;
    for(i=1;i<lens;i++){
        p=extend[a]+a-1;
        L=next[i-a];
        if(L+i<p+1)extend[i]=L;
        else{
            j=max(0,p-i+1);
            while(i+j<lens && j<lent && s[i+j]==t[j])j++;
            extend[i]=j;
            a=i;
        }
    }
}

const int MAXN=500010;
char str1[MAXN],str2[MAXN];
int sum[MAXN];
int v[27];
int next[MAXN];
int extend1[MAXN],extend2[MAXN];

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        for(int i=0;i<26;i++)
            scanf("%d",&v[i]);
        scanf("%s",str1);
        int len=strlen(str1);
        sum[0]=0;
        for(int i=0;i<len;i++){
            sum[i+1]=sum[i]+v[str1[i]-'a'];
            str2[i]=str1[len-1-i];
        }
        str2[len]=0;
        EKMP(str2,str1,next,extend1);
        EKMP(str1,str2,next,extend2);
        int ans=-10000;
        //需要保证分成两部分，所以i从1到len-1
        for(int i=1;i<len;i++){
            int tmp=0;
            if(i+extend1[i]==len){
                tmp+=sum[len-i];
            }
            int pos=len-i;
            if(pos+extend2[pos]==len){
                tmp+=sum[len]-sum[pos];
            }
            if(tmp>ans)ans=tmp;
        }
        printf("%d\n",ans);
    }
    return 0;
}
