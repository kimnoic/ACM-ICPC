#include <bits/stdc++.h>

//#define l ,mid ,t << 1
//#define mid ,r ,t << 1 | 1
#define N 100005

using namespace std;

typedef struct{
    long long l ,r ,h ,mk;
}EDGE;

long long num[N*2*2] ,tmp[N*2*2];
long long len[N*2*2*4];
long long cnt[N*2*2*4];
EDGE E[N*2];

bool camp(EDGE a ,EDGE b){
    return a.h < b.h || a.h == b.h && a.mk < b.mk;
}

void PushUp(int l ,int r ,int t){
    if(cnt[t]) len[t] = num[r] - num[l];
    else if(l + 1 == r) len[t] = 0;
    else len[t] = len[t<<1] + len[t<<1|1];
}

void Update(int l ,int r ,int t ,int a ,int b ,int c){
    if(a == l && b == r){
        cnt[t] += c;
        PushUp(l ,r ,t);
        return ;
    }
    int mid = (l + r) >> 1;
    if(b <= mid) Update(l,mid ,t << 1 ,a ,b ,c);
    else if(a >= mid) Update(mid ,r ,t << 1 | 1 ,a ,b ,c);
    else{
        Update(l ,mid ,t << 1 ,a ,mid ,c);
        Update(mid ,r ,t << 1 | 1 ,mid  ,b ,c);
    }
    PushUp(l ,r ,t);
}

void BuidTree(){
    memset(cnt ,0 ,sizeof(cnt));
    memset(len ,0 ,sizeof(len));
    return ;
}

int search2(int now ,int n){
    int low = 1 ,up = n ,mid ,ans;
    while(low <= up){
        mid = (low + up) >> 1;
        if(now <= num[mid]){
            ans = mid;
            up = mid - 1;
        }
        else low = mid + 1;
    }
    return ans;
}



int main (){
    int i ,n ,id ,cas = 1;
    int x1 ,y1 ,x2 ,y2;
    long long Ans;
    while(~scanf("%d" ,&n) && n){
        for(id = 0 ,i = 1 ;i <= n ;i ++){
            cin>>x1>>y1>>x2>>y2;
            //scanf("%d %d %d %d" ,&x1 ,&y1 ,&x2 ,&y2);
            if(x1>x2)swap(x1,x2);
            if(y1>y2)swap(y1,y2);
            x2++;y2++;/*
            int xmax=max(x1,x2),xmin=min(x1,x2),ymax=max(y1,y2),ymin=min(y1,y2);

            if(x1==x2){
                x2=x1+1;
                y1=ymax;
                y2=ymin;
            }
            else{
                y2=y1-1;
                x1=xmin;
                x2=xmax;
            }*/
            //cout<<x1<<" "<<y1<<"  "<<x2<<" "<<y2<<endl;
            E[++id].l = x1;
            E[id].r = x2 ,E[id].h = y1 ,E[id].mk = 1;
            tmp[id] = x1;

            E[++id].l = x1;
            E[id].r = x2 ,E[id].h = y2 ,E[id].mk = -1;
            tmp[id] = x2;
        }
        sort(E + 1 ,E + id + 1 ,camp);
        sort(tmp + 1 ,tmp + id + 1);

        int n2 = n * 2;
        for(id = 0 ,i = 1 ;i <= n2 ;i ++){
            if(i == 1 || tmp[i] != tmp[i-1])
            num[++id] = tmp[i];
        }
        BuidTree();
        E[0].h = E[1].h;
        Ans = 0;
        for(i = 1 ;i <= n2 ;i ++){

            Ans += len[1] * (E[i].h - E[i-1].h);
            int l = search2(E[i].l ,id);
            int r = search2(E[i].r ,id);
            Update(1 ,id ,1 ,l ,r ,E[i].mk);//cout<<i<<endl;
        }//cout<<"asdf";
        printf("%I64d\n" ,Ans);
    }
    return 0;

}
