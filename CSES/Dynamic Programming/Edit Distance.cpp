/*
Edit Distance
https://cses.fi/problemset/task/1639
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
string A, B;
int N, M, dp[5005][5005];
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> A >> B;
    N = A.size(), M = B.size();
    for(int i = 0;i<=N;i++) dp[i][0] = i;
    for(int i = 0;i<=M;i++) dp[0][i] = i;
    for(int i = 1;i<=N;i++){
        for(int j = 1;j<=M;j++){
            if(A[i-1]==B[j-1]){
                dp[i][j] = dp[i-1][j-1];
                continue;
            }
            dp[i][j] = min(dp[i-1][j]+1, dp[i][j-1]+1);
            dp[i][j] = min(dp[i][j], dp[i-1][j-1]+1);
        }
    }
    cout << dp[N][M] << nl;
    return 0;
}