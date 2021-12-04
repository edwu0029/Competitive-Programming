/*
Array Description
https://cses.fi/problemset/task/1746
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
#define nl '\n'
#define sp ' '
#define mp(a, b) make_pair(a, b)
#define EPS 1e-9
const int inf = 0x3f3f3f3f;
const ll infll = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ll MODll = 4000004479;
const int MAXN = 1e5+5;
int N, M, F[MAXN];
ll dp[105][MAXN];
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N >> M;
    for(int i = 0;i<N;i++) cin >> F[i];
    if(F[0]==0){
        for(int i = 1;i<=M;i++) dp[i][0] = 1;
    }else dp[F[0]][0] = 1;
    for(int i = 0;i<N-1;i++){
        if(F[i]==0){
            for(int j = 1;j<=M;j++){
                if(dp[j][i]==0) continue;
                if(j+1<=M) dp[j+1][i+1] = (dp[j][i]+dp[j+1][i+1])%MOD;
                dp[j][i+1] = (dp[j][i]+dp[j][i+1]);
                if(j-1>=1) dp[j-1][i+1] = (dp[j][i]+dp[j-1][i+1])%MOD;
            }
        }else{
            if(F[i]+1<=M) dp[F[i]+1][i+1] = (dp[F[i]][i]+dp[F[i]+1][i+1])%MOD;
            dp[F[i]][i+1] = (dp[F[i]][i]+dp[F[i]][i+1]);
            if(F[i]-1>=1) dp[F[i]-1][i+1] = (dp[F[i]][i]+dp[F[i]-1][i+1])%MOD;
        }
    }
    int ans = 0;
    if(F[N-1]==0){
        for(int i = 1;i<=M;i++) ans = (ans+dp[i][N-1])%MOD;
    }else ans = dp[F[N-1]][N-1];
    cout << ans << nl;
    return 0;
}