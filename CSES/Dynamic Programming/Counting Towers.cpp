/*
Counting Towers
https://cses.fi/problemset/task/2413
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
const int MAXN = 1e6+5;
int T, N;
ll dp[MAXN][2];
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    dp[1][0] = dp[1][1] = 1;
    for(int i = 1;i<MAXN;i++){
        dp[i+1][0] = (2*dp[i][0]+dp[i][1])%MOD;
        dp[i+1][1] = (dp[i][0]+4*dp[i][1])%MOD;
    }
    cin >> T;
    while(T--){
        cin >> N;
        cout << (dp[N][0]+dp[N][1])%MOD << nl;
    }
    return 0;
}