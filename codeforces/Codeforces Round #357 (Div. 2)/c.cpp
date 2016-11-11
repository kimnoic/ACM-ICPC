#include <bits/stdc++.h>
using namespace std;
priority_queue<int, vector<int>, greater<int> >pq;
const int maxn = 1000010;
char s[maxn];
int a[maxn];
int main(){
    int n;
    cin>>n;
    string s1="insert";
    string s2="getMin";
    string s3="removeMin";
    int cnt=0;
    string temp;
    int k;
    while(n--){
        cin>>temp;
        if(temp[0]=='i'){
            cin>>k;
            pq.push(k);
            cnt++;
            s[cnt]='i';
            a[cnt]=k;
        }
        else if(temp[0]=='r'){
            if(pq.size()==0){
                ++cnt;
                s[cnt]='i';
                a[cnt]=1;
                pq.push(1);
            }
            ++cnt;
            s[cnt]='r';
            pq.pop();
        }
        else {
            cin>>k;
            while(pq.size()>0){
                if(k<=pq.top())break;
                ++cnt;
                s[cnt]='r';
                pq.pop();
            }
            if(pq.size()==0){
                pq.push(k);
                ++cnt;
                s[cnt]='i';
                a[cnt]=k;
                ++cnt;
                s[cnt]='g';
                a[cnt]=k;
            }
            else if(k==pq.top()){
                ++cnt;
                s[cnt]='g';
                a[cnt]=k;
            }
            else if(k<pq.top()){
                ++cnt;
                s[cnt]='i';
                a[cnt]=k;
                pq.push(k);
                ++cnt;
                s[cnt]='g';
                a[cnt]=k;
            }
        }
    }
    cout<<cnt<<endl;
    for(int i=1;i<=cnt;i++){
        if(s[i]=='i'){
            cout<<s1<<" "<<a[i]<<endl;
        }
        else if(s[i]=='g'){
            cout<<s2<<" "<<a[i]<<endl;
        }
        else cout<<s3<<endl;
    }
    return 0;
}
