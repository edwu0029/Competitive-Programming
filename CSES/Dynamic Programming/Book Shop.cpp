/*
Book Shop
https://cses.fi/problemset/task/1158
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
const int MAXN = 1005, MAXX = 1e5+5;
int N, X, h[MAXN], s[MAXN], dp[MAXX];
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N >> X;
    for(int i = 0;i<N;i++) cin >> h[i];
    for(int i = 0;i<N;i++) cin >> s[i];
    for(int i = 0;i<N;i++){
        for(int j = X;j>=h[i];j--){
            dp[j] = max(dp[j-h[i]]+s[i], dp[j]);
        }
    }
    cout << dp[X] << nl;
    return 0;
}