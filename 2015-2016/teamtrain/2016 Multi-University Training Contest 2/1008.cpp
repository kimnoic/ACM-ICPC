#include <bits/stdc++.h>
using namespace std;
const int maxn=1010;
struct pt{
    int a,b;
}p[maxn*maxn],sum[maxn];
int v[maxn];
int T,n,m,cnt;
int st[maxn*maxn],top,stk;
int cross(pt a,pt b,pt c){
    return (b.b-a.b)*(c.a-a.a)-(b.a-a.a)*(c.b-a.b);
}
double dis(pt a,pt b){
    return sqrt((double)(b.a-a.a)*(b.a-a.a)+(b.b-a.b)*(b.b-a.b));
}
bool cmp(pt a,pt b){
    int tmp=cross(p[1],a,b);
    if(tmp>0) return true;
    else if(tmp==0&&dis(p[0],a)<dis(p[0],b)) return true;
    return false;
}
void graham(int n){
    int i;
    top=1;
    if(n==1) {
        top=1;st[1]=1;
    }
    if(n==2){
        top=1;
        st[1]=1;
        st[2]=2;
    }
    if(n>2){
        for(int i=1;i<=2;i++) st[i]=i;
        top=2;
        for(int i=3;i<=n;i++){
            while(top>1&&cross(p[st[top-1]],p[st[top]],p[i])<=0) top--;
            top++;
            st[top]=i;
        }
    }
}
void solve(){
    sort(p+2,p+cnt+1,cmp);
    graham(cnt);
}

int main(){
    cin>>T;
    while(T--){

        cin>>n>>m;
        for(int i=1;i<=n;i++){
            scanf("%d",&v[i]);
            sum[i].a=sum[i-1].a;
            sum[i].b=sum[i-1].b;
            if(i&1){
                sum[i].a+=v[i];
            }
            else sum[i].b+=v[i];
        }
        cnt=0;
        p[++cnt].a=0,p[cnt].b=0;
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                if(i&1){
                    if(j&1){
                        p[++cnt].a=((sum[j-1].a-sum[i].a>=0)?(sum[j-1].a-sum[i].a):0),p[cnt].b=sum[j].b-sum[i].b;
                        p[++cnt].a=p[cnt-1].a+v[i]+((i!=j)?v[j]:0),p[cnt].b=sum[j].b-sum[i].b;
                        //if(i==1&&j==3) cout<<p[cnt].a<<" "<<v[i]<<" "<<((i!=j)?v[j]:0)<<endl;//p[cnt].a<<" "<<p[cnt-1].a<<endl;
                        //cout<<p[cnt].b<<endl;
                    }
                    else {
                        p[++cnt].a=sum[j].a-sum[i].a,p[cnt].b=sum[j-1].b-sum[i].b;
                        p[++cnt].a=p[cnt-1].a+v[i],p[cnt].b=p[cnt-1].b;
                        p[++cnt].a=p[cnt-2].a,p[cnt].b=p[cnt-1].b+v[j];
                        p[++cnt].a=p[cnt-2].a,p[cnt].b=p[cnt-1].b;
                    }
                }
                else {
                    if(j&1){
                        p[++cnt].a=sum[j-1].a-sum[i].a,p[cnt].b=sum[j].b-sum[i].b;
                        p[++cnt].a=p[cnt-1].a+v[j],p[cnt].b=p[cnt-1].b;
                        p[++cnt].a=p[cnt-2].a,p[cnt].b=p[cnt-2].b+v[i];
                        p[++cnt].a=p[cnt-2].a,p[cnt].b=p[cnt-1].b;
                    }
                    else {
                        p[++cnt].a=sum[j].a-sum[i].a,p[cnt].b=((sum[j-1].b-sum[i].b>=0)?(sum[j-1].b-sum[i].b):0);
                        p[++cnt].a=p[cnt-1].a,p[cnt].b=p[cnt-1].b+v[i]+((i!=j)?v[j]:0);
                    }
                }
            }
        }
//        for(int i=1;i<=cnt;i++){
//            cout<<p[i].b<<" "<<p[i].a<<endl;
//        }
//        cout<<endl;
        solve();
        top++;
        st[top]=++cnt;
        p[st[top]].a=0,p[st[top]].b=0;
//        for(int i=1;i<=top;i++){
//            cout<<p[st[i]].b<<" "<<p[st[i]].a<<endl;
//        }
        for(int i=1;i<top;i++) {
            if(p[st[i+1]].a<p[st[i]].a||p[st[i+1]].b<p[st[i]].b){
                stk=i;
                break;
            }
        }
//        cout<<stk<<endl;

        int flag;

        while(m--){
            flag=1;
            int A,B;
            scanf("%d%d",&A,&B);
            int l=1,r=stk,mid;
            if(A>p[st[stk]].a||B>p[st[stk]].b){
                printf("0");
                continue;
            }
            //cout<<l<<" "<<r<<endl;
            int f=0;
            while(r>l){
                //cout<<"r l"<<r<<" "<<l<<endl;
                mid=(l+r)/2;
                if((A>=p[st[mid]].a&&A<=p[st[mid+1]].a)){
                    f=1;
                    break;
                }
                else if(A>=p[st[mid-1]].a&&A<=p[st[mid]].a){
                    f=2;
                    break;
                }
                else if(A>=p[st[mid]].a){
                    l=mid+1;
                }
                else {
                    r=mid;
                }
            }
            if(f==0){
                printf("0");
                continue;
            }
            if(B>p[st[mid]].b&&f==1){
                flag=0;
                printf("0");
                continue;
            }
            if(B>p[st[mid-1]].b&&f==2){
                flag=0;
                printf("0");
                continue;
            }
            l=stk,r=top;
            //cout<<"asdf"<<endl;
            while(r>l){
                //cout<<"l r "<<l<<" "<<r<<endl;
                mid=(l+r)/2;
                if(A<=p[st[mid]].a&&A>=p[st[mid+1]].a){
                    f=1;
                    break;
                }
                if(A<=p[st[mid-1]].a&&A>=p[st[mid]].a){
                    f=2;
                    break;
                }
                else if(A<=p[st[mid]].a){
                    l=mid+1;
                }
                else r=mid;
            }
            if(f==0){
                printf("0");
                continue;
            }
            if(B<p[st[mid]].b&&f==1){
                //cout<<mid<<endl;
                printf("0");
                continue;
            }
            if(B<p[st[mid-1]].b&&f==2){
                //cout<<mid<<endl;
                printf("0");
                continue;
            }
            printf("1");
        }

        printf("\n");
    }
    return 0;
}
/*
1
12 10
2 1 1 2 3 4 1 4 1 1 2 7
2 1
2 2
2 3
2 4
2 5
4 1
4 2
4 3
4 4
4 5
*/
/*
1
12 1
2 1 1 2 3 4 1 4 1 1 2 7
4 2
*/
