/*
Removal Game
https://cses.fi/problemset/task/1097
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
const int MAXN = 5e3+5;
int N, x[MAXN];
ll sum[MAXN], dp[MAXN][MAXN];
bool done[MAXN][MAXN];
ll prefix_sum(int l, int r){
    return sum[r]-sum[l-1];
}
ll solve(int l, int r){
    if(done[l][r]) return dp[l][r];
    if(l==r) dp[l][r] = x[l];
    else{
        dp[l][r] = max(x[l]+(prefix_sum(l+1, r)-solve(l+1, r)), (prefix_sum(l, r-1)-solve(l, r-1)+x[r]));
    }
    done[l][r] = true;
    return dp[l][r];
}
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N;
    for(int i = 1;i<=N;i++){
        cin >> x[i];
        sum[i] = sum[i-1]+x[i];
    }
    cout << solve(1, N) << nl;
    return 0;
}