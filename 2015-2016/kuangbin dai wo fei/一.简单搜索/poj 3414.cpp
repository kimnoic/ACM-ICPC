#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <queue>
#include <stack>
#include <vector>
#include <set>
#include <map>
using namespace std;
#define Max 500
struct pt{
    int a,b,step;
    char str[Max][Max];
};

int A,B,C;
bool mark[Max][Max];
bool bfs(){
    memset(mark,false,sizeof(mark));
    queue<pt>que;
    pt p,q;
    p.a=0,p.b=0,p.step=0;
    que.push(p);
    mark[0][0]=true;
    while(!que.empty()){
        p=que.front();
        que.pop();
        if(p.a==C||p.b==C){
            printf("%d\n",p.step);
            for(int i=1;i<=p.step;i++){
                printf("%s\n",p.str[i]);
            }
            return true;
        }
        if(p.a==0){
            q=p;
            q.a=A;
            q.step++;
            strcpy(q.str[q.step],"FILL(1)");
            if(!mark[q.a][q.b]){
                mark[q.a][q.b]=true;
                que.push(q);
            }
        }else if(p.a<=A){
            q=p;
            q.a=0;
            q.step++;
            strcpy(q.str[q.step],"DROP(1)");
            if(!mark[q.a][q.b]){
                mark[q.a][q.b]=true;
                que.push(q);
            }
            if(p.b<B){
                q=p;
                if(q.a+q.b<=B){
                    q.b+=q.a;
                    q.a=0;
                }else {
                    q.a=(q.b+q.a)-B;
                    q.b=B;
                }
                q.step++;
                strcpy(q.str[q.step],"POUR(1,2)");
                if(!mark[q.a][q.b]){
                    mark[q.a][q.b]=true;
                    que.push(q);
                }
            }
        }
        if(p.b==0){
            q=p;
            q.b=B;
            q.step++;
            strcpy(q.str[q.step],"FILL(2)");
            if(!mark[q.a][q.b]){
                mark[q.a][q.b]=true;
                que.push(q);
            }
        }else if(p.b<=B){
            q=p;
            q.b=0;
            q.step++;
            strcpy(q.str[q.step],"DROP(2)");
            if(!mark[q.a][q.b]){
                mark[q.a][q.b]=true;
                que.push(q);
            }
            if(p.a<A){
                q=p;
                if(q.b+q.a<=A){
                    q.a+=q.b;
                    q.b=0;
                }else {
                    q.b=(q.b+q.a)-A;
                    q.a=A;
                }
                q.step++;
                strcpy(q.str[q.step],"POUR(2,1)");
                if(!mark[q.a][q.b]){
                    mark[q.a][q.b]=true;
                    que.push(q);
                }
            }
        }
    }
    return false;
}


int main(){
    while(cin>>A>>B>>C){
        if(!bfs())cout<<"impossible"<<endl;
    }
    return 0;
}
