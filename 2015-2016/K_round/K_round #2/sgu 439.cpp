#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e6+10;


int n,m;
int dis(int a,int b){
    return min(a,b-a-1);
}
int minp(char *s,int l){
    int i,j,k;
    i=0,j=1;k=0;
    while(i<l&&j<l){
        k=0;
        while(s[i+k]==s[j+k]&&k<l) k++;
        if(k==l) return i;
        if(s[i+k]>s[j+k]) if(i+k+1>j) i=i+k+1;
        else i=j+1;
        else if(j+k+1>i) j =j+k+1;
        else j=i+1;
    }
    if(i<l) return i;
    else return j;
}
void ekmp(char s[],char t[],int next[],int extend[]){
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
char x[maxn],y[maxn],c[maxn];
int next[maxn],extend[maxn],reextend[maxn];
int main(){
    cin>>n>>m;
    cin>>x;
    cin>>y;
    int start=minp(y,m);
    for(int i=0,j=start;i<m;i++,j=(j+1)%m) c[i]=y[j];c[m]=0;
    for(int i=n;i<n+n;i++) x[i]=x[i-n];
    x[n+n]=0;
    ekmp(x,c,next,extend);
    reverse(x,x+n*2);
    reverse(c,c+m);
    ekmp(x,c,next,reextend);

    reverse(reextend,reextend+n*2);
//    for(int i=0;i<2*n;i++){
//        cout<<reextend[i]<<endl;
//    }
    reverse(x,x+n*2);
    reverse(c,c+m);
    int ans=-1;
    for(int i=0;i<n;i++){
        if(extend[i]==m||extend[i]+reextend[i+m-1]==m-1){
            if(ans==-1) ans=i;
            else if(dis(i,n)<dis(ans,n)) ans=i;
        }
    }
    printf("%s\n",c);
    for(int i=0,j=ans;i<n;i++,j=(j+1)%n){
        printf("%c",x[j]);
    }
    /*
    for(int i=0;i<n;i++){
        ans[i]=x[i];
    }
    ans[n]=0;
    int p=minp(y,m);
    for(int i=0;i<m;i++){
        str[i]=y[(i+p)%m];
    }
    str[m]=0;
    cout<<str<<endl;
    ekmp(x,str,next,extend);
//    for(int i=0;i<n;i++) cout<<extend[i]<<endl;
    for(int i=0;i<m;i++){
        y[i]=str[m-1-i];
    }
    y[m]=0;
    for(int i=0;i<n;i++){
        str[i]=x[n-1-i];
    }
    x[n]=0;
    ekmp(str,y,next,reextend);
    int maxx=0;
    p=0;
//    for(int i=0;i<n;i++){
//        cout<<i<<" "<<reextend[i]<<endl;
//    }
    for(int i=0;i<n;i++){
//        cout<<"+ "<<i<<" "<<(n-(i+m)%n)%n<<endl;
        if(maxx>=m-1){
            break;
        }
        int temp=n-(i+m)%n;
        if(temp<0) temp+=n;
        else if(temp>=n) temp%=n;
        if(maxx<extend[i]+reextend[temp]){
            maxx=extend[i]+reextend[temp];
            p=i;
        }
//        cout<<maxx<<" "<<p<<endl;
    }
    for(int i=0;i<n;i++){
        cout<<ans[(i+p)%n];
    }
    */
    return 0;
}
