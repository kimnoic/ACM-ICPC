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
int mp[5][5];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,-1,1};
int front=0,rear=1;
struct node{
    int x,y,pre;
}q[100];

void print(int i){
    if(q[i].pre!=-1){
        print(q[i].pre);
        cout<<"("<<q[i].x<<", "<<q[i].y<<")"<<endl;
    }
}
void bfs(int x1,int y1){
    cout<<"(0, 0)"<<endl;
    q[front].x=x1;
    q[front].y=y1;
    q[front].pre=-1;
    while(front<rear){
        for(int i=0;i<4;i++){
            int a=dx[i]+q[front].x;
            int b=dy[i]+q[front].y;
            if(a<0||a>=5||b<0||b>=5||mp[a][b])
                continue;
            else{
                mp[a][b]=1;
                q[rear].x=a;
                q[rear].y=b;
                q[rear].pre=front;
                rear++;
            }
            if(a==4&&b==4) print(front);
        }
        front++;
    }
    cout<<"(4, 4)"<<endl;
}

int main(){
    for(int i=0;i<5;i++)
        for(int j=0;j<5;j++)
            cin>>mp[i][j];
    bfs(0, 0);
    return 0;
}
