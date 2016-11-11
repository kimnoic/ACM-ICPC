#include<stdio.h>
#include<string.h>
#include<algorithm>
#include <iostream>
#define ll __int64
using namespace std ;
const int maxn = 511111 ;

int p[maxn] ;
int min ( int a , int b ) { return a < b ? a : b ; }
int dp[25][maxn] , f[maxn] , fuck , n , l[maxn] , r[maxn] ;
ll ans1 , ans2 , d[maxn] ;

ll get ( int n ) {
    ll i = 0 ;
    if ( n == 0 ) i = 1 ;
    while ( n ) {
        i ++ ;
        n /= 10 ;
    }
    return i + 1 ;
}

struct Suf{
    int wa[maxn] , wb[maxn] , ws[maxn] , wv[maxn] ;
    int rank[maxn] , hei[maxn] , sa[maxn] ;

    int cmp ( int *r , int i , int j , int l ){ return r[i] == r[j] && r[i+l] == r[j+l] ; }

    void da ( int *r , int n , int m ){
            int *x = wa , *y = wb , *t ;
        int i , j , k , p ;
        for ( i = 0 ; i < m ; i ++ ) ws[i] = 0 ;
        for ( i = 0 ; i < n ; i ++ ) ws[x[i]=r[i]] ++ ;
        for ( i = 1 ; i < m ; i ++ ) ws[i] += ws[i-1] ;
        for ( i = n - 1 ; i >= 0 ; i -- ) sa[--ws[x[i]]] = i ;
        for ( j = 1 , p = 1 ; p < n ; j *= 2 , m = p ) {
//            cout<<"p "<<p<<endl;
            for ( p = 0 , i = n - j ; i < n ; i ++ ) y[p++] = i ;

            for ( i = 0 ; i < n ; i ++ ) if ( sa[i] >= j ) y[p++] = sa[i] - j ;
            for ( i = 0 ; i < m ; i ++ ) ws[i] = 0 ;
            for ( i = 0 ; i < n ; i ++ ) ws[x[i]] ++ ;
            for ( i = 1 ; i < m ; i ++ ) ws[i] += ws[i-1] ;
            for ( i = n - 1 ; i >= 0 ; i -- ) sa[--ws[x[y[i]]]] = y[i] ;cout<<p<<endl;
            for ( t = x , x = y , y = t ,x[sa[0]] = 0 , p = 1 , i = 1 ; i < n ; i ++ )
                x[sa[i]] = cmp ( y , sa[i-1] , sa[i] , j ) ? p - 1 : p ++ ;
//            cout<<p<<endl;
        }
        k = 0 ;
        for ( i = 1 ; i < n ; i ++ ) rank[sa[i]] = i ;
        for ( i = 0 ; i < n - 1 ; hei[rank[i++]] = k )
            for ( k ? k -- : 0 , j = sa[rank[i]-1] ; r[i+k] == r[j+k] ; k ++ ) ;
    }
    /*
    void rmq ( int n ) {
        int i , j ;
        for ( i = 1 ; i <= n ; i ++ ) {dp[0][i] = hei[i] ;if(dp[0][i]) cout<<"dp "<<dp[0][i]<<endl;}
        for ( i = 1 ; i <= 20 ; i ++ )
            for ( j = 1 ; j + ( 1 << i ) - 1 <= n ; j ++ )
                dp[i][j] = min ( dp[i-1][j] , dp[i-1][j+(1<<(i-1))] ) ;
        //if(dp[i][j]!=0) cout<<"dp"<<dp[i][j]<<endl;
    }*/
    void rmq(int n){
    int i,j;
    for(i=1;i<=n;i++) {dp[0][i]=hei[i];if(dp[0][i]) cout<<"dp "<<dp[0][i]<<endl;}
    for(i=1;i<=20;i++){
        for(j=1;j+(1<<j)-1<=n;j++){
            dp[i][j]=min(dp[i-1][j],dp[i-1][j+(1<<(i-1))]);
            //if(dp[i][j]!=0)cout<<"dp "<<dp[i][j]<<endl;
        }
    }
}
/*
    int query ( int l , int r ) {
        if ( l > r ) swap ( l , r ) ;
        l ++ ;//要从height[l+1]到height[r]之间求最小值
        if ( l == r ) return dp[0][l] ;
        int k = r - l + 1 ;
        return min ( dp[f[k]][l] , dp[f[k]][r-(1<<f[k])+1] ) ;
    }*/
    int query(int l,int r){
    if(l>r) swap(l,r);
    l++;
    if(l==r) return dp[0][l];
    int k=r-l+1;
    return min(dp[f[k]][l],dp[f[k]][r-(1<<f[k])+1]);
}
/*
    void solve () {
        int i , j , k ;
        for ( i = 2 ; i <= n ; i ++ ) {
            ll add ;
            if ( l[i] == l[i-1] ) add = min ( d[i] , d[i-1] ) ;
            else add = query ( rank[l[i-1]] , rank[l[i]] ) ;
//            printf ( "add = %I64d , d1 = %I64d , d2 = %I64d\n" , add , d[i-1] , d[i] ) ;
            add = min ( add , min ( d[i] , d[i-1] ) ) ;
            cout<<"add "<<add<<endl;
            ans2 += get ( add ) ;
    //        printf ( "add = %I64d\n" , d[i] - add + 1 ) ;
            ans2 += (ll) d[i] - add + 1 ;
    //        printf ( "ans2 = %I64d\n" , ans2 ) ;
            cout<<"i "<<ans2<<endl;
        }
    }*/
    void solve(){
    int i,j,k;
    for(i=2;i<=n;i++){
        long long add;
        if(l[i]==l[i-1]) add=min(d[i],d[i-1]);
        else add=query(rank[l[i-1]],rank[l[i]]);
        add=min(add,min(d[i],d[i-1]));
        cout<<"add "<<add<<endl;
        ans2+=get(add);
        cout<<ans2<<endl;
        ans2+=(long long)d[i]-add+1;
        cout<<"i "<<ans2<<endl;
    }
}

} arr ;

char s1[maxn] ;
int s[maxn] ;

int main () {
    int cas , i , j , ca = 0 ;
    /*
    j = 0 ;
    for ( i = 1 ; i < maxn - 1111 ; i ++ ) {
        if ( i > 1 << j + 1 ) j ++ ;
        f[i] = j ;
    }
    */
    for(int i=1,j=0;i<maxn-1111;i++){
        if(i > 1 << j + 1) j++;
        f[i]=j;
    }
    while ( scanf ( "%s" , s1 ) != EOF ) {
        ans1 = ans2 = 0 ;
        int len = strlen ( s1 ) ;
        scanf ( "%d" , &n ) ;
        for ( i = 1 ; i <= n ; i ++ ) {
            scanf ( "%d%d" , &l[i] , &r[i]) , r[i] -- , d[i] = r[i] - l[i] + 1 ;
            ans1 += (ll) d[i] + 1 ;
        }
        for ( i = 0 ; i < len ; i ++ ) s[i] = s1[i] ;
        s[len] = 0 ;
        cout<<len<<endl;
        arr.da ( s , len + 1 , 555 ) ;
        for(int i=0;i<len;i++) cout<<arr.hei[i]<<" ";cout<<endl;
        ans2 = 2 + d[1] + 1 ;
        cout<<" "<<ans2<<endl;
//        printf ( "ans2 = %I64d\n" , ans2 ) ;
        arr.rmq ( len ) ;
        cout<<ans2<<endl;
        arr.solve () ;
        printf ( "%I64d %I64d\n" , ans1 , ans2 ) ;
    }
}
