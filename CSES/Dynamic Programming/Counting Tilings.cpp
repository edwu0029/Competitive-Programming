/*
Counting Tilings
https://cses.fi/problemset/task/2181
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
int N, M;
ll dp[1005][25][1<<12];
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N >> M;
    swap(N, M); //N = # of rows, M = # of columns
    dp[0][M][0] = 1;
    for(int i = 1;i<=N;i++){
        for(int mask = 0;mask<(1<<(M+1));mask++){
            dp[i][0][mask<<1] = dp[i-1][M][mask];
        }
        for(int j = 1;j<=M;j++){
            for(int mask = 0;mask<(1<<(M+1));mask++){
                int rht = mask&(1<<(j-1)), dwn = mask&(1<<j);
                if(rht&&dwn) continue;
                else if(!rht&&!dwn){
                    dp[i][j][mask^(1<<j)] = (dp[i][j][mask^(1<<j)]+dp[i][j-1][mask])%MOD;
                    dp[i][j][mask^(1<<(j-1))] = (dp[i][j][mask^(1<<(j-1))]+dp[i][j-1][mask])%MOD;
                }else if(!rht&&dwn){
                    dp[i][j][mask^(1<<j)] = (dp[i][j][mask^(1<<j)]+dp[i][j-1][mask])%MOD;
                }else if(rht&&!dwn){
                    dp[i][j][mask^(1<<(j-1))] = (dp[i][j][mask^(1<<(j-1))]+dp[i][j-1][mask])%MOD;
                }
            }
        }
    }
    cout << dp[N][M][0] << nl;
    return 0;
}