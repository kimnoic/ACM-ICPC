#include <iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
#define maxn 5050
struct point{
    double x,y;
};
point data[maxn],stack[maxn],MinA;
int top;
double Direction(point i,point j,point k){
    return (j.x-i.x)*(k.y-i.y)-(k.x-i.x)*(j.y-i.y);
}
double Dis(point a,point b){
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
bool cmp(point a,point b){
    double k=Direction(MinA,a,b);
    if(k>0)return 1;
    if(k<0)return 0;
    return Dis(MinA,a)>Dis(MinA,b);
}
void Graham_Scan(point *a,int numa){
    for(int i=0; i<numa; i++)
        if(a[i].y<a[0].y||a[i].y==a[0].y&&a[i].x<a[0].x) swap(a[0],a[i]);
    MinA=a[0],top=0;
    sort(a+1,a+numa,cmp);
    stack[top++]=a[0],stack[top++]=a[1],stack[top++]=a[2];
    for(int i=3; i<numa; i++){
        while(Direction(stack[top-2],stack[top-1],a[i])<0&&top>=2) top--;
        stack[top++]=a[i];
    }
}
void rotating_calipers(point *ch,int n){
    double ans=0;
    int q=1;
    ch[n]=ch[0];
    int x1,x2,x3,y1,y2,y3;
    for(int p=0; p<n; p++){
        q=(p+2)%n;
        for(int i=p+1; i<n; i++){
            double mm;
            while(Direction(ch[p],ch[i],ch[q+1])>(mm=Direction(ch[p],ch[i],ch[q]))) q=(q+1)%n;
            if(mm>ans){
                ans=mm;
                x1=ch[p].x;
                y1=ch[p].y;
                x2=ch[i].x;
                y2=ch[i].y;
                x3=ch[q].x;
                y3=ch[q].y;
            }
            ans=max(ans,mm);
        }
    }
    cout<<x1+(x2-x3)<<" "<<y1+(y2-y3)<<endl;
    cout<<x2+(x3-x1)<<" "<<y2+(y3-y1)<<endl;
    cout<<x3+(x1-x2)<<" "<<y3+(y1-y2);
}
double s;
int main(){
    int n;
    cin>>n;
        cin>>s;
        for(int i=0; i<n; i++)
            scanf("%lf%lf",&data[i].x,&data[i].y);
        Graham_Scan(data,n);

        rotating_calipers(stack,top);
    return 0;
}
