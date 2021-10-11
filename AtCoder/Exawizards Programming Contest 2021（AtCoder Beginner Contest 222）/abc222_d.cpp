/*
Between Two Arrays
AtCoder Beginner Contest 222, Problem D
https://atcoder.jp/contests/abc222/tasks/abc222_d
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
const ll MODll = 998244353;
const int MAXN = 3005;
int N, a[MAXN], b[MAXN], mx;
ll prefix[MAXN], dp[MAXN];
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N;
    for(int i = 0;i<N;i++){
        cin >> a[i];
        mx = max(mx, a[i]);
    }
    for(int i = 0;i<N;i++){
        cin >> b[i];
        mx = max(mx, b[i]);
    }
    for(int i = a[0];i<=b[0];i++) prefix[i]++;
    for(int i = 1;i<=mx;i++) prefix[i]+=prefix[i-1];
    for(int i = 1;i<N;i++){
        memset(dp, 0, sizeof(dp));
        for(int j = a[i];j<=b[i];j++){
            dp[j] = prefix[j];
        }
        memset(prefix, 0, sizeof(prefix));
        prefix[0] = dp[0];
        for(int j = 1;j<=mx;j++) prefix[j] = (dp[j]+prefix[j-1])%MODll;
    }
    ll ans = 0;
    for(int i = a[N-1];i<=b[N-1];i++) ans = (ans+dp[i])%MODll;
    cout << ans << nl;
    return 0;
}