//Problem: https://dmoj.ca/problem/dmopc14c3p6

#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2001, MAXT = 10001;
int N, T, F[MAXN][6];
long long dp[MAXT][4];
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N >> T;
    for(int i = 1, pp, vp, pa, va, pg, vg;i<=N;i++){
        cin >> pp >> vp >> pa >> va >> pg >> vg;
        for(int j = T;j>=pp;j--){
            if(j-pp>=0)dp[j][1]=max(dp[j-pp][0]+vp, dp[j][1]);
            if(j-pa>=0)dp[j][2]=max(dp[j-pa][0]+va, dp[j][2]);
            if(j-pg>=0)dp[j][3]=max(dp[j-pg][0]+vg, dp[j][3]);
        }
        for(int j = 0;j<=T;j++){
            dp[j][0]=max(max(dp[j][1], dp[j][0]), max(dp[j][2], dp[j][3]));
            dp[j][1]=0; dp[j][2]=0; dp[j][3]=0;
        }
    }
    cout << dp[T][0] << '\n';
    return 0;
}