/*
Walking Home
USACO 2021 December Contest, Bronze, Problem 3
http://usaco.org/index.php?page=viewproblem2&cpid=1157
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
const int MAXN = 55;
int N, K, dp[MAXN][MAXN][2][4];
char m[MAXN][MAXN];
void solve(){
    cin >> N >> K;
    for(int i = 1;i<=N;i++){
        string S; cin >> S;
        for(int j = 1;j<=N;j++){
            m[i][j] = S[j-1];
        }
    }
    memset(dp, 0, sizeof(dp));
    dp[2][1][0][0] = dp[1][2][1][0] = 1;
    for(int i = 1;i<=N;i++){
        for(int j = 1;j<=N;j++){
            if(m[i][j]=='H') continue;
            for(int dir = 0;dir<2;dir++){
                for(int k = 0;k<=K;k++){
                    if(i+1<=N&&m[i+1][j]!='H'){
                        if(k+(dir!=0)>K) continue;
                        dp[i+1][j][0][k+(dir!=0)]+=dp[i][j][dir][k];
                    }
                    if(j+1<=N&&m[i][j+1]!='H'){
                        if(k+(dir!=1)>K) continue;
                        dp[i][j+1][1][k+(dir!=1)]+=dp[i][j][dir][k];
                    }
                }
            }
        }
    }
    int ans = 0;
    for(int i = 0;i<=K;i++){
        ans+=dp[N][N][0][i]+dp[N][N][1][i];
    }
    cout << ans << nl;
}
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int T; cin >> T;
    while(T--){
        solve();
    }
    return 0;
}