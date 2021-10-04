/*
Sequence Matching
AtCoder Beginner Contest 185, Problem E
https://atcoder.jp/contests/abc185/tasks/abc185_e
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
const int MAXN = 1e3+5;
int N, M, A[MAXN], B[MAXN], dp[MAXN][MAXN];
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N >> M;
    for(int i = 1;i<=N;i++) cin >> A[i];
    for(int i = 1;i<=M;i++) cin >> B[i];
    for(int i = 0;i<=N;i++){
        for(int j = 0;j<=M;j++){
            if(i==0&&j==0){
                dp[i][j] = 0;
                continue;
            }else if(i==0){
                dp[i][j] = j;
                continue;
            }else if(j==0){
                dp[i][j] = i;
                continue;
            }
            dp[i][j] = min(dp[i-1][j]+1, dp[i][j-1]+1);
            int t = (A[i]==B[j])?0:1;
            dp[i][j] = min(dp[i][j], dp[i-1][j-1]+t);
        }
    }
    cout << dp[N][M] << nl;
    return 0;
} 