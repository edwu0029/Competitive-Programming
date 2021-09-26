/*
Big shiny tunes
DWITE Online Computer Programming Contest, November 2008, Problem 4
https://dmoj.ca/problem/dwite08c2p4
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
int S, N, space[25], utility[25], dp[105];
void solve(){
    cin >> S >> N;
    for(int i = 0;i<N;i++){
        cin >> space[i] >> utility[i];
    }
    memset(dp, 0, sizeof(dp));
    for(int i = 0;i<N;i++){
        for(int j = S;j>=space[i];j--){
            dp[j] = max(dp[j-space[i]]+utility[i], dp[j]);
        }
    }
    cout << dp[S] << nl;
}
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    for(int i = 0;i<5;i++){
        solve();
    }
    return 0;
}