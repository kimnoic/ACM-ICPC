 REP(i, n) cin >> a[i];
        s[n] = 0; for (int i=n-1;i>=0;--i) s[i] = s[i+1] + a[i];
         f[n-1][n-1] = 0;
        for(int i=n-2;i>=0;--i){
            LL mn = INFF;
            FOR(j, i+1, n){
                mn = min(mn, f[i+1][j]);
                f[i][j] = f[i+1][j] + min(s[i+1] + 3*s[j+1] + (LL)3*(j-i)*a[i], 2*s[i+1]+2*s[j+1]);

            }
            f[i][i] = mn + 2*s[i+1];
            //FOR(j, i, n) cout <<f[i][j] << " "; cout << endl;
        }

        LL z = INFF; REP(i, n) z = min(z, f[0][i]);
        cout << z << endl;
