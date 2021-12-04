/*
Coin Combinations I
https://cses.fi/problemset/task/1635
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
const int MAXN = 105, MAXX = 1e6+5;
int N, X, c[MAXN], dp[MAXX];
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N >> X;
    for(int i = 0;i<N;i++) cin >> c[i];
    dp[0] = 1;
    for(int i = 0;i<=X;i++){
        for(int j = 0;j<N;j++){
            if(i+c[j]<=X){
                dp[i+c[j]] = (dp[i+c[j]]+dp[i])%MOD; 
            }
        }
    }
    cout << dp[X] << nl;
    return 0;
}