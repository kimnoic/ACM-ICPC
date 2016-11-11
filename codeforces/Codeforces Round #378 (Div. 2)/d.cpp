#include <bits/stdc++.h>
#define MP std::make_pair
std::map<std::pair<int,int>,int>mp;
std::map<std::pair<int,int>,int>rc;
int Min(int a,int b,int c){
    return std::min(std::min(a,b),c);
}
int n;
int main(){
    std::cin>>n;
    int a,b,c;
    int r=0;
    int x=0,y=0;
    for(int i=1;i<=n;i++){
        std::cin>>a>>b>>c;
        int flag=1;
        if(a>b) std::swap(a,b),flag=0;
        int temp=mp[MP(a,b)];
        int d=Min(a,b,temp+c);
        if(temp){
            if(r<d){
                x=rc[MP(a,b)];
                y=i;
                r=d;
            }
            if(c>temp){
                mp[MP(a,b)]=c;
                rc[MP(a,b)]=i;
            }
        }
        else {
            if(r<d){
                r=d;
                x=i;
                y=0;
            }
            mp[MP(a,b)]=c;
            rc[MP(a,b)]=i;
        }
        if(!flag) std::swap(a,b);
        flag=1;
        if(a>c) std::swap(a,c),flag=0;
        temp=mp[MP(a,c)];
        d=Min(a,c,temp+b);
        if(temp){
            int d=Min(a,c,temp+b);
            if(r<d){
                r=d;
                x=rc[MP(a,c)];
                y=i;
            }
            if(b>temp){
                mp[MP(a,c)]=b;
                rc[MP(a,c)]=i;
            }
        }
        else {
            if(r<d){
                r=d;
                x=i;
                y=0;
            }
            mp[MP(a,c)]=b;
            rc[MP(a,c)]=i;
        }
        if(!flag) std::swap(a,c);
        flag=1;
        if(b<c) std::swap(b,c),flag=0;
        temp=mp[MP(b,c)];
        d=Min(c,b,temp+a);
        if(temp){
            int d=Min(c,b,temp+a);
            if(r<d){
                r=d;
                x=rc[MP(c,b)];
                y=i;
            }
            if(a>temp){
                mp[MP(c,b)]=a;
                rc[MP(c,b)]=i;
            }
        }
        else {
            if(r<d){
                r=d;
                x=i;
                y=0;
            }
            mp[MP(c,b)]=a;
            rc[MP(c,b)]=i;
        }
        //std::cout<<i<<" "<<r<<std::endl;
    }
    if(y){
        std::cout<<2<<std::endl;
        std::cout<<x<<" "<<y;
    }
    else std::cout<<1<<std::endl<<x;
    return 0;
}
