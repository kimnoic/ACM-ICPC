#include <bits/stdc++.h>
__int64 *primarr,*v,q=1,p=1;
__int64 pi(__int64 n,__int64 p[],__int64 len){
    __int64 i=0,flag=0;
    for(i=len-i;i;i--){if(p[i]<n) {
            flag=1;break;
        }
    }
    if(flag) return i+1;
    return 0;
}
long long cnt=0;
__int64 phi(__int64 x,__int64 a,__int64 m){
    if(a==m) return(x/q)*p+v[x%q];
    if (x<primarr[a-1])
        return 1;
    cnt++;
    return -phi(x/primarr[a-1],a-1,m)+phi(x,a-1,m);
}
const int maxn=10000;
__int64 prime(__int64 n){
    char *mark;
    __int64 mark_len,count=0,i,j,m=7,sum=0,s=0,len,len2,len3;
    mark_len=(n<maxn)?maxn+2:((__int64)exp(2.0/3*log(n))+1);
    mark=(char *)malloc(sizeof(char)*mark_len);
    memset(mark,0,sizeof(char)*mark_len);
    for (i=2;i<(__int64)sqrt(mark_len);i++){
        if(mark[i]) continue;
        for(j=i+i;j<mark_len;j+=i)
            mark[j]=1;
    }
    mark[0]=mark[1]=1;
    for(i=0;i<mark_len;i++)
        if (!mark[i])
            count++;
    primarr=(__int64 *)malloc(sizeof(__int64)*count);
    j=0;
    cnt=0;
    for(i=0;i<mark_len;i++)
        if(!mark[i])
            primarr[j++]=i;

    if(n<maxn)
        return pi(n, primarr, count);
    len = pi((__int64)exp(1.0 / 3 * log(n)), primarr, count);
    len2 = pi((__int64)sqrt(n), primarr, count);
    len3 = pi(mark_len - 1, primarr, count);
    j = mark_len - 2;
    for (i = (__int64)exp(1.0 / 3 * log(n)); i <= (__int64)sqrt(n); i++) {
        if (!mark[i]) {
            while (i * j > n) {
                if (!mark[j])
                    s++;
                j--;
            }
            sum += s;
        }
    }
    free(mark);
    sum = (len2 - len) * len3 - sum;
    sum += (len * (len - 1) - len2 * (len2 - 1)) / 2;
    if (m > len)
        m = len;
    for (i = 0; i < m; i++) {
        q *= primarr[i];
        p *= primarr[i] - 1;
    }
    v = (__int64 *)malloc(sizeof(__int64) * q);
    for (i = 0; i < q; i++)
        v[i] = i;
    for (i = 0; i < m; i++)
        for (j = q - 1; j >= 0; j--)
            v[j] -= v[j / primarr[i]];

    sum = phi(n, len, m) - sum + len - 1;
    free(primarr);
    free(v);
    return sum;
}

int main(){
    __int64 n,c;
    while(std::cin>>n){
        if(n==2){std::cout<<1<<std::endl;continue;}
        else if(n==3) {std::cout<<2<<std::endl;continue;}
        p=1;
        q=1;
        std::cout<<prime(n)<<std::endl;
    }
    return 0;
}
