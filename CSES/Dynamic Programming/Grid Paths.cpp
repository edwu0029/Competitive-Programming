/*
Grid Paths
https://cses.fi/problemset/task/1638
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
const int MAXN = 1005;
int N, dp[MAXN][MAXN];
char m[MAXN][MAXN];
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N;
    for(int i = 1;i<=N;i++){
        string s; cin >> s;
        for(int j = 1;j<=N;j++){
            m[i][j] = s[j-1];
        }
    }
    dp[1][1] = m[1][1]!='*';
    for(int i = 1;i<=N;i++){
        for(int j = 1;j<=N;j++){
            if(i+1<=N&&m[i+1][j]!='*'){
                dp[i+1][j] = (dp[i+1][j]+dp[i][j])%MOD;;
            }
            if(j+1<=N&&m[i][j+1]!='*'){
                dp[i][j+1] = (dp[i][j+1]+dp[i][j])%MOD;;
            }
        }
    }
    cout << dp[N][N] << nl;
    return 0;
}