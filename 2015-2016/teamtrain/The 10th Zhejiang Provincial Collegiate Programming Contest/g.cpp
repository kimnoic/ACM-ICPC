int n,m,T,K;    ///N次开门，M个手，T分钟就干坏事，K个人
double dp[111][5][114][111];
///dp[第几次][位置关系][被警告一次后在屋内待了多久][剩下几只手]=概率
int t[122];
int main()
{
    int ca,i,j,k;
    cin>>ca;
    while(ca--)
    {
        memset(dp,0,sizeof dp);
        cin>>T>>n>>m>>K;
        dp[0][0][0][m]=1;   t[0]=0;
        for(int i=1;i<=n;i++)cin>>t[i];
        for(int i=1;i<=n;i++)
        {
            ///dp[第几次][位置关系][被警告一次后在屋内待了多久][剩下几只手]=概率
            int ti=t[i]-t[i-1];  ///BellyWhite犯错误砍手
            int k=K;
            for(int j=0;j<=m;j++)///State 0:BellyWhite屋外 MightyHorse屋外
            {
                dp[i][0][0][j]+=dp[i-1][0][0][j]*(k-2)/k;
                dp[i][1][0][j]+=dp[i-1][0][0][j]*1./k;
                dp[i][2][0][j]+=dp[i-1][0][0][j]*1./k;
            }
            for(int j=0;j<=m;j++)///State 1:BellyWhite屋外 MightyHorse屋内
            {
                dp[i][0][0][j]+=dp[i-1][1][0][j]*1/k;
                dp[i][1][0][j]+=dp[i-1][1][0][j]*(k-2)/k;
                dp[i][3][0][j]+=dp[i-1][1][0][j]*1/k;
            }
            for(k=0;k<=T;k++)
                for(int j=0;j<=m;j++)///State 2:BellyWhite屋内 MightyHorse屋外
            {
                dp[i][3][(k+ti)>=T?0:(k+ti)][max(0,j-(k+ti>=T))]+=dp[i-1][2][k][j]/K;
                dp[i][0][0][j]+=dp[i-1][2][k][j]/K;
                dp[i][2][min(T,k+ti)][j]+=dp[i-1][2][k][j]*(K-2)/K;
            }
            for(int k=0;k<=T;k++)
                for(int j=0;j<=m;j++)///State 3:BellyWhite屋内 MightyHorse屋内
            {
                int a,b;
                a=(k+ti)%T,b=max(0,j-(k+ti)/T);
                dp[i][3][a][b]+=dp[i-1][3][k][j]*(K-2)/K;
                dp[i][2][a][b]+=dp[i-1][3][k][j]/K;
                dp[i][1][0][b]+=dp[i-1][3][k][j]/K;
            }
        }
        int tmp=1440-t[n];
        double ans=0;
        for(int i=0;i<=2;i++)
            for(int j=0;j<=T;j++)
            for(int k=0;k<=m;k++)
            ans+=dp[n][i][j][k]*k;
        for(int i=0;i<=T;i++)
            for(int j=0;j<=m;j++)
            ans+=dp[n][3][i][j]*max(0,j-(i+tmp)/T);
        printf("%.6f\n",ans);
    }
}
