/*
Removing Digits
https://cses.fi/problemset/task/1637
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
const int MAXN = 1e6+5;
int N, dp[MAXN];
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N;
    memset(dp, 0x3f, sizeof(dp));
    dp[N] = 0;
    for(int i = N;i>0;i--){
        for(int j = i;j>0;j/=10){
            int digit = j%10;
            dp[i-digit] = min(dp[i-digit], dp[i]+1);
        }
    }
    cout << dp[0] << nl;
    return 0;
}