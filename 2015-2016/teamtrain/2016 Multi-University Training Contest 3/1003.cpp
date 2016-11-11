#include<bits/stdc++.h>
using namespace std;
const double delta = 1e-5;


int t;
int f1[1010][1010],f3[1010][1010],f4[1010][1010][3];

void run(int type,int n,int m)
{
    if(type==1)
    {
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                if(f1[i][j]!=-1)
                {
                    if(f1[i+1][j]==-1 || f1[i][j]==1)
                        f1[i+1][j]=!f1[i][j];
                    if(f1[i][j+1]==-1 || f1[i][j]==1)
                        f1[i][j+1]=!f1[i][j];
                    if(f1[i+1][j+1]==-1 || f1[i][j]==1)
                        f1[i+1][j+1]=!f1[i][j];
                }
    }
    else if(type==3)
    {
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                if(f3[i][j]!=-1)
                {
                    if(f3[i+1][j+2]==-1 || f3[i][j]==1)
                        f3[i+1][j+2]=!f1[i][j];
                    if(f3[i+2][j+1]==-1 || f3[i][j]==1)
                        f3[i+2][j+1]=!f1[i][j];
                }
    }
    else if (type==4)
    {
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                if(i!=1 || j!=1)
                for(int k=0;k<=2;k++)
                {
                    if(k==0 && i>1)
                    {
                        if(f4[i-1][j][0]==-1 && f4[i-1][j][1]==-1 && f4[i-1][j][2]==-1)
                            f4[i][j][0]=-1;
                        else if(f4[i-1][j][0]==0)
                            f4[i][j][0]=0;
                        else if(f4[i-1][j][1]==0 || f4[i-1][j][2]==0)
                            f4[i][j][0]=1;
                        else
                            f4[i][j][0]=0;
                    }
                    else if(k==1 && j>1)
                    {
                        if(f4[i][j-1][0]==-1 && f4[i][j-1][1]==-1 && f4[i][j-1][2]==-1)
                            f4[i][j][1]=-1;
                        else if(f4[i][j-1][1]==0)
                            f4[i][j][1]=0;
                        else if(f4[i][j-1][0]==0 || f4[i][j-1][2]==0)
                            f4[i][j][1]=1;
                        else
                            f4[i][j][1]=0;
                    }
                    else if(k==2 && i>1 && j>1)
                    {
                        if(f4[i-1][j-1][0]==-1 && f4[i-1][j-1][1]==-1 && f4[i-1][j-1][2]==-1)
                            f4[i][j][2]=-1;
                        else if(f4[i-1][j-1][2]==0)
                            f4[i][j][2]=0;
                        else if(f4[i-1][j-1][0]==0 || f4[i-1][j-1][1]==0)
                            f4[i][j][2]=1;
                        else
                            f4[i][j][2]=0;
                    }
                }
    }
    return ;
}

char ans[3]={'D','B','G'};

int main()
{

    scanf("%d",&t);
    int type,n,m;
    memset(f1,-1,sizeof f1);
    memset(f3,-1,sizeof f3);
    memset(f4,-1,sizeof f4);
    f1[1][1]=1;
    f3[1][1]=1;
    f4[1][1][0]=f4[1][1][1]=f4[1][1][2]=1;
    run(1,1000,1000);
    run(3,1000,1000);
    run(4,1000,1000);
    while(t--)
    {
        scanf("%d%d%d",&type,&n,&m);
        if(type==1)
            cout<<ans[f1[n][m]+1]<<endl;
        if(type==3)
            cout<<ans[f3[n][m]+1]<<endl;
        if(type==2)
        {
            int k;
            if(m==n)
                k=1;
            else
                k=0;
            cout<<ans[k+1]<<endl;
        }
        if(type==4)
        {
            int k=-1;
            if(f4[n][m][0]==0 || f4[n][m][1]==0 || f4[n][m][2]==0)
                k=0;
            else if(f4[n][m][0]!=-1 && f4[n][m][1]!=-1 || f4[n][m][2]!=-1)
                k=1;
            cout<<ans[k+1]<<endl;
        }
    }
/*    for(int i=1;i<=5;i++,cout<<endl)
        for(int j=1;j<=5;j++)
        {
            cout<<f4[i][j][0]<<" ";
        }
    cout<<endl;
    for(int i=1;i<=5;i++,cout<<endl)
        for(int j=1;j<=5;j++)
        {
            cout<<f4[i][j][1]<<" ";
        }
    cout<<endl;
    for(int i=1;i<=5;i++,cout<<endl)
        for(int j=1;j<=5;j++)
        {
            cout<<f4[i][j][2]<<" ";
        }*/
    return 0;
}
